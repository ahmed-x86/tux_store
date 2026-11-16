# PKGBUILD fields, options, and scripts

This file gives the full field reference. Read `SKILL.md` first for the rules that apply to each package.

## Field order

Keep the fields in this order. The order is a convention, not a requirement. Bash syntax is the only hard requirement.

```text
maintainer comments
pkgbase        (split packages only)
pkgname
pkgver
pkgrel
epoch          (only when a version goes backwards)
pkgdesc
arch
url
license
groups
depends
makedepends
checkdepends
optdepends
provides
conflicts
replaces
backup
options
install
changelog
source
noextract
validpgpkeys
b2sums | sha512sums | sha256sums
```

Delete each empty array. Keep each line under 100 characters.

## Version fields

### pkgver

- Copy the upstream version string.
- Do not use a hyphen. Replace each hyphen with an underscore.
- Restore the hyphen in a URL with `${pkgver//_/-}`.
- Use the ISO 8601 order for a date version, for example `20260130`.
- Compare two unusual versions with `vercmp 1.0.rc1 1.0`.

### pkgrel

- Set `pkgrel=1` for each new `pkgver`.
- Add 1 for a rebuild that keeps the same `pkgver`. Examples are a dependency fix, a patch, and a soname rebuild.
- Do not change `pkgrel` for a comment-only edit.

### epoch

- The default value is `0`.
- Add `epoch=1` only when the new upstream version sorts lower than the old one.
- An epoch stays in the version forever. Use it only when no other solution exists.

## Dependency arrays

```bash
depends=(
  glibc
  gcc-libs
  libarchive libarchive.so
  'python>=3.12'
)
makedepends=(git meson ninja)
checkdepends=(python-pytest)
optdepends=(
  'cups: print support'
  'sane: scanner support'
)
```

Rules:

- List each direct dependency. A transitive dependency can disappear after an update.
- Add the soname of each linked shared library, for example `libarchive.so`. Find them with `find-libdeps`.
- Do not list a member of `base-devel` in `makedepends`. Test a name with `pactree -rsud1 <package> | grep base-devel`.
- Enable each optional feature, or disable it with a configure flag. An undeclared feature makes an unpredictable build.
- Use `optdepends` for a feature that the main program does not need.

## Package relations

| Array | Use |
| --- | --- |
| `provides` | Virtual names and external shared libraries. Add a version, for example `provides=("example=$pkgver")`. Find libraries with `find-libprovides`. |
| `conflicts` | Packages that cannot share the same files. Two packages with the same `provides` entry conflict automatically. |
| `replaces` | A renamed package only. `pacman` replaces the old package on the next sync. Avoid this array in the AUR. |

## options

`options` overrides the defaults from `makepkg.conf`. Add `!` to disable an option.

| Option | Effect |
| --- | --- |
| `!strip` | Keep the debug symbols in the binaries. |
| `!debug` | Do not build a separate `-debug` package. Use this for a prebuilt binary package. |
| `!lto` | Disable link time optimization. Use this for a mixed Rust and C project that fails to link. |
| `!buildflags` | Do not export `CPPFLAGS`, `CFLAGS`, `CXXFLAGS`, and `LDFLAGS`. |
| `!makeflags` | Do not export `MAKEFLAGS`. Use this for a build with a race condition. |
| `!emptydirs` | Delete the empty directories from the package. |
| `staticlibs` | Keep the `.a` files. |
| `!zipman` | Do not compress the manual pages. |

Example:

```bash
options=(!debug !strip)
```

## install script

An `.install` script prints messages and runs commands at install time, upgrade time, and removal time.

```bash
install=example.install
```

```bash
# example.install
post_install() {
  printf '%s\n' 'Run "example --init" one time to make the database.'
}

post_upgrade() {
  if (( $(vercmp "$2" 2.0.0) < 0 )); then
    printf '%s\n' 'The configuration format changed in 2.0.0.'
  fi
}
```

Rules:

- Available functions: `pre_install`, `post_install`, `pre_upgrade`, `post_upgrade`, `pre_remove`, `post_remove`.
- `post_install` and `post_remove` receive the version as `$1`. The upgrade functions receive the new version as `$1` and the old version as `$2`.
- Do not end the script with `exit`. The functions then do not run.
- Do not put `optdepends` text in an `.install` script. `pacman` prints `optdepends` already.
- Do not create a user in an `.install` script. Use a `sysusers.d` file.
- Do not add the `.install` file to `source`. `makepkg` finds it from the `install` variable.

## Split packages

A split `PKGBUILD` file makes two or more packages from one build.

```bash
pkgbase=example
pkgname=(example example-docs)
pkgver=1.2.3
pkgrel=1
arch=(x86_64)
url='https://example.org/example'
license=(GPL-3.0-or-later)
makedepends=(meson ninja python-sphinx)
source=("https://example.org/example/$pkgbase-$pkgver.tar.gz")
sha256sums=('SKIP')

build() {
  arch-meson "$pkgbase-$pkgver" build
  meson compile -C build
}

package_example() {
  pkgdesc='Text editor for the terminal'
  depends=(glibc)
  meson install -C build --destdir "$pkgdir"
  rm -rf "$pkgdir/usr/share/doc"
}

package_example-docs() {
  pkgdesc='Documentation for example'
  arch=(any)
  meson install -C build --destdir "$pkgdir"
  find "$pkgdir" -mindepth 1 -maxdepth 3 ! -path '*/usr/share/doc*' -delete
}
```

Rules:

- Name each function `package_<pkgname>`.
- Each split package can override `pkgdesc`, `arch`, `url`, `license`, `groups`, `depends`, `optdepends`, `provides`, `conflicts`, `replaces`, `backup`, `options`, `install`, and `changelog`.
- `pkgver`, `pkgrel`, `epoch`, `source`, and the checksum arrays stay global.

## Systemd integration

- Install the upstream unit file. Do not write an Arch-specific unit when upstream has one.
- Do not use `EnvironmentFile=` with `/etc/conf.d`.
- Create a system user with a `sysusers.d` file, not with an `.install` script.
- Create a runtime directory with a `tmpfiles.d` file. A package must not contain `/run`.

```bash
package() {
  install -Dm644 "$srcdir/example.service" -t "$pkgdir/usr/lib/systemd/system/"
  install -Dm644 "$srcdir/example.sysusers" "$pkgdir/usr/lib/sysusers.d/example.conf"
  install -Dm644 "$srcdir/example.tmpfiles" "$pkgdir/usr/lib/tmpfiles.d/example.conf"
}
```

## Useful install commands

```bash
install -Dm755 build/example    "$pkgdir/usr/bin/example"
install -Dm644 LICENSE       -t "$pkgdir/usr/share/licenses/$pkgname/"
install -Dm644 docs/example.1 -t "$pkgdir/usr/share/man/man1/"
install -Dm644 example.desktop -t "$pkgdir/usr/share/applications/"
install -dm755 "$pkgdir/var/lib/example"
```

The flag `-D` makes the parent directories. The flag `-t` sets the target directory.

## Variables from makepkg

| Variable | Meaning |
| --- | --- |
| `$srcdir` | The directory with the extracted sources. Each function starts here. |
| `$pkgdir` | The fake root directory. It becomes the root of the package. |
| `$startdir` | The directory with the `PKGBUILD` file. Avoid this variable. |
| `$CARCH` | The target architecture, for example `x86_64`. |
| `$SOURCE_DATE_EPOCH` | The timestamp for a reproducible build. Use it when the build needs a date. |
