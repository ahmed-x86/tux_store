#!/bin/bash
pacman -Q designcraft 2>/dev/null | awk '{print $2}'
exit 0
