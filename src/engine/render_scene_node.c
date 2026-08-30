/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_eq;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1502;
extern unsigned int g_dispatchSave1503;
extern unsigned int g_dispatchSave1525;
extern unsigned int g_dispatchSave1526;
extern unsigned int g_dispatchSave1527;
extern unsigned int g_dispatchSave1528;
extern unsigned int g_dispatchSave1529;
extern unsigned int g_dispatchSave1554;
extern unsigned int g_dispatchSave1555;
extern unsigned int g_dispatchSave1556;
extern unsigned int g_dispatchSave1557;
extern unsigned int g_dispatchSave1558;
extern unsigned int g_dispatchSave1559;
extern unsigned int g_dispatchSave1570;
extern unsigned int g_dispatchSave1572;
extern unsigned int g_dispatchSave1573;
extern unsigned int g_dispatchSave1575;
extern unsigned int g_dispatchSave1576;
extern unsigned int g_dispatchSave1577;
extern unsigned int g_dispatchSave1333;
#endif
extern void BboxProjectAndStash(void);
extern void BillboardChainRender(void);
extern void BillboardSheetDualEmit(void *rec, int q);
extern void DirtyBitTripleWriteOrCall(void);
extern int  DirtyTestScaledCopy(void);
extern void DrawMeshBlock(unsigned int recVA, unsigned int f, unsigned short w);
extern void LeaScaledCall(int a);
extern void MStackPushCallCallPop_func_00405dd0(void);
extern void MatrixTransform3x3Q12(short *src, short *dst);
extern void MovesPanelEmit(void);
extern void TransformAccumulate(void);
extern void TristripBatchEmit2(unsigned int recVA, unsigned int f, unsigned short w);
extern void TristripBatchEmit3Cap(unsigned int recVA, unsigned int f, unsigned short w);
extern void TristripBatchEmit(unsigned int recVA, unsigned int f, unsigned short w);
extern void VertexQuadBuilder(int a, unsigned int b);
extern void VibrationFrameUpdate(int node);
extern void VtableDispatchSetDirty(int node);
extern void WtSnapshotPushCall(void);
extern void ZBucketClampStore(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
#include "portable/code_va.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx, g_currentNodeFlags, g_walkCallback, g_baseSel;
extern unsigned int g_cj_0054205c, g_cj_00542054, g_dualC, g_dualD;
extern unsigned int g_eventQueuePending, g_eventQueueCurrent, g_eventQueueWorkType;
extern unsigned int g_xformDirtyFlags, g_framePauseFlag, g_eq;
extern unsigned int g_dispatchSave1501, g_dispatchSave1502, g_dispatchSave1503;
extern unsigned int g_dispatchSave1525, g_dispatchSave1526, g_dispatchSave1527;
extern unsigned int g_dispatchSave1528, g_dispatchSave1529;
extern unsigned int g_dispatchSave1554, g_dispatchSave1555, g_dispatchSave1556;
extern unsigned int g_dispatchSave1557, g_dispatchSave1558;
extern unsigned int g_dispatchSave1559, g_dispatchSave1570, g_dispatchSave1572;
extern unsigned int g_dispatchSave1573, g_dispatchSave1575, g_dispatchSave1576;
extern unsigned int g_dispatchSave1577;
extern unsigned int g_mat3x3_007af990, g_mat3x3_007af994, g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c, g_mat3x3_007af9a0;
extern unsigned int g_tickW1, g_tickX1, g_tickFlagZ;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1333 (*(unsigned int *)MK4_VA(unsigned int, 0xf00004u))
#define g_dispatchSave1501 (*(unsigned int *)MK4_VA(unsigned int, 0xab4398u))
#define g_dispatchSave1502 (*(unsigned int *)MK4_VA(unsigned int, 0xab439cu))
#define g_dispatchSave1503 (*(unsigned int *)MK4_VA(unsigned int, 0xab43a0u))
#define g_dispatchSave1525 (*(unsigned int *)MK4_VA(unsigned int, 0xab4838u))
#define g_dispatchSave1526 (*(unsigned int *)MK4_VA(unsigned int, 0xab483cu))
#define g_dispatchSave1527 (*(unsigned int *)MK4_VA(unsigned int, 0xab4840u))
#define g_dispatchSave1528 (*(unsigned int *)MK4_VA(unsigned int, 0xab4844u))
#define g_dispatchSave1529 (*(unsigned int *)MK4_VA(unsigned int, 0xab4848u))
#define g_dispatchSave1554 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d58u))
#define g_dispatchSave1555 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d5cu))
#define g_dispatchSave1556 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d60u))
#define g_dispatchSave1557 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d64u))
#define g_dispatchSave1558 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d68u))
#define g_dispatchSave1559 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d9cu))
#define g_dispatchSave1570 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e28u))
#define g_dispatchSave1572 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e34u))
#define g_dispatchSave1573 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e38u))
#define g_dispatchSave1575 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e5cu))
#define g_dispatchSave1576 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e60u))
#define g_dispatchSave1577 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e6cu))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_dualD (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_eq (*(unsigned int *)MK4_VA(unsigned int, 0x542098u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_mat3x3_007af990 (*(short *)MK4_VA(short, 0x7af990u))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_mat3x3_007af9a0 (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_tickDecay (*(unsigned int *)MK4_VA(unsigned int, 0xab4e64u))
#define g_tickFlagZ (*(unsigned int *)MK4_VA(unsigned int, 0xab4e40u))
#define g_tickW1 (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))
#define g_tickX1 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d98u))
#define g_vtxMat ((short *)MK4_VA(short, 0x7af990u))
#define g_vtxTransX (*(int *)MK4_VA(int, 0x7af9a4u))
#define g_vtxTransY (*(int *)MK4_VA(int, 0x7af9a8u))
#define g_vtxTransZ (*(int *)MK4_VA(int, 0x7af9acu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif


extern void ZBucketClampStore(void);
extern void WtSnapshotPushCall(void);
extern void TransformAccumulate(void);
extern void Helper_TickInit(unsigned int base);
extern void DirtyBitTripleWriteOrCall(void);
extern void BillboardChainRender(void);
extern void MovesPanelEmit(void);
extern void BboxProjectAndStash(void);
extern void BillboardSheetDualEmit(void *p, int q);
extern void MStackPushCallCallPop_func_00405dd0(void);
extern void Helper_TickAlt(void);

/* Portable twin of the recursive scene-node renderer - the sole caller of
 * DrawMeshBlock, and the function that finally emits geometry.
 *
 * Three seam points, all of them load-bearing:
 *
 *  - the per-node-type dispatch reads a CODE VA from a packed-pointer table
 *    (index (flags >> 24) & 7, plus 8 when flag 0x100 is set) and the second,
 *    deeper dispatch reads one from a node field; both go through
 *    MK4_ResolveCode.
 *  - it installs ITSELF as g_walkCallback before handing off to Helper_TickAlt,
 *    which is a 32-bit slot, so that is MK4_CODE_VA.
 *  - it hands the engine a packed pointer to a THREE-WORD STACK LOCAL. That
 *    cannot survive the round trip on a 64-bit host, so the vector comes from
 *    the arena scratch stack; every return path below frees it.
 */
void RenderSceneNode(void)
{
    unsigned int saved_pending = g_eventQueuePending;
    unsigned int saved_dualC   = g_dualC;
    unsigned int saved_cj54    = g_cj_00542054;
    unsigned int node, kind, child, mat, sub;
    unsigned int *vec;
    int hit, blk;

    if (g_dispatchSave1573 == 0)
        goto tail;

    g_currentNodeFlags = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x20);
    node = g_currentNodeIdx;
#ifdef TARGET_SDL
    /* MK4_TRACE_VISIT: every node the graph walk REACHES, before any
     * culling. Compare against MK4_TRACE_GEO's emit list: equal counts
     * mean the graph really holds only what you see, a larger visit set
     * means geometry is arriving and being rejected downstream. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int n;
      if (getenv("MK4_TRACE_VISIT") && n < 20000
          && *MK4_VA(unsigned int, 0x537f94u) != 0) { n++;
        SDL_Log("VISIT node=%x flags=%x", node, g_currentNodeFlags); } }
#endif

    if ((g_currentNodeFlags & 0x2000) != 0) {
        ZBucketClampStore();
        if (g_framePauseFlag != 0)
            return;
        node = g_currentNodeIdx;
        if (g_eq == 0) {
            g_eventQueueWorkType = MK4_NODE_AT(unsigned int, node, 0);
            saved_pending = g_eventQueuePending;
            saved_dualC   = g_dualC;
            saved_cj54    = g_cj_00542054;
            if (g_eventQueueWorkType == 0)
                goto tail;
        }
    }
    saved_cj54    = g_cj_00542054;
    saved_dualC   = g_dualC;
    saved_pending = g_eventQueuePending;
    g_dualD = g_dualC;

    vec = (unsigned int *)MK4_ALLOCA(12);

    if (MK4_NODE_AT(int, node, 0x3c) == 0 && MK4_NODE_AT(int, node, 0x40) == 0 &&
        MK4_NODE_AT(int, node, 0x44) == 0) {
        g_cj_00542054 = g_eventQueuePending * 4;
        *(unsigned int *)MK4_VA(unsigned int, 0x7af990u) = *(unsigned int *)MK4_PTR(g_cj_00542054);
        *(unsigned int *)MK4_VA(unsigned int, 0x7af994u) = *(unsigned int *)MK4_PTR(g_cj_00542054 + 4);
        *(unsigned int *)MK4_VA(unsigned int, 0x7af998u) = *(unsigned int *)MK4_PTR(g_cj_00542054 + 8);
        *(unsigned int *)MK4_VA(unsigned int, 0x7af99cu) = *(unsigned int *)MK4_PTR(g_cj_00542054 + 12);
        g_mat3x3_007af9a0 = *(unsigned short *)MK4_PTR(g_cj_00542054 + 16);
        g_xformDirtyFlags &= 0xffffffefu;
    } else {
        g_eventQueuePending = node + 0xf;
        g_cj_00542054 += 0x14;
        kind = (g_currentNodeFlags >> 0x18) & 7u;
        if ((g_currentNodeFlags & 0x100) != 0)
            kind += 8;
        g_eventQueueCurrent = *MK4_NODE(unsigned int, kind + 0x13de22u);
        g_currentNodeIdx = g_cj_00542054 >> 2;
        ((void (*)(void))MK4_ResolveCode(g_eventQueueCurrent))();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
        g_dualC = g_currentNodeIdx;
        g_eventQueuePending = saved_pending;
        WtSnapshotPushCall();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
    }

    g_dualC = node + 0xc;
    g_currentNodeIdx = 0x2ad0e6;
    TransformAccumulate();
    if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
    /* MK4_TRACE_MAT=N: the 3x3 the accumulate just applied, the node's
     * local translation, the parent position it added to, and the result.
     * An all-zero matrix collapses every child onto its parent. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      extern int atoi(const char *);
      static int nm2, limm = -1;
      if (limm < 0) { char *e = getenv("MK4_TRACE_MAT"); limm = e ? atoi(e) : 0; }
      if (nm2 < limm && *MK4_VA(unsigned int, 0x537f94u) != 0) { nm2++;
        short *M = (short *)MK4_VA(short, 0x7af990u);
        SDL_Log("MAT node=%x f=%x rot=[%d %d %d] m=[%d %d %d|%d %d %d|%d %d %d] loc=[%d %d %d] par=%x out=[%d %d %d]",
                node, g_currentNodeFlags,
                MK4_NODE_AT(int, node, 0x3c), MK4_NODE_AT(int, node, 0x40),
                MK4_NODE_AT(int, node, 0x44),
                M[0], M[1], M[2], M[3], M[4], M[5], M[6], M[7], M[8],
                MK4_NODE_AT(int, node, 0x30), MK4_NODE_AT(int, node, 0x34),
                MK4_NODE_AT(int, node, 0x38), g_dualD,
                (int)g_dispatchSave1501, (int)g_dispatchSave1502,
                (int)g_dispatchSave1503); } }

    if ((g_currentNodeFlags & 0xf00004) != 0)
        goto cull;

    /* sar in the original - the transformed position is SIGNED (camera
     * space); a logical shift turns a negative coordinate into a huge
     * positive one and the scene collapses to a few pixels. */
    if ((g_cj_0054205c & 0x60) == 0) {
        g_vtxTransX = (unsigned int)((int)g_dispatchSave1501 >> 8);
        g_vtxTransY = (unsigned int)((int)g_dispatchSave1502 >> 8);
    } else {
        g_vtxTransX = (unsigned int)((int)g_dispatchSave1501 >> 0x11);
        g_vtxTransY = (unsigned int)((int)g_dispatchSave1502 >> 0x11);
    }
    g_vtxTransZ = (unsigned int)((int)g_dispatchSave1503 >> 8);
#ifdef TARGET_SDL
    /* MK4_TRACE_GEO=N: where the emitted geometry actually sits in camera
     * space, and how far it is from the eye. N caps the sample count; a
     * bare "1" keeps the old 24. The cap used to be hardcoded at 24, and
     * that truncation nearly bought a wrong conclusion - 24 samples all
     * landed inside one fighter, which reads as "the stage is missing"
     * whether or not it is. Raise it before concluding anything about
     * what is NOT in the graph. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      extern int atoi(const char *);
      static int n, lim = -1;
      if (lim < 0) { char *e = getenv("MK4_TRACE_GEO");
                     lim = e ? (atoi(e) > 1 ? atoi(e) : 24) : 0; }
      if (n < lim && *MK4_VA(unsigned int, 0x537f94u) != 0) { n++;
        SDL_Log("GEO node=%x cam=[%d %d %d] eye=[%d %d %d]",
                node, (int)g_vtxTransX, (int)g_vtxTransY, (int)g_vtxTransZ,
                *MK4_VA(int, 0xab4d18u) >> 8, *MK4_VA(int, 0xab4d1cu) >> 8,
                *MK4_VA(int, 0xab4d20u) >> 8); } }
#endif
    g_dualC = g_cj_00542054 >> 2;

    if (((g_currentNodeFlags | g_cj_0054205c) & 0x80) == 0) {
        g_currentNodeIdx = MK4_NODE_AT(unsigned int, node, 0x24);
        if (g_currentNodeIdx != 0) {
            g_eventQueuePending = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 4);
            g_walkCallback = (g_eventQueuePending >> 0xc) & 0x7ffu;
            if (g_walkCallback != 0 && DirtyTestScaledCopy() != 0)
                goto cull;
        }
    }
    g_currentNodeFlags &= 0xffffdfffu;
    MK4_NODE_AT(unsigned int, node, 0x20) = g_currentNodeFlags;
    g_dualC = g_cj_00542054 >> 2;

    if ((g_currentNodeFlags & 0x1600) != 0) {
        if ((g_currentNodeFlags & 0x1000) == 0) {
            if ((g_cj_0054205c & 2) != 0)
                goto emit;
            g_currentNodeIdx = MK4_UNPTR(&g_dispatchSave1525);
            if ((g_xformDirtyFlags & 0x30) == 0) {
                g_dispatchSave1525 = 0x1000;
                g_dispatchSave1526 = 0;
                g_dispatchSave1527 = 0x1000;
                g_dispatchSave1528 = 0;
                g_dispatchSave1529 = 0x1000;
            } else {
                *(unsigned int *)MK4_VA(unsigned int, 0x7af994u) = g_dispatchSave1555;
                *(unsigned int *)MK4_VA(unsigned int, 0x7af990u) = g_dispatchSave1554;
                *(unsigned int *)MK4_VA(unsigned int, 0x7af99cu) = g_dispatchSave1557;
                *(unsigned int *)MK4_VA(unsigned int, 0x7af998u) = g_dispatchSave1556;
                g_mat3x3_007af9a0 = g_dispatchSave1558;
                MatrixTransform3x3Q12(MK4_NODE(short, g_dualC),
                                      (short *)&g_dispatchSave1525);
            }
            g_xformDirtyFlags |= 0x30;
        } else {
            VtableDispatchSetDirty((int)node);
        }
        g_dualC = 0x2ad20e;
    }

emit:
    mat = g_dualC;
    g_dispatchSave1576 = g_tickW1;
    g_dispatchSave1575 = g_dispatchSave1577;
    if (g_tickDecay != 0)
        g_dispatchSave1576 = g_dispatchSave1577;

    g_eventQueuePending = MK4_NODE_AT(unsigned int, node, 0x28);
    if (g_eventQueuePending == 0) {
        if (g_tickX1 != 0) {
            g_currentNodeIdx = node;
            Helper_TickInit(g_tickX1);
        }
    } else {
        g_walkCallback = MK4_NODE_AT(unsigned int, g_eventQueuePending, 0x10);
        g_currentNodeIdx = node;
        if (g_walkCallback != 0) {
            ((void (*)(void))MK4_ResolveCode(g_walkCallback))();
            if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
            if (g_currentNodeIdx == 0) {
                g_dispatchSave1573 = 0;
                g_xformDirtyFlags &= 0xfffffffeu;
                MK4_ALLOCA_FREE(12);
                return;
            }
            if (g_currentNodeIdx == 0xffffffffu)
                goto descend;
        }
        g_walkCallback = MK4_NODE_AT(unsigned int, g_eventQueuePending, 0);
        g_dualC = mat;
        if ((g_walkCallback & 8) != 0)
            DirtyBitTripleWriteOrCall();
        if (g_tickFlagZ != 0)
            VibrationFrameUpdate((int)node);
    }

    if ((g_xformDirtyFlags & 0x10) != 0) {
        unsigned int m = g_dualC * 4;

        *(unsigned int *)MK4_VA(unsigned int, 0x7af990u) = *(unsigned int *)MK4_PTR(m);
        *(unsigned int *)MK4_VA(unsigned int, 0x7af994u) = *(unsigned int *)MK4_PTR(m + 4);
        *(unsigned int *)MK4_VA(unsigned int, 0x7af998u) = *(unsigned int *)MK4_PTR(m + 8);
        *(unsigned int *)MK4_VA(unsigned int, 0x7af99cu) = *(unsigned int *)MK4_PTR(m + 12);
        g_mat3x3_007af9a0 = *(unsigned short *)MK4_PTR(m + 16);
    }

    g_dualD = MK4_NODE_AT(unsigned int, node, 0x24);
    if (g_dualD == 0) {
        if ((g_cj_0054205c & 0x20000) != 0) {
            g_currentNodeIdx = node;
            BillboardChainRender();
        }
    } else {
        sub = MK4_NODE_AT(unsigned int, g_dualD, 4);
        g_eventQueuePending = sub;
        if (sub == 0) {
            g_currentNodeIdx = node;
            MovesPanelEmit();
        } else {
            blk = MK4_NODE_AT(int, g_dualD, 0x18);
#ifdef TARGET_SDL
            /* Skeleton-builder bones (type 0x99) carry their tick CALLBACK
             * VA in +0x24, not a mesh descriptor - dereferencing it as one
             * reads a code address as a slot pointer and walks off the
             * arena. The original never emits them (their class takes a
             * different path); until that gate is understood, skip any
             * descriptor whose slot or block lies outside the arena.
             * MK4_TRACE_EMITBAD logs each skip. */
            { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
              extern unsigned int g_mk4ArenaSize;
              if (sub >= g_mk4ArenaSize
                  || *(unsigned int *)MK4_PTR(sub + 4) >= g_mk4ArenaSize) {
                  static int n;
                  if (getenv("MK4_TRACE_EMITBAD") && n < 8) { n++;
                      SDL_Log("EMITBAD node=%x desc=%x sub=%08x blk=%08x",
                              node, g_dualD, sub, (unsigned)blk); }
                  goto descend; } }
#endif
            if (*(int *)MK4_PTR(sub + 4) > 0) {
                unsigned int recVA =
                    (unsigned int)(blk * 0x10 + 0xc + *(int *)MK4_PTR(sub + 4));
                unsigned char *rec = (unsigned char *)MK4_PTR(recVA);
                unsigned char tag = rec[0];
                unsigned short width = *(unsigned short *)MK4_PTR(
                    *(unsigned int *)MK4_PTR(sub) + 8);

                g_dispatchSave1572 = tag;
                if ((tag & 0x80) == 0) {
                    if ((g_currentNodeFlags & 0x40) == 0) {
                        unsigned int rebuild = 0;

                        g_walkCallback = 0;
                        g_dualC = MK4_NODE_AT(unsigned int, node, 0x48);
                        if (g_dualC != 0) {
                            g_currentNodeIdx = node;
                            if (*(unsigned int *)MK4_PTR(g_dualC) !=
                                (recVA * 0x20 |
                                 (((int)g_cj_0054205c >> 0x10) & 8) |
                                 g_dispatchSave1572)) {
                                rebuild = 1;
                                g_walkCallback = 1;
                            }
                        }
                        /* MK4_FORCE_CACHE_REBUILD: diagnostic - rebuild the
                         * vertex cache every visit. The validity header is
                         * entry<<5|kind-bits and encodes NOTHING about the
                         * texture page slots baked into the records, so a
                         * cache built before LoadGeoAsset_Textures patched
                         * the slots keeps nibble 0 forever. */
                        { extern char *getenv(const char *);
                          static int f = -1;
                          if (f < 0) f = getenv("MK4_FORCE_CACHE_REBUILD") != 0;
                          if (f && g_dualC != 0) { rebuild = 1; g_walkCallback = 1; } }
                        if (g_dualC == 0 || rebuild) {
                            g_currentNodeIdx = node;
                            VertexQuadBuilder(blk, rebuild);
                            if (g_dualC == 0)
                                goto descend;
                        }
                        kind = g_cj_0054205c;
                        /* += 4, not += 1: g_dualC is a raw VA here and the
                         * original does `add eax, 4` (0x4bacfd). The emitters
                         * then take records at g_dualC + 4, i.e. cache + 8 -
                         * exactly where VertexQuadBuilder writes them. With
                         * += 1 every record was read 3 BYTES EARLY: x,y still
                         * looked right (the emitter writes and the queue
                         * decode reads the same shifted offsets), but u,v,
                         * the sort key, the colors and the page-slot nibble
                         * all came from the wrong bytes - streaky textures
                         * sampling the font atlas at slot 0. */
                        g_dualC += 4;
                        g_baseSel = 0x1fff;
                        g_walkCallback = g_cj_0054205c & 1;
                        g_eventQueuePending = MK4_UNPTR(&g_dispatchSave1559);
#ifdef TARGET_SDL
                        /* MK4_TRACE_EMIT: which of the four mesh emitters the
                         * frame actually uses. The mesh tag picks it, and a
                         * fighter (tag 1) and a stage (tag 0) do not take the
                         * same one - so a gate that renders a character
                         * exercises only one of the four. */
                        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
                          static unsigned n2, dmb, n1, cap, ticks;
                          if (getenv("MK4_TRACE_EMIT")) {
                              if ((g_dispatchSave1572 & 0x40) != 0) n2++;
                              else if ((g_cj_0054205c & 0x80000) != 0 &&
                                       (g_dispatchSave1572 & 1) != 0) dmb++;
                              else if ((g_dispatchSave1572 & 2) != 0) n1++;
                              else cap++;
                              if ((++ticks % 2000) == 0)
                                  SDL_Log("EMIT emit2=%u drawMeshBlock=%u emit=%u emit3Cap=%u",
                                          n2, dmb, n1, cap); } }
#endif
                        /* MK4_EMIT_SKIP=<n>: drop one emitter to see what it
                         * was contributing. 1=emit2 2=drawMeshBlock 3=emit
                         * 4=emit3Cap. Diagnostic only. */
                        { extern char *getenv(const char *); extern int atoi(const char *);
                          static int skip = -1;
                          if (skip < 0) { char *e = getenv("MK4_EMIT_SKIP");
                                          skip = e ? atoi(e) : 0; }
                          if (skip) {
                              int which = ((g_dispatchSave1572 & 0x40) != 0) ? 1
                                        : (((g_cj_0054205c & 0x80000) != 0 &&
                                            (g_dispatchSave1572 & 1) != 0) ? 2
                                        : (((g_dispatchSave1572 & 2) != 0) ? 3 : 4));
                              if (which == skip) goto descend;
                          } }
                        if ((g_dispatchSave1572 & 0x40) != 0) {
                            TristripBatchEmit2(recVA, g_walkCallback, width);
                        } else if ((g_cj_0054205c & 0x80000) != 0 &&
                                   (g_dispatchSave1572 & 1) != 0) {
                            g_dispatchSave1570 = g_cj_0054205c & 0x1000;
                            DrawMeshBlock(recVA, g_walkCallback, width);
                            g_dispatchSave1570 = 0;
                            if ((kind & 0x40000) != 0) {
                                g_eventQueuePending = node;
                                BboxProjectAndStash();
                            }
                        } else if ((g_dispatchSave1572 & 2) != 0) {
                            TristripBatchEmit(recVA, g_walkCallback, width);
                        } else {
                            TristripBatchEmit3Cap(recVA, g_walkCallback, width);
                        }
                    }
                } else {
                    if ((tag & 1) != 0) {
                        g_currentNodeIdx = node;
                        BillboardSheetDualEmit(rec + 0x10, (int)saved_pending);
                    }
                    g_currentNodeIdx = node;
                    g_eventQueuePending = sub;
                    BillboardSheetDualEmit(rec, (int)saved_pending);
                }
            }
        }
    }
    goto descend;

