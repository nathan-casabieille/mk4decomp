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

 *   SequencedInit3Call (0x00464190, 173b) - THE one that swaps the screen.
 *     Re-enter the scene, reset the four projection globals, park the title
 *     logo node at (0, -0x1e666, -0x40000) with a zero angle triple, and
 *     load the .geo at 0x50b124 TWICE - the loader's own geometry-then-
 *     texture shape. 0x50b124 is the TOWER's scene; the select's is
 *     0x50b118 next door. With this hollow the tower never loaded and the
 *     select never went away, so the camera flew at the portraits instead -
 *     which is exactly what it looked like.
 *   Init4Globals (0x0042ae10, 36b) - those four globals: 0x20000 into
 *     0x4d5308 / 0x4d530c and 0x10000 into 0x4d5300 / 0x4d5304.
 *
 *   MStackChainPackedDispatch (0x00463c80, 412b) - build the tower's own
 *     node from the template at 0x50c97c: walk it, zero-fill a list slot,
 *     install the sub-node at [+0x18] against the kind read out of
 *     0x5108d0 (shifted down by two, signed), then stamp kind 0x250 and
 *     y 0x6666 on the result and prepend it. Dirty bit 2 after the first
 *     walk means "nothing there", and then it does none of that.
 *
 *   CombatChainWalkExpand (0x00463870, 1026b) - the one that STACKS the
 *     tower. Build the first cell from the record at 0x50cb3c, parent it to
 *     the title logo node, then walk the opponent list at record[+0xc]: for
 *     each entry, build a cell from 0x50cab0, install its sub-node against
 *     the kind out of 0x5108dc, link it under the previous cell through
 *     +0x40, and drop it 0x6978 further down in y. Each cell then unpacks
 *     its FOUR texture slots out of the entry a byte at a time - index by
 *     (v & 0xff) into the table at 0x542a08, shift down 8, four passes -
 *     stamping 0x004baf40 and the slot number into the record at +0x28.
 *     That 0x004baf40 IS called later - it is each cell's per-frame
 *     billboard step, packed inside Helper_TickAlt's symbol, and it needs a
 *     codeptr_extras entry like any other stored callback.
 *   0x004baf40 - the cell billboard. Take the cell's slot number out of the
 *     record at [+0x14], turn it into an angle - slot * 0x1921f, the same
 *     per-cell step MkTowerScreenFsmCluster uses - add the node's own +0x64,
 *     bias by 0x6487 or 0xc90 depending on the node's +0x54, wrap the result
 *     into [0, 0x6487e), and if it lands in the front half (< 0x330cf) clear
 *     the eight draw fields; otherwise park g_currentNodeIdx at -1 so the
 *     walk skips the cell. The two magic-number divides in the original are
 *     a plain modulo by 0x6487e and are written as one.
 *   ZeroEightFields (0x004b8f20, 43b) - those eight fields, 0xab4d9c
 *     through 0xab4db8.
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
extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void InstallSelfDispatch(void);
extern void MStackCall_MStackPush2ChainPrepend_00406390(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackPush4LLWalkPop4(void);
extern void DirtyDoubleDeref(void);
extern void ZeroEightFields(void);
extern void TaggedSceneDispatch(unsigned int tag);
extern void Cmp9DirtyToggle(void);

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
#define g_titleLogoNode2   (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_vsResult53a734b  (*(unsigned int *)MK4_VA(unsigned int, 0x53a734u))
#define g_wait53a350b      (*(unsigned int *)MK4_VA(unsigned int, 0x53a350u))
#define g_proj4d5300       (*(unsigned int *)MK4_VA(unsigned int, 0x4d5300u))
#define g_proj4d5304       (*(unsigned int *)MK4_VA(unsigned int, 0x4d5304u))
#define g_proj4d5308       (*(unsigned int *)MK4_VA(unsigned int, 0x4d5308u))
#define g_proj4d530c       (*(unsigned int *)MK4_VA(unsigned int, 0x4d530cu))
#define g_slot50           (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_selectSide       (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))

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

/* NOT here: PushPopScaledInit343c (0x004aa940) and AudioInstallSelfStatePush
 * (0x004aa8a0). Both transcribe cleanly and both do unblock the download
 * FSM's state 7 - without them it cycles 0 -> 6 -> 0 forever.
 *
 * They no longer crash. Every earlier note here blamed them for crashes and
 * for the pump dispatching packed indices as code; that was wrong. Those were
 * the split-storage globals in MStackPushTableWalk and the MK4_ANIM_PACK gate
 * around Anim_LoadPackFile, both fixed since. On the stable base the two
 * functions run clean on all of seeds 1-8.
 *
 * What they actually do is deterministic: the flow renders the tower, holds
 * it to about frame 1700, then unwinds to the mode-select menu - 207241 px on
 * 8 of 8 seeds, with or without a START press on the tower screen. That reads
 * like the attract-mode timeout, and it may well be correct, but the tower's
 * own confirm is not wired yet so there is nothing to compare it against. Two
 * reasons they stay out until it is: there is no evidence the timeout is
 * right, and the tower gate would drop from 246695 px on 8 of 8 seeds to a
 * frame-1100 snapshot that varies between 244151 and 245357 by seed. Wiring
 * the tower's confirm is what unblocks the question.
 */

/* 0x00462df0 - the tower's settle beat, packed in
 * PendingMatch_SetWalkCurCallPauseDirty. First visit re-arms on a 0x3c-tick
 * beat; every later one asks whether the phase is still 9 and, if so, fires
 * scene tag 0x4e27d8 before releasing. Held back twice on measurements that
 * turned out to be clock-seed noise - re-landed with MK4_SEED pinned. */
void TowerSettleBeat_00462df0(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        Cmp9DirtyToggle();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1u) != 0)
            TaggedSceneDispatch(*MK4_VA(unsigned short, 0x4e27d8u));
        CallSetPause();                          /* tail-jmp in the original */
        return;
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x00462df0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0x3c;
    g_framePauseFlag = 1;
}

