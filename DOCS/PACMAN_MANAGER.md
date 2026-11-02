# Pacman Layer (`tux-pacman` + `tux-search`)

Files: `crates/tux-pacman/src/{runner,info,localdb,queries}.rs`, `crates/tux-search/src/{lib,catalog}.rs`

`tux-pacman` is a plain library (no bus, no FFI) so it can be unit-tested; `tux-search` is the module that turns bus requests into calls on it. Everything here is **read-only**: it only asks pacman questions.

## `runner.rs`

`run(program, args, timeout) -> Captured { stdout, stderr, code, timed_out }`

- Forces `LC_ALL=C` so output is always English and parseable.
- stdout and stderr are drained on separate threads, so a chatty process can never deadlock on a full pipe.
- The child is polled with an adaptive sleep (1 ms doubling to 20 ms) and **killed when the timeout expires**.
- `in_path(name)` checks `$PATH` for an executable.

## `localdb.rs` — the local database, read directly

`/var/lib/pacman/local/<name>-<version>-<release>/desc` (override with `TUX_PACMAN_DBPATH`).

- `installed_names()` is one `readdir`; the package name is everything before the last two dashes of the directory name.
- `read_all()` / `read_one()` parse `desc` for `%VERSION%`, `%DESC%`, `%SIZE%` and `%REASON%` (`1` = installed as a dependency, absent = explicit).

This replaces every `pacman -Q` call of the C++ version.

## `info.rs`

`parse_info()` splits `pacman -Si/-Qi` output into one `key → value` map per package. Indented continuation lines are joined with a space. `parse_size("12.34 MiB")` returns bytes (`B`, `KiB`, `MiB`, `GiB`, `TiB`).

## `queries.rs`

| Function | pacman calls | Notes |
|---|---|---|
| `packages_by_name(names)` | one `-Si -- …` | one result per requested name, in order; unknown names become an `aur` stub (or the local data when installed) |
| `exact(name)` | via the above | |
| `search(query, limit)` | one `-Ss -- <words>` | see below |
| `details(name)` | `-Sp --print-format "%n\|%s"`, then one `-Si` for the planned packages | see below |
| `installed_packages()` | one `-Sl` (repo labels) + local db | explicit packages only, sorted |
| `updates()` | `checkupdates`, or `pacman -Qu` when pacman-contrib is missing | |

Timeouts: info 10 s, plan 20 s, search 8 s, `-Sl` 15 s, `checkupdates` 60 s.

### Search

- Each word is escaped for pacman's POSIX regex engine (`c++` no longer breaks), and `--` stops a query like `-x` from being read as an option.
- A result is kept only if the **normalised name** (lower-case, without spaces, `-`, `_`, `.`) contains the normalised query — the same rule as the C++ version.
- Results are de-duplicated and ranked: exact match, then prefix match, then shorter names first. The cap is **200** (the C++ version cut at 60 *before* ranking); the UI paginates.
- The `installed` flag comes from the local database, not from `[installed]` in the output.

### Details

1. `pacman -Sp --print-format "%n|%s" -- <pkg>` runs pacman's real resolver and returns the plan (names + download sizes).
2. If the plan is empty (foreign/AUR package) the details fall back to the size recorded in the local db and `plan_ok = false`.
3. One `pacman -Si -- <all planned>` supplies the installed size of every planned package.
4. For each planned package: add to `total_installed`; if it is **not** installed also add to `total_download` and `net_upgrade`; the target itself becomes `app_size`; other packages become dependencies, split into `installed_deps` / `new_deps`.
5. Dependencies are sorted installed-first (stable).

That is 2 processes instead of the C++ version's 4 (`-Si`, `-Sp`, `-Q`, `-Si`).

### Updates

`checkupdates` (from `pacman-contrib`) syncs a private copy of the databases without root and cannot cause a partial upgrade, so it is preferred. Its exit code 2 means "no updates". The fallback `pacman -Qu` only reports what the last sync already knows (exit 1 = none).

## `tux-search` (the module)

- **Catalog** — see [ADDONS_SYSTEM.md](ADDONS_SYSTEM.md) and [Home_Page_Categorization.md](Home_Page_Categorization.md).
- **One thread per request.** Searches carry a generation number: if a newer search started, the older one does not publish its results.
- **Home cache** — built once with a single `-Si` for the whole curated list; later requests only refresh the installed flags.
- **Details cache** — up to 32 entries, 60 s TTL.
- Both caches are dropped when `OperationFinished` is heard.
