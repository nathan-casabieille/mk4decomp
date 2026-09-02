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
	@echo "Native port (arm64/x86_64 SDL2, no Wine - the verified render path):"
	@echo "  make native-render      - SW pipeline in a window (hand-seeded 2D scene)"
	@echo "  make native-mesh        - FULL chain: a strip mesh -> projection ->"
	@echo "                            emit -> sort -> rasterize, spinning"
	@echo "  make native-geo         - render a REAL character from FILESYS.DAT"
	@echo "                            to a PPM        (CHAR=sc|sz|lk, default sc)"
	@echo "  make native-geo-win     - the same asset in an interactive window"
	@echo "  make native-full        - the broad engine closure + weak stub frontier"
	@echo "  make native-arena-check - same build, every arena deref range-checked"
	@echo "                            (prints the bad VA + source line, not a crash)"
	@echo "  make native-frame-check - the native app runs the ENGINE'S frame"
	@echo "                            stages and draws (MK4_SCENE=rect)"
	@echo "  make native-char-check  - native-full renders a real character and"
	@echo "                            must match the verified bundle byte-for-byte"
	@echo "  make native-render-check / native-mesh-check"
	@echo "                          - cross-target gate: the arm64 framebuffer"
	@echo "                            must be BYTE-IDENTICAL to the wasm32 one"
	@echo
	@echo "Verification harnesses (co-exec vs the original bytes):"
	@echo "  build/venv/bin/python tools/decomp/verify_{scanline,tri,flush,submit}.py"
	@echo "  build/venv/bin/python tools/decomp/verify_{project,emit,mesh}.py"
	@echo "  make frame-core-check   - SEEDED co-exec for MainLoopStep's frame-core"
	@echo "                            twins (guards are 0 at rest, so an unseeded"
	@echo "                            run passes without executing the body)"
	@echo "  make closure ROOT=NAME  - static call closure + the live-stub blockers"
	@echo "                            still standing between it and running natively"
	@echo "  make signed-audit       - twins whose signed tests were silently made"
	@echo "                            UNSIGNED by the arena alias typing"
	@echo "  make width-audit        - real ACCESS WIDTH of every fixed-VA global,"
	@echo "                            read off the original's own encodings"
	@echo "  make packed-ptr-audit   - packed pointers built from a truncated HOST"
	@echo "                            address instead of a VA (--fix rewrites them)"
	@echo "  make va-deref-audit     - VAs cast straight to host pointers"
	@echo "  make code-ptr-audit     - indirect calls that jump to a raw VA instead"
	@echo "                            of going through the VA -> native trampoline"
	@echo "  build/venv/bin/python tools/decomp/disasm_fn.py NAME   - original bytes"
	@echo "  build/venv/bin/python tools/geo_mesh.py FILE --blocks  - .geo mesh format"
	@echo
	@echo "Setup (run once):"
	@echo "  ./tools/setup-macos.sh"
	@echo "  ./tools/decomp/setup-msvc50.sh"
	@echo "  (then place MSVC 5.0 binaries - see docs/MSVC50.md)"
	@echo "  ./tools/decomp/test-toolchain.sh"

# frame-core-check: the seeded co-exec suite for the d2..d5 band that
# `make closure` identifies as MainLoopStep's real work-list. Seeded because
# every one of those twins is guarded on a counter or flag that is ZERO in the
# at-rest image - unseeded, they "verify" without running their body at all.
frame-core-check:
	@build/venv/bin/python tools/decomp/verify_frame_core.py

# closure: what still stands between a root function and running natively.
# Disassembles the original, walks direct call/jmp edges from ROOT, and lists
# the functions in that closure that only have a weak stub in native-full.
ROOT ?= MainLoopStep
closure:
	@build/venv/bin/python tools/decomp/closure.py $(ROOT)

