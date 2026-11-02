# Install Manager (`tux-install`)

Files: `crates/tux-install/src/{lib,stream}.rs`, `crates/tux-pacman/src/progress.rs`

`tux-install` is the only module that **changes the system**. It runs `pacman -S`, `pacman -R…` and `pacman -Syu`, streams their raw output, and derives a monotonic progress fraction.

## Messages

Handles `InstallRequested`, `RemoveRequested`, `SystemUpgradeRequested`, and overhears `DetailsReady`.
Emits `OperationStarted`, `OperationOutput`, `OperationProgress`, `OperationFinished`.

```
OperationStarted
OperationOutput …            × many
OperationProgress 0.05 … 0.96
OperationOutput …            hooks etc.
OperationProgress 1.0        only on exit code 0
OperationFinished{success, exit_code}
```

## Elevation and the pseudo-terminal

```
root:      script -qec "env LC_ALL=C pacman … " /dev/null
otherwise: pkexec script -qec "env LC_ALL=C pacman … " /dev/null
```

- **`pkexec`** brings up the native Polkit dialog; the app never handles credentials.
- **`script`** gives pacman a pty. Without a tty glibc block-buffers stdout and all output would arrive at the very end. Its stdin pipe is kept open (never written) so `script` does not see EOF and tear the pty down.
- **`env LC_ALL=C`** is applied *inside* the elevated command because `pkexec` resets the environment; the progress parser relies on English phrases.
- `--noconfirm` is mandatory (the app cannot answer prompts; the details page is the confirmation step). `--color=never` keeps escape codes out of the parser. The target is always passed after `--`.
- All arguments are shell-quoted, and names are checked with `is_valid_package_name` first.

Only one transaction runs at a time (`busy` flag); a second request is rejected with an `OperationFinished{success:false}` and an explanatory line of output. The flag is cleared *before* `OperationFinished` is published so the UI can start the next operation immediately.

## Where the sizes come from

When `DetailsReady` passes by, the installer stores `{package → installed size}` for the target and every **not-yet-installed** dependency (last 16 plans kept). On `InstallRequested` that map weights the download phase. The UI never has to hand sizes over. Removal and system upgrade have no map and use counters instead.

## Output pipeline (`pump` + `stream.rs`)

1. `Utf8Stream` re-assembles characters split across `read()` boundaries.
2. The complete text goes out unchanged as `OperationOutput`.
3. For stdout, `LineSplitter` cuts on `\n` **and** `\r` (pacman redraws bars with `\r`) and every line goes to the `ProgressTracker`. stderr is only forwarded.

## `ProgressTracker`

The tracker follows pacman's real phases, which are, in order:

| Phase | Band | Signal |
|---|---|---|
| resolve / conflicts | 0 – 5 % | `resolving dependencies`, `looking for conflicting packages` |
| download | 5 – 50 % | percent bars, weighted by installed size (or equal weights from `Packages (N)` when sizes are unknown, e.g. system upgrade) |
| verification | 50 – 70 % | `checking keys`, `package integrity`, `loading package files`, `file conflicts`, `disk space`, `processing package changes` |
| install | 70 – 96 % | `(n/m) installing\|upgrading\|reinstalling\|downgrading <pkg>` → `(n-1)/m` |
| hooks | 96 % | `running post-transaction hooks` |

Removal uses `checking dependencies` (15 %), `(n/m) removing` (30 – 90 %) and hooks (92 %).

Properties:
- **Monotonic.** Floors only rise, download credit only grows, step counters only advance.
- **Capped at 98 %.** pacman runs hooks (icon caches, `mkinitcpio` …) after the last "installing" line; only the real exit may produce `1.0`.
- A package file name is matched to a known package by the **longest** name that prefixes it (`name-` or exact), because names and versions both contain dashes. Database-sync bars during `-Syu` are ignored because download credit only starts after the `Packages (N)` line.
- Escape sequences are stripped before matching.

## Limits

- No cancel, retry or resume: a failed transaction is reported and must be started again.
- `pkexec` needs a running Polkit agent; if there is none, its message appears in the console and the operation fails.
