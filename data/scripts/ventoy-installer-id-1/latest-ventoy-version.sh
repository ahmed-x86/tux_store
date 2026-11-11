#!/bin/bash
latest_url=$(curl -sI https://github.com/ventoy/Ventoy/releases/latest | grep -i '^location:' | tr -d '\r' | awk '{print $2}')
basename "${latest_url:-unknown}"
