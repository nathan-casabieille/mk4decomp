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
#include <SDL2/SDL.h>
#include "platform/pal.h"

#include <stdlib.h>
#include <string.h>
#include "portable/mem_model.h"

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
extern void MK4_NativeVideoClaimTexSlots(void);
extern void AppInit_PreInstall(void);   /* FILESYS: open the archive, read its directory */
extern void AppInit_Misc2(void);        /* heap: clear 3 MB, seed the free head */
extern void AppInit_Misc3(void);        /* zero the 42-dword scratch block */
extern void AppInit_Misc4(void);
extern void MStackPackedInit(void);
extern void Set2FiveCallPauseJmp(void);
extern void AppInit_Misc7(void);
extern void AppInit_Misc8(void);
extern void Crt_srand(unsigned seed);
extern int  GameStateMachine(int cmd);
/* Fixed-VA globals, reached through the seam rather than as C variables - this
 * file is the port's, so it is not run through alias_globals.py. */
#define g_titlePauseGate (*(unsigned int *)MK4_VA(unsigned int, 0x004ffd7cu))
#define g_appInitFlag1   (*(unsigned int *)MK4_VA(unsigned int, 0x007af920u))
#define g_texXorKey      (*(unsigned int *)MK4_VA(unsigned int, 0x007af91cu))

