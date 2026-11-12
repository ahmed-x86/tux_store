#!/bin/bash
# Prints one line such as: Composer 2.8.4 · Laravel installer 5.12.0   (always exits 0)
export PATH="$HOME/.config/herd-lite/bin:$PATH"
export PHP_INI_SCAN_DIR="$HOME/.config/herd-lite/bin:${PHP_INI_SCAN_DIR:-}"
export COMPOSER_NO_INTERACTION=1

c="$(composer --version --no-ansi 2>/dev/null | head -n 1 | grep -oE '[0-9]+\.[0-9]+(\.[0-9]+)?' | head -n 1)"
l="$(laravel --version --no-ansi 2>/dev/null | grep -oE '[0-9]+\.[0-9]+(\.[0-9]+)?' | head -n 1)"

echo "Composer ${c:-?} · Laravel installer ${l:-?}"
exit 0
