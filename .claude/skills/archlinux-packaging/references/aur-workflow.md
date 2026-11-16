# AUR submission and maintenance

Read `SKILL.md` first. The AUR holds build scripts only. It holds no binary package.

## Rules of submission

The AUR staff can delete a package that breaks a rule. Check each item before you push.

1. The software is not in `core`, `extra`, or `multilib`. Search <https://archlinux.org/packages/>.
2. The package name is not in the AUR already. Search <https://aur.archlinux.org/packages>. Adopt an orphan instead of a duplicate.
3. The package is useful to more than a few people.
4. The package supports `x86_64`.
5. The package installs software, configuration, documentation, or program data. It does not install private files.
6. The name carries the correct suffix: `-git` for a repository build, `-bin` for a prebuilt file, no suffix for a release build.
7. A variant of an official package uses a different name, plus `conflicts` and `provides`. An example is `screen-sidebar`.
8. The `PKGBUILD` file starts with the maintainer comments.
9. The repository holds a `LICENSE` file for the package sources, and a `REUSE.toml` file.

## Maintainer comments

```bash
# Maintainer: Your Name <you at example dot org>
# Maintainer: Other Maintainer <other at example dot org>
# Contributor: Previous Maintainer <old at example dot org>
# Contributor: Original Submitter <first at example dot org>
```

Move the previous maintainer to a `Contributor` line. Keep every earlier name.

## SSH setup

Make a separate key pair for the AUR. You can then revoke that key alone.

```bash
ssh-keygen -f ~/.ssh/aur
```

Add the public key to your AUR account page. Then write the host block:

```text
# ~/.ssh/config
Host aur.archlinux.org
  IdentityFile ~/.ssh/aur
  User aur
```

## New package repository

```bash
git -c init.defaultBranch=master clone ssh://aur@aur.archlinux.org/example.git
cd example
```

A warning about an empty repository is normal for a new package.

For an existing local directory, add the remote instead:

```bash
git -c init.defaultBranch=master init
git remote add aur ssh://aur@aur.archlinux.org/example.git
git fetch aur
```

## Publish a change

```bash
updpkgsums
makepkg --printsrcinfo > .SRCINFO
git add PKGBUILD .SRCINFO example.install LICENSE REUSE.toml
git commit -m 'upgpkg: example 1.2.3-1'
git push
```

Rules:

- The AUR accepts a push to the `master` branch only.
- The AUR rejects a push without a current `.SRCINFO` file. Use `git commit --amend` to add it.
- Git writes your global name and email into the commit. Set a per-package identity with `git config user.name` and `git config user.email`.
- Change `pkgver` or `pkgrel` for each user-visible change. Do not change them for a typo fix.
- Do not commit a `pkgver` bump alone for a VCS package.

## Keep the working directory clean

```text
# .gitignore
*
!.gitignore
!.SRCINFO
!PKGBUILD
!*.install
!*.patch
!LICENSE
!REUSE.toml
```

This pattern hides the build output and the extracted sources.

## Package source license

Arch licenses the package sources under `0BSD`. RFC40 and RFC52 define this rule.

```bash
pkgctl license setup    # make a REUSE.toml file
pkgctl license check    # verify the result
```

- A file that you wrote takes `0BSD`, for example a launcher script or a systemd unit.
- A file from upstream keeps the upstream license, for example an icon or a patch.

## Maintenance duties

- Read the comments. Apply each useful correction.
- Do not write a comment for each version bump. Keep the comment section useful.
- Track new releases with `nvchecker` or `pkgctl version check`.
- Report an upstream problem to upstream. Add a link to the ticket in a `PKGBUILD` comment.
- Disown the package when you stop the work. Other users can then adopt it.
- Check each automated update by hand. A minor release can change the license or the dependencies.

## Version tracking with pkgctl

```bash
pkgctl version setup      # make a .nvchecker.toml file from the source array
pkgctl version check      # compare pkgver against upstream
pkgctl version upgrade    # set the new pkgver and update the checksums
```

## Requests

| Request | Use |
| --- | --- |
| Deletion | Remove a `pkgbase` from the AUR. Give a reason and the supporting facts. |
| Merge | Delete a `pkgbase` and move its votes and comments to another `pkgbase`. Use it after an upstream rename. |
| Orphan | Remove the current maintainer. Usually made two weeks after an out-of-date flag. |

Open a request with the "Submit Request" link in the "Package Actions" box. The request goes to the package maintainer and to the aur-requests mailing list.

The AUR accepts an orphan request automatically after an out-of-date flag of 180 days or more.

## Test before the push

```bash
pkgctl build --clean
namcap PKGBUILD
namcap ./*.pkg.tar.zst
makepkg --printsrcinfo | diff - .SRCINFO
```

The last command must print nothing. Output means that `.SRCINFO` is stale.
