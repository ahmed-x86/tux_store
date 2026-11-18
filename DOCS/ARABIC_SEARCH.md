# Arabic Search Normalization

Files: `crates/tux-abi/src/text.rs`, `crates/tux-search/src/normalize.rs`,
`crates/tux-search/src/catalog.rs`, `crates/tux-pacman/src/queries.rs`,
`crates/tux-libalpm/src/libalpm/query.rs`, `crates/tux-abi/src/script.rs`

Arabic text often uses different letter forms for the same word. A user may
type `احمد` while a package description says `أحمد`, or type `علي` while the
description says `على`. Search folds those variants on **both** the query and
the target text before comparing them. Latin text is unchanged.

## Folding rules

`tux_abi::text::normalize_arabic(text: &str) -> String` applies exactly these
mappings:

| Input | Output |
|---|---|
| `ا` `أ` `إ` `آ` `ٱ` | `ا` |
| `ي` `ى` | `ي` |
| `ة` `ه` | `ه` |

Everything else is copied unchanged: Latin letters, digits, punctuation and
Arabic diacritics are not removed. The caller still decides about case and
separators.

`tux_abi::text::contains_arabic(text: &str) -> bool` reports whether a string
contains Arabic-script characters. It checks the Arabic, Arabic Supplement,
Arabic Extended-A and Arabic Presentation Forms blocks.

`tux-search` re-exports `normalize_arabic` for callers that only depend on the
search crate.

## Search key

`tux-search/src/normalize.rs` builds the comparison key used by the add-on
catalog:

```rust
pub(crate) fn search_key(text: &str) -> String {
    normalize_arabic(text)
        .chars()
        .filter(|c| !matches!(c, ' ' | '-' | '_' | '.'))
        .flat_map(char::to_lowercase)
        .collect()
}
```

So `LibreOffice-Fresh` and `libreoffice fresh` produce the same key, and
`أحمد` and `احمد` both become `احمد`.

The direct pacman and libalpm query layers have their own small `normalize()`
helpers with the same steps: `normalize_arabic` first, then remove spaces,
`-`, `_`, `.`, then lower-case.

## Where it is applied

### Direct pacman (`crates/tux-pacman/src/queries.rs`)

- `normalize(query)` and `normalize(package.name)` place both sides in the
  same form before the containment check.
- `pacman -Ss` already searches descriptions, but `parse_search()` previously
  kept only results whose **name** contained the query. When the query contains
  Arabic (`contains_arabic(query)`), a normalised **description** match is now
  accepted too. The `installed` flag still comes from the local database and
  ranking is unchanged.

### Libalpm (`crates/tux-libalpm/src/libalpm/query.rs`)

- Names are normalised with the same helper.
- For Arabic queries, `pkg.desc()` is normalised and accepted as a match when
  the name does not match.
- De-duplication and ranking behave like the direct path.

### Add-on catalog (`crates/tux-search/src/catalog.rs`)

`Catalog::scripts_matching()` normalises the query once with `search_key()` and
passes the same function to `Script::matches()`. That method checks:

- `id`
- `title`
- `description`
- every `keyword`

each normalised before the containment test. This means add-on scripts can be
found by an Arabic word in their description, not only by id/title/keywords,
and the match works in both Arabic letter styles.

### UI search

The UI sends the raw text; normalization is entirely a backend concern. The
same query therefore reaches all three paths unchanged.

## Examples

| Query | Target | Result |
|---|---|---|
| `احمد` | `أحمد` | match |
| `أحمد` | `احمد` | match |
| `علي` | `على` | match |
| `على` | `علي` | match |
| `مدرسه` | `مدرسة` | match |
| `libreoffice fresh` | `LibreOffice-Fresh` | match (case and separators) |

## Limits

- No stemming, tashkeel removal or spelling correction: only the letter
  variants in the table are folded.
- `normalize_arabic` does not lower-case or remove separators; use the search
  key helpers for that.
- The description fallback in the pacman/libalpm paths is limited to Arabic
  queries, because those paths query pacman by name and only need the fallback
  to make already-returned Arabic descriptions searchable.
- The add-on catalog always searches descriptions, for Arabic and Latin
  queries alike.

## Tests

- `crates/tux-abi/src/text.rs`:
  `arabic_normalization_folds_letter_variants` and
  `arabic_detection_ignores_latin_text`.
- `crates/tux-search/src/normalize.rs`: alef variants, alef maqsura/yaa, taa
  marbuta/haa, separators/case, and empty queries.

See [PACMAN_MANAGER.md](PACMAN_MANAGER.md#search) for the surrounding search
pipeline and [PACKAGE_MODEL.md](PACKAGE_MODEL.md#helpers-textrs) for the shared
text helpers.
