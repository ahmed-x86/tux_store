# Architecture Overview

## High-Level Diagram

```
                         ┌────────────────────────┐
                         │        main.cpp         │
                         │  (glue / owns UI state) │
                         └───────────┬─────────────┘
                                     │ signals / slots
              ┌──────────────────────┼──────────────────────┐
              │                      │                       │
    ┌─────────▼─────────┐  ┌─────────▼─────────┐   ┌─────────▼─────────┐
    │   PacmanManager    │  │   InstallManager   │   │    IconFetcher     │
    │  (read-only query) │  │  (mutating action)  │  │  (network + cache) │
    └─────────┬─────────┘  └─────────┬─────────┘   └─────────┬─────────┘
              │ QtConcurrent          │ QProcess              │ QNetworkAccessManager
              ▼                       ▼                       ▼
        pacman -Q / -Ss /       pkexec pacman -S         GitHub raw icon repos
        -Si / -Sp                (streamed stdout)        + system icon theme
                                                            + on-disk cache

                         ┌────────────────────────┐
                         │      ui/main.slint      │
                         │  (declarative, reactive)│
                         └────────────────────────┘
                          driven by UiPackage /
                          UiPackageDetails /
                          UiInstallState structs
```

## Process Model

Tux Store is a single-process desktop application. There is no daemon, no D-Bus service, and no persistent background process. All `pacman` interaction happens through short-lived child processes spawned on demand:

| Operation | Mechanism | Blocks UI thread? |
|---|---|---|
| List curated apps + installed status | `QtConcurrent::run` running `pacman -Q` | No |
| Search repos | `QtConcurrent::run` running `pacman -Ss` | No |
| Fetch package details/sizes | `QtConcurrent::run` running `pacman -Si` / `-Sp` / `-Qi` (several calls) | No |
| Install a package | Async `QProcess` running `pkexec pacman -S` (or `pacman -S` directly if root) | No (event-driven) |
| Fetch an icon | Async `QNetworkAccessManager::get` | No (event-driven) |

None of these ever call `waitForFinished()` on the UI thread in a way that would freeze the interface — read queries move the blocking wait onto a `QtConcurrent` worker thread, and the install/network operations are fully signal/slot driven.

## Threading Model

- **Qt event loop** runs on the main thread as usual.
- **Slint event loop** is what actually calls `ui->run()` and blocks in `main()`.
- To let Qt's signals, `QNetworkAccessManager`, `QProcess`, and `QtConcurrent` callbacks fire while Slint owns the "real" event loop, `main.cpp` installs a repeating `slint::Timer` (16ms tick, ~60Hz) that calls `QGuiApplication::processEvents()`. This is the mechanism that makes the two frameworks coexist in one process.

```cpp
slint::Timer t;
t.start(slint::TimerMode::Repeated, std::chrono::milliseconds(16), []() {
    QGuiApplication::processEvents();
});
```

This means: **any Qt signal delivered to a lambda connected in `main.cpp` will fire with up to ~16ms of latency**, and any long-running synchronous Qt code on the main thread (there shouldn't be any) would stall Slint's own rendering/input handling too.

- **Worker threads** are used only via `QtConcurrent::run` for the read-only `PacmanManager` queries. Results are marshaled back to the main thread automatically through `QFutureWatcher`'s `finished` signal (which itself only fires because of the `processEvents()` pump above).

## The Qt ↔ Slint Boundary

Slint's C++ codegen produces C++ structs from the `struct` declarations in `ui/main.slint` (e.g. `UiPackage`, `UiPackageDetails`, `UiInstallState`, `UiPackageDependency`). These are **plain value types** — they know nothing about Qt.

The backend, on the other hand, speaks in Qt/C++ types (`Package`, `PackageDetails`, `QString`, `QVector`, etc., declared in `include/package.h`).

`main.cpp` is the *only* place these two worlds meet. Every backend signal handler in `main.cpp` follows the same pattern:

1. Receive a Qt-flavored payload (e.g. `QVector<Package>`, `PackageDetails`).
2. Construct/update the corresponding `Ui*` struct(s), converting `QString` → `slint::SharedString` via `.toStdString()`.
3. Push the struct into a `slint::VectorModel` (for lists) or call `ui->set_xxx(...)` (for single values).

This keeps the Slint UI files completely free of Qt dependencies and keeps `main.cpp` as the single "translation layer." **If you add a new field to a backend struct that the UI needs to display, you must add the mirrored field to the corresponding `Ui*` struct in `main.slint` AND add the copy-over line in `main.cpp`.**

## Data Flow: Browsing → Details → Install

1. **App launch** → `pacman->fetchDefaults()` → `PacmanManager::resultsReady(QVector<Package>)` → `refreshGrid()` rebuilds `pkgModel` (a `slint::VectorModel<UiPackage>`) → grid renders. Icons not found in the on-disk cache are requested lazily, one `IconFetcher::request()` call per card.
2. **User clicks a card** → `ui->on_app_clicked` fires → `main.cpp` immediately sets `current_package`, resets `current_install`, builds a random "You might also like" shelf from the currently-loaded grid, flips to the details view, and kicks off `pacman->fetchDetails(name)`.
3. **Details arrive asynchronously** → `PacmanManager::detailsReady(PackageDetails)` → `main.cpp` stores the raw `PackageDetails` in `lastDetails` (a `shared_ptr` kept alive for the install click handler) and converts it into a `UiPackageDetails` (formatted size strings + precomputed bar ratios).
4. **User clicks Install** → `ui->on_install_clicked` fires → `main.cpp` builds a `QHash<QString, long long>` of every *not-yet-installed* dependency plus the target package itself (using the `lastDetails` snapshot), resets `current_install`, and calls `installManager->install(pkgName, sizes)`.
5. **InstallManager streams progress** → `consoleOutput`, `progressChanged`, and eventually `finished` signals update `current_install` live; on success, the package's `installed` flag is flipped both in `current_package` and in the grid model in place (no full refetch).

## Why Not Re-implement Dependency Resolution?

A tempting shortcut would be to compute "what will be installed" by recursively walking `pacman -Si` dependency fields in application code. Tux Store deliberately does **not** do this. Instead, `PacmanManager::runFetchDetails` shells out to:

```
pacman -Sp --print-format "%n|%s" <pkg>
```

`-Sp` performs pacman's *real* dependency resolution (including version constraints, conflicts, provides/replaces, and optional-dependency rules) without downloading or installing anything, and `--print-format` lets us extract exactly the fields we need. This guarantees the UI's size/dependency breakdown always matches what `pacman -S` will actually do — see [PACMAN_MANAGER.md](PACMAN_MANAGER.md) for the full breakdown.

## Extension Points

If you're planning a contribution, these are the natural seams:

- **New backend query** → add a method + signal to `PacmanManager` (or a new manager class), following the existing `QtConcurrent` + `QFutureWatcher` pattern for anything that shells out to `pacman`.
- **New UI-visible field** → add it to the relevant struct in `ui/main.slint`, then wire the corresponding copy in `main.cpp`.
- **New install-time behavior** (e.g. `pacman -R` for removal) → `InstallManager` is currently install-only; `ui->on_remove_clicked` is stubbed as a TODO in `main.cpp` and is the intended integration point.
- **New icon source** → extend `urlsForCandidate()` in `iconfetcher.cpp`; the job/queue machinery is source-agnostic.
