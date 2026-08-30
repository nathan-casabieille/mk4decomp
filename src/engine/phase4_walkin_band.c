/**
 * The PHASE-4 WALK-IN BAND (0x412900..0x412ccd + its three engine
 * helpers) - the FSM that builds a fighter's skeleton through
 * SkelAnimUpdaterCluster and then steps the pair onto their marks. This
 * is the band whose absence keeps every bone's bind fields empty; the
 * whole map is in the commit trail of e9c8a2851, read from the bytes.
 *
 *   Phase4DualHelperTrampoline (0x412900, 19b): StoreTwoCall(0x412920,
 *       0x8a) - schedule a type-0x8a controller running the FSM below.
 *   Phase4Fsm_00412920: cmd 0 = the BUILD: RunCountdown, Bracket7,
 *       ChainDirtyBitWalker(0xa), seed the controller's +0x38..+0x40
 *       from the fighter record (+0x3c/+0x44, height 0xffffe667),
 *       ZeroThreeFields, SkelAnimUpdaterCluster on the STATIC template
 *       0x4d6948 with node type 0x99, then schedule the walk-in and
 *       yield. cmd 1 = schedule the walk-in and re-arm. cmd 2+ = the
 *       SetJmp gate decides between scheduling and plain pause.
 *   Phase4WalkIn_00412ad0: cmd 0 tail primes the second static template
 *       0x50bbb4 through MStackPushDispatchBitGate, group +0x30 = 0x97,
 *       position from the saved pair (+0x58 pinned 0xfffff334),
 *       ScaledChainOr8, entity+0x48 = 0x28f, prepend, counter 0xf.
 *       cmd 1 / cmd 2+ STEP: +0xccc forward each frame (cmd 2+ also
 *       +0x7ae up), count down, then LLInsert / reset to 7.
 *
 *   MStackPush2RunCountdown (0x4089e0, 226b): clear mask ~0x24 (and
 *       0xdb) on every positive bone's track-record flags.
 *   MStackBracket7_DispatchAndChain (0x4b8fa0, 674b): seven-push
 *       bracket; per-kind dispatch through the NodeApplyTransform table
 *       at 0x4f7888 ((+0x34 >> 24) & 7); optional ScaledNegThreeWords on
 *       +0x34 bit 0; a 12-byte scratch vec (MK4_ALLOCA - the original
 *       packs a PLAIN STACK local, see
 *       feedback_packed_ptr_to_stack_local) receives either
 *       ChainStreamMatMulVecAdd through the frame data or the group's
 *       own +0x54..+0x5c; then RegionFlushChain over the bone chain
 *       with the matrix bank at 0xab48d8.
 *   RegionFlushChain (0x4b9250, 698b): per node - if any of +0x3c..+0x44
 *       is set, re-dispatch the node's own transform ((+0x20 >> 24) & 7,
 *       +8 when +0x20 bit 8) into the region matrix at end+0x14 and
 *       WtSnapshotPushCall; blend the node's +0x30 deltas through the
 *       region into a scratch vec; write it into the track record's
 *       +0x3c..+0x44 (bit 2 set routes through a second MatMul at
 *       +0xc/+0xf instead); when the record's flags bit 4 is set, copy
 *       the NINE-WORD region matrix into record+0x18 - THE BIND ANGLE
 *       BANKS the pose walker reads. Recursion down the sibling chain
 *       goes through Helper_TickAlt with this function's own VA as the
 *       callback.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SDL_Log(const char *, ...);
extern char *getenv(const char *);
extern void *MK4_ResolveCode(unsigned va);
extern void StoreTwoCall(int cb, int type);
extern void CallSetPause(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void ChainDirtyBitWalker(void);
extern void SkelAnimUpdaterCluster(void);
extern void MStackPushDispatchBitGate(void);
extern void ScaledChainOr8(void);
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void MStackCall_MStackPush2ChainLLInsert(void);
extern void ScaledNegThreeWords(void);
extern void ChainStreamMatMulVecAdd(void);
extern void WtSnapshotPushCall(void);
extern void Helper_TickAlt(void);

void Phase4Fsm_00412920(void);
void Phase4WalkIn_00412ad0(void);
void MStackBracket7_DispatchAndChain(void);
void RegionFlushChain(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventQueueTotal  (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_slot54           (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58cur        (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCur    (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot84           (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_slot88           (*(unsigned int *)MK4_VA(unsigned int, 0x542088u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_eq_542098        (*(unsigned int *)MK4_VA(unsigned int, 0x542098u))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_xformLoopCtr     (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))

#define MSTACK_AT(i)       (*(unsigned int *)MK4_PTR((i) * 4u))
#define W(i)               (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define NODE_W(n,off)      MK4_NODE_AT(unsigned int, (n), (off))

void ZeroThreeFields_0040a8b0(void)
{
    unsigned int n = g_currentNodeIdx;

    g_walkCallback = 0;
    NODE_W(n, 0x44) = 0;
    NODE_W(n, 0x48) = 0;
    NODE_W(n, 0x4c) = 0;
}

void MStackPush2RunCountdown(void)
{
    unsigned int top, list, cnt, bone, rec, v;

    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_currentNodeIdx;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_xformEntityIdx;

    list = NODE_W(g_fightGroupHead, 0x1c);
    g_currentNodeIdx = list;
    cnt = W(list) - 1u;
    list++;
    g_currentNodeIdx = list;
    g_xformLoopCtr = cnt;
    while ((int)cnt >= 0) {
        bone = W(list);
        list++;
        g_walkCallback = bone;
        g_eq_542098 = ((int)bone <= 0);
        g_currentNodeIdx = list;
        g_xformEntityIdx = bone;
        if ((int)bone > 0) {
            rec = NODE_W(bone, 0x28);
            g_xformEntityIdx = rec;
            v = W(rec) & 0xffffffdbu;
            g_walkCallback = v;
            W(rec) = v;
        }
        cnt = g_xformLoopCtr - 1u;
        g_xformLoopCtr = cnt;
    }

    top = g_matrixStackTop;
    g_xformEntityIdx = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_currentNodeIdx = MSTACK_AT(top); top--; g_matrixStackTop = top;
}

void MStackBracket7_DispatchAndChain(void)
{
    unsigned int top, group, kind, vecVA, target;

#ifdef TARGET_SDL
    { static unsigned n;
      if (getenv("MK4_TRACE_B7") && (++n % 200u) == 1u)
          SDL_Log("B7 call #%u group=%06x", n, g_fightGroupHead); }
#endif

    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_currentNodeIdx;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_xformEntityIdx;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_pendingNodeType;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_eventQueueTotal;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_slot54;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_slot58cur;
    top = g_matrixStackTop + 1; g_matrixStackTop = top; MSTACK_AT(top) = g_eventQueueNotMask;

    MK4_ALLOCA(12);
    vecVA = MK4_SCRATCH_TOP - 12u;

    group = g_fightGroupHead;
    g_slot58cur = NODE_W(group, 0x34);
    g_xformEntityIdx = group + 0x18u;    /* the +0x60 block, packed cursor */
    kind = ((unsigned int)((int)g_slot58cur >> 24)) & 7u;
    g_currentNodeIdx = (0x4f7888u >> 2) + kind;
    target = W(g_currentNodeIdx);
    g_currentNodeIdx = 0xab48d8u >> 2;   /* the region matrix bank */
    g_eventQueueCur = target;
    g_eventQueueTotal = 0xab48d8u >> 2;
    ((void (*)(void))MK4_ResolveCode(target))();
    if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }

    if ((g_slot58cur & 1u) != 0) {
        ScaledNegThreeWords();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
    }

    group = g_fightGroupHead;
    g_currentNodeIdx = vecVA >> 2;
    if (NODE_W(group, 0x2c) != 0) {      /* frame data present: blend */
        g_walkCallback = NODE_W(group, 0x2c);
        g_pendingNodeType = NODE_W(group, 0x2c);
        g_xformEntityIdx = g_eventQueueTotal;
        g_eventQueueTotal = group + 0x15u;   /* +0x54 block, packed */
        ChainStreamMatMulVecAdd();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
    } else {                              /* copy the group position */
        unsigned int out = vecVA >> 2;

        g_walkCallback = NODE_W(group, 0x54);
        W(out) = g_walkCallback;
        g_walkCallback = NODE_W(g_fightGroupHead, 0x58);
        *(unsigned int *)MK4_PTR(out * 4u + 4u) = g_walkCallback;
        g_walkCallback = NODE_W(g_fightGroupHead, 0x5c);
        *(unsigned int *)MK4_PTR(out * 4u + 8u) = g_walkCallback;
    }

    g_slot54 = 0xab48d8u;
    g_currentNodeIdx = NODE_W(g_fightGroupHead, 0x18);
    g_xformEntityIdx = 0xab48d8u >> 2;
    g_pendingNodeType = vecVA >> 2;
    RegionFlushChain();
    if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }

    top = g_matrixStackTop;
    g_eventQueueNotMask = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_slot58cur = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_slot54 = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_eventQueueTotal = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_pendingNodeType = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_xformEntityIdx = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_currentNodeIdx = MSTACK_AT(top); top--; g_matrixStackTop = top;
    g_xformDirtyFlags &= 0xfffffffeu;
    MK4_ALLOCA_FREE(12);
}

