# Top Navigation Tabs

A floating segmented control under the header, visible on the main screen and hidden on details, add-ons and settings pages.

## State

`MainWindow.active-tab` (int):

| Value | Tab | Content |
|---|---|---|
| 0 | Home | shelves, or the search grid while the search box has text |
| 1 | Updates | pending upgrades + *Update all* |
| 2 | Installed | explicitly installed packages with a filter box |

Clicking a tab sets `active-tab` and calls `tab-changed(index)`; Rust then does:
- **1** → `UpdatesRequested` (loading flag on)
- **2** → `InstalledRequested` (loading flag on)
- **0** → nothing (the Home data is already there)

Typing in the search box or pressing the home button always switches to tab 0.

## Updates tab

- Header: *"N updates available"* / *"Your system is up to date"*, **Check again**, **Update all**.
- List rows: `name  old → new`.
- *Update all* runs `pacman -Syu` through `tux-install` and shows the shared progress card (`target = "@upgrade"`) with the console button. When it succeeds the list is re-checked.
- Update list source: `checkupdates` when available (safe, no root), otherwise `pacman -Qu`. Errors appear as a status line.

## Installed tab

- Packages with `%REASON% = explicit` from the local database, labelled with their repo (or `aur` for foreign packages).
- Filter matches the normalised name or the description; results are paginated (60, then 60 more).
- After a successful install/remove while this tab is open, the list reloads.

## Styling

Each `TabButton` has two gradient colours. The active tab shows its gradient plus a `drop-shadow` glow and grows to 1.5× width (animated through a `grow` property bound to `horizontal-stretch`); hover shows a faded gradient.
