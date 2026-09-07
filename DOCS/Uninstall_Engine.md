# Uninstall Engine

An advanced uninstallation engine has been added to the project, designed to abstract away the complexity of `pacman` commands and provide a simplified, user-friendly interface for non-technical users.

## 1. Graphical User Interface (UI - Slint)
When the user clicks the "Remove" button on the app details page, a popup window (Modal) appears, offering uninstallation options in very simple terms rather than terminal commands:
- **Basic Uninstall**: Uninstalls the program only (`pacman -R`).
- **Uninstall and Reset**: Uninstalls the program and deletes its configuration files to avoid leaving `.pacsave` files behind (`pacman -Rn`).
- **Uninstall and Clean Shared Files**: Uninstalls the program along with unused dependencies (`pacman -Rs`).
- **Force Uninstall**: Forces the uninstallation, ignoring broken dependencies for other programs (`pacman -Rdd`).
- **Complete Uninstall**: A complete uninstallation (Program + Dependencies + Configuration files) (`pacman -Rns`).

The UI passes the selected command (as a String, e.g., `-R` or `-Rns`) to the C++ backend.

## 2. Backend (C++)
The function `uninstall(const QString &pkgName, const QString &mode)` has been added to the `InstallManager` class.
- This function uses `QProcess` to execute the command `pkexec pacman <mode> --noconfirm <pkg>`.
- The function runs asynchronously and updates the UI state (`is_uninstalling`) to prevent the user from performing overlapping operations.
- The Package Model is automatically updated upon successful execution to reflect that the application is no longer installed (`cur.installed = false`).
