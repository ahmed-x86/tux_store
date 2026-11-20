---
name: qemu-virt-manager-arch
description: Complete guide to install, configure, and troubleshoot QEMU/KVM, libvirt, and virt-manager on Arch Linux and Arch-based distros (Manjaro, EndeavourOS, CachyOS, Garuda). Covers every install option (qemu-base, qemu-desktop, qemu-full, headless/CLI-only, minimal, full-featured), UEFI/OVMF, TPM, networking (NAT, bridge), permissions, nested virtualization, VirtIO drivers for Windows guests, GPU acceleration, first VM creation (GUI and virt-install), alternative QEMU GUIs to virt-manager (Cockpit web UI, GNOME Boxes, Quickgui, AQEMU, QtEmu, qt-virt-manager), essential QEMU command-line usage (qemu-img, qemu-system-x86_64, UEFI, TPM, headless, monitor), and uninstalling. Use this skill whenever the user mentions virtual machines on Arch, virt-manager, QEMU, KVM, libvirt, virsh, virt-install, "VM on Linux", or errors like "cannot connect to libvirt", "permission denied qemu:///system", "default network not found", even if they don't name the exact tools.
---

# QEMU/KVM + libvirt + virt-manager on Arch Linux

Sources: Chris Titus Tech guide, ArchWiki (Libvirt, Virt-manager, QEMU), Manjaro wiki, and community guides. Package names verified against these; always run `pacman -Si <pkg>` if unsure a package still exists.

## How the pieces fit

| Layer | What it is | Package |
|---|---|---|
| **KVM** | Linux kernel module that gives hardware-accelerated virtualization (Intel VT-x / AMD-V) | built into the kernel (`kvm`, `kvm_intel` / `kvm_amd`) |
| **QEMU** | Emulator/VM runner; uses KVM for speed | `qemu-base`, `qemu-desktop`, `qemu-full` |
| **libvirt** | Daemon + API that manages VMs, networks, storage | `libvirt` |
| **virt-manager** | GTK GUI on top of libvirt | `virt-manager` |
| **virt-install / virt-viewer** | CLI VM creation / console viewer | `virt-install`, `virt-viewer` |

QEMU alone works without libvirt, but libvirt + virt-manager is what gives you the easy GUI, snapshots, and networking.

---

## Step 1: Check hardware virtualization

```bash
grep -Eoc '(vmx|svm)' /proc/cpuinfo
```

- Result **> 0**: supported (Intel = `vmx`, AMD = `svm`).
- Result **0**: enable **Intel VT-x / Intel Virtualization Technology / AMD-V / SVM Mode** in BIOS/UEFI.
- Running inside a cloud VM or another hypervisor: nested virtualization must be enabled by the provider/parent (see "Nested virtualization" below).

Check KVM device exists:

```bash
ls -l /dev/kvm
```

Load modules manually if missing (normally auto-loaded):

```bash
sudo modprobe kvm_intel     # Intel
sudo modprobe kvm_amd       # AMD
```

