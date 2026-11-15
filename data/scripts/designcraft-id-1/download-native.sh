#!/bin/bash
# Downloads the official Arch package (.pkg.tar.zst) published on GitHub.
set -e
BUILD_DIR="/tmp/tux-store-designcraft-id-1"
VERSION="${TUX_VAR_LATEST_VERSION:-}"

case "$VERSION" in
    ""|unknown)
        echo "Could not work out the latest DesignCraft version. Check your internet connection and try again."
        exit 1
        ;;
esac

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR/native"

FILE="designcraft-${VERSION}-linux-x86_64.pkg.tar.zst"
URL="https://github.com/storytold/designcraft/releases/download/v${VERSION}/${FILE}"

curl -L --fail --retry 3 --progress-bar \
    -o "$BUILD_DIR/native/$FILE" \
    "$URL"

# sanity check: a real package is several MB, an error page is not
size="$(stat -c %s "$BUILD_DIR/native/$FILE" 2>/dev/null || echo 0)"
if [ "$size" -lt 1000000 ]; then
    echo "The downloaded file looks wrong ($size bytes)."
    exit 1
fi
