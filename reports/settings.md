# Settings & Feature Audit — island-fork.wh.cpp

- **Audited file:** `C:\dsh\work\island-fork\island-fork.wh.cpp` (read-only audit; source not modified)
- **Frozen version:** 747,550 bytes, 18,411 lines, sha256 `DE378CA847EFE269D3BD01D3494E8CB25E55651B1F6FFF600CB6DF54032CB494`, mtime 2026-11-03 10:07:09 +08:00. Re-hashed after the audit: identical, so all line numbers below are valid for this frozen file.
- **Settings block:** lines 142–251, one top-level `- Main:` group, **33 settings** (the brief said ~44; this fork has exactly 33 and no other groups).
- **Loader:** `ReadSettings()` 1868–1946; ints via `Wh_GetIntSetting`, strings via `GetStringSetting()` wrapper 1840–1848 (`WindhawkUtils::StringSetting`), booleans read as `Wh_GetIntSetting(...) != 0` (no boolean accessor used anywhere).

## 1. Settings table

Flags: **U** = read but never used · **I** = read but inert in this build (hard-disabled/constant path) · **D** = code fallback/default ≠ YAML default.

| Key (`Main.X`) | Type | YAML default | Read @ | Used @ (first/primary) / notes |
|---|---|---|---|---|
| Position | string | `"tray_left"` | 1870 | 2118–2128 (injection), 7491–7499 (expand dir), 10464, 18131–18137 |
| CompactWidth | int | 169 | 1871 (clamp 96–320) | 16956, 16971 |
| AutoSizeToTaskbar | bool | true | 1872 | 16957–16972 · **D** missing key → `!=0` = false, though YAML default is true |
| ExpandedWidth | int | 360 | 1873 (clamp 240–640) | 10432, 10489 |
| ExpandedHeight | int | 500 | 1874 (clamp 430–760) | **U** — never referenced again (popup height is derived from art size, 6749–6792, 10291–10527) |
| Compact | bool | false | 1875 | 6762, 9396, 10488, 17801, 17835 |
| PopupSpacing | int | 20 | 1876 (2–40) | 6632 |
| PopupCardGap | int | 8 | 1877 (0–40) | 6635 |
| PopupShadowDepth | int | 58 | 1878 (0–128) | 6638 |
| PopupShadowOpacity | int | 70 | 1879 (0–100) | 6644 |
| PopupButtonStyle | string | `"fluent_bold"` | 1880–1883 | 7798/8042, 8158 · **D** unknown value → `"minimal_transport"` (1883); options differ only by glyph font size (8042–8044) |
| PopupBackdropCoverEffect | string | `"dark_only"` | 1885–1890 | 6727, 6733 · effectively ignored when `Material=liquid_glass` (default), because LG returns `liquidGlassGradient` first (6723–6725) |
| ArtworkAbstractMode | string | `"browser_original"` | 1892–1900 | 5963–5972, 5996–6003 · legacy value `"off"` accepted and normalized (1894–1896, 5964) |
| Height | int | 40 | 1902 (32–56) | 16955, 16969 |
| MarginLeft | int | 4 | 1903 (0–48) | 17014 |
| MarginRight | int | 4 | 1904 (0–48) | 17015 |
| HideWhenNoMedia | bool | false | 1905 | 17946 (compact grid only; popup visibility handled separately) |
| HoverScale | int | 106 | 1906–1907 (100–125, /100) | 7295, 11647, 15781, 17308 |
| HoverLerpSpeed | int | 28 | 1908–1909 (1–80) | 11714, 16209 |
| AnimationSpeed | int | 100 | 1910–1911 (10–400, /100, re-clamped 0.1–4) | 6538 (expanded-popup spring only) |
| Material | string | `"liquid_glass"` | 1913–1919 | 1667–1695, 6700–6708, 7056 · one-time migration auto-changes old `mica_like` → `acrylic` (1850–1866, 18392–18402) |
| LiquidGlassOpacity | int | 66 | 1921–1922 | **U** — never referenced |
| LiquidGlassGradient | bool | false | 1923–1924 | 1710, 6725, 7071 |
| LiquidGlassCornerRadius | int | 46 | 1925–1926 (8–64) | 9399, 15380, 15470 |
| LiquidGlassFrost | int | 12 | 1927–1928 (0–24) | 15598 · **I** `blurStdDev = max(24, value)` with max 24 ⇒ constant 24, slider has no effect |
| LiquidGlassRefraction | int | 6 | 1929–1930 (0–100) | 13287 · **I** only feeds the GPU lens-warp path, hard-coded off at 15596 |
| LiquidGlassHighlight | int | 0 | 1931–1932 (0–100) | **U** — rim alpha hard-coded to 0 at 15601 |
| LiquidGlassRoundness | int | 4 | 1933–1934 (2–8) | 13062, 13126, 13226 · **I** only used to build the lens displacement map, disabled with lens warp |
| BackdropInitialFrameSkip | int | 0 | 1935–1936 (0–3) | 14560 · Acrylic-only WGC overlay path (14405, 15704) |
| BackdropFallbackBlurPasses | int | 5 | 1937–1938 (4–6) | 15050 · Acrylic-only fallback painter |
| BackdropFallbackCaptureScale | int | 2 | 1939–1940 (2–3) | 15021 · Acrylic-only fallback painter |
| BackdropWgcBlurStdDev | int | 18 | 1941–1942 (14–22) | **I** only used by `PopupBackdropWgcBlurStdDev()` 6664–6665, which has no callers |
| AllowScreenCapture | bool | false | 1943–1944 | 16040–16043 (capture exclusion on/off) + 15592–15690; static blurred fallback only exists in the Acrylic overlay path (description is partly inaccurate) |

