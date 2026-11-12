#!/bin/bash
inst=""
for p in $TUX_VAR_RECORDED_PACKAGES; do
  pacman -Qq "$p" >/dev/null 2>&1 && inst="$inst $p"
done
if [ -z "$inst" ]; then echo "None of the recorded packages are installed any more."; exit 0; fi
echo "Removing:$inst"
pacman -Rns --noconfirm $inst
