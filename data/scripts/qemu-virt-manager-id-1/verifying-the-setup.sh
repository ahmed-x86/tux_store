#!/bin/bash
for t in qemu-system-x86_64 qemu-img virsh; do
  command -v "$t" >/dev/null 2>&1 || { echo "'$t' was not found after the installation."; exit 1; }
done
systemctl is-active --quiet libvirtd.service || systemctl is-active --quiet libvirtd.socket || { echo "The libvirt service (libvirtd) is not running."; exit 1; }
if [ "$TUX_VAR_FRONTEND" = "virt-manager" ]; then
  command -v virt-manager >/dev/null 2>&1 || { echo "virt-manager was not found after the installation."; exit 1; }
fi
if [ "$TUX_VAR_FRONTEND" = "cockpit" ]; then
  systemctl is-active --quiet cockpit.socket || { echo "cockpit.socket is not running."; exit 1; }
fi
echo ok
