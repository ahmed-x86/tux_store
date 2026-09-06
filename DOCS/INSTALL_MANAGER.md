# InstallManager

Files: `include/installmanager.h`, `src/installmanager.cpp`

`InstallManager` is the only class in the codebase that **mutates system state**. It launches `pacman -S <pkg>`, elevated as needed, streams its raw output for a console view, and derives a smooth weighted progress percentage from that output — since `pacman` itself doesn't offer a simple single "percent done" figure across an entire multi-package transaction.

## Public API

```cpp
void install(const QString &pkgName, const QHash<QString, long long> &sizes);
bool isRunningAsRoot() const;

signals:
void started();
void consoleOutput(QString text);        // raw chunk, append to your log
void progressChanged(double fraction);   // 0..1 overall weighted progress
void finished(bool success, int exitCode);
```

`sizes` must contain **every package that will actually be installed in this transaction** (the target app + every new dependency), mapped to its installed-size-in-bytes. This is used purely to *weight* the progress bar — it has no effect on correctness of the install itself. See `main.cpp`'s `on_install_clicked` handler for how this map is built from a previously-fetched `PackageDetails`.

## Elevation Strategy

```cpp
bool InstallManager::isRunningAsRoot() const {
#ifdef Q_OS_UNIX
    return geteuid() == 0;
#else
    return false;
#endif
}
```

- **Already root** (e.g. launched via `sudo`) → run `pacman -S --noconfirm --noprogressbar <pkg>` directly, no elevation prompt.
- **Not root** → run `pkexec pacman -S --noconfirm --noprogressbar <pkg>`. `pkexec` brings up the native Polkit authentication dialog. No password handling, GUI prompting, or credential storage is implemented in this app — it's entirely delegated to Polkit.

`--noconfirm` is required because Tux Store cannot answer pacman's interactive "Proceed with installation? [Y/n]" prompt; the UI's own details/size view is meant to serve as the pre-install confirmation step instead. `--noprogressbar` disables pacman's own carriage-return progress bar rendering so the line-based parser in `processLine()` has cleaner, more predictable input.

## Process Lifecycle

`install()` fully resets state on every call (important since the same `InstallManager` instance is reused across multiple installs in a single app session):

```cpp
m_sizes = sizes;
m_progressBytes.clear();
m_currentDownloading.clear();
m_lineBuffer.clear();
m_totalBytes = 0;
for (auto v : m_sizes.values()) m_totalBytes += v;
```

Any previous `QProcess` is disconnected and scheduled for deletion before a new one is created — this avoids stale signal connections firing after a second install starts.

`QProcess::setProcessChannelMode(QProcess::MergedChannels)` combines stdout/stderr into a single stream, since pacman's progress lines and messages aren't cleanly separated between the two.

## Output Parsing Pipeline

### `feed(chunk)` — chunk reassembly

`pacman`'s progress lines are updated in-place using carriage returns (`\r`) rather than newlines, to redraw a single line in a terminal. `feed()` normalizes this:

```cpp
QByteArray data = m_lineBuffer + chunk;
data.replace('\r', '\n');
QList<QByteArray> lines = data.split('\n');
m_lineBuffer = lines.isEmpty() ? QByteArray() : lines.takeLast(); // partial line kept for next chunk
for (const QByteArray &l : lines) processLine(QString::fromUtf8(l));
```

Every `\r` becomes a `\n`, so each progress redraw becomes its own logical line for `processLine()`. The last (possibly incomplete) fragment is held in `m_lineBuffer` and prepended to the next chunk — this handles the case where a chunk boundary falls in the middle of a line.

The **raw, unmodified** chunk (before any of this normalization) is also emitted verbatim via `consoleOutput(QString)`, so the console overlay in the UI always shows exactly what pacman printed.

### `processLine(line)` — three line types recognized

