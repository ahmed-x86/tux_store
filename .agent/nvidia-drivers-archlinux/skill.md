---
name: nvidia-drivers-arch
description: Complete guide to detecting, choosing, installing, verifying, recovering and removing NVIDIA drivers on Arch Linux (nvidia-open-dkms for modern cards; 580xx / 470xx / 390xx / 340xx legacy branches from the AUR via yay). Use this skill whenever the user mentions NVIDIA, GeForce, RTX, GTX, GPU driver, black screen after installing a driver, nouveau, DKMS, nvidia-utils, kernel headers, "install nvidia on arch", or Arabic phrases like "تعريف نفيديا", "تعريف كرت الشاشة", "كرت الشاشة" on Arch or an Arch-based distro. Everything needed is inside this file; do not search the web.
---


## this is not compete yet

# NVIDIA drivers on Arch Linux

Source of truth: the "Install NVIDIA drivers" guide from Tux Store. Follow the steps in order. Every command below comes from that guide.

## Overview of the flow

1. Preflight checks (system must be healthy and fully updated)
2. Detect the GPU and map it to a driver branch
3. Detect installed kernels and their headers packages
4. Let the user pick a driver (recommend the detected branch, warn on mismatch)
5. Confirm, then install build tools + headers
6. Install the driver (official repo for modern cards, AUR via yay for legacy)
7. Rebuild the boot images
8. Verify the module was really built **before** restarting
9. Post-install notes (KMS hook, Wayland parameter for old branches), then restart

Never tell the user to restart until step 8 passes.

## 1. Preflight checks

Stop and tell the user what to fix if any check fails.

| Check | Failure message / meaning |
|---|---|
| Not running as root | yay refuses to build as root. Run as a normal user. |
| Tools exist: `lspci pkexec script curl pacman` | `lspci` comes from the `pciutils` package |
| `/var/lib/pacman/db.lck` does not exist | pacman is locked; another package manager is running. Wait, then retry |
| `/usr/lib/modules/$(uname -r)` exists | The running kernel was replaced by an update and its modules are gone. Restart first |
| At least 4 GiB free on `/` | Building a kernel module needs room |
| `pacman -Qu` is empty | Pending updates. Update the system first, restart if the kernel changed. Installing drivers on a half-updated system can break the graphics stack |
| `curl -fsI https://archlinux.org` works | No internet |

Also require `yay` (`command -v yay`). It is needed for the legacy branches from the AUR. If missing, tell the user to install yay first.

Quick manual versions:

```bash
id -u                                   # must not be 0
ls /var/lib/pacman/db.lck               # must not exist
ls /usr/lib/modules/$(uname -r)         # must exist
df -Pk / | awk 'NR==2 {print $4}'       # must be >= 4194304 (KiB)
pacman -Qu | wc -l                      # must be 0
```

## 2. Detect the GPU

```bash
lspci -nn -d 10de: | grep -Ei 'vga|3d controller|display controller' | head -n 1
```

- Empty output means no NVIDIA GPU was seen (branch = `none`).
- The chip code is the token after `NVIDIA Corporation`, for example `GA104`, `GP107`.

### Chip code to branch mapping

| Chip code prefix | Architecture | Branch |
|---|---|---|
| `GB`, `AD`, `GA`, `TU` | Blackwell, Ada, Ampere, Turing | `open` |
| `GV`, `GP`, `GM` | Volta, Pascal, Maxwell | `580xx` |
| `GK` | Kepler | `470xx` |
| `GF` | Fermi | `390xx` |
| `GT`, or `G` followed by digits | Tesla | `340xx` |

If the PCI id database does not know the chip name, fall back to the marketing name in the lspci line:

| Marketing name | Branch |
|---|---|
| RTX 20xx and newer (`RTX [2-9]xxx`), `RTX A…`, GTX 16xx, TITAN RTX | `open` |
| GTX 10xx, GTX 9xx, GTX 750, TITAN X, TITAN V, Quadro P*, Quadro M* | `580xx` |
| GTX 6xx / 7xx | `470xx` |
| GTX 4xx / 5xx | `390xx` |
| anything else | `unknown` (ask the user, do not guess) |

### If no NVIDIA GPU is found

Explain: on a hybrid-graphics laptop dual-booted with Windows, power-saving modes (for example ASUS "Eco Mode") can switch the NVIDIA GPU off at firmware level so Linux cannot see it. Fix: switch Windows or the BIOS to Standard / Optimized mode, shut down completely (not restart), boot Arch again. Only continue anyway if the user is sure a card exists (for example preparing a disk for another PC).

## 3. Kernels and headers (DKMS needs these)

