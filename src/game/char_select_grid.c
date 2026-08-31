/**
 * The character select's GRID controller cluster - P1's side. This is the
 * chain that walks the phase word 0x537f88 forward and puts the fighter and
 * the cursor into the scene; until it exists the select screen has exactly
 * ONE draw record (MK4_TRACE_SCENE), the title, and nothing else.
 *
 * GameNetSyncState installs 0x4a0060 under tag 0x15 and everything below
 * hangs off it:
 *
 *   0x4a0060 (AudioMStackPushHandlerPair+0x130) - the grid controller. On
 *     command 0 it parks P1's phase in slot54 and, if tag 0x239 is live AND
 *     both players sit on the same phase, re-arms itself and waits. Then it
 *     forks on g_dlMode and 0x53a1bc into SetOnePairJmp (which also forces
 *     P1 active) or straight into TripleTestInstallJmp.
 *   TripleTestInstallJmp_004a0130 - copy slot54 into slot74/slot78, run
 *     AudioVoiceSequencerCluster to turn the phase into a table entry, then
 *     tail into AudioStateRemap (the 1-on-1 path, and the two-player path
 *     while 0x53a1bc is clear) or, with both set, stamp 0x53a178 and go to
 *     AudioInstallSelfShiftedChainInit.
 *   AudioVoiceSequencerCluster (0x4a0d60, base only) - phase*5 - 5 indexes
 *     the table at 0x541fc4; the entry replaces slot78.
 *   AudioStateRemap (0x4a0190) - writes P1's char id (0x537f48) from slot78,
 *     with two remaps: entry 6 becomes 0xf once (latched in 0x543728) when
 *     0x543724 is set, and entry 7 becomes 0x11 when both 0x54372c and
 *     0x543730 are. Skipped entirely while 0x541dd4 is clear or either of
 *     the two pad bits (0x4d50a4 & 0x2000, 0x4d50a8 & 4) is up.
 *   AudioInstallSelfShiftedChainInit (0x4a0210) - command 0 clears the bit
 *     for slot74 in the mask 0x537eec, arms slot54 = 7 and chains its own
 *     state 1 through AudioInstallSelf3StateWithSubcall; command 1 either
 *     goes straight to AudioInstall2BodyDualSetup or first installs the
 *     0x250 controller with P1's phase.
 *   AudioInstall2BodyDualSetup (0x4a0300) - with g_dlMode set and 0x53a1bc
 *     clear, this is where the phase actually ADVANCES: 0x53a1bc goes to 1,
 *     the two latches clear, g_537f88 becomes 2 and RoundWinTransition puts
 *     the fighter in. In the 1-on-1 run g_dlMode is 0, so it only pauses -
 *     which is why the 1-on-1 path runs through AudioStateRemap instead.
 *   AudioInstallSelf3StateWithSubcall (0x4a0870) - a three-state countdown
 *     on slot54 (8 ticks) around MStackPush2LLWalkCompare, the chain insert
 *     and DualPushCallBitDispatch.
 *   AudioMStackPushHandlerPair (0x49ff30) - phase 0x12's hand-off: pick the
 *     table entry for the side in slot7c, and if its +0x18 slot is empty
 *     roll that side's chain back (0x22f / 0x230), dispatch its scene word
 *     (0x4e2860 / 0x4e2864) and mark the slot, then RoundWinTransition.
 *
 * P2's mirrors - 0x4a0370, SetOnePairJmp_004a0420,
 * TripleTestInstallJmp_004a0440, AudioStateRemapB (0x4a04a0) and
 * AudioInstallSelfChannel8 (0x4a0520) - are the same bodies against
 * 0x537e88 / 0x53a354 / 0x53a250 / 0x5380e0, and are not converted here.
 * Nor are DualPushCallBitDispatch (0x427ee0), the 0x250 controller
 * (AudioInitInstallSelfPeriodic+0x70) or the 0x23d one
 * (AudioVoiceSequencerCluster+0x60); each is installed by VA and simply
 * does not resolve yet.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void DualPushSetCallDualPop(unsigned int tag);
extern void TripleStageRollback(unsigned int tag);
extern void TaggedSceneDispatch(int tag);
extern void RoundWinTransition(void);
extern void CallSetPause(void);
extern void StoreTwoCall(int fn, int arg);
extern void StackPopDispatchTagged(void);
extern void MStackPush2LLWalkCompare(void);
extern void MStackPush2ChainLLInsert(void);
extern void MStackCall_MStackPush2ChainInsert_004062a0(void);
extern void DualPushCallBitDispatch(void);

void AudioVoiceSequencerCluster(void);
void AudioStateRemap(void);
void AudioInstallSelfShiftedChainInit(void);
void AudioInstall2BodyDualSetup(void);
void AudioInstallSelf3StateWithSubcall(void);
void TripleTestInstallJmp_004a0130(void);
void SetOnePairJmp_004a0110(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58          (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_dlMode          (*(unsigned int *)MK4_VA(unsigned int, 0x542004u))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_guardP1         (*(unsigned int *)MK4_VA(unsigned int, 0x53a1bcu))
#define g_settlingP1      (*(unsigned int *)MK4_VA(unsigned int, 0x541d88u))
#define g_gate541dd4      (*(unsigned int *)MK4_VA(unsigned int, 0x541dd4u))
#define g_phaseP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f88u))
#define g_phaseP2         (*(unsigned int *)MK4_VA(unsigned int, 0x537e90u))
#define g_charP1          (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_charP1Alt       (*(unsigned int *)MK4_VA(unsigned int, 0x53a178u))
#define g_selectMask      (*(unsigned int *)MK4_VA(unsigned int, 0x537eecu))
#define g_selectTable     (*(unsigned int *)MK4_VA(unsigned int, 0x541fc0u))
#define g_phaseTable      (*(unsigned int *)MK4_VA(unsigned int, 0x541fc4u))
#define g_selectSide      (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))

#define GRID_VA   0x4a0060u
#define SHIFT_VA  0x4a0210u
#define SUB3_VA   0x4a0870u

/* 0x4a0d60 - phase*5 - 5 indexes the table at 0x541fc4 */
void AudioVoiceSequencerCluster(void)
{
    unsigned int top, idx;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    idx = g_slot78 * 5u - 5u;
    g_slot78 = idx;
    idx += g_phaseTable;
    g_currentNodeIdx = idx;
    g_slot78 = *(unsigned int *)MK4_PTR(idx * 4);

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x4a0190 */
void AudioStateRemap(void)
{
    unsigned int v = g_slot78;

    g_charP1 = v;
    if (g_gate541dd4 != 0
        && (*MK4_VA(unsigned char, 0x4d50a4u) & 0x20u) == 0
        && (*MK4_VA(unsigned char, 0x4d50a8u) & 4u) == 0) {
        if (*MK4_VA(unsigned char, 0x543724u) != 0 && v == 6
            && *MK4_VA(unsigned char, 0x543728u) == 0) {
            v = 0xf;
            *MK4_VA(unsigned char, 0x543728u) = 1;
            g_charP1 = 0xf;
        }
        if (*MK4_VA(unsigned char, 0x54372cu) != 0
            && *MK4_VA(unsigned char, 0x543730u) != 0 && v == 7)
            g_charP1 = 0x11;
    }
    AudioInstallSelfShiftedChainInit();           /* jmp in the original */
}

/* 0x4a0300 - where the phase advances, in two-player mode */
void AudioInstall2BodyDualSetup(void)
{
    g_walkSlot6c = g_dlMode;
    if (g_dlMode != 0) {
        g_walkSlot6c = g_guardP1;
        if (g_guardP1 == 0) {
            g_guardP1 = 1;
            g_settlingP1 = 0;
            g_gate541dd4 = 0;
            g_phaseP1 = 2;
            g_walkSlot6c = 0;
            MK4_NODE_AT(unsigned int, g_baseSel, 0xc) = 0;
            RoundWinTransition();
        }
    }
    CallSetPause();
}

/* 0x4a0870 */
void AudioInstallSelf3StateWithSubcall(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int n;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {                              /* 0x4a091e */
        unsigned int v = g_slot54;

        g_slot54 = 8;
        g_walkSlot6c = v;
        g_slot58 = v;
        MStackPush2LLWalkCompare();
        if (g_framePauseFlag != 0) return;
        g_stateBits8c |= 4;
        n = g_currentNodeIdx;
        if (n == 0) {
            StackPopDispatchTagged();
            return;
        }
        g_stateBits8c ^= 4u;
        g_fightGroupHead = n;
        goto tail;
    }

    if (cmd == 1) {                              /* 0x4a08dd */
        g_currentNodeIdx = g_fightGroupHead;
        MStackCall_MStackPush2ChainInsert_004062a0();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = SUB3_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
        g_pendingNodeType = 2;
        g_framePauseFlag = 1;
        return;
    }

    g_slot54 -= 1;
    if (g_slot54 != 0)
        goto tail;

    g_walkSlot6c = g_slot58;
    MStackPush2LLWalkCompare();
    if (g_framePauseFlag != 0) return;
    MStackPush2ChainLLInsert();
    if (g_framePauseFlag != 0) return;
    StackPopDispatchTagged();
    return;

tail:                                            /* 0x4a097d */
    g_walkSlot6c = g_slot58;
    DualPushCallBitDispatch();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = SUB3_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 2;
    g_framePauseFlag = 1;
}

/* 0x4a0210 */
void AudioInstallSelfShiftedChainInit(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int c, mask, q;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        g_walkSlot6c = g_gate541dd4;
        if (g_gate541dd4 == 0) {
            g_slot54 = g_phaseP1;
            StoreTwoCall(0x4a0680, 0x250);
        }
        AudioInstall2BodyDualSetup();            /* jmp in the original */
        return;
    }

    c = g_slot74 - 1;
    g_slot54 = 7;
    mask = 1u << (c & 31);
    g_slot74 = c;
    g_slot70 = mask;
    g_walkSlot6c = g_selectMask & mask;
    g_selectMask &= mask;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = SHIFT_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = SHIFT_VA + (1u << 24);
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    AudioInstallSelf3StateWithSubcall();
    g_framePauseFlag = 1;
}

