#!/bin/bash
# Root: checks the system, tests the driver and installs the NVIDIA vendor image (runs waydroid init on a fresh install).
command -v waydroid-nvidia-setup >/dev/null 2>&1 || { echo "waydroid-nvidia-setup was not found."; exit 1; }
# Apply the user's graphics choice before the container starts; make sure it is not running during setup
waydroid container stop >/dev/null 2>&1 || true
waydroid-nvidia-setup < /dev/null || exit 1
systemctl restart waydroid-container.service || echo "The container service did not start yet; it will be started again at boot."
exit 0
