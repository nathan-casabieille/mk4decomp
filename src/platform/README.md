# Platform backends

The engine talks to the OS through a thin platform layer. Exactly ONE
backend is linked per build, selected by `TARGET` (see the Makefile):

| `TARGET` | Directory | Toolchain | Status |
|---|---|---|---|
| `win32` (default) | `src/platform/win32/` | MSVC 5.0 (matching) / mingw | the original engine's Win32/Glide/DSound layer - **frozen** for matching |
| `sdl`  | `src/platform/sdl/` | clang / mingw | native port (SDL2 + OpenGL + SDL_audio) - stub |
| `web`  | `src/platform/web/` | emscripten | WASM port (WebGL + WebAudio + virtual FS) - stub |

WASM is **one backend among these**, never privileged. A native-SDL port
builds `TARGET=sdl` and never compiles `web/`. The build axes are
orthogonal (see CONVENTIONS.md): `NON_MATCHING` (build mode), `MK4_ARENA`
(memory model), `TARGET_<X>` (this backend selection).

## The contract a backend must satisfy

Derived from the 91 Win32 IAT slots (`g_iat_*`) + the Glide / DirectDraw /
Direct3D / DirectSound surface the engine actually uses. A backend
provides equivalents for these categories:

- **Process / thread**: ExitProcess, CreateThread, GetCurrentThread,
  Get/SetThreadPriority, GetPriorityClass, InterlockedInc/Decrement.
- **Memory**: HeapCreate/Alloc/Free/Destroy (CRT heap), VirtualAlloc-style
  reservation backing `g_mk4Arena`.
- **Sync**: InitializeCriticalSection / Enter / Leave / Delete.
- **Video / window**: CreateWindow, GetDC, CreateDIBSection, GdiFlush,
  InvalidateRect, GetDeviceCaps, GetWindowRect/Placement + the Glide /
  DirectDraw / Direct3D rasterizer -> WebGL/OpenGL for sdl/web.
- **Input**: GetAsyncKeyState, GetCursorPos, MapVirtualKeyA.
- **Audio**: auxSetVolume, mciSendCommandA + DirectSound -> SDL_audio /
  WebAudio.
- **File**: GetFileAttributesA, CreateFileA/ReadFile/CloseHandle,
  GetFileType -> stdio / Emscripten virtual FS.
- **Time**: timeGetTime / QueryPerformanceCounter -> SDL_GetTicks /
  emscripten timing.
- **Locale / CRT support**: GetACP, GetOEMCP, GetCPInfo, LCMapStringA/W,
  GetStringTypeA/W, MultiByteToWideChar (mostly satisfied by the host CRT
  for sdl/web).

See tools/decomp/AGENT_PORTABLE_MIGRATION.md (Phase 2) for the PAL design
plan. The interface header (`include/platform/pal.h`) is introduced once
the engine call sites that use it are converted to portable C (Phase 3),
to avoid a speculative interface ahead of its first caller.
