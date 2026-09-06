# Package / Data Model

Files: `include/package.h`, `src/package.cpp`

This module has no Qt-widget or network dependencies — it's pure data structures and small pure functions, shared by `PacmanManager`, `InstallManager`, and `main.cpp`.

## Structs

### `Package`

Represents one browsable/searchable package as shown in the grid.

```cpp
struct Package {
    QString repo;          // e.g. "extra", "core", "aur"
    QString name;          // pacman package name, e.g. "libreoffice-fresh"
    QString version;       // version string, or "latest" for curated defaults
    QString description;   // short description shown on the card / details header
    bool installed = false;
};
```

Produced by `PacmanManager::runDefaults()` and `PacmanManager::runSearch()`.

### `PackageDependency`

One row in the dependency list on the details page.

```cpp
struct PackageDependency {
    QString name;
    long long sizeBytes = 0;   // Installed Size, from `pacman -Si`/`-Qi`
    bool installed = false;    // already present on the system?
};
```

### `PackageDetails`

The full breakdown computed for the details page + install sizing. This is the richest struct in the codebase — see [PACMAN_MANAGER.md](PACMAN_MANAGER.md) for exactly how each field is derived.

```cpp
struct PackageDetails {
    long long appSizeBytes = 0;              // Installed Size of the target package itself
    QVector<PackageDependency> dependencies; // installed-first, then new deps
    long long installedDepsBytes = 0;        // sum of already-installed deps' installed size
    long long newDepsBytes = 0;              // sum of new deps' installed size
    long long downloadBytes = 0;             // == totalDownloadBytes (kept for back-compat)
    long long totalBytes = 0;                // appSizeBytes + installedDepsBytes + newDepsBytes

    // Mirrors pacman's own transaction summary, computed from pacman's real
    // dependency resolution rather than re-derived by us:
    long long totalDownloadBytes = 0;   // sum of Download Size for everything pacman will fetch
    long long totalInstalledBytes = 0;  // sum of Installed Size for the whole transaction
    long long netUpgradeBytes = 0;      // net change to disk usage
};
```

> **Field overlap note:** `downloadBytes` and `totalDownloadBytes` currently hold the same value — `downloadBytes` exists for backward compatibility and should be considered deprecated. New code should read `totalDownloadBytes`.

## Free Functions

### `QString formatSize(long long bytes)`

Formats a byte count as a human-readable string with 2 decimal places, choosing the largest unit that keeps the number ≥ 1:

| Range | Output example |
|---|---|
| < 1024 B | `"512 B"` |
| < 1024 KiB | `"3.42 KiB"` |
| < 1024 MiB | `"128.00 MiB"` |
| ≥ 1024 MiB | `"1.20 GiB"` |

Used everywhere a size is shown in the UI (`main.cpp` when building `UiPackageDetails`).

### `QString prettifyName(const QString &raw)`

Converts a pacman package name into a display-friendly title, by splitting on `-` and capitalizing each segment:

```
"telegram-desktop" -> "Telegram Desktop"
"qbittorrent"       -> "Qbittorrent"
```

This is intentionally simple (no acronym dictionary, e.g. it won't render "vlc" as "VLC") — see [CONTRIBUTING.md](CONTRIBUTING.md) for notes on improving this.

### `QString sanitizeName(const QString &name)`

Iteratively strips known Arch packaging suffixes so a name resembles its "canonical" upstream project name — primarily used by `IconFetcher` to generate better icon-repo candidate names:

```cpp
static const QStringList suffixes = {"-git", "-bin", "-aur", "-patch", "-full", "-stable"};
```

Example: `"foo-bin-git"` → `"foo-bin"` → `"foo"` (applied repeatedly until no suffix matches).

**Note:** this is a generic string transform, not an alias table. Package-specific renaming (e.g. `"neovim"` → `"nvim"`) lives separately in `IconFetcher`'s `aliasFor()`, not here — see [ICON_FETCHER.md](ICON_FETCHER.md).

## Where This Data Comes From

Nothing in `package.h`/`package.cpp` talks to `pacman` directly. All construction of these structs happens in `PacmanManager` (see [PACMAN_MANAGER.md](PACMAN_MANAGER.md)); this module only defines the shape and the small pure helpers.
