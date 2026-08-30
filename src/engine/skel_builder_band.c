/**
 * The SKELETON BUILDER band (0x49d080..0x49dbf0) - what fills the bones'
 * bind fields at character creation, i.e. the source of the offsets whose
 * absence keeps every fighter a blob.
 *
 *   SkelAnimUpdaterCluster (0x49d940, 673b): per TEMPLATE - the stream at
 *       g_xformEntityIdx: [0]=record id, [1]=node type, [2]=word count,
 *       [3..]=payload - find the record (PushSetXfmMaskCallPop on
 *       template[0]), copy the controller's +0x38..+0x4c block onto the
 *       group's +0x54..+0x74 (SixCrossStores - THE group position
 *       install), hang the particle node, AllocNode(template[1]), prepend
 *       it, set child+0x20 bit 14, derive the per-bone count from
 *       template[2] (/3 when >= 3, then the SetJmp gate picks (n+1)/2 or
 *       n, then CmpDivJmp halves anything above 2), walk the new chain
 *       feeding template[3..] triples into each record's +4/+8/+0xc
 *       (LinkedListFieldAdd), and run PoseTreeBlendWalker over the
 *       result. V2 at 0x49dbf0 is the same shape against the V2 pump; it
 *       stays unconverted until something asks for it.
 *
 *   SkelPump_0049db40: the self-installing FSM that drives the builder
 *       over the tag<<24|template list at the 0x542058 cursor - a list
 *       the download band ALREADY BUILDS natively (verified in a live
 *       dump: 0x149285, 0x14e01c, 0-terminated). Only the dispatch of
 *       this pump is missing, because its installer lives in
 *       MatchStartFsmCluster, inside the match-init band the MK4_BOOT_*
 *       shortcuts skip.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush8(void);
extern void MStackPop8(void);
extern void PushSetXfmMaskCallPop(void);
extern void AllocNode(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackCall_MStackPush2ChainLLInsert(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void PoseTreeBlendWalker(void);
extern void Thunk_Thunk_0049cbc0_0049cbb0(void);
extern void MStackPush3HelperCondToggle(void);

void SkelAnimUpdaterCluster(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType  (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventQueueTotal  (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_skelListCursor   (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCur    (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_lit16_542074     (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_particleNode     (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))

#define MSTACK_AT(i)       (*(unsigned int *)MK4_PTR((i) * 4u))
#define W(i)               (*(unsigned int *)MK4_PTR((unsigned int)(i) * 4u))
#define NODE_W(n,off)      MK4_NODE_AT(unsigned int, (n), (off))

void CmpDivJmp(void)
{
    int v = (int)g_walkCallback;

    if (v > 2) {
        v = (v - (v >> 31)) >> 1;        /* signed /2, truncating */
        g_walkCallback = (unsigned int)v;
    }
    MStackPush3HelperCondToggle();       /* jmp in the original */
}

void SixCrossStores(void)
{
    unsigned int cam = g_baseSel;
    unsigned int grp = g_fightGroupHead;
    unsigned int v;

    v = NODE_W(cam, 0x38); g_walkCallback = v; NODE_W(grp, 0x54) = v;
    v = NODE_W(cam, 0x3c); g_walkCallback = v; NODE_W(grp, 0x58) = v;
    v = NODE_W(cam, 0x40); g_walkCallback = v; NODE_W(grp, 0x5c) = v;
    v = NODE_W(cam, 0x44); g_walkCallback = v; NODE_W(grp, 0x6c) = v;
    v = NODE_W(cam, 0x48); g_walkCallback = v; NODE_W(grp, 0x70) = v;
    v = NODE_W(cam, 0x4c); g_walkCallback = v; NODE_W(grp, 0x74) = v;
}

void LinkedListFieldAdd_StoreDoubleNegPauseSubStore(void)
{
    unsigned int node, ent, v;

    node = g_currentNodeIdx;
    g_walkCallback = node;
    if (node == 0)
        return;

    do {
        ent = g_xformEntityIdx;

        v = W(ent);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        NODE_W(node, 4) = v;

        v = *(unsigned int *)MK4_PTR(ent * 4u + 4u);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        NODE_W(node, 8) = v;

        v = *(unsigned int *)MK4_PTR(ent * 4u + 8u);
        g_walkCallback = v;
        if (v != 0) {
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag != 0) return;
            v = g_walkCallback;
        }
        NODE_W(node, 0xc) = v;

        node = W(node);
        g_walkCallback = node;
        g_currentNodeIdx = node;
    } while (node != 0);
}

