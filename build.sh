#!/usr/bin/env bash
# Build script for the tux project.
# Lets you choose between:
#   1) Strong/slow build (same mode used in GitHub Actions) -> smallest binary
#   2) Fast build for local development/testing -> uses all CPU cores/threads

set -euo pipefail

# ---------- detect number of CPU cores/threads ----------
detect_cpus() {
    if command -v nproc >/dev/null 2>&1; then
        nproc --all
    elif [ -f /proc/cpuinfo ]; then
        grep -c ^processor /proc/cpuinfo
    else
        echo 4   # fallback value if detection fails
    fi
}

CPU_THREADS=$(detect_cpus)

echo "=================================================="
echo "   tux build script"
echo "=================================================="
echo "Detected ${CPU_THREADS} core(s)/thread(s) on this machine."
echo
echo "Choose a build mode:"
echo "  1) Strong, very slow build  -> smallest binary (same as GitHub Actions)"
echo "  2) Fast build for local development/testing (default)"
echo
read -rp "Your choice [1/2] (press Enter = 2): " choice
choice="${choice:-2}"

case "$choice" in
    1)
        echo
        echo ">> Building in strong/slow mode (profile = dist) ..."
        echo ">> Warning: this can take a very long time, same as GitHub Actions."
        echo

        # Slow, mostly sequential build, for the smallest possible binary
        CARGO_BUILD_JOBS="1" \
            cargo build --profile dist --workspace

        echo
        echo ">> Strong build finished. Output is in: target/dist/"
        ;;
    2)
        echo
        echo ">> Building in fast mode (profile = dev) using ${CPU_THREADS} thread(s) ..."
        echo

        # Use all available cores/threads to speed up compilation
        export CARGO_BUILD_JOBS="${CPU_THREADS}"
        export RUSTFLAGS="${RUSTFLAGS:-} -C codegen-units=${CPU_THREADS}"

        cargo build --profile dev --workspace --jobs "${CPU_THREADS}"

        echo
        echo ">> Fast build finished. Output is in: target/debug/"
        ;;
    *)
        echo "Invalid choice. Please choose 1 or 2."
        exit 1
        ;;
esac