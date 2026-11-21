#!/bin/bash
# Runs as root (pkexec). Everything here is safe to run again.
set -e

echo "== KVM kernel module =="
if [ ! -e /dev/kvm ]; then
  if grep -qw vmx /proc/cpuinfo; then m=kvm_intel
  elif grep -qw svm /proc/cpuinfo; then m=kvm_amd
  else m=""; fi
  if [ -n "$m" ]; then
    modprobe "$m" || echo "Could not load $m (virtualization may be disabled in the BIOS)."
    if [ -e /dev/kvm ]; then
      printf '# Added by Tux Store (QEMU/KVM)\n%s\n' "$m" > /etc/modules-load.d/tux-store-kvm.conf
      echo "$m loaded and set to load at every boot."
    fi
  fi
else
  echo "/dev/kvm is present."
fi
echo "TUX_PROGRESS=20"

if [ "$TUX_VAR_NESTED" = "yes" ]; then
  echo "== Nested virtualization =="
  if grep -qw vmx /proc/cpuinfo; then nm=kvm_intel; elif grep -qw svm /proc/cpuinfo; then nm=kvm_amd; else nm=""; fi
  if [ -n "$nm" ]; then
    printf '# Added by Tux Store (QEMU/KVM nested virtualization)\noptions %s nested=1\n' "$nm" > /etc/modprobe.d/tux-store-kvm-nested.conf
    echo "Nested virtualization will be on after the next restart."
  fi
fi
echo "TUX_PROGRESS=35"

echo "== libvirt service =="
systemctl enable --now libvirtd.service
for _ in $(seq 1 20); do
  virsh -c qemu:///system list >/dev/null 2>&1 && break
  sleep 1
done
echo "TUX_PROGRESS=50"

echo "== Your user =="
user="${TUX_VAR_LOGIN_USER:-}"
[ -n "$user" ] || user=$(id -nu "${PKEXEC_UID:-0}" 2>/dev/null || true)
if [[ "$user" =~ ^[a-z_][a-z0-9_-]*\$?$ ]] && [ "$user" != "root" ]; then
  if getent group libvirt >/dev/null 2>&1; then
    if getent group libvirt | awk -F: '{print $4}' | tr ',' '\n' | grep -qx "$user"; then
      echo "$user is already in the libvirt group."
    else
      usermod -aG libvirt "$user"
      echo "$user was added to the libvirt group."
    fi
  else
    echo "The libvirt group does not exist."; exit 1
  fi
else
  echo "Could not work out which user to add to the libvirt group."; exit 1
fi
echo "TUX_PROGRESS=70"

echo "== Default network =="
if ! virsh -c qemu:///system net-list --all --name | grep -qx default; then
  virsh -c qemu:///system net-define /usr/share/libvirt/networks/default.xml
fi
virsh -c qemu:///system net-autostart default
if ! virsh -c qemu:///system net-info default | awk '/^Active:/ {print $2}' | grep -qx yes; then
  virsh -c qemu:///system net-start default || {
    echo "The default NAT network did not start. This is usually a firewall problem: install 'iptables-nft' and make sure 'dnsmasq' is installed, then restart libvirtd.service."
    exit 1
  }
fi
echo "TUX_PROGRESS=90"

if [ "$TUX_VAR_FRONTEND" = "cockpit" ]; then
  echo "== Cockpit =="
  systemctl enable --now cockpit.socket
fi
echo "Done."
