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

// sanitizeName() is now defined exclusively in libthumbnail
// (libs/thumbnail/src/thumbnail_utils.cpp) and linked via the shared library.
// Removing the duplicate here eliminates the ODR violation.

QString formatSize(long long bytes)
{
    if (bytes < 1024) return QString::number(bytes) + " B";
    if (bytes < 1024 * 1024) return QString::number(bytes / 1024.0, 'f', 2) + " KiB";
    if (bytes < 1024 * 1024 * 1024) return QString::number(bytes / (1024.0 * 1024.0), 'f', 2) + " MiB";
    return QString::number(bytes / (1024.0 * 1024.0 * 1024.0), 'f', 2) + " GiB";
}
