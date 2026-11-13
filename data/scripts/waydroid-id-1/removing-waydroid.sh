#!/bin/bash
# Stops Waydroid, removes the package(s) this add-on installed, its helper files, and Waydroid's
# Android image and data (/var/lib/waydroid and ~/.local/share/waydroid).
systemctl disable --now waydroid-container.service 2>&1 || true
waydroid container stop >/dev/null 2>&1 || true

inst=""
for p in $TUX_VAR_RECORDED_PACKAGES; do
  pacman -Qq "$p" >/dev/null 2>&1 && inst="$inst $p"
done
if [ -n "$inst" ]; then
  echo "Removing:$inst"
  pacman -Rns --noconfirm $inst || exit 1
else
  echo "No recorded package to remove."
fi

rm -f /etc/systemd/system/waydroid-container.service.d/tux-store.conf
rmdir /etc/systemd/system/waydroid-container.service.d 2>/dev/null || true
rm -f /etc/modules-load.d/tux-store-waydroid.conf /etc/modprobe.d/tux-store-waydroid.conf
rm -f /usr/local/lib/tux-store/waydroid-apply.sh /etc/tux-store/waydroid.conf /etc/tux-store/waydroid.managed
rmdir /usr/local/lib/tux-store /etc/tux-store 2>/dev/null || true
systemctl daemon-reload

if grep -Eq '/var/lib/waydroid|/\.local/share/waydroid' /proc/mounts; then
  echo "Waydroid folders are still mounted. Restart the computer and run the uninstall again."
  exit 1
fi
rm -rf /var/lib/waydroid /var/lib/waydroid-nvidia /home/.waydroid
H=$(getent passwd "${PKEXEC_UID:-}" 2>/dev/null | cut -d: -f6)
if [ -n "$H" ] && [ "$H" != "/" ] && [ -d "$H" ]; then
  rm -rf "$H/.local/share/waydroid"
  rm -f "$H"/.local/share/applications/waydroid.*.desktop
  echo "Removed Waydroid's data in $H/.local/share"
else
  echo "Could not find your home folder; ~/.local/share/waydroid was left in place."
fi
exit 0
