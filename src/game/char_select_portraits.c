/**
 * The character-select screen's PORTRAIT layer: RoundWinTransition
 * (0x49e7e0) and the four helpers under it. This is what puts each player's
 * fighter into the scene once that player is at state 2.
 *
 *   RoundWinTransition (0x49e7e0) - twice, once per player, under an mstack
 *     save of currentNodeIdx and xformEntityIdx. For each player at 2 whose
 *     own tag (0x15 / 0x16) is NOT already in the chain: SaveCallRestore(7 or
 *     8), then DualGuardStateMachine (or its P2 twin), a gate on 0x541dd4 /
 *     0x53a2e8, DoubleIndirectFourWaySelect to pick the descriptor, the
 *     spawn, kind 7 or 8, the chain insert, ThrowFlowSetupCluster on that
 *     player's phase word, and SetWalkCurCallPauseDirty(0x49ee30, 0x22f or
 *     0x230) for the portrait animator.
 *   DualGuardStateMachine (0x49ea30) / _SaveCallRestore (0x49eb20) - the
 *     same body against 0x53a1bc + tag 0x266 + table slot 0 for P1, and
 *     0x53a354 + tag 0x267 + table slot 1 for P2. With g_dlMode clear, or
 *     that player's guard word set, they just run the save-call-restore;
 *     otherwise, and only when the tag is absent, they spawn the node from
 *     the table entry's +0x28, mark it with the tag as its kind, run
 *     ThrowFlowSetupCluster and park z at 0x28f.
 *   DoubleIndirectFourWaySelect (0x49ec00) - the descriptor pick. Two
 *     dereferences off the table at 0x541fc0 give a first word and the word
 *     at +0x40; the first decides high (8/0xa) or low (0xc/0xe) against
 *     0xf, the second picks within the pair, and g_slot70 offsets the
 *     result. Both the node index and 0x535e48 are mstack-saved.
 *   ThrowFlowSetupCluster (0x49ed00) - copy the source node's +0x30/+0x34
 *     into the target's +0x54/+0x58 and set +0x5c from slot74, which is 0
 *     below 0x10 and 0xffffcccd above it. Saves slot74, xformEntityIdx and
 *     fightGroupHead.
 *   SaveCallRestoreOrXor (0x404a00) - probe one tag and report the result in
 *     dirty bit 2, SET meaning NOT found; walkSlot6c is restored either way.
 *
 * Still hollow: the portrait animator at 0x49ee30 (packed inside
 * ThrowFlowSetupCluster's symbol) and the two cursor steps GameNetSyncState
 * (0x49fb70) and AudioCmpCascadeDispatcher (0x49fd50).
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush2LLWalkCompare(void);
extern void SaveCallRestore(int arg);
extern void Wrapper_SaveCallRestore(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void MStackCall_MStackPush2ChainInsert_004062a0(void);
extern void DirtyDoubleDeref(void);
extern void DualPushSetCallDualPop(unsigned int tag);
extern void SetWalkCurCallPauseDirty(unsigned int callback, unsigned int tag);
extern void CallSetPause(void);
extern void DoubleIndirectFourWaySelect(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_dlMode          (*(unsigned int *)MK4_VA(unsigned int, 0x542004u))
#define g_phaseP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f88u))
#define g_phaseP2         (*(unsigned int *)MK4_VA(unsigned int, 0x537e90u))
#define g_selectTable     (*(unsigned int *)MK4_VA(unsigned int, 0x541fc0u))
#define g_selectSide      (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))

#define ANIM_VA 0x49ee30u
#define BLINK_VA ANIM_VA

/* 0x404a00 - probe a tag; dirty bit 2 SET means the tag is NOT in the chain */
void SaveCallRestoreOrXor(unsigned int tag)
{
    unsigned int saved = g_walkSlot6c;

    g_walkSlot6c = tag;
    MStackPush2LLWalkCompare();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = saved;
    g_stateBits8c |= 4;
    if (g_currentNodeIdx != 0)
        g_stateBits8c &= ~4u;
}

