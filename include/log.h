#pragma once
#include <QDebug>
#include <QLoggingCategory>

// Central logging categories — visible in terminal via QT_LOGGING_RULES or by default (qDebug/qWarning).
// Usage: qCDebug(logIcon) << "fetching" << name;
Q_DECLARE_LOGGING_CATEGORY(logApp)
Q_DECLARE_LOGGING_CATEGORY(logPacman)
Q_DECLARE_LOGGING_CATEGORY(logIcon)
Q_DECLARE_LOGGING_CATEGORY(logUi)

void installLogHandler();
