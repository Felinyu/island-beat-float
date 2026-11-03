import io, re

p = r"C:\dsh\work\island-fork\island-fork.wh.cpp"
t = io.open(p, encoding="utf-8", errors="replace").read()

new_yaml = r'''- Main:
  - Position: "tray_left"
    $name: Taskbar position
    $description: Where to insert the island on the taskbar.
    $options:
    - "tray_left": "Tray - far left"
    - "tray_right": "Tray - far right"
    - "tray_before_clock": "Tray - left of clock"
    - "tray_after_clock": "Tray - right of clock"
    - "taskbar_left_edge": "Taskbar - left overlay"
    - "taskbar_center_edge": "Taskbar - center overlay"
    - "taskbar_right_edge": "Taskbar - right overlay"
  - HideWhenNoMedia: false
    $name: Hide the island when no media is playing
  - Height: 40
    $name: Island height (DIP)
    $description: Height of the compact island on the taskbar.
  - CompactWidth: 169
    $name: Island width (DIP)
    $description: Width of the compact island; ignored when "Auto size to taskbar" adapts it to tall taskbars.
  - AutoSizeToTaskbar: true
    $name: Auto size to taskbar
    $description: Widen the island automatically on tall taskbars so artist names are not truncated.
  - MarginLeft: 4
    $name: Left margin (DIP)
  - MarginRight: 4
    $name: Right margin (DIP)
  - ExpandedWidth: 360
    $name: Expanded panel width (DIP)
    $description: Width of the expanded player panel.
  - Compact: false
    $name: Compact expanded layout
    $description: Use a single compact card with the cover beside the song and artist information.
  - PopupSpacing: 20
    $name: Expanded outer spacing (DIP)
    $description: Gap between the expanded panel and the taskbar.
  - PopupCardGap: 8
    $name: Expanded cover-to-controls gap (DIP)
  - PopupShadowDepth: 58
    $name: Expanded shadow depth (DIP)
  - PopupShadowOpacity: 70
    $name: Expanded shadow opacity (%)
  - PopupButtonStyle: "fluent_bold"
    $name: Expanded button style
    $options:
    - "minimal_transport": "Minimal transport"
    - "fluent_bold": "Fluent bold"
  - Material: "liquid_glass"
    $name: Background material
    $description: Material used for the compact island and the expanded panel.
    $options:
    - "mica_like": "Mica-like content layer"
    - "solid": "Solid"
    - "acrylic": "Acrylic / glass"
    - "liquid_glass": "Liquid glass"
  - LiquidGlassGradient: false
    $name: Liquid glass album gradient
    $description: Blend the current cover into the glass background.
  - LiquidGlassCornerRadius: 46
    $name: Liquid glass expanded corner radius
    $description: The compact endpoint is automatically limited to a capsule.
  - PopupBackdropCoverEffect: "dark_only"
    $name: Expanded album wash
    $description: Draw the album cover colours behind the expanded panel. Liquid Glass keeps its gradient wash enabled in light mode for readability.
    $options:
    - "off": "Off"
    - "dark_only": "Dark mode only"
    - "on": "Always on"
  - ArtworkAbstractMode: "browser_original"
    $name: Low-res video artwork mode
    $description: What to show when a browser session only provides a low-resolution thumbnail.
    $options:
    - "browser_original": "Browser thumbnail"
    - "mesh_gradient": "Mesh gradient"
    - "energy_flame": "Flame"
  - HoverScale: 106
    $name: Hover scale (%)
    $description: Size of the island while the pointer is over it (100 = no scaling).
  - HoverLerpSpeed: 28
    $name: Hover smoothing
    $description: Higher values make the hover animation snappier.
  - AnimationSpeed: 100
    $name: Animation speed (%)
    $description: Speed of the expanded-panel animation; 100 is normal, lower values are slow-motion (useful for previewing the animation).
  - AllowScreenCapture: false
    $name: Allow screen capture of the expanded panel
    $description: When off, the expanded panel is excluded from screen capture and screenshots. Uses a capturable static blurred backdrop for Acrylic and Liquid Glass, avoiding self-capture feedback.
  - LiquidGlassFrost: 12
    $name: Liquid glass frost strength
    $description: Gaussian blur strength of the liquid glass backdrop, from 0 to 24 (experimental).
  - LiquidGlassRefraction: 6
    $name: Liquid glass refraction strength
    $description: Edge displacement strength from 0 to 100. Only affects the experimental GPU lens-warp path, which is currently disabled.
  - LiquidGlassRoundness: 4
    $name: Liquid glass corner roundness
    $description: 2 is a normal rounded rectangle, 4 is the continuous Apple-like squircle. Only affects the experimental GPU lens-warp path, which is currently disabled.
  - BackdropInitialFrameSkip: 0
    $name: Acrylic backdrop initial frame skip
    $description: Number of WGC frames to skip before replacing the fallback frame (Acrylic material only).
  - BackdropFallbackBlurPasses: 5
    $name: Acrylic backdrop fallback blur passes
    $description: Blur strength for the animation-period fallback frame (Acrylic material only).
  - BackdropFallbackCaptureScale: 2
    $name: Acrylic backdrop fallback capture scale
    $description: Lower values sample more pixels; higher values are faster but softer (Acrylic material only).
'''

# replace settings block
m = re.search(r"(// ==WindhawkModSettings==\n/\*\n)(.*?)(\*/\n// ==/WindhawkModSettings==)", t, re.S)
assert m, "settings block not found"
t = t[:m.start(2)] + new_yaml + t[m.end(2):]

# remove orphan function ApplyOptimisticFavoriteToggle (block by name)
lines = t.split("\n")
start = None
for i, line in enumerate(lines):
    if line.startswith("void ApplyOptimisticFavoriteToggle(") and ";" not in line.rstrip()[-2:]:
        start = i
        break
    if line.startswith("void ApplyOptimisticFavoriteToggle(") and not line.rstrip().endswith(";"):
        start = i
        break
assert start is not None, "ApplyOptimisticFavoriteToggle definition not found"
depth = 0
seen = False
end = None
for j in range(start, len(lines)):
    depth += lines[j].count("{") - lines[j].count("}")
    if "{" in lines[j]:
        seen = True
    if seen and depth == 0:
        end = j
        break
assert end is not None
print("removing definition lines", start + 1, "-", end + 1, ":", lines[start].strip())
del lines[start:end + 1]
# remove its forward declaration if present
decls = [i for i, line in enumerate(lines) if line.strip() == "void ApplyOptimisticFavoriteToggle();"]
for i in reversed(decls):
    print("removing declaration at line", i + 1)
    del lines[i]
# collapse blank lines left behind
text = "\n".join(lines)
text = re.sub(r"\n\n\n+", "\n\n", text)

# align Settings struct defaults with YAML
text = text.replace("int liquidGlassFrost = 18;", "int liquidGlassFrost = 12;")
text = text.replace("int liquidGlassRefraction = 0;", "int liquidGlassRefraction = 6;")

io.open(p, "w", encoding="utf-8", newline="\n").write(text)
print("settings rewritten, lines:", len(text.split("\n")))
