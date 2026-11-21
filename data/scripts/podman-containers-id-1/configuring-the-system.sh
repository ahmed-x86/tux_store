#!/bin/bash
# Runs as root (pkexec). Every part is safe to run again.
set -e
user="${TUX_VAR_LOGIN_USER:-}"
[ -n "$user" ] || user=$(id -nu "${PKEXEC_UID:-0}" 2>/dev/null || true)
if ! [[ "$user" =~ ^[a-z_][a-z0-9_-]*\$?$ ]] || [ "$user" = "root" ]; then
  echo "Could not work out which user to set up."; exit 1
fi

if [ -n "$TUX_VAR_SUBID_NEW" ]; then
  echo "== Sub-UID / sub-GID range for $user =="
  [[ "$TUX_VAR_SUBID_NEW" =~ ^[0-9]+-[0-9]+$ ]] || { echo "Bad range: $TUX_VAR_SUBID_NEW"; exit 1; }
  has() { awk -F: -v u="$user" '$1==u {f=1} END {exit !f}' "$1" 2>/dev/null; }
  has /etc/subuid || usermod --add-subuids "$TUX_VAR_SUBID_NEW" "$user"
  has /etc/subgid || usermod --add-subgids "$TUX_VAR_SUBID_NEW" "$user"
  echo "Added $TUX_VAR_SUBID_NEW."
fi
echo "TUX_PROGRESS=40"

case " $TUX_VAR_SETUP " in
  *" ports "*)
    echo "== Ports below 1024 =="
    cur=$(cat /proc/sys/net/ipv4/ip_unprivileged_port_start 2>/dev/null || echo 1024)
    if [ "$cur" -gt 80 ]; then
      printf '# Added by Tux Store (Podman)\nnet.ipv4.ip_unprivileged_port_start=80\n' > /etc/sysctl.d/99-tux-store-podman-ports.conf
      sysctl -w net.ipv4.ip_unprivileged_port_start=80
    else
      echo "Ports from $cur up are already allowed."
    fi ;;
esac
echo "TUX_PROGRESS=70"

case " $TUX_VAR_SETUP " in
  *" linger "*)
    echo "== Linger =="
    if [ "$TUX_VAR_WAS_LINGER" = "yes" ]; then echo "Already on."; else loginctl enable-linger "$user"; echo "Enabled for $user."; fi ;;
esac
echo "Done."
