#include "installmanager.h"
#include "log.h"
#include <QRegularExpression>
#ifdef Q_OS_UNIX
#include <unistd.h>
#endif

InstallManager::InstallManager(QObject *parent) : QObject(parent) {}

bool InstallManager::isRunningAsRoot() const
{
#ifdef Q_OS_UNIX
    return geteuid() == 0;
#else
    return false;
#endif
}

// We don't try to parse "name-version-rel-arch.pkg.tar.zst" generically
// (versions/names can both contain dashes). Instead we match against the
// known set of packages in this transaction, picking the longest prefix hit.
QString InstallManager::matchKnownPackage(const QString &text) const
{
    QString best;
    for (auto it = m_sizes.cbegin(); it != m_sizes.cend(); ++it) {
        const QString &name = it.key();
        if ((text.startsWith(name + "-") || text == name) && name.size() > best.size())
            best = name;
    }
    return best;
}

// Single-quote for embedding into the shell command string that gets handed
// to `script -c`. Package names are always simple, but we never trust that.
QString InstallManager::shellQuote(const QString &s)
{
    QString escaped = s;
    escaped.replace(QStringLiteral("'"), QStringLiteral("'\\''"));
    return QStringLiteral("'") + escaped + QStringLiteral("'");
}

// Builds and starts the actual process for a pacman invocation.
//
// IMPORTANT: pacman is run under `script`, which allocates a pseudo-terminal
// for it. Without this, stdout is a plain pipe (QProcess always uses pipes),
// and glibc's stdio switches from line-buffered to fully block-buffered as
// soon as it detects it isn't talking to a real terminal. Pacman's output
// then sits in that buffer and is only flushed in large chunks - typically
// right before the process exits - which is exactly why the UI (and even the
// raw console view) used to appear stuck at 0% and then jump straight to
// "done". Running it inside a pty makes pacman behave as if attached to an
// interactive terminal, so it flushes each line/update as it's produced.
//
// Since we now look like a terminal, pacman would also emit ANSI colour
// codes; --color=never keeps the output plain text so our line parsing stays
// simple.
void InstallManager::startPacman(const QStringList &pacmanArgs)
{
    QStringList fullPacmanArgs = {"pacman"};
    fullPacmanArgs += pacmanArgs;
    // Root privilege must come from pkexec (or already being root), never
    // from inside the pty wrapper, so this order matters.
    QStringList quoted;
    for (const QString &a : fullPacmanArgs) quoted << shellQuote(a);
    const QString innerCmd = quoted.join(' ');

    QString program;
    QStringList args;
    if (isRunningAsRoot()) {
        // Already root - just need the pty, no polkit prompt needed.
        program = QStringLiteral("script");
        args = {"-qec", innerCmd, "/dev/null"};
    } else {
        // pkexec elevates first, then execs `script`, which allocates the
        // pty and runs pacman inside it as root.
        program = QStringLiteral("pkexec");
        args = {"script", "-qec", innerCmd, "/dev/null"};
    }

    if (m_proc) {
        m_proc->disconnect();
        m_proc->deleteLater();
        m_proc = nullptr;
    }

    m_proc = new QProcess(this);
    m_proc->setProcessChannelMode(QProcess::MergedChannels);

    connect(m_proc, &QProcess::readyReadStandardOutput, this, [this]() {
        feed(m_proc->readAllStandardOutput());
    });
    connect(m_proc, &QProcess::errorOccurred, this, [this](QProcess::ProcessError) {
        emit consoleOutput(QStringLiteral("\n[process error] %1\n").arg(m_proc->errorString()));
    });
    connect(m_proc, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this](int code, QProcess::ExitStatus status) {
        const bool ok = status == QProcess::NormalExit && code == 0;
        qCInfo(logApp) << "pacman finished, success:" << ok << "exitCode:" << code;
        // The real pacman/pkexec/script process has actually exited now
        // (hooks and all) - this is the only point where 100% / success is
        // allowed.
        if (ok) emit progressChanged(1.0);
        emit finished(ok, code);
    });

    qCInfo(logApp) << "starting pacman via" << program << args;
    emit started();
    m_proc->start(program, args);
}

void InstallManager::install(const QString &pkgName, const QHash<QString, long long> &sizes)
{
    m_sizes = sizes;
    m_progressBytes.clear();
    m_currentDownloading.clear();
    m_lineBuffer.clear();
    m_totalBytes = 0;
    m_milestoneFloor = 0.0;
    m_targetPkg = pkgName;
    for (auto v : m_sizes.values()) m_totalBytes += v;

    startPacman({"-S", "--noconfirm", "--noprogressbar", "--color=never", pkgName});
}

void InstallManager::uninstall(const QString &pkgName, const QString &mode)
{
    m_sizes.clear();
    m_progressBytes.clear();
    m_currentDownloading.clear();
    m_lineBuffer.clear();
    m_totalBytes = 0;
    m_milestoneFloor = 0.0;
    m_targetPkg = pkgName;

    startPacman({mode, "--noconfirm", "--color=never", pkgName});
}

void InstallManager::feed(const QByteArray &chunk)
{
    emit consoleOutput(QString::fromUtf8(chunk));

    // pacman rewrites progress lines with '\r'; treat that like a newline
    // so each update becomes its own logical line for processLine().
    QByteArray data = m_lineBuffer + chunk;
    data.replace('\r', '\n');
    QList<QByteArray> lines = data.split('\n');
    m_lineBuffer = lines.isEmpty() ? QByteArray() : lines.takeLast(); // keep partial line for next chunk
    for (const QByteArray &l : lines) processLine(QString::fromUtf8(l));
}

