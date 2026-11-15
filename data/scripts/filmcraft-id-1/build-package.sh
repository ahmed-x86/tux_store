#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-filmcraft-id-1"
PKGNAME="filmcraft"

PKGVER="${TUX_VAR_LATEST_VERSION:-}"
case "$PKGVER" in
    ""|unknown) PKGVER="0" ;;
esac

cd "$BUILD_DIR"

# ============ استخراج الأيقونة وملف desktop فقط (البرنامج نفسه يبقى AppImage سليم) ============
rm -rf extract
mkdir -p extract
cp filmcraft.AppImage extract/app.AppImage
(
    cd extract
    chmod +x app.AppImage
    ./app.AppImage --appimage-extract >/dev/null
)
ICON_SRC="$(find extract/squashfs-root -maxdepth 2 -iname "*.png" | head -n1)"
DESKTOP_SRC="$(find extract/squashfs-root -maxdepth 1 -iname "*.desktop" | head -n1)"

if [ -z "$ICON_SRC" ] || [ -z "$DESKTOP_SRC" ]; then
    echo "Could not find the icon or the desktop file inside the AppImage."
    exit 1
fi

cp "$ICON_SRC" icon.png
cp "$DESKTOP_SRC" app.desktop
rm -rf extract

# ============ كتابة PKGBUILD ============
cat > PKGBUILD <<EOF
pkgname=${PKGNAME}
pkgver=${PKGVER}
pkgrel=1
pkgdesc="FilmCraft — filmmaking app from the ArtCraft suite"
arch=('x86_64')
license=('custom')
depends=('fuse2')
options=('!strip')

package() {
    # الـ AppImage نفسه كما هو، بدون فك
    install -Dm755 "\${srcdir}/../filmcraft.AppImage" \\
        "\${pkgdir}/opt/${PKGNAME}/${PKGNAME}.AppImage"

    # الأيقونة
    install -Dm644 "\${srcdir}/../icon.png" \\
        "\${pkgdir}/usr/share/pixmaps/${PKGNAME}.png"

    # ملف الـ desktop (نفس الأصلي، بس نصحح Exec/Icon)
    install -Dm644 "\${srcdir}/../app.desktop" \\
        "\${pkgdir}/usr/share/applications/${PKGNAME}.desktop"
    sed -i "s|^Exec=.*|Exec=/usr/bin/${PKGNAME} %U|" \\
        "\${pkgdir}/usr/share/applications/${PKGNAME}.desktop"
    sed -i "s|^Icon=.*|Icon=${PKGNAME}|" \\
        "\${pkgdir}/usr/share/applications/${PKGNAME}.desktop"

    # أمر تشغيل مباشر في /usr/bin
    install -d "\${pkgdir}/usr/bin"
    cat > "\${pkgdir}/usr/bin/${PKGNAME}" <<'WRAP'
#!/usr/bin/env bash
exec "/opt/filmcraft/filmcraft.AppImage" "\$@"
WRAP
    chmod 755 "\${pkgdir}/usr/bin/${PKGNAME}"
}
EOF

# ============ البناء (لا يصح تشغيله كـ root) ============
makepkg -f
