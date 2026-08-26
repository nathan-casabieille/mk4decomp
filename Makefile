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

# The port-only platform backends (sdl/, web/) are NOT part of the matching
# build - it always compiles the win32 layer. They are built by their own
# targets (`make native` for sdl; emscripten for web) and need SDL2/WebGL
# headers MSVC does not have, so exclude them from the shared source list.
C_SOURCES   := $(shell find src -name '*.c' \
                 -not -path 'src/platform/sdl/*' \
                 -not -path 'src/platform/web/*' 2>/dev/null)
ASM_SOURCES := $(shell find asm -name '*.s' 2>/dev/null)

# Each src/foo/bar.c -> build/obj/foo/bar.obj
C_OBJS   := $(patsubst src/%.c,$(OBJ_DIR)/%.obj,$(C_SOURCES))
ASM_OBJS := $(patsubst asm/%.s,$(OBJ_DIR)/asm/%.obj,$(ASM_SOURCES))

ALL_OBJS := $(C_OBJS) $(ASM_OBJS)

# === Phony targets =======================================================

.PHONY: all matching portable portable-check native native-run wasm wasm-sdl diff progress clean help check-msvc

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
# Three ORTHOGONAL axes (WASM is NOT privileged - it is one backend):
#   -DNON_MATCHING : build mode. Drops byte-identity, swaps __asm bodies
#                    for portable-C twins. Shared by EVERY port target.
#   -DMK4_ARENA    : memory model. Relocates the absolute-VA / packed-ptr
#                    layout into one arena (see include/portable/mem_model.h).
#                    Needed by ANY relocated backend (native SDL included),
#                    not just WASM.
#   -DTARGET_<X>   : platform backend selector - which PAL impl + main loop
#                    you LINK. Backend-specific code lives ONLY in
#                    src/platform/<x>/ (e.g. win32/, sdl/, web/). A cloner
#                    wanting an SDL-native port picks TARGET_SDL and never
#                    compiles the web backend; WASM is TARGET_WEB + emcc.
# See the migration brief: tools/decomp/AGENT_PORTABLE_MIGRATION.md
#
# i686-w64-mingw32 is the first compile target: 32-bit (matches the
# packed-ptr / absolute-address memory model) and Windows (matches the
# current Win32 / Glide / DirectSound platform surface).
#
# Status: WIP. `make portable` will fail on functions still in x86
# `__asm` (no NON_MATCHING C body yet) - that is the remaining-work
# signal. Use `make portable-check SRC=...` to validate a single file's
# NON_MATCHING branch as you convert it.
# Backend selection (orthogonal axis): exactly one src/platform/<TARGET>/
# backend is compiled into the portable build; the others are excluded.
# Matching ignores TARGET entirely (it always compiles the real win32
# engine layer). WASM = TARGET=web; native = TARGET=sdl; default win32.
TARGET          ?= win32
PORT_BACKENDS   := win32 sdl web
PORT_DROP       := $(filter-out $(TARGET),$(PORT_BACKENDS))
PORT_SOURCES    := $(C_SOURCES)
$(foreach b,$(PORT_DROP),$(eval PORT_SOURCES := $(filter-out src/platform/$(b)/%,$(PORT_SOURCES))))

CC_PORTABLE     := i686-w64-mingw32-gcc
CFLAGS_PORTABLE := -DNON_MATCHING -DTARGET_PORTABLE -Iinclude -O2 -w
PORT_OBJ_DIR    := $(BUILD_DIR)/obj-portable
PORT_C_OBJS     := $(patsubst src/%.c,$(PORT_OBJ_DIR)/%.o,$(PORT_SOURCES))

portable: $(PORT_C_OBJS)
	@echo "portable (TARGET=$(TARGET)): $(words $(PORT_C_OBJS)) objects compiled."
	@echo "  (link step is TODO until the asm->C conversion + PAL land)"

$(PORT_OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC_PORTABLE) $(CFLAGS_PORTABLE) -c $< -o $@

# Syntax-check a single file's NON_MATCHING branch (no codegen / link):
#   make portable-check SRC=src/engine/mov_and_store_ret_jmp.c
portable-check:
	@$(CC_PORTABLE) $(CFLAGS_PORTABLE) -fsyntax-only $(SRC) \
		&& echo "OK: $(SRC) compiles under NON_MATCHING"

