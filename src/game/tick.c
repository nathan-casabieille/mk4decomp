/**
 * Per-frame gameplay tick.
 *
 * GameLogicStep is the 60 Hz fixed-step entry point; it bumps the
 * frame counter, runs the menu state machine + audio updates, then
 * dispatches either the SW-Win pause path (mode 4 + gate clear)
 * or the regular fight tick.
 */
#include "game/tick.h"
#include "game/statemachine.h"
#include "engine/scenegraph.h"
#include "audio/sound.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_frameCounter (*(unsigned int *)MK4_VA(unsigned int, 0x7af930u))
#define g_gameStateResult (*(unsigned int *)MK4_VA(unsigned int, 0x7af918u))
#define g_logicStepFlag (*(unsigned int *)MK4_VA(unsigned int, 0x54381cu))
#define g_mode4PauseGate (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd78u))
#endif


/*
 * @addr 0x004b26d0
 */
#ifdef TARGET_SDL
/* MK4_TRACE_PAD: the input aggregate 0x4d50b8 is up at MainLoopStep's entry
 * and gone by the time the node pump runs, so the clear is inside this
 * function. The original never writes that byte in any direct encoding, so
 * it goes indirectly - a computed address or a block wipe - and only a
 * bracket around each call can say which one. */
static unsigned char pad_now(void) { return *MK4_VA(unsigned char, 0x4d50b8u); }
static void pad_mark(const char *where, unsigned char before)
{
    extern void SDL_Log(const char *, ...);
    extern char *getenv(const char *);
    extern unsigned int g_mk4FrameNo;
    static int tr = -1; static unsigned n;
    unsigned char after = pad_now();
    if (tr < 0) tr = getenv("MK4_TRACE_PAD") != 0;
    if (tr && before != after && n < 16) { n++;
        SDL_Log("PAD f=%u %s %02x -> %02x", g_mk4FrameNo, where, before, after); }
}
#define PAD_BRACKET(where, call) \
    do { unsigned char b_ = pad_now(); call; pad_mark(where, b_); } while (0)
#else
#define PAD_BRACKET(where, call) do { call; } while (0)
#endif

void GameLogicStep(void)
{
    ++g_frameCounter;
    PAD_BRACKET("GameStateMachine(0)", g_gameStateResult = GameStateMachine(0));
    if (g_gameStateResult == 0) {
#ifdef TARGET_SDL
        /* MK4_TRACE_PAD: bracket Input_TickPlayers. The native publisher
         * stages 0x4d50b8 before the frame and it is still up at
         * MainLoopStep's entry, but the node pump never sees it - so print
         * either side of the game's own input tick. */
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          extern unsigned int g_mk4FrameNo;
          static int tr = -1; static unsigned n;
          unsigned char before, after;
          if (tr < 0) tr = getenv("MK4_TRACE_PAD") != 0;
          before = *MK4_VA(unsigned char, 0x4d50b8u);
          Input_TickPlayers();
          after = *MK4_VA(unsigned char, 0x4d50b8u);
          if (tr && before != after && n < 12) { n++;
              SDL_Log("PAD f=%u Input_TickPlayers %02x -> %02x", g_mk4FrameNo,
                      before, after); } }
#else
        Input_TickPlayers();
#endif
    }
    PAD_BRACKET("Audio_UpdateChannels", Audio_UpdateChannels());
    PAD_BRACKET("Audio_TimerTick", Audio_TimerTick());
    if (Renderer_GetMode() == 4 && g_mode4PauseGate == 0) {
        GameStateMachine(8);
    } else {
        PAD_BRACKET("XformChainAdvance", XformChainAdvance());
        PAD_BRACKET("GameTick", GameTick(0));
    }
    g_logicStepFlag = 0;
}
