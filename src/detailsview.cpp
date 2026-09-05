#include "detailsview.h"
#include "theme.h"
#include <QVBoxLayout>
#include <QFrame>
#include <QGridLayout>

DetailsView::DetailsView(PacmanManager *pacman, QWidget *parent) 
    : QWidget(parent), m_pacman(pacman)
{
    connect(m_pacman, &PacmanManager::detailsReady, this, &DetailsView::onDetailsReady);

    auto *outer = new QVBoxLayout(this);
    outer->setContentsMargins(64, 48, 64, 48);
    outer->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    outer->setSpacing(24);

    // Header section
    auto *headerWidget = new QWidget(this);
    auto *headerLayout = new QHBoxLayout(headerWidget);
    headerLayout->setContentsMargins(0, 0, 0, 0);
    headerLayout->setSpacing(32);

    m_iconLabel = new QLabel(this);
    m_iconLabel->setFixedSize(128, 128);
    m_iconLabel->setAlignment(Qt::AlignCenter);
    headerLayout->addWidget(m_iconLabel);

    auto *headerTextLayout = new QVBoxLayout();
    headerTextLayout->setAlignment(Qt::AlignVCenter);
    headerTextLayout->setSpacing(8);

    m_title = new QLabel("App Title", this);
    m_title->setObjectName("DetailsTitle");
    m_title->setStyleSheet("font-size: 36px; font-weight: bold;");
    headerTextLayout->addWidget(m_title);

    m_publisher = new QLabel("Repo \u2022 Version", this);
    m_publisher->setObjectName("DetailsPub");
    m_publisher->setStyleSheet("font-size: 16px; color: #888;");
    headerTextLayout->addWidget(m_publisher);

    auto *actionWrap = new QWidget(this);
    m_actionLayout = new QHBoxLayout(actionWrap);
    m_actionLayout->setContentsMargins(0, 12, 0, 0);
    m_actionLayout->setAlignment(Qt::AlignLeft);
    headerTextLayout->addWidget(actionWrap);

    headerLayout->addLayout(headerTextLayout);
    headerLayout->addStretch();
    outer->addWidget(headerWidget);

    // Divider
    auto *div1 = new QFrame(this);
    div1->setFrameShape(QFrame::HLine);
    div1->setStyleSheet("background-color: #333;");
    outer->addWidget(div1);

    m_description = new QLabel("Description...", this);
    m_description->setObjectName("DetailsDesc");
    m_description->setWordWrap(true);
    m_description->setMaximumWidth(800);
    m_description->setStyleSheet("font-size: 18px; line-height: 1.5;");
    outer->addWidget(m_description);

    // Stats section
    m_statsWidget = new QWidget(this);
    m_statsLayout = new QVBoxLayout(m_statsWidget);
    m_statsLayout->setContentsMargins(0, 24, 0, 24);
    m_statsLayout->setSpacing(8);
    outer->addWidget(m_statsWidget);

    // Suggestions Section
    auto *div3 = new QFrame(this);
    div3->setFrameShape(QFrame::HLine);
    div3->setStyleSheet("background-color: #333; margin-top: 48px; margin-bottom: 24px;");
    outer->addWidget(div3);
    
    auto *suggTitle = new QLabel("You Might Also Like", this);
    suggTitle->setStyleSheet("font-size: 24px; font-weight: bold; margin-bottom: 12px;");
    outer->addWidget(suggTitle);

    auto *suggLayout = new QHBoxLayout();
    suggLayout->setSpacing(16);
    QStringList suggestions = {"blender", "gimp", "discord", "vlc"};
    for(int i=0; i<4; ++i) {
        auto *lbl = new QLabel(prettifyName(suggestions[i]), this);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setFixedSize(140, 70);
        lbl->setStyleSheet("background-color: #222; border-radius: 12px; font-weight: bold; font-size: 16px; border: 1px solid #444; color: #eee;");
        suggLayout->addWidget(lbl);
    }
    suggLayout->addStretch();
    outer->addLayout(suggLayout);

    outer->addStretch();
}

