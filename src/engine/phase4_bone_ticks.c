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
 * The head block is NOT an entry point. Its only callers in the whole
 * image are two thunks that PUSH g_fightGroupHead first (the pop at the
 * head block's tail balances THEIR push):
 *
 *   MStackPushSet9Jmp        - 0x00413040 (39b): push group; cmd 9; tail.
 *   PushStackCallPauseSet0xa - 0x00413070 (68b): push group;
 *       MStackPush2RunCountdown; MStackBracket7_DispatchAndChain (this is
 *       Bracket7's live driver - the fight-path caller the probe hunt
 *       never found); cmd 0xa; tail. Pause paths leak the push, as the
 *       originals do.
 *
 * And the thunks' only callers are the Phase4FivePackedHelpers cluster
 * (0x412cb0, 901b, five packed entries) - the band MatchStart state 1
 * spawns as the type-0x8b idle controller:
 *
 *   0x412cb0 spawner: StoreTwoCall(0x412cd0, 0x8b).
 *   0x412cd0 idle FSM: budget 0x22; per tick AudioMixerStep(0x3333) +
 *       ZeroAndDirty4(+0xd999), thunk B only when dirty-4 is set.
 *   0x412d80 stage FSM: cmd 0->1(x5)->2(x6)->3(x28) driving thunk B +
 *       thunk A each tick, then done.
 *   0x412ec0 arm FSM: budget 3; thunk B, then arm the record the head
 *       block left in 0x542048: +0x48 = 0x4ccc, +0x10 = 0x412ff0 (the
 *       decay tick), ScaledStoreThree(template 0x4d6748), child
 *       +0x20 |= 0x40, CmpDivJmp(0x64), and unless dirty-4
 *       PoseTreeBlendWalker(template 0x4d5d38).
 *   0x412ff0 decay tick: unless 0x543800, entity+0x48 -= 0x24d and
 *       ChainListVecAdd; then ClampMulShiftStore. (Sister of 0x413310.)
 *
 * Dispatch protocol, measured against the binary: 0x412cd0/0x412d80/
 * 0x412ec0 are controller callbacks (node+8, group staged in 0x54205c by
 * the pump); 0x412ff0/0x4131f0/0x413310 are record +0x10 ticks dispatched
 * by RenderSceneNode's emit path (record staged in 0x542048); 0x413230 is
 * the AllocNode callback the 0x4d6948 skeleton template carries. Those
 * seven go in the codeptr table. 0x4130c0/0x413040/0x413070 are direct
 * call/tail-jmp targets only and MUST NOT be registered.
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
extern void AudioMixerStep(void);
extern void ZeroAndDirty4(void);
extern void ScaledStoreThree_00409260(void);
extern void CmpDivJmp(void);
extern void PoseTreeBlendWalker(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void StoreTwoCall(int cb, int type);

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
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_skelCursor58     (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))

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

/* ---- the two head-block entry thunks (direct-called only) ---- */

void MStackPushSet9Jmp(void)
{
    unsigned int top = g_matrixStackTop + 1;

    g_matrixStackTop = top;
    W(top) = g_fightGroupHead;
    g_walkCallback = 9;
    Phase4StateInit4Helpers();           /* jmp in the original */
}

void PushStackCallPauseSet0xa(void)
{
    unsigned int top = g_matrixStackTop + 1;

    g_matrixStackTop = top;
    W(top) = g_fightGroupHead;
    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;   /* abort: the push leaks */
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = 0xa;
    Phase4StateInit4Helpers();           /* jmp in the original */
}

/* ---- the Phase4FivePackedHelpers cluster (0x412cb0) ---- */

void Phase4FivePackedHelpers(void)
{
    StoreTwoCall(0x412cd0, 0x8b);
}

void Phase4IdleFsm_00412cd0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = MK4_NODE_AT(unsigned int, cam, 0x84);

    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd != 0) {
        if ((int)--g_skelCursor58 < 0) {
            CallSetPause();
            return;
        }
    } else {
        g_skelCursor58 = 0x22;
    }

    g_walkCallback = 0x3333u;
    AudioMixerStep();
    if (g_framePauseFlag != 0) return;
    g_walkCallback += 0xd999u;
    ZeroAndDirty4();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4u) != 0) {
        PushStackCallPauseSet0xa();
        if (g_framePauseFlag != 0) return;
    }
    MK4_NODE_AT(unsigned int, cam, 8) = 0x412cd0u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void Phase4StageFsm_00412d80(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    unsigned int next, pnt;

    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        g_skelCursor58 = 5;
        goto band1;
    }
    if (cmd == 1) {
        if ((int)--g_skelCursor58 >= 0)
            goto band1;
        g_skelCursor58 = 6;
        goto band2;
    }
    if (cmd == 2) {
        if ((int)--g_skelCursor58 >= 0)
            goto band2;
        g_skelCursor58 = 0x28;
        goto band3;
    }
    if ((int)--g_skelCursor58 >= 0)
        goto band3;
    CallSetPause();
    return;

band1:  next = 1; pnt = 3; goto drive;
band2:  next = 2; pnt = 2; goto drive;
band3:  next = 3; pnt = 1; /* fall through */
drive:
    PushStackCallPauseSet0xa();
    if (g_framePauseFlag != 0) return;
    MStackPushSet9Jmp();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, cam, 8) = 0x412d80u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = next;
    g_pendingNodeType = pnt;
    g_framePauseFlag = 1;
}

void Phase4ArmFsm_00412ec0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    unsigned int node, rec, child;

    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd != 0) {
        if ((int)--g_skelCursor58 < 0) {
            CallSetPause();
            return;
        }
    } else {
        g_skelCursor58 = 3;
    }

    PushStackCallPauseSet0xa();
    if (g_framePauseFlag != 0) return;

    node = g_currentNodeIdx;
    g_walkCallback = node;
    if (node != 0) {
        rec = g_xformEntityIdx;
        NODE_W(rec, 0x48) = 0x4cccu;
        NODE_W(g_xformEntityIdx, 0x10) = 0x412ff0u;
        g_walkCallback = 0x4d6748u >> 2;
        ScaledStoreThree_00409260();
        if (g_framePauseFlag != 0) return;

        child = NODE_W(g_currentNodeIdx, 0x18);
        g_currentNodeIdx = child;
        NODE_W(child, 0x20) |= 0x40u;
        g_walkCallback = 0x64;
        CmpDivJmp();
        if (g_framePauseFlag != 0) return;

        if ((g_xformDirtyFlags & 4u) == 0) {
            g_xformEntityIdx = 0x4d5d38u >> 2;
            PoseTreeBlendWalker();
            if (g_framePauseFlag != 0) return;
        }
    }
    MK4_NODE_AT(unsigned int, cam, 8) = 0x412ec0u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 4;
    g_framePauseFlag = 1;
}

void Phase4BoneDecay_00412ff0(void)
{
    if (g_gate543800 == 0) {
        unsigned int ent = g_xformEntityIdx;
        unsigned int v;

        g_walkCallback = 0xfffffdb3u;
        v = NODE_W(ent, 0x48) - 0x24du;
        g_walkCallback = v;
        NODE_W(ent, 0x48) = v;
        ChainListVecAdd();
        if (g_framePauseFlag != 0) return;
    }
    ClampMulShiftStore();                /* jmp in the original */
}

#endif /* NON_MATCHING */