/* 0x49ed00 */
void ThrowFlowSetupCluster(void)
{
    unsigned int top, src, dst, v;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot74;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_xformEntityIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_fightGroupHead;

    SaveCallRestoreOrXor(6);
    g_fightGroupHead = g_currentNodeIdx;
    if (g_walkSlot6c < 0x10u) {
        g_slot74 = 0;
    } else {
        unsigned int v6c = g_walkSlot6c + 0x10;

        g_slot74 = 0xffffcccdu;
        g_slot70 = v6c;
        g_walkSlot6c = v6c;
    }

    DirtyDoubleDeref();
    if (g_framePauseFlag != 0)
        return;                                  /* mstack leak, as original */

    src = g_currentNodeIdx;
    dst = g_xformEntityIdx;
    v = MK4_NODE_AT(unsigned int, src, 0x30);
    g_slot70 = v;
    MK4_NODE_AT(unsigned int, dst, 0x54) = v;
    v = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34);
    g_slot70 = v;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x58) = v;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x5c) = g_slot74;

    top = g_matrixStackTop;
    g_fightGroupHead = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot74 = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x49ec00 */
void DoubleIndirectFourWaySelect(void)
{
    unsigned int top, base, entry, first, second, pick;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_selectSide;

    base = g_selectTable;
    g_xformEntityIdx = base;
    g_selectSide = g_walkSlot6c;

    entry = *(unsigned int *)MK4_PTR((base + g_walkSlot6c) * 4);
    g_xformEntityIdx = entry;

    first = *(unsigned int *)MK4_PTR(entry * 4);
    g_currentNodeIdx = first;
    first = *(unsigned int *)MK4_PTR(first * 4);
    g_walkSlot6c = first;

    second = MK4_NODE_AT(unsigned int, entry, 0x40);
    g_currentNodeIdx = second;
    second = *(unsigned int *)MK4_PTR(second * 4);
    g_walkSlot6c = second;

    if (first > 0xfu)
        pick = second ? 0xe : 0xc;
    else
        pick = second ? 0xa : 8;

    pick += g_slot70;
    g_selectSide = pick;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR((entry + pick) * 4);

    top = g_matrixStackTop;
    g_selectSide = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* the shared body of the two guards */
static void cs_guard(unsigned int tag, unsigned int tableOff,
                     unsigned int phaseKey)
{
    unsigned int entry;

    SaveCallRestoreOrXor(tag);
    if ((g_stateBits8c & 4u) == 0)
        return;                                  /* already there */

    entry = g_selectTable;
    g_currentNodeIdx = entry;
    entry = *(unsigned int *)MK4_PTR(entry * 4 + tableOff);
    g_currentNodeIdx = entry;
    g_xformEntityIdx = MK4_NODE_AT(unsigned int, entry, 0x28);

    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) return;
    MStackCall_MStackPush2ChainInsert_004062a0();
    if (g_framePauseFlag != 0) return;

    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = tag;
    g_xformEntityIdx = g_currentNodeIdx;
    g_walkSlot6c = phaseKey;
    ThrowFlowSetupCluster();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0x28f;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x5c) = 0x28f;
}

/* 0x49ea30 - P1 */
void DualGuardStateMachine(void)
{
    g_walkSlot6c = g_dlMode;
    if (g_dlMode == 0) {
        SaveCallRestore(0x266);
        return;
    }
    g_walkSlot6c = *MK4_VA(unsigned int, 0x53a1bcu);
    if (*MK4_VA(unsigned int, 0x53a1bcu) != 0) {
        SaveCallRestore(0x266);
        return;
    }
    cs_guard(0x266, 0, 2);
}

/* 0x49eb20 - P2 */
void DualGuardStateMachine_SaveCallRestore(void)
{
    g_walkSlot6c = g_dlMode;
    if (g_dlMode == 0) {
        Wrapper_SaveCallRestore();               /* jmp in the original */
        return;
    }
    g_walkSlot6c = *MK4_VA(unsigned int, 0x53a354u);
    if (*MK4_VA(unsigned int, 0x53a354u) != 0) {
        SaveCallRestore(0x267);
        return;
    }
    cs_guard(0x267, 4, 4);
}