**Defaults note:** Windhawk supplies YAML defaults, but every numeric read passes no explicit fallback, so a missing/renamed key returns 0 and is clamped to the minimum — e.g. `AnimationSpeed` → 0.10×, `PopupShadowOpacity` → 0, `HoverScale` → 1.00, `ColorRadius` → 8. `Settings` struct initializers (764–798) also diverge from YAML: `expandedHeight` 430 vs 500, `liquidGlassOpacity` 88 vs 66, `liquidGlassFrost` 18 vs 12, `liquidGlassRefraction` 0 vs 6. Prefer explicit defaults or fix the struct to match YAML.

**(a) Read but never used:** ExpandedHeight, LiquidGlassOpacity, LiquidGlassHighlight (+ BackdropWgcBlurStdDev is de-facto unused via its dead getter).
**(b) Used but missing from YAML:** none — all 34 `L"Main.*"` reads map to a YAML key. Only internal persisted keys (`SettingsMigrationVersion`, `MigrateMicaLikeMaterialToAcrylic`, 1850–1866) are read via `Wh_GetIntValue`; they are storage, not settings-page entries.
**(c) Fallback ≠ YAML default:** see `D` rows (AutoSizeToTaskbar bool fallback, PopupButtonStyle invalid→minimal_transport) plus the struct-vs-YAML mismatches above.

## 2. Settings quality issues

- **Missing `$description` on 18/33 settings:** Position, CompactWidth, AutoSizeToTaskbar, ExpandedWidth, ExpandedHeight, PopupSpacing, PopupCardGap, PopupShadowDepth, PopupShadowOpacity, PopupButtonStyle, ArtworkAbstractMode, Height, MarginLeft, MarginRight, HideWhenNoMedia, HoverScale, HoverLerpSpeed, Material. Only 15 have descriptions.
- **Vocabulary is inconsistent:** internal keys say `Popup*`, visible labels say "Expanded*" (PopupSpacing→"Expanded outer spacing", PopupButtonStyle→"Expanded button style", PopupBackdropCoverEffect→"Expanded background album wash"). `CompactWidth` (island width) sits next to `Compact` (expanded single-card layout) — very easy to confuse. `Height` means compact-island height, not popup height.
- **All labels are English-only** (no bilingual placeholder). Keys are persisted, so plan localization in `$name`/`$description` (`"Taskbar position / 任务栏位置"`) and keep YAML keys ASCII.
- **Developer-facing knobs in the public UI:** BackdropInitialFrameSkip / BackdropFallbackBlurPasses / BackdropFallbackCaptureScale / BackdropWgcBlurStdDev are jargon, Acrylic-only and mostly invisible; LiquidGlassRefraction / Roundness / Highlight / Frost are currently inert (see §3). ExpandedHeight/LiquidGlassOpacity do nothing at all.
- **Option coverage:** all 5 options-bearing settings have unique values and every YAML value is handled in code. Caveats: PopupButtonStyle `minimal_transport` has no explicit branch (it is just the default look; only font size differs); PopupBackdropCoverEffect is ignored for the default Liquid Glass material, and its light-mode LG branch at 6730–6732 is unreachable; ArtworkAbstractMode handles a legacy `"off"` value not present in YAML; Position `taskbar_center_edge` only affects overlay alignment (18131) and expand direction falls back to a screen-center heuristic (7502–7504).
- **Labels/descriptions that mislead:** "Liquid glass frost strength / 0 to 24" (collapses to 24), "Liquid glass corner roundness" (unitless 2–8, no UI hint), "Expanded outer spacing", "Component height", "Backdrop fallback capture scale: lower values sample more pixels" (clamp minimum is 2), "Expanded background album wash keeps enabled for Liquid Glass" (false). HoverLerpSpeed/AnimationSpeed units only implied.
- **Missing settings coverage:** the expanded-popup system-volume slider is hard-coded (3948–4000, 8973–9231, 10036–10075) with no setting; NetEase/Bilibili special integrations have no enable/disable switch or priority setting; no theme override, no reset-defaults, no diagnostic/log toggle. AllowScreenCapture is privacy-relevant but sits mid-list with no warning.
- **Numeric ranges are invisible:** Windhawk has no min/max metadata, so clamp ranges (96–320, 240–640, 100–125, etc.) are undiscoverable; descriptions should state them where kept.

