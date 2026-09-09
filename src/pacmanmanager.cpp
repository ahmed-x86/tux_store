#include "pacmanmanager.h"
#include "log.h"
#include <QProcess>
#include <QSet>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QElapsedTimer>

PacmanManager::PacmanManager(QObject *parent) : QObject(parent) {}

const QStringList &PacmanManager::defaultApps()
{
    static const QStringList apps = {
        // Browsers
        "firefox", "chromium", "epiphany", "falkon", "qutebrowser", "midori", "brave-browser", "torbrowser-launcher", "vivaldi", "opera",
        // Design & Multimedia
        "blender", "gimp", "kdenlive", "audacity", "inkscape", "krita", "obs-studio", "vlc", "shotcut", "pitivi", "flowblade", "openshot",
        // Office & Productivity
        "libreoffice-fresh", "libreoffice-still", "onlyoffice-bin", "abiword", "gnumeric", "calligra", "wps-office",
        // Communication
        "telegram-desktop", "discord", "session-desktop", "session-desktop-bin", "signal-desktop", "element-desktop", "skypeforlinux", "slack-desktop",
        // Utilities
        "htop", "neovim", "kitty", "timeshift", "alacritty", "bleachbit", "gparted", "flameshot",
        // Development
        "python", "gcc", "base-devel", "rust", "code", "vscodium", "nodejs", "go", "docker", "git",
        // For You (General/Misc)
        "steam", "qbittorrent", "mpv", "thunar", "fastfetch"
    };
    return apps;
}

QString PacmanManager::normalize(const QString &s)
{
    QString out;
    out.reserve(s.size());
    for (QChar c : s) {
        if (c == ' ' || c == '-' || c == '_' || c == '.') continue;
        out += c.toLower();
    }
    return out;
}

QVector<Package> PacmanManager::runDefaults()
{
    qCDebug(logPacman) << "runDefaults: querying" << defaultApps().size() << "packages";
    QElapsedTimer t; t.start();

    QSet<QString> installed;
    {
        QProcess proc;
        QStringList args = {"-Q"};
        args << defaultApps();
        proc.start("pacman", args);
        if (!proc.waitForFinished(5000)) {
            qCWarning(logPacman) << "pacman -Q timed out, killing process";
            proc.kill();
            proc.waitForFinished(1000);
        }
        const QString out = QString::fromUtf8(proc.readAllStandardOutput());
        for (const QString &line : out.split('\n', Qt::SkipEmptyParts)) {
            const QStringList parts = line.split(' ', Qt::SkipEmptyParts);
            if (!parts.isEmpty()) installed.insert(parts[0]);
        }
        qCDebug(logPacman) << "pacman -Q exit code:" << proc.exitCode()
                            << "installed found:" << installed.size();
    }

    QMap<QString, Package> parsedPkgs;
    {
        QProcess proc;
        QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
        env.insert("LC_ALL", "C");
        proc.setProcessEnvironment(env);
        
        QStringList args = {"-Si"};
        args << defaultApps();
        proc.start("pacman", args);
        if (!proc.waitForFinished(10000)) {
            proc.kill();
            proc.waitForFinished(1000);
        }
        
        const QString out = QString::fromUtf8(proc.readAllStandardOutput());
        Package currentPkg;
        QString currentKey;
        for (const QString &line : out.split('\n')) {
            if (line.isEmpty()) continue;
            
            if (!line.startsWith(' ') && line.contains(':')) {
                currentKey = line.section(':', 0, 0).trimmed();
                QString val = line.section(':', 1).trimmed();
                if (currentKey == "Name") {
                    if (!currentPkg.name.isEmpty()) {
                        parsedPkgs[currentPkg.name] = currentPkg;
                    }
                    currentPkg = Package{};
                    currentPkg.name = val;
                } else if (currentKey == "Repository") {
                    currentPkg.repo = val;
                } else if (currentKey == "Version") {
                    currentPkg.version = val;
                } else if (currentKey == "Description") {
                    currentPkg.description = val;
                }
            } else if (line.startsWith("  ") && currentKey == "Description") {
                currentPkg.description += " " + line.trimmed();
            }
        }
        if (!currentPkg.name.isEmpty()) {
            parsedPkgs[currentPkg.name] = currentPkg;
        }
    }

    QVector<Package> pkgs;
    pkgs.reserve(defaultApps().size());
    for (const QString &name : defaultApps()) {
        Package p;
        if (parsedPkgs.contains(name)) {
            p = parsedPkgs[name];
        } else {
            p.repo = "extra";
            p.name = name;
            p.version = "latest";
            p.description = "A popular package available in the Arch Linux repositories. Click to manage.";
        }
        p.installed = installed.contains(name);
        pkgs.push_back(p);
    }
    qCInfo(logPacman) << "runDefaults done in" << t.elapsed() << "ms, packages:" << pkgs.size();
    return pkgs;
}

