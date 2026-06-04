# SDL native backend (TARGET=sdl)

Native desktop port: SDL2 window + OpenGL rasterizer + SDL_audio, host
stdio for files. Implements the contract in ../README.md. Build with
`make portable TARGET=sdl` (drops the win32 + web backends).

Status: stub. Populate as Phase 3 converts the engine's platform call
sites to route through the PAL.
