# Scripts (Interactive Add-on Packages)

Files: `data/scripts/*.json`, `crates/tux-abi/src/script.rs` (format + validation), `crates/tux-abi/src/receipt.rs` (install records), `crates/tux-script/` (engine)

A **script** is a package that is not in pacman: Tux Store shows it like any other app (search, Home shelf, the Categories pages it opts into, its own page), but pressing **Install** runs a small guided flow described by **one JSON file**. The same file can describe how to **uninstall** it later.

> Nothing is hard-coded: to add a new add-on package you only drop a JSON file in a folder. No Rust, no rebuild.

## 1. Where the files go

| Folder | Who owns it | Trust |
|---|---|---|
| `data/scripts/` (installed as `/usr/share/tux-store/scripts/`) | shipped with the store | trusted |
| `~/.config/tux-store/scripts/` | the user | **not trusted**: the store lists every administrator command and asks for confirmation before running it |

Rules:

- One script = one `*.json` file directly inside the folder (sub-folders are **not** scanned).
- The first script with a given `id` wins; a user file can never replace a shipped script.
- A file that fails validation is **skipped and logged** (run with `TUX_LOG=debug` or `warn` to see why). The store keeps starting.
- Maximum file size 512 KiB, at most 200 steps, 64 commands per `run` step, 40 options per `choice`.
- Icons referenced with `"file"` must sit **in the same folder as the JSON** (`data/scripts/my-tool-id-1.svg`).

### File name and `id`

Name the file after the id: `my-tool-id-1.json`. The `id` must be lowercase letters, digits and `- _ . +` only. It is the key of the install record, so **never change it** after you released the script.

## 2. Minimal script

```json
{
  "schema": 2,
  "id": "hello-id-1",
  "title": "Hello",
  "description": "A harmless demo.",
  "version": "1.0",
  "author": "You",
  "keywords": ["hello", "demo"],
  "show_on_home": true,
  "category": "utilities",
  "start": "welcome",
  "uninstall": "un_done",
  "steps": {
    "welcome": {
      "type": "dialog",
      "title": "Hello!",
      "message": "Install the demo?",
      "buttons": [
        { "label": "Install", "style": "primary", "goto": "work" },
        { "label": "Cancel", "exit": true }
      ]
    },
    "work": {
      "type": "run",
      "title": "Working…",
      "commands": [
        { "label": "Creating a file", "shell": "mkdir -p \"$HOME/.local/share/hello\" && echo hi > \"$HOME/.local/share/hello/hi.txt\"", "percent": 90 }
      ],
      "on_success": "remember"
    },
    "remember": { "type": "record", "files": ["~/.local/share/hello"], "next": "done" },
    "done": { "type": "finish", "title": "Done", "message": "Installed.", "mark": "installed" },

    "un_done": { "type": "finish", "title": "Nothing to do", "mark": "uninstalled" }
  }
}
```

## 3. Top-level keys

| Key | Required | Meaning |
|---|---|---|
| `schema` | yes | `2` (version `1` files still load, but have no `info` / `icon` / `percent`) |
| `id` | yes | unique id, see above |
| `title` | yes | name shown on the card and page |
| `description` | no | one or two sentences |
| `version` | no | text, **or** a command object (see *Dynamic values*) |
| `author` | no | shown in “About this add-on package” |
| `keywords` | no | extra search words (any language: `"فلاشة"` works) |
| `show_on_home` | no | list it in the Home “Tools & Scripts” shelf |
| `category` | no | AppStream category id or title (`utilities`, `developer-tools`, `games`, …). Lists it in that **Categories** page too |
| `categories` | no | every category it belongs to, as a list: AppStream ids/titles and/or custom add-on category ids (`["artcraft", "graphics"]`). Merged with `category` |
| `info` | no | `download_mb`, `extracted_mb`, `installed_mb`, `note` (numbers, or command objects) |
| `icon` | no | one source or a list tried in order: `{"file": "x.svg"}`, `{"theme": "nvidia"}`, `{"url": "https://…png"}` |
| `vars` | no | initial variables (`{"gpu_model": "unknown"}`) |
| `start` | yes | name of the first step of the **install** flow |
| `uninstall` | no | name of the first step of the **uninstall** flow. Without it the Uninstall button never appears |
| `steps` | yes | the state machine: `{ "step_name": { "type": …, … } }` |

