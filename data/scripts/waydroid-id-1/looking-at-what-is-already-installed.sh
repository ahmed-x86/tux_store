#!/bin/bash
# Prints the package this add-on is going to install, if it is not on the computer yet.
if [ "$TUX_VAR_RENDER_MODE" = "nvidia" ]; then
  pacman -Qq waydroid-nvidia-bin >/dev/null 2>&1 || echo "waydroid-nvidia-bin"
else
  pacman -Qq waydroid >/dev/null 2>&1 || echo "waydroid"
fi
exit 0
