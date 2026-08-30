/**
 * Phase4StateInit4Helpers (0x4130c0, 661b, four packed blocks) - the
 * per-bone EFFECT TICKS the skeleton template installs, and the code
 * that finally writes a GROUP POSITION from a resolved record:
 *
 *   0x4130c0 (head): ChainDirtyBitWalker to find the record, resolve the
 *       static template 0x4d6758 through PushSetXfmMaskCallPop, then
 *       group+0x30 = 0x98 and GROUP +0x54/+0x58/+0x5c = the record's
 *       +0x3c/+0x44 - the position install this whole hunt was for -
 *       followed by ThreeChanPackClamp(0x100020), CopyThreeFields(group),
 *       and the track-record arm: +0x48 = 0xa666, flags |= 8,
 *       +0x14 = 0xff, +0x10 = 0x4131f0 (the fade tick), prepend.
 *   0x4131f0: ClampMulShiftStore, then unless 0x543800 is up,
 *       entity+0x14 -= 0x16 - the fade-out counter.
 *   0x413230 (the VA the skeleton template carries): zero-init bracket,
 *       prepend, MStackPushNegMul10(0xccc) into group +0x6c / +0x74
 *       (launch velocities), child+0x20 |= 0x40, then the record arm:
 *       +0x48 = 0x3333, flags |= 0xa, +0x2c = 0x26666, +0x14 = 0xff,
 *       +0x10 = 0x413310, CallSetPause.
 *   0x413310: unless 0x543800, entity+0x48 -= 0x147 (gravity) and
 *       ChainListVecAdd; then ClampMulShiftStore.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void ChainDirtyBitWalker(void);
extern void PushSetXfmMaskCallPop(void);
extern void ThreeChanPackClamp(int arg);
extern void CopyThreeFields(int group);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void MStackPushZeroCallPop(void);
extern void MStackPushNegMul10(void);
extern void ChainListVecAdd(void);
extern void ClampMulShiftStore(void);
extern void CallSetPause(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCur    (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_gate543800       (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))

#define W(i)               (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define NODE_W(n,off)      MK4_NODE_AT(unsigned int, (n), (off))

void Phase4BoneFade_004131f0(void)
{
    ClampMulShiftStore();
    if (g_framePauseFlag != 0) return;
    if (g_gate543800 != 0) return;
    {
        unsigned int ent = g_xformEntityIdx;
        unsigned int v = NODE_W(ent, 0x14) - 0x16u;

        g_walkCallback = v;
        NODE_W(ent, 0x14) = v;
    }
}

void Phase4StateInit4Helpers(void)
{
    unsigned int group, rec, child, rec2;

    ChainDirtyBitWalker();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4u) != 0)
        goto pop_group;

    g_pendingNodeType = g_xformEntityIdx;
    g_walkCallback = 0x4d6758u >> 2;
    PushSetXfmMaskCallPop();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4u) != 0)
        goto pop_group;

    group = g_fightGroupHead;
    rec = g_pendingNodeType;
    g_walkCallback = 0x98u;
    NODE_W(group, 0x30) = 0x98u;
    g_walkCallback = NODE_W(rec, 0x3c);
    NODE_W(group, 0x54) = g_walkCallback;
    g_walkCallback = NODE_W(rec, 0x40);
    NODE_W(group, 0x58) = g_walkCallback;
    g_walkCallback = NODE_W(rec, 0x44);
    NODE_W(group, 0x5c) = g_walkCallback;
    g_currentNodeIdx = NODE_W(group, 0x18);
    ThreeChanPackClamp(0x100020);
    CopyThreeFields((int)g_fightGroupHead);

    child = g_currentNodeIdx;
    rec2 = NODE_W(child, 0x28);
    g_xformEntityIdx = rec2;
    NODE_W(rec2, 0x48) = 0xa666u;
    W(rec2) |= 8u;
    NODE_W(rec2, 0x14) = 0xffu;
    g_walkCallback = 0x4131f0u;
    NODE_W(rec2, 0x10) = 0x4131f0u;
    g_currentNodeIdx = g_fightGroupHead;
    MStackCall_MStackPush2ChainPrepend_00406600();
    if (g_framePauseFlag != 0) return;

pop_group:
    {
        unsigned int top = g_matrixStackTop;

        g_fightGroupHead = W(top);
        g_matrixStackTop = top - 1;
    }
}

void Phase4BoneLaunch_00413230(void)
{
    unsigned int group, child, rec;

    g_currentNodeIdx = g_fightGroupHead;
    MStackPushZeroCallPop();
    if (g_framePauseFlag != 0) return;
    MStackCall_MStackPush2ChainPrepend_00406600();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = 0xcccu;
    MStackPushNegMul10();
    if (g_framePauseFlag != 0) return;

    group = g_fightGroupHead;
    NODE_W(group, 0x6c) = g_walkCallback;
    NODE_W(group, 0x74) = g_eventQueueCur;
    child = NODE_W(group, 0x18);
    g_currentNodeIdx = child;
    g_walkCallback = NODE_W(child, 0x20) | 0x40u;
    NODE_W(child, 0x20) = g_walkCallback;

    rec = NODE_W(child, 0x28);
    g_xformEntityIdx = rec;
    NODE_W(rec, 0x48) = 0x3333u;
    NODE_W(rec, 0x2c) = 0x26666u;
    W(rec) |= 0xau;
    NODE_W(rec, 0x14) = 0xffu;
    g_walkCallback = 0x413310u;
    NODE_W(rec, 0x10) = 0x413310u;
    CallSetPause();                      /* jmp in the original */
}

void Phase4BoneGravity_00413310(void)
{
    if (g_gate543800 == 0) {
        unsigned int ent = g_xformEntityIdx;
        unsigned int v;

        g_walkCallback = 0xfffffeb9u;
        v = NODE_W(ent, 0x48) - 0x147u;
        g_walkCallback = v;
        NODE_W(ent, 0x48) = v;
        ChainListVecAdd();
        if (g_framePauseFlag != 0) return;
    }
    ClampMulShiftStore();                /* jmp in the original */
}

#endif /* NON_MATCHING */
