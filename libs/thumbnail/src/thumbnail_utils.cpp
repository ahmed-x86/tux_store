#include "thumbnail_utils.h"
#include <QStringList>

QString sanitizeName(const QString &name)
{
    static const QStringList suffixes = {
        "-git", "-bin", "-aur", "-patch", "-full", "-stable"
    };
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
