/**
 * The post-spawn attach pair TripleStateSwapCall drives - both were only
 * present in the matching blob TUs, so the native build resolved them to
 * weak autostubs and the spawned player never joined the scene lists.
 *
 * MStackPush2BiasResolveChain - 0x0048cca0 (347b game.download)
 *   mstack-push2 (currentNodeIdx, xformEntityIdx), snapshot walk/_74, run
 *   Helper_DownloadSetup; then resolve the slot in the table at 0x541de8
 *   (packed base + slot index from 0x542070): occupied -> entity =
 *   0x5114b4>>2 (the shared record), empty -> entity = node[+0xc]
 *   (or node[+0x10] when the _74 flag is up); run GuardedChainCopySetFlag;
 *   finally, unless state-bit 2 is up, mirror node[+0x1c] into the
 *   character-owner node's +0x3c for whichever of P1/P2 this character
 *   index (snapshot in walk) belongs to. Pops restore entity+node; every
 *   pause exit leaks the pushes (the usual abort pattern).
 *
 * GuardedChainCopySetFlag - 0x0048c480 (134b game.download)
 *   MStackPushDispatchBitGate; bail on pause or state-bit 2; then
 *   PushDualDerefClearPop, copy group-head[+0x58] into [+0x48] (the
 *   vertex-cache slot), stamp +0x64 = 0x4b6db, MStackPushTwoEntryChainCall,
 *   PushPopScaled18, prepend the group into the pair1 list via the 0x406340
 *   wrapper, and clear state-bit 2.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void Helper_DownloadSetup(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPushTwoEntryChainCall(void);
extern void PushPopScaled18(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_playerSlot      (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_setupFlag74     (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_charP1          (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_charP2          (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_ownerP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f78u))
#define g_ownerP2         (*(unsigned int *)MK4_VA(unsigned int, 0x541de0u))

/* PushDualDerefClearPop - 0x004092a0 (116b): push currentNodeIdx, walk
 * group-head[+0x1c][+0x10], move that node's +0x34 into the group head's
 * +0x58 (the cache GuardedChainCopySetFlag then promotes to +0x48),
 * clearing the source and the 0x54206c staging word; pop. */
void PushDualDerefClearPop(void)
{
    unsigned int top, head, n;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    head = g_groupHead;
    n = MK4_NODE_AT(unsigned int, head, 0x1c);
    g_currentNodeIdx = n;
    n = MK4_NODE_AT(unsigned int, n, 0x10);
    g_currentNodeIdx = n;
    MK4_NODE_AT(unsigned int, head, 0x58) = MK4_NODE_AT(unsigned int, n, 0x34);
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, n, 0x34) = 0;

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

void GuardedChainCopySetFlag(void)
{
    unsigned int head;

    MStackPushDispatchBitGate();
    if (g_framePauseFlag != 0)
        return;
    if ((g_stateBits8c & 4) != 0)
        return;
    PushDualDerefClearPop();
    if (g_framePauseFlag != 0)
        return;

    head = g_groupHead;
    MK4_NODE_AT(unsigned int, head, 0x48) = MK4_NODE_AT(unsigned int, head, 0x58);
    g_walkSlot6c = 0x4b6dbu;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x64) = 0x4b6dbu;

    MStackPushTwoEntryChainCall();
    if (g_framePauseFlag != 0)
        return;
    PushPopScaled18();
    if (g_framePauseFlag != 0)
        return;
    MStackCall_MStackPush2ChainPrepend_00406340();
    if (g_framePauseFlag != 0)
        return;
    g_stateBits8c &= ~4u;
}

void MStackPush2BiasResolveChain(void)
{
    unsigned int top, node, walk, f74, slotRec;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_xformEntityIdx;

    walk = g_walkSlot6c;
    f74  = g_setupFlag74;

    Helper_DownloadSetup();
    if (g_framePauseFlag != 0)
        return;                     /* abort: the two pushes leak */

    node = g_currentNodeIdx;
    slotRec = (0x541de8u >> 2) + g_playerSlot;
    g_xformEntityIdx = slotRec;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(slotRec * 4);
    if (g_walkSlot6c == 0) {
        g_xformEntityIdx = MK4_NODE_AT(unsigned int, node, 0xc);
        g_walkSlot6c = f74;
        if (f74 != 0)
            g_xformEntityIdx = MK4_NODE_AT(unsigned int, node, 0x10);
    } else {
        g_xformEntityIdx = 0x5114b4u >> 2;
    }

    GuardedChainCopySetFlag();
    if (g_framePauseFlag != 0)
        return;

    if ((g_stateBits8c & 4) == 0) {
        g_currentNodeIdx = node;
        g_walkSlot6c = walk;
        if (walk == g_charP1) {
            g_xformEntityIdx = g_ownerP1;
            MK4_NODE_AT(unsigned int, g_ownerP1, 0x3c) =
                MK4_NODE_AT(unsigned int, node, 0x1c);
        }
        g_walkSlot6c = walk;
        if (walk == g_charP2) {
            unsigned int link;
            g_xformEntityIdx = g_ownerP2;
            link = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x1c);
            g_walkSlot6c = link;
            MK4_NODE_AT(unsigned int, g_ownerP2, 0x3c) = link;
        }
    }

    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

#endif /* NON_MATCHING */
