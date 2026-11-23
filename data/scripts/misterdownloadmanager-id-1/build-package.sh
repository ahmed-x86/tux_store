#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-misterdownloadmanager-id-1"
PKGNAME="misterdownloadmanager"

PKGVER="${TUX_VAR_LATEST_VERSION:-}"
case "$PKGVER" in
    ""|unknown) PKGVER="0" ;;
esac

cd "$BUILD_DIR"

# ===== Take only the icon and the .desktop file out of the AppImage (the app itself stays a sealed AppImage) =====
rm -rf extract icon.png app.desktop
mkdir -p extract
cp misterdownloadmanager.AppImage extract/app.AppImage
if ! ( cd extract && chmod +x app.AppImage && ./app.AppImage --appimage-extract >/dev/null 2>&1 ); then
    echo "Note: could not unpack the AppImage to read its icon; using the built-in icon."
fi
ROOTFS="extract/squashfs-root"

# Icon: biggest PNG in usr/share/icons, else a PNG at the top level, else .DirIcon, else our own logo.
ICON_SRC=""
if [ -d "$ROOTFS/usr/share/icons" ]; then
    ICON_SRC="$(find "$ROOTFS/usr/share/icons" -type f -iname '*.png' -printf '%s %p\n' 2>/dev/null \
        | sort -rn | head -n1 | cut -d' ' -f2-)"
fi
if [ -z "$ICON_SRC" ] && [ -d "$ROOTFS" ]; then
    ICON_SRC="$(find "$ROOTFS" -maxdepth 1 -iname '*.png' 2>/dev/null | head -n1)"
fi
if [ -z "$ICON_SRC" ] && [ -f "$ROOTFS/.DirIcon" ] && file -L "$ROOTFS/.DirIcon" 2>/dev/null | grep -qi 'PNG image'; then
    ICON_SRC="$ROOTFS/.DirIcon"
fi
if [ -z "$ICON_SRC" ] && [ -n "${TUX_ADDON_DIR:-}" ] && [ -f "$TUX_ADDON_DIR/fallback-icon.png" ]; then
    ICON_SRC="$TUX_ADDON_DIR/fallback-icon.png"
fi
if [ -z "$ICON_SRC" ]; then
    echo "Could not find an icon inside the AppImage."
    exit 1
fi
cp -L "$ICON_SRC" icon.png

# Desktop entry: the original one when present, else a generated one.
DESKTOP_SRC=""
[ -d "$ROOTFS" ] && DESKTOP_SRC="$(find "$ROOTFS" -maxdepth 1 -iname '*.desktop' 2>/dev/null | head -n1)"
if [ -n "$DESKTOP_SRC" ]; then
    cp -L "$DESKTOP_SRC" app.desktop
else
    cat > app.desktop <<DESK
[Desktop Entry]
Type=Application
Name=Mister Download Manager
Comment=Download manager
Exec=${PKGNAME} %U
Icon=${PKGNAME}
Terminal=false
Categories=Network;Utility;
DESK
fi
rm -rf extract

# ===== PKGBUILD =====
{
    echo "pkgname=${PKGNAME}"
    echo "pkgver=${PKGVER}"
} > PKGBUILD

cat >> PKGBUILD <<'EOF'
pkgrel=1
pkgdesc="Mister Download Manager - the official AppImage wrapped as a pacman package (menu entry, icon, command)"
arch=('x86_64')
url="https://misterdownloadmanager.com/"
license=('custom')
depends=('fuse2')
options=('!strip' '!debug')

package() {
    # The AppImage itself, untouched
    install -Dm755 "${srcdir}/../misterdownloadmanager.AppImage" \
        "${pkgdir}/opt/${pkgname}/${pkgname}.AppImage"

    # Icon
    install -Dm644 "${srcdir}/../icon.png" \
        "${pkgdir}/usr/share/pixmaps/${pkgname}.png"

    # Desktop entry (the original one, with Exec/Icon fixed)
    install -Dm644 "${srcdir}/../app.desktop" \
        "${pkgdir}/usr/share/applications/${pkgname}.desktop"
    sed -i "s|^Exec=.*|Exec=/usr/bin/${pkgname} %U|" "${pkgdir}/usr/share/applications/${pkgname}.desktop"
    sed -i "s|^Icon=.*|Icon=${pkgname}|"              "${pkgdir}/usr/share/applications/${pkgname}.desktop"
    sed -i "/^TryExec=/d"                              "${pkgdir}/usr/share/applications/${pkgname}.desktop"

    # Launch command in /usr/bin
    install -d "${pkgdir}/usr/bin"
    printf '%s\n' '#!/usr/bin/env bash' \
        'exec "/opt/misterdownloadmanager/misterdownloadmanager.AppImage" "$@"' \
        > "${pkgdir}/usr/bin/${pkgname}"
    chmod 755 "${pkgdir}/usr/bin/${pkgname}"
}
EOF

# ===== Build (must not run as root) =====
makepkg -f
