# Logging

Files: `include/log.h`, `src/log.cpp`

Tux Store uses Qt's category-based logging (`QLoggingCategory`) rather than ad-hoc `printf`/`qDebug()` calls, so log verbosity can be controlled per-subsystem without recompiling.

## Categories

```cpp
Q_DECLARE_LOGGING_CATEGORY(logApp)      // "tuxstore.app"     — general app/install lifecycle
Q_DECLARE_LOGGING_CATEGORY(logPacman)   // "tuxstore.pacman"  — PacmanManager queries
Q_DECLARE_LOGGING_CATEGORY(logIcon)     // "tuxstore.icon"    — IconFetcher pipeline
Q_DECLARE_LOGGING_CATEGORY(logUi)       // "tuxstore.ui"      — reserved for UI-side logging
```

Usage anywhere in the codebase:

```cpp
#include "log.h"

qCDebug(logIcon) << "fetching" << name;
qCInfo(logPacman) << "runSearch done in" << t.elapsed() << "ms";
qCWarning(logIcon) << "hard timeout, aborting:" << url;
```

> **Note:** `logUi` is declared and initialized but not currently used anywhere in `main.slint` (Slint files don't use Qt logging) or `main.cpp`. It's reserved for future UI-side C++ logging — e.g. if `main.cpp`'s glue code grows complex enough to warrant its own category rather than reusing `logApp`.

## Setup — `installLogHandler()`

Called once, at the very top of a typical `main()` (though note: the current `main.cpp` does **not** call this yet — see the callout below). It does two things:

1. **Installs a custom message handler** (`qInstallMessageHandler`) that formats every log line as:
   ```
   [HH:mm:ss.zzz] LEVEL CATEGORY_NAME           message
   ```
   e.g.
   ```
   [14:32:07.113] INFO  tuxstore.icon    cache dir: /home/user/.cache/tuxstore/icons maxGlobalInFlight: 6
   ```
   Written to `stderr`, flushed immediately after each line (`fflush(stderr)`), and calls `abort()` on `QtFatalMsg` (matching Qt's default fatal-message behavior).

2. **Sets filter rules** via `QLoggingCategory::setFilterRules()`:
   ```cpp
   QLoggingCategory::setFilterRules(
       "tuxstore.*.debug=true\n"
       "qt.*.debug=false\n"
   );
   ```
   This enables debug-level output for **all** `tuxstore.*` categories by default, while suppressing Qt's own internal `qt.*` debug categories (which are otherwise very noisy, e.g. `qt.network.*`).

### ⚠️ Action item: `installLogHandler()` is currently unused

`src/main.cpp` never calls `installLogHandler()`. As shipped, Qt's default message handler and default filter rules apply instead, meaning:
- `tuxstore.*` debug messages are **not** shown by default (Qt's default `debug=false` for custom categories applies).
- The custom `[HH:mm:ss.zzz] LEVEL CATEGORY message` format is not active.

To get the intended logging behavior, add this near the top of `main()` in `src/main.cpp`, before any other logging occurs:

```cpp
int main(int argc, char *argv[])
{
    installLogHandler();
    QGuiApplication app(argc, argv);
    ...
```

This is flagged here so it isn't missed — until it's wired in, debug logs can still be forced on manually via the `QT_LOGGING_RULES` environment variable (see below), but the nicer formatted output requires the custom handler.

## Runtime Control via Environment Variable

Regardless of the code-level default rules, `QT_LOGGING_RULES` can override verbosity per run without a rebuild:

```bash
# Only icon-fetching debug logs:
QT_LOGGING_RULES="tuxstore.icon.debug=true" ./tuxstore

# Everything from Tux Store, nothing from Qt internals:
QT_LOGGING_RULES="tuxstore.*.debug=true;qt.*.debug=false" ./tuxstore

# Quiet — only warnings and above from pacman queries:
QT_LOGGING_RULES="tuxstore.pacman.debug=false" ./tuxstore
```

## What Gets Logged Where

| Category | Typical content |
|---|---|
| `logApp` | Install started/finished lifecycle events in `installmanager.cpp` (`qCInfo(logApp) << "starting install:" ...`, `"install finished, success:" ...`) |
| `logPacman` | Every `PacmanManager` method logs entry, an elapsed-time measurement (`QElapsedTimer`), and a result count — great for diagnosing a slow or timing-out search/details fetch |
| `logIcon` | The most verbose category by design: cache dir on startup, per-job queue depth, per-job start with in-flight counters, every GET with in-flight state, hit/miss/invalid-content per URL with elapsed time, hard-timeout aborts, and exhaustion warnings |
| `logUi` | Currently unused (reserved) |

## Conventions for New Code

- Prefer `qCDebug`/`qCInfo`/`qCWarning` over plain `qDebug`/`qInfo`/`qWarning` so new log lines are filterable by category. Pick the closest existing category (`logPacman` for anything shelling out to pacman for reads, `logApp` for install lifecycle, `logIcon` for icon fetching) rather than introducing a new one unless the subsystem is genuinely distinct.
- Use `qCDebug` for high-frequency/per-request detail (e.g. one line per HTTP request), `qCInfo` for milestone events (job started, query completed, a hit found), and `qCWarning` for recoverable-but-notable problems (timeouts, exhausted fallbacks, failed writes).
- Include timing (`QElapsedTimer`) for any operation that shells out to an external process or hits the network — this has already proven useful for diagnosing slow `pacman` calls and hung icon fetches.
