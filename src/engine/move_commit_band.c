/**
 * The move-commit band: what an animation event runs when a move lands.
 *
 * GameMusicState4Way - 0x00426d90 (516b, packed): a thunk (reaction
 *   0x23c -> MStackBitLoopTripleCall) + a 4-state self-installed FSM at
 *   0x426da0 (jump table at 0x426f84): state 0/default appends its own
 *   VA + 0x1000000 into the camera event queue and runs GuardedSelfRefSet;
 *   state 1 runs the countdown/dispatch chain then re-installs with a
 *   0x10-frame delay; states 2/3 run SetJmp_ZeroAndDirty4 and re-install
 *   unless state-bit 2 interferes.
 *
 * MStackBitLoopTripleCall - 0x0049cc30 (267b): bracketed loop - bit-mask
 *   search, then per hit (group head != node[+0x2c]) toggles bit 2 around
 *   AndStoreJmp until the search converges on the group head, then
 *   Thunk_LoadShlDerefCallSkip and loop.
 *
 * Phase4TrampolineMainHelpers - 0x00414b90 (1097b, packed): a
 *   StoreTwoCall(0x414bb0, 0xb1) installer thunk; the 3-state FSM at
 *   0x414bb0; the projectile/effect spawner at 0x414cf0 (dresses a node
 *   from the 5-word records at 0x4d77b0 - position triple, kind, type -
 *   and installs 0x4ba0e0 as the anim callback); and the small cleanup
 *   at 0x414fc0.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void AndStoreJmp(void);
extern void Thunk_LoadShlDerefCallSkip(void);
extern void SetupHelperCluster(void);
extern void GuardedSelfRefSet(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void Wrapper_ScaledChainPushCall_004ef828(void);
extern void CallPauseInc(void);
extern void StorePauseImulShr16(void);
extern void FramePauseScaledStore(void);
extern void ScaledStoreThree_00409260(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void MStackPushCallCallPop_func_00405e20(void);
extern void CallSetPause(void);
extern void PushPopScaled1cDoubleCall(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void ChainDirtyBitWalker(void);
extern void StoreTwoCall(int, int);
extern void DirtyDoubleDeref(void);
extern void ChainNodeAdvanceCallback(void);
extern void ScaledTestPauseStore(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50          (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58          (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_tickFlagF       (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))

void MStackBitLoopTripleCall(void)
{
    unsigned int top, saved;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;
    saved = g_walkSlot6c;
    g_slot74 = saved;

    SetJmp_Thunk_LinkedListBitMaskSearch();
    if (g_framePauseFlag != 0)
        return;                     /* abort: the push leaks */

    for (;;) {
        if ((g_stateBits8c & 4) != 0)
            break;
        while (g_groupHead != MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x2c)) {
            g_stateBits8c |= 4u;
            if (g_currentNodeIdx == 0)
                goto pop;
            g_stateBits8c ^= 4u;
            if (g_currentNodeIdx == 0)
                goto pop;
            /* 0x542070, not 0x542050 - the original's `or esi, -1` lands in
             * the 70 slot (caught by the sharpened audit-global-refs) */
            g_slot70 = (unsigned int)-1;
            g_walkSlot6c = g_slot74;
            AndStoreJmp();
            if (g_framePauseFlag != 0)
                return;
            if ((g_stateBits8c & 4) != 0)
                goto pop;
        }
        g_pendingNodeType = g_currentNodeIdx;
        Thunk_LoadShlDerefCallSkip();
        if (g_framePauseFlag != 0)
            return;
        g_walkSlot6c = g_slot74;
        SetJmp_Thunk_LinkedListBitMaskSearch();
        if (g_framePauseFlag != 0)
            return;
    }
pop:
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* append VA+tag into the camera node's event queue, install self, run
 * GuardedSelfRefSet and yield - the shared re-arm tail of both FSMs */
