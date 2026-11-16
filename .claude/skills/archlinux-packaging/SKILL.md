---
name: archlinux-packaging
description: >
  Use this skill to write, review, build, and publish Arch Linux packages. Apply it for a PKGBUILD
  file, an AUR package, a -git or -bin package, or a split package. Apply it also for checksum and
  .SRCINFO updates, namcap results, clean chroot builds with devtools or pkgctl, and a failed
  makepkg run. Do not use it for the package formats of other distributions, for example .deb.
compatibility: Needs an Arch Linux host or container with base-devel, devtools, namcap, and pacman-contrib.
metadata:
  language-standard: ASD-STE100 Simplified Technical English
  upstream-reference: https://wiki.archlinux.org/title/Arch_package_guidelines
---

# archlinux-packaging — PKGBUILD and AUR Packages

Write Arch Linux packages that obey the Arch package guidelines. A package starts as a `PKGBUILD` file.
`makepkg` reads the `PKGBUILD` file. Then `makepkg` makes a `.pkg.tar.zst` archive. `pacman` installs that archive.

This skill uses Simplified Technical English (ASD-STE100). Write new text in the same style.
Use short sentences. Use the active voice. Write one instruction in each sentence.

## Workflow

1. Read the upstream project. Find the build system, the license, the latest version, and the test command.
2. Search the official repositories and the AUR. Do not make a duplicate package. Adopt or patch the existing package instead.
3. Build the software one time by hand. Do not write a `PKGBUILD` file for software that you cannot build.
4. Copy a template from `assets/`. Then set the metadata and the functions.
5. Compute the checksums with `updpkgsums`.
6. Build the package in a clean chroot with `pkgctl build`.
7. Check the result with `namcap PKGBUILD` and `namcap *.pkg.tar.zst`. Correct each error.
8. Install the package. Then start the program to make sure that the package operates.
9. For an AUR package, write `.SRCINFO`, commit the files, and push to the AUR remote.
10. Report the package name, the version, the build command, and the open namcap warnings.

## Critical rules for agents

1. **Install to `/usr`, never to `/usr/local`.** The prefix `/usr/local` is for local builds only.
2. **Quote `"$pkgdir"` and `"$srcdir"`.** These paths can contain spaces.
3. **Prefix a custom variable or a custom function with an underscore.** An example is `_commit=`. This prevents a name conflict with `makepkg`.
4. **List each direct dependency in `depends`.** Do not depend on a transitive dependency. It can disappear after an update.
5. **Keep the integrity checks.** Do not delete a checksum or a PGP verification to make a broken release build.
6. **Do not call the `makepkg` helper functions.** The functions `msg`, `msg2`, `plain`, `warning`, and `error` can change. Use `printf` instead.
7. **Write a `package()` function in each `PKGBUILD` file.** The `build()` function is optional. The `package()` function is mandatory.
8. **Keep the functions non-interactive.** A prompt stops `makepkg` and stops the CI job.
9. **Set `pkgrel=1` for each new `pkgver`.** Increase `pkgrel` by 1 for a packaging change that keeps the same `pkgver`.
10. **Regenerate `.SRCINFO` after each metadata change.** A stale `.SRCINFO` file makes the AUR show the wrong version.

## Required software

```bash
sudo pacman -S --needed base-devel devtools namcap pacman-contrib
```

Set your identity one time in `~/.makepkg.conf`. An unset `PACKAGER` value writes `Unknown Packager` into the package metadata.

```bash
PACKAGER="Your Name <you@example.org>"
#GPGKEY="0x0123456789ABCDEF"
```

## PKGBUILD example

This example packages a Meson project from a signed release tarball.

```bash
# Maintainer: Your Name <you at example dot org>
# Contributor: Previous Maintainer <old at example dot org>

pkgname=example
pkgver=1.2.3
pkgrel=1
pkgdesc='Text editor for the terminal'
arch=(x86_64)
url='https://example.org/example'
license=(GPL-3.0-or-later)
depends=(
  glibc
  gtk4 libgtk-4.so
)
makedepends=(
  meson
  ninja
)
checkdepends=(xorg-server-xvfb)
optdepends=('cups: print support')
backup=(etc/example/example.conf)
source=(
  "https://example.org/example/releases/$pkgname-$pkgver.tar.gz"
  "https://example.org/example/releases/$pkgname-$pkgver.tar.gz.sig"
  'fix-build-with-gcc15.patch'
)
sha256sums=(
  '9a1f0e2f0a0e2d9b7a1b3c4d5e6f7081920a1b2c3d4e5f60718293a4b5c6d7e8'
  'SKIP'
  '1b2c3d4e5f60718293a4b5c6d7e8f9001a2b3c4d5e6f708192a3b4c5d6e7f801'
)
validpgpkeys=('ABCDEF0123456789ABCDEF0123456789ABCDEF01')

prepare() {
  patch -Np1 -d "$pkgname-$pkgver" -i "$srcdir/fix-build-with-gcc15.patch"
}

build() {
  arch-meson "$pkgname-$pkgver" build
  meson compile -C build
}

check() {
  meson test -C build --print-errorlogs
}

package() {
  meson install -C build --destdir "$pkgdir"
  install -Dm644 "$pkgname-$pkgver/LICENSE" -t "$pkgdir/usr/share/licenses/$pkgname/"
}
```