// Fixed checkpoints in a pacman transaction. These fire well before any
// download/install byte-credit exists (e.g. cached packages with nothing to
// download), which is what keeps the bar moving smoothly instead of sitting
// at 0% and then jumping to the end.
void InstallManager::applyMilestones(const QString &line, bool isUninstall)
{
    struct Milestone { const char *phrase; double floor; };

    static const Milestone kInstallMilestones[] = {
        {"checking keys in keyring",      0.05},
        {"checking package integrity",    0.10},
        {"loading package files",         0.15},
        {"checking for file conflicts",   0.20},
        {"checking available disk space", 0.25},
        {"processing package changes",    0.30}, // download/install phase starts here
        {"running post-transaction hooks", 0.96},
    };
    static const Milestone kUninstallMilestones[] = {
        {"checking dependencies",          0.20},
        {"running post-transaction hooks", 0.92},
    };

    const auto tryList = [&](const Milestone *list, size_t n) {
        for (size_t i = 0; i < n; ++i) {
            if (line.contains(QLatin1String(list[i].phrase), Qt::CaseInsensitive)) {
                m_milestoneFloor = qMax(m_milestoneFloor, list[i].floor);
                return;
            }
        }
    };

    if (isUninstall) {
        tryList(kUninstallMilestones, sizeof(kUninstallMilestones) / sizeof(Milestone));
        // "removing <pkg>" has no size data to credit, so treat it as its
        // own milestone, matched against the package we're actually removing.
        if (!m_targetPkg.isEmpty() && line.startsWith(QStringLiteral("removing "), Qt::CaseInsensitive)) {
            const QString rest = line.mid(QStringLiteral("removing ").size());
            if (rest.startsWith(m_targetPkg))
                m_milestoneFloor = qMax(m_milestoneFloor, 0.75);
        }
    } else {
        tryList(kInstallMilestones, sizeof(kInstallMilestones) / sizeof(Milestone));
    }
}

void InstallManager::processLine(const QString &lineIn)
{
    const QString line = lineIn.trimmed();
    if (line.isEmpty()) return;

    const bool isUninstall = m_sizes.isEmpty();
    applyMilestones(line, isUninstall);

    if (line.startsWith(QStringLiteral("downloading "), Qt::CaseInsensitive)) {
        const QString rest = line.mid(QStringLiteral("downloading ").size());
        const QString pkg = matchKnownPackage(rest);
        if (!pkg.isEmpty()) m_currentDownloading = pkg;
        else emitProgress(); // still nudge the bar via the milestone floor
        return;
    }

    static const QStringList verbs = {"installing ", "upgrading ", "reinstalling "};
    for (const QString &verb : verbs) {
        if (line.startsWith(verb, Qt::CaseInsensitive)) {
            const QString rest = line.mid(verb.size());
            const QString pkg = matchKnownPackage(rest);
            if (!pkg.isEmpty()) {
                creditPackage(pkg, m_sizes.value(pkg, 0)); // full credit once install starts
                if (m_currentDownloading == pkg) m_currentDownloading.clear();
            } else {
                emitProgress();
            }
            return;
        }
    }

    if (!m_currentDownloading.isEmpty()) {
        static const QRegularExpression rePercent(QStringLiteral("(\\d{1,3})\\s*%\\s*$"));
        const auto m = rePercent.match(line);
        if (m.hasMatch()) {
            const int pct = qBound(0, m.captured(1).toInt(), 100);
            const long long weight = m_sizes.value(m_currentDownloading, 0);
            creditPackage(m_currentDownloading, weight * pct / 100);
            return;
        }
    }

    // Any other recognised line (a milestone, most commonly) still needs to
    // push the bar forward even when there's no byte credit to update.
    emitProgress();
}

void InstallManager::creditPackage(const QString &pkg, long long bytes)
{
    long long &cur = m_progressBytes[pkg];
    const long long capped = qMin(bytes, m_sizes.value(pkg, bytes));
    if (capped > cur) { // progress never goes backwards
        cur = capped;
    }
    emitProgress();
}

void InstallManager::emitProgress()
{
    // Byte-weighted download/install fraction (0..1 across this pool),
    // mapped into the "transfer" band of the transaction. For uninstalls
    // m_totalBytes is 0, so this contributes nothing and we rely purely on
    // the milestone floor below.
    constexpr double kTransferStart = 0.30;
    constexpr double kTransferEnd = 0.95;

    long long sum = 0;
    for (auto v : m_progressBytes.values()) sum += v;
    const double transferFrac = m_totalBytes > 0 ? double(sum) / double(m_totalBytes) : 0.0;
    const double transferMapped = kTransferStart + transferFrac * (kTransferEnd - kTransferStart);

    // Progress never goes backwards: combine the milestone floor (driven by
    // recognising fixed pacman transaction stages) with whatever the
    // byte-weighted transfer phase has reached, and keep the running max.
    m_milestoneFloor = qMax(m_milestoneFloor, transferMapped);

    // Never report "done" from output parsing alone - pacman still has to
    // run post-transaction hooks (icon caches, desktop DB, etc.) after the
    // last "installing ..." line, and that can take a while. We only ever
    // emit 1.0 once the real process has exited (see the QProcess::finished
    // handler in startPacman()), so the UI can't show "Installed
    // successfully" while pacman is still doing work under the hood.
    emit progressChanged(qBound(0.0, m_milestoneFloor, 0.98));
}