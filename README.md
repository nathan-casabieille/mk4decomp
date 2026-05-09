# MK4 - Matching Decompilation

A **matching decompilation** of **Mortal Kombat 4** (PC, Midway /
Eurocom, 1998), in the spirit of [zeldaret/oot](https://github.com/zeldaret/oot)
and [n64decomp/sm64](https://github.com/n64decomp/sm64).

Goal: reproduce `MK4.EXE` **byte-for-byte** from reconstructed C source,
compiled with the original toolchain (Microsoft Visual C++ 5.0). Once
matching, the C source is the canonical representation of the game.

A **portable build** target (SDL2 / Metal on macOS) is maintained in
parallel for development convenience.

## Status

```
$ make progress
Functions identified : 104 (~6.1% of estimated total)
matched (byte-perfect)  :     0
drafted (functional)    :     0
stub (asm-only)         :   104
```

See [analysis/notes/architecture.md](analysis/notes/architecture.md)
for the architectural map already produced by static RE - every
subsystem of the engine is documented at a high level.

## Repo layout

| Path | Contents |
|---|---|
| `src/` | Reconstructed C source, organized by subsystem |
| `include/` | Reconstructed headers |
| `asm/` | Disassembly of functions not yet decompiled |
| `data/` | Raw binary data sections (split out of the original) |
| `config/` | Symbol map (`symbols.yaml`), linker script, splits |
| `tools/decomp/` | Diff, progress, build pipeline |
| `tools/ghidra_scripts/` | Jython scripts for Ghidra automation |
| `analysis/` | Notes, Ghidra DB |
| `original/` | Original CD image (`MortalK4.bin`+`.cue`). Source of truth. |
| `game/` | Extracted game files (target = `game/MK4.EXE`). |
| `audio/` | Extracted CD-DA tracks |
| `docs/` | Build / matching / contributing docs |

## Build (matching)

The matching build needs MSVC 5.0 + LINK 5.10. We run it under Wine
on macOS via Whisky.

```sh
./tools/setup-macos.sh                # first-time setup
./tools/decomp/setup-msvc50.sh        # install MSVC 5.0 in a Whisky bottle (TODO)
make matching                         # rebuild byte-identical MK4.EXE
make diff                             # compare each function vs original
```

When a function matches byte-for-byte, mark it `matched` in
`config/symbols.yaml`.

## Build (portable)

For day-to-day development without Wine. Uses MinGW-w64 (cross-compile)
or native clang on macOS. Produces a non-matching binary that runs
natively.

```sh
make portable
```

## Reading order for new contributors

1. [analysis/notes/architecture.md](analysis/notes/architecture.md) -
   what the engine does, subsystem-by-subsystem
2. [CONVENTIONS.md](CONVENTIONS.md) - naming, header layout, matching rules
3. [docs/MATCHING.md](docs/MATCHING.md) - workflow for claiming a function
   and getting it byte-perfect
4. [config/symbols.yaml](config/symbols.yaml) - find a `stub` function to
   work on

## Regenerating `game/` from the CD image

If `game/` is ever lost, rebuild from `original/`:

```sh
cd /tmp && bchunk -w \
  ../original/MortalK4.bin ../original/MortalK4.cue MK4
7z x MK401.iso
# move DATA/MK4.EXE, DATA/FILESYS.DAT, DATA/*.ECM, 3DFX/GRTVGR.EXE → game/
```

## Toolchain

- **Ghidra** - disassembly + interactive decompilation
- **Whisky** - Wine wrapper used to run MSVC 5.0 and the original `MK4.EXE`
- **MinGW-w64** - for the portable build
- **MSVC 5.0** (under Wine) - for the matching build
- **Python 3 + pyyaml** - for tooling

## Credits

Reverse engineering, decomp infrastructure: see git log.

The engine is © 1998 Eurocom Entertainment Software / Midway. This
project distributes ZERO original game assets - the `original/` and
`game/` paths are git-ignored. To run the result, you provide your
own copy of MK4.
