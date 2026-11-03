# Showcase mockups

Rendered product mockups of the Island Beat Float UI, used by the README
instead of raw desktop screenshots. Everything is plain HTML, CSS and inline
SVG - no photos, no personal data, no external assets - so the images can be
regenerated on any Windows machine with Edge.

The artboards are built at **1 CSS px per DIP** and rendered at
`--force-device-scale-factor=2`, so every image pixel is 2x the real UI. The
PNGs line up 1:1 with the real 2x captures in `reference/`; the only intended
differences are the clean gradient backdrop instead of the desktop/wallpaper,
the generated abstract artwork instead of a real cover, and the placeholder
idle text instead of a real track.

| Artboard | Query | Output |
| --- | --- | --- |
| Compact taskbar island | `preview.html?view=compact` | `../screenshots/compact.png` (385x110) |
| Expanded floating player | `preview.html?view=expanded` | `../screenshots/expanded.png` (720x1280) |
| README hero banner | `preview.html?view=hero` | `../screenshots/hero.png` (1600x875) |

Open `preview/preview.html` in a browser to see every artboard stacked (no
query string = browsing mode).

## Compact island (3.1.3)

Deployed 3.1.3 screen-space values (pill 154 x 40 DIP), used verbatim
(`Main.Height = 40`, `Main.CompactWidth = 154`):

| Element | DIP | 2x px in the image |
| --- | --- | --- |
| Pill | 154 x 40, radius 20, 1 DIP light rim, flat translucent dark fill | 308 x 80 |
| Cover circle | x 4..36, y 4..36 (32 DIP, centre 20,20 = left cap centre) | 64 |
| Cover rim | 1 DIP light ring outside the circle | 2 |
| Title/artist block | x 42.5, width 81 | 85..247 |
| Title | 12 DIP SemiBold, line box 14.5 | ink y 8..16.5 |
| Artist | 10 DIP Regular, line box 12 | ink y 22.5..31.5 |
| Equalizer | 5 bars 2.4 wide / 0.75 gaps, right-aligned to x 147 | right at 294 |
| Pill end cap | right edge 154, bar inset 7 | 14 |

Measured from the rendered PNG (pill top-left at 38.5/15 px):

- cover artwork right edge 36.0 DIP -> title ink 43.75 DIP = **7.75 DIP gap**
  (15.5 px); measured from the 1 DIP cover ring (37.0) it is 6.75 DIP (13.5 px)
- title/artist ink right edge 122.75 DIP -> bars left 132.25 DIP =
  **9.5 DIP gap** (19 px); block-edge gap (123.5 -> 131.25) is 7.75 DIP
- bars right edge 146.75 DIP -> pill right 154 DIP = **7.25 DIP gap** (14.5 px)

Two deliberate deviations from the real text rendering:

- the idle title "Island Beat Float" is 12 DIP with -0.045em tracking so the
  full title fits the real 81 DIP text block (the real UI would ellipsize it);
- the two-line block is placed so the *ink* is centred like the capture
  (title ink top 8 DIP, artist ink bottom 31.5 DIP, block top 5 DIP).

The equalizer accent `#8CC8EE` is the light-blue accent sampled from the
abstract artwork, mirroring the real capture's artwork-driven light-blue bars.

## Expanded player

Visible surface 324 x 578 DIP (Liquid Glass, radius 46), rendered at
720 x 1280 px on the 360 x 640 artboard:

| Element | DIP | Element | DIP |
| --- | --- | --- | --- |
| Card surface | 324 x 578, radius 46 | Artwork | 20,20, 284 square, radius 16 |
| Content column | x 38, width 248 | Title | 16 DIP Bold, baseline ~347 |
| Artist | 13 DIP, baseline ~372 | Progress | y 403, h 6, r 3 |
| Times | 11 DIP, y 415 | Transport | 52 x 58 buttons at 80/136/192, y 445 |
| Glyphs | EB9E / E768 / EB9D, 32 / 38 DIP | Volume | track x 66, y 530, 192 x 6, fill 56% |
| Volume icons | E992 / E767, 18 / 20 DIP | | |

All values come from `CalculatePopupFinalLayout()` / `UpdatePopupXamlVisuals()`.
The real 3.1.1 capture is cropped at the top (card top is above the screenshot),
so the comparison aligns the card bottoms.

## Rebuild

Requires Windows, Microsoft Edge (headless) and Python 3 with Pillow:

```powershell
python preview/build.py
```

Single-view artboards are anchored at a fixed `(40, 40)` CSS offset and the
window is the artboard plus 2 x 40 px: Edge reports a viewport a few pixels
wider than `--window-size` below ~500 px, which would shift a flex-centred
artboard. The screenshot is cropped back to the artboard rectangle, then given
softly rounded corners.

## Fidelity check

`preview/reference/` contains the real 2x panel captures extracted from git
history: `real-compact-3.1.1.png` (335 x 110) and
`real-expanded-3.1.1.png` (1100 x 1000, card top cropped). The 3.0.0 captures
are kept for history. They are measurement references only - the README uses
the rendered mockups.

```powershell
python preview/compare.py
```

writes 1:1 comparisons into `preview/compare/`:

- `compact.png` - real capture | rendered mockup | 50 % overlay, all at the
  same 2x pixel scale, overlay aligned on the pill top-left corner;
- `expanded.png` - real card | rendered card | overlay aligned on the card
  bottom edge (the only common anchor, since the real capture is top-cropped).

Note: the committed real capture is 3.1.1, which predates the 3.1.3 balanced
spacing (content padding 7 DIP, indicator margin 1 DIP). The mockup implements
the deployed 3.1.3 metrics, so in the 3.1.1 comparison the text starts ~2.5 DIP
later and the equalizer ends ~4 DIP later than in the capture.
