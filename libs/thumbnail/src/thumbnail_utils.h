#pragma once
// Utility functions used internally by libthumbnail.
// Not part of the public API.

#include <QString>
#include <string>
#include <string_view>

/**
 * Strips common Arch Linux package-name suffixes iteratively using
 * zero-allocation std::string_view matching:
 *   "foo-bin-git" -> "foo-bin" -> "foo"
 *
 * The core loop operates entirely on a string_view (no heap allocations);
 * a std::string is materialised only once at the very end.
 *
 * Used by IconFetcher to generate icon-name candidates.
 */

/// Core implementation: zero-allocation loop over a string_view.
std::string sanitizeNameSV(std::string_view name);

/// QString convenience overload (single conversion in, single conversion out).
QString sanitizeName(const QString &name);
