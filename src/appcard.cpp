#include "appcard.h"
#include "theme.h"
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QCursor>

AppCard::AppCard(const Package &pkg, int accentIdx, QWidget *parent)
    : QFrame(parent), m_pkg(pkg), m_accentIdx(accentIdx)
{
    setObjectName("AppCard");
    setFixedSize(160, 210);
    setCursor(Qt::PointingHandCursor);
    setFocusPolicy(Qt::NoFocus);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(12, 20, 12, 16);
    layout->setSpacing(4);
    layout->setAlignment(Qt::AlignHCenter);

    // Icon area: 64x64, colored background per accent, rounded via stylesheet.
    m_iconLabel = new QLabel(QStringLiteral("\u27F3"), this); // spinner glyph
    m_iconLabel->setAlignment(Qt::AlignCenter);
    m_iconLabel->setFixedSize(64, 64);
    const QString accent = Theme::accentColor(accentIdx);
    m_iconLabel->setStyleSheet(QStringLiteral(
        "QLabel { background-color: %1; border-radius: 14px; font-size: 26px; color: %1; }"
    ).arg(accent));
    layout->addWidget(m_iconLabel, 0, Qt::AlignHCenter);

    auto *name = new QLabel(prettifyName(pkg.name), this);
    name->setObjectName("AppName");
    name->setAlignment(Qt::AlignCenter);
    name->setStyleSheet("margin-top: 8px;");
    QFontMetrics fm(name->font());
    name->setText(fm.elidedText(prettifyName(pkg.name), Qt::ElideRight, 130));
    layout->addWidget(name);

    auto *publisher = new QLabel(QStringLiteral("%1 \u2022 %2").arg(pkg.repo, pkg.version), this);
    publisher->setObjectName("AppPublisher");
    publisher->setAlignment(Qt::AlignCenter);
    QFontMetrics fmPub(publisher->font());
    publisher->setText(fmPub.elidedText(publisher->text(), Qt::ElideRight, 130));
    layout->addWidget(publisher);

    auto *status = new QLabel(pkg.installed ? QStringLiteral("Installed \u2713")
                                             : QStringLiteral("Not Installed \u2717"), this);
    status->setObjectName(pkg.installed ? "AppInstalled" : "AppNotInstalled");
    status->setAlignment(Qt::AlignCenter);
    status->setStyleSheet("margin-top: 4px;");
    layout->addWidget(status);

    layout->addStretch();
}

void AppCard::setIconPixmap(const QPixmap &pm)
{
    m_iconLabel->setStyleSheet("QLabel { background-color: transparent; border-radius: 14px; }");
    m_iconLabel->setPixmap(pm);
}

void AppCard::setIconFallbackLetter()
{
    const QString letter = m_pkg.name.isEmpty() ? "?" : QString(m_pkg.name.at(0).toUpper());
    const QString accent = Theme::accentColor(m_accentIdx);
    m_iconLabel->setText(letter);
    m_iconLabel->setStyleSheet(QStringLiteral(
        "QLabel { background-color: %1; border-radius: 14px; font-size: 26px; font-weight: bold; color: #1e1e2e; }"
    ).arg(accent));
}

void AppCard::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked(m_pkg, m_accentIdx);
    QFrame::mousePressEvent(event);
}

void AppCard::enterEvent(QEnterEvent *event)
{
    setCursor(Qt::PointingHandCursor);
    QFrame::enterEvent(event);
}

void AppCard::leaveEvent(QEvent *event)
{
    QFrame::leaveEvent(event);
}