# signed-audit: every fixed-VA global is typed `unsigned int` - by
# alias_globals.py for the native build and by verify_coexec's gdef for the
# harness - which silently INVERTS a signed test (`g < 0` never fires,
# `0 < g` collapses to `!= 0`). It is invisible: it compiles, and co-exec still
# passes as long as no seed drives the value negative, because both sides are
# then wrong together. Hits are cross-checked against the original's own jcc
# opcodes. `--fix` inserts the (int) casts.
signed-audit:
	@build/venv/bin/python tools/decomp/audit_signed.py

# global-refs-audit: a pure-C body that the matching build SYNTHESIZES rather
# than compiles is never validated by `make matching` - it can name the wrong
# global and nothing notices until the native build links it. DirtyPushCallPop
# was exactly that: it tested g_walkCallback (0x54206c) where 0x004055b0 tests
# g_currentNodeIdx (0x542044). This compares the data VAs a twin names against
# the ones its original bytes reference and reports a SYMMETRIC difference -
# the C names one address, the original touches another, neither the other.
# A review queue, not a verdict: co-exec is what settles a hit.
global-refs-audit:
	@build/venv/bin/python tools/decomp/audit_global_refs.py

# template-twins-audit: linked twins whose bodies are byte-identical to each
# other. A family written from one template and never specialised looks
# correct until the original bytes say otherwise - seven of ten wrappers in
# mstack_calls.c were wrong that way, including the scene-node attach.
template-twins-audit:
	@build/venv/bin/python tools/decomp/audit_template_twins.py

# probe-writes: run a function's ORIGINAL bytes in the emulator and report
# what it writes. A SEARCH tool, not a gate: when a global is only ever
# written through a computed index - no instruction anywhere names its
# address - the static search that finds every other writer comes up empty,
# and running candidates is what is left. That is how the scene-heap
# initializer was found. Usage:
#   build/venv/bin/python tools/decomp/probe_writes.py <fn>... --watch=0xVA,...
#   ... --all   sweeps every function in the map

# unaliased-writes-audit: a LINKED native TU that writes an engine global
# without an arena alias. The assignment lands in the weak native global of
# the same name - a host variable - instead of the arena word every other TU
# reads, so the write is silently private and the value never arrives. The
# geo loader hit exactly this and opened an empty asset name.
unaliased-writes-audit:
	@build/venv/bin/python tools/decomp/audit_unaliased_writes.py

# linked-widths-audit: config/global_widths.yaml records which fixed-VA globals
# the original only ever touches 1 or 2 bytes wide. A LINKED twin that spells
# such a global 32 bits wide stores four bytes at a two-byte address. That is
# only destructive when a neighbour sits inside the window, so this reports
# exactly those - the packed clusters (the cursor quad, the six RGB scales, the
# working 3x3) rather than every lone byte flag.
#
# The co-exec harnesses do NOT catch this: they type globals themselves, so one
# can report VERIFIED while the file the native build compiles is still wrong.
linked-widths-audit:
	@build/venv/bin/python tools/decomp/audit_linked_widths.py

# width-audit: everything downstream types a fixed-VA global `unsigned int`,
# which for a packed byte or halfword field makes each store 32 bits wide and
# wipes its neighbours. The original's encodings settle the real width (and
# signedness, from movsx), so derive it: --write refreshes
# config/global_widths.yaml. Apply the result PER TWIN, never in bulk -
# narrowing a global also changes C integer promotion in expressions written
# for the 32-bit spelling.
width-audit:
	@build/venv/bin/python tools/decomp/audit_widths.py

# packed-ptr-audit: a twin that needs a packed pointer for a global writes it
# the way the original does, `(u32)&g_x >> 2`. Under the arena that casts a
# 64-bit HOST pointer down to 32 bits and the result points nowhere - it is why
# the frame loop segfaulted in FightFrameStep_Inner. MK4_UNPTR(&x) is the VA
# that pointer stands for, and under the identity model it is exactly the same
# expression, so matching and every existing co-exec verification are untouched.
packed-ptr-audit:
	@build/venv/bin/python tools/decomp/audit_packed_ptr.py

