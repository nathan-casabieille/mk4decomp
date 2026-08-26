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
