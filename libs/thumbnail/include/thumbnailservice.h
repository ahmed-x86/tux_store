#pragma once
// ThumbnailService — Qt C++ public API for libthumbnail.
//
// This class owns a private QThread on which IconFetcher does all its
// I/O work. Callers always interact with ThumbnailService from their own
// thread (typically the main/UI thread); requests are marshalled internally
// via Qt's queued-connection mechanism so the UI is never blocked.
//
// Usage:
//   auto *ts = new ThumbnailService(cacheDir, this);
//   connect(ts, &ThumbnailService::iconReady,   this, &MyClass::onIconReady);
//   connect(ts, &ThumbnailService::iconFailed,  this, &MyClass::onIconFailed);
//   ts->request("firefox", 64);

#include <QObject>
#include <QString>
#include <QThread>

class IconFetcher; // private; lives on m_thread

class ThumbnailService : public QObject
{
    Q_OBJECT

public:
    /**
     * @param cacheDir  Absolute path to the on-disk icon cache directory.
     *                  Created automatically if it does not exist.
     * @param parent    Optional QObject parent.
     */
    explicit ThumbnailService(const QString &cacheDir,
                              QObject *parent = nullptr);

    /**
     * Destructor — blocks until the internal worker thread has exited cleanly.
     * After this call no more signals will be emitted.
     */
    ~ThumbnailService() override;

    // Non-copyable, non-movable (QObject semantics).
    ThumbnailService(const ThumbnailService &)            = delete;
    ThumbnailService &operator=(const ThumbnailService &) = delete;

    /**
     * Request an icon for @p appName.
     *
     * Thread-safe — may be called from any thread.
     * The call returns immediately; results arrive asynchronously via signals.
     * Duplicate in-flight requests for the same app are automatically coalesced
     * inside the worker thread.
     *
     * @param pixelSize  Desired square size in pixels (e.g. 64).
     */
    void request(const QString &appName, int pixelSize);

signals:
    /**
     * Emitted when an icon has been resolved and written to disk.
     * @param appName   The package name that was requested.
     * @param diskPath  Absolute path to the cached icon file (PNG or SVG).
     *
     * Always delivered on the thread that *owns* this ThumbnailService object
     * (typically the main thread), regardless of which thread called request().
     */
    void iconReady(QString appName, QString diskPath);

    /**
     * Emitted when no icon could be found for @p appName (all sources
     * exhausted, including a fresh negative-cache check).
     *
     * Always delivered on the owner's thread.
     */
    void iconFailed(QString appName);

private:
    QThread      m_thread;
    IconFetcher *m_fetcher = nullptr; ///< Owned; lives exclusively on m_thread.
};
