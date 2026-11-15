#!/bin/bash
pacman -Q deckcraft 2>/dev/null | awk '{print $2}'
exit 0
