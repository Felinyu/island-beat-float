import io, re

base = r"C:\dsh\work\island-fork"
src = base + r"\island-fork.wh.cpp"
raw = io.open(src, encoding="utf-8", errors="replace").read()
lines = raw.split("\n")
orig_count = len(lines)

def line_no(idx0):
    return idx0 + 1

ops = []  # (pos, kind, text) kind: 'delete' with (s,e) encoded separately

deletions = [
    (1697, 1699, "orphan: IslandBackgroundBrush"),
    (2149, 2163, "orphan: MediaThumbFingerprint"),
    (4269, 4286, "orphan: LooksLikeNeteaseFavoriteControl"),
    (6664, 6666, "orphan: PopupBackdropWgcBlurStdDev"),
    (7830, 7845, "orphan: EmbeddedIconBitmap"),
    (7847, 7857, "orphan: MakeEmbeddedIconImage"),
    (1351, 1351, "dead global g_popupArtClickArmed"),
    (12240, 12240, "dead global g_lastTopmostGuardTime"),
    (255, 255, "unused include appmodel.h"),
    (256, 256, "unused include fstream"),
    (257, 257, "unused include shellapi.h"),
    (333, 333, "duplicate winrt Foundation include"),
    (352, 352, "missing placeholder asset include"),
    (161, 162, "dead setting ExpandedHeight YAML"),
    (214, 216, "dead setting LiquidGlassOpacity YAML"),
    (229, 231, "dead setting LiquidGlassHighlight YAML"),
    (244, 246, "dead setting BackdropWgcBlurStdDev YAML"),
    (769, 769, "dead settings field expandedHeight"),
    (786, 786, "dead settings field liquidGlassOpacity"),
    (791, 791, "dead settings field liquidGlassHighlight"),
    (796, 796, "dead settings field backdropWgcBlurStdDev"),
    (1874, 1874, "dead read Main.ExpandedHeight"),
    (1921, 1922, "dead read Main.LiquidGlassOpacity"),
    (1931, 1932, "dead read Main.LiquidGlassHighlight"),
    (1941, 1942, "dead read Main.BackdropWgcBlurStdDev"),
]

banners = [
    (253, "Includes"),
    (373, "Compatibility shims"),
    (427, "WinRT type aliases"),
    (469, "Implementation (anonymous namespace)"),
    (471, "Backdrop blur effects (D2D / WinRT)"),
    (764, "Core types"),
    (918, "Global state"),
    (1443, "Shared helpers"),
    (1846, "Settings"),
    (1948, "Taskbar host utilities"),
    (2149, "Media state model"),
    (2450, "NetEase Cloud Music - local data"),
    (3041, "NetEase Cloud Music - remote artwork"),
    (3392, "Process snapshot cache"),
    (3455, "Bilibili integration"),
    (3799, "NetEase Cloud Music - UI automation"),
    (4511, "Media source classification"),
    (4598, "Media refresh and commands"),
    (4740, "Artwork pipeline"),
    (6222, "Popup design system"),
    (6826, "Transport routing"),
    (6916, "Popup text foregrounds"),
    (7052, "Popup material brushes"),
    (7185, "Popup geometry and animation state"),
    (7376, "Popup window plumbing"),
    (7798, "Popup controls and theming"),
    (8611, "Popup XAML host"),
    (9251, "Popup visual update"),
    (10544, "Popup positioning"),
    (10611, "Compact island render loops"),
    (11231, "Popup progress, seek and close state machine"),
    (11949, "Taskbar tracking and z-order"),
    (12496, "Popup render loop and window procedure"),
    (12840, "WGC liquid-glass backdrop"),
    (14728, "CPU backdrop fallback and overlay windows"),
    (15742, "Popup hit window and lifecycle"),
    (16180, "Hover and expanded state"),
    (16448, "Media thread"),
    (16746, "Compact island UI construction"),
    (17335, "Taskbar layout monitor"),
    (17436, "Player contents update"),
    (17962, "Compact island grid injection"),
    (18181, "Settings application and shell callbacks"),
    (18251, "Hooks"),
    (18341, "Mod lifecycle"),
]

ops = []
for s, e, label in deletions:
    ops.append(("delete", s, e, label))
for pos, name in banners:
    banner = ["", "// ===== " + name + " ====="]
    ops.append(("insert", pos, None, banner))

ops.sort(key=lambda o: (o[1], 0 if o[0] == "delete" else 1), reverse=True)

removed = 0
for kind, a, b, payload in ops:
    if kind == "delete":
        del lines[a - 1:b]
        removed += b - a + 1
    else:
        lines[a - 1:a - 1] = payload

text = "\n".join(lines)

# ---- comment rewrites ----
repls = [
    ("//          0.9.50 diagnostic: Acrylic uses a separate native overlay window behind",
     "// Acrylic uses a separate native overlay window behind"),
    ("which reduced 1.4.1 to a dark translucent tint.",
     "which leaves a dark translucent tint."),
    ("bright flashing rectangle seen in 1.3.1.",
     "bright flashing rectangle artifact."),
    ("""    // Keep light and dark tint strengths independent. Light mode keeps the
    // stronger white-tint experiment, while dark mode is rolled back to the
    // earlier compact-material-d-backdrop-card-tint values.""",
     """    // Keep light and dark tint strengths independent; light mode needs a
    // stronger white tint so the controls stay legible over bright artwork."""),
    ("""    // Keep the overlay geometry exactly aligned to the XAML backdrop shell.
    // The previous inset experiment helped hide hard native edges in some
    // cases, but it made the blur layer visibly disagree with the component
    // shape. For this test, prefer exact shape matching and remove all extra
    // XAML tint/gray layers instead.""",
     """    // Keep the overlay geometry exactly aligned to the XAML backdrop shell.
    // Exact shape matching looks better than an inset: the inset hid hard
    // native edges but made the blur layer disagree with the component shape,
    // so no extra XAML tint/gray layers are used."""),
    ("""    // Artwork can be refreshed repeatedly while the media item itself hasn't
    // changed (this is especially common for browser-backed sessions). The
    // old code included the thumbnail hash in compactTextChanged, so every
    // refreshed frame restarted the title/artist slide. While the translated
    // TextBlocks crossed the host clip, XAML repeatedly rendered only their
    // ellipsis. Text motion must be keyed exclusively to text metadata; album
    // artwork already has its own independent transition below.""",
     """    // Artwork can be refreshed repeatedly while the media item itself hasn't
    // changed (especially for browser-backed sessions). Text motion must be
    // keyed to text metadata only: including the thumbnail hash restarted the
    // title/artist slide on every refreshed frame and made XAML render only
    // the ellipsis while the TextBlocks crossed the host clip. Album artwork
    // has its own independent transition below."""),
]
for old, new in repls:
    if old not in text:
        print("WARN: comment replacement not found:", old.split("\n")[0][:70])
        continue
    text = text.replace(old, new, 1)

# ---- whitespace normalization ----
out = []
blank = 0
for line in text.split("\n"):
    line = line.rstrip()
    if line == "":
        blank += 1
        if blank > 2:
            continue
    else:
        blank = 0
    out.append(line)
while out and out[-1] == "":
    out.pop()
text = "\n".join(out) + "\n"

io.open(src, "w", encoding="utf-8", newline="\n").write(text)
print("deleted lines:", removed)
print("banners:", len(banners))
print("lines:", orig_count, "->", len(out) + 1)
