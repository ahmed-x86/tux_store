# Contributing to Tux Store

The goal is a small, fast Arch Linux package-manager GUI that is honest about what pacman will actually do. Read [ARCHITECTURE.md](ARCHITECTURE.md) first.

## Building for development

```bash
cargo build                 # debug build: executable + every libtux_*.so
./target/debug/tux-store
TUX_LOG=debug ./target/debug/tux-store
cargo test --workspace      # parsers, progress model, catalog helpers — no UI needed
```

`cargo run` alone is **not enough**: it builds only the host, not the module libraries. Use `cargo build` (all members) first, or `make run`.

Release: `cargo build --release`, or `make`. Install: `sudo make install`.

## Code style

- Rust 2021, `rustfmt` defaults, no `unwrap()` on external data (process output, files, JSON).
- **Never block in `on_message`.** Spawn a thread; publish the answer later.
- **Every external process has a timeout** — use `tux_pacman::runner::run`, never a bare `Command::output()`.
- **Package names are untrusted** until `is_valid_package_name` passes, and are passed to commands after `--`.
- Share logic as plain functions in `tux-pacman` (testable) and keep modules as thin adapters.
- **Slint files stay logic-free:** receive formatted strings and ratios; do math and formatting in `convert.rs`.
- Log with the `log` macros ([LOGGING.md](LOGGING.md)).

## Where to add things

| You want to… | Start here |
|---|---|
| a new read-only pacman query | function in `tux-pacman/src/queries.rs` (+ unit test), then a request/answer pair in `Message` and a handler in `tux-search` |
| a new kind of transaction | `Operation` variant, `pacman_args()` in `tux-install`, milestone table in `progress.rs` |
| better icon matching for one app | `alias_for()` / `fallback_hints()` in `tux-thumbnail/src/names.rs` |
| a new field on the details page | `PackageDetails` → `convert::details` → `UiPackageDetails` in `types.slint` → `details_view.slint` |
| screenshots for a package | a folder in `data/screenshots/` ([SCREENSHOTS.md](SCREENSHOTS.md)) |
| an interactive add-on package (install / uninstall guide) | a JSON file in `data/scripts/` ([SCRIPTS_SYSTEM.md](SCRIPTS_SYSTEM.md)) |
| a Home category or app | `data/categories.json` |
| an add-on / language-pack set | a JSON file in `data/special_case_packages/` |
| a theme change | `ui/theme.slint` |
| a whole new capability | a new module crate (see [ARCHITECTURE.md](ARCHITECTURE.md#adding-a-module)) |

## Good first contributions

- Replace the three literal hex colours in the progress bars with `Theme.*`.
- `prettify_name`: special-case acronyms (`vlc → VLC`, `gimp → GIMP`).
- Cancel support for running transactions.
- Icon cache size limit / eviction (only the negative cache expires today).
- Async image decoding for the cover carousel (decode off the UI thread).
- More unit tests: `ThemeDirs`, `Catalog::load` with a temp directory, `ConsoleBuffer` limits.

## Submitting a change

1. One logical change per PR.
2. Changing a `Message` variant or a shared struct? Update every module that handles it and `MESSAGE_BUS.md`; give new fields `#[serde(default)]`.
3. Changing the `.so` ABI? Bump `ABI_VERSION` in `tux-abi/src/module.rs`.
4. Explain changed timeouts, concurrency limits or parsing heuristics in the PR text; they were tuned against real pacman output.
5. Test on a real Arch system when you can: much of the correctness depends on pacman's exact output.
6. Run `cargo fmt`, `cargo clippy --workspace` and `cargo test --workspace`.

## Reporting issues

Include `pacman -V`, whether you run as root or through `pkexec`, the output of `TUX_LOG=debug tux-store`, and for install problems the text of the *Console* overlay.
