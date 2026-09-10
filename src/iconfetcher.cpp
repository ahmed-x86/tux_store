#include "iconfetcher.h"
#include "package.h"
#include "log.h"
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QCoreApplication>
#include <QTimer>
#include <QIcon>
#include <QPixmap>


IconFetcher::IconFetcher(QDir cacheDir, QObject *parent)
    : QObject(parent), m_cacheDir(std::move(cacheDir))
{
    m_cacheDir.mkpath(".");
    qCInfo(logIcon) << "cache dir:" << m_cacheDir.absolutePath()
                     << "maxGlobalInFlight:" << kMaxGlobalInFlight;
}

// ---------------------------------------------------------------------------
// Candidate name generation (aliases -> raw -> sanitized -> truncated -> hints)
// candidates[0] is our single best guess and the only one we ever hit the
// network with.
// ---------------------------------------------------------------------------
static QString aliasFor(const QString &name)
{
    static const QHash<QString, QString> aliases = {
        {"neovim", "nvim"},
        {"libreoffice-fresh", "libreoffice-main"},
        {"libreoffice-still", "libreoffice-main"},
        {"libreoffice", "libreoffice-main"},
        {"fastfetch", "utilities-terminal"},
        {"telegram-desktop", "telegram"},
        {"chromium", "chromium-browser"},
        {"qbittorrent", "qbittorrent"},
    };
    return aliases.value(name);
}

static QStringList fallbackHints(const QString &name)
{
    static const QHash<QString, QStringList> hints = {
        {"yt-dlp", {"youtube-dl", "youtube"}},
        {"htop", {"htop", "utilities-system-monitor"}},
        {"fastfetch", {"utilities-terminal", "terminal"}},
        {"kitty", {"kitty", "terminal"}},
    };
    return hints.value(name);
}

QStringList IconFetcher::generateCandidates(const QString &appName)
{
    QStringList out;
    QSet<QString> seen;
    auto add = [&](const QString &n) {
        if (!n.isEmpty() && !seen.contains(n)) {
            seen.insert(n);
            out << n;
        }
    };

    if (const QString a = aliasFor(appName); !a.isEmpty()) add(a);
    add(appName);

    const QString sanitized = sanitizeName(appName);
    add(sanitized);
    if (const QString a = aliasFor(sanitized); !a.isEmpty()) add(a);

    const QStringList parts = sanitized.split('-', Qt::SkipEmptyParts);
    for (int end = parts.size() - 1; end >= 1; --end)
        add(parts.mid(0, end).join('-'));

    for (const QString &h : fallbackHints(appName)) add(h);
    for (const QString &h : fallbackHints(sanitized)) add(h);

    return out;
}

// ---------------------------------------------------------------------------
// Content sniffing — reject HTML error pages disguised as 200 OK
// ---------------------------------------------------------------------------
bool IconFetcher::isValidImageContent(const QByteArray &bytes)
{
    if (bytes.size() < 8) return false;
    if (bytes.startsWith(QByteArrayLiteral("\x89PNG"))) return true;

    const QByteArray head = bytes.left(512);
    const QString text = QString::fromUtf8(head).trimmed();
    const QString lower = text.toLower();
    if (lower.startsWith("<!doctype") || lower.startsWith("<html")) return false;
    if (lower.contains("<svg") || lower.startsWith("<?xml")) return true;
    return false;
}

// ---------------------------------------------------------------------------
// Disk cache (positive)
// ---------------------------------------------------------------------------
QString IconFetcher::diskPathFor(const QString &appName, const QString &ext) const
{
    return m_cacheDir.filePath(appName + '.' + ext);
}

QString IconFetcher::findCached(const QString &appName) const
{
    const QString svg = diskPathFor(appName, "svg");
    if (QFile::exists(svg)) return svg;
    const QString png = diskPathFor(appName, "png");
    if (QFile::exists(png)) return png;
    return QString();
}

// ---------------------------------------------------------------------------
// Disk cache (negative) — remembers "no icon found" so the same package
// doesn't get its (now single, but still real) network request repeated on
// every app launch / every list reload.
// ---------------------------------------------------------------------------
QString IconFetcher::negativeCachePathFor(const QString &appName) const
{
    return m_cacheDir.filePath(appName + ".notfound");
}

bool IconFetcher::hasFreshNegativeCache(const QString &appName) const
{
    const QFileInfo info(negativeCachePathFor(appName));
    if (!info.exists()) return false;
    const qint64 ageDays = info.lastModified().daysTo(QDateTime::currentDateTime());
    return ageDays < kNegativeCacheDays;
}

