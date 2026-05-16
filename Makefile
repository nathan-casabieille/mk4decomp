# MK4 matching decomp - top-level build entry.
#
# Two targets:
#   make matching   - rebuild MK4.EXE byte-for-byte using MSVC 5.0 (under Wine)
#   make portable   - build a portable binary using MinGW-w64 (or native clang)
#
# Setup is one-time:
#   ./tools/setup-macos.sh                  install Whisky, mingw, ghidra
#   ./tools/decomp/setup-msvc50.sh          create the MSVC 5.0 bottle
#   (manually copy MSVC 5.0 binaries into the bottle - see docs/MSVC50.md)
#   ./tools/decomp/test-toolchain.sh        verify cl/link work

ORIGINAL_EXE := game/MK4.EXE
BUILD_DIR    := build
OBJ_DIR      := $(BUILD_DIR)/obj
MATCH_EXE    := $(BUILD_DIR)/MK4.matching.exe
PORT_EXE     := $(BUILD_DIR)/MK4.portable.exe

# === Matching toolchain ===================================================

# Wrappers that proxy cl.exe / link.exe inside the Whisky bottle.
CL   := tools/decomp/cl.sh
LINK := tools/decomp/link.sh

# MSVC 5.0 flags chosen to match the original binary's signature.
#  /nologo  - quiet banner
#  /MT      - statically linked multi-threaded CRT (matches MK4)
#  /O2      - default release optimization
#  /W3      - moderate warning level
#  /Iinclude - include path
# Calling convention left at default (/Gd = __cdecl). The original
# binary uses cdecl for internal helpers; Win32 API stdcall is handled
# via the WINAPI/__stdcall annotations in the headers.
CFLAGS_MATCHING := /nologo /MT /O2 /W3 /Iinclude

# Linker flags. Subsystem 4.0 = Win95/NT 4.0 (matches MK4).
LDFLAGS_MATCHING := /nologo /SUBSYSTEM:WINDOWS,4.0 /MACHINE:IX86 \
                    /OUT:$(MATCH_EXE)

# Libraries linked by MK4.EXE (see PE imports).
MATCHING_LIBS := KERNEL32.LIB USER32.LIB GDI32.LIB ADVAPI32.LIB \
                 WINMM.LIB DDRAW.LIB DSOUND.LIB

# === Source discovery ====================================================

C_SOURCES   := $(shell find src -name '*.c' 2>/dev/null)
ASM_SOURCES := $(shell find asm -name '*.s' 2>/dev/null)

# Each src/foo/bar.c -> build/obj/foo/bar.obj
C_OBJS   := $(patsubst src/%.c,$(OBJ_DIR)/%.obj,$(C_SOURCES))
ASM_OBJS := $(patsubst asm/%.s,$(OBJ_DIR)/asm/%.obj,$(ASM_SOURCES))

ALL_OBJS := $(C_OBJS) $(ASM_OBJS)

# === Phony targets =======================================================

.PHONY: all matching portable diff progress clean help check-msvc

help:
	@echo "MK4 matching decomp - targets:"
	@echo "  make matching   - rebuild MK4.EXE byte-identical (MSVC 5.0)"
	@echo "  make portable   - build portable binary (MinGW-w64 / clang)"
	@echo "  make diff       - diff the matching build vs game/MK4.EXE"
	@echo "  make progress   - print per-function match progress"
	@echo "  make clean      - remove build/"
	@echo
	@echo "Setup (run once):"
	@echo "  ./tools/setup-macos.sh"
	@echo "  ./tools/decomp/setup-msvc50.sh"
	@echo "  (then place MSVC 5.0 binaries - see docs/MSVC50.md)"
	@echo "  ./tools/decomp/test-toolchain.sh"

all: matching

# === Matching build ======================================================

check-msvc:
	@if [ ! -f config/msvc50.env ]; then \
	    echo "ERROR: run ./tools/decomp/setup-msvc50.sh first."; \
	    exit 1; \
	fi
	@. config/msvc50.env && \
	    if [ ! -f "$$MSVC50_ROOT/Bin/CL.EXE" ]; then \
	        echo "ERROR: place MSVC 5.0 binaries - see docs/MSVC50.md"; \
	        exit 1; \
	    fi

matching: check-msvc $(MATCH_EXE)

$(MATCH_EXE): $(ALL_OBJS) | $(BUILD_DIR)
	@echo "  LINK    $@"
	@$(LINK) $(LDFLAGS_MATCHING) $(MATCHING_LIBS) $(ALL_OBJS)

# Pattern: src/foo/bar.c -> build/obj/foo/bar.obj
$(OBJ_DIR)/%.obj: src/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo "  CL      $<"
	@$(CL) $(CFLAGS_MATCHING) /Zm800 /c /Fo$@ $<

# Pattern: asm/foo.s -> build/obj/asm/foo.obj  (assembler - TODO)
$(OBJ_DIR)/asm/%.obj: asm/%.s | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo "  ML      $<"
	@echo "TODO: assembler wrapper not implemented yet" >&2
	@false

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

# === Portable build (MinGW-w64) - TODO ==================================

portable: $(PORT_EXE)

$(PORT_EXE):
	@echo "TODO: portable build not yet implemented."
	@false

# === Diff / progress =====================================================

diff: $(MATCH_EXE)
	@python3 tools/decomp/diff.py $(ORIGINAL_EXE) $(MATCH_EXE)

progress:
	@python3 tools/decomp/progress.py

clean:
	rm -rf $(BUILD_DIR)
