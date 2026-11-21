#!/bin/bash
# Rootless containers need a range of sub-UIDs/GIDs for your user.
# Prints nothing if both files already have an entry for you; otherwise a free range "START-END".
u=$(id -un)
has() { awk -F: -v u="$u" '$1==u {f=1} END {exit !f}' "$1" 2>/dev/null; }
if has /etc/subuid && has /etc/subgid; then echo ""; exit 0; fi
max=524287
for f in /etc/subuid /etc/subgid; do
  [ -r "$f" ] || continue
  m=$(awk -F: 'NF>=3 {e=$2+$3-1; if (e>m) m=e} END {print m+0}' "$f")
  [ "$m" -gt "$max" ] && max=$m
done
start=$((max+1))
echo "$start-$((start+65535))"
