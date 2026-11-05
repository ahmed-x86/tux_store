# Changelog

## 0.9.1

- **Page navigation:** *Back* and *Forward* buttons on package pages (and a ⟩ button next to Home after going back). Keys: `Esc` / `Backspace` / `Alt+←` back, `Alt+→` forward. See `DOCS/Tab_Navigation.md`.
- **Scrolling:** the Home screen, search results and the Installed list are no longer destroyed when a package page opens, so *Back* returns to the exact scroll position. Package pages open at the top. Vertical scrollbars you can drag (Home and package pages), a round ↑ "to the top" button once you scrolled far, and `PageUp` / `PageDown` / `Space` / `Home` / `End` / `↑` / `↓` on package pages.
- **Screenshot prefetch:** a few seconds after Home loads, the screenshots of the first apps of the first shelves are downloaded quietly (max 8 packages, each cached once; `TUX_NO_PREFETCH=1` turns it off). New message `ScreenshotsPrefetch`.
- **`tux-store --check-script FILE.json`:** validates an add-on script with the store's own loader and explains problems (unreachable steps, missing `mark`/`record`/`uninstall`, missing icon file, administrator commands list). Exit code 0 / 1.
- **New add-on script: “Install multimedia codecs”** (`data/scripts/multimedia-codecs-id-1.json`): Basic set (a52dec faac faad2 flac jasper lame libdca libdv libmad libmpeg2 libtheora libvorbis libxv wavpack x264 xvidcore) or Full (adds ffmpeg + GStreamer plugins). Installs only what is missing and not in the repos is skipped; uninstall removes only what it installed and keeps anything other software needs.
- Fix: Slint binding-loop warning on the tab bar width (caused by keeping the main screen alive).
- PKGBUILD: `!debug`, so makepkg no longer produces the `-debug` package.

## 0.9.0

- **Screenshots slider** on package pages (between “What you'll download” and Dependencies): two round arrows, drag, and a horizontal slider; hand cursor on thumbnails, click opens a full-window viewer: Back / click outside to close, edge arrows and ←→ / AD / HL for previous–next, wheel / buttons / `+ - 0` to zoom (navigation is off while zoomed). Data lives in `data/screenshots/<package>/` — local `<package>-N.png` files or a `flathub` link in `<package>.json` that is downloaded once and cached. See `DOCS/SCREENSHOTS.md`.
- New messages `ScreenshotsRequested` / `ScreenshotsReady` (handled by the thumbnail module).
- New docs: `DOCS/SCRIPTS_SYSTEM.md` (+ Arabic summary) — how to write add-on scripts, install, uninstall and install records.
- `tools/fetch_screenshots.py` to bundle Flathub screenshots offline.
