#pragma once
#include "package.h"
#include <QObject>
#include <QVector>

// Runs pacman queries off the UI thread via QtConcurrent, emits results as signals.
class PacmanManager : public QObject
{
    Q_OBJECT
public:
    explicit PacmanManager(QObject *parent = nullptr);

    // Async: fetches the curated default-app list with installed status.
    void fetchDefaults();

    // Async: fuzzy search via `pacman -Ss`, normalized-substring filtered.
    void search(const QString &query);

    static const QStringList &defaultApps();

signals:
    void resultsReady(QVector<Package> packages);

private:
    static QVector<Package> runDefaults();
    static QVector<Package> runSearch(QString query);
    static QString normalize(const QString &s);
};
