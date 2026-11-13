#!/bin/bash
if [ "$TUX_VAR_RENDER_MODE" = "nvidia" ]; then
  pacman -Qq waydroid-nvidia-bin >/dev/null 2>&1 || { echo "The waydroid-nvidia-bin package is not installed."; exit 1; }
  command -v waydroid-nvidia-setup >/dev/null 2>&1 || { echo "waydroid-nvidia-setup was not found."; exit 1; }
else
  pacman -Qq waydroid >/dev/null 2>&1 || { echo "The waydroid package is not installed."; exit 1; }
fi
systemctl is-enabled waydroid-container.service >/dev/null 2>&1 || { echo "The waydroid-container service is not enabled."; exit 1; }
[ -x /usr/local/lib/tux-store/waydroid-apply.sh ] || { echo "The settings helper was not installed."; exit 1; }
[ -d "$HOME/android-files" ] || { echo "The android-files folder was not created."; exit 1; }
echo ok
