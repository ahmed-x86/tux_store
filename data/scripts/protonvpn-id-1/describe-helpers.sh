#!/bin/bash
# Human readable version of TUX_VAR_HELPER_PKGS for the confirmation screen.
if [ -n "$TUX_VAR_HELPER_PKGS" ]; then
    printf '%s\n' "$TUX_VAR_HELPER_PKGS"
else
    echo "none, everything needed is already installed"
fi
exit 0