## Metadata rules

| Field | Rule |
| --- | --- |
| `pkgname` | Use lowercase letters, digits, and `@._+-`. Match the upstream project name. Do not start with a hyphen or a dot. |
| `pkgver` | Copy the upstream version. Replace each hyphen with an underscore. Use the ISO 8601 order for a date version. |
| `pkgrel` | Start at `1`. Add 1 for each rebuild of the same `pkgver`. Reset to `1` after a version change. |
| `epoch` | Add `epoch` only when the upstream version becomes lower than the previous version. |
| `pkgdesc` | Write 80 characters or less. Do not repeat the package name. Do not end with a period. |
| `arch` | Use `arch=(x86_64)` for compiled software. Use `arch=(any)` for architecture-independent files. |
| `license` | Use an SPDX identifier, for example `GPL-3.0-or-later` or `MIT`. Install the license file for a custom license or a BSD or MIT license. |
| `depends` | List each direct runtime dependency. Add each linked shared library, for example `libgtk-4.so`. |
| `makedepends` | List the build-only tools. Do not repeat a `depends` entry. Do not list a `base-devel` member. |
| `checkdepends` | List the test-only packages. `makepkg` reads this array only when `check()` exists. |
| `optdepends` | Use the format `'package: reason'`. Move each non-essential feature dependency here. |
| `provides` | List each virtual name and each external shared library. Do not list `$pkgname`. Add a version, for example `provides=("example=$pkgver")`. |
| `conflicts` | List each package that conflicts with this package. Do not list `$pkgname`. |
| `replaces` | Use `replaces` only for a renamed package. Use `conflicts` and `provides` for an alternative build. |
| `backup` | Use paths without the first slash, for example `etc/example/example.conf`. |
| `source` | Prefer `https://` and `git+https://`. Give each file a unique name with the `name::url` syntax. |
| `sha256sums` | Use the strongest checksum that upstream publishes. The order is `b2`, `sha512`, `sha256`. Use `SKIP` for a signature file and for a VCS source. |

## Function rules

`makepkg` calls these functions in this order. Each function starts in `$srcdir`.

| Function | Task | Notes |
| --- | --- | --- |
| `prepare()` | Patch the sources. Fetch the dependencies for offline use. | Runs one time after the extraction. Skipped with `--noextract`. |
| `pkgver()` | Print the new version to stdout. | Needed for a VCS package. Read `references/vcs-and-bin-packages.md`. |
| `build()` | Compile the software. | Optional. Omit this function when no compilation step exists. |
| `check()` | Run the test suite. | Add this function when upstream has tests. A user can skip it with `--nocheck`. |
| `package()` | Copy the results into `"$pkgdir"`. | Mandatory. Use `make DESTDIR="$pkgdir" install` or `install -Dm644`. |

Do not move files from `"$srcdir"` to `"$pkgdir"` with `mv`. A move breaks `makepkg --repackage`. Use `install` or `cp` instead.

## Directory rules

| Path | Content |
| --- | --- |
| `/etc/example/` | Configuration files. Add each file to `backup`. |
| `/usr/bin/` | Executable files. |
| `/usr/lib/example/` | Private libraries, plugins, and helper programs. |
| `/usr/share/example/` | Architecture-independent data. |
| `/usr/share/licenses/example/` | The license text of a custom, BSD, or MIT license. |
| `/usr/share/man/` | Manual pages. `makepkg` compresses them. |
| `/usr/lib/systemd/system/` | Systemd units. Prefer the upstream unit file. |
| `/usr/lib/sysusers.d/` | System user definitions. Do not create a user in an `.install` file. |
| `/usr/lib/tmpfiles.d/` | Runtime directories under `/run` and `/var`. |
| `/var/lib/example/` | Persistent application data. |
| `/opt/example/` | A large self-contained tree only. |

A package must not contain `/bin`, `/sbin`, `/dev`, `/home`, `/media`, `/mnt`, `/proc`, `/root`, `/run`, `/srv`, `/sys`, `/tmp`, `/usr/libexec`, or `/var/tmp`.

## Build and test commands

```bash
updpkgsums                       # compute the checksums and write them into the PKGBUILD
makepkg --printsrcinfo > .SRCINFO
makepkg -sri                     # sync dependencies, build, install, remove build dependencies
makepkg -o                       # download and extract only
makepkg -e                       # build with the existing $srcdir
makepkg --repackage              # run package() only
pkgctl build                     # build in a clean chroot (preferred gate)
pkgctl build --clean --nocheck   # recreate the chroot and skip check()
pkgctl build -I ../dep/dep.pkg.tar.zst   # add a local dependency to the chroot
namcap PKGBUILD
namcap example-1.2.3-1-x86_64.pkg.tar.zst
pacman -Qlp example-1.2.3-1-x86_64.pkg.tar.zst   # list the packaged files
pacman -Qip example-1.2.3-1-x86_64.pkg.tar.zst   # show the metadata
makerepropkg example-1.2.3-1-x86_64.pkg.tar.zst  # verify a reproducible build
```

