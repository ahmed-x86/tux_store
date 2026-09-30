#pragma once
// thumbnail.h — C-compatible public API for libthumbnail.so
//
// This header intentionally avoids any Qt includes so it can be consumed
// from plain C or from C++ code that does not use Qt.
//
// For Qt-based consumers that prefer signal/slot integration, use
// thumbnailservice.h instead.

// ─── Visibility macro ────────────────────────────────────────────────────────
#if defined(_WIN32)
#  ifdef THUMBNAIL_BUILDING_LIB
#    define THUMBNAIL_API __declspec(dllexport)
#  else
#    define THUMBNAIL_API __declspec(dllimport)
#  endif
#else
#  define THUMBNAIL_API __attribute__((visibility("default")))
#endif

// ─── C API ───────────────────────────────────────────────────────────────────
#ifdef __cplusplus
extern "C" {
#endif

/** Opaque handle returned by thumbnail_create(). */
typedef struct ThumbnailServiceHandle ThumbnailServiceHandle;

/**
 * Called when an icon was successfully resolved and written to disk.
 * @param app_name   UTF-8 package name.
 * @param disk_path  UTF-8 absolute path to the cached icon (PNG or SVG).
 * @param user_data  Pointer passed to thumbnail_create().
 *
 * Always invoked on the thread that owns the Qt event loop that was running
 * when thumbnail_create() was called (i.e. typically the main thread).
 */
typedef void (*ThumbnailReadyCb)(const char *app_name,
                                  const char *disk_path,
                                  void       *user_data);

/**
 * Called when no icon could be found for @p app_name.
 * @param app_name   UTF-8 package name.
 * @param user_data  Pointer passed to thumbnail_create().
 */
typedef void (*ThumbnailFailedCb)(const char *app_name,
                                   void       *user_data);

/**
 * Create a new thumbnail service and start its worker thread.
 *
 * A QGuiApplication (or QCoreApplication) must already be running in the
 * calling thread before this function is called.
 *
 * @param cache_dir_utf8  Absolute path to the icon cache directory (UTF-8).
 *                        Created automatically if it does not exist.
 * @param on_ready        Callback invoked when an icon is ready.
 *                        May be NULL if you only care about failures.
 * @param on_failed       Callback invoked when no icon was found.
 *                        May be NULL.
 * @param user_data       Arbitrary pointer forwarded verbatim to callbacks.
 * @return                Non-NULL opaque handle (aborts on OOM).
 */
THUMBNAIL_API ThumbnailServiceHandle *
thumbnail_create(const char       *cache_dir_utf8,
                 ThumbnailReadyCb  on_ready,
                 ThumbnailFailedCb on_failed,
                 void             *user_data);

/**
 * Destroy a previously created handle and release all resources.
 *
 * Blocks until the internal worker thread has exited cleanly.
 * After this call, no more callbacks will be invoked.
 * Must NOT be called from within a callback.
 *
 * @param handle  Handle to destroy. NULL is silently ignored.
 */
THUMBNAIL_API void
thumbnail_destroy(ThumbnailServiceHandle *handle);

/**
 * Request an icon for @p app_name.
 *
 * Thread-safe — may be called from any thread at any time.
 * Returns immediately; the result (if any) is delivered later via the
 * callbacks registered with thumbnail_create().
 *
 * Duplicate in-flight requests for the same app_name are coalesced
 * automatically — the callback fires exactly once per unique request.
 *
 * @param handle      Handle returned by thumbnail_create(). Must not be NULL.
 * @param app_name    UTF-8 package name (e.g. "firefox"). Must not be NULL.
 * @param pixel_size  Desired icon dimension in pixels (e.g. 64).
 */
THUMBNAIL_API void
thumbnail_request(ThumbnailServiceHandle *handle,
                  const char             *app_name,
                  int                     pixel_size);

#ifdef __cplusplus
} // extern "C"

// ─── C++ RAII wrapper (header-only) ──────────────────────────────────────────
// Convenient for C++ code that does not use Qt signals. Wraps the C API with
// RAII lifetime management and std::function callbacks.
#include <functional>
#include <memory>
#include <string>

/**
 * RAII owner of a ThumbnailServiceHandle.
 *
 * Example:
 *   ThumbnailClient client(
 *       "/home/user/.cache/tuxstore/icons",
 *       [](const std::string& name, const std::string& path) {
 *           // update UI with icon at path
 *       },
 *       [](const std::string& name) {
 *           // use placeholder icon
 *       });
 *   client.request("firefox", 64);
 */
class ThumbnailClient
{
public:
    using ReadyCb  = std::function<void(const std::string &appName,
                                        const std::string &diskPath)>;
    using FailedCb = std::function<void(const std::string &appName)>;

    ThumbnailClient(const std::string &cacheDir,
                    ReadyCb            onReady,
                    FailedCb           onFailed)
        // Heap-allocate the callbacks so the raw pointer in user_data remains
        // valid for the entire lifetime of the handle. We hold a shared_ptr
        // here to guarantee the Cbs outlive any in-flight callback delivery
        // even during destruction (thumbnail_destroy() blocks until all
        // pending work finishes, so no callbacks fire after it returns).
        : m_cbs(std::make_shared<Cbs>(std::move(onReady), std::move(onFailed)))
        , m_handle(
              thumbnail_create(
                  cacheDir.c_str(),
                  [](const char *n, const char *p, void *ud) noexcept {
                      static_cast<Cbs *>(ud)->ready(n, p);
                  },
                  [](const char *n, void *ud) noexcept {
                      static_cast<Cbs *>(ud)->failed(n);
                  },
                  m_cbs.get()))
    {}

    ~ThumbnailClient()
    {
        // thumbnail_destroy blocks until the worker thread stops — at that
        // point no more callbacks can fire, so it is safe to let m_cbs
        // destruct immediately after.
        thumbnail_destroy(m_handle);
    }

    ThumbnailClient(const ThumbnailClient &)            = delete;
    ThumbnailClient &operator=(const ThumbnailClient &) = delete;

    /** Thread-safe. Duplicate requests for the same app are coalesced. */
    void request(const std::string &appName, int pixelSize)
    {
        thumbnail_request(m_handle, appName.c_str(), pixelSize);
    }

private:
    struct Cbs {
        ReadyCb  ready;
        FailedCb failed;
    };

    std::shared_ptr<Cbs>    m_cbs;
    ThumbnailServiceHandle *m_handle;
};

#endif // __cplusplus
