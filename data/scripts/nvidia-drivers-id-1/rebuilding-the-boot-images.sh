#!/bin/bash
if command -v mkinitcpio >/dev/null 2>&1; then mkinitcpio -P; else echo "mkinitcpio not found (dracut or another tool?): skipping."; fi
