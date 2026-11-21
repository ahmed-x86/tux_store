#!/bin/bash
# Runs as root. Undo only what this install did.
want=/etc/sysctl.d/99-tux-store-podman-ports.conf
if [ "$TUX_VAR_PORTS_CONF" = "$want" ] && [ -f "$want" ] && grep -q '^# Added by Tux Store' "$want"; then
  rm -f -- "$want"; echo "removed $want"
  cur=$(cat /proc/sys/net/ipv4/ip_unprivileged_port_start 2>/dev/null || echo 0)
  [ "$cur" = "80" ] && sysctl -w net.ipv4.ip_unprivileged_port_start=1024
fi

user="${TUX_VAR_LOGIN_USER:-}"
[ -n "$user" ] || user=$(id -nu "${PKEXEC_UID:-0}" 2>/dev/null || true)
if [[ "$user" =~ ^[a-z_][a-z0-9_-]*\$?$ ]] && [ "$user" != "root" ]; then
  if [ "$TUX_VAR_LINGER_BY_US" = "yes" ]; then
    loginctl disable-linger "$user" 2>/dev/null || true
    echo "linger disabled for $user."
  fi
  # The sub-ID range stays unless the user also chose to delete all container data:
  # otherwise the stored images would belong to IDs that no longer map to anyone.
  if [ "$TUX_VAR_PURGE" = "yes" ] && [[ "$TUX_VAR_SUBID_RANGE" =~ ^([0-9]+)-[0-9]+$ ]]; then
    start=${BASH_REMATCH[1]}
    for kind in subuid subgid; do
      if awk -F: -v u="$user" -v s="$start" '$1==u && $2==s {f=1} END {exit !f}' "/etc/$kind" 2>/dev/null; then
        usermod "--del-${kind}s" "$TUX_VAR_SUBID_RANGE" "$user" && echo "removed $kind range $TUX_VAR_SUBID_RANGE"
      fi
    done
  fi
fi
exit 0
