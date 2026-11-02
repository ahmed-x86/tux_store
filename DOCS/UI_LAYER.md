# UI Layer (`tux-ui`)

Files: `crates/tux-ui/ui/*.slint`, `crates/tux-ui/src/{lib,app,state,convert,console,config,links}.rs`, `build.rs`

The UI is [Slint](https://slint.dev), compiled by `slint-build` from `ui/main.slint` and included with `slint::include_modules!()`. Only items **re-exported from `main.slint`** (`export { … }`) exist on the Rust side.

## Slint files

| File | Content |
|---|---|
| `theme.slint` | `global Theme` (Catppuccin palette, `is-dark`, 14 `accents`) |
| `types.slint` | enums `AppView`, `OpPhase`, `OpKind` and all `Ui*` structs |
| `components.slint` | `PillButton`, `TopBar`, `SearchBox`, `TabButton`, `HScrollBar`, `AppCard`, `SuggestionCard`, `AppRow`, `PackageGrid`, `DepRow`, `CoverCarousel`, `ProgressCard`, `ConsoleOverlay` |
| `home_tab.slint` | `HomeTab` — banner + one `AppRow` per section |
| `installed_tab.slint` | `InstalledTab` — filterable paginated grid |
| `update_tab.slint` | `UpdateTab` — update list + *Update all* + progress |
| `details_view.slint` | `DetailsView` + uninstall dialog |
| `addons_store.slint` | `AddonsStore` |
| `settings_view.slint` | `SettingsView` |
| `main.slint` | `MainWindow`: navigation, search, tabs, overlays |

Shared building blocks replace the original duplication: one `TopBar` (children go to the right via `@children`), one `PackageGrid` for search, installed and add-ons, one `ProgressCard` for installs, removals and system upgrades, one `HScrollBar` for every horizontal shelf.

## Shared types

```slint
UiPackage        { name, pretty-name, repo, version, description, installed, icon: image, is-same-name }
UiSection        { title, packages: [UiPackage] }
UiPackageDetails { app-size-str, dependencies, installed-deps-size-str, new-deps-size-str,
                   download-size-str, installed-ratio, new-ratio, app-ratio,
                   total-download-str, total-installed-str, net-upgrade-str, is-loading, plan-ok }
UiInstallState   { phase: OpPhase, kind: OpKind, success, progress, deps-ratio, target }
UiSpecialCase    { is-special, type-name, items: [UiAddon], is-addon-for }
UiUpdate         { name, old-version, new-version }
```

All sizes arrive pre-formatted and all proportions pre-computed (`convert.rs`): `.slint` files only lay things out.

`UiInstallState.target` is the package name, or `"@upgrade"` for a system upgrade. Views show the progress card only when `target` matches what they display, so a running upgrade does not appear on an unrelated package page.

## `MainWindow` interface

- **State properties:** `view: AppView`, `active-tab`, `search-query`, `installed-filter`, `show-console`.
- **Data properties (set from Rust):** models and strings listed in `main.slint`.
- **Callbacks (Slint → Rust):** `search-edited`, `search-submitted`, `home-clicked`, `tab-changed`, `app-clicked`, `back-clicked`, `install-clicked`, `remove-clicked(flag)`, `open-url`, `addon-clicked`, `view-all-addons-clicked`, `request-more-results`, `request-more-installed`, `installed-filter-edited`, `refresh-updates`, `upgrade-all`, `cover-prev/next/clicked`, `theme-changed`, `clear-icon-cache`.
- `copy-text(string)` — a public function that copies through a hidden read-only `TextInput` (`select-all()` + `copy()`), which works on X11 and Wayland without extra dependencies.

## Rust side

### `state.rs`
`State` owns every model and cache for the UI thread: icon map, section/search/installed/add-on/suggestion models, covers, history, last details, console buffer. `State::handle(Message)` is the only place bus results are applied. Highlights:

- **Stale answers are dropped:** search results carry their query; details/add-ons check that the package is still the current one.
- **Icons:** `request_icons` publishes one `IconRequested` per package ever; `on_icon` loads the file once, caches the `Image`, and patches every model row with that name.
- **Pagination:** `Paged` (35 search results first, then 20 per click; installed 60, then 60).
- **Navigation history:** opening a package from a suggestion or add-on pushes the current one; *Back* pops it, and returns to Main when empty.
- **Suggestions:** up to 8, preferring packages of the same Home section.
- **Operations:** `begin_operation` refuses to start while one is running; on success the *installed* flag is patched in all lists.

### `app.rs`
Creates the window, loads the saved theme, binds models, installs the state, wires callbacks, starts two timers and runs the event loop. Search typing is **debounced 250 ms**; Enter searches immediately. `tux-store openpackage <name>` is read here from `std::args()` and published as `ExactRequested`.

### `console.rs`
`ConsoleBuffer` interprets `\r` as "rewind to line start" so a progress bar occupies one line; strips ANSI; caps at 200 000 bytes (drops the oldest half at a line boundary). The state copies it into Slint at most every **100 ms**.

### `config.rs`, `links.rs`
Config is `~/.config/tux-store/config.json` (`{"dark": true}`). `links::package_url(repo, name)` builds archlinux.org / AUR / mirror URLs; `links::open` uses `xdg-open` and reaps the child.

## Theming

`Theme` is a global with `is-dark`; every colour is a property that switches on it. Colours in `.slint` files should reference `Theme.*`; the progress bars still use three literal hex colours (`#89b4fa`, `#cba6f7`, `#6c7086`) — a good first clean-up.

## Slint notes (for the version in use)

- `Flickable` uses `content-width`, `content-height`, `content-x` (the `viewport-*` names are deprecated and rejected by the build).
- A layout whose padding depends on `parent.width` while its Flickable's size depends on the layout creates a binding loop; use the outer component's `root.width` instead (see `settings_view.slint`).
- Enum values inside expressions must be qualified (`MouseCursor.pointer`).
