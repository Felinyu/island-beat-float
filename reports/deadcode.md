# Dead-code & leftover audit — Island Media Controls fork

- Target: `C:\dsh\work\island-fork\island-fork.wh.cpp`
- Frozen baseline: **SHA-256 `DE378CA847EFE269D3BD01D3494E8CB25E55651B1F6FFF600CB6DF54032CB494`** (747,550 bytes, 18,411 lines, git HEAD `1f418f6`)
- Scope: audit of the frozen post-pass-1 file. The 23 compiler-detected unused symbols, both `#if 0` blocks, the Codex debug logger and its 2 call sites were removed in pass 1 and are **not** re-reported here.
- Method: targeted read + grep plus read-only structural scans (function/global/settings-usage counts). No source edits, no build.

## Summary

| Item | Count / result |
|---|---|
| Commented-out C++ code blocks | **0** (no action needed) |
| `#if 0` / `#ifdef DISABLED` blocks | 0 |
| Functions newly orphaned by pass 1 (no call sites) | **6** |
| Dead global variables | 2 |
| Settings fields read but never consumed (no-op YAML options) | 3 |
| Unused includes / dangling asset include | 3 + 1 |
| Duplicated forward declarations | 5 functions (46 prototypes total) |
| Silent `catch (...)` vs `try` | 117 / 118 |
| Stale version / diagnostic comments | 4 |

## 1. Commented-out C++ code blocks

**None found in the frozen file.** Screened all `//` lines for statement terminators, braces, assignments, call syntax, `return/if/for/while/switch/case`, and all `/* */` blocks (only the two documentation blocks exist: readme 15–139, settings YAML 143–250). Pass 1 also removed the only two `#if 0` blocks, so this category is clean — **no deletion work here.**

Related but not commented-out code: two comments narrate deleted/old code instead of the current behaviour — 17586–17592 (“The old code included the thumbnail hash…”) and 6701–6704 (see §2). Recommendation: rewrite to present tense, or drop.

## 2. Debug / experimental leftovers

| Lines | What | Recommendation |
|---|---|---|
| 6701–6704 | `// 0.9.50 diagnostic:` inside `UseOverlayPopupBackdropMaterial()` — stale version-tagged diagnostic note (current version is 2.5.26) | **delete** the tag, keep the 2 useful sentences |
| 1351 | `bool g_popupArtClickArmed = false;` — only user was the removed `#if 0` artwork-click code; now dead state | **delete** |
| 12240 | `std::chrono::steady_clock::time_point g_lastTopmostGuardTime{};` — only user was the pass-1-removed `KeepPopupOnTopThrottled()`; now dead state | **delete** |
| 6801–6803 | “Light mode keeps the stronger white-tint experiment, while dark mode is rolled back…” — tuning narrative, not maintainable behaviour spec | **rewrite** as a factual colour rationale |
| 15356–15360 | “The previous inset experiment… **For this test**, prefer exact shape matching…” — dev scratch note | **rewrite/delete** “For this test…” |
| 743, 7541 | Old-version history in code comments: “which reduced 1.4.1 to…”, “bright flashing rectangle seen in 1.3.1” | keep behaviour note, **drop version numbers** (move to CHANGELOG) |
| 6865 | “These are NetEase’s own registered global shortcuts and were verified” — manual-verification note | keep, rephrase (no action required) |
| YAML 204–206 + readme 129–130 | `AnimationSpeed` documented as “slow-motion animation preview” — a developer preview knob exposed as a user setting | keep as feature, but document it as an intentional preview mode, not an internal debug switch |
| 352 | include of a placeholder asset header (see §3) | **delete** include once §4A is removed |

No `TODO` / `FIXME` / `XXX` / `HACK` / `TEMP` markers remain anywhere in the file (verified).

## 3. AI / session remnants

- **Placeholder asset header (highest-signal remnant).** Line 352: `#include "assets/media-icons/apple_media_icons_embedded.h"`. The referenced `assets/` tree does not exist in the repo. The only copy on disk is `C:\dsh\apple_media_icons_embedded.h`, whose own header says: *“placeholder generated 2026-08-18: the original embedded Apple media icons were missing from this machine; a 1x1 transparent PNG keeps the image pipeline producing a valid bitmap (icons render blank).”* After pass 1 nothing references `apple_media_icons::*` — the include is both a session artifact and now dead. **Delete line 352 and the placeholder file** (or vendor the real asset if Apple icon buttons are ever restored).
- Scratch/session-tone comments: 15356–15360 (“For this test…”), 17586–17592 (long narration about the old implementation), 6701 (“0.9.50 diagnostic”), 743/7541 (old release numbers). Rewrite as present-tense rationale — see §2.
- No `Codex`, `ASUS`, `C:\Users\...`, `AppData`, `.log` writer, `std::wofstream`, or AI-tool references remain (re-checked after pass 1; those were correctly removed).