Package PacmanManager::getPackageExact(const QString &pkgName)
{
    Package currentPkg;
    currentPkg.name = pkgName;

    // Check if installed
    {
        QProcess proc;
        proc.start("pacman", {"-Q", pkgName});
        proc.waitForFinished();
        if (proc.exitCode() == 0) {
            currentPkg.installed = true;
        } else {
            currentPkg.installed = false;
        }
    }

    // Get info
    {
        QProcess proc;
        QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
        env.insert("LC_ALL", "C");
        proc.setProcessEnvironment(env);
        
        proc.start("pacman", {"-Si", pkgName});
        if (!proc.waitForFinished(10000)) {
            proc.kill();
            proc.waitForFinished();
        }
        
        if (proc.exitCode() != 0) {
            // Might be an AUR package, we just return a stub
            currentPkg.repo = "aur";
            currentPkg.version = "unknown";
            currentPkg.description = "AUR Package or unknown repo";

            return currentPkg;
        }

        const QString out = QString::fromUtf8(proc.readAllStandardOutput());
        QString currentKey;
        for (const QString &line : out.split('\n')) {
            if (line.isEmpty()) continue;
            
            if (!line.startsWith(' ') && line.contains(':')) {
                currentKey = line.section(':', 0, 0).trimmed();
                QString val = line.section(':', 1).trimmed();
                if (currentKey == "Repository") {
                    currentPkg.repo = val;
                } else if (currentKey == "Version") {
                    currentPkg.version = val;
                } else if (currentKey == "Description") {
                    currentPkg.description = val;
                }
            } else if (line.startsWith("  ") && currentKey == "Description") {
                currentPkg.description += " " + line.trimmed();
            }
        }
    }
    
    return currentPkg;
}

QVector<Package> PacmanManager::runSearch(QString query)
{
    qCDebug(logPacman) << "runSearch:" << query;
    QElapsedTimer t; t.start();

    QProcess proc;
    QStringList args = {"-Ss"};
    args << query.split(' ', Qt::SkipEmptyParts);
    proc.start("pacman", args);
    if (!proc.waitForFinished(8000)) {
        qCWarning(logPacman) << "pacman -Ss timed out for query:" << query;
        proc.kill();
        proc.waitForFinished(1000);
    }
    const QString out = QString::fromUtf8(proc.readAllStandardOutput());

    QVector<Package> pkgs;
    const QString normQuery = normalize(query);
    Package current;
    bool has = false;

    auto flush = [&]() {
        if (has && pkgs.size() < 60) {
            if (normalize(current.name).contains(normQuery))
                pkgs.push_back(current);
        }
        has = false;
        current = Package{};
    };

    const QStringList lines = out.split('\n');
    for (const QString &line : lines) {
        if (line.isEmpty()) continue;
        if (!line.startsWith(' ')) {
            flush();
            const QStringList parts = line.split(' ', Qt::SkipEmptyParts);
            if (parts.size() >= 2) {
                const QStringList repoName = parts[0].split('/');
                if (repoName.size() == 2) {
                    current.repo = repoName[0];
                    current.name = repoName[1];
                    current.version = parts[1];
                    current.installed = line.contains("[installed]");
                    current.description.clear();
                    has = true;
                }
            }
        } else if (line.startsWith("    ") && has) {
            current.description = line.trimmed();
        }
    }
    flush();
    qCInfo(logPacman) << "runSearch done in" << t.elapsed() << "ms, matches:" << pkgs.size();
    return pkgs;
}

