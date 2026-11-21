#!/bin/bash
# Runs as root. Remove only the packages this install added, and only if still installed.
inst=""
for p in $TUX_VAR_RECORDED_PACKAGES; do
  pacman -Qq "$p" >/dev/null 2>&1 && inst="$inst $p"
done
if [ -z "$inst" ]; then echo "None of the recorded packages are installed any more."; exit 0; fi
echo "Removing:$inst"
# shellcheck disable=SC2086
pacman -Rns --noconfirm $inst
