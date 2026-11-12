#!/bin/bash
# Prints an error text (and exits 0) when something is missing; prints nothing when all is fine.
command -v curl >/dev/null 2>&1 || { echo "curl is not installed. Install it first:  sudo pacman -S curl"; exit 0; }
command -v bash >/dev/null 2>&1 || { echo "bash was not found."; exit 0; }
case "$(uname -m)" in
  x86_64|aarch64|arm64) ;;
  *) echo "Unsupported CPU architecture: $(uname -m). php.new supports x86_64 and arm64 only."; exit 0 ;;
esac
if ! curl -fsSL --max-time 10 -o /dev/null "https://php.new/install/linux"; then
  echo "Could not reach php.new. Check your internet connection and try again."
fi
exit 0