void PacmanManager::fetchDefaults()
{
    auto *watcher = new QFutureWatcher<QVector<Package>>(this);
    connect(watcher, &QFutureWatcher<QVector<Package>>::finished, this, [this, watcher]() {
        emit resultsReady(watcher->result());
        watcher->deleteLater();
    });
    watcher->setFuture(QtConcurrent::run(&PacmanManager::runDefaults));
}

void PacmanManager::search(const QString &query)
{
    if (query.trimmed().isEmpty()) {
        fetchDefaults();
        return;
    }
    auto *watcher = new QFutureWatcher<QVector<Package>>(this);
    connect(watcher, &QFutureWatcher<QVector<Package>>::finished, this, [this, watcher]() {
        emit resultsReady(watcher->result());
        watcher->deleteLater();
    });
    watcher->setFuture(QtConcurrent::run(&PacmanManager::runSearch, query));
}

long long PacmanManager::parseSize(const QString &sizeStr)
{
    QStringList parts = sizeStr.trimmed().split(' ', Qt::SkipEmptyParts);
    if (parts.size() < 2) return 0;
    double val = parts[0].toDouble();
    QString unit = parts[1].toLower();
    if (unit == "kib") return val * 1024;
    if (unit == "mib") return val * 1024 * 1024;
    if (unit == "gib") return val * 1024 * 1024 * 1024;
    if (unit == "b") return val;
    return val;
}

