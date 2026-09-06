#pragma once
#include <QString>
#include <QVector>

struct Package {
    QString repo;
    QString name;
    QString version;
    QString description;
    bool installed = false;
};

struct PackageDependency {
    QString name;
    long long sizeBytes = 0;
    bool installed = false;
};

struct PackageDetails {
    long long appSizeBytes = 0;
    QVector<PackageDependency> dependencies;
    long long installedDepsBytes = 0;   // deps already on disk (won't be downloaded)
    long long newDepsBytes = 0;         // deps that still need to be fetched
    long long downloadBytes = 0;        // == totalDownloadBytes below; kept for backward compatibility
    long long totalBytes = 0;           // appSizeBytes + installedDepsBytes + newDepsBytes -> total installed footprint

    // Mirrors pacman's own transaction summary (as seen right before
    // ":: Proceed with installation?"), computed from pacman's real
    // dependency resolution rather than re-derived by us.
    long long totalDownloadBytes = 0;   // sum of "Download Size" for every package pacman will actually fetch
    long long totalInstalledBytes = 0;  // sum of "Installed Size" for every package in the transaction
    long long netUpgradeBytes = 0;      // net change to disk usage this transaction causes
};

QString formatSize(long long bytes);
QString prettifyName(const QString &raw);
QString sanitizeName(const QString &name);