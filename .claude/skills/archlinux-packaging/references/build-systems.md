# Build system snippets

Each snippet shows the `prepare()`, `build()`, `check()`, and `package()` functions for one ecosystem.
Read `SKILL.md` for the metadata rules.

## Meson

Add `meson` to `makedepends`. The wrapper `arch-meson` sets the Arch defaults.

```bash
makedepends=(meson ninja)

prepare() {
  # Only for a project with downloadable subprojects.
  meson subprojects download --sourcedir="$pkgname-$pkgver"
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
}
```

Use `meson setup --prefix=/usr --buildtype=plain build "$pkgname-$pkgver"` when you need full control.
Set a project option with `-D key=value`. Read `meson.options` or `meson_options.txt` to find the names.

## CMake

```bash
makedepends=(cmake ninja)

build() {
  cmake -B build -S "$pkgname-$pkgver" \
    -DCMAKE_BUILD_TYPE=None \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DBUILD_SHARED_LIBS=ON \
    -Wno-dev
  cmake --build build
}

check() {
  ctest --test-dir build --output-on-failure
}

package() {
  DESTDIR="$pkgdir" cmake --install build
}
```

`CMAKE_BUILD_TYPE=None` keeps the flags from `makepkg.conf`. Do not use `Release`, because it adds its own flags.

## Autotools

```bash
build() {
  cd "$pkgname-$pkgver"
  ./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var
  make
}

check() {
  make -C "$pkgname-$pkgver" check
}

package() {
  make -C "$pkgname-$pkgver" DESTDIR="$pkgdir" install
}
```

Run `./autogen.sh` or `autoreconf -fiv` in `prepare()` when the tarball has no `configure` script.
Use `make prefix="$pkgdir/usr" install` only when `DESTDIR` does not work.

## Python (PEP 517)

Name a library package `python-<module>`. Name an application with the program name only.

```bash
_name=${pkgname#python-}
pkgname=python-example
arch=(any)
makedepends=(python-build python-installer python-wheel python-setuptools)
checkdepends=(python-pytest)
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name//-/_}/${_name//-/_}-$pkgver.tar.gz")

build() {
  cd "${_name//-/_}-$pkgver"
  python -m build --wheel --no-isolation
}

check() {
  cd "${_name//-/_}-$pkgver"
  pytest
}

package() {
  cd "${_name//-/_}-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
}
```

Rules:

- Prefer the upstream source tarball. Use the PyPI sdist URL as the second choice.
- Add the build backend to `makedepends`. Read `build-system.build-backend` in `pyproject.toml`.
- Copy each runtime requirement from the project metadata into `depends`.
- Set `arch=(any)` for pure Python. Set `arch=(x86_64)` for a C extension.
- Export `SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver` when the project reads its version from Git.
- Do not run `tox`. It downloads packages from PyPI and tests the wrong code.
- Do not add a lint plugin or a coverage plugin to `checkdepends`.

## Rust

Name the package after the binary. Do not package a library crate.

```bash
makedepends=(cargo)
source=("$pkgname-$pkgver.tar.gz::https://static.crates.io/crates/$pkgname/$pkgname-$pkgver.crate")

prepare() {
  cd "$pkgname-$pkgver"
  export RUSTUP_TOOLCHAIN=stable
  cargo fetch --locked --target "$(rustc -vV | sed -n 's/host: //p')"
}

build() {
  cd "$pkgname-$pkgver"
  export RUSTUP_TOOLCHAIN=stable
  export CARGO_TARGET_DIR=target
  cargo build --frozen --release --all-features
}

check() {
  cd "$pkgname-$pkgver"
  export RUSTUP_TOOLCHAIN=stable
  cargo test --frozen --all-features
}

package() {
  cd "$pkgname-$pkgver"
  install -Dm0755 -t "$pkgdir/usr/bin/" "target/release/$pkgname"
}
```

Rules:

