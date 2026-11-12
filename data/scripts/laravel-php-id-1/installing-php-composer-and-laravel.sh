#!/bin/bash
# Runs the official php.new installer:  /bin/bash -c "$(curl -fsSL https://php.new/install/linux/<version>)"
# Runs as the normal user (no root). It installs into ~/.config/herd-lite/bin
# and adds PATH lines to the first shell profile it finds (.bashrc / .zshrc ...).
set -u

ver="${TUX_VAR_PHP_VERSION:-}"
case "$ver" in
  8.1|8.2|8.3|8.4|8.5) ;;
  *) echo "Unsupported PHP version: '$ver'" >&2; exit 2 ;;
esac

echo "Downloading the php.new installer for PHP $ver ..."
script="$(curl -fsSL --retry 3 --max-time 60 "https://php.new/install/linux/$ver")" || {
  echo "Could not download the installer from php.new." >&2
  exit 1
}
[ -n "$script" ] || { echo "The php.new installer was empty." >&2; exit 1; }

/bin/bash -c "$script"