static void mcb_queue_selfref(unsigned int self_va, unsigned int cmd)
{
    unsigned int cam = g_baseSel;
    unsigned int q;

    MK4_NODE_AT(unsigned int, cam, 8) = self_va;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = cmd;
    q = MK4_NODE_AT(unsigned int, cam, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = self_va + 0x1000000u;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, cam, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    GuardedSelfRefSet();
    g_framePauseFlag = 1;
}

void GameMusicFsm_00426da0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 1) {
        MStackPush2RunCountdown();
        if (g_framePauseFlag != 0) return;
        MStackBracket7_DispatchAndChain();
        if (g_framePauseFlag != 0) return;
        /* scan the zero-terminated list at [0x542054], wrapping to the
         * static list at 0x4e2670 */
        for (;;) {
            unsigned int cur = g_slot54;
            unsigned int v = *(unsigned int *)MK4_PTR(cur * 4);
            g_walkSlot6c = v;
            g_slot54 = cur + 1;
            if (v != 0)
                break;
            g_slot54 = 0x4e2670u >> 2;
        }
        ChainDirtyBitWalker();
        if (g_framePauseFlag != 0) return;
        g_xformEntityIdx += 0xf;
        g_slot58 = g_xformEntityIdx;
        SetupHelperCluster();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, cam, 8) = 0x426da0u;
        MK4_NODE_AT(unsigned int, cam, 0x84) = 2;
        g_pendingNodeType = 0x10;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 2) {
        g_walkSlot6c = 0xd999u;
        SetJmp_ZeroAndDirty4();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) == 0) {
            MK4_NODE_AT(unsigned int, cam, 8) = 0x426da0u;
            MK4_NODE_AT(unsigned int, cam, 0x84) = 3;
            g_pendingNodeType = 4;
            g_framePauseFlag = 1;
            return;
        }
        mcb_queue_selfref(0x426da0u, 1);
        return;
    }
    if (cmd == 3) {
        SetJmp_ZeroAndDirty4();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) == 0) {
            MK4_NODE_AT(unsigned int, cam, 8) = 0x426da0u;
            MK4_NODE_AT(unsigned int, cam, 0x84) = 4;
            g_pendingNodeType = 6;
            g_framePauseFlag = 1;
            return;
        }
    }
    mcb_queue_selfref(0x426da0u, 1);
}

void GameMusicState4Way(void)
{
    g_walkSlot6c = 0x23c;
    MStackBitLoopTripleCall();      /* jmp in the original */
}

void Phase4Fsm_00414bb0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {
        mcb_queue_selfref(0x414bb0u, 1);
        return;
    }
    if (cmd != 1) {
        SetJmp_ZeroAndDirty4();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) != 0) {
            StoreTwoCall(0x414cf0, 0xb2);
            g_slot54 -= 1;
            if ((int)g_slot54 < 0)
                goto arm_next;
        }
        goto tick;
    }
arm_next:
    if (g_tickFlagF == 4) {
        Wrapper_ScaledChainPushCall_004ef828();
        if (g_framePauseFlag != 0) return;
    }
    g_slot54 = 4;
tick:
    g_walkSlot6c = 0xc;
    CallPauseInc();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c += 6;
    g_pendingNodeType = g_walkSlot6c;
    MK4_NODE_AT(unsigned int, cam, 8) = 0x414bb0u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 2;
    g_framePauseFlag = 1;
}

