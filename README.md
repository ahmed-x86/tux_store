# Tux Store

A lightweight, native GUI package manager for **Arch Linux**, built with **Qt6** (backend/logic) and **Slint** (UI). Tux Store wraps `pacman` in a friendly app-store-like experience: browse curated apps, search the repositories, inspect real dependency/size breakdowns before installing, and watch a live weighted progress bar while `pacman` does the work.

![platform](https://img.shields.io/badge/platform-Arch%20Linux-1793d1)
![language](https://img.shields.io/badge/language-C%2B%2B20-blue)
![ui](https://img.shields.io/badge/UI-Slint-orange)
![qt](https://img.shields.io/badge/backend-Qt6-41cd52)

---

## Features

- **Curated home grid** — a hand-picked list of popular default apps, with live installed/not-installed status pulled from `pacman -Q`.
- **Fuzzy search** — searches the sync databases via `pacman -Ss`, with normalized substring filtering (ignores case, spaces, dashes, underscores, dots).
- **Real dependency & size breakdown** — before installing, Tux Store asks `pacman`'s own resolver (`pacman -Sp --print-format`) for the *actual* transaction plan: new dependencies, already-installed dependencies, download size, and net upgrade size — mirroring pacman's own summary instead of guessing.
- **Weighted install progress** — parses `pacman`'s streamed console output live and turns it into a smooth, size-weighted 0–100% progress bar, split visually into "new dependencies" vs "the app itself."
- **Raw console viewer** — a togglable overlay shows the unmodified `pacman` output for anyone who wants to see exactly what's happening.
- **Smart icon fetching** — resolves app icons from several popular icon-theme GitHub repos (Papirus, Tela, Fluent, WhiteSur, Qogir), with:
  - a system-icon-theme check first (fast, no network),
  - fuzzy candidate name generation (aliases, suffix stripping, prefix truncation),
  - a global concurrency cap so a big grid doesn't open dozens of sockets at once,
  - per-request timeouts with hard-abort safety nets,
  - on-disk caching so icons only need to be fetched once.
- **"You might also like"** — a randomized suggestion shelf on the details page to encourage discovery.
- **Root-aware installs** — uses `pkexec` for the native Polkit auth prompt, or runs directly if already root.

## Screenshots

*(Add screenshots of the home grid and the details/install view here.)*

## Requirements

- **Arch Linux** (or an Arch-based distro) with `pacman` and (optionally) `pkexec`/Polkit installed.
- **CMake** ≥ 3.21
- **C++20** compiler (GCC or Clang)
- **Qt6** — `Core`, `Gui`, `Network`, `Concurrent`
- **Slint** (C++ API) — see [slint.dev](https://slint.dev) for installation instructions

On Arch Linux, most dependencies can be installed with:

```bash
sudo pacman -S cmake qt6-base gcc
```

Slint is not currently in the official Arch repos as a prebuilt package for this integration; install it per the [Slint C++ getting-started guide](https://releases.slint.dev/latest/docs/cpp/) (via `FetchContent`, a system install, or an AUR package if available).

## Building

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

This produces a `tuxstore` executable in the `build/` directory.

Run it with:

```bash
./tuxstore
```

> **Note:** installing packages triggers a `pkexec` (Polkit) authentication prompt unless Tux Store is already running as root.

## Project Layout

```
├── include/            # Public headers for all backend classes
├── src/                # Backend implementation (Qt/C++) + main.cpp
├── ui/                 # Slint UI: main.slint (views/components), theme.slint (design tokens)
├── DOCS/               # In-depth developer documentation (see below)
├── CMakeLists.txt
└── README.md
```

## Documentation

Full developer documentation — architecture, module-by-module deep dives, the Qt↔Slint data flow, and contribution guidelines — lives in [`DOCS/`](DOCS/README.md). Start there if you plan to contribute or need to understand how a specific piece works.

Quick links:

- [Architecture Overview](DOCS/ARCHITECTURE.md)
- [PacmanManager](DOCS/PACMAN_MANAGER.md)
- [InstallManager](DOCS/INSTALL_MANAGER.md)
- [IconFetcher](DOCS/ICON_FETCHER.md)
- [Package / Data Model](DOCS/PACKAGE_MODEL.md)
- [UI Layer (Slint)](DOCS/UI_LAYER.md)
- [Logging](DOCS/LOGGING.md)
- [Contributing](DOCS/CONTRIBUTING.md)

## How It Works (in short)

1. On launch, `PacmanManager::fetchDefaults()` runs `pacman -Q` against a curated app list off the UI thread (via `QtConcurrent`) and populates the home grid.
2. Icons are resolved lazily per-card by `IconFetcher`, which checks disk cache → system icon theme → a handful of GitHub icon-theme repos, in that order.
3. Clicking a card calls `PacmanManager::fetchDetails()`, which uses pacman's real transaction planner (`pacman -Sp --print-format`) to compute exact download/installed sizes and the new-vs-installed dependency split.
4. Clicking **Install** hands the target package name and per-package size map to `InstallManager`, which spawns `pacman -S` (via `pkexec` if not root), streams and parses its output line-by-line, and emits a weighted progress fraction.
5. The Slint UI (`ui/main.slint`) is a thin, mostly declarative view over plain data structs (`UiPackage`, `UiPackageDetails`, `UiInstallState`) that `main.cpp` keeps in sync with signals from the backend.

## License

[GPL v3](./LICENSE)

## Contributing

Contributions are welcome! Please read [`DOCS/CONTRIBUTING.md`](DOCS/CONTRIBUTING.md) before opening a PR — it covers code style, the logging conventions, and how the Qt/Slint boundary is expected to be maintained.