## 4. Redundant / duplicated code and abandoned-looking blocks

### 4A. Functions orphaned by pass 1 — no call sites left (delete; a rebuild should re-emit these as `-Wunused-function`)

| Lines | Function | Why it is dead now |
|---|---|---|
| 1697–1699 | `IslandBackgroundBrush()` | only caller was removed `PopupSurfaceBrush()` |
| 2149–2163 | `MediaThumbFingerprint()` | only caller was removed `MediaContentKey()` |
| 4269–4286 | `LooksLikeNeteaseFavoriteControl()` | only caller was removed `FindNeteaseFavoriteControl()` |
| 6664–6666 | `PopupBackdropWgcBlurStdDev()` | only callers were removed `PopupBackdropWgcEffectiveBlurStdDev()` / `…LiquidRefractionBlurStdDev()` |
| 7847–7857 | `MakeEmbeddedIconImage()` | only callers were removed `ApplyAppleTransportIcon()` / `ApplyAppleVolumeIcon()` |
| 7830–7845 | `EmbeddedIconBitmap()` | only caller is `MakeEmbeddedIconImage()` above (delete together) |

The two dead globals at 1351 and 12240 (§2) are also pass-1 residue; non-const globals may not trigger `-Wunused-variable`, so delete them explicitly.

### 4B. Dead `Settings` fields whose YAML options do nothing (read but never consumed)

| Field decl | Read at | YAML option | Effect |
|---|---|---|---|
| 769 `int expandedHeight` | 1874 | 161–162 `Main.ExpandedHeight` | none — value never consumed |
| 786 `int liquidGlassOpacity` | 1921–1922 | 214–216 `Main.LiquidGlassOpacity` | none |
| 791 `int liquidGlassHighlight` | 1931–1932 | 229–231 `Main.LiquidGlassHighlight` | none |

Recommendation: **investigate** whether each was intentionally dropped from the renderer. If yes, delete field + `Wh_GetIntSetting` read + YAML entry (they currently mislead users); if no, wire it up. (Overlaps the settings-auditor report.)

### 4C. Duplicated plumbing / code to factor

- **7532–7583 vs 7585–7625**: `SetPopupOverlayNativeFrost()` and `ApplyPopupBackdrop()` each hand-roll `AccentPolicy`, `CompositionAttributeData` and the `SetWindowCompositionAttribute` `GetProcAddress` block (7548–7568 and 7595–7612). Extract one helper.
- **15300–15421 vs 15423–15478**: `CalculatePopupBackdropOverlayRect()` and `CalculatePopupBackdropOverlayTargetSize()` repeat the same `popupScreenPx → DipRect → CalculatePopupFinalLayout → PopupBackdropRectFromParts → targetRadiusDip` chain; the radius block is near-identical (15374–15382 vs 15464–15472). Factor a shared core.
- **15247–15263 vs 15265–15290**: `HidePopupBackdropOverlayWindowVisualOnly()` vs `HidePopupBackdropOverlayWindow()` duplicate ~10 global-reset lines.
- **6710–6721**: `PopupBackdropOverlayOpacity()` always returns `1.0`; `PopupBackdropOverlayMaxAlpha()` therefore always returns 255 (used at 15061, 15554). Tuning scaffolding — inline or delete.
- **377–379**: `#ifndef DWMWA_WINDOW_CORNER_PREFERENCE / #define … 33` shim is unused — code passes literal `33` at 7528.
- **279 & 333**: exact duplicate `#include <winrt/Windows.Foundation.h>`; the C++/WinRT includes are split into two unordered groups (279–285 and 332–351, with `<winrt/base.h>` after projection headers). Merge/sort.
- **Duplicate forward declarations**: `KeepPopupOnTop` (7356, 11946, 12372; def 12214), `UpdatePlayerContents` (11234, 15981, 16178; def 17436), `SetCompactIslandSuppressed` (10601, 11226), `StartPopupXamlRenderLoop` (10602, 11227), `StopHoverRenderLoop` (10603, 11228). 46 file-scope prototypes sit in ~13 small clusters — consolidate into one declarations block (structure report overlaps).
- **Unused includes** (verified no remaining users): 255 `<appmodel.h>` (only `GetApplicationUserModelId`, removed with the media-source `#if 0` block), 256 `<fstream>` (only the removed debug logger), 257 `<shellapi.h>` (only `ShellExecuteW`, removed with the same block). Keep `<dwmapi.h>`, `<commctrl.h>`, `<shlwapi.h>` (still used).