## 3. Feature inventory (line ranges in frozen file)

| Feature | Where | Status |
|---|---|---|
| Compact taskbar island | layout model 800–990; `BuildIslandGrid` 17004–17334; `UpdatePlayerContents` 17436–17960; `InjectIslandGrid`/`RemoveIslandGrid` 18097–18180 / 17962–18096; injection target 2114–2129; autosize/layout 16899–17002, 17411–17435; compact visuals 7139–7154, 1783–1839 | Complete |
| Compact animations | progress loop 10611–10690; playback indicator 10700–10944; text/track transition 10945–11225; hover 16180–16241 | Complete |
| Expanded popup | XAML host 8611–9250; visuals 9258–10079; layout/position 7193–7316, 10268–10527, 10544–10600; lifecycle 15927–16177; theme/accents 8141–8610; GDI fallback renderer 7642–7796, 10112–10209 | Complete; two render paths (XAML preferred, GDI fallback when XAML host fails) |
| Popup open/close morph | 11567–11625 (begin close), 11765–11807 (resume), 11840–11857, 11870–11945 (finish), 11949–11991 (rest as compact), 16242–16366 (`ApplyExpandedState`), 16418–16445 (expand loop), 12496–12857 (XAML render loop) | Complete |
| Liquid Glass (default material) | `ImmediateBackdropBlurBrush` 700–762; `EnsurePopupLiquidGlassBlur` 7160–7183 (hard-coded 25 px blur + tint); glass brushes 1697–1782; DWM host-backdrop flag 7513 / 7523–7531 | Complete but **hard-coded**: blur/frost, rim/highlight/refraction are not driven by the LiquidGlass* settings |
| WGC desktop-capture backdrop | capture item/devices 12858–14384; frame render 13912–14262; start/capture loop 14385–14727; low-res + box-blur fallback 14728–15189; capture exclusion 14772–14809; overlay windows/regions 15190–15497; overlay update 15498–15798 | Reachable **only for Material=acrylic** (6700–6708, 14405, 15499). Native-Acrylic branch hard-disabled (`systemFrostOnly=false`, 15517); lens warp & rim disabled (15596, 15601) — comments at 6701–6707 vs 15514–15516 contradict each other |
| Animations | spring/`AnimationSpeed` 6537–6574; easing/morph helpers 6456–6621; XAML transition 8285–8470, 9258–10079; hover loop 16180–16241; expand loop 16418–16445 | Complete |
| Artwork / album wash | GSMTC thumbnail 4631–4660; WIC decode/mask/dims 4740–5360; abstract art 5360–5960 (mesh 5436, flame 5934, cache 5981–6006); palette/accent 5741–5878, 6008–6221; album wash 6723–6747, 8327–8421, 9385–9420; NetEase CDN artwork 3041–3060, 3206–3320 | Complete |
| NetEase Cloud Music integration | local data/DB 2450–2790; queue metadata 2828–3040; process/window 3799–4053; UIA playback 4054–4161; transport hotkeys 6845–6879; seek 4162–4268; favorite 4269–4386; progress estimate 4324–4386; state 4387–4510 | Working but fragile/undocumented: private UIA access, global-hotkey simulation, SQLite reads; always-on, no setting |
| Bilibili integration | process/window 3444–3521; UI state/URL 3522–3618; metadata via api.bilibili.com 3619–3674; state 3675–3718; favorite click 3719–3798 | Working but fragile/undocumented (Chrome render-widget scraping + web API); always-on |
| Media session & progress | GSMTC session manager 2419–2449; `RefreshMediaState` 4598–4673; media thread 16448–16788; popup seek/live progress 11236–11527; compact progress 10611–10690; time format 6411–6427 | Complete |
| Transport controls | command dispatch 6880–6941; button creation 8949–9231 (inside 8611–9250); glyphs 7811–7869; button layout/visual 7999–8135; optimistic feedback 7871–7998; favorite 7933–7998 | Complete |
| Multi-monitor / taskbar patching | taskbar.dll symbol hooks 18297–18337; hook bodies 18251–18295; init/uninit 18341–18411; taskbar visibility subclassing 12315–12371; auto-hide/anchor/z-order 11992–12314; monitor geometry 10268–10527, 12001–12070, 13741–13764; layout monitor 17411–17435 | Complete; taskbar-position aware, per-monitor popup placement |
| System volume row | 3948–4000 (endpoint volume), 8262–8284 (theme), 8973–9231 (XAML creation), 10036–10075 (layout) | Implemented, **not documented in README/settings**; AirPlay capsule intentionally absent (comment 10036) |
| Apple Music seek fallback | 1465–1572 (UIA), used 4709–4720 | Hidden compatibility hack, no setting |

