/**
 * SpawnListBatchLoader (0x477710, 513b) - the scene populator.
 *
 * This is the function that fills an arena. Until now it was a weak no-op
 * returning 0, called exactly once per match, which is why the fight's
 * scene graph held nothing but the two fighters' 55 bone nodes: every
 * other object in the stage was spawned by this loop and the loop never
 * ran. skbgnd_g.geo loads fine (169111 bytes, node 0x141b26) and is
 * simply never linked into the graph.
 *
 * The shape is an INLINE PARAMETER STREAM. g_currentNodeIdx is not a node
 * here, it is a read cursor into a word list, and the function walks it
 * consuming six words per object:
 *
 *   [0] node type   -> g_eventQueueChild, and 0 terminates the list
 *   [1] a flag      -> g_eventQueueNotMask; non-zero runs ScaledOrStore
 *   [2] callback    -> group +0x30
 *   [3] x           -> group +0x54
 *   [4] y           -> group +0x58, biased by +0x40000
 *   [5] z           -> group +0x5c
 *
 * Per object it pushes the cursor on the matrix stack, calls
 * MStackPushDispatchBitGate to build the node and
 * MStackPushComplexCallPop_...00406430 to prepend it to the chain, then
 * pops the cursor back and writes the four fields. The +0x40000 on the y
 * word is a height bias, not a coordinate.
 *
 * Dirty-bit 2 on 0x54208c aborts the object mid-flight: that path pops
 * the cursor and then falls into the shared two-pop epilogue, so an
 * aborted object leaves the stack balanced three deep rather than two.
 *
 * After the list the original runs five tails - PollThenInit,
 * MultiGateDispatchCallJmp, EnduranceStateInitWalk, SpawnLeftRightProps
 * and BulletVolleySpawner. Those are still hollow here, so the arena's
 * side props and projectiles stay absent; the main spawn list does not
 * depend on them.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPushDispatchBitGate(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void ScaledOrStore_004903d0(void);
extern void PollThenInit(void);
extern void MultiGateDispatchCallJmp(void);
extern void EnduranceStateInitWalk(void);
extern void SpawnLeftRightProps(void);
extern void BulletVolleySpawner(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern int  Mul10Tail(int a, int b);

#define g_currentNodeIdx     (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx     (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightGroupHead     (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback       (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueNotMask  (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_eventQueueChild    (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_xformDirtyFlags    (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag     (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop     (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))

#define g_eventQueueCurMm    (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_dispatchArg        (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))
#define g_dlNalt1            (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_dlNalt2            (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_dispatchSave653    (*(unsigned int *)MK4_VA(unsigned int, 0x4d514cu))

/* The two prop slots are looked up in the table at 0x542b20, indexed by the
 * stage's own descriptor word. The base is kept as a PACKED index (VA >> 2)
 * because that is what the original holds in esi and what it stores into
 * g_currentNodeIdx - writing the unpacked address there would make every
 * downstream node deref land four times too far out. */
#define PROP_TABLE_BASE      (0x542b20u >> 2)

#define MSTACK_AT(i)         (*(unsigned int *)MK4_PTR((i) * 4u))
#define STREAM_AT(i)         (*(unsigned int *)MK4_PTR((i) * 4u))

/* Pop the cursor, then the group head - the epilogue both the normal and
 * the aborted path share (0x4778e9). */
static void SpawnList_PopTail(unsigned int top)
{
    g_currentNodeIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_fightGroupHead = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
}

void SpawnListBatchLoader(void)
{
    unsigned int cur = g_currentNodeIdx;
    unsigned int entry, top, group, v;

    entry = STREAM_AT(cur);
    cur++;
    g_eventQueueChild = entry;
    g_currentNodeIdx = cur;

    while (entry != 0) {
        v = STREAM_AT(cur);
        cur++;
        g_eventQueueNotMask = v;

        top = g_matrixStackTop + 1;
        g_currentNodeIdx = cur;
        g_matrixStackTop = top;
        MSTACK_AT(top) = cur;                 /* push the read cursor */

        g_xformEntityIdx = g_eventQueueChild;
        MStackPushDispatchBitGate();
        if (g_framePauseFlag != 0)
            return;

        if ((g_xformDirtyFlags & 4u) != 0) {
            /* aborted: restore the cursor, then the shared two-pop tail */
            top = g_matrixStackTop;
            g_currentNodeIdx = MSTACK_AT(top);
            top--;
            g_matrixStackTop = top;
            SpawnList_PopTail(top);
            return;
        }

        MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430();
        if (g_framePauseFlag != 0)
            return;

        top = g_matrixStackTop;
        cur = MSTACK_AT(top);                 /* pop the read cursor */
        top--;
        g_matrixStackTop = top;
        g_currentNodeIdx = cur;

        if (g_eventQueueNotMask != 0) {
            ScaledOrStore_004903d0();
            if (g_framePauseFlag != 0)
                return;
        }

        cur = g_currentNodeIdx;
        group = g_fightGroupHead;
        v = STREAM_AT(cur);
        cur++;
        g_walkCallback = v;
        g_currentNodeIdx = cur;
        MK4_NODE_AT(unsigned int, group, 0x30) = v;

        cur = g_currentNodeIdx;
        v = STREAM_AT(cur);
        cur++;
        g_currentNodeIdx = cur;
        g_walkCallback = v;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x54) = v;

        cur = g_currentNodeIdx;
        group = g_fightGroupHead;
        v = STREAM_AT(cur);
        cur++;
        g_walkCallback = v;
        v += 0x40000u;
        g_currentNodeIdx = cur;
        MK4_NODE_AT(unsigned int, group, 0x58) = v;

        cur = g_currentNodeIdx;
        v = STREAM_AT(cur);
        cur++;
        g_currentNodeIdx = cur;
        g_walkCallback = v;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x5c) = v;

        cur = g_currentNodeIdx;
        entry = STREAM_AT(cur);
        cur++;
        g_eventQueueChild = entry;
        g_currentNodeIdx = cur;
    }

    PollThenInit();
    if (g_framePauseFlag != 0) return;
    MultiGateDispatchCallJmp();
    if (g_framePauseFlag != 0) return;
    EnduranceStateInitWalk();
    if (g_framePauseFlag != 0) return;
    SpawnLeftRightProps();
    if (g_framePauseFlag != 0) return;
    BulletVolleySpawner();
    if (g_framePauseFlag != 0) return;

    SpawnList_PopTail(g_matrixStackTop);
}

