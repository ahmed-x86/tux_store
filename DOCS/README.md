# Tux Store Documentation

Start with [ARCHITECTURE.md](ARCHITECTURE.md), then read the pages that match
what you are changing.

## Core

| Document | What it covers |
|---|---|
| [ARCHITECTURE.md](ARCHITECTURE.md) | host executable, `.so` modules, message bus, threading, Rust↔Slint boundary |
| [MESSAGE_BUS.md](MESSAGE_BUS.md) | every message, who sends it and who reacts |
| [PACKAGE_MODEL.md](PACKAGE_MODEL.md) | shared types in `tux-abi` and text helpers |
| [PACMAN_MANAGER.md](PACMAN_MANAGER.md) | pacman queries, search, details, installed and update lists |
| [TAXONOMY.md](TAXONOMY.md) | side menu: repositories, groups/families, AppStream categories, add-on category metadata |
| [HIDDEN_PACKAGES.md](HIDDEN_PACKAGES.md) | `hidden_packages.json` and every surface it filters |

## UI and behaviour

| Document | What it covers |
|---|---|
| [UI_LAYER.md](UI_LAYER.md) | Slint components and UI state |
| [Tab_Navigation.md](Tab_Navigation.md) | Home / Updates / Installed tabs |
| [Home_Page_Categorization.md](Home_Page_Categorization.md) | data-driven Home shelves |
| [SCREENSHOTS.md](SCREENSHOTS.md) | screenshot slider and `data/screenshots/` |
| [ICON_FETCHER.md](ICON_FETCHER.md) | icon pipeline and covers |
| [INSTALL_MANAGER.md](INSTALL_MANAGER.md) | install transactions and progress |
| [Uninstall_Engine.md](Uninstall_Engine.md) | the five removal modes |
| [LOGGING.md](LOGGING.md) | log sinks |

## Content

| Document | What it covers |
|---|---|
| [ADDONS_SYSTEM.md](ADDONS_SYSTEM.md) | add-ons / language packs attached to a parent package |
| [SCRIPTS_SYSTEM.md](SCRIPTS_SYSTEM.md) ([عربي](SCRIPTS_SYSTEM_AR.md)) | interactive add-on packages: JSON format, `category` / `categories`, install/uninstall, receipts |

## Project

| Document | What it covers |
|---|---|
| [CONTRIBUTING.md](CONTRIBUTING.md) | build, conventions, where to add things |
| [RELEASING.md](RELEASING.md) | release workflow and artifacts |