**Half-finished / disabled (fix or remove before release):**
1. Native Acrylic path compiled but hard-disabled (`systemFrostOnly=false` 15517; `SetPopupOverlayNativeFrost(...,false)` 15548).
2. GPU liquid-lens warp + rim disabled (15596, 15601) → LiquidGlassRefraction/Highlight/Roundness settings do nothing.
3. LiquidGlassFrost neutralized by `std::max(24, …)` against a 0–24 range (15598); LiquidGlassOpacity never used.
4. `PopupBackdropWgcBlurStdDev()` getter never called; `ExpandedHeight` read into a field that is never consumed.
5. Liquid Glass uses a hard-coded XAML blur brush (7167), while the WGC pipeline only serves Acrylic; conflicting comments suggest an unfinished material refactor.
6. `PopupBackdropCoverEffect` semantics broken for the default LG material (6723–6739).
7. Old `mica_like` silently migrates to `acrylic` once (1850–1866), while README still advertises Mica-like.
8. GDI popup renderer kept as fallback; AirPlay capsule absent; NetEase/Bilibili integrations are undocumented and non-optional.

## 4. Suggested grouping / order for a public release

Keep YAML keys/labels separate: **do not rename persisted keys** without a migration in `ApplySettingsMigrations` (1850–1866) — change `$name` text instead.

1. **Placement** — Position, HideWhenNoMedia (first: highest user impact; add `$description` explaining tray insertion vs full-taskbar overlay).
2. **Size & margins** — Height→"Island height", CompactWidth→"Island width", AutoSizeToTaskbar, MarginLeft, MarginRight.
3. **Expanded player** — ExpandedWidth→"Popup width", Compact→"Single-card expanded layout", PopupSpacing, PopupCardGap, PopupShadowDepth, PopupShadowOpacity, PopupButtonStyle. Remove ExpandedHeight unless implemented.
4. **Appearance** — Material, LiquidGlassGradient, LiquidGlassCornerRadius, PopupBackdropCoverEffect→"Expanded album wash" (fix LG behavior or hide when Material=liquid_glass first).
5. **Artwork** — ArtworkAbstractMode (add description that it only affects low-res browser/video thumbnails).
6. **Animation** — HoverScale, HoverLerpSpeed, AnimationSpeed (state ranges in descriptions).
7. **Advanced (collapsed/last)** — AllowScreenCapture (privacy warning, default off), and either implement or delete before release: LiquidGlassOpacity, LiquidGlassFrost, LiquidGlassRefraction, LiquidGlassHighlight, LiquidGlassRoundness, BackdropWgcBlurStdDev; move Acrylic-only BackdropInitialFrameSkip/BlurPasses/CaptureScale here behind an "Acrylic backdrop (advanced)" description or drop them.
8. Add `$description` to all 33 settings, prepare bilingual `$name`/`$description` (English / 中文), align `Settings` struct defaults with YAML, and replace bare numeric reads with explicit YAML defaults so future key renames cannot silently push values to clamp minima.
