/**
 * The animation-track band: the per-node frame advancer and its wrappers.
 * LoadCmpAddrJmp tail-jumps into AnimEventUpdateCluster every anim tick;
 * with this band stubbed no pose ever advanced and both fighters rendered
 * as ~10px blobs (every vertex collapsed onto the node origin).
 *
 * DirtyDoubleDeref - 0x00408cb0 (105b): node = group-head[+0x1c]; when
 *   set, node = [node + 0x54206c]; state-bit 2 toggles around each deref
 *   (set before, cleared when the deref survives).
 *
 * TripleAddVec3 - 0x00425130 (61b): [node] = [pending] + [entity],
 *   three words, straight adds.
 *
 * Vec3AddViaHelper - 0x00425170 (120b): the same sum but each component
 *   goes through BootMod6487eClampAndChainMul10 (the angle-wrap clamp).
 *
 * ChainNodeAdvanceCallback - 0x00408e70 (609b): the track advancer.
 *   entity[+4] track base, [+8] cursor, [+0xc] frames-remaining. When the
 *   flags word allows, integrates velocity (+6/+0xc raw, +9/+0xf clamped)
 *   first. Then counts down; at zero reads the next track word: low 24
 *   bits an optional pose-record packed pointer (ScaledStoreIdx24 stores
 *   it), bit 31 arms an event, bits 24..30 the next frame count. An armed
 *   event pulls one more word: low 24 bits a code VA to call, high byte
 *   its argument in 0x54206c.
 *
 * AnimEventUpdateCluster - 0x00493ef0 (578b, two packed entries): the
 *   bracketed wrapper that re-arms a node's track record (flags |= 2,
 *   period 0x5999) and installs the second entry - the anim-tick callback
 *   at 0x494020 - into the anim record's +0x10 slot; the callback
 *   brackets five staging globals and runs the advancer unless the
 *   game-mode word at 0x543800 is set.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void ScaledTestPauseStore(void);
extern void OrDualStore_0048a190(void);
extern void DualBitGateInitCall(void);
extern void ScaledStoreIdx24(void);
extern void BootMod6487eClampAndChainMul10(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50          (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_scratch98       (*(unsigned int *)MK4_VA(unsigned int, 0x542098u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_dualBitGateByte (*(unsigned char *)MK4_VA(unsigned char, 0x53a7b0u))
#define g_gameMode3800    (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))

void DirtyDoubleDeref(void)
{
    unsigned int n;

    n = MK4_NODE_AT(unsigned int, g_groupHead, 0x1c);
    g_stateBits8c |= 4u;
    g_currentNodeIdx = n;
    if (n == 0)
        return;
    g_stateBits8c ^= 4u;
    n = g_currentNodeIdx + g_walkSlot6c;
    g_currentNodeIdx = n;
    g_stateBits8c |= 4u;
    n = *(unsigned int *)MK4_PTR(n * 4);
    g_currentNodeIdx = n;
    if (n != 0)
        g_stateBits8c ^= 4u;
}

void TripleAddVec3(void)
{
    unsigned int dst = g_currentNodeIdx;
    unsigned int a = g_xformEntityIdx, b = g_pendingNodeType;

    MK4_NODE_AT(unsigned int, dst, 0) =
        MK4_NODE_AT(unsigned int, a, 0) + MK4_NODE_AT(unsigned int, b, 0);
    MK4_NODE_AT(unsigned int, dst, 4) =
        MK4_NODE_AT(unsigned int, a, 4) + MK4_NODE_AT(unsigned int, b, 4);
    MK4_NODE_AT(unsigned int, dst, 8) =
        MK4_NODE_AT(unsigned int, a, 8) + MK4_NODE_AT(unsigned int, b, 8);
}

void Vec3AddViaHelper(void)
{
    unsigned int dst = g_currentNodeIdx;
    unsigned int a = g_xformEntityIdx, b = g_pendingNodeType;
    int i;

    for (i = 0; i < 3; i++) {
        g_walkSlot6c = MK4_NODE_AT(unsigned int, a, i * 4)
                     + MK4_NODE_AT(unsigned int, b, i * 4);
        BootMod6487eClampAndChainMul10();
        MK4_NODE_AT(unsigned int, dst, i * 4) = g_walkSlot6c;
    }
}

void ChainNodeAdvanceCallback(void)
{
    unsigned int ent = g_xformEntityIdx;
    unsigned int node = g_currentNodeIdx;
    unsigned int rec, trk, cursor, word, w, frames, cnt;


    rec = *(unsigned int *)MK4_PTR(ent * 4);
    g_walkSlot6c = rec;
    g_slot54 = ent;
    g_scratch98 = ((rec & 3) == 0);
    g_slot50 = node;
    g_scratch94 = rec & 1;

    if ((rec & 3) != 0) {
        g_scratch98 = ((rec & 1) == 0);
        g_xformEntityIdx = ent + 6;
        g_currentNodeIdx = node + 0xc;
        g_pendingNodeType = node + 0xc;
        if ((rec & 1) != 0) {
            TripleAddVec3();
            if (g_framePauseFlag != 0)
                return;
            ent = g_slot54;
        }
        rec = *(unsigned int *)MK4_PTR(ent * 4);
        g_walkSlot6c = rec;
        g_scratch94 = rec & 2;
        g_scratch98 = ((rec & 2) == 0);
        g_xformEntityIdx = ent + 9;
        if ((rec & 2) != 0) {
            g_currentNodeIdx = g_slot50 + 0xf;
            g_pendingNodeType = g_slot50 + 0xf;
            Vec3AddViaHelper();
            if (g_framePauseFlag != 0)
                return;
            ent = g_slot54;
        }
        g_currentNodeIdx = g_slot50;
        g_xformEntityIdx = ent;
    }

    trk = MK4_NODE_AT(unsigned int, ent, 4);
    g_slot78 = trk;
    if (trk == 0)
        return;

    cnt = MK4_NODE_AT(unsigned int, ent, 0xc);
    g_scratch98 = ((int)cnt > 0);
    cnt--;
    g_slot70 = cnt;
    MK4_NODE_AT(unsigned int, ent, 0xc) = cnt;
    ent = g_xformEntityIdx;
    cursor = MK4_NODE_AT(unsigned int, ent, 8);
    g_walkSlot6c = cursor;
    if (g_scratch98 != 0)
        return;                          /* still counting down */

    if (cursor == 0) {
        cursor = trk;
        g_walkSlot6c = cursor;
    }
    g_pendingNodeType = cursor;
    word = *(unsigned int *)MK4_PTR(cursor * 4);
    g_slot74 = word;
    if (word == 0) {                     /* wrap: restart the track */
        cursor = trk;
        g_pendingNodeType = cursor;
        word = *(unsigned int *)MK4_PTR(trk * 4);
        g_slot74 = word;
    }
    cursor++;
    g_pendingNodeType = cursor;
    MK4_NODE_AT(unsigned int, ent, 8) = cursor;

    w = word;
    word &= 0xffffffu;
    g_slot70 = w;
    g_slot74 = word;
    if (word != 0) {                     /* pose record for this span */
        g_walkSlot6c = (unsigned int)((int)word >> 2);
        ScaledStoreIdx24();
        if (g_framePauseFlag != 0)
            return;
        w = g_slot70;
    }

    if ((w & 0x80000000u) != 0)
        g_stateBits8c |= 1u;
    else
        g_stateBits8c &= ~1u;
    g_scratch98 = (~g_stateBits8c) & 1u;
    frames = ((w >> 24) & 0x7f) - 1;
    g_slot70 = frames;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0xc) = frames;
    if (g_scratch98 != 0)
        return;

    /* bit 31 was set: the next word is (arg << 24) | code VA */
    cursor = g_pendingNodeType;
    word = *(unsigned int *)MK4_PTR(cursor * 4);
    cursor++;
    g_slot70 = word;
    g_pendingNodeType = cursor;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8) = cursor;
    g_walkSlot6c = (unsigned int)((int)word >> 24);
    word &= 0xffffffu;
    g_slot70 = word;
