/**
 * The bone allocator the skeleton build runs on - the two functions that
 * hand a fresh chain of bone nodes to a group, and the reason every
 * SkelAnimUpdaterCluster build produced bones whose local translation
 * (+0x30) stayed zero: with both of these hollow, the build linked no
 * bones of its own and the render collapsed the whole skeleton onto the
 * group origin (the long-standing "blob").
 *
 * MStackPush3LinkedListZeroWalk - 0x0049ce00 (368b): pop N nodes off the
 *   spare-node free chain at 0x537f24, where N is the count in 0x54206c.
 *   Each popped node has its +4..+0x18 fields zeroed. The chain head is
 *   published in 0x542044 and the walk stops early if the chain runs out,
 *   in which case 0x537f24 keeps whatever is left. The final node's link
 *   is cut and 0x537f24 takes the remainder. Returns the number actually
 *   taken in 0x54206c, and clears dirty bit 2 when that is non-zero.
 *   Three staging globals are bracketed on the mstack (0x54204c, 0x542074,
 *   0x542078).
 *
 * MStackPush3HelperCondToggle - 0x0049cf70 (259b): the caller-side wrapper.
 *   Brackets 0x542048 / 0x54204c / 0x542050, parks the parent (the node in
 *   0x542044) in 0x542050, runs the allocator, and - unless the allocation
 *   came back empty (dirty bit 2) - PREPENDS the fresh chain to the
 *   parent's +0x2c list: the old head goes into the new chain's tail slot
 *   and +0x2c takes the new head. CmpDivJmp tail-jumps here, so this is
 *   what SkelAnimUpdaterCluster reaches after it has divided the template
 *   count down to the bone count.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50           (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot74           (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78           (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_spareNodeChain   (*(unsigned int *)MK4_VA(unsigned int, 0x537f24u))

#define W(i)               (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define NODE_W(n, off)     MK4_NODE_AT(unsigned int, (n), (off))

static void bone_zero_fields(unsigned int node)
{
    NODE_W(node, 4)    = 0;
    NODE_W(node, 8)    = 0;
    NODE_W(node, 0xc)  = 0;
    NODE_W(node, 0x10) = 0;
    NODE_W(node, 0x14) = 0;
    NODE_W(node, 0x18) = 0;
}

void MStackPush3LinkedListZeroWalk(void)
{
    unsigned int top, head, node, taken, rest;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_pendingNodeType;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_slot74;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_slot78;

    head = g_spareNodeChain;
    g_currentNodeIdx = head;
    taken = 0;
    g_pendingNodeType = 0;

    if (head != 0) {
        g_slot74 = head;
        g_xformEntityIdx = head;
        bone_zero_fields(head);
        taken = 1;
        g_pendingNodeType = taken;

        while (g_walkCallback != taken) {
            node = W(g_xformEntityIdx);
            g_slot74 = node;
            if (node == 0)
                goto publish;          /* chain ran out: keep what we have */
            g_xformEntityIdx = node;
            bone_zero_fields(node);
            taken = g_pendingNodeType + 1;
            g_pendingNodeType = taken;
        }

        /* cut the tail: the remainder stays on the spare chain */
        rest = W(g_xformEntityIdx);
        g_slot74 = rest;
        W(g_xformEntityIdx) = 0;
        head = g_slot74;
publish:
        g_spareNodeChain = head;
    }

    g_walkCallback = g_pendingNodeType;

    top = g_matrixStackTop;
    g_slot78 = W(top);
    g_matrixStackTop = --top;
    g_slot74 = W(top);
    g_matrixStackTop = --top;
    g_pendingNodeType = W(top);
    g_matrixStackTop = top - 1;

    g_xformDirtyFlags |= 4;
    if (g_walkCallback != 0)
        g_xformDirtyFlags ^= 4;
}

void MStackPush3HelperCondToggle(void)
{
    unsigned int top, parent, old;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_xformEntityIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_pendingNodeType;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    W(top) = g_slot50;

    g_slot50 = g_currentNodeIdx;          /* the parent */
    MStackPush3LinkedListZeroWalk();
    if (g_framePauseFlag != 0)
        return;                           /* abort: the three pushes leak */

    if ((g_xformDirtyFlags & 4u) == 0) {
        parent = g_slot50;
        old = NODE_W(parent, 0x2c);
        g_pendingNodeType = old;
        W(g_xformEntityIdx) = old;        /* the fresh tail keeps the old head */
        NODE_W(g_slot50, 0x2c) = g_currentNodeIdx;
    }

    top = g_matrixStackTop;
    g_slot50 = W(top);
    g_matrixStackTop = --top;
    g_pendingNodeType = W(top);
    g_matrixStackTop = --top;
    g_xformEntityIdx = W(top);
    g_matrixStackTop = top - 1;

    g_xformDirtyFlags |= 4;
    if (g_currentNodeIdx != 0)
        g_xformDirtyFlags ^= 4;
}

#endif /* NON_MATCHING */
