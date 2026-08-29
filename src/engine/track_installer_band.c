/**
 * PendingMatch_StackPopDispatchTagged_00466fc0 (2008b game.fight): the
 * per-record ANIMATION TRACK INSTALLER, and the round-start sequence
 * around it. This is what writes a packed track pointer into each
 * animation record's +4 - the field that otherwise keeps the stale
 * .data registry VA the shipped image ships with, which is why every
 * bone stays at its group's origin and each fighter renders as a blob.
 *
 * Four packed entries, each a self-installing state machine on the
 * controller node's +0x84:
 *
 *   0x466fc0  HeightSettle - drop the group's height toward
 *       0xfffff334 in 0xffffee15 steps (with a per-frame 0x28f nudge
 *       from 0x542084, three iterations armed on entry), folding the
 *       +0x78 spin back toward zero by +/-0x3333 each pass; when the
 *       three iterations are spent, clear +0x6c and pop the queue.
 *
 *   0x467100  TrackInstall - THE payload. State 1 walks four chains
 *       off the controller (+0x48, +0x50, +0x4c, +0x3c) with
 *       ChainDirtyBitWalker and, for the two records each walk leaves
 *       in 0x542048 / 0x54204c, installs a STATIC TRACK: entity+4 and
 *       entity+8 both take the packed pointer, 0x4e5700 / 0x4e5718 for
 *       the first pair and 0x4e5760 / 0x4e5778 for the second. Then it
 *       allocates the 0x26e node with 0x467600 as its callback and
 *       runs the two 0x4ec120 / 0x4ec1a0 store-two brackets over the
 *       +0x40 and +0x44 chains. State 0 (entry) builds those chains -
 *       countdown, bracket7, four ChainDirtyBitWalker passes stamping
 *       +0x40/+0x44/+0x48/+0x4c/+0x3c - through the IntroCombo cluster
 *       helpers, bailing to Thunk_ScaledNeg1SetPause whenever
 *       state-bit 2 comes up. State 2+ counts 0x54207c up to 0x78.
 *
 *   0x467600  RoundBanner - the announce beat: GatedWordPushCall(0x1e),
 *       yield 0x2f frames, then restore +0x64/+0x68, run the 0xc
 *       dispatch, allocate the 0x26f node with 0x467710 as callback,
 *       GatedWordPushCall(0x2c), latch 0x53a770 into 0x53a514 and
 *       yield 0xd3 frames.
 *
 *   0x467710  RoundBannerTick - two StorePauseImulShr16 beats with
 *       GatedWordPushCall(+0x1f) between them, then re-install.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void StackPopDispatchTagged(void);
extern void ChainDirtyBitWalker(void);
extern void AllocNode(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void MStackBracketedStoreTwoCall(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void ScaledAddrInit_IntroComboFsmCluster_004677c0(void);
extern void ScaledAddrInit_IntroComboFsmCluster_004677e0(void);
extern void ScaledOrStore_004677a0(void);
extern void Thunk_ScaledNeg1SetPause(void);
extern void GatedWordPushCall(void);
extern void GuardedSeq_DualPushCmp12Dispatch_then_ByteWordTableTaggedDispatch(void);
extern void StorePauseImulShr16(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58          (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_slot84          (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_eventArm        (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventLatch      (*(unsigned int *)MK4_VA(unsigned int, 0x53a514u))

static void ti_yield(unsigned int cam, unsigned int self_va,
                     unsigned int cmd, unsigned int pending)
{
    MK4_NODE_AT(unsigned int, cam, 8) = self_va;
    MK4_NODE_AT(unsigned int, cam, 0x84) = cmd;
    g_pendingNodeType = pending;
    g_framePauseFlag = 1;
}

/* walk one controller chain, then install a track pair on the two
 * records the walk leaves in entity / pending */
static int ti_walk(unsigned int chain_off)
{
    g_walkSlot6c = 1;
    g_groupHead = MK4_NODE_AT(unsigned int, g_baseSel, chain_off);
    ChainDirtyBitWalker();
    return g_framePauseFlag != 0;
}

