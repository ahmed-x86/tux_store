#!/bin/bash
# Usage: greet.sh <greeting> [extra ...]   (extras come from the check boxes)
greeting="$1"; shift
echo "$greeting from a script file! (folder: $TUX_ADDON_DIR)"
for extra in "$@"; do
  echo "  extra: $extra"
done
for i in 1 2 3 4; do
  sleep 0.5
  echo "TUX_PROGRESS=$((i * 25))"
done