Every installed kernel needs its matching `<pkgbase>-headers` package, otherwise the module cannot be built for it.

```bash
cat /usr/lib/modules/*/pkgbase | sort -u          # kernel pkgbases, e.g. linux linux-lts linux-zen
# for each pkgbase B, check B-headers exists:
pacman -Si B-headers || pacman -Qq B-headers
```

If a kernel has no headers package, the NVIDIA module cannot be built for it. Tell the user to install its headers, or use the official `linux` / `linux-lts` kernels, and stop.

## 4. Driver choice

| Branch | For | Source | Packages |
|---|---|---|---|
| `open` (latest) | RTX 20/30/40/50 and GTX 16 (Turing and newer) | Official Arch repos | `nvidia-open-dkms nvidia-utils nvidia-settings lib32-nvidia-utils` |
| `580xx` | GTX 10 (Pascal), GTX 9 / GTX 750 (Maxwell), Volta. Not supported by the latest driver | AUR | `nvidia-580xx-dkms nvidia-580xx-utils nvidia-580xx-settings lib32-nvidia-580xx-utils` |
| `470xx` | GeForce 600 / 700 (Kepler). Legacy, no updates from NVIDIA | AUR | `nvidia-470xx-dkms nvidia-470xx-utils nvidia-470xx-settings lib32-nvidia-470xx-utils` |
| `390xx` | GeForce 400 / 500 (Fermi). Legacy, unsupported | AUR | `nvidia-390xx-dkms nvidia-390xx-utils nvidia-390xx-settings lib32-nvidia-390xx-utils` |
| `340xx` | GeForce 8 / 9 / 200 / 300 (Tesla). Very old, unsupported | AUR | `nvidia-340xx-dkms nvidia-340xx-utils nvidia-340xx-settings lib32-nvidia-340xx-utils` |

The `lib32-*` package is only installed when the `multilib` repo is enabled (`pacman -Sl multilib`). Steam and 32-bit apps need it.

Notes to tell the user:

- **open**: a few RTX 30 laptops freeze with this driver. If that happens, use 580.xx instead.
- **470xx**: no longer maintained by NVIDIA. May fail to build on the newest kernel (`linux-lts` is the safer choice). On Intel 11th gen or newer CPUs it may need the kernel parameter `ibt=off` to boot.
- **390xx**: may fail to build on new kernels or Xorg. Fallback is the open-source nouveau driver.
- **340xx**: will most likely fail on recent kernels and Xorg. Consider nouveau instead.
- AUR drivers are built on the user's computer (about 350 MB download).

### Mismatch warning

If the detected branch is known and the user picks a different one, warn: a driver that does not support the card can leave a black screen after restart. Offer: choose again / install anyway / cancel. Do not block, but make the risk clear.

## 5. Install

Show a confirmation first: driver label, source, kernels the headers are for, the warning for that branch, and that conflicting NVIDIA packages will be replaced and a restart is needed.

### 5a. Build tools and headers (as root)

```bash
sudo pacman -S --needed --noconfirm base-devel <kernel>-headers [<kernel2>-headers ...]
```

### 5b. Driver

**Open (official repo), as root:**

```bash
sudo pacman -S --needed --noconfirm --ask 4 nvidia-open-dkms nvidia-utils nvidia-settings lib32-nvidia-utils
```

`--ask 4` lets pacman replace conflicting NVIDIA packages inside one transaction, so the system is never left without a driver in between. Drop `lib32-nvidia-utils` if multilib is off.

**Legacy branches (580xx / 470xx / 390xx / 340xx), as a NORMAL user (not root):**

```bash
B=580xx   # or 470xx / 390xx / 340xx
yay -S --needed --noconfirm --ask 4 --sudo pkexec \
  --answerclean None --answerdiff None --answeredit None --answerupgrade None \
  "nvidia-$B-dkms" "nvidia-$B-utils" "nvidia-$B-settings" "lib32-nvidia-$B-utils"
```

yay must run as a normal user. `--sudo pkexec` makes it ask for the password in a graphical dialog. Validate `B` against the four allowed values before using it. Drop the lib32 package if multilib is off.

### 5c. Rebuild boot images (as root)

```bash
sudo mkinitcpio -P
```

If `mkinitcpio` is not present (dracut or another tool), skip it and tell the user to rebuild the initramfs with their own tool.

## 6. Verify BEFORE restarting

DKMS can fail without making pacman fail. Check every installed kernel has an NVIDIA module:

```bash
for f in /usr/lib/modules/*/pkgbase; do
  v=${f%/pkgbase}; v=${v##*/}
  modinfo -k "$v" nvidia >/dev/null 2>&1 || echo "NOT built for: $v"
done
```

