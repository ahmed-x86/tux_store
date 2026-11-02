# Message Bus

File: `crates/tux-abi/src/message.rs`

A single enum, `Message`, is the whole vocabulary. On the wire it is JSON with an internal tag (`{"type":"SearchRequested","query":"vlc"}`).

## Rules

- `Bus::publish(&msg)` delivers to **every** module, including the sender.
- Delivery is synchronous on the publisher's thread: handlers must not block.
- A module ignores messages it does not care about, and ignores messages it cannot decode (a module built against an older enum simply skips new variants).
- Naming: `XxxRequested` goes *towards* a backend; `XxxReady`, `Operation*` and `Icon*` come back.

## Reference

| Message | Sent by | Handled by | Meaning |
|---|---|---|---|
| `UiReady` | ui | thumbnail | window exists; warm up the icon theme index |
| `HomeRequested` | ui | search | build the curated sections |
| `HomeReady{sections}` | search | ui | one `Section` per catalog section |
| `SearchRequested{query}` | ui | search | run a search |
| `SearchResults{query, packages}` | search | ui | echoes `query` so stale answers can be dropped |
| `DetailsRequested{name}` | ui | search | plan + sizes for one package |
| `DetailsReady{name, details, special}` | search | ui, **install** | plan, plus add-on info; installer caches sizes |
| `ExactRequested{name}` | ui | search | look up one package by exact name |
| `ExactReady{package}` | search | ui | the package (opens its page) |
| `AddonsRequested{package}` | ui | search | list the package's add-ons |
| `AddonsReady{package, packages}` | search | ui | add-ons with real repo/version data |
| `InstalledRequested` / `InstalledReady{packages}` | ui / search | search / ui | explicitly installed packages |
| `UpdatesRequested` / `UpdatesReady{updates, error}` | ui / search | search / ui | pending upgrades |
| `CoversRequested` / `CoversReady{covers}` | ui / thumbnail | thumbnail / ui | home banner images |
| `IconRequested{name, size}` | ui | thumbnail | resolve an icon (once per package) |
| `IconReady{name, path}` / `IconFailed{name}` | thumbnail | ui | result |
| `ClearIconCache` / `IconCacheCleared{removed}` | ui / thumbnail | thumbnail / ui | settings button |
| `InstallRequested{name}` | ui | install | `pacman -S` |
| `RemoveRequested{name, mode}` | ui | install | `pacman -R…` (see [Uninstall_Engine.md](Uninstall_Engine.md)) |
| `SystemUpgradeRequested` | ui | install | `pacman -Syu` |
| `OperationStarted{op}` | install | ui | transaction began |
| `OperationOutput{text}` | install | ui | raw output chunk |
| `OperationProgress{fraction}` | install | ui | 0..0.98, then 1.0 on success |
| `OperationFinished{op, success, exit_code}` | install | ui, **search** | search drops its caches |

## Adding a message

1. Add the variant to `Message` (struct variants or unit variants only — the internal tag does not support newtype variants of primitives).
2. Handle it in the receiving module's `on_message`; nothing else needs to change.
3. If you add a field to an existing variant, give it `#[serde(default)]` so older modules still decode it.
