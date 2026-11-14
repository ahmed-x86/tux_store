# Changelog

## 0.15.0

- **Add-on packages in Categories.** An interactive add-on (`data/scripts/*.json`) can now declare `"category": "games"` (AppStream id or title). The add-on then appears in that Categories page with its real title, description, version and installed state — even when `show_on_home` is `false` — and clicking it opens its add-on page. The JSON key is the only metadata needed; unknown categories are logged and leave the add-on available through Home and search. See `DOCS/TAXONOMY.md#add-on-packages-in-categories` and `DOCS/SCRIPTS_SYSTEM.md`.
- **Hiding packages is documented.** New `DOCS/HIDDEN_PACKAGES.md` explains `data/hidden_packages.json` and `~/.config/tux-store/hidden_packages.json`: the format, `hide_in_installed`, exact/case-insensitive matching, every surface that filters the package, and what hiding does not do. Hidden filtering now also covers add-on scripts in search, Home, the Installed tab and category lists.
- **Taxonomy is documented.** New `DOCS/TAXONOMY.md` explains how Repositories, Groups (and group families) and AppStream Categories are discovered, the `group-families.json` keys, the message flow, caching, and `tux-store --dump-taxonomy`. A user copy of `group-families.json` now really overrides the shipped one, as the code comment and docs already said.
- **Documentation index and links.** New `DOCS/README.md`; the documentation list, contributing table and Home-categorization page now point to the taxonomy and hidden-packages pages. The Arabic README and scripts summary mention `category` and hidden packages.

## 0.10.0

- **Remote thumbnails and covers.** `data/images/remote_images.json` (and the user's `~/.config/tux-store/remote_images.json`, which wins) maps a package to an `icon` link and/or up to 3 `covers` links. Only `https://` links on trusted hosts (`raw.githubusercontent.com`, `github.com`, `gitlab.com`, `upload.wikimedia.org`, `flathub.org`, `dl.flathub.org`, `cdn.jsdelivr.net`, `invent.kde.org`, `user-images.githubusercontent.com`) are ever followed; PNG/SVG/JPEG only; everything is downloaded once and cached. An installed theme icon or a local file still wins; a declared link is tried exactly (no shortened-name guesses such as `base-devel` → `base`) and overrides an old "not found" verdict. New module `tux_abi::remote`.
- **Icon sources (Plan B):** an entry can also list `"theme"` (icon names looked up in the icon theme you run, e.g. `onlyoffice-desktopeditors`) and `"file"` (just a file name: put the png/svg/jpg **next to `remote_images.json`**, or in `data/images/icons/`; the user's own JSON looks beside itself in `~/.config/tux-store/`). Order: theme names → file → `icon` link as the last resort. So a broken or blocked link no longer matters when your theme already has the icon.
- Remote icons now declared for `onlyoffice-bin`, `wps-office`, `alacritty`, `calligra`, `epiphany`, `gcc`, `base-devel`, `nodejs`, `docker`, `android-tools`, `bun`, `clang`, `dkms`, `checksec`, `dolphin`, `grub`, and a remote Home cover for `alacritty`. Every link was fetched and its content checked (a Papirus *symlink* answers HTTP 200 with a 10-byte text, which the first version of this list missed for `onlyoffice-bin` and `calligra`; both now point at the real files).
- Home covers: local covers are shown immediately; remote ones are downloaded in the background and added without changing the cover you are looking at (`tux-thumbnail/src/covers.rs`).
- Icon downloads and caches accept JPEG as well as PNG/SVG.
- **Screenshots for add-on scripts.** A script may declare `"screenshots"` as file **names** (found next to the JSON, then in `screenshots/<script-id>/`), `url` links (trusted hosts) or one `flathub` app id; max 12, order kept. The Screenshots slider and full-window viewer now also appear on script pages. The classic `data/screenshots/<script-id>/` folder works for scripts too. `--check-script` reports missing screenshot files. Format version stays 2; older stores reject the new key (unknown keys are errors).
- **Eight new add-on scripts:** Developer toolchain, Fonts pack, Gaming setup (Steam, GameMode, MangoHud), Flatpak and Flathub, Docker, AUR helper (yay), Faster mirrors (reflector), System cleanup. Each has an SVG icon, and all but System cleanup (a one-shot tool) support uninstall.

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
