/**
 * The character select's P1 CURSOR STEP: GameNetSyncState (0x49fb70), the
 * function the P1 picker calls every five ticks, and the two small helpers
 * under it.
 *
 * It is a phase machine on 0x537f88, and it only does anything when the
 * screen is settled (0x52aac4 == 3), P1 is at state 2 and the "still
 * settling" latch 0x541d88 is clear - which it sets itself on the way out,
 * so the body runs ONCE per phase:
 *
 *   phase <= 0xf  If P1's own picker tag 0x252 is gone, read the pad through
 *      MStackPush2TableNot and, with the button bit (slot74 & 4) up, take
 *      the MOVE path - MStackDualPushSaveRestore, then the 0x238 controller
 *      at 0x4a0b00. Otherwise install the grid controller 0x4a0060 under tag
 *      0x15, run RoundWinTransition to put the fighter in, roll the 0x22f
 *      chain back and dispatch the scene word at 0x4e2860.
 *   phase 0x10   install 0x4a0dc0 under tag 0x23d.
 *   phase 0x11   dispatch 0x4e2860, install 0x4a10d0 under tag 0x242.
 *   phase 0x12   hand off to AudioMStackPushHandlerPair.
 *
 *   Cmp3DirtyToggle (0x49fa20) - dirty bit 0 = "the screen phase is 3",
 *     which is what SceneEvalFsm's ready path set.
 *   MStackPush2TableNot (0x426230) - the pad read: the three words at
 *     0x4d50a4 / 0x4d50a8 / 0x4d50b0 INVERTED into walkSlot6c (masked to 16
 *     bits), slot70 and slot74, under an mstack save of 0x542078 and the
 *     current node.
 *
 * Still hollow below this: the grid controller 0x4a0060 and its family
 * (AudioMStackPushHandlerPair, AudioVoiceSequencerCluster, AudioStateRemap),
 * MStackDualPushSaveRestore, BitSetByIndex, and P2's mirror
 * AudioCmpCascadeDispatcher. None of them can hang the pump: the picker that
 * calls this pauses on its own beat afterwards.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void DualPushSetCallDualPop(unsigned int tag);
extern void SetWalkCurCallPauseDirty(unsigned int callback, unsigned int tag);
extern void TripleStageRollback(unsigned int tag);
extern void TaggedSceneDispatch(int tag);
extern void RoundWinTransition(void);
/* still hollow */
extern void MStackDualPushSaveRestore(void);
extern void BitSetByIndex(void);
extern void AudioMStackPushHandlerPair(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_xformScratch94  (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_tickFlagF       (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_settlingP1      (*(unsigned int *)MK4_VA(unsigned int, 0x541d88u))
#define g_phaseP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f88u))
#define g_phaseP2         (*(unsigned int *)MK4_VA(unsigned int, 0x537e90u))

/* 0x49fa20 */
void Cmp3DirtyToggle(void)
{
    g_walkSlot6c = g_tickFlagF;
    if (g_tickFlagF == 3) g_stateBits8c |= 1; else g_stateBits8c &= ~1u;
}

/* 0x426230 - the pad read, inverted, under an mstack save */
void MStackPush2TableNot(void)
{
    unsigned int top, v;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot78;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    g_currentNodeIdx = 0x4d50a4u >> 2;
    v = ~*MK4_VA(unsigned int, 0x4d50a4u) & 0xffffu;
    g_slot78 = 0xffff;
    g_walkSlot6c = v;

    g_currentNodeIdx = 0x4d50a8u >> 2;
    g_slot70 = ~*MK4_VA(unsigned int, 0x4d50a8u);
    g_walkSlot6c = v;

    g_currentNodeIdx = 0x4d50b0u >> 2;
    g_slot74 = ~*MK4_VA(unsigned int, 0x4d50b0u);
    g_walkSlot6c = v;

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot78 = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x49fb70 */
void GameNetSyncState(void)
{
    unsigned int phase;

    Cmp3DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) return;

    g_walkSlot6c = g_activeP1;
    if (g_activeP1 != 2) return;
    g_walkSlot6c = g_settlingP1;
    if (g_settlingP1 != 0) return;

    phase = g_phaseP1;
    g_slot7c = 0;
    g_slot78 = phase;

    if (phase > 0xfu) {
        if (phase == 0x10) {                     /* 0x49fcd4 */
            g_slot54 = 0;
            SetWalkCurCallPauseDirty(0x4a0dc0u, 0x23d);
            g_walkSlot6c = 1;
            g_settlingP1 = 1;
            return;
        }
        if (phase == 0x11) {                     /* 0x49fd00 */
            g_slot54 = 0;
            TaggedSceneDispatch((int)*MK4_VA(unsigned short, 0x4e2860u));
            SetWalkCurCallPauseDirty(0x4a10d0u, 0x242);
            g_walkSlot6c = 1;
            g_settlingP1 = 1;
            return;
        }
        if (phase == 0x12)
            AudioMStackPushHandlerPair();
        return;
    }

    DualPushSetCallDualPop(0x252);
    if ((g_stateBits8c & 1u) == 0) {
        MStackPush2TableNot();
        if (g_framePauseFlag != 0) return;
        g_xformScratch94 = g_slot74 & 4u;
        if (g_xformScratch94 != 0) {             /* 0x49fc58: MOVE */
            MStackDualPushSaveRestore();
            if (g_framePauseFlag != 0) return;
            if ((g_stateBits8c & 1u) == 0) return;
            DualPushSetCallDualPop(0x239);
            if ((g_stateBits8c & 1u) != 0 && g_slot78 == g_phaseP2)
                return;
            g_walkSlot6c = 0;
            BitSetByIndex();
            if (g_framePauseFlag != 0) return;
            g_slot80 = g_slot78;
            SetWalkCurCallPauseDirty(0x4a0b00u, 0x238);
            return;
        }
    }

    /* 0x49fc0c: install the grid controller and put the fighter in */
    g_walkSlot6c = 1;
    g_settlingP1 = 1;
    SetWalkCurCallPauseDirty(0x4a0060u, 0x15);
    RoundWinTransition();
    if (g_framePauseFlag != 0) return;
    TripleStageRollback(0x22f);
    TaggedSceneDispatch((int)*MK4_VA(unsigned short, 0x4e2860u));
}

#endif /* NON_MATCHING */
