# Changelog

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
