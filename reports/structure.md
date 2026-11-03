# Structure map — Island Media Controls - Fork (v2.5.26)

- Source: `C:\dsh\work\island-fork\island-fork.wh.cpp` (read-only audit; not modified)
- Frozen audit base: **18,411 lines / 747,550 bytes**, sha256 `DE378CA847EFE269D3BD01D3494E8CB25E55651B1F6FFF600CB6DF54032CB494` (git 1f418f6)
- All line numbers below refer to this frozen revision. The file has no section banners; structure is inferred from function/type/constant anchors (grep for `^...(` definitions, `^struct|class|enum`, `^#include`, `^using`, `^//`, `constexpr`, `Wh_Mod*`).

## 1. Current top-level map

```
     1-   12   Windhawk metadata (// ==WindhawkMod==)
    14-  140   README (// ==WindhawkModReadme==)
   142-  251   Settings YAML (// ==WindhawkModSettings==, top-level "- Main:", ~40 keys)
   253-  371   Includes — 4 sub-groups: Win32/D3D 253-285; local interop decls 287-324;
                windhawk_utils/winrt/embedded-asset 326-352; std 354-371
   373-  379   Compatibility #defines (WS_EX_NOREDIRECTIONBITMAP, DWMWA_WINDOW_CORNER_PREFERENCE)
   381-  425   Local WinRT interop shim: ABI::Windows::Graphics::Effects,
                IGraphicsEffectD2D1Interop, winrt::impl::guid_v specializations (416-425)
   427-  467   WinRT namespace + type aliases (xaml/controls/mediax/gsm/json/...)
   469          namespace {  <-- ONE anonymous namespace opens; everything through 18339 is internal
   471-  762   "Immediate" D2D/WinRT blur effect classes (Gaussian 480, Flood 579,
                Composite 641, ImmediateBackdropBlurBrush 711) — the WindhawkBlur-style live backdrop core
   764-  916   Core types: Settings 764, RuntimeLayout 800, CompactVisualSpec 827
                (+ CompactVisualSpecFrom 851), DipRect 880, MediaState 887,
                taskbar hook typedefs 903-914, MediaCommand 915
   918- 1441   Global state (~200 g_* variables) INTERLEAVED with code and types:
                CurrentCompactVisualSpec() 920-922, IsModActive() 992-994,
                timeout constants 996-1002, WaitForAsyncWithTimeout 1005-1027,
                GetAsyncResultWithTimeout 1030-1039, RemoteBytesCacheEntry struct 970,
                ClearPopupBackdropOverlayHandoffCache() 1122-1135,
                PopupOverlayWgcDiagnosticState 1086, PopupOverlayWgcRenderParameters 1140,
                PopupLifecycleState 1320, hook function-pointer globals 1432-1440
  1443- 1947   Shared helpers: Clamp 1443; color/brush factories 1447-1804;
                ReadThumbnailBytes 1806; GetStringSetting 1840; settings constants 1846-1848;
                ApplySettingsMigrations 1850; ReadSettings 1868
  1948- 2147   Taskbar/Win32/XAML utilities: FindCurrentProcessTaskbarWnd 1948,
                RunFromWindowThread 1965, GetTaskbarXamlRoot 2018, FindChildByName 2074,
                FindTaskbarRootGrid 2095, InjectionTarget 2108, ResolveInjectionTarget 2114
  2149- 2448   Media state model: fingerprints/keys 2149-2244, SnapshotMedia 2280/2285,
                SetMedia 2291, RequestMediaRefresh 2419
  2450- 3040   NetEase local data layer (paths, UTF-8, embedded SQLite shims 2574-2604,
                cached artwork, JSON, track metadata 2873)
  3041- 3303   Remote artwork download (sync/async + background thread)
  3322- 3390   UIA click-injection helper (ClickResolvedScreenPointForWindow)
  3392- 3798   Process-snapshot cache 3392-3454 (RunningProcessSnapshot, ProcessProbeCache)
                + Bilibili integration 3455-3798
  3799- 4510   NetEase Cloud Music UI-automation integration (window, volume, shortcuts,
                playback state, seek, favorite, 16 functions)
  4511- 4597   Media source classification + WinRT GSMTC session selection
  4598- 4673   RefreshMediaState (aggregates NetEase / Bilibili / default session)
  4674- 4739   Media command execution (RunMediaCommand 4674, SeekToMediaPosition 4686)
  4740- 5017   Artwork decode (ThumbnailHash, DecodeAlbumBitmap 4753, low-detail cover 4825)
  5018- 6221   Artwork generation pipeline (G2 mask, placeholders, mesh gradient,
                adaptive palette, energy flame, display cache, accent color 6008)
  6222- 6825   Color/palette/geometry/animation math; popup class/timer constants 6444-6453
                and popup layout constants 6627-6698 embedded mid-block
  6826- 6915   Media navigation direction + transport routing (Netease command 6845,
                RunMediaTransportCommand 6880)
  6916- 7051   Popup text foreground brushes/fades
  7052- 7184   Popup material/brush helpers (tint, stroke, compact surface,
                liquid-glass blur)
  7185- 7375   Popup geometry & animation state (CalculatePopupFinalLayout 7193,
                hit test 7347, forward decls 7356-7360)
  7376- 7797   Popup host HWND plumbing: child subclass proc 7376, click-through/parking,
                DWM attrs 7523, ApplyPopupBackdrop 7585, PopupButtonRect 7627,
                PaintExpandedPopup 7642; DWM constants 7507-7513
  7798- 8610   Popup controls/theming: glyphs & embedded icons, optimistic toggles
                7871/7933, button metrics/visuals, MakePopupXamlButton 8087,
                ApplyPopupXamlTheme 8141, accent visuals 8285, transition 8327,
                composition shadow 8471, element reset 8507
  8611- 9250   InitializePopupXamlHost — builds the entire expanded XAML tree in one function
  9251-10543   Popup visual update: DPI forward decls 9251-9256, UpdatePopupXamlVisuals
                9258-10079, RenderExpandedPopupLayer 10112-10244, DPI helpers 10245-10267,
                popup open direction 10268, CapturePopupSourceGeometry 10291-10527,
                WGC/backdrop forward decls 10528-10542
 10544-10610   PositionExpandedPopup (final screen placement)
 10611-11230   Compact island render loops: progress 10611-10699, playback indicator
                10700-10944, text clipping/slide 10945-11230
 11231-11948   Expanded popup progress/seek/close state machine: progress 11236, seek
                11297/11469, text refresh 11534, BeginCloseExpandedPopup 11567, window
                regions 11626-11668, playback indicator loop 11669-11764, ResumeOpen 11765,
                suppression/morph 11808-11857, StopPopupXamlRenderLoop 11858,
                FinishCloseExpandedPopup 11870
 11949-12495   Taskbar tracking & z-order: RestExpandedPopupAsCompact 11949-11991,
                hidden/shown probes 11992-12189, AnchorIslandAboveTaskbar 12190,
                KeepPopupOnTop 12214, taskbar-visibility subclassing 12242-12371,
                SyncRestingPopupWithTaskbarVisibility 12374-12495;
                mid-code globals kTaskbarVisibilitySubclassId + g_taskbarVisibilitySubclassedWnds 12122-12123
 12496-12839   Popup render loop (OnPopupXamlRendering 12496, StartPopupXamlRenderLoop 12574)
                + ExpandedPopupWndProc 12585-12839
 12840-14727   WGC borderless live backdrop + liquid-glass lens: ModInstance 12840, capture
                item 12858, D2D/DComp resources 12923-13740, borderless-access thread
                13765-13838, frame render 13912-14262, start/stop 14309-14672,
                PopupRoundedRectAlpha 14673-14727
 14728-15741   CPU blur fallback + backdrop overlay window: box blur 14728, capture
                exclusion 14759-14808 (WDA #defines inline 14777-14782), low-res capture
                14872, layered blur 14996, overlay wndproc/class/window 15153-15299,
                overlay geometry 15300-15497, UpdatePopupBackdropOverlayWindow 15498-15741
 15742-16179   Popup hit window 15799-15887; popup window class & lifecycle
                15888-16179 (EnsureExpandedPopup 15927, ShowExpandedPopup 15983,
                DestroyExpandedPopup 16054)
 16180-16447   Hover loop 16180-16241, ApplyExpandedState 16242, compact interactivity /
                state repair 16367-16447
 16448-16745   Media thread (MediaThreadProc 16448-16695, Start/Stop)
 16746-17334   Compact island UI construction/theme/layout: MakeTextBlock 16746,
                MakeMediaButton 16760, UpdateThemeVisuals 16808, DetectTaskbarHeightDip 16899,
                UpdateRuntimeLayout 16949-17003, BuildIslandGrid 17004-17334
 17335-17435   Taskbar layout monitor (Stop/On/Start 17335/17344/17411)
 17436-17961   UpdatePlayerContents
 17962-18180   RemoveIslandGrid 17962 / InjectIslandGrid 18097
 18181-18250   Settings application on taskbar thread + shell hide/show callbacks
 18251-18338   Hook thunks (5) + HookTaskbarSymbols 18297-18338
 18339         } // namespace  (anonymous namespace closes)
 18341-18411   Mod lifecycle: Wh_ModInit 18341, Wh_ModAfterInit 18356, Wh_ModUninit 18371,
                Wh_ModSettingsChanged 18392 (no Wh_ModBeforeUninit exists)
```