# va-deref-audit / code-ptr-audit: the two remaining "a VA is not a pointer"
# classes. The first finds VAs cast straight to host pointers (clang's
# -Wint-to-pointer-cast names every one); the second finds indirect calls
# through a 32-bit callback global, which can only hold a VA and so must go via
# MK4_ResolveCode. Both --fix through the seam, which is the identity outside
# MK4_ARENA - so matching and every co-exec verification are untouched.
va-deref-audit:
	@build/venv/bin/python tools/decomp/audit_va_deref.py

code-ptr-audit:
	@build/venv/bin/python tools/decomp/audit_code_ptr.py

.PHONY: frame-core-check closure signed-audit width-audit packed-ptr-audit
.PHONY: va-deref-audit code-ptr-audit

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

# split-globals-audit: catches a global that is reached BOTH through its
# MK4_ARENA alias and through the plain extern (a real host symbol in __DATA).
# Two storages for one game global; nothing warns, and the symptom surfaces
# far from the cause. Reads object-file relocations, not grep - grep over-
# reports this by ~80x because most matches are `#ifndef MK4_ARENA` externs.
split-globals-audit: native-full
	@build/venv/bin/python tools/decomp/audit_split_globals.py

# native-arena-check: the same build with every arena deref range-checked
# (MK4_ARENA_CHECK). A VA below the image base WRAPS - `(unsigned)(0-0x400000)`
# is 0xffc00000 - so a null packed pointer does not fault at zero the way it
# would in the original, it faults about 4 GB above the arena with nothing to
# identify it. This build prints the offending VA and the source line instead.
# Slow by design: a compare and a branch on every engine memory access.
NATIVE_CHECK_EXE := $(BUILD_DIR)/MK4.native.check
native-arena-check:
	@mkdir -p $(BUILD_DIR)
	$(NATIVE_CC) -DNON_MATCHING -DMK4_ARENA -DMK4_ARENA_CHECK -DTARGET_SDL \
		-DMK4_NATIVE_FULL -Iinclude $(SDL_CFLAGS) -O1 -w $(NATIVE_PORTFLAGS) \
		$(NATIVE_FULL_SRCS) src/portable/arena_check.c $(SDL_LIBS) -o $(NATIVE_CHECK_EXE)
	@echo "native-arena-check: linked $(NATIVE_CHECK_EXE)"

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

# The menu's own texture page: a 256x256 16-bit TGA in FILESYS.DAT, which is
# 1-5-5-5 little-endian, i.e. the engine's texture format unchanged.
MENU_TEX := $(BUILD_DIR)/assets/menu.tga
$(MENU_TEX):
	@mkdir -p $(BUILD_DIR)/assets
	build/venv/bin/python tools/fsys_extract.py game/FILESYS.DAT \
		'c:\source\mk4\win\menu.tga' $@

GEO_TEX := $(BUILD_DIR)/assets/$(CHAR)_tex.bin
$(GEO_TEX): $(GEO_ASSET)
	build/venv/bin/python tools/geo_decode.py $(GEO_ASSET) 0 --raw $@