#ifdef TARGET_SDL
    /* guard: a mis-installed track (see the fight-scene status memory)
     * feeds sample data here; a code VA outside the image would reach
     * the trampoline as a per-frame miss. Skip it - the miss log is the
     * work-list, not a crash. */
    if (word < 0x401000u || word > 0x4d0000u)
        return;
#endif
#ifdef TARGET_SDL
    /* MK4_TRACE_FREEPOP family: every 0x405dd0 event is a node
     * DESTRUCTION request - log which track fired it and on which node,
     * to find who arms self-destruct streams on live nodes. */
    if (word == 0x405dd0u) {
        extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static int f = -1; static int n;
        if (f < 0) f = getenv("MK4_TRACE_FREEPOP") != 0;
        if (f && n < 60) { n++;
            SDL_Log("FREEEVT node=%x rec=%x trk=%x cur=%x",
                    *MK4_VA(unsigned int, 0x542044u), g_xformEntityIdx,
                    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 4),
                    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8)); }
    }
#endif
    ((void (*)(void))MK4_ResolveCode(word))();
}

/* the second packed entry at 0x00494020, installed into anim[+0x10] */
void AnimEventNodeCallback_00494020(void)
{
    unsigned int top, node;

    top = g_matrixStackTop;
    *(unsigned int *)MK4_PTR(++top * 4) = g_currentNodeIdx;
    *(unsigned int *)MK4_PTR(++top * 4) = g_xformEntityIdx;
    *(unsigned int *)MK4_PTR(++top * 4) = g_pendingNodeType;
    *(unsigned int *)MK4_PTR(++top * 4) = g_slot50;
    *(unsigned int *)MK4_PTR(++top * 4) = g_slot54;
    g_matrixStackTop = top;

    node = *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4);
    g_currentNodeIdx = node;
    g_xformEntityIdx = MK4_NODE_AT(unsigned int, node, 0x28);
    if (g_gameMode3800 == 0) {
        ChainNodeAdvanceCallback();
        if (g_framePauseFlag != 0)
            return;                  /* abort: the five pushes leak */
    }
    top = g_matrixStackTop;
    g_slot54 = *(unsigned int *)MK4_PTR(top-- * 4);
    g_slot50 = *(unsigned int *)MK4_PTR(top-- * 4);
    g_pendingNodeType = *(unsigned int *)MK4_PTR(top-- * 4);
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top-- * 4);
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top-- * 4);
    g_matrixStackTop = top;
}