cull:
    g_currentNodeFlags |= 0x2000;
    g_currentNodeIdx = node;
    MK4_NODE_AT(unsigned int, node, 0x20) = g_currentNodeFlags;
    if ((g_cj_0054205c & 0x4000) != 0) {
        MStackPushCallCallPop_func_00405dd0();
        if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
        g_dispatchSave1573 = 0;
        g_xformDirtyFlags &= 0xfffffffeu;
        MK4_ALLOCA_FREE(12);
        return;
    }
    LeaScaledCall(1);

descend:
    child = MK4_NODE_AT(unsigned int, node, 0);
    g_currentNodeIdx = node;
    if (child != 0) {
        vec[0] = g_dispatchSave1501;      /* local_c */
        vec[1] = g_dispatchSave1502;      /* local_8 */
        vec[2] = g_dispatchSave1503;      /* local_4 */
        g_walkCallback = MK4_NODE_AT(unsigned int, node, 0xc);
        g_eventQueuePending = g_cj_00542054 >> 2;
        g_dualC = MK4_UNPTR(vec) >> 2;
        if (g_walkCallback == 1) {
            g_currentNodeIdx = child;
            RenderSceneNode();
            if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
        } else {
            g_walkCallback = MK4_CODE_VA(RenderSceneNode);
            Helper_TickAlt();
            if (g_framePauseFlag != 0) { MK4_ALLOCA_FREE(12); return; }
        }
    }
    MK4_ALLOCA_FREE(12);

