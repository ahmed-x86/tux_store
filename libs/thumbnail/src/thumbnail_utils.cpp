#include "thumbnail_utils.h"

#include <array>
#include <string_view>

// ---------------------------------------------------------------------------
// Zero-allocation suffix stripping using std::string_view.
//
// The inner loop checks each suffix against the *end* of the remaining view
// using C++20 std::string_view::ends_with(). No intermediate std::string or
// QString objects are created — the view simply shrinks in place. A single
// std::string allocation occurs at the very end when the result is returned.
// ---------------------------------------------------------------------------

static constexpr std::array<std::string_view, 6> kSuffixes = {
    "-git", "-bin", "-aur", "-patch", "-full", "-stable"
};

std::string sanitizeNameSV(std::string_view name)
{
    bool changed = true;
    while (changed) {
        changed = false;
        for (const auto &suf : kSuffixes) {
            if (name.size() > suf.size() && name.ends_with(suf)) {
                name.remove_suffix(suf.size());
                changed = true;
                break;   // restart from the first suffix
            }
        }
    }
    return std::string(name);
}

QString sanitizeName(const QString &name)
{
    const std::string utf8 = name.toStdString();
    std::string result = sanitizeNameSV(utf8);
    return QString::fromStdString(result);
}
