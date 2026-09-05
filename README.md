# Tux Store (C++/Qt6)

Rewrite of the original Rust/GTK4 concept in C++20 + Qt6, same Catppuccin Mocha look.

## Build
```
sudo pacman -S qt6-base qt6-svg cmake
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./tuxstore
```

## What changed vs. the Rust version

**Icon system (main upgrade):**
- Old: tried each candidate URL one at a time, sequentially, per icon.
- New (`IconFetcher`): races up to 4 candidate URLs **in parallel** per icon (`QNetworkAccessManager`), first valid hit wins and cancels the rest of that job's need to continue. Much faster on cold cache / bulk grid loads.
- Added an **in-memory `QPixmapCache`** layer on top of the disk cache, so re-showing a card (e.g. after Load More or navigating back) never touches disk or network twice in one session.
- Same fuzzy candidate generation (aliases → raw name → suffix-stripped → progressive truncation → hand-curated hints) and same HTML-vs-image content sniffing to reject fake 200 OK error pages.

**Architecture:**
- GTK `Stack` → `QStackedWidget` (home / details).
- GTK `FlowBox` → `QGridLayout` with column count recomputed from width (min 2, max 8), same as the original's `min/max_children_per_line`.
- `pacman -Q` / `pacman -Ss` calls run via `QtConcurrent` off the UI thread (equivalent to the Rust `std::thread` + channel pattern).
- Pagination (35/page, "Load More") preserved exactly.

## Notes
- Install/Remove buttons currently show a confirmation dialog instead of running `pacman -S/-R` directly — wire `DetailsView::installRequested/removeRequested` to a `QProcess` + polkit/pkexec call for real installs.
- Icon repos used: Papirus, Tela, Fluent, WhiteSur, Qogir (same 5 as original).
