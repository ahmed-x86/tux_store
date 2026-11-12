#!/bin/bash
l=$(lspci -nn -d 10de: 2>/dev/null | grep -Ei 'vga|3d controller|display controller' | head -n 1)
[ -n "$l" ] || { echo ""; exit 0; }
m=$(printf '%s\n' "$l" | sed -n 's/.*NVIDIA Corporation [A-Za-z0-9]* \[\([^]]*\)\].*/\1/p')
[ -n "$m" ] || m=$(printf '%s\n' "$l" | sed 's/^[^:]*:[^:]*: //')
printf '%s\n' "$m"
