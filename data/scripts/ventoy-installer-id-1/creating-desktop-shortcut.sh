#!/bin/bash
set -e
dest="$HOME/.local/share/ventoy"
app_dir="$HOME/.local/share/applications"
mkdir -p "$app_dir"
desktop_file="$app_dir/ventoy.desktop"

cat << EOF > "$desktop_file"
[Desktop Entry]
Name=Ventoy
Comment=Create bootable USB easily
Exec=pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY $dest/VentoyGUI.x86_64
Path=$dest
Icon=$dest/document/ventoy.png
Terminal=false
Type=Application
Categories=System;Utility;
EOF

chmod +x "$desktop_file"
