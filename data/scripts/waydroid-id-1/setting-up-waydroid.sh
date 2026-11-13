#!/bin/bash
set -e

case "$TUX_VAR_RENDER_MODE" in auto|igpu|cpu) ;; *) echo "Unexpected graphics choice."; exit 1 ;; esac
case "$TUX_VAR_SEPARATE_WINDOWS" in yes|no) ;; *) echo "Unexpected window choice."; exit 1 ;; esac
case "$TUX_VAR_SIZE_MODE" in auto|compact|large) ;; *) echo "Unexpected screen size choice."; exit 1 ;; esac
for x in $TUX_VAR_EXTRAS; do
  case "$x" in keep_awake|reverse_scroll|hotplug) ;; *) echo "Unexpected extra option: $x"; exit 1 ;; esac
done

# 1. binder: only when it is a loadable module (not built into the kernel), load it now and at every boot
for m in rust_binder binder_linux; do
  p=$(modinfo -n "$m" 2>/dev/null || true)
  case "$p" in
    ""|"(builtin)") ;;
    *)
      if [ "$m" = binder_linux ]; then
        echo "options binder_linux devices=binder,hwbinder,vndbinder" > /etc/modprobe.d/tux-store-waydroid.conf
      fi
      echo "$m" > /etc/modules-load.d/tux-store-waydroid.conf
      modprobe "$m" || echo "Could not load $m now; it will be tried again at boot."
      break ;;
  esac
done

# 2. the user's choices
install -d /etc/tux-store /usr/local/lib/tux-store
printf 'RENDER=%s\nWINDOWS=%s\nSIZE=%s\nEXTRAS=%s\n' "$TUX_VAR_RENDER_MODE" "$TUX_VAR_SEPARATE_WINDOWS" "$TUX_VAR_SIZE_MODE" "$TUX_VAR_EXTRAS" > /etc/tux-store/waydroid.conf

# 3. a small helper that applies them to Waydroid's config before the container starts
#    (Waydroid's own Android image is downloaded later, from inside Waydroid, so its config does not exist yet)
cat > /usr/local/lib/tux-store/waydroid-apply.sh <<'HELPER'
#!/bin/bash
# Installed by the Tux Store Waydroid add-on. Runs as root before waydroid-container starts.
CONF=/etc/tux-store/waydroid.conf
CFG=/var/lib/waydroid/waydroid.cfg
[ -r "$CONF" ] && [ -f "$CFG" ] || exit 0
RENDER=$(sed -n 's/^RENDER=//p' "$CONF" | head -n 1)
WINDOWS=$(sed -n 's/^WINDOWS=//p' "$CONF" | head -n 1)
SIZE=$(sed -n 's/^SIZE=//p' "$CONF" | head -n 1)
EXTRAS=$(sed -n 's/^EXTRAS=//p' "$CONF" | head -n 1)
node=""
if [ "$RENDER" = igpu ]; then
  for r in /sys/class/drm/renderD*; do
    [ -r "$r/device/vendor" ] || continue
    [ "$(cat "$r/device/vendor")" = "0x10de" ] && continue
    node="/dev/dri/${r##*/}"
    break
  done
fi
python3 - "$CFG" "$RENDER" "$WINDOWS" "$node" "$SIZE" "$EXTRAS" /etc/tux-store/waydroid.managed <<'PY'
import configparser, os, sys
path, render, windows, node, size, extras, mfile = sys.argv[1:8]
cp = configparser.RawConfigParser()
cp.optionxform = str
cp.read(path)
if not cp.has_section("properties"):
    cp.add_section("properties")
want = {"persist.waydroid.multi_windows": "true" if windows == "yes" else "false"}
if render == "cpu":
    want["ro.hardware.gralloc"] = "default"
    want["ro.hardware.egl"] = "swiftshader"
elif render == "igpu" and node:
    want["gralloc.gbm.device"] = node
ex = extras.split()
if "keep_awake" in ex:
    want["persist.waydroid.suspend"] = "false"
if "reverse_scroll" in ex:
    want["persist.waydroid.reverse_scrolling"] = "true"
if "hotplug" in ex:
    want["persist.waydroid.uevent"] = "true"
sizes = {"compact": ("576", "1024"), "large": ("720", "1280")}
if size in sizes:
    want["persist.waydroid.width"], want["persist.waydroid.height"] = sizes[size]
changed = False
# keys an earlier run of this add-on wrote and this run no longer wants
old = set(open(mfile).read().split()) if os.path.exists(mfile) else set()
# drop what an earlier choice of this add-on left behind
stale = []
if render != "cpu" and cp.has_option("properties", "ro.hardware.egl") and cp.get("properties", "ro.hardware.egl") == "swiftshader":
    stale.append("ro.hardware.egl")
    if cp.has_option("properties", "ro.hardware.gralloc") and cp.get("properties", "ro.hardware.gralloc") == "default":
        stale.append("ro.hardware.gralloc")
if render != "igpu":
    stale.append("gralloc.gbm.device")
for k in sorted(old - set(want)):
    if k not in stale:
        stale.append(k)
for k in stale:
    if cp.has_option("properties", k):
        cp.remove_option("properties", k)
        changed = True
for k, v in want.items():
    if cp.has_option("properties", k) and cp.get("properties", k) == v:
        continue
    cp.set("properties", k, v)
    changed = True
if changed:
    with open(path, "w") as f:
        cp.write(f)
with open(mfile, "w") as f:
    f.write("\n".join(sorted(want)) + "\n")
sys.exit(10 if changed else 0)
PY
[ $? -eq 10 ] && waydroid upgrade --offline
exit 0
HELPER
chmod 755 /usr/local/lib/tux-store/waydroid-apply.sh

# 4. run the helper every time the container starts, and enable the service
install -d /etc/systemd/system/waydroid-container.service.d
cat > /etc/systemd/system/waydroid-container.service.d/tux-store.conf <<'DROPIN'
[Service]
ExecStartPre=-/usr/local/lib/tux-store/waydroid-apply.sh
DROPIN
systemctl daemon-reload
systemctl enable waydroid-container.service
systemctl restart waydroid-container.service || echo "The container service did not start yet; it will be started again at boot."
exit 0
