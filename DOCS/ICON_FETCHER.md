# IconFetcher

Files: `include/iconfetcher.h`, `src/iconfetcher.cpp`

Resolves an app icon for a given package name and caches it to disk, trying (in order) the **system icon theme**, an **on-disk cache** from a previous run, and finally a handful of **GitHub icon-theme repositories**. Designed to stay responsive even when loading a grid of 20+ apps at once, and to never let a single hung network connection block icon loading indefinitely.

## Public API

```cpp
explicit IconFetcher(QDir cacheDir, QObject *parent = nullptr);
void request(const QString &appName, int pixelSize);

signals:
void iconReady(QString appName, QString diskPath);
void iconFailed(QString appName);
```

`request()` is **safe to call repeatedly for the same app** — in-flight or already-queued duplicate requests are coalesced (see below), and a disk-cache hit short-circuits everything.

## Resolution Order

```
request(appName)
   │
   ├─► already in-flight? ──────────────► ignore (coalesced)
   │
   ├─► found in disk cache (.svg/.png)? ─► emit iconReady() immediately
   │
   └─► enqueueJob() ──► tryStartNext()
                            │
                            ├─► system icon theme (QIcon::fromTheme) has a hit
                            │      for any generated candidate name?
                            │        └─► render to PNG, save to disk cache,
                            │            emit iconReady() — no network used
                            │
                            └─► no system icon → pumpJob(): race candidate
                                 URLs against several icon-theme GitHub repos
```

## Candidate Name Generation — `generateCandidates(appName)`

Pacman package names don't always match the filename an icon theme uses for that app's icon (e.g. `"neovim"` vs `"nvim"`, or `"telegram-desktop"` vs `"telegram"`). `generateCandidates()` builds an ordered, de-duplicated list of name variants to try, from most-specific/likely to least:

1. **Alias** for the raw name, if one exists (`aliasFor(appName)`).
2. The **raw name** itself.
3. The **sanitized name** (via `sanitizeName()` from `package.h` — strips `-git`, `-bin`, `-aur`, `-patch`, `-full`, `-stable` suffixes).
4. An **alias for the sanitized name**, if different from the raw alias.
5. **Progressive prefix truncation** of the sanitized name's dash-separated parts, from most to least specific — e.g. for `"foo-bar-baz"`: tries `"foo-bar"`, then `"foo"` (but never the empty string, since the loop stops at `end >= 1`).
6. **Fallback hints** for the raw name, then for the sanitized name (`fallbackHints()`) — a small table of manually curated alternate icon names for apps whose icon is filed under a completely unrelated name (e.g. `yt-dlp` → `youtube-dl`/`youtube`).

### Current alias & hint tables

```cpp
// aliasFor()
{"neovim", "nvim"}, {"libreoffice-fresh", "libreoffice-main"},
{"libreoffice-still", "libreoffice-main"}, {"libreoffice", "libreoffice-main"},
{"fastfetch", "utilities-terminal"}, {"telegram-desktop", "telegram"},
{"chromium", "chromium-browser"}, {"qbittorrent", "qbittorrent"}

// fallbackHints()
{"yt-dlp", {"youtube-dl", "youtube"}}, {"htop", {"htop", "utilities-system-monitor"}},
{"fastfetch", {"utilities-terminal", "terminal"}}, {"kitty", {"kitty", "terminal"}}
```

Both tables are `static const QHash` — see [CONTRIBUTING.md](CONTRIBUTING.md) for how to extend them for a new app whose icon isn't resolving well.

## Icon Sources (URL Templates)

For each candidate name, `urlsForCandidate()` expands it against several icon-theme repos, hosted as raw files on GitHub:

1. Papirus (`PapirusDevelopmentTeam/papirus-icon-theme`, 64×64 SVG)
2. Tela (`vinceliuice/Tela-icon-theme`, SVG)
3. Fluent (`vinceliuice/Fluent-icon-theme`, SVG)
4. WhiteSur (`vinceliuice/WhiteSur-icon-theme`, SVG)
5. Qogir (`vinceliuice/Qogir-icon-theme`, SVG)
6. Papirus again, but **PNG** as a last-resort fallback

A job's full URL list is the concatenation of these 6 URLs for **every** generated candidate name, in order — so the highest-priority candidate is fully tried across all repos before moving to the next candidate name.

## Concurrency Model

Three limits work together to keep a large grid's icon-loading from overwhelming the network stack or event loop:

```cpp
static constexpr int kMaxGlobalInFlight = 6;   // across ALL jobs combined
static constexpr int kPerJobParallelism = 2;   // per single icon job
static constexpr int kRequestTimeoutMs = 6000;
```

- **`kMaxGlobalInFlight`** — the hard ceiling on simultaneous HTTP requests app-wide. Without this, requesting icons for a 20+ item grid could open 80+ sockets at once (many candidates × many repos × many apps), which can stall DNS resolution and the event loop. Jobs beyond this cap sit in `m_pending` (a `QQueue<QString>`) until a slot frees up.
- **`kPerJobParallelism`** — even a single icon "races" up to 2 candidate URLs concurrently (rather than one at a time sequentially), so a single 404 doesn't add a full round-trip of latency before trying the next option — while still respecting the global cap.
- **`kRequestTimeoutMs`** (6s) — `QNetworkRequest::setTransferTimeout()`, Qt's built-in timeout mechanism.

