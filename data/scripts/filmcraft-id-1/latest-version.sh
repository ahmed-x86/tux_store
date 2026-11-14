#!/bin/bash
# FilmCraft tags its releases as vX.Y.Z and ships
# filmcraft-X.Y.Z-linux-x86_64.AppImage (the asset name has no "v").
# The redirect of /releases/latest needs no token and no API quota.
final="$(curl -sIL -o /dev/null -w '%{url_effective}' --max-time 20 \
    "https://github.com/storytold/filmcraft/releases/latest" 2>/dev/null)"
tag="$(basename "${final:-}")"
tag="${tag#v}"

# Fallback: the GitHub API (60 requests an hour per IP without a token).
if ! printf '%s' "$tag" | grep -Eq '^[0-9]+\.[0-9]+\.[0-9]+$'; then
    tag="$(curl -fsSL --max-time 20 "https://api.github.com/repos/storytold/filmcraft/releases/latest" 2>/dev/null \
        | grep -o '"tag_name"[[:space:]]*:[[:space:]]*"[^"]*"' | head -n1 \
        | sed 's/.*"tag_name"[[:space:]]*:[[:space:]]*"//; s/"$//')"
    tag="${tag#v}"
fi

printf '%s\n' "${tag:-unknown}"
