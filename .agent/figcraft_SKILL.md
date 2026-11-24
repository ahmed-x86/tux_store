---
name: figcraft
description: Read, understand, generate, edit, and validate `.figcraft` design files (a Figma-like, ZIP-based design format containing `document.json` + `images/` + `thumbnail.png`). Use this skill whenever the user mentions figcraft, a `.figcraft` file, FigCraft, an unzipped folder containing `document.json` with `"format": "figcraft"`, or wants to create/convert/modify UI mockups, app screens, wireframes or design systems that must be saved as a figcraft file. Also use it when asked to explain, audit, restyle, translate (text), recolor, or batch-edit an existing figcraft design, or to build a UI design programmatically (e.g. a Catppuccin-style dark app UI) in this format, even if the user never says "skill" or describes the format in detail.
---

# FigCraft (`.figcraft`) — Complete Format & Design Skill

This skill teaches you (an AI) how a `.figcraft` file is built, how to **read** it, how to **generate** a correct one from scratch, how to **edit** it safely, and how to **design** screens in the same quality/style as the reference project (**"Tux Store"**, a dark Catppuccin‑Mocha package-manager UI for Arch Linux).

Everything below was reverse‑engineered from a real file (`TuxStore_5 (1).figcraft`: 2152 nodes, 17 screens, 134 images, ~1.2 MB JSON) and **verified** by (a) validating the original with the validator in §18, (b) rendering its frames with the renderer in §18 and comparing against the thumbnail, and (c) generating a new file with the builder and validating/rendering it. Where something is *not observed* in the sample, it is explicitly marked **[UNOBSERVED]** — do not invent it; see §15.

---

## 0. TL;DR — the 15 rules that matter most

1. A `.figcraft` file is a **ZIP** (deflate). Root entries: `document.json`, `images/<sha256>` (extension‑less PNG bytes), `thumbnail.png` (400×286 RGBA PNG).
2. `document.json` is one JSON object: `format:"figcraft"`, `version:1`, `imageIndex`, `name`, `pages`, `nodes`, `next_id`, `styles`, `variables`, `current_page`, `document_colors`, `comments`.
3. `nodes` is a **flat dictionary**: string id → node object. The tree is expressed with `parent` (int) and `children` (list of ints). Keep both in sync.
4. Node types seen: `page`, `frame`, `rectangle`, `text`, `vector`. Nothing else (no ellipse/line/group/component/instance types were observed).
5. **Children order = paint order.** First child is at the bottom; last child is on top. (Ids are NOT guaranteed sorted — 2 children lists in the sample are not sorted.)
6. Each non-page node has a 6‑number `transform` `[a,b,c,d,tx,ty]`. In practice `[1,0,0,1,x,y]`; **x,y are relative to the parent's top‑left**. A missing `transform` means `(0,0)`.
7. There is **no stroke, no shadow, no gradient, no auto‑layout** in this document. Everything is absolutely positioned. Borders are faked with **two stacked rectangles** (outer = border colour, inner = fill, inset by 1px, radius−1). Gradients are **baked PNG images** used as image fills.
8. Fills are lists. Only two fill types exist: `solid` and `image`. Colours are `{r,g,b,a}` floats 0‥1.
9. Text nodes always carry `characters`, a `style` object (Inter), `auto_resize`, an explicit measured `width`/`height`, and a `child_layout` object. Text colour lives in the **node's** `fills`, **not** in `style.fills` (which is `null`).
10. Image fills reference an image by its **SHA‑256 hex of the PNG file bytes**, and every used hash must be in `imageIndex` *and* exist as `images/<hash>`.
11. `next_id` must be **greater than every id** in use. Allocate new ids from it and bump it.
12. Screens are top‑level `frame`s directly under the page, 1920×1023, named `"NN Title"`, laid on a canvas grid with pitch **2120 × 1223** (200 px gaps).
13. Scrollable regions are a child frame named `"Content (scrolls)"` with `clip:true`; rows inside are frames named `"Row: …"` with `clip:true`.
14. Dark palette = Catppuccin **Mocha** (see §12). Text/radius/spacing scales are tiny and consistent — reuse them, don't invent new values.
15. After generating or editing, **always run the validator** (§18) and ideally the renderer, then fix anything it reports.

---

## 1. When to use this skill

Use when the user:
- uploads/mentions a `.figcraft` file or an unzipped folder with `document.json`, `images/`, `thumbnail.png`;
- asks to "explain / read / summarise / audit" a figcraft design;
- asks to create a new design/mockup/app UI **as figcraft**;
- asks to change text, colours, sizes, add/remove screens or components in an existing figcraft;
- asks to teach another AI how figcraft works (give them this file).

Do **not** use for real Figma `.fig` files, SVG, or HTML/CSS generation — unless the user wants a figcraft output derived from them.

---

## 2. Container format (ZIP)

```
MyDesign.figcraft            # a normal ZIP archive, deflate-compressed
├── document.json            # the whole design (JSON, UTF-8)
├── thumbnail.png            # 400x286, RGBA PNG, preview of the file (shows all top-level frames)
└── images/
    ├── 02e35210…caa7        # NO extension. Raw PNG bytes. Filename == sha256(file bytes) in lowercase hex (64 chars)
    └── …
```

Facts verified on the sample:
- `file x.figcraft` → "Zip archive data". All 134 image files are PNG; **filename == SHA‑256 of the file's bytes for 134/134**.
- Images are stored **once** even if used many times (134 unique images are used by 187 fills).
- The user's `tree` output (document.json, images/, thumbnail.png) is just the ZIP extracted.

Unpack / repack:

```bash
mkdir out && cd out && unzip -q ../file.figcraft        # unpack
# ... edit document.json / add images/<sha256> ...
zip -q -r ../new.figcraft document.json images thumbnail.png   # repack (document.json at ZIP root, no wrapper folder!)
```

⚠️ Never put the files inside a subfolder in the ZIP; `document.json` must be at the archive root. Python: use `zipfile.ZipFile(path,"w",zipfile.ZIP_DEFLATED)` and `writestr("document.json", …)`, `writestr("images/<hash>", bytes)`.

**Thumbnail**: any 400×286 PNG works for validity. Ideally render the top-level frames into a contact sheet (the original is a 4‑column mini overview of all screens on the page background `#1E1E1E`). If you can't render, write a flat `#1E1E1E` PNG (the builder does this) — or copy the old thumbnail when only doing small edits.

---

## 3. `document.json` — top level

```jsonc
{
  "format": "figcraft",          // constant
  "version": 1,                  // constant (int)
  "imageIndex": [                // one entry per image file; sorted by hash in the sample
    { "hash": "02e3…caa7", "width": 64, "height": 64 }
  ],
  "name": "Tux Store",           // document name
  "pages": [2],                  // list of page node ids (sample has exactly one page)
  "nodes": { "2": {…}, "3": {…}, … },   // FLAT dict, keys are STRINGS of the int id
  "next_id": 2166,               // > max(id). In the sample max id = 2165
  "styles": [],                  // shared styles — EMPTY in sample [UNOBSERVED content]
  "variables": { "collections": [], "variables": [] },   // EMPTY in sample [UNOBSERVED content]
  "current_page": 2,             // id of the active page (must be in `pages`)
  "document_colors": [],         // EMPTY in sample
  "comments": []                 // EMPTY in sample
}
```

Id notes: ids start at **2** (the page). The first screen is 3. Ids in the sample are allocated depth‑first in creation order (header pieces, then content), but nothing requires that — only uniqueness and `< next_id`.

`imageIndex[i].width/height` are the **pixel size of the PNG** (not the displayed size).

---

## 4. Common node fields

