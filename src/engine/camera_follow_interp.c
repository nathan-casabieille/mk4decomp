/**
 * PendingMatch_ThreeMul10Stores - 0x00432110 (1412b game.fight): the
 * camera-follow interpolator, and the last thing between the converted
 * fight scene and a framed arena. WalkTowardTargetFsm hands it the
 * follow state on its converged branch; without it the camera record
 * keeps the zeroes BulkSlotInit left and sits in the fighters' own
 * plane with no pull-back at all.
 *
 * A 4-state machine on the controller node's +0x84 command word
 * (jump table at 0x432684 -> states 0,1,2,3 = entries 0x432308,
 * 0x432140, 0x432203, 0x432221):
 *
 *   state 0 (entry): pick the spline pair by the shot length at +0x30 -
 *     >= 0x3d frames: 0x4e3ae0 / 0x4e3b38
 *     >= 0x1a       : 0x4e3b90 / 0x4e3bc0
 *     >= 0x0b       : 0x4e3bf0 / 0x4e3c08
 *     else          : 0x4e3c20 for all four slots
 *     (packed into the controller's +0x68/+0x6c/+0x70/+0x74), then
 *     take the delta from the camera's own position to the aim vector
 *     (TripleSubVec3 into 0x541f98), run the two DiffMul10Loop passes
 *     that turn the spline into per-frame position and angle steps,
 *     wrap the angles (TripleMod411262), shortest-path them
 *     (TripleArrayDiffClamp), and prime the cursors and the countdown.
 *   state 1: count the shot down; at zero copy the controller's
 *     +0x4c..+0x60 block into the camera record's +0x6c..+0x80 and
 *     re-arm as state 2. Otherwise fall into the per-frame step.
 *   state 2: advance both cursors by 2 and step.
 *   state 3: count down, step, and at zero re-arm as state 4 (which
 *     falls off the jump table into the cleanup tail).
 *   default (cmd > 3): zero the three fields and pop the queue.
 *
 * The per-frame step is the same pair either way: ThreeMul10Stores from
 * cursor A into the camera's +0x6c (position) and from cursor B into
 * its +0x78 (angles), each consuming one word.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void ThreeMul10Stores(void);
extern void TripleSubVec3(void);
extern void TripleMod411262(void);
extern void TripleArrayDiffClamp(void);
extern void DiffMul10Loop(void);
extern void PendingMatch_ZeroThreeFields6c_then_ZeroThreeSlots(void);
extern void StackPopDispatchTagged(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50          (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_curA            (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_curB            (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_countdown7c     (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_camScratch98    (*(unsigned int *)MK4_VA(unsigned int, 0x541f98u))

/* re-install self on the controller node and yield the frame */
static void cfi_yield(unsigned int cam, unsigned int next_cmd,
                      unsigned int pending)
{
    MK4_NODE_AT(unsigned int, cam, 8) = 0x432110u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = next_cmd;
    g_pendingNodeType = pending;
    g_framePauseFlag = 1;
}

/* one frame of the follow step: position from cursor A, angles from
 * cursor B, each consuming a word. Returns non-zero if paused. */
static int cfi_step(unsigned int cam)
{
    g_currentNodeIdx = g_groupHead + 0x1b;
    g_xformEntityIdx = cam + 0x13;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(g_curA * 4);
    g_curA += 1;
    ThreeMul10Stores();
    if (g_framePauseFlag != 0)
        return 1;

    g_currentNodeIdx = g_groupHead + 0x1e;
    g_xformEntityIdx = cam + 0x16;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(g_curB * 4);
    g_curB += 1;
    ThreeMul10Stores();
    return g_framePauseFlag != 0;
}

