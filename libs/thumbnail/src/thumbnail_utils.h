#pragma once
// Utility functions used internally by libthumbnail.
// Not part of the public API.

#include <QString>

/**
 * Strips common Arch Linux package-name suffixes iteratively:
 *   "foo-bin-git" -> "foo-bin" -> "foo"
 * Used by IconFetcher to generate icon-name candidates.
 */
QString sanitizeName(const QString &name);