void IconFetcher::writeNegativeCache(const QString &appName) const
{
    QFile f(negativeCachePathFor(appName));
    if (f.open(QIODevice::WriteOnly)) {
        f.write(QDateTime::currentDateTimeUtc().toString(Qt::ISODate).toUtf8());
        f.close();
    } else {
        qCWarning(logIcon) << "failed to write negative-cache marker for:" << appName;
    }
}

void IconFetcher::clearNegativeCache(const QString &appName) const
{
    QFile::remove(negativeCachePathFor(appName));
}

// ---------------------------------------------------------------------------
// Bundled local icons root, resolved to an ABSOLUTE path once. Previously
// this was built as a bare relative string ("images/icons/...") which
// depends on the process's current working directory at launch time. The
// lookup itself could still succeed (QFile::exists() resolves relative to
// CWD too), but the path handed to the UI was still relative — and Slint's
// image loader needs an absolute (or resource) path to reliably display it,
// which is why the icon fetcher logged a "hit" while the UI kept showing a
// blank placeholder square.
// ---------------------------------------------------------------------------
static QString localIconsRoot()
{
    static const QString root = [] {
        const QStringList candidates = {
            QCoreApplication::applicationDirPath() + "/images/icons",
            QCoreApplication::applicationDirPath() + "/../images/icons",
            QCoreApplication::applicationDirPath() + "/../share/tuxstore/images/icons",
            QDir::current().filePath("images/icons"),
        };
        for (const QString &c : candidates) {
            if (QDir(c).exists())
                return QDir(c).absolutePath();
        }
        // Last resort: keep the old relative behavior rather than crash,
        // but this should only be hit if the assets truly aren't installed.
        return QDir("images/icons").absolutePath();
    }();
    return root;
}

// ---------------------------------------------------------------------------
// Zero-network lookups: local custom icons and the system icon theme.
// Resolved synchronously and unconditionally in request() — never queued
// behind, or rate-limited alongside, network jobs.
// ---------------------------------------------------------------------------
bool IconFetcher::tryLocalOrThemeIcon(const QString &appName, int pixelSize)
{
    const QStringList candidates = generateCandidates(appName);

    for (const QString &c : candidates) {
        // Bundled custom icons (currently: LibreOffice Fresh language packs).
        if (c.startsWith("libreoffice-fresh")) {
            const QString base = localIconsRoot() + "/libreoffice-fresh/" + c;
            QString localPath;
            if (QFile::exists(base + ".svg")) localPath = base + ".svg";
            else if (QFile::exists(base + ".png")) localPath = base + ".png";

            if (!localPath.isEmpty()) {
                // Always hand back an absolute path — this is what the UI
                // actually needs to render it.
                localPath = QFileInfo(localPath).absoluteFilePath();
                qCInfo(logIcon) << "local custom icon hit:" << appName
                                 << "via candidate:" << c << "at" << localPath;
                emit iconReady(appName, localPath);
                return true;
            }
        }

        // System icon theme (e.g. Papirus, as configured in the screenshot).
        if (QIcon::hasThemeIcon(c)) {
            QIcon sysIcon = QIcon::fromTheme(c);
            if (!sysIcon.isNull()) {
                QPixmap pix = sysIcon.pixmap(pixelSize, pixelSize);
                if (!pix.isNull()) {
                    const QString savePath = diskPathFor(appName, "png");
                    if (pix.save(savePath, "PNG")) {
                        qCInfo(logIcon) << "system theme hit:" << appName << "via candidate:" << c;
                        emit iconReady(appName, savePath);
                        return true;
                    }
                    qCWarning(logIcon) << "failed to save system theme icon for:" << appName;
                }
            }
        }
    }

    return false;
}

// ---------------------------------------------------------------------------
// Public entry point
// ---------------------------------------------------------------------------
void IconFetcher::request(const QString &appName, int pixelSize)
{
    if (m_jobs.contains(appName)) {
        qCDebug(logIcon) << "already in flight, coalescing:" << appName;
        return;
    }

    if (const QString path = findCached(appName); !path.isEmpty()) {
        qCDebug(logIcon) << "disk-cache hit:" << appName << path;
        emit iconReady(appName, path);
        return;
    }

    if (tryLocalOrThemeIcon(appName, pixelSize))
        return;

    if (hasFreshNegativeCache(appName)) {
        qCDebug(logIcon) << "negative-cache hit, skipping network:" << appName;
        emit iconFailed(appName);
        return;
    }

    enqueueJob(appName);
}

