#!/bin/bash
# Runs as root. Only remove the user if this install was the one that added it.
if [ "$TUX_VAR_WAS_IN_GROUP" = "yes" ]; then
  echo "You were already in the libvirt group before this install; leaving it."
  exit 0
fi
user="${TUX_VAR_LOGIN_USER:-}"
[ -n "$user" ] || user=$(id -nu "${PKEXEC_UID:-0}" 2>/dev/null || true)
if [[ "$user" =~ ^[a-z_][a-z0-9_-]*\$?$ ]] && [ "$user" != "root" ] && getent group libvirt >/dev/null 2>&1; then
  if getent group libvirt | awk -F: '{print $4}' | tr ',' '\n' | grep -qx "$user"; then
    gpasswd -d "$user" libvirt && echo "$user was removed from the libvirt group."
  fi
fi
exit 0