/* 0x004b8f20 (43b) */
void ZeroEightFields(void)
{
    unsigned int k;

    for (k = 0; k < 8; k++)
        *MK4_VA(unsigned int, 0xab4d9cu + k * 4u) = 0;
}

/* 0x004baf40 - each tower cell's per-frame billboard step, packed inside
 * Helper_TickAlt's symbol and reached only as a stored callback. */
void TowerCellBillboard_004baf40(void)
{
    unsigned int rec = g_xformEntityIdx;
    unsigned int node = g_slot58;
    unsigned int span = *MK4_VA(unsigned int, 0x543550u);
    unsigned int slot = MK4_NODE_AT(unsigned int, rec, 0x14);
    int a;

    *MK4_VA(unsigned int, 0xab4e60u) = span;
    *MK4_VA(unsigned int, 0xab4e5cu) = (unsigned int)((int)span / 2);
    *MK4_VA(unsigned int, 0xab4e64u) = 2;

    a = (int)(MK4_NODE_AT(unsigned int, node, 0x64) + slot * 0x1921fu);
    a += ((int)MK4_NODE_AT(unsigned int, node, 0x54) >= 0x10000) ? 0x6487 : 0xc90;

    /* wrap into [0, 0x6487e) - the original spells both halves with a
     * reciprocal multiply, and the second as a subtract loop */
    if (a < 0)
        a += (int)((unsigned int)(0x6487d - a) / 0x6487eu) * 0x6487e;
    if (a >= 0x6487e)
        a -= (int)((unsigned int)a / 0x6487eu) * 0x6487e;

    if (a >= 0 && a < 0x330cf) {
        if (*MK4_VA(unsigned int, 0xab4db8u) != 0)
            ZeroEightFields();
        return;
    }
    g_currentNodeIdx = 0xffffffffu;
}

