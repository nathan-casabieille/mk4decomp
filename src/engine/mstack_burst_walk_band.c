/**
 * Three mstack-bracketed leaves the fight runs every frame, all weak
 * no-ops until MK4_TRACE_STUBS showed them being called 42-50 times a
 * match without ever appearing in the dispatch trace.
 *
 * MStackPush2LLWalkCompare (0x4069b0, 365b) walks the list whose packed
 * base is 0x5420a0, ticking each entry through Helper_TickAlt. The walk
 * continues while a tick leaves g_currentNodeIdx at ZERO and stops on the
 * first entry that does not - so it is a find-first, not a for-each. Its
 * symbols.yaml size covers a packed helper at 0x406af0 that shares no code
 * with the body; that one is split out here rather than inlined.
 *
 * MStackPush2DirtyCall (0x427f90, 156b) brackets the same walk and, when
 * it stops on a live node, links it in through MStackPush2ChainLLInsert.
 *
 * MStackPush2Burst6Init (0x405450, 348b) zeroes two runs through the node
 * cursor - six dwords at the cursor, then thirteen more six dwords along -
 * and writes g_baseSel into +0x14. The original spells both runs as
 * compiler-unrolled four-at-a-time blocks plus a rep stosd remainder;
 * they are plain memsets and are written as loops.
 *
 * Dirty-bit 2 is used as a scratch throughout: set before a deref, xored
 * back out when the value survives, so a caller that finds it still set
 * knows the walk stopped early.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void Helper_TickAlt(void);
extern void MStackPushChainStepIndex(void);
extern void MStackPush2ChainLLInsert(void);

void MStackPush2LLWalkCompare(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCurMm  (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_xformLoopCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))
#define g_bootChainState4  (*(unsigned int *)MK4_VA(unsigned int, 0x541eb0u))
#define g_dispatchSave652  (*(unsigned int *)MK4_VA(unsigned int, 0x4d513cu))

#define MSTACK_AT(i)       (*(unsigned int *)MK4_PTR((i) * 4u))
#define WALK_LIST_BASE     (0x5420a0u >> 2)

/* 0x406af0 - the walk's COMPARE, packed inside MStackPush2LLWalkCompare's
 * own symbol and reached only as the callback Helper_TickAlt dispatches by
 * VA (g_dispatchSave652 holds 0x406af0), so it needs a codeptr_extras entry
 * or every walk silently matches nothing. It reports "this node's kind
 * (+0x30) equals the tag in slot70" in dirty bit 0.
 *
 * Unresolved, this is what a missing tag search looks like from outside:
 * SaveCallRestoreOrXor always returns "not found", ThrowFlowSetupCluster
 * takes a zero group head, and DirtyDoubleDeref then indexes head[+0x1c]
 * off the null node and faults - the character select's 900-frame SIGSEGV. */
void WalkCompareKind_00406af0(void)
{
    g_xformDirtyFlags &= ~1u;
    if (g_eventQueueCurMm == MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30))
        g_xformDirtyFlags |= 1u;
}

void MStackPush2LLWalkCompare(void)
{
    unsigned int top, cursor, node, saved;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_eventQueueCurMm;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_xformEntityIdx;

    saved = g_walkCallback;
    g_xformEntityIdx = WALK_LIST_BASE;

    for (;;) {
        cursor = g_xformEntityIdx;
        node = MSTACK_AT(cursor);
        g_xformEntityIdx = cursor + 1;
        g_xformDirtyFlags |= 4u;
        g_currentNodeIdx = node;
        if (node == 0)
            break;
        g_xformDirtyFlags ^= 4u;

        node = *(unsigned int *)MK4_PTR(node * 4u);
        g_currentNodeIdx = node;
        g_eventQueueCurMm = saved;
        g_walkCallback = g_dispatchSave652;
        Helper_TickAlt();
        if (g_framePauseFlag != 0)
            return;

        g_xformDirtyFlags |= 4u;
        saved = g_eventQueueCurMm;
        g_walkCallback = saved;
        node = g_currentNodeIdx;
        if (node == 0)
            continue;                 /* nothing there - keep walking */
        g_xformDirtyFlags ^= 4u;
        break;                        /* found a live node - stop */
    }

    top = g_matrixStackTop;
    g_xformEntityIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_eventQueueCurMm = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_xformDirtyFlags |= 4u;
    if (node != 0)
        g_xformDirtyFlags ^= 4u;
}

/* Packed inside MStackPush2LLWalkCompare's symbols.yaml size, but a
 * separate entry point: clear dirty bit 0, then set it again only if the
 * cursor's +0x30 still matches the saved value. */
void LLWalkCompareTail_00406af0(void)
{
    unsigned int node = g_currentNodeIdx;

    g_xformDirtyFlags &= 0xfffffffeu;
    if (g_eventQueueCurMm == MK4_NODE_AT(unsigned int, node, 0x30))
        g_xformDirtyFlags |= 1u;
}

void MStackPush2DirtyCall(void)
{
    unsigned int top, node;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_walkCallback;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;

    MStackPush2LLWalkCompare();
    if (g_framePauseFlag != 0)
        return;

    g_xformDirtyFlags |= 4u;
    node = g_currentNodeIdx;
    if (node != 0) {
        g_xformDirtyFlags ^= 4u;
        MStackPush2ChainLLInsert();
        if (g_framePauseFlag != 0)
            return;
    }

    top = g_matrixStackTop;
    g_currentNodeIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_walkCallback = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
}

void MStackPush2Burst6Init(void)
{
    unsigned int top, cursor, saved;
    unsigned int i;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_xformLoopCounter;

    g_currentNodeIdx = g_bootChainState4;
    MStackPushChainStepIndex();
    if (g_framePauseFlag != 0)
        return;

    if ((g_xformDirtyFlags & 4u) == 0) {
        cursor = g_currentNodeIdx;
        for (i = 0; i < 6u; i++)
            MSTACK_AT(cursor + i) = 0;

        cursor += 6u;
        g_xformLoopCounter = 0xd;
        g_currentNodeIdx = cursor;
        g_walkCallback = 0;
        for (i = 0; i < 0xdu; i++)
            MSTACK_AT(cursor + i) = 0;

        cursor -= 6u;
        g_currentNodeIdx = cursor;
        MK4_NODE_AT(unsigned int, cursor, 0x14) = g_baseSel;
    }

    saved = g_currentNodeIdx;
    g_xformEntityIdx = saved;
    top = g_matrixStackTop;
    g_xformLoopCounter = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_currentNodeIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;

    g_xformDirtyFlags |= 4u;
    if (saved != 0) {
        g_xformDirtyFlags ^= 4u;
        return;
    }
    g_xformEntityIdx = 0;
}

#endif /* NON_MATCHING */
