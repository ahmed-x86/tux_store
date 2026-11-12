# Thumbnails (`tux-thumbnail`)

Files: `crates/tux-thumbnail/src/{lib,resolver,names,themes}.rs`

Resolves one icon file per package name and lists the Home cover images. Designed so that the common case (an icon already on disk) never waits behind a slow network request.

## Messages

Handles `IconRequested`, `CoversRequested`, `ClearIconCache`, `UiReady` (warm-up).
Emits `IconReady{name, path}`, `IconFailed{name}`, `CoversReady`, `IconCacheCleared`.

`IconReady` carries a **file path** (cache file, bundled file or system theme file); the UI loads it. Nothing is copied or re-encoded.

## Two stages

```
IconRequested ──► coalesce (one job per name) ──► stage 1: "thumb-local" (1 thread)
                                                     │ active system theme?   ─► IconReady
                                                     │ bundled icon?          ─► IconReady
                                                     │ hicolor / pixmaps?     ─► IconReady
                                                     │ downloaded (disk cache)? ─► IconReady
                                                     │ fresh negative marker? ─► IconFailed
                                                     └ otherwise ─► stage 2: "thumb-net-0..7"
                                                                      one HTTP request ─► IconReady / IconFailed
```

Stage 1 is a single thread that never touches the network, so local hits are not delayed by a stalled download. Stage 2 is a pool of 8 workers; each download runs the system `curl` (6 s timeout, 2 MiB cap, HTTPS only). No TLS library is linked into the module — statically linked `ring` was what made `libtux_thumbnail.so` fail to load (`undefined symbol: ring_core_…`) in LTO-enabled makepkg builds.

Names failing `is_valid_package_name` are dropped, which also makes path traversal in cache file names impossible.

## Candidate names — `names::candidates(app)`

Ordered and de-duplicated, most likely first:

1. alias of the raw name (`neovim → nvim`, `libreoffice-fresh → libreoffice-main`, `obs-studio → com.obsproject.Studio`, `telegram-desktop → telegram`, …)
2. the raw name
3. the sanitised name (strips `-git -bin -aur -patch -full -stable` repeatedly)
4. alias of the sanitised name
5. progressive dash-prefix truncation (`foo-bar-baz → foo-bar → foo`)
6. manual hints (`yt-dlp → youtube-dl, youtube`, `htop`, `fastfetch`, `kitty`)

Only candidate **[0]** is requested over the network; stage 1 tries every candidate locally.

## Sources, in order

1. **Active system icon theme** — the theme the desktop really uses plus everything it `Inherits=` (see below).
2. **Bundled icons** — `data/images/icons/custom_icons.json` maps a name prefix to a sub-directory (used for the LibreOffice language packs).
3. **Fallback tier** — `hicolor` and `/usr/share/pixmaps`.
4. **Disk cache** — icons downloaded earlier, `~/.cache/tux-store/icons/<name>.svg`. Consulted only when the theme has nothing, so a stale download can never shadow the current theme.
5. **Network** — one request to the Papirus 64×64 SVG on `raw.githubusercontent.com` (via `curl`).

### System theme lookup (`themes.rs`)

The theme name comes from, in order: `$TUX_ICON_THEME`; on KDE `~/.config/kdeglobals` `[Icons] Theme`; otherwise `gsettings org.gnome.desktop.interface icon-theme`, `gtk-4.0/settings.ini`, `gtk-3.0/settings.ini` (`gtk-icon-theme-name`), then `kdeglobals`. The first name that exists under an icon root wins. Its `index.theme` `Inherits=` chain is followed; installed-but-unselected themes are not searched. If nothing can be detected, every installed theme is used (old behaviour).

No Qt, no per-file index: the `…/apps` directories of the chosen themes are collected once (hicolor/Papirus layout `<theme>/<size>/apps` and Breeze layout `<theme>/apps/<size>`), sorted by closeness to 64 px (scalable first). A lookup is a few `stat` calls for `<dir>/<candidate>.svg|png`.

## Validation

`is_valid_image(bytes)` rejects HTML error pages served with status 200: at least 8 bytes; PNG magic is accepted; otherwise the first 512 bytes must not start with `<!doctype`/`<html` and must contain `<svg` or start with `<?xml`.

## Cache behaviour

- Writes go to `<name>.svg.tmp` and are renamed, so a crash never leaves a half-written icon.
- A failure writes `<name>.notfound`; it is trusted for **14 days**, then retried.
- Settings → *Clear cache* sends `ClearIconCache`; the module deletes **everything** inside `~/.cache/tux-store` (guarded: only a directory literally named `tux-store`), forgets the detected icon theme, and answers `IconCacheCleared{removed}`. `tux-search` and `tux-install` also drop their in-memory caches on that message, and the UI reloads the icons on screen.

## Covers

`scan_covers()` lists `data/images/cover/<app>/*.png|jpg|jpeg`, sorted, one `Cover { name, images }` per folder that has images. The UI decodes only the cover currently shown.

## Debugging

`TUX_LOG=debug` prints the detected icon theme and the number of indexed directories; failed cache writes are warnings.

## Remote icon and cover links (0.10.0)

`data/images/remote_images.json` (shipped) and `~/.config/tux-store/remote_images.json` (yours; wins per package):

```json
{ "images": { "gcc": { "icon": "https://raw.githubusercontent.com/devicons/devicon/master/icons/gcc/gcc-original.svg" },
              "alacritty": { "icon": "https://…/Alacritty.svg", "covers": ["https://…/shot.png"] } } }
```

Each entry may also have `"theme": ["icon-name", …]` (looked up in your icon theme) and `"file": "icon.svg"` (only the file name: the picture sits **next to the JSON** that names it, otherwise it is looked up in `data/images/icons/`). Sources are tried theme → file → link.

Order for icons: add-on script declaration → exact bundled icon → your icon theme (exact package name when a link is declared) → files shipped in `data/images/icons` → hicolor/pixmaps → earlier download → **the declared link**. Only `https://` links on trusted hosts are used; PNG, SVG and JPEG are accepted. Covers: a local `data/images/cover/<name>/` folder always wins; remote covers are cached in `~/.cache/tux-store/covers/<name>/`. Wrong or unreachable links are skipped and logged; a link that returns 404 is not retried for 7 days.