| field | type | notes |
|---|---|---|
| `id` | int | equals the dict key (as string) |
| `name` | string | human label. **Names carry semantic meaning** (see §14) |
| `type` | `"page" \| "frame" \| "rectangle" \| "text" \| "vector"` | |
| `parent` | int | id of parent (absent on the page) |
| `children` | int[] | frames/pages only; **ordered bottom → top** |
| `blend` | `"normal"` | present on rectangle/text/vector (not frame/page) |
| `transform` | `[a,b,c,d,tx,ty]` | affine; relative to parent; omit ⇒ identity at (0,0) |
| `width`,`height` | float | node size in px |
| `fills` | Fill[] | see §6 |
| `corners` | `{radii:[tl,tr,br,bl], smoothing:0.0}` | optional |
| `clip` | bool | frames only |

Key presence stats (sample): rectangle: `transform` 1005/1034 (missing ⇒ x=y=0), `corners` 818/1034; frame: `clip` 38/38, `fills` 17/38 (the "Content/Row" frames have **no fills** — transparent), `corners` 17/38 (only the 17 screens).

### 4.1 `page`

```json
{ "id":2, "name":"Page 1", "type":"page",
  "background":{"r":0.1176,"g":0.1176,"b":0.1176,"a":1.0},          // #1E1E1E canvas colour
  "flows":[],
  "prototype":{"device":"None","background":{"r":0.11764706,"g":0.11764706,"b":0.11764706,"a":1.0},"rotation":"portrait"},
  "children":[3,90,305,508,734,779,838,955,1203,1305,1355,1458,1595,1849,2065,1881,1936],
  "width":0.0,"height":0.0 }
```
`flows` (prototype links) is empty **[UNOBSERVED content]**.

### 4.2 `frame`