If any kernel is listed: **do NOT restart.** Read the DKMS/pacman output. The usual causes are headers that do not match the kernel, or the build failed.

Read the installed version afterwards:

```bash
pacman -Q nvidia-utils            # open branch
pacman -Q nvidia-580xx-utils      # or the matching branch
```

Latest available version in the repos: `pacman -Si nvidia-utils | awk '/^Version/ {print $3; exit}'`

## 7. Post-install notes

- **kms hook (optional):** if `/etc/mkinitcpio.conf` HOOKS contains `kms`, removing it keeps nouveau out of the initramfs. Then run `sudo mkinitcpio -P`.

  ```bash
  grep -E '^[[:space:]]*HOOKS=.*[( ]kms[) ]' /etc/mkinitcpio.conf
  ```

- **Wayland with 470xx / 390xx / 340xx:** these older drivers need the kernel parameters `nvidia_drm.modeset=1 nvidia_drm.fbdev=1` in the bootloader. For GRUB, add them to `GRUB_CMDLINE_LINUX_DEFAULT` in `/etc/default/grub`, then regenerate the config. Add them **before** restarting, otherwise Wayland may show a black screen.

- Then tell the user to restart.

## 8. Backups and recovery

### Safety nets already built into the flow

- pacman works in all-or-nothing transactions, so a failed install normally leaves the old driver in place.
- `--ask 4` replaces conflicting packages in one transaction (no driver-less gap).
- The module check (section 6) catches silent DKMS failures before the restart.
- Preflight blocks installs on a half-updated system, low disk, lock files, a stale running kernel and no network.

### If the installation fails

Tell the user which step failed and to read the output. If the cause is a conflict with an older NVIDIA package, offer the cleanup-and-retry path, and warn first that they will have **no NVIDIA driver until the new one is installed**. Do not turn off or restart during it.

Cleanup removes all installed NVIDIA driver packages (including lib32 variants and opencl-nvidia), then repeats section 5:

```bash
pk=$(pacman -Qq | grep -E '^(lib32-)?(nvidia|nvidia-lts|nvidia-dkms|nvidia-open|nvidia-open-lts|nvidia-open-dkms|nvidia-utils|nvidia-settings|nvidia-[0-9]+xx-(dkms|utils|settings)|opencl-nvidia(-[0-9]+xx)?)$')
sudo pacman -Rdd --noconfirm $pk
```

`-Rdd` skips dependency checks because other packages depend on these (steam, egl-wayland, and so on). The replacement must be installed immediately afterwards.

### If the screen is black after restart

Switch to a text console with `Ctrl+Alt+F3`, log in, and reinstall from there. Typical causes: wrong branch for the card, module not built for the running kernel, or missing Wayland parameters on old branches. Check the branch table in section 4 first.

### Fallback for failing legacy drivers

470xx: use the `linux-lts` kernel. 390xx / 340xx: the open-source nouveau driver.

## 9. Uninstall

Warn first: afterwards the computer uses the open-source nouveau driver, and if the screen stays black after restart, use `Ctrl+Alt+F3` and reinstall from the console. Do not turn off the computer while it works.

Run the preflight subset first: `pkexec` exists and `/var/lib/pacman/db.lck` does not exist.

Remove only the packages that were recorded at install time and are still installed:

```bash
for p in <recorded packages>; do pacman -Qq "$p" >/dev/null 2>&1 && inst="$inst $p"; done
sudo pacman -Rns --noconfirm $inst
sudo mkinitcpio -P
```

If removal fails, another program probably depends on a package (for example Steam needs the 32-bit libraries). The driver is still installed, so the user can try again later. Then ask for a restart.

## 10. Disk space and sizes

- Download and installed sizes for the open driver can be read from the package database:

  ```bash
  pacman -Si nvidia-open-dkms nvidia-utils nvidia-settings | grep -E '^(Download|Installed) Size'
  ```

- AUR drivers build on the machine: about 350 MB download.
- Estimated working space while installing: about 1500 MB. Keep at least 4 GiB free on `/`.

## Behaviour rules for Claude

- Walk the user through the steps in order; do not skip preflight or the post-install verification.
- Prefer the detected branch. Never push the latest driver onto a card that maps to a legacy branch.
- Legacy branches go through `yay` as a normal user; the open branch goes through `pacman` as root.
- Do not claim the install worked until the module check passes.
- If the GPU branch is `unknown`, ask for the exact `lspci -nn -d 10de:` line instead of guessing.
- Keep answers in the user's language (Arabic if they write Arabic), but keep commands, package names and file paths exactly as written above.
