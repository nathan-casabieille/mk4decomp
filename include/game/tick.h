/**
 * Per-frame gameplay tick + 4-player state.
 *
 * GameLogicStep is the 60 Hz fixed-step entry point. It dispatches
 * to GameStateMachine (menus) and GameTick (active fight) plus
 * per-frame audio + input updates.
 */
#ifndef MK4_GAME_TICK_H
#define MK4_GAME_TICK_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* === API ==================================================== */

void GameLogicStep(void);                                /* 0x004b26d0 */
void GameTick(s32 param);                                /* 0x0041fd70 */
void FrameFinalize(void);                                /* 0x00405400 */

/* Fight subsystem internals. */
void FightFrameStep(void);                               /* 0x0045c5c0 */
void FightFrameStep_Inner(void);                         /* 0x0045c6c0 */
void DispatchEventQueue(void);                           /* 0x0045c820 */
void DispatchEventQueue_Commit(void);                    /* 0x0045c8d0 */

/* === Globals ================================================ */

extern u32        g_frameCounter;     /* 0x007af930 */
extern s32        g_gameStateResult;  /* 0x007af918 */
extern s32        g_gameMode;         /* 0x00543800 - 0 = active fight */

/* Event-queue ping-pong. The dispatcher writes a fresh value into
 * g_eventQueuePending each tick; Commit() promotes it to
 * g_eventQueueActive when the frame is done. */
extern u32        g_eventQueuePending;  /* 0x00542048 */
extern u32        g_eventQueueActive;   /* 0x0053a31c */

/* End-of-frame state. */
extern u32        g_framePauseFlag;     /* 0x00541e6c (non-zero = skip) */
extern u32        g_logicFrameCounter;  /* 0x0053a79c */

extern packed_ptr g_player1NodeIdx;   /* 0x00538158 */
extern packed_ptr g_player2NodeIdx;   /* 0x0053815c */
extern packed_ptr g_player3NodeIdx;   /* 0x00538160 */
extern packed_ptr g_player4NodeIdx;   /* 0x00538164 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_GAME_TICK_H */