/* 0x00463870 (1026b) - stack the tower */
void CombatChainWalkExpand(void)
{
    unsigned int top, desc, node, sub, v;

    desc = g_pendingNodeType;
    g_slot50 = MK4_NODE_AT(unsigned int, desc, 0xc);   /* the opponent list */
    g_slot7c = 0;
    g_xformEntityIdx = 0x50cb3cu >> 2;
    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) return;

    /* the first cell */
    node = g_currentNodeIdx;
    desc = g_pendingNodeType;
    g_walkSlot6c = MK4_NODE_AT(unsigned int, desc, 4);
    MK4_NODE_AT(unsigned int, node, 0x54) = g_walkSlot6c;
    MK4_NODE_AT(unsigned int, node, 0x58) = g_slot7c;
    g_slot70 = MK4_NODE_AT(unsigned int, desc, 8);
    MK4_NODE_AT(unsigned int, node, 0x5c) = g_slot70;

    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_pendingNodeType;
    g_pendingNodeType = g_titleLogoNode;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = g_titleLogoNode;
    top = g_matrixStackTop;
    g_pendingNodeType = MSTACK_AT(top);
    g_matrixStackTop = top - 1;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x40) = 0;
    MStackCall_MStackPush2ChainPrepend_00406340();
    if (g_framePauseFlag != 0) return;

    g_fightGroupHead = g_currentNodeIdx;
    g_slot7c = g_slot7c - 0x6978u;
    v = *MK4_NODE(unsigned int, g_slot50);
    g_slot50 = g_slot50 + 1u;
    g_slot74 = v;

    while (v != 0) {
        g_xformEntityIdx = 0x50cab0u >> 2;
        DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4u) != 0) return;
        MStackBracket4_ListInsertZeroFill();
        if (g_framePauseFlag != 0) return;
        MStackPush3LinkedListWalk();
        if (g_framePauseFlag != 0) return;

        top = g_matrixStackTop + 1; g_matrixStackTop = top;
        MSTACK_AT(top) = g_currentNodeIdx;
        top = g_matrixStackTop + 1; g_matrixStackTop = top;
        MSTACK_AT(top) = g_pendingNodeType;

        g_pendingNodeType = g_titleLogoNode;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = g_titleLogoNode;
        g_xformEntityIdx = 0x5108dcu >> 2;
        g_xformEntityIdx =
            (unsigned int)((int)*MK4_NODE(unsigned int, 0x5108dcu >> 2) >> 2);
        g_currentNodeIdx = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x18);
        InstallSelfDispatch();
        if (g_framePauseFlag != 0) return;
        g_xformEntityIdx = 0x50a49cu >> 2;
        MStackPush4LLWalkPop4();
        if (g_framePauseFlag != 0) return;

        top = g_matrixStackTop;
        desc = MSTACK_AT(top);
        top--; g_matrixStackTop = top;
        g_pendingNodeType = desc;
        node = MSTACK_AT(top);
        top--; g_matrixStackTop = top;
        g_currentNodeIdx = node;

        g_walkSlot6c = MK4_NODE_AT(unsigned int, desc, 4);
        MK4_NODE_AT(unsigned int, node, 0x54) = g_walkSlot6c;
        MK4_NODE_AT(unsigned int, node, 0x58) = g_slot7c;
        g_slot70 = MK4_NODE_AT(unsigned int, g_pendingNodeType, 8);
        MK4_NODE_AT(unsigned int, node, 0x5c) = g_slot70;
        MK4_NODE_AT(unsigned int, node, 0x40) = g_fightGroupHead;
        MStackCall_MStackPush2ChainPrepend_00406340();
        if (g_framePauseFlag != 0) return;

        g_fightGroupHead = g_currentNodeIdx;
        g_walkSlot6c = 1;
        g_slot70 = 0xff;
        g_slot54 = 0x542a08u >> 2;
        for (;;) {                       /* four texture slots, a byte each */
            unsigned int idx = g_slot74 & g_slot70;

            g_selectSide = idx;
            if (idx > 0x10u)
                return;
            g_slot78 = *MK4_NODE(unsigned int, g_slot54 + idx);
            DirtyDoubleDeref();
            if (g_framePauseFlag != 0) return;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x24) = g_slot78;
            sub = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x28);
            MK4_NODE_AT(unsigned int, sub, 0x10) = 0x004baf40u;
            MK4_NODE_AT(unsigned int, sub, 0x14) = g_walkSlot6c;
            g_slot74 = (unsigned int)((int)g_slot74 >> 8);
            g_walkSlot6c = g_walkSlot6c + 1u;
            if (g_walkSlot6c > 4u)
                break;
        }

        g_slot7c = g_slot7c - 0x6978u;
        v = *MK4_NODE(unsigned int, g_slot50);
        g_slot50 = g_slot50 + 1u;
        g_slot74 = v;
    }

    g_walkSlot6c = *MK4_NODE(unsigned int, g_pendingNodeType);
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x30) = g_walkSlot6c;
}