void RegionFlushChain(void)
{
    unsigned int node, ent0, pnt0, end0, vecVA, rec, flags, kind, target, v;

    node = g_currentNodeIdx;
    ent0 = g_xformEntityIdx;
    pnt0 = g_pendingNodeType;
    end0 = g_slot54;

    MK4_ALLOCA(12);
    vecVA = MK4_SCRATCH_TOP - 12u;

    if (NODE_W(node, 0x3c) == 0 && NODE_W(node, 0x40) == 0
        && NODE_W(node, 0x44) == 0) {
        g_slot54 = ent0 << 2;            /* region stays the parent's */
    } else {
        g_slot54 = end0 + 0x14u;
        g_xformEntityIdx = node;
        v = NODE_W(node, 0x20);
        g_eventQueueCur = v;
        kind = ((unsigned int)((int)v >> 24)) & 7u;
        if ((v & 0x100u) != 0)
            kind += 8u;
        g_currentNodeIdx = (0x4f7888u >> 2) + kind;
        target = W(g_currentNodeIdx);
        g_eventQueueCur = target;
        g_xformEntityIdx = node + 0xfu;
        g_currentNodeIdx = (end0 + 0x14u) >> 2;
        ((void (*)(void))MK4_ResolveCode(target))();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
        g_pendingNodeType = g_currentNodeIdx;
        g_xformEntityIdx = ent0;
        WtSnapshotPushCall();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
    }

    g_eventQueueTotal = pnt0;
    g_pendingNodeType = node + 0xcu;     /* the +0x30 delta block */
    g_currentNodeIdx = vecVA >> 2;
    ChainStreamMatMulVecAdd();
    if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }

    g_pendingNodeType = node;
    rec = NODE_W(node, 0x28);
    g_xformEntityIdx = rec;
    if (rec != 0) {
        flags = W(rec);
        g_eventQueueCur = flags;
        if ((flags & 4u) != 0) {
            g_currentNodeIdx = rec + 0xfu;
            g_pendingNodeType = rec + 0xcu;
            g_eventQueueTotal = vecVA >> 2;
            g_xformEntityIdx = g_slot54 >> 2;
            ChainStreamMatMulVecAdd();
            if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
        } else {
            unsigned int src = vecVA >> 2;

            v = W(src);
            g_walkCallback = v;
            NODE_W(rec, 0x3c) = v;
            v = *(unsigned int *)MK4_PTR(src * 4u + 4u);
            g_walkCallback = v;
            NODE_W(rec, 0x40) = v;
            v = *(unsigned int *)MK4_PTR(src * 4u + 8u);
            g_walkCallback = v;
            NODE_W(rec, 0x44) = v;
        }
        g_xformEntityIdx = rec;
        flags = W(rec);
        g_walkCallback = flags;
        if ((flags & 0x10u) != 0) {      /* copy the 9-word region matrix */
            unsigned int dst = rec + 6u;
            unsigned int i;

            g_xformEntityIdx = dst;
            for (i = 0; i < 9u; i++)
                *(unsigned int *)MK4_PTR(dst * 4u + i * 4u) =
                    *(unsigned int *)MK4_PTR(g_slot54 + i * 4u);
        }
    }

    g_currentNodeIdx = node;
    v = W(node);                          /* the sibling link */
    g_walkCallback = v;
    g_eq_542098 = (v == 0);
    g_xformEntityIdx = g_slot54 >> 2;
    if (v != 0) {
        g_walkCallback = 0x4b9250u;      /* recurse through the tick */
        g_pendingNodeType = vecVA >> 2;
        Helper_TickAlt();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
    }

    g_slot54 = end0;
    g_xformEntityIdx = ent0;
    g_pendingNodeType = pnt0;
    g_xformDirtyFlags &= 0xfffffffeu;
    MK4_ALLOCA_FREE(12);
}

