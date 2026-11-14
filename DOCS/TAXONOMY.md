# Side Menu: Repositories, Groups and Categories

Files: `crates/tux-taxonomy/src/lib.rs`, `crates/tux-pacman/src/taxonomy.rs`,
`crates/tux-appstream/`, `data/group-families.json`, `data/addon_categories/`

The side menu has three browse sections. Repositories, groups and AppStream
categories are discovered from the machine at runtime; the only shipped
configuration is `data/group-families.json` plus the optional custom add-on
categories in `data/addon_categories/`. Nothing is a hand-written list of
packages.

```
Side menu
├── Categories     AppStream catalogs + the system category tree + data/addon_categories/
├── Groups         pacman -Sgg ∪ pacman -Qg, related names collapsed
└── Repositories   pacman.conf + pacman -Sl
```

`tux-taxonomy::build()` performs the discovery on a worker thread. The result is
kept in memory until an install, remove, add-on script finish or engine change
drops it.

## Repositories

A repository row is one `[section]` of `/etc/pacman.conf` in **registration
order** (the order pacman itself uses), never sorted A-Z:

| Part | Source |
|---|---|
| name | `pacman-conf --repo-list` |
| package count / installed count | `pacman -Sl` joined with `/var/lib/pacman/local` |
| `Official` / `Third-party` badge | hosts of the repo's `Server` lines compared with `/etc/pacman.d/mirrorlist` |
| package list | every sync package of that repo, installed or not |

The documented fallback is also used: a repo whose `Include` points at
`/etc/pacman.d/mirrorlist` is official even when its expanded servers cannot be
read.

Opening a repository sends `TaxonomyPackagesRequested { kind: Repository, id }`.
The answer is `TaxonomyPackagesReady` with the complete list, installed entries
first and then A-Z. Hidden packages are removed (see
[HIDDEN_PACKAGES.md](HIDDEN_PACKAGES.md)).

## Groups

Groups are the groups declared by **all sync databases** (`pacman -Sgg`) union
the groups declared by **all installed packages** (`pacman -Qg`). The second
pass is what makes local / AUR-only groups such as `cs50` or `selinux` visible.
A group present only in the local pass gets the `Local only` badge.

### Collapsing related groups into families

Arch repositories contain many closely related groups (`gnome`,
`gnome-extra`, `gnome-circle`, `kde-games`, `kde-pim`, …). The Groups page
collapses them **only when they share a whole leading word**:

- `gnome`, `gnome-extra`, `gnome-circle` → one **gnome** family;
- `kde-games`, `kde-pim` → one **kde** family;
- `kdevelop` stays alone: `kde` is a whole word, not a prefix.

The leading word is found by splitting on non-alphanumerics and on the
letter/digit boundary: `xfce4-goodies` → `xfce` + `4` + `goodies`. A family is
created only when it has at least `min_family_size` members and its key is at
least `min_key_len` characters long and is not in `never`.

`data/group-families.json` tunes the algorithm:

```json
{
  "min_family_size": 2,
  "min_key_len": 2,
  "never": ["lib", "python", "perl", "ruby", "go", "rust"],
  "aliases": { "kubectl": "kubernetes" },
  "force": {},
  "labels": { "kde": "KDE", "gnome": "GNOME" },
  "bundles": {}
}
```

| Key | Meaning |
|---|---|
| `min_family_size` | members needed to form a family |
| `min_key_len` | shortest allowed family key |
| `never` | leading words that must never create a family |
| `aliases` | map a first word to another family key (`kubectl-*` → `kubernetes`) |
| `force` | force one group name into a family key |
| `labels` | display label for a family key |
| `bundles` | hand-made families whose members do not share a first word |

A copy in `~/.config/tux-store/group-families.json` takes precedence over the
shipped file. An unreadable or invalid file is logged and the next candidate is
used. **No group is lost:** every group either becomes a family member or a
single row.

A family row has `expandable: true`; clicking it shows its member groups as
depth-1 rows. Opening a single row sends `TaxonomyPackagesRequested` and returns
the union of its members, installed first and then A-Z.

## Categories

AppStream is the only source of application categories; pacman has none. The
discovery joins three things:

1. **Components** — package name, display name, summary and raw freedesktop
   category ids from the AppStream catalogs (`/usr/share/swcatalog/xml/*.xml.gz`
   and the other locations `tux-appstream` knows).
2. **The category tree** — the system's own default tree, read from
   `libappstream` through `as_get_default_categories()`. It supplies the ids,
   localized titles, icons, nesting and order.
3. **The package index** — `pacman -Sl` plus the local database, to drop stale
   catalog entries and to know which rows are installed.

If `libappstream` cannot be loaded, the store falls back to one category per raw
id, humanized (for example `AudioVideo` → “Audio Video”). It never falls back to
a hard-written table. The source is reported as `libappstream` or `raw-ids`.

A category with no packages left after the join is not shown. Raw ids that no
tree node claims are collected in the final **Other** category instead of being
dropped.

On a typical Arch machine the top-level AppStream ids and titles are:

