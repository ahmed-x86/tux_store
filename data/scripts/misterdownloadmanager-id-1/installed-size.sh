#!/bin/bash
# The AppImage is installed as-is, so the installed size is the download size (+1 MB for icon/menu entry).
size="$(bash "$(dirname "$0")/download-size.sh" 2>/dev/null | tail -n1)"
if [ "${size:-0}" -gt 0 ] 2>/dev/null; then echo $(( size + 1 )); else echo 0; fi
exit 0
