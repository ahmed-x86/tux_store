#!/bin/bash
# Only symbolic links that point into Waydroid's storage are removed, then the folder if it is empty.
printf '%s\n' "$TUX_VAR_RECORDED_FILES" | while IFS= read -r f; do
  case "$f" in "$HOME"/*) ;; *) continue ;; esac
  if [ -L "$f" ]; then
    case "$(readlink "$f")" in
      */.local/share/waydroid/data/media/0/*) rm -f -- "$f"; echo "removed $f" ;;
    esac
  fi
done
printf '%s\n' "$TUX_VAR_RECORDED_FILES" | while IFS= read -r f; do
  case "$f" in "$HOME"/*) ;; *) continue ;; esac
  if [ -d "$f" ] && [ ! -L "$f" ]; then
    rmdir -- "$f" 2>/dev/null && echo "removed $f" || echo "kept $f (not empty)"
  fi
done
exit 0
