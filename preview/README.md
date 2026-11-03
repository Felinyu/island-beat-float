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

The compact artboard models the **3.1.4** layout: the new arc spin-toggle next
to the cover and the text block shifted 13 DIP to the right. The newest real
capture is still 3.1.3, so those two changes are the intended differences in
`compare/compact.png`; the expanded artboard is unchanged.

| Artboard | Query | Output |
| --- | --- | --- |
| Compact taskbar island | `preview.html?view=compact` | `../screenshots/compact.png` (385x110) |
| Expanded floating player | `preview.html?view=expanded` | `../screenshots/expanded.png` (720x1280) |
| README hero banner | `preview.html?view=hero` | `../screenshots/hero.png` (1600x875) |

Open `preview/preview.html` in a browser to see every artboard stacked (no
query string = browsing mode).

## Compact island (3.1.4)

Deployed 3.1.4 screen-space values (pill 154 x 40 DIP), used verbatim
(`Main.Height = 40`, `Main.CompactWidth = 154`):

| Element | DIP | 2x px in the image |
| --- | --- | --- |
| Pill | 154 x 40, radius 20, 1 DIP light rim, flat translucent dark fill | 308 x 80 |
| Cover circle | x 4..36, y 4..36 (32 DIP, centre 20,20 = left cap centre) | 64 |
| Cover rim | 1 DIP light ring outside the circle | 2 |
| Arc spin-toggle | layout box x 38, y 10, 12 x 20 (2 DIP after the cover, vertically centred) | x 76, y 20 |
| Text block | x 55.5..123.5, width 68 (was 42.5..123.5, width 81 in 3.1.3) | 111..247 |
| Title | 12 DIP SemiBold, line box 14.5 | ink y 8..16.5 |
| Artist | 10 DIP Regular, line box 12 | ink y 22.5..31.5 |
| Equalizer | 5 bars 2.5 wide / 1.0 gaps (16.5 DIP) centred in the 18 DIP indicator at right inset 7 (bars 129.75..146.25) | 259.5..292.5 |
| Pill end cap | right edge 154, bar inset 7 | 14 |

### Arc spin-toggle (new in 3.1.4)

The toggle is a thin **right-half ring**: a 20 DIP diameter circle (r = 10,
like the real `Ellipse`) with its left half clipped away at the vertical
diameter, i.e. a semicircular ")" bracket. The real UI draws a stroked ellipse
and clips it with `RectangleGeometry(0, -0.9, 12, 21.8)`; the mockup does the
same in SVG: the arc path covers only the 180 degree right half and the SVG
viewport (`overflow: hidden`, box x 0 = vertical diameter) clips the round
end caps' left halves.

