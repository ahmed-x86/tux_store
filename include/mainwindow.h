#pragma once
#include "package.h"
#include "pacmanmanager.h"
#include "iconfetcher.h"
#include "detailsview.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
#include <QVector>

static constexpr int kPageSize = 35;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    // Data
    PacmanManager *m_pacman;
    IconFetcher *m_iconFetcher;
    QVector<Package> m_allPackages;
    int m_displayedCount = 0;

    // Header widgets
    QLineEdit *m_searchBox;
    QPushButton *m_homeBtn;
    QPushButton *m_backBtn;

    // Home page widgets
    QLabel *m_countLabel;
    QWidget *m_gridHost;
    QGridLayout *m_gridLayout;
    QWidget *m_emptyState;
    QPushButton *m_loadMoreBtn;

    // Navigation
    QStackedWidget *m_stack;
    DetailsView *m_detailsView;

    QDir m_cacheDir;

    QWidget *buildHeader();
    QWidget *buildHomePage();

    void populateGrid(QVector<Package> pkgs);
    void appendPage();
    void addCardToGrid(const Package &pkg, int accentIdx, int index);
    void showDetails(const Package &pkg, int accentIdx);
    void goHome();
    static int gridColumns(int width);
};
