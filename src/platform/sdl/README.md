# SDL native backend (TARGET=sdl)

Native desktop port: SDL2 window + renderer (RGB-555 streaming texture; an
OpenGL/Glide path replaces it as the rasterizer call sites convert) +
SDL_audio for the DirectSound replacement + SDL keyboard/mouse/timer.
Implements the PAL contract in `include/platform/pal.h` (and ../README.md).

## Build / run

```
make native            # host clang + SDL2 -> build/MK4.native
make native-run        # build then run
make native SDL_PREFIX=/usr/local   # if SDL2 lives elsewhere
```

## Status: runnable skeleton

`build/MK4.native` builds and runs **today**: it opens a window and drives
the PAL main loop. Because the engine is not yet link-complete (asm->C
conversion in progress), the engine entry points (`MK4_GameInit` /
`MK4_GameFrame` / `MK4_GameShutdown`) are **weak** stubs here, so standalone
the loop shows an animated RGB-555 test fill - this validates the platform
layer end to end (window, present, events, time) before the engine joins.

Files:
- `pal_sdl.c`  - the SDL2 implementation of `include/platform/pal.h`.
- `main_sdl.c` - `main()` + the PAL-driven frame loop + weak engine stubs.

## How the engine joins

As engine call sites convert to portable C (and route their Win32/Glide/
DSound calls through the PAL), they provide the strong `MK4_Game*` entry
points, which override the weak stubs at link time. Engine objects are added
to the `native` link once they are portable AND seam-clean (`MK4_ARENA`).
The win32 backend stays the matching build's frozen layer; this directory is
never compiled by `make matching`.
