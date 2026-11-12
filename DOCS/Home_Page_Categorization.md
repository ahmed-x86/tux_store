# Home Feed & Categorization

The Home tab shows horizontally scrolling shelves, one per category — a data-driven version of the original hard-coded model-per-category design.

## Data: `data/categories.json`

```json
{ "sections": [
  { "id": "browsers", "title": "Browsers", "packages": ["firefox", "chromium", "…"] }
] }
```

Order in the file is order on screen. Sections shipped: For You, Browsers, Communication, Design & Multimedia, Office & Productivity, Development, Utilities.

To add a category, add an object — no code changes. To add an app, add its pacman name to a `packages` list.

## Backend

`tux-search`:
1. `Catalog::all_package_names()` — every curated name once, in display order.
2. **One** `pacman -Si` for the whole list (`packages_by_name`). Names pacman does not know are shown as `aur` stubs instead of being hidden.
3. The result is cached as `Vec<Section>` and published as `HomeReady`. Later requests reuse the cache and only refresh the *installed* flags from the local database; the cache is dropped after an install/remove.

## UI

`HomeTab` iterates the section model — `for section[i] in sections : AppRow { … }`. `AppRow` is a titled `Flickable` of `AppCard`s with the shared `HScrollBar` (drag or touch). The row index feeds the placeholder accent colour so neighbouring rows differ.

While the search box has text, the shelves are replaced by the paginated search grid; clearing it brings the shelves back.

The banner above the shelves is the cover carousel (`data/images/cover/<app>/*`): a random cover first, auto-advance every 8 s (paused on hover), arrows to step, click to open that app's page (`codium` maps to `vscodium`). Only the visible image is decoded.
