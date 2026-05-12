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

/*
 * @addr 0x0041fd70
 */
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
        FightFrameStep();
        if (g_framePauseFlag != 0) return;
        ++g_gtFightTickCounter;
        DispatchEventQueue();
        if (g_framePauseFlag != 0) return;
    }

    Helper_TickFrame_Misc();
    if (g_framePauseFlag != 0) return;
    Helper_TickFrame_PostFight();
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
            g_currentNodeIdx = p;
            if (*(u32 *)(p * 4 + 0x30) == 1 &&
                g_gtPlayerProbe1 != 0 &&
                *(u32 *)(g_gtPlayerProbe1 * 4 + 0x74) != 0x501) {
                if (g_gtPlayerEnabled != 0 && *(s32 *)(p * 4 + 0x58) > (s32)0xffff0000) {
                    u32 v = *(u32 *)(p * 4 + 0x34) | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    *(u32 *)(p * 4 + 0x34) = v;
                } else {
                    *(u32 *)(p * 4 + 0x34) &= 0xffffefff;
                }
            }
        }
        p = g_player2NodeIdx;
        if (p != 0) {
            g_currentNodeIdx = p;
            if (*(u32 *)(p * 4 + 0x30) == 2 &&
                g_gtPlayerProbe2 != 0 &&
                *(u32 *)(g_gtPlayerProbe2 * 4 + 0x74) != 0x501) {
                if (g_gtPlayerEnabled != 0 && *(s32 *)(p * 4 + 0x58) > (s32)0xffff0000) {
                    u32 v = *(u32 *)(p * 4 + 0x34) | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    *(u32 *)(p * 4 + 0x34) = v;
                } else {
                    *(u32 *)(p * 4 + 0x34) &= 0xffffefff;
                }
            }
        }
        p = g_player3NodeIdx;
        if (p != 0) {
            g_currentNodeIdx = p;
            if (*(u32 *)(p * 4 + 0x30) == 3) {
                if (g_gtPlayerEnabled != 0 && *(s32 *)(p * 4 + 0x58) > (s32)0xffff0000) {
                    u32 v = *(u32 *)(p * 4 + 0x34) | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    *(u32 *)(p * 4 + 0x34) = v;
                } else {
                    *(u32 *)(p * 4 + 0x34) &= 0xffffefff;
                }
            }
        }
        p = g_player4NodeIdx;
        if (p != 0) {
            g_currentNodeIdx = p;
            if (*(u32 *)(p * 4 + 0x30) == 4) {
                if (g_gtPlayerEnabled != 0 && *(s32 *)(p * 4 + 0x58) > (s32)0xffff0000) {
                    u32 v = *(u32 *)(p * 4 + 0x34) | 0x1000;
                    g_walkCallback = (void (*)(void))v;
                    *(u32 *)(p * 4 + 0x34) = v;
                } else {
                    *(u32 *)(p * 4 + 0x34) &= 0xffffefff;
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
