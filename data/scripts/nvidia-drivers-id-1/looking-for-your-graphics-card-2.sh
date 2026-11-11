#!/bin/bash
# Prints: none | open | 580xx | 470xx | 390xx | 340xx | unknown
l=$(lspci -nn -d 10de: 2>/dev/null | grep -Ei 'vga|3d controller|display controller' | head -n 1)
[ -n "$l" ] || { echo none; exit 0; }
code=$(printf '%s\n' "$l" | sed -n 's/.*NVIDIA Corporation \([A-Z][A-Z0-9]*\) \[.*/\1/p')
case "$code" in
  GB[0-9]*|AD[0-9]*|GA[0-9]*|TU[0-9]*) echo open; exit 0 ;;
  GV[0-9]*|GP[0-9]*|GM[0-9]*)          echo 580xx; exit 0 ;;
  GK[0-9]*)                            echo 470xx; exit 0 ;;
  GF[0-9]*)                            echo 390xx; exit 0 ;;
  GT[0-9]*|G[0-9][0-9]*)               echo 340xx; exit 0 ;;
esac
# The PCI id database does not know this chip name: fall back to the marketing name.
case "$l" in
  *RTX\ [2-9][0-9][0-9][0-9]*|*RTX\ A[0-9]*|*GTX\ 16[0-9][0-9]*|*TITAN\ RTX*) echo open ;;
  *GTX\ 10[0-9][0-9]*|*GTX\ 9[0-9][0-9]*|*GTX\ 750*|*TITAN\ X*|*TITAN\ V*|*Quadro\ P*|*Quadro\ M*) echo 580xx ;;
  *GTX\ [67][0-9][0-9]*) echo 470xx ;;
  *GTX\ [45][0-9][0-9]*) echo 390xx ;;
  *) echo unknown ;;
esac
