import io, re

p = r"C:\dsh\work\island-beat-float\island-beat-float.wh.cpp"
t = io.open(p, encoding="utf-8", errors="replace").read()

# ---- metadata ----
old_meta = """// @id              island-media-controls-fork
// @name            Island Media Controls - Fork
// @description     Dynamic island-like media controls for the Windows 11 taskbar.
// @version         2.5.26
// @author          usho
// @github          https://github.com/usho-lear
// @license         MIT
"""
new_meta = """// @id              island-beat-float
// @name            Island Beat Float
// @description     Dynamic Island style floating music controller for Windows: a compact taskbar island that shows the current track, and expands into a full media player.
// @description:zh-CN 动态岛风格的 Windows 悬浮音乐控制器：任务栏小岛实时显示当前歌曲与封面，点击展开完整播放器。
// @version         3.0.0
// @author          Felinyu
// @github          https://github.com/Felinyu
// @license         MIT
"""
assert old_meta in t, "metadata block not found"
t = t.replace(old_meta, new_meta, 1)

# ---- readme ----
readme = r'''// ==WindhawkModReadme==
/*
# Island Beat Float

**Dynamic Island style floating music controller for Windows.**

Island Beat Float puts the current media session into the Windows 11 taskbar as
a compact, clickable island. It shows the artwork, title, artist, playback state
and progress at a glance; click it and the island expands into a floating player
with a seekable progress bar and previous / play-pause / next controls. The
expanded panel morphs back into the compact island when it closes.

## Features

- **Compact taskbar island** - artwork, title, artist, playback indicator and
  progress in one slim pill, placed near the tray, the clock or either taskbar
  edge (seven positions).
- **Expanded floating player** - large artwork, seekable progress bar, transport
  buttons, album-colour wash, optional single-card layout, and a smooth
  open/close morph that hands off to the compact island.
- **Materials** - Mica-like, solid, acrylic/glass and Liquid Glass, with an
  album gradient option, adjustable corner radius and an optional screen-capture
  exclusion for the expanded panel.
- **Artwork pipeline** - uses the media session artwork; for low-resolution
  browser/video thumbnails it can generate a mesh-gradient or flame artwork
  instead, and it extracts an adaptive palette for accents and the album wash.
- **Taskbar-position aware** - the island follows the taskbar when it moves,
  stays anchored above it, adapts the expand direction, and raises only the
  expanded panel above shell surfaces such as the Start menu.
- **Animations** - hover scale and smoothing, spring-based panel animation and a
  slow-motion preview speed.
- **Music app integrations** - NetEase Cloud Music (playback state, seek,
  favourite, artwork) and Bilibili (now-playing metadata) are supported in
  addition to the standard Windows media sessions.
- **Multi-monitor friendly** - per-taskbar placement and popup positioning, with
  the island following the taskbar it lives on.

## Settings

All visual and behavioural knobs are in the mod settings (grouped as placement,
size and margins, expanded player, appearance, artwork, animation, advanced):
island position/height/width, margins, expanded panel width and layout,
spacing/shadow, button style, material and Liquid Glass options, album wash,
artwork mode, hover and animation speeds, and advanced backdrop/capture
options. Settings are English; a Chinese translation is planned.

## Installation

1. Install [Windhawk](https://windhawk.net/).
2. Open Windhawk → **Mods** → **Create a New Mod**.
3. Use `island-beat-float` as the mod identifier and paste the contents of
   `island-beat-float.wh.cpp`.
4. Compile, install and enable the mod, then restart Explorer.

The mod replaces the taskbar clock icon content on each taskbar and injects the
compact island next to it; disabling the mod restores the native elements.

## Compatibility

Windows 11 only. Tested on Windows 11 26H2 (build 26300). The mod hooks internal
taskbar symbols, so a future Windows update may require an updated version.

## Credits and license

Based on **Island Media Controls** by [usho](https://github.com/usho-lear),
licensed under the MIT license; this fork is a heavily modified version with a
new name, reworked layout/animation pipeline, material system, artwork pipeline
and music-app integrations. MIT licensed - see `LICENSE`.

# 中文说明

**动态岛风格的 Windows 悬浮音乐控制器。**

Island Beat Float 把当前媒体会话放进 Windows 11 任务栏，变成一个可点击的小岛：
显示封面、歌名、歌手、播放状态和进度；点击后小岛展开为悬浮播放器，带可拖动的
进度条和上一首/播放暂停/下一首按钮，关闭时再收拢回任务栏小岛。

主要功能：7 种任务栏位置；展开面板的液态玻璃/亚克力/纯色/类 Mica 材质与专辑
渐变；封面自适应调色板与专辑色氛围；低分辨率视频封面可改用网格渐变/火焰封面；
跟随任务栏位置与展开方向；悬停与展开动画可调速（含慢动作预览）；支持网易云音乐
和哔哩哔哩集成；多显示器任务栏适配。

设置项按「位置 / 尺寸与边距 / 展开面板 / 外观 / 封面 / 动画 / 高级」分组，可调
岛屿位置、高度、宽度、展开面板宽度与布局、材质、液态玻璃参数、专辑氛围、封面
模式、悬停与动画速度等。

本项目基于 usho 的 **Island Media Controls**（MIT 协议）修改而来，使用 MIT 协议
开源，详见 `LICENSE`。
*/
// ==/WindhawkModReadme==
'''
m = re.search(r"// ==WindhawkModReadme==\n/\*\n.*?\*/\n// ==/WindhawkModReadme==", t, re.S)
assert m, "readme block not found"
t = t[:m.start()] + readme.rstrip("\n") + t[m.end():]

io.open(p, "w", encoding="utf-8", newline="\n").write(t)
print("metadata + readme updated; bytes:", len(t.encode("utf-8")))