void EffectSpawner_00414cf0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, rec, node, anim, v;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd != 0) {
        node = g_slot58;
        g_currentNodeIdx = node;
        g_xformEntityIdx = MK4_NODE_AT(unsigned int, node, 0x28);
        ChainNodeAdvanceCallback();
        if (g_framePauseFlag != 0) return;
        g_walkSlot6c = g_currentNodeIdx;
        if (g_currentNodeIdx == 0) {
            CallSetPause();
            return;
        }
        goto rearm;
    }

    g_walkSlot6c = 0xa;
    StorePauseImulShr16();
    if (g_framePauseFlag != 0) return;
    rec = (0x4d77b0u >> 2) + g_walkSlot6c * 5;   /* lea ecx,[eax+eax*4] */
    g_walkSlot6c = g_walkSlot6c * 5;
    g_slot50 = rec;
    node = *(unsigned int *)MK4_PTR(rec * 4);
    g_xformEntityIdx = node;
    g_xformEntityIdx = (unsigned int)
        (((int)*(unsigned int *)MK4_PTR(node * 4) >> 2) & 0x3fffff);
    FramePauseScaledStore();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4) != 0) {
        CallSetPause();
        return;
    }
    ScaledTestPauseStore();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4) != 0) {
        MStackPushCallCallPop_func_00405e20();
        if (g_framePauseFlag != 0) return;
        CallSetPause();
        return;
    }
    rec = g_slot50;
    v = *(unsigned int *)MK4_PTR(rec * 4);
    g_walkSlot6c = v;
    g_slot50 = rec + 1;
    ScaledStoreThree_00409260();
    if (g_framePauseFlag != 0) return;

    node = g_currentNodeIdx;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, node, 0x1c) = 0;
    v = *(unsigned int *)MK4_PTR(g_slot50 * 4);
    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) = v;
    g_slot50 += 1;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(g_slot50 * 4);
    StoreDoubleNegPauseSubStore();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = g_walkSlot6c;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(g_slot50 * 4);
    g_slot50 += 1;
    StoreDoubleNegPauseSubStore();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x38) = g_walkSlot6c;

    anim = g_xformEntityIdx;
    g_walkSlot6c = 0x4ba0e0u;
    MK4_NODE_AT(unsigned int, anim, 0x10) = 0x4ba0e0u;    /* anim callback */
    v = MK4_NODE_AT(unsigned int, anim, 0x48) | 8u;
    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, anim, 0x48) = v;
    MK4_NODE_AT(unsigned int, anim, 0x48) = *(unsigned int *)MK4_PTR(g_slot50 * 4);
    g_slot50 += 1;
    g_walkSlot6c = 0xff;
    MK4_NODE_AT(unsigned int, anim, 0x14) = 0xff;
    g_slot58 = g_currentNodeIdx;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(g_slot50 * 4);
    g_slot50 += 1;
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = g_currentNodeIdx;
    g_currentNodeIdx = g_slot58;
    PushPopScaled1cDoubleCall();
    if (g_framePauseFlag != 0) return;
rearm:
    MK4_NODE_AT(unsigned int, cam, 8) = 0x414cf0u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void Phase4Cleanup_00414fc0(void)
{
    MStackPushCallCallPop_func_00405e20();
    if (g_framePauseFlag != 0)
        return;
    g_currentNodeIdx = 0;
}

void Phase4TrampolineMainHelpers(void)
{
    StoreTwoCall(0x414bb0, 0xb1);
}


extern void ChainSearch(void);
extern void PushSetXfmMaskCallPop(void);
extern void QuadMul10TailFpuChain(void);
extern void ClampMulShiftStore(void);
extern void ChainWalkPushPop(void);
extern void ZeroAndDirty4(void);
extern void MStackPushCallCallPop_func_00405dd0(void);
extern void AudioMixerStep(void);
extern void StackPopDispatchTagged(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);

#define g_slot70b         (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_roundWord7c     (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80b         (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_audioSave130    (*(unsigned int *)MK4_VA(unsigned int, 0x538130u))
#define g_camRecIdx       (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_gameMode3800b   (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))
#define g_p1NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_p2NodeIdxG      (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))

/* AndStoreJmp - 0x0049cc10 (24b) */
void AndStoreJmp(void)
{
    g_walkSlot6c &= g_slot70b;
    ChainSearch();                  /* jmp in the original */
}

/* CallPauseInc - 0x004ab670 (21b) */
void CallPauseInc(void)
{
    StorePauseImulShr16();
    if (g_framePauseFlag != 0)
        return;
    g_walkSlot6c += 1;
}

/* GuardedSelfRefSet - 0x0048d070 (80b) */
void GuardedSelfRefSet(void)
{
    unsigned int cam = g_baseSel;

    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (g_groupHead == g_p1NodeIdxG || g_groupHead == g_p2NodeIdxG) {
        StackPopDispatchTagged();   /* jmp in the original */
        return;
    }
    MK4_NODE_AT(unsigned int, cam, 8) = 0x48d070u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_pendingNodeType = 0xa;
    g_framePauseFlag = 1;
}