## 2. Function inventory

`≈408` top-level function definitions (a definition-head grep returns 420 lines: 408 definitions + 9 `using` alias lines + 1 local struct header + 2 multi-line declarations; 46 further one-line forward declarations are separate lines; 445 definitions existed before the Lead's dead-code cleanup). 5 functions are embedded inside the global-state block (920, 992, 1005, 1030, 1122).

| area | ~count | notable / central functions (line) |
|---|---|---|
| D2D blur effect classes | 0 free fn | 4 classes 471-762 |
| Shared helpers + settings | 24 | Clamp 1443, Color 1447, Brush 1569, ApplyLayoutRect 1625, IslandBackgroundColor 1672, ApplySettingsMigrations 1850, ReadSettings 1868 |
| Taskbar host utilities | 6 | RunFromWindowThread 1965, ResolveInjectionTarget 2114 |
| Media session/state/commands | 20 | SetMedia 2291, SelectBestSession 4534, RefreshMediaState 4598, RunMediaCommand 4674 |
| NetEase local data + remote artwork | 25 | ReadNeteaseCachedArtwork 2656, TryReadNeteaseTrackMetadata 2862, RemoteBytesThreadProc 3240 |
| NetEase UI automation | 16 | TrySeekNeteaseCloudMusic 4162, TryToggleNeteaseFavorite 4289, TryReadNeteaseCloudMusicState 4387 |
| Process snapshot cache | 3 | TakeRunningProcessSnapshot 3403, RefreshProcessProbeCacheLocked 3434 |
| Bilibili | 11 | TryReadBilibiliUiState 3550, TryReadBilibiliState 3675 |
| Artwork pipeline | 27 | DecodeAlbumBitmap 4753, CreateMeshGradientAlbumCoverBytes 5436, ExtractAdaptiveArtworkPalette 5741, ExtractAlbumAccentColor 6008 |
| Popup design system | ~64 | LerpColor 6222, ColorFromHsv 6248, AdvancePopupSpring 6537, CalculatePopupFinalLayout 7193, ApplyPopupTextForegrounds 6968 |
| Popup host / XAML | ~50 | PaintExpandedPopup 7642, ApplyPopupXamlTheme 8141, InitializePopupXamlHost 8611, UpdatePopupXamlVisuals 9258, RenderExpandedPopupLayer 10112 |
| Popup lifecycle/animation | ~23 | PositionExpandedPopup 10544, BeginCloseExpandedPopup 11567, FinishCloseExpandedPopup 11870, RestExpandedPopupAsCompact 11949, OnPopupXamlRendering 12496 |
| Compact island | ~32 | OnCompactProgressRendering 10664, OnCompactPlaybackIndicatorRendering 10788, OnCompactTextRendering 11078, UpdateRuntimeLayout 16949, BuildIslandGrid 17004 |
| Taskbar tracking/z-order | ~16 | AnchorIslandAboveTaskbar 12190, KeepPopupOnTop 12214, SyncRestingPopupWithTaskbarVisibility 12374 |
| WGC backdrop / liquid glass | 25 | EnsurePopupOverlayWgcDeviceResourcesLocked 13592, RenderPopupOverlayWgcFrameLocked 13912, StartPopupOverlayWgcBackdrop 14385 |
| CPU backdrop fallback / window plumbing | ~31 | SetPopupWindowCaptureExclusion 14772, UpdatePopupBackdropOverlayWindow 15498, PopupBackdropOverlayWndProc 15161, EnsureExpandedPopup 15927, DestroyExpandedPopup 16054 |
| Hover / expanded state | 7 | ApplyExpandedState 16242 |
| Media thread | 3 | MediaThreadProc 16448 |
| Player contents + island injection | 3 | UpdatePlayerContents 17436, InjectIslandGrid 18097 |
| Settings application / shell callbacks | 5 | ApplySettingsOnTaskbarThread 18208, OnTaskbarShellHiding 18226 |
| Hooks + lifecycle | 10 | HookTaskbarSymbols 18297, Wh_ModInit 18341, Wh_ModUninit 18371 |

Largest functions (candidates for future splitting, out of scope for a move-only reorganization): UpdatePopupXamlVisuals 9258-10079 (822 lines), InitializePopupXamlHost 8611-9250 (640), UpdatePlayerContents 17436-17961 (526), RenderPopupOverlayWgcFrameLocked 13912-14262 (351), BuildIslandGrid 17004-17334 (331), CapturePopupSourceGeometry 10291-10527 (237).

## 3. Ordering problems

1. **Includes split by code.** Four include groups with code in between: 253-285, 287-324 (local COM interop structs), 326-352, 354-371. Duplicate `<winrt/Windows.Foundation.h>` at 279 and 333; `<fstream>` (256) sits in the Win32 group; the local asset include (352) is between winrt and std; `#undef GetCurrentTime` (328-330) sits mid-include; `extern "C" CreateDirect3D11DeviceFromDXGIDevice` (322) is declared between include blocks.
2. **One anonymous namespace wraps everything (469-18339).** Only `Wh_Mod*` (18341+) is outside. All ~417 functions and ~300 variables are TU-internal; there is no structural module boundary to expose, and block moves must stay inside the namespace.
3. **Global-state block interleaved with executable code and types (918-1441).** Function definitions/constants/templates injected between globals at 920-922, 992-994, 996-1002, 1005-1039, 1122-1135; type definitions at 970, 1086, 1140, 1320; taskbar hook function pointers (1432-1440) are adjacent to compact-island UI globals (1386-1430). Two more mid-code globals appear later: `g_processProbeCache` 3432 and `kTaskbarVisibilitySubclassId`/`g_taskbarVisibilitySubclassedWnds` 12122-12123.
4. **Types defined mid-file next to first use instead of at top:** RemoteBytesCacheEntry 970, PopupOverlayWgcDiagnosticState 1086, PopupOverlayWgcRenderParameters 1140, PopupLifecycleState 1320, InjectionTarget 2108, NeteaseSqlite* 2574-2604, NeteaseTrackMetadata 2818, RunningProcessSnapshot 3396, ProcessProbeCache 3427, BilibiliUiState 3543, NeteaseCloudMusicWindow 3901, MediaTransportCommand 4150, AdaptiveArtworkPalette 5697, RenderColorD 5712.
5. **Constants scattered:** async timeouts 996-1002, migration constants 1846-1848, popup class/timer constants 6444-6453, popup layout constants 6627-6698, kPopupXamlChildSubclassId 7354, parking coords 7446-7447, DWM constants 7507-7513, taskbar-subclass id 12122; plus two `#define`s inside a function body (WDA_* 14777-14782).
6. **48 forward declarations in 14 islands:** 4156-4159, 7356-7360, 8136-8139, 9251-9256, 10528-10542, 10601-10609, 11226-11234, 11528-11529, 11946-11947, 12372, 12855, 15981, 16178, 16446. They encode real use-before-definition edges (e.g. KeepPopupOnTop used at 7390 but defined 12214; ApplyOptimisticPlaybackToggle used 6887/6889, defined 7871; ApplyExpandedState used 11582, defined 16242; UpdatePlayerContents used 11829/12565/16029/16658, defined 17436; InjectIslandGrid 16656 vs 18097; PopupDpiScale/PopupDipToPx decl 9251-9252 vs def 10245/10254; SetPopupWindowCaptureExclusion decl 10539 vs def 14772; StartPopupOverlayWgcBackdrop decl 10534 vs def 14385).
7. **Duplicated declarations:** KeepPopupOnTop 7356/11946/12372; UpdatePlayerContents 11234/15981/16178; SetCompactIslandSuppressed 10601/11226; StartPopupXamlRenderLoop 10602/11227; StopHoverRenderLoop 10603/11228. `ClearPopupBackdropOverlayHandoffCache` is defined at 1122 and then re-declared at 10541 (a declaration after its definition). Multi-line declaration/definition pairs: PopupScreenRectToLocalDip 9254 vs 10258; StartPopupOverlayWgcBackdrop 10534 vs 14385.
8. **Compact-island code is split into four disjoint regions** (render loops 10611-11230, interactivity/expanded state 16180-16447, UI construction/theme/layout 16746-17334, grid injection/removal 17962-18180) while expanded-popup code is interrupted at 10611 by the compact render loops (popup 10544→11231).
9. **Hooks are far from their declarations/state:** hook typedefs 903-914, function-pointer globals 1432-1440, apply-side settings callbacks 18181-18250, hook thunks 18251-18296, HookTaskbarSymbols 18297, lifecycle 18341-18411 (Wh_ModInit calls HookTaskbarSymbols at 18348). A reader cannot see the hook contract without jumping ~16k lines.
10. **Minor noise:** redundant `static` inside the anonymous namespace (SourceScaledRadius 6610, SubclassTaskbarChildWindowsProc 12330); `Clamp`/`Clamp01`/`LerpDouble`/`LerpInt` spread over three regions (1443, 6244, 6606, 6622).
11. **No `Wh_ModBeforeUninit`:** the lifecycle only has Init/AfterInit/Uninit/SettingsChanged; there is nothing to move for that hook, and unload cleanup lives entirely in Wh_ModUninit 18371-18390.

## 4. Proposed section order (move-only; no function rewrites)

Rules: (a) [K] = block must stay in relative position; (b) move whole existing blocks unchanged; only split/centralize items explicitly marked [X]. Existing anonymous namespace can stay exactly as it is; banners go inside it. Put all types, constants, globals and forward declarations before behavior code so no declaration islands are needed.

1. `// ===== Windhawk metadata =====` [K] (1-12, must stay first for the mod parser)
2. `// ===== README =====` [K] (14-140)
3. `// ===== Settings schema =====` [K] (142-251)
4. `// ===== Includes =====` (253-371): one sorted block, Win32/COM → D3D/D2D → WinRT → project include 352 → std; drop duplicate Foundation include 333; move `#undef GetCurrentTime` 328-330 out.
5. `// ===== Compatibility shims =====` (287-324, 381-425, 373-379, 328-330; WDA #defines [X] from 14777-14782) — must precede everything that uses the interfaces/guid_v.
6. `// ===== Compile-time constants =====` [X] (996-1002, 1846-1848, 6444-6453, 6627-6698, 7354, 7446-7447, 7507-7513, 12122)
7. `// ===== WinRT type aliases =====` (427-467; must follow includes/shims)
8. `// ===== Types =====` (764-916 core set + [X] move 970-974, 1086-1095, 1140-1148, 1320-1325, 2108-2113, 2574-2604, 2818-2827, 3396-3431, 3543-3549, 3901-3905, 4150-4154, 5697-5717 here)
9. `// ===== Global state =====` (918-1441 minus the moved code/types/constants + [X] 3432, 12123); sub-banners: media, settings, popup XAML, WGC overlay, backdrop fallback, compact island, taskbar, hook pointers.
10. `// ===== Forward declarations =====` [X] (collect the 48 lines from §3.6, one per function; drop duplicates)
11. `// ===== Backdrop blur effects (D2D / WinRT) =====` (469-762)
12. `// ===== Shared helpers (math, color, brushes, XAML, input) =====` (1443-1848 + click helper 3322-3390)
13. `// ===== Settings =====` (1850-1947 + settings application 18181-18250)
14. `// ===== Taskbar host utilities =====` (1948-2147)
15. `// ===== Media session, state and commands =====` (2149-2448 + 4511-4673 + 4674-4739 + navigation/transport routing 6826-6915)
16. `// ===== Process snapshot cache =====` (3392-3454)
17. `// ===== NetEase Cloud Music =====` (2450-3040 local library/cache, 3041-3303 remote artwork, 3799-4510 UI automation; three sub-banners)
18. `// ===== Bilibili =====` (3455-3798)
19. `// ===== Artwork pipeline =====` (4740-6221)
20. `// ===== Popup design system =====` (6222-6825 + 6916-7051 text styling + 7052-7184 material brushes as sub-banners)
21. `// ===== Popup layout and positioning =====` (7185-7375 + 10291-10610 CapturePopupSourceGeometry/PositionExpandedPopup)
22. `// ===== Popup window plumbing =====` (7376-7797)
23. `// ===== Popup controls and theming =====` (7798-8610)
24. `// ===== Popup XAML host and visual update =====` (8611-10543)
25. `// ===== Popup render loop and window procedure =====` (12496-12839)
26. `// ===== Popup window lifecycle =====` (15742-16179)
27. `// ===== Popup open/close and animation state machine =====` (11231-11948)
28. `// ===== Taskbar tracking and z-order =====` (11992-12495)
29. `// ===== WGC liquid-glass backdrop =====` (12840-14727)
30. `// ===== CPU backdrop fallback and overlay windows =====` (14728-15741)
31. `// ===== Compact island =====` (10611-11230 render loops + 16180-16447 hover/expanded-state glue + 16746-17334 construction/theme/layout + 17962-18180 grid injection; four sub-banners)
32. `// ===== Media thread =====` (16448-16745)
33. `// ===== Player contents update =====` (17436-17961)
34. `// ===== Hooks =====` (18251-18338)
35. `// ===== Mod lifecycle =====` [K] (18341-18411, keep last; anonymous namespace closes right before it at 18339)

Resulting order is dependency-safe: includes → shims → aliases/constants/types → globals → forward decls → helpers → backends → artwork → popup → backdrop → compact island → media thread → hooks/lifecycle. Only three block splits are needed ([X] items 5, 6, 8/9/10); every other move is a contiguous copy.

## 5. Blockers / risks for the reorganization

1. **Anonymous namespace (469-18339):** keep it; removing it to split files would change linkage and is a separate project. All moves stay inside it, so no ODR/link changes.
2. **Shim ordering is load-bearing:** ABI namespace + IGraphicsEffectD2D1Interop (381-425) and `guid_v` specializations (416-425) must come after the WinRT includes (332-351) and before the blur classes (471+) / WGC code; `#include <windhawk_utils.h>` (326) must follow windows.h. Don't let "sort includes" break this.
3. **Types-before-globals:** moving types to §8 is safe only if done before global-state §9 and forward decls §10. Watch: RemoteBytesCacheEntry/PopupOverlayWgcRenderParameters/PopupLifecycleState are instantiated by globals; NeteaseSqliteDb/Stmt are forward-declared (2574-2575) and must move with NeteaseSqliteApi.
4. **WinRT `using` declarations (447-467)** are file-scope aliases of `Border`, `Image`, `Grid`, etc.; moving them is fine but they must stay after includes and before first use; any attempt to convert them to `using namespace` would cause collisions.
5. **Macros:** WDA_* `#define`s inside SetPopupWindowCaptureExclusion (14777-14782) and the WS_EX_/DWMWA compat macros (373-379) must be hoisted together with their `#ifndef` guards, otherwise later includes could redefine them. `#undef GetCurrentTime` (328-330) must run after windows.h and before WinRT headers that use it.
6. **Forward refs form a graph, not a chain:** ~48 declarations encode use-before-definition. Centralize them (§10) rather than deleting them during the move, or finalize order by moving definitions too. Removing duplicates (KeepPopupOnTop ×3, UpdatePlayerContents ×3, etc.) is safe only after all call sites are still covered by one declaration.
7. **Shared mutable state couples "compact" and "popup" code:** ~200 g_* globals and helpers are used from both areas (e.g. SetCompactPlaybackIndicatorState is called from popup controls 7918/16364/17638; KeepPopupOnTop/AnchorIslandAboveTaskbar are used by popup, taskbar and wndproc code). Do not try to split compact vs popup into separate files/subsystems in this pass — that is a rewrite, not a move.
8. **Hooks/lifecycle:** hook thunks + SYMBOL_HOOK array (18251-18338) reference the `_Original` function pointers declared in the global block (1432-1440) and the typedefs (903-914). Keep those three groups consistent (typing changes are out of scope). Windhawk entry points must stay outside the anonymous namespace and after HookTaskbarSymbols, or add one forward declaration.
9. **Behavioral risk of moves is low but not zero:** any accidental change to `#include` order, macro visibility, or function ordering that removes a required declaration breaks the build; recommend applying sections one at a time with a Windhawk compile check (or at least a clang syntax check) between moves.