/* 0x4a0130 */
void TripleTestInstallJmp_004a0130(void)
{
    unsigned int v = g_slot54;

    g_slot74 = v;
    g_slot78 = v;
    AudioVoiceSequencerCluster();
    if (g_framePauseFlag != 0) return;

    g_walkSlot6c = g_dlMode;
    if (g_dlMode == 0) { AudioStateRemap(); return; }
    g_walkSlot6c = g_guardP1;
    if (g_guardP1 == 0) { AudioStateRemap(); return; }
    g_charP1Alt = g_slot78;
    AudioInstallSelfShiftedChainInit();           /* jmp in the original */
}

/* 0x4a0110 */
void SetOnePairJmp_004a0110(void)
{
    g_walkSlot6c = 1;
    g_activeP1 = 1;
    TripleTestInstallJmp_004a0130();              /* jmp in the original */
}

/* 0x49ff30 - phase 0x12's hand-off */
void AudioMStackPushHandlerPair(void)
{
    unsigned int top, side, entry, slot, w;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_xformEntityIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot54;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_selectSide;

    side = g_slot7c;
    g_xformEntityIdx = g_selectTable;
    g_selectSide = side;
    entry = *(unsigned int *)MK4_PTR((g_selectTable + side) * 4);
    g_xformEntityIdx = entry;
    slot = MK4_NODE_AT(unsigned int, entry, 0x18);
    g_slot54 = slot;
    w = *(unsigned int *)MK4_PTR(slot * 4);
    g_walkSlot6c = w;

    if (w == 0) {
        unsigned int tag;

        if (side == 0) {
            TripleStageRollback(0x22f);
            tag = *MK4_VA(unsigned short, 0x4e2860u);
        } else {
            TripleStageRollback(0x230);
            tag = *MK4_VA(unsigned short, 0x4e2864u);
        }
        TaggedSceneDispatch((int)tag);
        g_walkSlot6c = 1;
        *(unsigned int *)MK4_PTR(g_slot54 * 4) = 1;
    }

    RoundWinTransition();
    if (g_framePauseFlag != 0)
        return;                                  /* mstack leak, as original */

    top = g_matrixStackTop;
    g_selectSide = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot54 = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x4a0060 - the grid controller, installed under tag 0x15 */
void CharSelect_GridP1_004a0060(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {
        g_slot54 = g_phaseP1;
        DualPushSetCallDualPop(0x239);
        if ((g_stateBits8c & 1u) != 0 && g_slot54 == g_phaseP2) {
            MK4_NODE_AT(unsigned int, g_baseSel, 8) = GRID_VA;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
            g_pendingNodeType = 1;
            g_framePauseFlag = 1;
            return;
        }
    }

    g_walkSlot6c = g_dlMode;
    if (g_dlMode == 0) { SetOnePairJmp_004a0110(); return; }
    g_walkSlot6c = g_guardP1;
    if (g_guardP1 == 0) { TripleTestInstallJmp_004a0130(); return; }
    SetOnePairJmp_004a0110();
}

#endif /* NON_MATCHING */
