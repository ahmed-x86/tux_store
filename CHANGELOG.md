# Changelog

## 0.9.0

- **Screenshots slider** on package pages (between “What you'll download” and Dependencies): two round arrows, drag, and a horizontal slider; hand cursor on thumbnails, click opens a full-window viewer: Back / click outside to close, edge arrows and ←→ / AD / HL for previous–next, wheel / buttons / `+ - 0` to zoom (navigation is off while zoomed). Data lives in `data/screenshots/<package>/` — local `<package>-N.png` files or a `flathub` link in `<package>.json` that is downloaded once and cached. See `DOCS/SCREENSHOTS.md`.
- New messages `ScreenshotsRequested` / `ScreenshotsReady` (handled by the thumbnail module).
- New docs: `DOCS/SCRIPTS_SYSTEM.md` (+ Arabic summary) — how to write add-on scripts, install, uninstall and install records.
- `tools/fetch_screenshots.py` to bundle Flathub screenshots offline.
