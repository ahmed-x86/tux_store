#include "mainwindow.h"
#include "appcard.h"
#include "theme.h"
#include "log.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Tux Store");
    resize(960, 700);

    m_cacheDir = QDir(QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.cache/tux_store/icons");
    m_pacman = new PacmanManager(this);
    m_iconFetcher = new IconFetcher(m_cacheDir, this);

    auto *root = new QWidget(this);
    root->setObjectName("Root");
    root->setStyleSheet(Theme::styleSheet());
    setCentralWidget(root);

    auto *rootLayout = new QVBoxLayout(root);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    rootLayout->addWidget(buildHeader());

    m_stack = new QStackedWidget(root);
    rootLayout->addWidget(m_stack, 1);

    m_stack->addWidget(buildHomePage());

    m_detailsView = new DetailsView(m_pacman, m_stack);
    auto *detailsScroll = new QScrollArea(m_stack);
    detailsScroll->setWidgetResizable(true);
    detailsScroll->setFrameShape(QFrame::NoFrame);
    detailsScroll->setWidget(m_detailsView);
    m_stack->addWidget(detailsScroll);

    connect(m_detailsView, &DetailsView::installRequested, this, [](const Package &p) {
        QMessageBox::information(nullptr, "Install", "Would run: pacman -S " + p.name);
    });
    connect(m_detailsView, &DetailsView::removeRequested, this, [](const Package &p) {
        QMessageBox::information(nullptr, "Remove", "Would run: pacman -R " + p.name);
    });

    connect(m_pacman, &PacmanManager::resultsReady, this, &MainWindow::populateGrid);
    connect(m_iconFetcher, &IconFetcher::iconReady, this, [this](const QString &name, QPixmap pm) {
        // Update any visible card matching this app name (icon area scaled to 52px on cards).
        for (int i = 0; i < m_gridLayout->count(); ++i) {
            if (auto *card = qobject_cast<AppCard *>(m_gridLayout->itemAt(i)->widget())) {
                if (card->package().name == name)
                    card->setIconPixmap(pm.scaled(52, 52, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }
        }
        if (m_detailsView->currentPackage().name == name) {
            m_detailsView->iconLabel()->setStyleSheet("background: transparent; border-radius: 24px;");
            m_detailsView->iconLabel()->setPixmap(pm.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    });
    connect(m_iconFetcher, &IconFetcher::iconFailed, this, [this](const QString &name) {
        for (int i = 0; i < m_gridLayout->count(); ++i) {
            if (auto *card = qobject_cast<AppCard *>(m_gridLayout->itemAt(i)->widget())) {
                if (card->package().name == name)
                    card->setIconFallbackLetter();
            }
        }
        if (m_detailsView->currentPackage().name == name) {
            const QString letter = name.isEmpty() ? "?" : QString(name.at(0).toUpper());
            const QString accent = Theme::accentColor(0);
            m_detailsView->iconLabel()->setText(letter);
        }
    });

    qCInfo(logUi) << "MainWindow constructed, requesting default packages";
    m_pacman->fetchDefaults();
}

// ---------------------------------------------------------------------------
QWidget *MainWindow::buildHeader()
{
    auto *header = new QWidget(this);
    header->setObjectName("HeaderBar");
    header->setFixedHeight(72);

    auto *layout = new QHBoxLayout(header);
    layout->setContentsMargins(32, 12, 32, 12);
    layout->setSpacing(12);

    auto *logo = new QLabel(QStringLiteral("\U0001F427"), header); // penguin emoji
    logo->setObjectName("LogoEmoji");
    layout->addWidget(logo);

    auto *titleBox = new QVBoxLayout();
    auto *title = new QLabel("Tux Store", header);
    title->setObjectName("BrandTitle");
    auto *subtitle = new QLabel("for Arch Linux", header);
    subtitle->setObjectName("BrandSubtitle");
    titleBox->addWidget(title);
    titleBox->addWidget(subtitle);
    titleBox->setSpacing(0);
    layout->addLayout(titleBox);

    layout->addStretch(1);

    m_backBtn = new QPushButton("\u276E Back", header);
    m_backBtn->setObjectName("NavBtn");
    m_backBtn->setCursor(Qt::PointingHandCursor);
    m_backBtn->setVisible(false);
    connect(m_backBtn, &QPushButton::clicked, this, &MainWindow::goHome);
    layout->addWidget(m_backBtn);

    m_homeBtn = new QPushButton("\U0001F3E0 Home", header);
    m_homeBtn->setObjectName("NavBtn");
    m_homeBtn->setCursor(Qt::PointingHandCursor);
    connect(m_homeBtn, &QPushButton::clicked, this, &MainWindow::goHome);
    layout->addWidget(m_homeBtn);

    m_searchBox = new QLineEdit(header);
    m_searchBox->setObjectName("SearchBox");
    m_searchBox->setPlaceholderText("Search pacman (Press Enter)...");
    m_searchBox->setFixedWidth(320);
    connect(m_searchBox, &QLineEdit::returnPressed, this, [this]() {
        m_countLabel->setText("Searching pacman...");
        m_pacman->search(m_searchBox->text());
    });
    layout->addWidget(m_searchBox);

    return header;
}

// ---------------------------------------------------------------------------
QWidget *MainWindow::buildHomePage()
{
    auto *page = new QWidget(this);
    auto *pageLayout = new QVBoxLayout(page);
    pageLayout->setContentsMargins(0, 0, 0, 0);
    pageLayout->setSpacing(0);

    auto *sectionBox = new QWidget(page);
    auto *sectionLayout = new QHBoxLayout(sectionBox);
    sectionLayout->setContentsMargins(32, 20, 32, 10);
    sectionLayout->setSpacing(8);

    auto *star = new QLabel(QStringLiteral("\u2726"), sectionBox);
    star->setObjectName("SectionStar");
    sectionLayout->addWidget(star);

    auto *title = new QLabel("Packages", sectionBox);
    title->setObjectName("SectionTitle");
    sectionLayout->addWidget(title);

    m_countLabel = new QLabel("(0)", sectionBox);
    m_countLabel->setObjectName("SectionCount");
    sectionLayout->addWidget(m_countLabel);
    sectionLayout->addStretch();

    pageLayout->addWidget(sectionBox);

    // Scrollable content: grid + load-more + empty state
    auto *scroll = new QScrollArea(page);
    scroll->setWidgetResizable(true);
    scroll->setFrameShape(QFrame::NoFrame);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    auto *content = new QWidget(scroll);
    auto *contentLayout = new QVBoxLayout(content);
    contentLayout->setContentsMargins(32, 0, 32, 32);
    contentLayout->setSpacing(16);

    m_gridHost = new QWidget(content);
    m_gridLayout = new QGridLayout(m_gridHost);
    m_gridLayout->setSpacing(16);
    m_gridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    contentLayout->addWidget(m_gridHost);

    m_loadMoreBtn = new QPushButton("Load More", content);
    m_loadMoreBtn->setObjectName("LoadMoreBtn");
    m_loadMoreBtn->setCursor(Qt::PointingHandCursor);
    m_loadMoreBtn->setVisible(false);
    connect(m_loadMoreBtn, &QPushButton::clicked, this, &MainWindow::appendPage);
    contentLayout->addWidget(m_loadMoreBtn);

    m_emptyState = new QWidget(content);
    auto *emptyLayout = new QVBoxLayout(m_emptyState);
    emptyLayout->setAlignment(Qt::AlignHCenter);
    auto *emptyIcon = new QLabel(QStringLiteral("\U0001F50D"), m_emptyState);
    emptyIcon->setObjectName("EmptyIcon");
    emptyIcon->setAlignment(Qt::AlignCenter);
    auto *emptyTitle = new QLabel("No packages found", m_emptyState);
    emptyTitle->setObjectName("EmptyTitle");
    emptyLayout->addWidget(emptyIcon);
    emptyLayout->addWidget(emptyTitle);
    m_emptyState->setVisible(false);
    contentLayout->addWidget(m_emptyState);

    contentLayout->addStretch();
    scroll->setWidget(content);
    pageLayout->addWidget(scroll, 1);

    return page;
}

// ---------------------------------------------------------------------------
int MainWindow::gridColumns(int width)
{
    // 160px card + 16px spacing, min 2 / max 8 columns — mirrors the original FlowBox limits.
    const int cardSpan = 160 + 16;
    int cols = qMax(2, (width - 64) / cardSpan);
    return qMin(cols, 8);
}

void MainWindow::addCardToGrid(const Package &pkg, int accentIdx, int index)
{
    auto *card = new AppCard(pkg, accentIdx, m_gridHost);
    connect(card, &AppCard::clicked, this, &MainWindow::showDetails);

    const int cols = gridColumns(m_gridHost->width() > 0 ? m_gridHost->width() : width());
    m_gridLayout->addWidget(card, index / cols, index % cols);

    m_iconFetcher->request(pkg.name, 52);
}

void MainWindow::populateGrid(QVector<Package> pkgs)
{
    qCInfo(logUi) << "populateGrid: received" << pkgs.size() << "packages";

    // Clear existing cards.
    QLayoutItem *item;
    int cleared = 0;
    while ((item = m_gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
        cleared++;
    }
    qCDebug(logUi) << "cleared" << cleared << "old cards";

    m_allPackages = std::move(pkgs);
    m_displayedCount = 0;

    const int total = m_allPackages.size();
    m_emptyState->setVisible(total == 0);

    const int firstPageEnd = qMin(kPageSize, total);
    qCDebug(logUi) << "rendering first page:" << firstPageEnd << "of" << total;
    for (int i = 0; i < firstPageEnd; ++i)
        addCardToGrid(m_allPackages[i], i % 14, i);
    m_displayedCount = firstPageEnd;
    qCInfo(logUi) << "populateGrid done, requested icons for" << firstPageEnd << "cards";

    if (total <= kPageSize)
        m_countLabel->setText(QStringLiteral("(%1 packages)").arg(total));
    else
        m_countLabel->setText(QStringLiteral("(%1 packages, showing %2)").arg(total).arg(firstPageEnd));

    const int remaining = total - firstPageEnd;
    if (remaining > 0) {
        m_loadMoreBtn->setText(QStringLiteral("Load More (%1 remaining)").arg(remaining));
        m_loadMoreBtn->setVisible(true);
    } else {
        m_loadMoreBtn->setVisible(false);
    }
}

void MainWindow::appendPage()
{
    const int total = m_allPackages.size();
    const int start = m_displayedCount;
    const int end = qMin(start + kPageSize, total);

    for (int i = start; i < end; ++i)
        addCardToGrid(m_allPackages[i], i % 14, i);
    m_displayedCount = end;

    const int remaining = total - end;
    if (remaining > 0)
        m_loadMoreBtn->setText(QStringLiteral("Load More (%1 remaining)").arg(remaining));
    else
        m_loadMoreBtn->setVisible(false);

    m_countLabel->setText(QStringLiteral("(%1 packages, showing %2)").arg(total).arg(end));
}

void MainWindow::showDetails(const Package &pkg, int accentIdx)
{
    m_detailsView->show(pkg, accentIdx);
    m_iconFetcher->request(pkg.name, 100);

    m_stack->setCurrentIndex(1);
    m_searchBox->setVisible(false);
    m_homeBtn->setVisible(false);
    m_backBtn->setVisible(true);
}

void MainWindow::goHome()
{
    m_searchBox->clear();
    m_stack->setCurrentIndex(0);
    m_backBtn->setVisible(false);
    m_searchBox->setVisible(true);
    m_homeBtn->setVisible(true);

    m_countLabel->setText("Loading...");
    m_pacman->fetchDefaults();
}
