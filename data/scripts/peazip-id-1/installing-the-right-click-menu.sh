#!/bin/bash
# Downloads the PeaZip right-click menu files for every file manager in $TUX_VAR_MENU_FMS.
BASE="https://raw.githubusercontent.com/ahmed-x86/peazip_rightclick/refs/heads/main/output"
sel="$TUX_VAR_MENU_FMS"
if [ -z "$sel" ]; then echo "No file manager selected: skipping the right-click menu."; exit 0; fi
command -v curl >/dev/null 2>&1 || { echo "curl is missing."; exit 1; }

dolphin_dir() {
  local v=6
  if command -v plasmashell >/dev/null 2>&1; then
    v=$(plasmashell --version 2>/dev/null | grep -oE '[0-9]+' | head -n1)
  fi
  if [ "${v:-6}" -le 5 ]; then echo "$HOME/.local/share/kservices5/ServiceMenus"
  else echo "$HOME/.local/share/kio/servicemenus"; fi
}

download() {
  local url="$1" dest_file="$2"
  local tmp
  tmp=$(mktemp)
  if curl -fsSL --retry 2 --connect-timeout 15 -o "$tmp" "$url"; then
    mv "$tmp" "$dest_file" && echo "   installed $(basename "$dest_file")"
  else
    rm -f "$tmp"
    echo "   FAILED to download $(basename "$dest_file")"
    return 1
  fi
}

fail=0
for fm in $sel; do
  case "$fm" in
    nautilus)
      dest="$HOME/.local/share/nautilus-python/extensions"
      mkdir -p "$dest" || { fail=1; continue; }
      download "$BASE/nautilus/PeaZipMenu.py" "$dest/PeaZipMenu.py" || fail=1
      chmod 755 "$dest/PeaZipMenu.py" 2>/dev/null
      ;;
    nemo)
      dest="$HOME/.local/share/nemo-python/extensions"
      mkdir -p "$dest" || { fail=1; continue; }
      download "$BASE/nemo/PeaZipMenu.py" "$dest/PeaZipMenu.py" || fail=1
      chmod 755 "$dest/PeaZipMenu.py" 2>/dev/null
      ;;
    caja)
      dest="$HOME/.local/share/caja-python/extensions"
      mkdir -p "$dest" || { fail=1; continue; }
      download "$BASE/caja/PeaZipMenu.py" "$dest/PeaZipMenu.py" || fail=1
      chmod 755 "$dest/PeaZipMenu.py" 2>/dev/null
      ;;
    thunar)
      dest="$HOME/.local/share/thunarx-python/extensions"
      mkdir -p "$dest" || { fail=1; continue; }
      download "$BASE/thunar/PeaZipMenu.py" "$dest/PeaZipMenu.py" || fail=1
      chmod 755 "$dest/PeaZipMenu.py" 2>/dev/null
      ;;
    dolphin)
      dest="$(dolphin_dir)"
      mkdir -p "$dest" || { fail=1; continue; }
      for n in PeaZipMenu_Group1.desktop PeaZipMenu_Group2.desktop PeaZipMenu_Group3.desktop PeaZipMenu_Group4.desktop PeaZipMenu_Group5.desktop; do
        download "$BASE/dolphin/$n" "$dest/$n" || fail=1
        chmod 644 "$dest/$n" 2>/dev/null
      done
      ;;
    pcmanfm)
      dest="$HOME/.local/share/file-manager/actions"
      mkdir -p "$dest" || { fail=1; continue; }
      for n in PeaZipMenu_Group1.desktop PeaZipMenu_Group2.desktop PeaZipMenu_Group3.desktop PeaZipMenu_Group4.desktop PeaZipMenu_Group5.desktop; do
        download "$BASE/pcmanfm/$n" "$dest/$n" || fail=1
        chmod 644 "$dest/$n" 2>/dev/null
      done
      ;;
    *) echo "Unknown file manager: $fm"; continue ;;
  esac
  echo ">> $fm done"
done
echo "Restart your file manager to see the PeaZip menu."
exit $fail
