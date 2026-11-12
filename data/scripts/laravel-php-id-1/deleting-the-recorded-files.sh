#!/bin/bash
printf '%s\n' "$TUX_VAR_RECORDED_FILES" | while IFS= read -r f; do
  case "$f" in "$HOME"/*) rm -rf -- "$f"; echo "removed $f" ;; *) echo "skipped $f" ;; esac
done