/**
 * SpawnLeftRightProps (0x478140, 515b) - the two stage-side props.
 *
 * Called from SpawnListBatchLoader's tail once the main spawn list is
 * consumed. It brackets its work by pushing three globals on the matrix
 * stack, then places up to two objects looked up in the table at 0x542b20:
 *
 *   left  - descriptor g_dlNalt1 (0x537f48), fixed at x=-0xbc0000,
 *           y=-0x5e0000, callback 0x2b
 *   right - descriptor g_dlNalt2 (0x5380e0), x measured from the prop's own
 *           +0x0c field scaled by g_dispatchSave653 and subtracted from
 *           0xbc0000, same y, callback 0x2c
 *
 * A descriptor above 0x11 means the stage declares no props and the whole
 * body is skipped. A table entry of -1 means that side is empty: the left
 * slot then falls through to the right one rather than returning, which is
 * how a stage can carry a right prop and no left.
 *
 * On either side, a descriptor of exactly 8 overrides y to -0x5c0000 - a
 * per-prop height special case, applied after the default store.
 *
 * Dirty-bit 2 aborts to the shared three-pop epilogue; a frame pause
 * returns WITHOUT popping, which is the usual mstack-abort leak.
 */
void SpawnLeftRightProps(void)
{
    unsigned int base = PROP_TABLE_BASE;
    unsigned int top, idx, rec, node;
    int v;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_eventQueueCurMm;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_xformEntityIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_dispatchArg;

    g_currentNodeIdx = base;
    idx = g_dlNalt1;
    g_dispatchArg = idx;

    do {
        if (idx > 0x11u)
            break;                       /* stage declares no props */

        rec = *(unsigned int *)MK4_PTR((base + idx) * 4u);
        g_xformEntityIdx = rec;
        if (rec != 0xffffffffu) {
            DispatcherComplex260_FramePauseScaledStore();
            if (g_framePauseFlag != 0)
                return;                  /* paused: pops intentionally skipped */
            if ((g_xformDirtyFlags & 4u) != 0)
                break;

            node = g_currentNodeIdx;
            MK4_NODE_AT(unsigned int, node, 0x54) = 0xff440000u;
            node = g_currentNodeIdx;
            MK4_NODE_AT(unsigned int, node, 0x58) = 0xffa20000u;
            node = g_currentNodeIdx;
            g_walkCallback = 0x2bu;
            MK4_NODE_AT(unsigned int, node, 0x30) = 0x2bu;
            if (g_dispatchArg == 8u) {
                node = g_currentNodeIdx;
                g_walkCallback = 0xffa40000u;
                MK4_NODE_AT(unsigned int, node, 0x58) = 0xffa40000u;
            }
            MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0();
        }

        /* right-hand prop - reached whether or not the left one existed */
        idx = g_dlNalt2;
        g_currentNodeIdx = base;
        g_dispatchArg = idx;
        rec = *(unsigned int *)MK4_PTR((base + idx) * 4u);
        g_xformEntityIdx = rec;
        if (rec == 0xffffffffu)
            break;

        v = (int)MK4_NODE_AT(unsigned int, rec, 0xc);
        g_eventQueueCurMm = (unsigned int)v;
        v = Mul10Tail((int)g_dispatchSave653, v);
        g_eventQueueCurMm = (unsigned int)v;

        DispatcherComplex260_FramePauseScaledStore();
        if (g_framePauseFlag != 0)
            return;
        if ((g_xformDirtyFlags & 4u) != 0)
            break;

        node = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, node, 0x54) = 0xbc0000u - g_eventQueueCurMm;
        node = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, node, 0x58) = 0xffa20000u;
        node = g_currentNodeIdx;
        g_walkCallback = 0x2cu;
        MK4_NODE_AT(unsigned int, node, 0x30) = 0x2cu;
        if (g_dispatchArg == 8u) {
            node = g_currentNodeIdx;
            g_walkCallback = 0xffa40000u;
            MK4_NODE_AT(unsigned int, node, 0x58) = 0xffa40000u;
        }
        MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0();
    } while (0);

    top = g_matrixStackTop;
    g_dispatchArg = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_xformEntityIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_eventQueueCurMm = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
}

#endif /* NON_MATCHING */
