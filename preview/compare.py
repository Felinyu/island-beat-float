#!/usr/bin/env python3
"""Build 1:1 side-by-side comparisons between the real panel captures and the
rendered showcase mockups, so fidelity can be judged at the same pixel scale.

Inputs:
    preview/reference/real-compact-3.0.png     (390 x 105 real capture)
    preview/reference/real-expanded-3.0.png    (645 x 1197 real capture)
    screenshots/compact.png, screenshots/expanded.png

Outputs (both at the real capture's pixel scale):
    preview/compare/compact.png
    preview/compare/expanded.png

Usage: python preview/compare.py
"""

from __future__ import annotations

import os

from PIL import Image, ImageDraw, ImageFont

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
REF = os.path.join(HERE, "reference")
SHOTS = os.path.join(ROOT, "screenshots")
OUT = os.path.join(HERE, "compare")

BG = (13, 17, 23)
FG = (230, 230, 235)
MUTED = (150, 155, 165)
PAD = 16
LABEL_H = 26

FONT_REG = r"C:\Windows\Fonts\segoeui.ttf"
FONT_BOLD = r"C:\Windows\Fonts\seguisb.ttf"


def font(path: str, size: int) -> ImageFont.FreeTypeFont:
    try:
        return ImageFont.truetype(path, size)
    except OSError:
        return ImageFont.load_default()


def caption(draw: ImageDraw.ImageDraw, x: int, y: int, text: str, bold: bool = False) -> None:
    draw.text((x, y), text, fill=FG, font=font(FONT_BOLD if bold else FONT_REG, 14))


def frame(img: Image.Image, color=(70, 74, 84)) -> Image.Image:
    """1 px outline so the image bounds are visible on the dark canvas."""
    out = img.copy()
    draw = ImageDraw.Draw(out)
    draw.rectangle((0, 0, out.width - 1, out.height - 1), outline=color)
    return out


def build_compact() -> None:
    real = Image.open(os.path.join(REF, "real-compact-3.0.png")).convert("RGB")
    ours = Image.open(os.path.join(SHOTS, "compact.png")).convert("RGB")
    # The mockup is rendered at 2x the real capture's pixel scale: put it back
    # at capture scale for the comparison.
    ours = ours.resize((ours.width // 2, ours.height // 2), Image.LANCZOS)

    gap = 20
    canvas = Image.new("RGB", (PAD * 2 + real.width + gap + ours.width, PAD * 2 + LABEL_H + max(real.height, ours.height)), BG)
    draw = ImageDraw.Draw(canvas)
    caption(draw, PAD, PAD, "real 3.0.0 capture (390 x 105 px)", bold=True)
    caption(draw, PAD + real.width + gap, PAD, "rendered mockup (same scale)", bold=True)
    canvas.paste(frame(real), (PAD, PAD + LABEL_H))
    canvas.paste(frame(ours), (PAD + real.width + gap, PAD + LABEL_H))
    out = os.path.join(OUT, "compact.png")
    canvas.save(out, "PNG", optimize=True)
    print("wrote", os.path.relpath(out, ROOT), canvas.size)


def build_expanded() -> None:
    real = Image.open(os.path.join(REF, "real-expanded-3.0.png")).convert("RGB")
    ours = Image.open(os.path.join(SHOTS, "expanded.png")).convert("RGB")

    # The visible glass surface in our render is 720 x 1284 px at (40, 83) of
    # the 800 x 1450 render; the real capture's surface is 645 x 1155 at
    # (0, 10).  Scale our surface to the capture's pixel size.
    shell = ours.crop((40, 83, 760, 1367))
    scale = real.width / shell.width
    shell = shell.resize((real.width, round(shell.height * scale)), Image.LANCZOS)
    real_shell = real.crop((0, 10, real.width, 1165))

    gap = 24
    height = PAD * 2 + LABEL_H + max(real_shell.height, shell.height)
    canvas = Image.new("RGB", (PAD * 2 + real_shell.width * 2 + gap, height), BG)
    draw = ImageDraw.Draw(canvas)
    caption(draw, PAD, PAD, "real 3.0.0 capture (glass surface 645 x 1155 px)", bold=True)
    caption(draw, PAD + real_shell.width + gap, PAD, "rendered mockup (same scale)", bold=True)
    canvas.paste(frame(real_shell), (PAD, PAD + LABEL_H))
    canvas.paste(frame(shell), (PAD + real_shell.width + gap, PAD + LABEL_H))
    out = os.path.join(OUT, "expanded.png")
    canvas.save(out, "PNG", optimize=True)
    print("wrote", os.path.relpath(out, ROOT), canvas.size)


def main() -> None:
    os.makedirs(OUT, exist_ok=True)
    build_compact()
    build_expanded()


if __name__ == "__main__":
    main()
