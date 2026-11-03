# Changelog

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
