#!/bin/bash
set -e
v="$TUX_VAR_VENTOY_VERSION"
v_clean=$(echo "$v" | sed 's/^v//')
tarball="ventoy-${v_clean}-linux.tar.gz"
dl_url="https://github.com/ventoy/Ventoy/releases/download/${v}/${tarball}"
tmp="${XDG_CACHE_HOME:-$HOME/.cache}/tux-store/ventoy-download"
rm -rf "$tmp"; mkdir -p "$tmp"
echo "Downloading $tarball..."
curl -fL -# -o "$tmp/ventoy.tar.gz" "$dl_url"
