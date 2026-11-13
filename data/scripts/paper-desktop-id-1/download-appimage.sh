#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-paper-desktop-id-1"

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

curl -L --fail --progress-bar \
    -o "$BUILD_DIR/paper-desktop.AppImage" \
    "https://download.paper.design/linux/appImage/x64"

chmod +x "$BUILD_DIR/paper-desktop.AppImage"
