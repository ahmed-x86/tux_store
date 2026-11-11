#!/bin/bash
set -e
export WINEPREFIX="$TUX_VAR_WINE_PREFIX" WINEDEBUG=-all WINEDLLOVERRIDES="mscoree,mshtml="
if [ -d "$WINEPREFIX/drive_c" ]; then
  echo "The Wine prefix already exists."
else
  echo "Creating the Wine prefix…"
  wineboot -u
  wineserver -w 2>/dev/null || true
fi
