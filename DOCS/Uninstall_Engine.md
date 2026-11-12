# Uninstall Engine

Removal hides pacman's flags behind five plain-language choices.

## UI

The **Remove** button on an installed package opens a dialog:

| Option | pacman | `RemoveMode` |
|---|---|---|
| Basic Uninstall — keeps settings and shared files | `-R` | `Basic` |
| Uninstall and Reset — also deletes settings (no `.pacsave`) | `-Rn` | `Reset` |
| Uninstall and Clean Shared Files — also unused dependencies | `-Rs` | `Clean` |
| Force Uninstall (Advanced) — ignores broken dependencies | `-Rdd` | `Force` |
| Complete Uninstall (Recommended) — program + dependencies + settings | `-Rns` | `Complete` |

The dialog is the `RemoveOption` component; *Force* is outlined red, *Complete* is outlined green and emphasised.

## Flow

1. Slint calls `remove-clicked("-Rns")`.
2. Rust maps the string with `RemoveMode::from_flag`; an unknown string is ignored, so the backend can never forward an arbitrary argument to a root command.
3. `State::begin_operation` switches `current-install` to `{phase: Running, kind: Remove, target: <pkg>}` and refuses if something is already running.
4. `RemoveRequested{name, mode}` → `tux-install` runs `pacman <flag> --noconfirm --color=never -- <pkg>` through `pkexec` + `script` (see [INSTALL_MANAGER.md](INSTALL_MANAGER.md)).
5. Progress uses the removal bands (dependency check → `(n/m) removing` → hooks).
6. On success the UI sets `installed = false` for that package in every list and reloads the Installed tab if it is open; search drops its caches.

The progress card shows "Uninstalling…", "Uninstalled successfully" or "Uninstallation failed" from `kind == remove`.
