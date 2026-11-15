#!/bin/bash
pacman -Q texturecraft 2>/dev/null | awk '{print $2}'
exit 0
