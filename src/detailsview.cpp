#include "detailsview.h"
#include "theme.h"
#include <QVBoxLayout>

DetailsView::DetailsView(QWidget *parent) : QWidget(parent)
{
    auto *outer = new QVBoxLayout(this);
    outer->setContentsMargins(48, 48, 48, 48);
    outer->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    outer->setSpacing(12);

    m_iconLabel = new QLabel(this);
    m_iconLabel->setFixedSize(128, 128);
    m_iconLabel->setAlignment(Qt::AlignCenter);
    outer->addWidget(m_iconLabel, 0, Qt::AlignHCenter);

    m_title = new QLabel("App Title", this);
    m_title->setObjectName("DetailsTitle");
    m_title->setAlignment(Qt::AlignCenter);
    outer->addWidget(m_title);

    m_publisher = new QLabel("Repo \u2022 Version", this);
    m_publisher->setObjectName("DetailsPub");
    m_publisher->setAlignment(Qt::AlignCenter);
    outer->addWidget(m_publisher);

    m_description = new QLabel("Description...", this);
    m_description->setObjectName("DetailsDesc");
    m_description->setAlignment(Qt::AlignCenter);
    m_description->setWordWrap(true);
    m_description->setMaximumWidth(560);
    outer->addWidget(m_description, 0, Qt::AlignHCenter);

    auto *actionWrap = new QWidget(this);
    m_actionLayout = new QHBoxLayout(actionWrap);
    m_actionLayout->setContentsMargins(0, 12, 0, 0);
    outer->addWidget(actionWrap, 0, Qt::AlignHCenter);

    outer->addStretch();
}

void DetailsView::show(const Package &pkg, int accentIdx)
{
    m_pkg = pkg;
    m_accentIdx = accentIdx;

    m_title->setText(prettifyName(pkg.name));
    m_publisher->setText(QStringLiteral("%1 \u2022 %2").arg(pkg.repo, pkg.version));
    m_description->setText(pkg.description.isEmpty() ? "No description available." : pkg.description);

    // Reset icon to spinner placeholder with accent background.
    const QString accent = Theme::accentColor(accentIdx);
    m_iconLabel->setPixmap(QPixmap());
    m_iconLabel->setText(QStringLiteral("\u27F3"));
    m_iconLabel->setStyleSheet(QStringLiteral(
        "QLabel { background-color: %1; border-radius: 24px; font-size: 28px; color: %1; }"
    ).arg(accent));

    // Rebuild the action button.
    QLayoutItem *item;
    while ((item = m_actionLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    if (pkg.installed) {
        auto *btn = new QPushButton("Remove \u2717", this);
        btn->setObjectName("BtnRemove");
        btn->setCursor(Qt::PointingHandCursor);
        connect(btn, &QPushButton::clicked, this, [this]() { emit removeRequested(m_pkg); });
        m_actionLayout->addWidget(btn);
    } else {
        auto *btn = new QPushButton("Install \u2713", this);
        btn->setObjectName("BtnInstall");
        btn->setCursor(Qt::PointingHandCursor);
        connect(btn, &QPushButton::clicked, this, [this]() { emit installRequested(m_pkg); });
        m_actionLayout->addWidget(btn);
    }
}
