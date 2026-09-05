#include "mainwindow.h"
#include "log.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    installLogHandler();
    qCInfo(logApp) << "Tux Store starting up...";

    QApplication app(argc, argv);
    app.setApplicationName("Tux Store");

    // Force Fusion style so the app never inherits the desktop theme's
    // native widget rendering (KDE/GTK focus rings, accent colors, etc).
    // Without this, focused widgets can show the OS theme's highlight
    // color instead of our Catppuccin palette.
    app.setStyle(QStyleFactory::create("Fusion"));

    MainWindow window;
    window.show();
    qCInfo(logApp) << "main window shown, entering event loop";

    const int rc = app.exec();
    qCInfo(logApp) << "event loop exited with code" << rc;
    return rc;
}