- `cargo fetch --locked` in `prepare()` makes the later steps offline.
- `--frozen` equals `--locked --offline`. It keeps the build reproducible.
- Do not add `--release` to `cargo test`. A debug test catches more errors.
- Add `--workspace` to `cargo test` when `Cargo.toml` has a `[workspace]` table.
- Most Rust binaries need `glibc` and `gcc-libs` in `depends`.
- Use `cargo install --no-track --frozen --root "$pkgdir/usr/" --path .` when the project installs extra files.
- Add `options=(!lto)` when a mixed Rust and C project fails to link.

## Go

Name the package after the program. Use `go-<module>` for a Go ecosystem tool.

```bash
makedepends=(go)

prepare() {
  cd "$pkgname-$pkgver"
  mkdir -p build
  export GOPATH="$srcdir"
  go mod download -modcacherw
}

build() {
  cd "$pkgname-$pkgver"
  export CGO_CPPFLAGS="$CPPFLAGS"
  export CGO_CFLAGS="$CFLAGS"
  export CGO_CXXFLAGS="$CXXFLAGS"
  export CGO_LDFLAGS="$LDFLAGS"
  export GOPATH="$srcdir"
  export GOFLAGS='-buildmode=pie -trimpath -ldflags=-linkmode=external -mod=readonly -modcacherw'
  go build -o build ./cmd/...
}

check() {
  cd "$pkgname-$pkgver"
  go test ./...
}

package() {
  cd "$pkgname-$pkgver"
  install -Dm755 "build/$pkgname" "$pkgdir/usr/bin/$pkgname"
}
```

Rules:

- Go ignores the system flags. Export each `CGO_*` variable to get the hardening flags.
- `-buildmode=pie` hardens the binary. `-trimpath` makes the build reproducible.
- Change `-mod=readonly` to `-mod=vendor` when the sources hold a `vendor/modules.txt` file.
- Read the `Makefile`. Most Go makefiles overwrite `GOFLAGS`. Call `go build` directly instead.

## Node.js

```bash
makedepends=(npm)
options=(!emptydirs)

package() {
  npm install -g --prefix "$pkgdir/usr" "$srcdir/$pkgname-$pkgver.tgz"
  # Delete the references to $pkgdir from the metadata.
  find "$pkgdir/usr" -name package.json -exec sed -i "s|$pkgdir||" {} +
  chown -R root:root "$pkgdir"
}
```

Rules:

- Delete each reference to `$pkgdir` and `$srcdir` from the installed files.
- Set `arch=(any)` when the package holds no native module.
- Check the file mode after the install. `npm` can leave the wrong owner.

## Java

```bash
arch=(any)
depends=('java-runtime>=17')
makedepends=('java-environment>=17' maven)

build() {
  cd "$pkgname-$pkgver"
  mvn -B -Dmaven.repo.local="$srcdir/m2" package
}

package() {
  install -Dm644 "$pkgname-$pkgver/target/$pkgname-$pkgver.jar" \
    "$pkgdir/usr/share/java/$pkgname/$pkgname.jar"
  install -Dm755 "$srcdir/$pkgname.sh" "$pkgdir/usr/bin/$pkgname"
}
```

Set `maven.repo.local` inside `$srcdir`. The build then does not write to the home directory of the user.

## Shell scripts, fonts, and data

```bash
arch=(any)

package() {
  install -Dm755 "$pkgname-$pkgver/$pkgname" "$pkgdir/usr/bin/$pkgname"
  install -Dm644 "$pkgname-$pkgver/completions/$pkgname.bash" \
    "$pkgdir/usr/share/bash-completion/completions/$pkgname"
  install -Dm644 "$pkgname-$pkgver/LICENSE" -t "$pkgdir/usr/share/licenses/$pkgname/"
}
```

Add `bash` or the correct interpreter to `depends`. namcap reads each shebang line and reports a missing interpreter.
