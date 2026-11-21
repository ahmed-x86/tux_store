#!/bin/bash
# Runs as YOUR user. Undo only what this install did.
if [ "$TUX_VAR_SOCKET_BY_US" = "yes" ]; then
  systemctl --user disable --now podman.socket 2>/dev/null || true
  echo "podman.socket disabled."
fi
f="$TUX_VAR_REGISTRIES_CONF"
case "$f" in
  "$HOME"/*/containers/registries.conf)
    if [ -f "$f" ] && grep -q '^# Added by Tux Store' "$f"; then rm -f -- "$f"; echo "removed $f"; fi ;;
esac
exit 0