```json
{ "id":3, "name":"01 Home", "type":"frame", "parent":2, "children":[4,5,…,23],
  "width":1920.0, "height":1023.0,
  "fills":[{"type":"solid","color":{"r":0.1176,"g":0.1176,"b":0.1804,"a":1.0},"opacity":1.0,"visible":true,"blend":"normal"}],
  "corners":{"radii":[12.0,12.0,12.0,12.0],"smoothing":0.0},
  "clip":true }
```
- A frame is both **a container and a clipping window** (`clip:true` for all 38). Children outside the frame bounds are cut off.
- The first screen has **no `transform`** (it's at 0,0); all others have one.
- Frames never have `blend`, `child_layout`, or auto‑layout props in this file.

### 4.3 `rectangle`

```json
{ "id":33, "name":"Card border: Steam", "type":"rectangle", "parent":32, "blend":"normal",
  "width":200.0, "height":178.0,
  "fills":[{"type":"solid","color":{…#45475A…},"opacity":1.0,"visible":true,"blend":"normal"}],
  "corners":{"radii":[12.0,12.0,12.0,12.0],"smoothing":0.0} }          // note: no transform ⇒ (0,0)
```
Used for **everything non-text**: backgrounds, borders, buttons, dividers, scrollbars, icons (image fill), screenshots (image fill), checkboxes, toggles, glow lines, scrims.

### 4.4 `text`

```json
{ "id":42, "name":"Name", "type":"text", "characters":"Qbittorrent",
  "style":{ "font_family":"Inter","font_style":"Bold","font_size":12.0,
            "line_height":{"unit":"auto"},
            "letter_spacing":{"unit":"percent","value":0.0},
            "decoration":"none","case":"original","fills":null,"link":null },
  "auto_resize":"height",
  "parent":32, "blend":"normal", "transform":[1,0,0,1,283.83,100.5],
  "width":68.34, "height":15.0,
  "fills":[{"type":"solid","color":{"r":0.8039,"g":0.8392,"b":0.9569,"a":1.0},"opacity":1.0,"visible":true,"blend":"normal"}],
  "child_layout":{"sizing_h":"fixed","sizing_v":"hug","absolute":false,"min_w":null,"max_w":null,"min_h":null,"max_h":null,
                  "grid_column":null,"grid_row":null,"grid_column_span":0,"grid_row_span":0} }
```
Details in §7.

### 4.5 `vector`

Only **1** in the whole file ("Row-to-pane flow (top)", a 20×20 inverted rounded‑corner connector, rotated 180°). Structure:

```json
{ "type":"vector",
  "network":{ "vertices":[{"x":10,"y":0,"radius":0}, …],
              "segments":[{"a":0,"b":1,"ta":[0,0],"tb":[0,0]}, …],   // ta/tb = bezier tangents (relative handles)
              "regions":[{"loops":[[0,1,2,3,4,5]],"winding":"nonZero"}] },
  "transform":[-1,0,0,-1,949,176], "width":20, "height":20, "fills":[solid #1E1E2E] }
```
- It's a **vertex network** (Figma‑style): `vertices` (x,y,radius), `segments` (a,b = vertex indices, `ta`,`tb` tangents), `regions` (closed loops of vertex indices + winding rule).
- The only observed non‑identity transform is a **180° rotation `[-1,0,0,-1,tx,ty]`**; for it, `(tx,ty)` is the **bottom‑right corner** of the shape in parent space (the shape extends left/up from there). The sample uses it twice (the "inverted corner" that visually joins a selected row to the detail pane).
- Use vectors only when you truly need a non‑rectangular shape; prefer rectangles.

---

## 5. Coordinate system, z‑order, clipping

- Origin top‑left, +x right, +y down, units = px (design is 1920×1023 desktop).
- A child's `transform` `tx,ty` is **relative to the parent's top‑left**. Absolute position = sum of ancestors' offsets. (Top-level screens use page coordinates.)
- **Z‑order = order of the `children` array**, first = bottom. To bring something to front, move its id to the end of its parent's `children`.
- `clip:true` frames clip all descendants to their rectangle (with the frame's corner radii if set). Use it for scroll windows: put content taller/wider than the frame, the overflow is cut off.
- Content that "scrolls" is simply laid out **past** the frame edge (e.g. a 54‑child row of cards 1872 px wide where only part is visible inside the 1920 screen, and a scrollbar thumb drawn to hint it).
- Negative offsets are legal and used (e.g. `Row: For You` at `y:-22` in the scrolled variant, to show the page scrolled).

---

## 6. Fills

```jsonc
// SOLID
{ "type":"solid", "color":{"r":0.1922,"g":0.1961,"b":0.2667,"a":1.0}, "opacity":1.0, "visible":true, "blend":"normal" }

// IMAGE
{ "type":"image", "image":"<sha256 hex>", "scale_mode":"fill", "scale":1.0, "rotation":0, "crop":null,
  "filters":{"exposure":0.0,"contrast":0.0,"saturation":0.0,"temperature":0.0,"tint":0.0,"highlights":0.0,"shadows":0.0},
  "opacity":1.0, "visible":true, "blend":"normal" }
```
Observed counts: 1943 solid, 187 image. Observed values: all image fills use `scale_mode:"fill"`, `scale:1.0`, `rotation:0`, `crop:null`, zeroed filters. Solid `opacity` is 1.0 almost everywhere; the only exception is the **modal scrim: `#000000` at `opacity:0.5`** (use opacity for dimming, not `color.a`; `color.a` is always 1.0).

Colour conversion: `r = int("RR",16)/255` rounded to 4 decimals (the sample mixes 4‑decimal and 8‑decimal values; both fine).

Only `fills[0]` is ever used (single fill per node).

**Gradients do not exist as a fill type.** The sample's gradients (the pastel purple→blue "active tab" pill, the dark shade over the carousel) are **PNG images** (176×36, 190×36, 194×36, 8×120) stretched with `scale_mode:"fill"` and rounded with the rectangle's own `corners`. To make a gradient: render a small PNG with PIL, hash it, add to `imageIndex` + `images/`, and fill a rectangle with it.

---

## 7. Text in depth

### 7.1 Style object (all 1078 text nodes)
- `font_family`: always `"Inter"`.
- `font_style`: `"Bold"` (582), `"Regular"` (490), `"Medium"` (6). Nothing else — use only these 3.
- `font_size` observed (px): **8, 9, 9.5, 10, 10.5, 11, 11.5, 12, 12.5, 13, 14, 15, 16, 18, 19, 20, 21, 26, 28, 32, 36** (see §12 for role mapping).
- `line_height`: always `{"unit":"auto"}`. `letter_spacing`: percent; 0.0 except 5 nodes with `10.0` (the uppercase section labels like `BROWSE`, size 9 Bold). `decoration:"none"`, `case:"original"` always (uppercase labels are typed uppercase in `characters`, not via `case`). `link:null`.
- **Colour is in `node.fills`** (a solid fill). `style.fills` stays `null`.

### 7.2 Sizing semantics
- `auto_resize:"height"` (1072 nodes) + `child_layout.sizing_h:"fixed"`, `sizing_v:"hug"` → single-line text whose **width is fixed to the measured width** and height hugs the line.
- `auto_resize:"none"` (6 nodes) → fixed box (used for the package‑details title/stat/labels, where width/height were set explicitly, and `child_layout` is **absent**).
- All text is **single line**: no `\n` appears in any `characters`. For multi-line copy the sample creates **separate text nodes per line** (`Dialog text 1`, `Dialog text 2`, `Engine help 1/2`) positioned 24px apart for 11–11.5px text. Do the same; don't rely on wrapping.

### 7.3 Height from font size (Inter "auto" line height ≈ 1.21 × size, rounded)

| size | 8 | 9 | 9.5 | 10 | 10.5 | 11 | 11.5 | 12 | 12.5 | 14 | 15 | 16 | 18 | 19 | 20 | 21 | 26 | 28 | 32 | 36 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| height | 10 | 11 | 11 | 12 | 13 | 13 | 14 | 15 | 15 | 17 | 18 | 19 | 22 | 23 | 24 | 25 | 31 | 34 | 39 | 42 |

(Some nodes deviate by a pixel, e.g. 12px → 13; 16px → 21; fine. Formula `round(size*1.21)` is good.)

### 7.4 Width estimation (when you have no font metrics)
Average advance of Inter in this file, as a fraction of font size per character: **Bold ≈ 0.544, Regular ≈ 0.487, Medium ≈ 0.562** (e.g. "Steam" Bold 12 → 41.34 px). `width = round(len(text) * size * k, 2)`. For precision, measure with PIL + Inter TTF (`ImageFont.truetype("Inter-Bold.ttf", size).getlength(text)`) if the font is available. Slight width errors are harmless visually but make centering imperfect; if you can measure, do.

### 7.5 Placing text
- `transform` = top‑left of the text box.
- **Vertical centering** inside a box of height H at y0: `y = y0 + (H - text_height)/2` (e.g. button 34 px tall at y153, 11px text (h13) → y=163.5 ✔ exact).
- **Horizontal centering**: `x = box_x + (box_w - text_w)/2`. In the sample centred texts are consistently nudged **+2 px right** of the geometric centre (card centre at x+100, text centre at x+102; same on buttons). Optional detail, replicate for pixel parity.
- Left‑aligned text uses the content padding of its container (cards in settings: x=580 inside an 800‑wide card starting at 560 ⇒ 20 px padding).
- Right‑aligned text: compute `x = right_edge - width`.
- Long names are **truncated manually** in `characters` with an ellipsis (`"Heroic Games Launcher …"`) — there is no overflow handling.

### 7.6 Glyph icons as text
Simple icons are text glyphs: `×` (close, 18–20px Regular), `›` (chevron, 14–16px Regular, `#9399B2`), `<` `>` (carousel arrows, 20px Bold), `→` (version arrows), `↑ ↓` (dialog options, 16 Bold), `✓` (checkmark 11 Bold), `↻` (fallback app glyph, 28 Regular, `#11111B` on a coloured tile). Prefer these over drawing vectors.

---

## 8. Images

- PNG only. Common sizes: **64×64** app icons (100 unique images, 133 fills), **38×38** category icons, **20×20** nav icons (home/sidebar), **18×18** section icons, **48×48** small app icons, 14×14 caret, 16×16 info, 72×84 package icon, tab‑pill gradients 176/190/194×36, carousel hero 872×460, carousel shade 8×120, screenshots 399×272 / 446×272.
- Icons are drawn **at 1× in a rectangle of identical size** (64×64 image in a 64×64 rectangle). No corner radius on icons (they carry their own transparency/shape); screenshots/hero use radius (hero 24, screenshots ≈ 12).
- Always register a new image: compute `h = sha256(png_bytes).hexdigest()`, add `{"hash":h,"width":w,"height":h}` to `imageIndex`, write `images/<h>`.
- **Fallback tile** when an app has no icon: a rounded rectangle 64×64, radius 11, solid pastel (e.g. `#CBA6F7`, `#14A3C7`, `#3B5BDB`, `#F26B1D`), with a centred `↻` glyph (28 Regular, `#11111B`) on top (glyph box ≈ 30.72×34 at tile (+18.64, +15)).

---

## 9. The "no strokes" rule and the two‑rectangle idiom (CRITICAL)

The format in this file has **no stroke property**. Every 1‑px border is made by two rectangles, **border first, then fill** (so fill paints above):

```
outer  "<X> border"  at (x, y)       size (w, h)         fill = border colour, radius R
inner  "<X>"         at (x+1, y+1)   size (w-2, h-2)     fill = surface colour, radius R-1
```
Examples (exact values from the file):
- Card: border `#45475A` r12 200×178 / body `#313244` r11 198×176 @+1,+1
- Button: border `#45475A` r9 / body `#313244` r8
- Search & input: border `#45475A` r8 36 tall / body `#313244` r7
- Tab bar: border `#313244` r12 480×44 / body `#181825` r11
- Dialog: border `#313244` r16 720×416 / body `#181825` r15
- Detail pane: border `#313244` r24 / body `#171725` r23
- Checkbox: border `#89B4FA` r4 16×16 / body r3 12×12 @+2,+2 (inset 2 here)
- Selected row: border `#89B4FA`-ish with **per‑corner radii** `[16,0,0,16]` / body `[14,0,0,14]` (left corners round, right corners square so it merges with the detail pane).

A "selected/active/primary" state changes the **border colour** (to accent `#89B4FA`) and the body/label colours — it does not add a stroke.

Other "missing feature" workarounds:
| want | do this |
|---|---|
| drop shadow | don't. (None in file.) Use a darker/lighter surface + border. |
| divider | 1‑px‑high rectangle `#313244` (`Divider`, `Header border`, `Sidebar border`) |
| accent bar | 2–3 px rectangle: e.g. dialog top accent `696×2 @ (612,303)` radius 1 in `#F9E2AF` (warning) etc.; sidebar active indicator `3×30` r1.5 `#89B4FA` |
| scrollbar | track `#313244` r3 (6 px thick) + thumb `#585B70` r3. Horizontal track `1872×6 @ (24,871)`, vertical thumb at `x = 1909` (6 wide) |
| modal | full‑screen `Scrim` rectangle `#000000` opacity 0.5, then dialog rectangles/texts above it (later in children) |
| hamburger icon | 3 rectangles 18×2 r1 `#CDD6F4` at y = 23, 30, 37 (7 px pitch) |
| toggle / segmented control | two button pairs; the active one has border + label in accent `#89B4FA` and body `#3E455F`; inactive: border `#585B70`, body `#45475A`, label `#CDD6F4` Regular |
| gradient | baked PNG (see §6) |
| blur/overlay | scrim rectangle |

---

## 10. Screens, canvas grid & naming

Top-level frames (all 1920×1023, radius 12, fill `#1E1E2E`, `clip:true`) and their canvas positions:

```
col x:   0        2120      4240      6360          → pitch 2120 (1920 + 200 gap)
row y=0:      01 Home | 02 Home - scrolled (Browsers, Communication) | 03 Home - scrolled (Security, System, Add-ons) | 04 Sidebar menu
row y=1223:   05 Settings | 06 Categories | 07 Category - ArtCraft | 08 Category - Audio & Video
row y=2446:   09 Groups | 10 Repositories | 11 Updates | 12 Updates - newer packages dialog
row y=3669:   13 Installed | 14 Search results | 15 Package details | 16 Package details - scrolled
row y=4892:   14b Search results - package selected   (extra, wraps to col 0)
```
- Pitch rows: **1223 = 1023 + 200**. Max 4 columns per row, reading order left→right, top→bottom. Page `children` order follows creation order, which is why `14b`(2065) sits before `15`(1881) in the list.
- Name format: `"NN Title"` — two‑digit number, optional letter suffix for inserted variants (`14b`), then a **hyphen + state** for variants (`"Home - scrolled (…)"`, `"Category - ArtCraft"`, `"Updates - newer packages dialog"`). Use `-` ASCII hyphen with spaces.
- **State variants are full duplicates of the screen** with changed content (scrolled content, open sidebar, open dialog). The "sidebar menu" and "dialog" variants literally contain the whole underlying page, then append `Scrim` + sidebar/dialog nodes at the end of the `children` list.
- Scroll state is expressed by shifting the `Content (scrolls)` children (e.g. rows at negative y) — the scroll container stays put.

---

## 11. Layout metrics of the Tux Store screen (1920×1023)

```
Header            rect 0,0   1920×62  #181825;   Header border 0,62  1920×1  #313244
Hamburger         3 lines 18×2 r1 at x=35, y=23/30/37, #CDD6F4
App title         "Tux Store" Bold 16 #89B4FA @ (74, 11.5)
App subtitle      "for Arch Linux" Regular 10 #A2A9C4 @ (74, 42)
Home button       border 1584,13 40×36 #45475A r8 | body 1585,14 38×34 #313244 r7 | icon 20×20 @ 1594,21
Search            border 1636,13 260×36 #45475A r8 | body 1637,14 258×34 #313244 r7 | placeholder Regular 11 #9399B2 centred(+2)
Tab bar           border 720,73 480×44 #313244 r12 | body 721,74 478×42 #181825 r11
Active tab pill   image(gradient) 724,77 176×36 r9  (width follows label: 176 Home, 190 Updates, 194 Installed)
Tab labels        12.5px: active Bold #11111B ; inactive Regular #A6ADC8 ; baseline y=88.5
Content frame     "Content (scrolls)" @ (0,128) 1920×895   (on list screens: @ (0,201) 1920×822 after a heading row)
Sub‑page header   Back button 66–68×36 @ x=1728 ; Forward 86–88×36 @ x=1808 ; y=14 ; content @ (0,64) 1920×959
Page margins      24 px left/right (rows start at x=24, width 1872)
```

---

## 12. Design tokens (Catppuccin Mocha) — reuse exactly

### 12.1 Palette & roles

| Hex | Catppuccin | Role in this design |
|---|---|---|
| `#1E1E1E` | — | Page/canvas background (outside screens) |
| `#1E1E2E` | Base | Screen background |
| `#181825` | Mantle | Header, tab bar body, sidebar, dialog body |
| `#171725` | (custom) | Detail pane body |
| `#11111B` | Crust | Text on bright fills (active tab label, primary button label, glyph on tile) |
| `#313244` | Surface0 | Card/button/input body; row bg; borders of containers; dividers; scroll track |
| `#45475A` | Surface1 | Border of cards/buttons/inputs; inactive toggle body |
| `#585B70` | Surface2 | Scroll thumb; inactive toggle border |
| `#6C7086` | Overlay0 | rare |
| `#9399B2` | Overlay2 | Muted text: placeholders, help text, chevrons, section labels |
| `#A6ADC8` | Subtext0 | Secondary text: versions, inactive tabs, close × |
| `#CDD6F4` | Text | Primary text, hamburger lines |
| `#89B4FA` | Blue | **Primary accent**: title, active borders, primary button fill, indicators, links |
| `#A6E3A1` | Green | "Installed", new version, success, ✓ |
| `#CBA6F7` | Mauve | "Add-on package"/secondary status, fallback tile |
| `#F9E2AF` | Yellow | warnings, dialog accent line |
| `#FAB387` | Peach | tile colours |
| `#F38BA8` | Red | destructive/error |
| `#94E2D5` / `#74C7EC` / `#89DCEB` / `#F5C2E7` / `#EBA0AC` / `#F2CDCD` / `#F5E0DC` | Teal/Sapphire/Sky/Pink/Maroon/Flamingo/Rosewater | category/tile accent colours |
| `#292F45` | (custom) | Active sidebar item bg |
| `#3E455F` | (custom) | Selected toggle body (blue tint) |
| `#414965` | (custom) | Checkbox / option icon tile (blue tint) |
| `#465255` | (custom) | Option tile, green tint |
| `#555257` | (custom) | Option tile, yellow tint |
| `#7D699C`, `#3D3752` | (custom) | purple tint pairs (status badges) |
| `#000000` @ 0.5 | — | Scrim |
| `#939393` + `#000000` glyph | — | Carousel arrow buttons |

Near‑duplicates exist in the sample (`#A6ACC7`, `#A5ACC7`, `#A2A9C4`, `#CCD5F4`, `#CBD3F1`) — artefacts of an export; **prefer the canonical Mocha value** (`#A6ADC8`, `#CDD6F4`).

Tint rule: a "tinted tile" = status colour at ~20 % over `#313244` (e.g. green `#A6E3A1` → `#465255`, yellow → `#555257`, blue → `#414965`, mauve → `#3D3752`).

### 12.2 Type scale (Inter)

| Role | Size | Style | Colour |
|---|---|---|---|
| Hero/carousel title | 32 | Bold | `#FFFFFF` |
| Big numerals / empty headings | 26–36 | Bold | `#CDD6F4` |
| Section/page heading (“For You”, “406 updates available”) | 18 | Bold | `#CDD6F4` |
| Dialog title | 19 | Bold | `#CDD6F4` |
| Empty-state text | 18 | Regular | `#CCD5F4` |
| Card title in settings (“App Theme”) | 14 | Medium | `#CDD6F4` |
| Detail title / package name | 15 (list) – 21+ (details) | Bold | `#CDD6F4` |
| App title (header) | 16 | Bold | `#89B4FA` |
| Tab label | 12.5 | Bold (active) / Regular | `#11111B` / `#A6ADC8` |
| Card name, list name, option title | 12 | Bold | `#CDD6F4` |
| Sidebar item | 12 | Regular (Bold when active, accent) | `#CDD6F4` / `#89B4FA` |
| Body text (dialog) | 11.5 | Regular | `#CDD6F4` |
| Button / input labels, source·version | 11 | Bold (buttons) / Regular | |
| Help text, option description | 10–11 | Regular | `#9399B2` |
| Status badge | 10 | Bold | status colour |
| Version numbers in rows | 10.5 | Regular / Bold(new) | `#A6ADC8` / `#A6E3A1` |
| Count captions | 9.5 | Regular | `#A5ACC7` |
| Section label (uppercase, tracking 10 %) | 9 | Bold | `#9399B2` |
| Footer/version | 9 | Regular | `#9399B2` |

### 12.3 Radius scale
`1` (thin bars) · `1.5` · `3` (scrollbar/checkbox inner) · `4` · `7/8` (inputs) · `8/9` (buttons) · `9` (tab pill) · `10` (update row, tiles, sidebar item) · `11/12` (cards; inner = outer−1) · `16` (dialog) · `24` (hero image, detail pane) · `12` (screens). Pill/circle: radius = half the size (48 px arrow button → 24; 128 px empty icon bg → 64).

### 12.4 Spacing
- Gaps: **16 px** between cards (pitch 216 for 200‑wide cards), **8 px** between rows in lists (row 44 + 8 = pitch 52), **68 px** pitch in category list rows, **50 px** pitch for sidebar items (item 46 + 4), 24 px page margins, 14 px sidebar margins, 20 px inner padding on settings cards.
- Border thickness is always **1**.

---

## 13. Component recipes (exact geometry from the file)

All coordinates are relative to the parent shown. Build **border → body → contents** in that order.

### 13.1 App card (grid item) — in a `Row: …` frame (1872×178, clip)
```
Card border   (x,0)     200×178  #45475A r12
Card          (x+1,1)   198×176  #313244 r11
Icon          (x+68,19) 64×64    image   (or fallback tile + ↻ glyph)
Name          Bold 12  #CDD6F4  y=100.5, centred (centre = x+102)
Source/ver    Regular 11 #A6ADC8 y=128.5  "multilib • 1.0.0.87-3"
Status        Bold 10  y=153  "Installed" #A6E3A1 | "Not installed" #A6ADC8(ish) | "Add-on package" #CBA6F7 | "Installed add-on" #A6E3A1
x pitch = 216 ; the sample puts 8+ cards in a row that overflows the screen (clip hides it) – rows have ~54 children (≈ 9 cards × 6 nodes)
Names/ids: "Card border: <App>", "Card: <App>", "Icon: <App>", "Name", "Source / version", "Status"
```
Card in a list screen (Installed/Category pages) is the same, but laid out as a **grid with 216 px × 216 px pitch** (row pitch = 178 + 38; e.g. y=21, 237…), starting at x=24/25.

### 13.2 Section header + scroll row (Home)
`Section title: <Name>` Bold 18 `#CDD6F4` at (24, y) then `Row: <Name>` frame at (24, y+44) 1872×178. Vertical rhythm between sections ≈ 292 (title 22 + 44 + row 178 + 48 gap).
Horizontal scrollbar (per page, not per row): track 1872×6 @ (24, 871) `#313244` r3; thumb `#585B70` r3 width proportional (954).
Vertical scrollbar thumb: 6×H @ (1909, 3) `#585B70` r3 (inside the content frame).

### 13.3 Carousel / hero
Hero image rect 1000×562 @ (460,23) r24 (image fill; source PNG 872×460, `fill` crops); shade rect 1000×120 @ (460, 465) (gradient PNG 8×120, bottom of hero); title Bold 32 `#FFFFFF` @ (492, 531.5); prev/next buttons 48×48 r24 `#939393` at x=476 / 1396, y=281, with `<`/`>` Bold 20 `#000000` centred.

### 13.4 Header (every screen)
See §11. Home screens show hamburger + title/subtitle on the left, **tab bar centred** (x=720), home button + search on the right. Sub‑pages replace right side with **Back/Forward** buttons and the left title shifts to x=34.

### 13.5 Tab bar (3 tabs)
Container 480×44 @ (720,73). Pill under the active label: 176/190/194 × 36 @ (724/857/1003, 77). Labels 12.5px centred in thirds: Home centre x≈814, Updates ≈ 954, Installed ≈ 1101 (active label x = pill_x + (pill_w - label_w)/2; inactive labels are laid out so that every tab has equal visual gap).

### 13.6 Buttons
| Variant | border | body | label |
|---|---|---|---|
| Secondary (default) | `#45475A` r9 | `#313244` r8 | Bold 11 `#CDD6F4` |
| Primary | none — single rect `#89B4FA` r9 (no border pair) | – | Bold 11 `#11111B` |
| Selected (toggle on) | `#89B4FA` r9 | `#3E455F` r8 | Bold 11 `#89B4FA` |
| Unselected (toggle off) | `#585B70` r9 | `#45475A` r8 | Regular 11 `#CDD6F4` |
Height 36; width = label width + ~28–36 px padding; label vertically centred (y = top + 10.5 for 36 tall, i.e. top + (36-13)/2).
Names: `Button border: <Label>`, `Button: <Label>`, `Label: <Label>`.

### 13.7 Input / search
`Search border` 260×36 `#45475A` r8, `Search field` 258×34 `#313244` r7 @+1; placeholder Regular 11 `#9399B2`; typed text Regular 12 `#CBD3F1`. Filter field identical (`Filter border/field/placeholder`).

### 13.8 Sidebar (drawer) — frame `04 Sidebar menu` (appended after the full home screen)
```
Scrim            0,0 1920×1023 #000000 opacity 0.5
Sidebar          0,0 312×1023 #181825 ; Sidebar border 311,0 1×1023 #313244
Title/subtitle   (24,23.5) Bold 16 #89B4FA / (24,56) Regular 10 #A2A9C4 ; Close × Regular 20 #A6ADC8 @ (270.4,20)
Divider          (14,78) 284×1 #313244
Section label    "BROWSE" Bold 9, letter-spacing 10 %, #9399B2 @ (14,93.5)
Active item      (14,118) 284×46 #292F45 r10 ; Active indicator (14,126) 3×30 #89B4FA r1.5 ; icon 20×20 @ (30,131) ; label Bold 12 #89B4FA @ (62,133.5) ; chevron › 16 #9399B2 @ (279.9,133.5)
Other items      pitch 50: icon @ (30, 181/231/281), label Regular 12 #CDD6F4 @ (62, +2.5 from icon y)
Bottom divider   (14,928) ; Settings item icon @ (30,946) label @ (62,948.5) ; version text Regular 9 #9399B2 @ (centre, 990.5)
```

### 13.9 Dialog (modal)
```
Scrim            full screen #000000 @0.5
Dialog border    (600,303) 720×416 #313244 r16 ; Dialog (601,304) 718×414 #181825 r15   → centred: (1920-720)/2=600, (1023-416)/2≈303.5
Accent line      (612,303) 696×2 #F9E2AF r1  (colour = severity: yellow warning)
Title            Bold 19 #CDD6F4 @ (622, 336.5) ; Close × Regular 18 #A6ADC8 @ (right-37, 335)
Body             Regular 11.5 #CDD6F4, one text node per line, lines 24 px apart from y=379
Option row       border (622,y) 676×65 #45475A r12 | body (623,y+1) 674×63 #313244 r11 ; row pitch 76
   icon tile     (638, y) 34×34 r9 tinted colour (green #465255 / yellow #555257 / blue #414965) ; glyph Bold 16 in the status colour ; or checkbox
   title         Bold 12 #CDD6F4 @ (684, y+11.5) ; description Regular 10 #9399B2 @ (684, y+41)
   chevron       › Regular 14 #9399B2 @ (1275, y+24.5)
Footer buttons   Cancel 68×36 secondary @ (1233,666) …
```

### 13.10 Settings card (frame `05 Settings`)
Cards 800×99 (one help line) / 123 (two lines) centred at x=560; pitch 66 between 99‑tall cards (223 → 389 → 579 → 745 incl. taller ones). Title Medium 14 @ (580, y+27.5); help Regular 11 `#9399B2` @ (580, y+59.5); control right‑aligned, buttons ending at x=1340 (right padding 20): segmented controls = 2 buttons 110×36 with 12 px gap (x=1108 and 1230).

### 13.11 Update row (list)
Row rect 1872×44 `#313244` r10 @ (24, 77+52k). Package name Bold 12 @ (40, y+14.5) `#CDD6F4`; right cluster (right‑aligned to x=1884): installed version Regular 10.5 `#A6ADC8`, arrow `→` Regular 11 `#A6ADC8` (fixed x ≈ 1814.75), new version Bold 10.5 `#A6E3A1`.

### 13.12 Category row
Icon 38×38 @ (38, y) ; name Bold 12 @ (90, y+0.5) ; count Regular 9.5 `#A5ACC7` @ (90, y+29.5) e.g. `"199 packages · 7 installed"` ; chevron › 16 `#9399B2` @ (1873.9, y+11.5) ; row pitch 68. Row background is a `#313244`/`#45475A` pair spanning ~1872.

### 13.13 Search results + detail pane (screen 14 / 14b)
Left: list rows (icon 64 @ x=48, name Bold 15 @132, source Regular 12 `#A6ACC7`, buttons to the right); right: **detail pane** border (948,140) 948×859 `#313244` r24, body (949,141) 946×857 `#171725` r23. Empty state: circle 128 r64 `#313244`, “magnifier” made of two nested rounded rects + circle (`#89B4FA`/`#313244`), text Regular 18 `#CCD5F4` centred: "Select a package to view its details". Selected row uses border `#89B4FA`, per‑corner radii `[16,0,0,16]` + the 20×20 rotated **vector** connectors at the row/pane junction (fill `#1E1E2E`).
"Did you mean:" prefix Regular 14 `#A6ACC7` + term Bold 14 `#89B4FA`.

### 13.14 Package details (screens 15/16)
Back/Forward on header right; title text boxes use `auto_resize:"none"` with fixed width (191×42 etc.); stat blocks: label ("Version") 9 px `none` + value Bold; Install box with label/notes (`"Will be installed from chaotic-aur. 0 B to download."`); "About this package" heading; screenshots 2 × (399|446)×272 rounded 12.

---

## 14. Naming conventions (semantic names — keep them)

Layer names are meaningful and consistent; an AI reading the file should use them to understand structure, and an AI writing the file should reproduce them.

| Pattern | Meaning |
|---|---|
| `NN Title`, `NN Title - variant` | top-level screens/states |
| `Content (scrolls)` | the scrolling viewport frame of a screen |
| `Row: <Section>` | horizontal card strip frame |
| `Card border: <X>` / `Card: <X>` / `Icon: <X>` | the 3 layers of a card |
| `Button border: <L>` / `Button: <L>` / `Label: <L>` | button layers |
| `Tab (active): <L>` / `Tab: <L>` / `Active tab` | tabs |
| `Section title: <S>` | heading above a row |
| `Name`, `Source / version`, `Status`, `Count`, `Chevron`, `Divider`, `Scrim` | generic repeated names (same name appears many times; ids differ) |
| `Scrollbar track / Scrollbar thumb / Scrollbar thumb (vertical)` | scroll indicators |
| `Header`, `Header border`, `App title`, `App subtitle`, `Menu line 1..3`, `Home button(+border)`, `Home icon`, `Search border/field/placeholder`, `Tab bar(+border)` | the global header, **duplicated verbatim into every screen** |
| `Icon: <App>`, `Icon glyph`, `Category icon: <C>`, `Section icon` | images/glyphs |
| `Dialog`, `Dialog border`, `Dialog accent`, `Dialog title`, `Dialog text N`, `Option border/…`, `Option icon tile`, `Option glyph`, `Option title`, `Option text` | modal parts |
| `Sidebar`, `Sidebar border`, `Sidebar title`, `Item: <X>`, `Active item`, `Active indicator`, `Section label` | drawer parts |

---

## 15. What is NOT in the sample (do not assume)

The following are **[UNOBSERVED]**; this file contains no examples, so emitting them is a guess that may break the app:
- strokes/borders as properties, effects (shadow/blur), gradient fills, auto‑layout (`layout`/`padding`/`gap` on frames — `child_layout` is only on text and with `absolute:false`/all‑null grid values), constraints, groups, components/instances/variants, ellipse/line/polygon/star/boolean node types, text ranges/mixed styles, `styles`/`variables`/`document_colors` entries, `comments`, prototype `flows`, multiple pages, `blend` values other than `"normal"`, non-zero `corners.smoothing`, `scale_mode` other than `"fill"`, `crop`, non-zero image filters, `decoration` ≠ `none`, `case` ≠ `original`, `line_height` other than `auto`, `letter_spacing` unit other than `percent`, `text` `auto_resize` values other than `height`/`none`, rotations other than 0°/180°, skew/scale in `transform`.

**Policy:** when the user asks for something outside the observed set, (1) say it is not verified in this format, (2) achieve the look with the observed idioms (§9), and (3) only if essential, add the unobserved property in a clearly isolated way and tell the user to test-open the file.

---

## 16. Workflows

### 16.1 Explain / analyse an existing file
1. `unzip` → load `document.json`.
2. Print `name`, `len(nodes)`, node-type counts, top-level frames (`name`, size, transform → canvas position).
3. For each screen, list **named** layers (names are semantic) with positions. Use the renderer (§18) to get a PNG and *look at it*.
4. Summarise: screens, components (via name patterns §14), palette (colour histogram), type scale, spacing.

### 16.2 Create a new figcraft from a brief
1. Pick the screen list and name them `NN Title`. Plan the canvas grid (§10).
2. Define tokens first (palette/type/radius) — copy §12 or derive a coherent set; never improvise hex values per node.
3. Create a **build function per component** (header, card, button, input, dialog…) that emits the border/body/label layers with the semantic names (§13, §14), then compose screens.
4. Create PNG assets (icons, gradients, screenshots) with PIL; register them (§8).
5. Measure text (PIL+Inter if available; otherwise §7.4) so centring is correct.
6. Save (§2), validate (§18), render the frames and **look** at them; fix overflow/overlap; regenerate the thumbnail.
7. Deliver the `.figcraft` file (and mention what was and wasn't verified).

### 16.3 Edit an existing file (safe protocol)
1. Work on `document.json` as a dict; never renumber existing ids.
2. **Text edit:** change `characters`; recompute `width` (and re-centre `tx` if it was centred).
3. **Recolour:** change `fills[0].color` (a token swap means replacing *every* node using the old hex — do a histogram first; also recolour the screen frame fills and `page.background`).
4. **Add node:** `id = next_id; next_id += 1`; set `parent`; append `id` to parent's `children` (position = z‑order); fill all required fields for that node type (copy a sibling and modify).
5. **Delete node:** remove from parent's `children`, delete recursively all descendants from `nodes`. Don't leave dangling ids.
6. **Duplicate a screen:** deep-copy the frame and *all descendants* with fresh ids (map old→new, rewrite `parent` and `children`), set new `name` and `transform` (+2120 x or new row +1223 y), append the new frame id to `page.children`.
7. **Replace an image:** add the new PNG (new hash) and point the fill's `image` to it; delete the old `images/<hash>` + `imageIndex` entry only if no other fill uses it.
8. Always re-validate. Keep the old `thumbnail.png` if you only did small edits.

### 16.4 Convert text → proper layout
Because there is no auto‑layout, **you compute the layout**: write helper functions that take a container box and return child coordinates (center, stack with gap, right-align, grid with pitch). Emit absolute `transform`s.

---

## 17. Pitfalls checklist

- ❌ Putting colour in `style.fills` → text is invisible/black. ✔ Put it in `node.fills`.
- ❌ Forgetting `child_layout` on text (breaks the editor). ✔ Copy it verbatim; omit only for `auto_resize:"none"` nodes as the sample does.
- ❌ `nodes` keys as ints → must be **strings** in JSON.
- ❌ `parent`/`children` out of sync; dangling child ids; id ≥ `next_id`.
- ❌ Absolute coordinates for children of frames → they're **relative** to the parent.
- ❌ Reversing z-order (borders painted over fills). ✔ border rect before body rect.
- ❌ Image fill hash not in `imageIndex`, or `images/<hash>` missing, or hash ≠ sha256(bytes).
- ❌ Adding `.png` extension to files in `images/`.
- ❌ Zip with a top-level folder.
- ❌ Multi-line text in one node. ✔ One node per line.
- ❌ Using `color.a<1` for dimming. ✔ `fills[0].opacity`.
- ❌ Inventing fonts/weights. ✔ Inter Regular/Medium/Bold only.
- ❌ Making cards without the inner 1‑px inset or without radius−1 on the inner rect (visible fringe).
- ❌ Forgetting to duplicate the global header into every screen (it's not a shared component here).
- ❌ Changing a token in one place only (e.g. `#89B4FA` appears on 41 nodes + borders) — do a histogram sweep.

---

## 18. Tools: full Python helper library (tested)

Save as `figcraft_lib.py`. Requires `pillow`. Provides: colour helpers, a `Doc` builder (frames, rectangles, text, border pairs, image registration, save), `validate()` (structural checks incl. SHA‑256 verification), and `render()` (approximate PIL renderer used to verify understanding — it honours relative transforms, paint order, clipping, radii, image fills and 180° rotations; fonts fall back to DejaVu so text widths differ slightly from Inter).

```python
"""figcraft_lib.py - read / build / validate / render .figcraft files (reverse-engineered, format v1)."""
import json, zipfile, hashlib, io, os, copy

# ---------- colour helpers ----------
def rgba(hexstr, a=1.0):
    h = hexstr.lstrip('#')
    return {"r": round(int(h[0:2],16)/255,4), "g": round(int(h[2:4],16)/255,4), "b": round(int(h[4:6],16)/255,4), "a": a}
def to_hex(c): return '#%02X%02X%02X' % tuple(round(c[k]*255) for k in 'rgb')

def solid(hexstr, opacity=1.0):
    return {"type":"solid","color":rgba(hexstr),"opacity":opacity,"visible":True,"blend":"normal"}
def image_fill(img_hash):
    return {"type":"image","image":img_hash,"scale_mode":"fill","scale":1.0,"rotation":0,"crop":None,
            "filters":{"exposure":0.0,"contrast":0.0,"saturation":0.0,"temperature":0.0,"tint":0.0,"highlights":0.0,"shadows":0.0},
            "opacity":1.0,"visible":True,"blend":"normal"}
def corners(r):
    rr = list(r) if isinstance(r,(list,tuple)) else [r]*4
    return {"radii":[float(x) for x in rr],"smoothing":0.0}
def xf(x=0.0,y=0.0): return [1.0,0.0,0.0,1.0,float(x),float(y)]

# ---------- document ----------
class Doc:
    def __init__(self, name="Untitled", bg="#1E1E1E"):
        self.name=name; self.nodes={}; self.next_id=2; self.images={}   # hash -> (bytes,w,h)
        self.page=self._new({"name":"Page 1","type":"page","background":rgba(bg),"flows":[],
            "prototype":{"device":"None","background":rgba(bg),"rotation":"portrait"},"children":[],"width":0.0,"height":0.0})
    def _new(self, d):
        i=self.next_id; self.next_id+=1; d={"id":i,**d}; self.nodes[i]=d; return i
    def add_image(self, png_bytes):
        from PIL import Image
        h=hashlib.sha256(png_bytes).hexdigest(); im=Image.open(io.BytesIO(png_bytes))
        self.images[h]=(png_bytes,im.width,im.height); return h
    def _attach(self,parent,i):
        self.nodes[i]["parent"]=parent; self.nodes[parent]["children"].append(i)
    def frame(self,parent,name,x,y,w,h,fill=None,radius=None,clip=True):
        d={"name":name,"type":"frame","children":[],"width":float(w),"height":float(h)}
        if fill: d["fills"]=[solid(fill)]
        if radius is not None: d["corners"]=corners(radius)
        d["clip"]=clip
        if (x,y)!=(0,0) or parent!=self.page: d["transform"]=xf(x,y)
        i=self._new(d); self._attach(parent,i); return i
    def rect(self,parent,name,x,y,w,h,fill=None,radius=None,img=None,opacity=1.0):
        d={"name":name,"type":"rectangle","blend":"normal","width":float(w),"height":float(h),
           "fills":[image_fill(img) if img else solid(fill,opacity)]}
        if (x,y)!=(0,0): d["transform"]=xf(x,y)
        if radius is not None: d["corners"]=corners(radius)
        i=self._new(d); self._attach(parent,i); return i
    def text(self,parent,name,s,x,y,size,style="Regular",fill="#CDD6F4",w=None,font="Inter",letter_spacing=0.0):
        lh=round(size*1.21); w=w if w is not None else round(len(s)*size*(0.544 if style=="Bold" else 0.487),2)
        d={"name":name,"type":"text","characters":s,
           "style":{"font_family":font,"font_style":style,"font_size":float(size),"line_height":{"unit":"auto"},
                    "letter_spacing":{"unit":"percent","value":float(letter_spacing)},"decoration":"none","case":"original","fills":None,"link":None},
           "auto_resize":"height","blend":"normal","transform":xf(x,y),"width":float(w),"height":float(lh),"fills":[solid(fill)],
           "child_layout":{"sizing_h":"fixed","sizing_v":"hug","absolute":False,"min_w":None,"max_w":None,"min_h":None,"max_h":None,
                           "grid_column":None,"grid_row":None,"grid_column_span":0,"grid_row_span":0}}
        i=self._new(d); self._attach(parent,i); return i
    # ---- compound components (the "two-rectangles border" idiom) ----
    def bordered(self,parent,name,x,y,w,h,fill,border,radius,bw=1):
        b=self.rect(parent,f"{name} border",x,y,w,h,border,radius)
        i=self.rect(parent,name,x+bw,y+bw,w-2*bw,h-2*bw,fill,max(radius-bw,0)); return b,i
    def save(self,path):
        out={"format":"figcraft","version":1,
             "imageIndex":[{"hash":h,"width":w,"height":hh} for h,(b,w,hh) in sorted(self.images.items())],
             "name":self.name,"pages":[self.page],
             "nodes":{str(k):v for k,v in self.nodes.items()},
             "next_id":self.next_id,"styles":[],"variables":{"collections":[],"variables":[]},
             "current_page":self.page,"document_colors":[],"comments":[]}
        # page node: serialise key order like the original (id first)
        with zipfile.ZipFile(path,"w",zipfile.ZIP_DEFLATED) as z:
            z.writestr("document.json",json.dumps(out,ensure_ascii=False))
            for h,(b,_,_) in self.images.items(): z.writestr(f"images/{h}",b)
            z.writestr("thumbnail.png", self._thumb())
    def _thumb(self):
        from PIL import Image
        buf=io.BytesIO(); Image.new("RGBA",(400,286),(30,30,30,255)).save(buf,"PNG"); return buf.getvalue()

# ---------- validate ----------
def validate(path):
    errs=[]; z=zipfile.ZipFile(path); d=json.loads(z.read("document.json"))
    if d.get("format")!="figcraft": errs.append("format != figcraft")
    N=d["nodes"]; names=set(z.namelist())
    for h in [i["hash"] for i in d["imageIndex"]]:
        if f"images/{h}" not in names: errs.append(f"missing image file {h}")
        elif hashlib.sha256(z.read(f"images/{h}")).hexdigest()!=h: errs.append(f"hash mismatch {h}")
    idx={i["hash"] for i in d["imageIndex"]}
    for k,n in N.items():
        if str(n["id"])!=k: errs.append(f"id/key mismatch {k}")
        if int(k)>=d["next_id"]: errs.append(f"id {k} >= next_id")
        for c in n.get("children",[]):
            if str(c) not in N: errs.append(f"{k}: dangling child {c}")
            elif N[str(c)].get("parent")!=n["id"]: errs.append(f"{c}: parent mismatch")
        if n["type"]!="page" and "parent" not in n: errs.append(f"{k}: no parent")
        for f in n.get("fills") or []:
            if f["type"]=="image" and f["image"] not in idx: errs.append(f"{k}: image fill not in imageIndex")
        if n["type"]=="text" and "style" not in n: errs.append(f"{k}: text without style")
    for p in d["pages"]:
        if str(p) not in N: errs.append(f"page {p} missing")
    if d["current_page"] not in d["pages"]: errs.append("current_page not in pages")
    return errs

# ---------- render (PIL, approximate) ----------
def render(path, frame_id, out_png, scale=0.5, font_dir=None):
    from PIL import Image, ImageDraw, ImageFont
    z=zipfile.ZipFile(path); d=json.loads(z.read("document.json")); N=d["nodes"]
    imgs={}
    def getimg(h):
        if h not in imgs: imgs[h]=Image.open(io.BytesIO(z.read(f"images/{h}"))).convert("RGBA")
        return imgs[h]
    def font(style,size):
        cands={"Bold":["DejaVuSans-Bold.ttf","Inter-Bold.ttf"],"Medium":["DejaVuSans.ttf"],"Regular":["DejaVuSans.ttf","Inter-Regular.ttf"]}[style]
        for c in cands:
            for base in ["/usr/share/fonts/truetype/dejavu/","/usr/share/fonts/truetype/"]:
                try: return ImageFont.truetype(base+c,max(int(size*scale*0.9),1))
                except Exception: pass
        return ImageFont.load_default()
    root=N[str(frame_id)]; W,H=int(root["width"]*scale),int(root["height"]*scale)
    canvas=Image.new("RGBA",(W,H),(0,0,0,0))
    def paint(n,ox,oy,clip_box,target):
        t=n.get("transform") or [1,0,0,1,0,0]; x=ox+t[4]; y=oy+t[5]
        if t[0]<0: x=ox+t[4]-n["width"]; y=oy+t[5]-n["height"]   # 180deg rotation: origin is bottom-right
        w,h=n["width"],n["height"]; box=[int(x*scale),int(y*scale),int((x+w)*scale),int((y+h)*scale)]
        fills=[f for f in (n.get("fills") or []) if f.get("visible",True)]
        r=(n.get("corners") or {}).get("radii",[0])[0]
        layer=Image.new("RGBA",target.size,(0,0,0,0)); dr=ImageDraw.Draw(layer)
        if n["type"] in("rectangle","frame","vector") and fills:
            f=fills[0]
            if f["type"]=="solid":
                c=f["color"]; col=(round(c["r"]*255),round(c["g"]*255),round(c["b"]*255),int(255*c["a"]*f["opacity"]))
                if r>0: dr.rounded_rectangle(box,radius=int(r*scale),fill=col)
                else: dr.rectangle(box,fill=col)
            else:
                im=getimg(f["image"]).resize((max(box[2]-box[0],1),max(box[3]-box[1],1)))
                m=Image.new("L",im.size,0); ImageDraw.Draw(m).rounded_rectangle([0,0,im.width-1,im.height-1],radius=int(r*scale),fill=255)
                a=im.split()[3]; from PIL import ImageChops
                m=ImageChops.multiply(m,a); layer.paste(im,(box[0],box[1]),m)
        elif n["type"]=="text":
            c=fills[0]["color"]; col=(round(c["r"]*255),round(c["g"]*255),round(c["b"]*255),255)
            dr.text((box[0],box[1]),n["characters"],font=font(n["style"]["font_style"],n["style"]["font_size"]),fill=col)
        if clip_box:   # clip to parent frame
            mask=Image.new("L",target.size,0); ImageDraw.Draw(mask).rectangle(clip_box,fill=255)
            from PIL import ImageChops
            layer.putalpha(ImageChops.multiply(layer.split()[3],mask))
        target.alpha_composite(layer)
        if n["type"]=="frame":
            cb=box if n.get("clip") else clip_box
            if cb and clip_box: cb=[max(cb[0],clip_box[0]),max(cb[1],clip_box[1]),min(cb[2],clip_box[2]),min(cb[3],clip_box[3])]
            for c in n["children"]: paint(N[str(c)],x,y,cb,target)   # children order = paint order (first = bottom)
    paint(root,-(root.get("transform") or [0]*6)[4],-(root.get("transform") or [0]*6)[5],None,canvas)
    canvas.convert("RGB").save(out_png)

```

### 18.1 Usage examples

```python
import sys; sys.path.insert(0, ".")
import figcraft_lib as L, io
from PIL import Image

# --- validate + render an existing file
print(L.validate("TuxStore.figcraft"))                 # [] means OK
L.render("TuxStore.figcraft", 3, "home.png", scale=0.5)  # 3 = id of "01 Home"

# --- build a new file
doc = L.Doc("My App", bg="#1E1E1E")
buf = io.BytesIO(); Image.new("RGB",(64,64),(137,180,250)).save(buf,"PNG"); icon = doc.add_image(buf.getvalue())

home = doc.frame(doc.page, "01 Home", 0, 0, 1920, 1023, "#1E1E2E", 12)         # first screen at (0,0)
doc.rect(home, "Header", 0, 0, 1920, 62, "#181825")
doc.rect(home, "Header border", 0, 62, 1920, 1, "#313244")
doc.text(home, "App title", "My App", 74, 11.5, 16, "Bold", "#89B4FA")

content = doc.frame(home, "Content (scrolls)", 0, 128, 1920, 895, None, None)  # transparent clip window
row = doc.frame(content, "Row: Demo", 24, 100, 1872, 178, None, None)
for i in range(3):
    x = i * 216                                              # 200 card + 16 gap
    doc.bordered(row, f"Card: App{i}", x, 0, 200, 178, "#313244", "#45475A", 12)  # emits "Card: App0 border" + "Card: App0"
    doc.rect(row, f"Icon: App{i}", x+68, 19, 64, 64, img=icon)
    doc.text(row, "Name", f"App{i}", x+81, 100.5, 12, "Bold")
    doc.text(row, "Status", "Installed", x+79, 153, 10, "Bold", "#A6E3A1")

doc.frame(doc.page, "02 Second", 2120, 0, 1920, 1023, "#1E1E2E", 12)             # next screen: +2120 in x
doc.save("my_app.figcraft")
assert L.validate("my_app.figcraft") == []
L.render("my_app.figcraft", home, "preview.png", 0.5)
```

Naming caveat for `Doc.bordered`: it emits `"<name> border"`; the sample uses `"Card border: X"` + `"Card: X"`. Pass names accordingly or rename afterwards to match §14 exactly (e.g. call `rect` twice yourself).

### 18.2 Quick inspection one-liners

```python
import json, zipfile, collections
d = json.loads(zipfile.ZipFile("f.figcraft").read("document.json")); N = d["nodes"]
print(collections.Counter(n["type"] for n in N.values()))
for c in N[str(d["pages"][0])]["children"]:
    n = N[str(c)]; t = n.get("transform") or [0]*6
    print(c, n["name"], n["width"], n["height"], (t[4], t[5]))
# colour histogram
def hx(c): return "#%02X%02X%02X" % tuple(round(c[k]*255) for k in "rgb")
print(collections.Counter(hx(f["color"]) for n in N.values() for f in (n.get("fills") or []) if f["type"]=="solid").most_common(20))
# find all text
print([n["characters"] for n in N.values() if n["type"]=="text"][:50])
```

### 18.3 Generating gradient / shade PNGs

```python
from PIL import Image
def vgrad(w, h, top, bottom):          # RGBA tuples → PNG bytes (the carousel shade is 8×120, transparent→dark)
    im = Image.new("RGBA", (w, h))
    for y in range(h):
        t = y/(h-1); im.putpixel((0,y), tuple(round(a+(b-a)*t) for a,b in zip(top,bottom)))
    im = im.resize((w,h))
    for x in range(1,w):
        for y in range(h): im.putpixel((x,y), im.getpixel((0,y)))
    b = io.BytesIO(); im.save(b,"PNG"); return b.getvalue()
shade = doc.add_image(vgrad(8,120,(30,30,46,0),(30,30,46,230)))
doc.rect(content, "Carousel shade", 460, 465, 1000, 120, img=shade)
# active-tab pill: horizontal gradient pastel purple (#CBA6F7) → blue (#89B4FA), size = pill size (176×36), used with radius 9
```

---

## 19. Mini glossary (Arabic/English quick notes)

- **frame** إطار/شاشة · **rectangle** مستطيل (يُستخدم لكل شيء غير النص) · **fill** تعبئة · **transform** موضع/تحويل نسبي للأب · **clip** قص المحتوى خارج الإطار · **z-order** ترتيب الطبقات = ترتيب `children` · **scrim** طبقة سوداء شفافة 50% خلف النوافذ · **border pair** مستطيلان فوق بعض لعمل حد 1px · **baked gradient** تدرّج مُحوَّل إلى صورة PNG.

---

## 20. Final self-check before delivering any figcraft file

1. `validate()` returns `[]`.
2. Every screen is 1920×1023 (or the documented size), named `NN Title`, positioned on the 2120×1223 grid, no overlaps.
3. Colours ⊂ the palette (§12) unless the user asked for a new theme; all text is Inter Regular/Medium/Bold at scale sizes.
4. Every card/button/input is a border+body pair with radius−1 inset; labels centred in their boxes.
5. Rendered preview inspected: nothing clipped unintentionally, text not overlapping, hierarchy readable.
6. `thumbnail.png` present (400×286).
7. You told the user which parts are **[UNOBSERVED]** assumptions, if any.