void AnimEventUpdateCluster(void)
{
    unsigned int top, rec, anim;


    top = g_matrixStackTop;
    *(unsigned int *)MK4_PTR(++top * 4) = g_currentNodeIdx;
    *(unsigned int *)MK4_PTR(++top * 4) = g_xformEntityIdx;
    g_matrixStackTop = top;

    g_walkSlot6c = 1;
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0)
        return;                      /* abort: the two pushes leak */
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(g_currentNodeIdx * 4);
    ScaledTestPauseStore();
    if (g_framePauseFlag != 0)
        return;

    if ((g_stateBits8c & 4) == 0) {
        rec = *(unsigned int *)MK4_PTR(g_xformEntityIdx * 4) | 2u;
        *(unsigned int *)MK4_PTR(g_xformEntityIdx * 4) = rec;
        MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x2c) = 0x5999u;
        g_walkSlot6c = 1;
        DirtyDoubleDeref();
        if (g_framePauseFlag != 0)
            return;
        anim = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x28);
        g_walkSlot6c = 0x494020u;
        g_xformEntityIdx = anim;
        MK4_NODE_AT(unsigned int, anim, 0x10) = 0x494020u;
        if ((g_dualBitGateByte & 1) == 0) {
            g_walkSlot6c = 1;
            OrDualStore_0048a190();
            if (g_framePauseFlag != 0)
                return;
            DualBitGateInitCall();
            if (g_framePauseFlag != 0)
                return;
        }
    }

    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top-- * 4);
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top-- * 4);
    g_matrixStackTop = top;
}

#endif /* NON_MATCHING */