void DetailsView::show(const Package &pkg, int accentIdx)
{
    m_pkg = pkg;
    m_accentIdx = accentIdx;

    m_title->setText(prettifyName(pkg.name));
    m_publisher->setText(QStringLiteral("%1 \u2022 %2").arg(pkg.repo, pkg.version));
    m_description->setText(pkg.description.isEmpty() ? "No description available." : pkg.description);

    const QString accent = Theme::accentColor(accentIdx);
    m_iconLabel->setPixmap(QPixmap());
    m_iconLabel->setText(QStringLiteral("\u27F3"));
    m_iconLabel->setStyleSheet(QStringLiteral(
        "QLabel { background-color: %1; border-radius: 32px; font-size: 48px; color: %1; }"
    ).arg(accent));

    QLayoutItem *item;
    while ((item = m_actionLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    if (pkg.installed) {
        auto *btn = new QPushButton("Remove \u2717", this);
        btn->setObjectName("BtnRemove");
        btn->setCursor(Qt::PointingHandCursor);
        btn->setFixedSize(140, 40);
        btn->setStyleSheet("background-color: #d32f2f; color: white; border-radius: 8px; font-weight: bold; font-size: 16px;");
        connect(btn, &QPushButton::clicked, this, [this]() { emit removeRequested(m_pkg); });
        m_actionLayout->addWidget(btn);
    } else {
        auto *btn = new QPushButton("Install \u2713", this);
        btn->setObjectName("BtnInstall");
        btn->setCursor(Qt::PointingHandCursor);
        btn->setFixedSize(140, 40);
        btn->setStyleSheet(QString("background-color: %1; color: white; border-radius: 8px; font-weight: bold; font-size: 16px;").arg(accent));
        connect(btn, &QPushButton::clicked, this, [this]() { emit installRequested(m_pkg); });
        m_actionLayout->addWidget(btn);
    }

    while ((item = m_statsLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    auto *loading = new QLabel("Fetching package details...", this);
    loading->setStyleSheet("color: #888; font-style: italic;");
    m_statsLayout->addWidget(loading);

    m_pacman->fetchDetails(pkg.name);
}

void DetailsView::onDetailsReady(PackageDetails details)
{
    QLayoutItem *item;
    while ((item = m_statsLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    
    auto *depsTitle = new QLabel("Dependencies", this);
    depsTitle->setStyleSheet("font-size: 20px; font-weight: bold; margin-top: 24px;");
    m_statsLayout->addWidget(depsTitle);
    
    if (details.dependencies.isEmpty()) {
        m_statsLayout->addWidget(new QLabel("No additional packages required.", this));
    } else {
        QGridLayout *depsGrid = new QGridLayout();
        depsGrid->setSpacing(12);
        int row = 0;
        for (const auto &dep : details.dependencies) {
            auto *lblName = new QLabel(dep.name, this);
            lblName->setStyleSheet("color: #bbb;");
            auto *lblSize = new QLabel(formatSize(dep.sizeBytes), this);
            lblSize->setStyleSheet("color: #888;");
            lblSize->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            depsGrid->addWidget(lblName, row, 0);
            depsGrid->addWidget(lblSize, row, 1);
            row++;
        }
        m_statsLayout->addLayout(depsGrid);
        
        auto *lblTotalDeps = new QLabel(QString("Total Dependencies Size: %1").arg(formatSize(details.totalDepsBytes)), this);
        lblTotalDeps->setStyleSheet("font-weight: bold; color: #aaa; margin-top: 8px;");
        m_statsLayout->addWidget(lblTotalDeps);
    }
    
    auto *div2 = new QFrame(this);
    div2->setFrameShape(QFrame::HLine);
    div2->setStyleSheet("background-color: #333; margin-top: 16px; margin-bottom: 16px;");
    m_statsLayout->addWidget(div2);
    
    auto *lblAppSize = new QLabel(QString("App Size: %1").arg(formatSize(details.appSizeBytes)), this);
    lblAppSize->setStyleSheet("font-size: 16px; font-weight: bold;");
    m_statsLayout->addWidget(lblAppSize);
    
    auto *lblTotal = new QLabel(QString("Total Size (App + Dependencies): %1").arg(formatSize(details.totalBytes)), this);
    lblTotal->setStyleSheet(QString("font-size: 18px; font-weight: bold; color: %1;").arg(Theme::accentColor(m_accentIdx)));
    m_statsLayout->addWidget(lblTotal);
}