static void ti_install_pair(unsigned int trackA, unsigned int trackB)
{
    unsigned int a = g_xformEntityIdx, b = g_pendingNodeType;
    unsigned int pa = trackA >> 2, pb = trackB >> 2;

    g_walkSlot6c = pa;
    MK4_NODE_AT(unsigned int, a, 4) = pa;
    MK4_NODE_AT(unsigned int, a, 8) = g_walkSlot6c;
    g_walkSlot6c = pb;
    MK4_NODE_AT(unsigned int, b, 4) = pb;
    MK4_NODE_AT(unsigned int, b, 8) = g_walkSlot6c;
}

void PendingMatch_StackPopDispatchTagged_00466fc0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, step;
    int h, spin;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    if (cmd == 0) {
        step = 0x28f;
        g_slot54 = 3;
        g_slot84 = step;
    } else {
        step = g_slot84;
    }

    h = (int)MK4_NODE_AT(unsigned int, g_groupHead, 0x58);
    g_walkSlot6c = (unsigned int)h;
    while (h > (int)0xfffff334) {
        MK4_NODE_AT(unsigned int, g_groupHead, 0x70) = 0;
        g_walkSlot6c = 0xfffff0a4u;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x58) = 0xfffff0a4u;

        spin = (int)MK4_NODE_AT(unsigned int, g_groupHead, 0x78);
        if (spin != 0) {
            if (spin > 0) {
                spin -= 0x3333;
                if (spin <= 0xccc) spin = 0;
            } else {
                spin += 0x3333;
                if (spin >= (int)0xfffff334) spin = 0;
            }
        }
        MK4_NODE_AT(unsigned int, g_groupHead, 0x78) = (unsigned int)spin;

        g_slot54 -= 1;
        if (g_slot54 == 0) {
            g_walkSlot6c = 0;
            MK4_NODE_AT(unsigned int, g_groupHead, 0x6c) = 0;
            StackPopDispatchTagged();
            return;
        }
        g_walkSlot6c = 0xffffee15u;
        MK4_NODE_AT(unsigned int, g_groupHead, 0x70) = 0xffffee15u;
        h = (int)MK4_NODE_AT(unsigned int, g_groupHead, 0x58);
        g_walkSlot6c = (unsigned int)h;
        step = g_slot84;
    }
    step += MK4_NODE_AT(unsigned int, g_groupHead, 0x70);
    g_walkSlot6c = step;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x70) = step;
    ti_yield(cam, 0x466fc0u, 1, 1);
}

