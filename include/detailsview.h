#pragma once
#include "package.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class DetailsView : public QWidget
{
    Q_OBJECT
public:
    explicit DetailsView(QWidget *parent = nullptr);

    void show(const Package &pkg, int accentIdx);
    QLabel *iconLabel() const { return m_iconLabel; }
    int currentAccent() const { return m_accentIdx; }
    const Package &currentPackage() const { return m_pkg; }

signals:
    void installRequested(Package pkg);
    void removeRequested(Package pkg);

private:
    QLabel *m_iconLabel;
    QLabel *m_title;
    QLabel *m_publisher;
    QLabel *m_description;
    QHBoxLayout *m_actionLayout;
    Package m_pkg;
    int m_accentIdx = 0;
};
