# Home Feed & Categorization

The home page has been completely redesigned to display applications in horizontally scrolling rows (categories), providing a modern app store experience.

## 1. Data Engine (Backend - C++)
A large list of default applications is fetched via `PacmanManager::defaultApps()`. Instead of pushing all of them into a single monolithic model, `main.cpp` filters these applications as soon as they are received and distributes them across multiple independent VectorModels:
- `browsersModel`: For web browsers (Firefox, Chromium, Brave, ...).
- `designModel`: For design and multimedia software (Blender, GIMP, Kdenlive, ...).
- `officeModel`: For productivity and office suites (LibreOffice, OnlyOffice, ...).
- `devModel`: For development tools (VS Code, Python, GCC, Rust, ...).
- `communicationModel`: For messaging and VoIP apps (Telegram, Discord, Signal, ...).
- `forYouModel`: For general and miscellaneous apps (Steam, qBittorrent, ...).
- `pkgModel`: Specifically used for comprehensive search results.

These models are then passed to the Slint UI via dedicated properties (e.g., `set_browsers`, `set_dev`, etc.).

## 2. Graphical User Interface (UI - Slint)
- A custom component named `AppRow` was created.
- `AppRow` accepts a category title (e.g., "Browsers") and a list of applications (`[UiPackage]`).
- The component contains a horizontal `Flickable` area with a custom-built scrollbar that responds smoothly to both mouse dragging and touch.
- If the user types into the top search bar, the `AppRow` sections immediately disappear, replaced by a responsive Grid view showing the search results. Once the search query is cleared, the store gracefully returns to the categorized row layout.
