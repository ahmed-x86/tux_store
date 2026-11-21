#!/bin/bash
# Runs as YOUR user (no root).
set -e
case " $TUX_VAR_SETUP " in
  *" registries "*)
    d="${XDG_CONFIG_HOME:-$HOME/.config}/containers"; f="$d/registries.conf"
    if [ -e "$f" ]; then
      echo "$f already exists: left untouched."
    else
      mkdir -p "$d"
      printf '# Added by Tux Store (Podman)\nunqualified-search-registries = ["docker.io"]\n' > "$f"
      echo "Created $f"
    fi ;;
esac
echo "TUX_PROGRESS=40"

# A new sub-ID range needs the rootless "pause" process restarted (this stops running containers,
# so it is done only when this install just added the range).
if [ -n "$TUX_VAR_SUBID_NEW" ]; then
  podman system migrate || echo "podman system migrate did not finish; log out and back in if Podman complains."
fi
echo "TUX_PROGRESS=70"

case " $TUX_VAR_SETUP " in
  *" socket "*)
    systemctl --user enable --now podman.socket || echo "Could not enable podman.socket (no user session?). You can run: systemctl --user enable --now podman.socket" ;;
esac
echo "Done."
