/**
 * Per-frame fight-mode tick.
 *
 * Calls the fight frame-step + dispatch + post-fight chain, then
 * gates a 4-player overlay update (each player checks state field
 * +0x30 == player_index, plus a global probe ptr, then either OR
 * 0x10 into [+0x34] high byte or AND with mask). Tail interpolates
 * three "axis" sticky lows toward 0x8000 in 1/8 increments and
 * resets g_gameMode if it was -1 (sentinel).
 */
#include "game/tick.h"
#include "engine/scenegraph.h"
#include "audio/sound.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameMode (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))
#define g_gtAxisX (*(unsigned int *)MK4_VA(unsigned int, 0xab4e44u))
#define g_gtAxisY (*(unsigned int *)MK4_VA(unsigned int, 0xab4e48u))
#define g_gtAxisZ (*(unsigned int *)MK4_VA(unsigned int, 0xab4e4cu))
#define g_gtConfig4f (*(unsigned int *)MK4_VA(unsigned int, 0x4f3234u))
#define g_gtFightTickCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a498u))
#define g_gtModeFlag (*(unsigned int *)MK4_VA(unsigned int, 0x543590u))
#define g_gtOtherFlag (*(unsigned int *)MK4_VA(unsigned int, 0x54356cu))
#define g_gtPauseMode (*(unsigned int *)MK4_VA(unsigned int, 0x543804u))
#define g_gtPlayerEnabled (*(unsigned int *)MK4_VA(unsigned int, 0x4d5714u))
#define g_gtPlayerProbe1 (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_gtPlayerProbe2 (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_gtState438 (*(unsigned int *)MK4_VA(unsigned int, 0x543438u))
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_player2NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_player3NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538160u))
#define g_player4NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538164u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/*
 * @addr 0x0041fd70
 */
#ifdef TARGET_SDL
/* MK4_TRACE_PAD: bracketed from GameLogicStep, the input aggregate 0x4d50b8
 * is cleared inside THIS function - it reads 1 on entry and 0 on return. The
 * original never writes that byte directly, so a consumer here is reading it
 * through a computed address or wiping a block that covers it. Bracket the
 * per-frame helpers to say which. */
static unsigned char gt_pad(void) { return *MK4_VA(unsigned char, 0x4d50b8u); }
static void gt_mark(const char *where, unsigned char before)
{
    extern void SDL_Log(const char *, ...);
    extern char *getenv(const char *);
    extern unsigned int g_mk4FrameNo;
    static int tr = -1; static unsigned n;
    unsigned char after = gt_pad();
    if (tr < 0) tr = getenv("MK4_TRACE_PAD") != 0;
    if (tr && before != after && n < 16) { n++;
        SDL_Log("PAD f=%u GameTick/%s %02x -> %02x", g_mk4FrameNo, where,
                before, after); }
}
#define GT_BRACKET(where, call) \
    do { unsigned char b_ = gt_pad(); call; gt_mark(where, b_); } while (0)
#else
#define GT_BRACKET(where, call) do { call; } while (0)
#endif

void GameTick(s32 param)
{
    u32 p;

    if (g_gameMode != 0) {
        if (g_gtPauseMode == 2) {
            DebugStub_NoOp_B();
        } else {
            DebugStub_NoOp_A();
        }
    }

    if (g_gtOtherFlag == 1) {
        if (g_gtModeFlag == 1) {
            DebugStub_NoOp_A();
        } else {
            DebugStub_NoOp_B();
        }
    }

    if (g_gtConfig4f != 2 && g_gtState438 != 0) {
        if (g_gtModeFlag == 1) {
            DebugStub_NoOp_A();
        }
        if (g_gtModeFlag == 2) {
            DebugStub_NoOp_B();
        }
    }

    if (g_gameMode == 0) {
        GT_BRACKET("FightFrameStep", FightFrameStep());
        if (g_framePauseFlag != 0) return;
        ++g_gtFightTickCounter;
        GT_BRACKET("DispatchEventQueue", DispatchEventQueue());
        if (g_framePauseFlag != 0) return;
    }

    GT_BRACKET("Helper_TickFrame_Misc", Helper_TickFrame_Misc());
    if (g_framePauseFlag != 0) return;
    GT_BRACKET("Helper_TickFrame_PostFight", Helper_TickFrame_PostFight());
    if (g_framePauseFlag != 0) return;

    if (g_gameMode == 0) {
        g_walkCallback = (void (*)(void))g_player1NodeIdx;
        if (g_player1NodeIdx != 0) {
            Helper_PerPlayerTick();
            if (g_framePauseFlag != 0) return;
        }
        Helper_PostPlayerTick();
        if (g_framePauseFlag != 0) return;
        Helper_TickFrameTail();
        if (g_framePauseFlag != 0) return;
    }

    if (param == 0) {
        p = g_player1NodeIdx;
        if (p != 0) {
            ScenegraphNode *n = (ScenegraphNode *)MK4_PTR((p * 4));
            g_currentNodeIdx = p;
            if (n->player_id == 1 &&
                g_gtPlayerProbe1 != 0 &&
                ((ScenegraphNode *)MK4_PTR((g_gtPlayerProbe1 * 4)))->fsm_state != 0x501) {
                if (g_gtPlayerEnabled != 0 && n->position_y > (s32)0xffff0000) {
                    u32 v = n->state_mask | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    n->state_mask = v;
                } else {
                    n->state_mask &= 0xffffefff;
                }
            }
        }
        p = g_player2NodeIdx;
        if (p != 0) {
            ScenegraphNode *n = (ScenegraphNode *)MK4_PTR((p * 4));
            g_currentNodeIdx = p;
            if (n->player_id == 2 &&
                g_gtPlayerProbe2 != 0 &&
                ((ScenegraphNode *)MK4_PTR((g_gtPlayerProbe2 * 4)))->fsm_state != 0x501) {
                if (g_gtPlayerEnabled != 0 && n->position_y > (s32)0xffff0000) {
                    u32 v = n->state_mask | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    n->state_mask = v;
                } else {
                    n->state_mask &= 0xffffefff;
                }
            }
        }
        p = g_player3NodeIdx;
        if (p != 0) {
            ScenegraphNode *n = (ScenegraphNode *)MK4_PTR((p * 4));
            g_currentNodeIdx = p;
            if (n->player_id == 3) {
                if (g_gtPlayerEnabled != 0 && n->position_y > (s32)0xffff0000) {
                    u32 v = n->state_mask | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    n->state_mask = v;
                } else {
                    n->state_mask &= 0xffffefff;
                }
            }
        }
        p = g_player4NodeIdx;
        if (p != 0) {
            ScenegraphNode *n = (ScenegraphNode *)MK4_PTR((p * 4));
            g_currentNodeIdx = p;
            if (n->player_id == 4) {
                if (g_gtPlayerEnabled != 0 && n->position_y > (s32)0xffff0000) {
                    u32 v = n->state_mask | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    n->state_mask = v;
                } else {
                    n->state_mask &= 0xffffefff;
                }
            }
        }

        FrameFinalize();
        if (g_framePauseFlag != 0) return;
        if (g_gameMode == 0) {
            g_gtAxisX = (s16)(g_gtAxisX + ((0x8000 - (u16)g_gtAxisX) >> 3));
            g_gtAxisY = (s16)(g_gtAxisY + ((0x8000 - (u16)g_gtAxisY) >> 3));
            g_gtAxisZ = (s16)(g_gtAxisZ + ((0x8000 - (u16)g_gtAxisZ) >> 3));
        }
    }

    if (g_gameMode == -1) {
        g_gameMode = 0;
    }
}
