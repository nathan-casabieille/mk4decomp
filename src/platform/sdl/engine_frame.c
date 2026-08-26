/**
 * Native engine frame wiring (TARGET=sdl).
 *
 * Strong override of main_sdl.c's weak MK4_GameFrame: drive the real engine
 * per-frame loop body (MainLoopStep, src/boot/main_loop.c) instead of the smoke
 * pattern. This is the bridge from the SDL host loop into the converted engine.
 *
 * Built only for the native SDL target. Blockers that MainLoopStep's closure
 * still needs (PAL video routing, host timer, FSM cluster) are provided as
 * stubs in engine_stubs.c until each is lit up for real.
 */
#include "platform/pal.h"

extern void MainLoopStep(void);
extern void MK4_NativeVideoInit(void);
extern void MK4_NativeVideoPresent(void);

int MK4_GameInit(int argc, char **argv)
{
    (void)argc; (void)argv;
    /* Point the renderer's BeginFrame hook at an arena framebuffer and fill
     * the tables the boot path would have built. See engine_video.c. */
    MK4_NativeVideoInit();
    return 0;
}

void MK4_GameFrame(void)
{
    MainLoopStep();          /* BeginFrame / GameLogicStep / DrawScene / Present */
    MK4_NativeVideoPresent();/* arena framebuffer -> the SDL window */
}