void PendingMatch_ThreeMul10Stores(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, len, a, b;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd > 3) {
        PendingMatch_ZeroThreeFields6c_then_ZeroThreeSlots();
        if (g_framePauseFlag != 0)
            return;
        StackPopDispatchTagged();
        return;
    }

    if (cmd == 0) {
        /* pick the spline pair by shot length */
        len = MK4_NODE_AT(unsigned int, cam, 0x30) - 1;
        if ((int)len >= 0x3c) {
            a = 0x4e3ae0u >> 2;  b = 0x4e3b38u >> 2;
            g_walkSlot6c = a;
            MK4_NODE_AT(unsigned int, cam, 0x68) = a;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x70) = a;
            g_walkSlot6c = b;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x6c) = b;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x74) = b;
        } else if ((int)len >= 0x19) {
            a = 0x4e3b90u >> 2;  b = 0x4e3bc0u >> 2;
            g_walkSlot6c = a;
            MK4_NODE_AT(unsigned int, cam, 0x68) = a;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x70) = a;
            g_walkSlot6c = b;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x6c) = b;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x74) = b;
        } else if ((int)len >= 0xa) {
            a = 0x4e3bf0u >> 2;  b = 0x4e3c08u >> 2;
            g_walkSlot6c = a;
            MK4_NODE_AT(unsigned int, cam, 0x68) = a;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x70) = a;
            g_walkSlot6c = b;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x6c) = b;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x74) = b;
        } else {
            a = 0x4e3c20u >> 2;
            g_walkSlot6c = a;
            MK4_NODE_AT(unsigned int, cam, 0x68) = a;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x6c) = a;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x70) = a;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x74) = a;
        }

        /* camera-to-aim delta into the scratch vec */
        g_currentNodeIdx = g_camScratch98;
        g_xformEntityIdx = g_baseSel + 0xd;
        g_pendingNodeType = g_groupHead + 0x15;
        TripleSubVec3();
        if (g_framePauseFlag != 0)
            return;

        /* position steps */
        g_xformEntityIdx = g_currentNodeIdx;
        g_currentNodeIdx = g_baseSel + 0x13;
        g_pendingNodeType = MK4_NODE_AT(unsigned int, g_baseSel, 0x68);
        g_slot50 = MK4_NODE_AT(unsigned int, g_baseSel, 0x6c);
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_baseSel, 0x30) - 1;
        DiffMul10Loop();
        if (g_framePauseFlag != 0)
            return;

        /* angle steps: wrap, shortest-path, then the same treatment */
        g_currentNodeIdx = g_baseSel + 0x10;
        TripleMod411262();
        if (g_framePauseFlag != 0)
            return;
        g_xformEntityIdx = g_currentNodeIdx;
        g_currentNodeIdx = g_camScratch98;
        g_pendingNodeType = g_groupHead + 0x18;
        TripleArrayDiffClamp();
        if (g_framePauseFlag != 0)
            return;

        g_xformEntityIdx = g_currentNodeIdx;
        g_currentNodeIdx = g_baseSel + 0x16;
        g_pendingNodeType = MK4_NODE_AT(unsigned int, g_baseSel, 0x70);
        g_slot50 = MK4_NODE_AT(unsigned int, g_baseSel, 0x74);
        g_walkSlot6c = MK4_NODE_AT(unsigned int, g_baseSel, 0x30) - 1;
        DiffMul10Loop();
        if (g_framePauseFlag != 0)
            return;

        /* prime the cursors and the countdown, then step this frame */
        {
            unsigned int base = g_baseSel;
            unsigned int ca = MK4_NODE_AT(unsigned int, base, 0x68);
            unsigned int cb = MK4_NODE_AT(unsigned int, base, 0x70);
            unsigned int n = MK4_NODE_AT(unsigned int, base, 0x30) - 1;
            unsigned int first = *(unsigned int *)MK4_PTR(ca * 4);

            g_slot80 = n - first;
            g_countdown7c = first;
            g_curA = ca + 2;
            g_curB = cb + 2;
        }
        if (cfi_step(cam))
            return;
        cfi_yield(cam, 1, 1);
        return;
    }

    if (cmd == 1) {
        g_countdown7c -= 1;
        if ((int)g_countdown7c > 0) {
            if (cfi_step(cam))
                return;
            cfi_yield(cam, 1, 1);
            return;
        }
        /* the shot is done: publish the controller's final block */
        {
            unsigned int base = g_baseSel, node = g_groupHead;
            static const unsigned char src[] = {0x4c,0x50,0x54,0x58,0x5c,0x60};
            static const unsigned char dst[] = {0x6c,0x70,0x74,0x78,0x7c,0x80};
            int i;

            for (i = 0; i < 6; i++) {
                unsigned int v = MK4_NODE_AT(unsigned int, base, src[i]);
                g_walkSlot6c = v;
                MK4_NODE_AT(unsigned int, node, dst[i]) = v;
            }
            g_curA = MK4_NODE_AT(unsigned int, base, 0x6c);
            g_curB = MK4_NODE_AT(unsigned int, base, 0x74);
            {
                unsigned int first = *(unsigned int *)MK4_PTR(g_curA * 4);
                g_countdown7c = first;
                g_pendingNodeType = g_slot80 - first;
            }
        }
        cfi_yield(cam, 2, g_pendingNodeType);
        return;
    }

    if (cmd == 2) {
        g_curA += 2;
        g_curB += 2;
        if (cfi_step(cam))
            return;
        cfi_yield(cam, 3, 1);
        return;
    }

    /* cmd == 3 */
    g_countdown7c -= 1;
    if ((int)g_countdown7c <= 0) {
        cfi_yield(cam, 4, 1);
        return;
    }
    if (cfi_step(cam))
        return;
    cfi_yield(cam, 3, 1);
}

#endif /* NON_MATCHING */
