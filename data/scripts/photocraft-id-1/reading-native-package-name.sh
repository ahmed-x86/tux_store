#!/bin/bash
# Prints the real pacman package name stored inside the downloaded package
# (the official package is not called "photocraft", so we read it instead of guessing).
BUILD_DIR="/tmp/tux-store-photocraft-id-1"
PKG_FILE="$(ls "$BUILD_DIR"/native/*.pkg.tar.zst 2>/dev/null | head -n1)"
if [ -z "$PKG_FILE" ]; then
    echo "The downloaded package was not found." >&2
    exit 1
fi

name="$(pacman -Qpq "$PKG_FILE" 2>/dev/null | head -n1)"
if [ -z "$name" ]; then
    echo "Could not read the package name from $PKG_FILE." >&2
    exit 1
fi
printf '%s\n' "$name"
