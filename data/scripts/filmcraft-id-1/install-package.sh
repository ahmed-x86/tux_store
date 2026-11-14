#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-filmcraft-id-1"

PKG_FILE="$(ls "$BUILD_DIR"/filmcraft-*-x86_64.pkg.tar.zst 2>/dev/null | head -n1)"
if [ -z "$PKG_FILE" ]; then
    echo "The built package was not found."
    exit 1
fi

pacman -U --noconfirm "$PKG_FILE"
