/**
 * The character-select controller and the two leaves it drives.
 *
 * RoundSetupSpawn already allocates this FSM - it does
 * `g_pendingNodeType = 0x455f00; AllocNode()` with node type 0x26b, the
 * same shape every other controller is spawned with - but the callback it
 * installs existed natively nowhere, so the select screen was never
 * reached. This is that callback.
 *
 * CharSelectController_00455f00 (0x455f00, part of the 1448b cluster at
 * 0x455bd0): a seven-state machine on the controller's command word,
 * dispatched through the jump table at 0x45615c:
 *
 *   0 (0x45604b) build: DualScaledStore, spawn the 0x4745e0 screen node,
 *       carry the old pair head into g_fightGroupHead, arm a 10-frame
 *       countdown, then fall into the state-2 body.
 *   1 (0x455f2e) settle: ZeroAndDirty4; when dirty bit 2 came up, run the
 *       cmd-9 and cmd-0xa passes; re-arm as state 2.
 *   2 (0x455f8f) countdown: tick g_slot54 down; at zero reload it with 0x3c
 *       and drop into the shared tail; otherwise take the state-0 body.
 *   3, 4 (0x455faf) the cmd-3 pass, re-arming as state 5.
 *   5 (0x455fe3) TwoCallPauseSetJmp2, re-arming as state 6.
 *   6 (0x456017) the cmd-0xa pass, re-arming as state 7 - which is out of
 *       the table's range, so the next tick takes the default arm.
 *   default (0x4560dd) the shared tail: tick the countdown, and when it
 *       has not expired run ZeroAndDirty4 and re-arm as state 4 or 3
 *       depending on dirty bit 2; when it has, Thunk_ScaledNeg1SetPause.
 *
 * Leaves:
 *   StoreLoadJmp (0x404ef0, 33b): spawn a node - the callback comes in as
 *       the argument, the node type from the controller's own +0xc.
 *   TwoCallPauseSetJmp2 (0x456180, 54b): the countdown + Bracket7 pair,
 *       then g_slot78 = 2 and the cmd-3 tail.
 *   CharSelectBracket_004561f0 (91b): the same pair inside an mstack
 *       bracket on g_walkCallback, then g_slot78 = 2 and its own tail.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SetJmp_ZeroAndDirty4(void);
extern void DualScaledStore(void);
extern void AllocNode(void);
extern void Thunk_ScaledNeg1SetPause(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop(void);
extern void GuardedSeq_DualSetShiftCall_then_MStackPush2CjMul10Triple(void);
extern void SetJmp_CharSelectFsmCluster_004561c0(void);   /* cmd 3   */
extern void SetJmp_CharSelectFsmCluster_004561d0(void);   /* cmd 9   */
extern void SetJmp_CharSelectFsmCluster_004561e0(void);   /* cmd 0xa */

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54           (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot74           (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78           (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))

#define W(i)               (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define NODE_W(n, off)     MK4_NODE_AT(unsigned int, (n), (off))

void StoreLoadJmp(unsigned int callback)
{
    g_pendingNodeType = callback;
    g_slot74 = NODE_W(g_baseSel, 0xc);
    AllocNode();                          /* jmp in the original */
}

void TwoCallPauseSetJmp2(void)
{
    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_slot78 = 2;
    g_walkCallback = 3;
    GuardedSeq_DualSetShiftCall_then_MStackPush2CjMul10Triple();  /* jmp */
}

void CharSelectBracket_004561f0(void)
{
    unsigned int top = g_matrixStackTop + 1;

    g_matrixStackTop = top;
    W(top) = g_walkCallback;

    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;    /* abort: the push leaks */
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;

    top = g_matrixStackTop;
    g_walkCallback = W(top);
    g_matrixStackTop = top - 1;
    g_slot78 = 2;
    GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop();      /* jmp */
}

/* re-install self on the controller with the given command */
static void cs_arm(unsigned int cam, unsigned int cmd)
{
    NODE_W(cam, 8) = 0x455f00u;
    NODE_W(cam, 0x84) = cmd;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void CharSelectController_00455f00(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;

    switch (cmd) {
    case 1:                                       /* 0x455f2e */
        SetJmp_ZeroAndDirty4();
        if (g_framePauseFlag != 0) return;
        if ((g_xformDirtyFlags & 4u) != 0) {
            SetJmp_CharSelectFsmCluster_004561d0();
            if (g_framePauseFlag != 0) return;
            SetJmp_CharSelectFsmCluster_004561e0();
            if (g_framePauseFlag != 0) return;
        }
        cs_arm(cam, 2);
        return;

    case 2:                                       /* 0x455f8f */
        if ((int)--g_slot54 < 0) {
            g_slot54 = 0x3c;
            goto tail;
        }
        goto build_body;

    case 3:
    case 4:                                       /* 0x455faf */
        SetJmp_CharSelectFsmCluster_004561c0();
        if (g_framePauseFlag != 0) return;
        cs_arm(cam, 5);
        return;

    case 5:                                       /* 0x455fe3 */
        TwoCallPauseSetJmp2();
        if (g_framePauseFlag != 0) return;
        cs_arm(cam, 6);
        return;

    case 6:                                       /* 0x456017 */
        SetJmp_CharSelectFsmCluster_004561e0();
        if (g_framePauseFlag != 0) return;
        cs_arm(cam, 7);
        return;

    case 0:                                       /* 0x45604b - the build */
        DualScaledStore();
        if (g_framePauseFlag != 0) return;
        StoreLoadJmp(0x4745e0u);
        g_fightGroupHead = g_slot54;
        g_slot54 = 0xa;
build_body:
        SetJmp_CharSelectFsmCluster_004561c0();
        if (g_framePauseFlag != 0) return;
        SetJmp_ZeroAndDirty4();
        if (g_framePauseFlag != 0) return;
        if ((g_xformDirtyFlags & 4u) != 0) {
            TwoCallPauseSetJmp2();
            if (g_framePauseFlag != 0) return;
        }
        cs_arm(cam, 1);
        return;

    default:                                      /* 0x4560dd - shared tail */
        if ((int)--g_slot54 < 0) {
            Thunk_ScaledNeg1SetPause();
            return;
        }
tail:
        SetJmp_ZeroAndDirty4();
        if (g_framePauseFlag != 0) return;
        if ((g_xformDirtyFlags & 4u) != 0) {
            SetJmp_CharSelectFsmCluster_004561d0();
            if (g_framePauseFlag != 0) return;
            cs_arm(cam, 4);
            return;
        }
        cs_arm(cam, 3);
        return;
    }
}

#endif /* NON_MATCHING */
