/**
 * The POSE PIPELINE - what turns an anim id into bone positions, and the
 * reason every fighter has rendered as a blob since the first native
 * frame. Called every frame by GuardedChainCmpDualBitXor once the
 * fight-script VM sets an anim on the group:
 *
 *   BootMStackBracket3SubdispatchPair (0x407920, 437b)
 *     -> Anim_AcquireFrameData (0x401000, 282b)   frame data for frame N
 *          uncompressed: packed base + stride*N, straight into the pack
 *          compressed (rec+8 bit 15): a 12-slot LRU keyed by the group,
 *          decoded by Anim_DecodeBitstream - STILL A TRACED STUB here, so
 *          compressed anims come back zeroed (safe, wrong, and logged)
 *     -> BootChainStreamWalkExtract (0x407ae0, 287b)  walk the group's
 *          bone list; every bone whose +0x20 has bit 8 takes three words
 *          from the frame stream through ExtractBitsToVec3 (REAL)
 *     -> GuardedChainDispatch2c (0x4082d0, 122b)  when the anim record's
 *          +8 bit 0 is set, run the frame's EVENT list through
 *          MStackBootPush4Init (traced stub for now)
 *
 * The 0x407a70 sibling recurses the whole pair onto a child group.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SDL_Log(const char *, ...);
extern char *getenv(const char *);
extern void ExtractBitsToVec3(void);
extern void MStackBootPush4Init(void);
extern void Anim_DecodeBitstream(void);
extern void SetJmp_CallPauseScaledStoreAdd(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback    (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_lit16_542074    (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_xformScratch94  (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_eq_542098       (*(unsigned int *)MK4_VA(unsigned int, 0x542098u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))

#define MSTACK_AT(i)      (*(unsigned int *)MK4_PTR((i) * 4u))
#define NODE_W(n,off)     MK4_NODE_AT(unsigned int, (n), (off))

/* ---- Anim_AcquireFrameData (0x401000): returns the PACKED index of the
 * frame's data. args are cdecl (rec, frame, flag). ---- */
int Anim_AcquireFrameData(int rec_in, int frame_in, int flag)
{
    unsigned int rec = (unsigned int)rec_in;
    unsigned int frame = (unsigned int)frame_in;
    unsigned int hdr, w, stride, i, slot, best, group, slotbuf;

    hdr = *(unsigned int *)MK4_PTR(rec * 4u);
    if (hdr == 0) {
        rec = 0x4ffe88u >> 2;
        hdr = *(unsigned int *)MK4_PTR(rec * 4u);
    }
    if ((int)frame >= (int)*(unsigned int *)MK4_PTR(rec * 4u + 4u))
        frame = 0;

    w = *(unsigned int *)MK4_PTR(rec * 4u + 8u);
    stride = w >> 16;
    if ((w & 0x8000u) == 0) {
        unsigned int ret = (hdr >> 2) + stride * frame;
#ifdef TARGET_SDL
        { static int n;
          if (getenv("MK4_TRACE_ANIM") && n < 12) { n++;
            SDL_Log("ANIM rec=%06x hdr=%08x count=%u stride=%u frame=%u -> data=%06x [%08x %08x %08x %08x]",
                    rec, hdr, *(unsigned int *)MK4_PTR(rec * 4u + 4u), stride, frame, ret,
                    *(unsigned int *)MK4_PTR(ret * 4u), *(unsigned int *)MK4_PTR(ret * 4u + 4u),
                    *(unsigned int *)MK4_PTR(ret * 4u + 8u), *(unsigned int *)MK4_PTR(ret * 4u + 12u)); } }
#endif
        return (int)ret;                             /* uncompressed */
    }

    /* compressed: 12-slot LRU keyed by the group */
#ifdef TARGET_SDL
    { static int warned;
      if (!warned) { warned = 1;
          SDL_Log("ANIM compressed path hit (rec+8=%08x) - Anim_DecodeBitstream"
                  " is still a stub, poses from this anim are zeroed", w); } }
#endif
    group = g_fightGroupHead;
    slot = 0;
    for (i = 0; i < 12u; i++) {
        if (*(unsigned int *)MK4_PTR(0x523b28u + i * 4u) == group) break;
    }
    slot = i;
    if ((int)slot >= 12) {                 /* miss: evict the max-count slot */
        best = 0; slot = 0;
        for (i = 1; i < 12u; i++)
            if (*(unsigned int *)MK4_PTR(0x523ae8u + i * 4u) >=
                *(unsigned int *)MK4_PTR(0x523ae8u + best * 4u))
                { best = i; }
        /* the original keeps the FIRST maximal index scanning 1..11 with
         * jae - i.e. later ties win; match that */
        slot = 0; best = 0;
        for (i = 1; i < 12u; i++)
            if (*(unsigned int *)MK4_PTR(0x523ae8u + i * 4u) >=
                *(unsigned int *)MK4_PTR(0x523ae8u + slot * 4u))
                slot = i;
    }
    *(unsigned int *)MK4_PTR(0x523b28u + slot * 4u) = group;
    *(unsigned int *)MK4_PTR(0x523ae4u) = hdr;
    *(unsigned int *)MK4_PTR(0x523ae8u + slot * 4u) += 1;
    slotbuf = 0x523b58u + (slot << 7);
    *(unsigned int *)MK4_PTR(0x523b24u) = *(unsigned int *)MK4_PTR(rec * 4u + 4u);
    *(unsigned int *)MK4_PTR(0x523b20u) = stride - 3u;
    *(unsigned int *)MK4_PTR(0x523ae0u) = frame;
    *(unsigned int *)MK4_PTR(0x523b1cu) = slotbuf;
    *(unsigned char *)MK4_PTR(0x523b18u) = (unsigned char)flag;
    Anim_DecodeBitstream();
    return (int)(slotbuf >> 2);
}

