#!/bin/bash
# Runs as YOUR user. Deletes every container, pod, image, volume and network of your rootless Podman.
command -v podman >/dev/null 2>&1 || { echo "Podman is not installed: nothing to delete."; exit 0; }
podman system reset --force
