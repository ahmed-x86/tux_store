#include "package.h"
#include <QStringList>

QString prettifyName(const QString &raw)
{
    const QStringList parts = raw.split('-', Qt::SkipEmptyParts);
    QStringList out;
    for (const QString &p : parts) {
        if (p.isEmpty()) continue;
        out << (p.left(1).toUpper() + p.mid(1));
    }
    return out.join(' ');
}

// Strips common Arch suffixes iteratively: "foo-bin-git" -> "foo-bin" -> "foo"
QString sanitizeName(const QString &name)
{
    static const QStringList suffixes = {"-git", "-bin", "-aur", "-patch", "-full", "-stable"};
    QString result = name;
    bool changed = true;
    while (changed) {
        changed = false;
        for (const QString &suf : suffixes) {
            if (result.endsWith(suf) && result.size() > suf.size()) {
                result.chop(suf.size());
                changed = true;
                break;
            }
        }
    }
    return result;
}

QString formatSize(long long bytes)
{
    if (bytes < 1024) return QString::number(bytes) + " B";
    if (bytes < 1024 * 1024) return QString::number(bytes / 1024.0, 'f', 2) + " KiB";
    if (bytes < 1024 * 1024 * 1024) return QString::number(bytes / (1024.0 * 1024.0), 'f', 2) + " MiB";
    return QString::number(bytes / (1024.0 * 1024.0 * 1024.0), 'f', 2) + " GiB";
}
