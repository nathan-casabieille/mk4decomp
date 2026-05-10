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

/* Mode-4 (SW Windowed) pause / single-step gate. When non-zero,
 * GameLogicStep skips the special SW-Win StateMachine(8) path. */
extern u32        g_mode4PauseGate;     /* 0x004ffd78 */

/* Set to 0 at the end of every GameLogicStep iteration. */
extern u32        g_logicStepFlag;      /* 0x0054381c */

/* Helpers called from GameLogicStep that aren't in render.h /
 * scenegraph.h yet. */
int  Renderer_GetMode(void);             /* 0x004b3db0 - tiny getter */
void GameStateMachineMaybeRebuild(void); /* 0x004b5850 */
void XformChainAdvance(void);            /* 0x004bd990 */

extern packed_ptr g_player1NodeIdx;   /* 0x00538158 */
extern packed_ptr g_player2NodeIdx;   /* 0x0053815c */
extern packed_ptr g_player3NodeIdx;   /* 0x00538160 */
extern packed_ptr g_player4NodeIdx;   /* 0x00538164 */

/* === Fight subsystem groups ================================== */

/* Three entity sub-trees iterated by FightFrameStep. Each row is a
 * (head_a, head_b) packed-ptr pair into 0x5453a4a0..0x5453a4b7. */
extern u32 g_fightGroupHeads[6];      /* 0x005453a4a0 (3 pairs of u32) */

/* Three matching arrays indexed by g_fightGroupHeads slot - the
 * fixed-address sources from .rdata / .data that get packed and
 * stashed in g_pendingNodeType, g_eventQueueTotal,
 * g_fightGroupHead respectively. */
extern u32 g_fightTableA0;            /* 0x004e9250 */
extern u32 g_fightTableB0;            /* 0x00542948 */
extern u32 g_fightTableC0;            /* 0x004d50a4 */
extern u32 g_fightTableA1;            /* 0x004e92c8 */
extern u32 g_fightTableB1;            /* 0x004e9300 */
extern u32 g_fightTableC1;            /* 0x004d50a8 */
extern u32 g_fightTableA2;            /* 0x004e9318 */
extern u32 g_fightTableB2;            /* 0x0054294c */
extern u32 g_fightTableC2;            /* 0x004d50b0 */

/* === TickAllEntities state =================================== */

/* TickAllEntities walks 6 fixed entity sub-trees on the first
 * frame, then a single "main" sub-tree on every subsequent frame.
 * Per-pass it sets up (g_currentNodeIdx, g_walkCallback, g_curMask)
 * and calls one of TickInner / TickAlt; g_framePauseFlag aborts the
 * sequence. */
void Helper_PreTick(void);                               /* 0x004b9770 */
void Helper_TickInit(s32 zero);                          /* 0x004b8ec0 */
void Helper_TickInner(void);                             /* 0x004ba130 */
void Helper_TickAlt(void);                               /* 0x004bae90 */
void Helper_TickReinit(void);                            /* 0x004bc7e0 */
void Helper_FightSceneCallback(void);                    /* 0x004ba1c0 */
void TickAllEntities(void);                              /* 0x004b9e50 */

extern u32  g_tickX1;                /* 0x00ab4d98 */
extern u8   g_tickByteFlag;          /* 0x00543720 */
extern u32  g_tickW1;                /* 0x00543550 */
extern u32  g_tickX2;                /* 0x00ab51f4 */
extern u32  g_tickX3;                /* 0x00ab4e68 */
extern u32  g_tickInitFlag;          /* 0x00ab4e70 */
extern s32  g_tickDecay;             /* 0x00ab4e64 */
extern u16  g_tickCurMask;           /* 0x00ab4e20 */
extern u32 *g_tickCurConfig;         /* 0x00ab4e2c (pointer to a small struct) */
extern u32  g_tickFlagZ;             /* 0x00ab4e40 */
extern u32  g_tickFlagV;             /* 0x00541ec0 */
extern u32  g_tickFlagF;             /* 0x0052aac4 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_GAME_TICK_H */