void TrackInstall_00467100(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd, v;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd == 0) {                       /* build the four chains */
        g_slot54 = MK4_NODE_AT(unsigned int, cam, 0x64);
        g_slot58 = MK4_NODE_AT(unsigned int, cam, 0x68);
        MK4_NODE_AT(unsigned int, cam, 0x64) = g_slot54;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x68) = g_slot58;
        g_groupHead = g_slot54;
        MStackPush2RunCountdown();
        if (g_framePauseFlag != 0) return;
        MStackBracket7_DispatchAndChain();
        if (g_framePauseFlag != 0) return;

        g_walkSlot6c = 3;
        ChainDirtyBitWalker();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x40) = g_xformEntityIdx;
        g_walkSlot6c = 4;
        ChainDirtyBitWalker();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = g_xformEntityIdx;

        ScaledAddrInit_IntroComboFsmCluster_004677e0();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) != 0) { Thunk_ScaledNeg1SetPause(); return; }
        MK4_NODE_AT(unsigned int, g_baseSel, 0x48) = g_currentNodeIdx;
        ScaledAddrInit_IntroComboFsmCluster_004677c0();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) != 0) { Thunk_ScaledNeg1SetPause(); return; }
        MK4_NODE_AT(unsigned int, g_baseSel, 0x4c) = g_currentNodeIdx;

        g_xformEntityIdx = MK4_NODE_AT(unsigned int, g_baseSel, 0x40);
        ScaledAddrInit_IntroComboFsmCluster_004677e0();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) != 0) { Thunk_ScaledNeg1SetPause(); return; }
        ScaledOrStore_004677a0();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x50) = g_currentNodeIdx;
        ScaledAddrInit_IntroComboFsmCluster_004677c0();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 4) != 0) { Thunk_ScaledNeg1SetPause(); return; }
        ScaledOrStore_004677a0();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) = g_currentNodeIdx;
        ti_yield(cam, 0x467100u, 1, 5);
        return;
    }

    if (cmd == 1) {                       /* THE track installs */
        if (ti_walk(0x48)) return;
        g_pendingNodeType = g_xformEntityIdx;
        if (ti_walk(0x50)) return;
        ti_install_pair(0x4e5700u, 0x4e5718u);

        if (ti_walk(0x4c)) return;
        g_pendingNodeType = g_xformEntityIdx;
        if (ti_walk(0x3c)) return;
        ti_install_pair(0x4e5760u, 0x4e5778u);

        g_slot54 = MK4_NODE_AT(unsigned int, g_baseSel, 0x64);
        g_slot58 = MK4_NODE_AT(unsigned int, g_baseSel, 0x68);
        g_slot74 = 0x26e;
        g_pendingNodeType = 0x467600u;
        AllocNode();
        if (g_framePauseFlag != 0) return;
        v = 4;
    } else {
        v = g_slot7c + 1;
        g_slot7c = v;
        if (v > 0x78) v = 0x78;
        else goto have;
    }
    g_slot7c = v;
have:
    g_slot80 = g_slot7c >> 2;

    g_xformEntityIdx = MK4_NODE_AT(unsigned int, g_baseSel, 0x40) + 0xf;
    SetJmp_ZeroAndDirty4();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4) != 0) {
        g_slot70 = 0x4ec1a0u >> 2;
        MStackBracketedStoreTwoCall();
        if (g_framePauseFlag != 0) return;
    }
    g_slot70 = 0x4ec120u >> 2;
    MStackBracketedStoreTwoCall();
    if (g_framePauseFlag != 0) return;

    g_slot70 = 0x4ec1a0u >> 2;
    g_xformEntityIdx = MK4_NODE_AT(unsigned int, g_baseSel, 0x44) + 0xf;
    MStackBracketedStoreTwoCall();
    if (g_framePauseFlag != 0) return;
    SetJmp_ZeroAndDirty4();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 4) != 0) {
        g_slot70 = 0x4ec120u >> 2;
        MStackBracketedStoreTwoCall();
        if (g_framePauseFlag != 0) return;
    }
    ti_yield(g_baseSel, 0x467100u, 2, 3);
}

void RoundBanner_00467600(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, cam, 0x84);
    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;

    if (cmd != 0) {
        g_walkSlot6c = 0x1e;
        GatedWordPushCall();
        if (g_framePauseFlag != 0) return;
        ti_yield(cam, 0x467600u, 2, 0x2f);
        return;
    }
    MK4_NODE_AT(unsigned int, cam, 0x64) = g_slot54;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x68) = g_slot58;
    g_walkSlot6c = 0xc;
    GuardedSeq_DualPushCmp12Dispatch_then_ByteWordTableTaggedDispatch();
    if (g_framePauseFlag != 0) return;
    g_slot74 = 0x26f;
    g_pendingNodeType = 0x467710u;
    AllocNode();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0x2c;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    g_eventLatch = g_eventArm;
    ti_yield(cam, 0x467600u, 1, 0xd3);
}

void RoundBannerTick_00467710(void)
{
    unsigned int cam = g_baseSel;

    MK4_NODE_AT(unsigned int, cam, 0x84) = 0;
    g_walkSlot6c = 3;
    StorePauseImulShr16();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c += 0x1f;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0xf;
    StorePauseImulShr16();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c += 0xf;
    g_pendingNodeType = g_walkSlot6c;
    MK4_NODE_AT(unsigned int, cam, 8) = 0x467710u;
    MK4_NODE_AT(unsigned int, cam, 0x84) = 1;
    g_framePauseFlag = 1;
}


