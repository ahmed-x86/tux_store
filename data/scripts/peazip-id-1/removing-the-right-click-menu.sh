#!/bin/bash
# Removes the PeaZip right-click menu files from every known location.
rm_if() { [ -e "$1" ] && rm -f -- "$1" && echo "removed $1"; }
d="$HOME/.local/share"

rm_if "$d/nautilus-python/extensions/PeaZipMenu.py"
rm_if "$d/nemo-python/extensions/PeaZipMenu.py"
rm_if "$d/caja-python/extensions/PeaZipMenu.py"
rm_if "$d/thunarx-python/extensions/PeaZipMenu.py"

for sm in "$d/kio/servicemenus" "$d/kservices5/ServiceMenus"; do
  for n in PeaZipMenu_Group1.desktop PeaZipMenu_Group2.desktop PeaZipMenu_Group3.desktop PeaZipMenu_Group4.desktop PeaZipMenu_Group5.desktop; do
    rm_if "$sm/$n"
  done
done

for n in PeaZipMenu_Group1.desktop PeaZipMenu_Group2.desktop PeaZipMenu_Group3.desktop PeaZipMenu_Group4.desktop PeaZipMenu_Group5.desktop; do
  rm_if "$d/file-manager/actions/$n"
done

exit 0
