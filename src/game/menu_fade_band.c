/**
 * The MENU FADE - what runs between "you picked a mode" and the mode's own
 * handler, and the reason picking one used to bounce the mode-select screen
 * back to its state 0 instead of leaving it.
 *
 * The menu's state 4 confirm path parks the row's handler in 0x543574,
 * queues its own state 5 and hands the frame to InstallSelfPackedF80. That
 * was a weak no-op, so the queued continuation unwound immediately and the
 * controller re-entered at 0.
 *
 *   InstallSelfPackedF80 (0x426000) - a two-state controller.
 *     state 0: stash slot70, build the fade overlay through
 *       DispatcherChainRampClamp, and - unless the spawn came back dirty -
 *       install the per-frame ramp step as the overlay's callback
 *       (node[+0x10] = 0x426190, node[+0x14] = 0x80 the ramp's start), put
 *       slot70 back, divide 0x80 by it for the per-tick step, and park as
 *       state 1 with that step + 6 as the wait.
 *     state 1 (or a dirty state 0): clear the tick word and
 *       StackPopDispatchTagged, which resumes the menu at its state 5.
 *   DispatcherChainRampClamp (0x4260d0) - spawn record 0x514f1c, place it at
 *     x = 0xf8300000 with kind 0x274, take its child at +0x18 as the
 *     pendingNodeType, mark that child's +0x1c, run the list insert and the
 *     three-deep walk, then tail into the chain-prepend with the child's
 *     +0x28 as the head.
 *   DispatcherChainRampStep_00426190 - the per-frame step, packed behind
 *     DispatcherChainRampClamp with no symbol of its own, so it is reached
 *     only through the node's +0x10 callback slot: it needs an entry in
 *     config/codeptr_extras.yaml or MK4_ResolveCode returns nothing and the
 *     ramp never moves. Counts node[+0x14] down by the stashed step,
 *     clamps at zero, publishes twice the remainder as the tick word, and
 *     tails into ClampMulShiftStore.
 *   DivBy (0x4ab300) - walkSlot6c /= slot70, with slot70 == 0 meaning
 *     "result zero" rather than a divide fault.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void ClampMulShiftStore(void);
extern void StackPopDispatchTagged(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_fadeStash       (*(unsigned int *)MK4_VA(unsigned int, 0x53a384u))
#define g_tickW1          (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))

#define FADE_VA           0x426000u
#define FADE_STEP_VA      0x426190u

/* 0x4ab300 */
void DivBy(void)
{
    unsigned int d = g_slot70;

    if (d == 0) {
        g_walkSlot6c = 0;
        return;
    }
    g_walkSlot6c = (unsigned int)((int)g_walkSlot6c / (int)d);
}

/* 0x426190 - the per-frame ramp step, reached only through node[+0x10] */
void DispatcherChainRampStep_00426190(void)
{
    unsigned int node = g_xformEntityIdx;
    int left = (int)MK4_NODE_AT(unsigned int, node, 0x14) - (int)g_fadeStash;

    g_walkSlot6c = (unsigned int)left;
    if (left < 0) {
        left = 0;
        g_walkSlot6c = 0;
    }
    g_tickW1 = (unsigned int)(left + left);
    MK4_NODE_AT(unsigned int, node, 0x14) = (unsigned int)left;
    ClampMulShiftStore();                        /* jmp in the original */
}

/* 0x4260d0 - build the fade overlay */
void DispatcherChainRampClamp(void)
{
    unsigned int node, child;

    g_xformEntityIdx = 0x514f1cu >> 2;
    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) return;

    node = g_currentNodeIdx;
    MK4_NODE_AT(unsigned int, node, 0x54) = 0xf8300000u;
    g_walkSlot6c = 0x274;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x274;

    child = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x18);
    g_walkSlot6c = 1;
    g_pendingNodeType = child;
    MK4_NODE_AT(unsigned int, child, 0x1c) = 1;

    MStackBracket4_ListInsertZeroFill();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) return;
    MStackPush3LinkedListWalk();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4u) != 0) return;

    g_xformEntityIdx = MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x28);
    MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430();  /* jmp */
}

/* 0x426000 */
void InstallSelfPackedF80(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {
        g_fadeStash = g_slot70;
        DispatcherChainRampClamp();
        if (g_framePauseFlag != 0)
            return;
        if ((g_stateBits8c & 4u) == 0) {
            MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x10) = FADE_STEP_VA;
            MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x14) = 0x80;
            g_slot70 = g_fadeStash;
            g_walkSlot6c = 0x80;
            DivBy();
            if (g_framePauseFlag != 0)
                return;
            g_walkSlot6c += 6;
            g_pendingNodeType = g_walkSlot6c;
            MK4_NODE_AT(unsigned int, g_baseSel, 8) = FADE_VA;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
            g_framePauseFlag = 1;
            return;
        }
    }
    g_tickW1 = 0;
    StackPopDispatchTagged();                    /* jmp in the original */
}

#endif /* NON_MATCHING */
