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
    void uninstall(const QString &pkgName, const QString &mode);

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

    // Name of the package this transaction targets (used to recognise the
    // "removing <pkg>" line during uninstall, which has no size data).
    QString m_targetPkg;

    // Monotonically-increasing progress floor driven by recognising pacman's
    // fixed transaction milestones (checking keys, loading files, etc). This
    // is what makes the bar move even before/without any byte-weighted
    // download or install credit.
    double m_milestoneFloor = 0.0;

    QString matchKnownPackage(const QString &text) const;
    void feed(const QByteArray &chunk);
    void processLine(const QString &line);
    void applyMilestones(const QString &line, bool isUninstall);
    void creditPackage(const QString &pkg, long long bytes);
    void emitProgress();
    static QString shellQuote(const QString &s);
    void startPacman(const QStringList &pacmanArgs);
};