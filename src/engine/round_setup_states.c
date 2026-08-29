/**
 * The two AppInit_Misc7 states that reach the animation track installer,
 * plus the leaves they need.
 *
 * AppInit_Misc7 (0x464830, 5812b per symbols.yaml) is really a HEAD
 * THUNK of 13 bytes followed by 25 packed state-machine entries. Only
 * the head was converted (app_init_misc7.c); the 25 entries existed
 * natively nowhere, which is why nothing in 0x464xxx-0x465xxx ever
 * dispatched and the track installer - whose only caller in the whole
 * image is one of those entries - never ran.
 *
 * Rather than convert all 25, only the chain that reaches the installer
 * is needed, and it is two entries:
 *
 *   0x465ae0 RoundSetupSpawn (144b): flag the group (bit 2), allocate
 *       the 0x26b node with 0x465c00 as its callback, run the 4-entry
 *       flag dispatcher, allocate a second 0x26b node pointing at
 *       0x455f00, and tail into ArgSarStoreJmp(0x4ea8e8). This is what
 *       installs 0x465c00.
 *
 *   0x465c00 RoundSetupPose (272b): on a non-zero command it stages the
 *       group's x/z into 0x54206c/0x542070 and runs
 *       MStackBracket3PackedSlotInit, then pauses. On command zero - the
 *       first visit - it runs ChainFieldCopyTailJmp, seeds the group's
 *       +0x78 / +0x6c / +0x70 (0x6ccc, 0x7ae, -0.15), queues its own
 *       tagged VA, and CALLS THE TRACK INSTALLER at 0x466fc0.
 *
 * Leaves:
 *   ChainFieldCopyTailJmp (0x466e70, 325b): duplicate a fighter's node
 *       into the group - copy +0x54..+0x68 with the height lowered by
 *       0x9999, flip kind bit 0, carry +0x3c over, clear the child's
 *       +0x30/+0x34/+0x38 - then tail into SetupVecFsmCluster.
 *   FlagThunk4EntryDispatcher (0x40a470, 174b, 4 packed entries): gated
 *       on the byte at 0x4f360c, mstack-push8 / dispatch through the
 *       table at 0x4d5818 / pop8; plus three small tails.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void GuardedSeq_DirtyDoubleDeref_then_ScaledOr4Jmp(void);
extern void AllocNode(void);
extern void ArgSarStoreJmp(int rec);
extern void CallSetPause(void);
extern void MStackBracket3PackedSlotInit(void);
extern void PendingMatch_StackPopDispatchTagged_00466fc0(void);
extern void DirtyDoubleDeref(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPushTwoEntryChainCall(void);
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void SetupVecFsmCluster(void);
extern void MStackPush8(void);
extern void MStackPop8(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void MStackPushCallCallPop_func_00405dd0(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_flag4f360c      (*(unsigned char *)MK4_VA(unsigned char, 0x4f360cu))

void ChainFieldCopyTailJmp(void)
{
    unsigned int src, dst, child;
    int v;

    g_walkSlot6c = 2;
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x24);
    MStackPushDispatchBitGate();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4) != 0) return;
    MStackPushTwoEntryChainCall();
    if (g_framePauseFlag != 0) return;
    MStackCall_MStackPush2ChainPrepend_004062f0();
    if (g_framePauseFlag != 0) return;

    src = g_slot54;
    dst = g_groupHead;
    v = (int)MK4_NODE_AT(unsigned int, src, 0x54);
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, dst, 0x54) = (unsigned int)v;
    v = (int)MK4_NODE_AT(unsigned int, src, 0x58) - 0x9999;
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, dst, 0x58) = (unsigned int)v;
    v = (int)MK4_NODE_AT(unsigned int, src, 0x5c);
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, dst, 0x5c) = (unsigned int)v;
    v = (int)MK4_NODE_AT(unsigned int, src, 0x60);
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, dst, 0x60) = (unsigned int)v;
    v = (int)MK4_NODE_AT(unsigned int, src, 0x64);
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, dst, 0x64) = (unsigned int)v;
    v = (int)MK4_NODE_AT(unsigned int, src, 0x68);
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, dst, 0x68) = (unsigned int)v;
    v = (int)(MK4_NODE_AT(unsigned int, src, 0x34) ^ 1u);
    g_walkSlot6c = (unsigned int)v;
    MK4_NODE_AT(unsigned int, dst, 0x34) = (unsigned int)v;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x3c) =
        MK4_NODE_AT(unsigned int, g_slot54, 0x3c);

    child = MK4_NODE_AT(unsigned int, dst, 0x18);
    g_currentNodeIdx = child;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, child, 0x30) = 0;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) = g_walkSlot6c;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x38) = g_walkSlot6c;
    SetupVecFsmCluster();                /* jmp in the original */
}

void FlagThunk4EntryDispatcher(void)
{
    unsigned int fn;

    if (g_flag4f360c == 0)
        return;
    MStackPush8();
    if (g_framePauseFlag != 0) return;
    g_slot54 = g_groupHead;
    g_currentNodeIdx = (0x4d5818u >> 2) + g_walkSlot6c;
    fn = *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4);
    g_walkSlot6c = fn;
    ((void (*)(void))MK4_ResolveCode(fn))();
    if (g_framePauseFlag != 0) return;
    MStackPop8();                        /* jmp in the original */
}

void FlagThunkTail_0040a4d0(void)
{
    SetJmp_ZeroAndDirty4();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4) != 0) return;
    MStackPushCallCallPop_func_00405dd0();
}

void FlagThunkClear4_0040a4f0(void)
{
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 4) = 0;
}

void FlagThunkClearBit2_0040a510(void)
{
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x20) &= 0xfffffffbu;
}

void RoundSetupSpawn_00465ae0(void)
{
    g_walkSlot6c = 2;
    GuardedSeq_DirtyDoubleDeref_then_ScaledOr4Jmp();
    if (g_framePauseFlag != 0) return;

    g_slot74 = 0x26b;
    g_pendingNodeType = 0x465c00u;       /* the state that installs tracks */
    AllocNode();
    if (g_framePauseFlag != 0) return;

    g_walkSlot6c = 4;
    FlagThunk4EntryDispatcher();
    if (g_framePauseFlag != 0) return;

    g_slot54 = g_groupHead;
    g_slot74 = 0x26b;
    g_pendingNodeType = 0x455f00u;
    AllocNode();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp(0x4ea8e8);            /* tail in the original */
}

void RoundSetupPose_00465c00(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, node, q;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    node = g_groupHead;

    if (cmd != 0) {
        g_walkSlot6c = MK4_NODE_AT(unsigned int, node, 0x54);
        g_slot70 = MK4_NODE_AT(unsigned int, node, 0x5c);
        MStackBracket3PackedSlotInit();
        if (g_framePauseFlag != 0) return;
        CallSetPause();
        return;
    }

    g_slot54 = node;
    ChainFieldCopyTailJmp();
    if (g_framePauseFlag != 0) return;

    node = g_groupHead;
    MK4_NODE_AT(unsigned int, node, 0x78) = 0x6ccc;
    MK4_NODE_AT(unsigned int, node, 0x6c) = 0x7ae;
    g_walkSlot6c = 0xffffd99au;
    MK4_NODE_AT(unsigned int, node, 0x70) = 0xffffd99au;

    MK4_NODE_AT(unsigned int, cam, 8) = 0x465c00u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    q = MK4_NODE_AT(unsigned int, cam, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = 0x465c00u + 0x1000000u;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, cam, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    PendingMatch_StackPopDispatchTagged_00466fc0();
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