| Id | Title |
|---|---|
| `audio-video` | Audio & Video |
| `developer-tools` | Developer Tools |
| `education` | Education |
| `games` | Games |
| `graphics` | Graphics & Photography |
| `office` | Office |
| `science` | Science |
| `communication` | Communication & News |
| `utilities` | Utilities |
| `other` | Other (created only for unclaimed raw ids) |

Children such as `audio-video/music-players`, `developer-tools/ide` and
`games/strategy` are separate rows with Depth 1 and a parent id.

### Add-on packages in Categories

Interactive add-on packages (`data/scripts/*.json`) are not AppStream
components. They opt into one or more categories with the top-level keys
`category` (one name, kept for older files) and `categories` (a list):

```json
{
  "id": "gaming-setup-id-1",
  "title": "Gaming setup",
  "categories": ["games", "artcraft"],
  "show_on_home": true
}
```

- Each name is an AppStream **id** (`utilities`) or **title** (`Utilities`), or
  a **custom add-on category** id/title (`artcraft`); case, spaces, `&`, `_`
  and `-` are ignored.
- Every script that names at least one category is added to **all** of them,
  whether or not `show_on_home` is set. The two keys are independent, and the
  singular `category` is merged with the list.
- The add-on is listed like any package: its real title, description, version
  and installed state are used, and clicking it opens its add-on page.
- A name that matches nothing is logged as a warning and skipped; the other
  names still work. An AppStream category must exist on the system, while a
  custom category ships with the store.
- The `category` / `categories` keys belong to the script's own JSON; no
  separate file or central list is needed. See
  [SCRIPTS_SYSTEM.md](SCRIPTS_SYSTEM.md).

### Custom add-on categories

A custom category is a folder below `data/addon_categories/` (shipped) or
`~/.config/tux-store/addon_categories/` (the user's; the first one with a given
id wins). The folder name is the id, and it holds a JSON file of the same name
plus, optionally, its picture:

```text
data/addon_categories/artcraft/
├── artcraft.json
└── artcraft.svg
```

```json
{
  "schema": 1,
  "id": "artcraft",
  "title": "ArtCraft",
  "description": "Apps and add-ons from the ArtCraft suite.",
  "icon": { "file": "artcraft.svg" }
}
```

| Key | Required | Meaning |
|---|---|---|
| `schema` | no | `1` (the only version) |
| `id` | yes | the folder name: lowercase letters, digits and `- _ . +` only |
| `title` | yes | the row's name in the Categories page (1–80 characters) |
| `description` | no | one sentence about the category |
| `icon` | no | where the row's picture comes from, see below |

`icon` names **exactly one** source:

| Key | Thumbnail |
|---|---|
| `file` | a `.svg` / `.png` / `.ico` **next to the JSON** (bare file name) |
| `url` | a plain `https://` link on a trusted host, downloaded once and cached |
| `flathub` | a Flathub **app id** only (`org.gnome.Builder`); the store builds the icon link itself |

```json
"icon": { "flathub": "org.gnome.Builder" }
```

The three forms become the same kind of icon request the add-on packages use,
under the key `addon-category-<id>`, so the thumbnail module caches them like
any other picture. Without an `icon` the row shows its first letter.

How a custom category behaves:

- Its id in the taxonomy is `addon:<id>` (`addon:artcraft`), so it can never
  collide with an AppStream id (which may itself be `artcraft`).
- Custom categories are listed **before** the AppStream categories, in file
  (folder) order. Their members are the add-on packages that name them;
  nothing else can be a member.
- A category with no members is not shown, exactly like an empty AppStream
  category.
- A custom category wins when its id or title equals an AppStream one.
- The add-on package lists inside it follow the normal rules: hidden packages
  are removed, installed entries come first, then A-Z.

See [SCRIPTS_SYSTEM.md](SCRIPTS_SYSTEM.md) for how an add-on joins a category,
and `data/addon_categories/artcraft/` for a complete example.

### Hidden packages

All three sections remove packages listed in
`data/hidden_packages.json` or `~/.config/tux-store/hidden_packages.json`,
before counts are calculated. For categories the display title from AppStream is
checked as well as the package name. See
[HIDDEN_PACKAGES.md](HIDDEN_PACKAGES.md).

## Messages and caching

| Request | Answer |
|---|---|
| `TaxonomyRequested` | `TaxonomyReady { taxonomy }` — all rows of the three sections |
| `TaxonomyPackagesRequested { kind, id }` | `TaxonomyPackagesReady { kind, id, title, subtitle, packages }` |

`TaxonomyReady` contains `repositories`, `groups`, `categories`, plus
`raw_categories` (each raw AppStream id and its component count) and
`category_source`. The UI renders one list for the active section; families can
be expanded in place. While a section entry is open, the list is paged in the UI,
not in the backend.

The cached taxonomy is dropped after `OperationFinished`, `ScriptEnded` and
`EngineChanged`; the next request rebuilds it so installed counts and the
category membership are current.

## Inspecting the result

```bash
tux-store --dump-taxonomy
```

This builds the taxonomy exactly as the store does and prints `Taxonomy` as
JSON, followed by a one-line summary on stderr (number of repositories, group
rows, categories, source and elapsed time). Custom add-on categories appear in
`categories` with their `addon:<id>` id and their `addon-category-<id>` icon.
It is the quickest way to check what a machine actually reports before changing
code or documentation.
