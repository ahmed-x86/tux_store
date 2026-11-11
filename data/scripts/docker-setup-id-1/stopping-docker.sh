#!/bin/bash
systemctl disable --now docker.service docker.socket >/dev/null 2>&1 || true
if [ -n "${PKEXEC_UID:-}" ]; then u=$(id -nu "$PKEXEC_UID"); gpasswd -d "$u" docker >/dev/null 2>&1 || true; fi
exit 0
