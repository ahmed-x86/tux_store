#!/bin/bash
# After a native install, TUX_VAR_NATIVE_PKG holds the real package name;
# for the AppImage method the package is simply called "texturecraft".
pacman -Q "${TUX_VAR_NATIVE_PKG:-texturecraft}" 2>/dev/null | awk '{print $2}'
exit 0
