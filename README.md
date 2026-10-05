# gramide-c

The standalone `gramide_c` language package for [gramide](https://github.com/O6lvl4/gramide).
The grammar and scanner are original implementations informed by
[C11 draft N1570, section 6](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf).

## Coverage

- Functions and prototypes, typedefs, structs/unions, enums, fields and variables
- Pointer and array declarators; parameters, initializers and designated fields
- Blocks, if/else, loops, switch/case, jumps and returns
- Calls, member/subscript access, casts and operators with C precedence levels
- C comments, quoted literals and prefixes, numeric suffixes, UTF-8 byte spans
- Source-level preprocessing directives retained as opaque nodes, including continuations

This is a **core reader**, not a C compiler or a preprocessor. It offers `tokens`,
`parse`, `outline`, `symbols`, `tags` and `map`; it does **not** advertise `check`
or recovered symbols. A file outside this subset may be valid C. A parsed file
may still violate type, declaration or preprocessing constraints.

Known limits include macro expansion and conditional preprocessing, typedef-name
disambiguation, complex function-pointer declarations/parameters, old-style
definitions, GNU/MS extensions, C23 additions, `_Generic`, `_Alignas`, `_Atomic`
type specifiers and compound literals. Numeric/character spelling is read
permissively. `.h` is treated as C; C++ headers need their own future package.
No whole-corpus or tree-sitter-equivalence claim is made.

## Development

From this directory: `almide test`, then
`almide build cli/main.almd -o gramide_c`.
Regenerate the committed table with `./gramide_c gen-table > src/table.almd`.
Run `bash ci/check.sh` for the standalone package test, table and fixture gates.

MIT or Apache-2.0, at your option; see LICENSE-MIT and LICENSE-APACHE.

Source line endings are LF or CRLF. Lone CR is refused in strict mode because
the pinned engine uses LF-based document line counts; this prevents inconsistent
complete symbol ranges for older-Mac or control-bearing source files.

Symbol spans start at the declaration/type (including shared type text in a
comma-separated declaration). A grouped declarator or field can end before its
comma/semicolon; it is a syntax-node range, not a standalone C statement.

## Repository contract

This repository owns this language package and its tests. `src/mod.almd` exports
`definition()` using the shared gramide package API. The `gramide-cli` repository
composes it as a git dependency; no grammar source is vendored into the CLI.
`bash ci/check.sh` runs the complete package gate with an explicit test entry
point, avoiding recursive parallel compiler fan-out. CI pins Almide and Rust
in `.github/workflows/quality.yml`.
