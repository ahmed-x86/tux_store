#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-vectorcraft-id-1"
VERSION="${TUX_VAR_LATEST_VERSION:-}"

case "$VERSION" in
    ""|unknown)
        echo "Could not work out the latest VectorCraft version. Check your internet connection and try again."
        exit 1
        ;;
esac

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

URL="https://github.com/storytold/vectorcraft/releases/download/v${VERSION}/vectorcraft-${VERSION}-linux-x86_64.AppImage"

curl -L --fail --retry 3 --progress-bar \
    -o "$BUILD_DIR/vectorcraft.AppImage" \
    "$URL"

chmod +x "$BUILD_DIR/vectorcraft.AppImage"
