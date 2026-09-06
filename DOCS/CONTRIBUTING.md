# Contributing to Tux Store

Thanks for considering contributing! This project is a small, focused Arch Linux package-manager GUI — the goal is to keep it fast, honest about what pacman will actually do, and free of unnecessary complexity. Please read [ARCHITECTURE.md](ARCHITECTURE.md) first if you haven't.

## Building for Development

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j$(nproc)
```

Run with verbose logging (see [LOGGING.md](LOGGING.md)):

```bash
QT_LOGGING_RULES="tuxstore.*.debug=true;qt.*.debug=false" ./tuxstore
```

> Consider wiring `installLogHandler()` into `main()` first (see the callout in [LOGGING.md](LOGGING.md)) — it isn't currently called, so you're working with Qt's default log formatting until that's fixed.

## Code Style

- **C++20**, matching the existing style: 4-space indentation, braces on the same line as control statements, `snake_case` for local variables where the codebase already does so, `camelCase` for member functions.
- **Prefer `QVector`/`QHash`/`QString`** (Qt containers) in backend code, consistent with the existing headers — don't mix in `std::vector`/`std::string` for data that crosses Qt signal/slot boundaries.
- **Every blocking `QProcess::waitForFinished()` needs an explicit timeout and a kill-on-timeout fallback.** This is a hard rule in `pacmanmanager.cpp` — see any of its methods for the pattern.
- **Read-only pacman queries must run via `QtConcurrent::run` + `QFutureWatcher`**, never synchronously on the UI thread. Only truly interactive/streaming operations (like the actual install) should use an async `QProcess` directly.
- **Log with categories** (`qCDebug(logXxx)`, etc.) — see [LOGGING.md](LOGGING.md) for which category to use and when.
- **Slint files stay Qt-free.** All formatting, math, and Qt-type handling belongs in `.cpp` files; `.slint` files should only receive already-formatted strings and pre-computed numeric ratios.

## Where to Add Things

| You want to... | Start here |
|---|---|
| Add a new `pacman`-backed query (read-only) | `PacmanManager` — add a method + signal, follow the `QtConcurrent`/`QFutureWatcher` pattern used by the existing three methods |
| Add package removal (`pacman -R`) | `InstallManager` — needs a parallel method to `install()`, and `ui->on_remove_clicked` in `main.cpp` is the existing (currently stubbed) wire-up point |
| Improve icon resolution for a specific app | `iconfetcher.cpp` — extend the `aliasFor()` or `fallbackHints()` tables, or add a new repo to `urlsForCandidate()` |
| Add a UI-visible field to package details | Add the field to `UiPackageDetails` in `ui/main.slint`, then copy it over in the `detailsReady` handler in `main.cpp` |
| Change the visual theme | `ui/theme.slint` only — avoid introducing new hardcoded hex colors in `main.slint` |
| Fix a hardcoded hex color in `main.slint` | The install/download progress bar segment colors (`#89b4fa`, `#cba6f7`, `#6c7086`) are currently inline literals rather than `Theme.*` references — replacing them with theme properties is a good, contained first PR |
| Add logging to a new subsystem | See [LOGGING.md](LOGGING.md) — reuse an existing category unless the subsystem is genuinely distinct |

## Good First Contributions

- **Wire up `installLogHandler()`** in `main()` (see [LOGGING.md](LOGGING.md)) — small, self-contained, immediately useful for everyone debugging afterward.
- **Replace the few hardcoded hex colors** in `main.slint`'s progress bars with `Theme.*` references.
- **Improve `prettifyName()`** in `package.cpp` to special-case known acronyms (e.g. `"vlc"` → `"VLC"`, `"gimp"` → `"GIMP"`) rather than naive per-segment capitalization.
- **Implement `pacman -R` removal**, following the elevation/streaming pattern already established in `InstallManager::install()`.
- **Add disk-cache invalidation/expiry** to `IconFetcher` (currently icons are cached forever with no TTL or manual-refresh path).
- **Add unit tests** — there is currently no test suite. Good early candidates: `PacmanManager::normalize()`, `sanitizeName()`, `formatSize()`, and `IconFetcher::isValidImageContent()`/`generateCandidates()`, since these are all pure functions with no process/network dependency.

## Submitting a Change

1. Keep PRs focused — one logical change per PR is much easier to review than a bundle of unrelated fixes.
2. If you touch a backend struct that the UI reads, double-check you've updated **both** the C++ struct (`package.h` or similar) **and** the mirrored Slint struct in `main.slint`, plus the copy-over code in `main.cpp` — see [ARCHITECTURE.md](ARCHITECTURE.md#the-qt--slint-boundary).
3. If you change timeout values, concurrency limits, or parsing heuristics (especially in `InstallManager`'s line parser or `IconFetcher`'s candidate generation), please explain the reasoning in the PR description — these were tuned somewhat empirically and future contributors will thank you for the context.
4. Test against a real Arch system where possible — much of this app's correctness depends on the exact text format of live `pacman` output, which is hard to fully mock.

## Reporting Issues

When filing a bug, please include:
- Your Arch Linux `pacman` version (`pacman -V`)
- Whether you're running as root or via `pkexec`
- Relevant log output (ideally with `QT_LOGGING_RULES="tuxstore.*.debug=true"` set — see [LOGGING.md](LOGGING.md))
- For install issues: the raw console output from the details page's "Console" overlay, if available
