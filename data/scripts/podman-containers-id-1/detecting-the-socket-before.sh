#!/bin/bash
# yes = your podman.socket (user service) was already enabled before this install.
if systemctl --user is-enabled --quiet podman.socket 2>/dev/null; then echo yes; else echo no; fi
