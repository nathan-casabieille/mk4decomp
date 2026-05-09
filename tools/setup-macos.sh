#!/usr/bin/env bash
#
# One-shot environment bootstrap for the MK4 RE project on macOS (Apple Silicon
# or Intel). Idempotent: safe to re-run. Installs:
#   - Whisky          : Wine GUI for running the original MK4.EXE
#   - mingw-w64       : i686 cross-compiler for matching/portable Win32 builds
#   - Ghidra          : disassembler / decompiler
#
# Run from repo root:   ./tools/setup-macos.sh

set -euo pipefail

bold() { printf "\033[1m%s\033[0m\n" "$*"; }
info() { printf "  • %s\n" "$*"; }
warn() { printf "\033[33m  ! %s\033[0m\n" "$*"; }

bold "==> Checking prerequisites"
if ! command -v brew >/dev/null 2>&1; then
  warn "Homebrew not found. Install it first: https://brew.sh"
  exit 1
fi
info "Homebrew: $(brew --version | head -1)"

bold "==> Installing Wine runtime (Whisky)"
# Whisky bundles its own Wine + CrossOver patches and exposes a CLI binary at
# /opt/homebrew/bin/whisky. Marked deprecated upstream (2026-04-09) but still
# works fine for a 1998 DX5/6 title and is the only well-maintained option on
# Apple Silicon today. Alternatives if Whisky breaks: CrossOver (paid),
# Apple Game Porting Toolkit, or Kegworks (Whisky fork).
if brew list --cask whisky >/dev/null 2>&1; then
  info "Whisky already installed."
else
  brew install --cask whisky
fi

bold "==> Installing MinGW-w64 cross-compiler"
if brew list mingw-w64 >/dev/null 2>&1; then
  info "mingw-w64 already installed: $(i686-w64-mingw32-gcc --version | head -1)"
else
  brew install mingw-w64
fi

bold "==> Installing Ghidra"
if brew list ghidra >/dev/null 2>&1; then
  info "Ghidra already installed: $(brew info --json=v2 ghidra | grep -o '"version":"[^"]*"' | head -1)"
else
  brew install ghidra
fi

bold "==> Done"
cat <<EOF

Next steps:
  1. Launch Whisky.app, create a new bottle (Win32 / Windows 7 is fine).
  2. Drag-and-drop game/MK4.EXE onto the bottle to verify it runs.
  3. Open Ghidra, create a new project under analysis/ghidra/, and import
     game/MK4.EXE for analysis.

Cross-compile sanity check (build a 32-bit Win32 hello.exe):
  echo '#include <windows.h>
  int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPSTR c, int s) {
    MessageBoxA(0, "hello", "test", 0); return 0;
  }' > /tmp/hello.c
  i686-w64-mingw32-gcc /tmp/hello.c -o /tmp/hello.exe -mwindows
  # Run via Whisky bottle to confirm the toolchain end-to-end.

EOF
