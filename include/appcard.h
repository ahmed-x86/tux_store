#pragma once
#include "package.h"
#include <QFrame>
#include <QLabel>

// A fixed-size (160x210) card widget representing one package in the grid.
// Icon area is a 64x64 QLabel that starts as a spinner glyph and gets
// swapped for a real pixmap (or a colored letter fallback) asynchronously.
class AppCard : public QFrame
{
    Q_OBJECT
public:
    explicit AppCard(const Package &pkg, int accentIdx, QWidget *parent = nullptr);

    const Package &package() const { return m_pkg; }
    int accentIndex() const { return m_accentIdx; }
    QLabel *iconLabel() const { return m_iconLabel; }

    void setIconPixmap(const QPixmap &pm);
    void setIconFallbackLetter();

signals:
    void clicked(Package pkg, int accentIdx);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    Package m_pkg;
    int m_accentIdx;
    QLabel *m_iconLabel;
};
