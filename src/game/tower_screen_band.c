/**
 * The TOWER select - the screen the character select hands the frame to
 * once a fighter is confirmed - and the six list walkers that build it.
 *
 * The 0x00462xxx cluster this sits under is the tower screen, not a "VS"
 * screen: MkTowerScreenFsmCluster carries its packed controllers, its input
 * repeater runs over the cell table at 0x4ea518, and its state 0 asks
 * PlayerCharSelector to commit the chosen fighter before it builds anything.
 *
 * Everything here reads the same three globals, so they are worth naming
 * once: g_ladderIdx (0x541fb0) is the tower cell, g_chainBase541fb8 the
 * per-cell record table, and g_ladderState (0x53a3c0) how far up the tower
 * we are.
 *
 *   BitShiftExtract (0x00464090, 250b) - pull the character id for the
 *     current cell out of a PACKED record. The cell's list at [+0xc] is
 *     indexed by ladderState - 1, and the dword there holds several ids a
 *     byte apart: one is shifted down by ((counter - 2) & 3) * 8 into
 *     0x535d10, the other by (counter * 8) & 31 into the work slot. Both
 *     shifts are ARITHMETIC, and the second needs the x86 shift-count mask
 *     spelled out - C leaves a shift past the width undefined.
 *   PlayerCharSelector (0x004636d0, 309b) - commit that id for whichever
 *     player is still active and download them. Two symmetric halves; each
 *     maps 0xf ("random", when both the stored and the fresh id read 0xf) to
 *     6, and stamps the costume id for the three special cases 6, 8 and 0xf.
 *   MStackChainOrBitLoop (0x004635a0, 291b) and MStackPush2ScaledChainLoop
 *     (0x00463430, 355b) - the same walk twice: find the cell's node, size
 *     it with the countdown, then point every node in the +0x40 chain at a
 *     parent through +0x3c. The first parents them to the title logo node;
 *     the second parents them to the select camera and gives that camera the
 *     position triple, z pulled back by 0x38000.
 *   PackedTableWalkChainStore (0x00463e20, 166b) - read the cell's 3-dword
 *     record at 0x4ea670 + cell * 12 and park z at 0x14000.
 *   MStackChainCountdownLoop (0x00463fb0, 220b) - turn the cell list's
 *     length into a y offset: 0xffff9688 stepped down by 0x6978 per entry
 *     past the first.
 *   PoseFnInstallDualCluster (0x00463090) with its sibling 0x00463220 and
 *     Push0_Push463220_Jmp (0x00463070) - seed a node's transform block from
 *     all of the above and chain into PendingMatch_ThreeMul10Stores.
 *
 *   MkTowerScreenFsmCluster (0x00462560, its own 240b in front of the two
 *     packed controllers) - the tower's ROTATION pass: find the cell's node
 *     and give every node in its +0x40 chain the same +0x64 angle,
 *     0xfffe6de1 stepped by -0x1921f per cell already climbed.
 *   StoreCallPauseCmpDirty (0x00464240, 60b) - dirty bit 0 = "the tower is
 *     taller than the cell list is long", i.e. we are past the top.
 *   DirtyBitToggleDispatch (0x00463390, 150b) - look the active player's
 *     character up in the table at 0x542a08, run the scaled store, and on a
 *     miss prepend a fresh 0x26d node. Dirty bit 2 reports "nothing there".
 *

 * STILL held back, and now for a MEASURED reason rather than a guess:
 * 0x00462df0 (the tower's settle beat) and AudioInstallSelfStatePush
 * (0x004aa8a0). Both transcribe cleanly and both carry the flow past the
 * download FSM's state 7 into Screen_ArcadeEnding - and there
 * MatchInitMonsterChain hunts the record registry at 0x543200, which is
 * EMPTY on this path. MStackPushTableWalk's scan is unbounded by design (the
 * original assumes the record is there), so it walks off and faults. With
 * them in: the confirm path survives 1 run in 4 and MK4_BOOT_MATCH drops
 * from 10/10 to 3/4. MK4_TRACE_TBLWALK prints the registry head and the
 * record kind each walk hunts; nothing in the binary writes 0x543200 as an
 * immediate, so the registrar reaches it through a packed pointer and
 * finding it is the next job.
 *
 * ORDER MATTERS, and it cost a revert last time: the pose cluster CONSUMES
 * what these walkers produce, so landing it while they were still weak
 * no-ops made it deref a zero index. Producers first.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void StackPopDispatchTagged(void);
extern void CallSetPause(void);
extern void StoreTwoCall(int fn, int tag);
extern void FixedDiv16(void);
extern void SaveCallRestore(int tag);
extern void SaveCallRestoreOrXor(int tag);
extern void PendingMatch_ThreeMul10Stores(void);
extern void MStackPush2LLWalkCompare(void);
extern void MStackPushSearchLoop(void);
extern void Push70CallScaleArith(void);
extern void DownloadPlayerChar(void);
extern void Thunk_BootMod6487eClampAndChainMul10(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_slot54           (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58           (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c       (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70           (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74           (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78           (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c           (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_stateBits8c      (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_titleLogoNode    (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_selectCam        (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))
#define g_activeP1         (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2         (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_charIdP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_charIdP2         (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_costumeId        (*(unsigned int *)MK4_VA(unsigned int, 0x535d10u))
#define g_costumeMirror    (*(unsigned int *)MK4_VA(unsigned int, 0x535d5cu))
#define g_costumeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a178u))
#define g_costumeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x53a250u))
#define g_clear541ec4      (*(unsigned int *)MK4_VA(unsigned int, 0x541ec4u))
#define g_clear541ec8      (*(unsigned int *)MK4_VA(unsigned int, 0x541ec8u))
#define g_ladderIdx        (*(unsigned int *)MK4_VA(unsigned int, 0x541fb0u))
#define g_chainBase541fb4  (*(unsigned int *)MK4_VA(unsigned int, 0x541fb4u))
#define g_chainBase541fb8  (*(unsigned int *)MK4_VA(unsigned int, 0x541fb8u))
#define g_ladderState      (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))

#define MSTACK_AT(i) (*(unsigned int *)MK4_PTR((i) * 4u))

/* 0x00464090 (250b) */
void BitShiftExtract(void)
{
    unsigned int top, entry, elem, slot, counter;
    int packed, other;

    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_slot70;
    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;

    g_slot70 = 4;
    g_walkSlot6c = g_ladderIdx << 2;
    entry = (g_ladderIdx << 2) + g_chainBase541fb8;
    g_currentNodeIdx = entry;
    elem = MK4_NODE_AT(unsigned int, entry, 0xc);
    g_walkSlot6c = g_ladderState - 1u;
    elem = elem + (g_ladderState - 1u);
    g_currentNodeIdx = elem;
    packed = (int)*MK4_NODE(unsigned int, elem);
    slot = g_ladderIdx + g_chainBase541fb4;
    g_slot70 = (unsigned int)packed;
    g_currentNodeIdx = slot;
    counter = *MK4_NODE(unsigned int, slot);

    /* two ids a byte apart, both pulled out with an ARITHMETIC shift; the
     * second count is masked to 5 bits the way the hardware does it */
    other = packed >> (((counter - 2u) & 3u) * 8u);
    packed = packed >> ((counter * 8u) & 31u);
    other &= 0xff;
    g_costumeMirror = (unsigned int)other;
    g_costumeId = (unsigned int)other;
    packed &= 0xff;
    g_slot70 = (unsigned int)packed;
    g_walkSlot6c = (unsigned int)packed;

    top = g_matrixStackTop;
    g_currentNodeIdx = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
    g_slot70 = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
}

