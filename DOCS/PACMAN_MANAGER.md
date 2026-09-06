# PacmanManager

Files: `include/pacmanmanager.h`, `src/pacmanmanager.cpp`

`PacmanManager` is the read-only query layer: it never mutates system state, only asks `pacman` questions. All three of its operations run off the UI thread via `QtConcurrent::run` + `QFutureWatcher`, so the UI never blocks waiting on a `pacman` subprocess.

## Public API

```cpp
void fetchDefaults();                    // -> resultsReady(QVector<Package>)
void search(const QString &query);       // -> resultsReady(QVector<Package>)
void fetchDetails(const QString &pkg);   // -> detailsReady(PackageDetails)

static const QStringList &defaultApps(); // curated home-grid list
static QString normalize(const QString &s);
```

## 1. `fetchDefaults()` / `runDefaults()`

Populates the home grid from a hardcoded curated list (`defaultApps()` — firefox, chromium, vlc, gimp, etc.).

**How installed-status is determined:** a single `pacman -Q <name1> <name2> ...` call, batching *all* curated app names into one invocation (rather than one call per app) to keep it fast. Output lines are split on whitespace; the first token of each line is the installed package name, collected into a `QSet<QString>` for O(1) membership checks.

```cpp
QProcess proc;
proc.start("pacman", {"-Q", "firefox", "chromium", ...});
proc.waitForFinished(5000);  // 5s timeout, then kill()
```

Every curated app becomes a `Package` with `repo = "extra"` and `version = "latest"` — **these are placeholder values**, not queried from the sync DB, since the goal of this call is just fast installed/not-installed status for the grid. Real version/repo/size info is fetched lazily per-package in `fetchDetails()`.

> **Timeout handling:** if `pacman -Q` doesn't finish in 5 seconds, the process is force-killed rather than left to hang indefinitely. This is a recurring pattern in this file — every blocking `QProcess::waitForFinished()` call has an explicit timeout and kill fallback.

## 2. `search(query)` / `runSearch(query)`

Runs `pacman -Ss <query words>` (an 8s timeout) and parses pacman's two-line-per-result search output format:

```
extra/firefox 128.0-1 [installed]
    Fast, private and secure web browser
```

Parsing logic:
- A line **not** starting with a space begins a new result: split on whitespace, the first token is `repo/name`, the second is the version, and the presence of the literal substring `"[installed]"` anywhere on the line sets `installed = true`.
- A line starting with 4 spaces is the description continuation for the *current* result.
- A `flush()` helper commits the current result to the output vector when a new result starts (or at EOF) — but **only if** `PacmanManager::normalize(current.name)` contains `normalize(query)`.

### Why the extra normalize-and-filter step?

`pacman -Ss` already does substring matching against names *and* descriptions, so a query can match a result whose *name* doesn't actually contain the query text (e.g. it matched only in the description). The `normalize()`-based post-filter narrows results down to ones where the **package name itself** is a case/separator-insensitive match, which produces more relevant, less noisy search results in a small grid UI. `normalize()` strips spaces, dashes, underscores, and dots, and lowercases everything, so `"vs-code"`, `"vs_code"`, and `"VS Code"` are all treated the same for matching purposes.

There's also a hard cap of **60 results** (`pkgs.size() < 60`) to keep the grid from becoming huge on broad queries.

Passing an empty/whitespace-only query to `search()` redirects to `fetchDefaults()` instead of hitting `pacman -Ss` with nothing.

## 3. `fetchDetails(pkgName)` / `runFetchDetails(pkgName)`

The most involved method in the file — this is what powers the "What you'll download" card, the dependency list, and the size numbers used to weight the install progress bar. It runs several `pacman` subprocess calls in sequence, entirely on a worker thread:

### Step 1 — Basic info about the target package

```
pacman -Si <pkg>     # sync DB info (repo package)
```
If that returns empty output (e.g. an AUR/foreign package that's already installed and thus absent from any sync DB), it falls back to:
```
pacman -Qi <pkg>     # local DB info
```
Either output is parsed into a `QMap<QString, QString>` of field → value (handling pacman's info-block format, where continuation lines start with two spaces). `Installed Size` becomes `details.appSizeBytes` via `parseSize()`.

A local `inSyncDb` bool records whether the sync-DB path succeeded — this gates Step 2, since dependency-transaction planning only makes sense for a package that's actually installable from a sync repo.

### Step 2 — Ask pacman's real resolver for the transaction plan

```
pacman -Sp --print-format "%n|%s" <pkg>
```

`-Sp` performs pacman's full dependency resolution — exactly as `pacman -S <pkg>` would — but only *prints* the plan (package names + download size) instead of downloading/installing. This is the load-bearing call of the whole method: **the UI's numbers come from pacman's actual resolver, not a hand-rolled dependency walk.**

Output is parsed into:
- `plannedNames` — every package name in the transaction (target + all dependencies)
- `plannedDownloadBytes` — download size per name, straight from `%s`

Given `plannedNames`, two more batched calls fill in the rest:

```
pacman -Q <plannedNames...>     # which of these are ALREADY installed?
pacman -Si <plannedNames...>    # Installed Size for EACH planned package
```

The `-Si` output here is multi-package, so it's split on blank lines (`"\n\n"`) into per-package info blocks and parsed the same field-map way as Step 1.

### Step 3 — Classify and accumulate

For every planned package name:

```cpp
details.totalDownloadBytes += alreadyInstalled ? 0 : downloadSize;
details.totalInstalledBytes += installedSize;
```

- If `name == pkgName` (the target itself) → skip (already counted in `appSizeBytes`).
- Else, build a `PackageDependency` and route it into `installedDeps` or `newDeps` depending on whether `pacman -Q` found it locally, accumulating `installedDepsBytes` / `newDepsBytes` respectively.

Finally:

```cpp
details.netUpgradeBytes = details.totalInstalledBytes;
```

For a fresh install (no existing version of the target already on the system, which is the only case Tux Store currently drives an install for), the net upgrade size equals the full installed footprint of everything newly added — there's no "replace an older version" delta to subtract here.

### Dependency ordering

```cpp
details.dependencies = installedDeps;
details.dependencies += newDeps;
```

Already-installed dependencies are listed **first**, followed by new ones — this ordering is intentional so the UI can put a visual divider or simply let the "already have this" items sit at the top of the list.

### `parseSize(sizeStr)`

Parses pacman's human-readable size strings (`"12.34 MiB"`, `"512 B"`, etc.) back into raw bytes. Recognizes `B`, `KiB`, `MiB`, `GiB` (case-insensitive); anything unrecognized falls through to treating the numeric part as raw bytes.

## Timeouts Used in This File

| Call | Timeout |
|---|---|
| `pacman -Q` (defaults) | 5s |
| `pacman -Ss` (search) | 8s |
| `pacman -Si` / `-Qi` (single target) | 5s |
| `pacman -Sp --print-format` (transaction plan) | 15s |
| `pacman -Q` (planned names) | 5s |
| `pacman -Si` (planned names, batched) | 15s |

Dependency resolution and batched `-Si` calls get the longest timeouts since they can touch many packages and may need to sync/read larger sync databases.

## Logging

Uses the `logPacman` category (see [LOGGING.md](LOGGING.md)). Each method logs entry parameters, an `QElapsedTimer`-measured duration, and a result-count summary — useful for diagnosing slow searches or unexpectedly-timing-out queries in the field.
