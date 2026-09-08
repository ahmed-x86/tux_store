# Addons & Language Packs System

Tux Store supports a "Special Cases" configuration system for applications that have an ecosystem of official add-ons, extensions, or language packs (e.g., LibreOffice). 

Rather than hardcoding these relationships into the C++ backend or the UI, Tux Store reads from a dedicated directory of JSON files (`special_case_packages/`).

## Architecture

### 1. JSON Configuration Files
Located in the `special_case_packages/` directory at the root of the project, each JSON file maps a primary package to its respective addons.

**Example `libreoffice-fresh.json`:**
```json
{
  "package": "libreoffice-fresh",
  "language_packs": {
    "Arabic": "libreoffice-fresh-ar",
    "French": "libreoffice-fresh-fr"
  }
}
```
*Note: The key can be either `language_packs` or `addons`. The UI will dynamically adjust the section title based on this.*

### 2. Startup Parsing (`main.cpp`)
At application startup, `main.cpp` scans the `special_case_packages/` directory for `.json` files.
It populates two in-memory lookup maps:
- `packageAddons`: Maps the parent package (e.g., `libreoffice-fresh`) to a struct containing all its add-ons.
- `addonToPackage`: A reverse lookup map linking every add-on (e.g., `libreoffice-fresh-ar`) back to its parent package.

### 3. UI Integration (`ui/main.slint`)
When `PacmanManager` fetches details for a package, `main.cpp` checks these maps.
- **Viewing the Parent**: If the user views the parent package, a localized `UiSpecialCase` struct is built and pushed to the UI, rendering a list of clickable add-ons right above the dependencies section.
- **Viewing an Addon**: If the user views an add-on directly, the UI renders an info banner: `ℹ️ This package is an addon for libreoffice-fresh`, with a clickable link to navigate instantly to the parent package.

### 4. Direct Navigation & CLI Support
When an add-on or parent link is clicked in the UI, it fires the `addon_clicked(pkgName)` callback.
- **`PacmanManager::getPackageExact`**: The C++ backend launches a synchronous query via `QtConcurrent` to fetch the target package's details (`pacman -Si`) and format it into a `UiPackage` without needing a user-initiated search.
- **`IconFetcher::request`**: Simultaneously, an asynchronous icon fetch request is queued for the target package.
- **CLI Arg**: The user can bypass the UI and instantly open any package details view on startup by running `./tuxstore openpackage <packagename>`. This leverages the exact same navigation pipeline.
