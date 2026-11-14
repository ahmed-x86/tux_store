#!/bin/bash
inst=""
for p in $TUX_VAR_RECORDED_PACKAGES; do
    pacman -Qq "$p" >/dev/null 2>&1 && inst="$inst $p"
done

[ -n "$inst" ] && pacman -Rns --noconfirm $inst

rm -rf "/tmp/tux-store-filmcraft-id-1"
exit 0