`pkgctl build` gives the strongest signal, because the chroot holds no other packages. A local `makepkg` build can hide a missing dependency that your system already has.

## Quality gates

Run these gates before you publish a package.

1. `pkgctl build` completes in a clean chroot.
2. `namcap PKGBUILD` reports no error.
3. `namcap *.pkg.tar.zst` reports no error. Explain each remaining warning.
4. `pacman -Qlp` shows no forbidden directory and no empty package.
5. The installed program starts and does its main task.
6. `.SRCINFO` agrees with the `PKGBUILD` file.

## Reference files

Read a reference file only when the task needs it.

| File | Content |
| --- | --- |
| [references/pkgbuild-fields.md](references/pkgbuild-fields.md) | Full field reference, split packages, `options`, `.install` scripts, and hooks. |
| [references/build-systems.md](references/build-systems.md) | Snippets for Meson, CMake, Autotools, Python, Rust, Go, Node.js, and Java. |
| [references/vcs-and-bin-packages.md](references/vcs-and-bin-packages.md) | `-git` packages, `pkgver()` recipes, submodules, Git LFS, and `-bin` packages. |
| [references/aur-workflow.md](references/aur-workflow.md) | AUR rules, SSH setup, Git remotes, `.SRCINFO`, comments, and requests. |
| [references/quality-and-security.md](references/quality-and-security.md) | namcap tags, clean chroot setup, PGP verification, licensing, and reproducible builds. |

## Templates and scripts

| Path | Purpose |
| --- | --- |
| [assets/PKGBUILD.template](assets/PKGBUILD.template) | Release tarball package. |
| [assets/PKGBUILD-vcs.template](assets/PKGBUILD-vcs.template) | Git package with a `pkgver()` function. |
| [assets/PKGBUILD-bin.template](assets/PKGBUILD-bin.template) | Prebuilt binary package. |
| [scripts/check-package.sh](scripts/check-package.sh) | Run the local gates: `updpkgsums`, `.SRCINFO`, `namcap`, and `pkgctl build`. Run `bash <skill-dir>/scripts/check-package.sh --help` in the PKGBUILD directory for the options. |

## Gotchas and common mistakes

- **Mistake: a missing dependency that the host already has.** A local `makepkg` build passes. The user gets a broken package. Build with `pkgctl build`.
- **Mistake: a hyphen in `pkgver`.** `makepkg` rejects it. Replace the hyphen with an underscore, and restore it in the `source` entry with `${pkgver//_/-}`.
- **Mistake: a stale `.SRCINFO` file.** The AUR shows the old version. Run `makepkg --printsrcinfo > .SRCINFO` before each commit.
- **Mistake: `$pkgname` in `provides` or in `conflicts`.** `pacman` adds `$pkgname` automatically. namcap reports the duplicate.
- **Mistake: `replaces` in an AUR package.** `pacman` removes the official package after a sync. Use `conflicts` and `provides`.
- **Mistake: a version bump without a checksum update.** `makepkg` fails with a validity check error. Run `updpkgsums`.
- **Mistake: an unquoted `$pkgdir`.** The build writes files to the wrong path when the path contains a space.
- **Mistake: a `-git` package with a static `pkgver`.** Add a `pkgver()` function. Do not commit a version-only bump for a VCS package.
- **Mistake: a missing license file.** A BSD, MIT, or custom license needs `install -Dm644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"`.
- **Mistake: a source name that is not unique.** Two packages then share one file in `SRCDEST`. Use the `name::url` syntax.
- **Failure: `makepkg` succeeds but `make` alone fails, or the opposite.** A flag from `makepkg.conf` is the usual cause. Test with `options=(!buildflags !makeflags !lto)`.
- **Failure: namcap prints `W: Directory (usr/src/debug/...) is empty`.** Add `options=(!debug)` for a package that has no debug symbols.
- **Failure: the build needs network access in `build()`.** Move the download into `prepare()`, for example `cargo fetch --locked` or `go mod download`.
- **Edge case: upstream signs the Git tag but not the tarball.** Build from the tag object hash with `git rev-parse`. Keep `?signed` in the source URL.
- **Edge case: upstream publishes no tag and no release.** Use `pkgver() { printf 'r%s.%s' "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"; }`.
- **Edge case: the software is already in a repository.** Do not upload a duplicate to the AUR. Flag the official package as out-of-date, or report a bug.

## Output format for agent responses

Report these items after each packaging task:

- The package name, the `pkgver` value, and the `pkgrel` value.
- The files that you added or changed.
- The build command that you ran, and its result.
- The namcap errors and warnings, with your decision for each one.
- The next manual step for the user, for example a test run or a `git push` command.