static void MK4_EngineStateInit(void)
{
    /* AppInit runs this FIRST, before the heap: everything the engine loads
     * comes through the FILESYS archive, and a lookup against an unread
     * directory is fatal rather than a miss. */
    AppInit_PreInstall();
    SDL_Log("filesys: %u entries from the archive directory",
            *(unsigned int *)MK4_VA(unsigned int, 0x007af4e4u));
    AppInit_Misc2();
    AppInit_Misc3();
    AppInit_Misc4();
    /* Misc4 CLEARS the texture-slot occupancy table and Misc7 loads the first
     * .geo into it, so this is the only window where the backend can claim the
     * slots it staged. Claiming earlier is wiped; later is too late. */
    MK4_NativeVideoClaimTexSlots();
    MStackPackedInit();
    Set2FiveCallPauseJmp();
    AppInit_Misc7();
    AppInit_Misc8();
    /* AppInit seeds the PRNG from timeGetTime; a fixed seed keeps the native
     * build reproducible, which the frame gates depend on. */
    Crt_srand(1);

    /* The backend staged content into the texture page before any of this ran,
     * and the engine's init clears the slot-occupancy table - so the slots the
     * backend owns are claimed here, once, or the first .geo the engine loads
     * takes slot 0 and overwrites them. */

    /* AppInit's own bootstrap: with the disc check UNsatisfied it hands the
     * state machine command 7, which selects the insert-CD dialog. Transcribed
     * faithfully, and on this arena it does not fire - g_titlePauseGate is 1 at
     * rest, i.e. "disc present", and AppInit_Misc8 (the check) is still a weak
     * stub that leaves it alone. So the state stays 0, the main menu, which
     * GameStateMachine does not itself draw. Whatever stages the first screen
     * lives further up the boot path than AppInit, and that is the next thing
     * to find. */
    /* MK4_NO_DISC=1 clears the gate, which is what AppInit_Misc8 would do on a
     * machine without the disc. It is the only way to reach a drawing state
     * today - the arena has the gate SET, so the bootstrap below is skipped and
     * the state stays 0, which draws nothing - so it is how the menu render
     * path gets exercised until the boot sequence above AppInit is converted. */
    if (getenv("MK4_NO_DISC"))
        g_titlePauseGate = 0;
    if (g_titlePauseGate == 0)
        GameStateMachine(7);
    g_appInitFlag1 = 0;
    g_texXorKey = 0;
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
        /* Arm the framebuffer before the frame body. On Windows BeginFrame
         * gets base and pitch by LOCKING a DirectDraw surface and feeds them
         * to SetViewport; here that path does not run, so g_viewportX/W/H stay
         * zero and FlushDrawQueue rasterises into nothing - the queue fills
         * (57 entries for the insert-CD screen) and every pixel is discarded.
         *
         * The rearm variant, not SetViewport: SetViewport also zeroes
         * g_drawQueueSize, which would throw the frame away. */
        { extern void MK4_NativeVideoRearmFB(void); MK4_NativeVideoRearmFB(); }

        /* MK4_BOOT_MATCH=1: the native command source the port needs - the
         * original moves the FSM off state 0 only from the Win32 menu bar.
         * One FSM command 2 (start game, gated on g_gsmFlag) a few frames in,
         * once the boot chain has drained; the in-game pump, the loading
         * screen and the match loader take it from there. */
        if (frame == 8 && getenv("MK4_BOOT_MATCH")) {
            extern int GameStateMachine(int);
            extern void StoreTwoCall(int, int);
            /* What character select leaves behind, minus the gameplay
             * records: the two character indices, the arena index, and the
             * three loading-screen work flags. Then the same two calls
             * Screen_ArcadeEnding makes: FSM to in-game, and the loading
             * screen's tick entry scheduled as a node callback. */
            /* AudioInitSequence PUBLISHES these into the live slots
             * (g_dlNalt1/2 at 0x537f48/0x5380e0), so stage its sources -
             * writing the live slots directly is overwritten. */
            {   const char *p1 = getenv("MK4_P1"), *p2 = getenv("MK4_P2");
                const char *ar = getenv("MK4_ARENA_IDX");
                *MK4_VA(unsigned int, 0x53a790u) = p1 ? (unsigned)atoi(p1) : 0;
                *MK4_VA(unsigned int, 0x537ea0u) = p2 ? (unsigned)atoi(p2) : 1;
                *MK4_VA(unsigned int, 0x541eccu) = 0;   /* P1 alt id */
                *MK4_VA(unsigned int, 0x541ed0u) = 0;   /* P2 alt id */
                *MK4_VA(unsigned int, 0x537edcu) = 0;   /* dest record 1 */
                *MK4_VA(unsigned int, 0x53a1ccu) = 0;   /* dest record 2 */
                *MK4_VA(unsigned int, 0x53a51cu) = ar ? (unsigned)atoi(ar) : 0;
            }
            *MK4_VA(unsigned int, 0x543810u) = 1;   /* world re-init */
            *MK4_VA(unsigned int, 0x543814u) = 1;   /* audio re-init */
            *MK4_VA(unsigned int, 0x543818u) = 1;   /* hand to the loader */
            *MK4_VA(unsigned int, 0x543930u) = 1;   /* g_gsmFlag gates cmd 2 */
            GameStateMachine(2);
            StoreTwoCall(0x4a42e0, 0x4000);
            /* -1 is the "run every scheduled node" tag the walk gates on;
             * the loading screen sets it to its own VA only while it owns
             * the frame, which would starve the node we just queued. */
            *MK4_VA(unsigned int, 0x543800u) = 0xffffffffu;
            {   /* MK4_BOOT_MODE=vs|tour|prac picks the pump's mode entry
                 * (the 0x4f512c table: 0x18 VS, 0x19 tournament, 0x1a
                 * practice); without it the pump keeps its own selection. */
                const char *m = getenv("MK4_BOOT_MODE");
                if (m) {
                    unsigned int c = !strcmp(m, "tour") ? 0x19u
                                   : !strcmp(m, "prac") ? 0x1au : 0x18u;
                    *MK4_VA(unsigned int, 0xab4360u) = c;
                    SDL_Log("boot-match: mode command %x staged", c);
                }
            }
            /* The loader's state 3 waits on the DirectSound stream-busy
             * bits (0xc / 0xc00 of 0x4d50b4). Nothing sets them natively,
             * so without this the loader waits there forever. */
            if (!getenv("MK4_BOOT_NO_AUDIO_BITS"))
                *MK4_VA(unsigned int, 0x4d50b4u) |= 4u;
            SDL_Log("boot-match: FSM -> 6, loading screen scheduled");
        }
        if (getenv("MK4_BOOT_MATCH") && (frame == 40 || frame == 199))
            SDL_Log("boot f%-3d mode=%x tickW1=%-4x dl1=%x dl2=%x 89c=%x "
                    "loaderState=%x texNode0=%x",
                    frame, *MK4_VA(unsigned int, 0x543800u),
                    *MK4_VA(unsigned int, 0x543550u),
                    *MK4_VA(unsigned int, 0x537f48u),
                    *MK4_VA(unsigned int, 0x5380e0u),
                    (unsigned)*MK4_VA(unsigned char, 0x54389cu),
                    0u, *MK4_VA(unsigned int, 0xab4e78u));
        if (getenv("MK4_BOOT_MATCH") && (frame == 40 || frame == 199)) {
            unsigned int n = *MK4_VA(unsigned int, 0x52ab3cu);
            while (n) {
                SDL_Log("   node %x handler=%08x state=%x timer=%d",
                        n, *MK4_VA(unsigned int, n + 0xd8u),
                        *MK4_VA(unsigned int, n + 0x84u),
                        (int)*MK4_VA(short, n + 0xdcu));
                n = *MK4_VA(unsigned int, n + 0xe4u);
            }
        }
        if (getenv("MK4_TRACE_MSTACK") && (frame % 4) == 0)
            SDL_Log("f%-3d mstackTop=%08x nodeIdx=%08x", frame,
                    *MK4_VA(unsigned int, 0x4d57acu),
                    *MK4_VA(unsigned int, 0x542044u));
        frame++;
        MainLoopStep();      /* BeginFrame / GameLogicStep / DrawScene / Present */
    }
    MK4_NativeVideoPresent();/* arena framebuffer -> the SDL window */
}
