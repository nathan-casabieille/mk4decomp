/**
 * The TEXT OBJECT band: how every piece of on-screen text outside DrawMenu's
 * option overlays comes to exist. The main menu's ARCADE..EXIT GAME lines,
 * PRESS START, the ROUND announcements and the fight timer digits are all
 * SCENE NODES built by this chain - which was hollow end to end, which is
 * why the title state drew nothing and the main mode-select menu had never
 * been seen natively.
 *
 *   GuardedSetupCallTailJmp(textVA, y) - the public entry: queue-bracket via
 *       AllocSlotPushTripleGlobals, stage {kind 0xa000, font 4, x 0, y},
 *       Push70CallScaleArith, restore via MStackPop4Rewrite.
 *   Push70CallScaleArith - mstack-saves the font slot, builds the string
 *       object, then x-centres the container by half the accumulated
 *       advance ((-x << 9) / 2, signed).
 *   StreamChainStringInstall - the builder: a container node (position,
 *       kind, flag 0x20000, double-linked into the scene), then ONE NODE
 *       PER GLYPH from the allocator, each pointed at its glyph record by
 *       ScaledSearchSum through the font's range table
 *       ([0x541fd8 + font*4]), advancing x proportionally (rec+0xc + the
 *       font advance at [0x4d5338 + font*4]) when the proportional byte
 *       0x4f3e24 is set, else monospace (advance + 0x7ae, glyph centred).
 *   ScaledSearchSum - glyph lookup: walk the (lo,hi) range pairs, sum the
 *       widths of the skipped ranges, index the record array that follows
 *       the table's zero terminator.
 *
 * StrLen keeps its host-pointer twin in src/engine/str_len.c (now linked);
 * this band passes it a translated pointer.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern int  StrLen(char *s);
extern void BootPhaseGateBracketedInit(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0(void);
extern void MStackBracket5_FieldClear_StateAdvance(void);
extern void MStackPush3HelperCondToggle(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_propFontByte    (*(unsigned char *)MK4_VA(unsigned char, 0x4f3e24u))

/* the record-pool seeder (0x49cd40), called by BootInitChainHeavy: builds
 * the SPARE CHAIN the glyph/bone allocator pops - 0x190 records of 0x1c
 * bytes growing downward from 0x52d718, threaded through their +0 words,
 * head parked at 0x537f24. Was a weak stub, which left the chain empty and
 * every text object glyphless. The stride constant is re-read each step
 * through the pointer parked at 0x541f98, exactly as the original does. */
void ScaledChainAccumLoop(void)
{
    unsigned int cur = 0x52d718u >> 2;
    unsigned int strideCell = *MK4_VA(unsigned int, 0x541f98u);
    unsigned int prev, i;

    *MK4_VA(unsigned int, 0x535e48u) = 0xfffffff9u;
    g_xformEntityIdx = strideCell;
    *(unsigned int *)MK4_PTR(strideCell * 4) = 0xfffffff9u;

    cur += *MK4_VA(unsigned int, 0x535e48u);
    g_currentNodeIdx = cur;
    *(unsigned int *)MK4_PTR(cur * 4) = 0;
    prev = cur;
    g_walkSlot6c = prev;
    *MK4_VA(unsigned int, 0x53a1acu) = 0x18e;
    for (i = 0; i <= 0x18e; i++) {
        cur += *(unsigned int *)MK4_PTR(strideCell * 4);
        g_currentNodeIdx = cur;
        *(unsigned int *)MK4_PTR(cur * 4) = prev;
        prev = cur;
        g_walkSlot6c = prev;
        *MK4_VA(unsigned int, 0x53a1acu) = 0x18e - i - 1;
    }
    g_walkSlot6c = 0x52ab58u >> 2;
    *MK4_VA(unsigned int, 0x537f24u) = 0x52ab58u >> 2;
}

void ScaledSearchSum(void)
{
    unsigned int save70 = g_slot70;
    unsigned int tbl = g_pendingNodeType;        /* font range table, packed */
    unsigned int ch = g_walkSlot6c;
    unsigned int lo, hi, skip = 0, idx = 0, gofs = 0;
    int found = 0;

    lo = *(unsigned int *)MK4_PTR(tbl * 4);
    g_slot70 = lo;
    if (lo != 0) {
        for (;;) {
            hi = *(unsigned int *)MK4_PTR((tbl + idx + 1) * 4);
            idx++;
            if ((int)ch >= (int)lo && (int)ch <= (int)hi) {
                found = 1;
                gofs = skip + (ch - lo);
                idx++;
                break;
            }
            idx++;
            skip += (hi - lo) + 1;
            lo = *(unsigned int *)MK4_PTR((tbl + idx) * 4);
            g_slot70 = lo;
            if (lo == 0)
                break;
        }
    }
    if (!found)
        gofs = 0;

    /* walk to the table's zero terminator */
    g_slot78 = 0;
    while (*(unsigned int *)MK4_PTR((tbl + idx) * 4) != 0)
        idx++;

    g_xformEntityIdx =
        *(unsigned int *)MK4_PTR((tbl + idx + gofs) * 4 + 8);
    g_slot70 = save70;
}