/* ---- BootChainStreamWalkExtract (0x407ae0): bone-list walk ---- */
void BootChainStreamWalkExtract(void)
{
    unsigned int top, cursor, end, bone, flags, countdown;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_eventQueueTotal;

    countdown = g_pendingNodeType - 1u;
    g_eventQueueTotal = countdown;

    cursor = g_currentNodeIdx;
    end = *(unsigned int *)MK4_PTR(cursor * 4u) + cursor + 1u;
    cursor++;
    g_currentNodeIdx = cursor;
    g_lit16_542074 = end;
    if ((int)end <= (int)cursor)
        goto pop_out;

next:
    bone = *(unsigned int *)MK4_PTR(cursor * 4u);
    cursor++;
    g_walkCallback = bone;
    g_currentNodeIdx = cursor;
    if ((int)bone < 0)
        goto advance_entity;              /* negative: skip, still consume */

    g_pendingNodeType = bone;
    g_eq_542098 = (bone == 0);
    if (bone == 0)
        goto no_entity;

    flags = NODE_W(bone, 0x20);
    g_walkCallback = flags;
    g_pendingNodeType = bone + 0xfu;
    g_xformScratch94 = flags & 0x100u;
    if ((flags & 0x100u) == 0)
        goto no_entity;

    g_walkCallback = *(unsigned int *)MK4_PTR(g_xformEntityIdx * 4u);
#ifdef TARGET_SDL
    { static int n;
      if (getenv("MK4_TRACE_ANIM") && n < 20) { n++;
        SDL_Log("XTRACT bone=%06x flags=%08x entity=%06x word=%08x",
                bone, flags, g_xformEntityIdx, g_walkCallback); } }
#endif
#ifdef TARGET_SDL
    /* MK4_TRACE_ANIM=N: the pose decoder writing a bone's rotation. If the
     * fighters' bones never appear here they stay in bind pose, which is
     * what "the characters are lying down" looks like. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      extern int atoi(const char *);
      static int lim = -1; static int n;
      if (lim < 0) { char *e = getenv("MK4_TRACE_ANIM"); lim = e ? atoi(e) : 0; }
      if (n < lim) { n++;
          SDL_Log("ANIM bone=%x", *MK4_VA(unsigned int, 0x542044u)); } }
#endif
    ExtractBitsToVec3();
    if (g_framePauseFlag != 0)
        return;                            /* pop skipped - abort leak */
    end = g_lit16_542074;
    cursor = g_currentNodeIdx;

advance_entity:
    g_xformEntityIdx += 1;
    g_eq_542098 = ((int)end > (int)cursor);
    if ((int)end <= (int)cursor)
        goto pop_out;
    countdown = g_eventQueueTotal - 1u;
    g_eventQueueTotal = countdown;
    if ((int)countdown < 0)
        goto pop_out;
    goto next;

no_entity:
    if ((int)end > (int)cursor)
        goto next;

pop_out:
    top = g_matrixStackTop;
    g_eventQueueTotal = MSTACK_AT(top);
    g_matrixStackTop = top - 1;
}

