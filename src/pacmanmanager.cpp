#include "pacmanmanager.h"
#include "log.h"
#include <QProcess>
#include <QSet>
#include <QRegularExpression>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QElapsedTimer>

PacmanManager::PacmanManager(QObject *parent) : QObject(parent) {}

const QStringList &PacmanManager::defaultApps()
{
    static const QStringList apps = {
        "firefox", "chromium", "vlc", "gimp", "mpv", "discord", "telegram-desktop", "blender",
        "inkscape", "audacity", "steam", "thunar", "neovim", "kitty", "htop", "fastfetch",
        "qbittorrent", "libreoffice-fresh", "timeshift", "galculator",
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

    QVector<Package> pkgs;
    pkgs.reserve(defaultApps().size());
    for (const QString &name : defaultApps()) {
        Package p;
        p.repo = "extra";
        p.name = name;
        p.version = "latest";
        p.description = "A popular package available in the Arch Linux repositories. Click to manage.";
        p.installed = installed.contains(name);
        pkgs.push_back(p);
    }
    qCInfo(logPacman) << "runDefaults done in" << t.elapsed() << "ms, packages:" << pkgs.size();
    return pkgs;
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
    
    QProcess proc;
    proc.start("pacman", QStringList{"-Si", pkgName});
    if (!proc.waitForFinished(5000)) {
        proc.kill();
        proc.waitForFinished(1000);
    }
    
    QString out = QString::fromUtf8(proc.readAllStandardOutput());
    if (out.isEmpty()) {
        // Fallback to -Qi if not in sync db
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
    
    QString depsStr = fields["Depends On"];
    QStringList deps;
    if (depsStr != "None" && !depsStr.isEmpty()) {
        for (const QString &d : depsStr.split(' ', Qt::SkipEmptyParts)) {
            QString name = d;
            int idx = name.indexOf(QRegularExpression("[=><]"));
            if (idx != -1) name = name.left(idx);
            if (!deps.contains(name)) deps << name;
        }
    }
    
    if (!deps.isEmpty()) {
        QProcess procDeps;
        QStringList args = {"-Si"};
        args << deps;
        procDeps.start("pacman", args);
        if (procDeps.waitForFinished(10000)) {
            QString outDeps = QString::fromUtf8(procDeps.readAllStandardOutput());
            
            for (const QString &block : outDeps.split("\n\n", Qt::SkipEmptyParts)) {
                QString cKey;
                QMap<QString, QString> fDeps;
                for (const QString &line : block.split('\n')) {
                    if (line.isEmpty()) continue;
                    if (!line.startsWith(' ') && line.contains(':')) {
                        cKey = line.section(':', 0, 0).trimmed();
                        fDeps[cKey] = line.section(':', 1).trimmed();
                    } else if (line.startsWith("  ") && !cKey.isEmpty()) {
                        fDeps[cKey] += " " + line.trimmed();
                    }
                }
                QString depName = fDeps["Name"];
                long long depSize = parseSize(fDeps["Installed Size"]);
                if (!depName.isEmpty()) {
                    PackageDependency pd;
                    pd.name = depName;
                    pd.sizeBytes = depSize;
                    details.dependencies.push_back(pd);
                    details.totalDepsBytes += depSize;
                }
            }
        }
    }
    
    details.totalBytes = details.appSizeBytes + details.totalDepsBytes;
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
