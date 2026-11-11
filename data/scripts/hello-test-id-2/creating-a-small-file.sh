#!/bin/bash
mkdir -p "$HOME/.local/share/tux-hello"
echo "$TUX_VAR_GREETING from Tux Store" > "$HOME/.local/share/tux-hello/hello.txt"
