#!/bin/bash
for t in curl tar awk grep sed; do
  command -v "$t" >/dev/null 2>&1 || { echo "Required tool '$t' is missing."; exit 0; }
done
curl -fsI --max-time 10 https://github.com >/dev/null 2>&1 || { echo "No internet connection to GitHub."; exit 0; }
echo ""
