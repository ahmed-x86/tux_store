# Releasing

File: `.github/workflows/release.yml`

The workflow runs inside an **`archlinux:latest` container**, builds once, and produces:

| Artifact | Contents |
|---|---|
| `tux-store-<version>-x86_64-linux.tar.gz` | portable build: `tux-store`, `libtux_*.so`, `data/`, `LICENSE`, `README.md`; runs in place |
| `tux-store-<version>-1-x86_64.pkg.tar.zst` | Arch package built by `makepkg` from `packaging/PKGBUILD` |
| `SHA256SUMS` | checksums of both |

## Triggers

- **Push a tag** `v*` (e.g. `v0.2.1`): builds, then publishes a GitHub Release with the three files.
- **Manual run** (*Actions → Release → Run workflow*): builds and uploads the files as workflow artifacts only.

The version is the tag without the leading `v`; for manual runs it is the `version` in the root `Cargo.toml`.

## Steps

1. Install the build dependencies with `pacman` (`base-devel`, `rust`, `git`, Slint's system libraries).
2. Create an unprivileged `builder` user — `makepkg` refuses to run as root.
3. `makepkg` runs `packaging/PKGBUILD`, which compiles the whole workspace (`cargo build --release`) and runs `make install` into the package.
4. The tarball is assembled from the finished `target/release` directory (no second compile).
5. Checksums are written and everything is uploaded.

## Cutting a release

```bash
# bump `version` in Cargo.toml (workspace) and, optionally, pkgver in packaging/PKGBUILD
git commit -am "Release 0.2.1"
git tag v0.2.1
git push origin main v0.2.1
```

## Installing the result

```bash
sudo pacman -U tux-store-0.2.1-1-x86_64.pkg.tar.zst
# or
tar xzf tux-store-0.2.1-x86_64-linux.tar.gz && ./tux-store-0.2.1/tux-store
```

## Notes

- Arch packages are `.pkg.tar.zst` by default. To get `.pkg.tar.gz` instead, export `PKGEXT=.pkg.tar.gz` for the `makepkg` step; `pacman -U` installs either.
- Runtime dependencies of the package: `pacman polkit util-linux xdg-utils fontconfig libxkbcommon libglvnd`; optional `pacman-contrib` for the Updates tab.
- The workflow overrides `pkgver` from the tag, so `packaging/PKGBUILD` does not need editing for every release.
