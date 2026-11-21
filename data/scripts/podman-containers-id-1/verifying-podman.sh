#!/bin/bash
command -v podman >/dev/null 2>&1 || { echo "podman was not found after the installation."; exit 1; }
out=$(podman unshare id -u 2>&1) || { echo "Rootless Podman could not start: $out"; echo "Check that your user has a range in /etc/subuid and /etc/subgid."; exit 1; }
[ "$out" = "0" ] || { echo "Unexpected result from podman unshare: $out"; exit 1; }
echo ok
