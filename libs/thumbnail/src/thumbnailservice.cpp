#include "thumbnailservice.h"
#include "iconfetcher_p.h"
#include "thumbnail_log.h"
#include "thumbnail.h"

#include <QDir>
#include <QMetaObject>

// ─── ThumbnailService ─────────────────────────────────────────────────────────

ThumbnailService::ThumbnailService(const QString &cacheDir, QObject *parent)
    : QObject(parent)
{
    m_thread.setObjectName(QStringLiteral("ThumbnailWorker"));

    // Construct the fetcher on the calling thread first, then hand it over
    // to the worker thread. QObject::moveToThread() requires the object to
    // have no parent at move time.
    m_fetcher = new IconFetcher(QDir(cacheDir));
    m_fetcher->moveToThread(&m_thread);

    // ── Route worker signals back to the owner thread ────────────────────
    // ThumbnailService lives on the calling thread; IconFetcher lives on
    // m_thread. Qt selects QueuedConnection automatically when the sender
    // and receiver are on different threads, so iconReady / iconFailed are
    // always delivered on THIS object's thread (typically the main thread).
    connect(m_fetcher, &IconFetcher::iconReady,
            this,      &ThumbnailService::iconReady);
    connect(m_fetcher, &IconFetcher::iconFailed,
            this,      &ThumbnailService::iconFailed);

    m_thread.start();
    qCInfo(logIcon) << "ThumbnailService started";
}

ThumbnailService::~ThumbnailService()
{
    // Ask the worker's event loop to stop processing new events.
    m_thread.quit();
    // Block until the thread has fully exited. After wait() returns,
    // m_fetcher's event loop is dead and no more signals will be emitted.
    m_thread.wait();
    // Now it is safe to delete m_fetcher directly: its thread has stopped
    // and no pending events can be delivered to it.
    delete m_fetcher;
    m_fetcher = nullptr;
    qCInfo(logIcon) << "ThumbnailService: worker thread stopped";
}

void ThumbnailService::request(const QString &appName, int pixelSize)
{
    // Marshal the call to the worker thread via a queued invocation.
    // This function returns immediately on the calling thread — the actual
    // IconFetcher::request() executes asynchronously on m_thread.
    QMetaObject::invokeMethod(
        m_fetcher,
        [fetcher = m_fetcher, appName, pixelSize]() {
            fetcher->request(appName, pixelSize);
        },
        Qt::QueuedConnection);
}

// ─── C API implementation ─────────────────────────────────────────────────────
//
// The opaque ThumbnailServiceHandle bundles the ThumbnailService instance with
// its Qt signal connections and the caller-supplied callbacks.
// Creating and destroying handles is NOT thread-safe with respect to each
// other, but thumbnail_request() is safe to call from any thread.

struct ThumbnailServiceHandle
{
    ThumbnailService *service  = nullptr;
    ThumbnailReadyCb  on_ready  = nullptr;
    ThumbnailFailedCb on_failed = nullptr;
    void             *user_data = nullptr;

    // Keep connections so we can disconnect cleanly in thumbnail_destroy().
    QMetaObject::Connection readyConn;
    QMetaObject::Connection failedConn;
};

extern "C" {

THUMBNAIL_API ThumbnailServiceHandle *
thumbnail_create(const char       *cache_dir_utf8,
                 ThumbnailReadyCb  on_ready,
                 ThumbnailFailedCb on_failed,
                 void             *user_data)
{
    Q_ASSERT(cache_dir_utf8 != nullptr);

    auto *h       = new ThumbnailServiceHandle;
    h->service    = new ThumbnailService(QString::fromUtf8(cache_dir_utf8));
    h->on_ready   = on_ready;
    h->on_failed  = on_failed;
    h->user_data  = user_data;

    // Bridge Qt signals to the plain C callbacks.
    // The lambdas capture `h` by raw pointer; this is safe because the
    // connections are explicitly disconnected inside thumbnail_destroy()
    // before `h` is freed.
    h->readyConn = QObject::connect(
        h->service, &ThumbnailService::iconReady,
        [h](const QString &appName, const QString &diskPath) {
            if (h->on_ready) {
                // toUtf8().constData() pointers are valid for the duration
                // of this lambda call (the QByteArrays are temporary locals
                // kept alive on the stack for the duration of the call).
                const QByteArray nameBytes = appName.toUtf8();
                const QByteArray pathBytes = diskPath.toUtf8();
                h->on_ready(nameBytes.constData(),
                             pathBytes.constData(),
                             h->user_data);
            }
        });

    h->failedConn = QObject::connect(
        h->service, &ThumbnailService::iconFailed,
        [h](const QString &appName) {
            if (h->on_failed) {
                const QByteArray nameBytes = appName.toUtf8();
                h->on_failed(nameBytes.constData(), h->user_data);
            }
        });

    return h;
}

THUMBNAIL_API void
thumbnail_destroy(ThumbnailServiceHandle *handle)
{
    if (!handle) return;

    // Disconnect first to ensure no callbacks fire after this call returns.
    QObject::disconnect(handle->readyConn);
    QObject::disconnect(handle->failedConn);

    // Destroy the service — its destructor blocks until the worker thread
    // exits, guaranteeing all pending icon work has completed or been
    // abandoned before we free the handle struct.
    delete handle->service;
    handle->service = nullptr;

    delete handle;
}

THUMBNAIL_API void
thumbnail_request(ThumbnailServiceHandle *handle,
                  const char             *app_name,
                  int                     pixel_size)
{
    if (!handle || !app_name) return;
    handle->service->request(QString::fromUtf8(app_name), pixel_size);
}

} // extern "C"