/* --- three leaves the band needs ---------------------------------- */

extern void TaggedSceneDispatch(int tag);
extern void StoreTwoCall(int fn, int arg);

#define g_depth64         (*(unsigned int *)MK4_VA(unsigned int, 0x541e64u))
#define g_lastWord98      (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_frame53a498     (*(unsigned int *)MK4_VA(unsigned int, 0x53a498u))
#define g_frame54358c     (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))

/* GatedWordPushCall - 0x00489f90 (91b): announce word `w` unless the
 * same word was announced less than one frame-count ago; the ids
 * 5..9, 0x17 and 0x19 are the ones subject to that debounce. Dispatches
 * the sound id from the u16 table at 0x4ec7a0. */
void GatedWordPushCall(void)
{
    int w = (int)g_walkSlot6c;

    if (w == 0x19 || w == 0x17 || (w >= 5 && w <= 9)) {
        if (w == (int)g_lastWord98) {
            if ((int)g_frame54358c <= (int)g_frame53a498 + 1)
                return;                      /* too soon - stay silent */
            goto emit;
        }
    }
    g_lastWord98 = (unsigned int)w;
    g_frame54358c = g_frame53a498;
emit:
    if (w < 0)
        return;
    TaggedSceneDispatch((int)*(unsigned short *)
                        MK4_VA(unsigned short, 0x4ec7a0u + (unsigned)w * 2u));
}

/* ScaledOrStore_004677a0 - 0x004677a0 (28b) */
void ScaledOrStore_004677a0(void)
{
    unsigned int v = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) | 1u;

    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34) = v;
}

/* MStackBracketedStoreTwoCall - 0x004714e0 (398b): guarded by a depth
 * counter at 0x541e64 (bails past 0x38), brackets four staging words,
 * runs StoreTwoCall(0x49ddf0, 0xc0) with the node/param pair swapped in,
 * and unless state-bit 0 came up copies the entity's first three words
 * into the node's +0x38/+0x3c/+0x40 and zeroes +0x44/+0x48/+0x4c. */
void MStackBracketedStoreTwoCall(void)
{
    unsigned int top;

    if ((int)g_depth64 > 0x38)
        return;
    top = g_matrixStackTop;
    *(unsigned int *)MK4_PTR(++top * 4) = g_slot7c;
    *(unsigned int *)MK4_PTR(++top * 4) = g_slot58;
    *(unsigned int *)MK4_PTR(++top * 4) = g_slot54;
    *(unsigned int *)MK4_PTR(++top * 4) = g_currentNodeIdx;
    g_matrixStackTop = top;

    g_slot54 = g_groupHead;
    g_slot58 = g_slot70;
    g_slot7c = 0xc1;
    StoreTwoCall(0x49ddf0, 0xc0);

    if ((g_stateBits8c & 1) == 0) {
        unsigned int ent = g_xformEntityIdx, node = g_currentNodeIdx;
        unsigned int v;

        v = *(unsigned int *)MK4_PTR(ent * 4);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, node, 0x38) = v;
        v = MK4_NODE_AT(unsigned int, ent, 4);
        g_walkSlot6c = v;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = v;
        v = MK4_NODE_AT(unsigned int, ent, 8);
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x40) = v;
        g_walkSlot6c = 0;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x44) = 0;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x48) = 0;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x4c) = 0;
    }

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top-- * 4);
    g_slot54 = *(unsigned int *)MK4_PTR(top-- * 4);
    g_slot58 = *(unsigned int *)MK4_PTR(top-- * 4);
    g_slot7c = *(unsigned int *)MK4_PTR(top-- * 4);
    g_matrixStackTop = top;
}

#endif /* NON_MATCHING */
