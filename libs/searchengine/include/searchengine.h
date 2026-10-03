#pragma once
// searchengine.h — Public API for libsearchengine.so
//
// Provides asynchronous package search, default-app listing, and detail
// fetching via Qt signals. All heavy work (pacman subprocesses) runs off
// the caller's thread through QtConcurrent.

// ─── Visibility macro ────────────────────────────────────────────────────────
#if defined(_WIN32)
#  ifdef SEARCHENGINE_BUILDING_LIB
#    define SEARCHENGINE_API __declspec(dllexport)
#  else
#    define SEARCHENGINE_API __declspec(dllimport)
#  endif
#else
#  ifdef SEARCHENGINE_BUILDING_LIB
#    define SEARCHENGINE_API __attribute__((visibility("default")))
#  else
#    define SEARCHENGINE_API
#  endif
#endif

#include <QObject>
#include <QVector>
#include <QString>
#include <QStringList>

// ─── Data types ──────────────────────────────────────────────────────────────
// Re-use the application-wide Package / PackageDetails types so the main
// binary doesn't need a separate conversion layer.
#include "package.h"

// ─── SearchEngine ────────────────────────────────────────────────────────────
class SEARCHENGINE_API SearchEngine : public QObject
{
    Q_OBJECT
public:
    explicit SearchEngine(QObject *parent = nullptr);

    /// Async: fetches the curated default-app list with installed status.
    void fetchDefaults();

    /// Async: fuzzy search via `pacman -Ss`, normalized-substring filtered.
    void search(const QString &query);

    /// Async: fetches package details including size and dependencies.
    void fetchDetails(const QString &pkgName);

    /// Sync: fetches exact package info (safe to call from any thread).
    static Package getPackageExact(const QString &pkgName);

    /// The curated list of default app names shown on the Home tab.
    static const QStringList &defaultApps();

signals:
    void resultsReady(QVector<Package> packages);
    void detailsReady(PackageDetails details);
};
