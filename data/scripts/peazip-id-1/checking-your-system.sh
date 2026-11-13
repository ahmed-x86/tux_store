#!/bin/bash
# Checks that pacman is available. Prints an error message and exits 0 on failure
# so the caller can capture the message; exits 0 silently on success.
if ! command -v pacman >/dev/null 2>&1; then
  echo "pacman was not found. PeaZip can only be installed on Arch-based systems with pacman."
  exit 0
fi
exit 0
