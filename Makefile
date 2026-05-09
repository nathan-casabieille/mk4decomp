# MK4 matching decomp — top-level build entry.
#
# Two targets:
#   make matching   — rebuild MK4.EXE byte-for-byte using MSVC 5.0 (under Wine)
#   make portable   — build a portable binary using MinGW-w64 (or native clang)
#
# The matching target requires `tools/decomp/setup-msvc50.sh` to have
# been run first. The portable target is intended for development on
# macOS / Linux without Wine.

ORIGINAL_EXE := game/MK4.EXE
BUILD_DIR    := build
MATCH_EXE    := $(BUILD_DIR)/MK4.matching.exe
PORT_EXE     := $(BUILD_DIR)/MK4.portable.exe

# Locate MSVC 5.0 in the user's Whisky bottle (override via env var).
MSVC50_BOTTLE ?= $(HOME)/Library/Application Support/com.isaacmarovitz.Whisky/Bottles/MK4DECOMP

# Wine wrapper around MSVC 5.0. Invoked by the matching build's
# per-file compile rules in tools/decomp/build.mk (TODO).
WINE ?= wine64
CL   ?= "$(MSVC50_BOTTLE)/drive_c/MSVC5/Bin/CL.EXE"
LINK ?= "$(MSVC50_BOTTLE)/drive_c/MSVC5/Bin/LINK.EXE"

# MSVC flags that match the original binary's signature.
CFLAGS_MATCHING := /nologo /MT /O2 /W3 /Gz /Iinclude

# Sources are organized by subsystem (see CONVENTIONS.md).
SOURCES := $(shell find src -name '*.c' 2>/dev/null)
ASM_SOURCES := $(shell find asm -name '*.s' 2>/dev/null)

.PHONY: all matching portable diff progress clean help

help:
	@echo "MK4 matching decomp — targets:"
	@echo "  make matching   — rebuild MK4.EXE byte-identical (MSVC 5.0 under Wine)"
	@echo "  make portable   — build portable binary (MinGW-w64 / clang)"
	@echo "  make diff       — diff the matching build against game/MK4.EXE"
	@echo "  make progress   — print per-function match progress"
	@echo "  make clean      — remove build/"
	@echo
	@echo "Setup:"
	@echo "  ./tools/decomp/setup-msvc50.sh    install MSVC 5.0 under Whisky"

all: matching

matching: $(MATCH_EXE)

$(MATCH_EXE):
	@echo "TODO: matching build pipeline not yet implemented."
	@echo "      See tools/decomp/build.mk for the planned rules."
	@false

portable: $(PORT_EXE)

$(PORT_EXE):
	@echo "TODO: portable build not yet implemented."
	@false

diff: $(MATCH_EXE)
	@python3 tools/decomp/diff.py $(ORIGINAL_EXE) $(MATCH_EXE)

progress:
	@python3 tools/decomp/progress.py

clean:
	rm -rf $(BUILD_DIR)