**Unknown keys are errors.** A typo such as `on_succes` is rejected instead of silently changing behaviour. Every `goto` / `next` / `on_success` / `on_failure` must name an existing step.

### Home and Categories

`show_on_home` and the categories are independent:

- `show_on_home: true` adds the add-on to the Home **Add-on packages** shelf.
- `category: "utilities"` adds it to the **Categories → Utilities** page, even
  when `show_on_home` is `false`.
- `categories: ["artcraft", "graphics"]` adds it to **every** listed page at
  once. The singular `category` still works and is merged with the list, so
  both keys may be used in the same file.
- With none of them the add-on is still found by search and reachable through
  its own page.

```json
{
  "category": "graphics",
  "categories": ["artcraft"]
}
```

The example above lists the add-on in **Graphics & Photography** (AppStream) and
in **ArtCraft** (the custom category in `data/addon_categories/artcraft/`). The
order of the names is kept, repeated names are ignored, at most 16 are allowed.

`category` / `categories` accept:

- an AppStream category **id** or display **title** — case, spaces, `&`, `_`
  and `-` are ignored (`graphics`, `Graphics & Photography`, `raw:Graphics`);
- a **custom add-on category id or title** — the folder name below
  `data/addon_categories/` or its `title` (`artcraft`, `ArtCraft`).

Common AppStream ids:

| Id | Category |
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

An unknown name is logged as a warning and skipped; the add-on still appears in
the other categories it named, in Home and in search. An AppStream category
must exist on the user's machine (for example it is missing when AppStream
itself is missing), while a custom add-on category ships with the store. A
custom category wins when it has the same id or title as an AppStream one.

