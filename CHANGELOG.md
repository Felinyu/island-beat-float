# Changelog

## 3.1.19

- Reverted the experimental progress-bar splitting transition (3.1.17/3.1.18);
  the original spring open/close morph is back and the progress bar behaves
  normally again.

## 3.1.18

- Experimental: progress bar split inside the collapse/expand morph (removed
  again in 3.1.19).

## 3.1.17

- Experimental: decorative progress-bar split pieces on collapse/expand
  (removed again in 3.1.19).

## 3.1.16

- NetEase Cloud Music progress sync fixes: a track change (in-app or from the
  island) now resets the displayed progress to 00:00 and discards the previous
  track's samples instead of inheriting its position; progress is recalibrated
  against the freshest sample on a 500 ms cadence while a NetEase session is
  active; seeking publishes the target position immediately and holds it until
  the provider catches up so backward seeks are not undone.

## 3.1.15

- Double-clicking the arc in the resting compact state now reliably stops the
  spin and snaps the cover upright (the hit window class now receives
  double-click messages, with a fallback two-tap detector on both the popup
  compact endpoint and the taskbar island).

## 3.1.14

- Flash-free collapse: the popup's compact endpoint remains the resting surface
  (no cross-surface handoff frame), and the compact arc toggle is drawn on that
  endpoint too, so the arc stays visible after opening and closing the player
  and never blinks during the morph.
- The vinyl spin and ring hit routing now work in the resting compact endpoint
  as well.

## 3.1.13

- Fixed the arc disappearing after opening and closing the player by handing the
  resting compact state back to the real taskbar island (superseded by the
  flash-free approach in 3.1.14).

## 3.1.12

- Reverted the arc layout/rendering subsystem to the proven 3.1.8
  implementation, keeping the 3.1.9 animation/startup work; arc parameters:
  77 degrees, 4.5 DIP stroke, 2.7 DIP gap from the cover.

## 3.1.11

- Arc cold-start visibility experiments (superseded by 3.1.12/3.1.14).

## 3.1.10

- Forced arc re-application after popup close (superseded by 3.1.12/3.1.14).

## 3.1.9

- Attempted cold-start arc recovery, new track-change animation (crossfade +
  vertical settle replacing the horizontal slide) and faster startup injection;
  the animation and startup changes are kept, the arc recovery was superseded.

## 3.1.8

- Compact arc: 80 degrees, 3.7 DIP gap, 4 DIP stroke; asymmetric text margins
  (right margin 4 DIP) so the title gets a longer text box without widening the
  island.

## 3.1.7

- Compact arc parameters: 87 degrees, 4 DIP stroke, text starting at 50 DIP.

## 3.1.6

- Compact arc: 90 degrees, 3 DIP gap, 3.7 DIP stroke, text shifted clear of the
  arc to 44.5 DIP.

## 3.1.5

- Compact arc spin toggle redesigned per feedback: the bracket column is gone
  (text returns to starting right after the cover) and the toggle is now a
  thicker 120-degree accent-coloured arc hugging the right edge of the circular
  cover, concentric with it and never overlapping the artwork; spin is slowed to
  ~33 deg/s, and double-tapping the arc stops the spin and snaps the cover back
  upright.

## 3.1.4

- Compact cover spin toggle: a thin semicircular arc bracket (a rounded ")"
  drawn from a clipped stroked ellipse) now sits to the right of the circular
  cover. Tapping it starts a slow vinyl-style rotation of the album art;
  tapping it again freezes the cover at its current angle. The artwork and its
  cross-fade rotate together inside the fixed circular clip (RenderTransform
  only, no layout work), the rotation survives media changes, and the tap is
  handled so it never opens the expanded player.
- Compact layout: the arc toggle gets its own 14 DIP grid column (2 DIP gap +
  12 DIP arc) between the cover and the text, so the text column starts about
  55.5 DIP from the pill's left edge (cover inset 4 + cover 32, 2 DIP gap,
  12 DIP arc, 5.5 DIP text margin). The round caps and themed 0.55-opacity
  stroke scale with the island height; the right side keeps the 7 DIP content
  padding and 7 DIP equalizer inset, and the compact text clip/edge-fade
  fallbacks account for the new column.
- In-mod README (English and Chinese) documents the arc spin toggle.

## 3.1.3

- Compact layout: the right content padding (7 DIP) and the equalizer leading
  margin (1 DIP) are tuned so the three horizontal gaps read evenly:
  cover -> text ~5.5 DIP, text -> equalizer ~6.5 DIP, equalizer -> pill edge
  ~7 DIP.

## 3.1.2

- Compact layout: balanced cover-to-text and text-to-equalizer spacing. The
  text margin now scales as `Clamp(5.5 * scale, 3, 8)` DIP instead of
  `Clamp(4 * scale, 2, 6)`, widening the cover-to-text gap by 1.5 DIP and
  narrowing the text column by 3 DIP, so the text sits evenly between the
  circular cover and the right-anchored equalizer.

## 3.1.1

- The compact artwork circle is now concentric with the pill's left rounded end
  cap. Its bounds start at ((H - D) / 2, (H - D) / 2) from the pill's left/top
  edge (H = island height, D = cover diameter), so the cover shares the cap
  centre (H/2, H/2) instead of being pushed right by the padded content box; the
  text column still starts after the circle plus the usual gap.

## 3.1.0

UI and personalisation update.

- Circular compact artwork: the collapsed cover is clipped to a circle whose
  diameter equals the island's inner height, so its curvature matches the pill's
  rounded ends. The expanded cover keeps its rounded-square shape and the circle
  follows `Height` changes.
- New `DefaultCoverImage` setting: optional image file shown as the cover while
  no media session is active (validated and decoded with the existing WIC
  artwork pipeline). Empty/invalid paths keep the built-in placeholder.
- New `DefaultTitle` and `DefaultArtist` settings for the idle text shown on the
  compact island and expanded player when no media session is active
  (defaults: "Island Beat Float" / "No media playing").
- New `AccentColorMode` (`artwork` / `custom`) and `AccentColor` settings. A
  custom accent colours the compact equalizer bars, the expanded playback
  indicator and the accent-derived progress glow; invalid hex values safely
  fall back to artwork mode.
- Island `Height` range widened to 28-72 DIP. Compact padding, artwork circle,
  fonts, equalizer and progress geometry scale with it.
- README and in-mod documentation updated for the new features and settings.

## 3.0.0

First public release of Island Beat Float, a heavily reworked fork of
[Island Media Controls](https://github.com/usho-lear/island-media-controls)
by usho (MIT).

- Renamed and rebranded to Island Beat Float.
- Cleaned up the code base: removed unused functions/constants, dead `#if 0`
  blocks, debug logging and placeholder assets; added section banners and a
  consistent clang-format pass (about 1,000 lines removed).
- Settings reorganized into groups (placement, size and margins, expanded
  player, appearance, artwork, animation, advanced) and every setting got a
  description.
- Localized the mod description for Chinese (`@description:zh-CN`).
- New README with feature overview, installation and licensing/credits.

Based on Island Media Controls 2.5.26.
