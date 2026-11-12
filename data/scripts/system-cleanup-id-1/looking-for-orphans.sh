#!/bin/bash
pacman -Qdtq 2>/dev/null | tr "\n" " " || true
echo ""
