#!/bin/bash
pacman -Q waydroid 2>/dev/null | awk '{print $2}'
