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

QString prettifyName(const QString &raw);
QString sanitizeName(const QString &name);
