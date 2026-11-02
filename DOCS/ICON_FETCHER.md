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
                                                     │ disk cache hit?        ─► IconReady
                                                     │ bundled icon?          ─► IconReady
                                                     │ system theme icon?     ─► IconReady
                                                     │ fresh negative marker? ─► IconFailed
                                                     └ otherwise ─► stage 2: "thumb-net-0..7"
                                                                      one HTTP request ─► IconReady / IconFailed
```

Stage 1 is a single thread that never touches the network, so local hits are not delayed by a stalled download. Stage 2 is a pool of 8 workers sharing one `ureq::Agent` (keep-alive, 6 s timeout, 2 MiB cap).

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

1. **Disk cache** — `~/.cache/tux-store/icons/<name>.svg|png`, keyed by the original package name.
2. **Bundled icons** — `data/images/icons/custom_icons.json` maps a name prefix to a sub-directory (used for the LibreOffice language packs).
3. **System icon theme** — see below.
4. **Network** — one request to the Papirus 64×64 SVG on `raw.githubusercontent.com`.

### System theme lookup (`themes.rs`)

No Qt, no per-file index. On warm-up it collects the `…/apps` directories of every theme under `~/.local/share/icons`, `~/.icons` and `$XDG_DATA_DIRS/icons` (hicolor/Papirus layout `<theme>/<size>/apps` and Breeze layout `<theme>/apps/<size>`), sorted by closeness to 64 px (scalable first), plus `/usr/share/pixmaps`. A lookup is then a few `stat` calls for `<dir>/<candidate>.svg|png`.

## Validation

`is_valid_image(bytes)` rejects HTML error pages served with status 200: at least 8 bytes; PNG magic is accepted; otherwise the first 512 bytes must not start with `<!doctype`/`<html` and must contain `<svg` or start with `<?xml`.

## Cache behaviour

- Writes go to `<name>.svg.tmp` and are renamed, so a crash never leaves a half-written icon.
- A failure writes `<name>.notfound`; it is trusted for **14 days**, then retried.
- Settings → *Clear cache* sends `ClearIconCache`; the module removes every `svg/png/notfound/tmp` file and answers `IconCacheCleared{removed}`.

## Covers

`scan_covers()` lists `data/images/cover/<app>/*.png|jpg|jpeg`, sorted, one `Cover { name, images }` per folder that has images. The UI decodes only the cover currently shown.

## Debugging

`TUX_LOG=debug` prints the number of indexed theme directories; failed cache writes are warnings.