$(NATIVE_GEO_SRC): tools/decomp/gen_wasm_render.py $(ARENA_BLOB) $(GEO_ASSET) $(GEO_TEX)
	@mkdir -p $(NATIVE_RENDER_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py --geo $(GEO_ASSET) > $@
$(NATIVE_GEO_PPM): $(NATIVE_GEO_SRC)
	$(NATIVE_RENDER_CC) $(NATIVE_PORTFLAGS) $< -lm -o $@

# native-geo-win: the same real asset in an interactive SDL2 window (spinning,
# ESC or the close box to quit) instead of a one-shot PPM.
NATIVE_GEO_WIN_SRC := $(NATIVE_RENDER_DIR)/mk4_geo_win_$(CHAR).c
NATIVE_GEO_WIN     := $(NATIVE_RENDER_DIR)/mk4_geo_win_$(CHAR)

$(NATIVE_GEO_WIN_SRC): tools/decomp/gen_wasm_render.py $(ARENA_BLOB) $(GEO_ASSET) $(GEO_TEX)
	@mkdir -p $(NATIVE_RENDER_DIR)
	@build/venv/bin/python tools/decomp/gen_wasm_render.py --native --geo $(GEO_ASSET) > $@
$(NATIVE_GEO_WIN): $(NATIVE_GEO_WIN_SRC)
	$(NATIVE_RENDER_CC) $(NATIVE_PORTFLAGS) $(SDL_CFLAGS) $< $(SDL_LIBS) -lm -o $@

native-geo-win: $(NATIVE_GEO_WIN)
	@echo "native-geo-win: built $<  ->  run: $(NATIVE_GEO_WIN) $(ARENA_BLOB)"

native-geo: $(NATIVE_GEO_PPM) $(GEO_ASSET) $(GEO_TEX)
	@build/venv/bin/python tools/geo_mesh.py $(GEO_ASSET)
	@$(NATIVE_GEO_PPM) $(ARENA_BLOB) $(NATIVE_RENDER_DIR)/$(CHAR)_geo.ppm
	@command -v sips >/dev/null && sips -s format png $(NATIVE_RENDER_DIR)/$(CHAR)_geo.ppm \
		--out $(NATIVE_RENDER_DIR)/$(CHAR)_geo.png >/dev/null || true
	@echo "native-geo: rendered $(NATIVE_RENDER_DIR)/$(CHAR)_geo.ppm from MK4's own model data"

# native-frame-check: the native app must run the ENGINE'S OWN frame stages
# and produce pixels. MK4_SCENE=rect feeds the draw queue through the engine's
# real enqueue (Helper_DrawCursor) because the game logic that would fill it -
# RenderSceneNode + GameStateMachine - is not converted yet; everything after
# that point is engine code:
#   BeginFrame -> Renderer5_BeginFrame_SW_FS_Hi (the port's video hook)
#              -> SetViewport -> DrawScene -> FlushDrawQueue -> rasterisers
#              -> arena framebuffer -> SDL
native-frame-check: native-full $(ARENA_BLOB) $(MENU_TEX)
	@MK4_SCENE=rect MK4_MAX_FRAMES=3 MK4_DUMP_PPM=$(BUILD_DIR)/native/frame.ppm \
		$(NATIVE_FULL_EXE) $(ARENA_BLOB) 2>&1 | grep -E "native video|non-zero" || true
	@build/venv/bin/python -c "import sys; d=open('$(BUILD_DIR)/native/frame.ppm','rb').read(); \
	 i=d.index(b'255\n')+4; px=d[i:]; nz=sum(1 for k in range(0,len(px),3) if px[k:k+3]!=b'\0\0\0'); \
	 print('native-frame-check: %d non-zero pixels' % nz); sys.exit(0 if nz > 1000 else 1)"

# native-char-check: the strongest gate on the native engine build. It renders
# a real character through native-full's ENGINE path and requires the frame to
# be BYTE-IDENTICAL to the standalone bundle that was co-exec verified. Same
# geometry, same emitter, same rasterisers, same arena - so any drift in the
# alias model (a wrong width, a lost adjacency) shows up immediately.
native-char-check: native-full $(GEO_ASSET) $(GEO_TEX) native-geo
	@MK4_SCENE=$(GEO_ASSET) MK4_MAX_FRAMES=1 \
		MK4_DUMP_PPM=$(BUILD_DIR)/native/char_native.ppm \
		$(NATIVE_FULL_EXE) $(ARENA_BLOB) 2>&1 | grep -E "scene:|non-zero" || true
	@cmp $(BUILD_DIR)/native/char_native.ppm $(NATIVE_RENDER_DIR)/$(CHAR)_geo.ppm \
		&& echo "native-char-check: OK - native-full's frame is BYTE-IDENTICAL to the verified bundle" \
		|| (echo "native-char-check: MISMATCH"; exit 1)

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