/* the id fix-up both halves of PlayerCharSelector share */
static unsigned int tower_pick_id(unsigned int stored)
{
    unsigned int id = g_walkSlot6c;

    if (stored == 0xf && id == 0xf) {            /* both random -> 6 */
        id = 6;
        g_walkSlot6c = 6;
    }
    if (id == 6)  g_costumeId = 8;
    if (id == 0xf) g_costumeId = 0xe;
    if (id == 8)  g_costumeId = 0xa;
    return id;
}

/* 0x004636d0 (309b) */
void PlayerCharSelector(void)
{
    unsigned int id;

    BitShiftExtract();
    if (g_framePauseFlag != 0)
        return;

    if (g_activeP1 == 0) {                       /* 0x4636f1 - player one */
        g_clear541ec4 = 0;
        id = tower_pick_id(g_charIdP2);
        g_charIdP1 = id;
        g_costumeP1 = g_costumeId;
        g_slot54 = 0x535cfcu >> 2;
        g_slot70 = 0;
        DownloadPlayerChar();
        return;
    }

    g_clear541ec8 = 0;                           /* 0x463771 - player two */
    id = tower_pick_id(g_charIdP1);
    g_charIdP2 = id;
    g_costumeP2 = g_costumeId;
    g_slot54 = 0x53a1d0u >> 2;
    g_slot70 = 1;
    DownloadPlayerChar();
    if (g_framePauseFlag != 0)
        return;
    g_walkSlot6c = 0;
    g_activeP2 = 0;
}