The Categories page shows the add-on like any package, with its real title,
description, version and installed state; clicking it opens the add-on page.
See [TAXONOMY.md](TAXONOMY.md#add-on-packages-in-categories) and
[TAXONOMY.md](TAXONOMY.md#custom-add-on-categories).

Stores older than 0.15.0 reject the unknown `category` / `categories` keys, like
every other key added after their release.

## 4. Variables

- Declared in `vars`, set by `choice` (`store_as`), `check` (`capture`), `set`, `record` and button `set`.
- Names: start with a lowercase letter, then lowercase letters, digits, `_` (max 48 chars).
- In JSON **text** (titles, messages, `argv` items, conditions) write `${name}`. An unknown variable is empty. `$$` is a literal `$`.
- In **shell text** `${name}` is deliberately **not** replaced. The value arrives as the environment variable `TUX_VAR_NAME` (upper-case). Always quote it: `"$TUX_VAR_NAME"`. This way a value can never change the structure of a command.
- Variables bigger than 8 KiB are not exported to commands.
- The engine fills some for you: `script_id`, and after a failed command `last_failed` (its label), `last_exit_code`, `last_output` (last 2000 chars).

### Conditions (`when`)

All parts present must hold (AND). Unset variables compare as `""`. Operands are interpolated.

```json
{ "var": "driver", "eq": "open" }
{ "var": "driver", "ne": "${gpu_branch}" }
{ "var": "gpu_branch", "one_of": ["470xx", "390xx"] }
{ "all": [ {…}, {…} ] }   { "any": [ {…}, {…} ] }   { "not": {…} }
```

## 5. Step types

Every step has `"type"`. Text fields accept a string **or an array of lines** (joined with `\n`), which is how you write long messages and multi-line shell code in JSON.

### `dialog` — message with buttons
```json
{ "type": "dialog", "title": "…", "message": ["line 1", "line 2"], "tone": "info",
  "buttons": [ { "label": "Continue", "style": "primary", "goto": "next_step" },
               { "label": "Cancel", "exit": true } ] }
```
`tone`: `info` (default) · `warning` · `error` · `success`. `style`: `primary` · `secondary` (default) · `danger`. A button needs **exactly one** of `goto` or `exit` (ends the script). It may also carry `"set": {"var": "value"}`.

### `choice` — pick one option
```json
{ "type": "choice", "title": "Pick", "store_as": "flavour", "default": "${suggested}", "next": "confirm",
  "continue_label": "Continue",
  "options": [ { "value": "a", "label": "Option A", "hint": "Explains A.",
                 "notes": [ { "when": {"var": "suggested", "eq": "a"}, "text": "✔ Recommended" } ],
                 "visible_if": { "var": "advanced", "eq": "yes" },
                 "set": { "pkgs": "foo bar" }, "goto": "special_step" } ],
  "buttons": [ { "label": "Back", "goto": "welcome" } ] }
```
The chosen `value` goes into `store_as`. An option's `set` is applied when picked; its `goto` overrides `next`. Values must be unique and non-empty.

### `check` — silent command
```json
{ "type": "check", "command": { "label": "Looking for yay…", "shell": "command -v yay >/dev/null 2>&1" },
  "capture": "result", "on_success": "ok_step", "on_failure": "fail_step" }
```
Exit code 0 = success. Runs **silently, never as root**, default timeout 20 s. `capture` stores the trimmed standard output in a variable **even when it fails**. Idiom used by the shipped scripts: print an error text and `exit 0`, then `branch` on `capture != ""`.

### `run` — visible commands with a progress bar
```json
{ "type": "run", "title": "Installing…", "message": "Please wait.",
  "commands": [ { "label": "Installing build tools", "shell": ["pacman -S --needed --noconfirm base-devel"],
                  "root": true, "weight": 2, "expected_secs": 40, "percent": 30 } ],
  "on_success": "next_step", "on_failure": "install_failed", "echo": false }
```
- A command has **exactly one** of `shell` (run with `sh -c`) or `argv` (program + arguments, no shell, `${var}` allowed).
- `root: true` runs it through **pkexec** (polkit shows the password dialog). Only `run` commands may be root.
- `when` skips a command; `ignore_failure` keeps going after a failure; `timeout_secs` kills it; `env` adds environment variables.
- Progress: `weight` (relative share), `expected_secs` (shapes the bar), `percent` (absolute 0–100 once this command is done — also works across several `run` steps).
- Without `on_failure` a generic error screen is shown. `echo: true` also prints the output to the terminal the store was started from (handy while developing).

### `branch` — decide
```json
{ "type": "branch", "cases": [ { "when": {"var": "err", "ne": ""}, "goto": "failed" } ], "default": "continue" }
```
First matching case wins.

### `set` — assign variables
`{ "type": "set", "vars": { "msg": "text ${other}" }, "next": "step" }`

### `print` — write to the terminal the store was started from
`{ "type": "print", "text": "debug ${var}", "next": "step" }`

### `record` — remember what the install did (the **install record**, see §7)
```json
{ "type": "record", "set": { "installed_driver": "${driver}" },
  "packages": ["${driver_packages}"], "files": ["~/.local/share/ventoy", "/opt/thing"], "next": "done" }
```

### `finish` — end the flow
```json
{ "type": "finish", "title": "Installation Complete", "message": "…", "success": true, "button": "Close", "mark": "installed" }
```
`mark` tells the store what this ending means: `"installed"` writes the finished record, `"uninstalled"` deletes it. Without `mark` the record is left as it is.

## 6. Install and uninstall

### Install flow
1. The user opens the add-on page and presses **Install**. The engine starts at `start`.
2. A script from the user's folder first shows a **trust screen** with every command that asks for administrator rights; nothing runs until the user agrees.
3. Typical shape: `dialog` (explain) → `check` (tools / network / free space) → `choice` (options) → `dialog` (confirm) → `run` (do it) → `check` (verify) → `record` → `finish` with `"mark": "installed"`.
4. Put the **`record` step after the commands succeeded**, right before `finish`. Then the record never claims something that was not done.

### Uninstall flow
1. The page shows **Uninstall** only when the script has `uninstall` **and** an install record exists.
2. The engine starts at the `uninstall` step. It sees the record as variables:
   - every variable chosen during the install (`driver`, …) and every `record.set` value,
   - `${installed_version}`,
   - `${recorded_packages}` — recorded pacman packages joined with spaces (use `$TUX_VAR_RECORDED_PACKAGES` in shell),
   - `${recorded_files}` — recorded files, one per line (`$TUX_VAR_RECORDED_FILES`).
3. Typical shape: `dialog` (what will be removed, `danger` button) → optional `check` (pacman locked? pkexec present?) → `run` (remove) → `finish` with `"mark": "uninstalled"`.
4. Reaching a `finish` with `"mark": "uninstalled"` deletes the record. If the removal fails, **do not mark** — the record stays so the user can try again.

Safe removal snippets (the shipped scripts use exactly these):

```sh
# files: only inside $HOME
printf '%s\n' "$TUX_VAR_RECORDED_FILES" | while IFS= read -r f; do
  case "$f" in "$HOME"/*) rm -rf -- "$f"; echo "removed $f" ;; *) echo "skipped $f" ;; esac
done

# packages: only those still installed (run with "root": true)
inst=""; for p in $TUX_VAR_RECORDED_PACKAGES; do pacman -Qq "$p" >/dev/null 2>&1 && inst="$inst $p"; done
[ -n "$inst" ] && pacman -Rns --noconfirm $inst
```

## 7. Install records ("fingerprints" / receipts)

A record is a small JSON file written by the engine: `~/.local/share/tux-store/addons/<id>.json` (`$XDG_DATA_HOME` respected). It is what makes the page say **Installed** and what the uninstall flow reads.

```json
{
  "id": "ventoy-installer-id-1",
  "title": "Install Ventoy",
  "script_version": "",
  "installed_version": "v1.0.99",
  "installed_at": 1793722337,
  "complete": true,
  "vars": { "ventoy_version": "v1.0.99" },
  "values": { "installed_driver": "open" },
  "packages": ["nvidia-open-dkms"],
  "files": ["/home/me/.local/share/ventoy"]
}
```

| Field | Written by | Meaning |
|---|---|---|
| `complete` | `finish` + `mark: installed` | `false` while an install is only partly done (a `record` step ran but the flow did not finish) |
| `installed_at` | `mark: installed` | Unix seconds |
| `installed_version` | `mark: installed` | the variable `installed_version` if non-empty (capture it with a `check`), else the script's written `version` |
| `vars` | `record` / `mark: installed` | snapshot of the user's choices (engine variables `last_*`, `recorded_*`, `script_id` are left out) |
| `values` | `record.set` | values you asked to remember |
| `packages` | `record.packages` | pacman packages; each word must be a valid package name; duplicates are ignored |
| `files` | `record.files` | absolute paths or `~/…`; `..` and `/` are rejected; the install **stops with an error** on a bad path |

Notes:

- You may use several `record` steps (e.g. after each phase); they accumulate.
- The file is written atomically, so a crash never leaves half a record.
- Deleting the JSON by hand makes the store forget the install (the page shows **Install** again).
- Ids are validated, so a record can never be written outside its folder.

## 8. Dynamic values (`version`, `info`)

`version` and the three `info` sizes can be a plain value **or** a command that prints it:

```json
"version": { "label": "Latest version", "shell": ["pacman -Si nvidia-utils | awk '/^Version/ {print $3; exit}'"] },
"info": { "download_mb": { "label": "Download size", "shell": "echo 15" }, "installed_mb": 50, "extracted_mb": 50,
          "note": "Shown under the sizes." }
```

The command runs silently, without root, with a time limit; the **last non-empty line** of its output is used (for sizes: the first number on that line, rounded up, in MB). Scripts from the user's folder only run these after the user presses the “Calculate” button.

## 9. Checking a script: `--check-script`

```bash
tux-store --check-script ~/.config/tux-store/scripts/my-tool-id-1.json
```

Uses the store's own loader, so *valid* here means the store will load it. On a problem it prints the reason and a hint (misspelled key, missing key, unknown step type, broken JSON) and exits with code 1. When the file is valid it also lists warnings: steps nothing leads to; no `finish` with `"mark": "installed"` / `"uninstalled"`; no `uninstall`; uninstall without any `record` step in the install flow; missing description / keywords; an icon file that is not next to the JSON; and the list of commands that ask for administrator rights.

## 10. Checklist before you ship a script

1. `uninstall` points to a step and the flow ends in `"mark": "uninstalled"`.
2. Everything the install creates is listed in a `record` step (`files` / `packages`).
3. Every `root` command is justified; checks never use `root`.
4. Shell variables are used as `"$TUX_VAR_X"` (quoted), never pasted into the command.
5. Every failure path ends in a `dialog` with `"tone": "error"` and a `Close` button.
6. Run it: `TUX_LOG=debug ./target/debug/tux-store`, open the page, install, uninstall, check `~/.local/share/tux-store/addons/`.
7. If it should appear in Categories, add a valid `category` or `categories` and check that page; it appears there even when `show_on_home` is `false`.
8. The shipped files are good templates: `multimedia-codecs-id-1.json` (a choice, "only what is missing" detection, record of just the new packages, safe per-package uninstall), `hello-test-id-2.json` (all step types), `ventoy-installer-id-1.json` (Ventoy: download + extract + shortcut + file-based uninstall), `nvidia-drivers-id-1.json` (checks, choices, root, package-based uninstall).

## Screenshots (0.10.0)

Optional top-level key, shown as the Screenshots slider on the script's page:

```json
"screenshots": [ { "file": "my-script-id-1.png" }, { "url": "https://raw.githubusercontent.com/me/repo/main/2.png" } ]
```

Each item has exactly one of `file` (bare `.png`/`.jpg`/`.jpeg` name next to the JSON) or `url` (`https://` on a trusted host). Max 12, order kept. Details: `SCREENSHOTS.md`. Stores older than 0.10.0 reject the key, as with every unknown key.

## Check boxes, option pictures, real progress, logs (0.11)

**Check boxes.** `choice` with `"multiple": true` shows check boxes. `store_as` receives every ticked `value` joined with spaces, in option order (`for x in $TUX_VAR_EXTRAS; do …; done`). `default` is a space-separated list of values ticked at the start; `min_select` (default 0) is how many must be ticked to continue. Values must not contain white space and options cannot have `goto` in a multiple choice. Each ticked option's `set` is applied. The radio-button choice is unchanged.

**Option pictures.** Any option (radio or check box) may have `"icon"`, with the same sources as the add-on icon: `{"file": "x.svg"}` (next to the JSON), `{"theme": "firefox"}`, `{"url": "https://…png"}`, or a list tried in order.

**Progress bar.** `percent` is cumulative over the whole add-on (e.g. 50, then 90, then 100); the label of the running command is shown beside the bar. Inside a command the bar can follow real progress instead of creeping:
- `"progress": "percent"` reads the last `NN%` from the command's output (`curl -#`, `wget`, `rsync --info=progress2`);
- any command can print `TUX_PROGRESS=NN` (0–100); that line is hidden.
The bar then moves from the previous `percent` to this command's `percent` and ends exactly there.

**Logs.** Every install/uninstall that runs a command or fails saves what the console showed (colours removed, progress meters collapsed) to `~/.local/state/tux-store/logs/tux-store-<HH-MM-SS>-<YYYY-MM-DD>-<add-on title>.log` (`$XDG_STATE_HOME` respected). The path is shown on the last screen and in the console.

## Script files in a folder (instead of bash inside JSON)

Put a folder named like the JSON **without `.json`** beside it:

```
data/scripts/nvidia-drivers-id-1.json
data/scripts/nvidia-drivers-id-1/nvidia-install.sh
data/scripts/nvidia-drivers-id-1/detect.py
```

A command then names only the file:

```json
{ "label": "Installing the driver", "script": "nvidia-install.sh", "root": true,
  "args": ["--branch", "${driver}", "@{extras}"], "progress": "percent", "percent": 80 }
```

- The store finds the folder itself; `script` is a bare file name (no `/`). Works in `run` and `check` steps and in `version`/`info` commands.
- The file must start with `#!` (`#!/bin/bash`, `#!/usr/bin/env python3`, …). It need not be executable.
- `args`: `"${var}"` is one argument; an element that is exactly `"@{var}"` becomes one argument per space-separated word, which is what a `multiple` choice stores. Variables are also in the environment as `$TUX_VAR_<NAME>`, and `$TUX_ADDON_DIR` is the folder (to call sibling files).
- `root`, `when`, `ignore_failure`, `timeout_secs`, `percent`, `progress`, `TUX_PROGRESS=NN` and the log all work exactly as for `shell`/`argv`. A symlink cannot lead outside the folder.
- `tux-store --check-script` warns about a missing file or a missing `#!` line. User add-ons: put the folder in `~/.config/tux-store/scripts/` beside the JSON.

> **All shipped add-ons use this layout.** Each `data/scripts/<name>.json` has a folder `data/scripts/<name>/` with its `.sh` files; the JSON only lists steps, choices and file names. The folder is named after the JSON file (not the `id`).
>
> **Asking a script for information.** A silent `check` step can call a script with parameters and show the result to the user before anything is installed:
> `{"type":"check","command":{"script":"query.sh","args":["latest","${tool}"]},"capture":"latest","on_success":"confirm","on_failure":"error"}` — then use `${latest}` in the next dialog (`"Latest Laravel: ${latest}"`). Checks never run as root and are limited to 20 s by default (`timeout_secs`).
