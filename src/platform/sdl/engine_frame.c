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
#include <stdio.h>
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
extern void AppInit_Misc1(void);        /* key labels; menu.tga -> slot 15; the cursor bars */
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
    /* Loads menu.tga into texture slot 15 and then PAINTS the 32 gradient
     * bars DrawMenu's selection cursor samples - rows 0x50..0x5b of that
     * slot, which are black in the art because they are not art. It needs
     * the archive open, hence its place right after PreInstall, which is
     * also where AppInit runs it.
     *
     * Skipped for the smoke scenes: they stage their own content into the
     * same page (a flat fill, or a row-encoded ramp) and this would paint
     * menu.tga over it, which is what `make native-frame-check` measures. */
    if (!getenv("MK4_SCENE") && !getenv("MK4_TEX_SOLID") && !getenv("MK4_TEX_ROWS"))
        AppInit_Misc1();
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
    /* After ResetConfigToDefaults, which owns the config half of this block:
     * the pad table is hardware state, and publishing it first would let the
     * config reset stamp over the device assignment. */
    { extern void MK4_NativeJoystickPublish(void); MK4_NativeJoystickPublish(); }
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

        /* MK4_START=<frame>: the port's replacement for the ORIGINAL's Win32
         * MENU BAR. MK4.EXE is a windowed Win32 game whose game-state
         * machine sits in state 0 until the menu bar sends it command 2;
         * that menu is window chrome, not game content, so a native port
         * has to supply the command itself. This is the whole of it - no
         * character, arena or loader staging, unlike MK4_BOOT_MATCH - so
         * whatever the game does next is its own attract / title / select
         * chain running under its own steam.
         */
        /* MK4_KEYS="frame:vk,frame:vk,...": a scripted key SEQUENCE, in
         * frame order. MK4_FAKE_KEY holds one key forever, which the
         * game's own repeat suppression turns into a single move - fine
         * for one action, useless for walking a menu. This arms a real
         * two-frame press at each listed frame, so a headless run can
         * navigate and select like a player. */
        { static const char *seq; static int parsed;
          if (!parsed) { parsed = 1; seq = getenv("MK4_KEYS"); }
          if (seq) { const char *p = seq;
            while (*p) { int f = 0, vk = 0;
                while (*p >= '0' && *p <= '9') f = f * 10 + (*p++ - '0');
                if (*p == ':') p++;
                while (*p >= '0' && *p <= '9') vk = vk * 10 + (*p++ - '0');
                if (f == frame && vk) {
                    extern void MK4_NativeFakeKeyPress(int, int);
                    MK4_NativeFakeKeyPress(vk, 2);
                    SDL_Log("keys: frame %d press vk %d", f, vk);
                }
                if (*p == ',') p++; else break;
            } } }

        { const char *at = getenv("MK4_START");
          if (at && frame == atoi(at)) {
              extern int GameStateMachine(int);
              /* command 2 is gated on g_gsmFlag, which the Win32 side
               * raises once the app is ready to run a game; nothing in the
               * game code sets it. */
              *MK4_VA(unsigned int, 0x543930u) = 1;
              SDL_Log("start: menu-bar equivalent, FSM command 2 -> state %d",
                      GameStateMachine(2));
          } }

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
            /* ONE flag at a time. The loading tick consumes exactly one of
             * these per invocation and then releases its own node with
             * CallSetPause; the next one needs a freshly scheduled tick,
             * which the phase machine below queues once the previous flag
             * reads back clear. Raising all three at frame 8 only ever
             * worked because a released node was never unlinked AND the
             * -1 screen tag below matches the -1 release marker at +0xd8,
             * so the dead node kept passing the pump's gate. */
            *MK4_VA(unsigned int, 0x543810u) = 1;   /* world re-init */
            *MK4_VA(unsigned int, 0x543930u) = 1;   /* g_gsmFlag gates cmd 2 */
            /* g_gsmActiveFlag. The loading tick only re-enters Screen_Loading
             * - which re-arms 0x543824 and resets the audio sources before
             * each work flag - while this is set, and FSM state 6 is the only
             * thing that sets it. MK4_BOOT_FSM is off by default here, so the
             * harness sets it directly; without it the second scheduled tick
             * runs against a screen that was never re-armed and the loader
             * walks a stale record. */
            *MK4_VA(unsigned int, 0xab4334u) = 1;
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
        /* MK4_BOOT_MATCH: schedule the loading tick again for each of the
         * two remaining work flags, once the previous one has been consumed.
         * out3 (world re-init) hands the world to the root game-flow FSM and
         * dies; out2 (audio re-init) and out1 (hand to the match loader) each
         * need their own invocation. */
        if (getenv("MK4_BOOT_MATCH") && frame > 8) {
            extern void StoreTwoCall(int, int);
            static int lt_phase;
            unsigned int *out3 = MK4_VA(unsigned int, 0x543810u);
            unsigned int *out2 = MK4_VA(unsigned int, 0x543814u);
            unsigned int *out1 = MK4_VA(unsigned int, 0x543818u);
            if (lt_phase == 0 && *out3 == 0) {
                *out2 = 1;
                StoreTwoCall(0x4a42e0, 0x4000);
                *MK4_VA(unsigned int, 0x543800u) = 0xffffffffu;
                lt_phase = 1;
                SDL_Log("boot-match: world re-init done, audio re-init queued "
                        "at frame %d", frame);
            } else if (lt_phase == 1 && *out2 == 0) {
                *out1 = 1;
                StoreTwoCall(0x4a42e0, 0x4000);
                *MK4_VA(unsigned int, 0x543800u) = 0xffffffffu;
                lt_phase = 2;
                SDL_Log("boot-match: audio re-init done, loader hand-off "
                        "queued at frame %d", frame);
            } else if (lt_phase == 2 && *out1 == 0) {
                lt_phase = 3;
                SDL_Log("boot-match: loader hand-off taken at frame %d", frame);
            }
        }

        /* MK4_MAIN_MENU=<frame>: schedule the game's own MODE SELECT menu
         * (ARCADE / TEAM / ENDURANCE / TOURNAMENT / PRACTICE / EXIT GAME) -
         * the controller the attract sequencer would chain. Type 1 gets it
         * pumped next frame; its own states load the menu background .geo
         * pair and build the text objects. */
        if (getenv("MK4_MAIN_MENU")) {
            const char *at = getenv("MK4_MAIN_MENU");
            /* the world root first: the text containers prepend to the
             * AMBIENT group, and without the gsmOut3 world re-init that
             * ambient is garbage and nothing lands in the render chain */
            if (frame == 8) {
                *MK4_VA(unsigned int, 0x543930u) = 1;
                *MK4_VA(unsigned int, 0x543810u) = 1;   /* world re-init */
                *MK4_VA(unsigned int, 0x543814u) = 1;   /* audio publish */
                *MK4_VA(unsigned int, 0x4d50b4u) |= 4u;
            }
            if (frame == atoi(at)) {
                extern void StoreTwoCall(int, int);
                *MK4_VA(unsigned int, 0x541e6cu) = 0;
                StoreTwoCall(0x4a2a80, 1);
                *MK4_VA(unsigned int, 0x543800u) = 0xffffffffu;
                SDL_Log("main-menu: controller scheduled at frame %d "
                        "(spare chain 0x%x)", frame,
                        *MK4_VA(unsigned int, 0x537f24u));
            }
        }
        /* Part 2 of what character select leaves behind: the two fighters
         * DOWNLOADED. The real select runs DownloadPlayerChar per player
         * (PendingMatch_DownloadPlayerChar's demo state does the same
         * pair); MK4_BOOT_MATCH skipped it, and the match sequencer's
         * MatchInitMonsterChain then hunted the record registry for
         * fighters nobody had registered - the unbounded walk that
         * faulted. Gated on the gameMode == -1 rendezvous so the publish
         * in AudioInitSequence (char ids, costume ids, the stage load)
         * has run first; driven per frame because the download streams
         * assets and pauses. */
        if (getenv("MK4_BOOT_MATCH")) {
            static int dl_phase;
            /* Straight after the frame-8 staging, BEFORE anything can
             * reach match init: with MK4_ANIM_PACK the sequencer's entry
             * fires within a few frames, and its record hunts fault on
             * fighters nobody registered. The download reads the staged
             * char ids directly and streams from FILESYS - it does not
             * need the loader or the audio publish to have run. */
            if (dl_phase == 0 && frame == 9)
                dl_phase = 1;
            if (dl_phase == 1) {
                extern void DownloadPlayerChar(void);
                /* frame-top drive, outside the pump: the pause flag holds
                 * whatever the last yield left, so clear it - the pump
                 * rebuilds it from its own dispatches below */
                *MK4_VA(unsigned int, 0x541e6cu) = 0;
                /* the publish AudioInitSequence would do: sources -> live
                 * slots. DownloadPlayerChar reads the LIVE slots (0x537f48
                 * and 0x5380e0) and its player comes from 0x542070. */
                *MK4_VA(unsigned int, 0x537f48u) = *MK4_VA(unsigned int, 0x53a790u);
                *MK4_VA(unsigned int, 0x5380e0u) = *MK4_VA(unsigned int, 0x537ea0u);
                *MK4_VA(unsigned int, 0x53a178u) = *MK4_VA(unsigned int, 0x537edcu);
                *MK4_VA(unsigned int, 0x53a250u) = *MK4_VA(unsigned int, 0x53a1ccu);
                *MK4_VA(unsigned int, 0x541ec4u) = *MK4_VA(unsigned int, 0x541eccu);
                *MK4_VA(unsigned int, 0x541ec8u) = *MK4_VA(unsigned int, 0x541ed0u);
                *MK4_VA(unsigned int, 0x542054u) = 0x535cfcu >> 2;
                *MK4_VA(unsigned char, 0x54371cu) = 1;
                *MK4_VA(unsigned int, 0x542070u) = 0;
                /* the WORK SLOT carries the character id into the download -
                 * DualPathDownloadChar and PlayerCharSelector both set it
                 * before the call, and Helper_DownloadSetup indexes its
                 * table at 0x4f02d0 by (work slot * 8). Left as whatever the
                 * previous frame happened to leave, that index walks out of
                 * the arena and faults at a wild address, which is what made
                 * this harness fail a run in three with no other symptom. */
                *MK4_VA(unsigned int, 0x54206cu) = *MK4_VA(unsigned int, 0x537f48u);
                DownloadPlayerChar();
                if (*MK4_VA(unsigned int, 0x541e6cu) == 0) {
                    *MK4_VA(unsigned int, 0x542070u) = 1;
                    *MK4_VA(unsigned int, 0x54206cu) = *MK4_VA(unsigned int, 0x5380e0u);
                    DownloadPlayerChar();
                    if (*MK4_VA(unsigned int, 0x541e6cu) == 0) {
                        *MK4_VA(unsigned char, 0x54371cu) = 0;
                        dl_phase = 2;
                        SDL_Log("boot-match: both fighters downloaded at frame %d "
                                "(P1 char %u node %x, P2 char %u node %x)", frame,
                                *MK4_VA(unsigned int, 0x537f48u),
                                *MK4_VA(unsigned int, 0x541ed4u),
                                *MK4_VA(unsigned int, 0x5380e0u),
                                *MK4_VA(unsigned int, 0x541ed8u));
                    }
                }
            }
        }
        if (getenv("MK4_TRACE_REG") ) {
        static unsigned last0 = 0xdeadbeefu;
        unsigned v0 = *MK4_VA(unsigned int, 0x543200u);
        if (v0 != last0) {
            SDL_Log("REG 0x543200[0]: 0x%x -> 0x%x at frame %d", last0, v0, frame);
            last0 = v0;
        }
    }
    if (getenv("MK4_TRACE_CAMNODE") && (frame % 60) == 0)
        SDL_Log("CAMNODE f%-4d boot=%x partInit=%x emitter=%x (0x535e6c=title node)",
                frame, *MK4_VA(unsigned int, 0x537f78u),
                *MK4_VA(unsigned int, 0x541de0u),
                *MK4_VA(unsigned int, 0x535e6cu));
    /* MK4_TRACE_LIGHT: the render path's lighting scratch - light matrix,
     * vertex colour, the packed RGB scales, attenuation. All zero on a path
     * means no lit geometry reached the walker that frame; it is per-node
     * scratch, so seeding it from outside the walker does nothing. */
    /* MK4_DUMP_ATLAS=<path>: write texture page 0 as a PPM once the scene
     * is up - the font atlas the text glyphs sample. */
    { const char *ap = getenv("MK4_DUMP_ATLAS");
      static int done;
      if (ap && !done && frame > 100) {
          extern int MK4_NativeDumpTexPage(int slot, const char *path);
          done = 1;
          MK4_NativeDumpTexPage(0, ap);
      } }
    if (getenv("MK4_TRACE_LIGHT") && (frame % 60) == 0)
        SDL_Log("LIGHT f%-4d mat=[%x %x %x | %x %x %x] col=%04x prev=%04x "
                "scales=%02x %02x %02x %02x %02x %02x  atten=%x bias=%x",
                frame,
                *MK4_VA(unsigned int, 0x7af9c0u), *MK4_VA(unsigned int, 0x7af9c4u),
                *MK4_VA(unsigned int, 0x7af9c8u), *MK4_VA(unsigned int, 0x7af9ccu),
                *MK4_VA(unsigned int, 0x7af9d0u), *MK4_VA(unsigned int, 0x7af9d4u),
                *MK4_VA(unsigned short, 0x7af9fcu),
                *MK4_VA(unsigned short, 0x7af9f0u),
                *MK4_VA(unsigned char, 0x7af9f2u), *MK4_VA(unsigned char, 0x7af9f3u),
                *MK4_VA(unsigned char, 0x7af9f4u), *MK4_VA(unsigned char, 0x7af9f5u),
                *MK4_VA(unsigned char, 0x7af9f6u), *MK4_VA(unsigned char, 0x7af9f7u),
                *MK4_VA(unsigned int, 0xab4e60u), *MK4_VA(unsigned int, 0xab4d9cu));
    if (getenv("MK4_TRACE_MSTACK") && (frame % 4) == 0)
            SDL_Log("f%-3d mstackTop=%08x nodeIdx=%08x", frame,
                    *MK4_VA(unsigned int, 0x4d57acu),
                    *MK4_VA(unsigned int, 0x542044u));
        /* The two "someone is pressing something" bytes are filled by the
         * original's DirectInput layer, not by MK4's own code - so the
         * backend publishes them, once per frame, before the logic runs. */
        { extern void MK4_NativeInputPublish(void); MK4_NativeInputPublish(); }
        /* the frame number, exported so probes deep in the engine can say
         * WHEN they ran - "this never saw the input" and "this never ran
         * while the input was up" look identical without it */
        { extern unsigned int g_mk4FrameNo; g_mk4FrameNo = (unsigned int)frame; }
        { extern void MK4_NativeFakeKeyTick(void); MK4_NativeFakeKeyTick(); }
        /* MK4_TRACE_NODES: the node allocator's live count and the spare
         * chain cursor. A controller that re-queues its continuation on
         * every visit shows up here as a straight line upward, long before
         * it exhausts the 64 slots. */
        if (getenv("MK4_TRACE_WALKLIST") && (frame % 200) == 0)
            SDL_Log("f%-4d walklist=[%x %x %x %x %x %x %x %x] heads=[%x %x] cb=%x",
                    frame,
                    *MK4_VA(unsigned int, 0x5420a0u), *MK4_VA(unsigned int, 0x5420a4u),
                    *MK4_VA(unsigned int, 0x5420a8u), *MK4_VA(unsigned int, 0x5420acu),
                    *MK4_VA(unsigned int, 0x5420b0u), *MK4_VA(unsigned int, 0x5420b4u),
                    *MK4_VA(unsigned int, 0x5420b8u), *MK4_VA(unsigned int, 0x5420bcu),
                    *MK4_VA(unsigned int, 0x541e84u), *MK4_VA(unsigned int, 0x541e98u),
                    *MK4_VA(unsigned int, 0x4d513cu));
        if (getenv("MK4_TRACE_WALKLIST") && (frame % 200) == 0) {
            unsigned int k, tot = 0;
            for (k = 0; k < 8; k++) {
                unsigned int h = *MK4_VA(unsigned int, 0x541e84u + k * 4u);
                tot += h ? MK4_NODE_AT(unsigned int, h, 0xc) : 0;
            }
            SDL_Log("f%-4d chain elements total=%u", frame, tot);
        }
        { extern char *getenv(const char *);
          static unsigned int lastChar = 0xffffffffu;
          if (getenv("MK4_TRACE_SEL")) {
              unsigned int c = *MK4_VA(unsigned int, 0x537f48u);
              if (c != lastChar) { lastChar = c;
                  SDL_Log("SEL f%-4d char1=%u phase1=%u slot78=%x", frame, c,
                          *MK4_VA(unsigned int, 0x537f88u),
                          *MK4_VA(unsigned int, 0x542078u)); } } }
        /* MK4_SELECT_IDLE=<frame>: force the character select's idle counter
         * (0x5380e4) to 1 at that frame, so the 20-beat / 60-tick attract
         * timeout in CharSelect_IdleTimeout fires within one beat instead of
         * 1200 frames. Nothing else changes - the controller still runs its
         * own probes and its own install. */
        { const char *at = getenv("MK4_SELECT_IDLE");
          if (at && frame == atoi(at)) {
              *MK4_VA(unsigned int, 0x5380e4u) = 1;
              SDL_Log("select: idle counter forced to 1 at frame %d", frame);
          } }

        /* MK4_TRACE_GLOBALS=<frame>:<va>,<va>,... - print a handful of arena
         * dwords once, at that frame. For answering "which branch would this
         * take" without having to convert the function first. */
        { const char *spec = getenv("MK4_TRACE_GLOBALS");
          if (spec) { const char *p2 = spec; int f = 0;
            while (*p2 >= '0' && *p2 <= '9') f = f * 10 + (*p2++ - '0');
            if (f == frame) { if (*p2 == ':') p2++;
                while (*p2) { unsigned int va = 0;
                    while ((*p2 >= '0' && *p2 <= '9') || (*p2 >= 'a' && *p2 <= 'f'))
                        va = va * 16u + (unsigned)(*p2 <= '9' ? *p2 - '0' : *p2 - 'a' + 10), p2++;
                    if (va) SDL_Log("GLOBAL %06x = %08x", va,
                                    *MK4_VA(unsigned int, va));
                    if (*p2 == ',') p2++; else break; } } } }

        /* MK4_TRACE_NODELIST=<frame>: walk the live controller list once and
         * print every node's tag, callback and resume word. The dispatch
         * tally only shows what RUNS; this shows what is installed but gated
         * out, which is what you need when a screen ignores a button. */
        { const char *at = getenv("MK4_TRACE_NODELIST");
          if (at && frame == atoi(at)) {
              unsigned int n = *MK4_VA(unsigned int, 0x52ab3cu);
              int guard = 0;
              while (n != 0 && guard++ < 80) {
                  SDL_Log("NODE %06x tag=%-5x cb=%08x d8=%08x wt=%-4x st=%x",
                          n,
                          *MK4_VA(unsigned int, n + 0xcu),
                          *MK4_VA(unsigned int, n + 8u),
                          *MK4_VA(unsigned int, n + 0xd8u),
                          *MK4_VA(unsigned int, n + 0xe0u),
                          *MK4_VA(unsigned int, n + 0x84u));
                  n = *MK4_VA(unsigned int, n + 0xe4u);
              }
              SDL_Log("NODE list end (gameMode=%x)",
                      *MK4_VA(unsigned int, 0x543800u));
          } }
        if (getenv("MK4_TRACE_NODES") && (frame % 100) == 0)
            SDL_Log("f%-4d nodes=%u queue=%u pad=[%x %x %x %x] gate=[%x %x] "
                    "dirs=%x act=%x", frame,
                    *MK4_VA(unsigned int, 0x541e64u),
                    *MK4_VA(unsigned int, 0x00f85b40u),
                    *MK4_VA(unsigned int, 0x4d50a4u),
                    *MK4_VA(unsigned int, 0x4d50a8u),
                    *MK4_VA(unsigned int, 0x4d50acu),
                    *MK4_VA(unsigned int, 0x4d50b0u),
                    *MK4_VA(unsigned int, 0x4ffd7cu),
                    *MK4_VA(unsigned int, 0x7af918u),
                    *MK4_VA(unsigned int, 0x4d50b4u),
                    (unsigned)*MK4_VA(unsigned char, 0x4d50b8u));
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
        /* MK4_BOOT_MATCHSTART=<frame>: schedule the FULL match-start FSM -
         * the keystone that spawns the skeleton build, drives the round
         * intro anims, steps the walk-in through code-table states 0x25 /
         * 0x26 with a ten-step budget, and STOPS it. One spawn per
         * fighter, group staged before each (the controller captures it). */
        /* MK4_DEBUG_VIEW=1: the fight-scene debug view - the one knob that
         * puts both fighters on screen, one either side, facing each
         * other, the way the game frames a round.
         *
         * It applies the three corrections this port has MEASURED but not
         * yet sourced from the engine's own state:
         *   - a quarter turn in the first and third angle slots of each
         *     fighter, which is what makes their matrix builder behave as
         *     a yaw about the vertical instead of tipping the model flat;
         *   - the same quarter turns on the camera, for the same reason;
         *   - a camera pose on the world Z axis looking at the origin,
         *     perpendicular to the fighters' separation axis (they stand
         *     at world x = -1.30 and +1.30).
         *
         * This is a HARNESS, not the engine's path: the engine still has
         * to supply those angles itself, and the fighters still stand in
         * bind pose because no decoded animation reaches their bones.
         * Setting any of the individual knobs overrides the matching part.
         */
        { extern unsigned int g_mk4FrameNo; g_mk4FrameNo = (unsigned int)frame; }

        if (getenv("MK4_DEBUG_VIEW")) {
            unsigned int cam = *MK4_VA(unsigned int, 0x52ab10u);
            unsigned int ns[2] = { *MK4_VA(unsigned int, 0x538158u),
                                   *MK4_VA(unsigned int, 0x53815cu) };
            const int Q = 102943;              /* a quarter turn in BAM */
            int i;
            if (cam && !getenv("MK4_CAM_POS")) {
                MK4_NODE_AT(int, cam, 0x54) = 0;
                MK4_NODE_AT(int, cam, 0x58) = -110000;
                MK4_NODE_AT(int, cam, 0x5c) = -524288;
            }
            if (cam) {
                if (!getenv("MK4_CAM_PITCH")) MK4_NODE_AT(int, cam, 0x60) = Q;
                if (!getenv("MK4_CAM_YAW"))   MK4_NODE_AT(int, cam, 0x64) = Q;
                if (!getenv("MK4_CAM_ROLL"))  MK4_NODE_AT(int, cam, 0x68) = Q;
            }
            for (i = 0; i < 2; i++) if (ns[i]) {
                if (!getenv("MK4_FIGHTER_PITCH")) MK4_NODE_AT(int, ns[i], 0x60) = Q;
                if (!getenv("MK4_FIGHTER_ROLL"))  MK4_NODE_AT(int, ns[i], 0x68) = Q;
            }
        }

        /* MK4_CAM_POS="x,y,z": EXPERIMENT ONLY - park the camera at a
         * fixed world pose each frame (16.16 units). The view looks along
         * world +X, so x=-7 z=0 frames the origin where the fighters
         * stand. */
        { const char *cp = getenv("MK4_CAM_POS");
          if (cp) { int cx = 0, cy = 0, cz = 0;
            if (sscanf(cp, "%d,%d,%d", &cx, &cy, &cz) == 3) {
                unsigned int cam = *MK4_VA(unsigned int, 0x52ab10u);
                if (cam) { MK4_NODE_AT(int, cam, 0x54) = cx;
                           MK4_NODE_AT(int, cam, 0x58) = cy;
                           MK4_NODE_AT(int, cam, 0x5c) = cz; } } } }

        /* MK4_FIGHTER_PITCH=<bam>: EXPERIMENT ONLY - set the fighters'
         * first angle slot (+0x60). Under BuildRotMatrix_OrderA a zero
         * first angle always sources world height from the model's LOCAL
         * Z; a quarter turn here should bring local Y up instead. */
        { const char *pt = getenv("MK4_FIGHTER_PITCH");
          if (pt) { int a = atoi(pt); int i;
            unsigned int ns[2] = { *MK4_VA(unsigned int, 0x538158u),
                                   *MK4_VA(unsigned int, 0x53815cu) };
            const char *rl = getenv("MK4_FIGHTER_ROLL");
            for (i = 0; i < 2; i++) if (ns[i]) {
                MK4_NODE_AT(int, ns[i], 0x60) = a;
                if (rl) MK4_NODE_AT(int, ns[i], 0x68) = atoi(rl);
            } } }

        /* MK4_FIGHTER_SEL=<n>: EXPERIMENT ONLY - force the matrix-builder
         * selector in the fighters' kind word (bits 24..26), which picks
         * from the 8-entry table at 0x4f7888. */
        { const char *se = getenv("MK4_FIGHTER_SEL");
          if (se) { unsigned int n = (unsigned int)atoi(se) & 7u; int i;
            unsigned int ns[2] = { *MK4_VA(unsigned int, 0x538158u),
                                   *MK4_VA(unsigned int, 0x53815cu) };
            for (i = 0; i < 2; i++) if (ns[i])
                MK4_NODE_AT(unsigned int, ns[i], 0x34) =
                    (MK4_NODE_AT(unsigned int, ns[i], 0x34) & ~0x7000000u)
                    | (n << 24); } }

        /* MK4_FIGHTER_ROT=<slot>: EXPERIMENT ONLY - move each fighter's
         * facing angle into a different one of the three angle slots, to
         * find which one the model's own axes expect. 0/1/2 = +0x60 /
         * +0x64 / +0x68. */
        { const char *sl = getenv("MK4_FIGHTER_ROT");
          if (sl) { int k = atoi(sl); int i;
            unsigned int ns[2] = { *MK4_VA(unsigned int, 0x538158u),
                                   *MK4_VA(unsigned int, 0x53815cu) };
            for (i = 0; i < 2; i++) if (ns[i]) {
                int a = MK4_NODE_AT(int, ns[i], 0x60)
                      | MK4_NODE_AT(int, ns[i], 0x64)
                      | MK4_NODE_AT(int, ns[i], 0x68);
                MK4_NODE_AT(int, ns[i], 0x60) = 0;
                MK4_NODE_AT(int, ns[i], 0x64) = 0;
                MK4_NODE_AT(int, ns[i], 0x68) = 0;
                MK4_NODE_AT(int, ns[i], 0x60 + 4 * k) = a;
            } } }

        /* MK4_CAM_YAW=<bam>: EXPERIMENT ONLY - force the camera's yaw each
         * frame to test whether the framing gap is a constant offset. */
        { const char *y = getenv("MK4_CAM_YAW");
          const char *cpi = getenv("MK4_CAM_PITCH");
          const char *cro = getenv("MK4_CAM_ROLL");
          unsigned int cam = *MK4_VA(unsigned int, 0x52ab10u);
          if (cam) {
              if (y)   MK4_NODE_AT(int, cam, 0x64) = atoi(y);
              if (cpi) MK4_NODE_AT(int, cam, 0x60) = atoi(cpi);
              if (cro) MK4_NODE_AT(int, cam, 0x68) = atoi(cro);
          } }

        /* MK4_TRACE_POS=<frame>: where the two fighter groups and the
         * camera actually are in world space. The arena renders at the
         * right depth, so a fighter sitting far closer to the eye than the
         * floor means its GROUP position is wrong, not its bones. */
        { const char *at = getenv("MK4_TRACE_POS");
          if (at && frame == atoi(at)) {
              unsigned int p1 = *MK4_VA(unsigned int, 0x538158u);
              unsigned int p2 = *MK4_VA(unsigned int, 0x53815cu);
              unsigned int cam = *MK4_VA(unsigned int, 0x52ab10u);
              SDL_Log("POS p1=%x at [%d %d %d]", p1,
                      p1 ? MK4_NODE_AT(int, p1, 0x54) : 0,
                      p1 ? MK4_NODE_AT(int, p1, 0x58) : 0,
                      p1 ? MK4_NODE_AT(int, p1, 0x5c) : 0);
              { unsigned int r84 = *MK4_VA(unsigned int, 0x541e84u);
                unsigned int r8c = *MK4_VA(unsigned int, 0x541e8cu);
                SDL_Log("POS roots: e84=%x (+4=%x +8=%x +c=%x)  e8c=%x (+4=%x +8=%x +c=%x)",
                        r84, r84?MK4_NODE_AT(unsigned int,r84,4):0,
                        r84?MK4_NODE_AT(unsigned int,r84,8):0,
                        r84?MK4_NODE_AT(unsigned int,r84,0xc):0,
                        r8c, r8c?MK4_NODE_AT(unsigned int,r8c,4):0,
                        r8c?MK4_NODE_AT(unsigned int,r8c,8):0,
                        r8c?MK4_NODE_AT(unsigned int,r8c,0xc):0); }
              if (p1) SDL_Log("POS p1 list: l0=%x owner4=%x prev8=%x cnt_c=%x",
                      MK4_NODE_AT(unsigned int, p1, 0),
                      MK4_NODE_AT(unsigned int, p1, 4),
                      MK4_NODE_AT(unsigned int, p1, 8),
                      MK4_NODE_AT(unsigned int, p1, 0xc));
              if (p1) SDL_Log("POS p1 links: parent14=%x next10=%x child18=%x list1c=%x flags20=%x kind34=%x",
                      MK4_NODE_AT(unsigned int, p1, 0x14),
                      MK4_NODE_AT(unsigned int, p1, 0x10),
                      MK4_NODE_AT(unsigned int, p1, 0x18),
                      MK4_NODE_AT(unsigned int, p1, 0x1c),
                      MK4_NODE_AT(unsigned int, p1, 0x20),
                      MK4_NODE_AT(unsigned int, p1, 0x34));
              SDL_Log("POS p2=%x at [%d %d %d]", p2,
                      p2 ? MK4_NODE_AT(int, p2, 0x54) : 0,
                      p2 ? MK4_NODE_AT(int, p2, 0x58) : 0,
                      p2 ? MK4_NODE_AT(int, p2, 0x5c) : 0);
              { unsigned int c = p1 ? MK4_NODE_AT(unsigned int, p1, 0x18) : 0;
                int k = 0;
                SDL_Log("POS p1 child chain:");
                while (c && k < 10) {
                    SDL_Log("   bone %x loc=[%d %d %d] rot=[%x %x %x] mesh=%x kid=%x",
                            c, MK4_NODE_AT(int, c, 0x30), MK4_NODE_AT(int, c, 0x34),
                            MK4_NODE_AT(int, c, 0x38),
                            MK4_NODE_AT(unsigned int, c, 0x3c),
                            MK4_NODE_AT(unsigned int, c, 0x40),
                            MK4_NODE_AT(unsigned int, c, 0x44),
                            MK4_NODE_AT(unsigned int, c, 0x24),
                            MK4_NODE_AT(unsigned int, c, 0x18));
                    c = MK4_NODE_AT(unsigned int, c, 0);   /* next sibling */
                    k++;
                } }
              if (cam) SDL_Log("POS cam rot=[%d %d %d] loc30=[%d %d %d] flags=%x",
                      MK4_NODE_AT(int, cam, 0x60), MK4_NODE_AT(int, cam, 0x64),
                      MK4_NODE_AT(int, cam, 0x68),
                      MK4_NODE_AT(int, cam, 0x30), MK4_NODE_AT(int, cam, 0x34),
                      MK4_NODE_AT(int, cam, 0x38),
                      MK4_NODE_AT(unsigned int, cam, 0x20));
              SDL_Log("POS cam=%x at [%d %d %d] aim=[%d %d]", cam,
                      cam ? MK4_NODE_AT(int, cam, 0x54) : 0,
                      cam ? MK4_NODE_AT(int, cam, 0x58) : 0,
                      cam ? MK4_NODE_AT(int, cam, 0x5c) : 0,
                      *MK4_VA(int, 0x52ab04u), *MK4_VA(int, 0x52ab08u));
          } }

        if (getenv("MK4_BOOT_MATCHSTART")) {
            const char *at = getenv("MK4_BOOT_MATCHSTART");
            if (frame == atoi(at)) {
                unsigned int save = *MK4_VA(unsigned int, 0x54205cu);
                unsigned int p1 = *MK4_VA(unsigned int, 0x538158u);
                unsigned int p2 = *MK4_VA(unsigned int, 0x53815cu);
                extern void StoreTwoCall(int cb, int type);

                if (p1) { *MK4_VA(unsigned int, 0x54205cu) = p1;
                          StoreTwoCall(0x468f60, 0x8a); }
                if (p2) { *MK4_VA(unsigned int, 0x54205cu) = p2;
                          StoreTwoCall(0x468f60, 0x8a); }
                *MK4_VA(unsigned int, 0x54205cu) = save;
                SDL_Log("boot-matchstart: FSM scheduled for %06x / %06x", p1, p2);
            }
        }
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
        /* MK4_FRONTEND_GSM=<frame>: send the game-state machine command 2
         * (state 0 -> 6) from the NORMAL front-end flow, not the boot-match
         * harness. State 6 is the only thing that sets g_gsmActiveFlag
         * (0xab4334), and Screen_Loading only takes the branch that calls
         * AudioInitSequence - the one that would give the match sequencer a
         * node - while that flag is set. In the front-end flow it reads 0 at
         * frame 2000, so this is the experiment that tests whether the flag
         * is the whole gap. Diagnostic only. */
        { const char *at = getenv("MK4_FRONTEND_GSM");
          if (at && frame == atoi(at)) {
              extern int GameStateMachine(int);
              SDL_Log("frontend-gsm: command 2 at frame %d -> %d", frame,
                      GameStateMachine(2));
              SDL_Log("frontend-gsm: gsmActiveFlag now %08x",
                      *MK4_VA(unsigned int, 0xab4334u)); } }
        /* MK4_FRONTEND_TICK=<frame>: queue a SECOND loading tick. The tick at
         * 0x4a42e0 is a one-shot - it clears its own command word and never
         * re-arms +8 - and it services exactly ONE work flag per visit: the
         * world re-init at 0x543810 first (that arm ends at 0x4a4494 with a
         * ret, so it can never fall through to the audio arm), then the audio
         * publish at 0x543814 on a LATER tick. Nothing in the front-end flow
         * schedules that later tick; SAE's state 4 installs only the first.
         * This is the experiment that tests whether a second one is all that
         * is missing to reach AudioInitSequence. Diagnostic only. */
        /* MK4_FRONTEND_WORK=<frame>: raise g_gsmDirty1/2/3 (0xab4374/78/7c),
         * the three flags GameStateMachine's title state publishes into the
         * loading tick's work flags g_gsmOut1/2/3 (0x543818/814/810). Arm 3,
         * the g_gsmOut1 one, is the only arm of the tick that RE-ARMS it
         * (+8 = 0x4a42e0, cmd = 2) before chaining to the geo loader - so it
         * is the arm that makes the tick self-schedule instead of dying after
         * one work flag. MK4_MAIN_MENU raises 0x543810 and 0x543814 directly
         * at frame 8 and never 0x543818, which is why the chain has always
         * stopped. Diagnostic only. */
        /* MK4_FRONTEND_PRESS=<frame>: the loading screen's press-start gate,
         * answered the way MK4_BOOT_PRESS does it. TripleCallByteCheck reads
         * an aggregate that MK4_KEYS does not feed - pressing Enter through
         * the normal key script leaves the loader's state 3 spinning - so use
         * the same fake-press entry point. Diagnostic only. */
        /* MK4_FRONTEND_SRC=<frame>: stage a press at the SOURCE word instead
         * of the derived aggregate. Helper_TickFrame_Misc recomputes
         * 0x4d50b8 every frame as `~*0x543370 & ~*0x4d50c8` (triplet 2 of the
         * table at 0x4f2fd4) and 0x4d50b4 the same way from 0x54336c - so
         * whatever the native publisher writes into the derived words is
         * wiped before the node pump runs. The sources are ACTIVE LOW, so a
         * press is a bit going CLEAR for one frame. Diagnostic only. */
        { const char *at = getenv("MK4_FRONTEND_SRC");
          if (at && frame == atoi(at)) {
              *MK4_VA(unsigned int, 0x543370u) &= ~1u;
              SDL_Log("frontend-src: 0x543370 bit0 cleared at frame %d (src=%08x)",
                      frame, *MK4_VA(unsigned int, 0x543370u)); }
          if (at && frame == atoi(at) + 1)
              *MK4_VA(unsigned int, 0x543370u) |= 1u; }
        /* ---- FRONT END TO A FIGHT, end to end ----------------------------
         * The five MK4_FRONTEND_* variables below drive the game's own screens
         * from the mode select all the way into a live match. Recipe:
         *
         *   MK4_MAIN_MENU=40 MK4_SELECT_IDLE=420
         *   MK4_KEYS=150:85,300:85,540:49,580:49,2400:85,2600:85
         *   MK4_FRONTEND_GSM=1750 MK4_FRONTEND_TICK=2050,2150,2250
         *   MK4_FRONTEND_FIGHT=3000
         *
         * THREE variables, not four - ablation says MK4_FRONTEND_WORK is not
         * needed: dropping it gives the identical 157664 px. Dropping either
         * of the other two does break it (no GSM produces no frame at all, no
         * TICK lands on a different screen at 222435 px), so the set is
         * minimal as it stands.
         *
         * gives mode select -> character select -> tower -> loading screen ->
         * a live 3D scene with both fighters spawned (P1 and P2 node handles
         * non-zero at 0x538158 / 0x53815c), 157664 px on seeds 1, 2 and 3 and
         * changing frame to frame.
         *
         * Each one stands in for a piece the flow cannot yet do on its own,
         * and each is documented at its own block: GSM sets g_gsmActiveFlag
         * that only FSM state 6 sets; TICK queues one tick per work arm
         * because the tick is a one-shot; FIGHT schedules the match init that
         * Phase3InstallSelf would. (WORK, which raises the tick's work flags
         * by hand, turns out to be redundant - MK4_MAIN_MENU's frame-8 writes
         * to 0x543810 and 0x543814 already cover what this path needs.) They are diagnostics, not fixes - the point of having them
         * is that what remains is now five named gaps rather than a screen
         * that stops.
         * ------------------------------------------------------------------ */
        /* MK4_FRONTEND_FIGHT=<frame>: schedule the match init from the
         * NORMAL front-end flow. This is the same StoreTwoCall(0x4228b0,
         * 0x11) MK4_BOOT_FIGHT makes, and work type 0x11 is what matters -
         * the pump's gate passes any node whose +0xe0 is 0x11 regardless of
         * gameMode, so this reaches the pump even while the loading tick
         * still owns the world at 0x4a42e0. Diagnostic only. */
        /* MK4_FRONTEND_NOP2=<frame>: clear player two's node handle, to test
         * whether the fighters are actually DRAWN in the scene or merely
         * spawned. If the frame changes, the renderer is walking them. */
        { const char *at = getenv("MK4_FRONTEND_NOP2");
          if (at && frame == atoi(at)) {
              *MK4_VA(unsigned int, 0x53815cu) = 0;
              SDL_Log("frontend-nop2: P2 node handle cleared at frame %d", frame); } }
        { const char *at = getenv("MK4_FRONTEND_FIGHT");
          if (at && frame == atoi(at)) {
              extern void StoreTwoCall(int, int);
              StoreTwoCall(0x4228b0, 0x11);
              *MK4_VA(unsigned int, 0x543800u) = 0xffffffffu;
              SDL_Log("frontend-fight: match init scheduled at frame %d", frame); } }
        { const char *at = getenv("MK4_FRONTEND_PRESS");
          if (at && frame == atoi(at)) {
              extern void MK4_NativeFakeKeyPress(int, int);
              MK4_NativeFakeKeyPress(0x0d, 2);
              SDL_Log("frontend-press: Enter faked at frame %d", frame); } }
        { const char *at = getenv("MK4_FRONTEND_WORK");
          if (at && frame == atoi(at)) {
              /* the dirty flags alone do nothing here - publishing them into
               * the work flags needs GameStateMachine's title state, which
               * this flow never runs - so raise g_gsmOut1 directly too, which
               * is what the tick actually reads at 0x4a44c2 */
              *MK4_VA(unsigned int, 0xab4374u) = 1;
              *MK4_VA(unsigned int, 0xab4378u) = 1;
              *MK4_VA(unsigned int, 0xab437cu) = 1;
              *MK4_VA(unsigned int, 0x543818u) = 1;
              SDL_Log("frontend-work: gsmDirty1/2/3 + gsmOut1 raised at frame %d",
                      frame); } }
        { const char *at = getenv("MK4_FRONTEND_TICK");
          /* comma-separated frames: the tick services ONE work flag per
           * visit in priority order (world 0x543810, then audio 0x543814,
           * then 0x543818), so reaching a later arm needs one queued tick per
           * arm ahead of it. */
          int want = 0;
          if (at) { const char *q = at;
              while (*q) { int f = 0;
                  while (*q >= '0' && *q <= '9') f = f * 10 + (*q++ - '0');
                  if (f == frame) want = 1;
                  if (*q == ',') q++; else break; } }
          if (want) {
              extern void StoreTwoCall(int, int);
              StoreTwoCall(0x4a42e0, 0x4000);
              SDL_Log("frontend-tick: second loading tick queued at frame %d"
                      " (worldFlag=%08x audioFlag=%08x gsm=%08x)", frame,
                      *MK4_VA(unsigned int, 0x543810u),
                      *MK4_VA(unsigned int, 0x543814u),
                      *MK4_VA(unsigned int, 0xab4334u)); } }
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


