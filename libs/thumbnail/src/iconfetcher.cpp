#include "iconfetcher_p.h"
#include "thumbnail_log.h"
#include "thumbnail_utils.h"

#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QCoreApplication>
#include <QTimer>
#include <QIcon>
#include <QPixmap>
#include <QJsonDocument>
#include <QJsonObject>


IconFetcher::IconFetcher(QDir cacheDir, QObject *parent)
    : QObject(parent), m_cacheDir(std::move(cacheDir))
{
    m_cacheDir.mkpath(".");
    qCInfo(logIcon) << "ready — cache:" << m_cacheDir.absolutePath()
                    << "maxConcurrent:" << kMaxGlobalInFlight;
}

// ---------------------------------------------------------------------------
// Candidate name generation (aliases -> raw -> sanitized -> truncated -> hints)
// candidates[0] is our single best guess and the only one we ever hit the
// network with.
// ---------------------------------------------------------------------------
static QString aliasFor(const QString &name)
{
    static const QHash<QString, QString> aliases = {
        {"neovim",               "nvim"},
        {"libreoffice-fresh",    "libreoffice-main"},
        {"libreoffice-still",    "libreoffice-main"},
        {"libreoffice",          "libreoffice-main"},
        {"fastfetch",            "utilities-terminal"},
        {"telegram-desktop",     "telegram"},
        {"chromium",             "chromium-browser"},
        {"qbittorrent",          "qbittorrent"},
        // Brave Browser: Papirus uses "brave" not "brave-browser"
        {"brave-browser",        "brave"},
        // OBS Studio: Papirus uses the FreeDesktop app-id
        {"obs-studio",           "com.obsproject.Studio"},
        // Skype: Papirus stores it as "skype"
        {"skypeforlinux",        "skype"},
        // -bin packages share their icon with the base package
        {"session-desktop-bin",  "session-desktop"},
    };
    return aliases.value(name);
}