/* StoreDoubleNegPauseSubStore - 0x004ab750 (62b) */
void StoreDoubleNegPauseSubStore(void)
{
    int v = (int)g_walkSlot6c;

    g_audioSave130 = (unsigned int)v;
    v += v;
    g_walkSlot6c = (unsigned int)v;
    if (v < 0)
        g_walkSlot6c = (unsigned int)(-v);
    AudioMixerStep();
    if (g_framePauseFlag != 0)
        return;
    g_walkSlot6c -= g_audioSave130;
}

/* the effect-tick callback SetupHelperCluster installs (anim +0x10) */
void EffectTick_00427230(void)
{
    unsigned int head, anim, v;
    unsigned int top;

    ClampMulShiftStore();
    if (g_framePauseFlag != 0) return;
    if (g_gameMode3800b != 0) return;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_groupHead;
    ChainWalkPushPop();
    if (g_framePauseFlag != 0) return;

    head = g_groupHead;
    v = MK4_NODE_AT(unsigned int, head, 0x6c);
    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, head, 0x6c) =
        (unsigned int)(((long long)0xe666 * (int)v) >> 16);
    g_walkSlot6c = 0xffffffbfu;
    v = MK4_NODE_AT(unsigned int, head, 0x70) - 0x41;
    g_walkSlot6c = v;
    v = (unsigned int)(((long long)0xe666 * (int)v) >> 16);
    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, head, 0x70) = v;
    v = MK4_NODE_AT(unsigned int, head, 0x74);
    g_walkSlot6c = v;
    v = (unsigned int)(((long long)0xe666 * (int)v) >> 16);
    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, head, 0x74) = v;

    top = g_matrixStackTop;
    g_groupHead = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;

    anim = g_xformEntityIdx;
    v = MK4_NODE_AT(unsigned int, anim, 0x18) - 1;
    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, anim, 0x18) = v;
    if ((int)g_walkSlot6c > 0)
        return;

    g_slot70b = 0xfffffff9u;
    g_walkSlot6c = 0xd999u;
    ZeroAndDirty4();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4) == 0)
        g_slot70b = 0xfffffff2u;
    v = g_slot70b + MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x14);
    g_slot70b = v;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x14) = v;
    if ((int)g_slot70b > 0x30)
        return;
    MStackPushCallCallPop_func_00405dd0();
}

/* SetupHelperCluster - 0x00426fa0 (1005b, main entry): dress the spawned
 * effect group from its parent - timers, halved +0x70, the anim record
 * (period 0xff, life 0x19, callback 0x427230), position from the
 * parent's vec (+4 lowered by 0x2666), camera-relative drift scaled
 * 0.3 via QuadMul10TailFpuChain, and prepend into the scaled2 list. */
void SetupHelperCluster(void)
{
    unsigned int top, head, parent, anim, v;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot54;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_groupHead;

    g_slot54 = g_groupHead;
    g_walkSlot6c = 0x4e2700u >> 2;
    PushSetXfmMaskCallPop();
    if (g_framePauseFlag != 0)
        return;                     /* abort: the pushes leak */

    if ((g_stateBits8c & 4) == 0) {
        head = g_groupHead;
        parent = g_slot54;
        g_walkSlot6c = 0x258;
        MK4_NODE_AT(unsigned int, head, 0x30) = 0x258;
        v = MK4_NODE_AT(unsigned int, parent, 0x6c);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, head, 0x6c) = v;
        v = (unsigned int)((int)MK4_NODE_AT(unsigned int, parent, 0x70) >> 1);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, head, 0x70) = v;
        v = MK4_NODE_AT(unsigned int, parent, 0x74);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, head, 0x74) = v;

        anim = MK4_NODE_AT(unsigned int, head, 0x18);
        g_xformEntityIdx = anim;
        anim = MK4_NODE_AT(unsigned int, anim, 0x28);
        g_xformEntityIdx = anim;
        MK4_NODE_AT(unsigned int, anim, 0x14) = 0xff;
        MK4_NODE_AT(unsigned int, anim, 0x18) = 0x19;
        g_walkSlot6c = 0x427230u;
        MK4_NODE_AT(unsigned int, anim, 0x10) = 0x427230u;

        v = *(unsigned int *)MK4_PTR(g_slot58 * 4);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = v;
        v = MK4_NODE_AT(unsigned int, g_slot58, 4) - 0x2666;
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = v;
        v = MK4_NODE_AT(unsigned int, g_slot58, 8);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = v;

        {
            unsigned int savedHead = g_groupHead;
            unsigned int cam = g_camRecIdx;
            g_groupHead = cam;
            g_roundWord7c = MK4_NODE_AT(unsigned int, cam, 0x54);
            g_slot80b = MK4_NODE_AT(unsigned int, cam, 0x5c);
            g_groupHead = savedHead;
        }
        QuadMul10TailFpuChain();
        if (g_framePauseFlag != 0)
            return;
        g_roundWord7c = (unsigned int)
            (((long long)0x4ccc * (int)g_roundWord7c) >> 16);
        g_slot80b = (unsigned int)
            (((long long)0x4ccc * (int)g_slot80b) >> 16);
        v = *(unsigned int *)MK4_PTR(g_slot58 * 4) + g_roundWord7c;
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = v;
        v = MK4_NODE_AT(unsigned int, g_slot58, 8) + g_slot80b;
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = v;
        MStackCall_MStackPush2ChainPrepend_00406600();
        if (g_framePauseFlag != 0)
            return;
    }
    top = g_matrixStackTop;
    g_groupHead = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    top = g_matrixStackTop;
    g_slot54 = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}


