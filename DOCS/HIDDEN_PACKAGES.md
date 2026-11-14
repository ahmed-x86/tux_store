# Hiding Packages

Files: `data/hidden_packages.json`, `crates/tux-abi/src/hidden.rs`

Tux Store can hide packages from the store without touching the system. A
hidden package is still installed, upgraded and managed by pacman normally; it
simply does not appear in the store's browsing, search and category lists.

## Two files, merged

| File | Who owns it |
|---|---|
| `data/hidden_packages.json` (installed as `/usr/share/tux-store/hidden_packages.json`) | shipped with the store |
| `~/.config/tux-store/hidden_packages.json` (`$XDG_CONFIG_HOME` respected) | the user |

Both files are read at start-up and their lists are **added together**. The
user's file does not replace the shipped list, so hiding one more package only
requires a small file of your own.

## Format

```json
{
  "note": "Packages listed here are hidden across Tux Store.",
  "hide_in_installed": false,
  "hidden_packages": [
    "nvidia",
    "nvidia-utils",
    "xiphos",
    "bibletime"
  ]
}
```

| Key | Required | Meaning |
|---|---|---|
| `hidden_packages` | yes (may be empty) | Package names (or display titles) to hide |
| `hide_in_installed` | no, default `false` | Also hide these entries from the **Installed** tab |
| `note` | no | Free text for humans; the store ignores it |

Unknown keys are rejected, so a typo is reported in the log instead of being
silently ignored.

The simplest personal file is therefore just:

```json
{ "hidden_packages": ["telegram-desktop", "steam"] }
```

## Matching rules

- Comparison is **case-insensitive** and ignores leading / trailing spaces:
  `"VLC"`, `"vlc"` and `" vlc "` all hide `vlc`.
- Matching is **exact**. There are no globs, regular expressions or prefixes:
  `"nvidia*"` hides nothing, and hiding `nvidia` does **not** hide
  `nvidia-utils`.
- A package is hidden when either its pacman name or its display title (when
  the store knows one, for example from AppStream) appears in the list.
- Each entry must be a valid package-style name: 1–128 bytes, ASCII letters,
  digits and `@ . _ + -`, and it must not start with `-` or `.`. Invalid
  entries are ignored and logged as a warning.

Anything not listed stays visible. Dependencies are **not** hidden
automatically; if you want all of them gone from the lists, list each one.

## Where hiding applies

A hidden package disappears from:

- the Home shelves and the Home **Add-on packages** shelf;
- search results, including interactive add-on packages (scripts);
- the add-on / language-pack lists attached to another package;
- the details page and direct `tux-store openpackage <name>` (the request is
  refused);
- the **Categories**, **Groups** and **Repositories** pages, including the
  category an add-on package declares in its own JSON;
- the **Installed** tab, but only when `hide_in_installed` is `true`. Otherwise
  installed packages remain listed there so the user can still see and remove
  them.

Hiding does not change the system or pacman's view:

- the package is not uninstalled;
- the **Updates** tab still reports its pending upgrade;
- dependency calculation, install and remove operations are unaffected;
- dependency rows on a details page are not filtered.

## Applying a change

The list is loaded once when the search module starts. Save the file and
restart Tux Store. A running window picks up the change on the next start,
including after an install/remove refresh.

## Related

- [TAXONOMY.md](TAXONOMY.md) — how Categories, Groups and Repositories are discovered.
- [SCRIPTS_SYSTEM.md](SCRIPTS_SYSTEM.md) — add-on packages and their `category` key.