// ---------------------------------------------------------------------------
// Job orchestration: at most kMaxGlobalInFlight requests in flight, each job
// is exactly ONE request to ONE repo (Papirus) for ONE best-guess candidate
// name. No racing across multiple icon themes/extensions/name variants.
// ---------------------------------------------------------------------------
static QString singleUrlFor(const QString &candidate)
{
    return QStringLiteral(
        "https://raw.githubusercontent.com/PapirusDevelopmentTeam/papirus-icon-theme/master/Papirus/64x64/apps/%1.svg"
    ).arg(candidate);
}

void IconFetcher::enqueueJob(const QString &appName)
{
    const QStringList candidates = generateCandidates(appName);
    const QString bestCandidate = candidates.isEmpty() ? appName : candidates.first();

    auto *job = new Job();
    job->appName = appName;
    job->url = singleUrlFor(bestCandidate);

    m_jobs.insert(appName, job);
    m_pending.enqueue(appName);
    qCDebug(logIcon) << "queued:" << appName << "candidate:" << bestCandidate
                      << "queueDepth:" << m_pending.size();

    tryStartNext();
}

void IconFetcher::tryStartNext()
{
    while (m_globalInFlight < kMaxGlobalInFlight && !m_pending.isEmpty()) {
        const QString appName = m_pending.dequeue();
        Job *job = m_jobs.value(appName);
        if (!job || job->done) continue; // may have been cancelled/coalesced away
        if (job->started) continue;

        job->started = true;
        job->timer.start();
        startJob(job);
    }
}

void IconFetcher::startJob(Job *job)
{
    qCDebug(logIcon) << "GET" << job->url << "job:" << job->appName
                      << "globalInFlight:" << m_globalInFlight + 1;

    QNetworkRequest req{QUrl(job->url)};
    req.setTransferTimeout(kRequestTimeoutMs);
    QNetworkReply *reply = m_net.get(req);
    m_globalInFlight++;

    // Hard-abort safety net: setTransferTimeout should fire finished() with
    // an error, but if a connection wedges before headers arrive we force
    // it closed so this job (and its global slot) can never hang.
    auto *hardTimeout = new QTimer(reply);
    hardTimeout->setSingleShot(true);
    connect(hardTimeout, &QTimer::timeout, reply, [reply, url = job->url]() {
        if (reply->isRunning()) {
            qCWarning(logIcon) << "hard timeout, aborting:" << url;
            reply->abort();
        }
    });
    hardTimeout->start(kRequestTimeoutMs + 2000);

    connect(reply, &QNetworkReply::finished, this, [this, job, reply]() {
        m_globalInFlight--;
        reply->deleteLater();

        if (job->done) {
            // Shouldn't normally happen (jobs are single-shot now), but
            // guard against it anyway.
            delete job;
            tryStartNext();
            return;
        }

        const bool ok = reply->error() == QNetworkReply::NoError;
        if (!ok) {
            qCDebug(logIcon) << "miss:" << job->url << "error:" << reply->errorString();
        }

        if (ok) {
            const QByteArray bytes = reply->readAll();
            if (isValidImageContent(bytes)) {
                qCInfo(logIcon) << "hit:" << job->url << "bytes:" << bytes.size()
                                 << "elapsedMs:" << job->timer.elapsed();
                finishSuccess(job, bytes, "svg");
                tryStartNext();
                return;
            }
            qCDebug(logIcon) << "invalid content (likely 404 page):" << job->url;
        }

        qCDebug(logIcon) << "no icon for:" << job->appName
                          << "elapsedMs:" << job->timer.elapsed();
        finishFailure(job);
        tryStartNext();
    });
}

void IconFetcher::finishSuccess(Job *job, const QByteArray &bytes, const QString &ext)
{
    job->done = true;

    const QString savePath = diskPathFor(job->appName, ext);
    QFile f(savePath);
    if (f.open(QIODevice::WriteOnly)) {
        f.write(bytes);
        f.close();
    } else {
        qCWarning(logIcon) << "failed to write cache file:" << savePath;
    }

    clearNegativeCache(job->appName);

    m_jobs.remove(job->appName);
    emit iconReady(job->appName, savePath);
    delete job;
}

void IconFetcher::finishFailure(Job *job)
{
    job->done = true;
    m_jobs.remove(job->appName);

    writeNegativeCache(job->appName);

    emit iconFailed(job->appName);
    delete job;
}