/* 0x49e7e0 */
void RoundWinTransition(void)
{
    unsigned int top;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_xformEntityIdx;

    g_walkSlot6c = g_activeP1;
    if (g_activeP1 == 2) {
        DualPushSetCallDualPop(0x15);
        if ((g_stateBits8c & 1u) == 0) {
            SaveCallRestore(7);
            DualGuardStateMachine();
            if (g_framePauseFlag != 0) return;   /* mstack leak, as original */
            if (*MK4_VA(unsigned int, 0x541dd4u) == 0) {
                g_walkSlot6c = 0;
                g_slot70 = 0;
                DoubleIndirectFourWaySelect();
                if (g_framePauseFlag != 0) return;
                DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
                if (g_framePauseFlag != 0) return;
                if ((g_stateBits8c & 4u) == 0) {
                    g_walkSlot6c = 7;
                    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 7;
                    g_xformEntityIdx = g_currentNodeIdx;
                    MStackCall_MStackPush2ChainInsert_004062a0();
                    if (g_framePauseFlag != 0) return;
                    g_walkSlot6c = g_phaseP1;
                    ThrowFlowSetupCluster();
                    if (g_framePauseFlag != 0) return;
                    SetWalkCurCallPauseDirty(ANIM_VA, 0x22f);
                }
            }
        }
    }

    g_walkSlot6c = g_activeP2;
    if (g_activeP2 == 2) {
        DualPushSetCallDualPop(0x16);
        if ((g_stateBits8c & 1u) == 0) {
            SaveCallRestore(8);
            DualGuardStateMachine_SaveCallRestore();
            if (g_framePauseFlag != 0) return;
            g_walkSlot6c = *MK4_VA(unsigned int, 0x53a2e8u);
            if (*MK4_VA(unsigned int, 0x53a2e8u) == 0) {
                g_walkSlot6c = 1;
                g_slot70 = 0;
                DoubleIndirectFourWaySelect();
                if (g_framePauseFlag != 0) return;
                DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
                if (g_framePauseFlag != 0) return;
                if ((g_stateBits8c & 4u) == 0) {
                    g_walkSlot6c = 8;
                    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 8;
                    g_xformEntityIdx = g_currentNodeIdx;
                    MStackCall_MStackPush2ChainInsert_004062a0();
                    if (g_framePauseFlag != 0) return;
                    g_walkSlot6c = g_phaseP2;
                    ThrowFlowSetupCluster();
                    if (g_framePauseFlag != 0) return;
                    SetWalkCurCallPauseDirty(ANIM_VA, 0x230);
                }
            }
        }
    }

    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x49ee30 - the portrait BLINKER, packed inside ThrowFlowSetupCluster's
 * symbol and installed by RoundWinTransition under tag 0x22f (P1) or 0x230
 * (P2), so it is reached only by VA.
 *
 * Two states that flip g_fightGroupHead between 0 and 1 and, for each,
 * pick a descriptor through DoubleIndirectFourWaySelect and write it into
 * the node's child at +0x18, slot +0x24 - i.e. it alternates the selected
 * portrait's mesh on a 4-tick beat, which is the flash under the cursor.
 * Command 0 only starts it when the controller's own tag (+0xc) is 0x22f;
 * the 0x230 instance falls straight into the second half. */
void CharSelect_PortraitBlink_0049ee30(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int side, child;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {
        unsigned int tag = MK4_NODE_AT(unsigned int, g_baseSel, 0xc);

        g_fightGroupHead = 0;
        g_walkSlot6c = tag;
        if (tag != 0x22f)
            goto half_b;
    } else {
        g_fightGroupHead ^= 1u;
        if (cmd == 1)
            goto half_b;
    }

    /* 0x49ee92 */
    SaveCallRestoreOrXor(7);
    if ((g_stateBits8c & 4u) != 0) { CallSetPause(); return; }
    side  = g_fightGroupHead;
    child = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x18);
    g_walkSlot6c = 0;
    g_slot70 = side;
    g_currentNodeIdx = child;
    DoubleIndirectFourWaySelect();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x24) = g_xformEntityIdx;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = BLINK_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
    g_pendingNodeType = 4;
    g_framePauseFlag = 1;
    return;

half_b:                                          /* 0x49ef11 */
    SaveCallRestoreOrXor(8);
    if ((g_stateBits8c & 4u) != 0) { CallSetPause(); return; }
    side  = g_fightGroupHead;
    child = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x18);
    g_walkSlot6c = 1;
    g_slot70 = side;
    g_currentNodeIdx = child;
    DoubleIndirectFourWaySelect();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x24) = g_xformEntityIdx;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = BLINK_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 4;
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
