#!/bin/bash
# Prints only the packages that are still missing (one line, space separated).
want="podman $TUX_VAR_TOOLS"
missing=""; unknown=""
for p in $want; do
  [[ "$p" =~ ^[a-z0-9@._+-]+$ ]] || { echo "Invalid package name: $p"; exit 1; }
  case " $missing " in *" $p "*) continue ;; esac
  pacman -Qq "$p" >/dev/null 2>&1 && continue
  pacman -Si "$p" >/dev/null 2>&1 || { unknown="$unknown $p"; continue; }
  missing="$missing $p"
done
if [ -n "$unknown" ]; then
  echo "These packages were not found in your repositories:$unknown"
  echo "Make sure the 'extra' repository is enabled in /etc/pacman.conf and your package databases are synced."
  exit 1
fi
case " $missing " in
  *" podman-docker "*)
    if pacman -Qq docker >/dev/null 2>&1 || pacman -Qq docker-cli >/dev/null 2>&1; then
      echo "podman-docker cannot be installed next to Docker. Remove Docker first or untick podman-docker."
      exit 1
    fi ;;
esac
printf '%s\n' "${missing# }"
