/* @addr 0x004ba1c0 (1026b game) - scene-graph iteration + render loop.
 *
 * Walks the entity table from g_currentNodeIdx, follows the node chain
 * via field +0x18 (and +0x34 sibling slot), and for each node performs:
 * camera-relative transform (ChainStreamMatMulVecAdd, ScaledNegThreeWords,
 * Mat3x3VecMul6Bit), frustum culling (CameraSetupAndCullFan),
 * and RenderSceneNode (0x4ba720). Body is a backward-jmp loop that
 * iterates until the chain pointer at field +0x18 reaches zero, with
 * the scenegraph cleanup hook ChainWalkCleanup firing on exit.
 *
 * Referenced via DIR32 fnptr from TickAllEntities (0x4b9ea1) and from a
 * function-pointer slot in .data within the BigDataBlob region (likely
 * a per-renderer dispatch table). Kept as raw _emit bytes because the
 * structural decompilation hasn't been attempted; absolute addresses
 * inside the body (DIR32 references to globals + calls) are baked into
 * the literal bytes and only valid when synth places this function at
 * exactly 0x004ba1c0.
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx, g_currentNodeFlags, g_walkCallback;
extern unsigned int g_cj_0054205c, g_cj_00542054, g_cj_00542058;
extern unsigned int g_dualC, g_dualD, g_eventQueuePending, g_eventQueueNotMask;
extern unsigned int g_eventQueueCurrent, g_xformDirtyFlags, g_framePauseFlag;
extern unsigned int g_player1NodeIdx, g_player2NodeIdx;
extern unsigned int g_dispatchSave1573, g_dispatchSave1574, g_dispatchSave1577;
extern unsigned int g_dispatchSave1530, g_dispatchSave1531, g_dispatchSave1532;
extern unsigned int g_dispatchSave1533, g_dispatchSave1549, g_dispatchSave1550;
extern unsigned int g_dispatchSave1551, g_dispatchSave1552, g_dispatchSave1553;
extern unsigned int g_dispatchSave1525, g_vtxMatBase, g_tickX3;
extern unsigned int g_bootHeavyState, g_particleInitState, g_particleEmitterNode;
extern unsigned int g_mat3x3_007af994, g_mat3x3_007af998, g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_bootHeavyState (*(unsigned int *)MK4_VA(unsigned int, 0x537f78u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1525 (*(unsigned int *)MK4_VA(unsigned int, 0xab4838u))
#define g_dispatchSave1530 (*(unsigned int *)MK4_VA(unsigned int, 0xab487cu))
#define g_dispatchSave1531 (*(unsigned int *)MK4_VA(unsigned int, 0xab4880u))
#define g_dispatchSave1532 (*(unsigned int *)MK4_VA(unsigned int, 0xab4884u))
#define g_dispatchSave1533 (*(unsigned int *)MK4_VA(unsigned int, 0xab4888u))
#define g_dispatchSave1549 (*(unsigned int *)MK4_VA(unsigned int, 0xab48d8u))
#define g_dispatchSave1550 (*(unsigned int *)MK4_VA(unsigned int, 0xab4cd8u))
#define g_dispatchSave1551 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d18u))
#define g_dispatchSave1552 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d1cu))
#define g_dispatchSave1553 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d20u))
#define g_dispatchSave1573 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e38u))
#define g_dispatchSave1574 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e3cu))
#define g_dispatchSave1577 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e6cu))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_dualD (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_mat3x3_007af9a0 (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_particleEmitterNode (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))
#define g_particleInitState (*(unsigned int *)MK4_VA(unsigned int, 0x541de0u))
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_player2NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_tickX3 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e68u))
#define g_vtxMatBase (*(unsigned int *)MK4_VA(unsigned int, 0xab4878u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif


extern void ChainWalkCleanup(void);
extern void ScaledNegThreeWords(void);
extern void ChainStreamMatMulVecAdd(void);
extern void Push2GlobalsCall(void);
extern void Mat3x3VecMul6Bit(void *a, void *b);
extern void CameraSetupAndCullFan(void);
extern void RenderSceneNode(void);

/* Portable twin of the per-node scene walk.
 *
 * TickAllEntities installs this as g_walkCallback and Helper_TickInner calls it
 * once per node, so it is the function that turns the scene graph into draw
 * queue entries.
 *
 * Two things needed the seam rather than a transcription. The node-type
 * dispatch reads a CODE VA out of a packed-pointer slot, so it goes through
 * MK4_ResolveCode; and the several `(int)&g_x >> 2` idioms that build a packed
 * pointer for a global go through MK4_UNPTR, because a truncated host address
 * is not a VA (see make packed-ptr-audit).
 *
 * The flag tests are on bits, not magnitudes, so none of them is signed - the
 * one signed operation is `(int)g_walkCallback >> 8` in the distance scale,
 * which is an arithmetic shift in the original. */
