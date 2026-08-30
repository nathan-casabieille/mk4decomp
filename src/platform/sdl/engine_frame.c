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

/* VA of the slot MK4_ARENA_STAGE allocated, for MK4_ARENA_NODE to aim at. */
static unsigned int g_mk4ArenaSlotVA;
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
extern int Input_GetAsyncKey(int);
extern void ResetConfigToDefaults(void);
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
    /* In the original this runs inside ValidateInstall, which is the Win32
     * registry / install-path check the port replaces rather than converts.
     * Only its config half matters here: without it the key map at 0x543ab8
     * stays zero and Input_PollPlayerKeyboard asks for key 0 all frame, so
     * no input ever reaches the game. */
    ResetConfigToDefaults();
    MStackPackedInit();
    Set2FiveCallPauseJmp();
    if (getenv("MK4_TRACE_SCENE"))
        SDL_Log("init: after Set2FiveCallPauseJmp pause=%x freeChainHdr=%x/%x",
                *MK4_VA(unsigned int, 0x541e6cu),
                *MK4_VA(unsigned int, 0x541e74u),
                *MK4_VA(unsigned int, 0x535e0cu));
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
    { extern void MK4_NativeInstallFaultHandler(void);
      MK4_NativeInstallFaultHandler(); }
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
            /* MK4_BOOT_FSM=1 also sends FSM command 2 (state 0 -> 6, the
             * in-game pump). Off by default: state 6 sets g_gsmActiveFlag,
             * and that is exactly what makes TestQueueGateState refuse the
             * Enter key - the loading screen's only working skip, since
             * nothing in the game writes the pad aggregates the other two
             * pollers read. */
            if (getenv("MK4_BOOT_FSM"))
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
        if (getenv("MK4_TRACE_MSTACK") && (frame % 4) == 0)
            SDL_Log("f%-3d mstackTop=%08x nodeIdx=%08x", frame,
                    *MK4_VA(unsigned int, 0x4d57acu),
                    *MK4_VA(unsigned int, 0x542044u));
        /* The two "someone is pressing something" bytes are filled by the
         * original's DirectInput layer, not by MK4's own code - so the
         * backend publishes them, once per frame, before the logic runs. */
        { extern void MK4_NativeInputPublish(void); MK4_NativeInputPublish(); }
        { extern void MK4_NativeFakeKeyTick(void); MK4_NativeFakeKeyTick(); }
        if (getenv("MK4_TRACE_SCENE") && (frame % 25) == 0)
            SDL_Log("f%-3d queue=%u mode=%x tickInit=%x head738=%x head1e0=%x "
                    "head1e50=%x",
                    frame, *MK4_VA(unsigned int, 0x00f85b40u),
                    *MK4_VA(unsigned int, 0x00543800u),
                    *MK4_VA(unsigned int, 0x00ab4e70u),
                    *MK4_VA(unsigned int, 0x0053a738u),
                    *MK4_VA(unsigned int, 0x0053a1e0u),
                    *MK4_VA(unsigned int, 0x00541e50u));
        if (getenv("MK4_TRACE_CAM") && (frame % 25) == 0) {
            unsigned int p1 = *MK4_VA(unsigned int, 0x538158u);
            unsigned int p2 = *MK4_VA(unsigned int, 0x53815cu);
            unsigned int cam = *MK4_VA(unsigned int, 0x52ab10u);
            SDL_Log("      p1=[%d %d %d] p2=[%d %d %d] cam=[%d %d %d] camrot=%d",
                    p1 ? *(int *)MK4_PTR(p1*4+0x54) : 0,
                    p1 ? *(int *)MK4_PTR(p1*4+0x58) : 0,
                    p1 ? *(int *)MK4_PTR(p1*4+0x5c) : 0,
                    p2 ? *(int *)MK4_PTR(p2*4+0x54) : 0,
                    p2 ? *(int *)MK4_PTR(p2*4+0x58) : 0,
                    p2 ? *(int *)MK4_PTR(p2*4+0x5c) : 0,
                    cam ? *(int *)MK4_PTR(cam*4+0x54) : 0,
                    cam ? *(int *)MK4_PTR(cam*4+0x58) : 0,
                    cam ? *(int *)MK4_PTR(cam*4+0x5c) : 0,
                    cam ? *(int *)MK4_PTR(cam*4+0x64) : 0);
        }
        if (getenv("MK4_TRACE_CAM") && (frame % 25) == 0)
            SDL_Log("      camang=[%d %d %d] wt=[%x %x %x %x %x]",
                    *MK4_VA(unsigned int, 0x52ab10u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x52ab10u)*4+0x60) : 0,
                    *MK4_VA(unsigned int, 0x52ab10u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x52ab10u)*4+0x64) : 0,
                    *MK4_VA(unsigned int, 0x52ab10u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x52ab10u)*4+0x68) : 0,
                    *MK4_VA(unsigned int, 0xab4878u),
                    *MK4_VA(unsigned int, 0xab487cu),
                    *MK4_VA(unsigned int, 0xab4880u),
                    *MK4_VA(unsigned int, 0xab4884u));
        if (getenv("MK4_TRACE_CAM") && (frame % 25) == 0)
            SDL_Log("      camrec=%x pos=[%d %d %d] eye=[%d %d %d]",
                    *MK4_VA(unsigned int, 0x52ab10u),
                    *MK4_VA(unsigned int, 0x52ab10u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x52ab10u) * 4 + 0x54) : -1,
                    *MK4_VA(unsigned int, 0x52ab10u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x52ab10u) * 4 + 0x58) : -1,
                    *MK4_VA(unsigned int, 0x52ab10u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x52ab10u) * 4 + 0x5c) : -1,
                    *MK4_VA(int, 0xab4d18u), *MK4_VA(int, 0xab4d1cu),
                    *MK4_VA(int, 0xab4d20u));
        if (getenv("MK4_TRACE_CAM") && (frame % 25) == 0)
            SDL_Log("      trans=[%d %d %d] camNodePos=[%d %d]",
                    *MK4_VA(int, 0x7af9a4u), *MK4_VA(int, 0x7af9a8u),
                    *MK4_VA(int, 0x7af9acu),
                    *MK4_VA(unsigned int, 0x542060u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x542060u) * 4 + 0x54) : -1,
                    *MK4_VA(unsigned int, 0x542060u) ?
                      *(int *)MK4_PTR(*MK4_VA(unsigned int, 0x542060u) * 4 + 0x5c) : -1);
        if (getenv("MK4_TRACE_CAM") && (frame % 25) == 0)
            SDL_Log("      cam m=[%x %x %x %x %x] axis=[%x %x %x %x] dist=%x",
                    *MK4_VA(unsigned int, 0x7af990u),
                    *MK4_VA(unsigned int, 0x7af994u),
                    *MK4_VA(unsigned int, 0x7af998u),
                    *MK4_VA(unsigned int, 0x7af99cu),
                    *MK4_VA(unsigned int, 0x7af9a0u),
                    *MK4_VA(unsigned int, 0x535e70u),
                    *MK4_VA(unsigned int, 0x535e74u),
                    *MK4_VA(unsigned int, 0x535e78u),
                    *MK4_VA(unsigned int, 0x535e7cu),
                    *MK4_VA(unsigned int, 0x542084u));
        if (getenv("MK4_TRACE_SCENE") && (frame % 25) == 0)
            SDL_Log("      root8070=%x/%x  1e0head=%x  siblingTail=%x",
                    *MK4_VA(unsigned int, 0x00538070u),
                    *MK4_VA(unsigned int, 0x00538074u),
                    *MK4_VA(unsigned int, 0x0053a1e4u),
                    *MK4_VA(unsigned int, 0x0053e440u));
        if (getenv("MK4_TRACE_SCENE") && (frame % 25) == 0)
            SDL_Log("      freeChain=%x freeVar=%x  chainHead=%x size=%x",
                    *MK4_VA(unsigned int, 0x00541e74u),
                    *MK4_VA(unsigned int, 0x00541e78u),
                    *MK4_VA(unsigned int, 0x00541e74u) ?
                      *MK4_NODE(unsigned int, *MK4_VA(unsigned int, 0x00541e74u)) : 0,
                    *MK4_VA(unsigned int, 0x00541e74u) ?
                      MK4_NODE_AT(unsigned int, *MK4_VA(unsigned int, 0x00541e74u), 0xc) : 0);
        if (getenv("MK4_TRACE_SCENE") && (frame % 25) == 0)
            SDL_Log("      altBlock=%x  hdrWords=%x %x %x %x",
                    *MK4_VA(unsigned int, 0x00541e70u),
                    *MK4_VA(unsigned int, 0x00535e08u),
                    *MK4_VA(unsigned int, 0x00535e0cu),
                    *MK4_VA(unsigned int, 0x00535e10u),
                    *MK4_VA(unsigned int, 0x00535e14u));
        if (getenv("MK4_TRACE_SCENE") && (frame % 25) == 0)
            SDL_Log("      pair1cnt=%x  pair0cnt=%x  base82=%x pair0=%x head=%x  slot2=%x head=%x",
                    *MK4_VA(unsigned int, 0x541e84u) ?
                      MK4_NODE_AT(unsigned int, *MK4_VA(unsigned int, 0x541e84u), 8) : 0xdead,
                    *MK4_VA(unsigned int, 0x541e80u) ?
                      MK4_NODE_AT(unsigned int, *MK4_VA(unsigned int, 0x541e80u), 8) : 0xdead,
                    *MK4_VA(unsigned int, 0x541e7cu),
                    *MK4_VA(unsigned int, 0x541e80u),
                    *MK4_VA(unsigned int, 0x541e80u) ?
                      *MK4_NODE(unsigned int, *MK4_VA(unsigned int, 0x541e80u)) : 0xdead,
                    *MK4_VA(unsigned int, 0x541ea8u),
                    *MK4_VA(unsigned int, 0x541ea8u) ?
                      *MK4_NODE(unsigned int, *MK4_VA(unsigned int, 0x541ea8u)) : 0xdead);
        if (getenv("MK4_TRACE_SCENE") && (frame % 25) == 0)
            SDL_Log("      freeHead=%x freeSize=%x  nodesAlloc=%x",
                    *MK4_VA(unsigned int, 0x00535e0cu),
                    *MK4_VA(unsigned int, 0x00535e0cu) ?
                      MK4_NODE_AT(unsigned int, *MK4_VA(unsigned int, 0x00535e0cu), 0xc) : 0,
                    *MK4_VA(unsigned int, 0x0053a780u));
        if (getenv("MK4_TRACE_SCENE") && (frame % 25) == 0)
            SDL_Log("      p1=%x p2=%x grp=%x dlEnab=%x",
                    *MK4_VA(unsigned int, 0x538158u),
                    *MK4_VA(unsigned int, 0x53815cu),
                    *MK4_VA(unsigned int, 0x54205cu),
                    (unsigned)*MK4_VA(unsigned char, 0x54371cu));
        /* MK4_FORCE_ROOTS=<frame> is a DIAGNOSTIC, not a port feature: it
         * hands TickAllEntities' second walk root a list made of the two
         * player nodes, to answer whether the render path draws once the
         * list is non-empty. Nothing in the game writes these three heads
         * by name, so this is how we tell "the list is the only thing
         * missing" from "the geometry is not in the graph either". */
        if (getenv("MK4_BOOT_MATCH")) {
            const char *at = getenv("MK4_FORCE_ROOTS");
            if (at && frame == atoi(at)) {
                unsigned int p1 = *MK4_VA(unsigned int, 0x538158u);
                unsigned int root = 0x53a1e0u >> 2;
                MK4_NODE_AT(unsigned int, root, 0) = 1;
                MK4_NODE_AT(unsigned int, root, 4) = p1;
                MK4_NODE_AT(unsigned int, root, 8) = 5;   /* link at +0x1c */
                SDL_Log("force-roots: head=%x at frame %d", p1, frame);
            }
        }
        /* MK4_BOOT_FIGHT=<frame> schedules the match init once the loader
         * has the assets in. In the original this comes from
         * Phase3InstallSelf, which the demo/title state machines drive;
         * scheduling the handler directly is the same shape as the
         * loading screen above and skips those two for now. */
        /* MK4_SKEL_BUILD=<frame>: DIAGNOSTIC ONLY - dispatch the skeleton
         * builder directly over whatever the 0x542058 cursor points at.
         *
         * Measured result: the words there are NOT skeleton templates.
         * 0x542058 is a generic walk scratch (TwinLoopSlotFinder and the
         * fight-script VM both use it), and at fight time it holds node
         * links (template[0] = 0 -> the record lookup aborts with dirty
         * bit 2, correctly). The REAL template list is built by the
         * Phase4 FSM that Phase4DualHelperTrampoline spawns (node type
         * 0x8a, callback 0x412920) from MatchStartFsmCluster - the
         * match-start band the MK4_BOOT_* shortcuts skip. Converting that
         * band is the remaining route to bind offsets; this hook stays as
         * the harness that will prove it the moment the list is real. */
        /* MK4_BOOT_WALKIN=<frame>: schedule the Phase4 build/walk-in FSM
         * through the engine's own scheduler - Phase4DualHelperTrampoline
         * is nothing but StoreTwoCall(0x412920, 0x8a), the exact mechanism
         * MK4_BOOT_FIGHT already uses for MatchInitMonsterChain. The
         * spawned type-0x8a controller gets dispatched by the pump with
         * real walk context; no globals are forged here. */
        if (getenv("MK4_BOOT_WALKIN")) {
            const char *at = getenv("MK4_BOOT_WALKIN");
            if (frame == atoi(at)) {
                extern void Phase4DualHelperTrampoline(void);
                unsigned int save = *MK4_VA(unsigned int, 0x54205cu);
                unsigned int p1 = *MK4_VA(unsigned int, 0x538158u);
                unsigned int p2 = *MK4_VA(unsigned int, 0x53815cu);

                /* the spawned controller CAPTURES the ambient group at
                 * creation, so each fighter needs its own spawn with the
                 * group staged - MatchStartFsm does the same per fighter */
                if (p1) {
                    *MK4_VA(unsigned int, 0x54205cu) = p1;
                    Phase4DualHelperTrampoline();
                }
                if (p2) {
                    *MK4_VA(unsigned int, 0x54205cu) = p2;
                    Phase4DualHelperTrampoline();
                }
                *MK4_VA(unsigned int, 0x54205cu) = save;
                SDL_Log("boot-walkin: Phase4 FSM scheduled for %06x and %06x", p1, p2);
            }
        }
        /* MK4_SKEL_BUILD: RETIRED as a direct bridge, kept as the record of
         * two measured dead ends. (1) The 0x542058 words are not templates
         * (generic walk scratch - the record lookup aborts dirty-2,
         * correctly). (2) Replicating the Phase4 FSM's own call site
         * (template 0x4d6948, node type 0x99 in 0x54207c, cam +0x38..+0x40
         * seeded) still aborts on template[0] = 0 - the record resolution
         * belongs to the FSM states that run BEFORE it (0x4089e0 /
         * 0x408c10) - and writing the position seed onto the LIVE intro
         * sequencer corrupts the running scene and crashes downstream.
         * Conclusion, twice measured: the skeleton build cannot be entered
         * sideways; Phase4's FSM (0x412920/0x412ad0, spawned with node
         * type 0x8a by Phase4DualHelperTrampoline) and MatchStartFsmCluster
         * (0x468eb0) must be converted and dispatched as the FSMs they
         * are, through the engine's own pump. */
        /* MK4_ARENA_STAGE=<n>: load arena n through the engine's own geo
         * loader, using the engine's OWN static slot.
         *
         * The 15 twelve-byte records at 0x503260 are not a table of
         * pointers to slots - they ARE the arena slots, one per stage, in
         * the same [name-record, block, ...] shape a character slot has.
         * prison is 0x5032d8. An earlier version of this hook fabricated a
         * slot and got the indirection wrong; there was never anything to
         * fabricate.
         *
         * Nothing reachable asks for a stage: LoadGeoAssetsStateMachine's
         * case 1 loads the slots at 0x4d52b8 indexed by g_dlNalt1 and
         * g_dlNalt2, and those two are CHARACTER indices - which is why
         * sc_geo and ra_geo arrive and no arena does.
         *
         * MK4_ARENA_NODE=<bone> additionally points that bone's +0x24 at
         * one of the stage's own static MESH DESCRIPTORS. Those live at
         * 0x5058ec + N*0x1c for prison, laid out exactly like a fighter's
         * (+0x04 the slot VA, +0x18 the sub-mesh number), so no descriptor
         * needs fabricating either. It has to be re-applied every frame:
         * the scene walk rewrites +0x24 from the model binding. */
        if (getenv("MK4_ARENA_STAGE")) {
            const char *at = getenv("MK4_ARENA_STAGE_FRAME");
            int when = at ? atoi(at) : 150;
            int stage = atoi(getenv("MK4_ARENA_STAGE"));
            unsigned int slotVA = 0x503260u + (unsigned)stage * 12u;

            if (frame == when) {
                extern void LoadGeoAsset_Default(void);
                *MK4_VA(unsigned int, 0x542044u) = slotVA >> 2;
                SDL_Log("arena-stage: stage %d, engine slot 0x%08x", stage, slotVA);
                LoadGeoAsset_Default();
                SDL_Log("arena-stage: block=%08x",
                        *MK4_VA(unsigned int, slotVA + 4u));
            }
            if (frame > when && getenv("MK4_ARENA_NODE")) {
                unsigned int bone =
                    (unsigned int)strtoul(getenv("MK4_ARENA_NODE"), 0, 16);
                const char *ds = getenv("MK4_ARENA_DESC");
                const char *cs = getenv("MK4_ARENA_COUNT");
                unsigned int descVA = ds ? (unsigned int)strtoul(ds, 0, 16)
                                         : 0x505908u;
                int count = cs ? atoi(cs) : 1;
                static int logged;
                int i;

                /* Scene nodes step 0x13 packed, stage descriptors 0x1c
                 * bytes, so consecutive nodes take consecutive sub-meshes
                 * and more of the arena draws with each one. */
                for (i = 0; i < count; i++)
                    *MK4_VA(unsigned int,
                            (bone + (unsigned)i * 0x13u) * 4u + 0x24u) =
                        (descVA + (unsigned)i * 0x1cu) >> 2;

                if (!logged) {
                    logged = 1;
                    SDL_Log("arena-node: %d nodes from 0x%x -> descs from "
                            "0x%08x (slot %08x) block %08x",
                            count, bone, descVA,
                            *MK4_VA(unsigned int, descVA + 4u),
                            *MK4_VA(unsigned int, slotVA + 4u));
                }
            }
        }
        /* MK4_TRACE_STAGE: the stage descriptors the arena code reads.
         * SpawnLeftRightProps bounds its table index at 0x11, i.e. 18
         * stages, so these two are stage ids and not flags. */
        if (getenv("MK4_TRACE_STAGE") && (frame % 40) == 0) {
            SDL_Log("STAGE f=%d dlNalt1=%u dlNalt2=%u sel543800=%08x "
                    "phase537f94=%u",
                    frame,
                    *MK4_VA(unsigned int, 0x537f48u),
                    *MK4_VA(unsigned int, 0x5380e0u),
                    *MK4_VA(unsigned int, 0x543800u),
                    *MK4_VA(unsigned int, 0x537f94u));
            SDL_Log("STAGE2 f=%d baseSel=%08x groupHead=%08x p1=%08x cam+8=%08x cam+84=%08x",
                    frame,
                    *MK4_VA(unsigned int, 0x542060u),
                    *MK4_VA(unsigned int, 0x54205cu),
                    *MK4_VA(unsigned int, 0x538158u),
                    *MK4_VA(unsigned int, 0x542060u) ?
                        *(unsigned int *)MK4_PTR(*MK4_VA(unsigned int, 0x542060u) * 4u + 8u) : 0,
                    *MK4_VA(unsigned int, 0x542060u) ?
                        *(unsigned int *)MK4_PTR(*MK4_VA(unsigned int, 0x542060u) * 4u + 0x84u) : 0);
        }
        if (getenv("MK4_BOOT_MATCH")) {
            const char *at = getenv("MK4_BOOT_FIGHT");
            if (at && frame == atoi(at)) {
                extern void StoreTwoCall(int, int);
                StoreTwoCall(0x4228b0, 0x11);
                *MK4_VA(unsigned int, 0x543800u) = 0xffffffffu;
                SDL_Log("boot-match: match init scheduled at frame %d", frame);
            }
        }
        /* MK4_BOOT_PRESS=<frame> answers the loading screen's press-start
         * gate, which is an EDGE detector - a held key latches it once and
         * never fires again. */
        if (getenv("MK4_BOOT_MATCH")) {
            const char *at = getenv("MK4_BOOT_PRESS");
            if (at && frame == atoi(at)) {
                extern void MK4_NativeFakeKeyPress(int, int);
                MK4_NativeFakeKeyPress(0x0d, 2);
                SDL_Log("boot-match: Enter pressed at frame %d", frame);
            }
        }
        /* MK4_BOOT_ROUND=<frame>: from that frame on, hold the round-start
         * gate 0x537f94 up (the "FIGHT!" signal the round-intro FSM would
         * raise). The intro FSM band (StateDispatchYield's reaction tables)
         * is still stubbed; without the gate the camera node's phase pump
         * yields every frame and the walk never reaches the fighters. */
        {
            const char *rs = getenv("MK4_BOOT_ROUND");
            if (rs && frame >= atoi(rs))
                *MK4_VA(unsigned int, 0x537f94u) = 1;
        }
        /* MK4_DUMP_ARENA=<frame>:<path> writes the LIVE arena to a file at
         * that frame. probe_writes --arena=<path> then runs ORIGINAL bytes
         * against the exact state the native build had - which is how a
         * "who writes X, given the real mid-game state" question gets
         * answered when synthetic seeds do not reach the writing path. */
        {
            const char *spec = getenv("MK4_DUMP_ARENA");
            if (spec) {
                int at = atoi(spec);
                const char *path = strchr(spec, ':');
                if (path && frame == at) {
                    extern unsigned char *g_mk4Arena;
                    extern unsigned int g_mk4ArenaSize;
                    FILE *f = fopen(path + 1, "wb");
                    if (f) {
                        fwrite(g_mk4Arena, 1, g_mk4ArenaSize, f);
                        fclose(f);
                        SDL_Log("arena dumped at frame %d -> %s", at, path + 1);
                    }
                }
            }
        }
        frame++;
        MainLoopStep();      /* BeginFrame / GameLogicStep / DrawScene / Present */
    }
    MK4_NativeVideoPresent();/* arena framebuffer -> the SDL window */
}

void MK4_NativeDumpArenaNow(const char *path)
{
    extern unsigned char *g_mk4Arena;
    extern unsigned int g_mk4ArenaSize;
    FILE *f = fopen(path, "wb");
    if (f) { fwrite(g_mk4Arena, 1, g_mk4ArenaSize, f); fclose(f);
             SDL_Log("arena dumped (on demand) -> %s", path); }
}