/* 0x00463c80 (412b) */
void MStackChainPackedDispatch(void)
{
    unsigned int top, node;

    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;
    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_xformEntityIdx;
    top = g_matrixStackTop + 1; g_matrixStackTop = top;
    MSTACK_AT(top) = g_fightGroupHead;

    g_xformEntityIdx = 0x50c97cu >> 2;
    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0)
        return;                       /* mstack left pushed, as in the original */

    if ((g_stateBits8c & 4u) == 0) {
        MStackBracket4_ListInsertZeroFill();
        if (g_framePauseFlag != 0) return;

        top = g_matrixStackTop + 1; g_matrixStackTop = top;
        MSTACK_AT(top) = g_currentNodeIdx;
        top = g_matrixStackTop + 1; g_matrixStackTop = top;
        MSTACK_AT(top) = g_pendingNodeType;

        node = g_currentNodeIdx;
        g_xformEntityIdx = 0x5108d0u >> 2;
        g_xformEntityIdx =
            (unsigned int)((int)*MK4_NODE(unsigned int, 0x5108d0u >> 2) >> 2);
        g_currentNodeIdx = MK4_NODE_AT(unsigned int, node, 0x18);
        InstallSelfDispatch();
        if (g_framePauseFlag != 0) return;

        top = g_matrixStackTop;
        g_pendingNodeType = MSTACK_AT(top);
        top--; g_matrixStackTop = top;
        node = MSTACK_AT(top);
        top--; g_matrixStackTop = top;
        g_currentNodeIdx = node;
        g_walkSlot6c = 0x250;
        MK4_NODE_AT(unsigned int, node, 0x30) = 0x250;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = 0x6666;
        MStackCall_MStackPush2ChainPrepend_00406390();
        if (g_framePauseFlag != 0) return;
        g_slot58 = g_currentNodeIdx;
    }

    top = g_matrixStackTop;
    g_fightGroupHead = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
    g_xformEntityIdx = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
    g_currentNodeIdx = MSTACK_AT(top);
    top--; g_matrixStackTop = top;
}

/* 0x0042ae10 (36b) */
void Init4Globals(void)
{
    g_proj4d5308 = 0x20000;
    g_proj4d530c = 0x20000;
    g_proj4d5300 = 0x10000;
    g_walkSlot6c = 0x10000;
    g_proj4d5304 = 0x10000;
}

/* 0x00464190 (173b) - the screen swap */
void SequencedInit3Call(void)
{
    unsigned int logo;

    BootInitGuardedCallChain();
    if (g_framePauseFlag != 0) return;
    Init4Globals();
    if (g_framePauseFlag != 0) return;

    logo = g_titleLogoNode2;
    g_vsResult53a734b = 0;
    g_currentNodeIdx = logo;
    g_wait53a350b = 0;
    MK4_NODE_AT(unsigned int, logo, 0x54) = 0;
    MK4_NODE_AT(unsigned int, logo, 0x58) = 0xfffe199au;
    MK4_NODE_AT(unsigned int, logo, 0x5c) = 0xfffc0000u;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, logo, 0x60) = 0;
    MK4_NODE_AT(unsigned int, logo, 0x64) = 0;
    MK4_NODE_AT(unsigned int, logo, 0x68) = 0;
    g_walkSlot6c = 0;
    CopyGlobal();
    if (g_framePauseFlag != 0) return;

    /* the TOWER scene, loaded twice - geometry pass then texture pass */
    g_currentNodeIdx = 0x50b124u >> 2;
    LoadGeoAsset_Default();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = 0x50b124u >> 2;
    LoadGeoAsset_Default();
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
