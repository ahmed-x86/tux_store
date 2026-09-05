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

    fprintf(stderr, "[%s] %-5s %-16s %s\n",
            qPrintable(ts), level, cat.constData(), qPrintable(msg));
    fflush(stderr);

    if (type == QtFatalMsg) abort();
}

void installLogHandler()
{
    qInstallMessageHandler(messageHandler);
    // Enable debug-level output for our own categories by default.
    QLoggingCategory::setFilterRules(
        "tuxstore.*.debug=true\n"
        "qt.*.debug=false\n"
    );
}
