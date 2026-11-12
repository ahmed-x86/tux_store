# Package / Data Model

Files: `crates/tux-abi/src/message.rs`, `crates/tux-abi/src/text.rs`

Pure data and pure helpers — no I/O, shared by every module.

## Structs

### `Package`
```rust
pub struct Package {
    pub name: String,         // pacman name, e.g. "libreoffice-fresh"
    pub repo: String,         // "extra", "core", … or "aur" when pacman does not know it
    pub version: String,
    pub description: String,
    pub installed: bool,
}
```
`repo = "aur"` is also used for packages that are installed but absent from the sync databases, and as the stub for curated entries pacman cannot find.

### `Dependency`
`{ name, size_bytes, installed }` — one row of the dependency list.

### `PackageDetails`
The transaction plan as pacman's own resolver reports it.

| Field | Meaning |
|---|---|
| `app_size` | installed size of the package itself |
| `installed_deps` | planned dependencies that are already on disk |
| `new_deps` | planned dependencies that still have to be installed |
| `total_download` | download size of everything not yet installed |
| `total_installed` | installed size of the whole plan |
| `net_upgrade` | installed size of what is **not** already installed (0 when only a reinstall) |
| `dependencies` | installed ones first, then new ones |
| `plan_ok` | `false` when pacman produced no plan (AUR / foreign package) |

`total_footprint()` = `app_size + installed_deps + new_deps`; the UI derives the three bar proportions from it.

### Others
`Addon { label, package }`, `SpecialCase { kind, items, addon_for }`, `Section { id, title, packages }`, `Cover { name, images }`, `UpdateEntry { name, old_version, new_version }`.

### `RemoveMode` and `Operation`
```rust
enum RemoveMode { Basic, Reset, Clean, Force, Complete }   // -R -Rn -Rs -Rdd -Rns
enum Operation  { Install{name}, Remove{name, mode}, SystemUpgrade }
```
A typed `RemoveMode` replaces the raw flag string the C++ version passed around, so the backend never forwards arbitrary arguments to a privileged command.

## Helpers (`text.rs`)

- `format_size(bytes)` → `"512 B"`, `"3.42 KiB"`, `"128.00 MiB"`, `"1.20 GiB"`.
- `prettify_name("telegram-desktop")` → `"Telegram Desktop"` (naive per-segment capitalisation; no acronym table).
- `is_valid_package_name(name)` — allow-list: non-empty, ≤ 128 bytes, ASCII alphanumerics and `@ . _ + -`, must not start with `-` or `.`. Used before a name reaches a command line or a cache file name.
- `strip_ansi(text)` — removes `ESC [ … final-byte` sequences.

Sanitising AUR-style suffixes (`-git`, `-bin`, …) lives in `tux-thumbnail/src/names.rs`, because only icon guessing needs it.
