#!/bin/bash
l_url=$(curl -sI https://github.com/ventoy/Ventoy/releases/latest | grep -i '^location:' | tr -d '\r' | awk '{print $2}')
v_tag=$(basename "$l_url")
[ -n "$v_tag" ] || { echo "Failed to fetch version tag."; exit 1; }
echo "$v_tag"
