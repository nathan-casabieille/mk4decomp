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
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "portable/mem_model.h"
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

/* --- CD-audio presence check --- */

/* AppInit_Misc8 is the disc check, and it is a CD-AUDIO one: it walks the
 * first fifteen tracks through the aux-audio device and compares each track's
 * length against a built-in table (0x5c, 0x5c, ..., 0x7a, 0x10, 0x38, ...,
 * 0x5a) with a tolerance of 5. All fifteen matching means the MK4 disc is in
 * the drive, and it sets g_titlePauseGate.
 *
 * There is no aux-audio device to walk here - SDL replaces DirectSound
 * outright, and nothing in this port reads redbook audio - so the probe has no
 * native equivalent to perform. Reporting the disc PRESENT is the only answer
 * that lets the state machine leave the insert-CD dialog; with the gate clear
 * the game sits on that dialog forever, because the retry it offers calls back
 * into this same check.
 *
 * Weak, so a converted app_init_misc8.c takes over if the aux-audio path is
 * ever brought up for real. */
__attribute__((weak)) void AppInit_Misc8(void)
{
    *(unsigned int *)MK4_PTR(0x004ffd7cu) = 1;      /* g_titlePauseGate */
}

/* --- CRT / error-path replacements --- */

/* The original is MSVC's sprintf internals: a fake FILE on the stack handed to
 * _output, with the "did it overflow" branch reading the residual count back
 * out of the frame. None of that survives the port - the host CRT does the
 * same job - so this is a replacement rather than a conversion.
 *
 * Callers pass HOST pointers: the arena VAs they hold (the path buffer, the
 * format literal, a name out of an asset table) go through the seam at the
 * call site, the way every other pointer argument in this port does. */
__attribute__((weak)) int Helper_Sprintf(char *buf, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vsprintf(buf, fmt, ap);
    va_end(ap);
    return n;
}

/* Win32 MessageBox plus a graphics teardown, on the path where the engine has
 * decided it cannot continue. SDL has no equivalent worth reproducing, and the
 * useful behaviour for a headless run is to say what happened and stop rather
 * than to fall through into whatever the caller does next - which for
 * Mem_Malloc is dereferencing the null it just failed to find. */
__attribute__((weak)) void ShowErrorMessage(const char *msg)
{
    SDL_Log("engine error: %s", msg ? msg : "(null)");
    MK4_PalShutdown();
    exit(1);
}
