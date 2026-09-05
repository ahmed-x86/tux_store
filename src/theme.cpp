#include "theme.h"

namespace Theme {

const std::array<const char *, 14> kAccentColors = {
    "#89b4fa", "#cba6f7", "#74c7ec", "#b4befe", "#94e2d5", "#a6e3a1", "#f9e2af", "#fab387",
    "#eba0ab", "#f38ba8", "#f2cdcd", "#f5c2e7", "#89dceb", "#f5e0dc",
};

QString accentColor(int idx)
{
    return QString::fromLatin1(kAccentColors[idx % kAccentColors.size()]);
}

QString styleSheet()
{
    return QStringLiteral(R"(
/* ── Global reset: kill all platform focus rectangles / native theming ── */
* {
    outline: none;
    selection-background-color: #585b70;
    selection-color: #cdd6f4;
}
QWidget { outline: none; }
QWidget:focus { outline: none; }
QAbstractScrollArea { border: none; }
QScrollArea { border: none; background: transparent; }
QScrollArea > QWidget > QWidget { background: transparent; }

QWidget#Root { background-color: #1e1e2e; color: #cdd6f4; }

QWidget#HeaderBar { background-color: #181825; border-bottom: 1px solid #313244; }
QLabel#LogoEmoji { font-size: 26px; }
QLabel#BrandTitle { color: #b4befe; font-weight: bold; font-size: 20px; }
QLabel#BrandSubtitle { color: #7f849c; font-size: 12px; }

QLineEdit#SearchBox {
    background-color: #313244; color: #cdd6f4;
    border: 1px solid #45475a; border-radius: 12px;
    padding: 6px 12px; font-size: 14px;
}
QLineEdit#SearchBox:focus { border: 1px solid #89b4fa; outline: none; }

QPushButton#NavBtn {
    background-color: #313244; color: #cdd6f4;
    border: 1px solid #45475a; border-radius: 12px;
    padding: 6px 16px; font-weight: bold;
    outline: none;
}
QPushButton#NavBtn:hover { background-color: #45475a; color: #89b4fa; }
QPushButton#NavBtn:focus { border: 1px solid #45475a; outline: none; }
QPushButton#NavBtn:pressed { background-color: #585b70; }

QLabel#SectionStar { color: #cba6f7; font-size: 16px; background: transparent; }
QLabel#SectionTitle { color: #cdd6f4; font-weight: bold; font-size: 18px; background: transparent; }
QLabel#SectionCount { color: #7f849c; font-size: 13px; background: transparent; }

QFrame#AppCard {
    background-color: #313244; border: 1px solid #45475a; border-radius: 16px;
    outline: none;
}
QFrame#AppCard:hover { background-color: #45475a; border: 1px solid #585b70; }
QFrame#AppCard:focus { outline: none; border: 1px solid #45475a; }
QLabel#AppName { color: #cdd6f4; font-weight: bold; font-size: 13px; background: transparent; }
QLabel#AppPublisher { color: #7f849c; font-size: 11px; background: transparent; }
QLabel#AppInstalled { color: #a6e3a1; font-size: 11px; font-weight: bold; background: transparent; }
QLabel#AppNotInstalled { color: #6c7086; font-size: 11px; font-weight: bold; background: transparent; }

QLabel#EmptyIcon { font-size: 44px; background: transparent; }
QLabel#EmptyTitle { color: #a6adc8; font-size: 17px; background: transparent; }

QLabel#DetailsTitle { font-size: 30px; font-weight: bold; color: #cdd6f4; background: transparent; }
QLabel#DetailsPub { font-size: 14px; color: #7f849c; background: transparent; }
QLabel#DetailsDesc { font-size: 15px; color: #bac2de; background: transparent; }

QPushButton#BtnInstall {
    background-color: #a6e3a1; color: #11111b; font-weight: bold;
    border-radius: 18px; padding: 10px 40px; font-size: 15px; border: none;
    outline: none;
}
QPushButton#BtnInstall:hover { background-color: #94e2d5; }
QPushButton#BtnInstall:pressed { background-color: #81c8a4; }
QPushButton#BtnInstall:focus { outline: none; border: none; }

QPushButton#BtnRemove {
    background-color: #f38ba8; color: #11111b; font-weight: bold;
    border-radius: 18px; padding: 10px 40px; font-size: 15px; border: none;
    outline: none;
}
QPushButton#BtnRemove:hover { background-color: #eba0ac; }
QPushButton#BtnRemove:pressed { background-color: #d88a96; }
QPushButton#BtnRemove:focus { outline: none; border: none; }

QPushButton#LoadMoreBtn {
    background-color: #313244; color: #b4befe;
    border: 1px solid #45475a; border-radius: 12px;
    padding: 10px; font-weight: bold; font-size: 13px;
    outline: none;
}
QPushButton#LoadMoreBtn:hover { background-color: #45475a; color: #89b4fa; }
QPushButton#LoadMoreBtn:focus { outline: none; border: 1px solid #45475a; }

QScrollBar:vertical { background: transparent; width: 10px; margin: 0; }
QScrollBar::handle:vertical { background: #45475a; border-radius: 5px; min-height: 24px; }
QScrollBar::handle:vertical:hover { background: #585b70; }
QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }
QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: transparent; }

QToolTip {
    background-color: #181825; color: #cdd6f4;
    border: 1px solid #45475a; padding: 4px 8px; border-radius: 6px;
}

QMessageBox { background-color: #1e1e2e; color: #cdd6f4; }
QMessageBox QLabel { color: #cdd6f4; background: transparent; }
QMessageBox QPushButton {
    background-color: #313244; color: #cdd6f4;
    border: 1px solid #45475a; border-radius: 8px; padding: 6px 16px;
}
QMessageBox QPushButton:hover { background-color: #45475a; }
)");
}

} // namespace Theme