/* 0x00463e20 (166b) */
void PackedTableWalkChainStore(void)
{
    unsigned int rec;

    SaveCallRestore(0x26f);
    g_walkSlot6c = g_ladderIdx * 3u;
    rec = (0x4ea670u >> 2) + g_ladderIdx * 3u;
    g_currentNodeIdx = rec;
    g_xformEntityIdx = *MK4_NODE(unsigned int, rec);
    g_currentNodeIdx = rec + 1u;
    g_slot78 = *MK4_NODE(unsigned int, rec + 1u);
    g_currentNodeIdx = rec + 2u;
    g_slot7c = *MK4_NODE(unsigned int, rec + 2u);
    g_currentNodeIdx = rec + 3u;
    g_walkSlot6c = 0x26f;
    g_slot70 = 4;
    Push70CallScaleArith();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) return;
    g_walkSlot6c = 0x14000;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x14000;
}

/* 0x00463fb0 (220b) */
void MStackChainCountdownLoop(void)
{
    unsigned int top, n, entry, v;

    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;

    g_slot74 = g_walkSlot6c;
    MStackPushSearchLoop();
    if (g_framePauseFlag != 0)
        return;                       /* the mstack stays pushed, as in the original */

    n = g_slot74;
    if (g_walkSlot6c < n) {           /* unsigned min */
        n = g_walkSlot6c;
        g_slot74 = n;
    }
    g_walkSlot6c = g_ladderIdx << 2;
    g_slot70 = 4;
    entry = g_chainBase541fb8 + (g_ladderIdx << 2);
    g_currentNodeIdx = entry;
    g_slot70 = MK4_NODE_AT(unsigned int, entry, 4);

    if (n == 0)
        n = 1;
    n = n - 1u;
    v = 0xffff9688u;
    g_slot74 = v;
    g_walkSlot6c = n;
    if (n != 0) {
        do {
            v -= 0x6978u;
            n--;
        } while (n != 0);
        g_walkSlot6c = n;             /* zero by construction */
        g_slot74 = v;
    }
    g_slot78 = MK4_NODE_AT(unsigned int, entry, 8);

    top = g_matrixStackTop;
    g_currentNodeIdx = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
}

/* the body MStackChainOrBitLoop and MStackPush2ScaledChainLoop share: find
 * the cell's node, size it, then point the whole +0x40 chain at `parent`
 * through +0x3c.  parentIsCam picks which of the two the caller wants and
 * whether the camera gets the position triple. */
static void tower_chain_reparent(int parentIsCam)
{
    unsigned int top, entry, node, parent;

    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;
    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_xformEntityIdx;

    g_walkSlot6c = g_ladderIdx << 2;
    entry = (g_ladderIdx << 2) + g_chainBase541fb8;
    g_currentNodeIdx = entry;
    g_walkSlot6c = *MK4_NODE(unsigned int, entry);
    MStackPush2LLWalkCompare();
    if (g_framePauseFlag != 0)
        return;                       /* mstack left pushed, as in the original */
    if ((g_stateBits8c & 4u) != 0)
        goto pop;
    MStackPushSearchLoop();
    if (g_framePauseFlag != 0) return;
    MStackChainCountdownLoop();
    if (g_framePauseFlag != 0) return;

    if (parentIsCam) {
        parent = g_selectCam;
        g_xformEntityIdx = parent;
        g_slot74 = (unsigned int)((int)g_slot74 >> 1);
        MK4_NODE_AT(unsigned int, parent, 0x54) = g_slot70;
        MK4_NODE_AT(unsigned int, parent, 0x58) = g_slot74;
        g_slot78 = g_slot78 - 0x38000u;
        MK4_NODE_AT(unsigned int, parent, 0x5c) = g_slot78;
    } else {
        g_slot74 = (unsigned int)((int)g_slot74 >> 1);
        g_xformEntityIdx = g_titleLogoNode;
    }

    for (;;) {
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = g_xformEntityIdx;
        node = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x40);
        g_stateBits8c |= 4u;
        g_currentNodeIdx = node;
        if (node == 0)
            break;
        g_stateBits8c ^= 4u;
    }

pop:
    top = g_matrixStackTop;
    g_xformEntityIdx = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
    g_currentNodeIdx = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
}

/* 0x004635a0 (291b) - parent to the title logo node */
void MStackChainOrBitLoop(void)
{
    tower_chain_reparent(0);
}

/* 0x00463430 (355b) - parent to the select camera, and place it */
void MStackPush2ScaledChainLoop(void)
{
    tower_chain_reparent(1);
}

/* 0x00464240 (60b) */
void StoreCallPauseCmpDirty(void)
{
    g_slot70 = g_ladderState;
    MStackPushSearchLoop();
    if (g_framePauseFlag != 0)
        return;
    if (g_slot70 > g_walkSlot6c)             /* unsigned */
        g_stateBits8c |= 1u;
    else
        g_stateBits8c &= ~1u;
}

