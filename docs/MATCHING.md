# Matching workflow

How to take a function from `stub` → `drafted` → `matched`.

## 1. Pick a function

Open `config/symbols.yaml`, find an entry with `status: stub`. Good
first targets are leaf functions (no callees, or only thoroughly-
matched callees) and small functions (size < 200 bytes).

```yaml
- addr: 0x004acc50
  name: CheckInstallPath
  size: 129
  group: engine.install
  status: stub
```

## 2. Read the original

Pull the disassembly + Ghidra pseudo-C:

```sh
# Asm (raw):
i686-w64-mingw32-objdump -d --start-address=0x004acc50 \
    --stop-address=$((0x004acc50 + 129)) game/MK4.EXE

# Or in Ghidra: navigate to 0x004acc50, look at Listing + Decompiler panes.
```

Decide which `src/<group>/<file>.c` it lives in (consult
`CONVENTIONS.md`'s naming + the `group` in symbols.yaml).

## 3. Write a draft

Write idiomatic C in the chosen file. Include the address comment,
match the function signature exactly. For globals, use the names
already in `include/<group>/*.h` — add new ones there if needed.

Set status to `drafted` in `symbols.yaml`.

## 4. Make it match

This is the hard part. Build the matching target:

```sh
make matching
make diff
```

The `diff` output will show where the rebuilt asm differs from the
original. For each mismatch, study the difference:

- **Different instruction selection** → maybe try a different C
  expression that nudges MSVC toward the same asm
- **Different register allocation** → try changing local variable
  declaration order (MSVC 5.0 is sensitive to this)
- **Extra prologue / epilogue** → check `__cdecl` vs `__stdcall`
- **Different constant encoding** → sometimes the original uses
  obscure tricks (e.g. `xor eax, eax` vs `mov eax, 0`)
- **Different optimization** → MSVC 5.0's `/O2` is aggressive but
  predictable; getting code to "fit" is mostly about C-level shape

For per-function detailed diff:

```sh
python3 tools/decomp/diff.py game/MK4.EXE build/MK4.matching.exe \
    --addr 0x004acc50
```

Iterate until the diff is empty for that function. Set status to
`matched`.

## 5. Common matching tricks (MSVC 5.0)

- **Variable declaration order** matters — MSVC 5.0 lays out locals
  on the stack in declaration order. Match the original's stack
  layout.
- **`int` vs `long`** — they're both 32-bit on Win32 but the
  compiler may emit different instructions. Check what the original
  used.
- **Loop styles** — `do/while` vs `while` vs `for` can produce
  different jump structures. Match the original.
- **Inline functions** — MSVC 5.0 has limited inlining; if the
  original has a tiny helper, it's usually not inlined.
- **`__forceinline`** doesn't exist in MSVC 5.0; use `__inline`.
- **Inline asm** — `__asm { ... }` blocks compile through. Use
  sparingly when the compiler can't generate the exact instruction.
- **Static functions** — `static` in C is the same; helps MSVC pick
  better calling conventions.

## 6. Mark it matched

Edit `config/symbols.yaml`:

```yaml
- addr: 0x004acc50
  name: CheckInstallPath
  size: 129
  group: engine.install
  status: matched     # <-- changed
```

Re-run `make progress` to see the bar move.

## 7. Don't break other matches

Re-run `make diff` after every change. If a previously-matched
function regresses, that's a problem: the change you made affected
the binary layout (e.g., reordered functions, changed data sizes).
Common causes:

- Adding a global → changes BSS layout → linker reorders
- Adding a string literal → changes `.rdata` content
- Reordering function definitions → affects `.text` ordering

Keep new globals + strings in the same source files as the original
(use `analysis/ghidra` to find which file owns each symbol).

## Tips

- Work bottom-up (leaves first) — if `A` calls `B`, get `B` matching
  first
- Small functions (< 100 bytes) are great practice for getting
  comfortable with MSVC 5.0's quirks
- The same C source MUST produce identical bytes EVERY time, so once
  you've matched, the function is done — no maintenance burden
- If a function seems impossible to match, leave a comment in the
  source explaining what you tried, and move on. Come back later.
