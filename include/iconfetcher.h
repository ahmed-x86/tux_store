#pragma once
#include <QObject>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QHash>
#include <QSet>
#include <QDir>
#include <QQueue>
#include <QElapsedTimer>

// Fetches app icons from several icon-theme repos on GitHub, with:
//  - in-memory LRU (QPixmapCache) so repeated cards in a session are instant
//  - on-disk cache keyed by original package name
//  - fuzzy candidate-name generation (aliases, suffix stripping, truncation)
//  - a GLOBAL cap on concurrent network requests (kMaxGlobalInFlight) so
//    loading a 20+ item grid doesn't open 80+ sockets at once and stall
//    the event loop / DNS resolver. Extra jobs queue and start as slots free.
//  - per-request timeouts with explicit abort, so a hanging connection
//    can never block a job forever.
//  - content sniffing so HTML 404 pages are never saved as "icons"
class IconFetcher : public QObject
{
    Q_OBJECT
public:
    explicit IconFetcher(QDir cacheDir, QObject *parent = nullptr);

    // Requests an icon for `appName`. Emits iconReady(appName, pixmap) on success,
    // or iconFailed(appName) if nothing was found in any repo.
    // Safe to call many times concurrently; in-flight duplicate requests are coalesced.
    void request(const QString &appName, int pixelSize);

signals:
    void iconReady(QString appName, QPixmap pixmap);
    void iconFailed(QString appName);

private:
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

    // Max HTTP requests in flight across ALL jobs at once. Keeps the whole
    // app responsive even when the grid populates 35+ cards at once.
    static constexpr int kMaxGlobalInFlight = 6;
    // Max parallel candidate URLs raced per single icon job.
    static constexpr int kPerJobParallelism = 2;
    static constexpr int kRequestTimeoutMs = 6000;

    QDir m_cacheDir;
    QNetworkAccessManager m_net;
    QHash<QString, Job *> m_jobs;      // appName -> active/queued job
    QQueue<QString> m_pending;         // appNames waiting for a global slot
    int m_globalInFlight = 0;

    static QStringList generateCandidates(const QString &appName);
    static bool isValidImageContent(const QByteArray &bytes);
    QString diskPathFor(const QString &appName, const QString &ext) const;
    QString findCached(const QString &appName) const;

    void enqueueJob(const QString &appName, int pixelSize);
    void tryStartNext();
    void pumpJob(Job *job);
    void finishSuccess(Job *job, const QByteArray &bytes, const QString &ext);
    void finishFailure(Job *job);
};
