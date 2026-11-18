# Smart Downgrade Handling

Files: `crates/tux-abi/src/message.rs`, `crates/tux-pacman/src/queries.rs`,
`crates/tux-libalpm/src/{direct,lib,libalpm/query,libalpm/transaction}.rs`,
`crates/tux-search/src/lib.rs`, `crates/tux-install/src/lib.rs`,
`crates/tux-ui/src/{state,convert,app}.rs`,
`crates/tux-ui/ui/{types,components,main}.slint`

Before a system update, Tux Store checks whether an installed package has a
**newer local version than the version in its sync repository**. A normal
`pacman -Syu` keeps such a package and prints a warning; `pacman -Syuu`
replaces it with the repository version. The store asks the user which of the
two behaviours they want, or lets them pick only some packages.

This page covers the whole flow: detection, messages, dialog, operations and
the two engines.

## Detection

The result is one [`DowngradeEntry`](PACKAGE_MODEL.md#others) per package:

```rust
pub struct DowngradeEntry {
    pub name: String,
    pub repo: String,          // repository that still carries the older version
    pub local_version: String,
    pub repo_version: String,
}
```

Entries are sorted by package name. Packages that are not in any sync
repository are ignored. Version comparison uses `alpm::vercmp`, so epochs and
`pkgrel` compare exactly like pacman compares them.

### Direct engine

`tux_libalpm::direct::downgrades()`:

1. `tux_pacman::queries::sync_versions()` runs one `pacman -Sl` (15 s timeout)
   and parses `repo name version` lines. The **first** repository carrying a
   name wins, matching pacman's own resolution order.
2. `tux_pacman::localdb::read_all()` reads the installed versions straight from
   `/var/lib/pacman/local` (no `pacman -Q`).
3. `alpm::vercmp(local, repo) == Ordering::Greater` selects the entries.

### Libalpm engine

`tux_libalpm::libalpm::query::downgrades()` opens the libalpm handle, walks the
local database, finds each package in the sync databases with the existing
`sync_package()` helper (first sync database wins), and applies the same
`vercmp` test. `repo` comes from the sync package's database.

### Dispatcher

`tux_libalpm::downgrades()` chooses `direct::downgrades()` or
`libalpm::downgrades()` from the active engine, just like `updates()` and
`search()`. Detection is read-only and never touches the system.

## Message flow

The UI never starts an update before this check finishes.

```
UI                       search                         install
 │ DowngradeCheckRequested │                              │
 ├────────────────────────►│  worker thread               │
 │                         │  tux_libalpm::downgrades()   │
 │ DowngradeCheckReady     │                              │
 │◄────────────────────────┤                              │
 │                                                         │
 │ no candidates / error → SystemUpgradeRequested ────────►│
 │ Continue             → SystemUpgradeRequested ────────►│
 │ Downgrade all        → SystemDowngradeRequested ──────►│
 │ Downgrade selected   → DowngradeRequested{packages} ──►│
 │                         │                              │
 │◄──────────────────────── OperationStarted/Output/... ───┤
```

`DowngradeCheckReady { packages, error }` is sent even when detection fails;
`error` carries the reason and `packages` is empty.

`SearchModule::downgrades()` runs on a short-lived worker thread so the bus
handler never blocks. `InstallModule` accepts the three update requests and
turns them into `Operation` values.

## UI flow

`State::upgrade_all()` (the *Update all* button) does not publish
`SystemUpgradeRequested` directly:

1. It refuses to run while another operation is active or a check is already in
   flight (`downgrade_check_pending`).
2. It sets the Updates status to `Checking installed packages…` and publishes
   `DowngradeCheckRequested`.
3. `State::on_downgrade_check()` handles the answer:
   - **No error and no packages** — start `SystemUpgradeRequested` immediately;
     there is nothing to ask.
   - **Error** — log the failure, show the message in the Updates status, then
     start `SystemUpgradeRequested` anyway. Detection is best-effort and must
     never block updates.
   - **Packages** — fill `downgrade_rows`, mark every row as checked, reset
     `downgrade_selecting` to `false`, set `downgrade_selected_count`, and open
     the dialog.

`main.slint` exposes `downgrade-open`, `downgrade-selecting`,
`downgrade-packages` and `downgrade-selected-count`; `app.rs` forwards the
five dialog callbacks to the matching `State` methods.

The `DowngradeDialog` (in `components.slint`, instantiated by `main.slint`)
has two views:

| View | Content |
|---|---|
| choice | three plain-language options: keep the newer versions and update normally, downgrade all, or choose packages |
| selecting | a scrollable check-box list of `UiDowngrade` rows, each showing name, `local → repo` versions and repository |

Callbacks and their effect:

| Callback | Rust method | Result |
|---|---|---|
| `continue-clicked` | `downgrade_continue()` | close dialog, `SystemUpgradeRequested` |
| `all-clicked` | `downgrade_all()` | close dialog, `SystemDowngradeRequested` |
| `select-clicked` | sets `downgrade_selecting = true` | show the check-box list |
| `toggle(i)` | `downgrade_toggle(i)` | flip one row and update the selected count |
| `selected-clicked` | `downgrade_selected()` | close dialog, `DowngradeRequested { packages }` |
| `cancel-clicked` | `downgrade_cancel()` | close dialog, clear the Updates status, start nothing |

All rows start checked. *Downgrade selected* stays disabled while the count is
zero. Selected names are read from the Rust-side `downgrade_checked` vector,
which is index-aligned with `downgrade_rows`, so the list is never read back
from Slint.

`UiDowngrade` is the Slint mirror of `DowngradeEntry` plus `checked`:

```slint
UiDowngrade { name, repo, local-version, repo-version, checked }
```

## Operations

| Operation | Direct engine | Libalpm engine |
|---|---|---|
| `SystemUpgrade` | `pacman -Syu --noconfirm --color=never` | `sync_sysupgrade(false)` |
| `SystemDowngrade` | `pacman -Syuu --noconfirm --color=never` | `sync_sysupgrade(true)` |
| `Downgrade { packages }` | `pacman -S --noconfirm --color=never -- <names>` | add only those sync packages to the transaction |

The selected case deliberately uses explicit targets instead of `-Syuu`, so
packages the user did not tick keep their newer version. The direct command
still resolves dependencies normally; the libalpm transaction does the same
through `trans_prepare()` after adding the selected sync packages.

Validation happens in `tux-install` before a transaction starts:

- `Downgrade { packages }` must be non-empty and every name must pass
  `is_valid_package_name`.
- Libalpm repeats the empty-list check and reports a missing repository package
  by name.

The direct engine runs all three operations with the `Upgrade` progress kind,
so they share the existing parser (which already recognises pacman's
`downgrading <pkg>` lines). Libalpm uses its own progress callback. When an
operation succeeds, the UI requests the update list again and refreshes the
Installed tab if it is open, like a normal `-Syu`.

## Failure and safety behaviour

- A failed detection is logged and the update proceeds as `-Syu`.
- Only one transaction can run at a time; the installer's existing busy flag
  still rejects a second request.
- A UI check already in flight ignores another *Update all* click.
- Cancelling the dialog does not change the system.
- An empty selection does nothing (the button is disabled and the Rust method
  returns early).
- The detection itself is read-only.

## Tests

- `crates/tux-pacman/src/queries.rs` —
  `sync_versions_parse_keeps_first_repository` checks the `-Sl` parser and the
  first-repository rule.
- The version comparison and engine paths are exercised through the normal
  `cargo test --workspace` build; the machine-dependent database queries are
  read-only and have no fixture.

See [MESSAGE_BUS.md](MESSAGE_BUS.md), [PACMAN_MANAGER.md](PACMAN_MANAGER.md),
[INSTALL_MANAGER.md](INSTALL_MANAGER.md) and [UI_LAYER.md](UI_LAYER.md) for the
surrounding machinery.
