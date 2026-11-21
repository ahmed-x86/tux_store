#!/bin/bash
# Prints the file only if Tux Store created it (it carries our marker line).
f=/etc/modprobe.d/tux-store-kvm-nested.conf
if [ -f "$f" ] && grep -q '^# Added by Tux Store' "$f" 2>/dev/null; then echo "$f"; else echo ""; fi