/* ChainSearch - 0x0041f9c0 (138b): walk the +0xe4 sibling chain from
 * currentNodeIdx looking for a live (+0xd8 set) entry whose +0xc equals
 * the search key and +0x2c equals the group head. Found: clear bit 2,
 * set bit 0. Exhausted: currentNodeIdx = 0, clear bit 0, set bit 2. */
void ChainSearch(void)
{
    unsigned int n = g_currentNodeIdx;
    unsigned int key = g_walkSlot6c, head = g_groupHead;

    while (n != 0) {
        if (MK4_NODE_AT(unsigned int, n, 0xd8) != 0) {
            g_currentNodeIdx = n;
            g_slot74 = MK4_NODE_AT(unsigned int, n, 0xc);
            if (g_slot74 == key &&
                MK4_NODE_AT(unsigned int, n, 0x2c) == head) {
                g_stateBits8c = (g_stateBits8c & ~4u) | 1u;
                return;
            }
        }
        n = MK4_NODE_AT(unsigned int, n, 0xe4);
    }
    g_currentNodeIdx = 0;
    g_stateBits8c = (g_stateBits8c & ~1u) | 4u;
}

/* ChainWalkPushPop - 0x00405a40 (114b): bracketed +0x14 chain descent to
 * the last link; group head takes its +0x18. */
void ChainWalkPushPop(void)
{
    unsigned int top, n, nxt;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    n = g_currentNodeIdx;
    nxt = MK4_NODE_AT(unsigned int, n, 0x14);
    g_walkSlot6c = nxt;
    while (nxt != 0) {
        n = nxt;
        g_currentNodeIdx = n;
        nxt = MK4_NODE_AT(unsigned int, n, 0x14);
        g_walkSlot6c = nxt;
    }
    g_walkSlot6c = MK4_NODE_AT(unsigned int, n, 0x18);
    g_groupHead = g_walkSlot6c;

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* ClampMulShiftStore - 0x004ba0e0 (66b): the effect fade - anim[+0x14]
 * times the master fade at 0xab4e6c, >>8, clamped to [0, 0x100], into
 * 0xab4e5c; 0xab4e60 takes the palette base at 0x543550. */
void ClampMulShiftStore(void)
{
    int v = (int)MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x14)
          * (int)*MK4_VA(int, 0xab4e6cu);

    v >>= 8;
    *MK4_VA(int, 0xab4e5cu) = v;
    if (v < 0)
        *MK4_VA(int, 0xab4e5cu) = 0;
    else if (v > 0x100)
        *MK4_VA(int, 0xab4e5cu) = 0x100;
    *MK4_VA(unsigned int, 0xab4e60u) = *MK4_VA(unsigned int, 0x543550u);
}

#endif /* NON_MATCHING */
