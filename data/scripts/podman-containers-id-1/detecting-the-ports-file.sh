#!/bin/bash
f=/etc/sysctl.d/99-tux-store-podman-ports.conf
if [ -f "$f" ] && grep -q '^# Added by Tux Store' "$f" 2>/dev/null; then echo "$f"; else echo ""; fi