/* ---- the FSM pair ---- */

void Phase4Fsm_00412920(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

#ifdef TARGET_SDL
    { static int n;
      if (getenv("MK4_TRACE_WALKIN") && n < 30) { n++;
        SDL_Log("P4FSM cmd=%u cam=%06x group=%06x", cmd, cam, g_fightGroupHead); } }
#endif

    NODE_W(cam, 0x84) = 0;
    if (cmd == 1) {
        StoreTwoCall(0x412ad0, 0x8a);
        NODE_W(cam, 8) = 0x412920u;
        NODE_W(cam, 0x84) = 2;
        g_pendingNodeType = 0xcu;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd >= 2) {
        SetJmp_ZeroAndDirty4();
        if (g_framePauseFlag != 0) return;
        if ((g_xformDirtyFlags & 4u) != 0) {
            StoreTwoCall(0x412ad0, 0x8a);
            CallSetPause();
            return;
        }
        CallSetPause();
        return;
    }

    /* cmd 0: the build */
    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = 0xau;
    ChainDirtyBitWalker();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4u) != 0) {
        CallSetPause();
        return;
    }

    {
        unsigned int ent = g_xformEntityIdx;

        g_slot88 = NODE_W(ent, 0x3c);
        g_slot84 = NODE_W(ent, 0x44);
        NODE_W(cam, 0x38) = g_slot88;
        NODE_W(cam, 0x40) = g_slot84;
        g_walkCallback = 0xffffe667u;
        NODE_W(cam, 0x3c) = 0xffffe667u;
    }
    g_currentNodeIdx = g_baseSel;
    ZeroThreeFields_0040a8b0();
    if (g_framePauseFlag != 0) return;

    g_eventQueueNotMask = 0x99u;
    g_xformEntityIdx = 0x4d6948u >> 2;
    SkelAnimUpdaterCluster();
    if (g_framePauseFlag != 0) return;

    StoreTwoCall(0x412ad0, 0x8a);
    NODE_W(cam, 8) = 0x412920u;
    NODE_W(cam, 0x84) = 1;
    g_pendingNodeType = 0xcu;
    g_framePauseFlag = 1;
}

