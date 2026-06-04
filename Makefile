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
# /ENTRY:entry uses our hand-coded CRT entry at 0x004c6cb0 (matches orig).
# /NODEFAULTLIB:LIBC.LIB disables LIBC (we use LIBCMT only).
# /BASE:0x00400000 places .text at orig VA.
# /ALIGN:0x1000 page-align sections (orig uses 0x1000).
# /ORDER:@order.txt lists every function in the order it appears in orig .text.
LDFLAGS_MATCHING := /nologo /SUBSYSTEM:WINDOWS,4.0 /MACHINE:IX86 \
                    /ENTRY:entry /NODEFAULTLIB:LIBC.LIB \
                    /BASE:0x00400000 /ALIGN:0x1000 \
                    /OPT:NOREF \
                    /ORDER:@order.txt \
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

.PHONY: all matching portable portable-check diff progress clean help check-msvc

help:
	@echo "MK4 matching decomp - targets:"
	@echo "  make matching       - rebuild MK4.EXE byte-identical (MSVC 5.0)"
	@echo "  make portable       - build portable binary (MinGW-w64, -DNON_MATCHING) [WIP]"
	@echo "  make portable-check SRC=path.c - syntax-check one file under NON_MATCHING"
	@echo "  make diff           - diff the matching build vs game/MK4.EXE"
	@echo "  make progress       - print per-function match progress"
	@echo "  make clean          - remove build/"
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
	@echo "  SYNTH   $@"
	@python3 tools/decomp/synthesize.py

# Refresh extras_map.yaml from current .obj files + orig EXE.
# Run after a batch of naked->C conversions to refresh stale $L* labels.
learn-addrs: $(ALL_OBJS)
	@python3 tools/decomp/learn_addrs.py --labels-only

# Same as learn-addrs but full (slower, picks up newly-referenced globals).
learn-addrs-full: $(ALL_OBJS)
	@python3 tools/decomp/learn_addrs.py

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

# === Portable / NON_MATCHING toolchain ===================================
#
# The portable build drops byte-identity (-DNON_MATCHING) and compiles
# with a non-MSVC toolchain, so the codebase can target other platforms
# (native first, then WASM via emscripten). See the migration brief:
#   tools/decomp/AGENT_PORTABLE_WASM_MIGRATION.md
#
# i686-w64-mingw32 is the first portable target: 32-bit (matches the
# packed-ptr / absolute-address memory model) and Windows (matches the
# current Win32 / Glide / DirectSound platform surface). Native and WASM
# backends come later behind -DTARGET_PORTABLE / -DTARGET_WEB.
#
# Status: WIP. `make portable` will fail on functions still in x86
# `__asm` (no NON_MATCHING C body yet) - that is the remaining-work
# signal. Use `make portable-check SRC=...` to validate a single file's
# NON_MATCHING branch as you convert it.
CC_PORTABLE     := i686-w64-mingw32-gcc
CFLAGS_PORTABLE := -DNON_MATCHING -DTARGET_PORTABLE -Iinclude -O2 -w
PORT_OBJ_DIR    := $(BUILD_DIR)/obj-portable
PORT_C_OBJS     := $(patsubst src/%.c,$(PORT_OBJ_DIR)/%.o,$(C_SOURCES))

portable: $(PORT_C_OBJS)
	@echo "portable: $(words $(PORT_C_OBJS)) objects compiled."
	@echo "  (link step is TODO until the asm->C conversion + PAL land)"

$(PORT_OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC_PORTABLE) $(CFLAGS_PORTABLE) -c $< -o $@

# Syntax-check a single file's NON_MATCHING branch (no codegen / link):
#   make portable-check SRC=src/engine/mov_and_store_ret_jmp.c
portable-check:
	@$(CC_PORTABLE) $(CFLAGS_PORTABLE) -fsyntax-only $(SRC) \
		&& echo "OK: $(SRC) compiles under NON_MATCHING"

# === Diff / progress =====================================================

diff: $(MATCH_EXE)
	@python3 tools/decomp/diff.py $(ORIGINAL_EXE) $(MATCH_EXE)

progress:
	@python3 tools/decomp/progress.py

clean:
	rm -rf $(BUILD_DIR)
