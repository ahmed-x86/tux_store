#!/bin/bash
set -e
tmp="${XDG_CACHE_HOME:-$HOME/.cache}/tux-store/ventoy-download"
cd "$tmp"
tar -xzf ventoy.tar.gz
dest="$HOME/.local/share/ventoy"
mkdir -p "$dest"
rm -rf "$dest"/*
extracted_folder=$(ls -d ventoy-*/)
mv ${extracted_folder}* "$dest/"
cd /; rm -rf "$tmp"
