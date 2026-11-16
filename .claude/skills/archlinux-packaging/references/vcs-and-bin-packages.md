# VCS packages and binary packages

Read `SKILL.md` first. This file covers a package that builds from a repository, and a package that ships a prebuilt file.

## Package name suffix

| Source | Suffix | Example |
| --- | --- | --- |
| Git branch or trunk | `-git` | `example-git` |
| Mercurial | `-hg` | `example-hg` |
| Subversion | `-svn` | `example-svn` |
| Bazaar | `-bzr` | `example-bzr` |
| Prebuilt file from upstream | `-bin` | `example-bin` |
| A fixed upstream release | no suffix | `example` |

A package that builds a specific tag takes no suffix, also when the source is a Git repository.

## VCS source syntax

```text
source=('[folder::][vcs+]url[#fragment]')
```

| Part | Use |
| --- | --- |
| `folder::` | Rename the checkout directory. Do not put `$pkgver` in this name. |
| `vcs+` | Give the type when the URL does not show it, for example `git+https://`. |
| `url` | The repository address. Prefer `https`. |
| `#fragment` | Select a branch, a tag, or a commit, for example `#branch=main` or `#tag=v1.2.3`. |

Set `SKIP` in the checksum array for a moving source. A fixed tag or a fixed commit can take a real checksum from `updpkgsums`.

## Git package template

```bash
pkgname=example-git
pkgver=1.2.3.r45.g1a2b3c4
pkgrel=1
pkgdesc='Text editor for the terminal'
arch=(x86_64)
url='https://example.org/example'
license=(GPL-3.0-or-later)
depends=(glibc)
makedepends=(git meson)
provides=("example=$pkgver")
conflicts=(example)
source=("$pkgname::git+https://example.org/example.git")
sha256sums=('SKIP')

pkgver() {
  cd "$pkgname"
  git describe --long --abbrev=7 | sed 's/\([^-]*-g\)/r\1/;s/-/./g'
}

build() {
  arch-meson "$pkgname" build
  meson compile -C build
}

package() {
  meson install -C build --destdir "$pkgdir"
}
```

## pkgver() recipes

Use the format `RELEASE.rREVISION`. The letter `r` keeps the version order correct after the first upstream release.

| Case | Function body | Output |
| --- | --- | --- |
| Annotated tags | `git describe --long --abbrev=7 \| sed 's/\([^-]*-g\)/r\1/;s/-/./g'` | `2.0.r6.ga17a017` |
| Any tag | `git describe --long --tags --abbrev=7 \| sed 's/\([^-]*-g\)/r\1/;s/-/./g'` | `0.71.r115.gd95ee07` |
| Tag with a prefix | `git describe --long --abbrev=7 \| sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'` | `6.1.r3.gd77e105` |
| No tag | `printf 'r%s.%s' "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"` | `r1142.a17a017` |
| Mercurial | `printf 'r%s.%s' "$(hg identify -n)" "$(hg identify -i)"` | `r2813.75881cc5391e` |
| Subversion | `local ver=$(svnversion); printf 'r%s' "${ver//[[:alpha:]]}"` | `r8546` |
| Last resort | `date +%Y%m%d` | `20260130` |

Each function starts with `cd "$pkgname"`, because `makepkg` calls it from `$srcdir`.

Test the function before you publish the package. A failure in `pkgver()` stops the whole build.

## Tag object hash for a release package

A maintainer can force-push a tag. A tag name alone does not protect the build. Use the tag object hash instead.

```bash
_tag=1234567890123456789012345678901234567890  # git rev-parse "v$pkgver"
source=("$pkgname::git+https://example.org/example.git?signed#tag=$_tag")

pkgver() {
  cd "$pkgname"
  git describe --tags | sed 's/^v//'
}
```

The `?signed` fragment asks `makepkg` to verify the PGP signature of the tag against `validpgpkeys`.
The `pkgver()` function stops a `pkgver` bump without a matching `_tag` update.

## Git submodules

Add each submodule URL to `source`. Then link the local copies in `prepare()`.

```bash
source=(
  'git+https://example.org/main-project.git'
  'git+https://example.org/lib-dependency.git'
)

prepare() {
  cd main-project
  git submodule init
  git config submodule.libs/libdep.url "$srcdir/lib-dependency"
  git -c protocol.file.allow=always submodule update
}
```

Read `.gitmodules` to find the submodule name. The name can differ from the repository name.
Repeat the three commands inside each submodule for a recursive tree.

## Git LFS

```bash
makedepends=(git git-lfs)

prepare() {
  cd "$pkgname"
  git lfs install --local
  git remote add network-origin https://example.org/example.git
  git lfs pull network-origin
}
```

## VCS package rules

- Add the VCS tool to `makedepends`, for example `git`.
- Add `provides=("example=$pkgver")` and `conflicts=(example)`.
- Do not use `replaces`.
- Do not commit a `pkgver` bump only. A VCS package is never out of date.
- Shallow clones and sparse checkouts are not supported.
- Run `makepkg --holdver` to keep the current `pkgver` during a test build.
- For a Python VCS package, run `git clean -dfx` in `prepare()` to delete a stale wheel.

## Binary packages

A `-bin` package ships a file that upstream compiled.

```bash
pkgname=example-bin
pkgver=1.2.3
pkgrel=1
pkgdesc='Text editor for the terminal'
arch=(x86_64)
url='https://example.org/example'
license=(LicenseRef-example-eula)
depends=(glibc gtk3)
provides=("example=$pkgver")
conflicts=(example)
options=(!strip !debug)
source_x86_64=("$pkgname-$pkgver.tar.gz::https://example.org/dl/example-$pkgver-linux-amd64.tar.gz")
sha256sums_x86_64=('9a1f0e2f0a0e2d9b7a1b3c4d5e6f7081920a1b2c3d4e5f60718293a4b5c6d7e8')

package() {
  install -Dm755 "example-$pkgver/example" "$pkgdir/usr/bin/example"
  install -Dm644 "example-$pkgver/LICENSE" -t "$pkgdir/usr/share/licenses/$pkgname/"
}
```

Rules:

- Use the `-bin` suffix when the sources exist but you ship a prebuilt file.
- Add `options=(!strip)` to keep the upstream binary unchanged. Add `!debug` to stop an empty debug package.
- Find the runtime dependencies with `ldd` on the binary. namcap also reports them.
- Use an architecture-specific `source_x86_64` array with a matching `sha256sums_x86_64` array.
- Do not repackage an official Arch package.
- For non-free software, read the Nonfree applications package guidelines. A custom download agent can be necessary.
