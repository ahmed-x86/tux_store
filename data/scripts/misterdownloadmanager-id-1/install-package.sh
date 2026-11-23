#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-misterdownloadmanager-id-1"

PKG_FILE="$(ls "$BUILD_DIR"/misterdownloadmanager-*.pkg.tar* 2>/dev/null | grep -v '\.sig$' | head -n1)"
if [ -z "$PKG_FILE" ]; then
    echo "The built package was not found."
    exit 1
fi

pacman -U --noconfirm "$PKG_FILE"
