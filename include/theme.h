#pragma once
#include <QString>
#include <array>

namespace Theme {
    QString styleSheet();
    extern const std::array<const char *, 14> kAccentColors;
    QString accentColor(int idx);
}
