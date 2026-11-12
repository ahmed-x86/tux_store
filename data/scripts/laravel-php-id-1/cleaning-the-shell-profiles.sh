#!/bin/bash
# Removes the two lines php.new added to the shell profile:
#   export PATH="$HOME/.config/herd-lite/bin:$PATH"
#   export PHP_INI_SCAN_DIR="$HOME/.config/herd-lite/bin:$PHP_INI_SCAN_DIR"
# A backup (<file>.tux-store-backup) is made before a file is changed.
pat='^export (PATH|PHP_INI_SCAN_DIR)=.*\.config/herd-lite'
for f in "$HOME/.bashrc" "$HOME/.bash_profile" "$HOME/.profile" "$HOME/.zshrc" "$HOME/.zprofile"; do
  [ -f "$f" ] || continue
  if grep -qE "$pat" "$f"; then
    cp -p -- "$f" "$f.tux-store-backup" || { echo "could not back up $f, skipped"; continue; }
    sed -i --follow-symlinks -E "\\#$pat#d" "$f" && echo "cleaned $f (backup: $f.tux-store-backup)"
  fi
done
exit 0