void SkelAnimUpdaterCluster(void)
{
    unsigned int tmpl, child, count, v;

    MStackPush8();
    if (g_framePauseFlag != 0)
        return;

    tmpl = g_xformEntityIdx;
    g_eventQueueTotal = tmpl;
    g_walkCallback = W(tmpl);            /* template[0] = record id */
    PushSetXfmMaskCallPop();
    if (g_framePauseFlag != 0)
        return;
    if ((g_xformDirtyFlags & 4u) != 0)
        goto pop_out;

    NODE_W(g_fightGroupHead, 0x30) = g_eventQueueNotMask;
    SixCrossStores();
    g_walkCallback = g_particleNode;
    NODE_W(g_fightGroupHead, 0x3c) = g_particleNode;

    tmpl = g_eventQueueTotal;
    g_lit16_542074 = g_eventQueueNotMask;
    g_pendingNodeType = *(unsigned int *)MK4_PTR(tmpl * 4u + 4u);
    AllocNode();
    if (g_framePauseFlag != 0)
        return;
    if ((g_xformDirtyFlags & 1u) != 0) {
        MStackCall_MStackPush2ChainLLInsert();
        if (g_framePauseFlag != 0) return;
        goto pop_out;
    }

    g_currentNodeIdx = g_fightGroupHead;
    MStackCall_MStackPush2ChainPrepend_00406340();
    if (g_framePauseFlag != 0)
        return;

    child = NODE_W(g_fightGroupHead, 0x18);
    g_currentNodeIdx = child;
    v = NODE_W(child, 0x20) | 0x4000u;
    g_walkCallback = v;
    NODE_W(child, 0x20) = v;

    count = *(unsigned int *)MK4_PTR(g_eventQueueTotal * 4u + 8u);
#ifdef TARGET_SDL
    /* MK4_TRACE_SKEL: one line per skeleton build - the group it builds
     * onto, the template stream, its payload count, and the first bone.
     * Two fighters must produce two builds with the same shape; a build
     * that comes back with a short or empty payload is a skeleton whose
     * bind offsets (bone +0x30) will stay zero. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f = -1; static int n;
      if (f < 0) f = getenv("MK4_TRACE_SKEL") != 0;
      if (f && n < 24) { n++;
          SDL_Log("SKEL group=%x tmpl=%x rec=%x count=%x child=%x",
                  g_fightGroupHead, g_eventQueueTotal,
                  *(unsigned int *)MK4_PTR(g_eventQueueTotal * 4u),
                  count, child); } }
#endif
    g_eventQueueCur = count;
    if ((int)count >= 3)
        g_eventQueueCur = count = (unsigned int)((int)count / 3);
    SetJmp_ZeroAndDirty4();
    if (g_framePauseFlag != 0)
        return;
    if ((g_xformDirtyFlags & 4u) == 0)
        g_eventQueueCur = (g_eventQueueCur + 1u) >> 1;
    g_walkCallback = g_eventQueueCur;
    if (g_eventQueueCur == 0)
        goto pop_out;
    CmpDivJmp();
    if (g_framePauseFlag != 0)
        return;
    if ((g_xformDirtyFlags & 4u) != 0)
        goto pop_out;

    {
        unsigned int top = g_matrixStackTop + 1;
        g_matrixStackTop = top;
        MSTACK_AT(top) = g_currentNodeIdx;
    }
    g_xformEntityIdx = g_eventQueueTotal + 3u;
    LinkedListFieldAdd_StoreDoubleNegPauseSubStore();
    if (g_framePauseFlag != 0)
        return;

    {
        unsigned int top = g_matrixStackTop;
        g_currentNodeIdx = MSTACK_AT(top);
        g_matrixStackTop = top - 1;
    }
    g_xformEntityIdx = g_eventQueueTotal;
    PoseTreeBlendWalker();
    if (g_framePauseFlag != 0)
        return;

pop_out:
    g_xformEntityIdx = g_eventQueueTotal;
    MStackPop8();                        /* jmp in the original */
}

/* the pump at 0x49db40: walk the tag<<24|template list at the 0x542058
 * cursor, one SkelAnimUpdaterCluster per live entry; a tagged entry
 * re-installs the pump on the controller and yields. */
void SkelPump_0049db40(void)
{
    unsigned int cam = g_baseSel;
    unsigned int w, ent;
    int tag;

    NODE_W(cam, 0x84) = 0;
    for (;;) {
        unsigned int cur = g_skelListCursor;

        w = W(cur);
        g_walkCallback = w;
        g_skelListCursor = cur + 1u;
        if (w == 0) {
            Thunk_Thunk_0049cbc0_0049cbb0();
            return;
        }
        tag = (int)w >> 24;              /* SIGNED shift, as the original */
        ent = w & 0xffffffu;
        g_eventQueueCur = (unsigned int)tag;
        g_xformEntityIdx = ent;
        g_pendingNodeType = (unsigned int)tag;
        g_walkCallback = ent;
        if (ent != 0) {
            SkelAnimUpdaterCluster();
            if (g_framePauseFlag != 0)
                return;
        }
        if (g_pendingNodeType == 0)
            continue;
        NODE_W(cam, 8) = 0x49db40u;
        NODE_W(cam, 0x84) = 1;
        g_framePauseFlag = 1;
        return;
    }
}

#endif /* NON_MATCHING */