PackageDetails PacmanManager::runFetchDetails(QString pkgName)
{
    PackageDetails details;

    // --- Step 1: basic info about the target package itself ---------------
    QProcess proc;
    proc.start("pacman", QStringList{"-Si", pkgName});
    if (!proc.waitForFinished(5000)) {
        proc.kill();
        proc.waitForFinished(1000);
    }

    QString out = QString::fromUtf8(proc.readAllStandardOutput());
    bool inSyncDb = !out.isEmpty();
    if (out.isEmpty()) {
        // Fallback to -Qi if not in sync db (e.g. foreign/AUR package already installed)
        proc.start("pacman", QStringList{"-Qi", pkgName});
        proc.waitForFinished(5000);
        out = QString::fromUtf8(proc.readAllStandardOutput());
    }

    QString currentKey;
    QMap<QString, QString> fields;
    for (const QString &line : out.split('\n')) {
        if (line.isEmpty()) continue;
        if (!line.startsWith(' ') && line.contains(':')) {
            currentKey = line.section(':', 0, 0).trimmed();
            fields[currentKey] = line.section(':', 1).trimmed();
        } else if (line.startsWith("  ") && !currentKey.isEmpty()) {
            fields[currentKey] += " " + line.trimmed();
        }
    }
    details.appSizeBytes = parseSize(fields["Installed Size"]);

    // --- Step 2: ask pacman's own resolver for the real transaction -------
    // `pacman -Sp --print-format "%n|%s"` performs full dependency resolution
    // (transitively, exactly like `pacman -S` would) and prints every package
    // that would be part of the transaction, without downloading or
    // installing anything. "%s" is pacman's Download Size for that package.
    // No --needed here: we want the full app+dependency tree even for an
    // already-installed app, so the UI can still show its breakdown; we
    // classify installed vs new ourselves right below.
    QVector<PackageDependency> installedDeps;
    QVector<PackageDependency> newDeps;

    if (inSyncDb) {
        QProcess procPlan;
        procPlan.start("pacman", QStringList{"-Sp", "--print-format", "%n|%s", pkgName});
        if (procPlan.waitForFinished(15000)) {
            const QString planOut = QString::fromUtf8(procPlan.readAllStandardOutput());

            QStringList plannedNames;
            QMap<QString, long long> plannedDownloadBytes;

            for (const QString &line : planOut.split('\n', Qt::SkipEmptyParts)) {
                const int sep = line.indexOf('|');
                if (sep < 0) continue;
                const QString name = line.left(sep).trimmed();
                const long long dlBytes = line.mid(sep + 1).trimmed().toLongLong();
                if (name.isEmpty()) continue;
                plannedNames << name;
                plannedDownloadBytes[name] = dlBytes;
            }

            if (!plannedNames.isEmpty()) {
                // Which of these are already installed locally (so we know
                // installedDeps vs newDeps, and can skip the target itself).
                QProcess procLocal;
                QStringList localArgs = {"-Q"};
                localArgs << plannedNames;
                procLocal.start("pacman", localArgs);
                procLocal.waitForFinished(5000);
                const QString localOut = QString::fromUtf8(procLocal.readAllStandardOutput());
                QSet<QString> installedNames;
                for (const QString &line : localOut.split('\n', Qt::SkipEmptyParts)) {
                    const QStringList parts = line.split(' ', Qt::SkipEmptyParts);
                    if (!parts.isEmpty()) installedNames.insert(parts[0]);
                }

                // Installed Size for each planned package (needed for the
                // Total Installed Size / Net Upgrade Size figures).
                QProcess procInfo;
                QStringList infoArgs = {"-Si"};
                infoArgs << plannedNames;
                procInfo.start("pacman", infoArgs);
                QMap<QString, long long> plannedInstalledBytes;
                if (procInfo.waitForFinished(15000)) {
                    const QString infoOut = QString::fromUtf8(procInfo.readAllStandardOutput());
                    for (const QString &block : infoOut.split("\n\n", Qt::SkipEmptyParts)) {
                        QString cKey;
                        QMap<QString, QString> fInfo;
                        for (const QString &line : block.split('\n')) {
                            if (line.isEmpty()) continue;
                            if (!line.startsWith(' ') && line.contains(':')) {
                                cKey = line.section(':', 0, 0).trimmed();
                                fInfo[cKey] = line.section(':', 1).trimmed();
                            } else if (line.startsWith("  ") && !cKey.isEmpty()) {
                                fInfo[cKey] += " " + line.trimmed();
                            }
                        }
                        const QString n = fInfo["Name"];
                        if (!n.isEmpty()) plannedInstalledBytes[n] = parseSize(fInfo["Installed Size"]);
                    }
                }

                for (const QString &name : plannedNames) {
                    const long long installedSize = plannedInstalledBytes.value(name, 0);
                    const long long downloadSize = plannedDownloadBytes.value(name, 0);
                    const bool alreadyInstalled = installedNames.contains(name);

                    details.totalDownloadBytes += alreadyInstalled ? 0 : downloadSize;
                    details.totalInstalledBytes += installedSize;

                    if (name == pkgName) {
                        // The target app itself; already captured in appSizeBytes above.
                        continue;
                    }

                    PackageDependency pd;
                    pd.name = name;
                    pd.sizeBytes = installedSize;
                    pd.installed = alreadyInstalled;

                    if (alreadyInstalled) {
                        installedDeps.push_back(pd);
                        details.installedDepsBytes += installedSize;
                    } else {
                        newDeps.push_back(pd);
                        details.newDepsBytes += installedSize;
                    }
                }

                // Net Upgrade Size: for a fresh install (no prior version of
                // the target on this system) this equals the total installed
                // footprint of everything newly added to disk.
                details.netUpgradeBytes = details.totalInstalledBytes;
            }
        }
    }

    // installed-first ordering for the dependency list shown in the UI
    details.dependencies = installedDeps;
    details.dependencies += newDeps;

    details.downloadBytes = details.totalDownloadBytes;
    details.totalBytes = details.appSizeBytes + details.installedDepsBytes + details.newDepsBytes;
    return details;
}

void PacmanManager::fetchDetails(const QString &pkgName)
{
    auto *watcher = new QFutureWatcher<PackageDetails>(this);
    connect(watcher, &QFutureWatcher<PackageDetails>::finished, this, [this, watcher]() {
        emit detailsReady(watcher->result());
        watcher->deleteLater();
    });
    watcher->setFuture(QtConcurrent::run(&PacmanManager::runFetchDetails, pkgName));
}