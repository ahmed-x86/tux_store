#!/bin/bash
# After a native install, TUX_VAR_NATIVE_PKG holds the real package name;
# for the AppImage method the package is simply called "deckcraft".
pacman -Q "${TUX_VAR_NATIVE_PKG:-deckcraft}" 2>/dev/null | awk '{print $2}'
exit 0