1. **`"downloading <pkgspec>"`** — records which package is *currently* being downloaded (`m_currentDownloading`), resolved via `matchKnownPackage()`.
2. **`"installing "` / `"upgrading "` / `"reinstalling "` <pkgspec>`** — the package has finished downloading and pacman has started installing it. This immediately credits the package's **full** weight (`creditPackage(pkg, m_sizes.value(pkg, 0))`), since once installation begins the download is done regardless of what percentage was last observed.
3. **A trailing `NN%`** while `m_currentDownloading` is set — an in-progress download percentage. Credits `weight * pct / 100` bytes toward that package.

Any other line (informational messages, warnings, `:: Synchronizing package databases...`, etc.) is ignored for progress purposes but still flows through to `consoleOutput`.

### `matchKnownPackage(text)` — name matching without full parsing

Pacman's package specs in these lines look like `name-version-release-arch.pkg.tar.zst` (or similar), and since **both names and versions can contain dashes**, there's no reliable generic way to split "name" from "the rest." Instead, `matchKnownPackage()` checks the known set of packages in `m_sizes` and returns the **longest name** that is a valid prefix of the text (i.e. `text.startsWith(name + "-")` or `text == name`). Longest-prefix-wins avoids a shorter package name incorrectly matching when a longer, more specific name is also a valid prefix.

### `creditPackage(pkg, bytes)` — monotonic progress

```cpp
long long &cur = m_progressBytes[pkg];
const long long capped = qMin(bytes, m_sizes.value(pkg, bytes));
if (capped > cur) {           // progress never goes backwards
    cur = capped;
    emitProgress();
}
```

Two safety properties are enforced here:
- **Capped** at that package's own declared size, so a parsing glitch (e.g. reading `150%`) can't overshoot.
- **Monotonic** — a credit is only applied if it's *larger* than the package's current credited amount, so out-of-order or duplicate lines can't make the bar visibly jump backward.

### `emitProgress()` — the 98% ceiling

```cpp
const double frac = m_totalBytes > 0 ? double(sum) / double(m_totalBytes) : 0.0;
emit progressChanged(qBound(0.0, frac, 0.98));
```

This is a deliberate design choice, not a bug: **progress computed from parsed output is never allowed to reach 100%.** Pacman runs post-transaction hooks (updating icon caches, desktop databases, `mkinitcpio`, etc.) *after* the last "installing" line, which can take a non-trivial amount of time. If the bar hit 100% right when the last package finished installing, the UI would appear "done" while pacman is still doing meaningful work. The only place `1.0` is ever emitted is in the `QProcess::finished` handler, once the actual subprocess has exited:

```cpp
connect(m_proc, ..., [this](int code, QProcess::ExitStatus status) {
    const bool ok = status == QProcess::NormalExit && code == 0;
    if (ok) emit progressChanged(1.0);
    emit finished(ok, code);
});
```

## Signal Timeline (typical successful install)

```
started()
consoleOutput("...")            × many, as pacman prints
progressChanged(0.02)
progressChanged(0.15)
...
progressChanged(0.98)           // last package finished "installing" line
consoleOutput("...")            // post-transaction hooks, etc.
progressChanged(1.0)            // ONLY after QProcess actually exits
finished(true, 0)
```

## Known Limitations / TODOs

- **No removal support.** `ui->on_remove_clicked` in `main.cpp` is currently a stub comment: `// TODO: wire up pacman -R the same way if/when needed.` `InstallManager` would need a parallel `remove()` method (or a generalized `run(QStringList args, ...)`) to support this.
- **No retry/resume.** If the process fails partway (e.g. auth cancelled, network failure mid-download), `finished(false, code)` fires and the UI shows a failure state; there's no partial-progress resume — a retry re-runs the whole `pacman -S` command from scratch.
- **`matchKnownPackage` is a heuristic.** In pathological cases (e.g. one package's name is a prefix of another package's *name*, not just its versioned filename), longest-prefix matching is the best available disambiguation without doing full pacman filename parsing, but it's not theoretically airtight. In practice, exact package name collisions of this shape are rare.
