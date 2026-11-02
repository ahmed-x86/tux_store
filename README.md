# Tux Store — Developer Documentation

In-depth documentation for contributors. If you are new to the codebase, read in this order:

1. **[ARCHITECTURE.md](ARCHITECTURE.md)** — the big picture: host executable + `.so` modules, threading model, the Rust↔Slint boundary.
2. **[MESSAGE_BUS.md](MESSAGE_BUS.md)** — every message modules can send, who sends it, who reacts.
3. **[PACKAGE_MODEL.md](PACKAGE_MODEL.md)** — the shared data types in `tux-abi` and its text helpers.
4. **[PACMAN_MANAGER.md](PACMAN_MANAGER.md)** — `tux-pacman` + `tux-search`: browsing, searching, details, installed and update lists.
5. **[INSTALL_MANAGER.md](INSTALL_MANAGER.md)** — `tux-install`: elevation, streaming, and the weighted progress model.
6. **[ICON_FETCHER.md](ICON_FETCHER.md)** — `tux-thumbnail`: the two-stage icon pipeline and covers.
7. **[UI_LAYER.md](UI_LAYER.md)** — `tux-ui`: Slint components, shared structs, state handling.
8. **[ADDONS_SYSTEM.md](ADDONS_SYSTEM.md)** — JSON-driven add-ons and language packs.
9. **[Home_Page_Categorization.md](Home_Page_Categorization.md)** — data-driven Home sections.
10. **[Tab_Navigation.md](Tab_Navigation.md)** — Home / Updates / Installed tabs.
11. **[Uninstall_Engine.md](Uninstall_Engine.md)** — the five removal modes.
12. **[LOGGING.md](LOGGING.md)** — one log sink for every module.
13. **[CONTRIBUTING.md](CONTRIBUTING.md)** — conventions and good first tasks.
14. **[RELEASING.md](RELEASING.md)** — how the GitHub release workflow builds the tarball and Arch package.

## Module Map

| Crate | Output | Responsibility |
|---|---|---|
| `tux-abi` | rlib | `Message` enum, data types, `Module` trait, C ABI, `export_module!`, paths, text helpers |
| `tux-pacman` | rlib | pacman runner with timeouts, output parsers, local-db reader, queries, progress model |
| `tux-search` | `libtux_search.so` | curated catalog, search, details, exact lookup, add-ons, installed and update lists |
| `tux-thumbnail` | `libtux_thumbnail.so` | icon resolution (cache → bundled → theme → network) and cover images |
| `tux-install` | `libtux_install.so` | privileged `pacman` transactions, output streaming, progress |
| `tux-ui` | `libtux_ui.so` | Slint window, UI state, owns the main loop |
| `tux-store` | `tux-store` | host: finds and loads modules, routes messages |

## Design Principles Used Throughout

- **No direct calls between modules.** Everything is a `Message` on the bus; modules ignore what they do not understand.
- **Handlers never block.** `on_message` runs on the publisher's thread, so slow work goes to a thread of the module's own.
- **Trust pacman's own resolver.** Sizes and dependency lists come from `pacman -Sp` / `-Si`, never from a hand-written dependency walk.
- **Never report 100 % early.** The progress model is capped at 98 %; only the real process exit produces 1.0.
- **Read the local database directly.** The installed set comes from `/var/lib/pacman/local`, not from spawning `pacman -Q`.
- **Defensive by default.** Package names are allow-listed and passed after `--`; every external process has a timeout; every module entry point is wrapped in `catch_unwind`.
- **Plain data across the Rust/Slint boundary.** The UI works with Slint-generated `Ui*` structs; strings are pre-formatted and ratios pre-computed in Rust.
