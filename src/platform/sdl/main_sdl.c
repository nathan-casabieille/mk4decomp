/**
 * SDL2 native entry point + main loop (TARGET=sdl).
 *
 * Brings up the PAL, then drives the engine: MK4_GameInit once, MK4_GameFrame
 * each vsync, MK4_GameShutdown on exit. The engine entry points are provided
 * by the portable engine as its call sites convert; until then the weak
 * defaults below let this build and RUN standalone (a window that clears and
 * shows an animated test fill), so the backend can be validated on its own.
 *
 * Compiled only for TARGET=sdl.
 */
#include "platform/pal.h"

#include <SDL2/SDL.h>
#include <stdlib.h>

/* Weak engine hooks: the real (strong) ones come from the converted engine
 * and override these at link time. Standalone, they make a visible smoke
 * loop so `make native && ./MK4.native` proves the SDL backend works. */
__attribute__((weak)) int  MK4_GameInit(int argc, char **argv) {
    (void)argc; (void)argv; return 0;
}
__attribute__((weak)) void MK4_GameShutdown(void) {}

__attribute__((weak)) void MK4_GameFrame(void)
{
    /* Smoke pattern: a scrolling RGB-555 gradient so the window is alive. */
    enum { W = 320, H = 240 };
    static unsigned short fb[W * H];
    static unsigned t;
    int x, y;
    t++;
    for (y = 0; y < H; y++)
        for (x = 0; x < W; x++)
            fb[y * W + x] = (unsigned short)
                (((x + t) & 0x1f) | (((y) & 0x1f) << 5) | (((t >> 1) & 0x1f) << 10));
    MK4_PalBlit555(fb, W, H);
}

int main(int argc, char **argv)
{
    mk4_pal_config cfg;
    cfg.width = 640;
    cfg.height = 480;
    cfg.fullscreen = 0;
    cfg.title = "Mortal Kombat 4 (SDL native port - skeleton)";

    if (MK4_PalInit(&cfg) != 0) {
        SDL_Log("MK4_PalInit failed: %s", SDL_GetError());
        return 1;
    }
    if (MK4_GameInit(argc, argv) != 0) {
        MK4_PalShutdown();
        return 1;
    }

    while (MK4_PalPumpEvents()) {
        MK4_PalFrameBegin();
        MK4_GameFrame();
        MK4_PalFramePresent();
    }

    MK4_GameShutdown();
    MK4_PalShutdown();
    return 0;
}
