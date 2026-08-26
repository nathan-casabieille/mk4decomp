/**
 * Native-port blocker stubs (TARGET=sdl).
 *
 * MainLoopStep's closure still has a handful of unconverted / platform-glue
 * blockers (the Win32 multimedia timer, the renderer begin/present, the game
 * FSM tick). Until each is lit up for real, these WEAK stubs let MainLoopStep
 * link + run natively, so we can confirm the host loop drives the real engine
 * frame body. Each real definition (render.c, tick.c, timer.c, ...) overrides
 * its weak stub here at link time as it starts compiling natively.
 *
 *   - QueryMicroTimer: real host microsecond clock (loop pacing needs it).
 *   - DrawScene:       smoke pattern via the PAL, so the window proves the
 *                      frame ran and reached the draw stage.
 *   - BeginFrame / GameLogicStep / PresentFrame: no-ops for now.
 *
 * The 5 loop-state globals are plain C variables here (loop bookkeeping, not
 * arena data), defined weak so the arena/data definitions win if ever linked.
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/tick.h"
#include "platform/pal.h"

#include <SDL2/SDL.h>

/* --- loop-state globals (weak; plain bookkeeping) --- */
__attribute__((weak)) u8  g_appFlags;
__attribute__((weak)) u32 g_lastFrameTime;
__attribute__((weak)) u32 g_loopCounter;
__attribute__((weak)) u32 g_sleepBudgetMs;
__attribute__((weak)) u32 g_inLoopStep;

/* --- host microsecond clock --- */
__attribute__((weak)) u32 QueryMicroTimer(void)
{
    static Uint64 freq;
    if (!freq) freq = SDL_GetPerformanceFrequency();
    return (u32)((SDL_GetPerformanceCounter() * 1000000ULL) / freq);
}

/* --- frame-stage stubs --- */
__attribute__((weak)) void BeginFrame(int flag)   { (void)flag; }
__attribute__((weak)) void GameLogicStep(void)    { }
__attribute__((weak)) void PresentFrame(void)     { }

/* DrawScene: animated RGB-555 gradient so the window is visibly alive and we
 * know MainLoopStep ran end-to-end. Replaced by the real draw_scene.c path
 * once the renderer route is wired. */
__attribute__((weak)) void DrawScene(void)
{
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