void RenderSceneGraphIterate(void)
{
    unsigned int idx, base;
    int scale;

#ifdef TARGET_SDL
    /* MK4_TRACE_ANIM: bone 0x14b5fe's rotation as the ENTITY render begins.
     * The anim pass writes it non-zero every frame and the node walk reads
     * zero; this brackets which side of the entity entry loses it. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      extern unsigned int g_mk4FrameNo;
      static int n;
      if (getenv("MK4_TRACE_ANIM") && g_mk4FrameNo >= 300 && n < 8) { n++;
          SDL_Log("f%u ENTRY entity=%x bone14b5fe rot=[%d %d %d]", g_mk4FrameNo, g_currentNodeIdx,
                  MK4_NODE_AT(int, 0x14b5feu, 0x3c),
                  MK4_NODE_AT(int, 0x14b5feu, 0x40),
                  MK4_NODE_AT(int, 0x14b5feu, 0x44)); } }
#endif
    g_walkCallback = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x18);
    if (g_walkCallback == 0) {
        g_xformDirtyFlags &= 0xfffffffeu;
        return;
    }
    g_cj_0054205c   = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x34);
#ifdef TARGET_SDL
    /* MK4_TRACE_ENTRY: the walker's ENTRY node and the two fields its camera
     * branch needs - +0x34 bit 0x80000 and +0x3c pointing at a camera node. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned n;
      if (getenv("MK4_TRACE_ENTRY") && ++n % 200 == 0)
          SDL_Log("ENTRY node=%x +34=%x (cam bit %d) +3c=%x  cams=%x/%x/%x",
                  g_currentNodeIdx, g_cj_0054205c,
                  (g_cj_0054205c & 0x80000) ? 1 : 0,
                  MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c),
                  *MK4_VA(unsigned int, 0x537f78u),
                  *MK4_VA(unsigned int, 0x541de0u),
                  *MK4_VA(unsigned int, 0x535e6cu)); }
#endif
    g_cj_00542058   = g_currentNodeIdx;
    idx             = g_currentNodeIdx;

    if (idx == g_player1NodeIdx)
        g_dispatchSave1574 = 0;
    else
        g_dispatchSave1574 = (unsigned int)
            ((-(int)(idx != g_player2NodeIdx) & (int)0xfffffffe) + 1);

    if ((g_cj_0054205c & 4) != 0) {
        g_currentNodeIdx = g_walkCallback;
        ChainWalkCleanup();
        g_xformDirtyFlags &= 0xfffffffeu;
        return;
    }

    g_eventQueuePending = idx + 0x18;
    g_xformDirtyFlags &= 0xffffffcfu;

    base = (g_cj_0054205c & 2) ? MK4_UNPTR(&g_dispatchSave1549)
                               : MK4_UNPTR(&g_dispatchSave1525);
    g_currentNodeIdx    = base >> 2;
    g_eventQueueNotMask = 0;
    g_dualD             = g_currentNodeIdx;

    if (MK4_NODE_AT(int, idx, 0x60) == 0 && MK4_NODE_AT(int, idx, 0x64) == 0 &&
        MK4_NODE_AT(int, idx, 0x68) == 0) {
        unsigned int m = g_currentNodeIdx;

        if ((g_cj_0054205c & 1) == 0) {
            MK4_NODE_AT(unsigned int, m, 0) = 0x1000;
            g_eventQueueNotMask = 1;
        } else {
            MK4_NODE_AT(unsigned int, m, 0) = 0xf000;
            g_xformDirtyFlags |= 0x30;
        }
        MK4_NODE_AT(unsigned int, m, 4)  = 0;
        MK4_NODE_AT(unsigned int, m, 8)  = 0x1000;
        MK4_NODE_AT(unsigned int, m, 12) = 0;
        MK4_NODE_AT(unsigned short, m, 16) = 0x1000;
    } else {
        g_dualC = ((g_cj_0054205c >> 0x18) & 7u) + 0x13de22u;
        g_eventQueueCurrent = *MK4_NODE(unsigned int, g_dualC);
#ifdef TARGET_SDL
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int n;
          if (getenv("MK4_TRACE_ROT") && n < 8
              && *MK4_VA(unsigned int, 0x537f94u) != 0) { n++;
            SDL_Log("ROT node=%x kind=%x sel=%u builder=%x ang=[%d %d %d]",
                    idx, g_cj_0054205c, (g_cj_0054205c >> 0x18) & 7u,
                    g_eventQueueCurrent,
                    MK4_NODE_AT(int, idx, 0x60), MK4_NODE_AT(int, idx, 0x64),
                    MK4_NODE_AT(int, idx, 0x68)); } }
#endif
        ((void (*)(void))MK4_ResolveCode(g_eventQueueCurrent))();
        if (g_framePauseFlag != 0)
            return;
        if ((g_cj_0054205c & 1) != 0) {
            ScaledNegThreeWords();
            if (g_framePauseFlag != 0)
                return;
        }
    }

    base = (g_cj_0054205c & 2) ? MK4_UNPTR(MK4_VA(unsigned int, 0xab4dc0u))
                               : MK4_UNPTR(&g_dispatchSave1550);
    g_currentNodeIdx = base >> 2;

    g_walkCallback = MK4_NODE_AT(unsigned int, idx, 0x2c);
    if (g_walkCallback == 0) {
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0) = MK4_NODE_AT(unsigned int, idx, 0x54);
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 4) = MK4_NODE_AT(unsigned int, idx, 0x58);
        g_walkCallback = MK4_NODE_AT(unsigned int, idx, 0x5c);
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 8) = g_walkCallback;
    } else {
        g_eventQueuePending = g_dualD;
        g_dualD = g_cj_00542058 + 0x15;
        g_dualC = g_walkCallback;
        ChainStreamMatMulVecAdd();
    }

    if ((g_cj_0054205c & 2) == 0) {
        g_mat3x3_007af9a0 = g_dispatchSave1533;
        *(unsigned int *)MK4_VA(unsigned int, 0x7af990u) = g_vtxMatBase;
        *(unsigned int *)MK4_VA(unsigned int, 0x7af994u) = g_dispatchSave1530;
        *(unsigned int *)MK4_VA(unsigned int, 0x7af998u) = g_dispatchSave1531;
        *(unsigned int *)MK4_VA(unsigned int, 0x7af99cu) = g_dispatchSave1532;
        if (g_eventQueueNotMask == 0) {
            g_dualC = MK4_UNPTR(&g_dispatchSave1525);
            g_currentNodeIdx = MK4_UNPTR(&g_dispatchSave1549);
            Push2GlobalsCall();
        } else {
            *(unsigned int *)MK4_VA(unsigned int, 0xab48e0u) = g_dispatchSave1531;
            g_dispatchSave1549 = g_vtxMatBase;
            *(unsigned int *)MK4_VA(unsigned int, 0xab48dcu) = g_dispatchSave1530;
            *(unsigned int *)MK4_VA(unsigned int, 0xab48e4u) = g_dispatchSave1532;
            *(unsigned int *)MK4_VA(unsigned int, 0xab48e8u) = g_dispatchSave1533;
        }
        *(unsigned int *)MK4_VA(unsigned int, 0xab4cdcu) -= g_dispatchSave1552;
        g_dispatchSave1550 -= g_dispatchSave1551;
        *(unsigned int *)MK4_VA(unsigned int, 0xab4ce0u) -= g_dispatchSave1553;
        Mat3x3VecMul6Bit(&g_dispatchSave1550, MK4_VA(void, 0xab4dc0u));
        g_currentNodeIdx = 0x2ad370;
    }

    g_walkCallback = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 8);
    MK4_NODE_AT(unsigned int, g_cj_00542058, 0x50) = g_walkCallback;
    g_eventQueuePending = MK4_NODE_AT(unsigned int, idx, 0x3c);

    if ((g_cj_0054205c & 0x80000) != 0 &&
        (g_eventQueuePending == g_bootHeavyState ||
         g_eventQueuePending == g_particleInitState ||
         g_eventQueuePending == g_particleEmitterNode)) {
        g_walkCallback = MK4_NODE_AT(unsigned int, g_eventQueuePending, 0x34) & 8;
        g_cj_0054205c |= g_walkCallback;
        g_currentNodeIdx = g_cj_00542058;
        CameraSetupAndCullFan();
    } else {
        if ((g_cj_0054205c & 0x80000) != 0)
            g_cj_0054205c &= 0xfff7ffffu;
        g_dispatchSave1577 = g_tickX3;
        if (g_eventQueuePending != 0) {
            g_walkCallback = MK4_NODE_AT(unsigned int, g_eventQueuePending, 0x3c);
            scale = (int)g_walkCallback >> 8;
            if (scale < 0x50)  scale = 0x50;
            if (scale > 0x100) scale = 0x100;
            g_dispatchSave1577 = (unsigned int)((scale * (int)g_tickX3) >> 8);
        }
    }

    g_dispatchSave1573  = g_cj_00542058;
    g_currentNodeIdx    = MK4_NODE_AT(unsigned int, idx, 0x18);
    g_eventQueuePending = 0x2ad236;
    g_cj_00542054       = MK4_UNPTR(&g_dispatchSave1549);
    g_dualC             = 0x2ad370;
    RenderSceneNode();
    if (g_framePauseFlag != 0)
        return;

    g_xformDirtyFlags &= 0xfffffffeu;
}
#else
__declspec(naked) void RenderSceneGraphIterate(void) {
    __asm {
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x53
        _emit    0x33
        _emit    0xdb
        _emit    0x55
        _emit    0x8b
        _emit    0x14
        _emit    0x85
        _emit    0x18
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x56
        _emit    0x3b
        _emit    0xd3
        _emit    0x57
        _emit    0x89
        _emit    0x15
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x84
        _emit    0x9e
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x35
        _emit    0x58
        _emit    0x81
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x85
        _emit    0x34
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x3b
        _emit    0xc6
        _emit    0x89
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8d
        _emit    0x3c
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x75
        _emit    0x08
        _emit    0x89
        _emit    0x1d
        _emit    0x3c
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0xeb
        _emit    0x18
        _emit    0x8b
        _emit    0x2d
        _emit    0x5c
        _emit    0x81
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0xf0
        _emit    0x2b
        _emit    0xf5
        _emit    0xf7
        _emit    0xde
        _emit    0x1b
        _emit    0xf6
        _emit    0x83
        _emit    0xe6
        _emit    0xfe
        _emit    0x46
        _emit    0x89
        _emit    0x35
        _emit    0x3c
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0xf6
        _emit    0xc1
        _emit    0x04
        _emit    0x74
        _emit    0x1c
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x6d
        _emit    0x32
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x24
        _emit    0xfe
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x8b
        _emit    0x15
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc0
        _emit    0x18
        _emit    0x83
        _emit    0xe2
        _emit    0xcf
        _emit    0xa3
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xf6
        _emit    0xc1
        _emit    0x02
        _emit    0x89
        _emit    0x15
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb8
        _emit    0x38
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x74
        _emit    0x05
        _emit    0xb8
        _emit    0xd8
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0xc1
        _emit    0xf8
        _emit    0x02
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x50
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x1d
        _emit    0x7c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x57
        _emit    0x60
        _emit    0x3b
        _emit    0xd3
        _emit    0x75
        _emit    0x56
        _emit    0x39
        _emit    0x5f
        _emit    0x64
        _emit    0x75
        _emit    0x51
        _emit    0x39
        _emit    0x5f
        _emit    0x68
        _emit    0x75
        _emit    0x4c
        _emit    0xc1
        _emit    0xe0
        _emit    0x02
        _emit    0xf6
        _emit    0xc1
        _emit    0x01
        _emit    0xba
        _emit    0x00
        _emit    0x10
        _emit    0x00
        _emit    0x00
        _emit    0x74
        _emit    0x24
        _emit    0xc7
        _emit    0x00
        _emit    0x00
        _emit    0xf0
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc9
        _emit    0x30
        _emit    0x89
        _emit    0x0d
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x58
        _emit    0x04
        _emit    0x89
        _emit    0x50
        _emit    0x08
        _emit    0x89
        _emit    0x58
        _emit    0x0c
        _emit    0x66
        _emit    0x89
        _emit    0x50
        _emit    0x10
        _emit    0xeb
        _emit    0x64
        _emit    0x89
        _emit    0x10
        _emit    0xc7
        _emit    0x05
        _emit    0x7c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x58
        _emit    0x04
        _emit    0x89
        _emit    0x50
        _emit    0x08
        _emit    0x89
        _emit    0x58
        _emit    0x0c
        _emit    0x66
        _emit    0x89
        _emit    0x50
        _emit    0x10
        _emit    0xeb
        _emit    0x49
        _emit    0xb8
        _emit    0x88
        _emit    0x78
        _emit    0x4f
        _emit    0x00
        _emit    0xc1
        _emit    0xf9
        _emit    0x18
        _emit    0xc1
        _emit    0xf8
        _emit    0x02
        _emit    0x83
        _emit    0xe1
        _emit    0x07
        _emit    0x03
        _emit    0xc1
        _emit    0xa3
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x04
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa3
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xff
        _emit    0xd0
        _emit    0x39
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x81
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xf6
        _emit    0x05
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x01
        _emit    0x74
        _emit    0x11
        _emit    0xe8
        _emit    0xf9
        _emit    0x3e
        _emit    0x00
        _emit    0x00
        _emit    0x39
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x67
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xf6
        _emit    0x05
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x02
        _emit    0xb8
        _emit    0xd8
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0x74
        _emit    0x05
        _emit    0xb8
        _emit    0xc0
        _emit    0x4d
        _emit    0xab
        _emit    0x00
        _emit    0xc1
        _emit    0xf8
        _emit    0x02
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x4f
        _emit    0x2c
        _emit    0x3b
        _emit    0xcb
        _emit    0x89
        _emit    0x0d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x26
        _emit    0xa1
        _emit    0x50
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc1
        _emit    0x15
        _emit    0x89
        _emit    0x0d
        _emit    0x50
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x31
        _emit    0x36
        _emit    0x00
        _emit    0x00
        _emit    0xeb
        _emit    0x3a
        _emit    0x8b
        _emit    0x4f
        _emit    0x54
        _emit    0x89
        _emit    0x0d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0c
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x47
        _emit    0x58
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x95
        _emit    0x04
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x47
        _emit    0x5c
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x8d
        _emit    0x08
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xf6
        _emit    0x05
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x02
        _emit    0x0f
        _emit    0x85
        _emit    0xde
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x66
        _emit    0x8b
        _emit    0x2d
        _emit    0x88
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0xa1
        _emit    0x78
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x7c
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x80
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x35
        _emit    0x84
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x66
        _emit    0x89
        _emit    0x2d
        _emit    0xa0
        _emit    0xf9
        _emit    0x7a
        _emit    0x00
        _emit    0x8b
        _emit    0x2d
        _emit    0x7c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x90
        _emit    0xf9
        _emit    0x7a
        _emit    0x00
        _emit    0x3b
        _emit    0xeb
        _emit    0x89
        _emit    0x0d
        _emit    0x94
        _emit    0xf9
        _emit    0x7a
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x98
        _emit    0xf9
        _emit    0x7a
        _emit    0x00
        _emit    0x89
        _emit    0x35
        _emit    0x9c
        _emit    0xf9
        _emit    0x7a
        _emit    0x00
        _emit    0x74
        _emit    0x25
        _emit    0x89
        _emit    0x15
        _emit    0xe0
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x88
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0xa3
        _emit    0xd8
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0xdc
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x35
        _emit    0xe4
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0xe8
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0xeb
        _emit    0x19
        _emit    0xc7
        _emit    0x05
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x38
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xd8
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0xe8
        _emit    0xa4
        _emit    0x36
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x1c
        _emit    0x4d
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0xdc
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0xa1
        _emit    0x18
        _emit    0x4d
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x35
        _emit    0xd8
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0x2b
        _emit    0xd1
        _emit    0x2b
        _emit    0xf0
        _emit    0xa1
        _emit    0xe0
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0xdc
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x20
        _emit    0x4d
        _emit    0xab
        _emit    0x00
        _emit    0x68
        _emit    0xc0
        _emit    0x4d
        _emit    0xab
        _emit    0x00
        _emit    0x2b
        _emit    0xc2
        _emit    0x68
        _emit    0xd8
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x35
        _emit    0xd8
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0xa3
        _emit    0xe0
        _emit    0x4c
        _emit    0xab
        _emit    0x00
        _emit    0xe8
        _emit    0x0c
        _emit    0x91
        _emit    0xff
        _emit    0xff
        _emit    0xb8
        _emit    0xc0
        _emit    0x4d
        _emit    0xab
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0xc1
        _emit    0xf8
        _emit    0x02
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xeb
        _emit    0x05
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x04
        _emit    0x85
        _emit    0x08
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x8d
        _emit    0x50
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x47
        _emit    0x3c
        _emit    0xf7
        _emit    0xc1
        _emit    0x00
        _emit    0x00
        _emit    0x08
        _emit    0x00
        _emit    0xa3
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x2e
        _emit    0x3b
        _emit    0x05
        _emit    0x78
        _emit    0x7f
        _emit    0x53
        _emit    0x00
        _emit    0x0f
        _emit    0x84
        _emit    0xb9
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x3b
        _emit    0x05
        _emit    0xe0
        _emit    0x1d
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x84
        _emit    0xad
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x3b
        _emit    0x05
        _emit    0x6c
        _emit    0x5e
        _emit    0x53
        _emit    0x00
        _emit    0x0f
        _emit    0x84
        _emit    0xa1
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x81
        _emit    0x25
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xff
        _emit    0xff
        _emit    0xf7
        _emit    0xff
        _emit    0x3b
        _emit    0xc3
        _emit    0x74
        _emit    0x31
        _emit    0x8b
        _emit    0x04
        _emit    0x85
        _emit    0x3c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa3
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc1
        _emit    0xf8
        _emit    0x08
        _emit    0x83
        _emit    0xf8
        _emit    0x50
        _emit    0x7d
        _emit    0x05
        _emit    0xb8
        _emit    0x50
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x3d
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x7e
        _emit    0x05
        _emit    0xb8
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x0f
        _emit    0xaf
        _emit    0x05
        _emit    0x68
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0xc1
        _emit    0xe8
        _emit    0x08
        _emit    0xeb
        _emit    0x05
        _emit    0xa1
        _emit    0x68
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0xa3
        _emit    0x6c
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb8
        _emit    0xd8
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x38
        _emit    0x4e
        _emit    0xab
        _emit    0x00
        _emit    0x8b
        _emit    0x57
        _emit    0x18
        _emit    0xb9
        _emit    0xc0
        _emit    0x4d
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc1
        _emit    0xf8
        _emit    0x02
        _emit    0xc1
        _emit    0xf9
        _emit    0x02
        _emit    0xa3
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x54
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xd8
        _emit    0x48
        _emit    0xab
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xaa
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x39
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x75
        _emit    0x0c
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x24
        _emit    0xfe
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x8b
        _emit    0x04
        _emit    0x85
        _emit    0x34
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xe0
        _emit    0x08
        _emit    0x0b
        _emit    0xc8
        _emit    0xa3
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xf3
        _emit    0xf3
        _emit    0xff
        _emit    0xff
        _emit    0xe9
        _emit    0x75
        _emit    0xff
        _emit    0xff
        _emit    0xff
    }
}
#endif