### 4D. Large legacy-looking subsystem (investigate, not dead)

Native acrylic/WGC backdrop-overlay stack: overlay state 1105–1149, declarations 10528–10542, implementation **12858–15740 (~2.9k lines, ~60 functions)**. It is only active when `material == "acrylic"` (`UseOverlayPopupBackdropMaterial()`, 6700–6708; the default material is `liquid_glass`). It is the single largest complexity/review-risk concentration and duplicates purpose with the XAML liquid-glass backdrop path. Decision needed before release: keep as the acrylic implementation or retire it. (Artwork generators 4825–6220 for mesh-gradient/flame modes are optional features but are still reachable — not dead.)

## 5. Other code-quality issues an OSS reviewer would flag

- **Giant functions**: `UpdatePopupXamlVisuals` 9258–10078 (821 lines), `InitializePopupXamlHost` 8611–9249 (639), `UpdatePlayerContents` 17436–17960 (525), `RenderPopupOverlayWgcFrameLocked` 13912–14261 (350), `BuildIslandGrid` 17004–17333 (330). Split into smaller builders/steps.
- **Silent error swallowing**: 117 of 118 `try` blocks use bare `catch (...)` with no logging; failures are invisible in the field. Log at least type/HRESULT on key WGC/XAML/UI-automation paths.
- **Raw DWM attribute IDs**: 7526–7529 passes `34 / 20 / 33 / 38` literally while named constants exist at 7507–7513 (and the shim at 377–379). Use `DWMWA_BORDER_COLOR`, `DWMWA_USE_IMMERSIVE_DARK_MODE`, `DWMWA_WINDOW_CORNER_PREFERENCE`, `DWMWA_SYSTEMBACKDROP_TYPE`.
- **Undocumented API use**: `SetWindowCompositionAttribute` + `AccentPolicy` (field 19 / `ACCENT_ENABLE_ACRYLICBLURBEHIND`) in 7532–7625 is reverse-engineered and fragile across Windows builds — document the fallback risk.
- **Readme bloat**: “What’s new” 29–113 is an 85-line internal changelog (including “Reverted the win-event hooks…” at 52). Move to GitHub releases/CHANGELOG and keep 1–3 bullets; the Features list 115–130 is the useful part.
- **Fork metadata / attribution**: metadata block 1–12 still says `@id island-media-controls-fork`, `@name … - Fork`, `@author usho`, `@github` upstream repo; preview images 27 and 136–138 point at the upstream repo. Decide rebranding + attribution/licence text before a public release (investigate; MIT is declared).
- **One-time settings migration**: `ApplySettingsMigrations()` 1846–1866 (call 1920) + reset logic 18396–18402 migrates `mica_like → acrylic` for users upgrading from older builds. For a first fork release this is probably unnecessary; keep only if upstream users will upgrade in place.
- **Whitespace scars from pass 1**: 29 double-blank-line spots remain (e.g. 269, 6792, 7828, 7858, 7869, 15245). Run one whitespace normalisation.
- **Missing vendored asset**: the only quoted include (352) is not present in the repo — the mod is not self-contained until §3/§4A are resolved.

## Suggested priority

1. **P0 (safe deletes, compile-verifiable):** orphans §4A (6 funcs), dead globals 1351/12240, dead includes 255/256/257 + line 352, placeholder header file. Rebuild after to confirm only expected leftover warnings.
2. **P1 (user-facing correctness):** dead settings §4B — remove or implement; delete or rewrite stale diagnostic/experiment comments §2.
3. **P2 (duplication/refactor):** §4C helpers, giant-function splits, DWM constants, silent catches.
4. **P3 (release polish):** readme/metadata/attribution/whitespace, decide the acrylic overlay subsystem §4D.