### Belt-and-suspenders: the hard-abort timer

`setTransferTimeout()` should reliably fire a `finished()` signal with an error once a transfer stalls, but `pumpJob()` also arms a manual `QTimer` at `kRequestTimeoutMs + 2000`ms as a safety net:

```cpp
auto *hardTimeout = new QTimer(reply);
hardTimeout->setSingleShot(true);
connect(hardTimeout, &QTimer::timeout, reply, [reply, url]() {
    if (reply->isRunning()) reply->abort();
});
hardTimeout->start(kRequestTimeoutMs + 2000);
```

This guarantees a connection that somehow evades the transfer timeout (e.g. before headers arrive) is still force-closed, so it can never permanently occupy one of the 6 global slots.

## Job Lifecycle — `Job` struct

```cpp
struct Job {
    QString appName;
    int pixelSize;
    QStringList candidates;
    QStringList urls;      // flattened, in priority order
    int urlIndex = 0;
    int inFlight = 0;
    bool done = false;
    bool started = false;
    QElapsedTimer timer;
};
```

- `m_jobs: QHash<QString, Job*>` tracks every active/queued job by app name — this is also what makes `request()` coalescing work: a second `request()` call for an app already in `m_jobs` is simply ignored.
- `m_pending: QQueue<QString>` holds app names waiting for a *global* slot.
- `tryStartNext()` drains `m_pending` while `m_globalInFlight < kMaxGlobalInFlight`, and for each newly-started job **first checks the system icon theme** (see below) before falling back to `pumpJob()`.
- `pumpJob(job)` fires off up to `kPerJobParallelism` concurrent GET requests for the job's next untried candidate URLs, and is re-invoked after each request finishes (success, failure, or timeout) to keep the job's local parallelism window full until its URL list is exhausted.

### The "straggler" problem

Because a job races multiple URLs concurrently, it's possible for one candidate to succeed while 1+ sibling requests for the *same job* are still in flight. When that happens:

```cpp
if (job->done) {
    // Late straggler from the same job's race — clean up and possibly
    // free the job once every straggler has reported.
    if (job->inFlight == 0) delete job;
    tryStartNext();
    return;
}
```

`finishSuccess()`/`finishFailure()` mark `job->done = true` and remove the job from `m_jobs` immediately (so no third-party sees it as "active" and duplicate-requests wouldn't coalesce into a dead job) — but the `Job*` object itself is only `delete`d once `inFlight` drops to zero, i.e. once every straggler request tied to it has finished and safely no-op'd.

## Content Sniffing — `isValidImageContent(bytes)`

GitHub's raw file server responds with **HTTP 200 and an HTML 404 page** for a nonexistent path in some scenarios (or a CDN edge case), which would otherwise be silently written to disk as a "successful" icon. Before accepting a response, `isValidImageContent()` checks:

- **Too short** (< 8 bytes) → reject.
- **PNG magic bytes** (`\x89PNG`) → accept immediately.
- Otherwise, decode the first 512 bytes as UTF-8 text and check:
  - Starts with `<!doctype` or `<html` (case-insensitive) → **reject**, this is an HTML error page.
  - Contains `<svg` or starts with `<?xml` → **accept**, this is a real SVG.
  - Anything else → reject.

This runs on every successful HTTP response before it's ever written to `m_cacheDir`.

## System Icon Theme Shortcut

Before touching the network at all, `tryStartNext()` checks whether any generated candidate name resolves via the user's installed icon theme:

```cpp
if (QIcon::hasThemeIcon(c)) {
    QIcon sysIcon = QIcon::fromTheme(c);
    QPixmap pix = sysIcon.pixmap(job->pixelSize, job->pixelSize);
    if (!pix.isNull()) {
        // save PNG to disk cache, emit iconReady(), done — no network
    }
}
```

This is checked for **every candidate name** in the job (not just the raw app name), so aliases and sanitized names benefit from this shortcut too. It's tried once per job, right as the job is dequeued from `m_pending` — a system-theme hit means the job never touches `pumpJob()` or the network at all.

## Disk Cache

```cpp
QString diskPathFor(appName, ext) const;   // cacheDir/<appName>.<ext>
QString findCached(appName) const;         // checks .svg first, then .png
```

The cache is keyed by the **original, unmodified app name** (not the resolved candidate), so a subsequent app launch's `request()` for the same package hits the cache immediately regardless of which candidate/source ultimately produced the icon. `.svg` is checked before `.png` since most icon-theme sources here are SVG-first.

The cache directory is created (`mkpath(".")`) once in the constructor and is otherwise unmanaged — there's currently no cache eviction, expiry, or invalidation. See [CONTRIBUTING.md](CONTRIBUTING.md) for notes if you're considering adding cache invalidation (e.g. on icon-theme repo updates).

## Logging

Uses the `logIcon` category (see [LOGGING.md](LOGGING.md)). Notably logs: cache hits, queue depth on enqueue, per-job start with current global in-flight count, every GET with in-flight counters, hits/misses/invalid-content per URL with elapsed time, and full-exhaustion warnings — this is usually the most useful category to enable when debugging why a specific app's icon never loads.
