#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-misterdownloadmanager-id-1"
REPO="anefzaoui/misterdownloadmanager"
VERSION="${TUX_VAR_LATEST_VERSION:-}"

case "$VERSION" in
    ""|unknown)
        echo "Could not work out the latest Mister Download Manager version. Check your internet connection and try again."
        exit 1
        ;;
esac

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

URL="https://github.com/${REPO}/releases/download/v${VERSION}/MisterDownloadManager-${VERSION}-linux-x86_64.AppImage"

curl -L --fail --retry 3 --progress-bar \
    -o "$BUILD_DIR/misterdownloadmanager.AppImage" \
    "$URL"

# sanity check: a real AppImage is an ELF file of several MB, an error page is not
size="$(stat -c %s "$BUILD_DIR/misterdownloadmanager.AppImage" 2>/dev/null || echo 0)"
magic="$(head -c 4 "$BUILD_DIR/misterdownloadmanager.AppImage" 2>/dev/null | tail -c 3)"
if [ "$size" -lt 1000000 ] || [ "$magic" != "ELF" ]; then
    echo "The downloaded file looks wrong ($size bytes). Expected an AppImage from:"
    echo "$URL"
    exit 1
fi

chmod +x "$BUILD_DIR/misterdownloadmanager.AppImage"
