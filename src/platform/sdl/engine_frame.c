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

#include <stdlib.h>
#include <string.h>

extern void MainLoopStep(void);
extern void MK4_NativeVideoInit(void);
extern void MK4_NativeVideoPresent(void);

/* The engine's own state initialisers, in AppInit's order.
 *
 * AppInit splits cleanly in two. Its first half is hardware - Timer_Init,
 * Joystick_Init, Gfx_Init, AuxAudio_Init, DSound_Init, TryInitRenderer - and
 * that is precisely the half this backend replaces with SDL, so none of it is
 * called here. Its tail builds the game state the frame body then walks, and
 * without it MainLoopStep dereferences packed pointers of zero.
 *
 * Anything still on the weak stub frontier is a no-op for now, so this runs
 * what exists rather than all of it; `make native-arena-check` reports which
 * VAs are still empty. */
extern void AppInit_Misc2(void);        /* heap: clear 3 MB, seed the free head */
extern void AppInit_Misc3(void);        /* zero the 42-dword scratch block */
extern void AppInit_Misc4(void);
extern void MStackPackedInit(void);
extern void Set2FiveCallPauseJmp(void);
extern void AppInit_Misc7(void);
extern void AppInit_Misc8(void);
extern void Crt_srand(unsigned seed);

static void MK4_EngineStateInit(void)
{
    AppInit_Misc2();
    AppInit_Misc3();
    AppInit_Misc4();
    MStackPackedInit();
    Set2FiveCallPauseJmp();
    AppInit_Misc7();
    AppInit_Misc8();
    /* AppInit seeds the PRNG from timeGetTime; a fixed seed keeps the native
     * build reproducible, which the frame gates depend on. */
    Crt_srand(1);
}

int MK4_GameInit(int argc, char **argv)
{
    (void)argc; (void)argv;
    /* Point the renderer's BeginFrame hook at an arena framebuffer and fill
     * the tables the boot path would have built. See engine_video.c. */
    MK4_NativeVideoInit();
    MK4_EngineStateInit();
    return 0;
}

void MK4_GameFrame(void)
{
    static int frame;
    const char *scene = getenv("MK4_SCENE");

    if (scene && strstr(scene, ".geo")) {
        extern void BeginFrame(int);
        extern void DrawScene(void);
        extern void PresentFrame(void);
        extern int  MK4_NativeSceneGeoLoad(const char *);
        extern void MK4_NativeSceneGeo(int);
        static int loaded;
        if (!loaded) { loaded = 1; MK4_NativeSceneGeoLoad(scene); }
        extern void MK4_NativeVideoArmViewport(void);
        BeginFrame(1);
        MK4_NativeVideoArmViewport();
        MK4_NativeSceneGeo(frame++);
        /* g_viewportX / Y are per-DISPATCH scratch the emit path also consumes,
         * so re-arm them - but NOT through SetViewport, which would also clear
         * the queue we just filled. */
        { extern void MK4_NativeVideoRearmFB(void); MK4_NativeVideoRearmFB(); }
        DrawScene();
        PresentFrame();
    } else if (scene && strcmp(scene, "rect") == 0) {
        /* Same stages MainLoopStep runs, with a scene source standing in for
         * the unconverted game logic between BeginFrame and DrawScene. */
        extern void BeginFrame(int);
        extern void DrawScene(void);
        extern void PresentFrame(void);
        extern void MK4_NativeSceneRects(int);
        extern void MK4_NativeVideoArmViewport(void);
        BeginFrame(1);
        MK4_NativeVideoArmViewport();
        MK4_NativeSceneRects(frame++);
        { extern void MK4_NativeVideoRearmFB(void); MK4_NativeVideoRearmFB(); }
        DrawScene();
        PresentFrame();
    } else {
        MainLoopStep();      /* BeginFrame / GameLogicStep / DrawScene / Present */
    }
    MK4_NativeVideoPresent();/* arena framebuffer -> the SDL window */
}
