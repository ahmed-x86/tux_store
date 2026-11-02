# Addons & Language Packs

Files: `data/special_case_packages/*.json`, `crates/tux-search/src/catalog.rs`

Some applications have an ecosystem of official add-ons or language packs (LibreOffice, aspell, …). Instead of hard-coding those relationships, Tux Store reads one JSON file per parent package.

## File format

```json
{
  "package": "libreoffice-fresh",
  "language_packs": { "Arabic": "libreoffice-fresh-ar", "French": "libreoffice-fresh-fr" }
}
```

The map may be called `language_packs` or `addons`; the UI section title becomes **Language Packs** or **Addons** accordingly. When both exist, `language_packs` wins. If `package` is missing, the file name is used.

## Loading (`Catalog::load`)

At module start, `tux-search` reads every `*.json` in the folder (sorted by file name) and builds:
- `specials: parent → { kind, items }` (items sorted by label)
- `addon_of: addon package → parent` — the reverse lookup

Invalid files are logged as warnings and skipped. Missing data never stops start-up.

## Flow

1. `DetailsRequested{name}` → search answers `DetailsReady{ …, special }`, where `special = Catalog::special_for(name)`.
2. **Viewing a parent:** `special.items` fills the add-on card (first 6 shown, *View more* opens the store view).
3. **Viewing an add-on:** `special.addon_for` produces the banner "This package is an addon for *parent*", which links back.
4. Clicking any add-on/parent link publishes `ExactRequested{name}`; search answers `ExactReady{package}` and the UI opens that page — exactly the path used by `tux-store openpackage <name>`.
5. *View more* switches to the add-ons view and publishes `AddonsRequested{package}`; search answers `AddonsReady` using **one `pacman -Si`** for the whole list (so every add-on gets its real repo, version and description).

Icons for add-ons are requested like any other (names such as `libreoffice-fresh-ar` are bundled under `data/images/icons/libreoffice-fresh/`).
