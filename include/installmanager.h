#pragma once
#include <QObject>
#include <QProcess>
#include <QHash>
#include <QString>
#include <QByteArray>

// Runs `pacman -S <pkg>` (elevated via pkexec unless already root), streams
// raw output for a console view, and estimates weighted progress (0..1)
// across the packages that will actually be installed (new deps + target).
class InstallManager : public QObject
{
    Q_OBJECT
public:
    explicit InstallManager(QObject *parent = nullptr);

    // sizes: package name -> installed size in bytes, for every package that
    // will be installed in this transaction (new deps + the target package).
    // Used only to weight the progress bar; not for correctness.
    void install(const QString &pkgName, const QHash<QString, long long> &sizes);

    bool isRunningAsRoot() const;

signals:
    void started();
    void consoleOutput(QString text);       // raw chunk, append to your log
    void progressChanged(double fraction);  // 0..1 overall weighted progress
    void finished(bool success, int exitCode);

private:
    QProcess *m_proc = nullptr;
    QHash<QString, long long> m_sizes;
    QHash<QString, long long> m_progressBytes;
    long long m_totalBytes = 0;
    QString m_currentDownloading;
    QByteArray m_lineBuffer;

    QString matchKnownPackage(const QString &text) const;
    void feed(const QByteArray &chunk);
    void processLine(const QString &line);
    void creditPackage(const QString &pkg, long long bytes);
    void emitProgress();
};
