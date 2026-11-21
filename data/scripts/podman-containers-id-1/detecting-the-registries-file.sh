#!/bin/bash
f="${XDG_CONFIG_HOME:-$HOME/.config}/containers/registries.conf"
if [ -f "$f" ] && grep -q '^# Added by Tux Store' "$f" 2>/dev/null; then echo "$f"; else echo ""; fi
