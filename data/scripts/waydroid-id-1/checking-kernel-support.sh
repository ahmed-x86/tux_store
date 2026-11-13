#!/bin/bash
# Waydroid needs the Android "binder" driver in the running kernel:
# rust_binder (newer kernels), binder_linux (module / DKMS) or binder built in.
ok=0
modinfo -n rust_binder >/dev/null 2>&1 && ok=1
modinfo -n binder_linux >/dev/null 2>&1 && ok=1
grep -qw binder /proc/filesystems 2>/dev/null && ok=1
if [ "$ok" -eq 0 ] && [ -r /proc/config.gz ]; then
  zcat /proc/config.gz 2>/dev/null | grep -Eq '^CONFIG_[A-Z_]*ANDROID_BINDER[A-Z_]*=(y|m)' && ok=1
fi
[ "$ok" -eq 1 ] || { echo "The kernel you are running ($(uname -r)) has no Android binder support (rust_binder / binder_linux), which Waydroid needs. Use a kernel that includes it, or install binder_linux-dkms from the AUR, then try again."; exit 0; }
echo ""
