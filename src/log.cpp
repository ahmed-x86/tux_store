#include "log.h"
#include <cstdio>
#include <QDateTime>

Q_LOGGING_CATEGORY(logApp, "tuxstore.app")
Q_LOGGING_CATEGORY(logPacman, "tuxstore.pacman")
Q_LOGGING_CATEGORY(logIcon, "tuxstore.icon")
Q_LOGGING_CATEGORY(logUi, "tuxstore.ui")

static void messageHandler(QtMsgType type, const QMessageLogContext &ctx, const QString &msg)
{
    const char *level = "DEBUG";
    switch (type) {
        case QtDebugMsg:    level = "DEBUG"; break;
        case QtInfoMsg:     level = "INFO "; break;
        case QtWarningMsg:  level = "WARN "; break;
        case QtCriticalMsg: level = "CRIT "; break;
        case QtFatalMsg:    level = "FATAL"; break;
    }
    const QString ts = QDateTime::currentDateTime().toString("HH:mm:ss.zzz");
    const QByteArray cat = ctx.category ? ctx.category : "default";

    fprintf(stderr, "[%s] %-5s %-20s %s\n",
            qPrintable(ts), level, cat.constData(), qPrintable(msg));
    fflush(stderr);

    if (type == QtFatalMsg) abort();
}

void installLogHandler()
{
    qInstallMessageHandler(messageHandler);
    QLoggingCategory::setFilterRules(
        // Show all levels for app, pacman, and UI categories.
        "tuxstore.app.debug=true\n"
        "tuxstore.pacman.debug=true\n"
        "tuxstore.ui.debug=true\n"
        // Thumbnail debug is very noisy (queued/GET/globalInFlight per package).
        // Set QT_LOGGING_RULES=tuxstore.thumbnail.debug=true to re-enable.
        "tuxstore.thumbnail.debug=false\n"
        "qt.*.debug=false\n"
    );
}