Persist across boots (only if they don't load automatically):

```bash
echo kvm_intel | sudo tee /etc/modules-load.d/kvm.conf    # or kvm_amd
```

---

## Step 2: Choose a QEMU package

Arch splits QEMU into several packages. **Pick ONE of the three main ones**, they conflict with each other.

| Package | What you get | Choose it when |
|---|---|---|
| `qemu-base` | Minimal QEMU, x86 only, **no GUI/audio/extra backends**. Smallest. | Servers, headless VMs managed over SSH/CLI. Not good with virt-manager's graphical console. |
| `qemu-desktop` | x86 only, with GUI display (SDL/GTK/SPICE), audio, USB redirection, and the features desktop VMs need | **Default recommendation** for a normal desktop with virt-manager. Running Linux/Windows x86 guests. |
| `qemu-full` | **Everything**: all architectures (ARM, RISC-V, PowerPC, ...) and all optional backends/block drivers (Gluster, iSCSI, Ceph/RBD, etc.) | You need to emulate non-x86 systems, or exotic storage backends, or just want "everything installed". Largest. |

Also available:

- `qemu-img`: disk image tool (`qemu-img create/convert/snapshot`). Already pulled in by the packages above.
- Individual architecture/feature split packages (e.g. `qemu-system-aarch64`, `qemu-system-riscv`, `qemu-block-*`, `qemu-ui-*`, `qemu-audio-*`) can be added on top of `qemu-desktop` if you only need one extra piece instead of `qemu-full`. List them: `pacman -Ss '^qemu-'`.

If you installed one and want to switch (e.g. desktop to full), pacman will offer to replace it. Accept the replacement.

---

## Step 3: Install packages

### Option A: Recommended desktop setup (Chris Titus / most common)

```bash
sudo pacman -Syu --needed qemu-desktop libvirt virt-manager dnsmasq
```

### Option B: Full-featured setup (qemu-full + extras)

```bash
sudo pacman -Syu --needed qemu-full libvirt virt-manager virt-viewer dnsmasq \
  edk2-ovmf swtpm iptables-nft
```

### Option C: Extended "everything" setup

```bash
sudo pacman -Syu --needed qemu-full qemu-img libvirt virt-install virt-manager virt-viewer \
  edk2-ovmf dnsmasq swtpm iptables-nft dmidecode libosinfo guestfs-tools
```

### Option D: Minimal / headless (no GUI, manage with `virsh` and `virt-install`)

```bash
sudo pacman -Syu --needed qemu-base libvirt virt-install dnsmasq
```

Add `virt-viewer` if you want to open a VM console from a desktop machine.

### Option E: User-session only (no root, no system daemon)

```bash
sudo pacman -Syu --needed qemu-desktop libvirt virt-manager edk2-ovmf dnsmasq
```

Then connect virt-manager to `qemu:///session` (limited, see "System vs session" below).

### What each package does

| Package | Purpose | Required? |
|---|---|---|
| `libvirt` | VM management daemon | Yes |
| `virt-manager` | GUI | Only for GUI |
| `dnsmasq` | DHCP/DNS for libvirt's default NAT network | Yes if you use the `default` NAT network |
| `virt-install` | CLI tool to create VMs (also used by virt-manager's ecosystem) | Optional (included with virt-manager on most setups, needed for headless) |
| `virt-viewer` | Standalone console viewer (SPICE/VNC) | Optional |
| `edk2-ovmf` | UEFI firmware for guests (needed for UEFI guests and Windows 11) | Recommended |
| `swtpm` | Software TPM emulator (Windows 11 requires TPM 2.0) | Optional; use `--asdeps` if you want it marked as a dependency |
| `iptables-nft` | iptables-compatible front end on nftables; fixes libvirt firewall backend errors on some setups | Only if you get firewall errors |
| `dmidecode` | Reads hardware info, libvirt uses it for host capabilities | Recommended |
| `libosinfo` | OS database so virt-manager/virt-install detect OS and set good defaults | Recommended |
| `guestfs-tools` / `libguestfs` | Inspect and modify VM disk images offline | Optional |
| `vde2`, `bridge-utils`, `openbsd-netcat`, `ebtables` | Appear in older tutorials for bridging/networking. Mostly unnecessary on a modern system; install only if a specific feature needs them | Optional / legacy |
| `tuned` | Host performance profiles (virtualization-host profile) | Optional |

> Tip: if the install complains about a conflict between `iptables` and `iptables-nft`, accept replacing `iptables` with `iptables-nft`.

---

## Step 4: Enable and start libvirt

Standard (all guides agree on this):

```bash
sudo systemctl enable --now libvirtd.service
```

Alternative: socket activation (starts the daemon on demand):

```bash
sudo systemctl enable --now libvirtd.socket
```

Check:

```bash
systemctl status libvirtd.service
```

---

## Step 5: Give your user access

Add your user to the `libvirt` group:

```bash
sudo usermod -aG libvirt "$USER"
```

Some guides (Manjaro wiki) also add extra groups for system-level VMs:

```bash
sudo usermod -aG libvirt,libvirt-qemu,kvm "$USER"
```

**Log out and back in (or reboot)** so the new groups apply. Verify with:

```bash
groups
```

Security note: the `libvirt` group lets the user manage system VMs. Do **not** add the user to broad groups like `disk` or `input` for this setup.

If group access still fails, ArchWiki also documents authenticating through polkit or setting socket permissions in `/etc/libvirt/libvirtd.conf` (`unix_sock_group = "libvirt"` and `unix_sock_rw_perms = "0770"`), then restart `libvirtd.service`.

---

## Step 6: Default virtual network (NAT)

```bash
sudo virsh net-list --all
```

If `default` is inactive:

```bash
sudo virsh net-start default
sudo virsh net-autostart default
```

If `default` does not exist:

```bash
sudo virsh net-define /usr/share/libvirt/networks/default.xml
sudo virsh net-autostart default
sudo virsh net-start default
```

Verify: state **active**, autostart **yes**.

```bash
sudo virsh net-list --all
```

---

## Step 7: Verify everything

```bash
lsmod | grep kvm                              # kvm + kvm_intel or kvm_amd
virsh --connect qemu:///system list --all     # empty list on a fresh install is normal
```

No connection or permission error means setup works.

---

## Step 8: Create your first VM

### GUI (virt-manager)

1. Download the OS ISO.
2. Run `virt-manager`.
3. Confirm the connection is **QEMU/KVM** (system, `qemu:///system`).
4. **Create a new virtual machine** > Local install media > choose ISO > set RAM/CPU/disk > Finish.
5. In "Customize configuration before install" you can set firmware to **UEFI** (needs `edk2-ovmf`) and add a **TPM** (needs `swtpm`).

Disk images are stored in `/var/lib/libvirt/images/` by default.

### CLI (virt-install)

Needs `virt-install`:

```bash
sudo virt-install \
  --name myvm \
  --memory 4096 \
  --vcpus 2 \
  --disk size=20 \
  --cdrom /path/to/image.iso \
  --os-variant detect=on,require=off \
  --network network=default \
  --graphics spice \
  --boot uefi
```

List supported OS variants: `osinfo-query os` (from `libosinfo`).

### Useful `virsh` commands

```bash
virsh list --all            # all VMs
virsh start <vm>            # start
virsh shutdown <vm>         # graceful shutdown
virsh destroy <vm>          # force stop (power cut)
virsh undefine <vm> --nvram # delete definition (add --remove-all-storage to delete disks)
virsh snapshot-create-as <vm> snap1
virsh snapshot-list <vm>
```

---

## Alternatives to virt-manager (QEMU GUIs only)

virt-manager is just one front end. These other graphical tools also drive QEMU/KVM. Some sit on top of **libvirt** (so you keep Steps 3-7 and just skip `virt-manager`), others talk to QEMU directly.

| Tool | Type | Uses libvirt? | Install source | Notes |
|---|---|---|---|---|
| **Cockpit + cockpit-machines** | Web GUI (browser) | Yes | Official repos | Good for headless/remote machines; actively maintained |
| **GNOME Boxes** | Simple desktop app (GTK) | Yes (session) | Official repos | Easiest, but few settings |
| **Quickgui** | Desktop GUI for Quickemu | No (QEMU directly) | AUR | Auto-downloads ISOs; Windows/macOS/Linux/BSD guests |
| **AQEMU** | Qt desktop GUI | No (QEMU directly) | AUR (check) | Old, low maintenance |
| **QtEmu** | Qt desktop GUI | No (QEMU directly) | AUR (check) | Older versions discontinued; a newer rewrite exists |
| **qt-virt-manager** | Qt GUI for libvirt | Yes | AUR (check) | Qt alternative to virt-manager; low maintenance |
| **Karton VM** | KDE-style libvirt VM manager | Yes | AUR (check) | Small project for KDE Plasma users |

For AUR items, search first (`yay -Ss <name>`) since packages and maintenance status change.

### Option 1: Cockpit web interface (cockpit-machines)

Needs libvirt + QEMU from Steps 2-5 (you can skip `virt-manager`).

```bash
sudo pacman -S --needed cockpit cockpit-machines
sudo systemctl enable --now cockpit.socket
```

Open `https://localhost:9090`, log in with your system user (member of the `libvirt` group), and open the **Virtual Machines** page to create, start, stop, and open consoles. Optional: `virt-install` (create VMs from the UI) and `virt-viewer` (graphical console). `cockpit-machines` pulls in `libvirt-dbus` automatically. For remote access, allow TCP 9090 in the firewall or tunnel it over SSH.

### Option 2: GNOME Boxes

```bash
sudo pacman -S --needed gnome-boxes
```

Uses libvirt/QEMU underneath with a per-user (session) connection, so basic use needs no root daemon setup. Networking and hardware customization are limited; use virt-manager or Cockpit for bridges, multiple disks, UEFI/TPM tweaks. (Confirm with `pacman -Si gnome-boxes`.)

### Option 3: Quickgui (GUI for Quickemu)

Quickemu is a QEMU wrapper that downloads the ISO and generates an optimized config; Quickgui is its graphical front end. Both are in the **AUR** and need an AUR helper. Quickemu depends on `qemu-desktop` (not `qemu-base`).

```bash
yay -S quickemu
yay -S quickgui-bin        # prefer -bin: the source build often fails on Flutter
```

Open **Quickgui** from the app menu, pick an OS and version, download, and start the VM. (CLI equivalent if you need it: `quickget <os> <version>` then `quickemu --vm <name>.conf`; syntax varies by version, check `quickget --help`.)

### Option 4: AQEMU / QtEmu / qt-virt-manager (Qt front ends)

```bash
yay -Ss aqemu
yay -Ss qtemu
yay -Ss qt-virt-manager
```

- **AQEMU** and **QtEmu** talk to QEMU directly: you need only `qemu-desktop` (or `qemu-full`), no libvirt.
- **qt-virt-manager** talks to libvirt: you need Steps 3-5.
- These are less maintained than virt-manager or Cockpit. If one fails to build, fall back to Cockpit or Boxes.

### Which one to pick

- Browser-based management, servers, remote access: **Cockpit**.
- Simplest possible desktop app: **GNOME Boxes**.
- One-click VMs with automatic ISO download: **Quickgui**.
- Prefer Qt look: **AQEMU / QtEmu / qt-virt-manager** (accept lower maintenance).

---

## Essential QEMU CLI commands

Works with only `qemu-desktop` (or `qemu-full`), no libvirt needed. Add `edk2-ovmf` for UEFI and `swtpm` for TPM.

### Disk images (`qemu-img`)

```bash
qemu-img create -f qcow2 disk.qcow2 30G          # new disk (grows as used)
qemu-img create -f qcow2 -b base.qcow2 -F qcow2 child.qcow2   # overlay on a base image
qemu-img info disk.qcow2                          # format, virtual vs real size
qemu-img resize disk.qcow2 +10G                   # grow (then extend the partition inside the guest)
qemu-img convert -f vmdk -O qcow2 in.vmdk out.qcow2   # convert formats (vdi, vmdk, raw, qcow2...)
qemu-img check disk.qcow2                         # check for corruption
qemu-img snapshot -l disk.qcow2                   # list internal snapshots (VM must be off)
qemu-img snapshot -c snap1 disk.qcow2             # create snapshot
qemu-img snapshot -a snap1 disk.qcow2             # revert to snapshot
```

### Install an OS from an ISO

```bash
qemu-system-x86_64 \
  -enable-kvm -cpu host -smp 4 -m 4G \
  -drive file=disk.qcow2,if=virtio \
  -cdrom /path/to/image.iso -boot d \
  -nic user,model=virtio-net-pci \
  -vga virtio -display gtk,gl=on \
  -device usb-tablet
```

Next boots: remove `-cdrom ... -boot d`.

### Most-used options

| Option | Meaning |
|---|---|
| `-enable-kvm` | Use KVM hardware acceleration (huge speedup) |
| `-cpu host` | Expose the host CPU features to the guest |
| `-smp 4` | Number of virtual CPUs |
| `-m 4G` | RAM |
| `-drive file=disk.qcow2,if=virtio` | Disk using fast VirtIO (Windows needs the VirtIO driver) |
| `-cdrom file.iso` / `-boot d` | Attach ISO / boot from CD first |
| `-nic user,model=virtio-net-pci` | NAT networking (guest can reach the internet, host cannot reach guest by default) |
| `-nic user,hostfwd=tcp::2222-:22` | Forward host port 2222 to guest SSH |
| `-vga virtio` | VirtIO GPU (with `-display gtk,gl=on` for 3D) |
| `-display gtk` / `sdl` / `none` | Window type, or no window |
| `-device usb-tablet` | Smooth mouse without capture |
| `-name myvm` | Window title / VM name |

### UEFI boot (OVMF)

Check where the files are: `pacman -Ql edk2-ovmf`. Typical layout:

```bash
cp /usr/share/edk2/x64/OVMF_VARS.4m.fd ./my_vars.fd     # per-VM writable NVRAM copy
qemu-system-x86_64 ... \
  -drive if=pflash,format=raw,readonly=on,file=/usr/share/edk2/x64/OVMF_CODE.4m.fd \
  -drive if=pflash,format=raw,file=./my_vars.fd
```

### TPM 2.0 (Windows 11) with swtpm

```bash
mkdir -p ./tpm
swtpm socket --tpmstate dir=./tpm --ctrl type=unixio,path=./tpm/swtpm-sock --tpm2 &
qemu-system-x86_64 ... \
  -chardev socket,id=chrtpm,path=./tpm/swtpm-sock \
  -tpmdev emulator,id=tpm0,chardev=chrtpm \
  -device tpm-tis,tpmdev=tpm0
```

### Headless / server use

```bash
qemu-system-x86_64 -enable-kvm -m 2G -smp 2 \
  -drive file=disk.qcow2,if=virtio \
  -nic user,hostfwd=tcp::2222-:22 \
  -nographic                      # serial console in the terminal
# or run in background: -display none -daemonize
```

With `-nographic`: exit with `Ctrl+A` then `X`. SSH in with `ssh -p 2222 user@localhost`.

### Other useful options

```bash
-snapshot                                   # discard all disk changes on exit (safe testing)
-virtfs local,path=/host/dir,mount_tag=share,security_model=mapped-xattr   # share a folder (9p)
                                            # in guest: sudo mount -t 9p -o trans=virtio share /mnt
-usb -device usb-host,vendorid=0x1234,productid=0x5678   # pass a USB device (find IDs with lsusb)
-device virtio-balloon                      # memory ballooning
-monitor stdio                              # QEMU monitor in your terminal
```

### QEMU monitor (live control)

Open with `-monitor stdio`, or `Ctrl+Alt+2` in the GTK window (`Ctrl+Alt+1` goes back to the VM).

```text
info status             # running/paused
stop / cont             # pause / resume
savevm snap1            # live snapshot (qcow2 disk)
loadvm snap1            # restore it
info snapshots
system_powerdown        # ACPI shutdown request
quit                    # kill the VM immediately
```

Release the mouse from the GTK window with `Ctrl+Alt+G`.

---

## System vs session connection

| | `qemu:///system` | `qemu:///session` |
|---|---|---|
| Runs as | root (via libvirtd) | your user |
| Networking | Full: NAT, bridges, virtual networks | Limited (user-mode networking only) |
| Disk location | `/var/lib/libvirt/images/` | `~/.local/share/libvirt/images/` |
| Needs group setup | Yes (`libvirt`) | No |
| Use when | Normal desktop use, bridged networking, anything advanced | Quick test without root |

Use **system** unless you have a reason not to.

---

## Optional features

### UEFI firmware

Install `edk2-ovmf`, then choose **UEFI x86_64** firmware in virt-manager (Overview > Firmware) before first boot, or use `--boot uefi` with virt-install.

### TPM (Windows 11)

```bash
sudo pacman -S --needed --asdeps swtpm
```

In VM details: Add Hardware > TPM > Emulated, model **CRB**, version **2.0**.

### Windows guests: VirtIO drivers

For better disk/network performance, use VirtIO devices and install the VirtIO driver ISO (`virtio-win`) in the guest. It is available in the AUR (`virtio-win`) or from the Fedora project's download page. Attach the ISO as a second CD-ROM during Windows setup and load the storage driver when the installer asks for a disk.

### Bridged networking (VM appears on your LAN)

Needs the system connection. Create a bridge with NetworkManager (`nmcli`) or systemd-networkd, attach your physical interface to it, and in the VM's NIC choose **Bridge device** with the bridge name. Note: Wi-Fi interfaces generally cannot be bridged; use NAT in that case.

### 3D / GPU acceleration (VirtIO-GPU)

In VM details: Video > **Virtio**, and Display > Spice with **OpenGL** enabled (Listen type: None). Needs a guest with VirtIO-GPU/virgl support (most modern Linux guests).

### Nested virtualization (run VMs inside a VM)

Check:

```bash
cat /sys/module/kvm_intel/parameters/nested     # or kvm_amd
```

Enable permanently:

```bash
echo "options kvm_intel nested=1" | sudo tee /etc/modprobe.d/kvm-nested.conf   # or kvm_amd
```

Reload modules or reboot. For cloud/another hypervisor as the host, the provider must expose VT-x/AMD-V to your machine.

### IOMMU / GPU passthrough (advanced)

Enable `intel_iommu=on` or `amd_iommu=on` in kernel parameters and verify with:

```bash
dmesg | grep -i -e DMAR -e IOMMU
```

Full passthrough is a large topic; follow the ArchWiki "PCI passthrough via OVMF" article.

### Extra QEMU backends and architectures

Instead of `qemu-full`, add only what you need on top of `qemu-desktop`. Search with `pacman -Ss '^qemu-'`.

---

## Troubleshooting

| Problem | Fix |
|---|---|
| Virtualization check returns 0 | Enable VT-x/AMD-V/SVM in BIOS/UEFI; nested virt needed if host is itself a VM. |
| virt-manager "cannot connect to libvirt" | `systemctl status libvirtd.service`; start/enable it. |
| "Permission denied" on `qemu:///system` | Check `groups` shows `libvirt`; log out fully and back in or reboot. |
| Default network missing | `virsh net-define /usr/share/libvirt/networks/default.xml`, then autostart + start. |
| Default network won't start / firewall error | Install `iptables-nft`, make sure `dnsmasq` is installed, restart `libvirtd.service`. |
| VM disk outside `/var/lib/libvirt/images` can't be opened | `sudo chown "$USER":libvirt-qemu /path/to/folder` (virt-manager may offer to fix it). |
| No UEFI option in virt-manager | Install `edk2-ovmf`, restart `libvirtd.service`. |
| Windows 11 refuses to install (TPM / Secure Boot) | Install `swtpm` + `edk2-ovmf`; add emulated TPM 2.0 and use UEFI firmware. |
| Package conflict between qemu variants | Install only one of `qemu-base` / `qemu-desktop` / `qemu-full`; let pacman replace the old one. |
| Slow VM | Confirm KVM (`ls /dev/kvm`), use VirtIO disk/network, give enough RAM/CPU, enable host CPU passthrough. |

---

## Uninstall

```bash
sudo systemctl disable --now libvirtd.service libvirtd.socket
sudo pacman -Rns virt-manager libvirt qemu-desktop      # use the QEMU package you installed
sudo gpasswd -d "$USER" libvirt
```

VM disks in `/var/lib/libvirt/images/` are not removed automatically; delete them yourself if you no longer need them.

---

## Notes for Claude when using this skill

- Default recommendation: `qemu-desktop libvirt virt-manager dnsmasq`; add `edk2-ovmf` and `swtpm` if the user mentions UEFI, Windows 11, or TPM.
- Offer `qemu-full` when the user needs non-x86 guests or special storage backends; offer `qemu-base` for headless servers.
- Never install two main QEMU packages together; they conflict.
- Always remind the user to re-login after adding the `libvirt` group.
- Use `--needed` with pacman to avoid reinstalling.
- Do not suggest running virt-manager as root.
- Ask which option fits (desktop / full / headless) if the user's goal is unclear, then give only that option's commands.
- If the user doesn't want virt-manager, offer only QEMU GUIs from "Alternatives to virt-manager (QEMU GUIs only)" and install only what the chosen option needs (skip `virt-manager`, keep libvirt for Cockpit/Boxes/qt-virt-manager).
- For plain QEMU command-line questions, use the "Essential QEMU CLI commands" section; always include `-enable-kvm` and VirtIO devices unless the guest can't use them.
- Do not suggest non-QEMU hypervisors (VirtualBox, VMware) unless the user explicitly asks.
- Quickgui/Quickemu/AQEMU/QtEmu are AUR packages: say so and mention an AUR helper (`yay`/`paru`) is needed.
