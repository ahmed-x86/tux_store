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

void InstallManager::install(const QString &pkgName, const QHash<QString, long long> &sizes)
{
    m_sizes = sizes;
    m_progressBytes.clear();
    m_currentDownloading.clear();
    m_lineBuffer.clear();
    m_totalBytes = 0;
    for (auto v : m_sizes.values()) m_totalBytes += v;

    if (m_proc) {
        m_proc->disconnect();
        m_proc->deleteLater();
        m_proc = nullptr;
    }

    m_proc = new QProcess(this);
    m_proc->setProcessChannelMode(QProcess::MergedChannels);

    QString program;
    QStringList args;
    if (isRunningAsRoot()) {
        // Already root (e.g. app launched with sudo) — no polkit prompt needed.
        program = QStringLiteral("pacman");
        args = {"-S", "--noconfirm", "--noprogressbar", pkgName};
    } else {
        // pkexec brings up the native polkit auth dialog for us.
        program = QStringLiteral("pkexec");
        args = {"pacman", "-S", "--noconfirm", "--noprogressbar", pkgName};
    }

    connect(m_proc, &QProcess::readyReadStandardOutput, this, [this]() {
        feed(m_proc->readAllStandardOutput());
    });
    connect(m_proc, &QProcess::errorOccurred, this, [this](QProcess::ProcessError) {
        emit consoleOutput(QStringLiteral("\n[process error] %1\n").arg(m_proc->errorString()));
    });
    connect(m_proc, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this](int code, QProcess::ExitStatus status) {
        const bool ok = status == QProcess::NormalExit && code == 0;
        qCInfo(logApp) << "install finished, success:" << ok << "exitCode:" << code;
        // The real pacman/pkexec process has actually exited now (hooks and
        // all) — this is the only point where 100% / success is allowed.
        if (ok) emit progressChanged(1.0);
        emit finished(ok, code);
    });

    qCInfo(logApp) << "starting install:" << program << args;
    emit started();
    m_proc->start(program, args);
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

void InstallManager::processLine(const QString &lineIn)
{
    const QString line = lineIn.trimmed();
    if (line.isEmpty()) return;

    if (line.startsWith(QStringLiteral("downloading "), Qt::CaseInsensitive)) {
        const QString rest = line.mid(QStringLiteral("downloading ").size());
        const QString pkg = matchKnownPackage(rest);
        if (!pkg.isEmpty()) m_currentDownloading = pkg;
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
        }
    }
}

void InstallManager::creditPackage(const QString &pkg, long long bytes)
{
    long long &cur = m_progressBytes[pkg];
    const long long capped = qMin(bytes, m_sizes.value(pkg, bytes));
    if (capped > cur) { // progress never goes backwards
        cur = capped;
        emitProgress();
    }
}

void InstallManager::emitProgress()
{
    long long sum = 0;
    for (auto v : m_progressBytes.values()) sum += v;
    const double frac = m_totalBytes > 0 ? double(sum) / double(m_totalBytes) : 0.0;

    // Never report "done" from output parsing alone — pacman still has to
    // run post-transaction hooks (icon caches, desktop DB, etc.) after the
    // last "installing ..." line, and that can take a while. We only ever
    // emit 1.0 once the real process has exited (see the QProcess::finished
    // handler in install()), so the UI can't show "Installed successfully"
    // while pacman is still doing work under the hood.
    emit progressChanged(qBound(0.0, frac, 0.98));
}