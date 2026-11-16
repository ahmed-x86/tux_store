#!/usr/bin/env bash
#
# check-package.sh — run the local quality gates for an Arch Linux package.
#
# Run this script in the directory that holds the PKGBUILD file.
#
# Gates:
#   1. bash syntax check of the PKGBUILD file
#   2. checksum update with updpkgsums      (skip with --no-sums)
#   3. .SRCINFO freshness check             (write it with --write-srcinfo)
#   4. namcap on the PKGBUILD file
#   5. clean chroot build with pkgctl build (skip with --no-build)
#   6. namcap on each built package
#
# Exit code 0 means that each gate passed.

set -euo pipefail

readonly PROGRAM=${0##*/}

no_sums=0
no_build=0
write_srcinfo=0

usage() {
	cat <<-EOF
		Usage: ${PROGRAM} [OPTIONS]

		Options:
		  --no-sums         Do not run updpkgsums.
		  --no-build        Do not run pkgctl build.
		  --write-srcinfo   Write .SRCINFO instead of only comparing it.
		  -h, --help        Show this text.
	EOF
}

log() {
	printf '\n== %s\n' "$1"
}

fail() {
	printf 'error: %s\n' "$1" >&2
	exit 1
}

need() {
	command -v "$1" >/dev/null 2>&1 || fail "$1 is not installed; install the $2 package"
}

while (($# > 0)); do
	case "$1" in
	--no-sums) no_sums=1 ;;
	--no-build) no_build=1 ;;
	--write-srcinfo) write_srcinfo=1 ;;
	-h | --help)
		usage
		exit 0
		;;
	*) fail "unknown option: $1" ;;
	esac
	shift
done

[[ -f PKGBUILD ]] || fail 'no PKGBUILD file in the current directory'

need bash bash
need makepkg pacman
need namcap namcap

log 'Gate 1: bash syntax'
bash -n PKGBUILD
printf 'ok\n'

if ((no_sums == 0)); then
	log 'Gate 2: checksums'
	need updpkgsums pacman-contrib
	updpkgsums
	printf 'ok\n'
fi

log 'Gate 3: .SRCINFO'
if ((write_srcinfo == 1)); then
	makepkg --printsrcinfo >.SRCINFO
	printf 'written\n'
elif [[ -f .SRCINFO ]]; then
	if makepkg --printsrcinfo | diff -u .SRCINFO - >/dev/null; then
		printf 'ok\n'
	else
		fail '.SRCINFO is stale; run "makepkg --printsrcinfo > .SRCINFO"'
	fi
else
	printf 'skipped: no .SRCINFO file (needed for the AUR)\n'
fi

log 'Gate 4: namcap PKGBUILD'
namcap PKGBUILD

if ((no_build == 0)); then
	log 'Gate 5: pkgctl build'
	need pkgctl devtools
	pkgctl build

	log 'Gate 6: namcap on the built packages'
	shopt -s nullglob
	packages=(./*.pkg.tar.zst)
	shopt -u nullglob
	((${#packages[@]} > 0)) || fail 'the build made no package file'
	for package in "${packages[@]}"; do
		printf -- '-- %s\n' "$package"
		namcap "$package"
	done
fi

log 'All gates passed.'
