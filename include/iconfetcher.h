#pragma once
#include <QObject>

#include <QNetworkAccessManager>
#include <QHash>
#include <QSet>
#include <QDir>
#include <QQueue>
#include <QElapsedTimer>

// Fetches app icons, in strict priority order, with the smallest possible
// footprint at each step:
//
//  1. On-disk cache (previously downloaded / previously resolved icon).
//  2. Bundled local custom icons (e.g. LibreOffice Fresh language packs) and
//     the user's system icon theme (QIcon::hasThemeIcon) — both resolved
//     SYNCHRONOUSLY in request(), before anything ever touches the network.
//     They cost no meaningful I/O, so they must never be queued behind, or
//     rate-limited alongside, real network jobs.
//  3. Exactly ONE network request, to ONE icon repo (Papirus), for the
//     single best-guess candidate name. No racing across multiple icon
//     themes/extensions/name variants — that's what used to blow up into
//     10-20+ HTTP requests per icon.
//
//  A disk-backed NEGATIVE cache remembers "no icon found" results so step 3
//  is never repeated for the same package once it has already failed
//  (until the negative-cache entry expires).
class IconFetcher : public QObject
{
    Q_OBJECT
public:
    explicit IconFetcher(QDir cacheDir, QObject *parent = nullptr);

    // Requests an icon for `appName`. Emits iconReady(appName, diskPath) on success,
    // or iconFailed(appName) if nothing was found.
    // Safe to call many times concurrently; in-flight duplicate requests are coalesced.
    void request(const QString &appName, int pixelSize);

signals:
    void iconReady(QString appName, QString diskPath);
    void iconFailed(QString appName);

private:
    struct Job {
        QString appName;
        QString url;        // the single URL this job will try
        bool done = false;
        bool started = false;
        QElapsedTimer timer;
    };

    // Max HTTP requests in flight across ALL jobs at once. Each job now
    // issues at most one request, so this simply caps how many icons can
    // be fetched from the network simultaneously.
    static constexpr int kMaxGlobalInFlight = 6;
    static constexpr int kRequestTimeoutMs = 6000;
    // How long a "no icon found" result is trusted before a retry is
    // allowed again (in case the upstream icon theme adds it later).
    static constexpr int kNegativeCacheDays = 14;

    QDir m_cacheDir;
    QNetworkAccessManager m_net;
    QHash<QString, Job *> m_jobs;      // appName -> active/queued job
    QQueue<QString> m_pending;         // appNames waiting for a global slot
    int m_globalInFlight = 0;

    static QStringList generateCandidates(const QString &appName);
    static bool isValidImageContent(const QByteArray &bytes);
    QString diskPathFor(const QString &appName, const QString &ext) const;
    QString findCached(const QString &appName) const;

    // Zero-network lookups.
    bool tryLocalOrThemeIcon(const QString &appName, int pixelSize);

    // Disk-backed negative cache.
    QString negativeCachePathFor(const QString &appName) const;
    bool hasFreshNegativeCache(const QString &appName) const;
    void writeNegativeCache(const QString &appName) const;
    void clearNegativeCache(const QString &appName) const;

    void enqueueJob(const QString &appName);
    void tryStartNext();
    void startJob(Job *job);
    void finishSuccess(Job *job, const QByteArray &bytes, const QString &ext);
    void finishFailure(Job *job);
};
