#!/bin/bash
# Downloads the WinRAR right-click menu files for every file manager in $TUX_VAR_MENU_FMS.
BASE="https://raw.githubusercontent.com/ahmed-x86/winemenu-winrar/refs/heads/main"
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

fail=0
for fm in $sel; do
  case "$fm" in
    nautilus) dest="$HOME/.local/share/nautilus-python/extensions"; files="nautilus/winrar.py" ;;
    nemo)     dest="$HOME/.local/share/nemo-python/extensions";     files="nemo/winrar.py" ;;
    caja)     dest="$HOME/.local/share/caja-python/extensions";     files="caja/winrar.py" ;;
    thunar)   dest="$HOME/.local/share/thunarx-python/extensions";  files="thunar/winrar.py" ;;
    dolphin)  dest="$(dolphin_dir)"; files="dolphin/winrar.desktop dolphin/winrar_dolphin.py" ;;
    pcmanfm)  dest="$HOME/.local/share/file-manager/actions"
              files="pcmanfm/winrar_compress_dialog.desktop pcmanfm/winrar_compress_quick.desktop pcmanfm/winrar_extract_dialog.desktop pcmanfm/winrar_extract_here.desktop pcmanfm/winrar_extract_to.desktop pcmanfm/winrar_open.desktop pcmanfm/winrar_pcmanfm.py" ;;
    *) echo "Unknown file manager: $fm"; continue ;;
  esac
  echo ">> $fm -> $dest"
  mkdir -p "$dest" || { fail=1; continue; }
  for f in $files; do
    name=$(basename "$f")
    tmp=$(mktemp)
    if curl -fsSL --retry 2 --connect-timeout 15 -o "$tmp" "$BASE/$f"; then
      case "$name" in
        *.py) chmod 755 "$tmp" ;;
        *.desktop) if [ "$fm" = dolphin ]; then chmod 755 "$tmp"; else chmod 644 "$tmp"; fi ;;
      esac
      mv "$tmp" "$dest/$name" && echo "   installed $name"
    else
      rm -f "$tmp"; echo "   FAILED to download $name"; fail=1
    fi
  done
done
echo "Restart your file manager to see the menu."
exit $fail
