#!/bin/bash
set -e
systemctl enable --now docker.service
if [ -n "${PKEXEC_UID:-}" ]; then u=$(id -nu "$PKEXEC_UID"); usermod -aG docker "$u"; echo "added $u to the docker group"; fi
