# Tux Store — Developer Documentation

This directory contains in-depth documentation for contributors. If you're new to the codebase, read these roughly in order:

1. **[ARCHITECTURE.md](ARCHITECTURE.md)** — the big picture: how the pieces fit together, threading model, and the Qt↔Slint bridge in `main.cpp`.
2. **[PACKAGE_MODEL.md](PACKAGE_MODEL.md)** — the core data structures (`Package`, `PackageDetails`, `PackageDependency`) and helper functions in `package.h/.cpp`.
3. **[PACMAN_MANAGER.md](PACMAN_MANAGER.md)** — how browsing, searching, and dependency/size resolution work under the hood via `pacman`.
4. **[INSTALL_MANAGER.md](INSTALL_MANAGER.md)** — how installs are launched, elevated, streamed, parsed, and turned into a progress bar.
5. **[ICON_FETCHER.md](ICON_FETCHER.md)** — the icon resolution pipeline: system theme, disk cache, and the networked icon-theme repo fallback with its concurrency controls.
6. **[UI_LAYER.md](UI_LAYER.md)** — the Slint side: components, structs shared with C++, and the theming system.
7. **[LOGGING.md](LOGGING.md)** — logging categories and conventions used across the backend.
8. **[CONTRIBUTING.md](CONTRIBUTING.md)** — coding conventions, PR expectations, and good first areas to work on.

## Module Map

| Module | Headers | Sources | Responsibility |
|---|---|---|---|
| Data model | `include/package.h` | `src/package.cpp` | Plain structs + formatting/name-sanitizing helpers |
| Pacman queries | `include/pacmanmanager.h` | `src/pacmanmanager.cpp` | Async `pacman` queries: defaults, search, details |
| Install flow | `include/installmanager.h` | `src/installmanager.cpp` | Runs & parses `pacman -S`, weighted progress |
| Icon fetching | `include/iconfetcher.h` | `src/iconfetcher.cpp` | Resolves & caches app icons from multiple sources |
| Logging | `include/log.h` | `src/log.cpp` | Central `QLoggingCategory` setup + formatter |
| Entry point / glue | — | `src/main.cpp` | Wires backend signals to the Slint UI, owns UI-facing state |
| UI | — | `ui/main.slint`, `ui/theme.slint` | All visual layout, components, and the Catppuccin-based theme |

## Design Principles Used Throughout

These recurring patterns show up in more than one module — worth internalizing before making changes:

- **Off-thread pacman calls.** Every `pacman` invocation used for *reading* data runs via `QtConcurrent::run` + `QFutureWatcher`, never blocking the UI thread. `InstallManager`, by contrast, uses an async `QProcess` because it needs to stream output live.
- **Trust pacman's own resolver.** Rather than re-implementing Arch's dependency resolution, `PacmanManager::runFetchDetails` shells out to `pacman -Sp --print-format` to get the *exact* transaction pacman itself would perform. This avoids subtle mismatches between what the UI predicts and what actually happens.
- **Never report 100% early.** `InstallManager` caps its own progress emission at 98% and only ever emits `1.0` after the real subprocess has exited — because pacman hooks (icon caches, desktop databases, etc.) can still be running after the last visible "installing" line.
- **Defensive networking.** `IconFetcher` bounds *global* concurrent requests (not just per-job), sets transfer timeouts, and adds a hard-abort timer as a second line of defense — so a single wedged connection can never stall icon loading for the whole grid.
- **Plain data across the Qt/Slint boundary.** The UI never touches `Package`/`PackageDetails` C++ structs directly. `main.cpp` translates them into Slint-generated `UiPackage` / `UiPackageDetails` / `UiInstallState` structs on every update.