void StreamChainStringInstall(void)
{
    unsigned int text = g_xformEntityIdx;        /* string VA >> 2 */
    unsigned int font = g_slot70;
    unsigned int kind = g_walkSlot6c;
    unsigned int container, glyph, top, adv, i, len;
    unsigned char *s;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_pendingNodeType;

    adv = *MK4_VA(unsigned int, 0x4d5338u + font * 4u);

    BootPhaseGateBracketedInit();
    if ((g_stateBits8c & 4) == 0) {
        container = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, container, 0x30) = kind;
        MK4_NODE_AT(unsigned int, container, 0x54) = g_slot78;
        MK4_NODE_AT(unsigned int, container, 0x58) = g_slot7c;
        MK4_NODE_AT(unsigned int, container, 0x34) |= 0x20000;
        MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0();
        if (g_framePauseFlag != 0)
            return;                              /* bracket leaked, as orig */
        MStackBracket5_FieldClear_StateAdvance();
        glyph = g_currentNodeIdx;
        MK4_NODE_AT(unsigned int, glyph, 0x24) = 0;
        MK4_NODE_AT(unsigned int, container, 0x18) = glyph;
        MK4_NODE_AT(unsigned int, glyph, 0x18) = container;

        s = (unsigned char *)MK4_PTR(text * 4);
        len = (unsigned int)StrLen((char *)s);
        g_walkSlot6c = len;
        MStackPush3HelperCondToggle();           /* the glyph chain */

        glyph = g_currentNodeIdx;
#ifdef TARGET_SDL
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int n;
          if (getenv("MK4_TRACE_TEXT") && n < 8) {
              n++;
              SDL_Log("TEXT alloc: str=%.10s len=%u chain=0x%x container=0x%x bits=%x",
                      (const char *)s, len, glyph, container, g_stateBits8c); } }
#endif
        g_slot70 = 0;                            /* running x */
        for (i = 0; glyph != 0; i++) {
            unsigned int rec, w;

            *(unsigned int *)MK4_PTR(glyph * 4 + 4) = g_slot70;
            *(unsigned int *)MK4_PTR(glyph * 4 + 8) = 0;
            g_walkSlot6c = s[i];
            g_pendingNodeType = *MK4_VA(unsigned int, 0x541fd8u + font * 4u);
            g_currentNodeIdx = glyph;
            ScaledSearchSum();
            rec = g_xformEntityIdx;
#ifdef TARGET_SDL
            { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
              static int n;
              if (getenv("MK4_TRACE_TEXT") && n < 6) {
                  n++;
                  SDL_Log("TEXT '%c' font=%u tbl=0x%x rec=0x%x tbl[0..5]=%x %x %x %x %x %x",
                          s[i], font, g_pendingNodeType, rec,
                          *(unsigned int *)MK4_PTR(g_pendingNodeType * 4),
                          *(unsigned int *)MK4_PTR(g_pendingNodeType * 4 + 4),
                          *(unsigned int *)MK4_PTR(g_pendingNodeType * 4 + 8),
                          *(unsigned int *)MK4_PTR(g_pendingNodeType * 4 + 12),
                          *(unsigned int *)MK4_PTR(g_pendingNodeType * 4 + 16),
                          *(unsigned int *)MK4_PTR(g_pendingNodeType * 4 + 20)); } }
#endif
            MK4_NODE_AT(unsigned int, glyph, 0xc) = rec;
            w = MK4_NODE_AT(unsigned int, rec, 0xc);
            if (g_propFontByte != 0) {
                g_slot70 += w + adv;
            } else {
                g_slot70 += adv + 0x7ae;
                *(unsigned int *)MK4_PTR(glyph * 4 + 4) -=
                    (unsigned int)((int)w / 2);
            }
            glyph = *(unsigned int *)MK4_PTR(glyph * 4);
        }
        g_currentNodeIdx = container;
    }

    top = g_matrixStackTop;
    g_pendingNodeType = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

void Push70CallScaleArith(void)
{
    unsigned int top;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot70;

    StreamChainStringInstall();
    if ((g_stateBits8c & 4) == 0) {
        unsigned int c = g_currentNodeIdx;

        MK4_NODE_AT(unsigned int, c, 0x54) +=
            (unsigned int)(((-(int)g_slot70) << 9) / 2);
    }

    top = g_matrixStackTop;
    g_slot70 = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

void AllocSlotPushTripleGlobals(void)
{
    unsigned int q, top;

    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = g_xformEntityIdx;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot70;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot78;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot7c;
}

void MStackPop4Rewrite(void)
{
    unsigned int top, saved48, q;

    top = g_matrixStackTop;
    saved48 = *(unsigned int *)MK4_PTR(top * 4);
    g_xformEntityIdx = saved48;
    top -= 1;
    g_matrixStackTop = top;
    g_slot7c = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot78 = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot70 = *(unsigned int *)MK4_PTR(top * 4);
    *(unsigned int *)MK4_PTR(top * 4) = saved48;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    q = MK4_NODE_AT(unsigned int, g_baseSel, 4) - 1;
    g_currentNodeIdx = q;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(q * 4);
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q;

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    g_stateBits8c |= 4;
    if (g_currentNodeIdx != 0)
        g_stateBits8c ^= 4;
}

void GuardedSetupCallTailJmp(unsigned int textVA, unsigned int y)
{
    AllocSlotPushTripleGlobals();
    if (g_framePauseFlag != 0)
        return;
    g_xformEntityIdx = textVA >> 2;
    g_walkSlot6c = 0xa000;
    g_slot70 = 4;
    g_slot78 = 0;
    g_slot7c = y;
    Push70CallScaleArith();
    if (g_framePauseFlag != 0)
        return;
    MStackPop4Rewrite();                         /* jmp in the original */
}

#endif /* NON_MATCHING */
