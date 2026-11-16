# Quality, security, and reproducible builds

Read `SKILL.md` first. This file covers the checks that run after the `PKGBUILD` file is complete.

## namcap

`namcap` reads a `PKGBUILD` file and a built package. It reports the common packaging errors.

```bash
namcap PKGBUILD
namcap example-1.2.3-1-x86_64.pkg.tar.zst
namcap --info example-1.2.3-1-x86_64.pkg.tar.zst
namcap --machine-readable PKGBUILD
```

| Tag | Meaning | Action |
| --- | --- | --- |
| `E:` | Error | Correct it before you publish. |
| `W:` | Warning | Correct it, or explain the reason to keep it. |
| `I:` | Information | Read it. Take no action. |

Common messages and their answers:

| Message | Answer |
| --- | --- |
| `Dependency detected and not included` | Add the package to `depends`. |
| `Dependency included but already satisfied` | Delete the redundant entry, or keep it as a direct dependency. |
| `Dependency included and not needed` | Delete the entry. |
| `Soname dependency ... not included` | Add the soname to `depends`, for example `libarchive.so`. |
| `Soname ... is not specified as provides` | The dependency needs a fix. Report it to its maintainer. |
| `Directory (usr/src/debug/...) is empty` | Add `options=(!debug)` for a package with no debug symbols. |
| `Insecure RPATH` | Correct the build flags. An RPATH to a build directory is a security problem. |
| `File referenced in backup does not exist` | Correct the path in `backup`. Use a path with no first slash. |
| `Package contains reference to $srcdir` | The build wrote a build path into a file. Add `-trimpath` or an equal flag. |

Find the `$srcdir` references by hand:

```bash
grep -R "$PWD/src" pkg/
```

## Clean chroot builds

A clean chroot holds `base-devel` and the declared dependencies only. It finds each missing dependency.

```bash
pkgctl build                       # build in the automatic chroot
pkgctl build --clean               # recreate the chroot first
pkgctl build --inspect failure     # open a shell in the chroot after a failure
pkgctl build -I ../dep/dep.pkg.tar.zst   # add a local dependency
pkgctl build --install-to-host all # install the result on the host
pkgctl build --rebuild             # increase pkgrel
pkgctl build --pkgver=1.2.4        # set pkgver, reset pkgrel, update the checksums
```

The manual commands do the same work:

```bash
CHROOT=$HOME/chroot
mkarchroot "$CHROOT/root" base-devel
arch-nspawn "$CHROOT/root" pacman -Syu
makechrootpkg -c -r "$CHROOT"
makechrootpkg -c -r "$CHROOT" -- --check   # force the check() function
```

Build in a tmpfs for more speed:

```bash
sudo mount --mkdir -t tmpfs -o defaults,size=20G tmpfs /mnt/chroots/arch
pkgctl build  # or: extra-x86_64-build -c -r /mnt/chroots/arch
```

Do not build a large package in a tmpfs. The build can fill the memory.

## Source integrity

Order of preference for the checksum type: `b2`, `sha512`, `sha384`, `sha256`.
Use the value that upstream publishes. Do not compute a value from a file that you cannot verify.

```bash
updpkgsums               # update the array that the PKGBUILD already uses
makepkg -g >> PKGBUILD   # append a new sha256sums array
```

## PGP verification

```bash
source=(
  "https://example.org/example-$pkgver.tar.gz"
  "https://example.org/example-$pkgver.tar.gz.sig"
)
sha256sums=('9a1f...' 'SKIP')
validpgpkeys=('ABCDEF0123456789ABCDEF0123456789ABCDEF01')
```

Rules:

- A `.sig`, `.asc`, or `.sign` file in `source` starts an automatic verification.
- `validpgpkeys` takes a full fingerprint in uppercase, with no space.
- Find a fingerprint with `gpg --list-keys --fingerprint <keyid>`.
- `makepkg` reads your user keyring, not the `pacman` keyring. Import the key one time.
- Export the keys into the repository with `export-pkgbuild-keys`. The build then needs no keyserver.
- Verify a Git tag with the `?signed` fragment in the source URL.
- Never delete a signature check to make a broken release build.

Test one time with `makepkg --skippgpcheck`. Do not commit that workaround.

## Licenses

- Use an SPDX identifier in `license`, for example `GPL-3.0-or-later`, `MIT`, or `Apache-2.0`.
- Combine identifiers with the SPDX syntax, for example `'BSD-3-Clause AND LGPL-2.1-or-later'`. Keep the whole expression in one string.
- The `licenses` package delivers each common text under `/usr/share/licenses/spdx/`.
- A BSD, MIT, or custom license needs its own file:

```bash
install -Dm644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
```

- Use `LicenseRef-<name>` or `custom:<name>` for a license with no SPDX identifier.

## Reproducible builds

```bash
makerepropkg example-1.2.3-1-x86_64.pkg.tar.zst
```

Rules:

- Use `$SOURCE_DATE_EPOCH` when the build needs a timestamp.
- Add `-trimpath` for Go. Add `--frozen` for Rust. Both remove the build path and the version drift.
- Pin each dependency version. A lock file keeps the build stable.
- Do not run `go mod tidy` or `cargo update` in `prepare()` for a release package. Both break reproducibility.

## Dependency analysis

```bash
ldd /usr/bin/example                  # direct shared libraries
ldd --unused --function-relocs /usr/bin/example
readelf -d /usr/bin/example           # dynamic section
find-libdeps example.pkg.tar.zst      # sonames for depends
find-libprovides example.pkg.tar.zst  # sonames for provides
pactree -rsud1 <package> | grep base-devel
```

## Failure handling

| Symptom | Cause | Correction |
| --- | --- | --- |
| `ERROR: One or more files did not pass the validity check` | The checksums are stale. | Run `updpkgsums`. Read the upstream release notes first. |
| `ERROR: Failure while downloading` | The URL moved, or the mirror is down. | Use the canonical upstream URL. Do not use a single mirror. |
| Build works with `make` but fails with `makepkg` | A flag from `makepkg.conf` breaks the build. | Test `options=(!buildflags !makeflags !debug !lto)`. Report the problem to upstream. |
| Build works on the host but fails in the chroot | A dependency is missing from the arrays. | Add the package to `depends` or `makedepends`. |
| `check()` fails but the program works | The test suite needs a display, a network, or a fixture. | Disable the single test. Do not delete the whole `check()` function. |
| The package holds no file | The prefix or `DESTDIR` is wrong. | Verify with `pacman -Qlp`. Use `DESTDIR="$pkgdir"`. |
| The package holds `/usr/local` | The build used the default prefix. | Set `--prefix=/usr`. |
| A GUI test needs a display | The test opens a window. | Run the tests under `xvfb-run`. |
