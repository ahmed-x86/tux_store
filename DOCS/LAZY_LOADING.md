# Lazy loading

Tux Store loads a resource only when it is (or is about to be) in front of the
user. This page lists every resource, when it is requested, and how to check
that nothing else was loaded.

The rule of thumb: **a Slint component tells Rust which rows are on screen**;
Rust asks the backend for exactly those rows, once.

## What is loaded at start-up

`State::startup` publishes only:

| Message | Why |
|---|---|
| `EngineChanged` | every backend must know which package manager to use |
| `UiReady` | lifecycle signal (no backend warms up on it) |
| `HomeRequested` | the Home shelves are the visible page |
| `CoversRequested` | lists cover folders **on disk**, no network and no decoding |

Not requested at start-up: taxonomy (categories / groups / repositories),
search results, installed and update lists, screenshots, icons of off-screen
cards, remote cover pictures, details of any package.

## Resources

| Resource | Requested when | Message |
|---|---|---|
| Home shelves | start-up / Home clicked (visible page) | `HomeRequested` → `HomeReady` |
| Icons | a card enters the viewport of a grid or shelf, or a package page opens | `IconRequested` → `IconReady` / `IconFailed` |
| Search results | the user types (debounced 250 ms) or submits | `SearchRequested` → `SearchResults` |
| Installed list | the Installed tab is selected or refreshed | `InstalledRequested` → `InstalledReady` |
| Updates | the Updates tab is selected, or after an upgrade | `UpdatesRequested` → `UpdatesReady` |
| Taxonomy section | a side-menu page is opened for the first time | `TaxonomySectionRequested` → `TaxonomySectionReady` |
| Taxonomy packages | one repository / group / category row is opened | `TaxonomyPackagesRequested` → `TaxonomyPackagesReady` |
| Package details | a package page opens | `DetailsRequested` → `DetailsReady` |
| Screenshots | a package page opens (and add-on page if it has them) | `ScreenshotsRequested` → `ScreenshotsReady` |
| Add-ons | the add-ons strip of a package page is shown | `AddonsRequested` → `AddonsReady` |
| Suggestions | a package page opens (built from already-loaded rows) | — |
| Cover pictures | that cover is displayed and has no local files | `CoverImagesRequested` → `CoverImagesReady` |
| Operations | the user presses Install / Remove / Upgrade / Run script | `InstallRequested`, `ScriptStartRequested`, … |

### Icons

Each grid and shelf reports a **visible index range**, not its whole model:

- Home: `home-icons-needed(row, first, last)` — one shelf row plus its range.
- Search, Installed, Browse packages, Add-ons: `*-icons-needed(first, last)`.
- Side-menu rows: `browse-icon-needed(key)` for the row's icon-theme name.

`State::request_icons` de-duplicates names in `icon_requested` and publishes one
`IconRequested` per name for the whole run. `on_icon` decodes the file once,
stores the `Image` in the `icons` map, and patches the matching rows of every
model. Clearing the icon cache empties both maps and bumps `icon-refresh-tick`
so only the cards currently on screen ask again.

Scrolling is what reveals new cards: when a model range changes, Slint calls the
callback again and the newly visible names are requested. Cards that never
reach the viewport keep an empty `image` and cost no decode and no network.

### Packages

Metadata rows are cheap; the UI still pages the big lists instead of building
every card widget at once:

| List | First page | Each "more" |
|---|---|---|
| Search | 35 | 20 |
| Installed | 60 | 60 |
| Browse entry | 60 | 40 |
| Add-ons / suggestions | all (small, part of the visible page) | — |

Paging is in `State` (`Paged`), not in the backend: the backend returns the
matching list once, and the model only receives the rows the user asked to see.

### Package pages

`open_package` clears the screenshot model, then asks for:

- `ScreenshotsRequested` — only for the package being opened;
- `DetailsRequested` (or `ScriptInfoRequested` for add-on scripts);
- the package's own icon, if it is not cached;
- suggestions, built from rows already in memory (Home, search), not a new
  backend query.

Add-ons are fetched by `show_addons` when that strip is displayed.

### Covers

`CoversRequested` scans the cover folders and returns a `Cover` per folder.
Remote covers are returned with an empty `images` list — **nothing is
downloaded**. `show_cover` decodes only the cover at `cover_idx`; if it has no
local pictures it publishes `CoverImagesRequested{name}` and shows a
placeholder. `on_cover_images` merges the answer and refreshes the banner only
if that cover is still on screen. Stepping to another cover repeats the process
for that cover alone.

### Taxonomy

The side menu is discovered per section:

- `BrowseSection` maps to a `TaxonomyKind` (Category, Group, Repository).
- `request_taxonomy(kind)` sends `TaxonomySectionRequested` once; the answer is
  cached in `taxonomy_sections: HashMap<TaxonomyKind, Vec<TaxonomyEntry>>`.
- Opening another drawer page asks for that section only.
- A finished install / remove / script, or an engine change, clears the cache;
  only the section on screen (if the Browse view is open) is fetched again.
- `TaxonomyRequested` / `TaxonomyReady` still exist for tools such as
  `tux-store --dump-taxonomy`, but the UI does not use them at start-up.

Within a section, family rows are collapsed until expanded, and the package
list of an entry is paged like the other grids.

### Operations

Transactions are never started speculatively. `begin_operation` runs only from
an explicit Install / Remove / Upgrade callback; console output and progress
are copied to Slint at most every 100 ms.

## Measuring

Set `TUX_LAZY_STATS=1` to print a summary through the normal logger when the UI
shuts down (`TUX_LOG` defaults to `info`):

```bash
TUX_LAZY_STATS=1 tux-store
# [lazy] icons 42/42 loaded/requested · 95 packages materialized ·
#        0 screenshots · 1 covers shown (0 remote picture sets) ·
#        0 taxonomy sections · 0 operations
```

| Counter | Meaning |
|---|---|
| `icons loaded/requested` | `IconReady` files decoded / distinct `IconRequested` sent |
| `packages materialized` | rows pushed into a Slint model by `push_page` |
| `screenshots` | screenshot files decoded for a package page |
| `covers shown` | times a cover with local pictures was decoded |
| `remote picture sets` | picture paths received through `CoverImagesReady` |
| `taxonomy sections` | section discoveries (`TaxonomySectionReady` counts 1, `TaxonomyReady` counts 3) |
| `operations` | install / remove / upgrade transactions and script runs started |

Open Home and wait: icons should equal the cards actually visible. Open the
Installed tab: taxonomy stays at 0. Open one drawer page: taxonomy becomes 1.
Open a package page: screenshots stay 0 until that page is opened, then only
that package's pictures are counted.

## Adding a lazy surface

1. Report the visible range from Slint when the model or scroll position
   changes (`changed packages`, `changed height`, …), like `AppRow` and
   `PackageGrid` do.
2. In Rust, turn the range into names (`names_in_range`) and call
   `request_icons`; never loop over the full model.
3. For a new backend resource, add an `XxxRequested` / `XxxReady` pair and send
   the request from the callback that makes the surface visible — not from
   `startup`.
4. Do not decode images in `on_*` for rows that are not on screen.