tail:
    g_cj_00542054       = saved_cj54;
    g_dualC             = saved_dualC;
    g_eventQueuePending = saved_pending;
    g_xformDirtyFlags  &= 0xfffffffeu;
}
#else
__declspec(naked) void RenderSceneNode(void)
{
    __asm {
    L_a720:
        mov      eax, dword ptr [g_dispatchSave1573]
        sub      esp, 0x20
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        je       L_ae67
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edi, dword ptr [eax*4 + 0x20]
        test     edi, 0x2000
        mov      dword ptr [g_currentNodeFlags], edi
        je       L_a78d
        call     ZBucketClampStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_eq]
        test     eax, eax
        jne      L_ae7b
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueWorkType], ecx
        je       L_ae67
        mov      edi, dword ptr [g_currentNodeFlags]
    L_a78d:
        mov      edx, dword ptr [g_pendingNodeType]
        mov      esi, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        lea      ebp, [eax*4]
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [g_eventQueueTotal], edx
        mov      edx, dword ptr [ebp + 0x3c]
        mov      ebx, eax
        test     edx, edx
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x10], esi
        mov      dword ptr [esp + 0x20], ecx
        mov      dword ptr [esp + 0x18], ebp
        jne      L_a81e
        mov      edx, dword ptr [ebp + 0x40]
        test     edx, edx
        jne      L_a81e
        mov      edx, dword ptr [ebp + 0x44]
        test     edx, edx
        jne      L_a81e
        lea      eax, [esi*4]
        mov      dword ptr [g_eventQueueEnd], eax
        mov      ecx, dword ptr [eax]
        mov      dword ptr [g_vtxMat], ecx
        mov      edx, dword ptr [eax + 4]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      ecx, dword ptr [eax + 8]
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      edx, dword ptr [eax + 0xc]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      ax, word ptr [eax + 0x10]
        mov      word ptr [g_mat3x3_007af9a0], ax
        mov      eax, dword ptr [g_xformDirtyFlags]
        and      al, 0xef
        mov      dword ptr [g_xformDirtyFlags], eax
        jmp      L_a89b
    L_a81e:
        add      eax, 0xf
        add      ecx, 0x14
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, edi
        sar      eax, 0x18
        and      eax, 7
        mov      dword ptr [g_eventQueueEnd], ecx
        test     edi, 0x100
        je       L_a842
        add      eax, 8
    L_a842:
        mov      edx, OFFSET g_nodeDispatchTable
        sar      edx, 2
        add      eax, edx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        sar      ecx, 2
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        call     eax
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [esp + 0x10]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     WtSnapshotPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
    L_a89b:
        mov      eax, OFFSET g_dispatchSave1501
        lea      edx, [ebx + 0xc]
        sar      eax, 2
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_currentNodeIdx], eax
        call     TransformAccumulate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_currentNodeFlags]
        test     eax, OFFSET g_dispatchSave1333
        jne      L_a97c
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_dispatchSave1501]
        test     cl, 0x60
        je       L_a8f8
        sar      edx, 0x11
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [g_dispatchSave1502]
        sar      edx, 0x11
        jmp      L_a90a
    L_a8f8:
        sar      edx, 8
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [g_dispatchSave1502]
        sar      edx, 8
    L_a90a:
        mov      dword ptr [g_vtxTransY], edx
        mov      edx, dword ptr [g_dispatchSave1503]
        sar      edx, 8
        mov      dword ptr [g_vtxTransZ], edx
        mov      edx, dword ptr [g_eventQueueEnd]
        sar      edx, 2
        mov      dword ptr [g_pendingNodeType], edx
        mov      edx, eax
        or       edx, ecx
        test     dl, 0x80
        jne      L_a9c4
        mov      ecx, dword ptr [ebx*4 + 0x24]
        test     ecx, ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        je       L_a9c4
        mov      ecx, dword ptr [ecx*4 + 4]
        mov      dword ptr [g_xformEntityIdx], ecx
        sar      ecx, 0xc
        and      ecx, 0x7ff
        mov      dword ptr [g_walkCallback], ecx
        je       L_a9c4
        call     DirtyTestScaledCopy
        test     eax, eax
        mov      eax, dword ptr [g_currentNodeFlags]
        je       L_a9c4
        mov      ebp, dword ptr [esp + 0x18]
    L_a97c:
        or       ah, 0x20
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [ebx*4 + 0x20], eax
        mov      eax, dword ptr [g_fightGroupHead]
        test     ah, 0x40
        jne      L_a9aa
        push     1
        call     LeaScaledCall
        add      esp, 4
        jmp      L_adb3
    L_a9aa:
        call     MStackPushCallCallPop_func_00405dd0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_ab22
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_a9c4:
        and      ah, 0xdf
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [ebx*4 + 0x20], eax
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeFlags]
        sar      eax, 2
        test     ch, 0x16
        mov      dword ptr [g_pendingNodeType], eax
        je       L_aab4
        mov      esi, 0x1000
        test     ecx, esi
        je       L_aa06
        push     ebx
        call     VtableDispatchSetDirty
        add      esp, 4
        jmp      L_aaa7
    L_aa06:
        test     byte ptr [g_fightGroupHead], 2
        jne      L_aab4
        mov      cl, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_currentNodeIdx], OFFSET g_dispatchSave1525
        test     cl, 0x30
        je       L_aa7d
        mov      edx, dword ptr [g_dispatchSave1555]
        mov      ecx, dword ptr [g_dispatchSave1554]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      edx, dword ptr [g_dispatchSave1557]
        mov      dword ptr [g_vtxMat], ecx
        mov      ecx, dword ptr [g_dispatchSave1556]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      cx, word ptr [g_dispatchSave1558]
        lea      edx, [eax*4]
        push     OFFSET g_dispatchSave1525
        push     edx
        mov      word ptr [g_mat3x3_007af9a0], cx
        call     MatrixTransform3x3Q12
        add      esp, 8
        jmp      L_aa9b
    L_aa7d:
        xor      eax, eax
        mov      dword ptr [g_dispatchSave1525], esi
        mov      dword ptr [g_dispatchSave1526], eax
        mov      dword ptr [g_dispatchSave1527], esi
        mov      dword ptr [g_dispatchSave1528], eax
        mov      dword ptr [g_dispatchSave1529], esi
    L_aa9b:
        mov      eax, dword ptr [g_xformDirtyFlags]
        or       al, 0x30
        mov      dword ptr [g_xformDirtyFlags], eax
    L_aaa7:
        mov      eax, OFFSET g_dispatchSave1525
        sar      eax, 2
        mov      dword ptr [g_pendingNodeType], eax
    L_aab4:
        mov      edx, dword ptr [g_tickW1]
        mov      ecx, dword ptr [g_dispatchSave1577]
        mov      dword ptr [g_dispatchSave1576], edx
        mov      edx, dword ptr [g_tickDecay]
        test     edx, edx
        mov      dword ptr [g_dispatchSave1575], ecx
        je       L_aadc
        mov      dword ptr [g_dispatchSave1576], ecx
    L_aadc:
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      ecx, dword ptr [ebx*4 + 0x28]
        test     ecx, ecx
        mov      dword ptr [g_xformEntityIdx], ecx
        je       L_ab84
        mov      edx, dword ptr [ecx*4 + 0x10]
        test     edx, edx
        mov      dword ptr [g_walkCallback], edx
        je       L_ab56
        mov      esi, eax
        call     edx
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_currentNodeIdx]
        test     eax, eax
        jne      L_ab40
    L_ab22:
        mov      eax, dword ptr [g_xformDirtyFlags]
        mov      dword ptr [g_dispatchSave1573], 0
        and      al, 0xfe
        mov      dword ptr [g_xformDirtyFlags], eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_ab40:
        cmp      eax, -1
        je       L_adaf
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, esi
        mov      dword ptr [g_pendingNodeType], eax
    L_ab56:
        mov      ecx, dword ptr [ecx*4]
        test     cl, 8
        mov      dword ptr [g_walkCallback], ecx
        je       L_ab72
        call     DirtyBitTripleWriteOrCall
        mov      eax, dword ptr [g_pendingNodeType]
    L_ab72:
        mov      ecx, dword ptr [g_tickFlagZ]
        test     ecx, ecx
        je       L_ab9c
        push     ebx
        call     VibrationFrameUpdate
        jmp      L_ab94
    L_ab84:
        mov      ecx, dword ptr [g_tickX1]
        test     ecx, ecx
        je       L_ab9c
        push     ecx
        call     Helper_TickInit
    L_ab94:
        mov      eax, dword ptr [g_pendingNodeType]
        add      esp, 4
    L_ab9c:
        test     byte ptr [g_xformDirtyFlags], 0x10
        je       L_abd5
        shl      eax, 2
        mov      ecx, dword ptr [eax]
        mov      dword ptr [g_vtxMat], ecx
        mov      edx, dword ptr [eax + 4]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      ecx, dword ptr [eax + 8]
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      edx, dword ptr [eax + 0xc]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      ax, word ptr [eax + 0x10]
        mov      word ptr [g_mat3x3_007af9a0], ax
    L_abd5:
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      eax, dword ptr [ebx*4 + 0x24]
        test     eax, eax
        mov      dword ptr [g_eventQueueTotal], eax
        jne      L_ac05
        test     dword ptr [g_fightGroupHead], 0x20000
        je       L_adaf
        call     BillboardChainRender
        jmp      L_adaf
    L_ac05:
        mov      edi, dword ptr [eax*4 + 4]
        test     edi, edi
        mov      dword ptr [g_xformEntityIdx], edi
        jne      L_ac20
        call     MovesPanelEmit
        jmp      L_adaf
    L_ac20:
        mov      ebp, dword ptr [eax*4 + 0x18]
        mov      eax, dword ptr [edi + 4]
        test     eax, eax
        jle      L_adaf
        mov      ecx, ebp
        shl      ecx, 4
        lea      esi, [ecx + eax + 0xc]
        xor      ecx, ecx
        mov      cl, byte ptr [esi]
        test     cl, 0x80
        mov      dword ptr [g_dispatchSave1572], ecx
        je       L_ac7f
        test     cl, 1
        je       L_ac6c
        mov      edx, dword ptr [esp + 0x10]
        lea      eax, [esi + 0x10]
        push     edx
        push     eax
        call     BillboardSheetDualEmit
        add      esp, 8
        mov      dword ptr [g_xformEntityIdx], edi
        mov      dword ptr [g_currentNodeIdx], ebx
    L_ac6c:
        mov      ecx, dword ptr [esp + 0x10]
        push     ecx
        push     esi
        call     BillboardSheetDualEmit
        add      esp, 8
        jmp      L_adaf
    L_ac7f:
        test     byte ptr [g_currentNodeFlags], 0x40
        jne      L_adaf
        xor      edx, edx
        mov      dword ptr [g_walkCallback], edx
        mov      eax, dword ptr [ebx*4 + 0x48]
        test     eax, eax
        mov      dword ptr [g_pendingNodeType], eax
        je       L_acce
        mov      ebx, dword ptr [g_fightGroupHead]
        mov      edx, esi
        sar      ebx, 0x10
        shl      edx, 5
        and      ebx, 8
        or       edx, ebx
        mov      ebx, dword ptr [eax]
        or       edx, ecx
        cmp      ebx, edx
        je       L_acf3
        mov      ebx, dword ptr [esp + 0x14]
        mov      edx, 1
        mov      dword ptr [g_walkCallback], edx
    L_acce:
        push     edx
        push     ebp
        call     VertexQuadBuilder
        mov      eax, dword ptr [g_pendingNodeType]
        add      esp, 8
        test     eax, eax
        je       L_adaf
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_dispatchSave1572]
        jmp      L_acfd
    L_acf3:
        mov      ebx, dword ptr [esp + 0x14]
        mov      edx, dword ptr [g_fightGroupHead]
    L_acfd:
        add      eax, 4
        mov      dword ptr [g_baseSel], 0x1fff
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, edx
        and      eax, 1
        mov      ebp, edx
        test     cl, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_xformEntityIdx], OFFSET g_dispatchSave1559
        je       L_ad3c
        mov      ecx, dword ptr [edi]
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     TristripBatchEmit2
        jmp      L_adac
    L_ad3c:
        test     edx, 0x80000
        je       L_ad87
        test     cl, 1
        je       L_ad87
        and      edx, 0x1000
        mov      dword ptr [g_dispatchSave1570], edx
        mov      ecx, dword ptr [edi]
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     DrawMeshBlock
        add      esp, 0xc
        mov      dword ptr [g_dispatchSave1570], 0
        test     ebp, 0x40000
        je       L_adaf
        mov      dword ptr [g_xformEntityIdx], ebx
        call     BboxProjectAndStash
        jmp      L_adaf
    L_ad87:
        test     cl, 2
        mov      ecx, dword ptr [edi]
        je       L_ad9e
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     TristripBatchEmit
        jmp      L_adac
    L_ad9e:
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     TristripBatchEmit3Cap
    L_adac:
        add      esp, 0xc
    L_adaf:
        mov      ebp, dword ptr [esp + 0x18]
    L_adb3:
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      eax, dword ptr [ebp]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_ae4a
        mov      ecx, dword ptr [g_dispatchSave1502]
        mov      eax, dword ptr [g_dispatchSave1501]
        mov      edx, dword ptr [g_dispatchSave1503]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [esp + 0x24], eax
        mov      dword ptr [esp + 0x2c], edx
        mov      eax, dword ptr [ebx*4 + 0xc]
        sar      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        lea      ecx, [esp + 0x24]
        sar      ecx, 2
        cmp      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_pendingNodeType], ecx
        je       L_ae33
        mov      dword ptr [g_walkCallback], OFFSET RenderSceneNode
        call     Helper_TickAlt
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_ae4a
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_ae33:
        mov      edx, dword ptr [ebp]
        mov      dword ptr [g_currentNodeIdx], edx
        call     L_a720
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
    L_ae4a:
        mov      eax, dword ptr [esp + 0x1c]
        mov      ecx, dword ptr [esp + 0x10]
        mov      edx, dword ptr [esp + 0x20]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_eventQueueEnd], edx
    L_ae67:
        mov      eax, dword ptr [g_xformDirtyFlags]
        and      al, 0xfe
        mov      dword ptr [g_xformDirtyFlags], eax
    L_ae73:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_ae7b:
        mov      edi, dword ptr [g_currentNodeFlags]
        mov      eax, dword ptr [g_currentNodeIdx]
        jmp      L_a78d
    }
}
#endif

