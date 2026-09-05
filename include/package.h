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
};

struct PackageDetails {
    long long appSizeBytes = 0;
    QVector<PackageDependency> dependencies;
    long long totalDepsBytes = 0;
    long long totalBytes = 0;
};

QString formatSize(long long bytes);
QString prettifyName(const QString &raw);
QString sanitizeName(const QString &name);
