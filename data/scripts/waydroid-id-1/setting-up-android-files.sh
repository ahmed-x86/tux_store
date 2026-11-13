#!/bin/bash
# ~/android-files/<Folder> -> Android shared storage. Waydroid creates the real
# folders the first time Android starts, so the links may point to nothing until then.
base="$HOME/.local/share/waydroid/data/media/0"
dir="$HOME/android-files"
mkdir -p "$dir" || exit 1
for n in Download DCIM Pictures Movies Music Documents; do
  l="$dir/$n"
  if [ -L "$l" ] || [ ! -e "$l" ]; then
    ln -sfn "$base/$n" "$l" && echo "linked $l"
  else
    echo "kept your existing $l"
  fi
done
exit 0