/* ---- GuardedChainDispatch2c (0x4082d0): the frame's event list ---- */
void GuardedChainDispatch2c(void)
{
    unsigned int top, ev;

    ev = NODE_W(g_fightGroupHead, 0x2c);
    g_walkCallback = ev;
    if (ev == 0)
        return;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;
    g_currentNodeIdx = ev;
    MStackBootPush4Init();
    if (g_framePauseFlag != 0)
        return;
    g_walkCallback = 0;
    NODE_W(g_fightGroupHead, 0x2c) = 0;
    top = g_matrixStackTop;
    g_currentNodeIdx = MSTACK_AT(top);
    g_matrixStackTop = top - 1;
}

/* ---- BootMStackBracket3SubdispatchPair (0x407920): the per-frame anim
 * step for one group ---- */
void BootMStackBracket3SubdispatchPair(void)
{
    unsigned int top, group, anim, frame, data, bones, w;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_xformEntityIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_pendingNodeType;

    group = g_fightGroupHead;
    anim = NODE_W(group, 0x24);
    g_walkCallback = anim;
    if (anim == 0)
        goto pops;

    g_xformEntityIdx = anim;
    frame = NODE_W(group, 0x28);
    g_walkCallback = frame;
    w = NODE_W(anim, 8);
    g_pendingNodeType = (w >> 16) - 3u;
    data = (unsigned int)Anim_AcquireFrameData((int)anim, (int)frame, 0);
    g_xformEntityIdx = data;
    NODE_W(g_fightGroupHead, 0x2c) = data;
    g_xformEntityIdx = data + 3u;

    bones = NODE_W(g_fightGroupHead, 0x1c);
    g_currentNodeIdx = bones;
    if (bones != 0) {
        BootChainStreamWalkExtract();
        if (g_framePauseFlag != 0)
            return;
    }

    anim = NODE_W(g_fightGroupHead, 0x24);
    g_xformEntityIdx = anim;
    w = NODE_W(anim, 8);
    g_walkCallback = w;
    g_xformScratch94 = w & 1u;
    if ((w & 1u) != 0) {
        GuardedChainDispatch2c();
        if (g_framePauseFlag != 0)
            return;
    }

pops:
    top = g_matrixStackTop;
    g_pendingNodeType = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_xformEntityIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_currentNodeIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
}

/* ---- the 0x407a70 sibling: run the pair on a CHILD group ---- */
void BootSubdispatchChild_00407a70(void)
{
    unsigned int top;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_fightGroupHead;
    g_fightGroupHead = g_currentNodeIdx;
    BootMStackBracket3SubdispatchPair();
    if (g_framePauseFlag != 0)
        return;
    SetJmp_CallPauseScaledStoreAdd();
    if (g_framePauseFlag != 0)
        return;
    top = g_matrixStackTop;
    g_fightGroupHead = MSTACK_AT(top);
    g_matrixStackTop = top - 1;
    g_xformDirtyFlags &= 0xfffffffeu;
}

#endif /* NON_MATCHING */
