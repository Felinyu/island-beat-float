// ==WindhawkMod==
// @id              island-beat-float
// @name            Island Beat Float
// @description     Dynamic Island style floating music controller for Windows: a compact taskbar island that shows the current track, and expands into a full media player.
// @description:zh-CN 动态岛风格的 Windows 悬浮音乐控制器：任务栏小岛实时显示当前歌曲与封面，点击展开完整播放器。
// @version         3.1.8
// @author          Felinyu
// @github          https://github.com/Felinyu
// @license         MIT
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -lole32 -loleaut32 -lruntimeobject -lwindowsapp -luuid -luser32 -lshell32 -lgdi32 -lmsimg32 -lshlwapi -lwindowscodecs -ldwmapi -luiautomationcore -lwinhttp -ld3d11 -ldxgi -ld2d1 -ldcomp -lcomctl32
// ==/WindhawkMod==

// ==WindhawkModReadme==
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
- **Circular compact cover** - the collapsed artwork is clipped to a circle
  whose diameter matches the island's inner height, so its curvature lines up
  with the pill's rounded ends; the expanded cover stays a rounded square.
- **Compact arc spin toggle** - a thin semicircular bracket next to the cover
  starts and stops a slow vinyl-style rotation of the cover. The artwork and
  its cross-fade rotate together inside the fixed circular clip, the text
  column sits to the right of the bracket, and clicking the bracket never
  opens the expanded player.
- **Idle state** - an optional default cover image, title and artist are shown
  before a media session starts (or while nothing is playing).
- **Accent colour** - the compact equalizer bars, expanded playback indicator
  and progress glow either follow the album artwork palette or use a custom
  accent colour.
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
island position, height (28-72 DIP) and width, margins, expanded panel width
and layout, spacing/shadow, button style, material and Liquid Glass options,
album wash, artwork mode, default cover image and idle title/artist, accent
colour mode, hover and animation speeds, and advanced backdrop/capture options.
Settings are English; a Chinese translation is planned.

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
折叠态封面为与胶囊曲率一致的圆形，展开态保持圆角方形；折叠态封面右侧的弧形
开关可切换封面像唱片一样缓慢旋转（再次点击停止）；无媒体时可显示自定义默认
封面、歌名与歌手；均衡器与进度条高光可跟随封面取色或使用自定义强调色；岛屿高度
支持 28-72 DIP 调节；跟随任务栏位置与展开方向；悬停与展开动画可调速（含慢动作
预览）；支持网易云音乐和哔哩哔哩集成；多显示器任务栏适配。

设置项按「位置 / 尺寸与边距 / 展开面板 / 外观 / 封面 / 动画 / 高级」分组，可调
岛屿位置、高度、宽度、展开面板宽度与布局、材质、液态玻璃参数、专辑氛围、封面
模式、默认封面与空闲文案、强调色模式、悬停与动画速度等。

本项目基于 usho 的 **Island Media Controls**（MIT 协议）修改而来，使用 MIT 协议
开源，详见 `LICENSE`。
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- Main:
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
    $description: Height of the compact island on the taskbar, from 28 to 72 DIP; the circular cover and the compact layout scale with it.
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
  - DefaultCoverImage: ""
    $name: Default cover image
    $description: Optional path to an image file shown as the cover while no media session is active. Leave empty to use the built-in placeholder.
  - DefaultTitle: "Island Beat Float"
    $name: Idle title
    $description: Title shown on the compact island and the expanded player while no media session is active.
  - DefaultArtist: "No media playing"
    $name: Idle artist
    $description: Artist line shown on the compact island and the expanded player while no media session is active.
  - AccentColorMode: "artwork"
    $name: Accent colour mode
    $description: Follow the current album artwork palette or use a fixed custom accent colour.
    $options:
    - "artwork": "Follow album artwork"
    - "custom": "Custom colour"
  - AccentColor: "#6EB85A"
    $name: Custom accent colour
    $description: Hex RGB colour in RRGGBB or AARRGGBB form, used when the accent colour mode is custom; invalid values fall back to following the album artwork.
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
*/
// ==/WindhawkModSettings==

// ===== Includes =====
#include <windows.h>
#include <windowsx.h>
#include <dwmapi.h>
#include <tlhelp32.h>
#include <uiautomation.h>
#include <winhttp.h>
#include <shlwapi.h>
#include <wincodec.h>
#include <commctrl.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audiopolicy.h>
#include <windows.ui.xaml.hosting.desktopwindowxamlsource.h>

#include <inspectable.h>
#include <d3d11.h>
#include <dxgi1_2.h>
#include <d2d1_1.h>
#include <d2d1_1helper.h>
#include <d2d1effects.h>
#include <dcomp.h>
#include <windows.graphics.effects.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Metadata.h>
#include <winrt/Windows.Security.Authorization.AppCapabilityAccess.h>
#include <winrt/Windows.Graphics.Capture.h>
#include <winrt/Windows.Graphics.DirectX.h>
#include <winrt/Windows.Graphics.DirectX.Direct3D11.h>
#include <winrt/Windows.Graphics.Effects.h>

// Windhawk's bundled SDK may miss the two small WinRT interop headers even
// though the WinRT projection and D3D/D2D headers are present. Define the
// minimal COM interfaces locally so the WGC path is actually compiled instead
// of silently falling back to the stub branch.
//
// Do not use __declspec(uuid) here: Windhawk's Clang/MinGW configuration ignores
// that attribute, which breaks winrt::guid_of<T>. Use explicit GUID constants
// and raw QueryInterface instead.
static constexpr GUID kIID_IGraphicsCaptureItemInterop{
    0x3628E81B,
    0x3CAC,
    0x4C60,
    {0xB7, 0xF4, 0x23, 0xCE, 0x0E, 0x0C, 0x33, 0x56}};
static constexpr GUID kIID_IDirect3DDxgiInterfaceAccess{
    0xA9B3D012,
    0x3DF2,
    0x4EE3,
    {0xB8, 0xD1, 0x86, 0x95, 0xF4, 0x57, 0xD3, 0xC1}};
static constexpr GUID kIID_IGraphicsCaptureItem{
    0x79C3F95B,
    0x31F7,
    0x4EC2,
    {0xA4, 0x64, 0x63, 0x2E, 0xF5, 0xD3, 0x07, 0x60}};
static constexpr GUID kCLSID_MMDeviceEnumerator{
    0xBCDE0395,
    0xE52F,
    0x467C,
    {0x8E, 0x3D, 0xC4, 0x57, 0x92, 0x91, 0x69, 0x2E}};

struct IGraphicsCaptureItemInterop : ::IUnknown {
    virtual HRESULT __stdcall CreateForWindow(HWND window,
                                              REFIID riid,
                                              void** result) = 0;
    virtual HRESULT __stdcall CreateForMonitor(HMONITOR monitor,
                                               REFIID riid,
                                               void** result) = 0;
};

struct IDirect3DDxgiInterfaceAccess : ::IUnknown {
    virtual HRESULT __stdcall GetInterface(REFIID iid, void** p) = 0;
};

extern "C" HRESULT __stdcall CreateDirect3D11DeviceFromDXGIDevice(
    IDXGIDevice* dxgiDevice,
    IInspectable** graphicsDevice);

#include <windhawk_utils.h>

#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

#include <winrt/base.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Numerics.h>
#include <winrt/Windows.Data.Json.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>

#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>

#include <algorithm>
#include <array>
#include <functional>
#include <atomic>
#include <chrono>
#include <cwctype>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <climits>
#include <condition_variable>
#include <deque>
#include <mutex>
#include <optional>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

// ===== Compatibility shims =====
#ifndef WS_EX_NOREDIRECTIONBITMAP
#define WS_EX_NOREDIRECTIONBITMAP 0x00200000L
#endif

#ifndef DWMWA_WINDOW_CORNER_PREFERENCE
#define DWMWA_WINDOW_CORNER_PREFERENCE 33
#endif

// Minimal windows.graphics.effects.interop.h surface used by the same
// CompositionBackdropBrush Gaussian implementation as WindhawkBlur.
namespace ABI::Windows::Graphics::Effects {
typedef interface IGraphicsEffectSource IGraphicsEffectSource;

enum GRAPHICS_EFFECT_PROPERTY_MAPPING {
    GRAPHICS_EFFECT_PROPERTY_MAPPING_UNKNOWN,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_DIRECT,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORX,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORY,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORZ,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORW,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_RECT_TO_VECTOR4,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_RADIANS_TO_DEGREES,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_COLORMATRIX_ALPHA_MODE,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_COLOR_TO_VECTOR3,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_COLOR_TO_VECTOR4,
};

struct __declspec(novtable) IGraphicsEffectD2D1Interop : IUnknown {
    virtual HRESULT STDMETHODCALLTYPE GetEffectId(GUID* id) = 0;
    virtual HRESULT STDMETHODCALLTYPE
    GetNamedPropertyMapping(LPCWSTR name,
                            UINT* index,
                            GRAPHICS_EFFECT_PROPERTY_MAPPING* mapping) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetPropertyCount(UINT* count) = 0;
    virtual HRESULT STDMETHODCALLTYPE
    GetProperty(UINT index,
                winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue>**
                    value) = 0;
    virtual HRESULT STDMETHODCALLTYPE
    GetSource(UINT index, IGraphicsEffectSource** source) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSourceCount(UINT* count) = 0;
};
}  // namespace ABI::Windows::Graphics::Effects

template <>
inline constexpr winrt::guid winrt::impl::guid_v<
    ABI::Windows::Graphics::Effects::IGraphicsEffectD2D1Interop>{
    0x2FC57384,
    0xA068,
    0x44D7,
    {0xA3, 0x31, 0x30, 0x98, 0x2F, 0xCF, 0x71, 0x77}};

template <>
inline constexpr winrt::guid winrt::impl::guid_v<
    winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue>>{
    winrt::impl::guid_v<winrt::Windows::Foundation::IPropertyValue>};

// ===== WinRT type aliases =====
namespace xaml = winrt::Windows::UI::Xaml;
namespace composition = winrt::Windows::UI::Composition;
namespace graphics_effects = winrt::Windows::Graphics::Effects;
namespace abi_graphics_effects = ABI::Windows::Graphics::Effects;
namespace controls = winrt::Windows::UI::Xaml::Controls;
namespace primitives = winrt::Windows::UI::Xaml::Controls::Primitives;
namespace input = winrt::Windows::UI::Xaml::Input;
namespace mediax = winrt::Windows::UI::Xaml::Media;
namespace imaging = winrt::Windows::UI::Xaml::Media::Imaging;
namespace shapes = winrt::Windows::UI::Xaml::Shapes;
namespace hosting = winrt::Windows::UI::Xaml::Hosting;
namespace streams = winrt::Windows::Storage::Streams;
namespace gsm = winrt::Windows::Media::Control;
namespace json = winrt::Windows::Data::Json;

namespace capture = winrt::Windows::Graphics::Capture;
namespace directx = winrt::Windows::Graphics::DirectX;
namespace direct3d11 = winrt::Windows::Graphics::DirectX::Direct3D11;

using controls::Border;
using controls::Button;
using controls::ColumnDefinition;
using controls::Grid;
using controls::Image;
using controls::ProgressBar;
using controls::StackPanel;
using controls::TextBlock;
using mediax::ScaleTransform;
using mediax::SolidColorBrush;
using mediax::TransformGroup;
using mediax::TranslateTransform;
using mediax::VisualTreeHelper;
using xaml::FrameworkElement;
using xaml::GridLength;
using xaml::GridUnitType;
using xaml::HorizontalAlignment;
using xaml::Thickness;
using xaml::UIElement;
using xaml::VerticalAlignment;
using xaml::Visibility;

// ===== Implementation (anonymous namespace) =====
namespace {

// ===== Backdrop blur effects (D2D / WinRT) =====
enum class ImmediateGaussianOptimization : uint32_t {
    Speed = 0,
    Balanced = 1,
    Quality = 2,
};

// Direct2D Gaussian effect description consumed by the Windows compositor.
// This is the small core of WindhawkBlur: its source is a live backdrop brush,
// so there is no screen-capture startup and no late first-frame replacement.
struct ImmediateGaussianEffect
    : winrt::implements<ImmediateGaussianEffect,
                        graphics_effects::IGraphicsEffect,
                        graphics_effects::IGraphicsEffectSource,
                        abi_graphics_effects::IGraphicsEffectD2D1Interop> {
    graphics_effects::IGraphicsEffectSource Source{nullptr};
    float BlurAmount = 25.0f;
    ImmediateGaussianOptimization Optimization =
        ImmediateGaussianOptimization::Balanced;
    D2D1_BORDER_MODE BorderMode = D2D1_BORDER_MODE_HARD;
    winrt::hstring effectName = L"ImmediateGaussianBlur";

    HRESULT STDMETHODCALLTYPE GetEffectId(GUID* id) noexcept override {
        if (!id)
            return E_INVALIDARG;
        *id = CLSID_D2D1GaussianBlur;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetNamedPropertyMapping(
        LPCWSTR name,
        UINT* index,
        abi_graphics_effects::GRAPHICS_EFFECT_PROPERTY_MAPPING*
            mapping) noexcept override {
        if (!name || !index || !mapping)
            return E_INVALIDARG;
        std::wstring_view property{name};
        if (property == L"BlurAmount") {
            *index = D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION;
        } else if (property == L"Optimization") {
            *index = D2D1_GAUSSIANBLUR_PROP_OPTIMIZATION;
        } else if (property == L"BorderMode") {
            *index = D2D1_GAUSSIANBLUR_PROP_BORDER_MODE;
        } else {
            return E_INVALIDARG;
        }
        *mapping =
            abi_graphics_effects::GRAPHICS_EFFECT_PROPERTY_MAPPING_DIRECT;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetPropertyCount(UINT* count) noexcept override {
        if (!count)
            return E_INVALIDARG;
        *count = 3;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE
    GetProperty(UINT index,
                winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue>**
                    value) noexcept override {
        if (!value)
            return E_INVALIDARG;
        try {
            using winrt::Windows::Foundation::PropertyValue;
            switch (index) {
                case D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION:
                    *value =
                        PropertyValue::CreateSingle(BlurAmount)
                            .as<winrt::impl::abi_t<
                                winrt::Windows::Foundation::IPropertyValue>>()
                            .detach();
                    return S_OK;
                case D2D1_GAUSSIANBLUR_PROP_OPTIMIZATION:
                    *value =
                        PropertyValue::CreateUInt32(
                            static_cast<uint32_t>(Optimization))
                            .as<winrt::impl::abi_t<
                                winrt::Windows::Foundation::IPropertyValue>>()
                            .detach();
                    return S_OK;
                case D2D1_GAUSSIANBLUR_PROP_BORDER_MODE:
                    *value =
                        PropertyValue::CreateUInt32(
                            static_cast<uint32_t>(BorderMode))
                            .as<winrt::impl::abi_t<
                                winrt::Windows::Foundation::IPropertyValue>>()
                            .detach();
                    return S_OK;
                default:
                    return E_BOUNDS;
            }
        } catch (...) {
            return winrt::to_hresult();
        }
    }

    HRESULT STDMETHODCALLTYPE
    GetSource(UINT index,
              abi_graphics_effects::IGraphicsEffectSource** source) noexcept
        override {
        if (!source)
            return E_INVALIDARG;
        if (index != 0 || !Source)
            return E_BOUNDS;
        winrt::copy_to_abi(Source, *reinterpret_cast<void**>(source));
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetSourceCount(UINT* count) noexcept override {
        if (!count)
            return E_INVALIDARG;
        *count = 1;
        return S_OK;
    }

    winrt::hstring Name() const { return effectName; }
    void Name(winrt::hstring const& value) { effectName = value; }
};

struct ImmediateFloodEffect
    : winrt::implements<ImmediateFloodEffect,
                        graphics_effects::IGraphicsEffect,
                        graphics_effects::IGraphicsEffectSource,
                        abi_graphics_effects::IGraphicsEffectD2D1Interop> {
    winrt::Windows::UI::Color Tint{};
    winrt::hstring effectName = L"DownAeroTint";

    HRESULT STDMETHODCALLTYPE GetEffectId(GUID* id) noexcept override {
        if (!id)
            return E_INVALIDARG;
        *id = CLSID_D2D1Flood;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetNamedPropertyMapping(
        LPCWSTR name,
        UINT* index,
        abi_graphics_effects::GRAPHICS_EFFECT_PROPERTY_MAPPING*
            mapping) noexcept override {
        if (!name || !index || !mapping ||
            std::wstring_view{name} != L"Color") {
            return E_INVALIDARG;
        }
        *index = D2D1_FLOOD_PROP_COLOR;
        *mapping =
            abi_graphics_effects::GRAPHICS_EFFECT_PROPERTY_MAPPING_DIRECT;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetPropertyCount(UINT* count) noexcept override {
        if (!count)
            return E_INVALIDARG;
        *count = 1;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE
    GetProperty(UINT index,
                winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue>**
                    value) noexcept override {
        if (!value)
            return E_INVALIDARG;
        if (index != D2D1_FLOOD_PROP_COLOR)
            return E_BOUNDS;
        try {
            *value =
                winrt::Windows::Foundation::PropertyValue::CreateSingleArray(
                    {Tint.R / 255.0f, Tint.G / 255.0f, Tint.B / 255.0f,
                     Tint.A / 255.0f})
                    .as<winrt::impl::abi_t<
                        winrt::Windows::Foundation::IPropertyValue>>()
                    .detach();
            return S_OK;
        } catch (...) {
            return winrt::to_hresult();
        }
    }
    HRESULT STDMETHODCALLTYPE
    GetSource(UINT,
              abi_graphics_effects::IGraphicsEffectSource**) noexcept override {
        return E_BOUNDS;
    }
    HRESULT STDMETHODCALLTYPE GetSourceCount(UINT* count) noexcept override {
        if (!count)
            return E_INVALIDARG;
        *count = 0;
        return S_OK;
    }
    winrt::hstring Name() const { return effectName; }
    void Name(winrt::hstring const& value) { effectName = value; }
};

struct ImmediateCompositeEffect
    : winrt::implements<ImmediateCompositeEffect,
                        graphics_effects::IGraphicsEffect,
                        graphics_effects::IGraphicsEffectSource,
                        abi_graphics_effects::IGraphicsEffectD2D1Interop> {
    std::vector<graphics_effects::IGraphicsEffectSource> Sources;
    D2D1_COMPOSITE_MODE Mode = D2D1_COMPOSITE_MODE_SOURCE_OVER;
    winrt::hstring effectName = L"DownAeroComposite";

    HRESULT STDMETHODCALLTYPE GetEffectId(GUID* id) noexcept override {
        if (!id)
            return E_INVALIDARG;
        *id = CLSID_D2D1Composite;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetNamedPropertyMapping(
        LPCWSTR name,
        UINT* index,
        abi_graphics_effects::GRAPHICS_EFFECT_PROPERTY_MAPPING*
            mapping) noexcept override {
        if (!name || !index || !mapping || std::wstring_view{name} != L"Mode") {
            return E_INVALIDARG;
        }
        *index = D2D1_COMPOSITE_PROP_MODE;
        *mapping =
            abi_graphics_effects::GRAPHICS_EFFECT_PROPERTY_MAPPING_DIRECT;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetPropertyCount(UINT* count) noexcept override {
        if (!count)
            return E_INVALIDARG;
        *count = 1;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE
    GetProperty(UINT index,
                winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue>**
                    value) noexcept override {
        if (!value)
            return E_INVALIDARG;
        if (index != D2D1_COMPOSITE_PROP_MODE)
            return E_BOUNDS;
        try {
            *value = winrt::Windows::Foundation::PropertyValue::CreateUInt32(
                         static_cast<uint32_t>(Mode))
                         .as<winrt::impl::abi_t<
                             winrt::Windows::Foundation::IPropertyValue>>()
                         .detach();
            return S_OK;
        } catch (...) {
            return winrt::to_hresult();
        }
    }
    HRESULT STDMETHODCALLTYPE
    GetSource(UINT index,
              abi_graphics_effects::IGraphicsEffectSource** source) noexcept
        override {
        if (!source)
            return E_INVALIDARG;
        try {
            winrt::copy_to_abi(Sources.at(index),
                               *reinterpret_cast<void**>(source));
            return S_OK;
        } catch (...) {
            return E_BOUNDS;
        }
    }
    HRESULT STDMETHODCALLTYPE GetSourceCount(UINT* count) noexcept override {
        if (!count)
            return E_INVALIDARG;
        *count = static_cast<UINT>(Sources.size());
        return S_OK;
    }
    winrt::hstring Name() const { return effectName; }
    void Name(winrt::hstring const& value) { effectName = value; }
};

class ImmediateBackdropBlurBrush
    : public mediax::XamlCompositionBrushBaseT<ImmediateBackdropBlurBrush> {
   public:
    ImmediateBackdropBlurBrush(UIElement const& element,
                               float blurAmount,
                               winrt::Windows::UI::Color tint)
        : compositor_(
              hosting::ElementCompositionPreview::GetElementVisual(element)
                  .Compositor()),
          blurAmount_(blurAmount),
          tint_(tint) {}

    void OnConnected() {
        if (CompositionBrush())
            return;
        auto effect = winrt::make_self<ImmediateGaussianEffect>();
        effect->Source =
            composition::CompositionEffectSourceParameter(L"backdrop");
        effect->BlurAmount = blurAmount_;
        effect->Optimization = ImmediateGaussianOptimization::Balanced;
        effect->BorderMode = D2D1_BORDER_MODE_HARD;

        auto tintEffect = winrt::make_self<ImmediateFloodEffect>();
        tintEffect->Tint = tint_;

        auto compositeEffect = winrt::make_self<ImmediateCompositeEffect>();
        compositeEffect->Mode = D2D1_COMPOSITE_MODE_SOURCE_OVER;
        compositeEffect->Sources.push_back(*effect);
        compositeEffect->Sources.push_back(*tintEffect);

        auto factory = compositor_.CreateEffectFactory(*compositeEffect);
        auto brush = factory.CreateBrush();
        // This UI lives in its own DesktopWindowXamlSource. A regular
        // BackdropBrush only sees pixels inside that transparent visual tree,
        // which leaves a dark translucent tint. HostBackdropBrush
        // samples the actual desktop/window content behind this popup, matching
        // the WindhawkBlur appearance used by Start Menu and Taskbar Styler.
        brush.SetSourceParameter(L"backdrop",
                                 compositor_.CreateHostBackdropBrush());
        CompositionBrush(brush);
    }

    void OnDisconnected() {
        if (auto brush = CompositionBrush()) {
            brush.Close();
            CompositionBrush(nullptr);
        }
    }

   private:
    composition::Compositor compositor_{nullptr};
    float blurAmount_ = 25.0f;
    winrt::Windows::UI::Color tint_{};
};

// ===== Core types =====
struct Settings {
    std::wstring position = L"tray_left";
    int compactWidth = 169;
    bool autoSizeToTaskbar = true;
    int expandedWidth = 360;
    bool compact = false;
    int popupSpacing = 20;
    int popupCardGap = 8;
    int popupShadowDepth = 58;
    int popupShadowOpacity = 70;
    std::wstring popupButtonStyle = L"fluent_bold";
    std::wstring popupBackdropCoverEffect = L"dark_only";
    std::wstring artworkAbstractMode = L"browser_original";
    std::wstring defaultCoverImage;
    std::wstring defaultTitle = L"Island Beat Float";
    std::wstring defaultArtist = L"No media playing";
    std::wstring accentColorMode = L"artwork";
    std::wstring accentColor = L"#6EB85A";
    winrt::Windows::UI::Color customAccentColor{0xFF, 0x6E, 0xB8, 0x5A};
    bool hasCustomAccent = false;
    int height = 40;
    int marginLeft = 4;
    int marginRight = 4;
    bool hideWhenNoMedia = false;
    double hoverScale = 1.06;
    double hoverLerpSpeed = 28.0;
    double animationSpeed = 1.0;
    std::wstring material = L"liquid_glass";
    bool liquidGlassGradient = false;
    int liquidGlassCornerRadius = 46;
    int liquidGlassFrost = 12;
    int liquidGlassRefraction = 6;
    int liquidGlassRoundness = 4;
    int backdropInitialFrameSkip = 0;
    int backdropFallbackBlurPasses = 5;
    int backdropFallbackCaptureScale = 2;
    bool allowScreenCapture = false;
};

struct RuntimeLayout {
    double taskbarHeightDip = 40.0;
    double compactHeight = 40.0;
    double compactWidth = 168.0;
    double artSize = 28.0;
    double artImageSize = 30.0;
    double artCornerRadius = 8.0;
    double cornerRadius = 20.0;
    double contentMarginX = 10.0;
    double contentMarginY = 4.0;
    // Distance from the pill's left/top edge to the circular cover bounds.
    // (H - D) / 2 puts the cover centre on the left cap centre (H/2, H/2).
    double artInset = 4.0;
    double artColumnWidth = 30.0;
    // Compact arc spin toggle: a short accent-coloured arc on the right side
    // of the circular cover, concentric with it and just outside the artwork
    // edge. Only the gap outside the cover and the stroke scale with the
    // island; the cover itself never moves or resizes for the arc.
    double arcToggleCoverGap = 3.7;
    double arcToggleStroke = 4.0;
    double textMarginX = 8.0;
    double textRightMargin = 4.0;
    double titleFontSize = 12.0;
    double artistFontSize = 10.0;
    double progressWidth = 74.0;
    double progressHeight = 4.0;
    double progressMarginLeft = 8.0;
    double playbackIndicatorWidth = 18.0;
    double playbackIndicatorHeight = 16.0;
    double playbackIndicatorMarginLeft = 3.0;
    double playbackBarWidth = 2.4;
    double playbackBarGap = 0.75;
};

// One authoritative compact-state specification. Both the taskbar island and
// the independent animation surface consume this exact data; neither side is
// allowed to invent fallback sizes, radii, margins or bar geometry.
struct CompactVisualSpec {
    double width;
    double height;
    double cornerRadius;
    double borderThickness;
    double contentMarginX;
    double contentMarginY;
    double artInset;
    double artSize;
    double artImageSize;
    double artCornerRadius;
    double artColumnWidth;
    double arcToggleCoverGap;
    double arcToggleStroke;
    double textMarginX;
    double textRightMargin;
    double titleFontSize;
    double artistFontSize;
    double progressWidth;
    double progressHeight;
    double progressMarginLeft;
    double playbackIndicatorWidth;
    double playbackIndicatorHeight;
    double playbackIndicatorMarginLeft;
    double playbackBarWidth;
    double playbackBarGap;
};

CompactVisualSpec CompactVisualSpecFrom(RuntimeLayout const& layout) {
    return {
        layout.compactWidth,
        layout.compactHeight,
        layout.cornerRadius,
        0.75,
        layout.contentMarginX,
        layout.contentMarginY,
        layout.artInset,
        layout.artSize,
        layout.artImageSize,
        layout.artCornerRadius,
        layout.artColumnWidth,
        layout.arcToggleCoverGap,
        layout.arcToggleStroke,
        layout.textMarginX,
        layout.textRightMargin,
        layout.titleFontSize,
        layout.artistFontSize,
        layout.progressWidth,
        layout.progressHeight,
        layout.progressMarginLeft,
        layout.playbackIndicatorWidth,
        layout.playbackIndicatorHeight,
        layout.playbackIndicatorMarginLeft,
        layout.playbackBarWidth,
        layout.playbackBarGap,
    };
}

// Fractional-DIP rect. Rounding the physical->DIP conversion used to snap
// each edge independently, which at 125%/150% scaling could land one pixel
// away from the native island edge and produce a visible flash at handoff.
struct DipRect {
    double left;
    double top;
    double right;
    double bottom;
};

struct MediaState {
    std::wstring title = L"Not Playing";
    std::wstring artist;
    bool hasSession = false;
    bool isPlaying = false;
    bool canSeek = false;
    int64_t timelineStartTicks = 0;
    int64_t positionTicks = 0;
    int64_t durationTicks = 0;
    std::wstring sourceAppUserModelId;
    std::wstring mediaId;
    bool canFavorite = false;
    bool isFavorite = false;
    std::vector<uint8_t> thumbnailBytes;
};

using CTaskBand_GetTaskbarHost_t = void(WINAPI*)(void* pThis, void* result);
using TaskbarHost_FrameHeight_t = int(WINAPI*)(void* pThis);
using Std_Ref_Decref_t = void(WINAPI*)(void* pThis);
using TrayUI_StartTaskbar_t = void(WINAPI*)(void* pThis);
using TrayUI__Hide_t = void(WINAPI*)(void* pThis);
using TrayUI_Unhide_t = void(WINAPI*)(void* pThis,
                                      int trayUnhideFlags,
                                      int unhideRequest);
using CSecondaryTray__AutoHide_t = void(WINAPI*)(void* pThis, bool param1);
using CSecondaryTray__Unhide_t = void(WINAPI*)(void* pThis,
                                               int trayUnhideFlags,
                                               int unhideRequest);
using WindowThreadProc = void (*)(void*);
using MediaCommand =
    std::function<void(gsm::GlobalSystemMediaTransportControlsSession const&)>;

// ===== Global state =====
Settings g_settings;
RuntimeLayout g_layout;
CompactVisualSpec CurrentCompactVisualSpec() {
    return CompactVisualSpecFrom(g_layout);
}
std::mutex g_pendingSettingsMutex;
std::optional<Settings> g_pendingSettings;
std::mutex g_mediaMutex;
std::mutex g_seekMutex;
MediaState g_media;
std::chrono::steady_clock::time_point g_mediaStateTimestamp;
bool g_optimisticPlaybackPending = false;
bool g_optimisticPlaybackDesired = false;
std::wstring g_optimisticPlaybackSource;
std::chrono::steady_clock::time_point g_optimisticPlaybackUntil;
double g_popupLiveProgressValue = 0.0;
bool g_popupLiveProgressValid = false;
std::wstring g_popupLiveProgressKey;
std::chrono::steady_clock::time_point g_popupLiveProgressFrameTime;
std::wstring g_mediaProgressResetKey;
std::chrono::steady_clock::time_point g_mediaProgressResetStarted;
std::chrono::steady_clock::time_point g_mediaProgressResetUntil;
bool g_mediaNavigationHoldZero = false;
std::wstring g_mediaNavigationOldTrackKey;
std::chrono::steady_clock::time_point g_mediaNavigationHoldUntil;
std::wstring g_timelineQuarantineTrackKey;
int64_t g_timelineQuarantinePreviousPositionTicks = 0;
std::chrono::steady_clock::time_point g_timelineQuarantineUntil;
bool g_popupSeekDragging = false;
double g_popupSeekPreviewRatio = 0.0;
std::chrono::steady_clock::time_point g_popupSeekPreviewUntil;
bool g_popupSeekCommitPending = false;
double g_popupSeekCommitRatio = 0.0;
int64_t g_popupSeekCommitTargetTicks = 0;
std::chrono::steady_clock::time_point g_popupSeekCommitUntil;

std::atomic_bool g_unloading = false;
std::atomic_bool g_modActive = false;
std::atomic_bool g_mediaThreadRunning = false;
std::thread* g_mediaThread = nullptr;
std::atomic_bool g_mediaThreadExited = true;
std::mutex g_mediaCommandMutex;
std::condition_variable g_mediaCommandCv;
std::deque<MediaCommand> g_mediaCommands;
std::atomic_bool g_mediaRefreshRequested = true;
std::atomic_bool g_remoteBytesThreadRunning = false;
std::atomic_bool g_remoteBytesThreadExited = true;
std::thread* g_remoteBytesThread = nullptr;
std::mutex g_remoteBytesMutex;
std::condition_variable g_remoteBytesCv;
std::wstring g_remoteBytesPendingUrl;
std::wstring g_remoteBytesInFlightUrl;
struct RemoteBytesCacheEntry {
    std::wstring url;
    std::vector<uint8_t> bytes;
    std::chrono::steady_clock::time_point attemptTime;
};
std::deque<RemoteBytesCacheEntry> g_remoteBytesCache;
std::atomic_bool g_neteaseFavoriteToggleRequested = false;
std::mutex g_neteaseFavoriteOptimisticMutex;
bool g_neteaseFavoriteOptimisticPending = false;
bool g_neteaseFavoriteOptimisticValue = false;
std::wstring g_neteaseFavoriteOptimisticTrackKey;
std::chrono::steady_clock::time_point g_neteaseFavoriteOptimisticUntil{};
std::atomic<double> g_neteaseSeekRatioRequested = -1.0;
std::atomic_bool g_bilibiliFavoriteRequested = false;
std::mutex g_bilibiliFavoriteStateMutex;
std::wstring g_bilibiliFavoriteTrackId;
bool g_bilibiliFavoriteValue = false;
std::wstring g_neteaseProgressTrackId;
uint64_t g_neteaseProgressSourceWriteTimeTicks = 0;
int64_t g_neteaseEstimatedPositionTicks = 0;
std::chrono::steady_clock::time_point g_neteaseProgressSampleTime{};

bool IsModActive() {
    return g_modActive.load() && !g_unloading.load();
}

constexpr auto kMediaPropertiesAsyncTimeout = std::chrono::milliseconds(1500);
constexpr auto kThumbnailAsyncTimeout = std::chrono::milliseconds(900);
constexpr auto kMediaCommandAsyncTimeout = std::chrono::milliseconds(1500);
constexpr auto kUiLocalAsyncTimeout = std::chrono::milliseconds(500);
constexpr auto kMediaThreadStopTimeout = std::chrono::milliseconds(5000);
constexpr auto kPopupOverlayWgcBorderlessAccessTimeout =
    std::chrono::milliseconds(5000);

template <typename AsyncOperation>
bool WaitForAsyncWithTimeout(AsyncOperation const& operation,
                             std::chrono::milliseconds timeout,
                             const wchar_t* label) {
    if (!operation) {
        return false;
    }

    auto status = operation.wait_for(timeout);
    if (status == winrt::Windows::Foundation::AsyncStatus::Completed) {
        return true;
    }

    try {
        operation.Cancel();
    } catch (...) {
    }

    Wh_Log(
        L"Island: async operation timed out label=%s status=%d timeoutMs=%lld",
        label ? label : L"(unknown)", static_cast<int>(status),
        static_cast<long long>(timeout.count()));
    return false;
}

template <typename AsyncOperation>
auto GetAsyncResultWithTimeout(AsyncOperation const& operation,
                               std::chrono::milliseconds timeout,
                               const wchar_t* label)
    -> decltype(operation.GetResults()) {
    if (!WaitForAsyncWithTimeout(operation, timeout, label)) {
        throw winrt::hresult_error(HRESULT_FROM_WIN32(ERROR_TIMEOUT));
    }

    return operation.GetResults();
}

HWND g_taskbarWnd = nullptr;
Grid g_playerGrid = nullptr;
FrameworkElement g_injectionParent = nullptr;
int g_playerColumn = -1;
bool g_expanded = false;
ScaleTransform g_islandScale = nullptr;
uint64_t g_lastThumbnailHash = 0;
winrt::event_token g_hoverRenderingToken{};
bool g_hoverRenderingHooked = false;
double g_currentHoverScale = 1.0;
double g_targetHoverScale = 1.0;
std::chrono::steady_clock::time_point g_lastHoverFrameTime{};
bool g_lastDarkMode = false;
bool g_themeVisualsValid = false;
bool g_popupXamlThemeValid = false;
bool g_popupXamlThemeDark = false;
std::wstring g_popupXamlThemeMaterial;
std::wstring g_popupXamlThemeButtonStyle;
int g_popupXamlThemeShadowDepth = -1;
int g_popupXamlThemeShadowOpacity = -1;
bool g_popupBackdropBlurActive = false;
bool g_popupTextForegroundValid = false;
bool g_popupTextForegroundEdgeFade = false;
bool g_popupTextForegroundDark = false;
double g_popupTextForegroundEdgeFadeAmount = -1.0;
HWND g_expandedPopup = nullptr;
bool g_popupClassRegistered = false;
HWND g_popupToggleHitWindow = nullptr;
bool g_popupToggleHitWindowClassRegistered = false;
HWND g_popupBackdropOverlay = nullptr;
bool g_popupBackdropOverlayClassRegistered = false;
std::chrono::steady_clock::time_point g_popupBackdropOverlayLastPaintTime{};
int g_popupBackdropOverlayLastWidth = 0;
int g_popupBackdropOverlayLastHeight = 0;
int g_popupBackdropOverlayLastRadius = 0;
std::atomic<int> g_popupBackdropOverlayFrameAlpha{255};
bool g_popupBackdropOverlayNativeBlurActive = false;
int g_popupBackdropOverlayNativeFrostAlpha = -1;
bool g_expandedPopupCaptureExcluded = false;
bool g_popupXamlChildCaptureExcluded = false;
bool g_popupBackdropOverlayCaptureExcluded = false;
RECT g_popupLiquidGlassPanelRectPx{};
int g_popupLiquidGlassPanelRadiusPx = 0;
bool g_popupLiquidGlassPanelRectValid = false;
bool g_popupOverlayWgcReadbackHadVisibleFrame = false;
enum class PopupOverlayWgcDiagnosticState {
    NotStarted,
    StartSkipped,
    StartedNoFrame,
    FrameArrived,
    RenderFailed,
    MapFailed,
    UpdateFailed,
    VisibleFrame,
};
PopupOverlayWgcDiagnosticState g_popupOverlayWgcDiagnosticState =
    PopupOverlayWgcDiagnosticState::NotStarted;
HRESULT g_popupOverlayWgcDiagnosticHr = S_OK;
uint64_t g_popupOverlayWgcFrameCount = 0;
std::atomic<uint64_t> g_popupOverlayWgcPresentedSerial{0};
std::atomic<uint64_t> g_popupOverlayWgcGeometryGeneration{0};
std::atomic<uint64_t> g_popupOverlayWgcPresentedGeometryGeneration{0};
uint64_t g_popupOverlayWgcRenderFailCount = 0;
std::chrono::steady_clock::time_point g_popupOverlayWgcLastStartAttemptTime{};
HRESULT g_popupOverlayWgcCreateItemHr = S_OK;
bool g_popupOverlayWgcCreateItemFailed = false;
bool g_popupOverlayWgcFallbackPainted = false;
int g_popupOverlayWgcFramesToSkip = 0;
std::mutex g_popupBackdropOverlayHandoffMutex;
std::vector<BYTE> g_popupBackdropOverlayFallbackPixels;
RECT g_popupBackdropOverlayFallbackRect{};
int g_popupBackdropOverlayFallbackWidth = 0;
int g_popupBackdropOverlayFallbackHeight = 0;
int g_popupBackdropOverlayFallbackRadius = 0;
bool g_popupBackdropOverlayFallbackPixelsValid = false;
std::vector<BYTE> g_popupBackdropOverlayCleanPixels;
RECT g_popupBackdropOverlayCleanRect{};
int g_popupBackdropOverlayCleanWidth = 0;
int g_popupBackdropOverlayCleanHeight = 0;
bool g_popupBackdropOverlayCleanPixelsValid = false;

void ClearPopupBackdropOverlayHandoffCache() {
    std::lock_guard cacheLock(g_popupBackdropOverlayHandoffMutex);
    g_popupBackdropOverlayFallbackPixels.clear();
    g_popupBackdropOverlayFallbackRect = {};
    g_popupBackdropOverlayFallbackWidth = 0;
    g_popupBackdropOverlayFallbackHeight = 0;
    g_popupBackdropOverlayFallbackRadius = 0;
    g_popupBackdropOverlayFallbackPixelsValid = false;
    g_popupBackdropOverlayCleanPixels.clear();
    g_popupBackdropOverlayCleanRect = {};
    g_popupBackdropOverlayCleanWidth = 0;
    g_popupBackdropOverlayCleanHeight = 0;
    g_popupBackdropOverlayCleanPixelsValid = false;
}

std::mutex g_popupOverlayWgcMutex;
std::atomic<bool> g_popupOverlayWgcRendering{false};
struct PopupOverlayWgcRenderParameters {
    int targetRadiusPx = 1;
    bool morphing = false;
    bool allowScreenCapture = false;
    bool useLiquidLensWarp = false;
    float blurStdDev = 18.0f;
    float refractionBlurStdDev = 2.0f;
    float liquidRimAlpha = 0.38f;
};
PopupOverlayWgcRenderParameters g_popupOverlayWgcRenderParameters;
std::atomic_bool g_popupOverlayWgcRunning = false;
bool g_popupOverlayWgcFrameCallbackHooked = false;
std::atomic<bool> g_popupOverlayWgcDirtyRegionsEnabled{false};
std::atomic<int> g_popupOverlayWgcBorderlessAccessState{0};
std::mutex g_popupOverlayWgcBorderlessAccessThreadMutex;
std::thread* g_popupOverlayWgcBorderlessAccessThread = nullptr;
RECT g_popupOverlayWgcCaptureRectPx{LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
RECT g_popupOverlayWgcMonitorRectPx{};
int g_popupOverlayWgcTargetWidthPx = 0;
int g_popupOverlayWgcTargetHeightPx = 0;
int g_popupOverlayWgcTargetRadiusPx = 0;
HMONITOR g_popupOverlayWgcMonitor = nullptr;
HRESULT g_popupOverlayWgcLastHr = S_OK;

[[clang::no_destroy]] winrt::com_ptr<ID3D11Device> g_popupOverlayWgcD3dDevice;
[[clang::no_destroy]] winrt::com_ptr<ID3D11DeviceContext>
    g_popupOverlayWgcD3dContext;
[[clang::no_destroy]] winrt::com_ptr<IDXGIDevice> g_popupOverlayWgcDxgiDevice;
[[clang::no_destroy]] winrt::com_ptr<IDXGISwapChain1>
    g_popupOverlayWgcSwapChain;
[[clang::no_destroy]] winrt::com_ptr<IDCompositionDevice>
    g_popupOverlayDcompDevice;
[[clang::no_destroy]] winrt::com_ptr<IDCompositionTarget>
    g_popupOverlayDcompTarget;
[[clang::no_destroy]] winrt::com_ptr<IDCompositionVisual>
    g_popupOverlayDcompVisual;
[[clang::no_destroy]] winrt::com_ptr<IDCompositionEffectGroup>
    g_popupOverlayDcompOpacityEffect;
[[clang::no_destroy]] winrt::com_ptr<IDCompositionRectangleClip>
    g_popupOverlayDcompClip;
bool g_popupOverlayDcompContentAttached = false;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Bitmap1>
    g_popupOverlayWgcSwapChainTargetBitmap;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Factory1> g_popupOverlayWgcD2dFactory;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Device> g_popupOverlayWgcD2dDevice;
[[clang::no_destroy]] winrt::com_ptr<ID2D1DeviceContext>
    g_popupOverlayWgcD2dContext;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Bitmap1>
    g_popupOverlayWgcLensDisplacementMap;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Bitmap1>
    g_popupOverlayWgcIntermediateBitmap;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Effect> g_popupOverlayWgcBlurEffect;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Effect>
    g_popupOverlayWgcRefractionBlurEffect;
[[clang::no_destroy]] winrt::com_ptr<ID2D1Effect>
    g_popupOverlayWgcDisplacementEffect;
[[clang::no_destroy]] winrt::com_ptr<ID2D1SolidColorBrush>
    g_popupOverlayWgcRimBrush;
[[clang::no_destroy]] winrt::com_ptr<ID2D1RoundedRectangleGeometry>
    g_popupOverlayWgcRoundedGeometry;
int g_popupOverlayWgcLensMapWidth = 0;
int g_popupOverlayWgcLensMapHeight = 0;
int g_popupOverlayWgcLensMapRadius = 0;
int g_popupOverlayWgcLensMapRoundness = 0;
int g_popupOverlayWgcRenderCacheWidth = 0;
int g_popupOverlayWgcRenderCacheHeight = 0;
int g_popupOverlayWgcRoundedGeometryWidth = 0;
int g_popupOverlayWgcRoundedGeometryHeight = 0;
int g_popupOverlayWgcRoundedGeometryRadius = 0;
bool g_popupOverlayDcompTransformValid = false;
float g_popupOverlayDcompLastScaleX = 0.0f;
float g_popupOverlayDcompLastScaleY = 0.0f;
float g_popupOverlayDcompLastRadius = -1.0f;
std::atomic<int> g_popupOverlayDcompPendingWidth{0};
std::atomic<int> g_popupOverlayDcompPendingHeight{0};
std::atomic<int> g_popupOverlayDcompPendingRadius{1};
std::atomic<bool> g_popupOverlayDcompGeometryDirty{false};
std::atomic<int> g_popupOverlayDcompOpacityMilli{-1};

[[clang::no_destroy]] direct3d11::IDirect3DDevice
    g_popupOverlayWgcGraphicsDevice{nullptr};
[[clang::no_destroy]] capture::GraphicsCaptureItem g_popupOverlayWgcItem{
    nullptr};
[[clang::no_destroy]] capture::Direct3D11CaptureFramePool
    g_popupOverlayWgcFramePool{nullptr};
[[clang::no_destroy]] capture::GraphicsCaptureSession g_popupOverlayWgcSession{
    nullptr};
winrt::event_token g_popupOverlayWgcFrameArrivedToken{};
bool g_popupOverlayWgcHadFrame = false;
std::chrono::steady_clock::time_point g_popupOverlayWgcDiagnosticStartTime{};
std::chrono::steady_clock::time_point g_popupOverlayWgcLastRenderTime{};
std::chrono::steady_clock::time_point g_popupOverlayWgcLastResizeTime{};
double g_popupOverlayWgcFrameIntervalMs = 1000.0 / 60.0;

hosting::DesktopWindowXamlSource g_popupXamlSource = nullptr;
// Scheme 2 keeps the independent animation surface alive at the compact
// endpoint and binds it to the taskbar anchor on every composition frame.
HWND g_popupXamlChild = nullptr;
bool g_popupXamlChildSubclassed = false;
Grid g_popupXamlRoot = nullptr;
controls::Canvas g_popupXamlCanvas = nullptr;
Border g_popupXamlShadow = nullptr;
composition::SpriteVisual g_popupXamlShadowVisual = nullptr;
composition::DropShadow g_popupXamlDropShadow = nullptr;
Border g_popupXamlBackdrop = nullptr;
ScaleTransform g_popupXamlBackdropScale = nullptr;
TranslateTransform g_popupXamlBackdropTranslate = nullptr;
Image g_popupXamlBackdropCoverFade = nullptr;
Image g_popupXamlBackdropCover = nullptr;
Border g_popupXamlBackdropTint = nullptr;
Border g_popupXamlBackdropSurfaceHighlight = nullptr;
Border g_popupXamlBackdropRimHighlight = nullptr;
Border g_popupXamlPanelCoverFrame = nullptr;
ScaleTransform g_popupXamlPanelCoverScale = nullptr;
TranslateTransform g_popupXamlPanelCoverTranslate = nullptr;
Image g_popupXamlPanelCoverFade = nullptr;
Image g_popupXamlPanelCover = nullptr;
Border g_popupXamlPanel = nullptr;
ScaleTransform g_popupXamlPanelScale = nullptr;
TranslateTransform g_popupXamlPanelTranslate = nullptr;
Border g_popupXamlArtFrame = nullptr;
composition::CompositionRoundedRectangleGeometry g_popupXamlArtClipGeometry =
    nullptr;
composition::CompositionGeometricClip g_popupXamlArtGeometricClip = nullptr;
ScaleTransform g_popupXamlArtScale = nullptr;
TranslateTransform g_popupXamlArtTranslate = nullptr;
Image g_popupXamlArtFade = nullptr;
Image g_popupXamlArt = nullptr;
FrameworkElement g_popupXamlTitleHost = nullptr;
FrameworkElement g_popupXamlArtistHost = nullptr;
FrameworkElement g_popupXamlPlaybackIndicator = nullptr;
std::vector<Border> g_popupXamlPlaybackBars;
mediax::SolidColorBrush g_popupXamlPlaybackAccentBrush = nullptr;
mediax::RectangleGeometry g_popupXamlPlaybackRevealClip = nullptr;
ScaleTransform g_popupXamlCompactHoverScale = nullptr;
winrt::event_token g_popupPlaybackRenderingToken{};
bool g_popupPlaybackRenderingHooked = false;
double g_popupPlaybackBarHeights[5] = {4.2, 7.0, 9.8, 7.0, 4.2};
double g_popupCompactHoverCurrent = 1.0;
double g_popupCompactHoverTarget = 1.0;
std::chrono::steady_clock::time_point g_popupPlaybackAnimationStart{};
std::chrono::steady_clock::time_point g_popupPlaybackRevealStart{};
std::chrono::steady_clock::time_point g_lastPopupPlaybackFrameTime{};
FrameworkElement g_popupXamlOutgoingTitleHost = nullptr;
FrameworkElement g_popupXamlOutgoingArtistHost = nullptr;
Border g_popupXamlTitleLeftFade = nullptr;
Border g_popupXamlTitleRightFade = nullptr;
Border g_popupXamlArtistLeftFade = nullptr;
Border g_popupXamlArtistRightFade = nullptr;
Border g_popupXamlOutgoingTitleLeftFade = nullptr;
Border g_popupXamlOutgoingTitleRightFade = nullptr;
Border g_popupXamlOutgoingArtistLeftFade = nullptr;
Border g_popupXamlOutgoingArtistRightFade = nullptr;
TextBlock g_popupXamlTitle = nullptr;
TextBlock g_popupXamlArtist = nullptr;
TextBlock g_popupXamlOutgoingTitle = nullptr;
TextBlock g_popupXamlOutgoingArtist = nullptr;
TranslateTransform g_popupXamlTitleTranslate = nullptr;
TranslateTransform g_popupXamlArtistTranslate = nullptr;
TranslateTransform g_popupXamlOutgoingTitleTranslate = nullptr;
TranslateTransform g_popupXamlOutgoingArtistTranslate = nullptr;
double g_popupTextBaseOpacity = 1.0;
bool g_popupTextTransitionActive = false;
int g_popupTextTransitionDirection = 1;
int g_pendingMediaNavigationDirection = 0;
std::chrono::steady_clock::time_point g_pendingMediaNavigationTime{};
TextBlock g_popupXamlElapsed = nullptr;
TextBlock g_popupXamlDuration = nullptr;
ProgressBar g_popupXamlProgress = nullptr;
ScaleTransform g_popupXamlProgressScale = nullptr;
Border g_popupXamlProgressTrack = nullptr;
Border g_popupXamlProgressFill = nullptr;
Border g_popupXamlProgressHitTarget = nullptr;
controls::Canvas g_popupXamlProgressGlowMask = nullptr;
mediax::RectangleGeometry g_popupXamlProgressGlowClip = nullptr;
std::vector<Border> g_popupXamlProgressGlowLayers;
std::vector<Border> g_popupXamlProgressCoreBlurLayers;
Border g_popupXamlProgressGlowCore = nullptr;
controls::Canvas g_popupXamlControls = nullptr;
Border g_popupXamlVolumeTrack = nullptr;
Border g_popupXamlVolumeFill = nullptr;
Border g_popupXamlVolumeHitTarget = nullptr;
FrameworkElement g_popupXamlVolumeLowIcon = nullptr;
FrameworkElement g_popupXamlVolumeHighIcon = nullptr;
bool g_popupVolumeDragging = false;
double g_popupSystemVolume = 0.5;
uint64_t g_popupXamlThumbnailHash = UINT64_MAX;
std::wstring g_popupXamlThumbnailMaterial;
bool g_popupXamlThumbnailCompact = false;
bool g_popupXamlBackdropCoverEnabled = false;
uint64_t g_popupAccentThumbnailHash = UINT64_MAX;
bool g_popupAccentColorValid = false;
winrt::Windows::UI::Color g_popupAccentColor{0xFF, 0x4F, 0x7D, 0xE8};
bool g_popupDisplayedAccentColorValid = false;
winrt::Windows::UI::Color g_popupDisplayedAccentColor{0xFF, 0x4F, 0x7D, 0xE8};
winrt::Windows::UI::Color g_popupAccentTransitionFrom{0xFF, 0x4F, 0x7D, 0xE8};
winrt::Windows::UI::Color g_popupAccentTransitionTo{0xFF, 0x4F, 0x7D, 0xE8};
double g_popupMediaTransitionProgress = 1.0;
bool g_popupMediaTransitionActive = false;
enum class PopupLifecycleState {
    Closed,
    Opening,
    Open,
    Closing,
};
PopupLifecycleState g_popupLifecycleState = PopupLifecycleState::Closed;
// Artwork/album-wash crossfade is intentionally separated from text/accent
// transitions. Track metadata can update before artwork arrives; sharing the
// same media transition would fade the current cover to the placeholder/blank
// even when the cover source itself did not change.
bool g_popupCoverTransitionActive = false;
double g_popupCurrentWidth = 0.0;
double g_popupTargetWidth = 0.0;
double g_popupExpandedWidth = 0.0;
double g_popupCurrentHeight = 0.0;
double g_popupTargetHeight = 0.0;
double g_popupExpandedHeight = 0.0;
bool g_popupClosing = false;
bool g_popupRestingCompact = false;
bool g_popupRestingHiddenWithTaskbar = false;
bool g_popupRidingTaskbarUp = false;
double g_popupCloseHandoffOpacity = 1.0;
bool g_popupCompactFramePending = false;
uint64_t g_popupCompactFrameStartSerial = 0;
std::chrono::steady_clock::time_point g_popupCompactFramePendingSince{};
std::atomic_bool g_popupOverlayAwaitFreshFrame{false};
uint64_t g_popupOverlayFreshFrameStartSerial = 0;
uint64_t g_popupOverlayFreshFrameStartGeneration = 0;
bool g_popupTransparentParkPending = false;
bool g_popupOutsideClickArmed = false;
HBITMAP g_popupAlbumBitmap = nullptr;
uint64_t g_popupThumbnailHash = 0;
RECT g_popupSourceRect{};
RECT g_popupSourceArtRect{};
RECT g_popupSourceTitleRect{};
RECT g_popupSourceArtistRect{};
RECT g_popupSourceProgressRect{};
RECT g_popupSourceControlsRect{};
RECT g_popupSourcePlaybackIndicatorRect{};
RECT g_popupFinalRect{};
RECT g_popupHostRect{};
bool g_popupExpandsRight = true;
bool g_popupOpensDown = false;
bool g_taskbarAtTop = false;
double g_popupAnimationProgress = 0.0;
double g_popupAnimationTarget = 0.0;
double g_popupAnimationVelocity = 0.0;
winrt::event_token g_popupRenderingToken{};
bool g_popupRenderingHooked = false;
std::chrono::steady_clock::time_point g_lastPopupFrameTime{};
bool g_popupPendingContentRefresh = false;
double g_lastPopupVisualProgress = -1.0;
RECT g_lastPopupVisualRect{LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
RECT g_lastPopupWindowRect{LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
RECT g_lastTrackedIslandRect{};
RECT g_lastTrackedTaskbarRect{LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
RECT g_lastTrackedBridgeRect{LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
int g_pendingPopupDeltaX = 0;
int g_pendingPopupDeltaY = 0;
std::atomic_bool g_taskbarHiddenBySystem = false;
HWND g_taskbarXamlHostWnd = nullptr;
std::chrono::steady_clock::time_point g_taskbarFullyShownSince{};
int g_taskbarShowReanchorStage = 0;

TextBlock g_compactTitleText = nullptr;
TextBlock g_compactArtistText = nullptr;
FrameworkElement g_compactTextHost = nullptr;
Border g_compactTextLeftFade = nullptr;
Border g_compactTextRightFade = nullptr;
TextBlock g_compactOutgoingTitleText = nullptr;
TextBlock g_compactOutgoingArtistText = nullptr;
TranslateTransform g_compactTitleTranslate = nullptr;
TranslateTransform g_compactArtistTranslate = nullptr;
TranslateTransform g_compactOutgoingTitleTranslate = nullptr;
TranslateTransform g_compactOutgoingArtistTranslate = nullptr;
Image g_compactAlbumArtImage = nullptr;
Image g_compactAlbumArtFade = nullptr;
Grid g_compactArcToggle = nullptr;
shapes::Path g_compactArcPath = nullptr;
mediax::SolidColorBrush g_compactArcAccentBrush = nullptr;
std::chrono::steady_clock::time_point g_compactArcLastDoubleTap{};
mediax::RotateTransform g_compactArtSpinImage = nullptr;
mediax::RotateTransform g_compactArtSpinFade = nullptr;
winrt::event_token g_compactArtSpinRenderingToken{};
bool g_compactArtSpinRenderingHooked = false;
bool g_compactArtSpinEnabled = false;
double g_compactArtSpinAngle = 0.0;
std::chrono::steady_clock::time_point g_lastCompactArtSpinFrameTime{};
ProgressBar g_compactProgress = nullptr;
winrt::event_token g_compactProgressRenderingToken{};
bool g_compactProgressRenderingHooked = false;
std::chrono::steady_clock::time_point g_lastCompactProgressFrameTime;
FrameworkElement g_compactPlaybackIndicator = nullptr;
std::vector<Border> g_compactPlaybackBars;
mediax::SolidColorBrush g_compactPlaybackAccentBrush = nullptr;
winrt::event_token g_compactPlaybackRenderingToken{};
bool g_compactPlaybackRenderingHooked = false;
bool g_compactPlaybackDesiredPlaying = false;
double g_compactPlaybackBarHeights[5] = {4.2, 7.0, 9.8, 7.0, 4.2};
std::chrono::steady_clock::time_point g_compactPlaybackAnimationStart{};
std::chrono::steady_clock::time_point g_compactPlaybackStateChangedAt{};
std::chrono::steady_clock::time_point g_lastCompactPlaybackFrameTime{};
uint64_t g_compactPlaybackAccentThumbnailHash = UINT64_MAX;
winrt::Windows::UI::Color g_compactPlaybackAccentFrom{0xFF, 0x4F, 0x7D, 0xE8};
winrt::Windows::UI::Color g_compactPlaybackAccentTo{0xFF, 0x4F, 0x7D, 0xE8};
winrt::Windows::UI::Color g_compactPlaybackAccentDisplayed{0xFF, 0x4F, 0x7D,
                                                           0xE8};
bool g_compactPlaybackAccentTransitionActive = false;
std::chrono::steady_clock::time_point g_compactPlaybackAccentTransitionStart{};
winrt::event_token g_compactTextRenderingToken{};
bool g_compactTextRenderingHooked = false;
double g_compactTextProgress = 1.0;
std::chrono::steady_clock::time_point g_lastCompactTextFrameTime{};
bool g_compactTextEdgeFadeActive = false;
HWND g_taskbarLayoutTimerWindow = nullptr;
FrameworkElement g_taskbarLayoutWatchRoot = nullptr;
FrameworkElement g_taskbarLayoutWatchTarget = nullptr;
bool g_compactTextInitialized = false;
std::wstring g_compactLastTitle;
std::wstring g_compactLastArtist;
uint64_t g_compactLastTextMediaHash = UINT64_MAX;

void* CTaskBand_ITaskListWndSite_vftable = nullptr;
CTaskBand_GetTaskbarHost_t CTaskBand_GetTaskbarHost_Original = nullptr;
TaskbarHost_FrameHeight_t TaskbarHost_FrameHeight_Original = nullptr;
Std_Ref_Decref_t Std_Ref_Decref_Original = nullptr;
TrayUI_StartTaskbar_t TrayUI_StartTaskbar_Original = nullptr;
TrayUI__Hide_t TrayUI__Hide_Original = nullptr;
TrayUI_Unhide_t TrayUI_Unhide_Original = nullptr;
CSecondaryTray__AutoHide_t CSecondaryTray__AutoHide_Original = nullptr;
CSecondaryTray__Unhide_t CSecondaryTray__Unhide_Original = nullptr;

template <typename T>

// ===== Shared helpers =====
T Clamp(T value, T lo, T hi) {
    return std::max(lo, std::min(value, hi));
}

winrt::Windows::UI::Color Color(BYTE a, BYTE r, BYTE g, BYTE b) {
    return winrt::Windows::UI::Color{a, r, g, b};
}

winrt::Windows::UI::Color ColorFromPbgra(BYTE const* pixel) {
    BYTE alpha = pixel[3];
    if (alpha == 0) {
        return Color(0, 0, 0, 0);
    }

    double inverseAlpha = 255.0 / alpha;
    return Color(alpha,
                 static_cast<BYTE>(
                     Clamp(std::lround(pixel[2] * inverseAlpha), 0L, 255L)),
                 static_cast<BYTE>(
                     Clamp(std::lround(pixel[1] * inverseAlpha), 0L, 255L)),
                 static_cast<BYTE>(
                     Clamp(std::lround(pixel[0] * inverseAlpha), 0L, 255L)));
}

DWORD FindAppleMusicProcessId() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }
    PROCESSENTRY32W entry{sizeof(entry)};
    DWORD processId = 0;
    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (_wcsicmp(entry.szExeFile, L"AppleMusic.exe") == 0) {
                processId = entry.th32ProcessID;
                break;
            }
        } while (Process32NextW(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return processId;
}

bool TrySeekAppleMusicWithUiAutomation(double ratio) {
    DWORD processId = FindAppleMusicProcessId();
    if (!processId) {
        return false;
    }

    IUIAutomation* automation = nullptr;
    IUIAutomationElement* root = nullptr;
    IUIAutomationCondition* processCondition = nullptr;
    IUIAutomationCondition* idCondition = nullptr;
    IUIAutomationCondition* combinedCondition = nullptr;
    IUIAutomationElement* scrubber = nullptr;
    IUnknown* unknown = nullptr;
    IUIAutomationRangeValuePattern* range = nullptr;
    bool succeeded = false;

    HRESULT result =
        CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER,
                         IID_PPV_ARGS(&automation));
    VARIANT processVariant{};
    processVariant.vt = VT_I4;
    processVariant.lVal = static_cast<LONG>(processId);
    VARIANT idVariant{};
    idVariant.vt = VT_BSTR;
    idVariant.bstrVal = SysAllocString(L"LCDScrubber");

    if (SUCCEEDED(result)) {
        result = automation->GetRootElement(&root);
    }
    if (SUCCEEDED(result)) {
        result = automation->CreatePropertyCondition(
            UIA_ProcessIdPropertyId, processVariant, &processCondition);
    }
    if (SUCCEEDED(result) && idVariant.bstrVal) {
        result = automation->CreatePropertyCondition(UIA_AutomationIdPropertyId,
                                                     idVariant, &idCondition);
    }
    if (SUCCEEDED(result)) {
        result = automation->CreateAndCondition(processCondition, idCondition,
                                                &combinedCondition);
    }
    if (SUCCEEDED(result)) {
        result =
            root->FindFirst(TreeScope_Subtree, combinedCondition, &scrubber);
        if (SUCCEEDED(result) && !scrubber) {
            result = HRESULT_FROM_WIN32(ERROR_NOT_FOUND);
        }
    }
    if (SUCCEEDED(result)) {
        result = scrubber->GetCurrentPattern(UIA_RangeValuePatternId, &unknown);
    }
    if (SUCCEEDED(result)) {
        result = unknown->QueryInterface(IID_PPV_ARGS(&range));
    }
    if (SUCCEEDED(result)) {
        BOOL readOnly = TRUE;
        double minimum = 0.0;
        double maximum = 0.0;
        result = range->get_CurrentIsReadOnly(&readOnly);
        if (SUCCEEDED(result))
            result = range->get_CurrentMinimum(&minimum);
        if (SUCCEEDED(result))
            result = range->get_CurrentMaximum(&maximum);
        if (SUCCEEDED(result) && !readOnly && maximum > minimum) {
            double value =
                minimum + (maximum - minimum) * Clamp(ratio, 0.0, 1.0);
            result = range->SetValue(value);
            succeeded = SUCCEEDED(result);
        }
    }

    VariantClear(&idVariant);
    if (range)
        range->Release();
    if (unknown)
        unknown->Release();
    if (scrubber)
        scrubber->Release();
    if (combinedCondition)
        combinedCondition->Release();
    if (idCondition)
        idCondition->Release();
    if (processCondition)
        processCondition->Release();
    if (root)
        root->Release();
    if (automation)
        automation->Release();

    Wh_Log(L"Island: Apple Music UI Automation seek result=%d hr=0x%08X",
           succeeded, static_cast<unsigned>(result));
    return succeeded;
}

SolidColorBrush Brush(winrt::Windows::UI::Color color) {
    return SolidColorBrush(color);
}

void AttachGpuFriendlyTransform(FrameworkElement const& element,
                                ScaleTransform& scale,
                                TranslateTransform& translate) {
    if (!element) {
        return;
    }

    scale = ScaleTransform();
    translate = TranslateTransform();
    TransformGroup group;
    group.Children().Append(scale);
    group.Children().Append(translate);
    element.RenderTransformOrigin({0.0, 0.0});
    element.RenderTransform(group);
}

void SetElementSizeIfChanged(FrameworkElement const& element,
                             double width,
                             double height) {
    if (!element) {
        return;
    }

    width = std::max(1.0, width);
    height = std::max(1.0, height);
    double currentWidth = element.Width();
    double currentHeight = element.Height();
    if (std::isnan(currentWidth) || std::abs(currentWidth - width) > 0.5) {
        element.Width(width);
    }
    if (std::isnan(currentHeight) || std::abs(currentHeight - height) > 0.5) {
        element.Height(height);
    }
}

void SetCanvasPositionIfChanged(FrameworkElement const& element,
                                double left,
                                double top) {
    if (!element) {
        return;
    }

    double currentLeft = controls::Canvas::GetLeft(element);
    double currentTop = controls::Canvas::GetTop(element);
    if (std::isnan(currentLeft) || std::abs(currentLeft - left) > 0.25) {
        controls::Canvas::SetLeft(element, left);
    }
    if (std::isnan(currentTop) || std::abs(currentTop - top) > 0.25) {
        controls::Canvas::SetTop(element, top);
    }
}

void ApplyLayoutRect(FrameworkElement const& element,
                     ScaleTransform const& scale,
                     TranslateTransform const& translate,
                     DipRect const& currentScreen,
                     RECT const& popupScreen) {
    if (!element) {
        return;
    }

    double currentWidth =
        std::max(1.0, currentScreen.right - currentScreen.left);
    double currentHeight =
        std::max(1.0, currentScreen.bottom - currentScreen.top);
    SetElementSizeIfChanged(element, currentWidth, currentHeight);
    SetCanvasPositionIfChanged(element, currentScreen.left - popupScreen.left,
                               currentScreen.top - popupScreen.top);
    if (scale) {
        scale.ScaleX(1.0);
        scale.ScaleY(1.0);
    }
    if (translate) {
        translate.X(0.0);
        translate.Y(0.0);
    }
}

bool IsDarkModeApprox() {
    HKEY key = nullptr;
    DWORD value = 1;
    DWORD size = sizeof(value);
    if (RegOpenKeyExW(HKEY_CURRENT_USER,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\P"
                      L"ersonalize",
                      0, KEY_READ, &key) == ERROR_SUCCESS) {
        RegQueryValueExW(key, L"AppsUseLightTheme", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&value), &size);
        RegCloseKey(key);
    }

    return value == 0;
}

bool IsLiquidGlassMaterial() {
    return g_settings.material == L"liquid_glass";
}

winrt::Windows::UI::Color IslandBackgroundColor() {
    bool dark = IsDarkModeApprox();
    if (g_settings.material == L"mica_like") {
        return dark ? Color(0xC8, 0x2A, 0x2A, 0x2F)
                    : Color(0xD4, 0xF3, 0xF3, 0xF6);
    }

    if (IsLiquidGlassMaterial()) {
        return dark ? Color(0xC8, 0x18, 0x1A, 0x20)
                    : Color(0xDE, 0xFB, 0xFC, 0xFF);
    }

    if (g_settings.material == L"acrylic") {
        // XAML AcrylicBrush can switch to its fallback when the taskbar/XAML
        // island loses focus, which makes the compact island suddenly look gray
        // and dirty. The expanded acrylic path uses a native overlay instead;
        // keep the compact surface visually stable with a tinted brush.
        return dark ? Color(0xD8, 0x20, 0x20, 0x24)
                    : Color(0xEA, 0xF8, 0xF8, 0xFA);
    }

    return dark ? Color(0xE8, 0x20, 0x20, 0x24) : Color(0xE8, 0xF4, 0xF4, 0xF6);
}

mediax::Brush LiquidGlassRimHighlightBrush() {
    // A single neutral hairline defines the glass boundary. It is neither a
    // gradient nor an outer glow and casts no shadow.
    return Brush(IsDarkModeApprox() ? Color(0x56, 0xFF, 0xFF, 0xFF)
                                    : Color(0x70, 0xFF, 0xFF, 0xFF));
}

mediax::Brush LiquidGlassSurfaceHighlightBrush() {
    if (!g_settings.liquidGlassGradient) {
        return Brush(Color(0x00, 0x00, 0x00, 0x00));
    }
    bool dark = IsDarkModeApprox();
    mediax::LinearGradientBrush brush;
    brush.StartPoint({0.08f, 0.0f});
    brush.EndPoint({0.72f, 0.92f});
    mediax::GradientStopCollection stops;

    auto addStop = [&](double offset, winrt::Windows::UI::Color const& color) {
        mediax::GradientStop stop;
        stop.Offset(offset);
        stop.Color(color);
        stops.Append(stop);
    };

    addStop(0.00, dark ? Color(0x26, 0xFF, 0xFF, 0xFF)
                       : Color(0x70, 0xFF, 0xFF, 0xFF));
    addStop(0.16, dark ? Color(0x14, 0xFF, 0xFF, 0xFF)
                       : Color(0x44, 0xFF, 0xFF, 0xFF));
    addStop(0.48, Color(0x00, 0xFF, 0xFF, 0xFF));
    addStop(0.76, Color(0x00, 0xFF, 0xFF, 0xFF));
    addStop(1.00, dark ? Color(0x10, 0xFF, 0xFF, 0xFF)
                       : Color(0x32, 0xFF, 0xFF, 0xFF));
    brush.GradientStops(stops);
    return brush;
}

mediax::Brush IslandBorderBrush() {
    bool dark = IsDarkModeApprox();
    if (IsLiquidGlassMaterial()) {
        return LiquidGlassRimHighlightBrush();
    }

    return Brush(dark ? Color(0x36, 0xFF, 0xFF, 0xFF)
                      : Color(0x26, 0x00, 0x00, 0x00));
}

mediax::Brush CompactPlaybackControlStrokeBrush() {
    if (IsLiquidGlassMaterial()) {
        return LiquidGlassRimHighlightBrush();
    }

    bool dark = IsDarkModeApprox();
    return Brush(dark ? Color(0x20, 0xFF, 0xFF, 0xFF)
                      : Color(0x16, 0x00, 0x00, 0x00));
}

mediax::Brush PopupAlbumArtStrokeBrush() {
    if (IsLiquidGlassMaterial()) {
        return LiquidGlassRimHighlightBrush();
    }

    // Match the bright directional edge used by native Windows 11 surfaces.
    // This stroke always brightens instead of adapting to a dark color.
    bool dark = IsDarkModeApprox();
    mediax::LinearGradientBrush brush;
    brush.StartPoint({0.0f, 0.0f});
    brush.EndPoint({1.0f, 1.0f});
    mediax::GradientStopCollection stops;
    auto addStop = [&](double offset, BYTE alpha) {
        mediax::GradientStop stop;
        stop.Offset(offset);
        stop.Color(Color(alpha, 0xFF, 0xFF, 0xFF));
        stops.Append(stop);
    };
    addStop(0.00, dark ? 0x78 : 0xA0);
    addStop(0.46, dark ? 0x30 : 0x48);
    addStop(1.00, dark ? 0x58 : 0x70);
    brush.GradientStops(stops);
    return brush;
}

void ConfigureCompactAlbumArtStroke(Border const& stroke) {
    if (!stroke) {
        return;
    }

    // The stroke sits in Island_ArtShell, outside the clipped image host.
    // Keep it exactly aligned with the artwork bounds; otherwise the border
    // looks like it has drifted inward relative to the cover.
    double size = std::max(1.0, g_layout.artSize);
    double radius = std::max(1.0, g_layout.artCornerRadius);

    stroke.Width(size);
    stroke.Height(size);
    stroke.Margin({0, 0, 0, 0});
    stroke.HorizontalAlignment(HorizontalAlignment::Center);
    stroke.VerticalAlignment(VerticalAlignment::Center);
    stroke.CornerRadius({radius, radius, radius, radius});
    stroke.Background(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    stroke.BorderThickness({0.0, 0.0, 0.0, 0.0});
    stroke.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    stroke.IsHitTestVisible(false);
}

std::vector<uint8_t> ReadThumbnailBytes(
    streams::IRandomAccessStreamReference const& thumbnail) {
    std::vector<uint8_t> bytes;
    if (!thumbnail) {
        return bytes;
    }

    try {
        auto stream = GetAsyncResultWithTimeout(thumbnail.OpenReadAsync(),
                                                kThumbnailAsyncTimeout,
                                                L"thumbnail OpenReadAsync");
        uint64_t size64 = stream.Size();
        if (size64 == 0 || size64 > 8 * 1024 * 1024) {
            return bytes;
        }

        uint32_t size = static_cast<uint32_t>(size64);
        auto buffer = GetAsyncResultWithTimeout(
            stream.ReadAsync(streams::Buffer(size), size,
                             streams::InputStreamOptions::None),
            kThumbnailAsyncTimeout, L"thumbnail ReadAsync");
        streams::DataReader reader = streams::DataReader::FromBuffer(buffer);
        bytes.resize(buffer.Length());
        if (!bytes.empty()) {
            reader.ReadBytes(winrt::array_view<uint8_t>(bytes));
        }
    } catch (...) {
        bytes.clear();
    }

    return bytes;
}

std::wstring GetStringSetting(const wchar_t* key, const wchar_t* fallback) {
    auto setting = WindhawkUtils::StringSetting::make(key);
    PCWSTR value = setting.get();
    return value && *value ? value : fallback;
}

// ===== Settings =====
// Compact island height bounds. Kept in one place so the settings page, the
// runtime layout maths and the safety clamps always agree.
constexpr int kCompactHeightMin = 28;
constexpr int kCompactHeightMax = 72;

// Parses "#RRGGBB" or "#AARRGGBB" (the leading '#' is optional). Returns false
// for any other length or a non-hex character.
bool ParseAccentColorHex(std::wstring_view text,
                         winrt::Windows::UI::Color& out) {
    while (!text.empty() && iswspace(text.front())) {
        text.remove_prefix(1);
    }
    while (!text.empty() && iswspace(text.back())) {
        text.remove_suffix(1);
    }
    if (!text.empty() && text.front() == L'#') {
        text.remove_prefix(1);
    }
    if (text.size() != 6 && text.size() != 8) {
        return false;
    }

    auto hexDigit = [](wchar_t ch) -> int {
        if (ch >= L'0' && ch <= L'9') {
            return ch - L'0';
        }
        if (ch >= L'a' && ch <= L'f') {
            return ch - L'a' + 10;
        }
        if (ch >= L'A' && ch <= L'F') {
            return ch - L'A' + 10;
        }
        return -1;
    };

    uint32_t value = 0;
    for (wchar_t ch : text) {
        int digit = hexDigit(ch);
        if (digit < 0) {
            return false;
        }
        value = (value << 4) | static_cast<uint32_t>(digit);
    }
    if (text.size() == 6) {
        value |= 0xFF000000u;
    }
    out = Color(static_cast<BYTE>(value >> 24), static_cast<BYTE>(value >> 16),
                static_cast<BYTE>(value >> 8), static_cast<BYTE>(value));
    return true;
}

// True when the user selected a valid custom accent colour. Every accent
// consumer falls back to the artwork-derived colour when this returns false.
bool CustomAccentColor(winrt::Windows::UI::Color& out) {
    if (g_settings.accentColorMode != L"custom" ||
        !g_settings.hasCustomAccent) {
        return false;
    }
    out = g_settings.customAccentColor;
    return true;
}

// Idle-state (no media session) text. Empty settings fall back to the built-in
// wording so the island never shows a blank line.
std::wstring DefaultIdleTitle() {
    return g_settings.defaultTitle.empty() ? std::wstring(L"No media")
                                           : g_settings.defaultTitle;
}

std::wstring DefaultIdleArtist() {
    return g_settings.defaultArtist.empty() ? std::wstring(L"No media playing")
                                            : g_settings.defaultArtist;
}

constexpr int kSettingsMigrationVersion = 1;
constexpr wchar_t kMigrateMicaLikeMaterialValue[] =
    L"MigrateMicaLikeMaterialToAcrylic";

void ApplySettingsMigrations(Settings* settings) {
    int migratedVersion = Wh_GetIntValue(L"SettingsMigrationVersion", 0);
    if (migratedVersion < kSettingsMigrationVersion) {
        if (settings->material == L"mica_like") {
            Wh_SetIntValue(kMigrateMicaLikeMaterialValue, 1);
        }
        Wh_SetIntValue(L"SettingsMigrationVersion", kSettingsMigrationVersion);
    }

    if (Wh_GetIntValue(kMigrateMicaLikeMaterialValue, 0)) {
        if (settings->material == L"mica_like") {
            settings->material = L"acrylic";
        } else {
            Wh_SetIntValue(kMigrateMicaLikeMaterialValue, 0);
        }
    }
}

Settings ReadSettings() {
    Settings settings;
    settings.position = GetStringSetting(L"Main.Position", L"tray_left");
    settings.compactWidth =
        Clamp(Wh_GetIntSetting(L"Main.CompactWidth"), 96, 320);
    settings.autoSizeToTaskbar =
        Wh_GetIntSetting(L"Main.AutoSizeToTaskbar") != 0;
    settings.expandedWidth =
        Clamp(Wh_GetIntSetting(L"Main.ExpandedWidth"), 240, 640);
    settings.compact = Wh_GetIntSetting(L"Main.Compact") != 0;
    settings.popupSpacing =
        Clamp(Wh_GetIntSetting(L"Main.PopupSpacing"), 2, 40);
    settings.popupCardGap =
        Clamp(Wh_GetIntSetting(L"Main.PopupCardGap"), 0, 40);
    settings.popupShadowDepth =
        Clamp(Wh_GetIntSetting(L"Main.PopupShadowDepth"), 0, 128);
    settings.popupShadowOpacity =
        Clamp(Wh_GetIntSetting(L"Main.PopupShadowOpacity"), 0, 100);
    settings.popupButtonStyle =
        GetStringSetting(L"Main.PopupButtonStyle", L"fluent_bold");
    if (settings.popupButtonStyle != L"minimal_transport" &&
        settings.popupButtonStyle != L"fluent_bold") {
        settings.popupButtonStyle = L"minimal_transport";
    }
    settings.popupBackdropCoverEffect =
        GetStringSetting(L"Main.PopupBackdropCoverEffect", L"dark_only");
    if (settings.popupBackdropCoverEffect != L"off" &&
        settings.popupBackdropCoverEffect != L"dark_only" &&
        settings.popupBackdropCoverEffect != L"on") {
        settings.popupBackdropCoverEffect = L"dark_only";
    }
    settings.artworkAbstractMode =
        GetStringSetting(L"Main.ArtworkAbstractMode", L"browser_original");
    if (settings.artworkAbstractMode == L"off") {
        settings.artworkAbstractMode = L"browser_original";
    }
    if (settings.artworkAbstractMode != L"browser_original" &&
        settings.artworkAbstractMode != L"mesh_gradient" &&
        settings.artworkAbstractMode != L"energy_flame") {
        settings.artworkAbstractMode = L"browser_original";
    }
    settings.defaultCoverImage =
        GetStringSetting(L"Main.DefaultCoverImage", L"");
    settings.defaultTitle =
        GetStringSetting(L"Main.DefaultTitle", L"Island Beat Float");
    if (settings.defaultTitle.empty()) {
        settings.defaultTitle = L"Island Beat Float";
    }
    settings.defaultArtist =
        GetStringSetting(L"Main.DefaultArtist", L"No media playing");
    if (settings.defaultArtist.empty()) {
        settings.defaultArtist = L"No media playing";
    }
    settings.accentColorMode =
        GetStringSetting(L"Main.AccentColorMode", L"artwork");
    settings.accentColor = GetStringSetting(L"Main.AccentColor", L"#6EB85A");
    if (settings.accentColorMode != L"artwork" &&
        settings.accentColorMode != L"custom") {
        settings.accentColorMode = L"artwork";
    }
    // A malformed custom colour must never leave the island with an unusable
    // accent: fall back to the artwork-derived behaviour instead.
    settings.hasCustomAccent =
        settings.accentColorMode == L"custom" &&
        ParseAccentColorHex(settings.accentColor, settings.customAccentColor);
    if (!settings.hasCustomAccent) {
        settings.accentColorMode = L"artwork";
    }
    settings.height = Clamp(Wh_GetIntSetting(L"Main.Height"), kCompactHeightMin,
                            kCompactHeightMax);
    settings.marginLeft = Clamp(Wh_GetIntSetting(L"Main.MarginLeft"), 0, 48);
    settings.marginRight = Clamp(Wh_GetIntSetting(L"Main.MarginRight"), 0, 48);
    settings.hideWhenNoMedia = Wh_GetIntSetting(L"Main.HideWhenNoMedia") != 0;
    settings.hoverScale = static_cast<double>(Clamp(
                              Wh_GetIntSetting(L"Main.HoverScale"), 100, 125)) /
                          100.0;
    settings.hoverLerpSpeed = static_cast<double>(
        Clamp(Wh_GetIntSetting(L"Main.HoverLerpSpeed"), 1, 80));
    settings.animationSpeed =
        static_cast<double>(
            Clamp(Wh_GetIntSetting(L"Main.AnimationSpeed"), 10, 400)) /
        100.0;

    settings.material = GetStringSetting(L"Main.Material", L"liquid_glass");
    if (settings.material != L"mica_like" && settings.material != L"solid" &&
        settings.material != L"acrylic" &&
        settings.material != L"liquid_glass") {
        settings.material = L"liquid_glass";
    }
    ApplySettingsMigrations(&settings);
    settings.liquidGlassGradient =
        Wh_GetIntSetting(L"Main.LiquidGlassGradient") != 0;
    settings.liquidGlassCornerRadius =
        Clamp(Wh_GetIntSetting(L"Main.LiquidGlassCornerRadius"), 8, 64);
    settings.liquidGlassFrost =
        Clamp(Wh_GetIntSetting(L"Main.LiquidGlassFrost"), 0, 24);
    settings.liquidGlassRefraction =
        Clamp(Wh_GetIntSetting(L"Main.LiquidGlassRefraction"), 0, 100);
    settings.liquidGlassRoundness =
        Clamp(Wh_GetIntSetting(L"Main.LiquidGlassRoundness"), 2, 8);
    settings.backdropInitialFrameSkip =
        Clamp(Wh_GetIntSetting(L"Main.BackdropInitialFrameSkip"), 0, 3);
    settings.backdropFallbackBlurPasses =
        Clamp(Wh_GetIntSetting(L"Main.BackdropFallbackBlurPasses"), 4, 6);
    settings.backdropFallbackCaptureScale =
        Clamp(Wh_GetIntSetting(L"Main.BackdropFallbackCaptureScale"), 2, 3);
    settings.allowScreenCapture =
        Wh_GetIntSetting(L"Main.AllowScreenCapture") != 0;
    return settings;
}

// ===== Taskbar host utilities =====
HWND FindCurrentProcessTaskbarWnd() {
    HWND result = nullptr;
    EnumWindows(
        [](HWND hwnd, LPARAM param) -> BOOL {
            DWORD pid = 0;
            wchar_t className[64]{};
            if (GetWindowThreadProcessId(hwnd, &pid) &&
                pid == GetCurrentProcessId() &&
                GetClassNameW(hwnd, className, ARRAYSIZE(className)) &&
                _wcsicmp(className, L"Shell_TrayWnd") == 0) {
                *reinterpret_cast<HWND*>(param) = hwnd;
                return FALSE;
            }
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&result));
    return result;
}

bool RunFromWindowThread(HWND hwnd, WindowThreadProc proc, void* param) {
    static const UINT msg =
        RegisterWindowMessageW(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
    struct Payload {
        WindowThreadProc proc;
        void* param;
    };

    DWORD tid = GetWindowThreadProcessId(hwnd, nullptr);
    if (!tid) {
        return false;
    }

    if (tid == GetCurrentThreadId()) {
        try {
            proc(param);
        } catch (...) {
            Wh_Log(L"Island: exception in taskbar-thread callback");
            return false;
        }
        return true;
    }

    HHOOK hook = SetWindowsHookExW(
        WH_CALLWNDPROC,
        [](int code, WPARAM wParam, LPARAM lParam) -> LRESULT {
            if (code == HC_ACTION) {
                auto cwp = reinterpret_cast<const CWPSTRUCT*>(lParam);
                static const UINT innerMsg = RegisterWindowMessageW(
                    L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
                if (cwp->message == innerMsg) {
                    auto payload = reinterpret_cast<Payload*>(cwp->lParam);
                    try {
                        payload->proc(payload->param);
                    } catch (...) {
                        Wh_Log(
                            L"Island: exception in taskbar-thread hook "
                            L"callback");
                    }
                }
            }
            return CallNextHookEx(nullptr, code, wParam, lParam);
        },
        nullptr, tid);

    if (!hook) {
        return false;
    }

    Payload payload{proc, param};
    SendMessageW(hwnd, msg, 0, reinterpret_cast<LPARAM>(&payload));
    UnhookWindowsHookEx(hook);
    return true;
}

xaml::XamlRoot GetTaskbarXamlRoot(HWND taskbarWnd) {
    HWND taskSwWnd =
        reinterpret_cast<HWND>(GetPropW(taskbarWnd, L"TaskbandHWND"));
    if (!taskSwWnd) {
        return nullptr;
    }

    void* taskBand = reinterpret_cast<void*>(GetWindowLongPtrW(taskSwWnd, 0));
    void* taskBandForSite = taskBand;
    for (int i = 0; i < 20; ++i) {
        if (*reinterpret_cast<void**>(taskBandForSite) ==
            CTaskBand_ITaskListWndSite_vftable) {
            break;
        }
        taskBandForSite = reinterpret_cast<void**>(taskBandForSite) + 1;
        if (i == 19) {
            return nullptr;
        }
    }

    void* taskbarHostSharedPtr[2]{};
    CTaskBand_GetTaskbarHost_Original(taskBandForSite, taskbarHostSharedPtr);
    if (!taskbarHostSharedPtr[0] && !taskbarHostSharedPtr[1]) {
        return nullptr;
    }

    size_t elementOffset = 0x10;
#if defined(_M_X64) || defined(__x86_64__)
    const BYTE* bytes =
        reinterpret_cast<const BYTE*>(TaskbarHost_FrameHeight_Original);
    if (bytes[0] == 0x48 && bytes[1] == 0x83 && bytes[2] == 0xEC &&
        bytes[4] == 0x48 && bytes[5] == 0x83 && bytes[6] == 0xC1 &&
        bytes[7] <= 0x7F) {
        elementOffset = bytes[7];
    }
#elif defined(_M_ARM64) || defined(__aarch64__)
    const DWORD* words =
        reinterpret_cast<const DWORD*>(TaskbarHost_FrameHeight_Original);
    if (words[0] == 0xD503237F && (words[1] & 0xFFC07FFF) == 0xA9807BFD &&
        words[2] == 0x910003FD && (words[3] & 0xFFF00FE0) == 0xF8400C00) {
        elementOffset = (words[3] >> 12) & 0xFF;
    }
#endif

    auto elementUnknown = *reinterpret_cast<IUnknown**>(
        reinterpret_cast<BYTE*>(taskbarHostSharedPtr[0]) + elementOffset);

    FrameworkElement taskbarElement{nullptr};
    if (elementUnknown) {
        elementUnknown->QueryInterface(winrt::guid_of<FrameworkElement>(),
                                       winrt::put_abi(taskbarElement));
    }

    auto root = taskbarElement ? taskbarElement.XamlRoot() : nullptr;
    if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original) {
        Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
    }
    return root;
}

FrameworkElement FindChildByName(FrameworkElement const& root,
                                 std::wstring_view name,
                                 int depth = 32) {
    if (!root || depth <= 0) {
        return nullptr;
    }

    int count = VisualTreeHelper::GetChildrenCount(root);
    for (int i = 0; i < count; ++i) {
        auto child =
            VisualTreeHelper::GetChild(root, i).try_as<FrameworkElement>();
        if (!child) {
            continue;
        }
        if (child.Name() == name) {
            return child;
        }
        if (auto found = FindChildByName(child, name, depth - 1)) {
            return found;
        }
    }
    return nullptr;
}

Grid FindTaskbarRootGrid(FrameworkElement const& root) {
    auto frame = FindChildByName(root, L"TaskbarFrame");
    if (!frame) {
        frame = FindChildByName(root, L"TaskbarFrameRepeater");
    }

    auto rootGrid = frame ? FindChildByName(frame, L"RootGrid") : nullptr;
    if (!rootGrid) {
        rootGrid = FindChildByName(root, L"RootGrid");
    }
    return rootGrid ? rootGrid.try_as<Grid>() : nullptr;
}

struct InjectionTarget {
    Grid grid = nullptr;
    int column = -1;
    bool overlay = false;
};

InjectionTarget ResolveInjectionTarget(FrameworkElement const& root) {
    auto trayFrame = FindChildByName(root, L"SystemTrayFrameGrid");
    if (auto trayGrid = trayFrame ? trayFrame.try_as<Grid>() : nullptr) {
        int col = -1;
        if (g_settings.position == L"tray_left") {
            col = 0;
        } else if (g_settings.position == L"tray_right") {
            col = static_cast<int>(trayGrid.ColumnDefinitions().Size());
        } else if (g_settings.position == L"tray_before_clock") {
            auto clock = FindChildByName(trayGrid, L"NotificationCenterButton");
            if (!clock) {
                clock = FindChildByName(root, L"NotificationCenterButton");
            }
            col = clock ? controls::Grid::GetColumn(clock) : -1;
        } else if (g_settings.position == L"tray_after_clock") {
            auto showDesktop = FindChildByName(trayGrid, L"ShowDesktopStack");
            if (!showDesktop) {
                showDesktop = FindChildByName(root, L"ShowDesktopStack");
            }
            col = showDesktop ? controls::Grid::GetColumn(showDesktop) : -1;
        }

        if (col >= 0) {
            return {trayGrid, col, false};
        }
    }

    auto rootGrid = FindTaskbarRootGrid(root);
    if (rootGrid) {
        return {rootGrid, 0, true};
    }

    return {};
}

// ===== Media state model =====
std::wstring MediaIdentityKey(MediaState const& state) {
    if (!state.hasSession) {
        return L"";
    }

    // Deliberately excludes artwork bytes. Browsers can emit metadata before a
    // live-room/video thumbnail is available, and some providers temporarily
    // repeat the previous thumbnail. This key represents the actual media item
    // for deciding whether old artwork can be reused safely.
    return state.sourceAppUserModelId + L"\n" + state.title + L"\n" +
           state.artist + L"\n" + std::to_wstring(state.durationTicks);
}

bool LooksLikeNativeMusicMediaSource(std::wstring const& source) {
    std::wstring lower;
    lower.reserve(source.size());
    for (wchar_t ch : source) {
        lower.push_back(static_cast<wchar_t>(std::towlower(ch)));
    }

    // Explicitly keep native music players out of the browser/live-thumbnail
    // path. Some providers use AppUserModelIds that contain generic substrings
    // which can otherwise be over-matched by the browser heuristics below.
    return lower.find(L"qqmusic") != std::wstring::npos ||
           lower.find(L"qq音乐") != std::wstring::npos ||
           lower.find(L"tencent.qqmusic") != std::wstring::npos ||
           lower.find(L"tencentmusic") != std::wstring::npos ||
           lower.find(L"spotify") != std::wstring::npos ||
           lower.find(L"applemusic") != std::wstring::npos ||
           lower.find(L"music.ui") != std::wstring::npos ||
           lower.find(L"zunemusic") != std::wstring::npos;
}

bool LooksLikeBrowserMediaSource(std::wstring const& source) {
    std::wstring lower;
    lower.reserve(source.size());
    for (wchar_t ch : source) {
        lower.push_back(static_cast<wchar_t>(std::towlower(ch)));
    }

    if (LooksLikeNativeMusicMediaSource(source)) {
        return false;
    }

    return lower.find(L"chrome") != std::wstring::npos ||
           lower.find(L"chromium") != std::wstring::npos ||
           lower.find(L"msedge") != std::wstring::npos ||
           lower.find(L"microsoftedge") != std::wstring::npos ||
           lower.find(L"firefox") != std::wstring::npos ||
           lower.find(L"brave") != std::wstring::npos ||
           lower.find(L"opera") != std::wstring::npos ||
           lower.find(L"vivaldi") != std::wstring::npos ||
           lower.find(L"arc") != std::wstring::npos ||
           lower.find(L"browser") != std::wstring::npos ||
           lower.find(L"zen") != std::wstring::npos ||
           lower.find(L"floorp") != std::wstring::npos ||
           lower.find(L"librewolf") != std::wstring::npos ||
           lower.find(L"yandex") != std::wstring::npos ||
           lower.find(L"safari") != std::wstring::npos;
}

std::wstring MediaTrackKey(MediaState const& state) {
    if (!state.hasSession) {
        return L"";
    }
    if (!state.mediaId.empty()) {
        // A player can publish the new title before replacing its media id.
        // Include both so the first new-song sample can't inherit old progress.
        return state.sourceAppUserModelId + L"\n" + state.mediaId + L"\n" +
               state.title;
    }
    // Artist often arrives one event after title, so don't reset twice merely
    // because that secondary metadata was filled in.
    return state.sourceAppUserModelId + L"\n" + state.title + L"\n" +
           std::to_wstring(state.durationTicks);
}

bool ShouldForceMediaProgressToZero(MediaState const& state,
                                    std::chrono::steady_clock::time_point now) {
    if (!state.hasSession) {
        g_mediaProgressResetKey.clear();
        g_mediaProgressResetStarted = {};
        g_mediaProgressResetUntil = {};
        return false;
    }

    std::wstring key =
        MediaTrackKey(state) + L"\n" + std::to_wstring(state.durationTicks);
    if (key != g_mediaProgressResetKey) {
        g_mediaProgressResetKey = std::move(key);
        g_mediaProgressResetStarted = now;
        // Providers frequently publish the new title one event before their
        // timeline. Hold zero briefly so the old song's timestamp cannot leak
        // into the new song's progress bar.
        g_mediaProgressResetUntil = now + std::chrono::milliseconds(1500);
        return true;
    }

    if (g_mediaProgressResetUntil.time_since_epoch().count() == 0) {
        return false;
    }
    if (now - g_mediaProgressResetStarted < std::chrono::milliseconds(280)) {
        return true;
    }
    if (state.positionTicks <= 5 * 10000000LL ||
        now >= g_mediaProgressResetUntil) {
        g_mediaProgressResetUntil = {};
        return false;
    }
    return true;
}

MediaState SnapshotMedia() {
    std::lock_guard lock(g_mediaMutex);
    return g_media;
}

MediaState SnapshotMediaWithTimestamp(
    std::chrono::steady_clock::time_point& timestamp) {
    std::lock_guard lock(g_mediaMutex);
    timestamp = g_mediaStateTimestamp;
    return g_media;
}

void SetMedia(MediaState&& state) {
    std::lock_guard lock(g_mediaMutex);
    auto now = std::chrono::steady_clock::now();

    if (g_optimisticPlaybackPending) {
        bool sameSource = state.hasSession &&
                          _wcsicmp(state.sourceAppUserModelId.c_str(),
                                   g_optimisticPlaybackSource.c_str()) == 0;
        if (!sameSource || now >= g_optimisticPlaybackUntil) {
            g_optimisticPlaybackPending = false;
            g_optimisticPlaybackSource.clear();
        } else if (state.isPlaying == g_optimisticPlaybackDesired) {
            // The provider has caught up with the click. From this point on its
            // playback events are authoritative again.
            g_optimisticPlaybackPending = false;
            g_optimisticPlaybackSource.clear();
        } else {
            // NetEase UI Automation and some GSMTC providers briefly re-emit
            // their pre-click state. Keep the button responsive while waiting
            // for the real player to acknowledge the command.
            state.isPlaying = g_optimisticPlaybackDesired;
        }
    }

    // Artwork can arrive asynchronously after the matching title and timeline.
    // It must not turn the same song into a "new media" item, otherwise the
    // committed seek position is discarded exactly when the cover appears.
    std::wstring currentKey = MediaTrackKey(g_media);
    std::wstring nextKey = MediaTrackKey(state);

    bool observedTrackChange = g_media.hasSession && state.hasSession &&
                               !currentKey.empty() && !nextKey.empty() &&
                               currentKey != nextKey;
    if (observedTrackChange) {
        // Metadata and timeline are separate GSMTC events. Several providers
        // publish the new title/id while their TimelineProperties still belong
        // to the previous song. Quarantine that mixed snapshot at the source;
        // otherwise every UI-level zero can be overwritten on the next poll.
        g_timelineQuarantineTrackKey = nextKey;
        g_timelineQuarantinePreviousPositionTicks = g_media.positionTicks;
        g_timelineQuarantineUntil = now + std::chrono::seconds(12);
        Wh_Log(
            L"Island: quarantining new-track timeline old=%lld incoming=%lld",
            static_cast<long long>(g_media.positionTicks),
            static_cast<long long>(state.positionTicks));
        state.positionTicks = 0;
    } else if (!g_timelineQuarantineTrackKey.empty()) {
        if (!state.hasSession || nextKey != g_timelineQuarantineTrackKey) {
            g_timelineQuarantineTrackKey.clear();
            g_timelineQuarantinePreviousPositionTicks = 0;
            g_timelineQuarantineUntil = {};
        } else {
            constexpr int64_t kFreshTrackStartTicks = 3 * 10000000LL;
            bool nearRealTrackStart =
                state.positionTicks <= kFreshTrackStartTicks;
            bool clearlyDifferentTimeline =
                g_timelineQuarantinePreviousPositionTicks > 20 * 10000000LL &&
                state.positionTicks + 15 * 10000000LL <
                    g_timelineQuarantinePreviousPositionTicks;
            if (nearRealTrackStart || clearlyDifferentTimeline ||
                now >= g_timelineQuarantineUntil) {
                g_timelineQuarantineTrackKey.clear();
                g_timelineQuarantinePreviousPositionTicks = 0;
                g_timelineQuarantineUntil = {};
            } else {
                state.positionTicks = 0;
            }
        }
    }

    bool sameMedia = g_media.hasSession && state.hasSession &&
                     !currentKey.empty() && currentKey == nextKey &&
                     state.durationTicks > 0 &&
                     g_media.durationTicks == state.durationTicks;

    {
        std::lock_guard seekLock(g_seekMutex);
        if (g_popupSeekCommitPending) {
            if (now >= g_popupSeekCommitUntil) {
                g_popupSeekCommitPending = false;
                g_popupSeekCommitTargetTicks = 0;
            } else if (sameMedia) {
                int64_t targetTicks = std::clamp<int64_t>(
                    g_popupSeekCommitTargetTicks, 0, state.durationTicks);
                int64_t delta = state.positionTicks > targetTicks
                                    ? state.positionTicks - targetTicks
                                    : targetTicks - state.positionTicks;
                int64_t tolerance =
                    std::max<int64_t>(10000000LL, state.durationTicks / 240);
                if (delta <= tolerance) {
                    g_popupSeekCommitPending = false;
                    g_popupSeekCommitTargetTicks = 0;
                } else {
                    // Some providers briefly report the pre-seek position. Keep the
                    // committed local position until the provider catches up.
                    state.positionTicks = targetTicks;
                }
            }
        }
    }

    if (sameMedia && state.isPlaying) {
        int64_t estimatedTicks = g_media.positionTicks;
        if (g_media.isPlaying &&
            g_mediaStateTimestamp.time_since_epoch().count() != 0) {
            double ageSec =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    now - g_mediaStateTimestamp)
                    .count() /
                1000.0;
            ageSec = Clamp(ageSec, 0.0, 3.0);
            estimatedTicks += static_cast<int64_t>(ageSec * 10000000.0);
            estimatedTicks =
                std::clamp<int64_t>(estimatedTicks, 0, state.durationTicks);
        }

        // Some GSMTC providers re-emit the old position when metadata is polled.
        // If we accepted those samples, the meteor tail would jump left and then
        // right again on the next local extrapolation.
        bool looksLikeStaleBackwardSample =
            state.positionTicks < estimatedTicks &&
            (estimatedTicks - state.positionTicks) <
                120000000LL;  // not a real big seek
        if (looksLikeStaleBackwardSample) {
            state.positionTicks = estimatedTicks;
        }
    }

    g_media = std::move(state);
    g_mediaStateTimestamp = now;
}

void RequestMediaRefresh() {
    if (!IsModActive() || !g_mediaThreadRunning.load()) {
        return;
    }
    g_mediaRefreshRequested = true;
    g_mediaCommandCv.notify_one();
}

gsm::GlobalSystemMediaTransportControlsSessionManager
RequestMediaManagerWithTimeout(std::chrono::milliseconds timeout) {
    if (g_unloading) {
        return nullptr;
    }

    try {
        auto operation = gsm::GlobalSystemMediaTransportControlsSessionManager::
            RequestAsync();
        if (operation.wait_for(timeout) !=
            winrt::Windows::Foundation::AsyncStatus::Completed) {
            try {
                operation.Cancel();
            } catch (...) {
            }
            return nullptr;
        }
        return operation.GetResults();
    } catch (...) {
        return nullptr;
    }
}

// ===== NetEase Cloud Music - local data =====
std::wstring NeteaseDataRootPath() {
    DWORD required = GetEnvironmentVariableW(L"LOCALAPPDATA", nullptr, 0);
    if (required <= 1) {
        return {};
    }

    std::wstring path(required, L'\0');
    DWORD copied =
        GetEnvironmentVariableW(L"LOCALAPPDATA", path.data(), required);
    if (!copied || copied >= required) {
        return {};
    }
    path.resize(copied);
    path += L"\\NetEase\\CloudMusic";
    return path;
}

std::wstring NeteaseLocalDataPath() {
    std::wstring path = NeteaseDataRootPath();
    if (!path.empty()) {
        path += L"\\webdata\\file\\playingList";
    }
    return path;
}

std::wstring Utf8ToWide(std::vector<uint8_t> const& bytes) {
    if (bytes.empty()) {
        return {};
    }

    size_t offset = bytes.size() >= 3 && bytes[0] == 0xEF && bytes[1] == 0xBB &&
                            bytes[2] == 0xBF
                        ? 3
                        : 0;
    int byteCount = static_cast<int>(bytes.size() - offset);
    int required = MultiByteToWideChar(
        CP_UTF8, MB_ERR_INVALID_CHARS,
        reinterpret_cast<char const*>(bytes.data() + offset), byteCount,
        nullptr, 0);
    if (required <= 0) {
        return {};
    }

    std::wstring result(static_cast<size_t>(required), L'\0');
    if (MultiByteToWideChar(
            CP_UTF8, MB_ERR_INVALID_CHARS,
            reinterpret_cast<char const*>(bytes.data() + offset), byteCount,
            result.data(), required) != required) {
        return {};
    }
    return result;
}

std::vector<uint8_t> ReadNeteaseFileBytes(std::wstring const& path,
                                          size_t maximumBytes) {
    std::vector<uint8_t> bytes;
    HANDLE file =
        CreateFileW(path.c_str(), GENERIC_READ,
                    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                    nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return bytes;
    }

    LARGE_INTEGER size{};
    if (!GetFileSizeEx(file, &size) || size.QuadPart <= 0 ||
        static_cast<uint64_t>(size.QuadPart) > maximumBytes) {
        CloseHandle(file);
        return bytes;
    }

    bytes.resize(static_cast<size_t>(size.QuadPart));
    DWORD read = 0;
    if (!ReadFile(file, bytes.data(), static_cast<DWORD>(bytes.size()), &read,
                  nullptr) ||
        read != bytes.size()) {
        bytes.clear();
    }
    CloseHandle(file);
    return bytes;
}

std::vector<uint8_t> const& ReadDefaultCoverBytes() {
    static std::vector<uint8_t> bytes = [] {
        DWORD required = GetEnvironmentVariableW(L"ProgramData", nullptr, 0);
        if (required <= 1) {
            return std::vector<uint8_t>{};
        }

        std::wstring path(required, L'\0');
        DWORD copied =
            GetEnvironmentVariableW(L"ProgramData", path.data(), required);
        if (!copied || copied >= required) {
            return std::vector<uint8_t>{};
        }
        path.resize(copied);
        path +=
            L"\\Windhawk\\Engine\\Mods\\island-media-controls-fork-default.png";
        return ReadNeteaseFileBytes(path, 4 * 1024 * 1024);
    }();
    return bytes;
}

std::string WideToUtf8(std::wstring_view value) {
    if (value.empty()) {
        return {};
    }
    int required = WideCharToMultiByte(CP_UTF8, 0, value.data(),
                                       static_cast<int>(value.size()), nullptr,
                                       0, nullptr, nullptr);
    if (required <= 0) {
        return {};
    }
    std::string result(static_cast<size_t>(required), '\0');
    if (WideCharToMultiByte(CP_UTF8, 0, value.data(),
                            static_cast<int>(value.size()), result.data(),
                            required, nullptr, nullptr) != required) {
        return {};
    }
    return result;
}

struct NeteaseSqliteDb;
struct NeteaseSqliteStmt;

struct NeteaseSqliteApi {
    using OpenV2 = int(__cdecl*)(char const*,
                                 NeteaseSqliteDb**,
                                 int,
                                 char const*);
    using Close = int(__cdecl*)(NeteaseSqliteDb*);
    using PrepareV2 = int(__cdecl*)(NeteaseSqliteDb*,
                                    char const*,
                                    int,
                                    NeteaseSqliteStmt**,
                                    char const**);
    using BindText = int(__cdecl*)(NeteaseSqliteStmt*,
                                   int,
                                   char const*,
                                   int,
                                   void(__cdecl*)(void*));
    using Step = int(__cdecl*)(NeteaseSqliteStmt*);
    using ColumnText = unsigned char const*(__cdecl*)(NeteaseSqliteStmt*, int);
    using Finalize = int(__cdecl*)(NeteaseSqliteStmt*);

    HMODULE module = nullptr;
    OpenV2 openV2 = nullptr;
    Close close = nullptr;
    PrepareV2 prepareV2 = nullptr;
    BindText bindText = nullptr;
    Step step = nullptr;
    ColumnText columnText = nullptr;
    Finalize finalize = nullptr;

    bool available() const {
        return module && openV2 && close && prepareV2 && bindText && step &&
               columnText && finalize;
    }
};

NeteaseSqliteApi const& GetNeteaseSqliteApi() {
    static NeteaseSqliteApi api = [] {
        NeteaseSqliteApi value;
        value.module = LoadLibraryW(L"winsqlite3.dll");
        if (!value.module) {
            return value;
        }
        value.openV2 = reinterpret_cast<NeteaseSqliteApi::OpenV2>(
            GetProcAddress(value.module, "sqlite3_open_v2"));
        value.close = reinterpret_cast<NeteaseSqliteApi::Close>(
            GetProcAddress(value.module, "sqlite3_close"));
        value.prepareV2 = reinterpret_cast<NeteaseSqliteApi::PrepareV2>(
            GetProcAddress(value.module, "sqlite3_prepare_v2"));
        value.bindText = reinterpret_cast<NeteaseSqliteApi::BindText>(
            GetProcAddress(value.module, "sqlite3_bind_text"));
        value.step = reinterpret_cast<NeteaseSqliteApi::Step>(
            GetProcAddress(value.module, "sqlite3_step"));
        value.columnText = reinterpret_cast<NeteaseSqliteApi::ColumnText>(
            GetProcAddress(value.module, "sqlite3_column_text"));
        value.finalize = reinterpret_cast<NeteaseSqliteApi::Finalize>(
            GetProcAddress(value.module, "sqlite3_finalize"));
        return value;
    }();
    return api;
}

bool LooksLikeJpegBytes(std::vector<uint8_t> const& bytes) {
    return bytes.size() >= 3 && bytes[0] == 0xFF && bytes[1] == 0xD8 &&
           bytes[2] == 0xFF;
}

bool LooksLikeWebpBytes(std::vector<uint8_t> const& bytes) {
    return bytes.size() >= 12 && bytes[0] == 'R' && bytes[1] == 'I' &&
           bytes[2] == 'F' && bytes[3] == 'F' && bytes[8] == 'W' &&
           bytes[9] == 'E' && bytes[10] == 'B' && bytes[11] == 'P';
}

bool LooksLikeImageBytes(std::vector<uint8_t> const& bytes) {
    if (LooksLikeJpegBytes(bytes)) {
        return true;
    }
    if (LooksLikeWebpBytes(bytes)) {
        return true;
    }
    if (bytes.size() >= 8 && bytes[0] == 0x89 && bytes[1] == 'P' &&
        bytes[2] == 'N' && bytes[3] == 'G') {
        return true;
    }
    return bytes.size() >= 6 && bytes[0] == 'G' && bytes[1] == 'I' &&
           bytes[2] == 'F';
}

std::vector<uint8_t> ReadNeteaseCachedArtwork(std::wstring const& artworkUrl) {
    static std::wstring cachedUrl;
    static std::vector<uint8_t> cachedBytes;
    static std::wstring lastMissUrl;
    static std::chrono::steady_clock::time_point lastMissTime{};

    if (artworkUrl.empty()) {
        return {};
    }
    if (artworkUrl == cachedUrl && !cachedBytes.empty()) {
        return cachedBytes;
    }
    auto now = std::chrono::steady_clock::now();
    if (artworkUrl == lastMissUrl &&
        now - lastMissTime < std::chrono::milliseconds(40)) {
        return {};
    }

    std::wstring root = NeteaseDataRootPath();
    auto const& sqlite = GetNeteaseSqliteApi();
    if (root.empty() || !sqlite.available()) {
        return {};
    }

    std::wstring baseUrl = artworkUrl;
    if (size_t query = baseUrl.find(L'?'); query != std::wstring::npos) {
        baseUrl.resize(query);
    }
    if (size_t scheme = baseUrl.find(L"://"); scheme != std::wstring::npos) {
        baseUrl.erase(0, scheme + 3);
    }
    if (size_t pathStart = baseUrl.find(L'/');
        pathStart != std::wstring::npos) {
        // p1/p2/p3.music.126.net are interchangeable CDN hosts. Match the
        // immutable image path so an already-cached JPEG is found regardless
        // of which host the current metadata selected.
        baseUrl.erase(0, pathStart);
    }
    std::string pattern = WideToUtf8(L"%" + baseUrl + L"%");
    std::string databasePath = WideToUtf8(root + L"\\Statics\\index.dat");
    if (pattern.empty() || databasePath.empty()) {
        return {};
    }

    constexpr int kSqliteOk = 0;
    constexpr int kSqliteRow = 100;
    constexpr int kSqliteOpenReadOnly = 0x00000001;
    NeteaseSqliteDb* database = nullptr;
    NeteaseSqliteStmt* statement = nullptr;
    std::vector<uint8_t> bytes;
    if (sqlite.openV2(databasePath.c_str(), &database, kSqliteOpenReadOnly,
                      nullptr) == kSqliteOk &&
        database) {
        constexpr char kQuery[] =
            "SELECT path FROM cache WHERE url LIKE ?1 "
            "ORDER BY CASE "
            "WHEN lower(url) LIKE '%type=jpg%' THEN 0 "
            "WHEN lower(url) NOT LIKE '%type=webp%' THEN 1 "
            "ELSE 2 END, size DESC LIMIT 8";
        if (sqlite.prepareV2(database, kQuery, -1, &statement, nullptr) ==
                kSqliteOk &&
            statement) {
            sqlite.bindText(statement, 1, pattern.c_str(),
                            static_cast<int>(pattern.size()), nullptr);
            // NetEase can cache several encodings/sizes for one cover URL. The
            // files all use an opaque .dat name, so choose by file signature:
            // prefer a WIC-native JPEG and retain the first other valid image
            // only as a fallback. This touches a handful of indexed candidates,
            // never the whole Statics directory or the multi-megabyte playlist.
            while (sqlite.step(statement) == kSqliteRow) {
                auto path = sqlite.columnText(statement, 0);
                if (!path) {
                    continue;
                }
                std::vector<uint8_t> utf8Path(
                    path,
                    path + std::strlen(reinterpret_cast<char const*>(path)));
                std::wstring cachedPath = Utf8ToWide(utf8Path);
                bool safeName =
                    !cachedPath.empty() &&
                    cachedPath.find(L"..") == std::wstring::npos &&
                    cachedPath.find_first_of(L"\\/") == std::wstring::npos;
                if (!safeName) {
                    continue;
                }
                auto candidate = ReadNeteaseFileBytes(
                    root + L"\\Statics\\" + cachedPath, 2 * 1024 * 1024);
                if (!LooksLikeImageBytes(candidate)) {
                    continue;
                }
                if (LooksLikeWebpBytes(candidate)) {
                    // BitmapImage/WIC support for WebP is optional on Windows.
                    // A WebP cache hit was the direct cause of the blank cover.
                    continue;
                }
                if (LooksLikeJpegBytes(candidate)) {
                    bytes = std::move(candidate);
                    break;
                }
                if (bytes.empty()) {
                    bytes = std::move(candidate);
                }
            }
        }
        if (statement) {
            sqlite.finalize(statement);
        }
        sqlite.close(database);
    }

    if (!bytes.empty()) {
        cachedUrl = artworkUrl;
        cachedBytes = bytes;
        lastMissUrl.clear();
    } else {
        lastMissUrl = artworkUrl;
        lastMissTime = now;
    }
    return bytes;
}

bool EqualsInsensitive(std::wstring_view left, std::wstring_view right) {
    return left.size() == right.size() &&
           _wcsnicmp(left.data(), right.data(), left.size()) == 0;
}

bool ContainsInsensitive(std::wstring_view value, std::wstring_view needle) {
    if (needle.empty() || needle.size() > value.size()) {
        return false;
    }
    for (size_t i = 0; i + needle.size() <= value.size(); ++i) {
        if (_wcsnicmp(value.data() + i, needle.data(), needle.size()) == 0) {
            return true;
        }
    }
    return false;
}

std::wstring JsonScalarString(json::JsonObject const& object,
                              wchar_t const* name) {
    if (!object.HasKey(name)) {
        return {};
    }
    try {
        auto value = object.GetNamedValue(name);
        if (value.ValueType() == json::JsonValueType::String) {
            return std::wstring(value.GetString());
        }
        if (value.ValueType() == json::JsonValueType::Number) {
            double number = value.GetNumber();
            wchar_t buffer[64];
            swprintf_s(buffer, L"%.0f", number);
            return buffer;
        }
    } catch (...) {
    }
    return {};
}

struct NeteaseTrackMetadata {
    std::wstring id;
    std::wstring title;
    std::wstring artist;
    std::wstring artworkUrl;
    int64_t durationTicks = 0;
    uint64_t sourceWriteTimeTicks = 0;
    bool sourceTimestampTracksPlayback = false;
};

bool NeteaseWindowTitleMatches(std::wstring const& windowTitle,
                               std::wstring const& trackTitle,
                               std::vector<std::wstring> const& artists) {
    if (trackTitle.empty() || artists.empty()) {
        return false;
    }

    std::wstring joined;
    for (size_t i = 0; i < artists.size(); ++i) {
        if (i) {
            joined += L"/";
        }
        joined += artists[i];
    }
    if (EqualsInsensitive(windowTitle, trackTitle + L" - " + joined)) {
        return true;
    }

    std::wstring prefix = trackTitle + L" - ";
    if (windowTitle.size() <= prefix.size() ||
        _wcsnicmp(windowTitle.data(), prefix.data(), prefix.size()) != 0) {
        return false;
    }

    std::wstring_view artistSuffix(windowTitle.data() + prefix.size(),
                                   windowTitle.size() - prefix.size());
    for (auto const& artist : artists) {
        if (!artist.empty() && ContainsInsensitive(artistSuffix, artist)) {
            return true;
        }
    }
    return false;
}

bool TryReadNeteaseTrackMetadata(std::wstring const& windowTitle,
                                 NeteaseTrackMetadata* metadata) {
    if (!metadata || windowTitle.empty()) {
        return false;
    }

    struct FileSignature {
        uint64_t writeTimeTicks = 0;
        uint64_t size = 0;
        bool exists = false;

        bool operator==(FileSignature const& other) const {
            return writeTimeTicks == other.writeTimeTicks &&
                   size == other.size && exists == other.exists;
        }
    };
    auto fileSignature = [](std::wstring const& path) {
        FileSignature signature;
        WIN32_FILE_ATTRIBUTE_DATA data{};
        if (GetFileAttributesExW(path.c_str(), GetFileExInfoStandard, &data)) {
            signature.exists = true;
            signature.writeTimeTicks =
                (static_cast<uint64_t>(data.ftLastWriteTime.dwHighDateTime)
                 << 32) |
                data.ftLastWriteTime.dwLowDateTime;
            signature.size = (static_cast<uint64_t>(data.nFileSizeHigh) << 32) |
                             data.nFileSizeLow;
        }
        return signature;
    };

    std::wstring playingListPath = NeteaseLocalDataPath();
    size_t slash = playingListPath.find_last_of(L"\\/");
    std::wstring directory = slash == std::wstring::npos
                                 ? std::wstring{}
                                 : playingListPath.substr(0, slash + 1);
    std::wstring fmPlayPath =
        directory.empty() ? std::wstring{} : directory + L"fmPlay";
    FileSignature fmSignature = fileSignature(fmPlayPath);
    FileSignature listSignature = fileSignature(playingListPath);

    static bool cached = false;
    static bool cachedFound = false;
    static std::wstring cachedWindowTitle;
    static FileSignature cachedFmSignature;
    static FileSignature cachedListSignature;
    static NeteaseTrackMetadata cachedMetadata;
    if (cached && windowTitle == cachedWindowTitle &&
        fmSignature == cachedFmSignature &&
        listSignature == cachedListSignature) {
        if (cachedFound) {
            *metadata = cachedMetadata;
        }
        return cachedFound;
    }

    NeteaseTrackMetadata parsedMetadata;
    auto tryFile = [&](std::wstring const& path, wchar_t const* arrayName,
                       bool wrappedTracks) {
        // The normal queue is under 1 MB on current NetEase builds. This is
        // only read after the window title or file signature changes, never on
        // every 60 ms playback poll.
        auto bytes = ReadNeteaseFileBytes(path, 2 * 1024 * 1024);
        std::wstring text = Utf8ToWide(bytes);
        if (text.empty()) {
            return false;
        }

        WIN32_FILE_ATTRIBUTE_DATA fileData{};
        uint64_t sourceWriteTimeTicks = 0;
        if (GetFileAttributesExW(path.c_str(), GetFileExInfoStandard,
                                 &fileData)) {
            sourceWriteTimeTicks =
                (static_cast<uint64_t>(fileData.ftLastWriteTime.dwHighDateTime)
                 << 32) |
                fileData.ftLastWriteTime.dwLowDateTime;
        }

        try {
            auto root = json::JsonObject::Parse(text);
            auto items = root.GetNamedArray(arrayName);
            for (auto const& itemValue : items) {
                try {
                    auto item = itemValue.GetObject();
                    auto track = wrappedTracks && item.HasKey(L"track")
                                     ? item.GetNamedObject(L"track")
                                     : item;
                    std::wstring title = JsonScalarString(track, L"name");
                    if (title.empty() || !track.HasKey(L"artists")) {
                        continue;
                    }

                    std::vector<std::wstring> artists;
                    for (auto const& artistValue :
                         track.GetNamedArray(L"artists")) {
                        auto artistObject = artistValue.GetObject();
                        std::wstring artist =
                            JsonScalarString(artistObject, L"name");
                        if (!artist.empty()) {
                            artists.push_back(std::move(artist));
                        }
                    }
                    if (!NeteaseWindowTitleMatches(windowTitle, title,
                                                   artists)) {
                        continue;
                    }

                    NeteaseTrackMetadata found;
                    found.id = JsonScalarString(track, L"id");
                    if (found.id.empty()) {
                        found.id = JsonScalarString(item, L"id");
                    }
                    found.title = std::move(title);
                    for (size_t i = 0; i < artists.size(); ++i) {
                        if (i) {
                            found.artist += L" / ";
                        }
                        found.artist += artists[i];
                    }

                    if (track.HasKey(L"album")) {
                        auto album = track.GetNamedObject(L"album");
                        found.artworkUrl = JsonScalarString(album, L"picUrl");
                        if (found.artworkUrl.empty()) {
                            found.artworkUrl =
                                JsonScalarString(album, L"cover");
                        }
                    }
                    if (track.HasKey(L"duration")) {
                        double durationMs =
                            track.GetNamedNumber(L"duration", 0.0);
                        if (durationMs > 0.0) {
                            found.durationTicks = static_cast<int64_t>(
                                std::llround(durationMs * 10000.0));
                        }
                    }
                    found.sourceWriteTimeTicks = sourceWriteTimeTicks;
                    found.sourceTimestampTracksPlayback = !wrappedTracks;
                    parsedMetadata = std::move(found);
                    return true;
                } catch (...) {
                }
            }
        } catch (...) {
        }
        return false;
    };

    // Private FM maintains a separate queue and updates this file whenever its
    // currentIndex changes, so prefer it for both metadata and progress.
    bool found = !fmPlayPath.empty() && tryFile(fmPlayPath, L"queue", false);
    if (!found) {
        found = tryFile(playingListPath, L"list", true);
    }

    cached = true;
    cachedFound = found;
    cachedWindowTitle = windowTitle;
    cachedFmSignature = fmSignature;
    cachedListSignature = listSignature;
    if (found) {
        cachedMetadata = parsedMetadata;
        *metadata = std::move(parsedMetadata);
    } else {
        cachedMetadata = {};
    }
    return found;
}

// ===== NetEase Cloud Music - remote artwork =====
std::wstring NormalizeRemoteUrl(std::wstring url) {
    if (url.rfind(L"http://", 0) == 0) {
        url.replace(0, 7, L"https://");
    }
    return url;
}

std::wstring NeteaseJpegThumbnailUrl(std::wstring artworkUrl) {
    artworkUrl = NormalizeRemoteUrl(std::move(artworkUrl));
    if (artworkUrl.empty()) {
        return {};
    }

    // Drop an old imageView/WebP transform and ask NetEase's image CDN for a
    // small JPEG. This is both faster than the original cover and decodable by
    // the stock Windows WIC JPEG codec on every supported Windows 11 build.
    if (size_t query = artworkUrl.find(L'?'); query != std::wstring::npos) {
        artworkUrl.resize(query);
    }
    artworkUrl += L"?imageView&enlarge=1&thumbnail=384y384&type=jpg";
    return artworkUrl;
}

std::vector<uint8_t> DownloadRemoteBytesSync(std::wstring remoteUrl) {
    remoteUrl = NormalizeRemoteUrl(std::move(remoteUrl));
    if (remoteUrl.empty()) {
        return {};
    }

    URL_COMPONENTS components{sizeof(components)};
    components.dwHostNameLength = static_cast<DWORD>(-1);
    components.dwUrlPathLength = static_cast<DWORD>(-1);
    components.dwExtraInfoLength = static_cast<DWORD>(-1);
    if (!WinHttpCrackUrl(remoteUrl.c_str(), 0, 0, &components) ||
        !components.lpszHostName || !components.dwHostNameLength) {
        return {};
    }

    std::wstring host(components.lpszHostName, components.dwHostNameLength);
    std::wstring resource;
    if (components.lpszUrlPath && components.dwUrlPathLength) {
        resource.assign(components.lpszUrlPath, components.dwUrlPathLength);
    }
    if (components.lpszExtraInfo && components.dwExtraInfoLength) {
        resource.append(components.lpszExtraInfo, components.dwExtraInfoLength);
    }
    if (resource.empty()) {
        resource = L"/";
    }

    HINTERNET session =
        WinHttpOpen(L"Windhawk Island Media Controls/0.9.234",
                    WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY, WINHTTP_NO_PROXY_NAME,
                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (!session) {
        return {};
    }
    // Network I/O only happens on the dedicated remote-bytes worker. Keep the
    // timeouts bounded so unloading Explorer never has to wait on a slow CDN.
    WinHttpSetTimeouts(session, 800, 800, 1500, 1500);

    HINTERNET connection =
        WinHttpConnect(session, host.c_str(), components.nPort, 0);
    HINTERNET request =
        connection ? WinHttpOpenRequest(
                         connection, L"GET", resource.c_str(), nullptr,
                         WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
                         components.nScheme == INTERNET_SCHEME_HTTPS
                             ? WINHTTP_FLAG_SECURE
                             : 0)
                   : nullptr;
    std::vector<uint8_t> result;
    BOOL succeeded = request &&
                     WinHttpSendRequest(request, WINHTTP_NO_ADDITIONAL_HEADERS,
                                        0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0) &&
                     WinHttpReceiveResponse(request, nullptr);
    if (succeeded) {
        DWORD status = 0;
        DWORD statusSize = sizeof(status);
        succeeded = WinHttpQueryHeaders(
            request, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
            WINHTTP_HEADER_NAME_BY_INDEX, &status, &statusSize,
            WINHTTP_NO_HEADER_INDEX);
        succeeded = succeeded && status >= 200 && status < 300;
    }

    constexpr size_t kMaximumArtworkBytes = 6 * 1024 * 1024;
    while (succeeded) {
        DWORD available = 0;
        if (!WinHttpQueryDataAvailable(request, &available)) {
            result.clear();
            break;
        }
        if (!available) {
            break;
        }
        if (result.size() + available > kMaximumArtworkBytes) {
            result.clear();
            break;
        }
        size_t offset = result.size();
        result.resize(offset + available);
        DWORD read = 0;
        if (!WinHttpReadData(request, result.data() + offset, available,
                             &read) ||
            !read) {
            result.clear();
            break;
        }
        result.resize(offset + read);
    }

    if (request) {
        WinHttpCloseHandle(request);
    }
    if (connection) {
        WinHttpCloseHandle(connection);
    }
    WinHttpCloseHandle(session);

    return result;
}

std::vector<uint8_t> RequestRemoteBytesAsync(std::wstring remoteUrl) {
    remoteUrl = NormalizeRemoteUrl(std::move(remoteUrl));
    if (remoteUrl.empty()) {
        return {};
    }

    auto now = std::chrono::steady_clock::now();
    {
        std::lock_guard lock(g_remoteBytesMutex);
        for (auto const& entry : g_remoteBytesCache) {
            if (entry.url != remoteUrl) {
                continue;
            }
            if (!entry.bytes.empty()) {
                return entry.bytes;
            }
            // Retry failed requests quickly enough to recover from a transient
            // CDN error, without sending another request every media refresh.
            if (now - entry.attemptTime < std::chrono::seconds(2)) {
                return {};
            }
            break;
        }
        if (remoteUrl == g_remoteBytesPendingUrl ||
            remoteUrl == g_remoteBytesInFlightUrl) {
            return {};
        }
        // The current track wins. Covers for tracks that have already been
        // skipped should not delay the visible track.
        g_remoteBytesPendingUrl = std::move(remoteUrl);
    }
    g_remoteBytesCv.notify_one();
    return {};
}

bool RemoteBytesRecentlyFailed(std::wstring const& remoteUrl) {
    auto normalizedUrl = NormalizeRemoteUrl(remoteUrl);
    auto now = std::chrono::steady_clock::now();
    std::lock_guard lock(g_remoteBytesMutex);
    for (auto const& entry : g_remoteBytesCache) {
        if (entry.url == normalizedUrl && entry.bytes.empty() &&
            now - entry.attemptTime < std::chrono::seconds(2)) {
            return true;
        }
    }
    return false;
}

std::vector<uint8_t> RequestNeteaseRemoteArtworkAsync(
    std::wstring const& artworkUrl) {
    std::wstring jpegThumbnailUrl = NeteaseJpegThumbnailUrl(artworkUrl);
    bool jpegFailed = RemoteBytesRecentlyFailed(jpegThumbnailUrl);
    auto bytes = RequestRemoteBytesAsync(jpegThumbnailUrl);
    if (LooksLikeImageBytes(bytes)) {
        return bytes;
    }

    // If the CDN rejected the transform, use the original URL on the refresh
    // caused by that failed request. Do not queue both at once: the artwork
    // worker intentionally keeps only the newest pending track.
    if (jpegFailed) {
        bytes = RequestRemoteBytesAsync(artworkUrl);
        if (LooksLikeImageBytes(bytes)) {
            return bytes;
        }
    }
    return {};
}

void RemoteBytesThreadProc() {
    struct ExitGuard {
        ~ExitGuard() { g_remoteBytesThreadExited = true; }
    } exitGuard;

    while (g_remoteBytesThreadRunning) {
        std::wstring remoteUrl;
        {
            std::unique_lock lock(g_remoteBytesMutex);
            g_remoteBytesCv.wait(lock, [] {
                return !g_remoteBytesThreadRunning ||
                       !g_remoteBytesPendingUrl.empty();
            });
            if (!g_remoteBytesThreadRunning) {
                break;
            }
            remoteUrl = std::move(g_remoteBytesPendingUrl);
            g_remoteBytesPendingUrl.clear();
            g_remoteBytesInFlightUrl = remoteUrl;
        }

        auto bytes = DownloadRemoteBytesSync(remoteUrl);
        {
            std::lock_guard lock(g_remoteBytesMutex);
            for (auto it = g_remoteBytesCache.begin();
                 it != g_remoteBytesCache.end();) {
                if (it->url == remoteUrl) {
                    it = g_remoteBytesCache.erase(it);
                } else {
                    ++it;
                }
            }
            g_remoteBytesCache.push_front({remoteUrl, std::move(bytes),
                                           std::chrono::steady_clock::now()});
            while (g_remoteBytesCache.size() > 8) {
                g_remoteBytesCache.pop_back();
            }
            if (g_remoteBytesInFlightUrl == remoteUrl) {
                g_remoteBytesInFlightUrl.clear();
            }
        }
        RequestMediaRefresh();
    }
}

void StartRemoteBytesThread() {
    if (g_remoteBytesThreadRunning.exchange(true)) {
        return;
    }
    g_remoteBytesThreadExited = false;
    try {
        g_remoteBytesThread = new std::thread(RemoteBytesThreadProc);
    } catch (...) {
        g_remoteBytesThreadRunning = false;
        g_remoteBytesThreadExited = true;
        g_remoteBytesThread = nullptr;
        Wh_Log(L"Island: failed to start remote bytes thread");
    }
}

void StopRemoteBytesThread() {
    g_remoteBytesThreadRunning = false;
    g_remoteBytesCv.notify_all();
    if (g_remoteBytesThread) {
        if (g_remoteBytesThread->joinable() &&
            g_remoteBytesThread->get_id() != std::this_thread::get_id()) {
            g_remoteBytesThread->join();
        } else if (g_remoteBytesThread->joinable()) {
            g_remoteBytesThread->detach();
        }
        delete g_remoteBytesThread;
        g_remoteBytesThread = nullptr;
    }
    std::lock_guard lock(g_remoteBytesMutex);
    g_remoteBytesPendingUrl.clear();
    g_remoteBytesInFlightUrl.clear();
    g_remoteBytesCache.clear();
}

bool ClickResolvedScreenPointForWindow(
    HWND window,
    std::function<bool(POINT*)> const& resolvePoint) {
    if (!window || !IsWindow(window)) {
        return false;
    }

    HWND previousForeground = GetForegroundWindow();
    POINT previousCursor{};
    bool havePreviousCursor = GetCursorPos(&previousCursor);
    bool wasMinimized = IsIconic(window);
    if (wasMinimized) {
        ShowWindow(window, SW_RESTORE);
        // SW_RESTORE is asynchronous across processes. Resolve the client
        // geometry only after the real NetEase window has left its iconic
        // placement, otherwise ClientToScreen converts against the minimized
        // placeholder coordinates.
        for (int attempt = 0; attempt < 40 && IsIconic(window); ++attempt) {
            Sleep(5);
        }
    }

    SetForegroundWindow(window);
    Sleep(12);
    POINT point{};
    if (!resolvePoint || !resolvePoint(&point)) {
        if (previousForeground && previousForeground != window &&
            IsWindow(previousForeground)) {
            SetForegroundWindow(previousForeground);
        }
        if (wasMinimized) {
            ShowWindow(window, SW_MINIMIZE);
        }
        return false;
    }
    if (!SetCursorPos(point.x, point.y)) {
        if (previousForeground && previousForeground != window &&
            IsWindow(previousForeground)) {
            SetForegroundWindow(previousForeground);
        }
        if (wasMinimized) {
            ShowWindow(window, SW_MINIMIZE);
        }
        return false;
    }

    INPUT inputs[2]{};
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    bool succeeded = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT)) ==
                     ARRAYSIZE(inputs);
    Sleep(12);

    if (havePreviousCursor) {
        SetCursorPos(previousCursor.x, previousCursor.y);
    }
    if (previousForeground && previousForeground != window &&
        IsWindow(previousForeground)) {
        SetForegroundWindow(previousForeground);
    }
    if (wasMinimized) {
        ShowWindow(window, SW_MINIMIZE);
    }
    return succeeded;
}

// ===== Process snapshot cache =====
// One process-table snapshot is reused across window enumeration and the media
// thread. Previously every Is*ProcessId call created a full Toolhelp snapshot,
// so a single EnumWindows pass performed hundreds of snapshots and the media
// loop created two more every 60 ms while a player was running.
struct RunningProcessSnapshot {
    bool neteaseRunning = false;
    bool bilibiliRunning = false;
    std::vector<DWORD> neteasePids;
    std::vector<DWORD> bilibiliPids;
};

RunningProcessSnapshot TakeRunningProcessSnapshot() {
    RunningProcessSnapshot snapshot;
    HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (processSnapshot == INVALID_HANDLE_VALUE) {
        return snapshot;
    }

    PROCESSENTRY32W entry{sizeof(entry)};
    if (Process32FirstW(processSnapshot, &entry)) {
        do {
            if (_wcsicmp(entry.szExeFile, L"cloudmusic.exe") == 0) {
                snapshot.neteaseRunning = true;
                snapshot.neteasePids.push_back(entry.th32ProcessID);
            } else if (_wcsicmp(entry.szExeFile, L"哔哩哔哩.exe") == 0 ||
                       _wcsicmp(entry.szExeFile, L"BiliBiliPC.exe") == 0) {
                snapshot.bilibiliRunning = true;
                snapshot.bilibiliPids.push_back(entry.th32ProcessID);
            }
        } while (Process32NextW(processSnapshot, &entry));
    }
    CloseHandle(processSnapshot);
    return snapshot;
}

struct ProcessProbeCache {
    std::mutex mutex;
    RunningProcessSnapshot snapshot;
    std::chrono::steady_clock::time_point lastProbeTime{};
};
ProcessProbeCache g_processProbeCache;

void RefreshProcessProbeCacheLocked() {
    auto now = std::chrono::steady_clock::now();
    if (g_processProbeCache.lastProbeTime.time_since_epoch().count() == 0 ||
        now - g_processProbeCache.lastProbeTime >=
            std::chrono::milliseconds(1000)) {
        g_processProbeCache.snapshot = TakeRunningProcessSnapshot();
        g_processProbeCache.lastProbeTime = now;
    }
}

bool IsBilibiliProcessId(DWORD processId) {
    if (!processId) {
        return false;
    }
    std::lock_guard lock(g_processProbeCache.mutex);
    RefreshProcessProbeCacheLocked();
    return std::find(g_processProbeCache.snapshot.bilibiliPids.begin(),
                     g_processProbeCache.snapshot.bilibiliPids.end(),
                     processId) !=
           g_processProbeCache.snapshot.bilibiliPids.end();
}

// ===== Bilibili integration =====

bool IsBilibiliRunning() {
    std::lock_guard lock(g_processProbeCache.mutex);
    RefreshProcessProbeCacheLocked();
    return g_processProbeCache.snapshot.bilibiliRunning;
}

HWND FindBilibiliWindow() {
    struct Search {
        HWND best = nullptr;
        long long bestArea = -1;
        HWND fallback = nullptr;
    } search;
    EnumWindows(
        [](HWND hwnd, LPARAM param) -> BOOL {
            DWORD processId = 0;
            if (!GetWindowThreadProcessId(hwnd, &processId) ||
                !IsBilibiliProcessId(processId)) {
                return TRUE;
            }

            int titleLength = GetWindowTextLengthW(hwnd);
            if (titleLength <= 0) {
                return TRUE;
            }
            auto result = reinterpret_cast<Search*>(param);
            if (!result->fallback) {
                result->fallback = hwnd;
            }

            RECT rect{};
            if (!IsWindowVisible(hwnd) || IsIconic(hwnd) ||
                !GetWindowRect(hwnd, &rect)) {
                return TRUE;
            }
            long long width = std::max<LONG>(rect.right - rect.left, 0);
            long long height = std::max<LONG>(rect.bottom - rect.top, 0);
            long long area = width * height;
            if (area > result->bestArea) {
                result->bestArea = area;
                result->best = hwnd;
            }
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&search));
    return search.best ? search.best : search.fallback;
}

HWND FindChromeRenderWidgetWindow(HWND parent) {
    struct Search {
        HWND hwnd = nullptr;
    } search;
    EnumChildWindows(
        parent,
        [](HWND child, LPARAM param) -> BOOL {
            wchar_t className[256]{};
            if (GetClassNameW(child, className, ARRAYSIZE(className)) &&
                _wcsicmp(className, L"Chrome_RenderWidgetHostHWND") == 0) {
                reinterpret_cast<Search*>(param)->hwnd = child;
                return FALSE;
            }
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&search));
    return search.hwnd;
}

std::wstring BilibiliBvidFromUrl(std::wstring const& url) {
    size_t marker = url.find(L"bvid=");
    if (marker != std::wstring::npos) {
        marker += 5;
        size_t end = url.find_first_of(L"&#", marker);
        return url.substr(marker, end == std::wstring::npos ? std::wstring::npos
                                                            : end - marker);
    }

    marker = url.find(L"/video/");
    if (marker != std::wstring::npos) {
        marker += 7;
        size_t end = url.find_first_of(L"/?#", marker);
        return url.substr(marker, end == std::wstring::npos ? std::wstring::npos
                                                            : end - marker);
    }
    return {};
}

struct BilibiliUiState {
    HWND window = nullptr;
    HWND renderWidget = nullptr;
    std::wstring title;
    std::wstring url;
};

bool TryReadBilibiliUiState(BilibiliUiState* state) {
    if (!state) {
        return false;
    }
    *state = {};
    state->window = FindBilibiliWindow();
    state->renderWidget =
        state->window ? FindChromeRenderWidgetWindow(state->window) : nullptr;
    if (!state->window || !state->renderWidget || IsIconic(state->window)) {
        return false;
    }

    IUIAutomation* automation = nullptr;
    IUIAutomationElement* root = nullptr;
    IUIAutomationCondition* documentCondition = nullptr;
    IUIAutomationElement* document = nullptr;
    HRESULT result =
        CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER,
                         IID_PPV_ARGS(&automation));
    if (SUCCEEDED(result)) {
        result = automation->ElementFromHandle(state->window, &root);
    }
    if (SUCCEEDED(result)) {
        VARIANT value{};
        value.vt = VT_I4;
        value.lVal = UIA_DocumentControlTypeId;
        result = automation->CreatePropertyCondition(UIA_ControlTypePropertyId,
                                                     value, &documentCondition);
    }
    if (SUCCEEDED(result)) {
        result = root->FindFirst(TreeScope_Descendants, documentCondition,
                                 &document);
    }

    if (SUCCEEDED(result) && document) {
        BSTR titleRaw = nullptr;
        if (SUCCEEDED(document->get_CurrentName(&titleRaw))) {
            state->title = titleRaw ? titleRaw : L"";
        }
        SysFreeString(titleRaw);

        IUnknown* unknown = nullptr;
        IUIAutomationValuePattern* valuePattern = nullptr;
        if (SUCCEEDED(
                document->GetCurrentPattern(UIA_ValuePatternId, &unknown)) &&
            unknown &&
            SUCCEEDED(unknown->QueryInterface(IID_PPV_ARGS(&valuePattern)))) {
            BSTR urlRaw = nullptr;
            if (SUCCEEDED(valuePattern->get_CurrentValue(&urlRaw))) {
                state->url = urlRaw ? urlRaw : L"";
            }
            SysFreeString(urlRaw);
        }
        if (valuePattern) {
            valuePattern->Release();
        }
        if (unknown) {
            unknown->Release();
        }
    }

    if (document)
        document->Release();
    if (documentCondition)
        documentCondition->Release();
    if (root)
        root->Release();
    if (automation)
        automation->Release();
    return !BilibiliBvidFromUrl(state->url).empty();
}

bool TryReadBilibiliMetadata(std::wstring const& bvid,
                             std::wstring* title,
                             std::wstring* artist,
                             std::vector<uint8_t>* artwork) {
    static std::wstring cachedBvid;
    static std::wstring cachedTitle;
    static std::wstring cachedArtist;
    static std::wstring cachedArtworkUrl;
    static std::vector<uint8_t> cachedArtwork;
    if (bvid.empty()) {
        return false;
    }
    if (bvid != cachedBvid) {
        std::wstring apiUrl =
            L"https://api.bilibili.com/x/web-interface/view?bvid=" + bvid;
        auto bytes = RequestRemoteBytesAsync(apiUrl);
        std::wstring text = Utf8ToWide(bytes);
        if (!text.empty()) {
            try {
                auto root = json::JsonObject::Parse(text);
                if (root.GetNamedNumber(L"code", -1) == 0) {
                    auto data = root.GetNamedObject(L"data");
                    std::wstring newTitle = JsonScalarString(data, L"title");
                    std::wstring newArtist;
                    if (data.HasKey(L"owner")) {
                        newArtist = JsonScalarString(
                            data.GetNamedObject(L"owner"), L"name");
                    }
                    std::wstring artworkUrl = JsonScalarString(data, L"pic");
                    cachedBvid = bvid;
                    cachedTitle = std::move(newTitle);
                    cachedArtist = std::move(newArtist);
                    cachedArtworkUrl = std::move(artworkUrl);
                    cachedArtwork.clear();
                }
            } catch (...) {
            }
        }
    }
    if (cachedBvid != bvid) {
        return false;
    }
    if (!cachedArtworkUrl.empty()) {
        auto artworkBytes = RequestRemoteBytesAsync(cachedArtworkUrl);
        if (!artworkBytes.empty()) {
            cachedArtwork = std::move(artworkBytes);
        }
    }
    if (title)
        *title = cachedTitle;
    if (artist)
        *artist = cachedArtist;
    if (artwork)
        *artwork = cachedArtwork;
    return true;
}

bool TryReadBilibiliState(MediaState* state, bool isPlaying) {
    if (!state) {
        return false;
    }
    BilibiliUiState ui;
    if (!TryReadBilibiliUiState(&ui)) {
        return false;
    }

    std::wstring bvid = BilibiliBvidFromUrl(ui.url);
    state->hasSession = true;
    state->isPlaying = isPlaying;
    state->sourceAppUserModelId = L"com.bilibili.bilibiliPC";
    state->mediaId = bvid;
    if (!ui.title.empty()) {
        state->title = ui.title;
    }

    std::wstring title;
    std::wstring artist;
    std::vector<uint8_t> artwork;
    if (TryReadBilibiliMetadata(bvid, &title, &artist, &artwork)) {
        if (!title.empty()) {
            state->title = std::move(title);
        }
        if (!artist.empty()) {
            state->artist = std::move(artist);
        }
        if (!artwork.empty()) {
            state->thumbnailBytes = std::move(artwork);
        }
    }
    state->canFavorite = true;
    {
        std::lock_guard favoriteLock(g_bilibiliFavoriteStateMutex);
        if (g_bilibiliFavoriteTrackId != bvid) {
            g_bilibiliFavoriteTrackId = bvid;
            g_bilibiliFavoriteValue = false;
        }
        state->isFavorite = g_bilibiliFavoriteValue;
    }
    return true;
}

bool TryFavoriteBilibili() {
    HWND window = FindBilibiliWindow();
    HWND renderWidget = window ? FindChromeRenderWidgetWindow(window) : nullptr;
    if (!window || !renderWidget) {
        return false;
    }

    bool succeeded = ClickResolvedScreenPointForWindow(
        window, [window](POINT* favoritePoint) -> bool {
            if (!favoritePoint) {
                return false;
            }

            IUIAutomation* automation = nullptr;
            IUIAutomationElement* root = nullptr;
            IUIAutomationCondition* condition = nullptr;
            IUIAutomationElement* cacheText = nullptr;
            HRESULT result = CoCreateInstance(CLSID_CUIAutomation, nullptr,
                                              CLSCTX_INPROC_SERVER,
                                              IID_PPV_ARGS(&automation));
            if (SUCCEEDED(result)) {
                result = automation->ElementFromHandle(window, &root);
            }
            if (SUCCEEDED(result)) {
                VARIANT value{};
                value.vt = VT_BSTR;
                value.bstrVal = SysAllocString(L"缓存");
                result = value.bstrVal
                             ? automation->CreatePropertyCondition(
                                   UIA_NamePropertyId, value, &condition)
                             : E_OUTOFMEMORY;
                VariantClear(&value);
            }
            if (SUCCEEDED(result)) {
                result = root->FindFirst(TreeScope_Descendants, condition,
                                         &cacheText);
            }

            RECT rect{};
            bool resolved =
                SUCCEEDED(result) && cacheText &&
                SUCCEEDED(cacheText->get_CurrentBoundingRectangle(&rect)) &&
                rect.right > rect.left && rect.bottom > rect.top;
            if (resolved) {
                UINT dpi = GetDpiForWindow(window);
                if (!dpi) {
                    dpi = 96;
                }
                favoritePoint->x = (rect.left + rect.right) / 2 -
                                   MulDiv(66, static_cast<int>(dpi), 96);
                favoritePoint->y = (rect.top + rect.bottom) / 2 -
                                   MulDiv(25, static_cast<int>(dpi), 96);
            }
            if (cacheText)
                cacheText->Release();
            if (condition)
                condition->Release();
            if (root)
                root->Release();
            if (automation)
                automation->Release();
            return resolved;
        });

    if (succeeded) {
        // Clicking the real star opens BiliBili's collection picker. E only
        // opens that picker; it doesn't confirm it. Submit the already-selected
        // default folder with Enter instead.
        Sleep(140);
        DWORD_PTR ignored = 0;
        SendMessageTimeoutW(renderWidget, WM_KEYDOWN, VK_RETURN, 0,
                            SMTO_ABORTIFHUNG | SMTO_NORMAL, 500, &ignored);
        SendMessageTimeoutW(renderWidget, WM_CHAR, L'\r', 0,
                            SMTO_ABORTIFHUNG | SMTO_NORMAL, 500, &ignored);
        SendMessageTimeoutW(renderWidget, WM_KEYUP, VK_RETURN, 0,
                            SMTO_ABORTIFHUNG | SMTO_NORMAL, 500, &ignored);
    }
    return succeeded;
}

// ===== NetEase Cloud Music - UI automation =====
bool IsNeteaseCloudMusicProcessId(DWORD processId) {
    if (!processId) {
        return false;
    }
    std::lock_guard lock(g_processProbeCache.mutex);
    RefreshProcessProbeCacheLocked();
    return std::find(g_processProbeCache.snapshot.neteasePids.begin(),
                     g_processProbeCache.snapshot.neteasePids.end(),
                     processId) !=
           g_processProbeCache.snapshot.neteasePids.end();
}

bool IsNeteaseCloudMusicRunning() {
    std::lock_guard lock(g_processProbeCache.mutex);
    RefreshProcessProbeCacheLocked();
    return g_processProbeCache.snapshot.neteaseRunning;
}

bool IsNeteaseCloudMusicAudioActive() {
    static std::mutex cacheMutex;
    static std::chrono::steady_clock::time_point lastCheck{};
    static bool lastResult = false;

    {
        std::lock_guard lock(cacheMutex);
        auto now = std::chrono::steady_clock::now();
        if (lastCheck.time_since_epoch().count() != 0 &&
            now - lastCheck < std::chrono::milliseconds(1000)) {
            return lastResult;
        }
    }

    auto probe = []() -> bool {
        winrt::com_ptr<IMMDeviceEnumerator> deviceEnumerator;
        HRESULT result = CoCreateInstance(kCLSID_MMDeviceEnumerator, nullptr,
                                          CLSCTX_INPROC_SERVER,
                                          IID_PPV_ARGS(deviceEnumerator.put()));
        if (FAILED(result)) {
            return false;
        }

        winrt::com_ptr<IMMDevice> device;
        result = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia,
                                                           device.put());
        if (FAILED(result)) {
            return false;
        }

        winrt::com_ptr<IAudioSessionManager2> sessionManager;
        result = device->Activate(__uuidof(IAudioSessionManager2),
                                  CLSCTX_INPROC_SERVER, nullptr,
                                  sessionManager.put_void());
        if (FAILED(result)) {
            return false;
        }

        winrt::com_ptr<IAudioSessionEnumerator> sessionEnumerator;
        result = sessionManager->GetSessionEnumerator(sessionEnumerator.put());
        if (FAILED(result)) {
            return false;
        }

        int sessionCount = 0;
        if (FAILED(sessionEnumerator->GetCount(&sessionCount))) {
            return false;
        }

        for (int i = 0; i < sessionCount; ++i) {
            winrt::com_ptr<IAudioSessionControl> sessionControl;
            if (FAILED(
                    sessionEnumerator->GetSession(i, sessionControl.put()))) {
                continue;
            }

            winrt::com_ptr<IAudioSessionControl2> sessionControl2;
            if (FAILED(sessionControl->QueryInterface(
                    IID_PPV_ARGS(sessionControl2.put())))) {
                continue;
            }

            DWORD processId = 0;
            AudioSessionState sessionState = AudioSessionStateInactive;
            if (SUCCEEDED(sessionControl2->GetProcessId(&processId)) &&
                SUCCEEDED(sessionControl2->GetState(&sessionState)) &&
                sessionState == AudioSessionStateActive &&
                IsNeteaseCloudMusicProcessId(processId)) {
                return true;
            }
        }

        return false;
    };

    bool result = probe();
    {
        std::lock_guard lock(cacheMutex);
        lastCheck = std::chrono::steady_clock::now();
        lastResult = result;
    }
    return result;
}

struct NeteaseCloudMusicWindow {
    HWND hwnd = nullptr;
    std::wstring title;
};

NeteaseCloudMusicWindow FindNeteaseCloudMusicWindow() {
    NeteaseCloudMusicWindow result;
    EnumWindows(
        [](HWND hwnd, LPARAM param) -> BOOL {
            auto result = reinterpret_cast<NeteaseCloudMusicWindow*>(param);
            DWORD processId = 0;
            if (!GetWindowThreadProcessId(hwnd, &processId) ||
                !IsNeteaseCloudMusicProcessId(processId)) {
                return TRUE;
            }

            int titleLength = GetWindowTextLengthW(hwnd);
            if (titleLength <= 0 || titleLength > 2048) {
                return TRUE;
            }

            std::wstring title(static_cast<size_t>(titleLength) + 1, L'\0');
            int copied = GetWindowTextW(hwnd, title.data(),
                                        static_cast<int>(title.size()));
            if (copied <= 0) {
                return TRUE;
            }
            title.resize(static_cast<size_t>(copied));

            // The desktop client exposes the currently loaded track as
            // "<title> - <artist>" in its top-level window title even when it
            // doesn't publish a GSMTC session.
            size_t separator = title.rfind(L" - ");
            if (separator == std::wstring::npos || separator == 0 ||
                separator + 3 >= title.size()) {
                return TRUE;
            }

            result->hwnd = hwnd;
            result->title = std::move(title);
            return FALSE;
        },
        reinterpret_cast<LPARAM>(&result));
    return result;
}

bool ReadDefaultOutputVolume(double& value) {
    winrt::com_ptr<IMMDeviceEnumerator> enumerator;
    if (FAILED(CoCreateInstance(kCLSID_MMDeviceEnumerator, nullptr,
                                CLSCTX_INPROC_SERVER,
                                IID_PPV_ARGS(enumerator.put())))) {
        return false;
    }
    winrt::com_ptr<IMMDevice> device;
    if (FAILED(enumerator->GetDefaultAudioEndpoint(eRender, eMultimedia,
                                                   device.put()))) {
        return false;
    }
    winrt::com_ptr<IAudioEndpointVolume> endpoint;
    if (FAILED(device->Activate(__uuidof(IAudioEndpointVolume),
                                CLSCTX_INPROC_SERVER, nullptr,
                                endpoint.put_void()))) {
        return false;
    }
    float scalar = 0.0f;
    if (FAILED(endpoint->GetMasterVolumeLevelScalar(&scalar))) {
        return false;
    }
    value = Clamp(static_cast<double>(scalar), 0.0, 1.0);
    return true;
}

bool WriteDefaultOutputVolume(double value) {
    value = Clamp(value, 0.0, 1.0);
    winrt::com_ptr<IMMDeviceEnumerator> enumerator;
    if (FAILED(CoCreateInstance(kCLSID_MMDeviceEnumerator, nullptr,
                                CLSCTX_INPROC_SERVER,
                                IID_PPV_ARGS(enumerator.put())))) {
        return false;
    }
    winrt::com_ptr<IMMDevice> device;
    if (FAILED(enumerator->GetDefaultAudioEndpoint(eRender, eMultimedia,
                                                   device.put()))) {
        return false;
    }
    winrt::com_ptr<IAudioEndpointVolume> endpoint;
    if (FAILED(device->Activate(__uuidof(IAudioEndpointVolume),
                                CLSCTX_INPROC_SERVER, nullptr,
                                endpoint.put_void()))) {
        return false;
    }
    if (FAILED(endpoint->SetMasterVolumeLevelScalar(static_cast<float>(value),
                                                    nullptr))) {
        return false;
    }
    g_popupSystemVolume = value;
    return true;
}

HWND FindNeteaseRenderWidgetWindow(HWND parent) {
    struct SearchResult {
        HWND hwnd = nullptr;
    } search;
    EnumChildWindows(
        parent,
        [](HWND child, LPARAM param) -> BOOL {
            wchar_t className[256]{};
            if (GetClassNameW(child, className, ARRAYSIZE(className)) &&
                _wcsicmp(className, L"Chrome_RenderWidgetHostHWND") == 0) {
                reinterpret_cast<SearchResult*>(param)->hwnd = child;
                return FALSE;
            }
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&search));
    return search.hwnd;
}

int ScaleNeteasePixel(HWND window, int pixel) {
    UINT dpi = window ? GetDpiForWindow(window) : 96;
    if (!dpi) {
        dpi = 96;
    }
    return MulDiv(pixel, static_cast<int>(dpi), 96);
}

bool SendNeteaseGlobalShortcut(WORD key) {
    INPUT inputs[6]{};
    WORD keys[3] = {VK_CONTROL, VK_MENU, key};
    for (int i = 0; i < 3; ++i) {
        inputs[i].type = INPUT_KEYBOARD;
        inputs[i].ki.wVk = keys[i];
    }
    for (int i = 0; i < 3; ++i) {
        inputs[3 + i].type = INPUT_KEYBOARD;
        inputs[3 + i].ki.wVk = keys[2 - i];
        inputs[3 + i].ki.dwFlags = KEYEVENTF_KEYUP;
    }
    return SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT)) ==
           ARRAYSIZE(inputs);
}

bool IsWindowInInteractiveMoveSize(HWND window) {
    if (!window || !IsWindow(window)) {
        return false;
    }
    DWORD threadId = GetWindowThreadProcessId(window, nullptr);
    GUITHREADINFO info{sizeof(info)};
    return threadId && GetGUIThreadInfo(threadId, &info) &&
           (info.flags & GUI_INMOVESIZE) != 0;
}

bool TryGetNeteasePlaybackState(bool* isPlaying) {
    if (!isPlaying) {
        return false;
    }
    auto window = FindNeteaseCloudMusicWindow();
    if (!window.hwnd) {
        return false;
    }

    // UI Automation traverses NetEase's CEF accessibility tree synchronously.
    // Doing that four times per second stalls the same UI thread that moves the
    // window. Never query it during an interactive move/resize and reuse the
    // last result between the much less frequent probes.
    static std::mutex cacheMutex;
    static std::chrono::steady_clock::time_point lastProbe{};
    static bool cachedValid = false;
    static bool cachedPlaying = false;
    auto now = std::chrono::steady_clock::now();
    {
        std::lock_guard lock(cacheMutex);
        if (IsWindowInInteractiveMoveSize(window.hwnd)) {
            if (cachedValid) {
                *isPlaying = cachedPlaying;
            }
            return cachedValid;
        }
        if (cachedValid && lastProbe.time_since_epoch().count() != 0 &&
            now - lastProbe < std::chrono::milliseconds(1500)) {
            *isPlaying = cachedPlaying;
            return true;
        }
    }

    IUIAutomation* automation = nullptr;
    IUIAutomationElement* root = nullptr;
    IUIAutomationCondition* condition = nullptr;
    IUIAutomationElement* element = nullptr;
    HRESULT result =
        CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER,
                         IID_PPV_ARGS(&automation));
    if (SUCCEEDED(result)) {
        result = automation->ElementFromHandle(window.hwnd, &root);
    }
    if (SUCCEEDED(result)) {
        VARIANT value{};
        value.vt = VT_BSTR;
        value.bstrVal = SysAllocString(L"btn_pc_minibar_play");
        result = value.bstrVal
                     ? automation->CreatePropertyCondition(
                           UIA_AutomationIdPropertyId, value, &condition)
                     : E_OUTOFMEMORY;
        VariantClear(&value);
    }
    if (SUCCEEDED(result)) {
        result = root->FindFirst(TreeScope_Descendants, condition, &element);
    }

    bool found = false;
    if (SUCCEEDED(result) && element) {
        BSTR nameRaw = nullptr;
        if (SUCCEEDED(element->get_CurrentName(&nameRaw))) {
            std::wstring name = nameRaw ? nameRaw : L"";
            if (EqualsInsensitive(name, L"pause")) {
                *isPlaying = true;
                found = true;
            } else if (EqualsInsensitive(name, L"play")) {
                *isPlaying = false;
                found = true;
            }
        }
        SysFreeString(nameRaw);
    }

    if (element) {
        element->Release();
    }
    if (condition) {
        condition->Release();
    }
    if (root) {
        root->Release();
    }
    if (automation) {
        automation->Release();
    }
    {
        std::lock_guard lock(cacheMutex);
        lastProbe = now;
        if (found) {
            cachedValid = true;
            cachedPlaying = *isPlaying;
        }
    }
    return found;
}

enum class MediaTransportCommand {
    Previous,
    TogglePlayPause,
    Next,
};

void ApplyOptimisticPlaybackToggle();
void SetCompactPlaybackIndicatorState(bool playing);
void ResetMediaProgressUiForTrackNavigation();

bool TrySeekNeteaseCloudMusic(double ratio) {
    auto window = FindNeteaseCloudMusicWindow();
    if (!window.hwnd) {
        return false;
    }

    ratio = Clamp(ratio, 0.0, 1.0);
    HWND previousForeground = GetForegroundWindow();
    bool wasMinimized = IsIconic(window.hwnd);

    // A cloaked DWM surface is suspended by this CEF build and therefore can't
    // accept seek input. Instead keep it interactive while making the parent
    // virtually invisible for the short activation interval.
    LONG_PTR originalExStyle = GetWindowLongPtrW(window.hwnd, GWL_EXSTYLE);
    bool wasLayered = (originalExStyle & WS_EX_LAYERED) != 0;
    COLORREF originalColorKey = 0;
    BYTE originalAlpha = 255;
    DWORD originalLayeredFlags = LWA_ALPHA;
    if (wasLayered) {
        GetLayeredWindowAttributes(window.hwnd, &originalColorKey,
                                   &originalAlpha, &originalLayeredFlags);
    }
    SetWindowLongPtrW(window.hwnd, GWL_EXSTYLE,
                      originalExStyle | WS_EX_LAYERED);
    bool hiddenForSeek =
        SetLayeredWindowAttributes(window.hwnd, 0, 1, LWA_ALPHA) != FALSE;
    auto restoreWindowVisual = [&] {
        if (wasLayered) {
            SetLayeredWindowAttributes(window.hwnd, originalColorKey,
                                       originalAlpha, originalLayeredFlags);
        } else {
            SetWindowLongPtrW(window.hwnd, GWL_EXSTYLE, originalExStyle);
            SetWindowPos(window.hwnd, nullptr, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
                             SWP_NOACTIVATE | SWP_FRAMECHANGED);
        }
    };
    if (!hiddenForSeek) {
        restoreWindowVisual();
        return false;
    }

    if (wasMinimized) {
        ShowWindow(window.hwnd, SW_RESTORE);
        for (int attempt = 0; attempt < 40 && IsIconic(window.hwnd);
             ++attempt) {
            Sleep(5);
        }
    }

    HWND renderWidget = FindNeteaseRenderWidgetWindow(window.hwnd);
    RECT client{};
    if (!renderWidget || !GetClientRect(renderWidget, &client) ||
        client.right <= client.left || client.bottom <= client.top) {
        if (wasMinimized) {
            ShowWindow(window.hwnd, SW_MINIMIZE);
        }
        restoreWindowVisual();
        return false;
    }

    int edgeInset = std::max(1, ScaleNeteasePixel(window.hwnd, 2));
    int seekWidth =
        std::max(1, static_cast<int>(client.right - client.left) - edgeInset);
    int x = client.left + static_cast<int>(std::llround(seekWidth * ratio));
    // NetEase 3.x draws the seek strip at the top edge of its 82-DIP minibar.
    int y = std::max(client.top,
                     client.bottom - ScaleNeteasePixel(window.hwnd, 82));
    LPARAM point = MAKELPARAM(static_cast<SHORT>(x), static_cast<SHORT>(y));

    bool foregroundAccepted = SetForegroundWindow(window.hwnd) != FALSE;
    Sleep(10);

    DWORD_PTR ignored = 0;
    auto send = [&](UINT message, WPARAM keys) {
        return SendMessageTimeoutW(renderWidget, message, keys, point,
                                   SMTO_ABORTIFHUNG | SMTO_BLOCK, 180,
                                   &ignored) != 0;
    };
    SendMessageTimeoutW(window.hwnd, WM_ACTIVATE, WA_ACTIVE,
                        reinterpret_cast<LPARAM>(previousForeground),
                        SMTO_ABORTIFHUNG | SMTO_BLOCK, 180, &ignored);
    SendMessageTimeoutW(renderWidget, WM_SETFOCUS, 0, 0,
                        SMTO_ABORTIFHUNG | SMTO_BLOCK, 180, &ignored);
    bool moved = send(WM_MOUSEMOVE, 0);
    bool pressed = send(WM_LBUTTONDOWN, MK_LBUTTON);
    bool released = send(WM_LBUTTONUP, 0);
    bool succeeded = moved && pressed && released;
    SendMessageTimeoutW(renderWidget, WM_KILLFOCUS,
                        reinterpret_cast<WPARAM>(previousForeground), 0,
                        SMTO_ABORTIFHUNG | SMTO_BLOCK, 180, &ignored);
    SendMessageTimeoutW(window.hwnd, WM_ACTIVATE, WA_INACTIVE,
                        reinterpret_cast<LPARAM>(previousForeground),
                        SMTO_ABORTIFHUNG | SMTO_BLOCK, 180, &ignored);

    if (previousForeground && previousForeground != window.hwnd &&
        IsWindow(previousForeground)) {
        SetForegroundWindow(previousForeground);
    }
    if (wasMinimized) {
        ShowWindow(window.hwnd, SW_MINIMIZE);
    }
    restoreWindowVisual();
    Wh_Log(
        L"Island: NetEase hidden seek result=%d foreground=%d ratio=%.4f "
        L"hwnd=%p",
        succeeded, foregroundAccepted, ratio, renderWidget);
    return succeeded;
}

bool TryToggleNeteaseFavorite() {
    auto window = FindNeteaseCloudMusicWindow();
    if (!window.hwnd) {
        return false;
    }

    // InvokePattern reports success but NetEase's CEF renderer ignores it.
    // Click the actual heart at the same location used to read its live
    // "like"/"dislike" accessibility state. Resolve this point after restoring
    // a minimized window and scale the minibar offsets for its monitor DPI.
    bool succeeded = ClickResolvedScreenPointForWindow(
        window.hwnd, [windowHandle = window.hwnd](POINT* point) -> bool {
            if (!point) {
                return false;
            }

            HWND renderWidget = FindNeteaseRenderWidgetWindow(windowHandle);
            RECT client{};
            if (!renderWidget || !GetClientRect(renderWidget, &client) ||
                client.right <= client.left || client.bottom <= client.top) {
                return false;
            }
            point->x = client.left + ScaleNeteasePixel(windowHandle, 247);
            point->y = client.bottom - ScaleNeteasePixel(windowHandle, 40);
            return ClientToScreen(renderWidget, point) != FALSE;
        });
    Wh_Log(L"Island: NetEase favorite toggle result=%d", succeeded);
    return succeeded;
}

int64_t EstimateNeteasePositionTicks(NeteaseTrackMetadata const& metadata,
                                     bool isPlaying) {
    auto now = std::chrono::steady_clock::now();
    // NetEase can update the visible title before its local metadata id. The
    // estimator must reset on either signal; otherwise it keeps accumulating
    // the previous song underneath the UI's temporary zero guard.
    std::wstring trackIdentity = metadata.id + L"\n" + metadata.title;
    bool firstTrackSample = g_neteaseProgressTrackId.empty();
    bool newTrack = trackIdentity != g_neteaseProgressTrackId;
    bool newPlaybackTimestamp =
        metadata.sourceTimestampTracksPlayback &&
        metadata.sourceWriteTimeTicks != 0 &&
        metadata.sourceWriteTimeTicks != g_neteaseProgressSourceWriteTimeTicks;

    if (newTrack || newPlaybackTimestamp ||
        g_neteaseProgressSampleTime.time_since_epoch().count() == 0) {
        g_neteaseProgressTrackId = std::move(trackIdentity);
        g_neteaseProgressSourceWriteTimeTicks = metadata.sourceWriteTimeTicks;
        g_neteaseEstimatedPositionTicks = 0;

        // A title-only change paired with the previous file timestamp is a
        // mixed old/new provider snapshot. Keep zero until a fresh timestamp
        // arrives instead of converting that old timestamp into inherited
        // progress for the new title.
        if (metadata.sourceTimestampTracksPlayback &&
            metadata.sourceWriteTimeTicks != 0 &&
            (firstTrackSample || newPlaybackTimestamp)) {
            FILETIME nowFileTime{};
            GetSystemTimeAsFileTime(&nowFileTime);
            uint64_t nowTicks =
                (static_cast<uint64_t>(nowFileTime.dwHighDateTime) << 32) |
                nowFileTime.dwLowDateTime;
            if (nowTicks >= metadata.sourceWriteTimeTicks) {
                uint64_t ageTicks = nowTicks - metadata.sourceWriteTimeTicks;
                if (ageTicks <= static_cast<uint64_t>(std::max<int64_t>(
                                    metadata.durationTicks, 0))) {
                    g_neteaseEstimatedPositionTicks =
                        static_cast<int64_t>(ageTicks);
                }
            }
        }
    } else if (isPlaying) {
        g_neteaseEstimatedPositionTicks +=
            std::chrono::duration_cast<
                std::chrono::duration<int64_t, std::ratio<1, 10000000>>>(
                now - g_neteaseProgressSampleTime)
                .count();
    }

    g_neteaseProgressSampleTime = now;
    g_neteaseEstimatedPositionTicks =
        std::clamp<int64_t>(g_neteaseEstimatedPositionTicks, 0,
                            std::max<int64_t>(metadata.durationTicks, 0));
    return g_neteaseEstimatedPositionTicks;
}

bool TryReadNeteaseCloudMusicState(MediaState* state, bool requireActive) {
    if (!state) {
        return false;
    }

    bool isPlaying = IsNeteaseCloudMusicAudioActive();
    bool playerButtonState = false;
    if (TryGetNeteasePlaybackState(&playerButtonState)) {
        isPlaying = playerButtonState;
    }
    if (requireActive && !isPlaying) {
        return false;
    }

    auto window = FindNeteaseCloudMusicWindow();
    size_t separator = window.title.rfind(L" - ");
    if (!window.hwnd || separator == std::wstring::npos) {
        return false;
    }

    MediaState fallback;
    fallback.hasSession = true;
    fallback.isPlaying = isPlaying;
    fallback.sourceAppUserModelId = L"cloudmusic.exe";
    NeteaseTrackMetadata metadata;
    if (TryReadNeteaseTrackMetadata(window.title, &metadata)) {
        fallback.mediaId = std::move(metadata.id);
        fallback.title = std::move(metadata.title);
        fallback.artist = std::move(metadata.artist);
        fallback.durationTicks = metadata.durationTicks;
        fallback.positionTicks =
            EstimateNeteasePositionTicks(metadata, isPlaying);
        fallback.canSeek = fallback.durationTicks > 0;
        fallback.thumbnailBytes = ReadNeteaseCachedArtwork(metadata.artworkUrl);
        if (fallback.thumbnailBytes.empty()) {
            fallback.thumbnailBytes =
                RequestNeteaseRemoteArtworkAsync(metadata.artworkUrl);
        }
    } else {
        fallback.title = window.title.substr(0, separator);
        fallback.artist = window.title.substr(separator + 3);
    }
    MediaState previous = SnapshotMedia();
    bool sameTrack =
        previous.hasSession &&
        _wcsicmp(previous.sourceAppUserModelId.c_str(), L"cloudmusic.exe") ==
            0 &&
        ((!fallback.mediaId.empty() && previous.mediaId == fallback.mediaId) ||
         (fallback.mediaId.empty() && previous.mediaId.empty() &&
          previous.title == fallback.title &&
          previous.artist == fallback.artist));
    fallback.canFavorite = true;
    fallback.isFavorite = sameTrack && previous.isFavorite;

    // NetEase 3.x doesn't expose the heart through UI Automation. Keep the
    // result of our real player click authoritative for this track so the star
    // responds instantly and isn't reset by the next 60 ms metadata refresh.
    std::wstring favoriteTrackKey =
        fallback.mediaId.empty() ? fallback.title : fallback.mediaId;
    {
        std::lock_guard optimisticLock(g_neteaseFavoriteOptimisticMutex);
        auto now = std::chrono::steady_clock::now();
        if (g_neteaseFavoriteOptimisticPending &&
            (now >= g_neteaseFavoriteOptimisticUntil ||
             g_neteaseFavoriteOptimisticTrackKey != favoriteTrackKey)) {
            g_neteaseFavoriteOptimisticPending = false;
            g_neteaseFavoriteOptimisticTrackKey.clear();
        }
        if (g_neteaseFavoriteOptimisticPending) {
            fallback.isFavorite = g_neteaseFavoriteOptimisticValue;
        }
    }

    // Commit title/artist/cover as one track snapshot. If NetEase has changed
    // its title a few milliseconds before writing the matching Statics entry,
    // retain the previous complete track briefly instead of showing a new title
    // with the old or missing cover.
    static std::wstring pendingArtworkMediaId;
    static std::chrono::steady_clock::time_point pendingArtworkSince{};
    bool changedTrack = previous.hasSession &&
                        _wcsicmp(previous.sourceAppUserModelId.c_str(),
                                 L"cloudmusic.exe") == 0 &&
                        (previous.mediaId != fallback.mediaId ||
                         previous.title != fallback.title);
    bool artworkExpected = !metadata.artworkUrl.empty();
    if (changedTrack && artworkExpected && fallback.thumbnailBytes.empty() &&
        !previous.thumbnailBytes.empty()) {
        std::wstring pendingKey =
            fallback.mediaId.empty() ? fallback.title : fallback.mediaId;
        auto now = std::chrono::steady_clock::now();
        if (pendingArtworkMediaId != pendingKey) {
            pendingArtworkMediaId = std::move(pendingKey);
            pendingArtworkSince = now;
        }
        if (now - pendingArtworkSince < std::chrono::milliseconds(300)) {
            previous.isPlaying = isPlaying;
            previous.canFavorite = fallback.canFavorite;
            previous.isFavorite = fallback.isFavorite;
            // The title bar has already switched tracks, so the old timeline
            // is invalid even if the new artwork is still arriving. Publish a
            // distinct pending track key at position zero while retaining only
            // the old pixels temporarily. This prevents a finished 5:04 track
            // from becoming the starting position of the next song.
            previous.mediaId = L"pending:" + pendingArtworkMediaId;
            previous.timelineStartTicks = 0;
            previous.positionTicks = 0;
            previous.durationTicks = fallback.durationTicks;
            previous.canSeek = fallback.canSeek;
            *state = std::move(previous);
            return true;
        }
    } else {
        pendingArtworkMediaId.clear();
        pendingArtworkSince = {};
    }
    *state = std::move(fallback);
    return true;
}

// ===== Media source classification =====
bool IsNeteaseCloudMusicSource(std::wstring const& sourceAppUserModelId) {
    return _wcsicmp(sourceAppUserModelId.c_str(), L"cloudmusic.exe") == 0;
}

bool IsBilibiliSource(std::wstring const& sourceAppUserModelId) {
    return ContainsInsensitive(sourceAppUserModelId, L"bilibili");
}

bool IsDefaultMediaSource(std::wstring const& sourceAppUserModelId) {
    return EqualsInsensitive(sourceAppUserModelId, L"island.default");
}

MediaState CreateDefaultMediaState() {
    MediaState state;
    state.hasSession = true;
    state.title = L"凤梨Felinyu";
    state.artist = L"Felinyu";
    state.sourceAppUserModelId = L"island.default";
    state.mediaId = L"default";
    state.thumbnailBytes = ReadDefaultCoverBytes();
    return state;
}

gsm::GlobalSystemMediaTransportControlsSession SelectBestSession(
    gsm::GlobalSystemMediaTransportControlsSessionManager const& manager) {
    try {
        if (!manager) {
            return nullptr;
        }

        auto current = manager.GetCurrentSession();
        gsm::GlobalSystemMediaTransportControlsSession first{nullptr};
        gsm::GlobalSystemMediaTransportControlsSession firstPlaying{nullptr};
        for (auto const& session : manager.GetSessions()) {
            if (!first) {
                first = session;
            }

            bool isPlaying = false;
            try {
                isPlaying =
                    session.GetPlaybackInfo().PlaybackStatus() ==
                    gsm::
                        GlobalSystemMediaTransportControlsSessionPlaybackStatus::
                            Playing;
            } catch (...) {
            }
            if (!isPlaying) {
                continue;
            }

            if (current && winrt::get_abi(session) == winrt::get_abi(current)) {
                return session;
            }
            if (!firstPlaying) {
                firstPlaying = session;
            }
        }

        if (firstPlaying) {
            return firstPlaying;
        }
        return current ? current : first;
    } catch (...) {
        return nullptr;
    }
}

gsm::GlobalSystemMediaTransportControlsSession CurrentSession() {
    try {
        auto manager = RequestMediaManagerWithTimeout(std::chrono::seconds(2));
        return SelectBestSession(manager);
    } catch (...) {
        return nullptr;
    }
}

gsm::GlobalSystemMediaTransportControlsSession CurrentSessionFromManager(
    gsm::GlobalSystemMediaTransportControlsSessionManager const& manager) {
    try {
        if (manager) {
            return SelectBestSession(manager);
        }
    } catch (...) {
    }
    return CurrentSession();
}

// ===== Media refresh and commands =====
void RefreshMediaState(
    gsm::GlobalSystemMediaTransportControlsSessionManager const& manager =
        nullptr) {
    MediaState state;
    MediaState previous = SnapshotMedia();
    bool neteaseWasCurrent =
        IsNeteaseCloudMusicSource(previous.sourceAppUserModelId);
    // Once NetEase is the active source, keep its paused state instead of
    // discarding it and falling back to a stale "playing" GSMTC session.
    bool haveState = TryReadNeteaseCloudMusicState(&state, !neteaseWasCurrent);
    if (!haveState) {
        try {
            auto session = CurrentSessionFromManager(manager);
            if (session) {
                state.hasSession = true;
                try {
                    state.sourceAppUserModelId =
                        std::wstring(session.SourceAppUserModelId());
                } catch (...) {
                    state.sourceAppUserModelId.clear();
                }
                auto playback = session.GetPlaybackInfo();
                state.isPlaying =
                    playback.PlaybackStatus() ==
                    gsm::
                        GlobalSystemMediaTransportControlsSessionPlaybackStatus::
                            Playing;
                try {
                    state.canSeek =
                        playback.Controls().IsPlaybackPositionEnabled();
                } catch (...) {
                    state.canSeek = false;
                }

                auto props = GetAsyncResultWithTimeout(
                    session.TryGetMediaPropertiesAsync(),
                    kMediaPropertiesAsyncTimeout,
                    L"TryGetMediaPropertiesAsync");
                state.title = props.Title().empty()
                                  ? L"Unknown title"
                                  : std::wstring(props.Title());
                state.artist = props.Artist().empty()
                                   ? std::wstring(props.AlbumArtist())
                                   : std::wstring(props.Artist());
                state.thumbnailBytes = ReadThumbnailBytes(props.Thumbnail());

                auto timeline = session.GetTimelineProperties();
                int64_t start = timeline.StartTime().count();
                int64_t end = timeline.EndTime().count();
                int64_t position = timeline.Position().count();
                state.timelineStartTicks = start;
                state.durationTicks = end > start ? end - start : 0;
                state.positionTicks =
                    state.durationTicks > 0
                        ? std::clamp<int64_t>(position - start, 0,
                                              state.durationTicks)
                        : 0;
                if (IsBilibiliSource(state.sourceAppUserModelId)) {
                    // Bilibili metadata can be more complete than GSMTC, but
                    // GSMTC remains the sole source of timeline and seek state.
                    TryReadBilibiliState(&state, state.isPlaying);
                }
                haveState = true;
            }
        } catch (...) {
            state = {};
        }
    }

    if (!haveState) {
        haveState = TryReadNeteaseCloudMusicState(&state, false);
    }
    if (!haveState) {
        state = CreateDefaultMediaState();
    }
    SetMedia(std::move(state));
}

void RunMediaCommand(MediaCommand command) {
    if (!command || !IsModActive() || !g_mediaThreadRunning.load()) {
        return;
    }

    {
        std::lock_guard lock(g_mediaCommandMutex);
        g_mediaCommands.push_back(std::move(command));
    }
    g_mediaCommandCv.notify_one();
}

void SeekToMediaPosition(double ratio) {
    MediaState state = SnapshotMedia();
    if (!state.hasSession || state.durationTicks <= 0) {
        return;
    }

    ratio = Clamp(ratio, 0.0, 1.0);
    if (IsNeteaseCloudMusicSource(state.sourceAppUserModelId)) {
        g_neteaseSeekRatioRequested = ratio;
        g_mediaCommandCv.notify_one();
        return;
    }

    int64_t relativePositionTicks = static_cast<int64_t>(
        std::llround(static_cast<double>(state.durationTicks) * ratio));
    int64_t absolutePositionTicks =
        state.timelineStartTicks + relativePositionTicks;
    bool providerReportsSeekSupport = state.canSeek;
    RunMediaCommand(
        [absolutePositionTicks, relativePositionTicks,
         providerReportsSeekSupport,
         ratio](gsm::GlobalSystemMediaTransportControlsSession const& session) {
            try {
                auto source = session.SourceAppUserModelId();
                bool isAppleMusic =
                    std::wstring_view(source).find(L"AppleMusic") !=
                    std::wstring_view::npos;
                if (isAppleMusic && !providerReportsSeekSupport &&
                    TrySeekAppleMusicWithUiAutomation(ratio)) {
                    return;
                }

                bool changed = GetAsyncResultWithTimeout(
                    session.TryChangePlaybackPositionAsync(
                        relativePositionTicks),
                    kMediaCommandAsyncTimeout,
                    L"TryChangePlaybackPositionAsync relative");
                if (!changed &&
                    absolutePositionTicks != relativePositionTicks) {
                    changed = GetAsyncResultWithTimeout(
                        session.TryChangePlaybackPositionAsync(
                            absolutePositionTicks),
                        kMediaCommandAsyncTimeout,
                        L"TryChangePlaybackPositionAsync absolute");
                }
                Wh_Log(
                    L"Island: seek source=%s result=%d advertised=%d "
                    L"relative=%lld absolute=%lld",
                    source.c_str(), changed, providerReportsSeekSupport,
                    static_cast<long long>(relativePositionTicks),
                    static_cast<long long>(absolutePositionTicks));
            } catch (winrt::hresult_error const& error) {
                Wh_Log(L"Island: seek source=%s failed=0x%08X",
                       session.SourceAppUserModelId().c_str(),
                       static_cast<unsigned>(error.code().value));
            }
        });
}

// ===== Artwork pipeline =====
uint64_t ThumbnailHash(std::vector<uint8_t> const& bytes) {
    if (bytes.empty()) {
        return 0;
    }

    uint64_t hash = 1469598103934665603ull;
    for (uint8_t byte : bytes) {
        hash ^= byte;
        hash *= 1099511628211ull;
    }
    return hash;
}

HBITMAP DecodeAlbumBitmap(std::vector<uint8_t> const& bytes, UINT size) {
    if (bytes.empty() || size == 0) {
        return nullptr;
    }

    IStream* stream =
        SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size()));
    IWICImagingFactory* factory = nullptr;
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;
    IWICBitmapScaler* scaler = nullptr;
    IWICFormatConverter* converter = nullptr;
    HBITMAP bitmap = nullptr;

    HRESULT hr = stream ? S_OK : E_FAIL;
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                              CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateDecoderFromStream(
            stream, nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    }
    if (SUCCEEDED(hr)) {
        hr = decoder->GetFrame(0, &frame);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateBitmapScaler(&scaler);
    }
    if (SUCCEEDED(hr)) {
        hr = scaler->Initialize(frame, size, size,
                                WICBitmapInterpolationModeFant);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateFormatConverter(&converter);
    }
    if (SUCCEEDED(hr)) {
        hr = converter->Initialize(scaler, GUID_WICPixelFormat32bppPBGRA,
                                   WICBitmapDitherTypeNone, nullptr, 0,
                                   WICBitmapPaletteTypeCustom);
    }

    void* pixels = nullptr;
    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = static_cast<LONG>(size);
    info.bmiHeader.biHeight = -static_cast<LONG>(size);
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    if (SUCCEEDED(hr)) {
        bitmap = CreateDIBSection(nullptr, &info, DIB_RGB_COLORS, &pixels,
                                  nullptr, 0);
        if (!bitmap || !pixels) {
            hr = E_OUTOFMEMORY;
        }
    }
    if (SUCCEEDED(hr)) {
        hr = converter->CopyPixels(nullptr, size * 4, size * size * 4,
                                   static_cast<BYTE*>(pixels));
    }
    if (FAILED(hr) && bitmap) {
        DeleteObject(bitmap);
        bitmap = nullptr;
    }

    if (converter)
        converter->Release();
    if (scaler)
        scaler->Release();
    if (frame)
        frame->Release();
    if (decoder)
        decoder->Release();
    if (factory)
        factory->Release();
    if (stream)
        stream->Release();
    return bitmap;
}

std::vector<uint8_t> CreateLowDetailAlbumCoverBytes(
    std::vector<uint8_t> const& bytes,
    bool edgeFadeToMiddle = false,
    bool fadeFromTop = false,
    bool fadeFromRight = false) {
    std::vector<uint8_t> output;
    if (bytes.empty()) {
        return output;
    }

    // Keep this layer as a soft color wash. Slightly stronger than the
    // previous C-polish pass, but not so smeared that it loses all album
    // character.
    constexpr UINT kLowDetailSize = 20;
    constexpr UINT kBlurRadius = 1;
    constexpr int kBlurPasses = 3;
    const UINT stride = kLowDetailSize * 4;
    const UINT bufferSize = stride * kLowDetailSize;

    IStream* stream =
        SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size()));
    IWICImagingFactory* factory = nullptr;
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;
    IWICBitmapScaler* scaler = nullptr;
    IWICFormatConverter* converter = nullptr;
    IStream* outStream = nullptr;
    IWICBitmapEncoder* encoder = nullptr;
    IWICBitmapFrameEncode* outFrame = nullptr;
    IPropertyBag2* propertyBag = nullptr;

    HRESULT hr = stream ? S_OK : E_FAIL;
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                              CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateDecoderFromStream(
            stream, nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    }
    if (SUCCEEDED(hr)) {
        hr = decoder->GetFrame(0, &frame);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateBitmapScaler(&scaler);
    }
    if (SUCCEEDED(hr)) {
        hr = scaler->Initialize(frame, kLowDetailSize, kLowDetailSize,
                                WICBitmapInterpolationModeFant);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateFormatConverter(&converter);
    }
    if (SUCCEEDED(hr)) {
        hr = converter->Initialize(scaler, GUID_WICPixelFormat32bppPBGRA,
                                   WICBitmapDitherTypeNone, nullptr, 0,
                                   WICBitmapPaletteTypeCustom);
    }

    std::vector<BYTE> pixels(bufferSize);
    if (SUCCEEDED(hr)) {
        hr = converter->CopyPixels(nullptr, stride, bufferSize, pixels.data());
    }

    auto boxBlurPass = [&] {
        std::vector<BYTE> source = pixels;
        for (UINT y = 0; y < kLowDetailSize; ++y) {
            for (UINT x = 0; x < kLowDetailSize; ++x) {
                int sumB = 0;
                int sumG = 0;
                int sumR = 0;
                int sumA = 0;
                int count = 0;
                int left = std::max(
                    0, static_cast<int>(x) - static_cast<int>(kBlurRadius));
                int right = std::min(
                    static_cast<int>(kLowDetailSize) - 1,
                    static_cast<int>(x) + static_cast<int>(kBlurRadius));
                int top = std::max(
                    0, static_cast<int>(y) - static_cast<int>(kBlurRadius));
                int bottom = std::min(
                    static_cast<int>(kLowDetailSize) - 1,
                    static_cast<int>(y) + static_cast<int>(kBlurRadius));
                for (int yy = top; yy <= bottom; ++yy) {
                    for (int xx = left; xx <= right; ++xx) {
                        BYTE* pixel =
                            source.data() +
                            (static_cast<size_t>(yy) * kLowDetailSize + xx) * 4;
                        sumB += pixel[0];
                        sumG += pixel[1];
                        sumR += pixel[2];
                        sumA += pixel[3];
                        ++count;
                    }
                }
                BYTE* target =
                    pixels.data() +
                    (static_cast<size_t>(y) * kLowDetailSize + x) * 4;
                target[0] = static_cast<BYTE>(sumB / count);
                target[1] = static_cast<BYTE>(sumG / count);
                target[2] = static_cast<BYTE>(sumR / count);
                target[3] = static_cast<BYTE>(sumA / count);
            }
        }
    };
    if (SUCCEEDED(hr)) {
        for (int pass = 0; pass < kBlurPasses; ++pass) {
            boxBlurPass();
        }
    }

    if (SUCCEEDED(hr) && edgeFadeToMiddle) {
        // Expanded-surface color wash: keep only a low-frequency album glow
        // near the selected edge and ease it to transparent at the middle.
        const double kEdgeAlpha = IsDarkModeApprox() ? 0.72 : 0.88;
        const double middle =
            (static_cast<double>(kLowDetailSize) - 1.0) * 0.50;
        const double edge = static_cast<double>(kLowDetailSize) - 1.0;
        for (UINT y = 0; y < kLowDetailSize; ++y) {
            for (UINT x = 0; x < kLowDetailSize; ++x) {
                double edgePosition =
                    fadeFromRight ? static_cast<double>(x)
                                  : (fadeFromTop ? edge - static_cast<double>(y)
                                                 : static_cast<double>(y));
                double amount = 0.0;
                if (edgePosition > middle && edge > middle) {
                    amount = (edgePosition - middle) / (edge - middle);
                    amount = Clamp(amount, 0.0, 1.0);
                    amount = amount * amount * (3.0 - 2.0 * amount);
                }
                double alphaScale = kEdgeAlpha * amount;
                BYTE* pixel = pixels.data() +
                              (static_cast<size_t>(y) * kLowDetailSize + x) * 4;
                pixel[3] =
                    static_cast<BYTE>(std::lround(pixel[3] * alphaScale));
                pixel[0] =
                    static_cast<BYTE>(std::lround(pixel[0] * alphaScale));
                pixel[1] =
                    static_cast<BYTE>(std::lround(pixel[1] * alphaScale));
                pixel[2] =
                    static_cast<BYTE>(std::lround(pixel[2] * alphaScale));
            }
        }
    }

    if (SUCCEEDED(hr)) {
        hr = CreateStreamOnHGlobal(nullptr, TRUE, &outStream);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateEncoder(GUID_ContainerFormatPng, nullptr, &encoder);
    }
    if (SUCCEEDED(hr)) {
        hr = encoder->Initialize(outStream, WICBitmapEncoderNoCache);
    }
    if (SUCCEEDED(hr)) {
        hr = encoder->CreateNewFrame(&outFrame, &propertyBag);
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->Initialize(propertyBag);
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->SetSize(kLowDetailSize, kLowDetailSize);
    }
    WICPixelFormatGUID pixelFormat = GUID_WICPixelFormat32bppPBGRA;
    if (SUCCEEDED(hr)) {
        hr = outFrame->SetPixelFormat(&pixelFormat);
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->WritePixels(kLowDetailSize, stride, bufferSize,
                                   pixels.data());
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->Commit();
    }
    if (SUCCEEDED(hr)) {
        hr = encoder->Commit();
    }
    if (SUCCEEDED(hr)) {
        HGLOBAL memory = nullptr;
        hr = GetHGlobalFromStream(outStream, &memory);
        if (SUCCEEDED(hr) && memory) {
            SIZE_T size = GlobalSize(memory);
            void* data = GlobalLock(memory);
            if (data && size > 0) {
                auto first = static_cast<uint8_t*>(data);
                output.assign(first, first + size);
            }
            if (data) {
                GlobalUnlock(memory);
            }
        }
    }

    if (propertyBag)
        propertyBag->Release();
    if (outFrame)
        outFrame->Release();
    if (encoder)
        encoder->Release();
    if (outStream)
        outStream->Release();
    if (converter)
        converter->Release();
    if (scaler)
        scaler->Release();
    if (frame)
        frame->Release();
    if (decoder)
        decoder->Release();
    if (factory)
        factory->Release();
    if (stream)
        stream->Release();
    return output;
}

winrt::Windows::UI::Color DefaultPopupAccentColor() {
    return Color(0xFF, 0x4F, 0x7D, 0xE8);
}

std::vector<uint8_t> EncodePbgraPngBytes(UINT width,
                                         UINT height,
                                         std::vector<BYTE> const& pixels) {
    std::vector<uint8_t> output;
    if (width == 0 || height == 0 ||
        pixels.size() < static_cast<size_t>(width) * height * 4) {
        return output;
    }

    IWICImagingFactory* factory = nullptr;
    IStream* outStream = nullptr;
    IWICBitmapEncoder* encoder = nullptr;
    IWICBitmapFrameEncode* outFrame = nullptr;
    IPropertyBag2* propertyBag = nullptr;

    HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                                  CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    if (SUCCEEDED(hr)) {
        hr = CreateStreamOnHGlobal(nullptr, TRUE, &outStream);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateEncoder(GUID_ContainerFormatPng, nullptr, &encoder);
    }
    if (SUCCEEDED(hr)) {
        hr = encoder->Initialize(outStream, WICBitmapEncoderNoCache);
    }
    if (SUCCEEDED(hr)) {
        hr = encoder->CreateNewFrame(&outFrame, &propertyBag);
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->Initialize(propertyBag);
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->SetSize(width, height);
    }
    WICPixelFormatGUID pixelFormat = GUID_WICPixelFormat32bppPBGRA;
    if (SUCCEEDED(hr)) {
        hr = outFrame->SetPixelFormat(&pixelFormat);
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->WritePixels(height, width * 4, width * height * 4,
                                   const_cast<BYTE*>(pixels.data()));
    }
    if (SUCCEEDED(hr)) {
        hr = outFrame->Commit();
    }
    if (SUCCEEDED(hr)) {
        hr = encoder->Commit();
    }
    if (SUCCEEDED(hr)) {
        HGLOBAL memory = nullptr;
        hr = GetHGlobalFromStream(outStream, &memory);
        if (SUCCEEDED(hr) && memory) {
            SIZE_T size = GlobalSize(memory);
            void* data = GlobalLock(memory);
            if (data && size > 0) {
                auto first = static_cast<uint8_t*>(data);
                output.assign(first, first + size);
            }
            if (data) {
                GlobalUnlock(memory);
            }
        }
    }

    if (propertyBag)
        propertyBag->Release();
    if (outFrame)
        outFrame->Release();
    if (encoder)
        encoder->Release();
    if (outStream)
        outStream->Release();
    if (factory)
        factory->Release();
    return output;
}

bool PopupCoverG2MaskContains(double px, double py, UINT size, double radius) {
    if (size == 0 || radius <= 0.0) {
        return true;
    }

    const double maxCoord = static_cast<double>(size);
    double dx = 0.0;
    double dy = 0.0;

    if (px < radius) {
        dx = radius - px;
    } else if (px > maxCoord - radius) {
        dx = px - (maxCoord - radius);
    }

    if (py < radius) {
        dy = radius - py;
    } else if (py > maxCoord - radius) {
        dy = py - (maxCoord - radius);
    }

    if (dx <= 0.0 || dy <= 0.0) {
        return true;
    }

    const double nx = dx / radius;
    const double ny = dy / radius;
    const double superellipse = nx * nx * nx * nx + ny * ny * ny * ny;
    return superellipse <= 1.0;
}

double PopupCoverG2MaskScale(UINT x, UINT y, UINT size, double radius) {
    constexpr int kSamplesPerAxis = 4;
    int coveredSamples = 0;
    for (int sampleY = 0; sampleY < kSamplesPerAxis; ++sampleY) {
        double py =
            static_cast<double>(y) + (static_cast<double>(sampleY) + 0.5) /
                                         static_cast<double>(kSamplesPerAxis);
        for (int sampleX = 0; sampleX < kSamplesPerAxis; ++sampleX) {
            double px = static_cast<double>(x) +
                        (static_cast<double>(sampleX) + 0.5) /
                            static_cast<double>(kSamplesPerAxis);
            if (PopupCoverG2MaskContains(px, py, size, radius)) {
                ++coveredSamples;
            }
        }
    }

    return static_cast<double>(coveredSamples) /
           static_cast<double>(kSamplesPerAxis * kSamplesPerAxis);
}

void ApplyPopupCoverG2Mask(std::vector<BYTE>& pixels, UINT size) {
    if (size == 0 || pixels.size() < static_cast<size_t>(size) * size * 4) {
        return;
    }

    constexpr double kPopupCoverG2RadiusRatio = 0.118;
    const double radius =
        std::max(1.0, static_cast<double>(size) * kPopupCoverG2RadiusRatio);
    for (UINT y = 0; y < size; ++y) {
        for (UINT x = 0; x < size; ++x) {
            double alphaScale = PopupCoverG2MaskScale(x, y, size, radius);
            if (alphaScale >= 1.0) {
                continue;
            }

            BYTE* pixel =
                pixels.data() + (static_cast<size_t>(y) * size + x) * 4;
            pixel[0] = static_cast<BYTE>(std::lround(pixel[0] * alphaScale));
            pixel[1] = static_cast<BYTE>(std::lround(pixel[1] * alphaScale));
            pixel[2] = static_cast<BYTE>(std::lround(pixel[2] * alphaScale));
            pixel[3] = static_cast<BYTE>(std::lround(pixel[3] * alphaScale));
        }
    }
}

std::vector<uint8_t> CreatePopupG2AlbumCoverBytes(
    std::vector<uint8_t> const& bytes,
    UINT size = 512) {
    std::vector<uint8_t> output;
    if (bytes.empty() || size == 0) {
        return output;
    }

    IStream* stream =
        SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size()));
    IWICImagingFactory* factory = nullptr;
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;
    IWICBitmapScaler* scaler = nullptr;
    IWICFormatConverter* converter = nullptr;

    UINT sourceWidth = 0;
    UINT sourceHeight = 0;
    HRESULT hr = stream ? S_OK : E_FAIL;
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                              CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateDecoderFromStream(
            stream, nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    }
    if (SUCCEEDED(hr)) {
        hr = decoder->GetFrame(0, &frame);
    }
    if (SUCCEEDED(hr)) {
        hr = frame->GetSize(&sourceWidth, &sourceHeight);
    }

    UINT scaledWidth = size;
    UINT scaledHeight = size;
    if (SUCCEEDED(hr) && sourceWidth > 0 && sourceHeight > 0) {
        double scale = static_cast<double>(size) /
                       static_cast<double>(std::min(sourceWidth, sourceHeight));
        scaledWidth =
            std::max(size, static_cast<UINT>(std::ceil(sourceWidth * scale)));
        scaledHeight =
            std::max(size, static_cast<UINT>(std::ceil(sourceHeight * scale)));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateBitmapScaler(&scaler);
    }
    if (SUCCEEDED(hr)) {
        hr = scaler->Initialize(frame, scaledWidth, scaledHeight,
                                WICBitmapInterpolationModeFant);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateFormatConverter(&converter);
    }
    if (SUCCEEDED(hr)) {
        hr = converter->Initialize(scaler, GUID_WICPixelFormat32bppPBGRA,
                                   WICBitmapDitherTypeNone, nullptr, 0,
                                   WICBitmapPaletteTypeCustom);
    }

    std::vector<BYTE> scaledPixels(static_cast<size_t>(scaledWidth) *
                                   scaledHeight * 4);
    if (SUCCEEDED(hr)) {
        hr = converter->CopyPixels(nullptr, scaledWidth * 4,
                                   static_cast<UINT>(scaledPixels.size()),
                                   scaledPixels.data());
    }
    if (SUCCEEDED(hr)) {
        std::vector<BYTE> pixels(static_cast<size_t>(size) * size * 4);
        UINT offsetX = (scaledWidth > size) ? (scaledWidth - size) / 2 : 0;
        UINT offsetY = (scaledHeight > size) ? (scaledHeight - size) / 2 : 0;
        for (UINT y = 0; y < size; ++y) {
            BYTE* source =
                scaledPixels.data() +
                (static_cast<size_t>(y + offsetY) * scaledWidth + offsetX) * 4;
            BYTE* target = pixels.data() + static_cast<size_t>(y) * size * 4;
            std::memcpy(target, source, static_cast<size_t>(size) * 4);
        }

        ApplyPopupCoverG2Mask(pixels, size);
        output = EncodePbgraPngBytes(size, size, pixels);
    }

    if (converter)
        converter->Release();
    if (scaler)
        scaler->Release();
    if (frame)
        frame->Release();
    if (decoder)
        decoder->Release();
    if (factory)
        factory->Release();
    if (stream)
        stream->Release();
    return output;
}

std::vector<uint8_t> CreatePlaceholderAlbumCoverBytes(
    UINT size,
    bool edgeFadeToMiddle = false,
    bool fadeFromTop = false,
    bool fadeFromRight = false) {
    if (size == 0) {
        return {};
    }

    // The generated idle cover follows the accent colour setting so a custom
    // accent also tints the no-media placeholder.
    auto accent = DefaultPopupAccentColor();
    winrt::Windows::UI::Color customAccent;
    if (CustomAccentColor(customAccent)) {
        accent = customAccent;
    }
    std::vector<BYTE> pixels(static_cast<size_t>(size) * size * 4);
    double denom = size > 1 ? static_cast<double>(size - 1) : 1.0;
    for (UINT y = 0; y < size; ++y) {
        double v = static_cast<double>(y) / denom;
        for (UINT x = 0; x < size; ++x) {
            double u = static_cast<double>(x) / denom;
            double dx = u - 0.34;
            double dy = v - 0.28;
            double glow = std::exp(-(dx * dx + dy * dy) / 0.16);
            double diagonal = 1.0 - 0.34 * v + 0.12 * u;
            double r = accent.R * (0.74 + 0.24 * glow) * diagonal + 36.0 * glow;
            double g =
                accent.G * (0.78 + 0.20 * glow) * diagonal + 28.0 * (1.0 - v);
            double b = accent.B * (0.86 + 0.14 * glow) * diagonal + 20.0 * u;

            double alphaScale = 1.0;
            if (edgeFadeToMiddle) {
                const double middle = 0.50;
                double edgeV = fadeFromRight ? u : (fadeFromTop ? 1.0 - v : v);
                alphaScale = 0.0;
                if (edgeV > middle) {
                    double amount = (edgeV - middle) / (1.0 - middle);
                    amount = Clamp(amount, 0.0, 1.0);
                    amount = amount * amount * (3.0 - 2.0 * amount);
                    alphaScale = 0.72 * amount;
                }
            }

            BYTE alpha = static_cast<BYTE>(
                std::lround(255.0 * Clamp(alphaScale, 0.0, 1.0)));
            BYTE rr = static_cast<BYTE>(
                Clamp(static_cast<int>(std::lround(r)), 0, 255));
            BYTE gg = static_cast<BYTE>(
                Clamp(static_cast<int>(std::lround(g)), 0, 255));
            BYTE bb = static_cast<BYTE>(
                Clamp(static_cast<int>(std::lround(b)), 0, 255));
            BYTE* pixel =
                pixels.data() + (static_cast<size_t>(y) * size + x) * 4;
            pixel[0] = static_cast<BYTE>(std::lround(bb * alpha / 255.0));
            pixel[1] = static_cast<BYTE>(std::lround(gg * alpha / 255.0));
            pixel[2] = static_cast<BYTE>(std::lround(rr * alpha / 255.0));
            pixel[3] = alpha;
        }
    }
    return EncodePbgraPngBytes(size, size, pixels);
}

bool GetArtworkDimensions(std::vector<uint8_t> const& bytes,
                          UINT& width,
                          UINT& height) {
    width = 0;
    height = 0;
    if (bytes.empty()) {
        return false;
    }

    IStream* stream =
        SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size()));
    IWICImagingFactory* factory = nullptr;
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;

    HRESULT hr = stream ? S_OK : E_FAIL;
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                              CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateDecoderFromStream(
            stream, nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    }
    if (SUCCEEDED(hr)) {
        hr = decoder->GetFrame(0, &frame);
    }
    if (SUCCEEDED(hr)) {
        hr = frame->GetSize(&width, &height);
    }

    if (frame)
        frame->Release();
    if (decoder)
        decoder->Release();
    if (factory)
        factory->Release();
    if (stream)
        stream->Release();
    return SUCCEEDED(hr) && width > 0 && height > 0;
}

// Reads a user-selected image file into memory. The size is capped so a huge
// file can never stall the taskbar UI thread; WIC validates the payload later.
std::vector<uint8_t> ReadImageFileBytes(std::wstring const& path) {
    std::vector<uint8_t> bytes;
    if (path.empty()) {
        return bytes;
    }

    HANDLE file =
        CreateFileW(path.c_str(), GENERIC_READ,
                    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                    nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return bytes;
    }

    LARGE_INTEGER fileSize{};
    if (GetFileSizeEx(file, &fileSize) && fileSize.QuadPart > 0 &&
        fileSize.QuadPart <= 16 * 1024 * 1024) {
        bytes.resize(static_cast<size_t>(fileSize.QuadPart));
        DWORD read = 0;
        if (!ReadFile(file, bytes.data(), static_cast<DWORD>(bytes.size()),
                      &read, nullptr) ||
            read != static_cast<DWORD>(bytes.size())) {
            bytes.clear();
        }
    }
    CloseHandle(file);
    return bytes;
}

// Loads Main.DefaultCoverImage once per path / last-write-time and validates it
// with the same WIC decoder that the artwork pipeline uses. Returns an empty
// vector when the setting is empty, the file is missing or the payload is not a
// decodable image, so callers keep the built-in placeholder in that case.
std::vector<uint8_t> LoadDefaultCoverImageBytes() {
    static std::wstring s_cachedPath;
    static ULONGLONG s_cachedWriteTime = 0;
    static std::vector<uint8_t> s_cachedBytes;

    std::wstring const& path = g_settings.defaultCoverImage;
    if (path.empty()) {
        s_cachedPath.clear();
        s_cachedWriteTime = 0;
        s_cachedBytes.clear();
        return {};
    }

    WIN32_FILE_ATTRIBUTE_DATA attributes{};
    if (!GetFileAttributesExW(path.c_str(), GetFileExInfoStandard,
                              &attributes)) {
        s_cachedPath.clear();
        s_cachedWriteTime = 0;
        s_cachedBytes.clear();
        return {};
    }

    ULONGLONG writeTime =
        (static_cast<ULONGLONG>(attributes.ftLastWriteTime.dwHighDateTime)
         << 32) |
        attributes.ftLastWriteTime.dwLowDateTime;
    if (path == s_cachedPath && writeTime == s_cachedWriteTime) {
        return s_cachedBytes;
    }

    s_cachedPath = path;
    s_cachedWriteTime = writeTime;
    s_cachedBytes = ReadImageFileBytes(path);
    if (!s_cachedBytes.empty()) {
        UINT width = 0;
        UINT height = 0;
        if (!GetArtworkDimensions(s_cachedBytes, width, height)) {
            s_cachedBytes.clear();
        }
    }
    return s_cachedBytes;
}

bool ShouldUseAbstractArtworkForDisplay(std::vector<uint8_t> const& bytes) {
    UINT width = 0;
    UINT height = 0;
    if (!GetArtworkDimensions(bytes, width, height)) {
        return false;
    }

    UINT longer = std::max(width, height);
    UINT shorter = std::min(width, height);
    if (shorter == 0) {
        return false;
    }

    double aspect = static_cast<double>(longer) / static_cast<double>(shorter);
    bool videoLikeAspect = aspect >= 1.25;
    bool lowResolution = longer < 320 || shorter < 220;

    // Only abstract low-resolution / video-like thumbnails. Typical square album
    // covers stay untouched.
    return videoLikeAspect || lowResolution;
}

winrt::Windows::UI::Color BoostArtworkColor(winrt::Windows::UI::Color color,
                                            double saturationScale,
                                            double brightnessScale) {
    double r = color.R;
    double g = color.G;
    double b = color.B;
    double luma = 0.299 * r + 0.587 * g + 0.114 * b;
    r = (luma + (r - luma) * saturationScale) * brightnessScale;
    g = (luma + (g - luma) * saturationScale) * brightnessScale;
    b = (luma + (b - luma) * saturationScale) * brightnessScale;

    auto cleanColor = [&](double minChroma, double minLuma, double maxLuma,
                          double extraSaturation, double whiteMix) {
        double gray = 0.299 * r + 0.587 * g + 0.114 * b;
        r = gray + (r - gray) * extraSaturation;
        g = gray + (g - gray) * extraSaturation;
        b = gray + (b - gray) * extraSaturation;

        double maxC = std::max({r, g, b});
        double minC = std::min({r, g, b});
        double chroma = maxC - minC;
        if (chroma < minChroma) {
            double factor =
                chroma < 1.0 ? 2.35 : std::min(2.35, minChroma / chroma);
            double g2 = 0.299 * r + 0.587 * g + 0.114 * b;
            r = g2 + (r - g2) * factor;
            g = g2 + (g - g2) * factor;
            b = g2 + (b - g2) * factor;
        }

        if (whiteMix > 0.0) {
            r = r * (1.0 - whiteMix) + 255.0 * whiteMix;
            g = g * (1.0 - whiteMix) + 255.0 * whiteMix;
            b = b * (1.0 - whiteMix) + 255.0 * whiteMix;
        }

        double lum = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        if (lum < minLuma) {
            double lift = minLuma - lum;
            r += lift * 0.88;
            g += lift * 0.88;
            b += lift * 0.88;
        } else if (lum > maxLuma) {
            double scale = maxLuma / std::max(1.0, lum);
            r *= scale;
            g *= scale;
            b *= scale;
        }
    };

    double maxBeforeClean = std::max({r, g, b});
    double minBeforeClean = std::min({r, g, b});
    double satBeforeClean =
        maxBeforeClean > 1.0
            ? (maxBeforeClean - minBeforeClean) / maxBeforeClean
            : 0.0;
    double muted = Clamp((0.34 - satBeforeClean) / 0.28, 0.0, 1.0);
    if (IsDarkModeApprox()) {
        // Dark theme: use the same adaptive idea as light mode. Muted covers get
        // a restrained clean-up rather than a fixed high-saturation boost.
        double minChroma = 34.0 + (1.0 - muted) * 26.0;
        double extraSat = 1.08 + (1.0 - muted) * 0.26;
        cleanColor(minChroma, 82.0, muted > 0.55 ? 202.0 : 226.0, extraSat,
                   0.00);
    } else {
        // Light theme: adapt to the source colorfulness. Muted covers should not
        // be forced into neon accents, but still need enough chroma to avoid a
        // dirty gray/brown look on the progress bar and generated artwork.
        double minChroma = 36.0 + (1.0 - muted) * 24.0;
        double extraSat = 1.16 + (1.0 - muted) * 0.28;
        cleanColor(minChroma, 122.0, muted > 0.55 ? 206.0 : 218.0, extraSat,
                   0.00);
    }

    return Color(color.A,
                 static_cast<BYTE>(std::clamp(std::lround(r), 0l, 255l)),
                 static_cast<BYTE>(std::clamp(std::lround(g), 0l, 255l)),
                 static_cast<BYTE>(std::clamp(std::lround(b), 0l, 255l)));
}

std::vector<uint8_t> CreateMeshGradientAlbumCoverBytes(
    std::vector<uint8_t> const& bytes) {
    if (bytes.empty()) {
        return {};
    }

    constexpr UINT kSampleSize = 14;
    constexpr UINT kOutputSize = 128;
    const UINT stride = kSampleSize * 4;
    const UINT bufferSize = stride * kSampleSize;

    IStream* stream =
        SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size()));
    IWICImagingFactory* factory = nullptr;
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;
    IWICBitmapScaler* scaler = nullptr;
    IWICFormatConverter* converter = nullptr;

    HRESULT hr = stream ? S_OK : E_FAIL;
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                              CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateDecoderFromStream(
            stream, nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    }
    if (SUCCEEDED(hr)) {
        hr = decoder->GetFrame(0, &frame);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateBitmapScaler(&scaler);
    }
    if (SUCCEEDED(hr)) {
        hr = scaler->Initialize(frame, kSampleSize, kSampleSize,
                                WICBitmapInterpolationModeFant);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateFormatConverter(&converter);
    }
    if (SUCCEEDED(hr)) {
        hr = converter->Initialize(scaler, GUID_WICPixelFormat32bppPBGRA,
                                   WICBitmapDitherTypeNone, nullptr, 0,
                                   WICBitmapPaletteTypeCustom);
    }

    std::vector<BYTE> sample(bufferSize);
    if (SUCCEEDED(hr)) {
        hr = converter->CopyPixels(nullptr, stride, bufferSize, sample.data());
    }
    if (FAILED(hr)) {
        if (converter)
            converter->Release();
        if (scaler)
            scaler->Release();
        if (frame)
            frame->Release();
        if (decoder)
            decoder->Release();
        if (factory)
            factory->Release();
        if (stream)
            stream->Release();
        return {};
    }

    auto averageRectColor = [&](int x0, int y0, int x1,
                                int y1) -> winrt::Windows::UI::Color {
        long sumB = 0, sumG = 0, sumR = 0, sumA = 0, count = 0;
        x0 = std::clamp(x0, 0, static_cast<int>(kSampleSize) - 1);
        y0 = std::clamp(y0, 0, static_cast<int>(kSampleSize) - 1);
        x1 = std::clamp(x1, x0 + 1, static_cast<int>(kSampleSize));
        y1 = std::clamp(y1, y0 + 1, static_cast<int>(kSampleSize));
        for (int y = y0; y < y1; ++y) {
            for (int x = x0; x < x1; ++x) {
                BYTE* pixel = sample.data() +
                              (static_cast<size_t>(y) * kSampleSize + x) * 4;
                auto color = ColorFromPbgra(pixel);
                if (color.A == 0) {
                    continue;
                }
                sumB += color.B;
                sumG += color.G;
                sumR += color.R;
                sumA += color.A;
                ++count;
            }
        }
        if (count <= 0) {
            return DefaultPopupAccentColor();
        }
        winrt::Windows::UI::Color c = Color(
            static_cast<BYTE>(sumA / count), static_cast<BYTE>(sumR / count),
            static_cast<BYTE>(sumG / count), static_cast<BYTE>(sumB / count));
        return BoostArtworkColor(c, 1.18, 1.04);
    };

    struct SalientSample {
        winrt::Windows::UI::Color color = DefaultPopupAccentColor();
        float x = 0.72f;
        float y = 0.30f;
        double score = -1.0;
    };

    SalientSample salient;
    for (UINT y = 0; y < kSampleSize; ++y) {
        for (UINT x = 0; x < kSampleSize; ++x) {
            BYTE* pixel =
                sample.data() + (static_cast<size_t>(y) * kSampleSize + x) * 4;
            auto color = ColorFromPbgra(pixel);
            if (color.A == 0) {
                continue;
            }
            double b = color.B;
            double g = color.G;
            double r = color.R;
            double maxChannel = std::max({r, g, b});
            double minChannel = std::min({r, g, b});
            double chroma = maxChannel - minChannel;
            double saturation = maxChannel > 1.0 ? chroma / maxChannel : 0.0;
            double luma = 0.299 * r + 0.587 * g + 0.114 * b;

            // Pick a visible accent, not merely the largest-area color. Favor
            // saturated mid/high-luma colors and de-emphasize black/white UI
            // chrome that can appear in video thumbnails.
            double lumaWindow = 1.0 - std::abs(luma - 145.0) / 145.0;
            lumaWindow = Clamp(lumaWindow, 0.0, 1.0);
            double score = saturation * saturation *
                           (0.45 + 0.55 * lumaWindow) *
                           (0.40 + 0.60 * (chroma / 255.0));
            if (score > salient.score) {
                salient.score = score;
                salient.color = BoostArtworkColor(color, 1.48, 1.08);
                salient.x = kSampleSize > 1
                                ? static_cast<float>(x) / (kSampleSize - 1)
                                : 0.72f;
                salient.y = kSampleSize > 1
                                ? static_cast<float>(y) / (kSampleSize - 1)
                                : 0.30f;
            }
        }
    }

    // Keep a stable highlight position even if the salient sample is near an edge.
    salient.x = std::clamp(salient.x, 0.18f, 0.82f);
    salient.y = std::clamp(salient.y, 0.16f, 0.78f);

    std::array<winrt::Windows::UI::Color, 6> palette{
        averageRectColor(0, 0, 5, 5),   averageRectColor(9, 0, 14, 5),
        averageRectColor(0, 9, 5, 14),  averageRectColor(9, 9, 14, 14),
        averageRectColor(3, 3, 11, 11), salient.color,
    };

    std::array<winrt::Windows::Foundation::Numerics::float2, 6> points{{
        {0.16f, 0.18f},
        {0.84f, 0.16f},
        {0.18f, 0.82f},
        {0.82f, 0.84f},
        {0.50f, 0.50f},
        {salient.x, salient.y},
    }};
    std::array<float, 6> sigma{{0.34f, 0.34f, 0.34f, 0.34f, 0.42f, 0.16f}};
    std::array<float, 6> weightBoost{{1.0f, 1.0f, 1.0f, 1.0f, 0.92f, 2.25f}};

    std::vector<BYTE> outputPixels(static_cast<size_t>(kOutputSize) *
                                   kOutputSize * 4);
    for (UINT y = 0; y < kOutputSize; ++y) {
        float fy =
            kOutputSize > 1 ? static_cast<float>(y) / (kOutputSize - 1) : 0.0f;
        for (UINT x = 0; x < kOutputSize; ++x) {
            float fx = kOutputSize > 1
                           ? static_cast<float>(x) / (kOutputSize - 1)
                           : 0.0f;
            double sumW = 0.0;
            double sumR = 0.0, sumG = 0.0, sumB = 0.0;
            for (size_t i = 0; i < points.size(); ++i) {
                float dx = fx - points[i].x;
                float dy = fy - points[i].y;
                float s = sigma[i];
                double w = std::exp(-static_cast<double>(dx * dx + dy * dy) /
                                    static_cast<double>(2.0f * s * s));
                w *= weightBoost[i];
                sumW += w;
                sumR += palette[i].R * w;
                sumG += palette[i].G * w;
                sumB += palette[i].B * w;
            }
            if (sumW <= 0.0)
                sumW = 1.0;
            double r = sumR / sumW;
            double g = sumG / sumW;
            double b = sumB / sumW;

            // Add an asymmetric accent orb: one side is denser / more solid,
            // while the opposite side diffuses into a softer bloom. This keeps
            // the salient accent color visible without turning the artwork into
            // a single flat gradient ball.
            double dirX = salient.x - 0.5;
            double dirY = salient.y - 0.5;
            double dirLen = std::sqrt(dirX * dirX + dirY * dirY);
            if (dirLen < 1e-4) {
                dirX = 0.78;
                dirY = -0.22;
                dirLen = std::sqrt(dirX * dirX + dirY * dirY);
            }
            dirX /= dirLen;
            dirY /= dirLen;
            double perpX = -dirY;
            double perpY = dirX;

            auto gaussianAniso = [&](double px, double py, double cx, double cy,
                                     double sigmaAlong,
                                     double sigmaAcross) -> double {
                double dx = px - cx;
                double dy = py - cy;
                double along = dx * dirX + dy * dirY;
                double across = dx * perpX + dy * perpY;
                double value =
                    (along * along) / (2.0 * sigmaAlong * sigmaAlong) +
                    (across * across) / (2.0 * sigmaAcross * sigmaAcross);
                return std::exp(-value);
            };

            double coreCx = salient.x + dirX * 0.020;
            double coreCy = salient.y + dirY * 0.020;
            double tailCx = salient.x - dirX * 0.060;
            double tailCy = salient.y - dirY * 0.060;
            double core = gaussianAniso(fx, fy, coreCx, coreCy, 0.060, 0.070);
            double tail = gaussianAniso(fx, fy, tailCx, tailCy, 0.170, 0.115);
            double rim = gaussianAniso(fx, fy, salient.x + dirX * 0.006,
                                       salient.y + dirY * 0.006, 0.038, 0.050);

            // Solid side: stronger local color injection plus a subtle specular lift.
            double solidMix = 0.40 * core + 0.16 * rim;
            // Soft side: broader low-contrast bloom using a lighter version.
            winrt::Windows::UI::Color softColor =
                BoostArtworkColor(salient.color, 1.08, 1.18);
            double softMix = 0.20 * tail;

            r = r * (1.0 - solidMix) + salient.color.R * solidMix;
            g = g * (1.0 - solidMix) + salient.color.G * solidMix;
            b = b * (1.0 - solidMix) + salient.color.B * solidMix;

            r = r * (1.0 - softMix) + softColor.R * softMix;
            g = g * (1.0 - softMix) + softColor.G * softMix;
            b = b * (1.0 - softMix) + softColor.B * softMix;

            // A small highlight sheen on the solid side adds contrast / texture.
            double sheen = 0.10 * core + 0.05 * rim;
            r = r * (1.0 - sheen) + 255.0 * sheen;
            g = g * (1.0 - sheen) + 255.0 * sheen;
            b = b * (1.0 - sheen) + 255.0 * sheen;

            // subtle brighten toward the center for a soft artwork-card glow
            double cx = (fx - 0.5) * 2.0;
            double cy = (fy - 0.5) * 2.0;
            double radial =
                std::clamp(1.0 - std::sqrt(cx * cx + cy * cy), 0.0, 1.0);
            double lift = 1.0 + radial * 0.07;
            size_t idx = (static_cast<size_t>(y) * kOutputSize + x) * 4;
            outputPixels[idx + 0] =
                static_cast<BYTE>(std::clamp(std::lround(b * lift), 0l, 255l));
            outputPixels[idx + 1] =
                static_cast<BYTE>(std::clamp(std::lround(g * lift), 0l, 255l));
            outputPixels[idx + 2] =
                static_cast<BYTE>(std::clamp(std::lround(r * lift), 0l, 255l));
            outputPixels[idx + 3] = 255;
        }
    }

    if (converter)
        converter->Release();
    if (scaler)
        scaler->Release();
    if (frame)
        frame->Release();
    if (decoder)
        decoder->Release();
    if (factory)
        factory->Release();
    if (stream)
        stream->Release();

    return EncodePbgraPngBytes(kOutputSize, kOutputSize, outputPixels);
}

struct AdaptiveArtworkPalette {
    winrt::Windows::UI::Color tl = DefaultPopupAccentColor();
    winrt::Windows::UI::Color tr = DefaultPopupAccentColor();
    winrt::Windows::UI::Color bl = DefaultPopupAccentColor();
    winrt::Windows::UI::Color br = DefaultPopupAccentColor();
    winrt::Windows::UI::Color center = DefaultPopupAccentColor();
    winrt::Windows::UI::Color bg = DefaultPopupAccentColor();
    winrt::Windows::UI::Color dark = Color(255, 32, 32, 40);
    winrt::Windows::UI::Color accent = DefaultPopupAccentColor();
    winrt::Windows::UI::Color accentSoft = DefaultPopupAccentColor();
    winrt::Windows::UI::Color bright = Color(255, 255, 240, 190);
    float accentX = 0.68f;
    float accentY = 0.32f;
};

struct RenderColorD {
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
};

RenderColorD ToRenderColor(winrt::Windows::UI::Color const& c) {
    return {static_cast<double>(c.R), static_cast<double>(c.G),
            static_cast<double>(c.B)};
}

void BlendRenderColor(RenderColorD& base,
                      winrt::Windows::UI::Color const& color,
                      double alpha) {
    alpha = Clamp(alpha, 0.0, 1.0);
    base.r = base.r * (1.0 - alpha) + color.R * alpha;
    base.g = base.g * (1.0 - alpha) + color.G * alpha;
    base.b = base.b * (1.0 - alpha) + color.B * alpha;
}

winrt::Windows::UI::Color LerpArtworkColor(winrt::Windows::UI::Color const& a,
                                           winrt::Windows::UI::Color const& b,
                                           double t) {
    t = Clamp(t, 0.0, 1.0);
    auto L = [&](BYTE av, BYTE bv) -> BYTE {
        return static_cast<BYTE>(
            std::clamp(std::lround(av * (1.0 - t) + bv * t), 0l, 255l));
    };
    return Color(255, L(a.R, b.R), L(a.G, b.G), L(a.B, b.B));
}

bool ExtractAdaptiveArtworkPalette(std::vector<uint8_t> const& bytes,
                                   AdaptiveArtworkPalette& out) {
    constexpr UINT kSampleSize = 14;
    const UINT stride = kSampleSize * 4;
    const UINT bufferSize = stride * kSampleSize;

    IStream* stream =
        SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size()));
    IWICImagingFactory* factory = nullptr;
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;
    IWICBitmapScaler* scaler = nullptr;
    IWICFormatConverter* converter = nullptr;

    HRESULT hr = stream ? S_OK : E_FAIL;
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                              CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateDecoderFromStream(
            stream, nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    }
    if (SUCCEEDED(hr)) {
        hr = decoder->GetFrame(0, &frame);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateBitmapScaler(&scaler);
    }
    if (SUCCEEDED(hr)) {
        hr = scaler->Initialize(frame, kSampleSize, kSampleSize,
                                WICBitmapInterpolationModeFant);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateFormatConverter(&converter);
    }
    if (SUCCEEDED(hr)) {
        hr = converter->Initialize(scaler, GUID_WICPixelFormat32bppPBGRA,
                                   WICBitmapDitherTypeNone, nullptr, 0,
                                   WICBitmapPaletteTypeCustom);
    }

    std::vector<BYTE> sample(bufferSize);
    if (SUCCEEDED(hr)) {
        hr = converter->CopyPixels(nullptr, stride, bufferSize, sample.data());
    }
    if (FAILED(hr)) {
        if (converter)
            converter->Release();
        if (scaler)
            scaler->Release();
        if (frame)
            frame->Release();
        if (decoder)
            decoder->Release();
        if (factory)
            factory->Release();
        if (stream)
            stream->Release();
        return false;
    }

    auto averageRectColor =
        [&](int x0, int y0, int x1, int y1, double sat = 1.14,
            double bri = 1.03) -> winrt::Windows::UI::Color {
        long sumB = 0, sumG = 0, sumR = 0, sumA = 0, count = 0;
        x0 = std::clamp(x0, 0, static_cast<int>(kSampleSize) - 1);
        y0 = std::clamp(y0, 0, static_cast<int>(kSampleSize) - 1);
        x1 = std::clamp(x1, x0 + 1, static_cast<int>(kSampleSize));
        y1 = std::clamp(y1, y0 + 1, static_cast<int>(kSampleSize));
        for (int y = y0; y < y1; ++y) {
            for (int x = x0; x < x1; ++x) {
                BYTE* pixel = sample.data() +
                              (static_cast<size_t>(y) * kSampleSize + x) * 4;
                auto color = ColorFromPbgra(pixel);
                if (color.A == 0) {
                    continue;
                }
                sumB += color.B;
                sumG += color.G;
                sumR += color.R;
                sumA += color.A;
                ++count;
            }
        }
        if (count <= 0) {
            return DefaultPopupAccentColor();
        }
        return BoostArtworkColor(Color(static_cast<BYTE>(sumA / count),
                                       static_cast<BYTE>(sumR / count),
                                       static_cast<BYTE>(sumG / count),
                                       static_cast<BYTE>(sumB / count)),
                                 sat, bri);
    };

    out.tl = averageRectColor(0, 0, 5, 5, 1.08, 1.01);
    out.tr = averageRectColor(9, 0, 14, 5, 1.08, 1.01);
    out.bl = averageRectColor(0, 9, 5, 14, 1.08, 1.00);
    out.br = averageRectColor(9, 9, 14, 14, 1.08, 1.00);
    out.center = averageRectColor(3, 3, 11, 11, 1.10, 1.03);
    out.bg = averageRectColor(0, 0, 14, 14, 1.05, 0.98);
    out.dark = averageRectColor(2, 2, 12, 12, 0.96, 0.72);

    double bestScore = -1.0;
    for (UINT y = 0; y < kSampleSize; ++y) {
        for (UINT x = 0; x < kSampleSize; ++x) {
            BYTE* pixel =
                sample.data() + (static_cast<size_t>(y) * kSampleSize + x) * 4;
            auto color = ColorFromPbgra(pixel);
            if (color.A == 0) {
                continue;
            }
            double b = color.B;
            double g = color.G;
            double r = color.R;
            double maxChannel = std::max({r, g, b});
            double minChannel = std::min({r, g, b});
            double chroma = maxChannel - minChannel;
            double saturation = maxChannel > 1.0 ? chroma / maxChannel : 0.0;
            double luma = 0.299 * r + 0.587 * g + 0.114 * b;
            double lumaWindow = 1.0 - std::abs(luma - 150.0) / 150.0;
            lumaWindow = Clamp(lumaWindow, 0.0, 1.0);
            double score = saturation * saturation *
                           (0.42 + 0.58 * lumaWindow) *
                           (0.40 + 0.60 * (chroma / 255.0));
            if (score > bestScore) {
                bestScore = score;
                out.accent = BoostArtworkColor(color, 1.46, 1.08);
                out.accentX = kSampleSize > 1
                                  ? static_cast<float>(x) / (kSampleSize - 1)
                                  : 0.68f;
                out.accentY = kSampleSize > 1
                                  ? static_cast<float>(y) / (kSampleSize - 1)
                                  : 0.32f;
            }
        }
    }
    out.accentX = std::clamp(out.accentX, 0.18f, 0.84f);
    out.accentY = std::clamp(out.accentY, 0.16f, 0.82f);
    out.accentSoft = BoostArtworkColor(out.accent, 1.08, 1.16);
    out.bright = BoostArtworkColor(
        LerpArtworkColor(out.accent, Color(255, 255, 245, 200), 0.42), 1.02,
        1.14);

    if (converter)
        converter->Release();
    if (scaler)
        scaler->Release();
    if (frame)
        frame->Release();
    if (decoder)
        decoder->Release();
    if (factory)
        factory->Release();
    if (stream)
        stream->Release();
    return true;
}

double GaussianBlobWeight(double fx,
                          double fy,
                          double cx,
                          double cy,
                          double sx,
                          double sy,
                          double rot = 0.0) {
    double dx = fx - cx;
    double dy = fy - cy;
    double cr = std::cos(rot);
    double sr = std::sin(rot);
    double rx = dx * cr + dy * sr;
    double ry = -dx * sr + dy * cr;
    return std::exp(
        -((rx * rx) / (2.0 * sx * sx) + (ry * ry) / (2.0 * sy * sy)));
}

double DiagonalBeamWeight(double fx,
                          double fy,
                          double cx,
                          double cy,
                          double rot,
                          double sx,
                          double sy) {
    return GaussianBlobWeight(fx, fy, cx, cy, sx, sy, rot);
}

double RibbonWeight(double fx,
                    double fy,
                    double yBase,
                    double amp,
                    double freq,
                    double phase,
                    double tilt,
                    double sigma) {
    double y = yBase + amp * std::sin((fx * freq + phase) * 6.28318530718) +
               tilt * (fx - 0.5);
    double d = fy - y;
    return std::exp(-(d * d) / (2.0 * sigma * sigma));
}

std::vector<uint8_t> RenderAdaptiveArtworkTemplate(
    AdaptiveArtworkPalette const& pal,
    std::function<void(double, double, RenderColorD&)> const& shader,
    UINT outputSize = 128) {
    std::vector<BYTE> out(static_cast<size_t>(outputSize) * outputSize * 4);
    for (UINT y = 0; y < outputSize; ++y) {
        double fy =
            outputSize > 1 ? static_cast<double>(y) / (outputSize - 1) : 0.0;
        for (UINT x = 0; x < outputSize; ++x) {
            double fx = outputSize > 1
                            ? static_cast<double>(x) / (outputSize - 1)
                            : 0.0;
            RenderColorD color = ToRenderColor(pal.bg);
            shader(fx, fy, color);
            // subtle top light and bottom vignette, similar to the HTML preview
            double topLight = (1.0 - fy) * 0.05;
            double bottomShade = fy * 0.14;
            color.r = std::clamp(
                color.r * (1.0 - bottomShade) + 255.0 * topLight, 0.0, 255.0);
            color.g = std::clamp(
                color.g * (1.0 - bottomShade) + 255.0 * topLight, 0.0, 255.0);
            color.b = std::clamp(
                color.b * (1.0 - bottomShade) + 255.0 * topLight, 0.0, 255.0);
            size_t idx = (static_cast<size_t>(y) * outputSize + x) * 4;
            out[idx + 0] =
                static_cast<BYTE>(std::clamp(std::lround(color.b), 0l, 255l));
            out[idx + 1] =
                static_cast<BYTE>(std::clamp(std::lround(color.g), 0l, 255l));
            out[idx + 2] =
                static_cast<BYTE>(std::clamp(std::lround(color.r), 0l, 255l));
            out[idx + 3] = 255;
        }
    }
    return EncodePbgraPngBytes(outputSize, outputSize, out);
}

std::vector<uint8_t> CreateEnergyFlameAlbumCoverBytes(
    std::vector<uint8_t> const& bytes) {
    AdaptiveArtworkPalette pal;
    if (!ExtractAdaptiveArtworkPalette(bytes, pal)) {
        return {};
    }
    auto warm = LerpArtworkColor(pal.accent, pal.center, 0.20);
    auto golden = BoostArtworkColor(
        LerpArtworkColor(pal.accent, Color(255, 255, 215, 70), 0.56), 1.10,
        1.10);
    return RenderAdaptiveArtworkTemplate(pal, [&](double fx, double fy,
                                                  RenderColorD& c) {
        auto top = LerpArtworkColor(pal.tl, warm, 0.48);
        auto bottom = LerpArtworkColor(pal.bl, pal.dark, 0.42);
        BlendRenderColor(c, LerpArtworkColor(bottom, top, 1.0 - fy), 1.0);
        BlendRenderColor(
            c, warm,
            0.28 * GaussianBlobWeight(fx, fy, 0.38, 0.34, 0.38, 0.26, -0.20));
        BlendRenderColor(
            c, pal.dark,
            0.26 * GaussianBlobWeight(fx, fy, 0.18, 0.78, 0.58, 0.28, 0.18));
        BlendRenderColor(
            c, golden,
            0.82 * GaussianBlobWeight(fx, fy, 0.55, 0.16, 0.14, 0.18, 0.46));
        BlendRenderColor(
            c, golden,
            0.38 * DiagonalBeamWeight(fx, fy, 0.58, 0.20, -0.72, 0.22, 0.08));
        BlendRenderColor(
            c, pal.accent,
            0.22 * RibbonWeight(fx, fy, 0.18, 0.03, 1.02, 0.22, 0.12, 0.08));
    });
}

std::vector<uint8_t> CreateDisplayAlbumCoverBytes(
    std::vector<uint8_t> const& bytes,
    std::wstring const& sourceAppUserModelId) {
    if (bytes.empty()) {
        return {};
    }

    bool browserSource = LooksLikeBrowserMediaSource(sourceAppUserModelId);
    if (!browserSource || !ShouldUseAbstractArtworkForDisplay(bytes) ||
        g_settings.artworkAbstractMode == L"browser_original" ||
        g_settings.artworkAbstractMode == L"off") {
        return bytes;
    }

    std::vector<uint8_t> abstractBytes;
    if (g_settings.artworkAbstractMode == L"energy_flame") {
        abstractBytes = CreateEnergyFlameAlbumCoverBytes(bytes);
    } else if (g_settings.artworkAbstractMode == L"mesh_gradient") {
        abstractBytes = CreateMeshGradientAlbumCoverBytes(bytes);
    }
    return abstractBytes.empty() ? bytes : abstractBytes;
}

// Abstract artwork (energy flame / mesh gradient) is expensive to generate:
// it renders a full 512x512 PNG from the palette. The compact island and
// popup refresh multiple times per second, so cache by thumbnail hash +
// source + mode. Only ever called from the taskbar UI thread.
std::vector<uint8_t> CreateDisplayAlbumCoverBytesCached(
    std::vector<uint8_t> const& bytes,
    std::wstring const& sourceAppUserModelId) {
    if (bytes.empty()) {
        return {};
    }

    uint64_t hash = ThumbnailHash(bytes);
    static uint64_t s_lastHash = 0;
    static std::wstring s_lastSource;
    static std::wstring s_lastMode;
    static std::vector<uint8_t> s_lastResult;

    if (hash != 0 && hash == s_lastHash &&
        s_lastSource == sourceAppUserModelId &&
        s_lastMode == g_settings.artworkAbstractMode && !s_lastResult.empty()) {
        return s_lastResult;
    }

    s_lastHash = hash;
    s_lastSource = sourceAppUserModelId;
    s_lastMode = g_settings.artworkAbstractMode;
    s_lastResult = CreateDisplayAlbumCoverBytes(bytes, sourceAppUserModelId);
    return s_lastResult;
}

winrt::Windows::UI::Color ExtractAlbumAccentColor(
    std::vector<uint8_t> const& bytes) {
    if (bytes.empty()) {
        return DefaultPopupAccentColor();
    }

    constexpr UINT kAccentSampleSize = 10;
    const UINT stride = kAccentSampleSize * 4;
    const UINT bufferSize = stride * kAccentSampleSize;

    IStream* stream =
        SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size()));
    IWICImagingFactory* factory = nullptr;
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;
    IWICBitmapScaler* scaler = nullptr;
    IWICFormatConverter* converter = nullptr;

    HRESULT hr = stream ? S_OK : E_FAIL;
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                              CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateDecoderFromStream(
            stream, nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    }
    if (SUCCEEDED(hr)) {
        hr = decoder->GetFrame(0, &frame);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateBitmapScaler(&scaler);
    }
    if (SUCCEEDED(hr)) {
        hr = scaler->Initialize(frame, kAccentSampleSize, kAccentSampleSize,
                                WICBitmapInterpolationModeFant);
    }
    if (SUCCEEDED(hr)) {
        hr = factory->CreateFormatConverter(&converter);
    }
    if (SUCCEEDED(hr)) {
        hr = converter->Initialize(scaler, GUID_WICPixelFormat32bppPBGRA,
                                   WICBitmapDitherTypeNone, nullptr, 0,
                                   WICBitmapPaletteTypeCustom);
    }

    std::vector<BYTE> pixels(bufferSize);
    if (SUCCEEDED(hr)) {
        hr = converter->CopyPixels(nullptr, stride, bufferSize, pixels.data());
    }

    double sumR = 0.0;
    double sumG = 0.0;
    double sumB = 0.0;
    double weightSum = 0.0;
    double sourceSaturationSum = 0.0;
    double sourceChromaSum = 0.0;
    if (SUCCEEDED(hr)) {
        for (UINT y = 0; y < kAccentSampleSize; ++y) {
            for (UINT x = 0; x < kAccentSampleSize; ++x) {
                BYTE* pixel =
                    pixels.data() +
                    (static_cast<size_t>(y) * kAccentSampleSize + x) * 4;
                double a = pixel[3] / 255.0;
                if (a < 0.05) {
                    continue;
                }
                double b = pixel[0] / std::max(a, 0.01);
                double g = pixel[1] / std::max(a, 0.01);
                double r = pixel[2] / std::max(a, 0.01);
                r = Clamp(r, 0.0, 255.0);
                g = Clamp(g, 0.0, 255.0);
                b = Clamp(b, 0.0, 255.0);
                double maxChannel = std::max({r, g, b});
                double minChannel = std::min({r, g, b});
                double chroma = maxChannel - minChannel;
                double saturation =
                    maxChannel > 1.0 ? chroma / maxChannel : 0.0;
                double saturationWeight = 0.65 + chroma / 255.0;
                double weight = a * saturationWeight;
                sumR += r * weight;
                sumG += g * weight;
                sumB += b * weight;
                sourceSaturationSum += saturation * weight;
                sourceChromaSum += chroma * weight;
                weightSum += weight;
            }
        }
    }

    if (converter)
        converter->Release();
    if (scaler)
        scaler->Release();
    if (frame)
        frame->Release();
    if (decoder)
        decoder->Release();
    if (factory)
        factory->Release();
    if (stream)
        stream->Release();

    if (FAILED(hr) || weightSum <= 0.0) {
        return DefaultPopupAccentColor();
    }

    double sourceAvgSaturation =
        Clamp(sourceSaturationSum / weightSum, 0.0, 1.0);
    double sourceAvgChroma = Clamp(sourceChromaSum / weightSum, 0.0, 255.0);
    double r = sumR / weightSum;
    double g = sumG / weightSum;
    double b = sumB / weightSum;
    double gray = 0.299 * r + 0.587 * g + 0.114 * b;
    double mutedSource = Clamp((0.38 - sourceAvgSaturation) / 0.32, 0.0, 1.0);
    double kSaturationBoost = IsDarkModeApprox()
                                  ? 1.08 + (1.0 - mutedSource) * 0.24
                                  : 1.10 + (1.0 - mutedSource) * 0.20;
    r = gray + (r - gray) * kSaturationBoost;
    g = gray + (g - gray) * kSaturationBoost;
    b = gray + (b - gray) * kSaturationBoost;

    double lum = 0.2126 * r + 0.7152 * g + 0.0722 * b;
    if (lum < 82.0) {
        double lift = 82.0 - lum;
        r += lift * 0.70;
        g += lift * 0.70;
        b += lift * 0.70;
    } else if (lum > 214.0) {
        double scale = 214.0 / lum;
        r *= scale;
        g *= scale;
        b *= scale;
    }

    if (IsDarkModeApprox()) {
        // Dark theme now follows the same source-aware logic as light mode:
        // clean enough to be visible on a dark surface, but avoid neon accents
        // when the cover itself is globally muted.
        double gray2 = 0.299 * r + 0.587 * g + 0.114 * b;
        double sourceColorfulness =
            Clamp((sourceAvgSaturation - 0.16) / 0.44, 0.0, 1.0);
        double extraSat = 1.08 + sourceColorfulness * 0.30;
        r = gray2 + (r - gray2) * extraSat;
        g = gray2 + (g - gray2) * extraSat;
        b = gray2 + (b - gray2) * extraSat;

        double maxC = std::max({r, g, b});
        double minC = std::min({r, g, b});
        double chroma = maxC - minC;
        double minChroma = 34.0 + sourceColorfulness * 28.0;
        if (sourceAvgChroma < 26.0) {
            minChroma = std::min(minChroma, 38.0);
        }
        if (chroma < minChroma) {
            double maxFactor = 1.50 + sourceColorfulness * 0.80;
            double factor = chroma < 1.0
                                ? maxFactor
                                : std::min(maxFactor, minChroma / chroma);
            double g2 = 0.299 * r + 0.587 * g + 0.114 * b;
            r = g2 + (r - g2) * factor;
            g = g2 + (g - g2) * factor;
            b = g2 + (b - g2) * factor;
        }

        double lum2 = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        double minLuma = 88.0 + sourceColorfulness * 8.0;
        double maxLuma = 202.0 + sourceColorfulness * 22.0;
        if (lum2 < minLuma) {
            double lift = minLuma - lum2;
            r += lift * 0.68;
            g += lift * 0.68;
            b += lift * 0.68;
        } else if (lum2 > maxLuma) {
            double scale = maxLuma / std::max(1.0, lum2);
            r *= scale;
            g *= scale;
            b *= scale;
        }
    } else {
        // Light theme accent: avoid the dirty gray left edge, but keep muted
        // covers muted. Use only a gentle chroma floor for low-saturation
        // artwork, and reserve stronger saturation for already-colorful covers.
        double gray2 = 0.299 * r + 0.587 * g + 0.114 * b;
        double sourceColorfulness =
            Clamp((sourceAvgSaturation - 0.18) / 0.42, 0.0, 1.0);
        double extraSat = 1.10 + sourceColorfulness * 0.30;
        r = gray2 + (r - gray2) * extraSat;
        g = gray2 + (g - gray2) * extraSat;
        b = gray2 + (b - gray2) * extraSat;

        double maxC = std::max({r, g, b});
        double minC = std::min({r, g, b});
        double chroma = maxC - minC;
        double minChroma = 30.0 + sourceColorfulness * 30.0;
        if (sourceAvgChroma < 26.0) {
            minChroma = std::min(minChroma, 34.0);
        }
        if (chroma < minChroma) {
            double maxFactor = 1.45 + sourceColorfulness * 0.75;
            double factor = chroma < 1.0
                                ? maxFactor
                                : std::min(maxFactor, minChroma / chroma);
            double g2 = 0.299 * r + 0.587 * g + 0.114 * b;
            r = g2 + (r - g2) * factor;
            g = g2 + (g - g2) * factor;
            b = g2 + (b - g2) * factor;
        }

        double lum2 = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        double minLuma = 118.0 - sourceColorfulness * 8.0;
        double maxLuma = 170.0 + sourceColorfulness * 8.0;
        if (lum2 < minLuma) {
            double lift = minLuma - lum2;
            r += lift * 0.58;
            g += lift * 0.58;
            b += lift * 0.58;
        } else if (lum2 > maxLuma) {
            double scale = maxLuma / std::max(1.0, lum2);
            r *= scale;
            g *= scale;
            b *= scale;
        }
    }

    return Color(
        0xFF,
        static_cast<BYTE>(Clamp(static_cast<int>(std::lround(r)), 0, 255)),
        static_cast<BYTE>(Clamp(static_cast<int>(std::lround(g)), 0, 255)),
        static_cast<BYTE>(Clamp(static_cast<int>(std::lround(b)), 0, 255)));
}

// ===== Popup design system =====
winrt::Windows::UI::Color LerpColor(winrt::Windows::UI::Color const& from,
                                    winrt::Windows::UI::Color const& to,
                                    double progress) {
    progress = Clamp(progress, 0.0, 1.0);
    auto lerpByte = [progress](BYTE a, BYTE b) -> BYTE {
        return static_cast<BYTE>(Clamp(
            static_cast<int>(std::lround(
                static_cast<double>(a) +
                (static_cast<double>(b) - static_cast<double>(a)) * progress)),
            0, 255));
    };
    return Color(lerpByte(from.A, to.A), lerpByte(from.R, to.R),
                 lerpByte(from.G, to.G), lerpByte(from.B, to.B));
}

winrt::Windows::UI::Color PopupTargetAccentColor() {
    winrt::Windows::UI::Color custom;
    if (CustomAccentColor(custom)) {
        return custom;
    }
    return g_popupAccentColorValid ? g_popupAccentColor
                                   : DefaultPopupAccentColor();
}

winrt::Windows::UI::Color PopupAccentColor() {
    // A valid custom accent is authoritative: the compact bars, the popup
    // playback indicator and every accent-derived progress layer use it
    // directly instead of the artwork palette.
    winrt::Windows::UI::Color custom;
    if (CustomAccentColor(custom)) {
        return custom;
    }
    return g_popupDisplayedAccentColorValid ? g_popupDisplayedAccentColor
                                            : PopupTargetAccentColor();
}

double Clamp01(double v) {
    return Clamp(v, 0.0, 1.0);
}

winrt::Windows::UI::Color ColorFromHsv(double h,
                                       double s,
                                       double v,
                                       BYTE a = 0xFF) {
    h = std::fmod(h, 360.0);
    if (h < 0.0)
        h += 360.0;
    s = Clamp01(s);
    v = Clamp01(v);
    double c = v * s;
    double x = c * (1.0 - std::abs(std::fmod(h / 60.0, 2.0) - 1.0));
    double m = v - c;
    double r = 0.0, g = 0.0, b = 0.0;
    if (h < 60.0) {
        r = c;
        g = x;
    } else if (h < 120.0) {
        r = x;
        g = c;
    } else if (h < 180.0) {
        g = c;
        b = x;
    } else if (h < 240.0) {
        g = x;
        b = c;
    } else if (h < 300.0) {
        r = x;
        b = c;
    } else {
        r = c;
        b = x;
    }
    return Color(
        a,
        static_cast<BYTE>(std::clamp(std::lround((r + m) * 255.0), 0l, 255l)),
        static_cast<BYTE>(std::clamp(std::lround((g + m) * 255.0), 0l, 255l)),
        static_cast<BYTE>(std::clamp(std::lround((b + m) * 255.0), 0l, 255l)));
}

void ColorToHsv(winrt::Windows::UI::Color const& color,
                double& h,
                double& s,
                double& v) {
    double r = color.R / 255.0;
    double g = color.G / 255.0;
    double b = color.B / 255.0;
    double maxv = std::max({r, g, b});
    double minv = std::min({r, g, b});
    double delta = maxv - minv;
    h = 0.0;
    if (delta > 1e-6) {
        if (maxv == r)
            h = 60.0 * std::fmod(((g - b) / delta), 6.0);
        else if (maxv == g)
            h = 60.0 * (((b - r) / delta) + 2.0);
        else
            h = 60.0 * (((r - g) / delta) + 4.0);
    }
    if (h < 0.0)
        h += 360.0;
    s = maxv <= 1e-6 ? 0.0 : delta / maxv;
    v = maxv;
}

winrt::Windows::UI::Color PopupProgressCleanStartColor() {
    double h, s, v;
    ColorToHsv(PopupAccentColor(), h, s, v);
    bool dark = IsDarkModeApprox();

    // The left edge uses the raw accent hue, but is cleaned in HSV space so it
    // doesn't become a gray/brown strip. If the cover is muted, keep saturation
    // moderate instead of forcing a neon color.
    double muted = Clamp((0.38 - s) / 0.32, 0.0, 1.0);
    double targetS;
    double targetV;
    if (dark) {
        targetS = muted > 0.0 ? Clamp(s * 1.10 + 0.08, 0.30, 0.52)
                              : Clamp(s * 1.04, 0.48, 0.76);
        targetV = muted > 0.0 ? Clamp(v + 0.08, 0.58, 0.76)
                              : Clamp(v + 0.04, 0.62, 0.88);
    } else {
        targetS = muted > 0.0 ? Clamp(s * 1.10 + 0.08, 0.28, 0.46)
                              : Clamp(s * 1.02, 0.46, 0.72);
        targetV =
            muted > 0.0 ? Clamp(v + 0.04, 0.64, 0.76) : Clamp(v, 0.58, 0.82);
    }
    return ColorFromHsv(h, targetS, targetV);
}

winrt::Windows::UI::Color PopupProgressVividColor() {
    double h, s, v;
    ColorToHsv(PopupAccentColor(), h, s, v);
    bool dark = IsDarkModeApprox();

    double muted = Clamp((0.40 - s) / 0.34, 0.0, 1.0);
    double targetS;
    double targetV;
    if (dark) {
        targetS = muted > 0.0 ? Clamp(s * 1.10 + 0.10, 0.34, 0.54)
                              : Clamp(s * 1.08, 0.56, 0.82);
        targetV = muted > 0.0 ? Clamp(v + 0.10, 0.68, 0.86)
                              : Clamp(v + 0.08, 0.76, 0.94);
    } else {
        targetS = muted > 0.0 ? Clamp(s * 1.08 + 0.10, 0.32, 0.50)
                              : Clamp(s * 1.08, 0.54, 0.78);
        targetV = muted > 0.0 ? Clamp(v + 0.06, 0.68, 0.82)
                              : Clamp(v + 0.07, 0.64, 0.86);
    }
    return ColorFromHsv(h, targetS, targetV);
}

winrt::Windows::UI::Color PopupProgressBrightSoftColor() {
    double h, s, v;
    ColorToHsv(PopupAccentColor(), h, s, v);
    bool dark = IsDarkModeApprox();

    double targetS;
    double targetV;
    double muted = Clamp((0.40 - s) / 0.34, 0.0, 1.0);
    if (dark) {
        targetS = muted > 0.0 ? Clamp(s * 0.78 + 0.08, 0.25, 0.42)
                              : Clamp(s * 0.52, 0.32, 0.56);
        targetV = muted > 0.0 ? 0.82 : 0.92;
    } else {
        targetS = muted > 0.0 ? Clamp(s * 0.78 + 0.08, 0.24, 0.40)
                              : Clamp(s * 0.64, 0.36, 0.58);
        targetV = muted > 0.0 ? 0.80 : 0.86;
    }
    auto color = ColorFromHsv(h, targetS, targetV);

    // Same idea as the component stroke: on dark surfaces the highlight leans
    // closer to white; on light surfaces it keeps more accent chroma for contrast.
    if (dark) {
        double muted = Clamp((0.40 - s) / 0.34, 0.0, 1.0);
        color = LerpArtworkColor(color, Color(0xFF, 0xFF, 0xFF, 0xFF),
                                 muted > 0.0 ? 0.08 : 0.14);
    }
    return color;
}

mediax::Brush MakePopupProgressGradientBrush() {
    auto accent = PopupProgressCleanStartColor();
    auto vivid = PopupProgressVividColor();
    auto soft = PopupProgressBrightSoftColor();
    bool dark = IsDarkModeApprox();

    if (dark) {
        double h, s, v;
        ColorToHsv(PopupAccentColor(), h, s, v);
        double muted = Clamp((0.40 - s) / 0.34, 0.0, 1.0);
        vivid = LerpArtworkColor(vivid, accent, muted > 0.0 ? 0.18 : 0.08);
        soft = LerpArtworkColor(soft, vivid, muted > 0.0 ? 0.16 : 0.08);
    } else {
        // Light theme: keep the gradient clean and related to the artwork
        // without introducing a gray first stop or an over-saturated tail.
        vivid = LerpArtworkColor(vivid, accent, 0.10);
        soft = LerpArtworkColor(soft, vivid, 0.22);
    }

    mediax::LinearGradientBrush brush;
    brush.StartPoint({0.0, 0.5});
    brush.EndPoint({1.0, 0.5});
    mediax::GradientStopCollection stops;

    auto addStop = [&](double offset, winrt::Windows::UI::Color const& color) {
        mediax::GradientStop stop;
        stop.Offset(offset);
        stop.Color(color);
        stops.Append(stop);
    };

    addStop(0.00, accent);
    addStop(dark ? 0.66 : 0.58, vivid);
    addStop(1.00, soft);
    brush.GradientStops(stops);
    return brush;
}

std::wstring FormatMediaTime(int64_t ticks) {
    if (ticks <= 0) {
        return L"0:00";
    }
    int64_t totalSeconds = ticks / 10000000LL;
    int64_t hours = totalSeconds / 3600;
    int64_t minutes = (totalSeconds / 60) % 60;
    int64_t seconds = totalSeconds % 60;
    wchar_t buffer[32]{};
    if (hours > 0) {
        swprintf_s(buffer, L"%lld:%02lld:%02lld", hours, minutes, seconds);
    } else {
        swprintf_s(buffer, L"%lld:%02lld", minutes, seconds);
    }
    return buffer;
}

void UpdatePopupAlbumBitmap(MediaState const& state) {
    // CPU-rendered popup fallback: the default cover also fills the idle state
    // here so both rendering paths stay visually consistent.
    std::vector<uint8_t> bytes = state.thumbnailBytes;
    if (bytes.empty() && !state.hasSession) {
        bytes = LoadDefaultCoverImageBytes();
    }

    uint64_t hash = ThumbnailHash(bytes);
    if (hash == g_popupThumbnailHash) {
        return;
    }

    g_popupThumbnailHash = hash;
    if (g_popupAlbumBitmap) {
        DeleteObject(g_popupAlbumBitmap);
        g_popupAlbumBitmap = nullptr;
    }
    if (hash) {
        g_popupAlbumBitmap = DecodeAlbumBitmap(bytes, 256);
    }
}

constexpr wchar_t kPopupClassName[] = L"WindhawkIslandMediaPopup";
constexpr wchar_t kPopupToggleHitWindowClassName[] =
    L"WindhawkIslandMediaToggleHitWindow";
constexpr wchar_t kPopupBackdropOverlayClassName[] =
    L"WindhawkIslandMediaBackdropOverlay";
constexpr UINT_PTR kPopupTimerId = 0x494D;
constexpr UINT_PTR kPopupBackdropOverlayTimerId = 0x494E;
constexpr UINT_PTR kTaskbarLayoutMonitorTimerId = 0x494D4C54;
constexpr UINT kTaskbarLayoutMonitorIntervalMs = 600;
constexpr int kPopupBackdropOverlayRefreshMs = 90;
constexpr int kPopupBackdropOverlayMaxCaptureSize = 320;

double SmootherStep(double value) {
    value = Clamp(value, 0.0, 1.0);
    return value * value * value * (value * (value * 6.0 - 15.0) + 10.0);
}

double PopupTextMotionEase(double value) {
    value = Clamp(value, 0.0, 1.0);
    return 0.5 - std::cos(value * 3.14159265358979323846) * 0.5;
}

// Clip animated text to its own text lane. Without this, render transforms can
// let the incoming/outgoing title briefly draw outside the compact/popup card.
void ApplyElementClip(FrameworkElement const& element,
                      double width,
                      double height) {
    if (!element || width <= 0.0 || height <= 0.0) {
        return;
    }
    try {
        mediax::RectangleGeometry clip;
        clip.Rect({0.0f, 0.0f, static_cast<float>(std::max(1.0, width)),
                   static_cast<float>(std::max(1.0, height))});
        element.Clip(clip);
    } catch (...) {
    }
}

void ApplyElementCircularClip(FrameworkElement const& element,
                              double diameter) {
    if (!element || diameter <= 0.0) {
        return;
    }
    double size = std::max(1.0, diameter);
    try {
        // XAML only accepts a RectangleGeometry for UIElement.Clip, so a real
        // circle needs a composition geometric clip (the same technique the
        // expanded panel artwork uses). Corner radius = half the square size
        // makes the rounded rectangle geometry exactly circular.
        auto visual =
            hosting::ElementCompositionPreview::GetElementVisual(element);
        auto compositor = visual.Compositor();
        auto geometry = compositor.CreateRoundedRectangleGeometry();
        float sizeF = static_cast<float>(size);
        geometry.Size({sizeF, sizeF});
        float radius = sizeF * 0.5f;
        geometry.CornerRadius({radius, radius});
        visual.Clip(compositor.CreateGeometricClip(geometry));
        return;
    } catch (...) {
    }

    // Last-resort fallback: a rectangular clip still keeps the artwork inside
    // its slot if the compositor path is unavailable.
    ApplyElementClip(element, size, size);
}

void ApplyElementClipWithPadding(FrameworkElement const& element,
                                 double width,
                                 double height,
                                 double horizontalPadding) {
    if (!element || width <= 0.0 || height <= 0.0) {
        return;
    }
    try {
        horizontalPadding = std::max(0.0, horizontalPadding);
        mediax::RectangleGeometry clip;
        clip.Rect(
            {static_cast<float>(-horizontalPadding), 0.0f,
             static_cast<float>(std::max(1.0, width + horizontalPadding * 2.0)),
             static_cast<float>(std::max(1.0, height))});
        element.Clip(clip);
    } catch (...) {
    }
}

mediax::Brush CompactTextEdgeFadeBrush(bool leftEdge) {
    auto bg = IslandBackgroundColor();
    auto clear = bg;
    clear.A = 0x00;

    mediax::LinearGradientBrush brush;
    brush.StartPoint({0.0, 0.5});
    brush.EndPoint({1.0, 0.5});
    mediax::GradientStopCollection stops;

    auto addStop = [&](double offset, winrt::Windows::UI::Color const& color) {
        mediax::GradientStop stop;
        stop.Offset(offset);
        stop.Color(color);
        stops.Append(stop);
    };

    if (leftEdge) {
        addStop(0.00, bg);
        addStop(0.42, bg);
        addStop(1.00, clear);
    } else {
        addStop(0.00, clear);
        addStop(0.58, bg);
        addStop(1.00, bg);
    }
    brush.GradientStops(stops);
    return brush;
}

double PopupProgress() {
    // The animation value is already the output of a critically damped spring.
    // Applying another easing curve here caused a hesitant start and a long,
    // uneven tail.
    return Clamp(g_popupAnimationProgress, 0.0, 1.0);
}

bool AdvancePopupSpring(double dt) {
    double speed = Clamp(g_settings.animationSpeed, 0.10, 4.0);
    double scaledDt = Clamp(dt * speed, 0.0, 0.08);
    if (scaledDt <= 0.0) {
        return false;
    }

    // Match the feel of Apple's smooth spring: critical damping gives a quick,
    // continuous response without a visible bounce. Small fixed substeps keep
    // the result stable when Explorer drops or delays a frame.
    constexpr double kAngularFrequency = 20.5;
    constexpr double kStiffness = kAngularFrequency * kAngularFrequency;
    constexpr double kDamping = 2.0 * kAngularFrequency;
    constexpr double kMaxStep = 1.0 / 120.0;
    int steps = std::max(1, static_cast<int>(std::ceil(scaledDt / kMaxStep)));
    double h = scaledDt / static_cast<double>(steps);
    for (int i = 0; i < steps; ++i) {
        double displacement = g_popupAnimationTarget - g_popupAnimationProgress;
        double acceleration =
            kStiffness * displacement - kDamping * g_popupAnimationVelocity;
        g_popupAnimationVelocity += acceleration * h;
        g_popupAnimationProgress += g_popupAnimationVelocity * h;
    }

    bool settled =
        std::abs(g_popupAnimationTarget - g_popupAnimationProgress) < 0.0008 &&
        std::abs(g_popupAnimationVelocity) < 0.012;
    if (settled) {
        g_popupAnimationProgress = g_popupAnimationTarget;
        g_popupAnimationVelocity = 0.0;
    }
    return settled;
}

double PopupClosingShellOpacity(double progress) {
    // The popup is the single morph surface from the compact geometry all the
    // way to the expanded geometry. Fading the shell near progress zero made
    // the separately-rendered compact island show through for a few frames,
    // which produced a visible flash whenever an animation was interrupted.
    return 1.0;
}

double PopupClosingTextOpacity(double progress) {
    // Title and artist belong to both compact and expanded layouts. Keep them
    // continuously visible while their geometry morphs, then hand off to the
    // compact XAML tree only after the final frame has been committed.
    return 1.0;
}

double PopupShadowMorphOpacity(double progress) {
    progress = Clamp(progress, 0.0, 1.0);
    return g_popupClosing
               ? SmootherStep(Clamp(progress / 0.28, 0.0, 1.0))
               : SmootherStep(Clamp((progress - 0.12) / 0.58, 0.0, 1.0));
}

double PopupControlMorphProgress(double progress) {
    return Clamp(progress, 0.0, 1.0);
}

double PopupControlOpacityProgress(double progress) {
    return Clamp(progress, 0.0, 1.0);
}

double LerpDouble(double from, double to, double progress) {
    return from + (to - from) * progress;
}

static double SourceScaledRadius(double baseRadius,
                                 double baseSize,
                                 DipRect const& sourceRect) {
    double sourceWidth =
        std::max(1.0, static_cast<double>(sourceRect.right - sourceRect.left));
    double sourceHeight =
        std::max(1.0, static_cast<double>(sourceRect.bottom - sourceRect.top));
    double scale =
        std::min(sourceWidth, sourceHeight) / std::max(1.0, baseSize);
    return std::max(1.0, baseRadius * scale);
}

int LerpInt(int from, int to, double progress) {
    return static_cast<int>(std::lround(from + (to - from) * progress));
}

// C variant: compact-material-expanded layout.
constexpr int kPopupMinimumArtSize = 220;
constexpr int kPopupMaximumArtSize = 420;
// Main.PopupSpacing controls only the outer shell inset: cover->shell top,
// cover->shell left/right, and card->shell bottom. Main.PopupCardGap controls
// only the distance between the cover and the playback card.
int PopupSurfaceGap() {
    return Clamp(g_settings.popupSpacing, 2, 40);
}
int PopupArtCardGap() {
    return Clamp(g_settings.popupCardGap, 0, 40);
}
int PopupShadowDepth() {
    if (IsLiquidGlassMaterial()) {
        return 0;
    }
    return Clamp(g_settings.popupShadowDepth, 0, 128);
}
int PopupShadowOpacityPercent() {
    if (IsLiquidGlassMaterial()) {
        return 0;
    }
    return Clamp(g_settings.popupShadowOpacity, 0, 100);
}
int PopupBackdropInitialFrameSkip() {
    return Clamp(g_settings.backdropInitialFrameSkip, 0, 3);
}
int PopupBackdropFallbackBlurPasses() {
    int passes = Clamp(g_settings.backdropFallbackBlurPasses, 4, 6);
    if (IsLiquidGlassMaterial()) {
        return Clamp(passes - 4, 1, 2);
    }

    return passes;
}
int PopupBackdropFallbackCaptureScale() {
    return Clamp(g_settings.backdropFallbackCaptureScale, 2, 3);
}
int PopupBackdropPadding() {
    return PopupSurfaceGap();
}
constexpr int kPopupCardHeight = 246;
constexpr int kPopupCompactCardHeight = 154;
constexpr int kPopupCompactMinimumCardWidth = 320;
constexpr int kPopupCardInnerPadding = 18;
constexpr int kPopupTimeTextHeight = 16;
// G2-style popup radius family. Windhawk's UWP XAML surface does not expose
// a true squircle clip here, so keep the visual language consistent by routing
// every expanded popup corner through these shared radii.
// Apple-style concentric family: the large glass surface uses a softer outer
// radius, while nested content subtracts its inset instead of inventing an
// unrelated curve.
constexpr double kPopupUnifiedCornerRadius = 30.0;
constexpr double kPopupInnerPanelCornerRadius = 24.0;
constexpr double kPopupArtworkCornerRadius = 16.0;
constexpr double kPopupG2ButtonCornerRadius = 16.0;
constexpr double kPopupG2ProgressCornerRadius = 3.0;

double PopupG2CornerRadius(double width, double height) {
    return std::max(1.0, std::min(width, height) * 0.118);
}

// Transparent host margin used only so the rounded XAML shadow can fit without
// falling back to the rectangular HWND shadow.
constexpr int kPopupHostShadowMargin = 18;
// The backdrop shell is the only outer background shape. In C mode its
// material is exactly the compact island material, so compact/expanded states
// share one color, one stroke model, and one predictable XAML clipping path.
constexpr double kPopupBackdropOpacity = 1.0;
constexpr double kPopupOverlayRadiusAdjustDip = 0.0;

bool UseOverlayPopupBackdropMaterial() {
    // Acrylic uses a separate native overlay window behind
    // the XAML popup, clipped to the animated rounded popup shell instead of
    // the full transparent host rectangle. This keeps the visibility test from
    // leaking outside the actual visual surface.
    // Liquid glass is painted directly by an immediate XAML composition
    // backdrop brush. Only legacy Acrylic still needs the separate HWND.
    return g_settings.material == L"acrylic";
}

double PopupBackdropOverlayOpacity() {
    // A readable frosted surface must retain enough captured wallpaper to
    // blur continuously; low historical Liquid Glass values made the popup
    // look fully transparent before/while the first captured frame arrived.
    return 1.0;
}

BYTE PopupBackdropOverlayMaxAlpha() {
    return static_cast<BYTE>(Clamp(
        static_cast<int>(std::lround(255.0 * PopupBackdropOverlayOpacity())), 0,
        255));
}

bool PopupBackdropCoverEffectEnabled() {
    if (IsLiquidGlassMaterial()) {
        return g_settings.liquidGlassGradient;
    }
    if (g_settings.popupBackdropCoverEffect == L"on") {
        return true;
    }
    if (IsLiquidGlassMaterial() && !IsDarkModeApprox()) {
        return true;
    }
    if (g_settings.popupBackdropCoverEffect == L"off") {
        return false;
    }
    // Default: keep the album color wash in dark mode. Liquid Glass also keeps
    // it in light mode so the glass surface remains readable.
    return IsDarkModeApprox();
}

bool PopupPanelCoverEffectEnabled() {
    if (IsLiquidGlassMaterial()) {
        return PopupBackdropCoverEffectEnabled();
    }

    return true;
}

int PopupTargetArtSize(int width, int height) {
    // finalRect is the host window. The visible compact-material surface sits
    // inside a small transparent margin so the shadow can be visible.
    int surfaceWidth = std::max(96, width - kPopupHostShadowMargin * 2);
    int surfaceHeight = std::max(96, height - kPopupHostShadowMargin * 2);
    int availableWidth = std::max(96, surfaceWidth - PopupSurfaceGap() * 2);
    int availableHeight =
        std::max(96, surfaceHeight - PopupSurfaceGap() * 2 - PopupArtCardGap() -
                         kPopupCardHeight);
    return std::max(96, std::min(availableWidth, availableHeight));
}

RECT PopupBackdropRectFromParts(RECT const& artRect, RECT const& cardRect) {
    if (g_settings.compact) {
        return cardRect;
    }
    // The background shell is the tight bounding box around cover + control card.
    int left = std::min(artRect.left, cardRect.left);
    int top = std::min(artRect.top, cardRect.top);
    int right = std::max(artRect.right, cardRect.right);
    int bottom = std::max(artRect.bottom, cardRect.bottom);
    return {left - PopupBackdropPadding(), top - PopupBackdropPadding(),
            right + PopupBackdropPadding(), bottom + PopupBackdropPadding()};
}

int PopupFinalWidthFromArtSize(int artSize) {
    return artSize + PopupSurfaceGap() * 2 + kPopupHostShadowMargin * 2;
}

int PopupFinalHeightFromArtSize(int artSize) {
    return artSize + kPopupCardHeight + PopupArtCardGap() +
           PopupSurfaceGap() * 2 + kPopupHostShadowMargin * 2;
}

int PopupCompactFinalWidth(int cardWidth) {
    return cardWidth + kPopupHostShadowMargin * 2;
}

int PopupCompactFinalHeight() {
    return kPopupCompactCardHeight + kPopupHostShadowMargin * 2;
}

winrt::Windows::UI::Color PopupControlCardColor() {
    bool dark = IsDarkModeApprox();
    if (IsLiquidGlassMaterial()) {
        return dark ? Color(0x3A, 0x12, 0x14, 0x1A)
                    : Color(0x68, 0xFB, 0xFC, 0xFF);
    }

    // Keep light and dark tint strengths independent; light mode needs a
    // stronger white tint so the controls stay legible over bright artwork.
    if (dark) {
        return Color(0x54, 0x20, 0x20, 0x26);
    }
    return Color(0x84, 0xFF, 0xFF, 0xFF);
}

mediax::Brush PopupControlCardBrush() {
    return Brush(PopupControlCardColor());
}

winrt::Windows::UI::Color PopupPrimaryTextColor() {
    bool dark = IsDarkModeApprox();
    return dark ? Color(0xFF, 0xFF, 0xFF, 0xFF) : Color(0xFF, 0x00, 0x00, 0x00);
}

winrt::Windows::UI::Color PopupSecondaryTextColor() {
    bool dark = IsDarkModeApprox();
    return dark ? Color(0xC8, 0xFF, 0xFF, 0xFF) : Color(0xC8, 0x00, 0x00, 0x00);
}

// ===== Transport routing =====
void NoteMediaNavigationDirection(int direction) {
    g_pendingMediaNavigationDirection =
        direction < 0 ? -1 : (direction > 0 ? 1 : 0);
    g_pendingMediaNavigationTime = std::chrono::steady_clock::now();
}

int ConsumeRecentMediaNavigationDirection() {
    int direction = g_pendingMediaNavigationDirection;
    if (direction == 0) {
        return 0;
    }

    auto now = std::chrono::steady_clock::now();
    auto ageMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                     now - g_pendingMediaNavigationTime)
                     .count();
    g_pendingMediaNavigationDirection = 0;
    return ageMs <= 4000 ? direction : 0;
}

bool TryRunNeteaseCloudMusicTransportCommand(MediaTransportCommand command) {
    MediaState state = SnapshotMedia();
    if (!IsNeteaseCloudMusicSource(state.sourceAppUserModelId)) {
        return false;
    }

    WORD shortcutKey = 0;
    switch (command) {
        case MediaTransportCommand::Previous:
            shortcutKey = VK_LEFT;
            break;
        case MediaTransportCommand::TogglePlayPause:
            shortcutKey = L'P';
            break;
        case MediaTransportCommand::Next:
            shortcutKey = VK_RIGHT;
            break;
    }

    // UI Automation reports success for the CEF buttons but the player ignores
    // it. These are NetEase's own registered global shortcuts and were verified
    // against the desktop client.
    if (!shortcutKey || !SendNeteaseGlobalShortcut(shortcutKey)) {
        return false;
    }

    if (command == MediaTransportCommand::Previous) {
        NoteMediaNavigationDirection(-1);
    } else if (command == MediaTransportCommand::Next) {
        NoteMediaNavigationDirection(1);
    }
    RequestMediaRefresh();
    return true;
}

void RunMediaTransportCommand(MediaTransportCommand command) {
    MediaState state = SnapshotMedia();
    if (IsDefaultMediaSource(state.sourceAppUserModelId)) {
        return;
    }

    if (command == MediaTransportCommand::TogglePlayPause) {
        ApplyOptimisticPlaybackToggle();
    } else {
        ResetMediaProgressUiForTrackNavigation();
    }

    if (TryRunNeteaseCloudMusicTransportCommand(command)) {
        return;
    }

    RunMediaCommand(
        [command](
            gsm::GlobalSystemMediaTransportControlsSession const& session) {
            switch (command) {
                case MediaTransportCommand::Previous:
                    NoteMediaNavigationDirection(-1);
                    (void)session.TrySkipPreviousAsync();
                    break;
                case MediaTransportCommand::TogglePlayPause:
                    (void)session.TryTogglePlayPauseAsync();
                    break;
                case MediaTransportCommand::Next:
                    NoteMediaNavigationDirection(1);
                    (void)session.TrySkipNextAsync();
                    break;
            }
        });
}

// ===== Popup text foregrounds =====
mediax::Brush PopupTextForegroundBrush(winrt::Windows::UI::Color color,
                                       double edgeFadeAmount) {
    edgeFadeAmount = Clamp(edgeFadeAmount, 0.0, 1.0);
    auto clear = color;
    clear.A = static_cast<BYTE>(std::lround(color.A * (1.0 - edgeFadeAmount)));

    mediax::LinearGradientBrush brush;
    brush.StartPoint({0.0f, 0.5f});
    brush.EndPoint({1.0f, 0.5f});
    mediax::GradientStopCollection stops;

    auto addStop = [&](double offset,
                       winrt::Windows::UI::Color const& stopColor) {
        mediax::GradientStop stop;
        stop.Offset(offset);
        stop.Color(stopColor);
        stops.Append(stop);
    };

    addStop(0.00, clear);
    addStop(0.16, color);
    addStop(0.84, color);
    addStop(1.00, clear);
    brush.GradientStops(stops);
    return brush;
}

void ApplyPopupTextForegroundFade(double edgeFadeAmount, bool force = false) {
    edgeFadeAmount = Clamp(edgeFadeAmount, 0.0, 1.0);
    bool dark = IsDarkModeApprox();
    if (!force && g_popupTextForegroundValid &&
        std::abs(g_popupTextForegroundEdgeFadeAmount - edgeFadeAmount) <
            0.003 &&
        g_popupTextForegroundDark == dark) {
        return;
    }

    g_popupTextForegroundValid = true;
    g_popupTextForegroundEdgeFade = edgeFadeAmount > 0.001;
    g_popupTextForegroundEdgeFadeAmount = edgeFadeAmount;
    g_popupTextForegroundDark = dark;

    auto primary =
        PopupTextForegroundBrush(PopupPrimaryTextColor(), edgeFadeAmount);
    auto secondary =
        PopupTextForegroundBrush(PopupSecondaryTextColor(), edgeFadeAmount);
    auto secondarySolid = Brush(PopupSecondaryTextColor());

    if (g_popupXamlTitle)
        g_popupXamlTitle.Foreground(primary);
    if (g_popupXamlOutgoingTitle)
        g_popupXamlOutgoingTitle.Foreground(primary);
    if (g_popupXamlArtist)
        g_popupXamlArtist.Foreground(secondary);
    if (g_popupXamlOutgoingArtist)
        g_popupXamlOutgoingArtist.Foreground(secondary);
    if (g_popupXamlElapsed)
        g_popupXamlElapsed.Foreground(secondarySolid);
    if (g_popupXamlDuration)
        g_popupXamlDuration.Foreground(secondarySolid);
}

void ApplyPopupTextForegrounds(bool edgeFade, bool force = false) {
    ApplyPopupTextForegroundFade(edgeFade ? 1.0 : 0.0, force);
}

mediax::Brush PopupTextEdgeFadeBrush(bool leftEdge) {
    auto bg = PopupControlCardColor();
    if (IsLiquidGlassMaterial()) {
        bool dark = IsDarkModeApprox();
        bg = dark ? Color(0x28, 0x12, 0x14, 0x1A)
                  : Color(0x50, 0xFB, 0xFC, 0xFF);
    }
    auto clear = bg;
    clear.A = 0x00;

    mediax::LinearGradientBrush brush;
    brush.StartPoint({0.0, 0.5});
    brush.EndPoint({1.0, 0.5});
    mediax::GradientStopCollection stops;

    auto addStop = [&](double offset, winrt::Windows::UI::Color const& color) {
        mediax::GradientStop stop;
        stop.Offset(offset);
        stop.Color(color);
        stops.Append(stop);
    };

    if (leftEdge) {
        addStop(0.00, bg);
        addStop(0.42, bg);
        addStop(1.00, clear);
    } else {
        addStop(0.00, clear);
        addStop(0.58, bg);
        addStop(1.00, bg);
    }
    brush.GradientStops(stops);
    return brush;
}

double PopupTextClipPadding() {
    return 2.0;
}

double PopupTextEdgeFadeWidth() {
    return IsLiquidGlassMaterial() ? 24.0 : 18.0;
}

void ConfigurePopupTextEdgeFade(Border const& fade,
                                bool leftEdge,
                                double height) {
    if (!fade) {
        return;
    }

    double clipPadding = PopupTextClipPadding();
    fade.Width(PopupTextEdgeFadeWidth() + clipPadding);
    fade.Height(std::max(1.0, height));
    fade.Margin(leftEdge ? xaml::Thickness{-clipPadding, 0, 0, 0}
                         : xaml::Thickness{0, 0, -clipPadding, 0});
    fade.Background(PopupTextEdgeFadeBrush(leftEdge));
}

void SetPopupTextEdgeFadeOpacity(double opacity) {
    opacity = Clamp(opacity, 0.0, 1.0);
    try {
        Border fades[] = {
            g_popupXamlTitleLeftFade,
            g_popupXamlTitleRightFade,
            g_popupXamlArtistLeftFade,
            g_popupXamlArtistRightFade,
            g_popupXamlOutgoingTitleLeftFade,
            g_popupXamlOutgoingTitleRightFade,
            g_popupXamlOutgoingArtistLeftFade,
            g_popupXamlOutgoingArtistRightFade,
        };
        for (Border const& fade : fades) {
            if (fade) {
                fade.Opacity(opacity);
            }
        }
    } catch (...) {
    }
}

// ===== Popup material brushes =====
mediax::Brush PopupBackdropCardTintBrush() {
    bool dark = IsDarkModeApprox();
    bool preserveCompactWash =
        g_settings.compact && PopupBackdropCoverEffectEnabled();
    if (g_settings.material == L"mica_like") {
        // Mica-like already carries its theme tint in IslandBackgroundColor().
        // A second light-mode white veil makes the expanded surface nearly
        // opaque white and breaks compact-to-expanded material continuity.
        return Brush(Color(0x00, 0x00, 0x00, 0x00));
    }

    if (IsLiquidGlassMaterial()) {
        // Down Aero tint is now part of the same GPU effect graph as the blur,
        // exactly like WindhawkBlur. Do not apply a second XAML overlay.
        return Brush(Color(0x00, 0x00, 0x00, 0x00));
    }

    if (UseOverlayPopupBackdropMaterial()) {
        if (IsLiquidGlassMaterial()) {
            if (!g_settings.liquidGlassGradient) {
                // Neutral adaptive frost: dark mode receives a charcoal veil,
                // light mode a soft white veil. No album-color gradient is
                // baked in, so readability remains stable on any wallpaper.
                return Brush(dark ? Color(0x78, 0x18, 0x1A, 0x20)
                                  : Color(0x80, 0xF2, 0xF4, 0xF7));
            }
            if (!dark) {
                mediax::LinearGradientBrush brush;
                brush.StartPoint({0.0f, 1.0f});
                brush.EndPoint({0.0f, 0.0f});
                mediax::GradientStopCollection stops;
                auto addStop = [&](double offset, BYTE alpha) {
                    mediax::GradientStop stop;
                    stop.Offset(offset);
                    stop.Color(Color(alpha, 0xF6, 0xF8, 0xFC));
                    stops.Append(stop);
                };

                addStop(0.00, preserveCompactWash ? 0x42 : 0x5C);
                addStop(0.24, preserveCompactWash ? 0x30 : 0x42);
                addStop(0.58, preserveCompactWash ? 0x16 : 0x22);
                addStop(1.00, 0x00);
                brush.GradientStops(stops);
                return brush;
            }
            return Brush(
                Color(preserveCompactWash ? 0x00 : 0x04, 0xFF, 0xFF, 0xFF));
        }

        // Native blur comes from the overlay window itself. Add only a clean
        // light-mode white veil here so acrylic keeps enough tint without the
        // compact island inheriting AcrylicBrush's inactive fallback behavior.
        return Brush(
            dark ? Color(0x00, 0x00, 0x00, 0x00)
                 : Color(preserveCompactWash ? 0x68 : 0x8C, 0xFF, 0xFF, 0xFF));
    }
    // Backdrop and control tints are tuned separately so light mode can stay
    // brighter without making dark mode look washed out. In dark mode this
    // matches the previous version, where the backdrop card tint reused the
    // control-card tint.
    if (dark) {
        return Brush(
            Color(preserveCompactWash ? 0x58 : 0x70, 0x20, 0x20, 0x26));
    }
    return Brush(Color(preserveCompactWash ? 0xB8 : 0xE8, 0xFF, 0xFF, 0xFF));
}

mediax::Brush PopupSurfaceStrokeBrush() {
    if (UseOverlayPopupBackdropMaterial()) {
        if (IsLiquidGlassMaterial()) {
            return LiquidGlassRimHighlightBrush();
        }

        bool dark = IsDarkModeApprox();
        return Brush(dark ? Color(0x10, 0xFF, 0xFF, 0xFF)
                          : Color(0x00, 0x00, 0x00, 0x00));
    }
    // Match the compact island outline exactly: the expanded popup surface
    // should use the same subtle theme-aware stroke and no extra DWM border.
    return IslandBorderBrush();
}

// The compact taskbar component and the compact endpoint of the popup share
// this exact surface recipe. Keeping this in one function prevents theme
// refreshes from silently replacing one side with a different tint/stroke.
void ApplyCompactSurfaceVisual(Border const& surface) {
    if (!surface) {
        return;
    }
    auto spec = CurrentCompactVisualSpec();
    surface.CornerRadius({spec.cornerRadius, spec.cornerRadius,
                          spec.cornerRadius, spec.cornerRadius});
    // ImmediateBackdropBlurBrush only has a valid backdrop source in the
    // independent popup tree. On the taskbar's native XAML island it samples
    // an invalid/black backing surface. Use the same stable, theme-aware
    // translucent brush on both endpoints so neither can fall back to black.
    surface.Background(PopupControlCardBrush());
    surface.BorderBrush(PopupSurfaceStrokeBrush());
    surface.BorderThickness({spec.borderThickness, spec.borderThickness,
                             spec.borderThickness, spec.borderThickness});
}

// Liquid glass's live Gaussian backdrop brush only works inside the
// independent popup host. Keep it attached while the popup is expanded, and
// swap to the same solid recipe as the taskbar island once the morph reaches
// the compact endpoint so the handoff is pixel-identical.
void EnsurePopupLiquidGlassBlur(Border const& surface, bool wantBlur) {
    if (!surface) {
        return;
    }
    if (wantBlur && !g_popupBackdropBlurActive) {
        try {
            surface.Background(winrt::make<ImmediateBackdropBlurBrush>(
                surface, 25.0f, Color(0x25, 0x32, 0x32, 0x32)));
            // The separate rim-highlight layer owns the glass edge while the
            // popup is expanded; keep the backdrop's own border empty so the
            // 1.0 DIP rim doesn't double up with the 0.75 DIP compact border.
            surface.BorderThickness({0, 0, 0, 0});
            surface.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));
            g_popupBackdropBlurActive = true;
        } catch (...) {
            g_popupBackdropBlurActive = false;
        }
    } else if (!wantBlur && g_popupBackdropBlurActive) {
        // The compact endpoint must be identical to the taskbar island:
        // solid recipe plus the same 0.75 DIP rim.
        ApplyCompactSurfaceVisual(surface);
        g_popupBackdropBlurActive = false;
    }
}

// ===== Popup geometry and animation state =====
mediax::Brush PopupShadowBrush() {
    bool dark = IsDarkModeApprox();
    // Rounded XAML-only shadow. Do not use CS_DROPSHADOW/DWM shadow here:
    // those shadow the transparent rectangular host instead of this surface.
    return Brush(dark ? Color(0x5C, 0x00, 0x00, 0x00)
                      : Color(0x46, 0x00, 0x00, 0x00));
}

void CalculatePopupFinalLayout(RECT const& finalRect,
                               RECT& artRect,
                               RECT& cardRect,
                               RECT& titleRect,
                               RECT& artistRect,
                               RECT& progressRect,
                               RECT& elapsedRect,
                               RECT& durationRect,
                               RECT& controlsRect) {
    RECT surfaceRect{finalRect.left + kPopupHostShadowMargin,
                     finalRect.top + kPopupHostShadowMargin,
                     finalRect.right - kPopupHostShadowMargin,
                     finalRect.bottom - kPopupHostShadowMargin};
    int finalWidth = surfaceRect.right - surfaceRect.left;

    if (g_settings.compact) {
        cardRect = surfaceRect;
        constexpr int inset = 14;
        int cardHeight = cardRect.bottom - cardRect.top;
        int artSize = std::max(72, cardHeight - inset * 2);
        int artTop = cardRect.top + inset;
        artRect = {cardRect.left + inset, artTop,
                   cardRect.left + inset + artSize, artTop + artSize};

        int contentLeft = artRect.right + inset;
        int contentRight = cardRect.right - inset;
        int textTop = artRect.top + 3;
        titleRect = {contentLeft, textTop, contentRight, textTop + 24};
        artistRect = {contentLeft, textTop + 24, contentRight, textTop + 45};
        int progressSideInset = artRect.left - cardRect.left;
        progressRect = {artRect.right + progressSideInset, cardRect.top + 66,
                        cardRect.right - progressSideInset, cardRect.top + 70};
        elapsedRect = {contentLeft, cardRect.top + 72, contentLeft + 68,
                       cardRect.top + 88};
        durationRect = {contentRight - 68, cardRect.top + 72, contentRight,
                        cardRect.top + 88};
        constexpr int controlsVisualOffset = 6;
        controlsRect = {contentLeft - controlsVisualOffset, cardRect.top + 96,
                        contentRight - controlsVisualOffset,
                        cardRect.bottom - inset};
        return;
    }

    int targetArt = PopupTargetArtSize(finalRect.right - finalRect.left,
                                       finalRect.bottom - finalRect.top);
    int artLeft = surfaceRect.left + (finalWidth - targetArt) / 2;
    if (g_popupOpensDown) {
        int cardTop = surfaceRect.top + PopupSurfaceGap();
        cardRect = {artLeft, cardTop, artLeft + targetArt,
                    cardTop + kPopupCardHeight};

        int artTop = cardRect.bottom + PopupArtCardGap();
        artRect = {artLeft, artTop, artLeft + targetArt, artTop + targetArt};
    } else {
        int artTop = surfaceRect.top + PopupSurfaceGap();
        artRect = {artLeft, artTop, artLeft + targetArt, artTop + targetArt};

        int cardTop = artRect.bottom + PopupArtCardGap();
        cardRect = {artRect.left, cardTop, artRect.right,
                    cardTop + kPopupCardHeight};
    }

    int contentLeft = cardRect.left + kPopupCardInnerPadding;
    int contentRight = cardRect.right - kPopupCardInnerPadding;
    titleRect = {contentLeft, cardRect.top + 18, contentRight,
                 cardRect.top + 46};
    artistRect = {contentLeft, cardRect.top + 48, contentRight,
                  cardRect.top + 74};
    progressRect = {contentLeft, cardRect.top + 91, contentRight,
                    cardRect.top + 97};
    elapsedRect = {contentLeft, cardRect.top + 103, contentLeft + 78,
                   cardRect.top + 103 + kPopupTimeTextHeight};
    durationRect = {contentRight - 78, cardRect.top + 103, contentRight,
                    cardRect.top + 103 + kPopupTimeTextHeight};
    controlsRect = {contentLeft, cardRect.top + 132, contentRight,
                    cardRect.top + 194};
}

RECT UnionPopupRects(RECT const& a, RECT const& b) {
    RECT result{std::min(a.left, b.left), std::min(a.top, b.top),
                std::max(a.right, b.right), std::max(a.bottom, b.bottom)};
    // Reserve the compact island's full center-hover envelope from the first
    // frame. Otherwise the resting XAML surface grows past the fixed host's
    // left edge and is clipped even though its own rounded clip is correct.
    double hoverScale = std::max(1.0, g_settings.hoverScale);
    int compactWidth = std::max(1L, a.right - a.left);
    int compactHeight = std::max(1L, a.bottom - a.top);
    int hoverPadX =
        static_cast<int>(std::ceil(compactWidth * (hoverScale - 1.0) * 0.5)) +
        3;
    int hoverPadY =
        static_cast<int>(std::ceil(compactHeight * (hoverScale - 1.0) * 0.5)) +
        3;
    InflateRect(&result, std::max(2, hoverPadX), std::max(2, hoverPadY));
    return result;
}

RECT CurrentPopupSurfaceScreenRect() {
    // Used only for outside-click hit testing. Keep this in physical screen
    // pixels and use the full animated host bounds; the precise XAML surface is
    // calculated in DIP coordinates in UpdatePopupXamlVisuals().
    double progress = PopupProgress();
    return {
        LerpInt(g_popupSourceRect.left, g_popupFinalRect.left, progress),
        LerpInt(g_popupSourceRect.top, g_popupFinalRect.top, progress),
        LerpInt(g_popupSourceRect.right, g_popupFinalRect.right, progress),
        LerpInt(g_popupSourceRect.bottom, g_popupFinalRect.bottom, progress)};
}

bool PopupScreenPointIsInsideCurrentSurface(POINT screenPoint) {
    if (!g_expandedPopup || !IsWindowVisible(g_expandedPopup) || !g_expanded) {
        return false;
    }

    // Keep the original compact island as a permanent interrupt target. The
    // popup host already spans the union of source and destination rectangles,
    // so this needs no extra transparent HWND and can never leave a stale
    // desktop-blocking overlay behind.
    RECT sourceHitRect = g_popupSourceRect;
    InflateRect(&sourceHitRect, 8, 8);
    if (PtInRect(&sourceHitRect, screenPoint)) {
        return true;
    }

    RECT hitRect{};
    if (g_popupXamlRoot) {
        hitRect = CurrentPopupSurfaceScreenRect();
    } else {
        GetWindowRect(g_expandedPopup, &hitRect);
    }
    if (hitRect.right <= hitRect.left || hitRect.bottom <= hitRect.top) {
        GetWindowRect(g_expandedPopup, &hitRect);
    }

    InflateRect(&hitRect, 8, 8);
    return PtInRect(&hitRect, screenPoint) != FALSE;
}

LRESULT PopupExpandedHitTest(LPARAM lParam) {
    POINT screenPoint{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
    return PopupScreenPointIsInsideCurrentSurface(screenPoint) ? HTCLIENT
                                                               : HTTRANSPARENT;
}

constexpr UINT_PTR kPopupXamlChildSubclassId = 1;

void KeepPopupOnTop();

void BeginCloseExpandedPopup();
void ResumeOpenExpandedPopup();

bool PopupPointIsInsideOriginalToggleArea(POINT screenPoint) {
    RECT sourceHitRect = g_popupSourceRect;
    InflateRect(&sourceHitRect, 8, 8);
    return PtInRect(&sourceHitRect, screenPoint) != FALSE;
}

void InterruptPopupAnimationFromOriginalArea() {
    if (g_popupClosing || g_popupRestingCompact ||
        g_popupLifecycleState == PopupLifecycleState::Closing) {
        ResumeOpenExpandedPopup();
    } else if (g_expanded) {
        BeginCloseExpandedPopup();
    }
}

// ===== Popup window plumbing =====
LRESULT CALLBACK PopupXamlChildSubclassProc(HWND hwnd,
                                            UINT message,
                                            WPARAM wParam,
                                            LPARAM lParam,
                                            UINT_PTR,
                                            DWORD_PTR) {
    if (message == WM_NCHITTEST) {
        LRESULT hit = PopupExpandedHitTest(lParam);
        if (hit == HTTRANSPARENT) {
            return HTTRANSPARENT;
        }
    } else if (message == WM_LBUTTONDOWN) {
        // Interacting with the island/card raises it above anything that may
        // have covered it (Start menu, taskbar) — one-shot, no oscillation.
        KeepPopupOnTop();
        POINT screenPoint{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
        ClientToScreen(hwnd, &screenPoint);
        bool transitionActive =
            g_popupLifecycleState == PopupLifecycleState::Opening ||
            g_popupLifecycleState == PopupLifecycleState::Closing ||
            std::abs(g_popupAnimationTarget - g_popupAnimationProgress) >=
                0.006;
        if ((transitionActive &&
             PopupScreenPointIsInsideCurrentSurface(screenPoint)) ||
            PopupPointIsInsideOriginalToggleArea(screenPoint)) {
            InterruptPopupAnimationFromOriginalArea();
            return 0;
        }
    } else if (message == WM_LBUTTONUP) {
        POINT screenPoint{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
        ClientToScreen(hwnd, &screenPoint);
        if (PopupPointIsInsideOriginalToggleArea(screenPoint)) {
            return 0;
        }
    } else if (message == WM_MOUSEACTIVATE) {
        return MA_NOACTIVATE;
    } else if (message == WM_NCDESTROY) {
        RemoveWindowSubclass(hwnd, PopupXamlChildSubclassProc,
                             kPopupXamlChildSubclassId);
        if (g_popupXamlChild == hwnd) {
            g_popupXamlChild = nullptr;
            g_popupXamlChildSubclassed = false;
        }
    }

    return DefSubclassProc(hwnd, message, wParam, lParam);
}

void SubclassPopupXamlChildWindow() {
    if (!g_popupXamlChild || g_popupXamlChildSubclassed) {
        return;
    }
    if (SetWindowSubclass(g_popupXamlChild, PopupXamlChildSubclassProc,
                          kPopupXamlChildSubclassId, 0)) {
        g_popupXamlChildSubclassed = true;
    }
}

void UnsubclassPopupXamlChildWindow() {
    if (!g_popupXamlChild || !g_popupXamlChildSubclassed) {
        return;
    }
    RemoveWindowSubclass(g_popupXamlChild, PopupXamlChildSubclassProc,
                         kPopupXamlChildSubclassId);
    g_popupXamlChildSubclassed = false;
}

constexpr int kPopupHiddenParkingX = -32000;
constexpr int kPopupHiddenParkingY = -32000;

void SetPopupWindowClickThrough(HWND hwnd, bool clickThrough) {
    if (!hwnd || !IsWindow(hwnd)) {
        return;
    }

    LONG_PTR style = GetWindowLongPtrW(hwnd, GWL_EXSTYLE);
    LONG_PTR targetStyle =
        clickThrough ? (style | WS_EX_TRANSPARENT)
                     : (style & ~static_cast<LONG_PTR>(WS_EX_TRANSPARENT));
    if (targetStyle != style) {
        SetWindowLongPtrW(hwnd, GWL_EXSTYLE, targetStyle);
    }
}

void ParkPopupWindow(HWND hwnd) {
    if (!hwnd || !IsWindow(hwnd)) {
        return;
    }

    SetWindowPos(hwnd, nullptr, kPopupHiddenParkingX, kPopupHiddenParkingY, 1,
                 1,
                 SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOOWNERZORDER |
                     SWP_NOCOPYBITS | SWP_NOSENDCHANGING | SWP_HIDEWINDOW);
}

void ParkExpandedPopupWindow(HWND hwnd) {
    SetPopupWindowClickThrough(hwnd, true);
    SetPopupWindowClickThrough(g_popupXamlChild, true);
    if (g_popupXamlChild && IsWindow(g_popupXamlChild)) {
        MoveWindow(g_popupXamlChild, 0, 0, 1, 1, FALSE);
    }
    ParkPopupWindow(hwnd);
}

bool PopupShouldExpandRight(MONITORINFO const& monitorInfo) {
    // Prefer the explicit taskbar-position setting over screen-center guessing.
    // In tray placements, the old behavior felt better: tray_left grows from
    // left to right, while the right-side tray placements grow right to left.
    if (g_settings.position == L"tray_left" ||
        g_settings.position == L"taskbar_left_edge") {
        return true;
    }
    if (g_settings.position == L"tray_right" ||
        g_settings.position == L"tray_before_clock" ||
        g_settings.position == L"tray_after_clock" ||
        g_settings.position == L"taskbar_right_edge") {
        return false;
    }

    int sourceCenter = (g_popupSourceRect.left + g_popupSourceRect.right) / 2;
    int monitorCenter =
        (monitorInfo.rcMonitor.left + monitorInfo.rcMonitor.right) / 2;
    return sourceCenter <= monitorCenter;
}

constexpr int kDwmCornerDoNotRound = 1;
constexpr int kDwmBackdropNone = 1;
constexpr DWORD kDwmColorNone = 0xFFFFFFFE;  // DWMWA_COLOR_NONE.
// Required for CreateHostBackdropBrush() in this standalone Win32 XAML host.
// This only enables live background sampling; it doesn't alter geometry,
// corner radii, layout, or the animation state machine.
constexpr DWORD kDwmwaUseHostBackdropBrush = 17;

DWORD PopupNativeBorderColorRef() {
    bool dark = IsDarkModeApprox();
    // DWMWA_BORDER_COLOR takes a COLORREF-style value, not an ARGB color.
    // These values mirror the subtle Windows 11 window outline: a soft gray in
    // dark mode and a bright white edge in light mode.
    return dark ? RGB(74, 74, 82) : RGB(255, 255, 255);
}

void SetPopupDwmAttributes(HWND hwnd,
                           int cornerPreference,
                           int backdropType,
                           bool nativeBorder = false) {
    DWORD borderColor =
        nativeBorder ? PopupNativeBorderColorRef() : kDwmColorNone;
    BOOL dark = IsDarkModeApprox();
    DwmSetWindowAttribute(hwnd, 34, &borderColor, sizeof(borderColor));
    DwmSetWindowAttribute(hwnd, 20, &dark, sizeof(dark));
    DwmSetWindowAttribute(hwnd, 33, &cornerPreference,
                          sizeof(cornerPreference));
    DwmSetWindowAttribute(hwnd, 38, &backdropType, sizeof(backdropType));
}

void SetPopupOverlayNativeFrost(HWND hwnd, bool enabled) {
    if (!hwnd || !IsWindow(hwnd)) {
        return;
    }

    // ACCENT_ENABLE_BLURBEHIND is effectively transparent in Explorer's
    // taskbar window tree. Acrylic is the native path that actually samples
    // and blurs the live desktop here. Keep its policy constant for the whole
    // transition: rebuilding the accent every animation frame caused the
    // bright flashing rectangle artifact.
    int effectiveAlpha = enabled ? 1 : 0;
    if (g_popupBackdropOverlayNativeBlurActive == enabled &&
        g_popupBackdropOverlayNativeFrostAlpha == effectiveAlpha) {
        return;
    }

    struct AccentPolicy {
        int state;
        int flags;
        DWORD gradientColor;
        int animationId;
    };
    struct CompositionAttributeData {
        int attribute;
        void* data;
        SIZE_T size;
    };
    using SetWindowCompositionAttribute_t =
        BOOL(WINAPI*)(HWND, CompositionAttributeData*);

    static auto setWindowCompositionAttribute =
        reinterpret_cast<SetWindowCompositionAttribute_t>(GetProcAddress(
            GetModuleHandleW(L"user32.dll"), "SetWindowCompositionAttribute"));
    if (!setWindowCompositionAttribute) {
        return;
    }

    AccentPolicy policy{
        enabled ? 4 : 0,  // ACCENT_ENABLE_ACRYLICBLURBEHIND / DISABLED.
        enabled ? 2 : 0,
        // A faint neutral gray tint: enough for text readability without the
        // heavy black sheet or the white flare of the previous versions.
        enabled ? static_cast<DWORD>(0x28909090) : 0,
        0,
    };
    CompositionAttributeData data{19, &policy, sizeof(policy)};
    if (setWindowCompositionAttribute(hwnd, &data)) {
        g_popupBackdropOverlayNativeBlurActive = enabled;
        g_popupBackdropOverlayNativeFrostAlpha = effectiveAlpha;
    }
}

void ApplyPopupBackdrop(HWND hwnd) {
    if (g_popupXamlRoot) {
        // C version: the host HWND only carries XAML. All visible material is
        // the same rounded compact-material Border used by the taskbar island.
        // Keep the host HWND visually empty. The only visible outline is the
        // same XAML IslandBorderBrush() stroke used by the compact island.
        SetPopupDwmAttributes(hwnd, kDwmCornerDoNotRound, kDwmBackdropNone,
                              false);
        return;
    }

    struct AccentPolicy {
        int state;
        int flags;
        DWORD gradientColor;
        int animationId;
    };
    struct CompositionAttributeData {
        int attribute;
        void* data;
        SIZE_T size;
    };
    using SetWindowCompositionAttribute_t =
        BOOL(WINAPI*)(HWND, CompositionAttributeData*);

    static auto setWindowCompositionAttribute =
        reinterpret_cast<SetWindowCompositionAttribute_t>(GetProcAddress(
            GetModuleHandleW(L"user32.dll"), "SetWindowCompositionAttribute"));
    if (setWindowCompositionAttribute) {
        bool dark = IsDarkModeApprox();
        AccentPolicy policy{
            4,  // ACCENT_ENABLE_ACRYLICBLURBEHIND.
            2,
            dark ? static_cast<DWORD>(0x702F2A2A)
                 : static_cast<DWORD>(0x78F6F3F3),
            0,
        };
        CompositionAttributeData data{19, &policy, sizeof(policy)};
        setWindowCompositionAttribute(hwnd, &data);
    }
}

RECT PopupButtonRect(int index, int width, int height) {
    RECT localFinal{0, 0, width, height};
    RECT art{}, card{}, title{}, artist{}, progress{}, elapsed{}, duration{},
        controls{};
    CalculatePopupFinalLayout(localFinal, art, card, title, artist, progress,
                              elapsed, duration, controls);

    int buttonSize = Clamp(
        static_cast<int>((controls.right - controls.left - 16) / 3), 30, 38);
    int gap = 8;
    int total = buttonSize * 3 + gap * 2;
    int left = (controls.left + controls.right - total) / 2 +
               index * (buttonSize + gap);
    int top =
        controls.top + ((controls.bottom - controls.top) - buttonSize) / 2;
    return {left, top, left + buttonSize, top + buttonSize};
}

void PaintExpandedPopup(HWND hwnd, HDC dc) {
    RECT client{};
    GetClientRect(hwnd, &client);
    int width = client.right;
    int height = client.bottom;
    if (width <= 0 || height <= 0) {
        return;
    }

    bool dark = IsDarkModeApprox();
    COLORREF primary = dark ? RGB(255, 255, 255) : RGB(0, 0, 0);
    COLORREF secondary = dark ? RGB(190, 190, 196) : RGB(82, 82, 88);
    COLORREF subtle = dark ? RGB(72, 72, 78) : RGB(218, 218, 224);
    double progress = PopupProgress();

    RECT popupScreen{};
    GetWindowRect(hwnd, &popupScreen);
    RECT targetArtScreen{};
    RECT targetCardScreen{};
    RECT targetTitleScreen{};
    RECT targetArtistScreen{};
    RECT targetProgressScreen{};
    RECT targetElapsedScreen{};
    RECT targetDurationScreen{};
    RECT targetControlsScreen{};
    CalculatePopupFinalLayout(
        g_popupFinalRect, targetArtScreen, targetCardScreen, targetTitleScreen,
        targetArtistScreen, targetProgressScreen, targetElapsedScreen,
        targetDurationScreen, targetControlsScreen);
    double artProgress = progress;
    RECT artScreen{
        LerpInt(g_popupSourceArtRect.left, targetArtScreen.left, artProgress),
        LerpInt(g_popupSourceArtRect.top, targetArtScreen.top, artProgress),
        LerpInt(g_popupSourceArtRect.right, targetArtScreen.right, artProgress),
        LerpInt(g_popupSourceArtRect.bottom, targetArtScreen.bottom,
                artProgress),
    };
    RECT artRect{
        artScreen.left - popupScreen.left,
        artScreen.top - popupScreen.top,
        artScreen.right - popupScreen.left,
        artScreen.bottom - popupScreen.top,
    };
    int artSize = std::max(1, static_cast<int>(artRect.right - artRect.left));

    int artRadius = static_cast<int>(kPopupUnifiedCornerRadius);
    HRGN artClip =
        CreateRoundRectRgn(artRect.left, artRect.top, artRect.right + 1,
                           artRect.bottom + 1, artRadius * 2, artRadius * 2);
    int saved = SaveDC(dc);
    SelectClipRgn(dc, artClip);
    if (g_popupAlbumBitmap) {
        HDC source = CreateCompatibleDC(dc);
        HGDIOBJ oldBitmap = SelectObject(source, g_popupAlbumBitmap);
        BLENDFUNCTION blend{AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
        AlphaBlend(dc, artRect.left, artRect.top, artSize, artSize, source, 0,
                   0, 256, 256, blend);
        SelectObject(source, oldBitmap);
        DeleteDC(source);
    } else {
        HBRUSH fallback = CreateSolidBrush(RGB(79, 125, 232));
        FillRect(dc, &artRect, fallback);
        DeleteObject(fallback);
    }
    RestoreDC(dc, saved);
    DeleteObject(artClip);

    MediaState state = SnapshotMedia();
    SetBkMode(dc, TRANSPARENT);
    int titleSize = LerpInt(12, 16, progress);
    int artistSize = LerpInt(10, 13, progress);
    HFONT titleFont = CreateFontW(-titleSize, 0, 0, 0, FW_BOLD, FALSE, FALSE,
                                  FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                  CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                  DEFAULT_PITCH, L"Segoe UI Variable Text");
    HFONT artistFont = CreateFontW(
        -artistSize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
        DEFAULT_PITCH, L"Segoe UI Variable Text");

    RECT titleScreen{
        LerpInt(g_popupSourceTitleRect.left, targetTitleScreen.left, progress),
        LerpInt(g_popupSourceTitleRect.top, targetTitleScreen.top, progress),
        LerpInt(g_popupSourceTitleRect.right, targetTitleScreen.right,
                progress),
        LerpInt(g_popupSourceTitleRect.bottom, targetTitleScreen.bottom,
                progress),
    };
    RECT artistScreen{
        LerpInt(g_popupSourceArtistRect.left, targetArtistScreen.left,
                progress),
        LerpInt(g_popupSourceArtistRect.top, targetArtistScreen.top, progress),
        LerpInt(g_popupSourceArtistRect.right, targetArtistScreen.right,
                progress),
        LerpInt(g_popupSourceArtistRect.bottom, targetArtistScreen.bottom,
                progress),
    };
    RECT titleRect{titleScreen.left - popupScreen.left,
                   titleScreen.top - popupScreen.top,
                   titleScreen.right - popupScreen.left,
                   titleScreen.bottom - popupScreen.top};
    RECT artistRect{artistScreen.left - popupScreen.left,
                    artistScreen.top - popupScreen.top,
                    artistScreen.right - popupScreen.left,
                    artistScreen.bottom - popupScreen.top};
    HGDIOBJ oldFont = SelectObject(dc, titleFont);
    SetTextColor(dc, primary);
    std::wstring title = state.hasSession ? state.title : DefaultIdleTitle();
    DrawTextW(dc, title.c_str(), -1, &titleRect,
              DT_LEFT | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS);

    SelectObject(dc, artistFont);
    SetTextColor(dc, secondary);
    std::wstring artist =
        !state.hasSession
            ? DefaultIdleArtist()
            : (state.artist.empty()
                   ? std::wstring(state.isPlaying ? L"Playing" : L"Paused")
                   : state.artist);
    DrawTextW(dc, artist.c_str(), -1, &artistRect,
              DT_LEFT | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS);

    if (progress >= 0.45) {
        RECT progressTrack{targetProgressScreen.left - popupScreen.left,
                           targetProgressScreen.top - popupScreen.top,
                           targetProgressScreen.right - popupScreen.left,
                           targetProgressScreen.bottom - popupScreen.top};
        HBRUSH trackBrush = CreateSolidBrush(subtle);
        FillRect(dc, &progressTrack, trackBrush);
        DeleteObject(trackBrush);
        double ratio = state.durationTicks > 0
                           ? Clamp(static_cast<double>(state.positionTicks) /
                                       static_cast<double>(state.durationTicks),
                                   0.0, 1.0)
                           : 0.0;
        RECT progressValue = progressTrack;
        progressValue.right =
            progressValue.left +
            static_cast<int>((progressTrack.right - progressTrack.left) *
                             ratio);
        HBRUSH valueBrush =
            CreateSolidBrush(dark ? RGB(242, 242, 245) : RGB(42, 42, 46));
        FillRect(dc, &progressValue, valueBrush);
        DeleteObject(valueBrush);

        HFONT iconFont = CreateFontW(-16, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE,
                                     FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                     CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                     DEFAULT_PITCH, L"Segoe Fluent Icons");
        SelectObject(dc, iconFont);
        const wchar_t* glyphs[] = {
            L"\uEB9E", state.isPlaying ? L"\uE769" : L"\uE768", L"\uEB9D"};
        for (int i = 0; i < 3; ++i) {
            RECT button = PopupButtonRect(i, width, height);
            SetTextColor(dc, primary);
            DrawTextW(dc, glyphs[i], -1, &button,
                      DT_CENTER | DT_SINGLELINE | DT_VCENTER);
        }
        SelectObject(dc, oldFont);
        DeleteObject(iconFont);
    }

    SelectObject(dc, oldFont);
    DeleteObject(artistFont);
    DeleteObject(titleFont);
}

// ===== Popup controls and theming =====
bool PopupButtonStyleIs(std::wstring_view style) {
    return std::wstring_view(g_settings.popupButtonStyle) == style;
}

bool IsPopupPrimaryButton(Border const& surface) {
    try {
        return winrt::unbox_value_or<winrt::hstring>(
                   surface.Tag(), winrt::hstring{}) == L"primary";
    } catch (...) {
        return false;
    }
}

winrt::hstring PopupTransportGlyph(Border const& surface,
                                   bool playing,
                                   bool favorite) {
    std::wstring name(surface.Name());
    if (name == L"Popup_Prev") {
        return winrt::hstring(L"\uEB9E");
    }
    if (name == L"Popup_Next") {
        return winrt::hstring(L"\uEB9D");
    }
    if (name == L"Popup_Favorite") {
        return favorite ? winrt::hstring(L"\uE00C") : winrt::hstring(L"\uE00B");
    }
    return playing ? winrt::hstring(L"\uE769") : winrt::hstring(L"\uE768");
}

void UpdatePopupTransportButtonGlyph(Border const& surface,
                                     bool playing,
                                     bool favorite) {
    if (auto icon = surface.Child().try_as<controls::FontIcon>()) {
        icon.Glyph(PopupTransportGlyph(surface, playing, favorite));
    } else if (auto text = surface.Child().try_as<TextBlock>()) {
        text.Text(PopupTransportGlyph(surface, playing, favorite));
    }
}

void ApplyOptimisticPlaybackToggle() {
    struct PlaybackUiState {
        bool playing;
        bool favorite;
    } uiState{};

    {
        std::lock_guard lock(g_mediaMutex);
        if (!g_media.hasSession) {
            return;
        }
        auto now = std::chrono::steady_clock::now();
        g_media.isPlaying = !g_media.isPlaying;
        g_mediaStateTimestamp = now;
        g_optimisticPlaybackPending = true;
        g_optimisticPlaybackDesired = g_media.isPlaying;
        g_optimisticPlaybackSource = g_media.sourceAppUserModelId;
        g_optimisticPlaybackUntil = now + std::chrono::seconds(2);
        uiState.playing = g_media.isPlaying;
        uiState.favorite = g_media.isFavorite;
    }

    HWND hwnd = g_taskbarWnd && IsWindow(g_taskbarWnd)
                    ? g_taskbarWnd
                    : FindCurrentProcessTaskbarWnd();
    if (!hwnd) {
        return;
    }
    RunFromWindowThread(
        hwnd,
        [](void* param) {
            if (!IsModActive()) {
                return;
            }
            auto const& state =
                *reinterpret_cast<PlaybackUiState const*>(param);
            if (g_playerGrid) {
                if (auto playFe =
                        FindChildByName(g_playerGrid, L"Island_Play")) {
                    if (auto button = playFe.try_as<Button>()) {
                        if (auto icon = button.Content().try_as<TextBlock>()) {
                            icon.Text(state.playing ? L"\uE769" : L"\uE768");
                        }
                    }
                }
                SetCompactPlaybackIndicatorState(state.playing);
            }
            if (g_popupXamlControls) {
                for (auto const& child : g_popupXamlControls.Children()) {
                    if (auto surface = child.try_as<Border>()) {
                        UpdatePopupTransportButtonGlyph(surface, state.playing,
                                                        state.favorite);
                    }
                }
            }
        },
        &uiState);
}

double PopupControlsWidth() {
    return 168.0;
}

double PopupControlsHeight() {
    return 60.0;
}

double PopupButtonWidth() {
    return 52.0;
}

double PopupButtonHeight() {
    return 58.0;
}

double PopupButtonTop() {
    return (PopupControlsHeight() - PopupButtonHeight()) * 0.5;
}

double PopupButtonLeft(int index) {
    return 2.0 + 56.0 * static_cast<double>(index);
}

mediax::Brush PopupButtonHoverBrush(bool dark) {
    return Brush(dark ? Color(0x26, 0xFF, 0xFF, 0xFF)
                      : Color(0x18, 0x00, 0x00, 0x00));
}

void ApplyPopupButtonVisual(Border const& surface, bool hovered = false) {
    bool dark = IsDarkModeApprox();
    bool primary = IsPopupPrimaryButton(surface);
    auto primaryText =
        dark ? Color(0xFF, 0xFF, 0xFF, 0xFF) : Color(0xFF, 0x00, 0x00, 0x00);

    double width = PopupButtonWidth();
    double height = PopupButtonHeight();
    double corner = std::min(height * 0.5, kPopupG2ButtonCornerRadius);
    double fontSize = primary ? 34.0 : 30.0;
    mediax::Brush background = hovered ? PopupButtonHoverBrush(dark)
                                       : Brush(Color(0x00, 0x00, 0x00, 0x00));
    mediax::Brush foreground = Brush(primaryText);

    if (PopupButtonStyleIs(L"fluent_bold")) {
        fontSize = primary ? 38.0 : 32.0;
    }

    surface.Width(width);
    surface.Height(height);
    surface.Visibility(Visibility::Visible);
    surface.CornerRadius({corner, corner, corner, corner});
    surface.Background(background);
    surface.BorderThickness({0, 0, 0, 0});
    surface.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));

    MediaState state = SnapshotMedia();
    if (auto icon = surface.Child().try_as<controls::FontIcon>()) {
        icon.Visibility(Visibility::Visible);
        icon.Opacity(1.0);
        icon.Width(width);
        icon.Height(height);
        icon.Margin({0, 0, 0, 0});
        icon.HorizontalAlignment(HorizontalAlignment::Center);
        icon.VerticalAlignment(VerticalAlignment::Center);
        icon.Glyph(
            PopupTransportGlyph(surface, state.isPlaying, state.isFavorite));
        icon.Foreground(foreground);
        icon.FontFamily(mediax::FontFamily(L"Segoe Fluent Icons"));
        icon.FontSize(fontSize);
        icon.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
    } else if (auto text = surface.Child().try_as<TextBlock>()) {
        text.Visibility(Visibility::Visible);
        text.Opacity(1.0);
        text.Width(width);
        text.Height(height);
        text.Margin({0, 0, 0, 0});
        text.HorizontalAlignment(HorizontalAlignment::Stretch);
        text.VerticalAlignment(VerticalAlignment::Center);
        text.TextAlignment(xaml::TextAlignment::Center);
        text.Text(
            PopupTransportGlyph(surface, state.isPlaying, state.isFavorite));
        text.Foreground(foreground);
        text.FontFamily(mediax::FontFamily(L"Segoe Fluent Icons"));
        text.FontSize(fontSize);
        text.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
    }
}

Border MakePopupXamlButton(const wchar_t* name,
                           void (*onClick)(),
                           bool primary = false) {
    Border surface;
    surface.Name(name);
    surface.Margin({0, 0, 0, 0});
    surface.Padding({0, 0, 0, 0});
    surface.Tag(
        winrt::box_value(winrt::hstring(primary ? L"primary" : L"secondary")));
    surface.IsHitTestVisible(true);

    controls::FontIcon icon;
    icon.FontFamily(mediax::FontFamily(L"Segoe Fluent Icons"));
    icon.Glyph(PopupTransportGlyph(surface, false, false));
    icon.HorizontalAlignment(HorizontalAlignment::Center);
    icon.VerticalAlignment(VerticalAlignment::Center);
    surface.Child(icon);
    ApplyPopupButtonVisual(surface, false);

    surface.PointerEntered(
        [](auto const& sender, input::PointerRoutedEventArgs const&) {
            if (auto border = sender.template try_as<Border>()) {
                ApplyPopupButtonVisual(border, true);
            }
        });
    surface.PointerExited(
        [](auto const& sender, input::PointerRoutedEventArgs const&) {
            if (auto border = sender.template try_as<Border>()) {
                ApplyPopupButtonVisual(border, false);
            }
        });
    surface.PointerPressed(
        [](auto const& sender, input::PointerRoutedEventArgs const& args) {
            if (auto border = sender.template try_as<Border>()) {
                border.Opacity(0.82);
            }
            args.Handled(true);
        });
    surface.PointerReleased(
        [onClick](auto const& sender,
                  input::PointerRoutedEventArgs const& args) {
            if (auto border = sender.template try_as<Border>()) {
                border.Opacity(1.0);
                ApplyPopupButtonVisual(border, false);
            }
            onClick();
            args.Handled(true);
        });
    surface.PointerCanceled(
        [](auto const& sender, input::PointerRoutedEventArgs const&) {
            if (auto border = sender.template try_as<Border>()) {
                border.Opacity(1.0);
                ApplyPopupButtonVisual(border, false);
            }
        });
    return surface;
}

void InitializePopupCompositionShadow();
void ApplyPopupDynamicAccentVisuals();
void UpdatePopupSeekPreview(double ratio);
void EndPopupSeek(bool commit);

void ApplyPopupXamlTheme(bool force = false) {
    if (!g_popupXamlPanel) {
        return;
    }

    bool dark = IsDarkModeApprox();
    if (!force && g_popupXamlThemeValid && g_popupXamlThemeDark == dark &&
        g_popupXamlThemeMaterial == g_settings.material &&
        g_popupXamlThemeButtonStyle == g_settings.popupButtonStyle &&
        g_popupXamlThemeShadowDepth == PopupShadowDepth() &&
        g_popupXamlThemeShadowOpacity == PopupShadowOpacityPercent()) {
        return;
    }
    g_popupXamlThemeValid = true;
    g_popupXamlThemeDark = dark;
    g_popupXamlThemeMaterial = g_settings.material;
    g_popupXamlThemeButtonStyle = g_settings.popupButtonStyle;
    g_popupXamlThemeShadowDepth = PopupShadowDepth();
    g_popupXamlThemeShadowOpacity = PopupShadowOpacityPercent();
    if (g_popupXamlShadow) {
        g_popupXamlShadow.Background(PopupShadowBrush());
        g_popupXamlShadow.BorderThickness({0, 0, 0, 0});
    }
    if (g_popupXamlBackdrop) {
        if (IsLiquidGlassMaterial()) {
            // Keep the live Gaussian backdrop brush attached during theme
            // refreshes; UpdatePopupXamlVisuals swaps it to the solid compact
            // recipe only when the morph reaches the compact endpoint.
            EnsurePopupLiquidGlassBlur(g_popupXamlBackdrop, true);
        } else {
            ApplyCompactSurfaceVisual(g_popupXamlBackdrop);
        }
        InitializePopupCompositionShadow();
    }
    if (g_popupXamlBackdropTint) {
        g_popupXamlBackdropTint.Background(PopupBackdropCardTintBrush());
        g_popupXamlBackdropTint.BorderThickness({0, 0, 0, 0});
    }
    if (g_popupXamlBackdropSurfaceHighlight) {
        g_popupXamlBackdropSurfaceHighlight.Background(
            LiquidGlassSurfaceHighlightBrush());
        g_popupXamlBackdropSurfaceHighlight.BorderThickness({0, 0, 0, 0});
    }
    if (g_popupXamlBackdropRimHighlight) {
        g_popupXamlBackdropRimHighlight.Background(
            Brush(Color(0x00, 0x00, 0x00, 0x00)));
        g_popupXamlBackdropRimHighlight.BorderBrush(
            LiquidGlassRimHighlightBrush());
        g_popupXamlBackdropRimHighlight.BorderThickness(
            IsLiquidGlassMaterial() ? Thickness{1.0, 1.0, 1.0, 1.0}
                                    : Thickness{0.0, 0.0, 0.0, 0.0});
    }
    if (g_popupXamlDropShadow) {
        float strength =
            static_cast<float>(PopupShadowOpacityPercent()) / 100.0f;
        g_popupXamlDropShadow.BlurRadius(
            28.0f + static_cast<float>(PopupShadowDepth()) * 0.35f);
        g_popupXamlDropShadow.Opacity((dark ? 0.70f : 0.56f) * strength);
        g_popupXamlDropShadow.Offset(
            {0.0f, 6.0f + static_cast<float>(PopupShadowDepth()) * 0.08f,
             0.0f});
        g_popupXamlDropShadow.Color(Color(0xFF, 0x00, 0x00, 0x00));
    }
    if (g_popupXamlPanelCoverFrame) {
        g_popupXamlPanelCoverFrame.Background(
            Brush(Color(0x00, 0x00, 0x00, 0x00)));
        g_popupXamlPanelCoverFrame.BorderThickness({0, 0, 0, 0});
        g_popupXamlPanelCoverFrame.BorderBrush(
            Brush(Color(0x00, 0x00, 0x00, 0x00)));
    }
    if (g_popupXamlArtFrame) {
        g_popupXamlArtFrame.BorderThickness({0.0, 0.0, 0.0, 0.0});
        g_popupXamlArtFrame.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    }
    // The reference uses one uninterrupted glass sheet. Text and controls sit
    // directly on it; there is no second rectangular card below the artwork.
    g_popupXamlPanel.Background(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    g_popupXamlPanel.BorderThickness({0, 0, 0, 0});
    g_popupXamlPanel.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    ConfigurePopupTextEdgeFade(g_popupXamlTitleLeftFade, true, 1.0);
    ConfigurePopupTextEdgeFade(g_popupXamlTitleRightFade, false, 1.0);
    ConfigurePopupTextEdgeFade(g_popupXamlArtistLeftFade, true, 1.0);
    ConfigurePopupTextEdgeFade(g_popupXamlArtistRightFade, false, 1.0);
    ConfigurePopupTextEdgeFade(g_popupXamlOutgoingTitleLeftFade, true, 1.0);
    ConfigurePopupTextEdgeFade(g_popupXamlOutgoingTitleRightFade, false, 1.0);
    ConfigurePopupTextEdgeFade(g_popupXamlOutgoingArtistLeftFade, true, 1.0);
    ConfigurePopupTextEdgeFade(g_popupXamlOutgoingArtistRightFade, false, 1.0);

    ApplyPopupTextForegrounds(false, true);

    auto accent = PopupAccentColor();
    auto accentBrush = Brush(accent);
    auto vividGlow = PopupProgressVividColor();
    auto softCore = PopupProgressBrightSoftColor();
    if (g_popupXamlProgress) {
        g_popupXamlProgress.Foreground(accentBrush);
        g_popupXamlProgress.Background(
            Brush(dark ? Color(0x00, 0xFF, 0xFF, 0xFF)
                       : Color(0x00, 0x00, 0x00, 0x00)));
    }
    if (g_popupXamlProgressTrack) {
        g_popupXamlProgressTrack.Background(
            Brush(dark ? Color(0x34, 0xFF, 0xFF, 0xFF)
                       : Color(0x24, 0x00, 0x00, 0x00)));
    }
    if (g_popupXamlProgressFill) {
        g_popupXamlProgressFill.Background(MakePopupProgressGradientBrush());
    }
    for (size_t i = 0; i < g_popupXamlProgressGlowLayers.size(); ++i) {
        static constexpr BYTE kAlpha[] = {0x14, 0x20, 0x32, 0x4A, 0x68, 0x86};
        BYTE a = kAlpha[std::min(i, (sizeof(kAlpha) / sizeof(kAlpha[0])) - 1)];
        g_popupXamlProgressGlowLayers[i].Background(
            Brush(Color(a, vividGlow.R, vividGlow.G, vividGlow.B)));
        g_popupXamlProgressGlowLayers[i].BorderThickness({0, 0, 0, 0});
    }
    for (size_t i = 0; i < g_popupXamlProgressCoreBlurLayers.size(); ++i) {
        static constexpr BYTE kAlpha[] = {0x08, 0x0E, 0x16, 0x24, 0x38, 0x58};
        BYTE a = kAlpha[std::min(i, (sizeof(kAlpha) / sizeof(kAlpha[0])) - 1)];
        g_popupXamlProgressCoreBlurLayers[i].Background(
            Brush(Color(a, softCore.R, softCore.G, softCore.B)));
        g_popupXamlProgressCoreBlurLayers[i].BorderThickness({0, 0, 0, 0});
    }
    if (g_popupXamlProgressGlowCore) {
        g_popupXamlProgressGlowCore.Background(
            Brush(Color(0xFF, softCore.R, softCore.G, softCore.B)));
        g_popupXamlProgressGlowCore.BorderThickness({0, 0, 0, 0});
    }
    if (g_popupXamlControls) {
        for (auto const& child : g_popupXamlControls.Children()) {
            if (auto buttonSurface = child.try_as<Border>()) {
                buttonSurface.Opacity(1.0);
                ApplyPopupButtonVisual(buttonSurface, false);
            }
        }
    }
    if (g_popupXamlVolumeTrack) {
        g_popupXamlVolumeTrack.Background(
            Brush(dark ? Color(0x50, 0xFF, 0xFF, 0xFF)
                       : Color(0x38, 0x00, 0x00, 0x00)));
    }
    if (g_popupXamlVolumeFill) {
        g_popupXamlVolumeFill.Background(
            Brush(dark ? Color(0xE8, 0xFF, 0xFF, 0xFF)
                       : Color(0xD8, 0x18, 0x18, 0x1B)));
    }
    auto volumeIconBrush = Brush(dark ? Color(0xD8, 0xFF, 0xFF, 0xFF)
                                      : Color(0xC8, 0x18, 0x18, 0x1B));
    if (auto icon = g_popupXamlVolumeLowIcon.try_as<controls::FontIcon>()) {
        icon.Foreground(volumeIconBrush);
    }
    if (auto icon = g_popupXamlVolumeHighIcon.try_as<controls::FontIcon>()) {
        icon.Foreground(volumeIconBrush);
    }
    ApplyPopupDynamicAccentVisuals();
}

void ApplyPopupDynamicAccentVisuals() {
    auto accent = PopupAccentColor();
    auto accentBrush = Brush(accent);
    bool dark = IsDarkModeApprox();
    if (g_popupXamlArtFrame) {
        g_popupXamlArtFrame.BorderBrush(PopupAlbumArtStrokeBrush());
    }
    if (g_popupXamlProgress) {
        g_popupXamlProgress.Foreground(accentBrush);
        g_popupXamlProgress.Background(
            Brush(dark ? Color(0x30, 0xFF, 0xFF, 0xFF)
                       : Color(0x22, 0x00, 0x00, 0x00)));
    }
    if (g_popupXamlProgressFill) {
        g_popupXamlProgressFill.Background(MakePopupProgressGradientBrush());
    }
    auto vividGlow = PopupProgressVividColor();
    auto softCore = PopupProgressBrightSoftColor();
    for (size_t i = 0; i < g_popupXamlProgressGlowLayers.size(); ++i) {
        static constexpr BYTE kAlpha[] = {0x14, 0x20, 0x32, 0x4A, 0x68, 0x86};
        BYTE a = kAlpha[std::min(i, (sizeof(kAlpha) / sizeof(kAlpha[0])) - 1)];
        g_popupXamlProgressGlowLayers[i].Background(
            Brush(Color(a, vividGlow.R, vividGlow.G, vividGlow.B)));
        g_popupXamlProgressGlowLayers[i].BorderThickness({0, 0, 0, 0});
    }
    for (size_t i = 0; i < g_popupXamlProgressCoreBlurLayers.size(); ++i) {
        static constexpr BYTE kAlpha[] = {0x08, 0x0E, 0x16, 0x24, 0x38, 0x58};
        BYTE a = kAlpha[std::min(i, (sizeof(kAlpha) / sizeof(kAlpha[0])) - 1)];
        g_popupXamlProgressCoreBlurLayers[i].Background(
            Brush(Color(a, softCore.R, softCore.G, softCore.B)));
        g_popupXamlProgressCoreBlurLayers[i].BorderThickness({0, 0, 0, 0});
    }
    if (g_popupXamlProgressGlowCore) {
        g_popupXamlProgressGlowCore.Background(
            Brush(Color(0xFF, softCore.R, softCore.G, softCore.B)));
        g_popupXamlProgressGlowCore.BorderThickness({0, 0, 0, 0});
    }
    if (g_popupXamlControls) {
        for (auto const& child : g_popupXamlControls.Children()) {
            if (auto buttonSurface = child.try_as<Border>()) {
                ApplyPopupButtonVisual(buttonSurface, false);
            }
        }
    }
}

void ApplyPopupMediaTransitionVisuals() {
    // Use a higher-order easing and a longer transition window so artwork,
    // album-wash, accent and text changes feel less abrupt during track switches.
    double fade =
        g_popupMediaTransitionActive
            ? SmootherStep(Clamp(g_popupMediaTransitionProgress, 0.0, 1.0))
            : 1.0;

    // Only fade artwork and album-wash layers when the artwork source really
    // changed. Text-only or accent-only transitions should not dim the cover;
    // otherwise a brief empty thumbnail state during track switches exposes the
    // placeholder/background as a visible flash.
    bool coverTransitionActive =
        g_popupCoverTransitionActive && g_popupMediaTransitionActive;
    double coverFade = coverTransitionActive ? fade : 1.0;
    double backdropWashProgress =
        g_popupClosing
            ? SmootherStep(Clamp((PopupProgress() - 0.001) / 0.065, 0.0, 1.0))
            : 1.0;
    if (g_popupXamlArt) {
        g_popupXamlArt.Opacity(coverFade);
    }
    if (g_popupXamlArtFade) {
        g_popupXamlArtFade.Opacity(coverTransitionActive ? (1.0 - fade) : 0.0);
    }
    bool backdropCoverEnabled = PopupBackdropCoverEffectEnabled();
    if (g_popupXamlBackdropCover) {
        g_popupXamlBackdropCover.Opacity(
            backdropCoverEnabled ? coverFade * backdropWashProgress : 0.0);
    }
    if (g_popupXamlBackdropCoverFade) {
        g_popupXamlBackdropCoverFade.Opacity(
            backdropCoverEnabled && coverTransitionActive
                ? (1.0 - fade) * backdropWashProgress
                : 0.0);
    }
    if (g_popupXamlPanelCover) {
        g_popupXamlPanelCover.Opacity(PopupPanelCoverEffectEnabled() ? coverFade
                                                                     : 0.0);
    }
    if (g_popupXamlPanelCoverFade) {
        g_popupXamlPanelCoverFade.Opacity(PopupPanelCoverEffectEnabled() &&
                                                  coverTransitionActive
                                              ? (1.0 - fade)
                                              : 0.0);
    }

    // Expanded-view text uses the same reversed direction as the compact island:
    // old title/artist slide left and fade out, while new title/artist slide in
    // from the right. The artist starts slightly later than the title.
    constexpr double kPopupTextSlideOffset = 28.0;
    if (g_popupTextTransitionActive) {
        double p = Clamp(g_popupMediaTransitionProgress, 0.0, 1.0);
        double titleIn =
            PopupTextMotionEase(Clamp((p - 0.02) / 0.92, 0.0, 1.0));
        double artistIn =
            PopupTextMotionEase(Clamp((p - 0.28) / 0.70, 0.0, 1.0));
        double titleOut =
            PopupTextMotionEase(Clamp((p + 0.02) / 0.84, 0.0, 1.0));
        double artistOut =
            PopupTextMotionEase(Clamp((p - 0.12) / 0.80, 0.0, 1.0));

        if (g_popupXamlTitleTranslate) {
            g_popupXamlTitleTranslate.X(kPopupTextSlideOffset *
                                        g_popupTextTransitionDirection *
                                        (1.0 - titleIn));
        }
        if (g_popupXamlArtistTranslate) {
            g_popupXamlArtistTranslate.X(kPopupTextSlideOffset *
                                         g_popupTextTransitionDirection *
                                         (1.0 - artistIn));
        }
        if (g_popupXamlTitle) {
            g_popupXamlTitle.Opacity(g_popupTextBaseOpacity * titleIn);
        }
        if (g_popupXamlArtist) {
            g_popupXamlArtist.Opacity(g_popupTextBaseOpacity * artistIn);
        }

        if (g_popupXamlOutgoingTitleTranslate) {
            g_popupXamlOutgoingTitleTranslate.X(-kPopupTextSlideOffset *
                                                g_popupTextTransitionDirection *
                                                titleOut);
        }
        if (g_popupXamlOutgoingArtistTranslate) {
            g_popupXamlOutgoingArtistTranslate.X(
                -kPopupTextSlideOffset * g_popupTextTransitionDirection *
                artistOut);
        }
        if (g_popupXamlOutgoingTitle) {
            g_popupXamlOutgoingTitle.Opacity(g_popupTextBaseOpacity *
                                             (1.0 - titleOut));
        }
        if (g_popupXamlOutgoingArtist) {
            g_popupXamlOutgoingArtist.Opacity(g_popupTextBaseOpacity *
                                              (1.0 - artistOut));
        }
        double popupEdgeFadeIn =
            PopupTextMotionEase(Clamp((p - 0.08) / 0.20, 0.0, 1.0));
        double popupEdgeFadeOut =
            1.0 - PopupTextMotionEase(Clamp((p - 0.72) / 0.22, 0.0, 1.0));
        double popupEdgeFade = popupEdgeFadeIn * popupEdgeFadeOut;
        ApplyPopupTextForegroundFade(popupEdgeFade < 0.01 ? 0.0
                                                          : popupEdgeFade);
        SetPopupTextEdgeFadeOpacity(0.0);
    } else {
        if (g_popupXamlTitleTranslate)
            g_popupXamlTitleTranslate.X(0.0);
        if (g_popupXamlArtistTranslate)
            g_popupXamlArtistTranslate.X(0.0);
        if (g_popupXamlOutgoingTitleTranslate)
            g_popupXamlOutgoingTitleTranslate.X(0.0);
        if (g_popupXamlOutgoingArtistTranslate)
            g_popupXamlOutgoingArtistTranslate.X(0.0);
        if (g_popupXamlOutgoingTitle)
            g_popupXamlOutgoingTitle.Opacity(0.0);
        if (g_popupXamlOutgoingArtist)
            g_popupXamlOutgoingArtist.Opacity(0.0);
        ApplyPopupTextForegrounds(false);
        SetPopupTextEdgeFadeOpacity(0.0);
    }
}

void TickPopupMediaTransition(double dt) {
    if (!g_popupMediaTransitionActive) {
        ApplyPopupMediaTransitionVisuals();
        return;
    }

    g_popupMediaTransitionProgress =
        Clamp(g_popupMediaTransitionProgress + dt * 8.0, 0.0, 1.0);
    double eased = SmootherStep(g_popupMediaTransitionProgress);
    g_popupDisplayedAccentColor = LerpColor(g_popupAccentTransitionFrom,
                                            g_popupAccentTransitionTo, eased);
    g_popupDisplayedAccentColorValid = true;
    ApplyPopupDynamicAccentVisuals();
    ApplyPopupMediaTransitionVisuals();

    if (g_popupMediaTransitionProgress >= 1.0) {
        g_popupMediaTransitionActive = false;
        g_popupCoverTransitionActive = false;
        g_popupDisplayedAccentColor = g_popupAccentTransitionTo;
        g_popupDisplayedAccentColorValid = true;
        if (g_popupXamlArtFade) {
            g_popupXamlArtFade.Source(nullptr);
            g_popupXamlArtFade.Opacity(0.0);
        }
        if (g_popupXamlBackdropCoverFade) {
            g_popupXamlBackdropCoverFade.Source(nullptr);
            g_popupXamlBackdropCoverFade.Opacity(0.0);
        }
        if (g_popupXamlPanelCoverFade) {
            g_popupXamlPanelCoverFade.Source(nullptr);
            g_popupXamlPanelCoverFade.Opacity(0.0);
        }
        g_popupTextTransitionActive = false;
        if (g_popupXamlOutgoingTitle) {
            g_popupXamlOutgoingTitle.Opacity(0.0);
        }
        if (g_popupXamlOutgoingArtist) {
            g_popupXamlOutgoingArtist.Opacity(0.0);
        }
        if (g_popupXamlTitleTranslate)
            g_popupXamlTitleTranslate.X(0.0);
        if (g_popupXamlArtistTranslate)
            g_popupXamlArtistTranslate.X(0.0);
        if (g_popupXamlOutgoingTitleTranslate)
            g_popupXamlOutgoingTitleTranslate.X(0.0);
        if (g_popupXamlOutgoingArtistTranslate)
            g_popupXamlOutgoingArtistTranslate.X(0.0);
        ApplyPopupDynamicAccentVisuals();
        ApplyPopupMediaTransitionVisuals();
    }
}

void InitializePopupCompositionShadow() {
    // UWP XAML Border in Windhawk does not expose GetAlphaMask(), so an
    // unmasked Composition DropShadow would cast a rectangular shadow for the
    // transparent host bounds. Use XAML ThemeShadow on the rounded surface
    // instead. Main.PopupShadowDepth controls ThemeShadow depth/strength;
    // set it to 0 to disable the native shadow entirely.
    g_popupXamlShadowVisual = nullptr;
    g_popupXamlDropShadow = nullptr;
    if (!g_popupXamlBackdrop) {
        return;
    }

    try {
        int depth = static_cast<int>(
            std::lround(PopupShadowDepth() *
                        (0.25 + 1.75 * PopupShadowOpacityPercent() / 100.0)));
        if (PopupShadowDepth() <= 0 || PopupShadowOpacityPercent() <= 0 ||
            depth <= 0) {
            g_popupXamlBackdrop.Shadow(mediax::Shadow{nullptr});
            g_popupXamlBackdrop.Translation(
                winrt::Windows::Foundation::Numerics::float3{0.0f, 0.0f, 0.0f});
            return;
        }

        mediax::ThemeShadow nativeShadow;
        try {
            if (g_popupXamlRoot) {
                nativeShadow.Receivers().Append(g_popupXamlRoot);
            }
        } catch (...) {
        }
        g_popupXamlBackdrop.Shadow(nativeShadow);
        g_popupXamlBackdrop.Translation(
            winrt::Windows::Foundation::Numerics::float3{0.0f, 0.0f, 0.0f});
    } catch (...) {
    }
}

void ResetPopupXamlElementState() {
    UnsubclassPopupXamlChildWindow();
    g_popupXamlSource = nullptr;
    g_popupXamlChild = nullptr;
    g_popupXamlChildSubclassed = false;
    g_popupXamlChildCaptureExcluded = false;
    g_popupXamlRoot = nullptr;
    g_popupXamlCanvas = nullptr;
    g_popupXamlShadow = nullptr;
    g_popupXamlShadowVisual = nullptr;
    g_popupXamlDropShadow = nullptr;
    g_popupXamlBackdrop = nullptr;
    g_popupXamlBackdropScale = nullptr;
    g_popupXamlBackdropTranslate = nullptr;
    g_popupXamlBackdropCoverFade = nullptr;
    g_popupXamlBackdropCover = nullptr;
    g_popupXamlBackdropTint = nullptr;
    g_popupXamlBackdropSurfaceHighlight = nullptr;
    g_popupXamlBackdropRimHighlight = nullptr;
    g_popupXamlPanelCoverFrame = nullptr;
    g_popupXamlPanelCoverScale = nullptr;
    g_popupXamlPanelCoverTranslate = nullptr;
    g_popupXamlPanelCoverFade = nullptr;
    g_popupXamlPanelCover = nullptr;
    g_popupXamlPanel = nullptr;
    g_popupXamlPanelScale = nullptr;
    g_popupXamlPanelTranslate = nullptr;
    g_popupXamlArtFrame = nullptr;
    g_popupXamlArtClipGeometry = nullptr;
    g_popupXamlArtGeometricClip = nullptr;
    g_popupXamlArtScale = nullptr;
    g_popupXamlArtTranslate = nullptr;
    g_popupXamlArtFade = nullptr;
    g_popupXamlArt = nullptr;
    g_popupXamlTitleHost = nullptr;
    g_popupXamlArtistHost = nullptr;
    g_popupXamlPlaybackIndicator = nullptr;
    g_popupXamlPlaybackBars.clear();
    g_popupXamlPlaybackAccentBrush = nullptr;
    g_popupXamlPlaybackRevealClip = nullptr;
    g_popupXamlCompactHoverScale = nullptr;
    g_popupXamlOutgoingTitleHost = nullptr;
    g_popupXamlOutgoingArtistHost = nullptr;
    g_popupXamlTitleLeftFade = nullptr;
    g_popupXamlTitleRightFade = nullptr;
    g_popupXamlArtistLeftFade = nullptr;
    g_popupXamlArtistRightFade = nullptr;
    g_popupXamlOutgoingTitleLeftFade = nullptr;
    g_popupXamlOutgoingTitleRightFade = nullptr;
    g_popupXamlOutgoingArtistLeftFade = nullptr;
    g_popupXamlOutgoingArtistRightFade = nullptr;
    g_popupTextForegroundValid = false;
    g_popupTextForegroundEdgeFade = false;
    g_popupTextForegroundDark = false;
    g_popupTextForegroundEdgeFadeAmount = -1.0;

    g_popupXamlTitle = nullptr;
    g_popupXamlArtist = nullptr;
    g_popupXamlOutgoingTitle = nullptr;
    g_popupXamlOutgoingArtist = nullptr;
    g_popupXamlTitleTranslate = nullptr;
    g_popupXamlArtistTranslate = nullptr;
    g_popupXamlOutgoingTitleTranslate = nullptr;
    g_popupXamlOutgoingArtistTranslate = nullptr;
    g_popupTextBaseOpacity = 1.0;
    g_popupTextTransitionActive = false;
    g_popupXamlElapsed = nullptr;
    g_popupXamlDuration = nullptr;
    g_popupXamlProgress = nullptr;
    g_popupXamlProgressScale = nullptr;
    g_popupXamlProgressTrack = nullptr;
    g_popupXamlProgressFill = nullptr;
    g_popupXamlProgressHitTarget = nullptr;
    g_popupXamlProgressGlowMask = nullptr;
    g_popupXamlProgressGlowClip = nullptr;
    g_popupXamlProgressGlowLayers.clear();
    g_popupXamlProgressCoreBlurLayers.clear();
    g_popupXamlProgressGlowCore = nullptr;
    g_popupXamlControls = nullptr;
    g_popupXamlVolumeTrack = nullptr;
    g_popupXamlVolumeFill = nullptr;
    g_popupXamlVolumeHitTarget = nullptr;
    g_popupXamlVolumeLowIcon = nullptr;
    g_popupXamlVolumeHighIcon = nullptr;
    g_popupVolumeDragging = false;
    g_popupXamlThumbnailHash = UINT64_MAX;
    g_popupXamlBackdropCoverEnabled = false;
    g_popupAccentThumbnailHash = UINT64_MAX;
    g_popupAccentColorValid = false;
    g_popupAccentColor = DefaultPopupAccentColor();
    g_popupDisplayedAccentColorValid = false;
    g_popupDisplayedAccentColor = DefaultPopupAccentColor();
    g_popupAccentTransitionFrom = DefaultPopupAccentColor();
    g_popupAccentTransitionTo = DefaultPopupAccentColor();
    g_popupMediaTransitionProgress = 1.0;
    g_popupMediaTransitionActive = false;
    g_popupCoverTransitionActive = false;
    g_popupXamlThemeValid = false;
    g_popupXamlThemeMaterial.clear();
    g_popupXamlThemeButtonStyle.clear();
    g_popupXamlThemeShadowDepth = -1;
    g_popupXamlThemeShadowOpacity = -1;
}

// ===== Popup XAML host =====
bool InitializePopupXamlHost(HWND hwnd) {
    try {
        g_popupXamlSource = hosting::DesktopWindowXamlSource();
        auto native = g_popupXamlSource.as<IDesktopWindowXamlSourceNative>();
        winrt::check_hresult(native->AttachToWindow(hwnd));
        winrt::check_hresult(native->get_WindowHandle(&g_popupXamlChild));
        SubclassPopupXamlChildWindow();

        Grid root;
        root.Background(Brush(Color(0, 0, 0, 0)));

        controls::Canvas canvas;

        // The host HWND stays fully transparent. Do not use a fake rounded black
        // rectangle or CS_DROPSHADOW; both look like a separate shape. A real
        // Composition DropShadow is attached to the rounded XAML surface below.
        Border shadow{nullptr};

        Border backdrop;
        backdrop.CornerRadius(
            {kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius,
             kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius});
        backdrop.BorderThickness({0, 0, 0, 0});
        backdrop.Opacity(kPopupBackdropOpacity);
        Grid backdropCoverHost;
        backdropCoverHost.Background(Brush(Color(0x00, 0x00, 0x00, 0x00)));
        Image backdropCoverFade;
        backdropCoverFade.Stretch(mediax::Stretch::UniformToFill);
        backdropCoverFade.Opacity(0.0);
        Image backdropCover;
        backdropCover.Stretch(mediax::Stretch::UniformToFill);
        backdropCover.Opacity(1.0);
        backdropCoverHost.Children().Append(backdropCoverFade);
        backdropCoverHost.Children().Append(backdropCover);
        Border backdropTint;
        backdropTint.Background(PopupBackdropCardTintBrush());
        backdropTint.BorderThickness({0, 0, 0, 0});
        backdropTint.CornerRadius(
            {kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius,
             kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius});
        backdropTint.IsHitTestVisible(false);
        backdropCoverHost.Children().Append(backdropTint);
        Border backdropSurfaceHighlight;
        backdropSurfaceHighlight.Background(LiquidGlassSurfaceHighlightBrush());
        backdropSurfaceHighlight.BorderThickness({0, 0, 0, 0});
        backdropSurfaceHighlight.CornerRadius(
            {kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius,
             kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius});
        backdropSurfaceHighlight.IsHitTestVisible(false);
        backdropSurfaceHighlight.Opacity(0.0);
        backdropCoverHost.Children().Append(backdropSurfaceHighlight);
        Border backdropRimHighlight;
        backdropRimHighlight.Background(Brush(Color(0x00, 0x00, 0x00, 0x00)));
        backdropRimHighlight.BorderBrush(LiquidGlassRimHighlightBrush());
        backdropRimHighlight.BorderThickness({1.0, 1.0, 1.0, 1.0});
        backdropRimHighlight.CornerRadius(
            {kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius,
             kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius});
        backdropRimHighlight.IsHitTestVisible(false);
        backdropRimHighlight.Opacity(0.0);
        backdropCoverHost.Children().Append(backdropRimHighlight);
        backdrop.Child(backdropCoverHost);
        AttachGpuFriendlyTransform(backdrop, g_popupXamlBackdropScale,
                                   g_popupXamlBackdropTranslate);
        canvas.Children().Append(backdrop);

        Border panelCoverFrame;
        panelCoverFrame.CornerRadius(
            {kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius,
             kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius});
        panelCoverFrame.BorderThickness({0, 0, 0, 0});
        panelCoverFrame.Opacity(0.0);
        AttachGpuFriendlyTransform(panelCoverFrame, g_popupXamlPanelCoverScale,
                                   g_popupXamlPanelCoverTranslate);
        Grid panelCoverHost;
        Image panelCoverFade;
        panelCoverFade.Stretch(mediax::Stretch::UniformToFill);
        panelCoverFade.Opacity(0.0);
        Image panelCover;
        panelCover.Stretch(mediax::Stretch::UniformToFill);
        panelCover.Opacity(1.0);
        panelCoverHost.Children().Append(panelCoverFade);
        panelCoverHost.Children().Append(panelCover);
        panelCoverFrame.Child(panelCoverHost);
        canvas.Children().Append(panelCoverFrame);

        Border panel;
        panel.CornerRadius(
            {kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius,
             kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius});
        panel.BorderThickness({1, 1, 1, 1});
        panel.BorderBrush(PopupSurfaceStrokeBrush());
        panel.Opacity(0.0);
        AttachGpuFriendlyTransform(panel, g_popupXamlPanelScale,
                                   g_popupXamlPanelTranslate);
        canvas.Children().Append(panel);

        Border artFrame;
        artFrame.CornerRadius(
            {kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius,
             kPopupUnifiedCornerRadius, kPopupUnifiedCornerRadius});
        artFrame.Background(Brush(Color(0x00, 0x00, 0x00, 0x00)));
        artFrame.BorderThickness({0.0, 0.0, 0.0, 0.0});
        artFrame.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));
        AttachGpuFriendlyTransform(artFrame, g_popupXamlArtScale,
                                   g_popupXamlArtTranslate);
        try {
            auto artVisual =
                hosting::ElementCompositionPreview::GetElementVisual(artFrame);
            auto compositor = artVisual.Compositor();
            g_popupXamlArtClipGeometry =
                compositor.CreateRoundedRectangleGeometry();
            g_popupXamlArtGeometricClip =
                compositor.CreateGeometricClip(g_popupXamlArtClipGeometry);
            artVisual.Clip(g_popupXamlArtGeometricClip);
        } catch (...) {
            g_popupXamlArtClipGeometry = nullptr;
            g_popupXamlArtGeometricClip = nullptr;
        }
        Grid artHost;
        Image artFade;
        artFade.Stretch(mediax::Stretch::UniformToFill);
        artFade.IsHitTestVisible(false);
        artFade.Opacity(0.0);
        Image art;
        art.Stretch(mediax::Stretch::UniformToFill);
        art.Opacity(1.0);
        artHost.Children().Append(artFade);
        artHost.Children().Append(art);
        artFrame.Child(artHost);
        canvas.Children().Append(artFrame);

        auto makePopupTextFade = [](bool leftEdge) {
            Border fade;
            fade.HorizontalAlignment(leftEdge ? HorizontalAlignment::Left
                                              : HorizontalAlignment::Right);
            fade.VerticalAlignment(VerticalAlignment::Stretch);
            fade.IsHitTestVisible(false);
            fade.Opacity(0.0);
            controls::Canvas::SetZIndex(fade, 10);
            return fade;
        };

        Grid outgoingTitleHost;
        outgoingTitleHost.IsHitTestVisible(false);
        TextBlock outgoingTitle;
        outgoingTitle.FontFamily(mediax::FontFamily(L"Segoe UI Variable Text"));
        outgoingTitle.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
        outgoingTitle.TextTrimming(xaml::TextTrimming::CharacterEllipsis);
        outgoingTitle.VerticalAlignment(VerticalAlignment::Center);
        outgoingTitle.Opacity(0.0);
        TranslateTransform outgoingTitleTranslate;
        outgoingTitle.RenderTransform(outgoingTitleTranslate);
        outgoingTitleHost.Children().Append(outgoingTitle);
        Border outgoingTitleLeftFade = makePopupTextFade(true);
        Border outgoingTitleRightFade = makePopupTextFade(false);
        outgoingTitleHost.Children().Append(outgoingTitleLeftFade);
        outgoingTitleHost.Children().Append(outgoingTitleRightFade);
        canvas.Children().Append(outgoingTitleHost);

        Grid outgoingArtistHost;
        outgoingArtistHost.IsHitTestVisible(false);
        TextBlock outgoingArtist;
        outgoingArtist.FontFamily(
            mediax::FontFamily(L"Segoe UI Variable Text"));
        outgoingArtist.TextTrimming(xaml::TextTrimming::CharacterEllipsis);
        outgoingArtist.VerticalAlignment(VerticalAlignment::Center);
        outgoingArtist.Opacity(0.0);
        TranslateTransform outgoingArtistTranslate;
        outgoingArtist.RenderTransform(outgoingArtistTranslate);
        outgoingArtistHost.Children().Append(outgoingArtist);
        Border outgoingArtistLeftFade = makePopupTextFade(true);
        Border outgoingArtistRightFade = makePopupTextFade(false);
        outgoingArtistHost.Children().Append(outgoingArtistLeftFade);
        outgoingArtistHost.Children().Append(outgoingArtistRightFade);
        canvas.Children().Append(outgoingArtistHost);

        Grid titleHost;
        titleHost.IsHitTestVisible(false);
        TextBlock title;
        title.FontFamily(mediax::FontFamily(L"Segoe UI Variable Text"));
        title.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
        title.TextTrimming(xaml::TextTrimming::CharacterEllipsis);
        title.VerticalAlignment(VerticalAlignment::Center);
        TranslateTransform titleTranslate;
        title.RenderTransform(titleTranslate);
        titleHost.Children().Append(title);
        Border titleLeftFade = makePopupTextFade(true);
        Border titleRightFade = makePopupTextFade(false);
        titleHost.Children().Append(titleLeftFade);
        titleHost.Children().Append(titleRightFade);
        canvas.Children().Append(titleHost);

        Grid artistHost;
        artistHost.IsHitTestVisible(false);
        TextBlock artist;
        artist.FontFamily(mediax::FontFamily(L"Segoe UI Variable Text"));
        artist.TextTrimming(xaml::TextTrimming::CharacterEllipsis);
        artist.VerticalAlignment(VerticalAlignment::Center);
        TranslateTransform artistTranslate;
        artist.RenderTransform(artistTranslate);
        artistHost.Children().Append(artist);
        Border artistLeftFade = makePopupTextFade(true);
        Border artistRightFade = makePopupTextFade(false);
        artistHost.Children().Append(artistLeftFade);
        artistHost.Children().Append(artistRightFade);
        canvas.Children().Append(artistHost);

        auto compactSpec = CurrentCompactVisualSpec();
        Grid popupPlaybackIndicator;
        popupPlaybackIndicator.IsHitTestVisible(false);
        popupPlaybackIndicator.Opacity(0.0);
        mediax::RectangleGeometry popupPlaybackRevealClip;
        popupPlaybackRevealClip.Rect(
            {0, 0, 0, static_cast<float>(compactSpec.playbackIndicatorHeight)});
        popupPlaybackIndicator.Clip(popupPlaybackRevealClip);
        StackPanel popupPlaybackBars;
        popupPlaybackBars.Orientation(controls::Orientation::Horizontal);
        popupPlaybackBars.HorizontalAlignment(HorizontalAlignment::Center);
        popupPlaybackBars.VerticalAlignment(VerticalAlignment::Center);
        popupPlaybackBars.IsHitTestVisible(false);
        mediax::SolidColorBrush popupPlaybackAccentBrush;
        popupPlaybackAccentBrush.Color(g_compactPlaybackAccentDisplayed);
        g_popupXamlPlaybackBars.clear();
        constexpr double kPopupPausedFractions[5] = {0.27, 0.43, 0.60, 0.43,
                                                     0.27};
        for (size_t i = 0; i < 5; ++i) {
            Border bar;
            bar.Width(compactSpec.playbackBarWidth);
            double barHeight =
                std::max(2.0, compactSpec.playbackIndicatorHeight *
                                  kPopupPausedFractions[i]);
            bar.Height(barHeight);
            bar.Margin({compactSpec.playbackBarGap * 0.5, 0,
                        compactSpec.playbackBarGap * 0.5, 0});
            double radius = compactSpec.playbackBarWidth * 0.5;
            bar.CornerRadius({radius, radius, radius, radius});
            bar.VerticalAlignment(VerticalAlignment::Center);
            bar.Background(popupPlaybackAccentBrush);
            bar.Opacity(i == 0 || i == 4 ? 0.86
                                         : (i == 1 || i == 3 ? 0.94 : 1.0));
            bar.IsHitTestVisible(false);
            g_popupPlaybackBarHeights[i] = barHeight;
            g_popupXamlPlaybackBars.push_back(bar);
            popupPlaybackBars.Children().Append(bar);
        }
        popupPlaybackIndicator.Children().Append(popupPlaybackBars);
        canvas.Children().Append(popupPlaybackIndicator);

        ScaleTransform compactHoverScale;
        compactHoverScale.ScaleX(1.0);
        compactHoverScale.ScaleY(1.0);
        canvas.RenderTransform(compactHoverScale);

        TextBlock elapsed;
        elapsed.FontFamily(mediax::FontFamily(L"Segoe UI Variable Text"));
        elapsed.FontSize(11);
        elapsed.Text(L"0:00");
        elapsed.VerticalAlignment(VerticalAlignment::Center);
        canvas.Children().Append(elapsed);

        TextBlock duration;
        duration.FontFamily(mediax::FontFamily(L"Segoe UI Variable Text"));
        duration.FontSize(11);
        duration.Text(L"0:00");
        duration.TextAlignment(xaml::TextAlignment::Right);
        duration.VerticalAlignment(VerticalAlignment::Center);
        canvas.Children().Append(duration);

        Border progressTrack;
        progressTrack.Height(6);
        progressTrack.CornerRadius(
            {kPopupG2ProgressCornerRadius, kPopupG2ProgressCornerRadius,
             kPopupG2ProgressCornerRadius, kPopupG2ProgressCornerRadius});
        progressTrack.IsHitTestVisible(false);
        canvas.Children().Append(progressTrack);

        Border progressFill;
        progressFill.Height(6);
        progressFill.CornerRadius(
            {kPopupG2ProgressCornerRadius, kPopupG2ProgressCornerRadius,
             kPopupG2ProgressCornerRadius, kPopupG2ProgressCornerRadius});
        progressFill.IsHitTestVisible(false);
        canvas.Children().Append(progressFill);

        ProgressBar progress;
        progress.Height(6);
        progress.Minimum(0);
        progress.Maximum(1000);
        progress.RenderTransformOrigin({0.5, 0.5});
        ScaleTransform progressScale;
        progressScale.ScaleX(0.82);
        progressScale.ScaleY(0.82);
        progress.RenderTransform(progressScale);
        progress.IsHitTestVisible(false);
        progress.Opacity(0.0);
        canvas.Children().Append(progress);

        controls::Canvas progressGlowMask;
        progressGlowMask.IsHitTestVisible(false);
        progressGlowMask.Opacity(0.0);
        mediax::RectangleGeometry progressGlowClip;
        progressGlowMask.Clip(progressGlowClip);
        std::vector<Border> progressGlowLayers;
        for (int i = 0; i < 6; ++i) {
            Border layer;
            layer.IsHitTestVisible(false);
            layer.Opacity(0.0);
            progressGlowMask.Children().Append(layer);
            progressGlowLayers.push_back(layer);
        }
        canvas.Children().Append(progressGlowMask);

        std::vector<Border> progressCoreBlurLayers;
        for (int i = 0; i < 6; ++i) {
            Border layer;
            layer.IsHitTestVisible(false);
            layer.Opacity(0.0);
            canvas.Children().Append(layer);
            progressCoreBlurLayers.push_back(layer);
        }

        Border progressGlowCore;
        progressGlowCore.Width(6);
        progressGlowCore.Height(6);
        progressGlowCore.CornerRadius(
            {kPopupG2ProgressCornerRadius, kPopupG2ProgressCornerRadius,
             kPopupG2ProgressCornerRadius, kPopupG2ProgressCornerRadius});
        progressGlowCore.IsHitTestVisible(false);
        progressGlowCore.Opacity(0.0);
        canvas.Children().Append(progressGlowCore);

        Border progressHitTarget;
        progressHitTarget.Height(22);
        progressHitTarget.Background(Brush(Color(0x01, 0x00, 0x00, 0x00)));
        canvas.Children().Append(progressHitTarget);

        controls::Canvas controlsPanel;
        controlsPanel.Width(PopupControlsWidth());
        controlsPanel.Height(PopupControlsHeight());

        Border prevButton = MakePopupXamlButton(L"Popup_Prev", [] {
            RunMediaTransportCommand(MediaTransportCommand::Previous);
        });
        Border playButton = MakePopupXamlButton(
            L"Popup_Play",
            [] {
                RunMediaTransportCommand(
                    MediaTransportCommand::TogglePlayPause);
            },
            true);
        Border nextButton = MakePopupXamlButton(L"Popup_Next", [] {
            RunMediaTransportCommand(MediaTransportCommand::Next);
        });
        controls::Canvas::SetLeft(prevButton, PopupButtonLeft(0));
        controls::Canvas::SetTop(prevButton, PopupButtonTop());
        controls::Canvas::SetLeft(playButton, PopupButtonLeft(1));
        controls::Canvas::SetTop(playButton, PopupButtonTop());
        controls::Canvas::SetLeft(nextButton, PopupButtonLeft(2));
        controls::Canvas::SetTop(nextButton, PopupButtonTop());

        controlsPanel.Children().Append(prevButton);
        controlsPanel.Children().Append(playButton);
        controlsPanel.Children().Append(nextButton);
        canvas.Children().Append(controlsPanel);

        controls::FontIcon volumeLowIcon;
        volumeLowIcon.FontFamily(mediax::FontFamily(L"Segoe Fluent Icons"));
        volumeLowIcon.Glyph(L"\xE992");
        volumeLowIcon.FontSize(18.0);
        volumeLowIcon.Margin({1.0, 1.0, -1.0, -1.0});
        volumeLowIcon.IsHitTestVisible(false);
        canvas.Children().Append(volumeLowIcon);

        Border volumeTrack;
        volumeTrack.Height(6.0);
        volumeTrack.CornerRadius({3.0, 3.0, 3.0, 3.0});
        volumeTrack.IsHitTestVisible(false);
        canvas.Children().Append(volumeTrack);

        Border volumeFill;
        volumeFill.Height(6.0);
        volumeFill.CornerRadius({3.0, 3.0, 3.0, 3.0});
        volumeFill.IsHitTestVisible(false);
        canvas.Children().Append(volumeFill);

        Border volumeHitTarget;
        volumeHitTarget.Height(28.0);
        volumeHitTarget.Background(Brush(Color(0x01, 0, 0, 0)));
        canvas.Children().Append(volumeHitTarget);

        controls::FontIcon volumeHighIcon;
        volumeHighIcon.FontFamily(mediax::FontFamily(L"Segoe Fluent Icons"));
        volumeHighIcon.Glyph(L"\xE767");
        volumeHighIcon.FontSize(20.0);
        volumeHighIcon.Margin({-1.0, 1.0, 1.0, -1.0});
        volumeHighIcon.IsHitTestVisible(false);
        canvas.Children().Append(volumeHighIcon);

        auto updateVolumeFromPointer =
            [](input::PointerRoutedEventArgs const& e) {
                if (!g_popupXamlVolumeTrack) {
                    return;
                }
                double width = g_popupXamlVolumeTrack.ActualWidth();
                if (width <= 0.0) {
                    return;
                }
                auto point =
                    e.GetCurrentPoint(g_popupXamlVolumeTrack).Position();
                double ratio = Clamp(point.X / width, 0.0, 1.0);
                if (WriteDefaultOutputVolume(ratio) && g_popupXamlVolumeFill) {
                    g_popupXamlVolumeFill.Width(width * ratio);
                }
            };
        volumeHitTarget.PointerPressed(
            [updateVolumeFromPointer](auto const& sender,
                                      input::PointerRoutedEventArgs const& e) {
                try {
                    g_popupVolumeDragging = true;
                    updateVolumeFromPointer(e);
                    if (auto element = sender.template try_as<UIElement>()) {
                        element.CapturePointer(e.Pointer());
                    }
                    e.Handled(true);
                } catch (...) {
                    g_popupVolumeDragging = false;
                }
            });
        volumeHitTarget.PointerMoved(
            [updateVolumeFromPointer](auto const&,
                                      input::PointerRoutedEventArgs const& e) {
                if (!g_popupVolumeDragging)
                    return;
                try {
                    updateVolumeFromPointer(e);
                    e.Handled(true);
                } catch (...) {
                }
            });
        volumeHitTarget.PointerReleased(
            [](auto const& sender, input::PointerRoutedEventArgs const& e) {
                g_popupVolumeDragging = false;
                try {
                    if (auto element = sender.template try_as<UIElement>()) {
                        element.ReleasePointerCapture(e.Pointer());
                    }
                    e.Handled(true);
                } catch (...) {
                }
            });
        volumeHitTarget.PointerCanceled(
            [](auto const&, input::PointerRoutedEventArgs const&) {
                g_popupVolumeDragging = false;
            });

        progressHitTarget.PointerPressed(
            [](auto const& sender, input::PointerRoutedEventArgs const& e) {
                try {
                    if (!g_popupXamlProgressTrack || PopupProgress() < 0.75) {
                        return;
                    }

                    auto point =
                        e.GetCurrentPoint(g_popupXamlProgressTrack).Position();
                    double width = g_popupXamlProgressTrack.ActualWidth();
                    double height = g_popupXamlProgressTrack.ActualHeight();
                    if (width <= 0.0) {
                        return;
                    }

                    constexpr double hitPadding = 8.0;
                    if (point.X >= 0.0 && point.X <= width &&
                        point.Y >= -hitPadding &&
                        point.Y <= height + hitPadding) {
                        UpdatePopupSeekPreview(point.X / width);
                        if (auto element =
                                sender.template try_as<UIElement>()) {
                            if (!element.CapturePointer(e.Pointer())) {
                                EndPopupSeek(false);
                                return;
                            }
                        }
                        e.Handled(true);
                    }
                } catch (...) {
                    try {
                        EndPopupSeek(false);
                    } catch (...) {
                    }
                }
            });
        progressHitTarget.PointerMoved(
            [](auto const&, input::PointerRoutedEventArgs const& e) {
                try {
                    if (!g_popupSeekDragging || !g_popupXamlProgressTrack) {
                        return;
                    }

                    double width = g_popupXamlProgressTrack.ActualWidth();
                    if (width > 0.0) {
                        auto point = e.GetCurrentPoint(g_popupXamlProgressTrack)
                                         .Position();
                        UpdatePopupSeekPreview(point.X / width);
                        e.Handled(true);
                    }
                } catch (...) {
                }
            });
        progressHitTarget.PointerReleased(
            [](auto const& sender, input::PointerRoutedEventArgs const& e) {
                if (!g_popupSeekDragging) {
                    return;
                }
                try {
                    if (g_popupXamlProgressTrack) {
                        double width = g_popupXamlProgressTrack.ActualWidth();
                        if (width > 0.0) {
                            auto point =
                                e.GetCurrentPoint(g_popupXamlProgressTrack)
                                    .Position();
                            UpdatePopupSeekPreview(point.X / width);
                        }
                    }
                } catch (...) {
                    // Commit the last valid preview even if the final pointer sample
                    // can't be resolved while the popup is being relaid out.
                }
                try {
                    EndPopupSeek(true);
                } catch (...) {
                }
                try {
                    if (auto element = sender.template try_as<UIElement>()) {
                        element.ReleasePointerCapture(e.Pointer());
                    }
                    e.Handled(true);
                } catch (...) {
                }
            });
        progressHitTarget.PointerCanceled(
            [](auto const& sender, input::PointerRoutedEventArgs const& e) {
                try {
                    if (!g_popupSeekDragging) {
                        return;
                    }
                    EndPopupSeek(false);
                    if (auto element = sender.template try_as<UIElement>()) {
                        element.ReleasePointerCapture(e.Pointer());
                    }
                    e.Handled(true);
                } catch (...) {
                }
            });
        progressHitTarget.PointerCaptureLost(
            [](auto const&, input::PointerRoutedEventArgs const&) {
                try {
                    if (g_popupSeekDragging) {
                        EndPopupSeek(false);
                    }
                } catch (...) {
                }
            });

        root.Children().Append(canvas);
        g_popupXamlSource.Content(root);

        // The element must belong to a live XAML visual tree before asking
        // ElementCompositionPreview for its compositor. This still runs
        // synchronously before the first frame is committed, so the popup has
        // Gaussian blur from its first visible frame.
        if (IsLiquidGlassMaterial()) {
            backdrop.Background(winrt::make<ImmediateBackdropBlurBrush>(
                backdrop, 25.0f, Color(0x25, 0x32, 0x32, 0x32)));
        }

        g_popupXamlRoot = root;
        g_popupXamlCanvas = canvas;
        g_popupXamlShadow = shadow;
        g_popupXamlBackdrop = backdrop;
        g_popupXamlBackdropCoverFade = backdropCoverFade;
        g_popupXamlBackdropCover = backdropCover;
        g_popupXamlBackdropTint = backdropTint;
        g_popupXamlBackdropSurfaceHighlight = backdropSurfaceHighlight;
        g_popupXamlBackdropRimHighlight = backdropRimHighlight;
        g_popupXamlPanelCoverFrame = panelCoverFrame;
        g_popupXamlPanelCoverFade = panelCoverFade;
        g_popupXamlPanelCover = panelCover;
        g_popupXamlPanel = panel;
        g_popupXamlArtFrame = artFrame;
        g_popupXamlArtFade = artFade;
        g_popupXamlArt = art;
        g_popupXamlTitleHost = titleHost;
        g_popupXamlArtistHost = artistHost;
        g_popupXamlPlaybackIndicator = popupPlaybackIndicator;
        g_popupXamlPlaybackAccentBrush = popupPlaybackAccentBrush;
        g_popupXamlPlaybackRevealClip = popupPlaybackRevealClip;
        g_popupXamlCompactHoverScale = compactHoverScale;
        g_popupXamlOutgoingTitleHost = outgoingTitleHost;
        g_popupXamlOutgoingArtistHost = outgoingArtistHost;
        g_popupXamlTitleLeftFade = titleLeftFade;
        g_popupXamlTitleRightFade = titleRightFade;
        g_popupXamlArtistLeftFade = artistLeftFade;
        g_popupXamlArtistRightFade = artistRightFade;
        g_popupXamlOutgoingTitleLeftFade = outgoingTitleLeftFade;
        g_popupXamlOutgoingTitleRightFade = outgoingTitleRightFade;
        g_popupXamlOutgoingArtistLeftFade = outgoingArtistLeftFade;
        g_popupXamlOutgoingArtistRightFade = outgoingArtistRightFade;
        g_popupXamlTitle = title;
        g_popupXamlArtist = artist;
        g_popupXamlOutgoingTitle = outgoingTitle;
        g_popupXamlOutgoingArtist = outgoingArtist;
        g_popupXamlTitleTranslate = titleTranslate;
        g_popupXamlArtistTranslate = artistTranslate;
        g_popupXamlOutgoingTitleTranslate = outgoingTitleTranslate;
        g_popupXamlOutgoingArtistTranslate = outgoingArtistTranslate;
        g_popupXamlElapsed = elapsed;
        g_popupXamlDuration = duration;
        g_popupXamlProgress = progress;
        g_popupXamlProgressScale = progressScale;
        g_popupXamlProgressTrack = progressTrack;
        g_popupXamlProgressFill = progressFill;
        g_popupXamlProgressHitTarget = progressHitTarget;
        g_popupXamlProgressGlowMask = progressGlowMask;
        g_popupXamlProgressGlowClip = progressGlowClip;
        g_popupXamlProgressGlowLayers = progressGlowLayers;
        g_popupXamlProgressCoreBlurLayers = progressCoreBlurLayers;
        g_popupXamlProgressGlowCore = progressGlowCore;
        g_popupXamlControls = controlsPanel;
        g_popupXamlVolumeTrack = volumeTrack;
        g_popupXamlVolumeFill = volumeFill;
        g_popupXamlVolumeHitTarget = volumeHitTarget;
        g_popupXamlVolumeLowIcon = volumeLowIcon;
        g_popupXamlVolumeHighIcon = volumeHighIcon;
        g_popupXamlThumbnailHash = UINT64_MAX;
        InitializePopupCompositionShadow();
        ApplyPopupXamlTheme(true);
        ShowWindow(g_popupXamlChild, SW_SHOWNA);
        return true;
    } catch (...) {
        if (g_popupXamlSource) {
            try {
                g_popupXamlSource.Content(nullptr);
                g_popupXamlSource.Close();
            } catch (...) {
            }
        }
        ResetPopupXamlElementState();
        return false;
    }
}

// ===== Popup visual update =====
double PopupDpiScale(HWND hwnd);
int PopupDipToPx(double value, HWND hwnd);

DipRect PopupScreenRectToLocalDip(RECT const& rect,
                                  RECT const& popupScreenPx,
                                  double scale);

void UpdatePopupXamlVisuals() {
    if (!g_popupXamlRoot || !g_expandedPopup) {
        return;
    }

    auto compactSpec = CurrentCompactVisualSpec();
    RECT popupScreenPx{};
    GetWindowRect(g_expandedPopup, &popupScreenPx);
    int widthPx = popupScreenPx.right - popupScreenPx.left;
    int heightPx = popupScreenPx.bottom - popupScreenPx.top;
    if (widthPx <= 0 || heightPx <= 0) {
        return;
    }

    double dpiScale = PopupDpiScale(g_expandedPopup);
    int width = std::max(1, static_cast<int>(std::lround(widthPx / dpiScale)));
    int height =
        std::max(1, static_cast<int>(std::lround(heightPx / dpiScale)));
    RECT popupScreen{0, 0, static_cast<LONG>(width), static_cast<LONG>(height)};
    DipRect sourceRect =
        PopupScreenRectToLocalDip(g_popupSourceRect, popupScreenPx, dpiScale);
    DipRect sourceArtRect = PopupScreenRectToLocalDip(g_popupSourceArtRect,
                                                      popupScreenPx, dpiScale);
    DipRect sourceTitleRect = PopupScreenRectToLocalDip(
        g_popupSourceTitleRect, popupScreenPx, dpiScale);
    DipRect sourceArtistRect = PopupScreenRectToLocalDip(
        g_popupSourceArtistRect, popupScreenPx, dpiScale);
    DipRect sourceProgressRect = PopupScreenRectToLocalDip(
        g_popupSourceProgressRect, popupScreenPx, dpiScale);
    DipRect sourceControlsRect = PopupScreenRectToLocalDip(
        g_popupSourceControlsRect, popupScreenPx, dpiScale);
    DipRect finalRectDip =
        PopupScreenRectToLocalDip(g_popupFinalRect, popupScreenPx, dpiScale);
    // The expanded layout stays on the rounded-DIP grid; the compact endpoint
    // is the part that must match the native island pixel-for-pixel.
    RECT finalRect{static_cast<LONG>(std::lround(finalRectDip.left)),
                   static_cast<LONG>(std::lround(finalRectDip.top)),
                   static_cast<LONG>(std::lround(finalRectDip.right)),
                   static_cast<LONG>(std::lround(finalRectDip.bottom))};

    double progress = PopupProgress();
    double morphProgress = Clamp(progress, 0.0, 1.0);
    // The popup starts at exactly the compact island's geometry. Keep this one
    // surface fully materialized throughout the morph instead of cross-fading
    // two independently composited windows, which caused the visible flash.
    double popupTreeOpacity = 1.0;
    if (g_popupXamlRoot) {
        g_popupXamlRoot.Opacity(popupTreeOpacity);
    }
    double visibilityProgress = PopupClosingShellOpacity(morphProgress);
    double closingTailFade = g_popupClosing ? morphProgress : morphProgress;
    // The popup itself is the compact endpoint. Never crossfade it into the
    // separately rendered taskbar island at the end of a close.
    double compactHandoff = 0.0;
    g_popupCloseHandoffOpacity = 1.0;
    if (g_popupXamlRoot) {
        g_popupXamlRoot.Opacity(g_popupCloseHandoffOpacity);
    }
    if (g_playerGrid) {
        try {
            if (g_expandedPopup && IsWindowVisible(g_expandedPopup)) {
                // The independent surface is the compact endpoint. The native
                // grid stays alive only as the continuously sampled anchor.
                g_playerGrid.Opacity(0.001);
                g_playerGrid.IsHitTestVisible(true);
            }
        } catch (...) {
        }
    }
    RECT currentRect{0, 0, static_cast<LONG>(width), static_cast<LONG>(height)};
    // Always update the animated XAML geometry while the popup is moving.
    // The previous small-delta skip optimization made the album-art morph
    // freeze for one or more frames when the HWND rect rounded to the same
    // integer coordinates, then jump on the next update. That looked like a
    // flash/offset during the cover scaling animation.
    g_lastPopupVisualRect = currentRect;
    g_lastPopupVisualProgress = progress;

    double rootWidth = g_popupXamlRoot.Width();
    double rootHeight = g_popupXamlRoot.Height();
    if (std::isnan(rootWidth) || std::abs(rootWidth - width) > 0.5) {
        g_popupXamlRoot.Width(width);
    }
    if (std::isnan(rootHeight) || std::abs(rootHeight - height) > 0.5) {
        g_popupXamlRoot.Height(height);
    }
    if (g_popupXamlCanvas) {
        double canvasWidth = g_popupXamlCanvas.Width();
        double canvasHeight = g_popupXamlCanvas.Height();
        if (std::isnan(canvasWidth) || std::abs(canvasWidth - width) > 0.5) {
            g_popupXamlCanvas.Width(width);
        }
        if (std::isnan(canvasHeight) || std::abs(canvasHeight - height) > 0.5) {
            g_popupXamlCanvas.Height(height);
        }
    }

    RECT targetArtScreen{};
    RECT targetCard{};
    RECT targetTitle{};
    RECT targetArtist{};
    RECT targetProgress{};
    RECT targetElapsed{};
    RECT targetDuration{};
    RECT targetControls{};
    CalculatePopupFinalLayout(finalRect, targetArtScreen, targetCard,
                              targetTitle, targetArtist, targetProgress,
                              targetElapsed, targetDuration, targetControls);
    RECT targetBackdrop =
        PopupBackdropRectFromParts(targetArtScreen, targetCard);
    DipRect backdropScreen{
        LerpDouble(sourceRect.left, targetBackdrop.left, progress),
        LerpDouble(sourceRect.top, targetBackdrop.top, progress),
        LerpDouble(sourceRect.right, targetBackdrop.right, progress),
        LerpDouble(sourceRect.bottom, targetBackdrop.bottom, progress),
    };
    double backdropWidth =
        std::max(1L, targetBackdrop.right - targetBackdrop.left);
    double backdropHeight =
        std::max(1L, targetBackdrop.bottom - targetBackdrop.top);
    double sourceShellRadius = compactSpec.cornerRadius;
    if (g_popupXamlShadowVisual) {
        float shadowOpacity = static_cast<float>(visibilityProgress);
        g_popupXamlShadowVisual.Size({static_cast<float>(backdropWidth),
                                      static_cast<float>(backdropHeight)});
        g_popupXamlShadowVisual.Offset(
            {static_cast<float>(targetBackdrop.left - popupScreen.left +
                                backdropScreen.left - targetBackdrop.left),
             static_cast<float>(targetBackdrop.top - popupScreen.top +
                                backdropScreen.top - targetBackdrop.top),
             0.0f});
        g_popupXamlShadowVisual.Opacity(shadowOpacity);
    }
    if (g_popupXamlBackdrop) {
        try {
            bool wantBackdropBlur = IsLiquidGlassMaterial() &&
                                    morphProgress > 0.55 &&
                                    !g_popupRestingCompact;
            EnsurePopupLiquidGlassBlur(g_popupXamlBackdrop, wantBackdropBlur);
            int shadowDepth = static_cast<int>(std::lround(
                PopupShadowDepth() *
                (0.25 + 1.75 * PopupShadowOpacityPercent() / 100.0)));
            float shadowZ =
                PopupShadowDepth() <= 0 || PopupShadowOpacityPercent() <= 0
                    ? 0.0f
                    : static_cast<float>(
                          shadowDepth * PopupShadowMorphOpacity(morphProgress));
            g_popupXamlBackdrop.Translation(
                winrt::Windows::Foundation::Numerics::float3{0.0f, 0.0f,
                                                             shadowZ});
        } catch (...) {
        }
        double targetShellRadius =
            g_settings.compact
                ? PopupG2CornerRadius(backdropWidth, backdropHeight)
                : (IsLiquidGlassMaterial()
                       ? static_cast<double>(g_settings.liquidGlassCornerRadius)
                       : kPopupUnifiedCornerRadius);
        double shellVisualRadius =
            LerpDouble(sourceShellRadius, targetShellRadius, morphProgress);
        double shellRadius =
            Clamp(shellVisualRadius, 1.0,
                  std::min(backdropScreen.right - backdropScreen.left,
                           backdropScreen.bottom - backdropScreen.top) *
                      0.5);
        g_popupXamlBackdrop.CornerRadius(
            {shellRadius, shellRadius, shellRadius, shellRadius});
        double backdropOpacity = kPopupBackdropOpacity * visibilityProgress;
        // The compact island has no full-surface cover wash. Grow the wash
        // from zero with the same geometry progress so the p=0 popup frame is
        // visually identical to the compact surface in both directions.
        double washOpacity = PopupBackdropCoverEffectEnabled()
                                 ? SmootherStep(morphProgress)
                                 : 0.0;
        g_popupXamlBackdrop.Opacity(backdropOpacity);
        // Optional album color wash. Liquid Glass keeps it visible in light mode;
        // otherwise Main.PopupBackdropCoverEffect controls the behavior.
        bool backdropCoverEnabled = PopupBackdropCoverEffectEnabled();
        if (g_popupXamlBackdropCover) {
            g_popupXamlBackdropCover.Stretch(mediax::Stretch::UniformToFill);
            g_popupXamlBackdropCover.Opacity(backdropCoverEnabled ? washOpacity
                                                                  : 0.0);
        }
        if (g_popupXamlBackdropCoverFade) {
            g_popupXamlBackdropCoverFade.Stretch(
                mediax::Stretch::UniformToFill);
            g_popupXamlBackdropCoverFade.Opacity(0.0);
        }
        if (g_popupXamlBackdropTint) {
            g_popupXamlBackdropTint.CornerRadius(
                {shellRadius, shellRadius, shellRadius, shellRadius});
            g_popupXamlBackdropTint.Opacity(SmootherStep(morphProgress));
        }
        double liquidHighlightOpacity =
            IsLiquidGlassMaterial()
                ? backdropOpacity * SmootherStep(morphProgress)
                : 0.0;
        double liquidSurfaceHighlightOpacity =
            IsLiquidGlassMaterial()
                ? backdropOpacity * (IsDarkModeApprox() ? 0.45 : 0.78) *
                      SmootherStep(morphProgress)
                : 0.0;
        if (g_popupXamlBackdropSurfaceHighlight) {
            g_popupXamlBackdropSurfaceHighlight.CornerRadius(
                {shellRadius, shellRadius, shellRadius, shellRadius});
            g_popupXamlBackdropSurfaceHighlight.Opacity(
                liquidSurfaceHighlightOpacity);
        }
        if (g_popupXamlBackdropRimHighlight) {
            g_popupXamlBackdropRimHighlight.CornerRadius(
                {shellRadius, shellRadius, shellRadius, shellRadius});
            g_popupXamlBackdropRimHighlight.BorderThickness(
                IsLiquidGlassMaterial() ? Thickness{1.0, 1.0, 1.0, 1.0}
                                        : Thickness{0.0, 0.0, 0.0, 0.0});
            g_popupXamlBackdropRimHighlight.Opacity(liquidHighlightOpacity);
        }
        ApplyLayoutRect(g_popupXamlBackdrop, g_popupXamlBackdropScale,
                        g_popupXamlBackdropTranslate, backdropScreen,
                        popupScreen);
    }
    DipRect artScreen{
        LerpDouble(sourceArtRect.left, targetArtScreen.left, progress),
        LerpDouble(sourceArtRect.top, targetArtScreen.top, progress),
        LerpDouble(sourceArtRect.right, targetArtScreen.right, progress),
        LerpDouble(sourceArtRect.bottom, targetArtScreen.bottom, progress),
    };
    double popupArtTargetSize = static_cast<double>(
        std::max(1L, targetArtScreen.right - targetArtScreen.left));
    double popupArtTargetRadius =
        std::min(kPopupArtworkCornerRadius, popupArtTargetSize * 0.5);
    double sourceArtRadius = SourceScaledRadius(
        compactSpec.artCornerRadius, compactSpec.artSize, sourceArtRect);
    double popupArtVisualRadius =
        LerpDouble(sourceArtRadius, popupArtTargetRadius, morphProgress);
    double popupArtRadius = Clamp(popupArtVisualRadius, 1.0,
                                  std::min(artScreen.right - artScreen.left,
                                           artScreen.bottom - artScreen.top) *
                                      0.5);
    g_popupXamlArtFrame.CornerRadius(
        {popupArtRadius, popupArtRadius, popupArtRadius, popupArtRadius});
    g_popupXamlArtFrame.BorderThickness({0.0, 0.0, 0.0, 0.0});
    g_popupXamlArtFrame.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    g_popupXamlArtFrame.Clip(nullptr);
    // The frame itself is compositor-scaled from the final layout, so its
    // contents must remain at that same fixed base size.
    double artWidth =
        std::max(1.0, static_cast<double>(artScreen.right - artScreen.left));
    double artHeight =
        std::max(1.0, static_cast<double>(artScreen.bottom - artScreen.top));
    if (g_popupXamlArtClipGeometry) {
        g_popupXamlArtClipGeometry.Size(
            {static_cast<float>(artWidth), static_cast<float>(artHeight)});
        g_popupXamlArtClipGeometry.CornerRadius(
            {static_cast<float>(popupArtRadius),
             static_cast<float>(popupArtRadius)});
    }
    double sourceArtOverscan =
        std::min(SourceScaledRadius(1.0, g_layout.artSize, sourceArtRect),
                 std::min(artWidth, artHeight) * 0.12);
    double artOverscan = LerpDouble(sourceArtOverscan, 0.0, morphProgress);
    if (auto artHost = g_popupXamlArtFrame.Child().try_as<FrameworkElement>()) {
        artHost.Width(artWidth);
        artHost.Height(artHeight);
        ApplyElementClip(artHost, artWidth, artHeight);
    }
    auto alignPopupArtImage = [&](Image const& image) {
        if (!image) {
            return;
        }
        image.Width(artWidth + artOverscan * 2.0);
        image.Height(artHeight + artOverscan * 2.0);
        image.Margin({-artOverscan, -artOverscan, -artOverscan, -artOverscan});
        image.Stretch(mediax::Stretch::UniformToFill);
    };
    alignPopupArtImage(g_popupXamlArtFade);
    alignPopupArtImage(g_popupXamlArt);
    // Artwork exists in both layouts, so fading it before the compact handoff
    // creates a blank-cover flash. Keep it opaque and only morph its bounds.
    g_popupXamlArtFrame.Opacity(1.0);
    ApplyLayoutRect(g_popupXamlArtFrame, g_popupXamlArtScale,
                    g_popupXamlArtTranslate, artScreen, popupScreen);

    DipRect cardScreen{
        LerpDouble(sourceRect.left, targetCard.left, progress),
        LerpDouble(sourceRect.top, targetCard.top, progress),
        LerpDouble(sourceRect.right, targetCard.right, progress),
        LerpDouble(sourceRect.bottom, targetCard.bottom, progress),
    };
    double panelTargetRadius =
        g_settings.compact
            ? PopupG2CornerRadius(targetCard.right - targetCard.left,
                                  targetCard.bottom - targetCard.top)
            : kPopupInnerPanelCornerRadius;
    double panelVisualRadius =
        LerpDouble(sourceShellRadius, panelTargetRadius, morphProgress);
    double panelRadius = Clamp(panelVisualRadius, 1.0,
                               std::min(cardScreen.right - cardScreen.left,
                                        cardScreen.bottom - cardScreen.top) *
                                   0.5);
    double expandedLayerOpacity =
        g_popupClosing ? closingTailFade : morphProgress;
    double cardOpacity = expandedLayerOpacity;
    if (g_popupXamlPanelCoverFrame) {
        g_popupXamlPanelCoverFrame.CornerRadius(
            {panelRadius, panelRadius, panelRadius, panelRadius});
        g_popupXamlPanelCoverFrame.Opacity(0.0);
        ApplyLayoutRect(g_popupXamlPanelCoverFrame, g_popupXamlPanelCoverScale,
                        g_popupXamlPanelCoverTranslate, cardScreen,
                        popupScreen);
    }
    g_popupXamlPanel.CornerRadius(
        {panelRadius, panelRadius, panelRadius, panelRadius});
    g_popupXamlPanel.Opacity(g_settings.compact ? 0.0 : cardOpacity);
    ApplyLayoutRect(g_popupXamlPanel, g_popupXamlPanelScale,
                    g_popupXamlPanelTranslate, cardScreen, popupScreen);

    auto placeText = [&](FrameworkElement const& host, TextBlock const& text,
                         Border const& leftFade, Border const& rightFade,
                         DipRect const& source, RECT const& target,
                         double compactSize, double expandedSize) {
        if (!host || !text) {
            return;
        }

        DipRect screen{LerpDouble(source.left, target.left, progress),
                       LerpDouble(source.top, target.top, progress),
                       LerpDouble(source.right, target.right, progress),
                       LerpDouble(source.bottom, target.bottom, progress)};
        // Text shrinks with exactly the same progress as the artwork: no
        // early snap, so both finish together. Trimming stays disabled during
        // closing (set below), so the shrinking viewport clips text instead
        // of reflowing into an ellipsis before the full text reappears.
        double textWidth = std::max(1.0, screen.right - screen.left);
        double textHeight = std::max(1.0, screen.bottom - screen.top);
        host.Width(textWidth);
        host.Height(textHeight);
        ApplyElementClipWithPadding(host, textWidth, textHeight,
                                    PopupTextClipPadding());
        ConfigurePopupTextEdgeFade(leftFade, true, textHeight);
        ConfigurePopupTextEdgeFade(rightFade, false, textHeight);
        text.Width(textWidth);
        text.Height(textHeight);
        // Ellipsize long titles instead of overflowing. There is no
        // cross-surface handoff anymore (the popup rests as the island), so
        // this cannot re-introduce the old "ellipsis then full text" flash.
        text.TextTrimming(g_popupClosing
                              ? xaml::TextTrimming::None
                              : xaml::TextTrimming::CharacterEllipsis);
        text.FontSize(LerpDouble(compactSize, expandedSize, progress));
        controls::Canvas::SetLeft(host, screen.left - popupScreen.left);
        controls::Canvas::SetTop(host, screen.top - popupScreen.top);
    };
    placeText(g_popupXamlOutgoingTitleHost, g_popupXamlOutgoingTitle,
              g_popupXamlOutgoingTitleLeftFade,
              g_popupXamlOutgoingTitleRightFade, sourceTitleRect, targetTitle,
              compactSpec.titleFontSize, 16);
    placeText(g_popupXamlOutgoingArtistHost, g_popupXamlOutgoingArtist,
              g_popupXamlOutgoingArtistLeftFade,
              g_popupXamlOutgoingArtistRightFade, sourceArtistRect,
              targetArtist, compactSpec.artistFontSize, 13);
    placeText(g_popupXamlTitleHost, g_popupXamlTitle, g_popupXamlTitleLeftFade,
              g_popupXamlTitleRightFade, sourceTitleRect, targetTitle,
              compactSpec.titleFontSize, 16);
    placeText(g_popupXamlArtistHost, g_popupXamlArtist,
              g_popupXamlArtistLeftFade, g_popupXamlArtistRightFade,
              sourceArtistRect, targetArtist, compactSpec.artistFontSize, 13);
    DipRect sourceIndicatorRect = PopupScreenRectToLocalDip(
        g_popupSourcePlaybackIndicatorRect, popupScreenPx, dpiScale);
    bool progressToIndicatorMorphActive =
        g_popupRestingCompact || g_popupClosing || morphProgress < 0.999;
    double openingProgressHandoff =
        !g_popupClosing && !g_popupRestingCompact
            ? SmootherStep(Clamp((morphProgress - 0.82) / 0.18, 0.0, 1.0))
            : 0.0;
    double indicatorMorphOpacity =
        g_popupClosing || g_popupRestingCompact
            ? 1.0
            : (progressToIndicatorMorphActive ? 1.0 - openingProgressHandoff
                                              : 0.0);
    if (g_popupXamlPlaybackIndicator) {
        double indicatorWidth =
            std::max(1.0, sourceIndicatorRect.right - sourceIndicatorRect.left);
        double indicatorHeight =
            std::max(1.0, sourceIndicatorRect.bottom - sourceIndicatorRect.top);
        double left = sourceIndicatorRect.left;
        double top = sourceIndicatorRect.top;
        g_popupXamlPlaybackIndicator.Width(indicatorWidth);
        g_popupXamlPlaybackIndicator.Height(indicatorHeight);
        controls::Canvas::SetLeft(g_popupXamlPlaybackIndicator, left);
        controls::Canvas::SetTop(g_popupXamlPlaybackIndicator, top);
        // The playback bars are part of the compact endpoint, so they fade in
        // during the last stretch of the collapse instead of appearing after
        // the spring settles. That makes the handoff a pure geometry swap
        // with no extra "widget loads then taskbar refreshes" step.
        double indicatorReveal = indicatorMorphOpacity;
        g_popupXamlPlaybackIndicator.Opacity(indicatorReveal);
        if (g_popupXamlPlaybackRevealClip) {
            double clipWidth = std::max(16.0, g_layout.playbackIndicatorWidth);
            double clipHeight =
                std::max(12.0, g_layout.playbackIndicatorHeight);
            double visibleWidth = clipWidth * indicatorReveal;
            g_popupXamlPlaybackRevealClip.Rect(
                {static_cast<float>(clipWidth - visibleWidth), 0,
                 static_cast<float>(visibleWidth),
                 static_cast<float>(clipHeight)});
        }
    }
    if (g_popupXamlCompactHoverScale) {
        g_popupXamlCompactHoverScale.CenterX(
            (sourceRect.left + sourceRect.right) * 0.5 - popupScreen.left);
        g_popupXamlCompactHoverScale.CenterY(
            (sourceRect.top + sourceRect.bottom) * 0.5 - popupScreen.top);
        if (!g_popupRestingCompact) {
            g_popupCompactHoverCurrent = 1.0;
            g_popupCompactHoverTarget = 1.0;
            g_popupXamlCompactHoverScale.ScaleX(1.0);
            g_popupXamlCompactHoverScale.ScaleY(1.0);
        }
    }

    double textOpacity = PopupClosingTextOpacity(morphProgress);
    g_popupTextBaseOpacity = textOpacity;
    if (!g_popupTextTransitionActive) {
        if (g_popupXamlTitle)
            g_popupXamlTitle.Opacity(textOpacity);
        if (g_popupXamlArtist)
            g_popupXamlArtist.Opacity(textOpacity);
        if (g_popupXamlTitleTranslate)
            g_popupXamlTitleTranslate.X(0.0);
        if (g_popupXamlArtistTranslate)
            g_popupXamlArtistTranslate.X(0.0);
        if (g_popupXamlOutgoingTitle)
            g_popupXamlOutgoingTitle.Opacity(0.0);
        if (g_popupXamlOutgoingArtist)
            g_popupXamlOutgoingArtist.Opacity(0.0);
        ApplyPopupTextForegrounds(false);
        SetPopupTextEdgeFadeOpacity(0.0);
    }

    // Morph the transport controls from the compact island area to their final
    // positions, instead of starting from the already-expanded control card.
    // The previous version used the card center as the source and delayed the
    // animation to progress 0.28~0.62. In practice that looked like a simple
    // fade-in because the source was already close to the target and the active
    // time window was too short.
    // Secondary controls do not need to participate in layout morphing. Keep
    // their final geometry stable and reveal them with compositor opacity,
    // matching the Dynamic Island pattern where the container morphs first
    // and secondary content follows.
    double controlsProgress = PopupControlMorphProgress(morphProgress);
    double controlsOpacity = PopupControlOpacityProgress(morphProgress);
    double controlsScale = 1.0;
    double buttonProgress = controlsProgress;
    bool showControls = controlsOpacity > 0.002;

    auto lerpRect = [&](DipRect const& source, RECT const& target,
                        double amount) {
        return DipRect{LerpDouble(source.left, target.left, amount),
                       LerpDouble(source.top, target.top, amount),
                       LerpDouble(source.right, target.right, amount),
                       LerpDouble(source.bottom, target.bottom, amount)};
    };

    double sourceCenterX = (sourceRect.left + sourceRect.right) * 0.5;
    double sourceCenterY = (sourceRect.top + sourceRect.bottom) * 0.5;

    // Morph the expanded playback progress into the compact equalizer's
    // position. Keep the endpoint as a thin accent-colored seed centered in
    // the indicator; the five bars take over during the final stretch.
    DipRect progressSource = sourceIndicatorRect;
    if (progressSource.right <= progressSource.left ||
        progressSource.bottom <= progressSource.top) {
        progressSource = {sourceCenterX - 10, sourceCenterY - 2,
                          sourceCenterX + 10, sourceCenterY + 2};
    } else {
        double indicatorCenterY =
            (progressSource.top + progressSource.bottom) * 0.5;
        double seedHeight = Clamp(g_layout.progressHeight, 3.0, 5.0);
        progressSource.top = indicatorCenterY - seedHeight * 0.5;
        progressSource.bottom = indicatorCenterY + seedHeight * 0.5;
    }
    DipRect progressScreen =
        lerpRect(progressSource, targetProgress, controlsProgress);
    // Keep a clearly visible colored seed almost all the way to the compact
    // endpoint. Only hand it to the five bars after it has actually arrived.
    double progressMorphOpacity = controlsOpacity;
    double progressTrackOpacity = controlsOpacity;
    double progressRatio = 0.0;
    if (g_popupXamlProgress && g_popupXamlProgress.Maximum() > 0.0) {
        progressRatio =
            Clamp(g_popupXamlProgress.Value() / g_popupXamlProgress.Maximum(),
                  0.0, 1.0);
        g_popupXamlProgress.Visibility(showControls ? Visibility::Visible
                                                    : Visibility::Collapsed);
        g_popupXamlProgress.Opacity(0.0);
        g_popupXamlProgress.Width(
            std::max(1.0, progressScreen.right - progressScreen.left));
        g_popupXamlProgress.Height(
            std::max(1.0, progressScreen.bottom - progressScreen.top));
        if (g_popupXamlProgressScale) {
            g_popupXamlProgressScale.ScaleX(controlsScale);
            g_popupXamlProgressScale.ScaleY(controlsScale);
        }
        controls::Canvas::SetLeft(g_popupXamlProgress,
                                  progressScreen.left - popupScreen.left);
        controls::Canvas::SetTop(g_popupXamlProgress,
                                 progressScreen.top - popupScreen.top);
    }
    double progressWidth =
        std::max(1.0, progressScreen.right - progressScreen.left) *
        controlsScale;
    double progressHeight =
        std::max(1.0, progressScreen.bottom - progressScreen.top) *
        controlsScale;
    double progressLeft =
        (progressScreen.left - popupScreen.left) +
        (std::max(1.0, progressScreen.right - progressScreen.left) -
         progressWidth) *
            0.5;
    double progressTop =
        (progressScreen.top - popupScreen.top) +
        (std::max(1.0, progressScreen.bottom - progressScreen.top) -
         progressHeight) *
            0.5;
    if (g_popupXamlProgressTrack) {
        g_popupXamlProgressTrack.Visibility(progressMorphOpacity > 0.002
                                                ? Visibility::Visible
                                                : Visibility::Collapsed);
        g_popupXamlProgressTrack.Opacity(progressTrackOpacity);
        g_popupXamlProgressTrack.Width(progressWidth);
        g_popupXamlProgressTrack.Height(std::max(4.0, progressHeight));
        double radius = kPopupG2ProgressCornerRadius;
        g_popupXamlProgressTrack.CornerRadius({radius, radius, radius, radius});
        controls::Canvas::SetLeft(g_popupXamlProgressTrack, progressLeft);
        controls::Canvas::SetTop(g_popupXamlProgressTrack, progressTop);
    }
    if (g_popupXamlProgressHitTarget) {
        double hitHeight = std::max(22.0, progressHeight + 16.0);
        g_popupXamlProgressHitTarget.Visibility(
            showControls ? Visibility::Visible : Visibility::Collapsed);
        g_popupXamlProgressHitTarget.Width(progressWidth);
        g_popupXamlProgressHitTarget.Height(hitHeight);
        controls::Canvas::SetLeft(g_popupXamlProgressHitTarget, progressLeft);
        controls::Canvas::SetTop(
            g_popupXamlProgressHitTarget,
            progressTop - (hitHeight - std::max(4.0, progressHeight)) * 0.5);
    }
    double progressThickness = std::max(4.0, progressHeight);
    double playedWidth = std::max(0.0, progressWidth * progressRatio);
    bool hasAnyProgress = playedWidth > 0.5;
    if (g_popupXamlProgressFill) {
        double fillWidth = hasAnyProgress ? playedWidth : 0.0;
        double fillOpacity =
            g_popupClosing || g_popupRestingCompact
                ? 0.0
                : (progressToIndicatorMorphActive
                       ? progressMorphOpacity * openingProgressHandoff
                       : progressMorphOpacity);
        g_popupXamlProgressFill.Visibility(fillOpacity > 0.002 && hasAnyProgress
                                               ? Visibility::Visible
                                               : Visibility::Collapsed);
        g_popupXamlProgressFill.Opacity(fillOpacity);
        g_popupXamlProgressFill.Width(fillWidth);
        g_popupXamlProgressFill.Height(progressThickness);
        double fillRadius = kPopupG2ProgressCornerRadius;
        g_popupXamlProgressFill.CornerRadius(
            {fillRadius, fillRadius, fillRadius, fillRadius});
        controls::Canvas::SetLeft(g_popupXamlProgressFill, progressLeft);
        controls::Canvas::SetTop(g_popupXamlProgressFill, progressTop);
    }

    // One-piece progress-to-equalizer morph. The five equalizer bars are the
    // colored progress fill itself: at the expanded endpoint they are wide,
    // gapless slices of one pill; while collapsing they travel together,
    // separate, narrow and grow into their frozen compact heights.
    if (g_popupXamlPlaybackIndicator && g_popupXamlPlaybackBars.size() == 5 &&
        progressToIndicatorMorphActive) {
        double targetTrackWidth = std::max(
            1.0,
            static_cast<double>(targetProgress.right - targetProgress.left));
        double targetFillWidth =
            std::max(4.0, targetTrackWidth * progressRatio);
        double targetCenterY =
            (static_cast<double>(targetProgress.top) + targetProgress.bottom) *
            0.5;
        double expandedSeedHeight = std::max(
            4.0,
            static_cast<double>(targetProgress.bottom - targetProgress.top));
        DipRect expandedSeed{
            static_cast<double>(targetProgress.left),
            targetCenterY - expandedSeedHeight * 0.5,
            static_cast<double>(targetProgress.left) + targetFillWidth,
            targetCenterY + expandedSeedHeight * 0.5};

        // Use the exact same spring progress as artwork and text. Applying a
        // second easing curve here makes the equalizer lag and then catch up.
        double geometryProgress = morphProgress;
        DipRect indicatorScreen{
            LerpDouble(sourceIndicatorRect.left, expandedSeed.left,
                       geometryProgress),
            LerpDouble(sourceIndicatorRect.top, expandedSeed.top,
                       geometryProgress),
            LerpDouble(sourceIndicatorRect.right, expandedSeed.right,
                       geometryProgress),
            LerpDouble(sourceIndicatorRect.bottom, expandedSeed.bottom,
                       geometryProgress)};
        double indicatorWidth =
            std::max(1.0, indicatorScreen.right - indicatorScreen.left);
        double indicatorHeight =
            std::max(1.0, indicatorScreen.bottom - indicatorScreen.top);
        g_popupXamlPlaybackIndicator.Width(indicatorWidth);
        g_popupXamlPlaybackIndicator.Height(indicatorHeight);
        g_popupXamlPlaybackIndicator.Opacity(indicatorMorphOpacity);
        controls::Canvas::SetLeft(g_popupXamlPlaybackIndicator,
                                  indicatorScreen.left - popupScreen.left);
        controls::Canvas::SetTop(g_popupXamlPlaybackIndicator,
                                 indicatorScreen.top - popupScreen.top);
        controls::Canvas::SetZIndex(g_popupXamlPlaybackIndicator, 20);
        if (g_popupXamlPlaybackRevealClip) {
            g_popupXamlPlaybackRevealClip.Rect(
                {0.0f, 0.0f, static_cast<float>(indicatorWidth),
                 static_cast<float>(indicatorHeight)});
        }

        double splitProgress = 1.0 - morphProgress;
        double compactGap = compactSpec.playbackBarGap;
        double gap = compactGap * splitProgress;
        double compactBarsWidth =
            5.0 * (compactSpec.playbackBarWidth + compactGap);
        double compactOuterPadding =
            std::max(0.0, (std::max(1.0, sourceIndicatorRect.right -
                                             sourceIndicatorRect.left) -
                           compactBarsWidth) *
                              0.5);
        double outerPadding = compactOuterPadding * splitProgress;
        double barWidth = std::max(
            0.8, (indicatorWidth - outerPadding * 2.0 - gap * 5.0) / 5.0);

        for (size_t i = 0; i < 5; ++i) {
            double compactHeight =
                std::max(2.0, g_compactPlaybackBarHeights[i]);
            double barHeight =
                LerpDouble(expandedSeedHeight, compactHeight, splitProgress);
            auto const& bar = g_popupXamlPlaybackBars[i];
            bar.Width(barWidth);
            bar.Height(barHeight);
            bar.Margin({gap * 0.5, 0, gap * 0.5, 0});

            double compactRadius = barWidth * 0.5;
            double seedRadius = expandedSeedHeight * 0.5;
            double topLeft = LerpDouble(i == 0 ? seedRadius : 0.0,
                                        compactRadius, splitProgress);
            double topRight = LerpDouble(i == 4 ? seedRadius : 0.0,
                                         compactRadius, splitProgress);
            double bottomRight = topRight;
            double bottomLeft = topLeft;
            bar.CornerRadius({topLeft, topRight, bottomRight, bottomLeft});
            double compactOpacity =
                i == 0 || i == 4 ? 0.86 : (i == 1 || i == 3 ? 0.94 : 1.0);
            bar.Opacity(LerpDouble(1.0, compactOpacity, splitProgress));
            g_popupPlaybackBarHeights[i] = barHeight;
        }
    } else if (g_popupXamlPlaybackIndicator) {
        controls::Canvas::SetZIndex(g_popupXamlPlaybackIndicator, 0);
    }
    if (g_popupXamlProgressGlowMask) {
        g_popupXamlProgressGlowMask.Visibility(Visibility::Collapsed);
        g_popupXamlProgressGlowMask.Opacity(0.0);
        if (g_popupXamlProgressGlowClip) {
            g_popupXamlProgressGlowClip.Rect({0.0f, 0.0f, 0.0f, 0.0f});
        }
        for (auto const& layer : g_popupXamlProgressGlowLayers) {
            layer.Visibility(Visibility::Collapsed);
            layer.Opacity(0.0);
        }
    }

    for (auto const& layer : g_popupXamlProgressCoreBlurLayers) {
        layer.Visibility(Visibility::Collapsed);
        layer.Opacity(0.0);
    }

    if (g_popupXamlProgressGlowCore) {
        g_popupXamlProgressGlowCore.Visibility(Visibility::Collapsed);
        g_popupXamlProgressGlowCore.Opacity(0.0);
    }

    auto placeTimeText = [&](TextBlock const& text, DipRect const& source,
                             RECT const& target, bool alignRight) {
        if (!text) {
            return;
        }
        DipRect screen = lerpRect(source, target, controlsProgress);
        text.Visibility(showControls ? Visibility::Visible
                                     : Visibility::Collapsed);
        text.Opacity(controlsOpacity);
        text.Width(std::max(1.0, screen.right - screen.left));
        text.Height(std::max(1.0, screen.bottom - screen.top));
        text.TextAlignment(alignRight ? xaml::TextAlignment::Right
                                      : xaml::TextAlignment::Left);
        controls::Canvas::SetLeft(text, screen.left - popupScreen.left);
        controls::Canvas::SetTop(text, screen.top - popupScreen.top);
    };

    DipRect elapsedSource{progressSource.left, progressSource.bottom + 2,
                          progressSource.left + 12, progressSource.bottom + 16};
    DipRect durationSource{progressSource.right - 12, progressSource.bottom + 2,
                           progressSource.right, progressSource.bottom + 16};
    placeTimeText(g_popupXamlElapsed, elapsedSource, targetElapsed, false);
    placeTimeText(g_popupXamlDuration, durationSource, targetDuration, true);

    double controlsWidth = PopupControlsWidth();
    double controlsHeight = PopupControlsHeight();
    DipRect controlsSource = sourceControlsRect;
    if (controlsSource.right <= controlsSource.left ||
        controlsSource.bottom <= controlsSource.top) {
        controlsSource = {sourceCenterX - 14, sourceCenterY - 10,
                          sourceCenterX + 14, sourceCenterY + 10};
    }
    DipRect controlsScreen =
        lerpRect(controlsSource, targetControls, controlsProgress);
    if (g_popupXamlControls) {
        g_popupXamlControls.Visibility(showControls ? Visibility::Visible
                                                    : Visibility::Collapsed);
        g_popupXamlControls.Opacity(controlsOpacity);
        g_popupXamlControls.Width(controlsWidth);
        g_popupXamlControls.Height(controlsHeight);

        double screenWidth =
            std::max(1.0, controlsScreen.right - controlsScreen.left);
        double screenHeight =
            std::max(1.0, controlsScreen.bottom - controlsScreen.top);
        double left = controlsScreen.left - popupScreen.left +
                      (screenWidth - controlsWidth) * 0.5;
        double top = controlsScreen.top - popupScreen.top +
                     (screenHeight - controlsHeight) * 0.5;

        controls::Canvas::SetLeft(g_popupXamlControls, left);
        controls::Canvas::SetTop(g_popupXamlControls, top);

        // Keep child button slots fixed in the local Canvas coordinates instead
        // of scaling the whole StackPanel. The previous group RenderTransform
        // could diverge from hit testing under high DPI, making the hover
        // highlight and glyph appear offset from each other.
        int index = 0;
        for (auto const& child : g_popupXamlControls.Children()) {
            if (auto buttonSurface = child.try_as<Border>()) {
                double buttonWidth =
                    LerpDouble(32.0, PopupButtonWidth(), buttonProgress);
                double buttonHeight =
                    LerpDouble(28.0, PopupButtonHeight(), buttonProgress);
                double finalButtonLeft =
                    PopupButtonLeft(index) +
                    (PopupButtonWidth() - buttonWidth) * 0.5;
                double finalButtonTop =
                    PopupButtonTop() +
                    (PopupButtonHeight() - buttonHeight) * 0.5;
                double sourceGroupWidth =
                    std::max(1.0, controlsSource.right - controlsSource.left);
                double buttonCount = std::max(
                    1.0,
                    static_cast<double>(g_popupXamlControls.Children().Size()));
                double sourceSlotWidth = sourceGroupWidth / buttonCount;
                double sourceButtonLeft =
                    (controlsWidth - sourceGroupWidth) * 0.5 +
                    sourceSlotWidth * static_cast<double>(index) +
                    (sourceSlotWidth - buttonWidth) * 0.5;
                double sourceButtonTop =
                    controlsHeight * 0.5 - buttonHeight * 0.5;
                double buttonLeft =
                    sourceButtonLeft +
                    (finalButtonLeft - sourceButtonLeft) * buttonProgress;
                double buttonTop =
                    sourceButtonTop +
                    (finalButtonTop - sourceButtonTop) * buttonProgress;
                controls::Canvas::SetLeft(buttonSurface, buttonLeft);
                controls::Canvas::SetTop(buttonSurface, buttonTop);
                buttonSurface.Width(buttonWidth);
                buttonSurface.Height(buttonHeight);
                buttonSurface.Opacity(1.0);
                buttonSurface.Visibility(Visibility::Visible);
                if (auto icon =
                        buttonSurface.Child().try_as<controls::FontIcon>()) {
                    icon.Visibility(Visibility::Visible);
                    icon.Opacity(1.0);
                    icon.Width(buttonWidth);
                    icon.Height(buttonHeight);
                    icon.Margin({0, 0, 0, 0});
                    icon.HorizontalAlignment(HorizontalAlignment::Center);
                    icon.VerticalAlignment(VerticalAlignment::Center);
                } else if (auto text =
                               buttonSurface.Child().try_as<TextBlock>()) {
                    text.Visibility(Visibility::Visible);
                    text.Opacity(1.0);
                    text.Width(buttonWidth);
                    text.Height(buttonHeight);
                    text.Margin({0, 0, 0, 0});
                }
                ++index;
            }
        }
    }

    // System volume row from the reference, without the AirPlay capsule.
    double volumeOpacity = controlsOpacity;
    RECT volumeTarget{targetCard.left + 46, targetCard.top + 218,
                      targetCard.right - 46, targetCard.top + 224};
    DipRect volumeSource{sourceCenterX - 1, sourceCenterY - 1,
                         sourceCenterX + 1, sourceCenterY + 1};
    DipRect volumeScreen =
        lerpRect(volumeSource, volumeTarget, controlsProgress);
    double volumeTop = volumeScreen.top;
    double volumeLeft = volumeScreen.left;
    double volumeRight = volumeScreen.right;
    double volumeWidth = std::max(1.0, volumeRight - volumeLeft);
    auto setVolumeElement = [&](FrameworkElement const& element, double left,
                                double top, double width, double height) {
        if (!element)
            return;
        element.Visibility(showControls ? Visibility::Visible
                                        : Visibility::Collapsed);
        element.Opacity(volumeOpacity);
        element.Width(width);
        element.Height(height);
        controls::Canvas::SetLeft(element, left - popupScreen.left);
        controls::Canvas::SetTop(element, top - popupScreen.top);
    };
    setVolumeElement(g_popupXamlVolumeTrack, volumeLeft, volumeTop, volumeWidth,
                     6.0);
    setVolumeElement(g_popupXamlVolumeFill, volumeLeft, volumeTop,
                     volumeWidth * Clamp(g_popupSystemVolume, 0.0, 1.0), 6.0);
    setVolumeElement(g_popupXamlVolumeHitTarget, volumeLeft, volumeTop - 11.0,
                     volumeWidth, 28.0);
    double iconSpread = 29.0 * controlsProgress;
    setVolumeElement(g_popupXamlVolumeLowIcon, volumeLeft - iconSpread,
                     volumeTop - 7.0, 20.0, 20.0);
    setVolumeElement(g_popupXamlVolumeHighIcon, volumeRight + iconSpread - 27.0,
                     volumeTop - 9.0, 27.0, 24.0);

    ApplyPopupMediaTransitionVisuals();
}

bool IsInsideRoundedPopupSample(double x,
                                double y,
                                int width,
                                int height,
                                double radius,
                                double inset) {
    double left = inset;
    double top = inset;
    double right = width - inset;
    double bottom = height - inset;
    if (x < left || x >= right || y < top || y >= bottom) {
        return false;
    }
    radius = std::max(0.0, radius - inset);
    double nearestX = Clamp(x, left + radius, right - radius);
    double nearestY = Clamp(y, top + radius, bottom - radius);
    double dx = x - nearestX;
    double dy = y - nearestY;
    return dx * dx + dy * dy <= radius * radius;
}

double RoundedPopupCoverage(int x,
                            int y,
                            int width,
                            int height,
                            double radius,
                            double inset) {
    constexpr double offsets[] = {0.25, 0.75};
    int samples = 0;
    for (double offsetY : offsets) {
        for (double offsetX : offsets) {
            if (IsInsideRoundedPopupSample(x + offsetX, y + offsetY, width,
                                           height, radius, inset)) {
                ++samples;
            }
        }
    }
    return samples / 4.0;
}

void RenderExpandedPopupLayer() {
    if (!g_expandedPopup) {
        return;
    }
    if (g_popupXamlRoot) {
        UpdatePopupXamlVisuals();
        return;
    }

    RECT windowRect{};
    GetWindowRect(g_expandedPopup, &windowRect);
    int width = windowRect.right - windowRect.left;
    int height = windowRect.bottom - windowRect.top;
    if (width <= 0 || height <= 0) {
        return;
    }

    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = -height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;

    void* pixelMemory = nullptr;
    HDC screenDc = GetDC(nullptr);
    HDC memoryDc = CreateCompatibleDC(screenDc);
    HBITMAP surface = CreateDIBSection(screenDc, &info, DIB_RGB_COLORS,
                                       &pixelMemory, nullptr, 0);
    if (!memoryDc || !surface || !pixelMemory) {
        if (surface)
            DeleteObject(surface);
        if (memoryDc)
            DeleteDC(memoryDc);
        if (screenDc)
            ReleaseDC(nullptr, screenDc);
        return;
    }

    HGDIOBJ oldBitmap = SelectObject(memoryDc, surface);
    memset(pixelMemory, 0, static_cast<size_t>(width) * height * 4);
    bool dark = IsDarkModeApprox();
    RECT fullSurface{0, 0, width, height};
    HBRUSH baseBrush =
        CreateSolidBrush(dark ? RGB(42, 42, 47) : RGB(243, 243, 246));
    FillRect(memoryDc, &fullSurface, baseBrush);
    DeleteObject(baseBrush);
    PaintExpandedPopup(g_expandedPopup, memoryDc);

    BYTE backgroundAlpha = dark ? 0xC8 : 0xD4;
    BYTE backgroundR = dark ? 42 : 243;
    BYTE backgroundG = dark ? 42 : 243;
    BYTE backgroundB = dark ? 47 : 246;
    auto pixels = static_cast<BYTE*>(pixelMemory);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            BYTE* pixel = pixels + (static_cast<size_t>(y) * width + x) * 4;
            double outerCoverage =
                RoundedPopupCoverage(x, y, width, height, 20.0, 0.0);
            if (outerCoverage <= 0.0) {
                pixel[0] = 0;
                pixel[1] = 0;
                pixel[2] = 0;
                pixel[3] = 0;
                continue;
            }

            bool isBackground =
                std::abs(static_cast<int>(pixel[2]) - backgroundR) <= 2 &&
                std::abs(static_cast<int>(pixel[1]) - backgroundG) <= 2 &&
                std::abs(static_cast<int>(pixel[0]) - backgroundB) <= 2;
            if (isBackground) {
                BYTE alpha = static_cast<BYTE>(
                    std::lround(backgroundAlpha * outerCoverage));
                pixel[0] =
                    static_cast<BYTE>(std::lround(backgroundB * alpha / 255.0));
                pixel[1] =
                    static_cast<BYTE>(std::lround(backgroundG * alpha / 255.0));
                pixel[2] =
                    static_cast<BYTE>(std::lround(backgroundR * alpha / 255.0));
                pixel[3] = alpha;
            } else {
                BYTE alpha =
                    static_cast<BYTE>(std::lround(255.0 * outerCoverage));
                pixel[0] =
                    static_cast<BYTE>(std::lround(pixel[0] * alpha / 255.0));
                pixel[1] =
                    static_cast<BYTE>(std::lround(pixel[1] * alpha / 255.0));
                pixel[2] =
                    static_cast<BYTE>(std::lround(pixel[2] * alpha / 255.0));
                pixel[3] = alpha;
            }
        }
    }

    POINT destination{windowRect.left, windowRect.top};
    POINT source{0, 0};
    SIZE size{width, height};
    BLENDFUNCTION blend{AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
    UpdateLayeredWindow(g_expandedPopup, screenDc, &destination, &size,
                        memoryDc, &source, 0, &blend, ULW_ALPHA);

    SelectObject(memoryDc, oldBitmap);
    DeleteObject(surface);
    DeleteDC(memoryDc);
    ReleaseDC(nullptr, screenDc);
}

bool GetElementScreenRect(FrameworkElement const& element, RECT& result) {
    if (!element || !g_taskbarWnd) {
        return false;
    }

    try {
        // The island lives in the taskbar's XAML composition bridge window,
        // not in Shell_TrayWnd itself. During auto-hide the bridge moves while
        // Shell_TrayWnd stays put, so the element rect must be computed from
        // the bridge's window rect or the popup tracks a ghost position.
        HWND hostWnd = (g_taskbarXamlHostWnd && IsWindow(g_taskbarXamlHostWnd))
                           ? g_taskbarXamlHostWnd
                           : g_taskbarWnd;
        RECT host{};
        GetWindowRect(hostWnd, &host);
        auto transform = element.TransformToVisual(nullptr);
        auto point = transform.TransformPoint({0, 0});
        double scale = static_cast<double>(GetDpiForWindow(hostWnd)) / 96.0;
        // Round both physical edges from the same DIP coordinate space. Never
        // round the origin and size independently: at fractional DPI that can
        // make the popup endpoint one pixel wider/taller than the native item.
        result.left =
            host.left + static_cast<int>(std::lround(point.X * scale));
        result.top = host.top + static_cast<int>(std::lround(point.Y * scale));
        result.right =
            host.left + static_cast<int>(std::lround(
                            (point.X + element.ActualWidth()) * scale));
        result.bottom =
            host.top + static_cast<int>(std::lround(
                           (point.Y + element.ActualHeight()) * scale));
        return result.right > result.left && result.bottom > result.top;
    } catch (...) {
        return false;
    }
}

double PopupDpiScale(HWND hwnd) {
    HWND source =
        hwnd ? hwnd : (g_expandedPopup ? g_expandedPopup : g_taskbarWnd);
    UINT dpi = source ? GetDpiForWindow(source) : 96;
    if (dpi == 0) {
        dpi = 96;
    }
    return std::max(0.01, static_cast<double>(dpi) / 96.0);
}

int PopupDipToPx(double value, HWND hwnd) {
    return static_cast<int>(std::lround(value * PopupDpiScale(hwnd)));
}

DipRect PopupScreenRectToLocalDip(RECT const& rect,
                                  RECT const& popupScreenPx,
                                  double scale) {
    return {(rect.left - popupScreenPx.left) / scale,
            (rect.top - popupScreenPx.top) / scale,
            (rect.right - popupScreenPx.left) / scale,
            (rect.bottom - popupScreenPx.top) / scale};
}

bool TaskbarPopupOpensDown(RECT const& taskbarRect,
                           MONITORINFO const& monitorInfo) {
    if (taskbarRect.right <= taskbarRect.left ||
        taskbarRect.bottom <= taskbarRect.top) {
        return false;
    }

    int distanceToTop = std::abs(taskbarRect.top - monitorInfo.rcMonitor.top);
    int distanceToBottom =
        std::abs(monitorInfo.rcMonitor.bottom - taskbarRect.bottom);
    if (distanceToTop != distanceToBottom) {
        return distanceToTop < distanceToBottom;
    }

    int taskbarCenter = (taskbarRect.top + taskbarRect.bottom) / 2;
    int monitorCenter =
        (monitorInfo.rcMonitor.top + monitorInfo.rcMonitor.bottom) / 2;
    return taskbarCenter <= monitorCenter;
}

void CapturePopupSourceGeometry(bool refreshSourceOnly = false) {
    auto compactSpec = CurrentCompactVisualSpec();
    if (!GetElementScreenRect(g_playerGrid, g_popupSourceRect)) {
        RECT taskbar{};
        GetWindowRect(g_taskbarWnd, &taskbar);
        g_popupSourceRect = {
            taskbar.left, taskbar.top,
            taskbar.left + static_cast<LONG>(
                               PopupDipToPx(compactSpec.width, g_taskbarWnd)),
            taskbar.top + static_cast<LONG>(
                              PopupDipToPx(compactSpec.height, g_taskbarWnd))};
    }
    auto art = FindChildByName(g_playerGrid, L"Island_ArtFallback");
    if (!GetElementScreenRect(art, g_popupSourceArtRect)) {
        // Fallback: circular cover bounds at ((H - D)/2, (H - D)/2).
        double artInset = g_layout.artInset;
        g_popupSourceArtRect = {
            g_popupSourceRect.left + PopupDipToPx(artInset, g_taskbarWnd),
            g_popupSourceRect.top + PopupDipToPx(artInset, g_taskbarWnd),
            g_popupSourceRect.left +
                PopupDipToPx(artInset + g_layout.artSize, g_taskbarWnd),
            g_popupSourceRect.top +
                PopupDipToPx(artInset + g_layout.artSize, g_taskbarWnd)};
    }
    double textColumnLeftDip =
        g_layout.artInset + g_layout.artSize + g_layout.textMarginX;
    auto title = FindChildByName(g_playerGrid, L"Island_Title");
    if (!GetElementScreenRect(title, g_popupSourceTitleRect)) {
        g_popupSourceTitleRect = {
            g_popupSourceRect.left +
                PopupDipToPx(textColumnLeftDip, g_taskbarWnd),
            g_popupSourceRect.top + PopupDipToPx(5.0, g_taskbarWnd),
            g_popupSourceRect.right -
                PopupDipToPx(g_layout.contentMarginX, g_taskbarWnd),
            g_popupSourceRect.top + PopupDipToPx(22.0, g_taskbarWnd)};
    }
    auto artist = FindChildByName(g_playerGrid, L"Island_CompactArtist");
    if (!GetElementScreenRect(artist, g_popupSourceArtistRect)) {
        g_popupSourceArtistRect = {
            g_popupSourceRect.left +
                PopupDipToPx(textColumnLeftDip, g_taskbarWnd),
            g_popupSourceRect.top + PopupDipToPx(21.0, g_taskbarWnd),
            g_popupSourceRect.right -
                PopupDipToPx(g_layout.contentMarginX, g_taskbarWnd),
            g_popupSourceRect.bottom - PopupDipToPx(4.0, g_taskbarWnd)};
    }

    // The individual TextBlock transform can still be mid-transition when a
    // close starts, so its screen rect may describe only the clipped/visible
    // fragment. The compact endpoint must use the stable text column instead;
    // otherwise that temporary narrow rect becomes permanent after collapse.
    RECT textHostRect{};
    if (g_compactTextHost &&
        GetElementScreenRect(g_compactTextHost, textHostRect) &&
        textHostRect.right - textHostRect.left >
            PopupDipToPx(20.0, g_taskbarWnd)) {
        g_popupSourceTitleRect.left = textHostRect.left;
        g_popupSourceTitleRect.right = textHostRect.right;
        g_popupSourceArtistRect.left = textHostRect.left;
        g_popupSourceArtistRect.right = textHostRect.right;
    }

    auto progress = FindChildByName(g_playerGrid, L"Island_Progress");
    if (!GetElementScreenRect(progress, g_popupSourceProgressRect)) {
        int progressWidth = PopupDipToPx(g_layout.progressWidth, g_taskbarWnd);
        int progressHeight =
            std::max(1, PopupDipToPx(g_layout.progressHeight, g_taskbarWnd));
        int contentRight = g_popupSourceRect.right -
                           PopupDipToPx(g_layout.contentMarginX, g_taskbarWnd);
        int centerY = (g_popupSourceRect.top + g_popupSourceRect.bottom) / 2;
        g_popupSourceProgressRect = {
            contentRight - progressWidth, centerY - progressHeight / 2,
            contentRight, centerY - progressHeight / 2 + progressHeight};
    }

    auto details = FindChildByName(g_playerGrid, L"Island_Details");
    if (!GetElementScreenRect(details, g_popupSourceControlsRect)) {
        int compactButtonWidth = PopupDipToPx(32.0, g_taskbarWnd);
        int compactButtonHeight = PopupDipToPx(28.0, g_taskbarWnd);
        int compactButtonGap = PopupDipToPx(4.0, g_taskbarWnd);
        int controlsWidth = compactButtonWidth * 4 + compactButtonGap * 3;
        int centerY = (g_popupSourceRect.top + g_popupSourceRect.bottom) / 2;
        int right = g_popupSourceProgressRect.left -
                    PopupDipToPx(g_layout.progressMarginLeft, g_taskbarWnd);
        if (right <= g_popupSourceRect.left) {
            right = g_popupSourceRect.right -
                    PopupDipToPx(g_layout.contentMarginX, g_taskbarWnd);
        }
        g_popupSourceControlsRect = {
            right - controlsWidth, centerY - compactButtonHeight / 2, right,
            centerY - compactButtonHeight / 2 + compactButtonHeight};
        if (g_popupSourceControlsRect.left < g_popupSourceRect.left) {
            int centerX =
                (g_popupSourceRect.left + g_popupSourceRect.right) / 2;
            g_popupSourceControlsRect = {
                centerX - controlsWidth / 2, centerY - compactButtonHeight / 2,
                centerX - controlsWidth / 2 + controlsWidth,
                centerY - compactButtonHeight / 2 + compactButtonHeight};
        }
    }

    auto indicator = FindChildByName(g_playerGrid, L"Island_PlaybackIndicator");
    if (!GetElementScreenRect(indicator, g_popupSourcePlaybackIndicatorRect)) {
        int indicatorWidth =
            PopupDipToPx(compactSpec.playbackIndicatorWidth, g_taskbarWnd);
        int indicatorHeight =
            PopupDipToPx(compactSpec.playbackIndicatorHeight, g_taskbarWnd);
        int right = g_popupSourceRect.right -
                    PopupDipToPx(compactSpec.contentMarginX, g_taskbarWnd);
        int centerY = (g_popupSourceRect.top + g_popupSourceRect.bottom) / 2;
        g_popupSourcePlaybackIndicatorRect = {
            right - indicatorWidth, centerY - indicatorHeight / 2, right,
            centerY - indicatorHeight / 2 + indicatorHeight};
    }

    if (refreshSourceOnly) {
        return;
    }

    HMONITOR monitor =
        MonitorFromRect(&g_popupSourceRect, MONITOR_DEFAULTTONEAREST);
    MONITORINFO monitorInfo{sizeof(monitorInfo)};
    if (GetMonitorInfoW(monitor, &monitorInfo)) {
        double dpiScale = PopupDpiScale(g_taskbarWnd);
        int monitorWidthPx =
            monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
        int monitorWidthDip = std::max(
            1, static_cast<int>(std::floor(monitorWidthPx / dpiScale)));
        RECT taskbar{};
        GetWindowRect(g_taskbarWnd, &taskbar);
        bool opensDown = TaskbarPopupOpensDown(taskbar, monitorInfo);
        g_popupOpensDown = opensDown;
        g_taskbarAtTop = opensDown;
        int popupGap = PopupDipToPx(opensDown ? 2.0 : 8.0, g_taskbarWnd);
        int edgePad = PopupDipToPx(12.0, g_taskbarWnd);
        int finalTop = taskbar.bottom + popupGap;
        int finalBottom = taskbar.top - popupGap;
        int availableHeightPx =
            opensDown ? monitorInfo.rcMonitor.bottom - finalTop - edgePad
                      : finalBottom - monitorInfo.rcMonitor.top - edgePad;
        int availableHeightDip = std::max(
            1, static_cast<int>(std::floor(availableHeightPx / dpiScale)));

        int finalWidthDip = 0;
        int finalHeightDip = 0;
        if (g_settings.compact) {
            int maxCardWidth =
                std::max(kPopupCompactMinimumCardWidth,
                         monitorWidthDip - 24 - kPopupHostShadowMargin * 2);
            int cardWidth =
                Clamp(std::min(g_settings.expandedWidth, maxCardWidth),
                      kPopupCompactMinimumCardWidth, 640);
            finalWidthDip = PopupCompactFinalWidth(cardWidth);
            finalHeightDip = PopupCompactFinalHeight();
        } else {
            int maxArtBySetting = std::max(
                96, g_settings.expandedWidth -
                        (PopupSurfaceGap() * 2 + kPopupHostShadowMargin * 2));
            int maxArtByMonitorWidth = std::max(
                96, monitorWidthDip - 24 -
                        (PopupSurfaceGap() * 2 + kPopupHostShadowMargin * 2));
            int maxArtByHeight = std::max(
                96, availableHeightDip -
                        (kPopupCardHeight + PopupArtCardGap() +
                         PopupSurfaceGap() * 2 + kPopupHostShadowMargin * 2));
            int targetArt =
                Clamp(std::min({maxArtBySetting, maxArtByMonitorWidth,
                                maxArtByHeight, kPopupMaximumArtSize}),
                      96, kPopupMaximumArtSize);
            if (targetArt < kPopupMinimumArtSize &&
                maxArtByHeight >= kPopupMinimumArtSize) {
                targetArt = kPopupMinimumArtSize;
            }
            finalWidthDip = PopupFinalWidthFromArtSize(targetArt);
            finalHeightDip = PopupFinalHeightFromArtSize(targetArt);
        }
        int finalWidth = PopupDipToPx(finalWidthDip, g_taskbarWnd);
        int finalHeight = PopupDipToPx(finalHeightDip, g_taskbarWnd);
        g_popupExpandedWidth = static_cast<double>(finalWidth);
        g_popupExpandedHeight = static_cast<double>(finalHeight);

        int rightSpace = monitorInfo.rcMonitor.right - g_popupSourceRect.left;
        int leftSpace = g_popupSourceRect.right - monitorInfo.rcMonitor.left;
        if (g_settings.position.rfind(L"tray_", 0) == 0 ||
            g_settings.position.rfind(L"taskbar_", 0) == 0) {
            g_popupExpandsRight = PopupShouldExpandRight(monitorInfo);
        } else {
            g_popupExpandsRight =
                rightSpace >= static_cast<int>(g_popupExpandedWidth) ||
                rightSpace >= leftSpace;
        }
        int finalLeft = g_popupExpandsRight
                            ? g_popupSourceRect.left
                            : g_popupSourceRect.right - finalWidth;
        finalLeft = Clamp(
            finalLeft, static_cast<int>(monitorInfo.rcMonitor.left) + edgePad,
            static_cast<int>(monitorInfo.rcMonitor.right) - finalWidth -
                edgePad);
        if (opensDown) {
            g_popupFinalRect = {finalLeft, finalTop, finalLeft + finalWidth,
                                finalTop + finalHeight};
        } else {
            g_popupFinalRect = {finalLeft, finalBottom - finalHeight,
                                finalLeft + finalWidth, finalBottom};
        }
    } else {
        int finalWidthDip = 0;
        int finalHeightDip = 0;
        if (g_settings.compact) {
            int cardWidth = Clamp(g_settings.expandedWidth,
                                  kPopupCompactMinimumCardWidth, 640);
            finalWidthDip = PopupCompactFinalWidth(cardWidth);
            finalHeightDip = PopupCompactFinalHeight();
        } else {
            int targetArt =
                Clamp(g_settings.expandedWidth -
                          (PopupSurfaceGap() * 2 + kPopupHostShadowMargin * 2),
                      96, kPopupMaximumArtSize);
            finalWidthDip = PopupFinalWidthFromArtSize(targetArt);
            finalHeightDip = PopupFinalHeightFromArtSize(targetArt);
        }
        int finalWidth = PopupDipToPx(finalWidthDip, g_taskbarWnd);
        int finalHeight = PopupDipToPx(finalHeightDip, g_taskbarWnd);
        RECT taskbar{};
        bool opensDown =
            GetWindowRect(g_taskbarWnd, &taskbar) &&
            g_popupSourceRect.top <= (GetSystemMetrics(SM_YVIRTUALSCREEN) +
                                      GetSystemMetrics(SM_CYVIRTUALSCREEN) / 2);
        g_popupOpensDown = opensDown;
        g_taskbarAtTop = opensDown;
        int popupGap = PopupDipToPx(opensDown ? 2.0 : 8.0, g_taskbarWnd);
        g_popupExpandedWidth = static_cast<double>(finalWidth);
        g_popupExpandedHeight = static_cast<double>(finalHeight);
        g_popupExpandsRight = true;
        if (opensDown) {
            int finalTop = taskbar.bottom + popupGap;
            g_popupFinalRect = {g_popupSourceRect.left, finalTop,
                                g_popupSourceRect.left + finalWidth,
                                finalTop + finalHeight};
        } else {
            g_popupFinalRect = {g_popupSourceRect.left,
                                g_popupSourceRect.top - finalHeight - popupGap,
                                g_popupSourceRect.left + finalWidth,
                                g_popupSourceRect.top - popupGap};
        }
    }
}

void UpdatePopupBackdropOverlayWindow();
bool CalculatePopupBackdropOverlayRect(RECT& overlayRect, int& cornerRadiusPx);
void HidePopupBackdropOverlayWindowVisualOnly();
void HidePopupBackdropOverlayWindow();
void StopPopupOverlayWgcBackdrop();
void ReleasePopupOverlayWgcDeviceResources();
bool StartPopupOverlayWgcBackdrop(
    RECT const& captureRect,
    int widthPx,
    int heightPx,
    PopupOverlayWgcRenderParameters const& renderParameters);
bool SetPopupWindowCaptureExclusion(HWND hwnd, bool exclude);
bool SetExpandedPopupCaptureExclusion(bool exclude);
void ClearPopupBackdropOverlayHandoffCache();
bool ClearPopupBackdropOverlayLayeredSurface(HWND hwnd);

// ===== Popup positioning =====
void PositionExpandedPopup() {
    if (!g_expandedPopup || !g_taskbarWnd) {
        return;
    }

    if (g_popupXamlRoot) {
        // Smooth XAML path: keep the DesktopWindowXamlSource host fixed for the
        // whole open/close cycle. The old implementation resized/moved this
        // HWND every frame, which is expensive in Explorer and looked like
        // dropped frames. The visible morph now happens entirely inside XAML.
        RECT hostRect = g_popupHostRect;
        if (hostRect.right <= hostRect.left ||
            hostRect.bottom <= hostRect.top) {
            hostRect = UnionPopupRects(g_popupSourceRect, g_popupFinalRect);
        }
        int width = std::max(1L, hostRect.right - hostRect.left);
        int height = std::max(1L, hostRect.bottom - hostRect.top);
        g_popupCurrentWidth = width;
        g_popupCurrentHeight = height;

        if (!EqualRect(&hostRect, &g_lastPopupWindowRect)) {
            g_lastPopupWindowRect = hostRect;
            SetWindowPos(g_expandedPopup, HWND_TOPMOST, hostRect.left,
                         hostRect.top, width, height,
                         SWP_NOACTIVATE | SWP_NOCOPYBITS | SWP_NOZORDER |
                             SWP_NOOWNERZORDER | SWP_NOSENDCHANGING);
            if (g_popupXamlChild) {
                MoveWindow(g_popupXamlChild, 0, 0, width, height, FALSE);
            }
        }
        UpdatePopupBackdropOverlayWindow();
        return;
    }

    // GDI fallback path keeps the old window-level morph.
    double progress = PopupProgress();
    int left = LerpInt(g_popupSourceRect.left, g_popupFinalRect.left, progress);
    int top = LerpInt(g_popupSourceRect.top, g_popupFinalRect.top, progress);
    int right =
        LerpInt(g_popupSourceRect.right, g_popupFinalRect.right, progress);
    int bottom =
        LerpInt(g_popupSourceRect.bottom, g_popupFinalRect.bottom, progress);
    int width = std::max(1, right - left);
    int height = std::max(1, bottom - top);
    g_popupCurrentWidth = width;
    g_popupCurrentHeight = height;

    RECT newRect{left, top, left + width, top + height};
    if (EqualRect(&newRect, &g_lastPopupWindowRect)) {
        return;
    }
    g_lastPopupWindowRect = newRect;
    SetWindowPos(g_expandedPopup, HWND_TOPMOST, left, top, width, height,
                 SWP_NOACTIVATE | SWP_NOCOPYBITS | SWP_NOZORDER |
                     SWP_NOOWNERZORDER | SWP_NOSENDCHANGING);
    if (g_popupXamlChild) {
        MoveWindow(g_popupXamlChild, 0, 0, width, height, FALSE);
    }
    UpdatePopupBackdropOverlayWindow();
}
void SetCompactIslandSuppressed(bool suppressed);
void StartPopupXamlRenderLoop();
void StopHoverRenderLoop();
void StopCompactTextRenderLoop();
void StopCompactProgressRenderLoop();
void StopCompactPlaybackIndicatorRenderLoop();
bool ShowPopupToggleHitWindow();
void HidePopupToggleHitWindow();
void DestroyPopupToggleHitWindow();

// ===== Compact island render loops =====
bool UpdateCompactProgressFromSnapshot() {
    if (!g_compactProgress) {
        return false;
    }

    std::chrono::steady_clock::time_point timestamp;
    MediaState state = SnapshotMediaWithTimestamp(timestamp);
    auto now = std::chrono::steady_clock::now();
    if (ShouldForceMediaProgressToZero(state, now)) {
        g_compactProgress.Value(0.0);
        return state.hasSession && state.isPlaying && state.durationTicks > 0;
    }

    int64_t positionTicks = state.positionTicks;
    if (state.hasSession && state.isPlaying && state.durationTicks > 0 &&
        timestamp.time_since_epoch().count() != 0) {
        double ageSeconds =
            std::chrono::duration_cast<std::chrono::milliseconds>(now -
                                                                  timestamp)
                .count() /
            1000.0;
        // The event-driven media worker has a 30-second safety refresh, so local
        // interpolation can remain smooth between provider timeline events.
        ageSeconds = Clamp(ageSeconds, 0.0, 30.0);
        positionTicks += static_cast<int64_t>(ageSeconds * 10000000.0);
    }

    double value = 0.0;
    if (state.hasSession && state.durationTicks > 0) {
        positionTicks =
            std::clamp<int64_t>(positionTicks, 0, state.durationTicks);
        value = Clamp(static_cast<double>(positionTicks) /
                          static_cast<double>(state.durationTicks) * 1000.0,
                      0.0, 1000.0);
    }
    g_compactProgress.Value(value);
    return state.hasSession && state.isPlaying && state.durationTicks > 0;
}

void StopCompactProgressRenderLoop() {
    if (!g_compactProgressRenderingHooked) {
        return;
    }
    try {
        mediax::CompositionTarget::Rendering(g_compactProgressRenderingToken);
    } catch (...) {
    }
    g_compactProgressRenderingHooked = false;
    g_lastCompactProgressFrameTime = {};
}

void OnCompactProgressRendering(
    winrt::Windows::Foundation::IInspectable const&,
    winrt::Windows::Foundation::IInspectable const&) {
    try {
        if (!g_playerGrid || !g_compactProgress || g_expanded || g_unloading) {
            StopCompactProgressRenderLoop();
            return;
        }

        auto now = std::chrono::steady_clock::now();
        if (g_lastCompactProgressFrameTime.time_since_epoch().count() != 0 &&
            now - g_lastCompactProgressFrameTime <
                std::chrono::milliseconds(33)) {
            return;
        }
        g_lastCompactProgressFrameTime = now;

        if (!UpdateCompactProgressFromSnapshot()) {
            StopCompactProgressRenderLoop();
        }
    } catch (...) {
        StopCompactProgressRenderLoop();
    }
}

void StartCompactProgressRenderLoop() {
    if (!g_compactProgress || g_compactProgressRenderingHooked || g_expanded ||
        g_unloading) {
        return;
    }
    g_lastCompactProgressFrameTime = {};
    g_compactProgressRenderingToken =
        mediax::CompositionTarget::Rendering(OnCompactProgressRendering);
    g_compactProgressRenderingHooked = true;
}

double CompactPlaybackIndicatorHeight() {
    return Clamp(g_layout.playbackIndicatorHeight, 10.0, 24.0);
}

winrt::Windows::UI::Color CompactPlaybackReadableAccent(
    winrt::Windows::UI::Color color) {
    double h = 0.0;
    double s = 0.0;
    double v = 0.0;
    ColorToHsv(color, h, s, v);
    bool dark = IsDarkModeApprox();

    // Keep the hue from the currently playing cover. Only tune saturation and
    // luminance enough to remain crisp on the compact island surface.
    if (s < 0.14) {
        s = Clamp(s * 1.10, 0.04, 0.18);
    } else if (dark) {
        s = Clamp(s * 1.07 + 0.02, 0.40, 0.84);
    } else {
        s = Clamp(s * 1.05 + 0.02, 0.44, 0.82);
    }
    v = dark ? Clamp(v + 0.10, 0.74, 0.96) : Clamp(v - 0.03, 0.50, 0.78);
    return ColorFromHsv(h, s, v);
}

void ApplyCompactPlaybackAccentColor(winrt::Windows::UI::Color color) {
    g_compactPlaybackAccentDisplayed = color;
    if (g_compactPlaybackAccentBrush) {
        g_compactPlaybackAccentBrush.Color(color);
    }
    // The cover arc toggle shares the equalizer accent, including its animated
    // accent transitions.
    if (g_compactArcAccentBrush) {
        g_compactArcAccentBrush.Color(color);
    }
    if (g_popupXamlPlaybackAccentBrush) {
        g_popupXamlPlaybackAccentBrush.Color(color);
    }
}

bool TickCompactPlaybackAccentTransition(
    std::chrono::steady_clock::time_point now) {
    if (!g_compactPlaybackAccentTransitionActive) {
        return false;
    }

    double elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                           now - g_compactPlaybackAccentTransitionStart)
                           .count();
    double progress = Clamp(elapsedMs / 420.0, 0.0, 1.0);
    double eased = SmootherStep(progress);
    ApplyCompactPlaybackAccentColor(LerpColor(
        g_compactPlaybackAccentFrom, g_compactPlaybackAccentTo, eased));
    if (progress >= 1.0) {
        g_compactPlaybackAccentTransitionActive = false;
        ApplyCompactPlaybackAccentColor(g_compactPlaybackAccentTo);
    }
    return g_compactPlaybackAccentTransitionActive;
}

void ApplyCompactPlaybackStaticFrame() {
    if (!g_compactPlaybackIndicator || g_compactPlaybackBars.size() != 5) {
        return;
    }

    constexpr double kPausedFractions[5] = {0.27, 0.43, 0.60, 0.43, 0.27};
    double height = CompactPlaybackIndicatorHeight();
    for (size_t i = 0; i < g_compactPlaybackBars.size(); ++i) {
        double barHeight = std::max(2.0, height * kPausedFractions[i]);
        g_compactPlaybackBarHeights[i] = barHeight;
        g_compactPlaybackBars[i].Height(barHeight);
    }
    g_compactPlaybackIndicator.Opacity(1.0);
}

void StopCompactPlaybackIndicatorRenderLoop() {
    if (!g_compactPlaybackRenderingHooked) {
        return;
    }
    try {
        mediax::CompositionTarget::Rendering(g_compactPlaybackRenderingToken);
    } catch (...) {
    }
    g_compactPlaybackRenderingHooked = false;
    g_lastCompactPlaybackFrameTime = {};
}

void OnCompactPlaybackIndicatorRendering(
    winrt::Windows::Foundation::IInspectable const&,
    winrt::Windows::Foundation::IInspectable const&) {
    try {
        if (!g_playerGrid || !g_compactPlaybackIndicator ||
            g_compactPlaybackBars.size() != 5 || g_expanded || g_unloading) {
            StopCompactPlaybackIndicatorRenderLoop();
            return;
        }

        auto now = std::chrono::steady_clock::now();
        if (g_lastCompactPlaybackFrameTime.time_since_epoch().count() != 0 &&
            now - g_lastCompactPlaybackFrameTime <
                std::chrono::milliseconds(16)) {
            return;
        }
        g_lastCompactPlaybackFrameTime = now;

        double indicatorHeight = CompactPlaybackIndicatorHeight();
        double maxDelta = 0.0;
        bool accentTransitionActive = TickCompactPlaybackAccentTransition(now);
        if (g_compactPlaybackDesiredPlaying) {
            double elapsed = std::chrono::duration<double>(
                                 now - g_compactPlaybackAnimationStart)
                                 .count();
            constexpr double kPhases[5] = {0.10, 1.22, 2.46, 3.72, 4.86};
            constexpr double kSpeeds[5] = {0.94, 1.08, 0.89, 1.13, 0.98};
            double minHeight =
                std::max(g_layout.playbackBarWidth, indicatorHeight * 0.18);
            double heightRange = indicatorHeight * 0.88 - minHeight;

            for (size_t i = 0; i < g_compactPlaybackBars.size(); ++i) {
                // Two blended waves give each pill fluid, non-repeating motion
                // without the visual jitter of random heights.
                double primary =
                    0.5 +
                    0.5 * std::sin(elapsed * 6.2 * kSpeeds[i] + kPhases[i]);
                double secondary =
                    0.5 + 0.5 * std::sin(elapsed * 10.4 +
                                         kPhases[(i + 1) % 4] * 0.83);
                double level = SmootherStep(
                    Clamp(primary * 0.70 + secondary * 0.30, 0.0, 1.0));
                double target = minHeight + heightRange * level;
                double current = g_compactPlaybackBarHeights[i];
                current += (target - current) * 0.30;
                g_compactPlaybackBarHeights[i] = current;
                g_compactPlaybackBars[i].Height(current);
            }
            g_compactPlaybackIndicator.Opacity(1.0);
            return;
        }

        constexpr double kPausedFractions[5] = {0.27, 0.43, 0.60, 0.43, 0.27};
        for (size_t i = 0; i < g_compactPlaybackBars.size(); ++i) {
            double target =
                std::max(2.0, indicatorHeight * kPausedFractions[i]);
            double current = g_compactPlaybackBarHeights[i];
            double delta = target - current;
            current += delta * 0.34;
            maxDelta = std::max(maxDelta, std::abs(delta));
            g_compactPlaybackBarHeights[i] = current;
            g_compactPlaybackBars[i].Height(current);
        }
        g_compactPlaybackIndicator.Opacity(1.0);

        auto settlingFor = now - g_compactPlaybackStateChangedAt;
        if (!accentTransitionActive &&
            (maxDelta < 0.08 ||
             settlingFor >= std::chrono::milliseconds(360))) {
            ApplyCompactPlaybackStaticFrame();
            StopCompactPlaybackIndicatorRenderLoop();
        }
    } catch (...) {
        StopCompactPlaybackIndicatorRenderLoop();
    }
}

void StartCompactPlaybackIndicatorRenderLoop() {
    if (!g_compactPlaybackIndicator || g_compactPlaybackBars.size() != 5 ||
        g_compactPlaybackRenderingHooked || g_expanded || g_unloading) {
        return;
    }
    g_lastCompactPlaybackFrameTime = {};
    g_compactPlaybackRenderingToken = mediax::CompositionTarget::Rendering(
        OnCompactPlaybackIndicatorRendering);
    g_compactPlaybackRenderingHooked = true;
}

void UpdateCompactPlaybackIndicatorAccent(
    std::vector<uint8_t> const& artworkBytes,
    bool immediate) {
    winrt::Windows::UI::Color customAccent;
    bool customMode = CustomAccentColor(customAccent);

    // A custom accent has its own synthetic key so switching the colour (or
    // switching back to artwork mode) retriggers the transition even when the
    // playing artwork did not change.
    uint64_t artworkHash =
        customMode ? (0xA11CE00000000000ULL |
                      (static_cast<uint64_t>(customAccent.A) << 24) |
                      (static_cast<uint64_t>(customAccent.R) << 16) |
                      (static_cast<uint64_t>(customAccent.G) << 8) |
                      static_cast<uint64_t>(customAccent.B))
                   : ThumbnailHash(artworkBytes);
    if (IsDarkModeApprox()) {
        artworkHash ^= 0x9E3779B97F4A7C15ULL;
    }
    if (artworkHash == g_compactPlaybackAccentThumbnailHash) {
        return;
    }

    // Custom accents are used verbatim; the readability tuning is only meant
    // for artwork-derived colours, which can be muted or too dark.
    auto nextColor =
        customMode
            ? customAccent
            : CompactPlaybackReadableAccent(
                  artworkBytes.empty() ? DefaultPopupAccentColor()
                                       : ExtractAlbumAccentColor(artworkBytes));
    bool firstColor = g_compactPlaybackAccentThumbnailHash == UINT64_MAX;
    g_compactPlaybackAccentThumbnailHash = artworkHash;

    if (firstColor || immediate) {
        g_compactPlaybackAccentFrom = nextColor;
        g_compactPlaybackAccentTo = nextColor;
        g_compactPlaybackAccentTransitionActive = false;
        ApplyCompactPlaybackAccentColor(nextColor);
        return;
    }

    g_compactPlaybackAccentFrom = g_compactPlaybackAccentDisplayed;
    g_compactPlaybackAccentTo = nextColor;
    g_compactPlaybackAccentTransitionStart = std::chrono::steady_clock::now();
    g_compactPlaybackAccentTransitionActive = true;
    StartCompactPlaybackIndicatorRenderLoop();
}

void SetCompactPlaybackIndicatorState(bool playing) {
    auto now = std::chrono::steady_clock::now();
    bool changed = playing != g_compactPlaybackDesiredPlaying;
    g_compactPlaybackDesiredPlaying = playing;
    if (changed) {
        g_compactPlaybackStateChangedAt = now;
        if (playing) {
            g_compactPlaybackAnimationStart = now;
        }
    }

    if (!g_compactPlaybackIndicator || g_compactPlaybackBars.size() != 5) {
        return;
    }

    if (playing) {
        if (g_compactPlaybackAnimationStart.time_since_epoch().count() == 0) {
            g_compactPlaybackAnimationStart = now;
        }
        StartCompactPlaybackIndicatorRenderLoop();
    } else if (changed || g_compactPlaybackRenderingHooked) {
        StartCompactPlaybackIndicatorRenderLoop();
    } else {
        ApplyCompactPlaybackStaticFrame();
    }
}

void SetCompactTextEdgeFadeOpacity(double opacity) {
    opacity = Clamp(opacity, 0.0, 1.0);
    try {
        if (g_compactTextLeftFade) {
            g_compactTextLeftFade.Opacity(opacity);
        }
        if (g_compactTextRightFade) {
            g_compactTextRightFade.Opacity(opacity);
        }
    } catch (...) {
    }
}

void ResetCompactTextAnimationVisuals() {
    try {
        if (g_compactTitleTranslate) {
            g_compactTitleTranslate.X(0.0);
        }
        if (g_compactArtistTranslate) {
            g_compactArtistTranslate.X(0.0);
        }
        if (g_compactOutgoingTitleTranslate) {
            g_compactOutgoingTitleTranslate.X(0.0);
        }
        if (g_compactOutgoingArtistTranslate) {
            g_compactOutgoingArtistTranslate.X(0.0);
        }
        if (g_compactTitleText) {
            g_compactTitleText.Opacity(1.0);
        }
        if (g_compactArtistText) {
            g_compactArtistText.Opacity(1.0);
        }
        if (g_compactOutgoingTitleText) {
            g_compactOutgoingTitleText.Opacity(0.0);
        }
        if (g_compactOutgoingArtistText) {
            g_compactOutgoingArtistText.Opacity(0.0);
        }
        if (g_compactAlbumArtImage) {
            g_compactAlbumArtImage.Opacity(1.0);
        }
        if (g_compactAlbumArtFade) {
            g_compactAlbumArtFade.Opacity(0.0);
            g_compactAlbumArtFade.Source(nullptr);
        }
        g_compactTextEdgeFadeActive = false;
        SetCompactTextEdgeFadeOpacity(0.0);
    } catch (...) {
    }
}

double CompactTextClipWidthFallback() {
    // The content row starts at artInset on the left and the right content
    // margin on the right; subtract the circle column, the text margins and a
    // small allowance for the auto-sized playback indicator column. The arc
    // toggle is drawn inside the cover lane, so it adds no column here.
    double width =
        g_layout.compactWidth -
        (g_layout.artInset + g_layout.contentMarginX + g_layout.artColumnWidth +
         g_layout.textMarginX + 4.0 + g_layout.textRightMargin);
    return std::max(1.0, width);
}

double CompactTextClipHeightFallback() {
    double height = g_layout.compactHeight - g_layout.contentMarginY * 2.0;
    return std::max(1.0, height);
}

double CompactTextClipPadding() {
    return Clamp(g_layout.textMarginX * 0.75 + 2.0, 5.0, 9.0);
}

double CompactTextEdgeFadeWidth() {
    return Clamp(g_layout.textRightMargin + 9.0, 12.0, 18.0);
}

void RefreshCompactTextHostClip(bool forceLayout = false) {
    if (!g_compactTextHost) {
        return;
    }

    try {
        if (forceLayout && g_playerGrid) {
            g_playerGrid.UpdateLayout();
        }

        double fallbackWidth = CompactTextClipWidthFallback();
        double fallbackHeight = CompactTextClipHeightFallback();
        double clipWidth = g_compactTextHost.ActualWidth();
        double clipHeight = g_compactTextHost.ActualHeight();

        // Right after a settings/theme change, XAML may report the previous
        // measured width for one frame. A too-small clip causes the compact
        // title/artist to look cropped until the next expand/collapse. Prefer a
        // geometry-derived fallback whenever ActualWidth is clearly stale.
        if (clipWidth <= 1.0 || clipWidth < fallbackWidth * 0.65) {
            clipWidth = fallbackWidth;
        }
        if (clipHeight <= 1.0 || clipHeight < fallbackHeight * 0.55) {
            clipHeight = fallbackHeight;
        }

        double clipPadding = CompactTextClipPadding();
        ApplyElementClipWithPadding(g_compactTextHost, clipWidth, clipHeight,
                                    clipPadding);

        double fadeWidth = CompactTextEdgeFadeWidth() + clipPadding;
        auto configureFade = [&](Border const& fade, bool leftEdge) {
            if (!fade) {
                return;
            }
            double leftCoverOffset =
                leftEdge ? Clamp(g_layout.textMarginX + 4.0, 8.0, 16.0) : 0.0;
            fade.Width(fadeWidth + leftCoverOffset);
            fade.Height(clipHeight);
            fade.Margin(
                leftEdge
                    ? xaml::Thickness{-(clipPadding + leftCoverOffset), 0, 0, 0}
                    : xaml::Thickness{0, 0, -clipPadding, 0});
            fade.Background(CompactTextEdgeFadeBrush(leftEdge));
        };
        configureFade(g_compactTextLeftFade, true);
        configureFade(g_compactTextRightFade, false);
    } catch (...) {
    }
}

void StopCompactTextRenderLoop() {
    if (!g_compactTextRenderingHooked) {
        return;
    }
    try {
        mediax::CompositionTarget::Rendering(g_compactTextRenderingToken);
    } catch (...) {
    }
    g_compactTextRenderingHooked = false;
    g_lastCompactTextFrameTime = {};
}

void OnCompactTextRendering(winrt::Windows::Foundation::IInspectable const&,
                            winrt::Windows::Foundation::IInspectable const&) {
    try {
        if (!g_playerGrid || !g_compactTitleTranslate ||
            !g_compactArtistTranslate || !g_compactTitleText ||
            !g_compactArtistText || g_unloading) {
            StopCompactTextRenderLoop();
            ResetCompactTextAnimationVisuals();
            return;
        }

        auto now = std::chrono::steady_clock::now();
        double dtSec = 1.0 / 60.0;
        if (g_lastCompactTextFrameTime.time_since_epoch().count() != 0) {
            dtSec = std::chrono::duration_cast<std::chrono::microseconds>(
                        now - g_lastCompactTextFrameTime)
                        .count() /
                    1000000.0;
        }
        g_lastCompactTextFrameTime = now;
        dtSec = Clamp(dtSec, 0.0, 0.05);

        // Keep the transition perceptible without making a track change look
        // late after the new metadata and cover have already arrived.
        g_compactTextProgress =
            Clamp(g_compactTextProgress + dtSec * 8.0, 0.0, 1.0);
        constexpr double kTextSlideOffset = 21.0;
        RefreshCompactTextHostClip(false);

        double titleIn = PopupTextMotionEase(
            Clamp((g_compactTextProgress - 0.02) / 0.92, 0.0, 1.0));
        double artistIn = PopupTextMotionEase(
            Clamp((g_compactTextProgress - 0.28) / 0.70, 0.0, 1.0));
        double titleOut = PopupTextMotionEase(
            Clamp((g_compactTextProgress + 0.02) / 0.84, 0.0, 1.0));
        double artistOut = PopupTextMotionEase(
            Clamp((g_compactTextProgress - 0.12) / 0.80, 0.0, 1.0));
        double artIn =
            PopupTextMotionEase(Clamp(g_compactTextProgress / 0.96, 0.0, 1.0));
        if (g_compactTextEdgeFadeActive) {
            double edgeFadeIn = PopupTextMotionEase(
                Clamp((g_compactTextProgress - 0.08) / 0.20, 0.0, 1.0));
            double edgeFadeOut =
                1.0 - PopupTextMotionEase(Clamp(
                          (g_compactTextProgress - 0.78) / 0.18, 0.0, 1.0));
            SetCompactTextEdgeFadeOpacity(edgeFadeIn * edgeFadeOut);
        }

        // An artwork-only refresh shares this render loop, but it must never
        // move or fade the title/artist. Otherwise frequently refreshed browser
        // thumbnails keep translating the text through its clip and expose the
        // outgoing TextBlock's ellipsis even though the full title fits.
        if (g_compactTextEdgeFadeActive) {
            // Reversed direction: new compact text now enters from the right.
            g_compactTitleTranslate.X(kTextSlideOffset * (1.0 - titleIn));
            g_compactArtistTranslate.X(kTextSlideOffset * (1.0 - artistIn));
            g_compactTitleText.Opacity(titleIn);
            g_compactArtistText.Opacity(artistIn);

            if (g_compactOutgoingTitleText && g_compactOutgoingTitleTranslate) {
                // Old compact text exits to the left.
                g_compactOutgoingTitleTranslate.X(-kTextSlideOffset * titleOut);
                g_compactOutgoingTitleText.Opacity(1.0 - titleOut);
            }
            if (g_compactOutgoingArtistText &&
                g_compactOutgoingArtistTranslate) {
                g_compactOutgoingArtistTranslate.X(-kTextSlideOffset *
                                                   artistOut);
                g_compactOutgoingArtistText.Opacity(1.0 - artistOut);
            }
        }
        if (g_compactAlbumArtImage) {
            g_compactAlbumArtImage.Opacity(artIn);
        }
        if (g_compactAlbumArtFade) {
            g_compactAlbumArtFade.Opacity(1.0 - artIn);
        }

        if (g_compactTextProgress >= 1.0) {
            ResetCompactTextAnimationVisuals();
            StopCompactTextRenderLoop();
        }
    } catch (...) {
        ResetCompactTextAnimationVisuals();
        StopCompactTextRenderLoop();
    }
}

void StartCompactTrackTransition(std::wstring const& oldTitle,
                                 std::wstring const& oldArtist,
                                 bool animateText,
                                 bool animateArt) {
    if (!g_playerGrid || g_expanded || g_unloading) {
        ResetCompactTextAnimationVisuals();
        return;
    }
    if (!g_compactTitleTranslate || !g_compactArtistTranslate ||
        !g_compactTitleText || !g_compactArtistText) {
        return;
    }

    constexpr double kTextSlideOffset = 22.0;
    g_compactTextProgress = 0.0;
    g_lastCompactTextFrameTime = std::chrono::steady_clock::now();

    if (animateText) {
        if (g_compactOutgoingTitleText) {
            g_compactOutgoingTitleText.Text(winrt::hstring(oldTitle));
            g_compactOutgoingTitleText.Opacity(1.0);
        }
        if (g_compactOutgoingArtistText) {
            g_compactOutgoingArtistText.Text(winrt::hstring(oldArtist));
            g_compactOutgoingArtistText.Opacity(1.0);
        }
        if (g_compactOutgoingTitleTranslate) {
            g_compactOutgoingTitleTranslate.X(0.0);
        }
        if (g_compactOutgoingArtistTranslate) {
            g_compactOutgoingArtistTranslate.X(0.0);
        }
        // Reversed direction: new compact text starts on the right.
        g_compactTitleTranslate.X(kTextSlideOffset);
        g_compactArtistTranslate.X(kTextSlideOffset);
        g_compactTitleText.Opacity(0.0);
        g_compactArtistText.Opacity(0.0);
        g_compactTextEdgeFadeActive = true;
        SetCompactTextEdgeFadeOpacity(0.0);
    } else {
        if (g_compactTitleTranslate)
            g_compactTitleTranslate.X(0.0);
        if (g_compactArtistTranslate)
            g_compactArtistTranslate.X(0.0);
        if (g_compactTitleText)
            g_compactTitleText.Opacity(1.0);
        if (g_compactArtistText)
            g_compactArtistText.Opacity(1.0);
        if (g_compactOutgoingTitleText)
            g_compactOutgoingTitleText.Opacity(0.0);
        if (g_compactOutgoingArtistText)
            g_compactOutgoingArtistText.Opacity(0.0);
        g_compactTextEdgeFadeActive = false;
        SetCompactTextEdgeFadeOpacity(0.0);
    }

    if (animateArt) {
        if (g_compactAlbumArtImage) {
            g_compactAlbumArtImage.Opacity(0.0);
        }
        if (g_compactAlbumArtFade) {
            g_compactAlbumArtFade.Opacity(
                g_compactAlbumArtFade.Source() != nullptr ? 1.0 : 0.0);
        }
    } else {
        if (g_compactAlbumArtImage)
            g_compactAlbumArtImage.Opacity(1.0);
        if (g_compactAlbumArtFade)
            g_compactAlbumArtFade.Opacity(0.0);
    }

    if (!g_compactTextRenderingHooked) {
        g_compactTextRenderingToken =
            mediax::CompositionTarget::Rendering(OnCompactTextRendering);
        g_compactTextRenderingHooked = true;
    }
}

void SetCompactIslandSuppressed(bool suppressed);
void StartPopupXamlRenderLoop();
void StopHoverRenderLoop();
void ApplyExpandedState();

// ===== Compact cover vinyl spin =====
// The arc toggle starts and stops a slow rotation of the compact album art.
// Only RenderTransform is animated, so layout never re-runs: the circular clip
// host stays fixed and the clipped image plus its cross-fade rotate under it.
void ApplyCompactCoverSpinAngle() {
    try {
        if (g_compactArtSpinImage) {
            g_compactArtSpinImage.Angle(g_compactArtSpinAngle);
        }
        if (g_compactArtSpinFade) {
            g_compactArtSpinFade.Angle(g_compactArtSpinAngle);
        }
    } catch (...) {
    }
}

void StopCompactCoverSpinLoop() {
    if (!g_compactArtSpinRenderingHooked) {
        return;
    }
    try {
        mediax::CompositionTarget::Rendering(g_compactArtSpinRenderingToken);
    } catch (...) {
    }
    g_compactArtSpinRenderingHooked = false;
    g_lastCompactArtSpinFrameTime = {};
}

void OnCompactCoverSpinRendering(
    winrt::Windows::Foundation::IInspectable const&,
    winrt::Windows::Foundation::IInspectable const&) {
    try {
        // Mirror the other compact loops: the island can be torn down, hidden
        // behind the expanded popup or unloaded while the spin is running.
        if (!g_playerGrid || !g_compactArtSpinImage || !g_compactArtSpinFade ||
            g_expanded || g_unloading) {
            StopCompactCoverSpinLoop();
            return;
        }

        auto now = std::chrono::steady_clock::now();
        double dtSec = 1.0 / 60.0;
        if (g_lastCompactArtSpinFrameTime.time_since_epoch().count() != 0) {
            dtSec = std::chrono::duration_cast<std::chrono::microseconds>(
                        now - g_lastCompactArtSpinFrameTime)
                        .count() /
                    1000000.0;
        }
        g_lastCompactArtSpinFrameTime = now;
        dtSec = Clamp(dtSec, 0.0, 0.1);

        // Slow vinyl speed: ~33 deg/s is about 11 s per revolution, and the
        // dt term keeps it frame-rate independent.
        g_compactArtSpinAngle += dtSec * 33.0;
        while (g_compactArtSpinAngle >= 360.0) {
            g_compactArtSpinAngle -= 360.0;
        }
        ApplyCompactCoverSpinAngle();
    } catch (...) {
        StopCompactCoverSpinLoop();
    }
}

void StartCompactCoverSpinLoop() {
    if (!g_compactArtSpinImage || !g_compactArtSpinFade ||
        g_compactArtSpinRenderingHooked || g_expanded || g_unloading) {
        return;
    }
    g_lastCompactArtSpinFrameTime = {};
    g_compactArtSpinRenderingToken =
        mediax::CompositionTarget::Rendering(OnCompactCoverSpinRendering);
    g_compactArtSpinRenderingHooked = true;
}

void ToggleCompactCoverSpin() {
    g_compactArtSpinEnabled = !g_compactArtSpinEnabled;
    if (g_compactArtSpinEnabled) {
        StartCompactCoverSpinLoop();
    } else {
        StopCompactCoverSpinLoop();
    }
    // Freeze the cover at its current angle when stopping; the next toggle
    // resumes from exactly that phase.
    ApplyCompactCoverSpinAngle();
}

// Double-tapping the arc ring stops the spin and snaps the artwork back to its
// original upright orientation. The angle is zeroed in the same step so the
// next single-tap toggle restarts from 0 degrees.
void ResetCompactCoverSpin() {
    g_compactArtSpinEnabled = false;
    StopCompactCoverSpinLoop();
    g_compactArtSpinAngle = 0.0;
    ApplyCompactCoverSpinAngle();
}

// ===== Popup progress, seek and close state machine =====
bool IsAnimatedTaskbarPopupVisible() {
    return g_expandedPopup && IsWindowVisible(g_expandedPopup);
}
void UpdatePlayerContents();

void SetPopupProgressVisualRatio(double ratio) {
    ratio = Clamp(ratio, 0.0, 1.0);
    if (g_popupXamlProgress) {
        g_popupLiveProgressValue = ratio * g_popupXamlProgress.Maximum();
        g_popupXamlProgress.Value(g_popupLiveProgressValue);
    }

    // The visible progress bar is a custom Border. The hidden ProgressBar is
    // only the numeric model used during layout. Once the morph animation had
    // settled, layout stopped running and only the hidden model was updated,
    // leaving this visible fill frozen. Drive both from the same ratio.
    if (g_popupXamlProgressTrack && g_popupXamlProgressFill) {
        double width = g_popupXamlProgressTrack.ActualWidth();
        if (width <= 0.0) {
            width = g_popupXamlProgressTrack.Width();
        }
        double fillWidth = std::max(0.0, width * ratio);
        g_popupXamlProgressFill.Width(fillWidth);
        bool trackVisible =
            g_popupXamlProgressTrack.Visibility() == Visibility::Visible;
        g_popupXamlProgressFill.Visibility(trackVisible && fillWidth > 0.5
                                               ? Visibility::Visible
                                               : Visibility::Collapsed);
    }
}

void ResetMediaProgressUiForTrackNavigation() {
    auto now = std::chrono::steady_clock::now();
    std::wstring oldTrackKey;
    {
        std::lock_guard lock(g_mediaMutex);
        if (g_media.hasSession) {
            oldTrackKey = MediaTrackKey(g_media);
            g_media.positionTicks = 0;
            g_mediaStateTimestamp = now;
        }
    }
    {
        std::lock_guard seekLock(g_seekMutex);
        g_mediaNavigationHoldZero = true;
        g_mediaNavigationOldTrackKey = std::move(oldTrackKey);
        g_mediaNavigationHoldUntil = now + std::chrono::seconds(4);
    }
    g_mediaProgressResetKey.clear();
    g_mediaProgressResetStarted = now;
    g_mediaProgressResetUntil = now + std::chrono::milliseconds(1500);
    g_popupLiveProgressKey.clear();
    g_popupLiveProgressValid = false;
    SetPopupProgressVisualRatio(0.0);
    if (g_popupXamlElapsed) {
        g_popupXamlElapsed.Text(L"0:00");
    }
    if (g_popupXamlDuration) {
        g_popupXamlDuration.Text(L"0:00");
    }
    if (g_compactProgress) {
        g_compactProgress.Value(0.0);
    }
}

void UpdatePopupSeekPreview(double ratio) {
    MediaState state = SnapshotMedia();
    if (!state.hasSession || state.durationTicks <= 0 || !g_popupXamlProgress) {
        g_popupSeekDragging = false;
        return;
    }

    ratio = Clamp(ratio, 0.0, 1.0);
    g_popupSeekDragging = true;
    g_popupSeekPreviewRatio = ratio;
    SetPopupProgressVisualRatio(ratio);

    int64_t previewTicks = static_cast<int64_t>(
        std::llround(static_cast<double>(state.durationTicks) * ratio));
    if (g_popupXamlElapsed) {
        g_popupXamlElapsed.Text(FormatMediaTime(previewTicks));
    }
    if (g_popupXamlDuration) {
        g_popupXamlDuration.Text(FormatMediaTime(state.durationTicks));
    }
}

void UpdatePopupLiveProgressFromSnapshot() {
    if (!g_popupXamlProgress) {
        return;
    }

    auto now = std::chrono::steady_clock::now();
    g_popupLiveProgressFrameTime = now;

    std::chrono::steady_clock::time_point timestamp;
    MediaState state = SnapshotMediaWithTimestamp(timestamp);
    if (!state.hasSession || state.durationTicks <= 0) {
        g_popupSeekDragging = false;
        g_popupSeekPreviewUntil = {};
        {
            std::lock_guard seekLock(g_seekMutex);
            g_popupSeekCommitPending = false;
            g_popupSeekCommitTargetTicks = 0;
            g_popupSeekCommitUntil = {};
        }
        g_popupLiveProgressValue = 0.0;
        g_popupLiveProgressValid = false;
        g_popupLiveProgressKey.clear();
        SetPopupProgressVisualRatio(0.0);
        if (g_popupXamlElapsed) {
            g_popupXamlElapsed.Text(L"0:00");
        }
        return;
    }

    std::wstring key =
        MediaTrackKey(state) + L"\n" + std::to_wstring(state.durationTicks);

    // After Previous/Next, ignore every refresh carrying the old track key.
    // NetEase can keep publishing the completed song for several polling
    // cycles; allowing one of those samples through restored its elapsed time
    // label even though the visible fill had already been reset.
    {
        std::lock_guard seekLock(g_seekMutex);
        if (g_mediaNavigationHoldZero) {
            std::wstring currentTrackKey = MediaTrackKey(state);
            bool newTrackArrived =
                !g_mediaNavigationOldTrackKey.empty() &&
                currentTrackKey != g_mediaNavigationOldTrackKey;
            if (newTrackArrived || now >= g_mediaNavigationHoldUntil) {
                g_mediaNavigationHoldZero = false;
                g_mediaNavigationOldTrackKey.clear();
                g_mediaNavigationHoldUntil = {};
            } else {
                SetPopupProgressVisualRatio(0.0);
                if (g_popupXamlElapsed) {
                    g_popupXamlElapsed.Text(L"0:00");
                }
                if (g_popupXamlDuration) {
                    g_popupXamlDuration.Text(L"0:00");
                }
                return;
            }
        }
    }
    bool trackChanged =
        !g_popupLiveProgressValid || key != g_popupLiveProgressKey;
    if (trackChanged) {
        g_popupSeekDragging = false;
        g_popupSeekPreviewUntil = {};
        {
            std::lock_guard seekLock(g_seekMutex);
            g_popupSeekCommitPending = false;
            g_popupSeekCommitTargetTicks = 0;
            g_popupSeekCommitUntil = {};
        }
        g_popupLiveProgressKey = key;
        g_popupLiveProgressValid = true;
        SetPopupProgressVisualRatio(0.0);
        if (g_popupXamlElapsed) {
            g_popupXamlElapsed.Text(L"0:00");
        }
        if (g_popupXamlDuration) {
            g_popupXamlDuration.Text(FormatMediaTime(state.durationTicks));
        }
        return;
    }

    if (ShouldForceMediaProgressToZero(state, now)) {
        SetPopupProgressVisualRatio(0.0);
        if (g_popupXamlElapsed) {
            g_popupXamlElapsed.Text(L"0:00");
        }
        if (g_popupXamlDuration) {
            g_popupXamlDuration.Text(FormatMediaTime(state.durationTicks));
        }
        return;
    }

    {
        std::lock_guard seekLock(g_seekMutex);
        if (g_popupSeekCommitPending) {
            if (now < g_popupSeekCommitUntil) {
                int64_t targetTicks = std::clamp<int64_t>(
                    g_popupSeekCommitTargetTicks, 0, state.durationTicks);
                g_popupLiveProgressValue =
                    Clamp(static_cast<double>(targetTicks) /
                              static_cast<double>(state.durationTicks) * 1000.0,
                          0.0, 1000.0);
                SetPopupProgressVisualRatio(
                    static_cast<double>(targetTicks) /
                    static_cast<double>(state.durationTicks));
                if (g_popupXamlElapsed) {
                    g_popupXamlElapsed.Text(FormatMediaTime(targetTicks));
                }
                if (g_popupXamlDuration) {
                    g_popupXamlDuration.Text(
                        FormatMediaTime(state.durationTicks));
                }
                return;
            }
            g_popupSeekCommitPending = false;
            g_popupSeekCommitTargetTicks = 0;
        }
    }

    if (g_popupSeekDragging || now < g_popupSeekPreviewUntil) {
        return;
    }

    int64_t livePositionTicks = state.positionTicks;
    if (state.isPlaying && timestamp.time_since_epoch().count() != 0) {
        double ageSec = std::chrono::duration_cast<std::chrono::milliseconds>(
                            now - timestamp)
                            .count() /
                        1000.0;
        // Keep progress moving between event-driven timeline updates. The media
        // worker performs a 30-second fallback refresh if a provider goes quiet.
        ageSec = Clamp(ageSec, 0.0, 30.0);
        livePositionTicks += static_cast<int64_t>(ageSec * 10000000.0);
    }

    livePositionTicks =
        std::clamp<int64_t>(livePositionTicks, 0, state.durationTicks);
    g_popupLiveProgressValue =
        Clamp(static_cast<double>(livePositionTicks) /
                  static_cast<double>(state.durationTicks) * 1000.0,
              0.0, 1000.0);

    SetPopupProgressVisualRatio(static_cast<double>(livePositionTicks) /
                                static_cast<double>(state.durationTicks));
    if (g_popupXamlElapsed) {
        g_popupXamlElapsed.Text(FormatMediaTime(livePositionTicks));
    }
    if (g_popupXamlDuration) {
        g_popupXamlDuration.Text(FormatMediaTime(state.durationTicks));
    }
}

void EndPopupSeek(bool commit) {
    if (!g_popupSeekDragging) {
        return;
    }

    double ratio = g_popupSeekPreviewRatio;
    g_popupSeekDragging = false;
    if (commit) {
        auto now = std::chrono::steady_clock::now();
        MediaState state = SnapshotMedia();
        int64_t targetTicks =
            state.durationTicks > 0
                ? static_cast<int64_t>(
                      std::llround(static_cast<double>(state.durationTicks) *
                                   Clamp(ratio, 0.0, 1.0)))
                : 0;
        g_popupSeekPreviewUntil = now + std::chrono::milliseconds(2600);
        double commitRatio = Clamp(ratio, 0.0, 1.0);
        {
            std::lock_guard seekLock(g_seekMutex);
            g_popupSeekCommitPending = true;
            g_popupSeekCommitRatio = commitRatio;
            g_popupSeekCommitTargetTicks = targetTicks;
            g_popupSeekCommitUntil = g_popupSeekPreviewUntil;
        }
        {
            std::lock_guard lock(g_mediaMutex);
            if (g_media.hasSession && g_media.durationTicks > 0) {
                g_media.positionTicks =
                    std::clamp<int64_t>(targetTicks, 0, g_media.durationTicks);
                g_mediaStateTimestamp = now;
            }
        }

        // Queue the provider seek before touching XAML. UI elements can become
        // temporarily invalid during popup relayout; that must never suppress
        // the actual playback-position change.
        SeekToMediaPosition(ratio);
        try {
            if (g_popupXamlProgress) {
                SetPopupProgressVisualRatio(commitRatio);
            }
            if (g_popupXamlElapsed && state.durationTicks > 0) {
                g_popupXamlElapsed.Text(FormatMediaTime(targetTicks));
            }
            StartPopupXamlRenderLoop();
        } catch (...) {
        }
    } else {
        g_popupSeekPreviewUntil = {};
        {
            std::lock_guard seekLock(g_seekMutex);
            g_popupSeekCommitPending = false;
            g_popupSeekCommitTargetTicks = 0;
            g_popupSeekCommitUntil = {};
        }
        UpdatePopupLiveProgressFromSnapshot();
    }
}

bool IsTaskbarCurrentlyAutoHidden();
void FinishCloseExpandedPopup(HWND hwnd);

// Popup text updates are deferred while the render loop is hooked, so the
// popup can be showing stale title/artist when a close starts. Refresh just
// the text (never the cover) so the popup's final frame matches the island.
void RefreshPopupTextOnly() {
    if (!g_popupXamlRoot || !g_popupXamlTitle || !g_popupXamlArtist) {
        return;
    }
    try {
        MediaState state = SnapshotMedia();
        winrt::hstring nextTitle = state.hasSession
                                       ? winrt::hstring(state.title)
                                       : winrt::hstring(DefaultIdleTitle());
        winrt::hstring nextArtist =
            !state.hasSession
                ? winrt::hstring(DefaultIdleArtist())
                : (state.artist.empty()
                       ? (state.isPlaying ? winrt::hstring(L"Playing")
                                          : winrt::hstring(L"Paused"))
                       : winrt::hstring(state.artist));
        g_popupXamlTitle.Text(nextTitle);
        g_popupXamlArtist.Text(nextArtist);
        if (g_popupXamlOutgoingTitle) {
            g_popupXamlOutgoingTitle.Opacity(0.0);
        }
        if (g_popupXamlOutgoingArtist) {
            g_popupXamlOutgoingArtist.Opacity(0.0);
        }
        if (g_popupXamlTitleTranslate) {
            g_popupXamlTitleTranslate.X(0.0);
        }
        if (g_popupXamlArtistTranslate) {
            g_popupXamlArtistTranslate.X(0.0);
        }
        g_popupTextTransitionActive = false;
    } catch (...) {
    }
}

void BeginCloseExpandedPopup() {
    if (g_popupRestingCompact) {
        return;
    }
    g_lastTrackedIslandRect = {};
    if (!g_expandedPopup || !IsWindowVisible(g_expandedPopup)) {
        if (g_expandedPopup) {
            ParkExpandedPopupWindow(g_expandedPopup);
        }
        g_expanded = false;
        SetCompactIslandSuppressed(false);
        return;
    }
    try {
        if (g_playerGrid) {
            ApplyExpandedState();
            g_playerGrid.UpdateLayout();
            g_playerGrid.Opacity(0.0);
            // Keep the island itself clickable through the whole close: it is
            // the reliable interrupt target at the original position even
            // when the shrinking surface no longer covers it.
            g_playerGrid.IsHitTestVisible(true);
        }
        g_popupTextTransitionActive = false;
        if (g_popupXamlOutgoingTitle)
            g_popupXamlOutgoingTitle.Opacity(0.0);
        if (g_popupXamlOutgoingArtist)
            g_popupXamlOutgoingArtist.Opacity(0.0);
    } catch (...) {
    }
    // Make the popup's closing text match the island's current text before
    // the morph starts; stale text is what flashed against the island.
    RefreshPopupTextOnly();
    // Re-target the closing animation at the island's current real geometry.
    // The rects captured at open can be a pixel stale after layout changes,
    // auto-hide transitions, or DPI re-rounding; animating to stale rects is
    // what makes the final frame visibly jump against the native island.
    CapturePopupSourceGeometry(true);
    if (g_popupXamlRoot) {
        g_popupHostRect = UnionPopupRects(g_popupSourceRect, g_popupFinalRect);
        g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
        PositionExpandedPopup();
    }
    g_popupClosing = true;
    g_popupLifecycleState = PopupLifecycleState::Closing;
    g_popupCompactFramePending = false;
    g_popupCompactFrameStartSerial = 0;
    g_popupCompactFramePendingSince = {};
    g_popupTransparentParkPending = false;
    // The host remains interactive while closing so the same click area can
    // reverse the same spring at any frame. WM_NCHITTEST still returns
    // HTTRANSPARENT everywhere outside the visible shell and source island.
    SetPopupWindowClickThrough(g_expandedPopup, false);
    SetPopupWindowClickThrough(g_popupXamlChild, false);
    g_popupOutsideClickArmed = false;
    g_popupAnimationTarget = 0.0;
    if (g_popupXamlRoot) {
        StartPopupXamlRenderLoop();
    }
}

void ClearPopupCompactWindowRegions() {
    if (g_expandedPopup) {
        SetWindowRgn(g_expandedPopup, nullptr, TRUE);
    }
    if (g_popupXamlChild) {
        SetWindowRgn(g_popupXamlChild, nullptr, TRUE);
    }
}

void ApplyPopupCompactWindowRegions() {
    if (!g_expandedPopup || IsRectEmpty(&g_popupSourceRect) ||
        IsRectEmpty(&g_popupHostRect)) {
        return;
    }
    int left = g_popupSourceRect.left - g_popupHostRect.left;
    int top = g_popupSourceRect.top - g_popupHostRect.top;
    int right = g_popupSourceRect.right - g_popupHostRect.left;
    int bottom = g_popupSourceRect.bottom - g_popupHostRect.top;
    // Reserve only the tiny hover-growth envelope. This keeps the host from
    // clipping the enlarged antialiased surface without reviving the old
    // full-screen/union transparent blocker.
    double maxScale = std::max(1.0, g_settings.hoverScale);
    int growX =
        static_cast<int>(std::ceil((right - left) * (maxScale - 1.0) * 0.5)) +
        2;
    int growY =
        static_cast<int>(std::ceil((bottom - top) * (maxScale - 1.0) * 0.5)) +
        2;
    left -= growX;
    right += growX;
    top -= growY;
    bottom += growY;
    // Only bound the otherwise union-sized host. Never use an HRGN rounded
    // corner here: GDI regions are hard pixel masks and would cut the
    // antialiased XAML rim a second time, producing broken/low-quality edges.
    HRGN hostRegion = CreateRectRgn(left, top, right + 1, bottom + 1);
    if (hostRegion && !SetWindowRgn(g_expandedPopup, hostRegion, TRUE)) {
        DeleteObject(hostRegion);
    }
    if (g_popupXamlChild) {
        HRGN childRegion = CreateRectRgn(left, top, right + 1, bottom + 1);
        if (childRegion && !SetWindowRgn(g_popupXamlChild, childRegion, TRUE)) {
            DeleteObject(childRegion);
        }
    }
}

void StopPopupPlaybackIndicatorRenderLoop() {
    if (!g_popupPlaybackRenderingHooked)
        return;
    try {
        mediax::CompositionTarget::Rendering(g_popupPlaybackRenderingToken);
    } catch (...) {
    }
    g_popupPlaybackRenderingHooked = false;
    g_lastPopupPlaybackFrameTime = {};
}

void OnPopupPlaybackIndicatorRendering(
    winrt::Windows::Foundation::IInspectable const&,
    winrt::Windows::Foundation::IInspectable const&) {
    try {
        if (!g_popupRestingCompact || !g_popupXamlPlaybackIndicator ||
            g_popupXamlPlaybackBars.size() != 5 || g_unloading) {
            StopPopupPlaybackIndicatorRenderLoop();
            return;
        }
        auto now = std::chrono::steady_clock::now();
        if (g_lastPopupPlaybackFrameTime.time_since_epoch().count() != 0 &&
            now - g_lastPopupPlaybackFrameTime <
                std::chrono::milliseconds(12)) {
            return;
        }
        g_lastPopupPlaybackFrameTime = now;
        // Once the expanded popup rests as the compact island, the native
        // compact render loop is intentionally stopped. Advance the shared
        // artwork-accent transition here so the visible popup bars follow each
        // song's cover instead of remaining stuck on the previous color.
        TickCompactPlaybackAccentTransition(now);
        if (g_popupXamlPlaybackAccentBrush) {
            g_popupXamlPlaybackAccentBrush.Color(
                g_compactPlaybackAccentDisplayed);
        }
        double height = std::max(12.0, g_layout.playbackIndicatorHeight);
        double indicatorWidth = std::max(16.0, g_layout.playbackIndicatorWidth);
        if (g_popupXamlPlaybackRevealClip) {
            // The bars already faded in during the last part of the collapse.
            // Keep the clip fully open so entering the resting loop does not
            // re-reveal them from zero (which read as a flash/refresh).
            g_popupXamlPlaybackRevealClip.Rect(
                {0.0f, 0.0f, static_cast<float>(indicatorWidth),
                 static_cast<float>(height)});
        }
        if (g_popupXamlCompactHoverScale) {
            double alpha =
                1.0 - std::exp(-g_settings.hoverLerpSpeed * (1.0 / 80.0));
            g_popupCompactHoverCurrent +=
                (g_popupCompactHoverTarget - g_popupCompactHoverCurrent) *
                Clamp(alpha, 0.0, 1.0);
            if (std::abs(g_popupCompactHoverTarget -
                         g_popupCompactHoverCurrent) < 0.0005) {
                g_popupCompactHoverCurrent = g_popupCompactHoverTarget;
            }
            g_popupXamlCompactHoverScale.ScaleX(g_popupCompactHoverCurrent);
            g_popupXamlCompactHoverScale.ScaleY(g_popupCompactHoverCurrent);
        }
        constexpr double paused[5] = {0.27, 0.43, 0.60, 0.43, 0.27};
        double elapsed =
            std::chrono::duration<double>(now - g_popupPlaybackAnimationStart)
                .count();
        constexpr double phase[5] = {0.10, 1.22, 2.46, 3.72, 4.86};
        for (size_t i = 0; i < 5; ++i) {
            double target = std::max(2.0, height * paused[i]);
            if (g_compactPlaybackDesiredPlaying) {
                double a =
                    0.5 + 0.5 * std::sin(elapsed * (5.8 + i * 0.16) + phase[i]);
                double b =
                    0.5 + 0.5 * std::sin(elapsed * 9.6 + phase[(i + 1) % 5]);
                double level =
                    SmootherStep(Clamp(a * 0.72 + b * 0.28, 0.0, 1.0));
                target = std::max(2.0, height * (0.18 + 0.70 * level));
            }
            double current = g_popupPlaybackBarHeights[i];
            current += (target - current) * 0.32;
            g_popupPlaybackBarHeights[i] = current;
            g_popupXamlPlaybackBars[i].Height(current);
        }
        // Paused means motionless, not dimmed. Keeping luminance constant
        // avoids the conspicuous bright-to-dark jump after the reveal.
        g_popupXamlPlaybackIndicator.Opacity(1.0);
    } catch (...) {
        StopPopupPlaybackIndicatorRenderLoop();
    }
}

void StartPopupPlaybackIndicatorRenderLoop() {
    if (g_popupPlaybackRenderingHooked || !g_popupRestingCompact ||
        !g_popupXamlPlaybackIndicator || g_popupXamlPlaybackBars.size() != 5) {
        return;
    }
    g_popupPlaybackAnimationStart = std::chrono::steady_clock::now();
    g_popupPlaybackRevealStart = g_popupPlaybackAnimationStart;
    g_popupCompactHoverCurrent = 1.0;
    g_popupCompactHoverTarget = 1.0;
    g_lastPopupPlaybackFrameTime = {};
    g_popupPlaybackRenderingToken =
        mediax::CompositionTarget::Rendering(OnPopupPlaybackIndicatorRendering);
    g_popupPlaybackRenderingHooked = true;
}

void ResumeOpenExpandedPopup() {
    if (!g_expandedPopup || !IsWindowVisible(g_expandedPopup) ||
        (!g_popupClosing && !g_popupRestingCompact)) {
        return;
    }

    // Reverse the same spring in place. Do not reset progress or velocity:
    // preserving both is what makes an interrupted transition continuous.
    g_popupClosing = false;
    g_popupRestingCompact = false;
    g_popupRestingHiddenWithTaskbar = false;
    g_popupRidingTaskbarUp = false;
    StopPopupPlaybackIndicatorRenderLoop();
    ClearPopupCompactWindowRegions();
    g_popupLifecycleState = PopupLifecycleState::Opening;
    g_popupCloseHandoffOpacity = 1.0;
    if (g_popupXamlRoot) {
        g_popupXamlRoot.Opacity(1.0);
    }
    g_popupCompactFramePending = false;
    g_popupCompactFrameStartSerial = 0;
    g_popupCompactFramePendingSince = {};
    g_popupTransparentParkPending = false;
    g_expanded = true;
    g_popupAnimationTarget = 1.0;
    g_popupOutsideClickArmed = false;
    SetPopupWindowClickThrough(g_expandedPopup, false);
    SetPopupWindowClickThrough(g_popupXamlChild, false);
    if (g_playerGrid) {
        try {
            // Keep the island clickable while reopening too, so rapid
            // continuous clicks at the original position keep toggling.
            g_playerGrid.IsHitTestVisible(true);
        } catch (...) {
        }
    }
    if (g_popupXamlRoot) {
        StartPopupXamlRenderLoop();
    }
    SetTimer(g_expandedPopup, kPopupTimerId, g_popupXamlRoot ? 30 : 15,
             nullptr);
}

void SetCompactIslandSuppressed(bool suppressed) {
    if (!g_playerGrid) {
        return;
    }

    if (suppressed) {
        StopCompactTextRenderLoop();
        StopCompactProgressRenderLoop();
        StopCompactPlaybackIndicatorRenderLoop();
        ResetCompactTextAnimationVisuals();
    }

    if (!suppressed) {
        StopHoverRenderLoop();
        g_currentHoverScale = 1.0;
        g_targetHoverScale = 1.0;
        if (g_islandScale) {
            g_islandScale.ScaleX(1.0);
            g_islandScale.ScaleY(1.0);
        }
        ApplyExpandedState();
        UpdatePlayerContents();
        try {
            g_playerGrid.UpdateLayout();
        } catch (...) {
        }
    }

    g_playerGrid.Opacity(suppressed ? 0.0 : 1.0);
    g_playerGrid.IsHitTestVisible(!suppressed);
}

void PrepareCompactIslandForPopupMorph() {
    if (!g_playerGrid) {
        return;
    }
    StopCompactTextRenderLoop();
    StopCompactProgressRenderLoop();
    StopCompactPlaybackIndicatorRenderLoop();
    StopCompactCoverSpinLoop();
    ResetCompactTextAnimationVisuals();
    try {
        // The taskbar-owned popup is the rendered component for the complete
        // transaction, including both endpoints. Keep only the injected grid's
        // layout and pointer anchor alive behind it.
        g_playerGrid.Opacity(0.001);
        g_playerGrid.IsHitTestVisible(true);
    } catch (...) {
    }
}

void StopPopupXamlRenderLoop() {
    if (!g_popupRenderingHooked) {
        return;
    }
    try {
        mediax::CompositionTarget::Rendering(g_popupRenderingToken);
    } catch (...) {
    }
    g_popupRenderingHooked = false;
    g_lastPopupFrameTime = {};
}

void FinishCloseExpandedPopup(HWND hwnd) {
    StopPopupXamlRenderLoop();
    StopPopupPlaybackIndicatorRenderLoop();
    ClearPopupCompactWindowRegions();
    g_expanded = false;
    try {
        StopHoverRenderLoop();
        g_currentHoverScale = 1.0;
        g_targetHoverScale = 1.0;
        if (g_islandScale) {
            g_islandScale.ScaleX(1.0);
            g_islandScale.ScaleY(1.0);
        }
        if (g_playerGrid) {
            // BeginCloseExpandedPopup already prepared and laid out the compact
            // tree before the morph started. Reapplying the complete layout at
            // the hand-off introduces a one-frame stall and occasionally a
            // visible flash, so only restore interaction here.
            g_playerGrid.Opacity(1.0);
            g_playerGrid.IsHitTestVisible(true);
            if (g_compactArtSpinEnabled) {
                StartCompactCoverSpinLoop();
            }
        }
    } catch (...) {
        Wh_Log(L"Island: failed to restore compact island after closing popup");
        try {
            if (g_playerGrid) {
                g_playerGrid.Opacity(1.0);
                g_playerGrid.IsHitTestVisible(true);
            }
        } catch (...) {
        }
    }
    HidePopupToggleHitWindow();
    if (hwnd) {
        ParkExpandedPopupWindow(hwnd);
        KillTimer(hwnd, kPopupTimerId);
    }
    HidePopupBackdropOverlayWindowVisualOnly();
    g_popupOverlayAwaitFreshFrame = false;
    g_popupAnimationProgress = 0.0;
    g_popupAnimationTarget = 0.0;
    g_popupAnimationVelocity = 0.0;
    g_lastPopupVisualProgress = -1.0;
    g_lastPopupVisualRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_popupHostRect = {};
    g_popupClosing = false;
    g_popupRestingCompact = false;
    g_popupRestingHiddenWithTaskbar = false;
    g_popupRidingTaskbarUp = false;
    g_popupLifecycleState = PopupLifecycleState::Closed;
    g_popupCloseHandoffOpacity = 1.0;
    g_lastTrackedIslandRect = {};
    if (g_popupXamlRoot) {
        g_popupXamlRoot.Opacity(1.0);
    }
    g_popupCompactFramePending = false;
    g_popupCompactFrameStartSerial = 0;
    g_popupCompactFramePendingSince = {};
    g_popupTransparentParkPending = false;
    g_popupOutsideClickArmed = false;
    g_popupLiveProgressValue = 0.0;
    g_popupLiveProgressValid = false;
    g_popupLiveProgressKey.clear();
    g_popupLiveProgressFrameTime = {};
    g_popupSeekDragging = false;
    g_popupSeekPreviewRatio = 0.0;
    g_popupSeekPreviewUntil = {};
    {
        std::lock_guard seekLock(g_seekMutex);
        g_popupSeekCommitPending = false;
        g_popupSeekCommitRatio = 0.0;
        g_popupSeekCommitTargetTicks = 0;
        g_popupSeekCommitUntil = {};
    }
}

void KeepPopupOnTop();
void AnchorIslandAboveTaskbar();

// ===== Taskbar tracking and z-order =====
void RestExpandedPopupAsCompact() {
    // The final collapsed frame is now the compact island itself. Keep every
    // object that is already on screen: same HWND, glass swap-chain, artwork,
    // text and corner clip. No second component is revealed underneath it.
    StopPopupXamlRenderLoop();
    g_popupAnimationProgress = 0.0;
    g_popupAnimationTarget = 0.0;
    g_popupAnimationVelocity = 0.0;
    g_popupClosing = false;
    g_popupRestingCompact = true;
    g_popupRestingHiddenWithTaskbar = false;
    g_popupRidingTaskbarUp = false;
    g_pendingPopupDeltaX = 0;
    g_pendingPopupDeltaY = 0;
    g_popupTransparentParkPending = false;
    g_popupOutsideClickArmed = false;
    if (g_playerGrid) {
        try {
            // Keep only the original in-taskbar hit target alive. A tiny alpha
            // keeps XAML hit testing active without drawing a second island.
            g_playerGrid.Opacity(0.001);
            g_playerGrid.IsHitTestVisible(true);
        } catch (...) {
        }
    }
    if (g_expandedPopup) {
        SetPopupWindowClickThrough(g_expandedPopup, true);
        SetPopupWindowClickThrough(g_popupXamlChild, true);
        // Keep a high-frequency binding timer in addition to composition
        // rendering so auto-hide movement is followed even while media is
        // paused and the rest of the animation loop is idle.
        SetTimer(g_expandedPopup, kPopupTimerId, 8, nullptr);
    }
    ApplyPopupCompactWindowRegions();
    StartPopupPlaybackIndicatorRenderLoop();
    // Preserve the original compact island's dedicated hit target. This is
    // the interaction model from the first interruptible build: every press
    // in the same physical region reverses the existing spring, with no state
    // reset and no dependency on where the animated surface currently is.
    ShowPopupToggleHitWindow();
    AnchorIslandAboveTaskbar();
}

bool IsTaskbarCurrentlyAutoHidden() {
    APPBARDATA data{sizeof(data)};
    UINT state = static_cast<UINT>(SHAppBarMessage(ABM_GETSTATE, &data));
    if ((state & ABS_AUTOHIDE) == 0 || !g_taskbarWnd ||
        !IsWindow(g_taskbarWnd)) {
        return false;
    }
    RECT taskbar{};
    if (!GetWindowRect(g_taskbarWnd, &taskbar))
        return false;
    HMONITOR monitor =
        MonitorFromWindow(g_taskbarWnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFO info{sizeof(info)};
    if (!GetMonitorInfoW(monitor, &info))
        return false;
    int width = taskbar.right - taskbar.left;
    int height = taskbar.bottom - taskbar.top;
    bool horizontal = width >= height;
    int visible = 0;
    if (horizontal) {
        LONG topOverlap =
            std::max<LONG>(0, std::min(taskbar.bottom, info.rcMonitor.bottom) -
                                  std::max(taskbar.top, info.rcMonitor.top));
        visible = static_cast<int>(topOverlap);
    } else {
        LONG sideOverlap =
            std::max<LONG>(0, std::min(taskbar.right, info.rcMonitor.right) -
                                  std::max(taskbar.left, info.rcMonitor.left));
        visible = static_cast<int>(sideOverlap);
    }
    return visible <= PopupDipToPx(3.0, g_taskbarWnd);
}

bool TaskbarFullyShown() {
    if (!g_taskbarWnd || !IsWindow(g_taskbarWnd)) {
        return true;
    }
    RECT taskbar{};
    if (!GetWindowRect(g_taskbarWnd, &taskbar)) {
        return true;
    }
    HMONITOR monitor = MonitorFromRect(&taskbar, MONITOR_DEFAULTTONEAREST);
    MONITORINFO monitorInfo{sizeof(monitorInfo)};
    if (!monitor || !GetMonitorInfoW(monitor, &monitorInfo)) {
        return true;
    }
    RECT intersection{};
    IntersectRect(&intersection, &taskbar, &monitorInfo.rcMonitor);
    int visibleHeight = intersection.bottom - intersection.top;
    int visibleWidth = intersection.right - intersection.left;
    int taskbarHeight = taskbar.bottom - taskbar.top;
    int taskbarWidth = taskbar.right - taskbar.left;
    bool horizontal = taskbarWidth >= taskbarHeight;
    int visible = horizontal ? visibleHeight : visibleWidth;
    int full = horizontal ? taskbarHeight : taskbarWidth;
    return visible >= full - PopupDipToPx(4.0, g_taskbarWnd);
}

bool IsIslandRectOnScreen(RECT const& rect) {
    if (rect.right <= rect.left || rect.bottom <= rect.top) {
        return false;
    }
    HMONITOR monitor = MonitorFromRect(&rect, MONITOR_DEFAULTTONEAREST);
    MONITORINFO monitorInfo{sizeof(monitorInfo)};
    if (!monitor || !GetMonitorInfoW(monitor, &monitorInfo)) {
        return false;
    }

    int margin = PopupDipToPx(4.0, g_taskbarWnd);
    RECT visible = monitorInfo.rcMonitor;
    InflateRect(&visible, -margin, -margin);
    RECT intersection{};
    if (!IntersectRect(&intersection, &rect, &visible)) {
        return false;
    }
    int minSize = PopupDipToPx(8.0, g_taskbarWnd);
    return (intersection.right - intersection.left) >= minSize &&
           (intersection.bottom - intersection.top) >= minSize;
}

bool IsIslandXamlVisible() {
    if (!g_playerGrid) {
        return false;
    }
    try {
        // The island itself is intentionally kept at ~0 opacity while the
        // popup rests, so only inspect ancestors: the taskbar content tree.
        winrt::Windows::UI::Xaml::DependencyObject current =
            VisualTreeHelper::GetParent(g_playerGrid);
        while (current) {
            auto frameworkElement = current.try_as<FrameworkElement>();
            if (frameworkElement) {
                if (frameworkElement.Visibility() == Visibility::Collapsed) {
                    return false;
                }
                auto uiElement = current.try_as<UIElement>();
                if (uiElement && uiElement.Opacity() <= 0.02) {
                    return false;
                }
            }
            current = VisualTreeHelper::GetParent(current);
        }
        // A collapsed/removed taskbar content tree also collapses layout size.
        if (g_playerGrid.ActualWidth() <= 1.0 ||
            g_playerGrid.ActualHeight() <= 1.0) {
            return false;
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool WindowRectIsHiding(RECT const& rect) {
    if (rect.right <= rect.left || rect.bottom <= rect.top) {
        return true;
    }
    HMONITOR monitor = MonitorFromRect(&rect, MONITOR_DEFAULTTONEAREST);
    MONITORINFO monitorInfo{sizeof(monitorInfo)};
    if (!monitor || !GetMonitorInfoW(monitor, &monitorInfo)) {
        return false;
    }
    RECT intersection{};
    if (!IntersectRect(&intersection, &rect, &monitorInfo.rcMonitor)) {
        return true;
    }
    // Auto-hidden taskbars leave at most a 1-2 px sliver visible.
    return (intersection.right - intersection.left) <= 3 ||
           (intersection.bottom - intersection.top) <= 3;
}

constexpr UINT_PTR kTaskbarVisibilitySubclassId = 2;
std::vector<HWND> g_taskbarVisibilitySubclassedWnds;

void OffsetAllPopupGeometry(int dx, int dy) {
    if (dx == 0 && dy == 0) {
        return;
    }
    OffsetRect(&g_popupSourceRect, dx, dy);
    OffsetRect(&g_popupSourceArtRect, dx, dy);
    OffsetRect(&g_popupSourceTitleRect, dx, dy);
    OffsetRect(&g_popupSourceArtistRect, dx, dy);
    OffsetRect(&g_popupSourceProgressRect, dx, dy);
    OffsetRect(&g_popupSourceControlsRect, dx, dy);
    OffsetRect(&g_popupSourcePlaybackIndicatorRect, dx, dy);
    OffsetRect(&g_popupFinalRect, dx, dy);
    OffsetRect(&g_popupHostRect, dx, dy);
}

void MovePopupHostBy(int dx, int dy) {
    if (!g_expandedPopup || !IsWindow(g_expandedPopup)) {
        return;
    }
    RECT rect{};
    GetWindowRect(g_expandedPopup, &rect);
    int width = std::max(1L, rect.right - rect.left);
    int height = std::max(1L, rect.bottom - rect.top);
    SetWindowPos(
        g_expandedPopup, HWND_TOPMOST, rect.left + dx, rect.top + dy, width,
        height,
        SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOSENDCHANGING);
    if (g_popupXamlChild && IsWindow(g_popupXamlChild)) {
        MoveWindow(g_popupXamlChild, 0, 0, width, height, FALSE);
    }
    // Keep the click-catch window glued to the island while it rides the
    // taskbar down, so interrupts keep working after an auto-hide move.
    if (g_popupToggleHitWindow && IsWindow(g_popupToggleHitWindow) &&
        IsWindowVisible(g_popupToggleHitWindow)) {
        RECT toggleRect{};
        GetWindowRect(g_popupToggleHitWindow, &toggleRect);
        int toggleWidth = std::max(1L, toggleRect.right - toggleRect.left);
        int toggleHeight = std::max(1L, toggleRect.bottom - toggleRect.top);
        SetWindowPos(g_popupToggleHitWindow, HWND_TOPMOST, toggleRect.left + dx,
                     toggleRect.top + dy, toggleWidth, toggleHeight,
                     SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOOWNERZORDER |
                         SWP_NOSENDCHANGING);
    }
    g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_lastPopupVisualRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
}

void ApplyPendingPopupDelta() {
    if (g_pendingPopupDeltaX == 0 && g_pendingPopupDeltaY == 0) {
        return;
    }
    int dx = g_pendingPopupDeltaX;
    int dy = g_pendingPopupDeltaY;
    g_pendingPopupDeltaX = 0;
    g_pendingPopupDeltaY = 0;
    OffsetAllPopupGeometry(dx, dy);
    MovePopupHostBy(dx, dy);
}

// Put the island back into its natural "in the taskbar" layer: directly
// above the taskbar window, below whatever is currently above the taskbar
// (Start menu, shell overlays, or an app that is covering the taskbar while
// it auto-hides). This is event-driven only - never called per tick - so it
// cannot cause the repeated backdrop re-sampling that looked like a flash.
void AnchorIslandAboveTaskbar() {
    if (!g_expandedPopup || !IsWindow(g_expandedPopup) || !g_taskbarWnd ||
        !IsWindow(g_taskbarWnd) || !IsWindowVisible(g_expandedPopup)) {
        return;
    }
    HWND insertAfter = GetWindow(g_taskbarWnd, GW_HWNDPREV);
    if (!insertAfter) {
        insertAfter = HWND_TOP;
    }
    SetWindowPos(g_expandedPopup, insertAfter, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOOWNERZORDER |
                     SWP_NOSENDCHANGING);
    if (g_popupToggleHitWindow && IsWindow(g_popupToggleHitWindow)) {
        HWND toggleAfter = GetWindow(g_expandedPopup, GW_HWNDPREV);
        if (!toggleAfter) {
            toggleAfter = HWND_TOP;
        }
        SetWindowPos(g_popupToggleHitWindow, toggleAfter, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE |
                         SWP_NOOWNERZORDER | SWP_NOSENDCHANGING);
    }
}

void KeepPopupOnTop() {
    if (!g_expandedPopup || !IsWindow(g_expandedPopup)) {
        return;
    }
    // While the taskbar is hiding (or hidden), do not touch z-order at all:
    // re-inserting the owned popup can drag the taskbar back above the
    // covering app and cause the flicker.
    if (g_taskbarHiddenBySystem.load() || IsTaskbarCurrentlyAutoHidden() ||
        !TaskbarFullyShown()) {
        return;
    }
    // The island is owned by the taskbar (Shell_TrayWnd is WS_EX_TOPMOST), so
    // it is already in the topmost band and can never drop below the taskbar.
    // HWND_TOP only re-orders within that band (e.g. above the Start menu on
    // click); it never changes topmost membership, so it cannot drag the
    // taskbar above a fullscreen app and cannot cause the flash.
    SetWindowPos(g_expandedPopup, HWND_TOP, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOOWNERZORDER |
                     SWP_NOSENDCHANGING);
    if (g_popupToggleHitWindow && IsWindow(g_popupToggleHitWindow)) {
        SetWindowPos(g_popupToggleHitWindow, HWND_TOP, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE |
                         SWP_NOOWNERZORDER | SWP_NOSENDCHANGING);
    }
}

LRESULT CALLBACK TaskbarVisibilitySubclassProc(HWND hwnd,
                                               UINT message,
                                               WPARAM wParam,
                                               LPARAM lParam,
                                               UINT_PTR,
                                               DWORD_PTR) {
    if (message == WM_WINDOWPOSCHANGING) {
        auto* windowPos = reinterpret_cast<WINDOWPOS*>(lParam);
        if (windowPos && (windowPos->flags & SWP_HIDEWINDOW) != 0) {
            g_taskbarHiddenBySystem = true;
        }
    } else if (message == WM_WINDOWPOSCHANGED) {
        // Child-window WINDOWPOS coordinates are parent-relative, so read
        // the real screen rect after the move instead of trusting lParam.
        auto* windowPos = reinterpret_cast<WINDOWPOS*>(lParam);
        RECT rect{};
        if (GetWindowRect(hwnd, &rect)) {
            g_taskbarHiddenBySystem = WindowRectIsHiding(rect);
        }
        // When the shell reorders the taskbar itself (drops it out of the
        // topmost band to auto-hide, or reinserts it on show), re-anchor the
        // island directly above it. This is what keeps the island's layer
        // glued to the taskbar's layer: it never floats over an app that
        // covers the taskbar, and it can never stay pressed under the
        // taskbar after the taskbar comes back. Only actual z-order changes
        // (SWP_NOZORDER absent) trigger this, never the per-frame move
        // animation, so there is no repeated backdrop re-sampling flash.
        bool zOrderChanged =
            windowPos && (windowPos->flags & SWP_NOZORDER) == 0;
        if (zOrderChanged && hwnd == g_taskbarWnd &&
            (g_popupClosing || g_popupRestingCompact)) {
            AnchorIslandAboveTaskbar();
        }
        // 1:1 follow fast-path: the island element lives in the XAML bridge
        // child; during auto-hide the bridge (and sometimes the parent) moves.
        // Follow EITHER window when it moves. The bridge usually does NOT
        // receive WM_WINDOWPOSCHANGED when the parent moves it implicitly, so
        // restricting the follow to one preferred window made the ride-down
        // never fire. Each window keeps its own last rect, so no bogus delta.
        RECT* trackedRect = nullptr;
        if (hwnd == g_taskbarWnd) {
            trackedRect = &g_lastTrackedTaskbarRect;
        } else if (hwnd == g_taskbarXamlHostWnd) {
            trackedRect = &g_lastTrackedBridgeRect;
        }
        if (trackedRect && (g_popupClosing || g_popupRestingCompact)) {
            if (trackedRect->left != LONG_MIN) {
                int dx = rect.left - trackedRect->left;
                int dy = rect.top - trackedRect->top;
                if (dx != 0 || dy != 0) {
                    OffsetAllPopupGeometry(dx, dy);
                    MovePopupHostBy(dx, dy);
                    // First upward movement while the resting island is
                    // hidden: show it right now so it rides up together with
                    // the taskbar instead of popping in after the rise.
                    bool rising = g_taskbarAtTop ? (dy > 0) : (dy < 0);
                    if (rising && g_popupRestingCompact &&
                        g_popupRestingHiddenWithTaskbar && g_expandedPopup &&
                        !IsWindowVisible(g_expandedPopup)) {
                        g_popupRestingHiddenWithTaskbar = false;
                        g_popupRidingTaskbarUp = true;
                        ShowWindow(g_expandedPopup, SW_SHOWNOACTIVATE);
                        ShowPopupToggleHitWindow();
                        AnchorIslandAboveTaskbar();
                    }
                }
            }
            *trackedRect = rect;
        }
    } else if (message == WM_SHOWWINDOW) {
        g_taskbarHiddenBySystem = (wParam == FALSE);
    }
    return DefSubclassProc(hwnd, message, wParam, lParam);
}

void SubclassTaskbarVisibilityWindow(HWND hwnd) {
    if (!hwnd || !IsWindow(hwnd)) {
        return;
    }
    for (auto existing : g_taskbarVisibilitySubclassedWnds) {
        if (existing == hwnd) {
            return;
        }
    }
    if (SetWindowSubclass(hwnd, TaskbarVisibilitySubclassProc,
                          kTaskbarVisibilitySubclassId, 0)) {
        g_taskbarVisibilitySubclassedWnds.push_back(hwnd);
    }
}

static BOOL CALLBACK SubclassTaskbarChildWindowsProc(HWND child, LPARAM) {
    wchar_t className[128]{};
    if (GetClassNameW(child, className, 128) > 0 &&
        wcscmp(className,
               L"Windows.UI.Composition.DesktopWindowContentBridge") == 0) {
        SubclassTaskbarVisibilityWindow(child);
        g_taskbarXamlHostWnd = child;
    }
    return TRUE;
}

void SubclassTaskbarVisibilityWindows() {
    g_taskbarVisibilitySubclassedWnds.clear();
    if (!g_taskbarWnd || !IsWindow(g_taskbarWnd)) {
        return;
    }

    // The taskbar content is hosted in a composition bridge child window;
    // auto-hide moves that bridge (or the top-level window), so watch both.
    SubclassTaskbarVisibilityWindow(g_taskbarWnd);
    EnumChildWindows(g_taskbarWnd, SubclassTaskbarChildWindowsProc, 0);

    RECT rect{};
    bool gotRect = GetWindowRect(g_taskbarWnd, &rect);
    g_taskbarHiddenBySystem = !(gotRect && !WindowRectIsHiding(rect));
    if (gotRect) {
        g_lastTrackedTaskbarRect = rect;
    }
    g_lastTrackedBridgeRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
}

void UnsubclassTaskbarVisibilityWindows() {
    for (auto hwnd : g_taskbarVisibilitySubclassedWnds) {
        if (hwnd && IsWindow(hwnd)) {
            RemoveWindowSubclass(hwnd, TaskbarVisibilitySubclassProc,
                                 kTaskbarVisibilitySubclassId);
        }
    }
    g_taskbarVisibilitySubclassedWnds.clear();
    g_taskbarXamlHostWnd = nullptr;
}

void KeepPopupOnTop();

void SyncRestingPopupWithTaskbarVisibility() {
    if (!g_popupRestingCompact || !g_expandedPopup)
        return;

    auto stabilizeVisibleTaskbarLayer = [&] {
        if (!TaskbarFullyShown() || !IsWindowVisible(g_expandedPopup)) {
            g_taskbarFullyShownSince = {};
            g_taskbarShowReanchorStage = 0;
            return;
        }
        auto now = std::chrono::steady_clock::now();
        if (g_taskbarFullyShownSince.time_since_epoch().count() == 0) {
            g_taskbarFullyShownSince = now;
            g_taskbarShowReanchorStage = 1;
            AnchorIslandAboveTaskbar();
            return;
        }
        auto shownFor = std::chrono::duration_cast<std::chrono::milliseconds>(
                            now - g_taskbarFullyShownSince)
                            .count();
        if (g_taskbarShowReanchorStage == 1 && shownFor >= 80) {
            AnchorIslandAboveTaskbar();
            g_taskbarShowReanchorStage = 2;
        } else if (g_taskbarShowReanchorStage == 2 && shownFor >= 240) {
            AnchorIslandAboveTaskbar();
            g_taskbarShowReanchorStage = 3;
        } else if (g_taskbarShowReanchorStage == 3 && shownFor >= 600) {
            AnchorIslandAboveTaskbar();
            g_taskbarShowReanchorStage = 4;
        }
    };

    // While the island is riding up with the taskbar, stay visible and let
    // the per-tick re-anchor carry it. Exit the riding state only when the
    // taskbar is fully shown (normal logic takes over) or hides again.
    if (g_popupRidingTaskbarUp) {
        if (IsTaskbarCurrentlyAutoHidden()) {
            g_popupRidingTaskbarUp = false;
        } else if (TaskbarFullyShown()) {
            g_popupRidingTaskbarUp = false;
        } else {
            return;
        }
    }

    // Rising transition: the taskbar has not fully risen yet, but the island
    // element is already partially on screen. Appear at its live position
    // right now and enter the riding state, so the island rises together
    // with the taskbar instead of popping in after it settles.
    if (g_popupRestingHiddenWithTaskbar && !TaskbarFullyShown()) {
        RECT islandNowRise{};
        if (g_playerGrid && GetElementScreenRect(g_playerGrid, islandNowRise) &&
            IsIslandRectOnScreen(islandNowRise)) {
            g_popupRidingTaskbarUp = true;
            g_popupRestingHiddenWithTaskbar = false;
            g_taskbarFullyShownSince = {};
            g_taskbarShowReanchorStage = 0;
            CapturePopupSourceGeometry();
            g_popupHostRect =
                UnionPopupRects(g_popupSourceRect, g_popupFinalRect);
            g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
            PositionExpandedPopup();
            UpdatePopupXamlVisuals();
            ApplyPopupCompactWindowRegions();
            ShowWindow(g_expandedPopup, SW_SHOWNOACTIVATE);
            ShowPopupToggleHitWindow();
            AnchorIslandAboveTaskbar();
            return;
        }
    }

    RECT islandNow{};
    bool haveIsland =
        g_playerGrid && GetElementScreenRect(g_playerGrid, islandNow);
    // Only hide once the taskbar/island is actually off-screen (or its XAML
    // collapsed). The shell-intent flag is deliberately NOT used here: the
    // 1:1 delta-follow first carries the popup down with the taskbar, and
    // hiding happens after it has visibly gone with the taskbar.
    bool taskbarFullyVisible = TaskbarFullyShown();
    // A fast fullscreen taskbar reveal can jump from fully hidden to fully
    // shown between two 8 ms ticks. In that case the partial-rise branch above
    // never runs, while the taskbar XAML tree can still report one stale hidden
    // frame. The real, fully-on-screen taskbar window is authoritative: once it
    // is fully shown, never let stale XAML visibility keep the resting popup
    // hidden forever.
    bool hidden =
        IsTaskbarCurrentlyAutoHidden() ||
        (!taskbarFullyVisible && (!IsIslandXamlVisible() || !haveIsland ||
                                  !IsIslandRectOnScreen(islandNow)));
    // The island is hidden and the taskbar is returning: show RIGHT NOW at
    // the island element's live position. The per-frame follow keeps it
    // riding up together with the taskbar from this very frame.
    if (hidden == g_popupRestingHiddenWithTaskbar) {
        if (!hidden) {
            stabilizeVisibleTaskbarLayer();
        }
        return;
    }
    g_popupRestingHiddenWithTaskbar = hidden;
    if (hidden) {
        g_popupRidingTaskbarUp = false;
        g_taskbarFullyShownSince = {};
        g_taskbarShowReanchorStage = 0;
        ShowWindow(g_expandedPopup, SW_HIDE);
        if (g_popupBackdropOverlay)
            ShowWindow(g_popupBackdropOverlay, SW_HIDE);
        HidePopupToggleHitWindow();
        return;
    }
    CapturePopupSourceGeometry();
    g_popupHostRect = UnionPopupRects(g_popupSourceRect, g_popupFinalRect);
    g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    PositionExpandedPopup();
    UpdatePopupXamlVisuals();
    ApplyPopupCompactWindowRegions();
    ShowWindow(g_expandedPopup, SW_SHOWNOACTIVATE);
    ShowPopupToggleHitWindow();
    AnchorIslandAboveTaskbar();
    g_taskbarFullyShownSince = std::chrono::steady_clock::now();
    g_taskbarShowReanchorStage = 1;
}

// ===== Popup render loop and window procedure =====
void OnPopupXamlRendering(winrt::Windows::Foundation::IInspectable const&,
                          winrt::Windows::Foundation::IInspectable const&) {
    try {
        if (!g_popupXamlRoot || !g_expandedPopup || g_unloading) {
            StopPopupXamlRenderLoop();
            return;
        }

        auto now = std::chrono::steady_clock::now();
        double dt = 1.0 / 60.0;
        if (g_lastPopupFrameTime.time_since_epoch().count() != 0) {
            dt = std::chrono::duration_cast<std::chrono::microseconds>(
                     now - g_lastPopupFrameTime)
                     .count() /
                 1000000.0;
        }
        g_lastPopupFrameTime = now;
        dt = Clamp(dt, 0.0, 0.05);
        if (g_popupClosing) {
            // Apply any pending taskbar-follow deltas before re-measuring.
            ApplyPendingPopupDelta();
            // The taskbar-move probe already drags the popup along on every
            // window move; this island-rect tracking is a second, frame-level
            // fallback for XAML-transform hides that don't move a window.
            RECT islandNow{};
            if (g_playerGrid && GetElementScreenRect(g_playerGrid, islandNow) &&
                !EqualRect(&islandNow, &g_lastTrackedIslandRect)) {
                g_lastTrackedIslandRect = islandNow;
                CapturePopupSourceGeometry(true);
                if (g_popupXamlRoot) {
                    g_popupHostRect =
                        UnionPopupRects(g_popupSourceRect, g_popupFinalRect);
                    g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN,
                                             LONG_MIN};
                }
            }
        }
        TickPopupMediaTransition(dt);
        bool animationSettled = AdvancePopupSpring(dt);
        PositionExpandedPopup();
        UpdatePopupLiveProgressFromSnapshot();
        RenderExpandedPopupLayer();

        if (animationSettled) {
            if (g_popupClosing && g_popupAnimationTarget == 0.0) {
                // Re-align the final frame with the island's current position,
                // then keep this same surface as the compact island. There is no
                // handoff swap at all, so no flash: the popup simply stays in
                // place, follows the taskbar (auto-hide included), and the next
                // click reverses the same spring to open again.
                CapturePopupSourceGeometry(true);
                if (g_popupXamlRoot) {
                    g_popupHostRect =
                        UnionPopupRects(g_popupSourceRect, g_popupFinalRect);
                    g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN,
                                             LONG_MIN};
                    PositionExpandedPopup();
                }
                RenderExpandedPopupLayer();
                g_popupPendingContentRefresh = false;
                RestExpandedPopupAsCompact();
                return;
            }
            if (g_popupMediaTransitionActive) {
                return;
            }
            if (g_popupAnimationTarget == 1.0) {
                g_popupLifecycleState = PopupLifecycleState::Open;
            }
            StopPopupXamlRenderLoop();
            if (g_popupPendingContentRefresh) {
                g_popupPendingContentRefresh = false;
                UpdatePlayerContents();
            }
        }
    } catch (...) {
        Wh_Log(L"Island: exception in popup rendering callback");
        FinishCloseExpandedPopup(g_expandedPopup);
    }
}

void StartPopupXamlRenderLoop() {
    if (!g_popupXamlRoot || g_popupRenderingHooked) {
        return;
    }
    // Let the first callback use a full 60 Hz step. Seeding this with "now"
    // produced a near-zero first step and made the popup appear to hesitate.
    g_lastPopupFrameTime = {};
    g_popupRenderingToken =
        mediax::CompositionTarget::Rendering(OnPopupXamlRendering);
    g_popupRenderingHooked = true;
}

LRESULT CALLBACK ExpandedPopupWndProc(HWND hwnd,
                                      UINT message,
                                      WPARAM wParam,
                                      LPARAM lParam) {
    try {
        switch (message) {
            case WM_ERASEBKGND:
                return 1;
            case WM_NCHITTEST:
                return PopupExpandedHitTest(lParam);
            case WM_PAINT: {
                PAINTSTRUCT paint{};
                BeginPaint(hwnd, &paint);
                EndPaint(hwnd, &paint);
                return 0;
            }
            case WM_LBUTTONDOWN: {
                KeepPopupOnTop();
                POINT screenPoint{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
                ClientToScreen(hwnd, &screenPoint);
                bool transitionActive =
                    g_popupLifecycleState == PopupLifecycleState::Opening ||
                    g_popupLifecycleState == PopupLifecycleState::Closing ||
                    std::abs(g_popupAnimationTarget -
                             g_popupAnimationProgress) >= 0.006;
                if ((transitionActive &&
                     PopupScreenPointIsInsideCurrentSurface(screenPoint)) ||
                    PopupPointIsInsideOriginalToggleArea(screenPoint)) {
                    InterruptPopupAnimationFromOriginalArea();
                    return 0;
                }
                break;
            }
            case WM_LBUTTONUP: {
                POINT originalTogglePoint{GET_X_LPARAM(lParam),
                                          GET_Y_LPARAM(lParam)};
                ClientToScreen(hwnd, &originalTogglePoint);
                if (PopupPointIsInsideOriginalToggleArea(originalTogglePoint)) {
                    return 0;
                }
                if (PopupProgress() < 0.75) {
                    if (!g_popupClosing) {
                        BeginCloseExpandedPopup();
                    }
                    return 0;
                }
                RECT client{};
                GetClientRect(hwnd, &client);
                POINT point{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
                RECT art{};
                RECT card{};
                RECT title{};
                RECT artist{};
                RECT progress{};
                RECT elapsed{};
                RECT duration{};
                RECT controls{};
                CalculatePopupFinalLayout(client, art, card, title, artist,
                                          progress, elapsed, duration,
                                          controls);
                RECT progressHitTarget = progress;
                InflateRect(&progressHitTarget, 0, 8);
                if (PtInRect(&progressHitTarget, point) &&
                    progress.right > progress.left) {
                    SeekToMediaPosition(
                        static_cast<double>(point.x - progress.left) /
                        static_cast<double>(progress.right - progress.left));
                    return 0;
                }
                for (int i = 0; i < 3; ++i) {
                    RECT button =
                        PopupButtonRect(i, client.right, client.bottom);
                    if (!PtInRect(&button, point)) {
                        continue;
                    }
                    if (i == 0) {
                        RunMediaTransportCommand(
                            MediaTransportCommand::Previous);
                    } else if (i == 1) {
                        RunMediaTransportCommand(
                            MediaTransportCommand::TogglePlayPause);
                    } else if (i == 2) {
                        RunMediaTransportCommand(MediaTransportCommand::Next);
                    }
                    return 0;
                }
                return 0;
            }
            case WM_TIMER: {
                // Apply taskbar-follow deltas that were accumulated off the
                // shell's message path.
                ApplyPendingPopupDelta();
                // One-shot z-order upkeep on foreground changes:
                // - Expanded card + shell surface (Start menu, taskbar): lift the
                //   card above the shell surface once.
                // - Compact/closing island: anchor it directly above the taskbar
                //   so it never floats above an app that took the foreground and
                //   never gets pressed under the taskbar when the taskbar is
                //   re-shown. Anchoring is event-driven (once per change), so it
                //   cannot cause the repeated backdrop re-sampling flash.
                static HWND s_lastForegroundHwnd = nullptr;
                HWND foregroundHwnd = GetForegroundWindow();
                if (foregroundHwnd != s_lastForegroundHwnd) {
                    s_lastForegroundHwnd = foregroundHwnd;
                    DWORD foregroundPid = 0;
                    GetWindowThreadProcessId(foregroundHwnd, &foregroundPid);
                    if (foregroundPid == GetCurrentProcessId()) {
                        // Shell surface (taskbar, Start menu).
                        if (!g_popupRestingCompact && g_expandedPopup &&
                            IsWindow(g_expandedPopup) &&
                            IsWindowVisible(g_expandedPopup)) {
                            KeepPopupOnTop();
                        } else {
                            AnchorIslandAboveTaskbar();
                        }
                    } else if (g_popupRestingCompact || g_popupClosing) {
                        // An app took the foreground. Keep the island glued to
                        // the taskbar's layer so it rides down together with the
                        // taskbar instead of floating above the app or staying
                        // behind at the old position.
                        if (g_expandedPopup && IsWindow(g_expandedPopup) &&
                            IsWindowVisible(g_expandedPopup)) {
                            AnchorIslandAboveTaskbar();
                        }
                    }
                }
                // Frame-level 1:1 follow: while closing or resting as the compact
                // island, re-anchor to the native island element's current screen
                // rect every tick. This works whether the auto-hide animation
                // moves Shell_TrayWnd, the XAML bridge, or only the island's
                // transform, so the island rides down AND up with the taskbar
                // instead of hiding/showing late in place.
                if ((g_popupClosing || g_popupRestingCompact) &&
                    g_expandedPopup && IsWindow(g_expandedPopup)) {
                    RECT islandNow{};
                    if (g_playerGrid &&
                        GetElementScreenRect(g_playerGrid, islandNow) &&
                        !EqualRect(&islandNow, &g_lastTrackedIslandRect)) {
                        g_lastTrackedIslandRect = islandNow;
                        CapturePopupSourceGeometry(true);
                        if (g_popupXamlRoot) {
                            g_popupHostRect = UnionPopupRects(g_popupSourceRect,
                                                              g_popupFinalRect);
                            g_lastPopupWindowRect = {LONG_MIN, LONG_MIN,
                                                     LONG_MIN, LONG_MIN};
                        }
                        PositionExpandedPopup();
                        UpdatePopupXamlVisuals();
                    }
                }
                // Keep the click-catch window glued to the island's current
                // position so rapid continuous clicks always hit the interrupt
                // target, even after the island moved with the taskbar.
                if (g_popupToggleHitWindow &&
                    IsWindow(g_popupToggleHitWindow) &&
                    IsWindowVisible(g_popupToggleHitWindow) &&
                    !IsRectEmpty(&g_popupSourceRect)) {
                    RECT toggleRect{};
                    GetWindowRect(g_popupToggleHitWindow, &toggleRect);
                    int toggleWidth =
                        g_popupSourceRect.right - g_popupSourceRect.left;
                    int toggleHeight =
                        g_popupSourceRect.bottom - g_popupSourceRect.top;
                    if (toggleRect.left != g_popupSourceRect.left ||
                        toggleRect.top != g_popupSourceRect.top ||
                        (toggleRect.right - toggleRect.left) != toggleWidth ||
                        (toggleRect.bottom - toggleRect.top) != toggleHeight) {
                        SetWindowPos(
                            g_popupToggleHitWindow, HWND_TOP,
                            g_popupSourceRect.left, g_popupSourceRect.top,
                            toggleWidth, toggleHeight,
                            SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOOWNERZORDER |
                                SWP_NOSENDCHANGING);
                    }
                }
                if (g_popupRestingCompact) {
                    SyncRestingPopupWithTaskbarVisibility();
                    return 0;
                }
                if (!g_popupSeekDragging) {
                    bool leftDown =
                        (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
                    if (!leftDown) {
                        g_popupOutsideClickArmed = true;
                    } else if (g_popupOutsideClickArmed) {
                        POINT cursor{};
                        RECT popupRect{};
                        GetCursorPos(&cursor);
                        if (g_popupXamlRoot) {
                            popupRect = CurrentPopupSurfaceScreenRect();
                            InflateRect(&popupRect, 12, 12);
                        } else {
                            GetWindowRect(hwnd, &popupRect);
                        }
                        if (!PtInRect(&popupRect, cursor)) {
                            BeginCloseExpandedPopup();
                        }
                    }
                }

                if (g_popupXamlRoot) {
                    UpdatePopupLiveProgressFromSnapshot();
                    // CompositionTarget::Rendering owns XAML animation and visual
                    // updates. Rendering again from this 30 ms timer made many
                    // frames execute twice and produced uneven pacing.
                    return 0;
                }

                bool animationSettled = AdvancePopupSpring(0.015);
                if (animationSettled) {
                    if (g_popupClosing && g_popupAnimationTarget == 0.0) {
                        RestExpandedPopupAsCompact();
                        return 0;
                    }
                }
                PositionExpandedPopup();
                RenderExpandedPopupLayer();
                return 0;
            }
            case WM_DPICHANGED: {
                auto suggestedRect = reinterpret_cast<RECT const*>(lParam);
                if (suggestedRect) {
                    SetWindowPos(
                        hwnd, nullptr, suggestedRect->left, suggestedRect->top,
                        suggestedRect->right - suggestedRect->left,
                        suggestedRect->bottom - suggestedRect->top,
                        SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOZORDER);
                }
                if (g_expandedPopup == hwnd) {
                    PositionExpandedPopup();
                    RenderExpandedPopupLayer();
                }
                return 0;
            }
            case WM_SETTINGCHANGE:
            case WM_THEMECHANGED:
                g_popupXamlThemeValid = false;
                ApplyPopupBackdrop(hwnd);
                ApplyPopupXamlTheme(true);
                RenderExpandedPopupLayer();
                return 0;
            case WM_DESTROY:
                StopPopupXamlRenderLoop();
                KillTimer(hwnd, kPopupTimerId);
                if (g_expandedPopup == hwnd) {
                    if (g_popupRestingCompact) {
                        g_popupRestingCompact = false;
                        g_popupRestingHiddenWithTaskbar = false;
                        g_popupRidingTaskbarUp = false;
                        SetCompactIslandSuppressed(false);
                    }
                    g_expandedPopup = nullptr;
                }
                return 0;
        }
        return DefWindowProcW(hwnd, message, wParam, lParam);
    } catch (...) {
        Wh_Log(L"Island: exception in expanded popup window callback");
        FinishCloseExpandedPopup(hwnd);
        return 0;
    }
}

// ===== WGC liquid-glass backdrop =====
HINSTANCE ModInstance() {
    static HINSTANCE instance = [] {
        HMODULE module = nullptr;
        static int moduleAnchor = 0;
        if (!GetModuleHandleExW(
                GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                    GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                reinterpret_cast<LPCWSTR>(&moduleAnchor), &module)) {
            return static_cast<HINSTANCE>(nullptr);
        }
        return reinterpret_cast<HINSTANCE>(module);
    }();
    return instance;
}

BYTE PopupRoundedRectAlpha(int x, int y, int width, int height, int radius);

bool CreatePopupOverlayWgcCaptureItemForMonitor(
    HMONITOR monitor,
    capture::GraphicsCaptureItem& item) {
    item = nullptr;
    g_popupOverlayWgcCreateItemHr = S_OK;
    if (!monitor) {
        g_popupOverlayWgcCreateItemHr = E_INVALIDARG;
        Wh_Log(L"Island: overlay WGC CreateForMonitor skipped: null monitor");
        return false;
    }

    try {
        auto activationFactory =
            winrt::get_activation_factory<capture::GraphicsCaptureItem>();

        winrt::com_ptr<IGraphicsCaptureItemInterop> interopFactory;
        HRESULT hr =
            reinterpret_cast<IUnknown*>(winrt::get_abi(activationFactory))
                ->QueryInterface(kIID_IGraphicsCaptureItemInterop,
                                 interopFactory.put_void());
        if (FAILED(hr) || !interopFactory) {
            g_popupOverlayWgcCreateItemHr = hr;
            Wh_Log(
                L"Island: overlay WGC QI IGraphicsCaptureItemInterop failed "
                L"hr=0x%08X",
                static_cast<unsigned>(hr));
            return false;
        }

        void* rawItem = nullptr;
        hr = interopFactory->CreateForMonitor(
            monitor, kIID_IGraphicsCaptureItem, &rawItem);
        g_popupOverlayWgcCreateItemHr = hr;
        if (FAILED(hr)) {
            Wh_Log(
                L"Island: overlay WGC CreateForMonitor failed hr=0x%08X "
                L"monitor=%p",
                static_cast<unsigned>(hr), monitor);
            return false;
        }
        if (!rawItem) {
            g_popupOverlayWgcCreateItemHr = E_POINTER;
            Wh_Log(
                L"Island: overlay WGC CreateForMonitor returned null item "
                L"hr=0x%08X monitor=%p",
                static_cast<unsigned>(hr), monitor);
            return false;
        }

        item = capture::GraphicsCaptureItem{rawItem,
                                            winrt::take_ownership_from_abi};
        Wh_Log(L"Island: overlay WGC CreateForMonitor succeeded monitor=%p",
               monitor);
        g_popupOverlayWgcCreateItemFailed = false;
        return true;
    } catch (winrt::hresult_error const& error) {
        g_popupOverlayWgcCreateItemHr = error.code().value;
        Wh_Log(L"Island: overlay WGC CreateForMonitor exception hr=0x%08X",
               static_cast<unsigned>(g_popupOverlayWgcCreateItemHr));
        return false;
    } catch (...) {
        g_popupOverlayWgcCreateItemHr = E_FAIL;
        Wh_Log(L"Island: overlay WGC CreateForMonitor unknown exception");
        return false;
    }
}

void ClearPopupOverlayWgcLensDisplacementMap() {
    g_popupOverlayWgcLensDisplacementMap = nullptr;
    g_popupOverlayWgcLensMapWidth = 0;
    g_popupOverlayWgcLensMapHeight = 0;
    g_popupOverlayWgcLensMapRadius = 0;
    g_popupOverlayWgcLensMapRoundness = 0;
}

void ClearPopupOverlayWgcRenderCache() {
    g_popupOverlayWgcIntermediateBitmap = nullptr;
    g_popupOverlayWgcBlurEffect = nullptr;
    g_popupOverlayWgcRefractionBlurEffect = nullptr;
    g_popupOverlayWgcDisplacementEffect = nullptr;
    g_popupOverlayWgcRimBrush = nullptr;
    g_popupOverlayWgcRoundedGeometry = nullptr;
    g_popupOverlayWgcRenderCacheWidth = 0;
    g_popupOverlayWgcRenderCacheHeight = 0;
    g_popupOverlayWgcRoundedGeometryWidth = 0;
    g_popupOverlayWgcRoundedGeometryHeight = 0;
    g_popupOverlayWgcRoundedGeometryRadius = 0;
}

ID2D1RoundedRectangleGeometry* EnsurePopupOverlayWgcRoundedGeometry(
    D2D1_RECT_F const& rect,
    int width,
    int height,
    int radius) {
    if (!g_popupOverlayWgcD2dFactory || width <= 0 || height <= 0 ||
        radius <= 0) {
        return nullptr;
    }
    if (g_popupOverlayWgcRoundedGeometry &&
        g_popupOverlayWgcRoundedGeometryWidth == width &&
        g_popupOverlayWgcRoundedGeometryHeight == height &&
        g_popupOverlayWgcRoundedGeometryRadius == radius) {
        return g_popupOverlayWgcRoundedGeometry.get();
    }

    D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(
        rect, static_cast<float>(radius), static_cast<float>(radius));
    winrt::com_ptr<ID2D1RoundedRectangleGeometry> geometry;
    HRESULT hr = g_popupOverlayWgcD2dFactory->CreateRoundedRectangleGeometry(
        &roundedRect, geometry.put());
    if (FAILED(hr) || !geometry) {
        g_popupOverlayWgcLastHr = FAILED(hr) ? hr : E_FAIL;
        return nullptr;
    }

    g_popupOverlayWgcRoundedGeometry = std::move(geometry);
    g_popupOverlayWgcRoundedGeometryWidth = width;
    g_popupOverlayWgcRoundedGeometryHeight = height;
    g_popupOverlayWgcRoundedGeometryRadius = radius;
    return g_popupOverlayWgcRoundedGeometry.get();
}

bool EnsurePopupOverlayWgcRenderCache(int width,
                                      int height,
                                      D2D1_BITMAP_PROPERTIES1 const& props,
                                      bool useLiquidLensWarp) {
    if (!g_popupOverlayWgcD2dContext || width <= 0 || height <= 0) {
        return false;
    }

    if (g_popupOverlayWgcRenderCacheWidth != width ||
        g_popupOverlayWgcRenderCacheHeight != height) {
        g_popupOverlayWgcIntermediateBitmap = nullptr;
        g_popupOverlayWgcRenderCacheWidth = 0;
        g_popupOverlayWgcRenderCacheHeight = 0;
    }

    auto createTargetBitmap = [&](winrt::com_ptr<ID2D1Bitmap1>& bitmap) {
        if (bitmap) {
            return true;
        }
        HRESULT hr = g_popupOverlayWgcD2dContext->CreateBitmap(
            D2D1::SizeU(static_cast<UINT32>(width),
                        static_cast<UINT32>(height)),
            nullptr, 0, &props, bitmap.put());
        if (FAILED(hr)) {
            g_popupOverlayWgcLastHr = hr;
            return false;
        }
        return true;
    };

    if (!createTargetBitmap(g_popupOverlayWgcIntermediateBitmap)) {
        ClearPopupOverlayWgcRenderCache();
        return false;
    }

    if (!g_popupOverlayWgcBlurEffect) {
        HRESULT hr = g_popupOverlayWgcD2dContext->CreateEffect(
            CLSID_D2D1GaussianBlur, g_popupOverlayWgcBlurEffect.put());
        if (FAILED(hr) || !g_popupOverlayWgcBlurEffect) {
            g_popupOverlayWgcLastHr = FAILED(hr) ? hr : E_FAIL;
            ClearPopupOverlayWgcRenderCache();
            return false;
        }
        g_popupOverlayWgcBlurEffect->SetValue(
            D2D1_GAUSSIANBLUR_PROP_BORDER_MODE, D2D1_BORDER_MODE_HARD);
    }

    if (useLiquidLensWarp && !g_popupOverlayWgcRefractionBlurEffect) {
        HRESULT hr = g_popupOverlayWgcD2dContext->CreateEffect(
            CLSID_D2D1GaussianBlur,
            g_popupOverlayWgcRefractionBlurEffect.put());
        if (FAILED(hr) || !g_popupOverlayWgcRefractionBlurEffect) {
            g_popupOverlayWgcLastHr = FAILED(hr) ? hr : E_FAIL;
            ClearPopupOverlayWgcRenderCache();
            return false;
        }
        g_popupOverlayWgcRefractionBlurEffect->SetValue(
            D2D1_GAUSSIANBLUR_PROP_BORDER_MODE, D2D1_BORDER_MODE_HARD);
    }

    g_popupOverlayWgcRenderCacheWidth = width;
    g_popupOverlayWgcRenderCacheHeight = height;
    return true;
}

bool EnsurePopupOverlayWgcLensDisplacementMap(int width,
                                              int height,
                                              int radius) {
    if (!g_popupOverlayWgcD2dContext || width <= 0 || height <= 0) {
        return false;
    }

    radius = Clamp(radius, 1, std::max(1, std::min(width, height) / 2));
    if (g_popupOverlayWgcLensDisplacementMap &&
        g_popupOverlayWgcLensMapWidth == width &&
        g_popupOverlayWgcLensMapHeight == height &&
        g_popupOverlayWgcLensMapRadius == radius &&
        g_popupOverlayWgcLensMapRoundness == g_settings.liquidGlassRoundness) {
        return true;
    }

    std::vector<BYTE> pixels(static_cast<size_t>(width) * height * 4);
    double widthD = static_cast<double>(width);
    double heightD = static_cast<double>(height);
    double minD = std::min(widthD, heightD);
    double radiusD = static_cast<double>(radius);
    double halfWidth = widthD * 0.5;
    double halfHeight = heightD * 0.5;
    double innerHalfWidth = std::max(0.0, halfWidth - radiusD);
    double innerHalfHeight = std::max(0.0, halfHeight - radiusD);
    double centerX = widthD * 0.5;
    double centerY = heightD * 0.5;

    // CodePen-style RG displacement texture. The texture is neutral gray in
    // the calm center (R=G=128), then the red/green channels follow a single
    // continuous tangent field around the rounded shell. A narrow high-index
    // rim is blended with a wider shoulder so the refraction is strongest on
    // the edge and fades inward toward neutral.
    // liquidGL-inspired thin bevel: a narrow high-index edge, a soft shoulder
    // and a neutral center. Keep the refractive area proportional to the pane.
    double rimWidth = Clamp(minD * 0.015, 1.5, 3.5);
    double shoulderWidth = Clamp(minD * 0.105, 7.0, 28.0);
    double bodyWidth = Clamp(minD * 0.220, 22.0, 72.0);

    auto smootherStep = [](double value) {
        value = Clamp(value, 0.0, 1.0);
        return value * value * value * (value * (value * 6.0 - 15.0) + 10.0);
    };
    auto smoothMax = [](double a, double b, double smoothness) {
        double h = Clamp(0.5 + 0.5 * (a - b) / smoothness, 0.0, 1.0);
        return a * h + b * (1.0 - h) + smoothness * h * (1.0 - h);
    };
    auto fastThenSlowQuadraticFalloff = [](double distance, double widthValue,
                                           double holdRatio) {
        double t = Clamp(distance / std::max(1.0, widthValue), 0.0, 1.0);
        holdRatio = Clamp(holdRatio, 0.0, 0.92);
        double u = t <= holdRatio ? t / std::max(0.001, holdRatio) : 1.0;
        double fastDrop =
            1.0 - (1.0 - holdRatio) * (1.0 - (1.0 - u) * (1.0 - u));
        if (t <= holdRatio) {
            return Clamp(fastDrop, 0.0, 1.0);
        }

        double tail = (t - holdRatio) / std::max(0.001, 1.0 - holdRatio);
        return Clamp(fastDrop * (1.0 - tail * tail * 0.42), 0.0, 1.0);
    };

    auto signedDistanceAt = [&](double px, double py) {
        double localX = px - centerX;
        double localY = py - centerY;
        double qx = std::abs(localX) - innerHalfWidth;
        double qy = std::abs(localY) - innerHalfHeight;
        double outsideX = std::max(qx, 0.0);
        double outsideY = std::max(qy, 0.0);
        // LiquidGlassKit models its boundary with a superellipse rather than
        // a circular rounded-rectangle SDF. Exponent 4 produces Apple's
        // continuous/squircle corner while 2 remains the classic circle.
        double exponent = static_cast<double>(g_settings.liquidGlassRoundness);
        double outsideLength = std::pow(
            std::pow(outsideX, exponent) + std::pow(outsideY, exponent),
            1.0 / exponent);
        double hardMax = std::max(qx, qy);
        double smoothness = Clamp(minD * 0.018, 2.8, 7.0);
        double innerTerm =
            hardMax < 0.0 ? smoothMax(qx, qy, smoothness) : hardMax;
        return outsideLength + std::min(innerTerm, 0.0) - radiusD;
    };

    auto profileAtDistance = [&](double distance) {
        if (distance < 0.0) {
            return 0.0;
        }

        double rim = 1.0 - smootherStep(distance / std::max(1.0, rimWidth));
        double shoulder =
            fastThenSlowQuadraticFalloff(distance, shoulderWidth, 0.36);
        double body = fastThenSlowQuadraticFalloff(distance, bodyWidth, 0.24);
        rim = std::pow(Clamp(rim, 0.0, 1.0), 0.58);
        shoulder = std::pow(Clamp(shoulder, 0.0, 1.0), 1.18);
        body = std::pow(Clamp(body, 0.0, 1.0), 3.35);
        return Clamp(rim * 0.72 + shoulder * 0.24 + body * 0.04, 0.0, 1.0);
    };

    for (int y = 0; y < height; ++y) {
        double fy = static_cast<double>(y) + 0.5;
        for (int x = 0; x < width; ++x) {
            double fx = static_cast<double>(x) + 0.5;
            double signedDistance = signedDistanceAt(fx, fy);
            double distance = -signedDistance;
            double offsetX = 0.0;
            double offsetY = 0.0;

            if (distance >= 0.0) {
                constexpr double kGradientStep = 0.75;
                double gradX = signedDistanceAt(fx + kGradientStep, fy) -
                               signedDistanceAt(fx - kGradientStep, fy);
                double gradY = signedDistanceAt(fx, fy + kGradientStep) -
                               signedDistanceAt(fx, fy - kGradientStep);
                double gradLength = std::sqrt(gradX * gradX + gradY * gradY);
                if (gradLength > 0.0001) {
                    double outwardX = gradX / gradLength;
                    double outwardY = gradY / gradLength;

                    // Match LiquidGlassKit's optical model: refract through
                    // the surface normal derived from the SDF, not along a
                    // tangential swirl around the edge.
                    double amount = profileAtDistance(distance);
                    offsetX = -outwardX * amount;
                    offsetY = -outwardY * amount;
                }
            }

            size_t index = (static_cast<size_t>(y) * width + x) * 4;
            pixels[index + 0] = 0x80;
            pixels[index + 1] = static_cast<BYTE>(
                Clamp(static_cast<int>(std::lround(128.0 + offsetY * 127.0)), 0,
                      255));
            pixels[index + 2] = static_cast<BYTE>(
                Clamp(static_cast<int>(std::lround(128.0 + offsetX * 127.0)), 0,
                      255));
            pixels[index + 3] = 0xFF;
        }
    }

    D2D1_BITMAP_PROPERTIES1 props = D2D1::BitmapProperties1(
        D2D1_BITMAP_OPTIONS_NONE,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE));
    winrt::com_ptr<ID2D1Bitmap1> map;
    HRESULT hr = g_popupOverlayWgcD2dContext->CreateBitmap(
        D2D1::SizeU(static_cast<UINT32>(width), static_cast<UINT32>(height)),
        pixels.data(), static_cast<UINT32>(width * 4), &props, map.put());
    if (FAILED(hr)) {
        g_popupOverlayWgcLastHr = hr;
        Wh_Log(L"Island: overlay WGC lens displacement map failed hr=0x%08X",
               static_cast<unsigned>(hr));
        ClearPopupOverlayWgcLensDisplacementMap();
        return false;
    }

    g_popupOverlayWgcLensDisplacementMap = std::move(map);
    g_popupOverlayWgcLensMapWidth = width;
    g_popupOverlayWgcLensMapHeight = height;
    g_popupOverlayWgcLensMapRadius = radius;
    g_popupOverlayWgcLensMapRoundness = g_settings.liquidGlassRoundness;
    return true;
}

bool DrawLiquidGlassGpuLensWarp(ID2D1DeviceContext* context,
                                ID2D1Image* blurredImage,
                                ID2D1Image* refractImage,
                                int width,
                                int height,
                                int radius,
                                float rimAlpha) {
    if (!context || !blurredImage || width <= 2 || height <= 2) {
        return false;
    }
    if (!refractImage) {
        refractImage = blurredImage;
    }

    float widthF = static_cast<float>(width);
    float heightF = static_cast<float>(height);
    D2D1_POINT_2F imageTargetOffset{0.0f, 0.0f};

    // Keep both Gaussian blurs inside one Direct2D effect graph. Direct2D can
    // schedule the complex sampling passes without us writing and reading two
    // additional full-size render targets every captured frame.
    context->DrawImage(blurredImage, &imageTargetOffset, nullptr,
                       D2D1_INTERPOLATION_MODE_LINEAR,
                       D2D1_COMPOSITE_MODE_SOURCE_OVER);

    if (radius <= 0) {
        radius = static_cast<int>(
            std::lround(std::min(std::min(widthF, heightF) * 0.17f, 36.0f)));
    }
    radius = Clamp(radius, 1, std::max(1, std::min(width, height) / 2));
    if (!EnsurePopupOverlayWgcLensDisplacementMap(width, height, radius)) {
        return true;
    }

    if (!g_popupOverlayWgcDisplacementEffect) {
        HRESULT createHr =
            context->CreateEffect(CLSID_D2D1DisplacementMap,
                                  g_popupOverlayWgcDisplacementEffect.put());
        if (FAILED(createHr) || !g_popupOverlayWgcDisplacementEffect) {
            return true;
        }
        g_popupOverlayWgcDisplacementEffect->SetValue(
            D2D1_DISPLACEMENTMAP_PROP_X_CHANNEL_SELECT,
            D2D1_CHANNEL_SELECTOR_R);
        g_popupOverlayWgcDisplacementEffect->SetValue(
            D2D1_DISPLACEMENTMAP_PROP_Y_CHANNEL_SELECT,
            D2D1_CHANNEL_SELECTOR_G);
    }

    g_popupOverlayWgcDisplacementEffect->SetInput(0, refractImage);
    g_popupOverlayWgcDisplacementEffect->SetInput(
        1, g_popupOverlayWgcLensDisplacementMap.get());

    float scale = static_cast<float>(Clamp(
        std::min(width, height) *
            (static_cast<double>(g_settings.liquidGlassRefraction) / 100.0),
        0.0, 64.0));
    HRESULT hr = g_popupOverlayWgcDisplacementEffect->SetValue(
        D2D1_DISPLACEMENTMAP_PROP_SCALE, scale);
    if (FAILED(hr)) {
        return true;
    }
    // Do not clip the displaced image into four rectangular edge bands. The
    // creates a visibly different "center rectangle" where only the base blur
    // is present. Instead, blend the full-field displacement over the base
    // glass. The displacement map is neutral in the interior, so the whole
    // surface shares one continuous lens field while the rim still pulls from
    // the lower-blur refractive source.
    D2D1_LAYER_PARAMETERS1 layerParams = D2D1::LayerParameters1(
        D2D1::InfiniteRect(), nullptr, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
        D2D1::IdentityMatrix(), 0.38f, nullptr, D2D1_LAYER_OPTIONS1_NONE);
    context->PushLayer(layerParams, nullptr);
    context->DrawImage(
        g_popupOverlayWgcDisplacementEffect.get(), &imageTargetOffset, nullptr,
        D2D1_INTERPOLATION_MODE_LINEAR, D2D1_COMPOSITE_MODE_SOURCE_OVER);
    context->PopLayer();

    float rimInset = 0.75f;
    float rimRadius = std::max(1.0f, static_cast<float>(radius) - rimInset);
    D2D1_ROUNDED_RECT rimRect = D2D1::RoundedRect(
        D2D1::RectF(rimInset, rimInset, widthF - rimInset, heightF - rimInset),
        rimRadius, rimRadius);
    rimAlpha = Clamp(rimAlpha, 0.0f, 1.0f);
    D2D1_COLOR_F rimColor = D2D1::ColorF(1.0f, 1.0f, 1.0f, rimAlpha);
    if (!g_popupOverlayWgcRimBrush) {
        context->CreateSolidColorBrush(rimColor,
                                       g_popupOverlayWgcRimBrush.put());
    } else {
        g_popupOverlayWgcRimBrush->SetColor(rimColor);
    }
    if (g_popupOverlayWgcRimBrush) {
        context->DrawRoundedRectangle(rimRect, g_popupOverlayWgcRimBrush.get(),
                                      1.25f);
    }

    return true;
}

void UpdatePopupOverlayDcompVisualTransformLocked(int widthPx,
                                                  int heightPx,
                                                  int radiusPx) {
    if (!g_popupOverlayDcompVisual) {
        return;
    }

    float scaleX = 1.0f;
    float scaleY = 1.0f;
    if (g_popupOverlayWgcTargetWidthPx > 0 &&
        g_popupOverlayWgcTargetHeightPx > 0 && widthPx > 0 && heightPx > 0) {
        scaleX = static_cast<float>(
            Clamp(static_cast<double>(widthPx) /
                      static_cast<double>(g_popupOverlayWgcTargetWidthPx),
                  0.01, 8.0));
        scaleY = static_cast<float>(
            Clamp(static_cast<double>(heightPx) /
                      static_cast<double>(g_popupOverlayWgcTargetHeightPx),
                  0.01, 8.0));
    }

    float radius = static_cast<float>(std::max(1, radiusPx));
    if (g_popupOverlayDcompTransformValid &&
        std::abs(scaleX - g_popupOverlayDcompLastScaleX) < 0.0005f &&
        std::abs(scaleY - g_popupOverlayDcompLastScaleY) < 0.0005f &&
        std::abs(radius - g_popupOverlayDcompLastRadius) < 0.25f) {
        return;
    }

    D2D_MATRIX_3X2_F transform = D2D1::Matrix3x2F::Scale(scaleX, scaleY);
    g_popupOverlayDcompVisual->SetTransform(transform);

    // Clip in pre-transform coordinates with independent X/Y radii. After the
    // anisotropic compact-to-expanded scale, both axes resolve to the same
    // on-screen radius. This preserves a true capsule at the compact end and a
    // continuous rounded rectangle at the expanded end.
    if (!g_popupOverlayDcompClip && g_popupOverlayDcompDevice) {
        if (SUCCEEDED(g_popupOverlayDcompDevice->CreateRectangleClip(
                g_popupOverlayDcompClip.put())) &&
            g_popupOverlayDcompClip) {
            g_popupOverlayDcompVisual->SetClip(g_popupOverlayDcompClip.get());
        }
    }
    if (g_popupOverlayDcompClip && g_popupOverlayWgcTargetWidthPx > 0 &&
        g_popupOverlayWgcTargetHeightPx > 0) {
        float radiusX =
            std::min(static_cast<float>(g_popupOverlayWgcTargetWidthPx) * 0.5f,
                     radius / std::max(scaleX, 0.01f));
        float radiusY =
            std::min(static_cast<float>(g_popupOverlayWgcTargetHeightPx) * 0.5f,
                     radius / std::max(scaleY, 0.01f));
        g_popupOverlayDcompClip->SetLeft(0.0f);
        g_popupOverlayDcompClip->SetTop(0.0f);
        g_popupOverlayDcompClip->SetRight(
            static_cast<float>(g_popupOverlayWgcTargetWidthPx));
        g_popupOverlayDcompClip->SetBottom(
            static_cast<float>(g_popupOverlayWgcTargetHeightPx));
        g_popupOverlayDcompClip->SetTopLeftRadiusX(radiusX);
        g_popupOverlayDcompClip->SetTopLeftRadiusY(radiusY);
        g_popupOverlayDcompClip->SetTopRightRadiusX(radiusX);
        g_popupOverlayDcompClip->SetTopRightRadiusY(radiusY);
        g_popupOverlayDcompClip->SetBottomLeftRadiusX(radiusX);
        g_popupOverlayDcompClip->SetBottomLeftRadiusY(radiusY);
        g_popupOverlayDcompClip->SetBottomRightRadiusX(radiusX);
        g_popupOverlayDcompClip->SetBottomRightRadiusY(radiusY);
    }
    g_popupOverlayDcompTransformValid = true;
    g_popupOverlayDcompLastScaleX = scaleX;
    g_popupOverlayDcompLastScaleY = scaleY;
    g_popupOverlayDcompLastRadius = radius;
    if (g_popupOverlayDcompDevice) {
        g_popupOverlayDcompDevice->Commit();
    }
}

void UpdatePopupOverlayDcompVisualTransform(int widthPx,
                                            int heightPx,
                                            int radiusPx) {
    // Callstack's native glass keeps one effect object alive and only updates
    // its properties. Mirror that model here: the UI thread publishes the
    // newest geometry without waiting for the WGC render lock. Intermediate
    // values may coalesce, but the latest radius can never be lost.
    g_popupOverlayDcompPendingWidth.store(widthPx, std::memory_order_relaxed);
    g_popupOverlayDcompPendingHeight.store(heightPx, std::memory_order_relaxed);
    g_popupOverlayDcompPendingRadius.store(radiusPx, std::memory_order_relaxed);
    g_popupOverlayDcompGeometryDirty.store(true, std::memory_order_release);
}

void SetPopupOverlayDcompContentOpacity(float opacity) {
    opacity = static_cast<float>(Clamp(static_cast<double>(opacity), 0.0, 1.0));
    int opacityMilli = static_cast<int>(std::lround(opacity * 1000.0f));
    if (g_popupOverlayDcompOpacityMilli.load(std::memory_order_acquire) ==
        opacityMilli) {
        return;
    }
    std::lock_guard lock(g_popupOverlayWgcMutex);
    if (!g_popupOverlayDcompVisual || !g_popupOverlayDcompDevice ||
        !g_popupOverlayDcompOpacityEffect) {
        return;
    }
    g_popupOverlayDcompOpacityEffect->SetOpacity(opacity);
    g_popupOverlayDcompDevice->Commit();
    g_popupOverlayDcompOpacityMilli.store(opacityMilli,
                                          std::memory_order_release);
}

bool RecreatePopupOverlayWgcReadbackTextures(int widthPx, int heightPx) {
    if (!g_popupOverlayWgcD3dDevice || !g_popupOverlayWgcDxgiDevice ||
        !g_popupOverlayWgcD2dContext || !g_popupBackdropOverlay ||
        widthPx <= 0 || heightPx <= 0) {
        return false;
    }

    if (g_popupOverlayWgcSwapChain && g_popupOverlayWgcSwapChainTargetBitmap &&
        g_popupOverlayWgcTargetWidthPx == widthPx &&
        g_popupOverlayWgcTargetHeightPx == heightPx) {
        return true;
    }

    // WGC capture, blur, rounded masking, and DirectComposition presentation
    // stay on the GPU without CPU readback or UpdateLayeredWindow.
    g_popupOverlayWgcSwapChainTargetBitmap = nullptr;
    g_popupOverlayWgcSwapChain = nullptr;
    g_popupOverlayDcompContentAttached = false;
    ClearPopupOverlayWgcRenderCache();
    ClearPopupOverlayWgcLensDisplacementMap();

    if (!g_popupOverlayDcompDevice) {
        HRESULT hr = DCompositionCreateDevice(
            g_popupOverlayWgcDxgiDevice.get(), __uuidof(IDCompositionDevice),
            g_popupOverlayDcompDevice.put_void());
        if (FAILED(hr)) {
            Wh_Log(L"Island: overlay DComp device failed hr=0x%08X",
                   static_cast<unsigned>(hr));
            g_popupOverlayWgcLastHr = hr;
            return false;
        }
    }

    if (!g_popupOverlayDcompTarget) {
        HRESULT hr = g_popupOverlayDcompDevice->CreateTargetForHwnd(
            g_popupBackdropOverlay, TRUE, g_popupOverlayDcompTarget.put());
        if (FAILED(hr)) {
            Wh_Log(L"Island: overlay DComp target failed hr=0x%08X",
                   static_cast<unsigned>(hr));
            g_popupOverlayWgcLastHr = hr;
            return false;
        }
    }

    if (!g_popupOverlayDcompVisual) {
        HRESULT hr = g_popupOverlayDcompDevice->CreateVisual(
            g_popupOverlayDcompVisual.put());
        if (FAILED(hr)) {
            Wh_Log(L"Island: overlay DComp visual failed hr=0x%08X",
                   static_cast<unsigned>(hr));
            g_popupOverlayWgcLastHr = hr;
            return false;
        }
        g_popupOverlayDcompTarget->SetRoot(g_popupOverlayDcompVisual.get());
        g_popupOverlayDcompOpacityMilli.store(-1, std::memory_order_release);
    }
    if (!g_popupOverlayDcompOpacityEffect) {
        HRESULT hr = g_popupOverlayDcompDevice->CreateEffectGroup(
            g_popupOverlayDcompOpacityEffect.put());
        if (FAILED(hr) || !g_popupOverlayDcompOpacityEffect) {
            g_popupOverlayWgcLastHr = hr;
            return false;
        }
        g_popupOverlayDcompVisual->SetEffect(
            g_popupOverlayDcompOpacityEffect.get());
        g_popupOverlayDcompOpacityMilli.store(-1, std::memory_order_release);
    }

    winrt::com_ptr<IDXGIAdapter> adapter;
    HRESULT hr = g_popupOverlayWgcDxgiDevice->GetAdapter(adapter.put());
    if (FAILED(hr)) {
        g_popupOverlayWgcLastHr = hr;
        return false;
    }
    winrt::com_ptr<IDXGIFactory2> factory;
    hr = adapter->GetParent(__uuidof(IDXGIFactory2), factory.put_void());
    if (FAILED(hr)) {
        g_popupOverlayWgcLastHr = hr;
        return false;
    }

    DXGI_SWAP_CHAIN_DESC1 desc{};
    desc.Width = static_cast<UINT>(widthPx);
    desc.Height = static_cast<UINT>(heightPx);
    desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    desc.Stereo = FALSE;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.BufferCount = 2;
    desc.Scaling = DXGI_SCALING_STRETCH;
    desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
    desc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
    desc.Flags = 0;

    winrt::com_ptr<IDXGISwapChain1> swapChain;
    hr = factory->CreateSwapChainForComposition(
        g_popupOverlayWgcD3dDevice.get(), &desc, nullptr, swapChain.put());
    if (FAILED(hr)) {
        Wh_Log(L"Island: overlay DComp swapchain failed hr=0x%08X",
               static_cast<unsigned>(hr));
        g_popupOverlayWgcLastHr = hr;
        return false;
    }

    winrt::com_ptr<IDXGISurface> backBufferSurface;
    hr = swapChain->GetBuffer(0, __uuidof(IDXGISurface),
                              backBufferSurface.put_void());
    if (FAILED(hr)) {
        g_popupOverlayWgcLastHr = hr;
        return false;
    }

    D2D1_BITMAP_PROPERTIES1 targetProps = D2D1::BitmapProperties1(
        D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM,
                          D2D1_ALPHA_MODE_PREMULTIPLIED));
    winrt::com_ptr<ID2D1Bitmap1> targetBitmap;
    hr = g_popupOverlayWgcD2dContext->CreateBitmapFromDxgiSurface(
        backBufferSurface.get(), &targetProps, targetBitmap.put());
    if (FAILED(hr)) {
        Wh_Log(L"Island: overlay DComp target bitmap failed hr=0x%08X",
               static_cast<unsigned>(hr));
        g_popupOverlayWgcLastHr = hr;
        return false;
    }
    g_popupOverlayDcompContentAttached = false;

    g_popupOverlayWgcSwapChain = std::move(swapChain);
    g_popupOverlayWgcSwapChainTargetBitmap = std::move(targetBitmap);
    g_popupOverlayWgcTargetWidthPx = widthPx;
    g_popupOverlayWgcTargetHeightPx = heightPx;
    g_popupOverlayWgcLastHr = S_OK;
    return true;
}
bool EnsurePopupOverlayWgcDeviceResourcesLocked(HWND hwnd,
                                                int widthPx,
                                                int heightPx) {
    if (!UseOverlayPopupBackdropMaterial() || !hwnd || widthPx <= 0 ||
        heightPx <= 0) {
        return false;
    }

    if (g_popupOverlayWgcD3dDevice && g_popupOverlayWgcSwapChain &&
        g_popupOverlayWgcSwapChainTargetBitmap &&
        g_popupOverlayWgcTargetWidthPx == widthPx &&
        g_popupOverlayWgcTargetHeightPx == heightPx) {
        return true;
    }

    g_popupOverlayWgcSession = nullptr;
    if (g_popupOverlayWgcFramePool && g_popupOverlayWgcFrameCallbackHooked) {
        try {
            g_popupOverlayWgcFramePool.FrameArrived(
                g_popupOverlayWgcFrameArrivedToken);
        } catch (...) {
        }
        g_popupOverlayWgcFrameCallbackHooked = false;
    }
    g_popupOverlayWgcFramePool = nullptr;
    g_popupOverlayWgcItem = nullptr;
    g_popupOverlayWgcGraphicsDevice = nullptr;
    g_popupOverlayWgcSwapChainTargetBitmap = nullptr;
    g_popupOverlayWgcSwapChain = nullptr;
    g_popupOverlayDcompContentAttached = false;
    if (g_popupOverlayDcompVisual) {
        g_popupOverlayDcompVisual->SetContent(nullptr);
    }
    if (g_popupOverlayDcompTarget) {
        g_popupOverlayDcompTarget->SetRoot(nullptr);
    }
    if (g_popupOverlayDcompDevice) {
        g_popupOverlayDcompDevice->Commit();
    }
    g_popupOverlayDcompVisual = nullptr;
    g_popupOverlayDcompOpacityEffect = nullptr;
    g_popupOverlayDcompClip = nullptr;
    g_popupOverlayDcompTransformValid = false;
    g_popupOverlayDcompLastScaleX = 0.0f;
    g_popupOverlayDcompLastScaleY = 0.0f;
    g_popupOverlayDcompLastRadius = -1.0f;
    g_popupOverlayDcompTarget = nullptr;
    g_popupOverlayDcompDevice = nullptr;
    ClearPopupOverlayWgcRenderCache();
    ClearPopupOverlayWgcLensDisplacementMap();
    g_popupOverlayWgcD2dContext = nullptr;
    g_popupOverlayWgcD2dDevice = nullptr;
    g_popupOverlayWgcD2dFactory = nullptr;
    g_popupOverlayWgcDxgiDevice = nullptr;
    g_popupOverlayWgcD3dContext = nullptr;
    g_popupOverlayWgcD3dDevice = nullptr;

    UINT deviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    D3D_FEATURE_LEVEL selectedFeatureLevel{};
    HRESULT hr = D3D11CreateDevice(
        nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, deviceFlags, featureLevels,
        ARRAYSIZE(featureLevels), D3D11_SDK_VERSION,
        g_popupOverlayWgcD3dDevice.put(), &selectedFeatureLevel,
        g_popupOverlayWgcD3dContext.put());
    if (FAILED(hr)) {
        hr = D3D11CreateDevice(
            nullptr, D3D_DRIVER_TYPE_WARP, nullptr, deviceFlags, featureLevels,
            ARRAYSIZE(featureLevels), D3D11_SDK_VERSION,
            g_popupOverlayWgcD3dDevice.put(), &selectedFeatureLevel,
            g_popupOverlayWgcD3dContext.put());
    }
    if (FAILED(hr)) {
        Wh_Log(L"Island: overlay WGC D3D11CreateDevice failed hr=0x%08X",
               static_cast<unsigned>(hr));
        return false;
    }

    g_popupOverlayWgcDxgiDevice = g_popupOverlayWgcD3dDevice.as<IDXGIDevice>();

    D2D1_FACTORY_OPTIONS factoryOptions{};
    hr = D2D1CreateFactory(
        D2D1_FACTORY_TYPE_MULTI_THREADED, __uuidof(ID2D1Factory1),
        &factoryOptions,
        reinterpret_cast<void**>(g_popupOverlayWgcD2dFactory.put()));
    if (FAILED(hr)) {
        Wh_Log(L"Island: overlay WGC D2D factory failed hr=0x%08X",
               static_cast<unsigned>(hr));
        return false;
    }
    hr = g_popupOverlayWgcD2dFactory->CreateDevice(
        g_popupOverlayWgcDxgiDevice.get(), g_popupOverlayWgcD2dDevice.put());
    if (FAILED(hr)) {
        Wh_Log(L"Island: overlay WGC D2D device failed hr=0x%08X",
               static_cast<unsigned>(hr));
        return false;
    }
    hr = g_popupOverlayWgcD2dDevice->CreateDeviceContext(
        D2D1_DEVICE_CONTEXT_OPTIONS_NONE, g_popupOverlayWgcD2dContext.put());
    if (FAILED(hr)) {
        Wh_Log(L"Island: overlay WGC D2D context failed hr=0x%08X",
               static_cast<unsigned>(hr));
        return false;
    }

    winrt::com_ptr<IInspectable> graphicsDeviceInspectable;
    hr = CreateDirect3D11DeviceFromDXGIDevice(g_popupOverlayWgcDxgiDevice.get(),
                                              graphicsDeviceInspectable.put());
    if (FAILED(hr)) {
        Wh_Log(
            L"Island: overlay WGC CreateDirect3D11DeviceFromDXGIDevice failed "
            L"hr=0x%08X",
            static_cast<unsigned>(hr));
        return false;
    }
    g_popupOverlayWgcGraphicsDevice =
        graphicsDeviceInspectable.as<direct3d11::IDirect3DDevice>();

    winrt::com_ptr<IDXGIAdapter> adapter;
    hr = g_popupOverlayWgcDxgiDevice->GetAdapter(adapter.put());
    if (FAILED(hr)) {
        return false;
    }
    winrt::com_ptr<IDXGIFactory2> factory;
    hr = adapter->GetParent(__uuidof(IDXGIFactory2), factory.put_void());
    if (FAILED(hr)) {
        return false;
    }

    return RecreatePopupOverlayWgcReadbackTextures(widthPx, heightPx);
}

double PopupOverlayWgcFrameIntervalMsForMonitor(HMONITOR monitor) {
    constexpr double kDefaultRefreshHz = 60.0;
    double refreshHz = kDefaultRefreshHz;

    MONITORINFOEXW monitorInfo{};
    monitorInfo.cbSize = sizeof(monitorInfo);
    if (monitor && GetMonitorInfoW(monitor, &monitorInfo)) {
        DEVMODEW devMode{};
        devMode.dmSize = sizeof(devMode);
        if (EnumDisplaySettingsW(monitorInfo.szDevice, ENUM_CURRENT_SETTINGS,
                                 &devMode) &&
            devMode.dmDisplayFrequency > 1 &&
            devMode.dmDisplayFrequency < 1000) {
            refreshHz = static_cast<double>(devMode.dmDisplayFrequency);
        }
    }

    // Match the monitor cadence while keeping a conservative floor for VRR or
    // drivers that report unusually high transient values.
    return Clamp(1000.0 / refreshHz, 1000.0 / 360.0, 1000.0 / 50.0);
}

bool PopupOverlayWgcBorderlessAccessAllowed() {
    return g_popupOverlayWgcBorderlessAccessState.load(
               std::memory_order_acquire) == 2;
}

bool PopupOverlayWgcBorderlessAccessPending() {
    int state =
        g_popupOverlayWgcBorderlessAccessState.load(std::memory_order_acquire);
    return state == 0 || state == 1;
}

void RequestPopupOverlayWgcBorderlessAccessAsync() {
    int expected = 0;
    if (!g_popupOverlayWgcBorderlessAccessState.compare_exchange_strong(
            expected, 1, std::memory_order_acq_rel)) {
        return;
    }

    std::lock_guard threadLock(g_popupOverlayWgcBorderlessAccessThreadMutex);
    if (g_unloading.load()) {
        g_popupOverlayWgcBorderlessAccessState.store(4,
                                                     std::memory_order_release);
        return;
    }

    try {
        g_popupOverlayWgcBorderlessAccessThread = new std::thread([]() {
            try {
                auto operation =
                    capture::GraphicsCaptureAccess::RequestAccessAsync(
                        capture::GraphicsCaptureAccessKind::Borderless);
                auto status = GetAsyncResultWithTimeout(
                    operation, kPopupOverlayWgcBorderlessAccessTimeout,
                    L"WGC borderless access");
                bool allowed =
                    status ==
                    winrt::Windows::Security::Authorization::
                        AppCapabilityAccess::AppCapabilityAccessStatus::Allowed;
                g_popupOverlayWgcBorderlessAccessState.store(
                    allowed ? 2 : 3, std::memory_order_release);
                if (allowed) {
                    std::lock_guard lock(g_popupOverlayWgcMutex);
                    if (g_popupOverlayWgcSession) {
                        try {
                            g_popupOverlayWgcSession.IsBorderRequired(false);
                        } catch (...) {
                        }
                    }
                }
                Wh_Log(L"Island: overlay WGC borderless access %s",
                       allowed ? L"allowed" : L"denied");
            } catch (winrt::hresult_error const& error) {
                g_popupOverlayWgcBorderlessAccessState.store(
                    4, std::memory_order_release);
                Wh_Log(
                    L"Island: overlay WGC borderless access failed hr=0x%08X",
                    static_cast<unsigned>(error.code().value));
            } catch (...) {
                g_popupOverlayWgcBorderlessAccessState.store(
                    4, std::memory_order_release);
                Wh_Log(L"Island: overlay WGC borderless access failed unknown");
            }
        });
    } catch (...) {
        g_popupOverlayWgcBorderlessAccessState.store(4,
                                                     std::memory_order_release);
        g_popupOverlayWgcBorderlessAccessThread = nullptr;
        Wh_Log(L"Island: failed to start overlay WGC access thread");
    }
}

void StopPopupOverlayWgcBorderlessAccessThread() {
    std::thread* thread = nullptr;
    {
        std::lock_guard threadLock(
            g_popupOverlayWgcBorderlessAccessThreadMutex);
        thread = g_popupOverlayWgcBorderlessAccessThread;
        g_popupOverlayWgcBorderlessAccessThread = nullptr;
    }

    if (!thread) {
        return;
    }

    if (thread->joinable()) {
        thread->join();
    }
    delete thread;
}

bool PopupOverlayWgcDirtyRegionsSupported() {
    try {
        return winrt::Windows::Foundation::Metadata::ApiInformation::
            IsPropertyPresent(
                L"Windows.Graphics.Capture.GraphicsCaptureSession",
                L"DirtyRegionMode");
    } catch (...) {
        return false;
    }
}

bool PopupOverlayWgcFrameTouchesCapture(
    capture::Direct3D11CaptureFrame const& frame,
    RECT const& captureRect,
    RECT const& monitorRect,
    bool morphing) {
    if (morphing || !g_popupOverlayWgcReadbackHadVisibleFrame ||
        !g_popupOverlayWgcDirtyRegionsEnabled.load(std::memory_order_acquire)) {
        return true;
    }

    try {
        if (frame.DirtyRegionMode() !=
            capture::GraphicsCaptureDirtyRegionMode::ReportAndRender) {
            return true;
        }

        RECT localCaptureRect{captureRect.left - monitorRect.left,
                              captureRect.top - monitorRect.top,
                              captureRect.right - monitorRect.left,
                              captureRect.bottom - monitorRect.top};
        for (auto const& dirtyRegion : frame.DirtyRegions()) {
            RECT dirtyRect{dirtyRegion.X, dirtyRegion.Y,
                           dirtyRegion.X + dirtyRegion.Width,
                           dirtyRegion.Y + dirtyRegion.Height};
            RECT intersection{};
            if (IntersectRect(&intersection, &localCaptureRect, &dirtyRect)) {
                return true;
            }
        }
        return false;
    } catch (...) {
        g_popupOverlayWgcDirtyRegionsEnabled.store(false,
                                                   std::memory_order_release);
        return true;
    }
}
void RenderPopupOverlayWgcFrameLocked(
    capture::Direct3D11CaptureFrame const& frame) {
    g_popupOverlayWgcHadFrame = true;
    ++g_popupOverlayWgcFrameCount;
    g_popupOverlayWgcDiagnosticState =
        PopupOverlayWgcDiagnosticState::FrameArrived;
    if (!g_popupOverlayWgcRunning || !frame || !g_popupOverlayWgcD2dContext ||
        !g_popupOverlayWgcSwapChain ||
        !g_popupOverlayWgcSwapChainTargetBitmap) {
        return;
    }

    if (g_popupOverlayDcompGeometryDirty.exchange(false,
                                                  std::memory_order_acq_rel)) {
        UpdatePopupOverlayDcompVisualTransformLocked(
            g_popupOverlayDcompPendingWidth.load(std::memory_order_relaxed),
            g_popupOverlayDcompPendingHeight.load(std::memory_order_relaxed),
            g_popupOverlayDcompPendingRadius.load(std::memory_order_relaxed));
    }

    PopupOverlayWgcRenderParameters renderParameters =
        g_popupOverlayWgcRenderParameters;
    RECT captureRect = g_popupOverlayWgcCaptureRectPx;
    RECT monitorRect = g_popupOverlayWgcMonitorRectPx;
    int targetWidth = g_popupOverlayWgcTargetWidthPx;
    int targetHeight = g_popupOverlayWgcTargetHeightPx;
    uint64_t renderGeometryGeneration =
        g_popupOverlayWgcGeometryGeneration.load(std::memory_order_acquire);
    if (targetWidth <= 0 || targetHeight <= 0 ||
        captureRect.right <= captureRect.left ||
        captureRect.bottom <= captureRect.top) {
        return;
    }

    bool morphing = renderParameters.morphing;
    if (!PopupOverlayWgcFrameTouchesCapture(frame, captureRect, monitorRect,
                                            morphing)) {
        return;
    }

    {
        auto now = std::chrono::steady_clock::now();
        // WGC normally follows the monitor compositor cadence. Keep only a
        // small jitter guard so 120/144/165/240 Hz displays stay synchronized
        // with the XAML morph instead of being capped to 60 Hz.
        double targetIntervalMs = Clamp(g_popupOverlayWgcFrameIntervalMs,
                                        1000.0 / 360.0, 1000.0 / 50.0);
        double guardIntervalMs = targetIntervalMs * 0.72;
        if (g_popupOverlayWgcLastRenderTime.time_since_epoch().count() != 0) {
            double elapsedMs = std::chrono::duration<double, std::milli>(
                                   now - g_popupOverlayWgcLastRenderTime)
                                   .count();
            if (elapsedMs < guardIntervalMs) {
                return;
            }
        }
        g_popupOverlayWgcLastRenderTime = now;
    }

    if (g_popupOverlayWgcFramesToSkip > 0) {
        --g_popupOverlayWgcFramesToSkip;
        return;
    }

    std::vector<BYTE> recordingCleanPixels;
    bool useRecordingCleanBackdrop = false;
    if (renderParameters.allowScreenCapture &&
        renderParameters.useLiquidLensWarp) {
        std::lock_guard cacheLock(g_popupBackdropOverlayHandoffMutex);
        if (g_popupBackdropOverlayCleanPixelsValid &&
            g_popupBackdropOverlayCleanWidth == targetWidth &&
            g_popupBackdropOverlayCleanHeight == targetHeight &&
            g_popupBackdropOverlayCleanPixels.size() ==
                static_cast<size_t>(targetWidth) * targetHeight * 4) {
            recordingCleanPixels = g_popupBackdropOverlayCleanPixels;
            useRecordingCleanBackdrop = true;
        }
    }

    try {
        auto surface = frame.Surface();
        winrt::com_ptr<IDirect3DDxgiInterfaceAccess> access;
        winrt::check_hresult(
            reinterpret_cast<IUnknown*>(winrt::get_abi(surface))
                ->QueryInterface(kIID_IDirect3DDxgiInterfaceAccess,
                                 access.put_void()));
        winrt::com_ptr<ID3D11Texture2D> frameTexture;
        winrt::check_hresult(access->GetInterface(__uuidof(ID3D11Texture2D),
                                                  frameTexture.put_void()));
        winrt::com_ptr<IDXGISurface> frameSurface;
        frameTexture.as(frameSurface);

        ID2D1Bitmap1* targetBitmap =
            g_popupOverlayWgcSwapChainTargetBitmap.get();

        D2D1_BITMAP_PROPERTIES1 sourceProps = D2D1::BitmapProperties1(
            D2D1_BITMAP_OPTIONS_NONE,
            D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM,
                              D2D1_ALPHA_MODE_IGNORE));
        winrt::com_ptr<ID2D1Bitmap1> sourceBitmap;
        winrt::check_hresult(
            g_popupOverlayWgcD2dContext->CreateBitmapFromDxgiSurface(
                frameSurface.get(), &sourceProps, sourceBitmap.put()));

        float srcLeft = static_cast<float>(captureRect.left - monitorRect.left);
        float srcTop = static_cast<float>(captureRect.top - monitorRect.top);
        float srcRight =
            static_cast<float>(captureRect.right - monitorRect.left);
        float srcBottom =
            static_cast<float>(captureRect.bottom - monitorRect.top);
        D2D1_RECT_F sourceRect =
            D2D1::RectF(srcLeft, srcTop, srcRight, srcBottom);
        D2D1_RECT_F targetRect =
            D2D1::RectF(0.0f, 0.0f, static_cast<float>(targetWidth),
                        static_cast<float>(targetHeight));

        int cornerRadiusPx = renderParameters.targetRadiusPx;
        cornerRadiusPx =
            Clamp(cornerRadiusPx, 1,
                  std::max(1, std::min(targetWidth, targetHeight) / 2));

        winrt::com_ptr<ID2D1Bitmap1> recordingCleanBitmap;
        winrt::com_ptr<ID2D1RoundedRectangleGeometry>
            recordingCleanMaskGeometry;
        if (useRecordingCleanBackdrop) {
            winrt::check_hresult(g_popupOverlayWgcD2dContext->CreateBitmap(
                D2D1::SizeU(static_cast<UINT32>(targetWidth),
                            static_cast<UINT32>(targetHeight)),
                recordingCleanPixels.data(),
                static_cast<UINT32>(targetWidth * 4), &sourceProps,
                recordingCleanBitmap.put()));

            D2D1_ROUNDED_RECT cleanMaskRect = D2D1::RoundedRect(
                targetRect, static_cast<float>(cornerRadiusPx),
                static_cast<float>(cornerRadiusPx));
            winrt::check_hresult(
                g_popupOverlayWgcD2dFactory->CreateRoundedRectangleGeometry(
                    &cleanMaskRect, recordingCleanMaskGeometry.put()));
        }
        bool useLiquidLensWarp = renderParameters.useLiquidLensWarp;
        D2D1_BITMAP_PROPERTIES1 intermediateProps = D2D1::BitmapProperties1(
            D2D1_BITMAP_OPTIONS_TARGET,
            D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM,
                              D2D1_ALPHA_MODE_IGNORE));
        if (!EnsurePopupOverlayWgcRenderCache(targetWidth, targetHeight,
                                              intermediateProps,
                                              useLiquidLensWarp)) {
            g_popupOverlayWgcDiagnosticHr = g_popupOverlayWgcLastHr;
            g_popupOverlayWgcDiagnosticState =
                PopupOverlayWgcDiagnosticState::RenderFailed;
            ++g_popupOverlayWgcRenderFailCount;
            return;
        }
        auto& intermediateBitmap = g_popupOverlayWgcIntermediateBitmap;

        // Step 1: crop/scale the monitor capture into an offscreen target-sized
        // bitmap. This keeps the later Gaussian blur independent of monitor
        // resolution and avoids trying to draw the full monitor-sized effect.
        g_popupOverlayWgcD2dContext->SetTarget(intermediateBitmap.get());
        g_popupOverlayWgcD2dContext->BeginDraw();
        g_popupOverlayWgcD2dContext->Clear(
            D2D1::ColorF(0.0f, 0.0f, 0.0f, 1.0f));
        g_popupOverlayWgcD2dContext->DrawBitmap(
            sourceBitmap.get(), targetRect, 1.0f,
            D2D1_INTERPOLATION_MODE_LINEAR, sourceRect);
        if (recordingCleanBitmap && recordingCleanMaskGeometry) {
            D2D1_LAYER_PARAMETERS1 cleanLayerParams = D2D1::LayerParameters1(
                targetRect, recordingCleanMaskGeometry.get(),
                D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, D2D1::IdentityMatrix(), 1.0f,
                nullptr, D2D1_LAYER_OPTIONS1_NONE);
            g_popupOverlayWgcD2dContext->PushLayer(cleanLayerParams, nullptr);
            g_popupOverlayWgcD2dContext->DrawBitmap(
                recordingCleanBitmap.get(), targetRect, 1.0f,
                D2D1_INTERPOLATION_MODE_LINEAR);
            g_popupOverlayWgcD2dContext->PopLayer();
        }
        HRESULT hr = g_popupOverlayWgcD2dContext->EndDraw();
        if (FAILED(hr)) {
            g_popupOverlayWgcLastHr = hr;
            g_popupOverlayWgcDiagnosticHr = hr;
            g_popupOverlayWgcDiagnosticState =
                PopupOverlayWgcDiagnosticState::RenderFailed;
            ++g_popupOverlayWgcRenderFailCount;
            Wh_Log(
                L"Island: overlay WGC state intermediate EndDraw failed "
                L"hr=0x%08X frames=%llu fails=%llu",
                static_cast<unsigned>(hr),
                static_cast<unsigned long long>(g_popupOverlayWgcFrameCount),
                static_cast<unsigned long long>(
                    g_popupOverlayWgcRenderFailCount));
            return;
        }

        // Keep the blur outputs as a Direct2D effect graph and evaluate them
        // directly into the final swapchain target. This preserves the exact
        // blur and refraction parameters while removing two full-size
        // render-target clears, writes, reads, and EndDraw submissions.
        g_popupOverlayWgcBlurEffect->SetInput(0, intermediateBitmap.get());
        g_popupOverlayWgcBlurEffect->SetValue(
            D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION,
            renderParameters.blurStdDev);
        winrt::com_ptr<ID2D1Image> blurredImage;
        g_popupOverlayWgcBlurEffect->GetOutput(blurredImage.put());
        if (!blurredImage) {
            g_popupOverlayWgcLastHr = E_FAIL;
            g_popupOverlayWgcDiagnosticHr = E_FAIL;
            g_popupOverlayWgcDiagnosticState =
                PopupOverlayWgcDiagnosticState::RenderFailed;
            ++g_popupOverlayWgcRenderFailCount;
            return;
        }

        winrt::com_ptr<ID2D1Image> refractionEffectOutput;
        ID2D1Image* refractionImage = intermediateBitmap.get();
        if (useLiquidLensWarp) {
            g_popupOverlayWgcRefractionBlurEffect->SetInput(
                0, intermediateBitmap.get());
            g_popupOverlayWgcRefractionBlurEffect->SetValue(
                D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION,
                renderParameters.refractionBlurStdDev);
            g_popupOverlayWgcRefractionBlurEffect->GetOutput(
                refractionEffectOutput.put());
            if (refractionEffectOutput) {
                refractionImage = refractionEffectOutput.get();
            }
        }

        D2D1_POINT_2F imageTargetOffset = D2D1::Point2F(0.0f, 0.0f);
        ID2D1Image* renderImage = blurredImage.get();
        if (!useLiquidLensWarp) {
            ClearPopupOverlayWgcLensDisplacementMap();
        }
        // Step 2: render the final rounded premultiplied surface directly into
        // the DirectComposition swapchain backbuffer. Capture, blur, clipping,
        // alpha and present now stay on the GPU.
        BYTE maxAlpha = static_cast<BYTE>(Clamp(
            g_popupBackdropOverlayFrameAlpha.load(std::memory_order_relaxed), 0,
            255));
        double layerOpacity = static_cast<double>(maxAlpha) / 255.0;
        ID2D1RoundedRectangleGeometry* roundedGeometry =
            EnsurePopupOverlayWgcRoundedGeometry(targetRect, targetWidth,
                                                 targetHeight, cornerRadiusPx);
        if (!roundedGeometry) {
            g_popupOverlayWgcDiagnosticHr = g_popupOverlayWgcLastHr;
            g_popupOverlayWgcDiagnosticState =
                PopupOverlayWgcDiagnosticState::RenderFailed;
            ++g_popupOverlayWgcRenderFailCount;
            return;
        }

        g_popupOverlayWgcD2dContext->SetTarget(targetBitmap);
        g_popupOverlayWgcD2dContext->BeginDraw();
        g_popupOverlayWgcD2dContext->Clear(
            D2D1::ColorF(0.0f, 0.0f, 0.0f, 0.0f));
        D2D1_LAYER_PARAMETERS1 layerParams = D2D1::LayerParameters1(
            targetRect, roundedGeometry, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
            D2D1::IdentityMatrix(), static_cast<float>(layerOpacity), nullptr,
            D2D1_LAYER_OPTIONS1_NONE);
        g_popupOverlayWgcD2dContext->PushLayer(layerParams, nullptr);
        bool drewGpuLens =
            useLiquidLensWarp &&
            DrawLiquidGlassGpuLensWarp(
                g_popupOverlayWgcD2dContext.get(), blurredImage.get(),
                refractionImage, targetWidth, targetHeight, cornerRadiusPx,
                renderParameters.liquidRimAlpha);
        if (!drewGpuLens) {
            g_popupOverlayWgcD2dContext->DrawImage(
                renderImage, &imageTargetOffset, nullptr,
                D2D1_INTERPOLATION_MODE_LINEAR,
                D2D1_COMPOSITE_MODE_SOURCE_COPY);
        }
        g_popupOverlayWgcD2dContext->PopLayer();
        hr = g_popupOverlayWgcD2dContext->EndDraw();
        if (FAILED(hr)) {
            g_popupOverlayWgcLastHr = hr;
            g_popupOverlayWgcDiagnosticHr = hr;
            g_popupOverlayWgcDiagnosticState =
                PopupOverlayWgcDiagnosticState::RenderFailed;
            ++g_popupOverlayWgcRenderFailCount;
            Wh_Log(
                L"Island: overlay WGC state EndDraw failed hr=0x%08X "
                L"frames=%llu fails=%llu",
                static_cast<unsigned>(hr),
                static_cast<unsigned long long>(g_popupOverlayWgcFrameCount),
                static_cast<unsigned long long>(
                    g_popupOverlayWgcRenderFailCount));
            return;
        }

        hr = g_popupOverlayWgcSwapChain->Present(0, 0);
        if (FAILED(hr)) {
            g_popupOverlayWgcLastHr = hr;
            g_popupOverlayWgcDiagnosticHr = hr;
            g_popupOverlayWgcDiagnosticState =
                PopupOverlayWgcDiagnosticState::UpdateFailed;
            ++g_popupOverlayWgcRenderFailCount;
            Wh_Log(
                L"Island: overlay WGC swapchain Present failed hr=0x%08X "
                L"frames=%llu fails=%llu",
                static_cast<unsigned>(hr),
                static_cast<unsigned long long>(g_popupOverlayWgcFrameCount),
                static_cast<unsigned long long>(
                    g_popupOverlayWgcRenderFailCount));
            return;
        }
        g_popupOverlayWgcPresentedSerial.fetch_add(1,
                                                   std::memory_order_release);
        g_popupOverlayWgcPresentedGeometryGeneration.store(
            renderGeometryGeneration, std::memory_order_release);
        bool attachedDcompContent = false;
        if (g_popupOverlayDcompVisual && g_popupOverlayWgcSwapChain &&
            !g_popupOverlayDcompContentAttached) {
            g_popupOverlayDcompVisual->SetContent(
                g_popupOverlayWgcSwapChain.get());
            g_popupOverlayDcompContentAttached = true;
            attachedDcompContent = true;
        }
        if (attachedDcompContent && g_popupOverlayDcompDevice) {
            g_popupOverlayDcompDevice->Commit();
        }
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::VisibleFrame;
        g_popupOverlayWgcReadbackHadVisibleFrame = true;
        g_popupOverlayWgcFallbackPainted = false;
    } catch (winrt::hresult_error const& error) {
        g_popupOverlayWgcLastHr = error.code().value;
        g_popupOverlayWgcDiagnosticHr = error.code().value;
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::RenderFailed;
        ++g_popupOverlayWgcRenderFailCount;
        Wh_Log(
            L"Island: overlay WGC state hresult_error=0x%08X frames=%llu "
            L"fails=%llu",
            static_cast<unsigned>(g_popupOverlayWgcLastHr),
            static_cast<unsigned long long>(g_popupOverlayWgcFrameCount),
            static_cast<unsigned long long>(g_popupOverlayWgcRenderFailCount));
    } catch (...) {
        g_popupOverlayWgcLastHr = E_FAIL;
        g_popupOverlayWgcDiagnosticHr = E_FAIL;
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::RenderFailed;
        ++g_popupOverlayWgcRenderFailCount;
        Wh_Log(
            L"Island: overlay WGC state unknown failure frames=%llu fails=%llu",
            static_cast<unsigned long long>(g_popupOverlayWgcFrameCount),
            static_cast<unsigned long long>(g_popupOverlayWgcRenderFailCount));
    }
}

void ResetPopupOverlayWgcDeviceResourcesLocked() {
    g_popupOverlayWgcSession = nullptr;
    g_popupOverlayWgcFramePool = nullptr;
    g_popupOverlayWgcFrameArrivedToken = {};
    g_popupOverlayWgcFrameCallbackHooked = false;
    g_popupOverlayWgcDirtyRegionsEnabled.store(false,
                                               std::memory_order_release);
    g_popupOverlayWgcItem = nullptr;
    g_popupOverlayWgcGraphicsDevice = nullptr;
    g_popupOverlayWgcSwapChainTargetBitmap = nullptr;
    g_popupOverlayWgcSwapChain = nullptr;
    g_popupOverlayDcompContentAttached = false;
    if (g_popupOverlayDcompVisual) {
        g_popupOverlayDcompVisual->SetContent(nullptr);
    }
    if (g_popupOverlayDcompTarget) {
        g_popupOverlayDcompTarget->SetRoot(nullptr);
    }
    if (g_popupOverlayDcompDevice) {
        g_popupOverlayDcompDevice->Commit();
    }
    g_popupOverlayDcompVisual = nullptr;
    g_popupOverlayDcompOpacityEffect = nullptr;
    g_popupOverlayDcompTransformValid = false;
    g_popupOverlayDcompLastScaleX = 0.0f;
    g_popupOverlayDcompLastScaleY = 0.0f;
    g_popupOverlayDcompTarget = nullptr;
    g_popupOverlayDcompDevice = nullptr;
    ClearPopupOverlayWgcRenderCache();
    ClearPopupOverlayWgcLensDisplacementMap();
    g_popupOverlayWgcD2dContext = nullptr;
    g_popupOverlayWgcD2dDevice = nullptr;
    g_popupOverlayWgcD2dFactory = nullptr;
    g_popupOverlayWgcDxgiDevice = nullptr;
    g_popupOverlayWgcD3dContext = nullptr;
    g_popupOverlayWgcD3dDevice = nullptr;
    g_popupOverlayWgcTargetWidthPx = 0;
    g_popupOverlayWgcTargetHeightPx = 0;
    g_popupOverlayWgcTargetRadiusPx = 0;
    g_popupOverlayWgcRenderParameters = {};
    g_popupOverlayWgcFrameIntervalMs = 1000.0 / 60.0;
    g_popupOverlayWgcMonitor = nullptr;
    g_popupOverlayWgcCaptureRectPx = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_popupOverlayWgcMonitorRectPx = {};
}

void StopPopupOverlayWgcBackdrop() {
    capture::GraphicsCaptureSession sessionToClose{nullptr};
    capture::Direct3D11CaptureFramePool framePoolToClose{nullptr};
    winrt::event_token frameArrivedToken{};
    bool frameCallbackHooked = false;

    {
        std::lock_guard lock(g_popupOverlayWgcMutex);
        g_popupOverlayWgcRunning = false;
        sessionToClose = g_popupOverlayWgcSession;
        framePoolToClose = g_popupOverlayWgcFramePool;
        frameArrivedToken = g_popupOverlayWgcFrameArrivedToken;
        frameCallbackHooked = g_popupOverlayWgcFrameCallbackHooked;
        g_popupOverlayWgcFrameCallbackHooked = false;
    }

    try {
        if (framePoolToClose && frameCallbackHooked) {
            framePoolToClose.FrameArrived(frameArrivedToken);
        }
    } catch (...) {
    }

    for (int i = 0;
         i < 80 && g_popupOverlayWgcRendering.load(std::memory_order_acquire);
         ++i) {
        Sleep(1);
    }

    {
        std::lock_guard lock(g_popupOverlayWgcMutex);
        ResetPopupOverlayWgcDeviceResourcesLocked();
        g_popupOverlayWgcHadFrame = false;
        g_popupOverlayWgcDiagnosticStartTime = {};
        g_popupOverlayWgcLastRenderTime = {};
        g_popupOverlayWgcLastResizeTime = {};
        g_popupOverlayWgcReadbackHadVisibleFrame = false;
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::NotStarted;
        g_popupOverlayWgcDiagnosticHr = S_OK;
        g_popupOverlayWgcFrameCount = 0;
        g_popupOverlayWgcRenderFailCount = 0;
        // Keep retry throttle fields intact here. This function is called before
        // rebuilding WGC resources, so clearing them here would re-enable rapid
        // CreateForMonitor retries after a failure.
        g_popupOverlayWgcFramesToSkip = 0;
    }

    if (g_expandedPopup) {
        SetWindowDisplayAffinity(g_expandedPopup, WDA_NONE);
    }
    if (g_popupXamlChild) {
        SetWindowDisplayAffinity(g_popupXamlChild, WDA_NONE);
    }
    if (g_popupBackdropOverlay) {
        SetWindowDisplayAffinity(g_popupBackdropOverlay, WDA_NONE);
    }
    g_expandedPopupCaptureExcluded = false;
    g_popupXamlChildCaptureExcluded = false;
    g_popupBackdropOverlayCaptureExcluded = false;
    try {
        if (sessionToClose) {
            sessionToClose.Close();
        }
        if (framePoolToClose) {
            framePoolToClose.Close();
        }
    } catch (...) {
    }
}
void ReleasePopupOverlayWgcDeviceResources() {
    StopPopupOverlayWgcBackdrop();

    std::lock_guard lock(g_popupOverlayWgcMutex);
    ResetPopupOverlayWgcDeviceResourcesLocked();
}

bool StartPopupOverlayWgcBackdrop(
    RECT const& captureRect,
    int widthPx,
    int heightPx,
    PopupOverlayWgcRenderParameters const& renderParameters) {
    auto now = std::chrono::steady_clock::now();
    if (g_popupOverlayWgcCreateItemFailed &&
        g_popupOverlayWgcLastStartAttemptTime.time_since_epoch().count() != 0 &&
        now - g_popupOverlayWgcLastStartAttemptTime < std::chrono::seconds(3)) {
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        return false;
    }
    g_popupOverlayWgcLastStartAttemptTime = now;

    if (g_unloading || widthPx <= 0 || heightPx <= 0) {
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        return false;
    }

    if (!UseOverlayPopupBackdropMaterial() || !g_popupBackdropOverlay ||
        !g_expandedPopup) {
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        Wh_Log(
            L"Island: overlay WGC state start skipped material=%d overlay=%p "
            L"popup=%p unloading=%d size=%dx%d",
            UseOverlayPopupBackdropMaterial(), g_popupBackdropOverlay,
            g_expandedPopup, g_unloading.load(), widthPx, heightPx);
        return false;
    }

    HMONITOR monitor = MonitorFromRect(&captureRect, MONITOR_DEFAULTTONEAREST);
    MONITORINFO monitorInfo{sizeof(monitorInfo)};
    if (!monitor || !GetMonitorInfoW(monitor, &monitorInfo)) {
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        Wh_Log(L"Island: overlay WGC state no monitor");
        return false;
    }
    double frameIntervalMs = PopupOverlayWgcFrameIntervalMsForMonitor(monitor);

    {
        std::unique_lock lock(g_popupOverlayWgcMutex, std::try_to_lock);
        if (!lock.owns_lock()) {
            // The GPU callback is presenting the current frame. Keep the
            // previous snapshot for this tick instead of blocking the taskbar
            // animation thread.
            return true;
        }

        if (g_popupOverlayWgcRunning && g_popupOverlayWgcSwapChain &&
            g_popupOverlayWgcSwapChainTargetBitmap &&
            g_popupOverlayWgcMonitor == monitor) {
            // Keep the monitor capture session alive during the morph. Only
            // update its immutable-per-frame input snapshot.
            g_popupOverlayWgcCreateItemFailed = false;
            bool sizeChanged = g_popupOverlayWgcTargetWidthPx != widthPx ||
                               g_popupOverlayWgcTargetHeightPx != heightPx;
            bool resizeDue =
                g_popupOverlayWgcLastResizeTime.time_since_epoch().count() ==
                    0 ||
                now - g_popupOverlayWgcLastResizeTime >=
                    std::chrono::milliseconds(40);
            if (sizeChanged && !renderParameters.morphing && resizeDue) {
                if (!RecreatePopupOverlayWgcReadbackTextures(widthPx,
                                                             heightPx)) {
                    g_popupOverlayWgcDiagnosticState =
                        PopupOverlayWgcDiagnosticState::RenderFailed;
                    ++g_popupOverlayWgcRenderFailCount;
                    return false;
                }
                g_popupOverlayWgcLastResizeTime = now;
            }
            if (sizeChanged && renderParameters.morphing) {
                UpdatePopupOverlayDcompVisualTransformLocked(
                    widthPx, heightPx, g_popupBackdropOverlayLastRadius);
            }
            g_popupOverlayWgcCaptureRectPx = captureRect;
            g_popupOverlayWgcMonitorRectPx = monitorInfo.rcMonitor;
            g_popupOverlayWgcTargetRadiusPx =
                Clamp(renderParameters.targetRadiusPx, 1,
                      std::max(1, std::min(widthPx, heightPx) / 2));
            g_popupOverlayWgcRenderParameters = renderParameters;
            g_popupOverlayWgcRenderParameters.targetRadiusPx =
                g_popupOverlayWgcTargetRadiusPx;
            g_popupOverlayWgcFrameIntervalMs = frameIntervalMs;
            g_popupOverlayWgcGeometryGeneration.fetch_add(
                1, std::memory_order_release);
            return true;
        }
    }

    StopPopupOverlayWgcBackdrop();

    if (!capture::GraphicsCaptureSession::IsSupported()) {
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        Wh_Log(L"Island: overlay WGC state not supported");
        return false;
    }

    RequestPopupOverlayWgcBorderlessAccessAsync();
    if (!PopupOverlayWgcBorderlessAccessAllowed()) {
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        if (!PopupOverlayWgcBorderlessAccessPending()) {
            g_popupOverlayWgcDiagnosticHr = E_ACCESSDENIED;
        }
        return false;
    }

    {
        std::lock_guard lock(g_popupOverlayWgcMutex);
        if (!EnsurePopupOverlayWgcDeviceResourcesLocked(g_popupBackdropOverlay,
                                                        widthPx, heightPx)) {
            g_popupOverlayWgcDiagnosticState =
                PopupOverlayWgcDiagnosticState::StartSkipped;
            Wh_Log(
                L"Island: overlay WGC state Ensure resources failed hr=0x%08X",
                static_cast<unsigned>(g_popupOverlayWgcLastHr));
            return false;
        }
    }

    if (!CreatePopupOverlayWgcCaptureItemForMonitor(monitor,
                                                    g_popupOverlayWgcItem)) {
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        g_popupOverlayWgcDiagnosticHr = g_popupOverlayWgcCreateItemHr;
        g_popupOverlayWgcCreateItemFailed = true;
        Wh_Log(
            L"Island: overlay WGC state Create capture item failed hr=0x%08X; "
            L"throttling retries",
            static_cast<unsigned>(g_popupOverlayWgcCreateItemHr));
        return false;
    }
    g_popupOverlayWgcCreateItemFailed = false;

    // Keep the existing blurred fallback visible until the first WGC frame is
    // ready. Exclude the overlay from capture first; optionally keep the popup
    // capturable so users can record the expanded material effect.
    bool captureAffinityChanged =
        SetExpandedPopupCaptureExclusion(!renderParameters.allowScreenCapture);
    captureAffinityChanged =
        SetPopupWindowCaptureExclusion(g_popupBackdropOverlay, true) ||
        captureAffinityChanged;
    if (captureAffinityChanged) {
        DwmFlush();
    }

    std::lock_guard lock(g_popupOverlayWgcMutex);
    g_popupOverlayWgcCaptureRectPx = captureRect;
    g_popupOverlayWgcMonitorRectPx = monitorInfo.rcMonitor;
    g_popupOverlayWgcMonitor = monitor;
    g_popupOverlayWgcTargetRadiusPx =
        Clamp(renderParameters.targetRadiusPx, 1,
              std::max(1, std::min(widthPx, heightPx) / 2));
    g_popupOverlayWgcRenderParameters = renderParameters;
    g_popupOverlayWgcRenderParameters.targetRadiusPx =
        g_popupOverlayWgcTargetRadiusPx;
    g_popupOverlayWgcFrameIntervalMs = frameIntervalMs;
    g_popupOverlayWgcGeometryGeneration.fetch_add(1, std::memory_order_release);
    g_popupOverlayWgcRunning = true;
    g_popupOverlayWgcLastHr = S_OK;
    g_popupOverlayWgcDiagnosticHr = S_OK;
    g_popupOverlayWgcHadFrame = false;
    g_popupOverlayWgcFrameCount = 0;
    g_popupOverlayWgcRenderFailCount = 0;
    g_popupOverlayWgcDiagnosticState =
        PopupOverlayWgcDiagnosticState::StartedNoFrame;
    g_popupOverlayWgcDiagnosticStartTime = std::chrono::steady_clock::now();
    g_popupOverlayWgcLastResizeTime = g_popupOverlayWgcDiagnosticStartTime;
    g_popupOverlayWgcFramesToSkip =
        renderParameters.morphing ? 0 : PopupBackdropInitialFrameSkip();

    try {
        g_popupOverlayWgcFramePool =
            capture::Direct3D11CaptureFramePool::CreateFreeThreaded(
                g_popupOverlayWgcGraphicsDevice,
                directx::DirectXPixelFormat::B8G8R8A8UIntNormalized, 2,
                g_popupOverlayWgcItem.Size());
        g_popupOverlayWgcFrameArrivedToken =
            g_popupOverlayWgcFramePool.FrameArrived(
                [](capture::Direct3D11CaptureFramePool const& sender,
                   winrt::Windows::Foundation::IInspectable const&) {
                    auto frame = sender.TryGetNextFrame();
                    if (!frame) {
                        return;
                    }

                    // While waiting for the first frame of a new opening, the
                    // overlay is deliberately still hidden. It must nevertheless
                    // render that frame; otherwise "wait for a fresh frame" and
                    // "skip rendering while hidden" deadlock each other and the
                    // Gaussian glass appears late or never appears.
                    HWND overlay = g_popupBackdropOverlay;
                    bool waitingForOpeningFrame =
                        g_popupOverlayAwaitFreshFrame.load(
                            std::memory_order_acquire);
                    if (!overlay || (!IsWindowVisible(overlay) &&
                                     !waitingForOpeningFrame)) {
                        frame.Close();
                        return;
                    }

                    bool expected = false;
                    if (!g_popupOverlayWgcRendering.compare_exchange_strong(
                            expected, true, std::memory_order_acq_rel)) {
                        frame.Close();
                        return;
                    }

                    try {
                        std::lock_guard callbackLock(g_popupOverlayWgcMutex);
                        if (g_popupOverlayWgcRunning) {
                            RenderPopupOverlayWgcFrameLocked(frame);
                        }
                    } catch (...) {
                        Wh_Log(
                            L"Island: overlay WGC callback render escaped "
                            L"exception");
                    }
                    g_popupOverlayWgcRendering.store(false,
                                                     std::memory_order_release);
                    frame.Close();
                });
        g_popupOverlayWgcFrameCallbackHooked = true;
        g_popupOverlayWgcSession =
            g_popupOverlayWgcFramePool.CreateCaptureSession(
                g_popupOverlayWgcItem);
        g_popupOverlayWgcDirtyRegionsEnabled.store(false,
                                                   std::memory_order_release);
        if (PopupOverlayWgcDirtyRegionsSupported()) {
            try {
                // Windows 11 24H2+ can preserve unchanged pixels in the frame
                // pool and render only compositor dirty regions. The callback
                // also uses those regions to skip blur work when a change is
                // completely outside the popup's sampled background.
                g_popupOverlayWgcSession.DirtyRegionMode(
                    capture::GraphicsCaptureDirtyRegionMode::ReportAndRender);
                g_popupOverlayWgcDirtyRegionsEnabled.store(
                    true, std::memory_order_release);
            } catch (...) {
            }
        }
        try {
            // Windows Graphics Capture shows a yellow border around monitor
            // captures by default. Request borderless access separately and
            // always set the per-session flag here; Windows ignores it until
            // access is granted, then the async callback applies it again to
            // the live session.
            g_popupOverlayWgcSession.IsBorderRequired(false);
        } catch (...) {
        }
        try {
            g_popupOverlayWgcSession.IsCursorCaptureEnabled(false);
        } catch (...) {
        }
        g_popupOverlayWgcSession.StartCapture();
        Wh_Log(
            L"Island: overlay WGC state backdrop started %dx%d "
            L"monitor=(%ld,%ld,%ld,%ld)",
            widthPx, heightPx, monitorInfo.rcMonitor.left,
            monitorInfo.rcMonitor.top, monitorInfo.rcMonitor.right,
            monitorInfo.rcMonitor.bottom);
        return true;
    } catch (winrt::hresult_error const& error) {
        g_popupOverlayWgcLastHr = error.code().value;
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        g_popupOverlayWgcDiagnosticHr = g_popupOverlayWgcLastHr;
        Wh_Log(L"Island: overlay WGC state start failed hr=0x%08X",
               static_cast<unsigned>(g_popupOverlayWgcLastHr));
        g_popupOverlayWgcRunning = false;
        g_popupOverlayWgcFrameCallbackHooked = false;
        ResetPopupOverlayWgcDeviceResourcesLocked();
        return false;
    } catch (...) {
        g_popupOverlayWgcLastHr = E_FAIL;
        g_popupOverlayWgcDiagnosticState =
            PopupOverlayWgcDiagnosticState::StartSkipped;
        g_popupOverlayWgcDiagnosticHr = E_FAIL;
        Wh_Log(L"Island: overlay WGC state start failed unknown");
        g_popupOverlayWgcRunning = false;
        g_popupOverlayWgcFrameCallbackHooked = false;
        ResetPopupOverlayWgcDeviceResourcesLocked();
        return false;
    }
}

BYTE PopupRoundedRectAlpha(int x, int y, int width, int height, int radius) {
    if (width <= 0 || height <= 0) {
        return 0;
    }

    radius = Clamp(radius, 1, std::max(1, std::min(width, height) / 2));

    auto contains = [&](double px, double py) {
        double left = 0.0;
        double top = 0.0;
        double right = static_cast<double>(width);
        double bottom = static_cast<double>(height);
        double r = static_cast<double>(radius);

        double cx = Clamp(px, left + r, right - r);
        double cy = Clamp(py, top + r, bottom - r);
        double dx = px - cx;
        double dy = py - cy;
        return dx * dx + dy * dy <= r * r;
    };

    double px = static_cast<double>(x) + 0.5;
    double py = static_cast<double>(y) + 0.5;
    if (contains(px, py)) {
        double innerMargin = 0.85;
        double left = static_cast<double>(radius) + innerMargin;
        double right = static_cast<double>(width - radius) - innerMargin;
        double top = static_cast<double>(radius) + innerMargin;
        double bottom = static_cast<double>(height - radius) - innerMargin;
        if ((px >= left && px <= right) || (py >= top && py <= bottom)) {
            return 255;
        }
    }

    constexpr int kSamplesPerAxis = 4;
    int coveredSamples = 0;
    for (int sy = 0; sy < kSamplesPerAxis; ++sy) {
        double sampleY =
            static_cast<double>(y) + (static_cast<double>(sy) + 0.5) /
                                         static_cast<double>(kSamplesPerAxis);
        for (int sx = 0; sx < kSamplesPerAxis; ++sx) {
            double sampleX = static_cast<double>(x) +
                             (static_cast<double>(sx) + 0.5) /
                                 static_cast<double>(kSamplesPerAxis);
            if (contains(sampleX, sampleY)) {
                ++coveredSamples;
            }
        }
    }

    return static_cast<BYTE>(
        std::lround(255.0 * static_cast<double>(coveredSamples) /
                    static_cast<double>(kSamplesPerAxis * kSamplesPerAxis)));
}

// ===== CPU backdrop fallback and overlay windows =====
void BoxBlurPbgraPixels(std::vector<BYTE>& pixels,
                        int width,
                        int height,
                        int passes) {
    if (width <= 1 || height <= 1 ||
        pixels.size() < static_cast<size_t>(width) * height * 4) {
        return;
    }

    std::vector<BYTE> temp(pixels.size());
    for (int pass = 0; pass < passes; ++pass) {
        temp = pixels;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int sumB = 0, sumG = 0, sumR = 0, sumA = 0, count = 0;
                for (int yy = std::max(0, y - 1);
                     yy <= std::min(height - 1, y + 1); ++yy) {
                    for (int xx = std::max(0, x - 1);
                         xx <= std::min(width - 1, x + 1); ++xx) {
                        BYTE* p = temp.data() +
                                  (static_cast<size_t>(yy) * width + xx) * 4;
                        sumB += p[0];
                        sumG += p[1];
                        sumR += p[2];
                        sumA += p[3];
                        ++count;
                    }
                }
                BYTE* out =
                    pixels.data() + (static_cast<size_t>(y) * width + x) * 4;
                out[0] = static_cast<BYTE>(sumB / count);
                out[1] = static_cast<BYTE>(sumG / count);
                out[2] = static_cast<BYTE>(sumR / count);
                out[3] = static_cast<BYTE>(sumA / count);
            }
        }
    }
}

bool* PopupCaptureExclusionCacheForHwnd(HWND hwnd) {
    if (hwnd && hwnd == g_expandedPopup) {
        return &g_expandedPopupCaptureExcluded;
    }
    if (hwnd && hwnd == g_popupXamlChild) {
        return &g_popupXamlChildCaptureExcluded;
    }
    if (hwnd && hwnd == g_popupBackdropOverlay) {
        return &g_popupBackdropOverlayCaptureExcluded;
    }
    return nullptr;
}

bool SetPopupWindowCaptureExclusion(HWND hwnd, bool exclude) {
    if (!hwnd) {
        return false;
    }

#ifndef WDA_EXCLUDEFROMCAPTURE
#define WDA_EXCLUDEFROMCAPTURE 0x00000011
#endif
#ifndef WDA_NONE
#define WDA_NONE 0x00000000
#endif

    bool* cached = PopupCaptureExclusionCacheForHwnd(hwnd);
    if (cached && *cached == exclude) {
        return false;
    }

    BOOL affinitySet = SetWindowDisplayAffinity(
        hwnd, exclude ? WDA_EXCLUDEFROMCAPTURE : WDA_NONE);
    if (cached) {
        // Avoid hammering DWM every animation tick. Repeating the same display
        // affinity call can invalidate composition surfaces and shows up as
        // intermittent input loss or blur flicker on Explorer's thread. Child
        // HWNDs may reject display affinity, but retrying them every frame is
        // still wasted work.
        *cached = exclude;
    }
    return affinitySet != FALSE;
}

bool SetExpandedPopupCaptureExclusion(bool exclude) {
    bool changed = SetPopupWindowCaptureExclusion(g_expandedPopup, exclude);
    changed =
        SetPopupWindowCaptureExclusion(g_popupXamlChild, exclude) || changed;
    return changed;
}

bool ClearPopupBackdropOverlayLayeredSurface(HWND hwnd) {
    if (!hwnd) {
        return false;
    }

    RECT rect{};
    GetWindowRect(hwnd, &rect);
    int width = std::max(1L, rect.right - rect.left);
    int height = std::max(1L, rect.bottom - rect.top);

    // Guard against invalid stale geometry during Explorer unload/reload.
    width = Clamp(width, 1, 2048);
    height = Clamp(height, 1, 2048);

    HDC screenDc = GetDC(nullptr);
    if (!screenDc) {
        return false;
    }
    HDC memDc = CreateCompatibleDC(screenDc);
    if (!memDc) {
        ReleaseDC(nullptr, screenDc);
        return false;
    }

    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = -height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;

    void* bits = nullptr;
    HBITMAP bitmap =
        CreateDIBSection(screenDc, &info, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!bitmap || !bits) {
        if (bitmap) {
            DeleteObject(bitmap);
        }
        DeleteDC(memDc);
        ReleaseDC(nullptr, screenDc);
        return false;
    }

    std::memset(bits, 0, static_cast<size_t>(width) * height * 4);

    HGDIOBJ oldBitmap = SelectObject(memDc, bitmap);
    POINT srcPoint{0, 0};
    SIZE size{width, height};
    POINT dstPoint{rect.left, rect.top};
    BLENDFUNCTION blend{AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};

    BOOL ok = UpdateLayeredWindow(hwnd, screenDc, &dstPoint, &size, memDc,
                                  &srcPoint, 0, &blend, ULW_ALPHA);

    SelectObject(memDc, oldBitmap);
    DeleteObject(bitmap);
    DeleteDC(memDc);
    ReleaseDC(nullptr, screenDc);
    return !!ok;
}

bool CaptureLowResScreenPixels(RECT const& screenRect,
                               int lowWidth,
                               int lowHeight,
                               std::vector<BYTE>& pixels,
                               HWND excludeOverlay = nullptr) {
    if (lowWidth <= 0 || lowHeight <= 0 ||
        screenRect.right <= screenRect.left ||
        screenRect.bottom <= screenRect.top) {
        return false;
    }

    pixels.assign(static_cast<size_t>(lowWidth) * lowHeight * 4, 0);

    // Keep the overlay visible while sampling. Hiding/restoring the layered
    // window here caused an obvious flash during the popup morph. Capture
    // exclusion is still requested; if a build ignores it for GetDC(nullptr),
    // WGC will take over after the final geometry is ready.
    if (excludeOverlay) {
        SetPopupWindowCaptureExclusion(excludeOverlay, true);
    }
    auto restoreExcludedOverlay = [&] {
        if (excludeOverlay) {
            // Keep the overlay excluded while a WGC session is active; otherwise
            // restore normal visibility for plain GDI fallback mode.
            SetPopupWindowCaptureExclusion(excludeOverlay,
                                           g_popupOverlayWgcRunning);
        }
    };

    HDC screenDc = GetDC(nullptr);
    if (!screenDc) {
        restoreExcludedOverlay();
        return false;
    }

    HDC memDc = CreateCompatibleDC(screenDc);
    if (!memDc) {
        ReleaseDC(nullptr, screenDc);
        restoreExcludedOverlay();
        return false;
    }

    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = lowWidth;
    info.bmiHeader.biHeight = -lowHeight;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;

    void* bits = nullptr;
    HBITMAP bitmap =
        CreateDIBSection(screenDc, &info, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!bitmap || !bits) {
        if (bitmap)
            DeleteObject(bitmap);
        DeleteDC(memDc);
        ReleaseDC(nullptr, screenDc);
        restoreExcludedOverlay();
        return false;
    }

    HGDIOBJ oldBitmap = SelectObject(memDc, bitmap);
    SetStretchBltMode(memDc, HALFTONE);
    SetBrushOrgEx(memDc, 0, 0, nullptr);

    int sourceWidth = screenRect.right - screenRect.left;
    int sourceHeight = screenRect.bottom - screenRect.top;
    BOOL ok =
        StretchBlt(memDc, 0, 0, lowWidth, lowHeight, screenDc, screenRect.left,
                   screenRect.top, sourceWidth, sourceHeight, SRCCOPY);

    if (ok) {
        std::memcpy(pixels.data(), bits, pixels.size());
    }

    SelectObject(memDc, oldBitmap);
    DeleteObject(bitmap);
    DeleteDC(memDc);
    ReleaseDC(nullptr, screenDc);
    restoreExcludedOverlay();
    return !!ok;
}

void SampleBilinearPbgra(std::vector<BYTE> const& pixels,
                         int width,
                         int height,
                         double x,
                         double y,
                         int& b,
                         int& g,
                         int& r) {
    if (width <= 0 || height <= 0 || pixels.empty()) {
        b = g = r = 0;
        return;
    }

    x = Clamp(x, 0.0, static_cast<double>(width - 1));
    y = Clamp(y, 0.0, static_cast<double>(height - 1));
    int x0 = Clamp(static_cast<int>(std::floor(x)), 0, width - 1);
    int y0 = Clamp(static_cast<int>(std::floor(y)), 0, height - 1);
    int x1 = Clamp(x0 + 1, 0, width - 1);
    int y1 = Clamp(y0 + 1, 0, height - 1);
    double fx = x - x0;
    double fy = y - y0;

    auto pixel = [&](int px, int py) -> BYTE const* {
        return pixels.data() + (static_cast<size_t>(py) * width + px) * 4;
    };

    BYTE const* p00 = pixel(x0, y0);
    BYTE const* p10 = pixel(x1, y0);
    BYTE const* p01 = pixel(x0, y1);
    BYTE const* p11 = pixel(x1, y1);

    auto blend = [&](int channel) -> int {
        double top = p00[channel] * (1.0 - fx) + p10[channel] * fx;
        double bottom = p01[channel] * (1.0 - fx) + p11[channel] * fx;
        return Clamp(
            static_cast<int>(std::lround(top * (1.0 - fy) + bottom * fy)), 0,
            255);
    };

    b = blend(0);
    g = blend(1);
    r = blend(2);
}

bool UpdatePopupBackdropOverlayLayeredBlur(HWND hwnd,
                                           RECT const& screenRect,
                                           int width,
                                           int height,
                                           int cornerRadiusPx,
                                           bool force) {
    if (!hwnd || width <= 2 || height <= 2) {
        return false;
    }

    auto now = std::chrono::steady_clock::now();
    bool sizeChanged = width != g_popupBackdropOverlayLastWidth ||
                       height != g_popupBackdropOverlayLastHeight ||
                       cornerRadiusPx != g_popupBackdropOverlayLastRadius;
    if (!force && !sizeChanged &&
        g_popupBackdropOverlayLastPaintTime.time_since_epoch().count() != 0) {
        auto age = std::chrono::duration_cast<std::chrono::milliseconds>(
                       now - g_popupBackdropOverlayLastPaintTime)
                       .count();
        if (age < kPopupBackdropOverlayRefreshMs) {
            return true;
        }
    }

    int captureScale = PopupBackdropFallbackCaptureScale();
    int lowWidth =
        Clamp(width / captureScale, 40, kPopupBackdropOverlayMaxCaptureSize);
    int lowHeight =
        Clamp(height / captureScale, 40, kPopupBackdropOverlayMaxCaptureSize);
    std::vector<BYTE> lowPixels;
    if (!CaptureLowResScreenPixels(screenRect, lowWidth, lowHeight, lowPixels,
                                   hwnd)) {
        return false;
    }

    std::vector<BYTE> cleanPixels(static_cast<size_t>(width) * height * 4);
    for (int y = 0; y < height; ++y) {
        double sampleY =
            ((static_cast<double>(y) + 0.5) * lowHeight / height) - 0.5;
        for (int x = 0; x < width; ++x) {
            double sampleX =
                ((static_cast<double>(x) + 0.5) * lowWidth / width) - 0.5;
            int sb = 0;
            int sg = 0;
            int sr = 0;
            SampleBilinearPbgra(lowPixels, lowWidth, lowHeight, sampleX,
                                sampleY, sb, sg, sr);

            BYTE* dst =
                cleanPixels.data() + (static_cast<size_t>(y) * width + x) * 4;
            dst[0] = static_cast<BYTE>(sb);
            dst[1] = static_cast<BYTE>(sg);
            dst[2] = static_cast<BYTE>(sr);
            dst[3] = 255;
        }
    }

    int blurPasses = PopupBackdropFallbackBlurPasses();
    if (g_settings.allowScreenCapture && IsLiquidGlassMaterial()) {
        blurPasses = std::max(blurPasses, 3);
    }
    BoxBlurPbgraPixels(lowPixels, lowWidth, lowHeight, blurPasses);

    std::vector<BYTE> out(static_cast<size_t>(width) * height * 4);
    bool dark = IsDarkModeApprox();
    constexpr double kDarkDim = 0.94;
    constexpr double kLightDim = 1.00;
    double dim = dark ? kDarkDim : kLightDim;
    BYTE maxAlpha = PopupBackdropOverlayMaxAlpha();

    for (int y = 0; y < height; ++y) {
        double sampleY =
            ((static_cast<double>(y) + 0.5) * lowHeight / height) - 0.5;
        for (int x = 0; x < width; ++x) {
            double sampleX =
                ((static_cast<double>(x) + 0.5) * lowWidth / width) - 0.5;
            BYTE edgeAlpha =
                PopupRoundedRectAlpha(x, y, width, height, cornerRadiusPx);
            BYTE a = static_cast<BYTE>(
                (static_cast<int>(edgeAlpha) * maxAlpha) / 255);

            int sb = 0;
            int sg = 0;
            int sr = 0;
            SampleBilinearPbgra(lowPixels, lowWidth, lowHeight, sampleX,
                                sampleY, sb, sg, sr);

            int b = Clamp(static_cast<int>(std::lround(sb * dim)), 0, 255);
            int g = Clamp(static_cast<int>(std::lround(sg * dim)), 0, 255);
            int r = Clamp(static_cast<int>(std::lround(sr * dim)), 0, 255);

            BYTE* dst = out.data() + (static_cast<size_t>(y) * width + x) * 4;
            // UpdateLayeredWindow expects premultiplied BGRA for AC_SRC_ALPHA.
            dst[0] = static_cast<BYTE>((b * a) / 255);
            dst[1] = static_cast<BYTE>((g * a) / 255);
            dst[2] = static_cast<BYTE>((r * a) / 255);
            dst[3] = a;
        }
    }
    {
        std::lock_guard cacheLock(g_popupBackdropOverlayHandoffMutex);
        g_popupBackdropOverlayFallbackPixels = out;
        g_popupBackdropOverlayFallbackRect = screenRect;
        g_popupBackdropOverlayFallbackWidth = width;
        g_popupBackdropOverlayFallbackHeight = height;
        g_popupBackdropOverlayFallbackRadius = cornerRadiusPx;
        g_popupBackdropOverlayFallbackPixelsValid = true;
        g_popupBackdropOverlayCleanPixels = cleanPixels;
        g_popupBackdropOverlayCleanRect = screenRect;
        g_popupBackdropOverlayCleanWidth = width;
        g_popupBackdropOverlayCleanHeight = height;
        g_popupBackdropOverlayCleanPixelsValid = true;
    }

    HDC screenDc = GetDC(nullptr);
    if (!screenDc) {
        return false;
    }
    HDC memDc = CreateCompatibleDC(screenDc);
    if (!memDc) {
        ReleaseDC(nullptr, screenDc);
        return false;
    }

    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = -height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;

    void* bits = nullptr;
    HBITMAP bitmap =
        CreateDIBSection(screenDc, &info, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!bitmap || !bits) {
        if (bitmap)
            DeleteObject(bitmap);
        DeleteDC(memDc);
        ReleaseDC(nullptr, screenDc);
        return false;
    }
    std::memcpy(bits, out.data(), out.size());

    HGDIOBJ oldBitmap = SelectObject(memDc, bitmap);
    POINT srcPoint{0, 0};
    SIZE size{width, height};
    POINT dstPoint{screenRect.left, screenRect.top};
    BLENDFUNCTION blend{AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};

    BOOL ok = UpdateLayeredWindow(hwnd, screenDc, &dstPoint, &size, memDc,
                                  &srcPoint, 0, &blend, ULW_ALPHA);

    SelectObject(memDc, oldBitmap);
    DeleteObject(bitmap);
    DeleteDC(memDc);
    ReleaseDC(nullptr, screenDc);

    if (ok) {
        g_popupBackdropOverlayLastPaintTime = now;
        g_popupBackdropOverlayLastWidth = width;
        g_popupBackdropOverlayLastHeight = height;
        g_popupBackdropOverlayLastRadius = cornerRadiusPx;
    }
    return !!ok;
}

void PaintPopupBackdropOverlay(HWND hwnd) {
    PAINTSTRUCT paint{};
    HDC dc = BeginPaint(hwnd, &paint);
    if (dc) {
        EndPaint(hwnd, &paint);
    }
}

LRESULT CALLBACK PopupBackdropOverlayWndProc(HWND hwnd,
                                             UINT message,
                                             WPARAM wParam,
                                             LPARAM lParam) {
    try {
        switch (message) {
            case WM_ERASEBKGND:
                return 1;
            case WM_NCHITTEST:
                return HTTRANSPARENT;
            case WM_TIMER:
                if (wParam == kPopupBackdropOverlayTimerId) {
                    UpdatePopupBackdropOverlayWindow();
                    return 0;
                }
                break;
            case WM_PAINT:
                PaintPopupBackdropOverlay(hwnd);
                return 0;
            case WM_DESTROY:
                KillTimer(hwnd, kPopupBackdropOverlayTimerId);
                SetPopupWindowCaptureExclusion(hwnd, false);
                if (g_popupBackdropOverlay == hwnd) {
                    g_popupBackdropOverlay = nullptr;
                }
                return 0;
        }
    } catch (...) {
    }
    return DefWindowProcW(hwnd, message, wParam, lParam);
}

bool RegisterPopupBackdropOverlayClass() {
    if (g_popupBackdropOverlayClassRegistered) {
        return true;
    }
    HINSTANCE moduleInstance = ModInstance();
    if (!moduleInstance) {
        return false;
    }
    WNDCLASSEXW windowClass{sizeof(windowClass)};
    windowClass.lpfnWndProc = PopupBackdropOverlayWndProc;
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.hInstance = moduleInstance;
    windowClass.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    windowClass.lpszClassName = kPopupBackdropOverlayClassName;
    if (!RegisterClassExW(&windowClass)) {
        Wh_Log(
            L"Island: failed to register popup backdrop overlay window class");
        return false;
    }
    g_popupBackdropOverlayClassRegistered = true;
    return true;
}

void UnregisterPopupBackdropOverlayClass() {
    if (!g_popupBackdropOverlayClassRegistered) {
        return;
    }
    HINSTANCE moduleInstance = ModInstance();
    if (moduleInstance &&
        UnregisterClassW(kPopupBackdropOverlayClassName, moduleInstance)) {
        g_popupBackdropOverlayClassRegistered = false;
    }
}

bool EnsurePopupBackdropOverlayWindow() {
    if (!UseOverlayPopupBackdropMaterial()) {
        return false;
    }
    if (g_popupBackdropOverlay) {
        return true;
    }
    if (!RegisterPopupBackdropOverlayClass()) {
        return false;
    }
    g_popupBackdropOverlay = CreateWindowExW(
        // Native Acrylic requires a normal redirected top-level surface.
        // NOREDIRECTIONBITMAP made the system effect fall back to opaque black.
        WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE | WS_EX_TRANSPARENT,
        kPopupBackdropOverlayClassName, L"", WS_POPUP, 0, 0, 1, 1, g_taskbarWnd,
        nullptr, ModInstance(), nullptr);
    if (!g_popupBackdropOverlay) {
        Wh_Log(L"Island: failed to create popup backdrop overlay window");
        return false;
    }
    return true;
}

void HidePopupBackdropOverlayWindowVisualOnly() {
    if (g_popupBackdropOverlay) {
        // This is a visual park, not a teardown. Recreating WGC/D3D and changing
        // display affinity on every toggle caused the large opening hitch and
        // a transparent frame. Preserve the session, swap-chain contents,
        // clipping and capture exclusion for instant reuse. Full cleanup still
        // happens in HidePopupBackdropOverlayWindow during unload/material
        // changes.
        SetPopupOverlayNativeFrost(g_popupBackdropOverlay, false);
        ParkPopupWindow(g_popupBackdropOverlay);
        g_popupLiquidGlassPanelRectPx = {};
        g_popupLiquidGlassPanelRadiusPx = 0;
        g_popupLiquidGlassPanelRectValid = false;
        g_popupBackdropOverlayNativeBlurActive = false;
        g_popupBackdropOverlayNativeFrostAlpha = -1;
    }
}

void HidePopupBackdropOverlayWindow() {
    if (g_popupBackdropOverlay) {
        ReleasePopupOverlayWgcDeviceResources();
        SetPopupWindowCaptureExclusion(g_popupBackdropOverlay, false);
        ClearPopupBackdropOverlayLayeredSurface(g_popupBackdropOverlay);
        SetWindowRgn(g_popupBackdropOverlay, nullptr, FALSE);
        ParkPopupWindow(g_popupBackdropOverlay);
        g_popupBackdropOverlayLastPaintTime = {};
        g_popupBackdropOverlayLastWidth = 0;
        g_popupBackdropOverlayLastHeight = 0;
        g_popupBackdropOverlayLastRadius = 0;
        g_popupLiquidGlassPanelRectPx = {};
        g_popupLiquidGlassPanelRadiusPx = 0;
        g_popupLiquidGlassPanelRectValid = false;
        g_popupOverlayWgcFallbackPainted = false;
        ClearPopupBackdropOverlayHandoffCache();
        if (g_expandedPopup) {
            SetExpandedPopupCaptureExclusion(false);
        }
    }
}

void DestroyPopupBackdropOverlayWindow() {
    if (g_popupBackdropOverlay) {
        StopPopupOverlayWgcBackdrop();
        SetPopupWindowCaptureExclusion(g_popupBackdropOverlay, false);
        ClearPopupBackdropOverlayLayeredSurface(g_popupBackdropOverlay);
        ClearPopupBackdropOverlayHandoffCache();
        SetWindowRgn(g_popupBackdropOverlay, nullptr, FALSE);
        DestroyWindow(g_popupBackdropOverlay);
        g_popupBackdropOverlay = nullptr;
    }
}

bool CalculatePopupBackdropOverlayRect(RECT& overlayRect, int& cornerRadiusPx) {
    if (!g_expandedPopup) {
        return false;
    }

    RECT popupScreenPx{};
    GetWindowRect(g_expandedPopup, &popupScreenPx);
    if (popupScreenPx.right <= popupScreenPx.left ||
        popupScreenPx.bottom <= popupScreenPx.top) {
        return false;
    }

    double dpiScale = PopupDpiScale(g_expandedPopup);
    DipRect sourceRectDip =
        PopupScreenRectToLocalDip(g_popupSourceRect, popupScreenPx, dpiScale);
    RECT sourceRect{static_cast<LONG>(std::lround(sourceRectDip.left)),
                    static_cast<LONG>(std::lround(sourceRectDip.top)),
                    static_cast<LONG>(std::lround(sourceRectDip.right)),
                    static_cast<LONG>(std::lround(sourceRectDip.bottom))};
    DipRect finalRectDip =
        PopupScreenRectToLocalDip(g_popupFinalRect, popupScreenPx, dpiScale);
    RECT finalRect{static_cast<LONG>(std::lround(finalRectDip.left)),
                   static_cast<LONG>(std::lround(finalRectDip.top)),
                   static_cast<LONG>(std::lround(finalRectDip.right)),
                   static_cast<LONG>(std::lround(finalRectDip.bottom))};

    RECT targetArt{};
    RECT targetCard{};
    RECT targetTitle{};
    RECT targetArtist{};
    RECT targetProgress{};
    RECT targetElapsed{};
    RECT targetDuration{};
    RECT targetControls{};
    CalculatePopupFinalLayout(finalRect, targetArt, targetCard, targetTitle,
                              targetArtist, targetProgress, targetElapsed,
                              targetDuration, targetControls);
    RECT targetBackdrop = PopupBackdropRectFromParts(targetArt, targetCard);

    double progress = PopupProgress();
    // Once the popup is visually at the end of the morph, snap the native
    // backdrop to the exact final XAML shell. This avoids a late 1-3 px WGC
    // handoff offset caused by starting capture at progress≈0.985.
    if (!g_popupClosing && progress >= 0.995) {
        progress = 1.0;
    }
    RECT currentDip{
        LerpInt(sourceRect.left, targetBackdrop.left, progress),
        LerpInt(sourceRect.top, targetBackdrop.top, progress),
        LerpInt(sourceRect.right, targetBackdrop.right, progress),
        LerpInt(sourceRect.bottom, targetBackdrop.bottom, progress),
    };

    // Keep the overlay geometry exactly aligned to the XAML backdrop shell.
    // Exact shape matching looks better than an inset: the inset hid hard
    // native edges but made the blur layer disagree with the component shape,
    // so no extra XAML tint/gray layers are used.
    overlayRect = {
        popupScreenPx.left +
            static_cast<LONG>(std::lround(currentDip.left * dpiScale)),
        popupScreenPx.top +
            static_cast<LONG>(std::lround(currentDip.top * dpiScale)),
        popupScreenPx.left +
            static_cast<LONG>(std::lround(currentDip.right * dpiScale)),
        popupScreenPx.top +
            static_cast<LONG>(std::lround(currentDip.bottom * dpiScale)),
    };

    int width = overlayRect.right - overlayRect.left;
    int height = overlayRect.bottom - overlayRect.top;
    if (width <= 2 || height <= 2) {
        return false;
    }

    double targetRadiusDip =
        g_settings.compact
            ? PopupG2CornerRadius(targetBackdrop.right - targetBackdrop.left,
                                  targetBackdrop.bottom - targetBackdrop.top)
            : std::max(
                  1.0,
                  (IsLiquidGlassMaterial()
                       ? static_cast<double>(g_settings.liquidGlassCornerRadius)
                       : kPopupUnifiedCornerRadius) +
                      kPopupOverlayRadiusAdjustDip);
    double sourceRadiusDip = std::min(sourceRect.right - sourceRect.left,
                                      sourceRect.bottom - sourceRect.top) *
                             0.5;
    double radiusDip = LerpDouble(sourceRadiusDip, targetRadiusDip, progress);
    int desiredRadius = static_cast<int>(std::lround(radiusDip * dpiScale));
    cornerRadiusPx =
        Clamp(desiredRadius, 1, std::max(1, std::min(width, height) / 2));

    RECT currentCardDip{
        LerpInt(sourceRect.left, targetCard.left, progress),
        LerpInt(sourceRect.top, targetCard.top, progress),
        LerpInt(sourceRect.right, targetCard.right, progress),
        LerpInt(sourceRect.bottom, targetCard.bottom, progress),
    };
    RECT panelRect{
        static_cast<LONG>(std::lround(currentCardDip.left * dpiScale)) -
            static_cast<LONG>(std::lround(currentDip.left * dpiScale)),
        static_cast<LONG>(std::lround(currentCardDip.top * dpiScale)) -
            static_cast<LONG>(std::lround(currentDip.top * dpiScale)),
        static_cast<LONG>(std::lround(currentCardDip.right * dpiScale)) -
            static_cast<LONG>(std::lround(currentDip.left * dpiScale)),
        static_cast<LONG>(std::lround(currentCardDip.bottom * dpiScale)) -
            static_cast<LONG>(std::lround(currentDip.top * dpiScale)),
    };
    panelRect.left = Clamp<LONG>(panelRect.left, 0L, static_cast<LONG>(width));
    panelRect.top = Clamp<LONG>(panelRect.top, 0L, static_cast<LONG>(height));
    panelRect.right =
        Clamp<LONG>(panelRect.right, 0L, static_cast<LONG>(width));
    panelRect.bottom =
        Clamp<LONG>(panelRect.bottom, 0L, static_cast<LONG>(height));
    int panelWidth = static_cast<int>(panelRect.right - panelRect.left);
    int panelHeight = static_cast<int>(panelRect.bottom - panelRect.top);
    g_popupLiquidGlassPanelRectPx = panelRect;
    g_popupLiquidGlassPanelRadiusPx = Clamp(
        desiredRadius, 1, std::max(1, std::min(panelWidth, panelHeight) / 2));
    g_popupLiquidGlassPanelRectValid = panelWidth > 4 && panelHeight > 4;
    return true;
}

bool CalculatePopupBackdropOverlayTargetSize(int& targetWidthPx,
                                             int& targetHeightPx,
                                             int& targetRadiusPx) {
    if (!g_expandedPopup) {
        return false;
    }

    RECT popupScreenPx{};
    GetWindowRect(g_expandedPopup, &popupScreenPx);
    if (popupScreenPx.right <= popupScreenPx.left ||
        popupScreenPx.bottom <= popupScreenPx.top) {
        return false;
    }

    double dpiScale = PopupDpiScale(g_expandedPopup);
    DipRect finalRectDip =
        PopupScreenRectToLocalDip(g_popupFinalRect, popupScreenPx, dpiScale);
    RECT finalRect{static_cast<LONG>(std::lround(finalRectDip.left)),
                   static_cast<LONG>(std::lround(finalRectDip.top)),
                   static_cast<LONG>(std::lround(finalRectDip.right)),
                   static_cast<LONG>(std::lround(finalRectDip.bottom))};

    RECT targetArt{};
    RECT targetCard{};
    RECT targetTitle{};
    RECT targetArtist{};
    RECT targetProgress{};
    RECT targetElapsed{};
    RECT targetDuration{};
    RECT targetControls{};
    CalculatePopupFinalLayout(finalRect, targetArt, targetCard, targetTitle,
                              targetArtist, targetProgress, targetElapsed,
                              targetDuration, targetControls);
    RECT targetBackdrop = PopupBackdropRectFromParts(targetArt, targetCard);
    int targetWidthDip =
        std::max(1L, targetBackdrop.right - targetBackdrop.left);
    int targetHeightDip =
        std::max(1L, targetBackdrop.bottom - targetBackdrop.top);
    targetWidthPx =
        std::max(1, static_cast<int>(std::lround(targetWidthDip * dpiScale)));
    targetHeightPx =
        std::max(1, static_cast<int>(std::lround(targetHeightDip * dpiScale)));

    double targetRadiusDip =
        g_settings.compact
            ? PopupG2CornerRadius(targetBackdrop.right - targetBackdrop.left,
                                  targetBackdrop.bottom - targetBackdrop.top)
            : std::max(
                  1.0,
                  (IsLiquidGlassMaterial()
                       ? static_cast<double>(g_settings.liquidGlassCornerRadius)
                       : kPopupUnifiedCornerRadius) +
                      kPopupOverlayRadiusAdjustDip);
    targetRadiusPx =
        Clamp(static_cast<int>(std::lround(targetRadiusDip * dpiScale)), 1,
              std::max(1, std::min(targetWidthPx, targetHeightPx) / 2));
    return true;
}

void ApplyPopupBackdropOverlayRegion(int width,
                                     int height,
                                     int cornerRadiusPx) {
    if (!g_popupBackdropOverlay || width <= 0 || height <= 0) {
        return;
    }

    // System Acrylic is a window backdrop, so the HWND itself must carry the
    // animated rounded shape. Clearing the region here was the square mask
    // visible over the compact island on the last closing frame.
    int diameter = std::max(2, cornerRadiusPx * 2);
    HRGN region =
        CreateRoundRectRgn(0, 0, width + 1, height + 1, diameter, diameter);
    if (region) {
        if (!SetWindowRgn(g_popupBackdropOverlay, region, FALSE)) {
            DeleteObject(region);
        }
    }
}

void UpdatePopupBackdropOverlayWindow() {
    if (!UseOverlayPopupBackdropMaterial()) {
        HidePopupBackdropOverlayWindow();
        return;
    }
    if (!g_expandedPopup || !g_expanded) {
        HidePopupBackdropOverlayWindowVisualOnly();
        return;
    }
    if (!IsWindowVisible(g_expandedPopup) && !g_popupClosing) {
        return;
    }
    if (!EnsurePopupBackdropOverlayWindow()) {
        return;
    }

    // Liquid glass now uses the existing GPU desktop-capture pipeline with a
    // real D2D GaussianBlur effect. Native Acrylic is intentionally disabled:
    // it is a system material, not a controllable Gaussian filter.
    bool systemFrostOnly = false;
    if (systemFrostOnly) {
        LONG_PTR currentStyle =
            GetWindowLongPtrW(g_popupBackdropOverlay, GWL_EXSTYLE);
        LONG_PTR nativeStyle =
            (currentStyle & ~(WS_EX_NOREDIRECTIONBITMAP | WS_EX_LAYERED)) |
            WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE | WS_EX_TRANSPARENT;
        if (nativeStyle != currentStyle) {
            SetWindowLongPtrW(g_popupBackdropOverlay, GWL_EXSTYLE, nativeStyle);
            SetWindowPos(g_popupBackdropOverlay, nullptr, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
                             SWP_NOACTIVATE | SWP_FRAMECHANGED);
        }
    }

    if (systemFrostOnly &&
        (g_popupOverlayWgcRunning || g_popupOverlayDcompVisual)) {
        StopPopupOverlayWgcBackdrop();
    }

    // At the compact handoff the real taskbar island is already fully visible.
    // Retire the blur host before it can sit over that compact endpoint. This
    // is the same final-frame handoff, not a material cross-fade.
    if (systemFrostOnly && g_popupClosing &&
        g_popupCloseHandoffOpacity <= 0.02) {
        HidePopupBackdropOverlayWindowVisualOnly();
        return;
    }

    SetPopupOverlayNativeFrost(g_popupBackdropOverlay, false);

    // The material is one continuous surface. Never fade the glass independently
    // from its geometry; doing so exposed the transparent host on both ends.
    g_popupBackdropOverlayFrameAlpha.store(
        static_cast<int>(
            std::lround(PopupBackdropOverlayMaxAlpha() *
                        Clamp(g_popupCloseHandoffOpacity, 0.0, 1.0))),
        std::memory_order_relaxed);

    RECT overlayRect{};
    int cornerRadiusPx = 1;
    if (!CalculatePopupBackdropOverlayRect(overlayRect, cornerRadiusPx)) {
        HidePopupBackdropOverlayWindowVisualOnly();
        return;
    }

    int width = std::max(1L, overlayRect.right - overlayRect.left);
    int height = std::max(1L, overlayRect.bottom - overlayRect.top);
    int renderWidth = width;
    int renderHeight = height;
    int renderRadiusPx = cornerRadiusPx;
    bool morphing =
        std::abs(g_popupAnimationTarget - g_popupAnimationProgress) >= 0.006;
    if (morphing) {
        int targetWidth = width;
        int targetHeight = height;
        int targetRadius = cornerRadiusPx;
        if (CalculatePopupBackdropOverlayTargetSize(targetWidth, targetHeight,
                                                    targetRadius)) {
            renderWidth = targetWidth;
            renderHeight = targetHeight;
            // During the anisotropic morph the compositor clip supplies the
            // correct current radius. Keep the swap-chain mask essentially
            // rectangular so a final-state circular mask can't be squashed
            // into visibly flat/elliptical corners.
            renderRadiusPx = 1;
        }
    }

    PopupOverlayWgcRenderParameters renderParameters;
    renderParameters.targetRadiusPx = renderRadiusPx;
    renderParameters.morphing = morphing;
    renderParameters.allowScreenCapture = g_settings.allowScreenCapture;
    // The rebuilt material is a stable native frosted-glass surface. Keeping
    // lens refraction active caused delayed shader warm-up and a second visual
    // state to appear after opening.
    renderParameters.useLiquidLensWarp = false;
    renderParameters.blurStdDev =
        static_cast<float>(std::max(24, g_settings.liquidGlassFrost));
    renderParameters.refractionBlurStdDev = 0.0f;
    // Requested optical surface has no outer glow, rim stroke or edge shadow.
    renderParameters.liquidRimAlpha = 0.0f;

    if (!g_settings.allowScreenCapture) {
        SetExpandedPopupCaptureExclusion(true);
        SetPopupWindowCaptureExclusion(g_popupBackdropOverlay, true);
    }

    bool waitingForFreshGaussian =
        g_popupOverlayAwaitFreshFrame.load(std::memory_order_acquire);
    if (waitingForFreshGaussian) {
        // Suppress a parked swap-chain's old pixels while keeping the HWND's
        // native live Acrylic backdrop visible underneath.
        SetPopupOverlayDcompContentOpacity(0.0f);
    }

    bool overlayWasVisible = IsWindowVisible(g_popupBackdropOverlay) != FALSE;
    UINT overlayPosFlags = SWP_NOACTIVATE | SWP_NOCOPYBITS | SWP_NOOWNERZORDER |
                           SWP_NOSENDCHANGING;
    if (!overlayWasVisible) {
        overlayPosFlags |= SWP_SHOWWINDOW;
    }
    // Place the blur host behind the popup once per layout update. Keeping the
    // blur host above and then reordering the popup again every frame produced
    // the white small-to-large flashing rectangle.
    SetWindowPos(g_popupBackdropOverlay, HWND_BOTTOM, overlayRect.left,
                 overlayRect.top, width, height, overlayPosFlags);
    ApplyPopupBackdropOverlayRegion(width, height, cornerRadiusPx);
    UpdatePopupOverlayDcompVisualTransform(width, height, cornerRadiusPx);
    g_popupBackdropOverlayLastWidth = width;
    g_popupBackdropOverlayLastHeight = height;
    g_popupBackdropOverlayLastRadius = cornerRadiusPx;
    if (!overlayWasVisible) {
        ShowWindow(g_popupBackdropOverlay, SW_SHOWNOACTIVATE);
    }

    if (systemFrostOnly) {
        // One material from first frame to last frame: native live Acrylic.
        // Do not start, reveal or cross-fade any WGC/Gaussian swap-chain.
        g_popupOverlayAwaitFreshFrame = false;
        return;
    }

    if (g_settings.allowScreenCapture) {
        g_popupOverlayAwaitFreshFrame = false;
        if (!IsWindowVisible(g_popupBackdropOverlay)) {
            SetWindowPos(g_popupBackdropOverlay, g_expandedPopup,
                         overlayRect.left, overlayRect.top, width, height,
                         SWP_NOACTIVATE | SWP_NOCOPYBITS | SWP_NOOWNERZORDER |
                             SWP_NOSENDCHANGING | SWP_SHOWWINDOW);
        }
        if (g_popupOverlayWgcRunning) {
            StopPopupOverlayWgcBackdrop();
        }
        LONG_PTR fallbackStyle =
            GetWindowLongPtrW(g_popupBackdropOverlay, GWL_EXSTYLE);
        LONG_PTR fallbackDesiredStyle =
            (fallbackStyle & ~WS_EX_NOREDIRECTIONBITMAP) | WS_EX_LAYERED |
            WS_EX_TRANSPARENT | WS_EX_NOACTIVATE | WS_EX_TOOLWINDOW;
        if (fallbackDesiredStyle != fallbackStyle) {
            SetWindowLongPtrW(g_popupBackdropOverlay, GWL_EXSTYLE,
                              fallbackDesiredStyle);
        }
        bool captureAffinityChanged = SetExpandedPopupCaptureExclusion(true);
        captureAffinityChanged =
            SetPopupWindowCaptureExclusion(g_popupBackdropOverlay, true) ||
            captureAffinityChanged;
        if (captureAffinityChanged) {
            DwmFlush();
        }
        bool forceSnapshot =
            !g_popupBackdropOverlayFallbackPixelsValid ||
            g_popupBackdropOverlayFallbackWidth != width ||
            g_popupBackdropOverlayFallbackHeight != height ||
            !EqualRect(&g_popupBackdropOverlayFallbackRect, &overlayRect);
        UpdatePopupBackdropOverlayLayeredBlur(g_popupBackdropOverlay,
                                              overlayRect, width, height,
                                              cornerRadiusPx, forceSnapshot);
        g_popupOverlayWgcFallbackPainted = true;
        SetPopupWindowCaptureExclusion(g_popupBackdropOverlay, false);
        SetExpandedPopupCaptureExclusion(false);
        return;
    }

    if (!g_popupOverlayWgcRunning && g_popupOverlayWgcFallbackPainted) {
        ClearPopupBackdropOverlayLayeredSurface(g_popupBackdropOverlay);
        g_popupOverlayWgcFallbackPainted = false;
    }
    LONG_PTR dcompStyle =
        GetWindowLongPtrW(g_popupBackdropOverlay, GWL_EXSTYLE);
    LONG_PTR dcompDesiredStyle = (dcompStyle & ~WS_EX_LAYERED) |
                                 WS_EX_TRANSPARENT | WS_EX_NOACTIVATE |
                                 WS_EX_TOOLWINDOW | WS_EX_NOREDIRECTIONBITMAP;
    if (dcompDesiredStyle != dcompStyle) {
        SetWindowLongPtrW(g_popupBackdropOverlay, GWL_EXSTYLE,
                          dcompDesiredStyle);
    }
    StartPopupOverlayWgcBackdrop(overlayRect, renderWidth, renderHeight,
                                 renderParameters);
    UpdatePopupOverlayDcompVisualTransform(width, height, cornerRadiusPx);

    if (g_popupOverlayAwaitFreshFrame.load(std::memory_order_acquire)) {
        // StartPopupOverlayWgcBackdrop may have just created a new visual; keep
        // its stale/empty swap-chain hidden until the first new present.
        SetPopupOverlayDcompContentOpacity(0.0f);
    }

    if (g_popupOverlayAwaitFreshFrame) {
        bool hasNewPresent =
            g_popupOverlayWgcPresentedSerial.load(std::memory_order_acquire) >
            g_popupOverlayFreshFrameStartSerial;
        bool hasNewGeometry = g_popupOverlayWgcPresentedGeometryGeneration.load(
                                  std::memory_order_acquire) >
                              g_popupOverlayFreshFrameStartGeneration;
        if (hasNewPresent && hasNewGeometry) {
            g_popupOverlayAwaitFreshFrame = false;
            SetPopupOverlayDcompContentOpacity(1.0f);
        }
    }
    if (!g_popupOverlayAwaitFreshFrame.load(std::memory_order_acquire)) {
        SetPopupOverlayDcompContentOpacity(1.0f);
    }
    if (!IsWindowVisible(g_popupBackdropOverlay)) {
        SetWindowPos(g_popupBackdropOverlay, g_expandedPopup, overlayRect.left,
                     overlayRect.top, width, height,
                     SWP_NOACTIVATE | SWP_NOCOPYBITS | SWP_NOOWNERZORDER |
                         SWP_NOSENDCHANGING | SWP_SHOWWINDOW);
        ShowWindow(g_popupBackdropOverlay, SW_SHOWNOACTIVATE);
    }
}

// ===== Popup hit window and lifecycle =====
LRESULT CALLBACK PopupToggleHitWindowWndProc(HWND hwnd,
                                             UINT message,
                                             WPARAM wParam,
                                             LPARAM lParam) {
    switch (message) {
        case WM_NCHITTEST:
            return HTCLIENT;
        case WM_MOUSEACTIVATE:
            return MA_NOACTIVATE;
        case WM_ERASEBKGND:
            return 1;
        case WM_PAINT: {
            PAINTSTRUCT paint{};
            BeginPaint(hwnd, &paint);
            FillRect(paint.hdc, &paint.rcPaint,
                     reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH)));
            EndPaint(hwnd, &paint);
            return 0;
        }
        case WM_LBUTTONDOWN:
            KeepPopupOnTop();
            // Toggle on the down edge. The click that originally opens the
            // popup can release over this newly-created window; handling that
            // release used to reverse the animation immediately and made a
            // normal click look like a required long press.
            if (g_popupRestingCompact) {
                ResumeOpenExpandedPopup();
            } else if (g_expanded && g_popupClosing) {
                ResumeOpenExpandedPopup();
            } else if (g_expanded) {
                BeginCloseExpandedPopup();
            }
            return 0;
        case WM_LBUTTONUP:
            return 0;
        case WM_MOUSEMOVE: {
            TRACKMOUSEEVENT track{sizeof(track), TME_LEAVE, hwnd, 0};
            TrackMouseEvent(&track);
            if (g_popupRestingCompact) {
                g_popupCompactHoverTarget = g_settings.hoverScale;
                StartPopupPlaybackIndicatorRenderLoop();
            }
            return 0;
        }
        case WM_MOUSELEAVE:
            g_popupCompactHoverTarget = 1.0;
            if (g_popupRestingCompact) {
                StartPopupPlaybackIndicatorRenderLoop();
            }
            return 0;
        case WM_SETCURSOR:
            SetCursor(LoadCursorW(nullptr, IDC_HAND));
            return TRUE;
    }
    return DefWindowProcW(hwnd, message, wParam, lParam);
}

bool RegisterPopupToggleHitWindowClass() {
    if (g_popupToggleHitWindowClassRegistered) {
        return true;
    }
    HINSTANCE moduleInstance = ModInstance();
    if (!moduleInstance) {
        return false;
    }

    WNDCLASSEXW windowClass{sizeof(windowClass)};
    windowClass.lpfnWndProc = PopupToggleHitWindowWndProc;
    windowClass.hInstance = moduleInstance;
    windowClass.hCursor = LoadCursorW(nullptr, IDC_HAND);
    windowClass.lpszClassName = kPopupToggleHitWindowClassName;
    if (!RegisterClassExW(&windowClass)) {
        Wh_Log(L"Island: failed to register permanent toggle hit window");
        return false;
    }
    g_popupToggleHitWindowClassRegistered = true;
    return true;
}

bool EnsurePopupToggleHitWindow() {
    if (g_popupToggleHitWindow && IsWindow(g_popupToggleHitWindow)) {
        return true;
    }
    g_popupToggleHitWindow = nullptr;
    if (!RegisterPopupToggleHitWindowClass()) {
        return false;
    }

    // Owned by the taskbar, same as the popup and the blur overlay: the hit
    // window inherits the taskbar's topmost band and can never drop below it.
    HWND hitOwner = g_taskbarWnd && IsWindow(g_taskbarWnd)
                        ? g_taskbarWnd
                        : FindCurrentProcessTaskbarWnd();
    g_popupToggleHitWindow =
        CreateWindowExW(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
                        kPopupToggleHitWindowClassName, L"", WS_POPUP, 0, 0, 1,
                        1, hitOwner, nullptr, ModInstance(), nullptr);
    if (!g_popupToggleHitWindow) {
        Wh_Log(L"Island: failed to create permanent toggle hit window");
        return false;
    }

    // A uniform alpha of 1/255 is visually imperceptible but, unlike a fully
    // transparent layered window, remains a real mouse hit target.
    SetLayeredWindowAttributes(g_popupToggleHitWindow, 0, 1, LWA_ALPHA);
    return true;
}

bool ShowPopupToggleHitWindow() {
    if (!EnsurePopupToggleHitWindow()) {
        return false;
    }
    int width = std::max(1L, g_popupSourceRect.right - g_popupSourceRect.left);
    int height = std::max(1L, g_popupSourceRect.bottom - g_popupSourceRect.top);
    SetWindowPos(g_popupToggleHitWindow, HWND_TOP, g_popupSourceRect.left,
                 g_popupSourceRect.top, width, height,
                 SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOOWNERZORDER |
                     SWP_NOSENDCHANGING);
    return IsWindowVisible(g_popupToggleHitWindow) != FALSE;
}

void HidePopupToggleHitWindow() {
    if (!g_popupToggleHitWindow) {
        return;
    }
    if (GetCapture() == g_popupToggleHitWindow) {
        ReleaseCapture();
    }
    ShowWindow(g_popupToggleHitWindow, SW_HIDE);
}

void DestroyPopupToggleHitWindow() {
    if (!g_popupToggleHitWindow) {
        return;
    }
    if (GetCapture() == g_popupToggleHitWindow) {
        ReleaseCapture();
    }
    DestroyWindow(g_popupToggleHitWindow);
    g_popupToggleHitWindow = nullptr;
}

bool RegisterPopupWindowClass() {
    if (g_popupClassRegistered) {
        return true;
    }

    HINSTANCE moduleInstance = ModInstance();
    if (!moduleInstance) {
        Wh_Log(L"Island: failed to resolve the mod module handle");
        return false;
    }

    WNDCLASSEXW windowClass{sizeof(windowClass)};
    windowClass.lpfnWndProc = ExpandedPopupWndProc;
    windowClass.style = 0;
    windowClass.hInstance = moduleInstance;
    windowClass.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    windowClass.lpszClassName = kPopupClassName;
    if (!RegisterClassExW(&windowClass)) {
        Wh_Log(L"Island: failed to register expanded popup window class");
        return false;
    }

    g_popupClassRegistered = true;
    return true;
}

void UnregisterPopupWindowClass() {
    UnregisterPopupBackdropOverlayClass();
    HINSTANCE moduleInstance = ModInstance();
    if (moduleInstance && g_popupToggleHitWindowClassRegistered &&
        UnregisterClassW(kPopupToggleHitWindowClassName, moduleInstance)) {
        g_popupToggleHitWindowClassRegistered = false;
    }
    if (moduleInstance && g_popupClassRegistered &&
        UnregisterClassW(kPopupClassName, moduleInstance)) {
        g_popupClassRegistered = false;
    }
}

bool EnsureExpandedPopup() {
    if (g_expandedPopup) {
        return true;
    }

    if (!RegisterPopupWindowClass()) {
        return false;
    }

    HWND popupOwner = g_taskbarWnd && IsWindow(g_taskbarWnd)
                          ? g_taskbarWnd
                          : FindCurrentProcessTaskbarWnd();
    RECT ownerRect{};
    int initialX = 0;
    int initialY = 0;
    if (popupOwner && GetWindowRect(popupOwner, &ownerRect)) {
        g_taskbarWnd = popupOwner;
        initialX = ownerRect.left;
        initialY = ownerRect.top;
    }
    int initialWidth =
        std::max(1, PopupDipToPx(g_layout.compactWidth, popupOwner));
    int initialHeight =
        std::max(1, PopupDipToPx(g_layout.compactHeight, popupOwner));

    g_expandedPopup = CreateWindowExW(
        WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE | WS_EX_NOREDIRECTIONBITMAP,
        kPopupClassName, L"", WS_POPUP, initialX, initialY, initialWidth,
        initialHeight,
        // Owned by the taskbar: Shell_TrayWnd is WS_EX_TOPMOST, so the popup
        // is in the topmost band and Windows enforces "never below the
        // taskbar". We never re-assert TOPMOST on it (only HWND_TOP within
        // the band), so the owner is never dragged and there is no flicker.
        popupOwner, nullptr, ModInstance(), nullptr);
    if (!g_expandedPopup) {
        return false;
    }
    BOOL useHostBackdropBrush = TRUE;
    HRESULT hostBackdropResult = DwmSetWindowAttribute(
        g_expandedPopup, kDwmwaUseHostBackdropBrush, &useHostBackdropBrush,
        sizeof(useHostBackdropBrush));
    Wh_Log(L"Host backdrop brush enabled: hwnd=%p hr=0x%08X", g_expandedPopup,
           static_cast<unsigned int>(hostBackdropResult));
    if (!InitializePopupXamlHost(g_expandedPopup)) {
        auto style = GetWindowLongPtrW(g_expandedPopup, GWL_EXSTYLE);
        style &= ~static_cast<LONG_PTR>(WS_EX_NOREDIRECTIONBITMAP);
        SetWindowLongPtrW(g_expandedPopup, GWL_EXSTYLE, style | WS_EX_LAYERED);
    }
    ApplyPopupBackdrop(g_expandedPopup);
    return true;
}

void UpdatePlayerContents();

void ShowExpandedPopup() {
    g_expandedPopupCaptureExcluded = false;
    g_popupXamlChildCaptureExcluded = false;
    g_popupBackdropOverlayCaptureExcluded = false;
    if (!EnsureExpandedPopup()) {
        g_expanded = false;
        return;
    }

    g_expanded = true;
    g_popupClosing = false;
    g_popupRestingCompact = false;
    g_popupRidingTaskbarUp = false;
    StopPopupPlaybackIndicatorRenderLoop();
    ClearPopupCompactWindowRegions();
    g_popupLifecycleState = PopupLifecycleState::Opening;
    g_popupTransparentParkPending = false;
    SetPopupWindowClickThrough(g_expandedPopup, false);
    SetPopupWindowClickThrough(g_popupXamlChild, false);
    g_popupOutsideClickArmed = false;
    CapturePopupSourceGeometry();
    g_popupHostRect = UnionPopupRects(g_popupSourceRect, g_popupFinalRect);
    g_popupAnimationProgress = 0.0;
    g_popupAnimationTarget = 1.0;
    g_popupAnimationVelocity = 0.0;
    // Never reveal a parked overlay with the previous popup's swap-chain
    // contents. Keep it hidden until WGC presents a frame captured after this
    // opening transaction began.
    HidePopupBackdropOverlayWindowVisualOnly();
    g_popupOverlayAwaitFreshFrame = true;
    g_popupOverlayFreshFrameStartSerial =
        g_popupOverlayWgcPresentedSerial.load(std::memory_order_acquire);
    g_popupOverlayFreshFrameStartGeneration =
        g_popupOverlayWgcGeometryGeneration.load(std::memory_order_acquire);
    g_popupCurrentWidth =
        static_cast<double>(g_popupSourceRect.right - g_popupSourceRect.left);
    g_popupCurrentHeight =
        static_cast<double>(g_popupSourceRect.bottom - g_popupSourceRect.top);
    g_popupTargetWidth = g_popupExpandedWidth;
    g_popupTargetHeight = g_popupExpandedHeight;
    g_lastPopupVisualProgress = -1.0;
    g_lastPopupVisualRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_popupPendingContentRefresh = false;
    if (g_popupXamlRoot) {
        g_popupXamlRoot.Opacity(1.0);
        UpdatePlayerContents();
    } else {
        UpdatePopupAlbumBitmap(SnapshotMedia());
    }
    ApplyPopupBackdrop(g_expandedPopup);
    PositionExpandedPopup();
    RenderExpandedPopupLayer();
    PrepareCompactIslandForPopupMorph();
    ShowWindow(g_expandedPopup, SW_SHOWNOACTIVATE);
    ShowPopupToggleHitWindow();
    KeepPopupOnTop();
    if (!g_settings.allowScreenCapture) {
        if (SetExpandedPopupCaptureExclusion(true)) {
            DwmFlush();
        }
    }
    // Re-apply after the popup becomes visible so the overlay is placed directly
    // under the popup in the active top-level z-order.
    UpdatePopupBackdropOverlayWindow();
    SetTimer(g_expandedPopup, kPopupTimerId, g_popupXamlRoot ? 30 : 15,
             nullptr);
    if (g_popupXamlRoot) {
        StartPopupXamlRenderLoop();
    }
}

void DestroyExpandedPopup() {
    StopPopupXamlRenderLoop();
    UnsubclassPopupXamlChildWindow();
    DestroyPopupToggleHitWindow();
    DestroyPopupBackdropOverlayWindow();
    SetCompactIslandSuppressed(false);
    if (g_popupXamlSource) {
        try {
            g_popupXamlSource.Content(nullptr);
            g_popupXamlSource.Close();
        } catch (...) {
        }
    }
    g_popupXamlSource = nullptr;
    g_popupXamlChild = nullptr;
    g_popupXamlChildSubclassed = false;
    g_popupXamlChildCaptureExcluded = false;
    g_popupXamlRoot = nullptr;
    g_popupXamlCanvas = nullptr;
    g_popupXamlShadow = nullptr;
    g_popupXamlShadowVisual = nullptr;
    g_popupXamlDropShadow = nullptr;
    g_popupXamlBackdrop = nullptr;
    g_popupXamlBackdropScale = nullptr;
    g_popupXamlBackdropTranslate = nullptr;
    g_popupXamlBackdropCoverFade = nullptr;
    g_popupXamlBackdropCover = nullptr;
    g_popupXamlBackdropTint = nullptr;
    g_popupXamlBackdropSurfaceHighlight = nullptr;
    g_popupXamlBackdropRimHighlight = nullptr;
    g_popupBackdropBlurActive = false;
    g_popupXamlPanelCoverFrame = nullptr;
    g_popupXamlPanelCoverScale = nullptr;
    g_popupXamlPanelCoverTranslate = nullptr;
    g_popupXamlPanelCoverFade = nullptr;
    g_popupXamlPanelCover = nullptr;
    g_popupXamlPanel = nullptr;
    g_popupXamlPanelScale = nullptr;
    g_popupXamlPanelTranslate = nullptr;
    g_popupXamlArtFrame = nullptr;
    g_popupXamlArtClipGeometry = nullptr;
    g_popupXamlArtGeometricClip = nullptr;
    g_popupXamlArtScale = nullptr;
    g_popupXamlArtTranslate = nullptr;
    g_popupXamlArtFade = nullptr;
    g_popupXamlArt = nullptr;
    g_popupXamlTitleHost = nullptr;
    g_popupXamlArtistHost = nullptr;
    g_popupXamlPlaybackIndicator = nullptr;
    g_popupXamlPlaybackBars.clear();
    g_popupXamlPlaybackAccentBrush = nullptr;
    g_popupXamlPlaybackRevealClip = nullptr;
    g_popupXamlCompactHoverScale = nullptr;
    g_popupXamlOutgoingTitleHost = nullptr;
    g_popupXamlOutgoingArtistHost = nullptr;
    g_popupXamlTitleLeftFade = nullptr;
    g_popupXamlTitleRightFade = nullptr;
    g_popupXamlArtistLeftFade = nullptr;
    g_popupXamlArtistRightFade = nullptr;
    g_popupXamlOutgoingTitleLeftFade = nullptr;
    g_popupXamlOutgoingTitleRightFade = nullptr;
    g_popupXamlOutgoingArtistLeftFade = nullptr;
    g_popupXamlOutgoingArtistRightFade = nullptr;
    g_popupXamlTitle = nullptr;
    g_popupXamlArtist = nullptr;
    g_popupXamlOutgoingTitle = nullptr;
    g_popupXamlOutgoingArtist = nullptr;
    g_popupXamlTitleTranslate = nullptr;
    g_popupXamlArtistTranslate = nullptr;
    g_popupXamlOutgoingTitleTranslate = nullptr;
    g_popupXamlOutgoingArtistTranslate = nullptr;
    g_popupTextBaseOpacity = 1.0;
    g_popupTextTransitionActive = false;
    g_popupXamlElapsed = nullptr;
    g_popupXamlDuration = nullptr;
    g_popupXamlProgress = nullptr;
    g_popupXamlProgressScale = nullptr;
    g_popupXamlProgressTrack = nullptr;
    g_popupXamlProgressFill = nullptr;
    g_popupXamlProgressHitTarget = nullptr;
    g_popupXamlProgressGlowMask = nullptr;
    g_popupXamlProgressGlowClip = nullptr;
    g_popupXamlProgressGlowLayers.clear();
    g_popupXamlProgressCoreBlurLayers.clear();
    g_popupXamlProgressGlowCore = nullptr;
    g_popupXamlControls = nullptr;
    g_popupXamlThumbnailHash = UINT64_MAX;
    g_popupXamlBackdropCoverEnabled = false;
    g_popupAccentThumbnailHash = UINT64_MAX;
    g_popupAccentColorValid = false;
    g_popupAccentColor = DefaultPopupAccentColor();
    g_popupDisplayedAccentColorValid = false;
    g_popupDisplayedAccentColor = DefaultPopupAccentColor();
    g_popupAccentTransitionFrom = DefaultPopupAccentColor();
    g_popupAccentTransitionTo = DefaultPopupAccentColor();
    g_popupMediaTransitionProgress = 1.0;
    g_popupMediaTransitionActive = false;
    g_popupCoverTransitionActive = false;
    g_popupTextTransitionActive = false;
    g_popupXamlThemeValid = false;
    g_popupXamlThemeMaterial.clear();
    g_popupXamlThemeShadowDepth = -1;
    g_popupXamlThemeShadowOpacity = -1;
    if (g_expandedPopup) {
        DestroyWindow(g_expandedPopup);
        g_expandedPopup = nullptr;
    }
    if (g_popupAlbumBitmap) {
        DeleteObject(g_popupAlbumBitmap);
        g_popupAlbumBitmap = nullptr;
    }
    g_popupThumbnailHash = 0;
    g_popupPendingContentRefresh = false;
    g_lastPopupVisualProgress = -1.0;
    g_lastPopupVisualRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_lastPopupWindowRect = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    g_expanded = false;
    g_popupXamlThemeValid = false;
    g_popupXamlThemeMaterial.clear();
    g_popupXamlThemeShadowDepth = -1;
    g_popupXamlThemeShadowOpacity = -1;
    UnregisterPopupWindowClass();
}

void UpdatePlayerContents();

// ===== Hover and expanded state =====
void StopHoverRenderLoop() {
    if (g_hoverRenderingHooked) {
        try {
            mediax::CompositionTarget::Rendering(g_hoverRenderingToken);
        } catch (...) {
        }
        g_hoverRenderingHooked = false;
    }
}

void OnHoverRendering(winrt::Windows::Foundation::IInspectable const&,
                      winrt::Windows::Foundation::IInspectable const&) {
    try {
        if (!g_islandScale || g_unloading) {
            StopHoverRenderLoop();
            return;
        }

        auto now = std::chrono::steady_clock::now();
        double dtSec = 1.0 / 60.0;
        if (g_lastHoverFrameTime.time_since_epoch().count() != 0) {
            dtSec = std::chrono::duration_cast<std::chrono::microseconds>(
                        now - g_lastHoverFrameTime)
                        .count() /
                    1000000.0;
        }
        g_lastHoverFrameTime = now;
        dtSec = Clamp(dtSec, 0.0, 0.05);

        double alpha = 1.0 - std::exp(-g_settings.hoverLerpSpeed * dtSec);
        alpha = Clamp(alpha, 0.0, 1.0);
        g_currentHoverScale +=
            (g_targetHoverScale - g_currentHoverScale) * alpha;

        if (std::abs(g_targetHoverScale - g_currentHoverScale) < 0.001) {
            g_currentHoverScale = g_targetHoverScale;
        }

        g_islandScale.ScaleX(g_currentHoverScale);
        g_islandScale.ScaleY(g_currentHoverScale);

        if (std::abs(g_targetHoverScale - g_currentHoverScale) < 0.001) {
            StopHoverRenderLoop();
            g_lastHoverFrameTime = {};
        }
    } catch (...) {
        StopHoverRenderLoop();
    }
}

void StartHoverRenderLoop(double targetScale) {
    g_targetHoverScale = targetScale;
    if (!g_islandScale) {
        return;
    }

    if (!g_hoverRenderingHooked) {
        g_lastHoverFrameTime = std::chrono::steady_clock::now();
        g_hoverRenderingToken =
            mediax::CompositionTarget::Rendering(OnHoverRendering);
        g_hoverRenderingHooked = true;
    }
}

// ===== Compact arc spin toggle =====
// A short accent-coloured arc hugging the right side of the circular cover.
// It is concentric with the cover but only sweeps 90 degrees on the right
// (y-down angles -45..+45), so the artwork keeps its exact size/position and
// the arc never draws over it. The arc lives in its own transparent hit grid;
// only ring-band taps are consumed, so taps on the cover itself still open the
// expanded player. Spinning the art is a RenderTransform only, no layout work.
constexpr double kCompactArcStartDeg = -40.0;
constexpr double kCompactArcSweepDeg = 80.0;

mediax::PathGeometry MakeCompactArcGeometry(double centerX,
                                            double centerY,
                                            double radius,
                                            double startDeg,
                                            double sweepDeg) {
    constexpr double kPi = 3.14159265358979323846;
    auto pointAt = [&](double deg) {
        double rad = deg * kPi / 180.0;
        return winrt::Windows::Foundation::Point{
            static_cast<float>(centerX + radius * std::cos(rad)),
            static_cast<float>(centerY + radius * std::sin(rad))};
    };

    mediax::PathFigure figure;
    figure.StartPoint(pointAt(startDeg));
    figure.IsClosed(false);

    mediax::ArcSegment segment;
    segment.Point(pointAt(startDeg + sweepDeg));
    segment.Size({static_cast<float>(radius), static_cast<float>(radius)});
    // Angles increase clockwise on screen (y grows downward), so a positive
    // sweep maps to a clockwise arc; 90 degrees is never the large arc.
    segment.SweepDirection(sweepDeg >= 0.0
                               ? mediax::SweepDirection::Clockwise
                               : mediax::SweepDirection::Counterclockwise);
    segment.IsLargeArc(std::abs(sweepDeg) > 180.0);
    figure.Segments().Append(segment);

    mediax::PathGeometry geometry;
    geometry.Figures().Append(figure);
    return geometry;
}

// r = artSize / 2 + coverGap + stroke / 2: the stroke's inner edge clears the
// cover by coverGap, and its outer edge sits at artSize/2+coverGap+stroke.
double CompactArcRadius(CompactVisualSpec const& spec) {
    return spec.artSize * 0.5 + spec.arcToggleCoverGap +
           spec.arcToggleStroke * 0.5;
}

// Hit test in the overlay's local DIP space: the point must be inside the
// short right-side arc band (distance tolerance plus the -45..+45 wedge).
bool CompactArcRingHitTest(winrt::Windows::Foundation::Point const& point) {
    if (!g_compactArcToggle) {
        return false;
    }

    auto spec = CurrentCompactVisualSpec();
    double width = g_compactArcToggle.ActualWidth();
    if (width <= 0.0) {
        width = g_compactArcToggle.Width();
    }
    double height = g_compactArcToggle.ActualHeight();
    if (height <= 0.0) {
        height = g_compactArcToggle.Height();
    }
    if (width <= 0.0 || height <= 0.0) {
        return false;
    }

    double dx = static_cast<double>(point.X) - width * 0.5;
    double dy = static_cast<double>(point.Y) - height * 0.5;
    double distance = std::sqrt(dx * dx + dy * dy);
    double radius = CompactArcRadius(spec);
    double tolerance = spec.arcToggleStroke * 0.5 + 4.0;
    if (std::abs(distance - radius) > tolerance) {
        return false;
    }

    constexpr double kPi = 3.14159265358979323846;
    double angleDeg = std::atan2(dy, dx) * 180.0 / kPi;
    return angleDeg >= kCompactArcStartDeg &&
           angleDeg <= kCompactArcStartDeg + kCompactArcSweepDeg;
}

void ApplyCompactArcToggleLayout() {
    if (!g_compactArcToggle || !g_compactArcPath) {
        return;
    }

    try {
        auto spec = CurrentCompactVisualSpec();
        double stroke = spec.arcToggleStroke;
        double radius = CompactArcRadius(spec);
        // The overlay must at least cover the cover plus the base tolerance
        // padding, and it must be large enough that the full ring hit band
        // (radius +/- (stroke/2 + 4 DIP)) is reachable, otherwise the hit
        // tolerance would be silently clipped by the overlay bounds.
        double overlaySize = std::max(spec.artSize + stroke * 2.0 + 8.0,
                                      2.0 * (radius + stroke * 0.5 + 4.0));
        double center = overlaySize * 0.5;
        double centerX = spec.artInset + spec.artSize * 0.5;
        double centerY = spec.height * 0.5;

        g_compactArcToggle.Width(overlaySize);
        g_compactArcToggle.Height(overlaySize);
        g_compactArcToggle.Margin({centerX - overlaySize * 0.5,
                                   centerY - overlaySize * 0.5, 0.0, 0.0});

        // Keep the transparent hit area inside the pill so the extra tap
        // tolerance cannot make clicks just outside the island expand it.
        mediax::RectangleGeometry hitClip;
        hitClip.Rect({static_cast<float>(center - centerX),
                      static_cast<float>(center - centerY),
                      static_cast<float>(spec.width),
                      static_cast<float>(spec.height)});
        g_compactArcToggle.Clip(hitClip);

        // The arc must use exactly the compact equalizer accent: share one
        // solid brush with the bars and keep its colour synced in
        // ApplyCompactPlaybackAccentColor.
        if (g_compactArcAccentBrush) {
            g_compactArcAccentBrush.Color(g_compactPlaybackAccentDisplayed);
            g_compactArcPath.Stroke(g_compactArcAccentBrush);
        }
        g_compactArcPath.Width(overlaySize);
        g_compactArcPath.Height(overlaySize);
        g_compactArcPath.StrokeThickness(stroke);
        g_compactArcPath.StrokeStartLineCap(mediax::PenLineCap::Round);
        g_compactArcPath.StrokeEndLineCap(mediax::PenLineCap::Round);
        g_compactArcPath.StrokeLineJoin(mediax::PenLineJoin::Round);
        g_compactArcPath.Data(MakeCompactArcGeometry(
            center, center, radius, kCompactArcStartDeg, kCompactArcSweepDeg));
    } catch (...) {
    }
}

void ApplyExpandedState() {
    if (!g_playerGrid) {
        return;
    }

    auto spec = CurrentCompactVisualSpec();
    g_playerGrid.Width(spec.width);
    g_playerGrid.Height(spec.height);
    g_playerGrid.MinHeight(spec.height);

    if (auto backgroundFe =
            FindChildByName(g_playerGrid, L"Island_Background")) {
        if (auto background = backgroundFe.try_as<Border>()) {
            ApplyCompactSurfaceVisual(background);
        }
    }

    ReadDefaultOutputVolume(g_popupSystemVolume);

    if (auto contentFe = FindChildByName(g_playerGrid, L"Island_Content")) {
        // Same concentric-cover layout as BuildIslandGrid: art starts at
        // (H - D)/2 from the pill's left/top edge.
        contentFe.Margin({spec.artInset, spec.contentMarginY,
                          spec.contentMarginX, spec.contentMarginY});
        if (auto content = contentFe.try_as<Grid>()) {
            if (content.ColumnDefinitions().Size() > 0) {
                content.ColumnDefinitions().GetAt(0).Width(
                    {spec.artColumnWidth, GridUnitType::Pixel});
            }
        }
    }
    ApplyCompactArcToggleLayout();

    if (auto details = FindChildByName(g_playerGrid, L"Island_Details")) {
        details.Visibility(Visibility::Collapsed);
        details.IsHitTestVisible(false);
        details.Opacity(0.0);
    }
    if (auto compactArtist =
            FindChildByName(g_playerGrid, L"Island_CompactArtist")) {
        compactArtist.Visibility(Visibility::Visible);
        compactArtist.Opacity(1.0);
    }

    if (auto textHost = FindChildByName(g_playerGrid, L"Island_TextHost")) {
        textHost.Margin({spec.textMarginX, 0, 4.0, 0});
    }
    RefreshCompactTextHostClip(false);

    auto updateTextBlockSize = [](wchar_t const* name, double fontSize) {
        if (auto fe = FindChildByName(g_playerGrid, name)) {
            if (auto text = fe.try_as<TextBlock>()) {
                text.FontSize(fontSize);
            }
        }
    };
    updateTextBlockSize(L"Island_Title", spec.titleFontSize);
    updateTextBlockSize(L"Island_OutgoingTitle", spec.titleFontSize);
    updateTextBlockSize(L"Island_CompactArtist", spec.artistFontSize);
    updateTextBlockSize(L"Island_OutgoingCompactArtist", spec.artistFontSize);

    if (auto artFe = FindChildByName(g_playerGrid, L"Island_ArtFallback")) {
        artFe.Width(g_layout.artSize);
        artFe.Height(g_layout.artSize);
        if (auto art = artFe.try_as<Border>()) {
            art.CornerRadius(
                {g_layout.artCornerRadius, g_layout.artCornerRadius,
                 g_layout.artCornerRadius, g_layout.artCornerRadius});
        }
    }
    if (auto artShellFe = FindChildByName(g_playerGrid, L"Island_ArtShell")) {
        artShellFe.Width(g_layout.artSize);
        artShellFe.Height(g_layout.artSize);
    }
    if (auto artHostFe = FindChildByName(g_playerGrid, L"Island_ArtHost")) {
        artHostFe.Width(g_layout.artSize);
        artHostFe.Height(g_layout.artSize);
        ApplyElementCircularClip(artHostFe, g_layout.artSize);
    }
    if (auto placeholderFe =
            FindChildByName(g_playerGrid, L"Island_ArtPlaceholder")) {
        placeholderFe.Width(g_layout.artSize);
        placeholderFe.Height(g_layout.artSize);
        if (auto placeholder = placeholderFe.try_as<Border>()) {
            placeholder.CornerRadius(
                {g_layout.artCornerRadius, g_layout.artCornerRadius,
                 g_layout.artCornerRadius, g_layout.artCornerRadius});
        }
    }
    if (auto imageFe = FindChildByName(g_playerGrid, L"Island_AlbumArt")) {
        imageFe.Width(g_layout.artImageSize);
        imageFe.Height(g_layout.artImageSize);
        imageFe.Margin({-1, -1, -1, -1});
    }
    if (auto fadeFe = FindChildByName(g_playerGrid, L"Island_AlbumArtFade")) {
        fadeFe.Width(g_layout.artImageSize);
        fadeFe.Height(g_layout.artImageSize);
        fadeFe.Margin({-1, -1, -1, -1});
    }
    if (auto strokeFe = FindChildByName(g_playerGrid, L"Island_ArtStroke")) {
        if (auto stroke = strokeFe.try_as<Border>()) {
            ConfigureCompactAlbumArtStroke(stroke);
        }
    }

    if (g_compactProgress) {
        g_compactProgress.Width(g_layout.progressWidth);
        g_compactProgress.Height(g_layout.progressHeight);
        g_compactProgress.Margin({g_layout.progressMarginLeft, 0, 0, 0});
    }
    if (auto indicator =
            FindChildByName(g_playerGrid, L"Island_PlaybackIndicator")) {
        indicator.Width(g_layout.playbackIndicatorWidth);
        indicator.Height(g_layout.playbackIndicatorHeight);
        indicator.Margin({g_layout.playbackIndicatorMarginLeft, 0, 0, 0});
        indicator.Visibility(Visibility::Visible);
    }
    if (auto barsHost = FindChildByName(g_playerGrid, L"Island_PlaybackBars")) {
        barsHost.Height(g_layout.playbackIndicatorHeight);
        barsHost.VerticalAlignment(VerticalAlignment::Center);
    }
    for (auto const& bar : g_compactPlaybackBars) {
        bar.Width(g_layout.playbackBarWidth);
        bar.Margin({g_layout.playbackBarGap * 0.5, 0,
                    g_layout.playbackBarGap * 0.5, 0});
        double radius = g_layout.playbackBarWidth * 0.5;
        bar.CornerRadius({radius, radius, radius, radius});
    }
    SetCompactPlaybackIndicatorState(g_compactPlaybackDesiredPlaying);
}

void EnsureCompactIslandInteractive() {
    if (!g_playerGrid || g_unloading) {
        return;
    }
    if (g_expanded || g_popupClosing) {
        return;
    }

    try {
        if (g_popupBackdropOverlay && IsWindowVisible(g_popupBackdropOverlay)) {
            HidePopupBackdropOverlayWindowVisualOnly();
        }
        if (g_expandedPopup && IsWindow(g_expandedPopup)) {
            ParkExpandedPopupWindow(g_expandedPopup);
        }
        g_playerGrid.Opacity(1.0);
        g_playerGrid.IsHitTestVisible(true);
        if (g_compactArtSpinEnabled) {
            StartCompactCoverSpinLoop();
        }
    } catch (...) {
    }
}

void RepairExpandedPopupStateIfHidden() {
    // While resting as the compact island, the popup is intentionally hidden
    // together with the taskbar; SyncRestingPopupWithTaskbarVisibility owns
    // that lifecycle, so the repair pass must not reset it.
    if (!g_expanded || g_popupClosing || g_popupRestingCompact) {
        return;
    }
    if (IsAnimatedTaskbarPopupVisible()) {
        return;
    }

    StopPopupXamlRenderLoop();
    g_expanded = false;
    g_popupClosing = false;
    g_popupAnimationProgress = 0.0;
    g_popupAnimationTarget = 0.0;
    g_popupAnimationVelocity = 0.0;
    g_popupOutsideClickArmed = false;
    HidePopupToggleHitWindow();
    HidePopupBackdropOverlayWindowVisualOnly();
    SetCompactIslandSuppressed(false);
    try {
        if (g_playerGrid) {
            g_playerGrid.Opacity(1.0);
            g_playerGrid.IsHitTestVisible(true);
            ApplyExpandedState();
            UpdatePlayerContents();
        }
    } catch (...) {
    }
}
void StartExpandRenderLoop(bool expanded) {
    RepairExpandedPopupStateIfHidden();
    ApplyExpandedState();
    if (expanded) {
        StopHoverRenderLoop();
        g_currentHoverScale = 1.0;
        g_targetHoverScale = 1.0;
        if (g_islandScale) {
            g_islandScale.ScaleX(1.0);
            g_islandScale.ScaleY(1.0);
        }
        if (g_playerGrid) {
            g_playerGrid.UpdateLayout();
            RefreshCompactTextHostClip(false);
        }
        bool reversingClose =
            g_expanded && g_popupClosing && IsAnimatedTaskbarPopupVisible();
        if (reversingClose) {
            ResumeOpenExpandedPopup();
        } else {
            ShowExpandedPopup();
        }
    } else {
        BeginCloseExpandedPopup();
    }
}

bool InjectIslandGrid();

// ===== Media thread =====
void MediaThreadProc() {
    struct MediaThreadExitGuard {
        ~MediaThreadExitGuard() { g_mediaThreadExited = true; }
    } mediaThreadExitGuard;

    bool apartmentInitialized = false;
    try {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        apartmentInitialized = true;
    } catch (...) {
        Wh_Log(L"Island: failed to initialize media thread apartment");
        g_mediaThreadRunning = false;
        return;
    }

    struct SessionEventSubscription {
        gsm::GlobalSystemMediaTransportControlsSession session{nullptr};
        winrt::event_token mediaPropertiesChangedToken{};
        winrt::event_token playbackInfoChangedToken{};
        winrt::event_token timelinePropertiesChangedToken{};
    };

    gsm::GlobalSystemMediaTransportControlsSessionManager manager{nullptr};
    std::vector<SessionEventSubscription> sessionEventSubscriptions;
    std::atomic_bool sessionListChanged = true;
    winrt::event_token sessionsChangedToken{};
    winrt::event_token currentSessionChangedToken{};

    auto clearSessionEvents = [&] {
        for (auto& subscription : sessionEventSubscriptions) {
            if (subscription.session) {
                try {
                    subscription.session.MediaPropertiesChanged(
                        subscription.mediaPropertiesChangedToken);
                } catch (...) {
                }
                try {
                    subscription.session.PlaybackInfoChanged(
                        subscription.playbackInfoChangedToken);
                } catch (...) {
                }
                try {
                    subscription.session.TimelinePropertiesChanged(
                        subscription.timelinePropertiesChangedToken);
                } catch (...) {
                }
            }
        }
        sessionEventSubscriptions.clear();
    };

    auto subscribeAllSessionEvents = [&] {
        clearSessionEvents();
        try {
            if (!manager) {
                return;
            }

            for (auto const& session : manager.GetSessions()) {
                SessionEventSubscription subscription;
                subscription.session = session;
                try {
                    subscription.mediaPropertiesChangedToken =
                        session.MediaPropertiesChanged(
                            [](auto const&, auto const&) {
                                RequestMediaRefresh();
                            });
                    subscription.playbackInfoChangedToken =
                        session.PlaybackInfoChanged(
                            [](auto const&, auto const&) {
                                RequestMediaRefresh();
                            });
                    subscription.timelinePropertiesChangedToken =
                        session.TimelinePropertiesChanged(
                            [](auto const&, auto const&) {
                                RequestMediaRefresh();
                            });
                    sessionEventSubscriptions.push_back(
                        std::move(subscription));
                } catch (...) {
                    try {
                        session.MediaPropertiesChanged(
                            subscription.mediaPropertiesChangedToken);
                    } catch (...) {
                    }
                    try {
                        session.PlaybackInfoChanged(
                            subscription.playbackInfoChangedToken);
                    } catch (...) {
                    }
                    try {
                        session.TimelinePropertiesChanged(
                            subscription.timelinePropertiesChangedToken);
                    } catch (...) {
                    }
                }
            }
        } catch (...) {
            clearSessionEvents();
        }
    };

    try {
        manager = RequestMediaManagerWithTimeout(std::chrono::seconds(3));
        if (manager) {
            sessionsChangedToken =
                manager.SessionsChanged([&](auto const&, auto const&) {
                    sessionListChanged = true;
                    RequestMediaRefresh();
                });
            currentSessionChangedToken = manager.CurrentSessionChanged(
                [](auto const&, auto const&) { RequestMediaRefresh(); });
            subscribeAllSessionEvents();
            sessionListChanged = false;
        }
    } catch (...) {
        manager = nullptr;
    }

    auto lastFallbackPoll = std::chrono::steady_clock::time_point{};
    g_mediaRefreshRequested = true;

    while (g_mediaThreadRunning) {
        double neteaseSeekRatio = g_neteaseSeekRatioRequested.exchange(-1.0);
        if (neteaseSeekRatio >= 0.0) {
            if (TrySeekNeteaseCloudMusic(neteaseSeekRatio)) {
                MediaState state = SnapshotMedia();
                g_neteaseEstimatedPositionTicks = static_cast<int64_t>(
                    std::llround(state.durationTicks * neteaseSeekRatio));
                g_neteaseProgressSampleTime = std::chrono::steady_clock::now();
            }
            g_mediaRefreshRequested = true;
        }

        if (g_neteaseFavoriteToggleRequested.exchange(false)) {
            TryToggleNeteaseFavorite();
            g_mediaRefreshRequested = true;
        }

        if (g_bilibiliFavoriteRequested.exchange(false)) {
            TryFavoriteBilibili();
            g_mediaRefreshRequested = true;
        }

        std::deque<MediaCommand> commands;
        {
            std::lock_guard lock(g_mediaCommandMutex);
            commands.swap(g_mediaCommands);
        }

        if (!commands.empty()) {
            // Reuse the subscribed manager. Recreating it per click can take up
            // to two seconds before the command is even sent.
            auto session = CurrentSessionFromManager(manager);
            if (session) {
                for (auto& command : commands) {
                    try {
                        command(session);
                    } catch (...) {
                    }
                }
            }
            g_mediaRefreshRequested = true;
        }

        auto now = std::chrono::steady_clock::now();
        // GSMTC events already trigger instant refreshes, so the fallback poll
        // only exists for providers that don't emit reliable events (mostly
        // NetEase's title/local-data path). 250 ms is plenty for that path and
        // avoids the previous 60 ms process-table and audio-session churn.
        std::chrono::milliseconds fallbackPollInterval =
            IsNeteaseCloudMusicRunning()
                ? std::chrono::milliseconds(500)
                : (IsBilibiliRunning() ? std::chrono::milliseconds(500)
                                       : std::chrono::milliseconds(30000));
        bool fallbackPollDue =
            lastFallbackPoll.time_since_epoch().count() == 0 ||
            now - lastFallbackPoll >= fallbackPollInterval;
        bool shouldRefresh =
            g_mediaRefreshRequested.exchange(false) || fallbackPollDue;

        if (shouldRefresh) {
            if (sessionListChanged.exchange(false)) {
                subscribeAllSessionEvents();
            }
            RefreshMediaState(manager);
            lastFallbackPoll = now;

            HWND hwnd = g_taskbarWnd;
            if (!hwnd || !IsWindow(hwnd)) {
                hwnd = FindCurrentProcessTaskbarWnd();
            }
            if (IsModActive() && hwnd) {
                RunFromWindowThread(
                    hwnd,
                    [](void* param) {
                        if (!IsModActive()) {
                            return;
                        }
                        HWND taskbarWnd = reinterpret_cast<HWND>(param);
                        if (!g_playerGrid) {
                            g_taskbarWnd = taskbarWnd;
                            InjectIslandGrid();
                        } else {
                            UpdatePlayerContents();
                        }
                    },
                    reinterpret_cast<void*>(hwnd));
            }
        }

        std::unique_lock lock(g_mediaCommandMutex);
        g_mediaCommandCv.wait_for(lock, fallbackPollInterval, [] {
            return !g_mediaThreadRunning || !g_mediaCommands.empty() ||
                   g_neteaseFavoriteToggleRequested.load() ||
                   g_neteaseSeekRatioRequested.load() >= 0.0 ||
                   g_bilibiliFavoriteRequested.load() ||
                   g_mediaRefreshRequested.load();
        });
    }

    clearSessionEvents();
    try {
        if (manager) {
            manager.SessionsChanged(sessionsChangedToken);
            manager.CurrentSessionChanged(currentSessionChangedToken);
        }
    } catch (...) {
    }

    // Release the GSMTC manager before tearing down the WinRT apartment. Keeping
    // the WinRT/COM object alive across winrt::uninit_apartment() can leave its
    // final Release() running after the COM apartment has already been torn down,
    // which is risky when the mod is unloaded inside explorer.exe.
    manager = nullptr;

    if (apartmentInitialized) {
        winrt::uninit_apartment();
    }
}

void StartMediaThread() {
    if (g_mediaThreadRunning.exchange(true)) {
        return;
    }
    StartRemoteBytesThread();
    g_mediaThreadExited = false;
    try {
        g_mediaThread = new std::thread(MediaThreadProc);
    } catch (...) {
        g_mediaThreadRunning = false;
        g_mediaThreadExited = true;
        g_mediaThread = nullptr;
        StopRemoteBytesThread();
        Wh_Log(L"Island: failed to start media thread");
    }
}

void StopMediaThread() {
    g_mediaThreadRunning = false;
    g_mediaRefreshRequested = false;
    g_mediaCommandCv.notify_all();
    if (g_mediaThread) {
        if (g_mediaThread->joinable()) {
            if (g_mediaThread->get_id() != std::this_thread::get_id()) {
                auto deadline =
                    std::chrono::steady_clock::now() + kMediaThreadStopTimeout;
                while (!g_mediaThreadExited.load() &&
                       std::chrono::steady_clock::now() < deadline) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }

                if (g_mediaThreadExited.load()) {
                    g_mediaThread->join();
                } else {
                    Wh_Log(L"Island: media thread stop timed out; detaching");
                    g_mediaThread->detach();
                }
            } else {
                g_mediaThread->detach();
            }
        }
        delete g_mediaThread;
        g_mediaThread = nullptr;
    }
    std::lock_guard lock(g_mediaCommandMutex);
    g_mediaCommands.clear();
    StopRemoteBytesThread();
}

// ===== Compact island UI construction =====
TextBlock MakeTextBlock(const wchar_t* name, double fontSize, bool semibold) {
    TextBlock text;
    text.Name(name);
    text.FontFamily(mediax::FontFamily(L"Segoe UI Variable Text"));
    text.FontSize(fontSize);
    text.FontWeight(semibold ? winrt::Windows::UI::Text::FontWeights::SemiBold()
                             : winrt::Windows::UI::Text::FontWeights::Normal());
    text.Foreground(Brush(IsDarkModeApprox() ? Color(0xF2, 0xFF, 0xFF, 0xFF)
                                             : Color(0xF2, 0x18, 0x18, 0x1B)));
    text.TextTrimming(xaml::TextTrimming::CharacterEllipsis);
    text.VerticalAlignment(VerticalAlignment::Center);
    return text;
}

Button MakeMediaButton(const wchar_t* name,
                       const wchar_t* glyph,
                       void (*onClick)()) {
    Button button;
    button.Name(name);
    button.Width(32);
    button.Height(28);
    button.Padding({0, 0, 0, 0});
    button.Margin({2, 0, 2, 0});
    button.Background(Brush(Color(0x18, 0xFF, 0xFF, 0xFF)));
    button.BorderBrush(CompactPlaybackControlStrokeBrush());
    button.BorderThickness({1, 1, 1, 1});
    button.CornerRadius({kPopupG2ButtonCornerRadius, kPopupG2ButtonCornerRadius,
                         kPopupG2ButtonCornerRadius,
                         kPopupG2ButtonCornerRadius});

    TextBlock icon = MakeTextBlock(L"", 13, true);
    icon.FontFamily(mediax::FontFamily(L"Segoe Fluent Icons"));
    icon.Text(glyph);
    icon.HorizontalAlignment(HorizontalAlignment::Center);
    icon.VerticalAlignment(VerticalAlignment::Center);
    icon.TextAlignment(xaml::TextAlignment::Center);
    icon.Width(32.0);
    icon.Height(28.0);
    icon.Margin({0, 0, 0, 0});
    button.Content(icon);
    button.Click([onClick](auto const&, auto const&) { onClick(); });
    return button;
}

void UpdateButtonTheme(const wchar_t* name) {
    if (!g_playerGrid) {
        return;
    }

    bool dark = IsDarkModeApprox();
    if (auto buttonFe = FindChildByName(g_playerGrid, name)) {
        if (auto button = buttonFe.try_as<Button>()) {
            button.Background(Brush(dark ? Color(0x18, 0xFF, 0xFF, 0xFF)
                                         : Color(0x14, 0x00, 0x00, 0x00)));
            button.BorderBrush(CompactPlaybackControlStrokeBrush());
            if (auto icon = button.Content().try_as<TextBlock>()) {
                icon.Foreground(Brush(dark ? Color(0xF2, 0xFF, 0xFF, 0xFF)
                                           : Color(0xF2, 0x18, 0x18, 0x1B)));
            }
        }
    }
}

void UpdateThemeVisuals() {
    if (!g_playerGrid) {
        return;
    }

    bool dark = IsDarkModeApprox();
    if (g_themeVisualsValid && g_lastDarkMode == dark) {
        return;
    }
    g_themeVisualsValid = true;
    g_lastDarkMode = dark;

    if (auto bgFe = FindChildByName(g_playerGrid, L"Island_Background")) {
        if (auto bg = bgFe.try_as<Border>()) {
            ApplyCompactSurfaceVisual(bg);
        }
    }
    auto primaryTextBrush = Brush(dark ? Color(0xF2, 0xFF, 0xFF, 0xFF)
                                       : Color(0xF2, 0x18, 0x18, 0x1B));
    auto secondaryTextBrush = Brush(dark ? Color(0xB8, 0xFF, 0xFF, 0xFF)
                                         : Color(0xB8, 0x1C, 0x1C, 0x20));
    if (auto titleFe = FindChildByName(g_playerGrid, L"Island_Title")) {
        if (auto title = titleFe.try_as<TextBlock>()) {
            title.Foreground(primaryTextBrush);
        }
    }
    if (auto outgoingTitleFe =
            FindChildByName(g_playerGrid, L"Island_OutgoingTitle")) {
        if (auto title = outgoingTitleFe.try_as<TextBlock>()) {
            title.Foreground(primaryTextBrush);
        }
    }
    if (auto artistFe =
            FindChildByName(g_playerGrid, L"Island_CompactArtist")) {
        if (auto artist = artistFe.try_as<TextBlock>()) {
            artist.Foreground(secondaryTextBrush);
        }
    }
    if (auto outgoingArtistFe =
            FindChildByName(g_playerGrid, L"Island_OutgoingCompactArtist")) {
        if (auto artist = outgoingArtistFe.try_as<TextBlock>()) {
            artist.Foreground(secondaryTextBrush);
        }
    }
    if (g_compactTextLeftFade) {
        g_compactTextLeftFade.Background(CompactTextEdgeFadeBrush(true));
    }
    if (g_compactTextRightFade) {
        g_compactTextRightFade.Background(CompactTextEdgeFadeBrush(false));
    }

    if (auto strokeFe = FindChildByName(g_playerGrid, L"Island_ArtStroke")) {
        if (auto stroke = strokeFe.try_as<Border>()) {
            ConfigureCompactAlbumArtStroke(stroke);
        }
    }

    UpdateButtonTheme(L"Island_Prev");
    UpdateButtonTheme(L"Island_Play");
    UpdateButtonTheme(L"Island_Next");
}

double EffectiveElementVisualHeightDip(FrameworkElement const& element,
                                       double referenceHeight) {
    if (!element) {
        return 0.0;
    }

    try {
        double height = element.ActualHeight();
        if (height <= 1.0) {
            return 0.0;
        }

        // Taskbar Styler themes often compress the *visual* taskbar by adding
        // positive top/bottom margins to high-level taskbar grids while the
        // outer layout slot keeps the normal taskbar height. If ActualHeight
        // still looks like the reference/root height, subtract those positive
        // margins to estimate the real visual content height. If XAML already
        // reduced ActualHeight because of the margin, do not subtract again.
        Thickness margin = element.Margin();
        double positiveVerticalMargin =
            std::max(0.0, margin.Top) + std::max(0.0, margin.Bottom);
        if (referenceHeight > 1.0 && positiveVerticalMargin > 0.0 &&
            height > referenceHeight - positiveVerticalMargin * 0.5) {
            height = std::max(1.0, height - positiveVerticalMargin);
        }

        return height;
    } catch (...) {
        return 0.0;
    }
}

double DetectTaskbarHeightDip(HWND hwnd,
                              FrameworkElement const& root,
                              FrameworkElement const& targetElement) {
    double rootHeight = 0.0;
    try {
        if (root) {
            rootHeight = root.ActualHeight();
        }
    } catch (...) {
        rootHeight = 0.0;
    }

    double bestVisualHeight = 0.0;
    auto consider = [&](FrameworkElement const& element) {
        double height = EffectiveElementVisualHeightDip(
            element, rootHeight > 1.0 ? rootHeight : 0.0);
        if (height >= 24.0) {
            bestVisualHeight = bestVisualHeight > 1.0
                                   ? std::min(bestVisualHeight, height)
                                   : height;
        }
    };

    // The injection target can be a full-height layout grid. Use it, but also
    // sample the tray grid because themes such as Matter/BottomDensy often put
    // their visual compression there.
    consider(targetElement);
    if (root) {
        consider(FindChildByName(root, L"SystemTrayFrameGrid"));
        consider(FindChildByName(root, L"TaskbarFrame"));
    }

    double height = bestVisualHeight;
    if (height <= 1.0 && rootHeight > 1.0) {
        height = rootHeight;
    }

    if (height <= 1.0 && hwnd) {
        RECT rc{};
        if (GetWindowRect(hwnd, &rc)) {
            UINT dpi = GetDpiForWindow(hwnd);
            double scale = dpi > 0 ? static_cast<double>(dpi) / 96.0 : 1.0;
            height =
                static_cast<double>(rc.bottom - rc.top) / std::max(0.01, scale);
        }
    }

    return Clamp(height, 28.0, 96.0);
}

void UpdateRuntimeLayout(HWND hwnd,
                         FrameworkElement const& root,
                         FrameworkElement const& targetElement) {
    double taskbarHeight = DetectTaskbarHeightDip(hwnd, root, targetElement);
    g_layout.taskbarHeightDip = taskbarHeight;

    double compactHeight = static_cast<double>(g_settings.height);
    double compactWidth = static_cast<double>(g_settings.compactWidth);
    if (g_settings.autoSizeToTaskbar) {
        // Use the detected *visual* height, not the outer Shell_TrayWnd height.
        // The taskbar's usable inner height is the hard ceiling and the
        // configured Height is the target: compact/themed taskbars shrink the
        // island to fit, while genuinely tall taskbars may grow it all the way
        // to the widened 28..72 DIP range. The taller bar also gets a wider
        // island so normal artist names display in full (the ellipsis remains
        // only for very long names).
        double maxFitHeight =
            Clamp(taskbarHeight - 8.0, static_cast<double>(kCompactHeightMin),
                  static_cast<double>(kCompactHeightMax));
        bool tallTaskbar = taskbarHeight > 50.0;
        double autoHeight =
            tallTaskbar ? maxFitHeight : std::min(maxFitHeight, 46.0);
        compactHeight =
            std::min(static_cast<double>(g_settings.height), autoHeight);

        double autoScale = autoHeight / 40.0;
        double autoWidth = Clamp(230.0 * autoScale, 112.0, 280.0);
        if (tallTaskbar) {
            compactWidth = std::max(
                static_cast<double>(g_settings.compactWidth), autoWidth);
        } else {
            compactWidth = std::min(
                static_cast<double>(g_settings.compactWidth), autoWidth);
        }
    }

    // Scale text and controls with the island, but clamp the factor so very
    // small and very large heights stay legible without overflowing the pill.
    double scale = Clamp(compactHeight / 40.0, 0.68, 1.50);
    g_layout.compactHeight = compactHeight;
    g_layout.compactWidth = compactWidth;
    g_layout.contentMarginX = Clamp(7.0 * scale, 4.0, 10.0);
    g_layout.contentMarginY = Clamp(4.0 * scale, 2.0, 6.0);
    // The compact cover is a circle whose diameter equals the island's inner
    // content height, so its curvature matches the pill's rounded cap radius.
    // The image keeps a 2 DIP overscan clipped by the circular geometry, which
    // avoids a hard anti-aliased edge on the cover bounds.
    double innerHeight =
        std::max(16.0, compactHeight - g_layout.contentMarginY * 2.0);
    g_layout.artSize = innerHeight;
    g_layout.artImageSize = g_layout.artSize + 2.0;
    // A Border with corner radius = half its size renders exactly as a circle;
    // this keeps the placeholder and stroke layers matching the circular clip.
    g_layout.artCornerRadius = g_layout.artSize * 0.5;
    g_layout.cornerRadius = Clamp(compactHeight * 0.50, 12.0, 36.0);
    // The cover must be concentric with the pill's left rounded end cap, whose
    // centre is (H/2, H/2) from the pill's left/top edge. With a circle
    // diameter D its bounds therefore start at ((H - D)/2, (H - D)/2) - this
    // inset is independent of the horizontal content padding, so the cover is
    // not pushed right by the text margin and the text still starts after the
    // circle plus the existing gap.
    g_layout.artInset = std::max(0.0, (compactHeight - g_layout.artSize) * 0.5);
    // The art column is exactly the circle: the +2 DIP image overscan lives
    // inside the clipped art host, not in the grid column, so the column cannot
    // add a half-overscan offset to the cover position.
    g_layout.artColumnWidth = g_layout.artSize;
    // The arc spin toggle is concentric with the cover and hugs its right
    // edge, so it never touches the cover size. The user picked a 3 DIP gap
    // and a thick 3.7 DIP stroke; both scale with the island.
    g_layout.arcToggleCoverGap = Clamp(3.7 * scale, 1.9, 5.5);
    g_layout.arcToggleStroke = Clamp(4.0 * scale, 2.6, 5.4);
    // The text must start just right of the thicker arc instead of after the
    // bare cover: the arc's outer edge is at artInset + artSize +
    // coverGap + stroke, so the text margin needs coverGap + stroke plus a
    // small breathing gap. At H=40/scale 1 this is 3.0 + 3.7 + 1.8 = 8.5 DIP,
    // so the text block starts at 4 + 32 + 8.5 = 44.5 DIP (arc outer x 42.7).
    // Fixed text start (per user request): 50 DIP at the default H=40, so the
    // text block begins 7 DIP clear of the thicker 4 DIP arc (outer x 43 DIP).
    g_layout.textMarginX = Clamp(14.0 * scale, 9.0, 21.0);
    g_layout.textRightMargin = Clamp(4.0 * scale, 2.0, 6.0);
    g_layout.titleFontSize = Clamp(12.0 * scale, 10.0, 15.5);
    g_layout.artistFontSize = Clamp(10.0 * scale, 8.5, 13.5);
    g_layout.progressWidth = Clamp(74.0 * scale, 42.0, 110.0);
    g_layout.progressHeight = Clamp(4.0 * scale, 2.5, 6.0);
    g_layout.progressMarginLeft = Clamp(8.0 * scale, 4.0, 12.0);
    g_layout.playbackIndicatorWidth = Clamp(18.0 * scale, 13.0, 24.0);
    g_layout.playbackIndicatorHeight = Clamp(16.0 * scale, 11.0, 24.0);
    g_layout.playbackIndicatorMarginLeft = Clamp(1.0 * scale, 0.5, 2.0);
    g_layout.playbackBarWidth = Clamp(2.4 * scale, 1.7, 3.6);
    g_layout.playbackBarGap = Clamp(0.75 * scale, 0.45, 1.2);
}

Grid BuildIslandGrid() {
    auto spec = CurrentCompactVisualSpec();
    Grid wrapper;
    wrapper.Name(L"IslandMedia_Wrapper");
    wrapper.Tag(winrt::box_value(winrt::hstring(L"IslandMediaControls")));
    wrapper.Width(spec.width);
    wrapper.Height(spec.height);
    wrapper.MinHeight(spec.height);
    wrapper.VerticalAlignment(VerticalAlignment::Center);
    wrapper.HorizontalAlignment(HorizontalAlignment::Left);
    wrapper.Margin({static_cast<double>(g_settings.marginLeft), 0,
                    static_cast<double>(g_settings.marginRight), 0});
    wrapper.Background(Brush(Color(0x01, 0, 0, 0)));
    // Initial and post-collapse islands use the same center-origin hover.
    // The previous bottom origin made the first island grow only upward, then
    // visibly switch behavior after the popup had been opened once.
    wrapper.RenderTransformOrigin({0.5, 0.5});

    ScaleTransform hoverScale;
    hoverScale.ScaleX(1.0);
    hoverScale.ScaleY(1.0);
    wrapper.RenderTransform(hoverScale);
    g_islandScale = hoverScale;
    g_currentHoverScale = 1.0;
    g_targetHoverScale = 1.0;

    Border background;
    background.Name(L"Island_Background");
    background.CornerRadius({spec.cornerRadius, spec.cornerRadius,
                             spec.cornerRadius, spec.cornerRadius});
    // This element isn't in a live visual tree yet, so assign the temporary
    // color now and replace it with the shared compositor brush after append.
    background.Background(PopupControlCardBrush());
    background.BorderBrush(PopupSurfaceStrokeBrush());
    background.BorderThickness({spec.borderThickness, spec.borderThickness,
                                spec.borderThickness, spec.borderThickness});
    background.IsHitTestVisible(false);
    controls::Canvas::SetZIndex(background, 0);

    Grid content;
    content.Name(L"Island_Content");
    content.IsHitTestVisible(false);
    // Left inset is (H - D)/2 so the circular cover is concentric with the
    // pill's left cap; vertical inset keeps the cover on the pill's centre
    // line; the right side keeps the regular content padding.
    content.Margin({spec.artInset, spec.contentMarginY, spec.contentMarginX,
                    spec.contentMarginY});
    controls::Canvas::SetZIndex(content, 1);

    ColumnDefinition artCol;
    artCol.Width({spec.artColumnWidth, GridUnitType::Pixel});
    ColumnDefinition textCol;
    textCol.Width({1, GridUnitType::Star});
    ColumnDefinition controlsCol;
    controlsCol.Width({1, GridUnitType::Auto});
    content.ColumnDefinitions().Append(artCol);
    content.ColumnDefinitions().Append(textCol);
    content.ColumnDefinitions().Append(controlsCol);

    Border art;
    art.Name(L"Island_ArtFallback");
    art.Width(g_layout.artSize);
    art.Height(g_layout.artSize);
    art.CornerRadius({g_layout.artCornerRadius, g_layout.artCornerRadius,
                      g_layout.artCornerRadius, g_layout.artCornerRadius});
    // Keep the parent transparent. The old blue fallback could show through as a
    // 1px strip on the right/bottom when the generated cover was rounded/scaled.
    art.Background(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    art.BorderThickness({0, 0, 0, 0});
    art.BorderBrush(Brush(Color(0x00, 0x00, 0x00, 0x00)));
    art.VerticalAlignment(VerticalAlignment::Center);

    Grid artShell;
    artShell.Name(L"Island_ArtShell");
    artShell.Width(g_layout.artSize);
    artShell.Height(g_layout.artSize);

    Grid artHost;
    artHost.Name(L"Island_ArtHost");
    artHost.Width(g_layout.artSize);
    artHost.Height(g_layout.artSize);
    ApplyElementCircularClip(artHost, g_layout.artSize);
    artShell.Children().Append(artHost);

    Border artPlaceholder;
    artPlaceholder.Name(L"Island_ArtPlaceholder");
    artPlaceholder.Width(g_layout.artSize);
    artPlaceholder.Height(g_layout.artSize);
    artPlaceholder.CornerRadius(
        {g_layout.artCornerRadius, g_layout.artCornerRadius,
         g_layout.artCornerRadius, g_layout.artCornerRadius});
    // The generated idle cover follows a custom accent colour; the default
    // accent keeps the stock blue placeholder.
    auto placeholderAccent = DefaultPopupAccentColor();
    winrt::Windows::UI::Color customAccent;
    if (CustomAccentColor(customAccent)) {
        placeholderAccent = customAccent;
    }
    artPlaceholder.Background(Brush(placeholderAccent));
    artPlaceholder.BorderThickness({0, 0, 0, 0});
    artPlaceholder.IsHitTestVisible(false);
    artHost.Children().Append(artPlaceholder);

    Image artFade;
    artFade.Name(L"Island_AlbumArtFade");
    artFade.Width(g_layout.artImageSize);
    artFade.Height(g_layout.artImageSize);
    artFade.Margin({-1, -1, -1, -1});
    artFade.Stretch(mediax::Stretch::UniformToFill);
    artFade.IsHitTestVisible(false);
    artFade.Opacity(0.0);
    // The cover and its cross-fade share one rotation phase, so a media change
    // fades between two identically oriented covers and leaves no ghost.
    mediax::RotateTransform artSpinFade;
    artSpinFade.Angle(g_compactArtSpinAngle);
    artFade.RenderTransformOrigin({0.5, 0.5});
    artFade.RenderTransform(artSpinFade);
    artHost.Children().Append(artFade);

    Image artImage;
    artImage.Name(L"Island_AlbumArt");
    artImage.Width(g_layout.artImageSize);
    artImage.Height(g_layout.artImageSize);
    artImage.Margin({-1, -1, -1, -1});
    artImage.Stretch(mediax::Stretch::UniformToFill);
    artImage.IsHitTestVisible(false);
    artImage.Opacity(1.0);
    mediax::RotateTransform artSpinImage;
    artSpinImage.Angle(g_compactArtSpinAngle);
    artImage.RenderTransformOrigin({0.5, 0.5});
    artImage.RenderTransform(artSpinImage);
    artHost.Children().Append(artImage);

    Border artStroke;
    artStroke.Name(L"Island_ArtStroke");
    ConfigureCompactAlbumArtStroke(artStroke);
    artShell.Children().Append(artStroke);

    art.Child(artShell);
    g_compactAlbumArtImage = artImage;
    g_compactAlbumArtFade = artFade;
    g_compactArtSpinImage = artSpinImage;
    g_compactArtSpinFade = artSpinFade;

    controls::Grid::SetColumn(art, 0);
    content.Children().Append(art);

    Grid textHost;
    textHost.Name(L"Island_TextHost");
    textHost.VerticalAlignment(VerticalAlignment::Center);
    textHost.Margin({spec.textMarginX, 0, 4.0, 0});
    controls::Grid::SetColumn(textHost, 1);

    StackPanel outgoingTextStack;
    outgoingTextStack.Orientation(controls::Orientation::Vertical);
    outgoingTextStack.IsHitTestVisible(false);
    outgoingTextStack.VerticalAlignment(VerticalAlignment::Center);
    outgoingTextStack.Opacity(1.0);

    auto outgoingTitle =
        MakeTextBlock(L"Island_OutgoingTitle", spec.titleFontSize, true);
    outgoingTitle.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
    outgoingTitle.Opacity(0.0);
    TranslateTransform outgoingTitleTranslate;
    outgoingTitleTranslate.X(0.0);
    outgoingTitle.RenderTransform(outgoingTitleTranslate);

    auto outgoingArtist = MakeTextBlock(L"Island_OutgoingCompactArtist",
                                        spec.artistFontSize, false);
    outgoingArtist.Foreground(Brush(IsDarkModeApprox()
                                        ? Color(0xB8, 0xFF, 0xFF, 0xFF)
                                        : Color(0xB8, 0x1C, 0x1C, 0x20)));
    outgoingArtist.Opacity(0.0);
    TranslateTransform outgoingArtistTranslate;
    outgoingArtistTranslate.X(0.0);
    outgoingArtist.RenderTransform(outgoingArtistTranslate);

    outgoingTextStack.Children().Append(outgoingTitle);
    outgoingTextStack.Children().Append(outgoingArtist);
    textHost.Children().Append(outgoingTextStack);

    StackPanel textStack;
    textStack.Orientation(controls::Orientation::Vertical);
    textStack.IsHitTestVisible(false);
    textStack.VerticalAlignment(VerticalAlignment::Center);

    auto title = MakeTextBlock(L"Island_Title", spec.titleFontSize, true);
    title.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
    TranslateTransform titleTranslate;
    titleTranslate.X(0.0);
    title.RenderTransform(titleTranslate);
    auto artist =
        MakeTextBlock(L"Island_CompactArtist", spec.artistFontSize, false);
    artist.Foreground(Brush(IsDarkModeApprox()
                                ? Color(0xB8, 0xFF, 0xFF, 0xFF)
                                : Color(0xB8, 0x1C, 0x1C, 0x20)));
    TranslateTransform artistTranslate;
    artistTranslate.X(0.0);
    artist.RenderTransform(artistTranslate);
    g_compactTitleText = title;
    g_compactArtistText = artist;
    g_compactTextHost = textHost;
    g_compactOutgoingTitleText = outgoingTitle;
    g_compactOutgoingArtistText = outgoingArtist;
    g_compactTitleTranslate = titleTranslate;
    g_compactArtistTranslate = artistTranslate;
    g_compactOutgoingTitleTranslate = outgoingTitleTranslate;
    g_compactOutgoingArtistTranslate = outgoingArtistTranslate;
    g_compactTextInitialized = false;
    g_compactLastTitle.clear();
    g_compactLastArtist.clear();
    g_compactLastTextMediaHash = UINT64_MAX;
    textStack.Children().Append(title);
    textStack.Children().Append(artist);
    textHost.Children().Append(textStack);

    Border leftTextFade;
    leftTextFade.Name(L"Island_TextLeftFade");
    leftTextFade.HorizontalAlignment(HorizontalAlignment::Left);
    leftTextFade.VerticalAlignment(VerticalAlignment::Stretch);
    leftTextFade.IsHitTestVisible(false);
    leftTextFade.Opacity(0.0);
    controls::Canvas::SetZIndex(leftTextFade, 10);
    Border rightTextFade;
    rightTextFade.Name(L"Island_TextRightFade");
    rightTextFade.HorizontalAlignment(HorizontalAlignment::Right);
    rightTextFade.VerticalAlignment(VerticalAlignment::Stretch);
    rightTextFade.IsHitTestVisible(false);
    rightTextFade.Opacity(0.0);
    controls::Canvas::SetZIndex(rightTextFade, 10);
    g_compactTextLeftFade = leftTextFade;
    g_compactTextRightFade = rightTextFade;
    textHost.Children().Append(leftTextFade);
    textHost.Children().Append(rightTextFade);

    content.Children().Append(textHost);

    Grid playbackIndicator;
    playbackIndicator.Name(L"Island_PlaybackIndicator");
    playbackIndicator.Width(spec.playbackIndicatorWidth);
    playbackIndicator.Height(spec.playbackIndicatorHeight);
    playbackIndicator.Margin({spec.playbackIndicatorMarginLeft, 0, 0, 0});
    playbackIndicator.HorizontalAlignment(HorizontalAlignment::Right);
    playbackIndicator.VerticalAlignment(VerticalAlignment::Center);
    playbackIndicator.IsHitTestVisible(false);
    playbackIndicator.Opacity(1.0);
    controls::Grid::SetColumn(playbackIndicator, 2);

    StackPanel playbackBars;
    playbackBars.Name(L"Island_PlaybackBars");
    playbackBars.Orientation(controls::Orientation::Horizontal);
    playbackBars.HorizontalAlignment(HorizontalAlignment::Center);
    playbackBars.VerticalAlignment(VerticalAlignment::Center);
    playbackBars.Height(spec.playbackIndicatorHeight);
    playbackBars.IsHitTestVisible(false);

    mediax::SolidColorBrush playbackAccentBrush;
    playbackAccentBrush.Color(g_compactPlaybackAccentDisplayed);
    g_compactPlaybackAccentBrush = playbackAccentBrush;

    constexpr double kInitialPausedFractions[5] = {0.27, 0.43, 0.60, 0.43,
                                                   0.27};
    g_compactPlaybackBars.clear();
    for (size_t i = 0; i < 5; ++i) {
        Border bar;
        bar.Name(winrt::hstring(L"Island_PlaybackBar" + std::to_wstring(i)));
        bar.Width(spec.playbackBarWidth);
        double barHeight = std::max(
            2.0, spec.playbackIndicatorHeight * kInitialPausedFractions[i]);
        bar.Height(barHeight);
        bar.Margin(
            {spec.playbackBarGap * 0.5, 0, spec.playbackBarGap * 0.5, 0});
        double radius = spec.playbackBarWidth * 0.5;
        bar.CornerRadius({radius, radius, radius, radius});
        bar.VerticalAlignment(VerticalAlignment::Center);
        bar.Background(playbackAccentBrush);
        bar.Opacity(i == 0 || i == 4 ? 0.86 : (i == 1 || i == 3 ? 0.94 : 1.0));
        bar.IsHitTestVisible(false);
        g_compactPlaybackBarHeights[i] = barHeight;
        g_compactPlaybackBars.push_back(bar);
        playbackBars.Children().Append(bar);
    }
    playbackIndicator.Children().Append(playbackBars);
    g_compactPlaybackIndicator = playbackIndicator;
    content.Children().Append(playbackIndicator);

    StackPanel details;
    details.Name(L"Island_Details");
    details.Orientation(controls::Orientation::Horizontal);
    details.VerticalAlignment(VerticalAlignment::Center);
    details.Visibility(Visibility::Collapsed);
    details.IsHitTestVisible(false);
    details.Opacity(0.0);
    controls::Grid::SetColumn(details, 2);

    details.Children().Append(MakeMediaButton(L"Island_Prev", L"\uEB9E", [] {
        RunMediaTransportCommand(MediaTransportCommand::Previous);
    }));
    details.Children().Append(MakeMediaButton(L"Island_Play", L"\uE768", [] {
        RunMediaTransportCommand(MediaTransportCommand::TogglePlayPause);
    }));
    details.Children().Append(MakeMediaButton(L"Island_Next", L"\uEB9D", [] {
        RunMediaTransportCommand(MediaTransportCommand::Next);
    }));

    ProgressBar progress;
    progress.Name(L"Island_Progress");
    progress.Width(g_layout.progressWidth);
    progress.Height(g_layout.progressHeight);
    progress.Margin({g_layout.progressMarginLeft, 0, 0, 0});
    progress.Minimum(0);
    progress.Maximum(1000);
    progress.Value(0);
    progress.IsHitTestVisible(false);
    g_compactProgress = progress;
    details.Children().Append(progress);
    content.Children().Append(details);

    wrapper.Children().Append(background);
    wrapper.Children().Append(content);

    // --- Compact arc spin toggle ---
    // A short accent-coloured arc hugging the right edge of the circular
    // cover, concentric with it. The overlay is a sibling of the hit-test
    // invisible content grid and is centred exactly on the cover; only the
    // ring band consumes pointer/tap events, so taps on the artwork itself
    // keep falling through to the island's expand handler.
    Grid arcToggle;
    arcToggle.Name(L"Island_ArcToggle");
    arcToggle.HorizontalAlignment(HorizontalAlignment::Left);
    arcToggle.VerticalAlignment(VerticalAlignment::Top);
    arcToggle.Background(Brush(Color(0x01, 0x00, 0x00, 0x00)));
    arcToggle.IsHitTestVisible(true);
    controls::Canvas::SetZIndex(arcToggle, 20);

    mediax::SolidColorBrush arcAccentBrush;
    arcAccentBrush.Color(g_compactPlaybackAccentDisplayed);
    g_compactArcAccentBrush = arcAccentBrush;

    shapes::Path arcPath;
    arcPath.Name(L"Island_ArcPath");
    arcPath.HorizontalAlignment(HorizontalAlignment::Left);
    arcPath.VerticalAlignment(VerticalAlignment::Top);
    arcPath.Stroke(arcAccentBrush);
    arcPath.StrokeThickness(spec.arcToggleStroke);
    arcPath.StrokeStartLineCap(mediax::PenLineCap::Round);
    arcPath.StrokeEndLineCap(mediax::PenLineCap::Round);
    arcPath.StrokeLineJoin(mediax::PenLineJoin::Round);
    arcPath.IsHitTestVisible(false);
    arcToggle.Children().Append(arcPath);

    g_compactArcToggle = arcToggle;
    g_compactArcPath = arcPath;
    ApplyCompactArcToggleLayout();

    arcToggle.PointerPressed(
        [](auto const& sender, input::PointerRoutedEventArgs const& e) {
            auto element = sender.template try_as<UIElement>();
            if (!element) {
                return;
            }
            // A tap on the ring toggles the spin; a tap on the cover area
            // leaves the event unhandled so it bubbles to the expand handler.
            if (CompactArcRingHitTest(e.GetCurrentPoint(element).Position())) {
                e.Handled(true);
            }
        });
    arcToggle.Tapped(
        [](auto const& sender, input::TappedRoutedEventArgs const& e) {
            auto element = sender.template try_as<UIElement>();
            if (!element) {
                return;
            }
            if (!CompactArcRingHitTest(e.GetPosition(element))) {
                return;
            }
            if (g_compactArcLastDoubleTap.time_since_epoch().count() != 0 &&
                std::chrono::steady_clock::now() - g_compactArcLastDoubleTap <
                    std::chrono::milliseconds(250)) {
                // Tail tap of a double-tap sequence: DoubleTapped owns the
                // final state (stopped + upright), so swallow this toggle.
                e.Handled(true);
                return;
            }
            e.Handled(true);
            ToggleCompactCoverSpin();
        });
    arcToggle.DoubleTapped(
        [](auto const& sender, input::DoubleTappedRoutedEventArgs const& e) {
            auto element = sender.template try_as<UIElement>();
            if (!element) {
                return;
            }
            if (!CompactArcRingHitTest(e.GetPosition(element))) {
                return;
            }
            g_compactArcLastDoubleTap = std::chrono::steady_clock::now();
            e.Handled(true);
            ResetCompactCoverSpin();
        });

    wrapper.Children().Append(arcToggle);

    wrapper.PointerEntered([hoverScale](auto const&, auto const&) {
        g_islandScale = hoverScale;
        StartHoverRenderLoop(g_settings.hoverScale);
    });
    wrapper.PointerExited([hoverScale](auto const&, auto const&) {
        g_islandScale = hoverScale;
        StartHoverRenderLoop(1.0);
    });
    wrapper.PointerPressed(
        [](auto const& sender, input::PointerRoutedEventArgs const& e) {
            auto source = sender.template try_as<UIElement>();
            auto point = e.GetCurrentPoint(source);
            if (point.Properties().IsLeftButtonPressed()) {
                RepairExpandedPopupStateIfHidden();
                if (g_popupRestingCompact) {
                    ResumeOpenExpandedPopup();
                    e.Handled(true);
                    return;
                }
                bool popupActuallyExpanded = g_expanded &&
                                             IsAnimatedTaskbarPopupVisible() &&
                                             !g_popupClosing;
                StartExpandRenderLoop(!popupActuallyExpanded);
                e.Handled(true);
            }
        });

    return wrapper;
}

// ===== Taskbar layout monitor =====
void StopTaskbarLayoutMonitor() {
    if (g_taskbarLayoutTimerWindow) {
        KillTimer(g_taskbarLayoutTimerWindow, kTaskbarLayoutMonitorTimerId);
        g_taskbarLayoutTimerWindow = nullptr;
    }
    g_taskbarLayoutWatchRoot = nullptr;
    g_taskbarLayoutWatchTarget = nullptr;
}

void CALLBACK OnTaskbarLayoutTimer(HWND, UINT, UINT_PTR timerId, DWORD) {
    try {
        if (timerId != kTaskbarLayoutMonitorTimerId) {
            return;
        }
        if (g_unloading || !g_playerGrid || !g_taskbarLayoutWatchRoot ||
            !g_taskbarLayoutWatchTarget) {
            StopTaskbarLayoutMonitor();
            return;
        }

        RepairExpandedPopupStateIfHidden();

        double oldHeight = g_layout.compactHeight;
        double oldWidth = g_layout.compactWidth;
        double oldTaskbarHeight = g_layout.taskbarHeightDip;

        HWND hwnd = g_taskbarWnd && IsWindow(g_taskbarWnd)
                        ? g_taskbarWnd
                        : FindCurrentProcessTaskbarWnd();
        if (!hwnd) {
            return;
        }
        g_taskbarWnd = hwnd;

        bool taskbarDirectionChanged = false;
        RECT taskbarRect{};
        if (GetWindowRect(hwnd, &taskbarRect)) {
            HMONITOR monitor =
                MonitorFromRect(&taskbarRect, MONITOR_DEFAULTTONEAREST);
            MONITORINFO monitorInfo{sizeof(monitorInfo)};
            if (monitor && GetMonitorInfoW(monitor, &monitorInfo)) {
                bool taskbarAtTop =
                    TaskbarPopupOpensDown(taskbarRect, monitorInfo);
                taskbarDirectionChanged = taskbarAtTop != g_taskbarAtTop;
                if (taskbarDirectionChanged) {
                    g_taskbarAtTop = taskbarAtTop;
                    g_popupXamlThumbnailHash = UINT64_MAX;
                    RequestMediaRefresh();
                }
            }
        }

        UpdateRuntimeLayout(hwnd, g_taskbarLayoutWatchRoot,
                            g_taskbarLayoutWatchTarget);

        bool layoutChanged =
            std::abs(g_layout.compactHeight - oldHeight) > 0.5 ||
            std::abs(g_layout.compactWidth - oldWidth) > 0.5 ||
            std::abs(g_layout.taskbarHeightDip - oldTaskbarHeight) > 0.75;

        if (layoutChanged || taskbarDirectionChanged) {
            ApplyExpandedState();
            try {
                g_playerGrid.UpdateLayout();
            } catch (...) {
            }
            RefreshCompactTextHostClip(false);
            if (!g_expanded) {
                CapturePopupSourceGeometry();
            }
        }
    } catch (...) {
        StopTaskbarLayoutMonitor();
    }
}

void StartTaskbarLayoutMonitor(FrameworkElement const& root,
                               FrameworkElement const& targetElement) {
    if (g_unloading || !root || !targetElement) {
        return;
    }

    StopTaskbarLayoutMonitor();
    g_taskbarLayoutWatchRoot = root;
    g_taskbarLayoutWatchTarget = targetElement;

    HWND hwnd = g_taskbarWnd && IsWindow(g_taskbarWnd)
                    ? g_taskbarWnd
                    : FindCurrentProcessTaskbarWnd();
    if (!hwnd ||
        !SetTimer(hwnd, kTaskbarLayoutMonitorTimerId,
                  kTaskbarLayoutMonitorIntervalMs, OnTaskbarLayoutTimer)) {
        g_taskbarLayoutWatchRoot = nullptr;
        g_taskbarLayoutWatchTarget = nullptr;
        return;
    }
    g_taskbarLayoutTimerWindow = hwnd;
}

// ===== Player contents update =====
void UpdatePlayerContents() {
    if (!g_playerGrid || g_unloading) {
        return;
    }

    try {
        MediaState state = SnapshotMedia();

        // Some providers briefly report metadata before the matching thumbnail is
        // available. Reuse old artwork only when the *same media item* temporarily
        // has an empty thumbnail. Do not carry a previous song/video cover into a
        // new browser live room, where GSMTC often reports no thumbnail or repeats
        // the previous thumbnail while the page is still updating.
        auto artworkNow = std::chrono::steady_clock::now();
        std::wstring artworkIdentityKey = MediaIdentityKey(state);
        std::wstring visualTrackKey = MediaTrackKey(state);
        uint64_t rawThumbnailHash = ThumbnailHash(state.thumbnailBytes);

        static std::vector<uint8_t> s_lastNonEmptyThumbnailBytes;
        static std::wstring s_lastNonEmptyThumbnailIdentityKey;
        static uint64_t s_lastNonEmptyThumbnailHash = 0;
        static std::chrono::steady_clock::time_point
            s_lastNonEmptyThumbnailTime{};
        static std::wstring s_suspectRepeatedThumbnailIdentityKey;
        static uint64_t s_suspectRepeatedThumbnailHash = 0;
        static std::chrono::steady_clock::time_point
            s_suspectRepeatedThumbnailSince{};
        static std::wstring s_lastVisualTrackKey;
        static std::chrono::steady_clock::time_point
            s_forceImmediateAccentUntil{};

        bool visualTrackChanged = state.hasSession &&
                                  !s_lastVisualTrackKey.empty() &&
                                  visualTrackKey != s_lastVisualTrackKey;
        if (!state.hasSession) {
            s_lastVisualTrackKey.clear();
            s_forceImmediateAccentUntil = {};
        } else {
            if (visualTrackChanged) {
                // The cover can arrive after title/id. Any accent received during
                // this window belongs to the new track and must apply immediately.
                s_forceImmediateAccentUntil =
                    artworkNow + std::chrono::milliseconds(2500);
            }
            s_lastVisualTrackKey = visualTrackKey;
        }
        bool forceImmediateAccent =
            s_forceImmediateAccentUntil.time_since_epoch().count() != 0 &&
            artworkNow < s_forceImmediateAccentUntil;

        std::vector<uint8_t> visualThumbnailBytes = state.thumbnailBytes;
        if (!state.hasSession) {
            visualThumbnailBytes.clear();
            s_suspectRepeatedThumbnailIdentityKey.clear();
            s_suspectRepeatedThumbnailHash = 0;
        } else if (!state.thumbnailBytes.empty()) {
            bool differentMedia =
                !s_lastNonEmptyThumbnailIdentityKey.empty() &&
                artworkIdentityKey != s_lastNonEmptyThumbnailIdentityKey;
            bool repeatedPreviousArtwork =
                differentMedia && rawThumbnailHash != 0 &&
                rawThumbnailHash == s_lastNonEmptyThumbnailHash;
            bool browserLiveLike =
                LooksLikeBrowserMediaSource(state.sourceAppUserModelId) &&
                state.durationTicks <= 0;

            if (repeatedPreviousArtwork && browserLiveLike) {
                if (s_suspectRepeatedThumbnailIdentityKey !=
                        artworkIdentityKey ||
                    s_suspectRepeatedThumbnailHash != rawThumbnailHash) {
                    s_suspectRepeatedThumbnailIdentityKey = artworkIdentityKey;
                    s_suspectRepeatedThumbnailHash = rawThumbnailHash;
                    s_suspectRepeatedThumbnailSince = artworkNow;
                }

                // Give browser/GSMTC a short chance to replace a stale thumbnail.
                // During that window show the placeholder instead of the previous
                // video's cover. If it never changes, accept it later so the UI
                // doesn't stay placeholder forever.
                auto suspectAge =
                    std::chrono::duration_cast<std::chrono::milliseconds>(
                        artworkNow - s_suspectRepeatedThumbnailSince)
                        .count();
                if (suspectAge < 3500) {
                    visualThumbnailBytes.clear();
                }
            } else {
                s_suspectRepeatedThumbnailIdentityKey.clear();
                s_suspectRepeatedThumbnailHash = 0;
            }

            if (!visualThumbnailBytes.empty()) {
                s_lastNonEmptyThumbnailBytes = state.thumbnailBytes;
                s_lastNonEmptyThumbnailIdentityKey = artworkIdentityKey;
                s_lastNonEmptyThumbnailHash = rawThumbnailHash;
                s_lastNonEmptyThumbnailTime = artworkNow;
            }
        } else if (!s_lastNonEmptyThumbnailBytes.empty() &&
                   artworkIdentityKey == s_lastNonEmptyThumbnailIdentityKey) {
            auto age = std::chrono::duration_cast<std::chrono::milliseconds>(
                           artworkNow - s_lastNonEmptyThumbnailTime)
                           .count();
            if (age <= 2500) {
                visualThumbnailBytes = s_lastNonEmptyThumbnailBytes;
            } else {
                visualThumbnailBytes.clear();
            }
        } else {
            visualThumbnailBytes.clear();
        }

        std::vector<uint8_t> displayThumbnailBytes =
            CreateDisplayAlbumCoverBytesCached(visualThumbnailBytes,
                                               state.sourceAppUserModelId);
        // Main.DefaultCoverImage is the idle cover: it only fills in while no
        // media session exists, and a real session always wins once it starts.
        std::vector<uint8_t> defaultCoverBytes;
        bool useDefaultCoverArt = false;
        if (!state.hasSession) {
            defaultCoverBytes = LoadDefaultCoverImageBytes();
            useDefaultCoverArt = !defaultCoverBytes.empty();
        }
        // Artwork-mode accents can also come from the idle cover, so the bars
        // already match the shown image before the first track starts.
        std::vector<uint8_t> const& compactAccentSourceBytes =
            !displayThumbnailBytes.empty()
                ? displayThumbnailBytes
                : (useDefaultCoverArt ? defaultCoverBytes
                                      : visualThumbnailBytes);
        UpdateCompactPlaybackIndicatorAccent(compactAccentSourceBytes,
                                             forceImmediateAccent);
        bool useGeneratedBlurCover =
            LooksLikeBrowserMediaSource(state.sourceAppUserModelId) &&
            ShouldUseAbstractArtworkForDisplay(visualThumbnailBytes) &&
            !displayThumbnailBytes.empty();
        std::vector<uint8_t> popupBlurSourceBytes = useGeneratedBlurCover
                                                        ? displayThumbnailBytes
                                                        : visualThumbnailBytes;
        uint64_t visualThumbnailHash = ThumbnailHash(visualThumbnailBytes);
        uint64_t displayThumbnailHash = ThumbnailHash(displayThumbnailBytes);

        UpdateThemeVisuals();

        auto makeBitmap =
            [](std::vector<uint8_t> const& bytes) -> imaging::BitmapImage {
            imaging::BitmapImage bitmap;
            if (bytes.empty()) {
                return imaging::BitmapImage{nullptr};
            }
            streams::InMemoryRandomAccessStream stream;
            streams::DataWriter writer(stream);
            writer.WriteBytes(winrt::array_view<const uint8_t>(bytes));
            try {
                GetAsyncResultWithTimeout(writer.StoreAsync(),
                                          kUiLocalAsyncTimeout,
                                          L"DataWriter.StoreAsync");
            } catch (...) {
                return imaging::BitmapImage{nullptr};
            }
            writer.DetachStream();
            stream.Seek(0);
            bitmap.SetSourceAsync(stream);
            return bitmap;
        };

        std::wstring compactTitle =
            state.hasSession ? state.title : DefaultIdleTitle();
        std::wstring compactArtist =
            !state.hasSession
                ? DefaultIdleArtist()
                : (state.artist.empty()
                       ? std::wstring(state.isPlaying ? L"Playing" : L"Paused")
                       : state.artist);
        // Artwork can be refreshed repeatedly while the media item itself hasn't
        // changed (especially for browser-backed sessions). Text motion must be
        // keyed to text metadata only: including the thumbnail hash restarted the
        // title/artist slide on every refreshed frame and made XAML render only
        // the ellipsis while the TextBlocks crossed the host clip. Album artwork
        // has its own independent transition below.
        uint64_t compactTextMediaHash = visualThumbnailHash;
        bool compactWasInitialized = g_compactTextInitialized;
        std::wstring compactOldTitle =
            g_compactLastTitle.empty() ? compactTitle : g_compactLastTitle;
        std::wstring compactOldArtist =
            g_compactLastArtist.empty() ? compactArtist : g_compactLastArtist;
        bool compactTextChanged =
            compactWasInitialized && (compactTitle != g_compactLastTitle ||
                                      compactArtist != g_compactLastArtist);
        bool compactPlaybackOnlyTextChange =
            compactWasInitialized && compactTitle == g_compactLastTitle &&
            state.artist.empty() &&
            (compactArtist == L"Playing" || compactArtist == L"Paused") &&
            (g_compactLastArtist == L"Playing" ||
             g_compactLastArtist == L"Paused") &&
            compactTextMediaHash == g_compactLastTextMediaHash;
        if (compactPlaybackOnlyTextChange) {
            compactTextChanged = false;
        }

        if (auto titleFe = FindChildByName(g_playerGrid, L"Island_Title")) {
            if (auto title = titleFe.try_as<TextBlock>()) {
                title.Text(winrt::hstring(compactTitle));
            }
        }
        if (auto artistFe =
                FindChildByName(g_playerGrid, L"Island_CompactArtist")) {
            if (auto artist = artistFe.try_as<TextBlock>()) {
                artist.Text(winrt::hstring(compactArtist));
            }
        }

        if (!g_compactTextInitialized) {
            g_compactTextInitialized = true;
            ResetCompactTextAnimationVisuals();
        }
        g_compactLastTitle = compactTitle;
        g_compactLastArtist = compactArtist;
        g_compactLastTextMediaHash = compactTextMediaHash;
        if (auto playFe = FindChildByName(g_playerGrid, L"Island_Play")) {
            if (auto button = playFe.try_as<Button>()) {
                if (auto icon = button.Content().try_as<TextBlock>()) {
                    icon.Text(state.isPlaying ? L"\uE769" : L"\uE768");
                }
            }
        }
        SetCompactPlaybackIndicatorState(state.hasSession && state.isPlaying);
        if (g_compactProgress) {
            bool shouldInterpolate = UpdateCompactProgressFromSnapshot();
            if (shouldInterpolate && !g_expanded) {
                StartCompactProgressRenderLoop();
            } else {
                StopCompactProgressRenderLoop();
            }
        }
        bool compactArtChanged = false;
        uint64_t compactArtHash = displayThumbnailHash;
        std::vector<uint8_t> const* compactArtBytes = &displayThumbnailBytes;
        if (useDefaultCoverArt) {
            compactArtHash = ThumbnailHash(defaultCoverBytes);
            compactArtBytes = &defaultCoverBytes;
        }
        if (auto imageFe = FindChildByName(g_playerGrid, L"Island_AlbumArt")) {
            if (auto image = imageFe.try_as<Image>()) {
                if (!g_compactAlbumArtImage) {
                    g_compactAlbumArtImage = image;
                }
                compactArtChanged = compactArtHash != g_lastThumbnailHash;
                if (compactArtChanged) {
                    bool canAnimateArt =
                        compactWasInitialized && !g_expanded && !g_unloading;
                    try {
                        if (canAnimateArt && g_compactAlbumArtFade) {
                            auto oldSource = image.Source();
                            g_compactAlbumArtFade.Source(oldSource);
                            g_compactAlbumArtFade.Opacity(
                                oldSource != nullptr ? 1.0 : 0.0);
                        }
                        if (compactArtHash) {
                            image.Source(makeBitmap(*compactArtBytes));
                        } else {
                            image.Source(nullptr);
                        }
                        image.Opacity(canAnimateArt ? 0.0 : 1.0);
                    } catch (...) {
                        image.Source(nullptr);
                        image.Opacity(1.0);
                        if (g_compactAlbumArtFade) {
                            g_compactAlbumArtFade.Source(nullptr);
                            g_compactAlbumArtFade.Opacity(0.0);
                        }
                    }
                    g_lastThumbnailHash = compactArtHash;
                }
            }
        }

        if (compactWasInitialized && !g_expanded &&
            (compactTextChanged || compactArtChanged)) {
            StartCompactTrackTransition(compactOldTitle, compactOldArtist,
                                        compactTextChanged, compactArtChanged);
        }

        if (g_popupXamlRoot) {
            if (g_popupRenderingHooked &&
                g_popupLifecycleState != PopupLifecycleState::Open) {
                g_popupPendingContentRefresh = true;
            } else {
                std::vector<uint8_t> const& accentSourceBytes =
                    !displayThumbnailBytes.empty()
                        ? displayThumbnailBytes
                        : (useDefaultCoverArt ? defaultCoverBytes
                                              : visualThumbnailBytes);
                uint64_t accentHash = displayThumbnailHash != 0
                                          ? displayThumbnailHash
                                          : visualThumbnailHash;
                if (accentHash == 0 && !accentSourceBytes.empty()) {
                    accentHash = ThumbnailHash(accentSourceBytes);
                }
                bool accentChanged = accentHash != g_popupAccentThumbnailHash;
                if (accentChanged) {
                    winrt::Windows::UI::Color nextAccent =
                        accentSourceBytes.empty()
                            ? DefaultPopupAccentColor()
                            : ExtractAlbumAccentColor(accentSourceBytes);
                    winrt::Windows::UI::Color currentAccent =
                        PopupAccentColor();
                    bool canAnimateAccent =
                        g_popupAccentThumbnailHash != UINT64_MAX &&
                        g_popupXamlRoot && IsAnimatedTaskbarPopupVisible() &&
                        !forceImmediateAccent;
                    g_popupAccentThumbnailHash = accentHash;
                    g_popupAccentColor = nextAccent;
                    g_popupAccentColorValid = !accentSourceBytes.empty();
                    g_popupAccentTransitionFrom =
                        canAnimateAccent ? currentAccent : nextAccent;
                    g_popupAccentTransitionTo = nextAccent;
                    g_popupDisplayedAccentColor =
                        canAnimateAccent ? currentAccent : nextAccent;
                    g_popupDisplayedAccentColorValid = true;
                    if (canAnimateAccent) {
                        g_popupMediaTransitionProgress = 0.0;
                        g_popupMediaTransitionActive = true;
                    }
                    g_popupXamlThemeValid = false;
                }
                ApplyPopupXamlTheme();
                winrt::hstring nextPopupTitle =
                    state.hasSession ? winrt::hstring(state.title)
                                     : winrt::hstring(DefaultIdleTitle());
                winrt::hstring nextPopupArtist =
                    !state.hasSession
                        ? winrt::hstring(DefaultIdleArtist())
                        : (state.artist.empty()
                               ? (state.isPlaying ? winrt::hstring(L"Playing")
                                                  : winrt::hstring(L"Paused"))
                               : winrt::hstring(state.artist));
                bool popupTextChanged =
                    g_popupXamlTitle && g_popupXamlArtist &&
                    (g_popupXamlTitle.Text() != nextPopupTitle ||
                     g_popupXamlArtist.Text() != nextPopupArtist);
                bool popupPlaybackOnlyTextChange =
                    popupTextChanged && g_popupXamlTitle && g_popupXamlArtist &&
                    g_popupXamlTitle.Text() == nextPopupTitle &&
                    state.artist.empty() &&
                    (nextPopupArtist == winrt::hstring(L"Playing") ||
                     nextPopupArtist == winrt::hstring(L"Paused")) &&
                    (g_popupXamlArtist.Text() == winrt::hstring(L"Playing") ||
                     g_popupXamlArtist.Text() == winrt::hstring(L"Paused"));
                bool canAnimatePopupText =
                    popupTextChanged && !popupPlaybackOnlyTextChange &&
                    g_popupXamlOutgoingTitle && g_popupXamlOutgoingArtist &&
                    IsAnimatedTaskbarPopupVisible();
                if (canAnimatePopupText) {
                    g_popupXamlOutgoingTitle.Text(g_popupXamlTitle.Text());
                    g_popupXamlOutgoingArtist.Text(g_popupXamlArtist.Text());
                    int navigationDirection =
                        ConsumeRecentMediaNavigationDirection();
                    g_popupTextTransitionDirection =
                        navigationDirection < 0 ? -1 : 1;
                    double popupTextStartOffset =
                        30.0 *
                        static_cast<double>(g_popupTextTransitionDirection);
                    if (g_popupXamlOutgoingTitleTranslate)
                        g_popupXamlOutgoingTitleTranslate.X(0.0);
                    if (g_popupXamlOutgoingArtistTranslate)
                        g_popupXamlOutgoingArtistTranslate.X(0.0);
                    g_popupXamlOutgoingTitle.Opacity(g_popupTextBaseOpacity);
                    g_popupXamlOutgoingArtist.Opacity(g_popupTextBaseOpacity);
                    if (g_popupXamlTitleTranslate)
                        g_popupXamlTitleTranslate.X(popupTextStartOffset);
                    if (g_popupXamlArtistTranslate)
                        g_popupXamlArtistTranslate.X(popupTextStartOffset);
                    g_popupXamlTitle.Opacity(0.0);
                    g_popupXamlArtist.Opacity(0.0);
                    g_popupTextTransitionActive = true;
                    g_popupMediaTransitionProgress = 0.0;
                    g_popupMediaTransitionActive = true;
                } else if (!popupTextChanged) {
                    // Leave the current transition state alone if only artwork/accent is changing.
                } else {
                    g_popupTextTransitionActive = false;
                }
                if (g_popupXamlTitle)
                    g_popupXamlTitle.Text(nextPopupTitle);
                if (g_popupXamlArtist)
                    g_popupXamlArtist.Text(nextPopupArtist);
                if (!canAnimatePopupText && !g_popupTextTransitionActive) {
                    if (g_popupXamlTitleTranslate)
                        g_popupXamlTitleTranslate.X(0.0);
                    if (g_popupXamlArtistTranslate)
                        g_popupXamlArtistTranslate.X(0.0);
                    if (g_popupXamlOutgoingTitle)
                        g_popupXamlOutgoingTitle.Opacity(0.0);
                    if (g_popupXamlOutgoingArtist)
                        g_popupXamlOutgoingArtist.Opacity(0.0);
                }
                UpdatePopupLiveProgressFromSnapshot();
                if (g_popupXamlControls) {
                    for (auto const& child : g_popupXamlControls.Children()) {
                        if (auto buttonSurface = child.try_as<Border>()) {
                            bool favoriteButton =
                                buttonSurface.Name() == L"Popup_Favorite";
                            UpdatePopupTransportButtonGlyph(buttonSurface,
                                                            state.isPlaying,
                                                            state.isFavorite);
                            if (favoriteButton) {
                                buttonSurface.IsHitTestVisible(
                                    state.canFavorite);
                                buttonSurface.Opacity(state.canFavorite ? 1.0
                                                                        : 0.38);
                            }
                        }
                    }
                }

                uint64_t popupHash = displayThumbnailHash != 0
                                         ? displayThumbnailHash
                                         : visualThumbnailHash;
                if (popupHash == 0 && useDefaultCoverArt) {
                    popupHash = ThumbnailHash(defaultCoverBytes);
                }
                bool useBackdropCover = PopupBackdropCoverEffectEnabled();
                if (popupHash != g_popupXamlThumbnailHash ||
                    g_popupXamlThumbnailMaterial != g_settings.material ||
                    g_popupXamlThumbnailCompact != g_settings.compact ||
                    useBackdropCover != g_popupXamlBackdropCoverEnabled) {
                    bool canAnimateCover =
                        g_popupXamlThumbnailHash != UINT64_MAX &&
                        g_popupXamlRoot && IsAnimatedTaskbarPopupVisible();
                    try {
                        if (canAnimateCover) {
                            if (g_popupXamlArtFade && g_popupXamlArt) {
                                auto oldArtSource = g_popupXamlArt.Source();
                                g_popupXamlArtFade.Source(oldArtSource);
                                g_popupXamlArtFade.Opacity(
                                    oldArtSource != nullptr ? 1.0 : 0.0);
                            }
                            if (g_popupXamlBackdropCoverFade &&
                                g_popupXamlBackdropCover) {
                                auto oldBackdropCoverSource =
                                    useBackdropCover
                                        ? g_popupXamlBackdropCover.Source()
                                        : nullptr;
                                g_popupXamlBackdropCoverFade.Source(
                                    oldBackdropCoverSource);
                                g_popupXamlBackdropCoverFade.Opacity(
                                    oldBackdropCoverSource != nullptr ? 1.0
                                                                      : 0.0);
                            }
                            if (g_popupXamlPanelCoverFade &&
                                g_popupXamlPanelCover) {
                                auto oldCoverSource =
                                    g_popupXamlPanelCover.Source();
                                g_popupXamlPanelCoverFade.Source(
                                    oldCoverSource);
                                g_popupXamlPanelCoverFade.Opacity(
                                    oldCoverSource != nullptr ? 1.0 : 0.0);
                            }
                        }

                        if (visualThumbnailBytes.empty()) {
                            if (useDefaultCoverArt) {
                                // Idle: use the configured default cover in
                                // both the artwork and the wash/card covers.
                                auto idleArtBytes =
                                    CreatePopupG2AlbumCoverBytes(
                                        defaultCoverBytes);
                                auto const& idleArt = idleArtBytes.empty()
                                                          ? defaultCoverBytes
                                                          : idleArtBytes;
                                g_popupXamlArt.Source(makeBitmap(idleArt));
                                if (g_popupXamlBackdropCover) {
                                    if (useBackdropCover) {
                                        auto idleBackdropBytes =
                                            CreateLowDetailAlbumCoverBytes(
                                                defaultCoverBytes, true,
                                                g_settings.compact ||
                                                    g_taskbarAtTop,
                                                false);
                                        auto const& idleBackdrop =
                                            idleBackdropBytes.empty()
                                                ? defaultCoverBytes
                                                : idleBackdropBytes;
                                        g_popupXamlBackdropCover.Source(
                                            makeBitmap(idleBackdrop));
                                    } else {
                                        g_popupXamlBackdropCover.Source(
                                            nullptr);
                                    }
                                }
                                if (g_popupXamlPanelCover) {
                                    auto idlePanelBytes =
                                        CreateLowDetailAlbumCoverBytes(
                                            defaultCoverBytes);
                                    auto const& idlePanel =
                                        idlePanelBytes.empty()
                                            ? defaultCoverBytes
                                            : idlePanelBytes;
                                    g_popupXamlPanelCover.Source(
                                        makeBitmap(idlePanel));
                                }
                            } else {
                                auto placeholderArtBytes =
                                    CreatePlaceholderAlbumCoverBytes(128);
                                auto placeholderG2ArtBytes =
                                    CreatePopupG2AlbumCoverBytes(
                                        placeholderArtBytes);
                                auto placeholderPanelBytes =
                                    CreatePlaceholderAlbumCoverBytes(20);
                                auto placeholderBackdropBytes =
                                    CreatePlaceholderAlbumCoverBytes(
                                        20, true,
                                        g_settings.compact || g_taskbarAtTop,
                                        false);
                                auto const& popupArtBytes =
                                    placeholderG2ArtBytes.empty()
                                        ? placeholderArtBytes
                                        : placeholderG2ArtBytes;
                                if (!popupArtBytes.empty()) {
                                    g_popupXamlArt.Source(
                                        makeBitmap(popupArtBytes));
                                } else {
                                    g_popupXamlArt.Source(nullptr);
                                }
                                if (g_popupXamlBackdropCover) {
                                    if (useBackdropCover &&
                                        !placeholderBackdropBytes.empty()) {
                                        g_popupXamlBackdropCover.Source(
                                            makeBitmap(
                                                placeholderBackdropBytes));
                                    } else {
                                        g_popupXamlBackdropCover.Source(
                                            nullptr);
                                    }
                                }
                                if (g_popupXamlPanelCover) {
                                    if (!placeholderPanelBytes.empty()) {
                                        g_popupXamlPanelCover.Source(
                                            makeBitmap(placeholderPanelBytes));
                                    } else {
                                        g_popupXamlPanelCover.Source(nullptr);
                                    }
                                }
                            }
                        } else {
                            auto popupArtBytes = CreatePopupG2AlbumCoverBytes(
                                displayThumbnailBytes);
                            g_popupXamlArt.Source(makeBitmap(
                                popupArtBytes.empty() ? displayThumbnailBytes
                                                      : popupArtBytes));
                            if (g_popupXamlBackdropCover) {
                                if (useBackdropCover) {
                                    auto lowDetailBackdropBytes =
                                        CreateLowDetailAlbumCoverBytes(
                                            popupBlurSourceBytes, true,
                                            g_settings.compact ||
                                                g_taskbarAtTop,
                                            false);
                                    auto const& backdropBytes =
                                        lowDetailBackdropBytes.empty()
                                            ? popupBlurSourceBytes
                                            : lowDetailBackdropBytes;
                                    g_popupXamlBackdropCover.Source(
                                        makeBitmap(backdropBytes));
                                } else {
                                    g_popupXamlBackdropCover.Source(nullptr);
                                }
                            }
                            if (g_popupXamlPanelCover) {
                                auto lowDetailCoverBytes =
                                    CreateLowDetailAlbumCoverBytes(
                                        popupBlurSourceBytes);
                                auto const& coverBytes =
                                    lowDetailCoverBytes.empty()
                                        ? popupBlurSourceBytes
                                        : lowDetailCoverBytes;
                                g_popupXamlPanelCover.Source(
                                    makeBitmap(coverBytes));
                            }
                        }

                        if (canAnimateCover) {
                            g_popupCoverTransitionActive = true;
                            g_popupMediaTransitionProgress = 0.0;
                            g_popupMediaTransitionActive = true;
                            ApplyPopupMediaTransitionVisuals();
                        } else {
                            g_popupCoverTransitionActive = false;
                            if (g_popupXamlArt)
                                g_popupXamlArt.Opacity(1.0);
                            if (g_popupXamlArtFade)
                                g_popupXamlArtFade.Opacity(0.0);
                            if (g_popupXamlBackdropCover) {
                                g_popupXamlBackdropCover.Opacity(
                                    useBackdropCover ? 1.0 : 0.0);
                            }
                            if (g_popupXamlBackdropCoverFade)
                                g_popupXamlBackdropCoverFade.Opacity(0.0);
                            if (g_popupXamlPanelCover)
                                g_popupXamlPanelCover.Opacity(1.0);
                            if (g_popupXamlPanelCoverFade)
                                g_popupXamlPanelCoverFade.Opacity(0.0);
                        }
                        g_popupXamlThumbnailHash = popupHash;
                        g_popupXamlThumbnailMaterial = g_settings.material;
                        g_popupXamlThumbnailCompact = g_settings.compact;
                        g_popupXamlBackdropCoverEnabled = useBackdropCover;
                    } catch (...) {
                        g_popupXamlArt.Source(nullptr);
                        if (g_popupXamlArtFade) {
                            g_popupXamlArtFade.Source(nullptr);
                            g_popupXamlArtFade.Opacity(0.0);
                        }
                        if (g_popupXamlBackdropCover) {
                            g_popupXamlBackdropCover.Source(nullptr);
                        }
                        if (g_popupXamlBackdropCoverFade) {
                            g_popupXamlBackdropCoverFade.Source(nullptr);
                            g_popupXamlBackdropCoverFade.Opacity(0.0);
                        }
                        if (g_popupXamlPanelCover) {
                            g_popupXamlPanelCover.Source(nullptr);
                        }
                        if (g_popupXamlPanelCoverFade) {
                            g_popupXamlPanelCoverFade.Source(nullptr);
                            g_popupXamlPanelCoverFade.Opacity(0.0);
                        }
                        g_popupXamlThumbnailHash = popupHash;
                        g_popupXamlThumbnailMaterial = g_settings.material;
                        g_popupXamlThumbnailCompact = g_settings.compact;
                        g_popupXamlBackdropCoverEnabled = useBackdropCover;
                    }
                }
                if (g_popupMediaTransitionActive && !g_popupRenderingHooked) {
                    StartPopupXamlRenderLoop();
                }
            }
        } else {
            UpdatePopupAlbumBitmap(state);
        }
        if (g_expandedPopup && IsWindowVisible(g_expandedPopup) &&
            !g_popupXamlRoot) {
            ApplyPopupBackdrop(g_expandedPopup);
            RenderExpandedPopupLayer();
        }

        g_playerGrid.Visibility(
            (g_settings.hideWhenNoMedia && !state.hasSession)
                ? Visibility::Collapsed
                : Visibility::Visible);
        EnsureCompactIslandInteractive();
    } catch (...) {
        Wh_Log(L"Island: exception while updating player contents");
        if (IsAnimatedTaskbarPopupVisible()) {
            try {
                BeginCloseExpandedPopup();
            } catch (...) {
                FinishCloseExpandedPopup(g_expandedPopup);
            }
        }
    }
}

// ===== Compact island grid injection =====
void RemoveIslandGrid() {
    UnsubclassTaskbarVisibilityWindows();
    StopTaskbarLayoutMonitor();
    StopHoverRenderLoop();
    StopCompactTextRenderLoop();
    StopCompactProgressRenderLoop();
    StopCompactPlaybackIndicatorRenderLoop();
    StopCompactCoverSpinLoop();
    DestroyExpandedPopup();

    if (!g_injectionParent || !g_playerGrid) {
        g_playerGrid = nullptr;
        g_injectionParent = nullptr;
        g_playerColumn = -1;
        g_islandScale = nullptr;
        g_compactTitleText = nullptr;
        g_compactArtistText = nullptr;
        g_compactTextHost = nullptr;
        g_compactTextLeftFade = nullptr;
        g_compactTextRightFade = nullptr;
        g_compactOutgoingTitleText = nullptr;
        g_compactOutgoingArtistText = nullptr;
        g_compactTitleTranslate = nullptr;
        g_compactArtistTranslate = nullptr;
        g_compactOutgoingTitleTranslate = nullptr;
        g_compactOutgoingArtistTranslate = nullptr;
        g_compactAlbumArtImage = nullptr;
        g_compactAlbumArtFade = nullptr;
        g_compactArcToggle = nullptr;
        g_compactArcPath = nullptr;
        g_compactArcAccentBrush = nullptr;
        g_compactArtSpinImage = nullptr;
        g_compactArtSpinFade = nullptr;
        g_compactProgress = nullptr;
        g_compactPlaybackIndicator = nullptr;
        g_compactPlaybackBars.clear();
        g_compactPlaybackAccentBrush = nullptr;
        g_compactPlaybackDesiredPlaying = false;
        g_compactPlaybackAnimationStart = {};
        g_compactPlaybackStateChangedAt = {};
        g_compactPlaybackAccentThumbnailHash = UINT64_MAX;
        g_compactPlaybackAccentFrom = Color(0xFF, 0x4F, 0x7D, 0xE8);
        g_compactPlaybackAccentTo = g_compactPlaybackAccentFrom;
        g_compactPlaybackAccentDisplayed = g_compactPlaybackAccentFrom;
        g_compactPlaybackAccentTransitionActive = false;
        g_compactPlaybackAccentTransitionStart = {};
        g_compactTextEdgeFadeActive = false;
        g_compactTextInitialized = false;
        g_compactLastTitle.clear();
        g_compactLastArtist.clear();
        g_compactLastTextMediaHash = UINT64_MAX;
        return;
    }

    try {
        if (auto targetGrid = g_injectionParent.try_as<Grid>()) {
            auto children = targetGrid.Children();
            for (uint32_t i = 0; i < children.Size(); ++i) {
                auto child = children.GetAt(i).try_as<FrameworkElement>();
                bool isIsland = false;
                if (child) {
                    isIsland = child.Name() == L"IslandMedia_Wrapper";
                    if (!isIsland) {
                        try {
                            auto tag = winrt::unbox_value_or<winrt::hstring>(
                                child.Tag(), winrt::hstring{});
                            isIsland = tag == L"IslandMediaControls";
                        } catch (...) {
                        }
                    }
                }
                if (isIsland) {
                    children.RemoveAt(i);
                    break;
                }
            }

            if (g_playerColumn >= 0 &&
                g_playerColumn <
                    static_cast<int>(targetGrid.ColumnDefinitions().Size())) {
                for (uint32_t i = 0; i < children.Size(); ++i) {
                    auto child = children.GetAt(i).try_as<FrameworkElement>();
                    if (!child) {
                        continue;
                    }
                    int col = controls::Grid::GetColumn(child);
                    if (col > g_playerColumn) {
                        controls::Grid::SetColumn(child, col - 1);
                    }
                }
                targetGrid.ColumnDefinitions().RemoveAt(g_playerColumn);
            }
        }
    } catch (...) {
    }

    g_playerGrid = nullptr;
    g_injectionParent = nullptr;
    g_playerColumn = -1;
    g_expanded = false;
    g_islandScale = nullptr;
    g_compactTitleText = nullptr;
    g_compactArtistText = nullptr;
    g_compactTextHost = nullptr;
    g_compactTextLeftFade = nullptr;
    g_compactTextRightFade = nullptr;
    g_compactOutgoingTitleText = nullptr;
    g_compactOutgoingArtistText = nullptr;
    g_compactTitleTranslate = nullptr;
    g_compactArtistTranslate = nullptr;
    g_compactOutgoingTitleTranslate = nullptr;
    g_compactOutgoingArtistTranslate = nullptr;
    g_compactAlbumArtImage = nullptr;
    g_compactAlbumArtFade = nullptr;
    g_compactArcToggle = nullptr;
    g_compactArcPath = nullptr;
    g_compactArcAccentBrush = nullptr;
    g_compactArtSpinImage = nullptr;
    g_compactArtSpinFade = nullptr;
    g_compactProgress = nullptr;
    g_compactPlaybackIndicator = nullptr;
    g_compactPlaybackBars.clear();
    g_compactPlaybackAccentBrush = nullptr;
    g_compactPlaybackDesiredPlaying = false;
    g_compactPlaybackAnimationStart = {};
    g_compactPlaybackStateChangedAt = {};
    g_compactPlaybackAccentThumbnailHash = UINT64_MAX;
    g_compactPlaybackAccentFrom = Color(0xFF, 0x4F, 0x7D, 0xE8);
    g_compactPlaybackAccentTo = g_compactPlaybackAccentFrom;
    g_compactPlaybackAccentDisplayed = g_compactPlaybackAccentFrom;
    g_compactPlaybackAccentTransitionActive = false;
    g_compactPlaybackAccentTransitionStart = {};
    g_compactTextEdgeFadeActive = false;
    g_compactTextInitialized = false;
    g_compactLastTitle.clear();
    g_compactLastArtist.clear();
    g_compactLastTextMediaHash = UINT64_MAX;
    g_lastThumbnailHash = 0;
    g_themeVisualsValid = false;
    g_popupXamlThemeValid = false;
    g_popupXamlThemeMaterial.clear();
    g_popupXamlThemeShadowDepth = -1;
    g_popupXamlThemeShadowOpacity = -1;
    g_currentHoverScale = 1.0;
    g_targetHoverScale = 1.0;
}

bool InjectIslandGrid() {
    HWND hwnd = g_taskbarWnd ? g_taskbarWnd : FindCurrentProcessTaskbarWnd();
    if (!hwnd) {
        Wh_Log(L"Island: taskbar window not found");
        return false;
    }
    g_taskbarWnd = hwnd;

    try {
        auto xamlRoot = GetTaskbarXamlRoot(hwnd);
        if (!xamlRoot) {
            Wh_Log(L"Island: failed to get taskbar XAML root");
            return false;
        }

        auto root = xamlRoot.Content().try_as<FrameworkElement>();
        if (!root) {
            Wh_Log(L"Island: XAML root content isn't a FrameworkElement");
            return false;
        }

        RemoveIslandGrid();
        SubclassTaskbarVisibilityWindows();

        auto target = ResolveInjectionTarget(root);
        if (!target.grid) {
            Wh_Log(L"Island: injection target not found");
            return false;
        }

        UpdateRuntimeLayout(hwnd, root, target.grid);
        Grid island = BuildIslandGrid();

        if (target.overlay) {
            if (g_settings.position == L"taskbar_center_edge") {
                island.HorizontalAlignment(HorizontalAlignment::Center);
            } else if (g_settings.position == L"taskbar_right_edge") {
                island.HorizontalAlignment(HorizontalAlignment::Right);
            } else {
                island.HorizontalAlignment(HorizontalAlignment::Left);
            }
            controls::Grid::SetColumn(island, 0);
            controls::Canvas::SetZIndex(island, 1000);
            target.grid.Children().Append(island);
            g_playerColumn = -1;
        } else {
            ColumnDefinition colDef;
            colDef.Width({1.0, GridUnitType::Auto});
            int col =
                Clamp(target.column, 0,
                      static_cast<int>(target.grid.ColumnDefinitions().Size()));
            if (col >=
                static_cast<int>(target.grid.ColumnDefinitions().Size())) {
                target.grid.ColumnDefinitions().Append(colDef);
            } else {
                target.grid.ColumnDefinitions().InsertAt(col, colDef);
                for (uint32_t i = 0; i < target.grid.Children().Size(); ++i) {
                    auto child = target.grid.Children()
                                     .GetAt(i)
                                     .try_as<FrameworkElement>();
                    if (child) {
                        int childCol = controls::Grid::GetColumn(child);
                        if (childCol >= col) {
                            controls::Grid::SetColumn(child, childCol + 1);
                        }
                    }
                }
            }
            controls::Grid::SetColumn(island, col);
            target.grid.Children().Append(island);
            g_playerColumn = col;
        }

        g_playerGrid = island;
        g_injectionParent = target.grid;
        StartTaskbarLayoutMonitor(root, target.grid);
        ApplyExpandedState();
        UpdatePlayerContents();
        target.grid.UpdateLayout();
        RefreshCompactTextHostClip(false);
        // A rebuild (settings/theme change) keeps the user's spin choice and
        // phase: the new art transforms start at g_compactArtSpinAngle.
        if (g_compactArtSpinEnabled) {
            StartCompactCoverSpinLoop();
        }
        Wh_Log(L"Island: injected successfully");
        return true;
    } catch (...) {
        Wh_Log(L"Island: exception while injecting");
        return false;
    }
}

// ===== Settings application and shell callbacks =====
void ApplyPendingSettings() {
    std::optional<Settings> settings;
    {
        std::lock_guard lock(g_pendingSettingsMutex);
        settings.swap(g_pendingSettings);
    }
    if (!settings) {
        return;
    }

    g_settings = std::move(*settings);
    g_themeVisualsValid = false;
    g_popupXamlThemeValid = false;
    g_popupXamlThemeMaterial.clear();
    g_popupXamlThemeShadowDepth = -1;
    g_popupXamlThemeShadowOpacity = -1;
    g_popupXamlThemeButtonStyle.clear();
}

void ApplyPendingSettingsAndInject() {
    if (!IsModActive()) {
        return;
    }
    ApplyPendingSettings();
    InjectIslandGrid();
}

void ApplySettingsOnTaskbarThread() {
    if (!IsModActive()) {
        return;
    }
    if (!g_taskbarWnd || !IsWindow(g_taskbarWnd)) {
        g_taskbarWnd = FindCurrentProcessTaskbarWnd();
    }
    if (g_taskbarWnd) {
        RunFromWindowThread(
            g_taskbarWnd, [](void*) { ApplyPendingSettingsAndInject(); },
            nullptr);
    }
}

// The shell is about to hide the taskbar (auto-hide, fullscreen, or the
// "auto-hide when maximized" mod). Hide the island with it at the exact same
// moment instead of measuring window rects or XAML state.
void OnTaskbarShellHiding() {
    if (g_unloading) {
        return;
    }
    g_taskbarHiddenBySystem = true;
    // Keep this hook trivial. Hiding is owned by the frame-level follow: the
    // island rides down together with the taskbar (bridge/parent delta) and is
    // hidden by SyncRestingPopupWithTaskbarVisibility once the island element
    // is actually off-screen. That is the same "ride together" behavior in
    // every hide mode, fullscreen included, so there is no flash and no
    // lingering overlay.
}

// The shell is showing the taskbar again: bring the resting island back.
void OnTaskbarShellShowing() {
    if (g_unloading) {
        return;
    }
    g_taskbarHiddenBySystem = false;
    // Do not show here: at the Unhide instant the taskbar window is still at
    // the hidden position, so showing would flash at the wrong spot. The
    // 8 ms resting sync shows the island only once the taskbar is actually
    // back on-screen, with live coordinates that match the native island.
}

// ===== Hooks =====
void WINAPI TrayUI__Hide_Hook(void* pThis) {
    if (TrayUI__Hide_Original) {
        TrayUI__Hide_Original(pThis);
    }
    OnTaskbarShellHiding();
}

void WINAPI TrayUI_Unhide_Hook(void* pThis,
                               int trayUnhideFlags,
                               int unhideRequest) {
    if (TrayUI_Unhide_Original) {
        TrayUI_Unhide_Original(pThis, trayUnhideFlags, unhideRequest);
    }
    OnTaskbarShellShowing();
}

void WINAPI CSecondaryTray__AutoHide_Hook(void* pThis, bool param1) {
    if (CSecondaryTray__AutoHide_Original) {
        CSecondaryTray__AutoHide_Original(pThis, param1);
    }
    OnTaskbarShellHiding();
}

void WINAPI CSecondaryTray__Unhide_Hook(void* pThis,
                                        int trayUnhideFlags,
                                        int unhideRequest) {
    if (CSecondaryTray__Unhide_Original) {
        CSecondaryTray__Unhide_Original(pThis, trayUnhideFlags, unhideRequest);
    }
    OnTaskbarShellShowing();
}

void WINAPI TrayUI_StartTaskbar_Hook(void* pThis) {
    TrayUI_StartTaskbar_Original(pThis);
    if (!IsModActive()) {
        return;
    }

    g_taskbarWnd = FindCurrentProcessTaskbarWnd();
    if (g_taskbarWnd) {
        RunFromWindowThread(
            g_taskbarWnd, [](void*) { ApplyPendingSettingsAndInject(); },
            nullptr);
    }
}

bool HookTaskbarSymbols() {
    HMODULE taskbarDll =
        LoadLibraryExW(L"taskbar.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!taskbarDll) {
        return false;
    }

    WindhawkUtils::SYMBOL_HOOK taskbarDllHooks[] = {
        {{L"const CTaskBand::`vftable'{for `ITaskListWndSite'}"},
         &CTaskBand_ITaskListWndSite_vftable},
        {{L"public: virtual class std::shared_ptr<class TaskbarHost> __cdecl "
          L"CTaskBand::GetTaskbarHost(void)const "},
         &CTaskBand_GetTaskbarHost_Original},
        {{L"public: int __cdecl TaskbarHost::FrameHeight(void)const "},
         &TaskbarHost_FrameHeight_Original},
        {{L"public: void __cdecl std::_Ref_count_base::_Decref(void)"},
         &Std_Ref_Decref_Original},
        {{L"public: virtual void __cdecl TrayUI::StartTaskbar(void)"},
         &TrayUI_StartTaskbar_Original,
         TrayUI_StartTaskbar_Hook},
        {{L"public: void __cdecl TrayUI::_Hide(void)"},
         &TrayUI__Hide_Original,
         TrayUI__Hide_Hook,
         true},
        {{L"public: virtual void __cdecl TrayUI::Unhide(enum "
          L"TrayCommon::TrayUnhideFlags,enum TrayCommon::UnhideRequest)",
          L"public: virtual void __cdecl TrayUI::Unhide(enum "
          L"TrayCommon::TrayUnhideFlags, enum TrayCommon::UnhideRequest)"},
         &TrayUI_Unhide_Original,
         TrayUI_Unhide_Hook,
         true},
        {{L"private: void __cdecl CSecondaryTray::_AutoHide(bool)"},
         &CSecondaryTray__AutoHide_Original,
         CSecondaryTray__AutoHide_Hook,
         true},
        {{L"private: void __cdecl CSecondaryTray::_Unhide(enum "
          L"TrayCommon::TrayUnhideFlags,enum TrayCommon::UnhideRequest)",
          L"private: void __cdecl CSecondaryTray::_Unhide(enum "
          L"TrayCommon::TrayUnhideFlags, enum TrayCommon::UnhideRequest)"},
         &CSecondaryTray__Unhide_Original,
         CSecondaryTray__Unhide_Hook,
         true},
    };

    return WindhawkUtils::HookSymbols(taskbarDll, taskbarDllHooks,
                                      ARRAYSIZE(taskbarDllHooks));
}

}  // namespace

// ===== Mod lifecycle =====
BOOL Wh_ModInit() {
    Wh_Log(L"Island: init");
    g_unloading = false;
    g_modActive = false;
    g_mediaRefreshRequested = false;
    g_settings = ReadSettings();

    if (!HookTaskbarSymbols()) {
        Wh_Log(L"Island: failed to hook taskbar symbols");
        return FALSE;
    }

    return TRUE;
}

void Wh_ModAfterInit() {
    if (g_unloading) {
        return;
    }
    g_modActive = true;
    g_taskbarWnd = FindCurrentProcessTaskbarWnd();
    // Acquire borderless monitor-capture access while the mod initializes,
    // not on the user's first click. The WGC liquid surface can therefore
    // render from the opening animation's first frame.
    RequestPopupOverlayWgcBorderlessAccessAsync();
    ApplySettingsOnTaskbarThread();
    StartMediaThread();
    RequestMediaRefresh();
}

void Wh_ModUninit() {
    if (g_unloading.exchange(true)) {
        return;
    }
    g_modActive = false;
    StopPopupOverlayWgcBorderlessAccessThread();
    ReleasePopupOverlayWgcDeviceResources();
    StopMediaThread();

    HWND hwnd = g_taskbarWnd && IsWindow(g_taskbarWnd)
                    ? g_taskbarWnd
                    : FindCurrentProcessTaskbarWnd();
    if (!hwnd && g_expandedPopup && IsWindow(g_expandedPopup)) {
        hwnd = g_expandedPopup;
    }
    if (hwnd) {
        RunFromWindowThread(hwnd, [](void*) { RemoveIslandGrid(); }, nullptr);
    }
    UnregisterPopupWindowClass();
}

void Wh_ModSettingsChanged() {
    if (!IsModActive()) {
        return;
    }
    if (Wh_GetIntValue(kMigrateMicaLikeMaterialValue, 0) &&
        GetStringSetting(L"Main.Material", L"acrylic") == L"mica_like") {
        // A settings-page change makes the current material an explicit user
        // choice. Stop applying the one-time old-default migration so
        // Mica-like can be selected normally after the update.
        Wh_SetIntValue(kMigrateMicaLikeMaterialValue, 0);
    }

    Settings settings = ReadSettings();
    {
        std::lock_guard lock(g_pendingSettingsMutex);
        g_pendingSettings = std::move(settings);
    }
    ApplySettingsOnTaskbarThread();
    RequestMediaRefresh();
}
