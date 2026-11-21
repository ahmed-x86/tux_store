#!/bin/bash
# yes = libvirt was already enabled before this install.
if systemctl is-enabled --quiet libvirtd.service 2>/dev/null || systemctl is-enabled --quiet libvirtd.socket 2>/dev/null; then
  echo yes
else
  echo no
fi