| Draw value | Value |
| --- | --- |
| Layout box (CSS/DIP) | `left: 38`, `top: 9.1`, `width: 12`, `height: 21.8` (the arc column is x 38..50, y 10..30) |
| SVG | `viewBox="0 0 12 21.8"`, default clipping |
| Path | `M 0 0.9 A 10 10 0 0 1 0 20.9` (start top, end bottom at the vertical diameter, r = 10, sweep 1 = bulge right) |
| Stroke | 1.8 DIP, round caps, `fill: none`, round end discs = the real cap ellipses |
| Colour | themed light foreground (`currentColor` = #FFFFFF) at `opacity: 0.55` |
| Visible ink | 10.9 x 21.8 DIP at x 38.0..48.9, y 9.1..30.9 (centre 43.45, 20.0) |

The 12 x 20 DIP layout slot is centred on the pill's centre line (y 10..30).
The stroke/caps extend 0.9 DIP above and below that slot, so the element is
21.8 DIP tall; the right side of the 12 DIP column keeps 1.1 DIP of space
between the ring's outer edge (10.9) and the column edge (12).

### Text block shift (3.1.4)

The block moves right by 13 DIP: the new column is
`4 (artInset) + 32 (cover) + 2 (gap) + 12 (arc) + 5.5 (textMarginX) = 55.5`
DIP, so the text block is x 55.5..123.5 and the right side is untouched.

Measured from the rendered PNG (pill top-left at 38.5/15 px, all gaps in DIP):

- cover artwork right edge 36.0 -> arc ink left 38.0 = **2.0 DIP gap** (nominal
  cover 36 -> arc column 38 = 2.0)
- arc ink right edge 48.9 -> title ink left 54.25 = **5.35 DIP gap** (nominal
  arc column 50 -> text block 55.5 = 5.5; the text ink starts ~1 DIP before the
  block edge)
- title ink right edge 123.75 (artist 121.75) -> bars left 129.75 = **6.0 DIP
  gap** (close to the 3.1.4 block-edge gap of 123.5 -> 129.75 = 6.25)
- bars right edge 146.25 -> pill right 154 = **7.75 DIP gap** (unchanged from
  3.1.3)

The equalizer bar count/width/pitch and the right side are untouched: every
comparable anchor is within 1 px at 2x (see the fidelity table below).

Two deliberate deviations from the real text rendering:

- the 3.1.4 text block is 13 DIP narrower, so the two placeholder lines are
  condensed slightly (`transform: scaleX(0.93)` on the block plus -0.075em /
  -0.03em tracking) to keep the *complete* idle text visible - the real UI
  ellipsizes both lines at this width; the showcase has always shown the full
  placeholder instead;
- the two-line block is placed so the *ink* is centred like the capture
  (title ink top 8.5 DIP, artist ink bottom 32 DIP, ink-block centre 20.25 DIP,
  the same as the real 3.1.3 capture).

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
python preview/build.py                 # all three artboards
python preview/build.py compact hero    # only the named artboards
python preview/compare.py compact       # only the named comparison
```

Single-view artboards are anchored at a fixed `(40, 40)` CSS offset and the
window is the artboard plus 2 x 40 px: Edge reports a viewport a few pixels
wider than `--window-size` below ~500 px, which would shift a flex-centred
artboard. The screenshot is cropped back to the artboard rectangle, then given
softly rounded corners.

## Fidelity check

`preview/reference/` contains the real 2x panel captures extracted from git
history: `real-compact-3.1.3.png` (335 x 110, live 3.1.3 island),
`real-taskbar-3.1.3.png` (full 2880 x 130 taskbar strip), and
`real-expanded-3.1.1.png` (1100 x 1000, card top cropped); the 3.0.0/3.1.1
captures are kept for history. They are measurement references only - the
README uses the rendered mockups.

```powershell
python preview/compare.py
```

writes 1:1 comparisons into `preview/compare/`:

- `compact.png` - real 3.1.3 capture | rendered 3.1.4 mockup | 50 % overlay,
  all at the same 2x pixel scale, overlay aligned on the pill top-left corner;
  the two panes are labelled with the expected 3.1.4 differences (new arc
  toggle and the +13 DIP text shift), since the newest real capture is 3.1.3;
- `expanded.png` - real card | rendered card | overlay aligned on the card
  bottom edge (the only common anchor, since the real capture is top-cropped).

Measured per-element deltas between `real-compact-3.1.3.png` and
`screenshots/compact.png` (pill top-left normalised, 2x pixels):

| Element | real 3.1.3 | render 3.1.4 | delta |
| --- | --- | --- | --- |
| pill bounds | 308 x 80 px, top 0 bottom 80 | same | 0 px |
| cover circle | x 4.0..36.0 DIP, y 4.0..36.0 | x 4.0..36.0, y 4.0..36.0 | 0 px |
| arc spin-toggle | absent (3.1.3) | x 38.0..48.9, y 9.1..30.9 | intended |
| text ink left | 41.5 DIP | 54.25 DIP | intended +12.75 DIP |
| title ink top | 8.0 DIP | 8.5 DIP | +1 px |
| artist ink top / bottom | 23.0 / 32.5 DIP | 22.5 / 32.0 DIP | -1 / -1 px |
| equalizer bars left / right / top | 130.0 / 146.0 / 15.5 DIP | 130.0 / 146.0 / 15.0 DIP | 0 / 0 / -1 px |

The title/artist *right* edges and the title-ink bottom are not comparable:
the capture shows the real track ("凤梨Felinyu" / "Felinyu", CJK caps), the
mockup the idle placeholder ("Island Beat Float" / "No media playing", Latin
caps). Only the expanded panel has no 3.1.3 capture yet, so that comparison
still uses the 3.1.1 capture.
