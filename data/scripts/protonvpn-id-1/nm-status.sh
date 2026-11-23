#!/bin/bash
# Proton VPN connects through NetworkManager. Prints "active" or "inactive".
if systemctl is-active --quiet NetworkManager 2>/dev/null; then
    echo "active"
else
    echo "inactive"
fi
exit 0
