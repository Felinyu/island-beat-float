#!/usr/bin/env python3
"""Build 1:1 comparisons between the real 3.1.1 panel captures and the rendered
showcase mockups.

Both sides are at the same pixel scale (2x the real UI): a 308 x 80 px compact
pill and a 648 x 1156 px expanded glass surface. The comparison images
therefore need no rescaling, so layout differences are directly readable.

Inputs:
    preview/reference/real-compact-3.1.1.png     (335 x 110 real capture)
    preview/reference/real-expanded-3.1.1.png    (1100 x 1000 real capture)
    screenshots/compact.png, screenshots/expanded.png

Outputs:
    preview/compare/compact.png    real | render | 50% overlay, 1:1 pixels
    preview/compare/expanded.png   real | render | bottom-aligned overlay

The compact overlay is aligned on the pill's top-left corner; the expanded
overlay is aligned on the card's bottom edge (the real capture is cropped at
the top, so the bottom is the only common anchor).

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

BG = (12, 14, 20)
FG = (235, 235, 240)
DIM = (150, 155, 170)
PAD = 16
LABEL_H = 26
GAP = 20

FONT_REG = r"C:\Windows\Fonts\segoeui.ttf"
FONT_BOLD = r"C:\Windows\Fonts\seguisb.ttf"

# Pill / card positions measured from the real captures (2x pixels) and from
# the rendered mockups.
REAL_PILL = (33.0, 14.0)           # pill top-left in real-compact-3.1.1.png
OUR_PILL = (38.5, 15.0)            # pill top-left in screenshots/compact.png
REAL_CARD = (165, 0, 812, 933)     # card region in real-expanded-3.1.1.png
OUR_CARD = (36, 62, 684, 1218)     # card region in screenshots/expanded.png


def font(path: str, size: int) -> ImageFont.FreeTypeFont:
    try:
        return ImageFont.truetype(path, size)
    except OSError:
        return ImageFont.load_default()


def add_panel(canvas: Image.Image, x: int, y: int, img: Image.Image) -> None:
    canvas.paste(img, (x, y))
    ImageDraw.Draw(canvas).rectangle(
        (x - 1, y - 1, x + img.width, y + img.height), outline=(72, 76, 88)
    )


def add_label(draw: ImageDraw.ImageDraw, x: int, y: int, text: str) -> None:
    draw.text((x, y), text, fill=FG, font=font(FONT_BOLD, 14))


def build_compact() -> None:
    real = Image.open(os.path.join(REF, "real-compact-3.1.1.png")).convert("RGB")
    ours = Image.open(os.path.join(SHOTS, "compact.png")).convert("RGB")

    # 50% overlay aligned on the pill top-left corner (integer round).
    aligned = Image.new("RGB", ours.size, BG)
    aligned.paste(
        real,
        (
            round(OUR_PILL[0] - REAL_PILL[0]),
            round(OUR_PILL[1] - REAL_PILL[1]),
        ),
    )
    overlay = Image.blend(aligned, ours, 0.5)

    w = PAD * 2 + real.width + GAP + ours.width + GAP + overlay.width
    h = PAD * 2 + LABEL_H + max(real.height, ours.height)
    canvas = Image.new("RGB", (w, h), BG)
    draw = ImageDraw.Draw(canvas)

    x = PAD
    for img, text in (
        (real, "real 3.1.1 capture (335 x 110 px)"),
        (ours, "rendered mockup (385 x 110 px)"),
        (overlay, "overlay, aligned on pill top-left"),
    ):
        add_label(draw, x, PAD, text)
        add_panel(canvas, x, PAD + LABEL_H, img)
        x += img.width + GAP

    canvas.save(os.path.join(OUT, "compact.png"), "PNG", optimize=True)
    print("wrote preview/compare/compact.png", canvas.size)


def build_expanded() -> None:
    real = Image.open(os.path.join(REF, "real-expanded-3.1.1.png")).convert("RGB")
    ours = Image.open(os.path.join(SHOTS, "expanded.png")).convert("RGB")

    real_card = real.crop(REAL_CARD)
    our_card = ours.crop(OUR_CARD)

    # Align on the card bottom (the real capture is cropped at the top).
    height = max(real_card.height, our_card.height)
    real_off = height - real_card.height

    base = Image.new("RGB", (our_card.width, height), BG)
    base.paste(real_card, (0, real_off))
    base.paste(our_card, (0, height - our_card.height))
    overlay = Image.blend(base, Image.new("RGB", base.size, BG), 0.5)
    # keep the render fully visible, blend the real capture on top of it
    overlay = Image.new("RGB", (our_card.width, height), BG)
    overlay.paste(our_card, (0, height - our_card.height))
    real_layer = Image.new("RGBA", overlay.size, (0, 0, 0, 0))
    real_layer.paste(real_card, (0, real_off))
    overlay = Image.composite(
        real_layer.convert("RGB"), overlay, real_layer.getchannel("A").point(lambda a: a // 2)
    ).convert("RGB") if False else Image.blend(
        overlay, Image.composite(real_layer.convert("RGB"), Image.new("RGB", overlay.size, BG), real_layer.getchannel("A")), 0.5
    )

    w = PAD * 2 + our_card.width * 3 + GAP * 2
    h = PAD * 2 + LABEL_H + height
    canvas = Image.new("RGB", (w, h), BG)
    draw = ImageDraw.Draw(canvas)

    x = PAD
    for img, off, text in (
        (real_card, real_off, "real 3.1.1 capture (top-cropped)"),
        (our_card, height - our_card.height, "rendered mockup"),
        (overlay, 0, "overlay, aligned on card bottom"),
    ):
        add_label(draw, x, PAD, text)
        draw.rectangle(
            (x - 1, PAD + LABEL_H - 1, x + our_card.width, PAD + LABEL_H + height),
            outline=(72, 76, 88),
        )
        canvas.paste(img, (x, PAD + LABEL_H + off))
        x += our_card.width + GAP

    canvas.save(os.path.join(OUT, "expanded.png"), "PNG", optimize=True)
    print("wrote preview/compare/expanded.png", canvas.size)


def main() -> None:
    os.makedirs(OUT, exist_ok=True)
    build_compact()
    build_expanded()


if __name__ == "__main__":
    main()
