#!/usr/bin/env python3
"""Render the Island Beat Float README showcase images.

The mockups live in ``preview/preview.html`` (one self-contained page, three
artboards selected with ``?view=compact|expanded|hero``).  Each artboard is
rendered at 2x device scale with Microsoft Edge headless into a padded
viewport, cropped back to the artboard rectangle, given subtly rounded
corners and written to ``screenshots/``.

Usage (from anywhere):
    python preview/build.py

Requires Microsoft Edge and Pillow; everything else is in the repo.
"""

from __future__ import annotations

import os
import shutil
import subprocess
import sys
import tempfile

from PIL import Image, ImageDraw

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
SHOTS = os.path.join(ROOT, "screenshots")
PAGE = os.path.join(HERE, "preview.html")
EDGE_CANDIDATES = (
    r"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe",
    r"C:\Program Files\Microsoft\Edge\Application\msedge.exe",
)
DSF = 2          # --force-device-scale-factor
MARGIN = 40      # CSS px of stage-coloured padding around each artboard

# name, css width, css height, crop corner radius (CSS px), output width (px)
VIEWS = (
    ("compact", 390, 100, 16, None),
    ("expanded", 400, 725, 20, None),
    ("hero", 1280, 700, 20, 1600),
)


def find_edge() -> str:
    for candidate in EDGE_CANDIDATES:
        if os.path.isfile(candidate):
            return candidate
    found = shutil.which("msedge")
    if found:
        return found
    sys.exit("Microsoft Edge not found; install Edge or edit EDGE_CANDIDATES.")


def render(edge: str, profile: str, view: str, css_w: int, css_h: int, dump: str) -> None:
    """Screenshot one artboard at 2x into *dump*."""
    win_w = css_w + 2 * MARGIN
    win_h = css_h + 2 * MARGIN
    url = "file:///" + PAGE.replace("\\", "/") + "?view=" + view
    cmd = [
        edge,
        "--headless=new",
        "--disable-gpu",
        "--hide-scrollbars",
        "--no-first-run",
        "--no-default-browser-check",
        "--disable-extensions",
        "--disable-sync",
        "--disable-background-networking",
        "--disable-component-update",
        f"--force-device-scale-factor={DSF}",
        f"--user-data-dir={profile}",
        f"--window-size={win_w},{win_h}",
        f"--screenshot={dump}",
        url,
    ]
    result = subprocess.run(
        cmd,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.PIPE,
        timeout=120,
    )
    if not os.path.isfile(dump):
        sys.exit(
            f"Edge produced no screenshot for {view!r} (exit {result.returncode}).\n"
            + result.stderr.decode("utf-8", "replace")[-2000:]
        )


def rounded_mask(width: int, height: int, radius: int) -> Image.Image:
    """Anti-aliased rounded-rectangle alpha mask (supersampled 4x)."""
    scale = 4
    mask = Image.new("L", (width * scale, height * scale), 0)
    draw = ImageDraw.Draw(mask)
    draw.rounded_rectangle(
        (0, 0, width * scale - 1, height * scale - 1),
        radius=radius * scale,
        fill=255,
    )
    return mask.resize((width, height), Image.LANCZOS)


def main() -> None:
    edge = find_edge()
    os.makedirs(SHOTS, exist_ok=True)
    profile = os.path.join(tempfile.gettempdir(), "island-beat-float-preview-profile")
    work = tempfile.mkdtemp(prefix="island-beat-float-preview-")
    try:
        for name, css_w, css_h, radius, out_w in VIEWS:
            dump = os.path.join(work, name + "-raw.png")
            print(f"[render] {name}: {css_w}x{css_h} css -> Edge window "
                  f"{css_w + 2 * MARGIN}x{css_h + 2 * MARGIN} @{DSF}x")
            render(edge, profile, name, css_w, css_h, dump)

            with Image.open(dump) as raw:
                raw = raw.convert("RGBA")
                expected = ((css_w + 2 * MARGIN) * DSF, (css_h + 2 * MARGIN) * DSF)
                if raw.size != expected:
                    sys.exit(f"{name}: expected {expected} raw pixels, got {raw.size}")
                box = (
                    MARGIN * DSF,
                    MARGIN * DSF,
                    (MARGIN + css_w) * DSF,
                    (MARGIN + css_h) * DSF,
                )
                img = raw.crop(box)

            if out_w and img.width != out_w:
                ratio = out_w / img.width
                out_size = (out_w, round(img.height * ratio))
                radius_px = max(1, round(radius * DSF * ratio))
                img = img.resize(out_size, Image.LANCZOS)
            else:
                radius_px = radius * DSF

            img.putalpha(rounded_mask(img.width, img.height, radius_px))
            out = os.path.join(SHOTS, name + ".png")
            img.save(out, "PNG", optimize=True)
            print(f"[write ] {os.path.relpath(out, ROOT)}: "
                  f"{img.width}x{img.height} px, {os.path.getsize(out) // 1024} KiB")
    finally:
        shutil.rmtree(work, ignore_errors=True)


if __name__ == "__main__":
    main()
