#!/bin/bash
if [ "$TUX_VAR_RENDER_MODE" = "nvidia" ]; then
  pacman -Q waydroid-nvidia-bin 2>/dev/null | awk '{print $2}'
else
  pacman -Q waydroid 2>/dev/null | awk '{print $2}'
fi
