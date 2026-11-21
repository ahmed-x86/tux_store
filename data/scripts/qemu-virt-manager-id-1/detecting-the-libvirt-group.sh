#!/bin/bash
# yes = this user is already a member of the libvirt group (so uninstall must not remove it).
u=$(id -un)
if getent group libvirt 2>/dev/null | awk -F: '{print $4}' | tr ',' '\n' | grep -qx "$u"; then
  echo yes
else
  echo no
fi