/* 0x00463390 (150b) */
void DirtyBitToggleDispatch(void)
{
    unsigned int id = (g_activeP1 == 1) ? g_charIdP1 : g_charIdP2;
    unsigned int p;

    g_walkSlot6c = id;
    p = (0x542a08u >> 2) + id;
    g_currentNodeIdx = p;
    g_xformEntityIdx = *MK4_NODE(unsigned int, p);
    DispatcherComplex260_FramePauseScaledStore();
    if (g_framePauseFlag != 0)
        return;
    if ((g_stateBits8c & 4u) == 0) {
        g_walkSlot6c = 0x26d;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x26d;
        MStackCall_MStackPush2ChainPrepend_00406340();
        if (g_framePauseFlag != 0)
            return;
    }
    g_stateBits8c |= 4u;
    if (g_currentNodeIdx != 0)
        g_stateBits8c ^= 4u;
}

/* 0x00462560 (240b of its own) - the tower's rotation pass */
void MkTowerScreenFsmCluster(void)
{
    unsigned int slot, entry, n, node;
    unsigned int v;

    slot = g_chainBase541fb4 + g_ladderIdx;
    g_currentNodeIdx = slot;
    n = *MK4_NODE(unsigned int, slot);
    g_slot70 = n;
    if (n == 0)
        return;

    g_walkSlot6c = g_ladderIdx << 2;
    entry = (g_ladderIdx << 2) + g_chainBase541fb8;
    g_pendingNodeType = entry;
    g_walkSlot6c = *MK4_NODE(unsigned int, entry);
    MStackPush2LLWalkCompare();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) return;

    n = n - 1u;
    v = 0xfffe6de1u;
    g_walkSlot6c = v;
    g_slot70 = n;
    if (n != 0) {
        do {
            v -= 0x1921fu;
            n--;
        } while (n != 0);
        g_slot70 = n;                        /* zero by construction */
        g_walkSlot6c = v;
    }
    Thunk_BootMod6487eClampAndChainMul10();
    if (g_framePauseFlag != 0) return;

    for (;;) {
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x64) = g_walkSlot6c;
        node = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x40);
        g_stateBits8c |= 4u;
        g_currentNodeIdx = node;
        if (node == 0)
            return;
        g_stateBits8c ^= 4u;
    }
}

/* the tail both pose bodies share: chain state 1 against their OWN VA */
static void pose_chain1(unsigned int selfVA)
{
    unsigned int v;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = selfVA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = v;
    *MK4_NODE(unsigned int, v) = selfVA + (1u << 24);
    g_currentNodeIdx = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    PendingMatch_ThreeMul10Stores();
    g_framePauseFlag = 1;
}

/* 0x00463090 */
void PoseFnInstallDualCluster(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int logo;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        StackPopDispatchTagged();
        return;
    }

    MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = g_slot58;
    g_walkSlot6c = g_slot54;
    MStackChainCountdownLoop();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = g_slot70;
    g_walkSlot6c = 0x6978;
    g_slot70 = 0x20000;
    FixedDiv16();
    if (g_framePauseFlag != 0) return;
    g_slot74 = g_slot74 - g_walkSlot6c;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = g_slot74;
    g_walkSlot6c = 0;
    MStackChainCountdownLoop();
    if (g_framePauseFlag != 0) return;
    g_slot78 = g_slot78 - 0x20000u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) = g_slot78;

    logo = g_titleLogoNode;
    g_fightGroupHead = logo;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x40) =
        MK4_NODE_AT(unsigned int, logo, 0x60);
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = 0;
    g_walkSlot6c = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x68);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x48) = g_walkSlot6c;

    pose_chain1(0x00463090u);
}

/* 0x00463220 - the sibling, against the CURRENT node */
void PoseFnInstallCurrent_00463220(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        CallSetPause();
        return;
    }

    MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = g_slot58;
    SaveCallRestoreOrXor(0x26d);
    if ((g_stateBits8c & 4u) != 0) {             /* bit 2 set = not found */
        CallSetPause();
        return;
    }

    g_fightGroupHead = g_currentNodeIdx;
    g_walkSlot6c = g_slot54;
    MStackChainCountdownLoop();
    if (g_framePauseFlag != 0) return;
    g_slot70 = g_slot70 - 0x3d70u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = g_slot70;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = g_slot74;
    g_slot78 = g_slot78 - 0x51eu;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) = g_slot78;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x40) =
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x60);
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = 0;
    g_walkSlot6c = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x68);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x48) = g_walkSlot6c;

    pose_chain1(0x00463220u);
}

/* 0x00463070 (20b) */
void Push0_Push463220_Jmp(void)
{
    StoreTwoCall(0x00463220, 0);
    PoseFnInstallDualCluster();                  /* tail-jmp in the original */
}

#endif /* NON_MATCHING */
