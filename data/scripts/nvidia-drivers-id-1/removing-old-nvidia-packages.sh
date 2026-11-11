#!/bin/bash
pk=$(pacman -Qq | grep -E '^(lib32-)?(nvidia|nvidia-lts|nvidia-dkms|nvidia-open|nvidia-open-lts|nvidia-open-dkms|nvidia-utils|nvidia-settings|nvidia-[0-9]+xx-(dkms|utils|settings)|opencl-nvidia(-[0-9]+xx)?)$' || true)
if [ -z "$pk" ]; then echo "No NVIDIA driver packages are installed."; exit 0; fi
echo "Removing: $pk"
# -Rdd: other packages depend on these (steam, egl-wayland…); the replacement is installed right after.
pacman -Rdd --noconfirm $pk
