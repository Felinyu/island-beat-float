import io, re

p = r"C:\dsh\work\island-fork\island-fork.wh.cpp"
t = io.open(p, encoding="utf-8", errors="replace").read()
lines = t.split("\n")

unused_funcs = ["IsBlurredGlassMaterial","MediaContentKey","ClickScreenPointForWindow",
"TryInvokeNeteasePlayerButton","FindNeteaseFavoriteControl","TryGetNeteaseFavoriteState",
"SmoothStep","PopupClosingCompactRevealOpacity","PopupBackdropWgcEffectiveBlurStdDev",
"PopupBackdropWgcLiquidRefractionBlurStdDev","ToggleCurrentFavorite","PopupPanelCoverOpacityFactor",
"PopupSurfaceBrush","MakeAppleTriangle","MakeAppleTransportIcon","ApplyAppleTransportIcon",
"MakeAppleVolumeIcon","ApplyAppleVolumeIcon","PopupTransportOpticalMargin",
"AnyWindowCoversTaskbarMonitor","KeepPopupOnTopThrottled"]
unused_vars = ["kPopupTextTopPadding","kPopupTextLineGap"]

# find def start lines via warning line numbers
warn = { }
for ln, name in [(1672,"IsBlurredGlassMaterial"),(2232,"MediaContentKey"),(3402,"ClickScreenPointForWindow"),
(4182,"TryInvokeNeteasePlayerButton"),(4432,"FindNeteaseFavoriteControl"),(4628,"TryGetNeteaseFavoriteState"),
(6840,"SmoothStep"),(6972,"PopupClosingCompactRevealOpacity"),(7062,"PopupBackdropWgcEffectiveBlurStdDev"),
(7070,"PopupBackdropWgcLiquidRefractionBlurStdDev"),(7494,"ToggleCurrentFavorite"),(7718,"PopupPanelCoverOpacityFactor"),
(7728,"PopupSurfaceBrush"),(8451,"MakeAppleTriangle"),(8497,"MakeAppleTransportIcon"),(8529,"ApplyAppleTransportIcon"),
(8547,"MakeAppleVolumeIcon"),(8563,"ApplyAppleVolumeIcon"),(8583,"PopupTransportOpticalMargin"),
(12820,"AnyWindowCoversTaskbarMonitor"),(13097,"KeepPopupOnTopThrottled"),(7081,"kPopupTextTopPadding"),(7082,"kPopupTextLineGap")]:
    warn[name] = ln

def find_close(start_idx):
    depth = 0
    i = start_idx
    while i < len(lines):
        depth += lines[i].count("{") - lines[i].count("}")
        if depth == 0 and "{" in "".join(lines[start_idx:i+1]):
            return i
        i += 1
    return -1

print("=== unused symbol spans ===")
for name, ln in warn.items():
    idx = ln - 1
    line = lines[idx]
    if name in unused_vars:
        print(f"{name}: line {ln}: {line.strip()}")
        continue
    # def line should contain '{' or next line
    start = idx
    j = idx
    while j < len(lines) and "{" not in lines[j]:
        j += 1
    end = find_close(j)
    print(f"{name}: def line {ln} .. end {end+1} ({end-ln+1} lines) | {line.strip()[:100]}")

print("\n=== debug log context (11055-11085) ===")
for i in range(11050, 11090):
    print(i+1, lines[i][:150])
