#!/bin/bash
# Prints the QEMU package that is already installed (empty if none).
for p in qemu-full qemu-desktop qemu-base; do
  if pacman -Qq "$p" >/dev/null 2>&1; then echo "$p"; exit 0; fi
done
echo ""
