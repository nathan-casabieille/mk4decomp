# MK4 decomp — coding conventions

These conventions exist so that contributions stay consistent and so
that the matching build target keeps producing byte-identical output.
Read [docs/MATCHING.md](docs/MATCHING.md) before claiming functions.

## Naming

| Kind | Style | Example |
|---|---|---|
| Functions (engine subsystem) | `Subsystem_VerbObject` | `FSYS_fopen`, `ESF_DecodeADPCM` |
| Functions (gameplay) | `PascalCase` | `GameTick`, `DrawMenu` |
| Functions (Win32 wrappers / engine) | `PascalCase` | `WinMain`, `RenderSceneNode` |
| Local helpers (file-static) | `lowerCase` or `verb_object` | `match_pattern`, `walk_list` |
| Globals | `g_camelCase` | `g_gameMode`, `g_player1NodeIdx` |
| Constants / macros | `SCREAMING_SNAKE` | `ESF_MAGIC`, `NODE_POOL_COUNT` |
| Types (struct) | `lower_snake_t` style with `_t` optional | `geo_block`, `fsys_entry` |

The engine prefixes match the original Eurocom debug strings we've
recovered (`FSYS_`, `ESF_`, `Gfx_`, `ECM_`, etc.). Don't invent new
prefixes — use what the binary's strings already attest to.

## Function-address comments

Every function must carry the original VA in a comment:

```c
/**
 * Reads `Path` from the install registry key, then chdir to it.
 * Returns false on any failure (which triggers the install popup).
 *
 * @addr 0x004acc50
 */
bool CheckInstallPath(void) {
    /* ... */
}
```

This makes the diff tool's output trivially readable and keeps the
mapping back to Ghidra explicit.

## Header layout

Each subsystem header has:
1. A docstring at the top (1-paragraph what + format pointer)
2. Include guards `MK4_SUBSYSTEM_FILE_H`
3. `#include "../types.h"` first
4. Public API forward decls
5. Internal helpers under `/* === Internal === */`
6. Globals under `/* === Globals === */`
7. `extern "C"` braces for C++ compat

Each function decl carries its `@addr` as an inline comment.

## Source-file layout

```c
/**
 * <module> — <one-line summary>.
 *
 * <2-4 line longer description>.
 */
#include "mk4.h"

/* File-static state (if any). */
static int s_localState;

/* === Helpers === */
static void helper(void) { /* ... */ }

/* === Public functions === */
/**
 * Body docstring.
 * @addr 0x00xxxxxx
 */
ReturnType FunctionName(args) {
    /* ... */
}
```

## Matching constraints

The matching build target requires:
- **Don't reorder** local variable declarations (MSVC stack layout
  is sensitive)
- **Don't introduce new locals** if the original asm doesn't use them
- **Match the exact integer types**: `int` vs `long` vs `unsigned`
  matters for cl.exe's instruction selection
- **Inline assembly** is allowed for things the compiler can't
  generate. Use `__asm` blocks; keep them minimal.
- **Avoid C99/C++ features** — MSVC 5.0 is C89 only. No `//` line
  comments, no mixed declarations and code, no VLAs.
- **Compiler flags** are fixed: `/MT /O2 /W3 /Gz` (stdcall default).
  Don't change them per-file unless the original asm requires it.

## Globals at fixed VAs

The original binary has globals at specific virtual addresses. To
match the layout, declare them in `src/data/bss_<addr>.c` files
and pin them via the linker script (`config/linker.ld`).

Within source code, ALWAYS reference them by their renamed symbol
(`g_drawQueue`, etc.), never by their VA.

## When a function isn't decompiled yet

Place the disassembly under `asm/<addr>.s` and add a stub in the
nearest source file:

```c
/* Not yet decompiled — see asm/0045c5c0.s */
extern void FightFrameStep(void);
```

The build links the .s file directly into the binary so the asm runs
unchanged. Match progress is tracked in `tools/decomp/progress.py`.