static QStringList fallbackHints(const QString &name)
{
    static const QHash<QString, QStringList> hints = {
        {"yt-dlp",    {"youtube-dl", "youtube"}},
        {"htop",      {"htop", "utilities-system-monitor"}},
        {"fastfetch", {"utilities-terminal", "terminal"}},
        {"kitty",     {"kitty", "terminal"}},
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

    for (const QString &h : fallbackHints(appName))   add(h);
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

    const QByteArray head  = bytes.left(512);
    const QString    text  = QString::fromUtf8(head).trimmed();
    const QString    lower = text.toLower();
    if (lower.startsWith("<!doctype") || lower.startsWith("<html")) return false;
    if (lower.contains("<svg") || lower.startsWith("<?xml"))        return true;
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
// doesn't get its network request repeated on every app launch / list reload.
// ---------------------------------------------------------------------------
QString IconFetcher::negativeCachePathFor(const QString &appName) const
{
    return m_cacheDir.filePath(appName + ".notfound");
}

bool IconFetcher::hasFreshNegativeCache(const QString &appName) const
{
    const QFileInfo info(negativeCachePathFor(appName));
    if (!info.exists()) return false;
    const qint64 ageDays =
        info.lastModified().daysTo(QDateTime::currentDateTime());
    return ageDays < kNegativeCacheDays;
}

void IconFetcher::writeNegativeCache(const QString &appName) const
{
    QFile f(negativeCachePathFor(appName));
    if (f.open(QIODevice::WriteOnly)) {
        f.write(QDateTime::currentDateTimeUtc().toString(Qt::ISODate).toUtf8());
        f.close();
    } else {
        qCWarning(logIcon) << "failed to write negative-cache marker for:"
                           << appName;
    }
}

void IconFetcher::clearNegativeCache(const QString &appName) const
{
    QFile::remove(negativeCachePathFor(appName));
}

// ---------------------------------------------------------------------------
// Bundled local icons root — resolved to an ABSOLUTE path once.
// Falls back through several candidate locations so the binary can be run
// from the build tree or from an installed prefix without changes.
// ---------------------------------------------------------------------------
static QString localIconsRoot()
{
    static const QString root = [] {
        const QStringList candidates = {
            QCoreApplication::applicationDirPath() + "/images/icons",
            QCoreApplication::applicationDirPath() + "/../images/icons",
            QCoreApplication::applicationDirPath() +
                "/../share/tuxstore/images/icons",
            QDir::current().filePath("images/icons"),
        };
        for (const QString &c : candidates) {
            if (QDir(c).exists())
                return QDir(c).absolutePath();
        }
        // Last resort — keeps old relative behaviour rather than crashing if
        // assets truly aren't installed yet.
        return QDir("images/icons").absolutePath();
    }();
    return root;
}

// ---------------------------------------------------------------------------
// Zero-network lookups: local custom icons and the system icon theme.
// Resolved synchronously and unconditionally in request() — never queued
// behind, or rate-limited alongside, network jobs.
// ---------------------------------------------------------------------------
static QJsonObject loadCustomIconsMap()
{
    static QJsonObject map;
    static bool        loaded = false;
    if (!loaded) {
        loaded = true;
        const QString jsonPath = localIconsRoot() + "/custom_icons.json";
        QFile file(jsonPath);
        if (file.open(QIODevice::ReadOnly)) {
            QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
            if (doc.isObject())
                map = doc.object();
            file.close();
        }
    }
    return map;
}

bool IconFetcher::tryLocalOrThemeIcon(const QString &appName, int pixelSize)
{
    const QStringList candidates  = generateCandidates(appName);
    const QJsonObject customMap   = loadCustomIconsMap();

    for (const QString &c : candidates) {
        // ── Bundled custom icons (configured in custom_icons.json) ──────────
        for (auto it = customMap.begin(); it != customMap.end(); ++it) {
            if (c.startsWith(it.key())) {
                const QString base = localIconsRoot() + "/"
                                   + it.value().toString() + "/" + c;
                QString localPath;
                if      (QFile::exists(base + ".svg")) localPath = base + ".svg";
                else if (QFile::exists(base + ".png")) localPath = base + ".png";

                if (!localPath.isEmpty()) {
                    // Always hand back an absolute path so the UI can render it.
                    localPath = QFileInfo(localPath).absoluteFilePath();
                    qCInfo(logIcon) << "icon:" << appName << "[local]";
                    emit iconReady(appName, localPath);
                    return true;
                }
            }
        }

        // ── System icon theme (e.g. Papirus) ──────────────────────────────
        if (QIcon::hasThemeIcon(c)) {
            const QIcon sysIcon = QIcon::fromTheme(c);
            if (!sysIcon.isNull()) {
                const QPixmap pix = sysIcon.pixmap(pixelSize, pixelSize);
                if (!pix.isNull()) {
                    const QString savePath = diskPathFor(appName, "png");
                    if (pix.save(savePath, "PNG")) {
                        qCInfo(logIcon) << "icon:" << appName << "[theme]";
                        emit iconReady(appName, savePath);
                        return true;
                    }
                    qCWarning(logIcon) << "failed to save system theme icon for:"
                                       << appName;
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
// is exactly ONE request to ONE repo (Papirus) for ONE best-guess candidate.
// ---------------------------------------------------------------------------
static QString singleUrlFor(const QString &candidate)
{
    return QStringLiteral(
        "https://raw.githubusercontent.com/PapirusDevelopmentTeam/"
        "papirus-icon-theme/master/Papirus/64x64/apps/%1.svg"
    ).arg(candidate);
}

void IconFetcher::enqueueJob(const QString &appName)
{
    const QStringList candidates  = generateCandidates(appName);
    const QString     bestCandidate =
        candidates.isEmpty() ? appName : candidates.first();

    auto *job      = new Job();
    job->appName   = appName;
    job->url       = singleUrlFor(bestCandidate);

    m_jobs.insert(appName, job);
    m_pending.enqueue(appName);
    qCDebug(logIcon) << "queued:" << appName
                     << "candidate:" << bestCandidate
                     << "queueDepth:" << m_pending.size();

    tryStartNext();
}

void IconFetcher::tryStartNext()
{
    while (m_globalInFlight < kMaxGlobalInFlight && !m_pending.isEmpty()) {
        const QString appName = m_pending.dequeue();
        Job *job = m_jobs.value(appName);
        if (!job || job->done)    continue;
        if (job->started)         continue;

        job->started = true;
        job->timer.start();
        startJob(job);
    }
}

void IconFetcher::startJob(Job *job)
{
    // Lazy-initialize QNetworkAccessManager here, the first time startJob()
    // is called on the worker thread. Creating m_net in the constructor
    // (before moveToThread) pins it to the main thread, causing Qt to emit
    // "Cannot create children for a parent in a different thread" whenever
    // a QNetworkReply child is created during get(). By initialising here
    // we guarantee both QNAM and its replies share the same thread affinity.
    if (!m_net) {
        m_net = new QNetworkAccessManager(this);
        qCDebug(logIcon) << "QNAM created on worker thread";
    }

    qCDebug(logIcon) << "GET" << job->url
                     << "job:" << job->appName
                     << "globalInFlight:" << m_globalInFlight + 1;

    QNetworkRequest req{QUrl(job->url)};
    req.setTransferTimeout(kRequestTimeoutMs);
    QNetworkReply *reply = m_net->get(req);
    ++m_globalInFlight;

    // Hard-abort safety net: if a connection wedges before headers arrive,
    // force it closed so this job (and its global slot) can never hang.
    auto *hardTimeout = new QTimer(reply);
    hardTimeout->setSingleShot(true);
    connect(hardTimeout, &QTimer::timeout, reply,
            [reply, url = job->url]() {
                if (reply->isRunning()) {
                    qCWarning(logIcon) << "hard timeout, aborting:" << url;
                    reply->abort();
                }
            });
    hardTimeout->start(kRequestTimeoutMs + 2000);

    connect(reply, &QNetworkReply::finished, this,
            [this, job, reply]() {
                --m_globalInFlight;
                reply->deleteLater();

                if (job->done) {
                    // Shouldn't normally happen (jobs are single-shot), but
                    // guard against it anyway.
                    delete job;
                    tryStartNext();
                    return;
                }

                const bool ok =
                    reply->error() == QNetworkReply::NoError;

                if (ok) {
                    const QByteArray bytes = reply->readAll();
                    if (isValidImageContent(bytes)) {
                        finishSuccess(job, bytes, "svg");
                        tryStartNext();
                        return;
                    }
                    qCDebug(logIcon) << "invalid content for:" << job->appName;
                }

                finishFailure(job);
                tryStartNext();
            });
}

void IconFetcher::finishSuccess(Job *job,
                                const QByteArray &bytes,
                                const QString &ext)
{
    job->done = true;

    qCInfo(logIcon) << "icon:" << job->appName
                    << "[network," << job->timer.elapsed() << "ms]";

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

    qCInfo(logIcon) << "icon not found:" << job->appName;

    writeNegativeCache(job->appName);

    emit iconFailed(job->appName);
    delete job;
}
