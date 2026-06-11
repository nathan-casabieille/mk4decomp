# The highest-ROI path to a native, no-Wine, *displaying* MK4

## Why not the pure-C native port
Reimplementing every function in C until it renders is BLOCKED: the SW rasterizers
(`TexturedTriRasterize*`, `ScanlineTexBlit*`) and the FSM dispatch are naked
functions that pass implicit REGISTER args to their callees (the engine's internal
fastcall-ish convention). A C twin can't reproduce register-passing, so these are
non-coaxable (see feedback_tail_jmp_register_args_non_coaxable). The render path is
exactly this code. So "convert everything" can never display.

## The chosen path: embed an x86 CPU emulator + a minimal MK4-specific PAL
Run the ORIGINAL `.text` under an embedded x86 emulator (unicorn - already used by
verify_coexec), with the image mapped at its real VAs, and intercept only the
~140 Win32/DDraw/DSound/winmm IAT imports MK4 actually calls, routing them to SDL +
host shims. The real SW renderer runs (byte-perfect) and writes its framebuffer
into a DDraw surface our shim backs with a real buffer; on Flip we blit to SDL.
- Sidesteps the conversion wall entirely (no rasterizer/FSM conversion needed).
- Portable + no Wine; unicorn runs on macOS/ARM, Linux, and WASM (emscripten) -
  Wine can't do WASM.
- PAL surface is BOUNDED (140 imports, a fraction needed for a SW-rendered frame),
  not all of Win32.
- The project already has the pieces: unicorn, the arena/image, the SDL backend,
  config/iat_map.yaml.

## Feasibility: PROVEN (tools/decomp/boot_emu.py)
A boot tracer loads game/MK4.EXE (4 sections, entry 0x4c6cb0, base 0x400000) into
unicorn at real VAs, sets up stack + TEB/fs via a GDT, hooks all 140 IAT slots to
sentinels, and runs from the entry point. With a bump heap + correct __stdcall arg
counts + sensible stubs (GetVersion/HeapCreate/VirtualAlloc/Tls*/GetStartupInfo/
locale), the real CRT startup runs **35 IAT calls (30 distinct) deep, no stack
corruption, no Wine**, into locale init - on its way to WinMain. (Currently faults
at eip=0x1: a stub returns a value later called; next stub refinement.)

## Roadmap (bounded, iterative, unblocked)
1. Finish CRT init: sensible returns for LoadLibraryA/GetProcAddress/GetStdHandle/
   GetCommandLine/env (each fault reveals the next; arg table already in place).
2. WinMain + window: RegisterClassA/CreateWindowExA/GetMessage/PeekMessage/
   DefWindowProc -> an SDL-backed message pump.
3. Renderer: force SW mode; DirectDrawCreate -> a shim object; CreateSurface/Lock
   -> a real linear buffer; Flip/Blt -> MK4_PalBlit (SDL). The SW rasterizers
   (running as x86) write pixels into that buffer.
4. Input: GetAsyncKeyState/GetCursorPos -> SDL key/mouse state.
5. Timer: timeGetTime/QueryPerformanceCounter -> host clock; Sleep -> SDL_Delay.
6. File: CreateFileA/ReadFile/CreateFileMapping -> read game/FILESYS.DAT + assets.
7. DSound: stub first (silent), real audio later.
First visible milestone: step 3 + enough of 1/2/4/5/6 to reach the first
DrawScene/Flip -> a real rendered frame in an SDL window, no Wine.

## Note
This makes the matching decomp's byte-perfect image *runnable natively/portably*.
The matching build + Wine path already displays the game today; this path removes
the Wine dependency and opens WASM, by emulating the CPU and shimming only MK4's
real API surface.
