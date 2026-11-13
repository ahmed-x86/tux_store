#!/bin/bash
[ "$(id -u)" -ne 0 ] || { echo "Tux Store is running as root. Wine must run as a normal user, so start Tux Store without sudo."; exit 0; }
for t in wine curl; do
  command -v "$t" >/dev/null 2>&1 || { echo "The required tool '$t' is missing. Install it first (for Wine: the 'wine' package)."; exit 0; }
done
p="${WINEPREFIX:-$HOME/.wine}"
if [ -f "$p/system.reg" ] && head -n 5 "$p/system.reg" | grep -q '^#arch=win32'; then
  echo "Your Wine prefix ($p) is 32-bit, but WinRAR 64-bit needs a 64-bit prefix. Use another prefix (WINEPREFIX=...) or recreate this one."; exit 0
fi
curl -fsI --max-time 10 https://www.rarlab.com >/dev/null 2>&1 || { echo "No internet connection (www.rarlab.com is unreachable)."; exit 0; }
echo ""
