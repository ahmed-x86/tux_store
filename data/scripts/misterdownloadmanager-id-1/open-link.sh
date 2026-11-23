#!/bin/bash
# Opens the URL given as the first argument in the default browser.
url="$1"
case "$url" in
    https://*|http://*) ;;
    *) echo "Refusing to open: $url"; exit 1 ;;
esac
command -v xdg-open >/dev/null 2>&1 || { echo "xdg-open is not installed."; exit 1; }
nohup xdg-open "$url" >/dev/null 2>&1 &
exit 0
