#!/usr/bin/env python3
"""Download Flathub screenshots into data/screenshots/<package>/<package>-N.png

Usage:  python3 tools/fetch_screenshots.py              # every folder with a "flathub" key
        python3 tools/fetch_screenshots.py firefox vlc  # only these packages
        python3 tools/fetch_screenshots.py --force      # also folders that already have pictures

After it runs, the pictures sit next to the JSON and the store uses them directly
(no download at run time). Needs internet; uses only the Python standard library.
"""
import json, sys, urllib.request, urllib.error
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent / "data" / "screenshots"
PREFERRED_WIDTH = 1600
UA = "tux-store-fetch/0.9"


def get(url, limit):
    req = urllib.request.Request(url, headers={"User-Agent": UA})
    with urllib.request.urlopen(req, timeout=30) as r:
        data = r.read(limit + 1)
    if len(data) > limit:
        raise ValueError("too large")
    return data


def app_id(raw):
    return raw.strip().split("?")[0].split("#")[0].rstrip("/").rsplit("/", 1)[-1]


def best(shot):
    if isinstance(shot, str):
        return shot
    sizes = shot.get("sizes") or []
    c = sorted(((int(s.get("width") or 0), s["src"]) for s in sizes if "src" in s))
    ok = [x for x in c if 0 < x[0] <= PREFERRED_WIDTH]
    if ok:
        return ok[-1][1]
    return c[0][1] if c else shot.get("src") or shot.get("url")


def ext(b):
    if b.startswith(b"\x89PNG\r\n\x1a\n"):
        return "png"
    if b.startswith(b"\xff\xd8\xff"):
        return "jpg"
    return None


def main():
    args = sys.argv[1:]
    force = "--force" in args
    only = [a for a in args if not a.startswith("--")]
    for d in sorted(p for p in ROOT.iterdir() if p.is_dir()):
        name = d.name
        if only and name not in only:
            continue
        mf = d / f"{name}.json"
        if not mf.is_file():
            continue
        info = json.loads(mf.read_text())
        if not info.get("flathub"):
            continue
        if not force and any(d.glob(f"{name}-*.png")):
            print(f"{name}: already has pictures (use --force)")
            continue
        try:
            meta = json.loads(get(f"https://flathub.org/api/v2/appstream/{app_id(info['flathub'])}", 2_000_000))
            urls = [u for u in map(best, meta.get("screenshots") or []) if u and u.startswith("https://")]
            n = 0
            for u in urls[: int(info.get("count", 8))]:
                try:
                    data = get(u, 8_000_000)
                except (urllib.error.URLError, ValueError) as e:
                    print(f"  skip {u}: {e}")
                    continue
                e = ext(data)
                if not e:
                    continue
                n += 1
                (d / f"{name}-{n}.{e}").write_bytes(data)
            print(f"{name}: {n} picture(s)")
        except Exception as e:  # network, JSON…
            print(f"{name}: failed ({e})")


if __name__ == "__main__":
    main()
