#!/bin/bash
# Prints a problem description if NVIDIA acceleration (waydroid-nvidia-bin) is unlikely to work, or nothing.
[ -r /proc/driver/nvidia/version ] || { echo "The NVIDIA kernel module is not loaded. Install and load the NVIDIA driver (nvidia / nvidia-open / nvidia-dkms), then restart."; exit 0; }
m=$(cat /sys/module/nvidia_drm/parameters/modeset 2>/dev/null)
[ "$m" = "Y" ] || { echo "nvidia_drm.modeset is not enabled. Add nvidia_drm.modeset=1 to your kernel command line (or modprobe.d) and restart."; exit 0; }
[ "$XDG_SESSION_TYPE" = "wayland" ] || { echo "NVIDIA acceleration needs a Wayland desktop session running on the NVIDIA GPU."; exit 0; }
for h in aur.archlinux.org github.com; do
  curl -fsI --max-time 10 "https://$h" >/dev/null 2>&1 || { echo "Cannot reach $h, which is needed to download waydroid-nvidia-bin."; exit 0; }
done
echo ""
