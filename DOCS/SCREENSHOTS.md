# Screenshots (since 0.9.0)

Files: `data/screenshots/`, `crates/tux-thumbnail/src/screenshots.rs`, `ScreenshotGallery` in `crates/tux-ui/ui/components.slint`, `tools/fetch_screenshots.py`

A package's page shows a **Screenshots** slider between the “What you'll download” card and the Dependencies card. It has two round arrows (like Google Play), a draggable strip and a horizontal slider underneath. The section is hidden when a package has no screenshots.

The pointer becomes a hand over a thumbnail. Clicking it opens a full-window viewer (`ScreenshotViewer`, in `components.slint`): the picture is fitted to the window and never enlarged past 100 % at first.

| Action | How |
|---|---|
| Close | the **⟨ Back** button, a click on the dark area outside the picture, or `Esc` (when zoomed, `Esc` first resets the zoom) |
| Previous / next picture | the round arrows at the far left / right edge, `←` `→`, `A` `D`, or Vim `H` `L` |
| Zoom | mouse wheel (around the pointer), the `−` / `+` buttons, or the keys `-` `+` `0` (reset); up to 5× |
| Move a zoomed picture | drag it, or use the arrows / `WASD` / `HJKL` |

While zoomed, going to another picture is disabled (the arrows disappear and the keys move the picture instead). Clicking the picture itself does nothing.

## Folder layout

```
data/screenshots/
└── <package-name>/              exactly the pacman package name
    ├── <package-name>.json      manifest (always)
    ├── <package-name>-1.png     numbered pictures (optional)
    ├── <package-name>-2.png
    └── …
```

Pictures are numbered from 1 with no zero padding (`brave-browser-1.png … brave-browser-10.png`), `.png`, `.jpg` or `.jpeg`. They are sorted numerically (2 before 10).

A user can add or override packages in `~/.config/tux-store/screenshots/<package>/…` (same layout); it is searched first.

## The manifest

```json
{ "package": "firefox", "flathub": "https://flathub.org/en/apps/org.mozilla.firefox", "count": 8 }
```

| Key | Meaning |
|---|---|
| `package` | the package name; must equal the folder name or the file is ignored |
| `flathub` | optional: a Flathub app id (`org.mozilla.firefox`) **or** its `flathub.org` link |
| `count` | optional: how many pictures to take from Flathub (1–12, default 8) |

## Two ways to provide pictures

1. **Pictures next to the JSON.** If `<package>-N.png` files exist they are used and the network is never touched.
2. **A Flathub link in the JSON, no pictures.** On first view the store downloads the screenshots, names them `<package>-1.png`, `<package>-2.png`, … and keeps them in `~/.cache/tux-store/screenshots/<package>/`. Later views are instant and offline. *Clear cache* in Settings removes them (they come back on the next view). The pictures appear one by one while downloading.

To turn mode 2 into mode 1 permanently (ship the pictures with the store), run on a machine with internet:

```bash
python3 tools/fetch_screenshots.py            # every folder with a "flathub" key and no pictures
python3 tools/fetch_screenshots.py firefox    # just one
python3 tools/fetch_screenshots.py --force    # download again
```

## Run-time behaviour

```
UI opens a package page ─ ScreenshotsRequested{name} ─► thumbnail module (thread "thumb-shots")
   local pictures?  ─► ScreenshotsReady{name, images}
   cache complete?  ─► ScreenshotsReady
   else Flathub     ─► GET https://flathub.org/api/v2/appstream/<id>
                       choose the widest size ≤ 1600 px per screenshot
                       download each (curl, 20 s, 8 MiB cap) ─► ScreenshotsReady after every picture
```

- Only `https://` links on `flathub.org` hosts are followed; names and ids are allow-listed.
- Only real PNG/JPEG data (checked by magic bytes) is saved; the extension is the real one.
- “Flathub has nothing” is remembered for 7 days (`.none` marker). A network failure is not remembered.
- `ScreenshotsReady` always carries the **complete list so far**; the UI replaces its model. Answers for a package the user already left are dropped.
- Scripts (add-on packages) have no screenshots section.

## Prefetch (0.9.1)

A few seconds after the Home shelves load, the UI sends `ScreenshotsPrefetch{names}` (the first 3 apps of the first 4 shelves, add-on scripts excluded). The thumbnail module waits 4 s, then downloads — one package at a time, 1.5 s apart, at most 8 packages — the screenshots of those with a `flathub` key that are not cached yet. Nothing is published; if you open a page while its download is running, the page follows the cache folder and shows the pictures as they arrive. Each package is tried once per run. `TUX_NO_PREFETCH=1` disables it.

## Adding a package

1. `mkdir data/screenshots/<package>`
2. Create `<package>.json` with `"package"` and, for Flathub mode, `"flathub"` (find the id in the app's flathub.org URL).
3. Or drop `<package>-1.png`… next to it.
4. Rebuild is **not** needed for data; `make install` copies `data/` to `/usr/share/tux-store/`.

Shipped examples: ~26 packages in Flathub mode (all browsers of the Home page and more), plus `fastfetch`, `htop`, `neovim` with local placeholder pictures that show the slider offline. Replace the placeholders with real screenshots (same names) or run the fetch tool after switching their JSON to a `flathub` key.
