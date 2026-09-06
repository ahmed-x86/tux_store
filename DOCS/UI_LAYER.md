# UI Layer (Slint)

Files: `ui/main.slint`, `ui/theme.slint`

The entire UI is written in [Slint](https://slint.dev), a declarative UI language compiled to native C++ code (`slint_target_sources(tuxstore ui/main.slint)` in `CMakeLists.txt` generates the `MainWindow` C++ class and its associated struct types used throughout `main.cpp`).

## Shared Data Structs

These `struct` declarations at the top of `main.slint` are code-generated into C++ types and are the **only** way data crosses from the backend into the UI (see [ARCHITECTURE.md](ARCHITECTURE.md#the-qt--slint-boundary)).

### `UiPackage`

One app, as shown on a card (home grid, suggestion shelf, or the details header).

```slint
export struct UiPackage {
    name: string,          // pacman name — used as a stable identity key
    pretty_name: string,   // display name via prettifyName()
    repo: string,
    version: string,
    description: string,
    installed: bool,
    icon: image,           // empty (width == 0) until IconFetcher resolves it
}
```

`name` is used throughout `main.cpp` as the identity key for finding/updating a specific row in `pkgModel` (e.g. when an icon arrives or an install completes) — **it must stay unique** within a single grid's dataset.

### `UiPackageDependency`

One row in the details page's dependency list.

```slint
export struct UiPackageDependency {
    name: string,
    size_str: string,   // pre-formatted via formatSize(), e.g. "12.34 MiB"
    installed: bool,
}
```

### `UiPackageDetails`

Everything shown in the details page's size/dependency cards.

```slint
export struct UiPackageDetails {
    app_size_str: string,
    dependencies: [UiPackageDependency],
    installed_deps_size_str: string,
    new_deps_size_str: string,
    download_size_str: string,
    installed_ratio: float,   // pre-computed bar segment proportions, sum ≈ 1.0
    new_ratio: float,
    app_ratio: float,
    total_download_str: string,
    total_installed_str: string,
    net_upgrade_str: string,
    is_loading: bool,
}
```

All size fields arrive **pre-formatted as strings** and all bar proportions arrive **pre-computed as floats** — the Slint side never parses a size string or divides byte counts itself. This is intentional: formatting/math belongs in `package.h`/`main.cpp`, keeping `.slint` files purely about layout.

### `UiInstallState`

Drives the install progress card and console overlay.

```slint
export struct UiInstallState {
    is_installing: bool,
    finished: bool,
    success: bool,
    progress: float,      // 0..1, overall weighted progress
    deps_ratio: float,    // fraction of the bar belonging to "new deps" vs "the app itself"
    console_log: string,
}
```

## Components

### `AppCard`

The home-grid tile. Shows the icon (or a colored placeholder with a "↻" glyph while loading, using `Theme.accents[mod(accent_idx, accents.length)]` for a rotating placeholder color per card), name, repo/version, and installed status. Emits `clicked()`.

### `SuggestionCard`

A smaller, left-aligned variant used in the "You might also like" horizontal shelf on the details page. Fixed size (`168×190`), hover border uses the accent color instead of a neutral surface color.

### `DepRow`

One dependency list row: a checkmark/download-arrow badge (green check if already installed, accent-colored down-arrow if new), the name, and the size.

### `DetailsView`

The full details page. Structurally:

1. **Top bar** — same branding as the home page, with a Back button.
2. **Header** — icon, name, installed badge or repo badge, description, version, and the Install/Remove button (label switches based on `pkg.installed` and `install_state.is_installing`).
3. **Install progress card** (conditionally shown while `is_installing || finished`) — a 3-segment progress bar (blue = new deps progress, mauve = app-itself progress, grey = remaining) plus a "Console" toggle button.
4. **Download summary card** — the size breakdown bar (grey/blue/mauve = installed/new/app ratios) plus the pacman-style Total Download / Total Installed / Net Upgrade stat row.
5. **Dependencies card** — the full `DepRow` list, or a "No additional dependencies required" message.
6. **Suggestions shelf** — a horizontally scrollable `Flickable` of `SuggestionCard`s, with a **custom-built draggable scrollbar** (`scroll-track`/`thumb`) since Slint doesn't provide one out of the box. The thumb width is computed from the ratio of visible to total content width, and dragging maps thumb position back to `viewport-x`.
7. **Console overlay** — a modal-style overlay (dimmed background, a `TouchArea` behind the dialog to swallow clicks) showing `install_state.console_log` in a monospace, green-on-dark terminal style, inside a scrollable `Flickable`.

### `MainWindow`

The top-level window. Toggles between the home grid and `DetailsView` based on `is_showing_details`. The home grid uses **manual absolute positioning** rather than Slint's built-in grid layout:

```slint
property <int> cols: max(1, floor((self.width - pad * 2 + gap) / (card-w + gap)));
...
x: grid-area.pad + mod(idx, grid-area.cols) * (grid-area.card-w + grid-area.gap);
y: grid-area.pad + floor(idx / grid-area.cols) * (grid-area.card-h + grid-area.gap);
```

This gives a responsive, reflowing grid (column count recalculates from the available width) while keeping full control over card size and gutters — something a plain `GridLayout` in Slint doesn't do dynamically based on width.

## Theming — `theme.slint`

A single `global Theme` block exposes a [Catppuccin Mocha](https://github.com/catppuccin/catppuccin)-derived palette as named color properties (`base`, `mantle`, `crust`, `text`, `subtext0/1`, `overlay0/1`, `surface0/1/2`, `red`, `green`, `mauve`, `pink`, `blue`), plus an `accents: [color]` array of 14 colors used for rotating per-card accent colors (`Theme.accents[mod(idx, Theme.accents.length)]`).

**All colors in `main.slint` should reference `Theme.*`** rather than hardcoding hex values, so a future re-theme only requires editing `theme.slint`. (A few raw hex literals currently exist inline for the progress-bar segment colors in `DetailsView` — see [CONTRIBUTING.md](CONTRIBUTING.md) for a good first cleanup task.)

## Callbacks (Slint → C++)

Declared on `MainWindow` and wired in `main.cpp` via `ui->on_xxx(...)`:

| Callback | Fired when | Handled by |
|---|---|---|
| `search_changed(string)` | search box "accepted" (Enter) | `pacman->search(query)` |
| `app_clicked(UiPackage)` | a card (grid or suggestion) is clicked | sets `current_package`, resets install state, builds suggestions, fetches details |
| `back_clicked()` | Back button on details page | `is_showing_details = false` |
| `install_clicked(UiPackage)` | Install button | builds size map from `lastDetails`, calls `installManager->install()` |
| `remove_clicked(UiPackage)` | Remove button | currently a **no-op stub** in `main.cpp` |

## A Note on Reactive Updates

Slint properties are reactive: setting `ui->set_current_install(st)` (etc.) in a C++ lambda automatically re-renders any part of the UI bound to that property, with no manual "redraw" calls needed. `main.cpp` generally follows a **read-modify-write** pattern for these structs — e.g. `UiInstallState st = ui->get_current_install(); st.progress = ...; ui->set_current_install(st);` — rather than trying to update a single field in place, since Slint's generated structs are plain value types with no partial-setter API.
