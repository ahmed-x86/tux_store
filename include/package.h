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
    long long downloadBytes = 0;        // appSizeBytes + newDepsBytes -> what actually downloads
    long long totalBytes = 0;           // appSizeBytes + installedDepsBytes + newDepsBytes -> total installed footprint
};

QString formatSize(long long bytes);
QString prettifyName(const QString &raw);
QString sanitizeName(const QString &name);