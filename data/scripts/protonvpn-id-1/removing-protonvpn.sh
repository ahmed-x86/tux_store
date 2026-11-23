#!/bin/bash
# Only the Proton VPN packages are removed (plus the Python libraries nothing else needs).
# NetworkManager, the keyring and the network applet are shared system parts and stay.
inst=""
for p in $TUX_VAR_RECORDED_PACKAGES; do
    pacman -Qq "$p" >/dev/null 2>&1 && inst="$inst $p"
done

[ -n "$inst" ] && pacman -Rns --noconfirm $inst
exit 0
