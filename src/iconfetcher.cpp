#include "iconfetcher.h"
#include "package.h"
#include "log.h"
#include <QNetworkReply>
#include <QFile>
#include <QTimer>

IconFetcher::IconFetcher(QDir cacheDir, QObject *parent)
    : QObject(parent), m_cacheDir(std::move(cacheDir))
{
    m_cacheDir.mkpath(".");
    qCInfo(logIcon) << "cache dir:" << m_cacheDir.absolutePath()
                     << "maxGlobalInFlight:" << kMaxGlobalInFlight;
}

// ---------------------------------------------------------------------------
// Candidate name generation (aliases -> raw -> sanitized -> truncated -> hints)
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
// Disk cache
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

    enqueueJob(appName, pixelSize);
}

// ---------------------------------------------------------------------------
// Job orchestration: GLOBAL cap on in-flight requests via a queue, plus a
// small per-job parallelism so each icon still races a couple of candidates.
// ---------------------------------------------------------------------------
static QStringList urlsForCandidate(const QString &candidate)
{
    return {
        QStringLiteral("https://raw.githubusercontent.com/PapirusDevelopmentTeam/papirus-icon-theme/master/Papirus/64x64/apps/%1.svg").arg(candidate),
        QStringLiteral("https://raw.githubusercontent.com/vinceliuice/Tela-icon-theme/master/src/64/apps/%1.svg").arg(candidate),
        QStringLiteral("https://raw.githubusercontent.com/vinceliuice/Fluent-icon-theme/master/src/64/apps/%1.svg").arg(candidate),
        QStringLiteral("https://raw.githubusercontent.com/vinceliuice/WhiteSur-icon-theme/master/src/64/apps/%1.svg").arg(candidate),
        QStringLiteral("https://raw.githubusercontent.com/vinceliuice/Qogir-icon-theme/master/src/64/apps/%1.svg").arg(candidate),
        QStringLiteral("https://raw.githubusercontent.com/PapirusDevelopmentTeam/papirus-icon-theme/master/Papirus/64x64/apps/%1.png").arg(candidate),
    };
}

void IconFetcher::enqueueJob(const QString &appName, int pixelSize)
{
    auto *job = new Job();
    job->appName = appName;
    job->pixelSize = pixelSize;
    job->candidates = generateCandidates(appName);
    for (const QString &c : job->candidates)
        job->urls << urlsForCandidate(c);

    m_jobs.insert(appName, job);
    m_pending.enqueue(appName);
    qCDebug(logIcon) << "queued:" << appName << "candidates:" << job->candidates.size()
                      << "urls:" << job->urls.size() << "queueDepth:" << m_pending.size();

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
        qCDebug(logIcon) << "starting job:" << appName
                          << "globalInFlight:" << m_globalInFlight
                          << "queueRemaining:" << m_pending.size();
        pumpJob(job);
    }
}

void IconFetcher::pumpJob(Job *job)
{
    if (job->done) return;

    while (job->inFlight < kPerJobParallelism
           && m_globalInFlight < kMaxGlobalInFlight
           && job->urlIndex < job->urls.size()) {
        const QString url = job->urls[job->urlIndex++];
        const QString ext = url.endsWith(".png") ? "png" : "svg";

        QNetworkRequest req{QUrl(url)};
        req.setTransferTimeout(kRequestTimeoutMs);
        QNetworkReply *reply = m_net.get(req);
        job->inFlight++;
        m_globalInFlight++;

        qCDebug(logIcon) << "GET" << url << "job:" << job->appName
                          << "jobInFlight:" << job->inFlight
                          << "globalInFlight:" << m_globalInFlight;

        // Hard-abort safety net: setTransferTimeout should fire NoError-less
        // finished(), but if a connection wedges before headers arrive we
        // force it closed so this job (and the global slot) can never hang.
        auto *hardTimeout = new QTimer(reply);
        hardTimeout->setSingleShot(true);
        connect(hardTimeout, &QTimer::timeout, reply, [reply, url]() {
            if (reply->isRunning()) {
                qCWarning(logIcon) << "hard timeout, aborting:" << url;
                reply->abort();
            }
        });
        hardTimeout->start(kRequestTimeoutMs + 2000);

        connect(reply, &QNetworkReply::finished, this, [this, job, reply, ext, url]() {
            job->inFlight--;
            m_globalInFlight--;
            reply->deleteLater();

            if (job->done) {
                // Job already completed by a sibling request; this is a late
                // straggler from the same job's race. Just clean up ourselves
                // and possibly free the job once every straggler has reported.
                qCDebug(logIcon) << "late straggler ignored for finished job:" << url;
                if (job->inFlight == 0) delete job;
                tryStartNext();
                return;
            }

            const bool ok = reply->error() == QNetworkReply::NoError;
            if (!ok) {
                qCDebug(logIcon) << "miss:" << url << "error:" << reply->errorString();
            }

            if (ok) {
                const QByteArray bytes = reply->readAll();
                if (isValidImageContent(bytes)) {
                    qCInfo(logIcon) << "hit:" << url << "bytes:" << bytes.size()
                                     << "elapsedMs:" << job->timer.elapsed();
                    finishSuccess(job, bytes, ext);
                    tryStartNext();
                    return;
                }
                qCDebug(logIcon) << "invalid content (likely 404 page):" << url;
            }

            // This candidate URL failed — try to keep the pipeline full.
            if (job->urlIndex >= job->urls.size() && job->inFlight == 0) {
                qCWarning(logIcon) << "exhausted all candidates for:" << job->appName
                                    << "elapsedMs:" << job->timer.elapsed();
                finishFailure(job);
            } else {
                pumpJob(job);
            }
            tryStartNext();
        });
    }

    // Nothing left to try and nothing in flight -> exhausted.
    if (job->urlIndex >= job->urls.size() && job->inFlight == 0 && !job->done) {
        finishFailure(job);
        tryStartNext();
    }
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

    m_jobs.remove(job->appName);
    emit iconReady(job->appName, savePath);

    // Only free the job once every sibling request from its race has
    // reported back (inFlight == 0). Stragglers still in flight will see
    // job->done == true in their own finished() handler and free it then.
    if (job->inFlight == 0) delete job;
}

void IconFetcher::finishFailure(Job *job)
{
    job->done = true;
    m_jobs.remove(job->appName);
    emit iconFailed(job->appName);

    if (job->inFlight == 0) delete job;
}