void Phase4WalkIn_00412ad0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);
    unsigned int a, b, ctr;

#ifdef TARGET_SDL
    { static int n;
      if (getenv("MK4_TRACE_WALKIN") && n < 40) { n++;
        SDL_Log("P4WALK cmd=%u cam=%06x group=%06x pair=%06x ctr=%u",
                cmd, cam, g_fightGroupHead, g_slot54, g_slot58cur); } }
#endif

    NODE_W(cam, 0x84) = 0;
    if (cmd == 0)
        goto first_visit;

    a = g_slot54;                         /* the stepped pair */
    if (cmd != 1) {
        /* cmd 2+: forward on A, up on the group */
        NODE_W(a, 0x48) += 0xcccu;
        g_walkCallback = NODE_W(g_slot54, 0x48);
        b = g_fightGroupHead;
        NODE_W(b, 0x58) += 0x7aeu;
        g_walkCallback = NODE_W(g_fightGroupHead, 0x58);
        ctr = g_slot58cur - 1u;
        g_slot58cur = ctr;
        if ((int)ctr < 0) {
            /* countdown done: destroy the effect node (the captured
             * group) and TERMINATE - the original never reinstalls
             * after the kill (jne ret / je CallSetPause+ret at
             * 0x412b63). The first transcription re-armed here, so the
             * dead walk-in killed its slot again every cycle - that
             * repeated free is what cycled the bootChainPair0 pool. */
            MStackCall_MStackPush2ChainLLInsert();
            if (g_framePauseFlag != 0) return;
            CallSetPause();
            return;
        }
        goto reinstall2;
    }
    /* cmd 1: forward only */
    NODE_W(a, 0x48) += 0xcccu;
    g_walkCallback = NODE_W(g_slot54, 0x48);
    ctr = g_slot58cur - 1u;
    g_slot58cur = ctr;
    if ((int)ctr >= 0)
        goto reinstall1;                  /* jns 0x412c8f: STAY in cmd 1 */
    g_slot58cur = 7u;                     /* expired: advance to cmd 2 */

reinstall2:
    NODE_W(cam, 8) = 0x412ad0u;
    NODE_W(cam, 0x84) = 2;
    g_pendingNodeType = 1u;
    g_framePauseFlag = 1;
    return;

reinstall1:
    NODE_W(cam, 8) = 0x412ad0u;
    NODE_W(cam, 0x84) = 1;
    g_pendingNodeType = 1u;
    g_framePauseFlag = 1;
    return;

first_visit:
    g_xformEntityIdx = 0x50bbb4u >> 2;
    MStackPushDispatchBitGate();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4u) != 0) {
        CallSetPause();
        return;
    }
    NODE_W(g_fightGroupHead, 0x30) = 0x97u;
    NODE_W(g_fightGroupHead, 0x54) = g_slot88;
    NODE_W(g_fightGroupHead, 0x5c) = g_slot84;
    g_walkCallback = 0xfffff334u;
    NODE_W(g_fightGroupHead, 0x58) = 0xfffff334u;
    ScaledChainOr8();
    {
        unsigned int ent = g_xformEntityIdx;

        g_walkCallback = 0x28fu;
        NODE_W(ent, 0x48) = 0x28fu;
        g_slot54 = ent;
    }
    MStackCall_MStackPush2ChainPrepend_004062f0();
    if (g_framePauseFlag != 0) return;
    g_slot58cur = 0xfu;
    NODE_W(cam, 8) = 0x412ad0u;
    NODE_W(cam, 0x84) = 1;
    g_pendingNodeType = 1u;
    g_framePauseFlag = 1;
}

void Phase4DualHelperTrampoline(void)
{
    StoreTwoCall(0x412920, 0x8a);
}

#endif /* NON_MATCHING */
