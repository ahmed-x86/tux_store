#!/bin/bash
# Prints the helper packages that are missing on this system (empty = nothing to add).
#  - NetworkManager      : only when the user agreed to enable it (TUX_VAR_ENABLE_NM=yes)
#  - a keyring provider  : Proton VPN stores the login in the Secret Service (gnome-keyring, KWallet or KeePassXC).
#                          Two providers together are not recommended, so nothing is added when one exists.
#  - a password prompt   : plasma-nm on KDE, network-manager-applet everywhere else
out=""

if [ "${TUX_VAR_ENABLE_NM:-no}" = "yes" ] && ! pacman -Qq networkmanager >/dev/null 2>&1; then
    out="$out networkmanager"
fi

have_keyring=0
for k in gnome-keyring kwallet keepassxc; do
    pacman -Qq "$k" >/dev/null 2>&1 && have_keyring=1
done
[ "$have_keyring" -eq 0 ] && out="$out gnome-keyring"

desktop="$(printf '%s' "${XDG_CURRENT_DESKTOP:-}" | tr '[:upper:]' '[:lower:]')"
case "$desktop" in
    *kde*|*plasma*) applet="plasma-nm" ;;
    *)              applet="network-manager-applet" ;;
esac
pacman -Qq "$applet" >/dev/null 2>&1 || out="$out $applet"

printf '%s\n' "${out# }"
exit 0