# === Native SDL port (TARGET=sdl) ========================================
#
# Desktop port: SDL2 + the PAL backend in src/platform/sdl/ (the contract in
# include/platform/pal.h). The full engine is not yet link-complete (asm->C
# conversion in progress), so `native` builds the SDL backend into a runnable
# SKELETON: weak engine stubs give a live window (animated test fill) that
# validates the platform layer end to end. Engine objects join this link as
# they become portable + seam-clean (MK4_ARENA). Matching is untouched - this
# is the host toolchain under NON_MATCHING + MK4_ARENA + TARGET_SDL only.
#
# SDL2 location is overridable: make native SDL_PREFIX=/usr/local
NATIVE_CC     ?= cc
SDL_PREFIX    ?= /opt/homebrew
SDL_CFLAGS    ?= -I$(SDL_PREFIX)/include
SDL_LIBS      ?= -L$(SDL_PREFIX)/lib -lSDL2
NATIVE_EXE    := $(BUILD_DIR)/MK4.native
# SDL backend + host Win32 shims + the arena loader (relocated memory model).
# Engine objects join this list as they become portable + seam-clean.
# Converted engine objects in MainLoopStep's closure, added as they link.
# Start: the per-frame loop body itself (MainLoopStep). Its frame-stage blockers
# (BeginFrame/GameLogicStep/DrawScene/PresentFrame/QueryMicroTimer) are weak
# stubs in src/platform/sdl/engine_stubs.c until each real file joins here.
NATIVE_ENGINE_SRCS := src/boot/main_loop.c
NATIVE_SRCS   := $(wildcard src/platform/sdl/*.c) src/portable/arena.c $(NATIVE_ENGINE_SRCS)
# Port-in-progress posture: the converted engine models a relocated pointer as
# an int-sized arena value, so int<->pointer conversions are expected, not
# bugs; and call sites for not-yet-declared host functions resolve at link via
# the shims. Downgrade those to warnings so engine objects can join the link
# incrementally. (The SDL backend itself compiles clean without these.)
NATIVE_PORTFLAGS := -Wno-int-conversion -Wno-incompatible-pointer-types \
                    -Wno-int-to-pointer-cast -Wno-implicit-function-declaration

native: $(NATIVE_EXE)
$(NATIVE_EXE): $(NATIVE_SRCS) include/platform/pal.h include/portable/arena.h
	@mkdir -p $(BUILD_DIR)
	$(NATIVE_CC) -DNON_MATCHING -DMK4_ARENA -DTARGET_SDL -Iinclude $(SDL_CFLAGS) \
		-O2 -Wall $(NATIVE_PORTFLAGS) $(NATIVE_SRCS) $(SDL_LIBS) -o $@
	@echo "native (TARGET=sdl): built $@  [skeleton: SDL backend + arena + host shims + weak engine stubs]"

native-run: native
	@$(NATIVE_EXE)

# native-full: the broad closure - every natively-compilable engine file in
# MainLoopStep + GameLogicStep + DrawScene's transitive closure (grown by
# tools/decomp/grow_native.py), linked against engine_autostubs.c (the weak
# stub frontier for the not-yet-portable naked/hardware/Win32 symbols, enabled
# by -DMK4_NATIVE_FULL). Measures native-port surface; may not run cleanly yet
# (hollow stubs), unlike the clean `native` smoke frame. Regenerate the file
# list with: build/venv/bin/python tools/decomp/grow_native.py
NATIVE_FULL_EXE  := $(BUILD_DIR)/MK4.native.full
NATIVE_FULL_SRCS := $(wildcard src/platform/sdl/*.c) src/portable/arena.c \
                    $(shell cat tools/decomp/native_full_srcs.txt)
native-full:
	@mkdir -p $(BUILD_DIR)
	$(NATIVE_CC) -DNON_MATCHING -DMK4_ARENA -DTARGET_SDL -DMK4_NATIVE_FULL -Iinclude $(SDL_CFLAGS) \
		-O2 -w $(NATIVE_PORTFLAGS) $(NATIVE_FULL_SRCS) $(SDL_LIBS) -o $(NATIVE_FULL_EXE)
	@echo "native-full: linked $(NATIVE_FULL_EXE)  [$(words $(NATIVE_FULL_SRCS)) TUs: broad engine closure + weak stub frontier]"

# wasm: the VERIFIED SW render pipeline (FlushDrawQueue + the rasterizers) as a
# self-contained wasm32 bundle. wasm32 is 32-bit (malloc/long/pointers all 32),
# so the twins' uint-pointer model is lossless - exactly the target the verified
# code fits (macOS arm64 cannot, see the pointer-width-fork note). The generator
# collects twin BODIES + arena-relative MK4_VA global aliases (so the vertex
# arrays the triangle twins index are contiguous by construction) + a driver that
# loads build/arena.bin, seeds a draw queue, runs FlushDrawQueue, and dumps a PPM.
WASM_DIR := $(BUILD_DIR)/wasm
wasm: $(WASM_DIR)/frame.ppm
$(WASM_DIR)/mk4_render.c: tools/decomp/gen_wasm_render.py $(ARENA_BLOB)
	@mkdir -p $(WASM_DIR)
	@python3 tools/decomp/gen_wasm_render.py > $@
$(WASM_DIR)/mk4_render.js: $(WASM_DIR)/mk4_render.c
	emcc -O2 -sNODERAWFS=1 -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=64MB \
		-Iinclude -DNON_MATCHING -DMK4_ARENA $< -o $@
$(WASM_DIR)/frame.ppm: $(WASM_DIR)/mk4_render.js $(ARENA_BLOB)
	node $(WASM_DIR)/mk4_render.js $(ARENA_BLOB) $@
	@echo "wasm: rendered $@  [verified SW pipeline running as wasm32]"

# wasm-sdl: the same verified pipeline driving an SDL2 canvas in the browser
# (emscripten ships SDL2). The framebuffer is native RGB565, uploaded straight
# into an SDL streaming texture each frame; seed_scene(frame) animates the scene
# so the dispatch runs every tick. arena.bin is packaged into the wasm VFS.
# Open with: emrun build/wasm/index.html   (or any static server)
wasm-sdl: $(WASM_DIR)/index.html
$(WASM_DIR)/mk4_render_sdl.c: tools/decomp/gen_wasm_render.py $(ARENA_BLOB)
	@mkdir -p $(WASM_DIR)
	@python3 tools/decomp/gen_wasm_render.py --sdl > $@
$(WASM_DIR)/index.html: $(WASM_DIR)/mk4_render_sdl.c $(ARENA_BLOB)
	emcc -O2 -sUSE_SDL=2 -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=64MB \
		--preload-file $(ARENA_BLOB)@build/arena.bin \
		-Iinclude -DNON_MATCHING -DMK4_ARENA $< -o $@
	@echo "wasm-sdl: built $@  [open with: emrun $@]"

# native-render: the VERIFIED SW render pipeline as a real arm64/x86_64 SDL2
# app - no Wine, no emulator, no Rosetta. What makes this possible on a 64-bit
# host is the MK4_PTR seam (include/portable/mem_model.h): the twins carry
# ORIGINAL 32-bit VAs in their register-mirror locals and translate at the
# deref, so the arena can live anywhere in a 64-bit address space. (Mapping the
# low 4 GB is impossible on macOS arm64 - the whole region is __PAGEZERO, and
# shrinking it makes the kernel refuse to exec the binary.) MK4_PTR is the
# IDENTITY under a flat 32-bit layout, so the matching build and the 100+
# co-exec verifications are byte-for-byte unaffected.
#   make native-render        -> build/native/mk4_render_native (SDL2 window)
#   make native-render-check  -> headless frame + PPM byte-diff vs the wasm32
#                                build (proves the seam is semantics-preserving)
NATIVE_RENDER_DIR := $(BUILD_DIR)/native
NATIVE_RENDER_EXE := $(NATIVE_RENDER_DIR)/mk4_render_native
NATIVE_RENDER_PPM := $(NATIVE_RENDER_DIR)/mk4_ppm
NATIVE_RENDER_CC  := $(NATIVE_CC) -O2 -Iinclude -DNON_MATCHING -DMK4_ARENA -w

native-render: $(NATIVE_RENDER_EXE)
$(NATIVE_RENDER_DIR)/mk4_render_native.c: tools/decomp/gen_wasm_render.py $(ARENA_BLOB)
	@mkdir -p $(NATIVE_RENDER_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py --native > $@
$(NATIVE_RENDER_EXE): $(NATIVE_RENDER_DIR)/mk4_render_native.c
	$(NATIVE_RENDER_CC) $(SDL_CFLAGS) $< $(SDL_LIBS) -o $@
	@echo "native-render: built $@  [verified SW pipeline, native SDL2 - run: $@ $(ARENA_BLOB)]"

$(NATIVE_RENDER_DIR)/mk4_render_ppm.c: tools/decomp/gen_wasm_render.py $(ARENA_BLOB)
	@mkdir -p $(NATIVE_RENDER_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py > $@
$(NATIVE_RENDER_PPM): $(NATIVE_RENDER_DIR)/mk4_render_ppm.c
	$(NATIVE_RENDER_CC) $< -o $@

# Cross-target equivalence gate: the 64-bit host (translated arena) and wasm32
# (flat VA, MK4_PTR = identity) must render the SAME framebuffer, bit for bit.
native-render-check: $(NATIVE_RENDER_PPM) $(WASM_DIR)/frame.ppm
	@$(NATIVE_RENDER_PPM) $(ARENA_BLOB) $(NATIVE_RENDER_DIR)/frame_native.ppm
	@cmp $(NATIVE_RENDER_DIR)/frame_native.ppm $(WASM_DIR)/frame.ppm \
		&& echo "native-render-check: OK - arm64 framebuffer is BYTE-IDENTICAL to wasm32" \
		|| (echo "native-render-check: MISMATCH - the MK4_PTR seam changed semantics"; exit 1)

# native-mesh: the FULL verified chain as a native SDL2 app - a real triangle
# -strip mesh goes in, pixels come out, and every stage in between is co-exec
# verified against the original bytes:
#
#   mesh -> TristripBatchEmit -> ProjectTwoVertices / ProjectVertex /
#           AdvanceTriStripRing -> backface test -> DrawEntry ->
#           Vec3ColorShiftClamp -> Helper_DrawCursor -> FlushDrawQueue ->
#           (counting sort) -> rasterizers -> framebuffer
#
# Rendered at 640x480 because that IS the engine's screen: the projection adds
# the centre as 0x140/0xf0 and Helper_DrawCursor's envelope rejects x > 0x280,
# y > 0x1e0.
#   make native-mesh        -> build/native/mk4_mesh (SDL2 window, spinning mesh)
#   make native-mesh-check  -> headless frame + PPM byte-diff vs wasm32
NATIVE_MESH_EXE := $(NATIVE_RENDER_DIR)/mk4_mesh
NATIVE_MESH_PPM := $(NATIVE_RENDER_DIR)/mk4_mesh_ppm

native-mesh: $(NATIVE_MESH_EXE)
$(NATIVE_RENDER_DIR)/mk4_mesh.c: tools/decomp/gen_wasm_render.py $(ARENA_BLOB)
	@mkdir -p $(NATIVE_RENDER_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py --native --emit > $@
$(NATIVE_MESH_EXE): $(NATIVE_RENDER_DIR)/mk4_mesh.c
	$(NATIVE_RENDER_CC) $(NATIVE_PORTFLAGS) $(SDL_CFLAGS) $< $(SDL_LIBS) -lm -o $@
	@echo "native-mesh: built $@  [full verified chain - run: $@ $(ARENA_BLOB)]"

$(NATIVE_RENDER_DIR)/mk4_mesh_ppm.c: tools/decomp/gen_wasm_render.py $(ARENA_BLOB)
	@mkdir -p $(NATIVE_RENDER_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py --emit > $@
$(NATIVE_MESH_PPM): $(NATIVE_RENDER_DIR)/mk4_mesh_ppm.c
	$(NATIVE_RENDER_CC) $(NATIVE_PORTFLAGS) $< -lm -o $@

$(WASM_DIR)/mk4_mesh.c: tools/decomp/gen_wasm_render.py $(ARENA_BLOB)
	@mkdir -p $(WASM_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py --emit > $@
$(WASM_DIR)/mesh0.ppm: $(WASM_DIR)/mk4_mesh.c $(ARENA_BLOB)
	emcc -O2 -sNODERAWFS=1 -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=64MB \
		-Iinclude -DNON_MATCHING -DMK4_ARENA $(NATIVE_PORTFLAGS) $< -o $(WASM_DIR)/mk4_mesh.js
	node $(WASM_DIR)/mk4_mesh.js $(ARENA_BLOB) $@

native-mesh-check: $(NATIVE_MESH_PPM) $(WASM_DIR)/mesh0.ppm
	@$(NATIVE_MESH_PPM) $(ARENA_BLOB) $(NATIVE_RENDER_DIR)/mesh0.ppm
	@cmp $(NATIVE_RENDER_DIR)/mesh0.ppm $(WASM_DIR)/mesh0.ppm \
		&& echo "native-mesh-check: OK - arm64 mesh frame is BYTE-IDENTICAL to wasm32" \
		|| (echo "native-mesh-check: MISMATCH"; exit 1)

# native-geo: render a REAL character asset. Extracts a .geo out of
# FILESYS.DAT, loads it verbatim into the arena and hands each of its mesh
# blocks to the verified emitter - so the pixels come from Mortal Kombat 4's
# own model data, through the same co-exec-verified chain as native-mesh.
#
# The parts are laid out on a grid rather than assembled: each .geo mesh block
# is a body part in its OWN local space and the per-part placement lives in the
# scene graph (the blocks are skeleton nodes), which is the next layer to
# convert. See tools/geo_mesh.py for the block format.
#   make native-geo          -> build/native/scorpion.ppm (+ .png if sips exists)
#   make native-geo CHAR=sz  -> Sub-Zero instead
CHAR ?= sc
GEO_ASSET := $(BUILD_DIR)/assets/$(CHAR)_geo.geo
# per-CHAR names: the generated C embeds the asset path, so switching
# characters must regenerate rather than reuse a stale binary.
NATIVE_GEO_SRC := $(NATIVE_RENDER_DIR)/mk4_geo_$(CHAR).c
NATIVE_GEO_PPM := $(NATIVE_RENDER_DIR)/mk4_geo_$(CHAR)

$(GEO_ASSET):
	@mkdir -p $(BUILD_DIR)/assets
	build/venv/bin/python tools/fsys_extract.py game/FILESYS.DAT \
		'c:\source\mk4\win\geogfx\$(CHAR)_geo.geo' $@

$(NATIVE_GEO_SRC): tools/decomp/gen_wasm_render.py $(ARENA_BLOB) $(GEO_ASSET)
	@mkdir -p $(NATIVE_RENDER_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py --geo $(GEO_ASSET) > $@
$(NATIVE_GEO_PPM): $(NATIVE_GEO_SRC)
	$(NATIVE_RENDER_CC) $(NATIVE_PORTFLAGS) $< -lm -o $@

native-geo: $(NATIVE_GEO_PPM) $(GEO_ASSET)
	@build/venv/bin/python tools/geo_mesh.py $(GEO_ASSET)
	@$(NATIVE_GEO_PPM) $(ARENA_BLOB) $(NATIVE_RENDER_DIR)/$(CHAR)_geo.ppm
	@command -v sips >/dev/null && sips -s format png $(NATIVE_RENDER_DIR)/$(CHAR)_geo.ppm \
		--out $(NATIVE_RENDER_DIR)/$(CHAR)_geo.png >/dev/null || true
	@echo "native-geo: rendered $(NATIVE_RENDER_DIR)/$(CHAR)_geo.ppm from MK4's own model data"

# === Arena (relocated memory model, Phase 1) =============================
#
# Extract the original mapped image into a flat blob, then exercise the
# MK4_VA / MK4_NODE seam against it with a host-native test (pure C, no
# Win32 / no asm - runs directly, no Wine).
ARENA_BLOB := $(BUILD_DIR)/arena.bin
HOST_CC    := cc

arena-blob: $(ARENA_BLOB)
$(ARENA_BLOB): $(ORIGINAL_EXE) tools/decomp/extract_arena.py
	@python3 tools/decomp/extract_arena.py $(ORIGINAL_EXE) $@

arena-test: $(ARENA_BLOB)
	@$(HOST_CC) -DMK4_ARENA -DNON_MATCHING -Iinclude -O2 -Wall \
		tools/portable/test_arena.c src/portable/arena.c -o $(BUILD_DIR)/test_arena
	@$(BUILD_DIR)/test_arena $(ARENA_BLOB)

# === Diff / progress =====================================================

diff: $(MATCH_EXE)
	@python3 tools/decomp/diff.py $(ORIGINAL_EXE) $(MATCH_EXE)

progress:
	@python3 tools/decomp/progress.py

clean:
	rm -rf $(BUILD_DIR)
