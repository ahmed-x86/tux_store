#!/bin/bash
# Removes the WinRAR right-click menu files from every known location (only files that are ours).
rm_if() { [ -e "$1" ] && rm -f -- "$1" && echo "removed $1"; }
d="$HOME/.local/share"
rm_if "$d/nautilus-python/extensions/winrar.py"
rm_if "$d/nemo-python/extensions/winrar.py"
rm_if "$d/caja-python/extensions/winrar.py"
rm_if "$d/thunarx-python/extensions/winrar.py"
for sm in "$d/kio/servicemenus" "$d/kservices5/ServiceMenus"; do
  rm_if "$sm/winrar.desktop"
  rm_if "$sm/winrar_dolphin.py"
done
for n in winrar_compress_dialog.desktop winrar_compress_quick.desktop winrar_extract_dialog.desktop winrar_extract_here.desktop winrar_extract_to.desktop winrar_open.desktop winrar_pcmanfm.py; do
  rm_if "$d/file-manager/actions/$n"
done
exit 0
