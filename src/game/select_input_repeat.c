/**
 * The SELECT-SCREEN INPUT REPEAT machine: the tag-0x262 controller at
 * 0x427780 that SceneEvalFsm installs in its state 1, and the six helpers
 * under it. It is the last unresolved code VA on the character-select path,
 * and it is the piece that turns a held direction into repeated events.
 *
 * The shape: eight slots, walked from 7 down to 0 in 0x535e50, each with its
 * own state in four parallel arrays whose bases live in 0x541fec / 0x541ff0
 * / 0x541ff4 / 0x541ff8 and are copied into slot50 / slot54 / slot58 /
 * fightGroupHead for the pass. Per slot the machine reads the pad through
 * MStackPush2TableNot, ANDs the slot's mask (from the controller node's
 * +0x38 table) against it, and then:
 *
 *   bit CLEAR (the button is up)  count the "still down" timer at
 *     slot50[2n+1] down; at zero clear slot50[2n] and, when the slot was
 *     marked, clear slot58[n] and fightGroupHead[n] and run
 *     Push48PreSetTwoStores - the RELEASE.
 *   bit SET (the button is down)  if the slot is already marked, count the
 *     repeat timer at slot54[n] down and reload it with 0xc when it goes
 *     negative - the AUTO-REPEAT; if it is not marked yet, count slot50[2n]
 *     down, and on the first press mark slot58[n] and fightGroupHead[n],
 *     run Push48PreSetTwoStores, then allocate the EVENT NODE: type 0x11,
 *     callback taken from the controller's own table at
 *     xformEntityIdx[+0x535e48+1].
 *
 * Command 0 builds the four arrays through FourVecFillMStackBracket - the
 * timers seeded 0/3 in pairs and 0xc for the repeat - and every later
 * command starts by unwinding the previous pass's bracket.
 *
 * Helpers, all of them absent until now:
 *   Eleven404b90_404c00 (0x4266d0) / Ten404c40_404bd0 (0x426780) - push and
 *     pop eleven walker slots on the CONTROLLER's own spare chain (the
 *     cursor at baseSel[+4]), not the matrix stack.
 *   ScaledPushArg_00404b90 / _00404c00 and ScaledDecPop_00404c40 / _00404bd0
 *     - that chain's primitives; each pair is the same body twice, which is
 *     why they have two names.
 *   Push48PreSetTwoStores (0x427ad0) - stamp the slot: slot54[n] = 0xc,
 *     slot50[m] = 0, slot50[m+1] = 3, under an mstack save of 0x535e48.
 *   FourVecFillMStackBracket (0x428130) - seed the four arrays.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush2TableNot(void);
extern void AllocNode(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot50          (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_slot58          (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_xformScratch94  (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_loopCounter     (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))
#define g_slotIdx         (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))
#define g_slotNo          (*(unsigned int *)MK4_VA(unsigned int, 0x535e50u))
#define g_arrA            (*(unsigned int *)MK4_VA(unsigned int, 0x541fecu))
#define g_arrB            (*(unsigned int *)MK4_VA(unsigned int, 0x541ff0u))
#define g_arrC            (*(unsigned int *)MK4_VA(unsigned int, 0x541ff4u))
#define g_arrD            (*(unsigned int *)MK4_VA(unsigned int, 0x541ff8u))

#define REPEAT_VA 0x427780u
#define AT(i)     (*(unsigned int *)MK4_PTR((i) * 4u))

/* 0x404b90 and 0x404c00 - the same body twice: push a value onto the
 * controller's spare chain and bump its cursor at baseSel[+4]. */
static void chain_push(unsigned int v)
{
    unsigned int cur = MK4_NODE_AT(unsigned int, g_baseSel, 4);

    g_currentNodeIdx = cur;
    AT(cur) = v;
    cur = g_currentNodeIdx + 1;
    g_currentNodeIdx = cur;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = cur;
}

void ScaledPushArg_00404b90(unsigned int v) { chain_push(v); }
void ScaledPushArg_00404c00(unsigned int v) { chain_push(v); }

/* 0x404c40 and 0x404bd0 - the matching pop */
static unsigned int chain_pop(void)
{
    unsigned int cur = MK4_NODE_AT(unsigned int, g_baseSel, 4) - 1;

    g_currentNodeIdx = cur;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = cur;
    return AT(cur);
}

unsigned int ScaledDecPop_00404c40(void) { return chain_pop(); }
unsigned int ScaledDecPop_00404bd0(void) { return chain_pop(); }

/* 0x4266d0 - push the eleven slots the pass will clobber */
void Eleven404b90_404c00(void)
{
    chain_push(g_walkSlot6c);
    chain_push(g_slot70);
    chain_push(g_slot74);
    chain_push(g_slot78);
    chain_push(g_slot7c);
    chain_push(g_slot80);
    chain_push(g_xformEntityIdx);
    chain_push(g_pendingNodeType);
    chain_push(g_slot50);
    chain_push(g_slotIdx);
    chain_push(g_slotNo);
}

/* 0x426780 - pop them back, in reverse */
void Ten404c40_404bd0(void)
{
    g_slotNo          = chain_pop();
    g_slotIdx         = chain_pop();
    g_slot50          = chain_pop();
    g_pendingNodeType = chain_pop();
    g_xformEntityIdx  = chain_pop();
    g_slot80          = chain_pop();
    g_slot7c          = chain_pop();
    g_slot78          = chain_pop();
    g_slot74          = chain_pop();
    g_slot70          = chain_pop();
    g_walkSlot6c      = chain_pop();
}

/* 0x427ad0 - stamp the slot's timers */
void Push48PreSetTwoStores(void)
{
    unsigned int top, i;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    AT(top) = g_slotIdx;

    AT(g_slot54 + g_slotNo) = 0xc;
    AT(g_slot50 + g_slotIdx) = 0;
    i = g_slotIdx + 1;
    g_slotIdx = i;
    g_walkSlot6c = 3;
    AT(g_slot50 + i) = 3;

    top = g_matrixStackTop;
    g_slotIdx = AT(top);
    g_matrixStackTop = top - 1;
}

/* 0x428130 - seed the four per-slot arrays */
void FourVecFillMStackBracket(void)
{
    unsigned int top, p;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    AT(top) = g_slot70;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    AT(top) = g_currentNodeIdx;

    g_currentNodeIdx = g_arrA;
    g_walkSlot6c = 0;
    g_slot70 = 3;
    g_loopCounter = 7;
    do {                                         /* pairs of 0 and 3 */
        p = g_currentNodeIdx;
        AT(p) = g_walkSlot6c;
        p = g_currentNodeIdx + 1;
        g_currentNodeIdx = p;
        AT(p) = g_slot70;
        g_currentNodeIdx = p + 1;
        g_loopCounter -= 1;
    } while ((int)g_loopCounter >= 0);

    g_currentNodeIdx = g_arrB;
    g_walkSlot6c = 0xc;
    g_loopCounter = 7;
    do {
        AT(g_currentNodeIdx) = g_walkSlot6c;
        g_currentNodeIdx += 1;
        g_loopCounter -= 1;
    } while ((int)g_loopCounter >= 0);

    g_walkSlot6c = 0;
    g_currentNodeIdx = g_arrC;
    g_loopCounter = 7;
    do {
        AT(g_currentNodeIdx) = g_walkSlot6c;
        g_currentNodeIdx += 1;
        g_loopCounter -= 1;
    } while ((int)g_loopCounter >= 0);

    g_currentNodeIdx = g_arrD;
    g_loopCounter = 7;
    do {
        AT(g_currentNodeIdx) = g_walkSlot6c;
        g_currentNodeIdx += 1;
        g_loopCounter -= 1;
    } while ((int)g_loopCounter >= 0);

    top = g_matrixStackTop;
    g_currentNodeIdx = AT(top);
    top -= 1;
    g_matrixStackTop = top;
    g_slot70 = AT(top);
    g_matrixStackTop = top - 1;
}

/* 0x427780 - the controller */
void SelectInputRepeat_00427780(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int self = g_baseSel;
    unsigned int a, n, v;

    MK4_NODE_AT(unsigned int, self, 0x84) = 0;

    if (cmd != 0) {
        Ten404c40_404bd0();
        if (g_framePauseFlag != 0) return;
    } else {
        g_xformEntityIdx = g_fightGroupHead;
        FourVecFillMStackBracket();
        if (g_framePauseFlag != 0) return;
        g_slot50 = g_arrA;
        g_slot54 = g_arrB;
        g_slot58 = g_arrC;
        g_fightGroupHead = g_arrD;
    }

    g_slotNo = 7;
    g_slotIdx = 0xe;
#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int n; unsigned int k; char b[300]; int o = 0;
      extern int SDL_snprintf(char *, unsigned long, const char *, ...);
      if (getenv("MK4_TRACE_SLOTS") && n < 1) { n++;
          for (k = 0; k < 16; k++)
              o += SDL_snprintf(b + o, sizeof b - o, "%x ",
                                AT(g_xformEntityIdx + 0xe - k));
          SDL_Log("SLOTS (mask,cb) from slot7 down: %s", b); } }
#endif
    g_slot78 = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x38);
    MStackPush2TableNot();
    if (g_framePauseFlag != 0) return;

    for (;;) {
        unsigned int hit = g_slot78 & g_walkSlot6c;

        g_xformScratch94 = hit;
        n = g_slotNo;

        if (hit == 0) {                          /* 0x42786f - button UP */
            v = AT(g_fightGroupHead + n);
            g_walkSlot6c = v;
            if (v != 0) {
                unsigned int idx = n + n + 1;
                unsigned int *cell;

                g_slotIdx = idx;
                cell = (unsigned int *)MK4_PTR((idx + g_slot50) * 4u);
                g_walkSlot6c = *cell - 1;
                if ((int)(*cell - 1) >= 0) {
                    *cell -= 1;
                    g_slotIdx -= 1;
                    if ((int)g_slotIdx >= 0)
                        AT(g_slot50 + g_slotIdx) = 0;
                    else
                        goto next;
                    goto repeat_reload;
                }
                /* 0x4278cb - the RELEASE */
                g_walkSlot6c = 0;
                AT(g_slot58 + n) = 0;
                AT(g_fightGroupHead + g_slotNo) = 0;
                g_slotIdx -= 1;
                Push48PreSetTwoStores();
                if (g_framePauseFlag != 0) return;
            }
            goto next;
        }

        /* 0x42792a - button DOWN */
        v = AT(g_fightGroupHead + n);
        g_walkSlot6c = v;
        if (v != 0) {                            /* already marked: repeat */
            unsigned int *cell = (unsigned int *)MK4_PTR((g_slot54 + n) * 4u);

            *cell -= 1;
            g_walkSlot6c = *cell;
            if ((int)*cell >= 0)
                goto next;
            g_walkSlot6c = 0xc;
            AT(g_slot54 + g_slotNo) = 0xc;
            goto fire;
        }

        {   /* 0x427978 - first press */
            unsigned int idx = n + n;
            unsigned int *cell;

            g_slotIdx = idx;
            cell = (unsigned int *)MK4_PTR((idx + g_slot50) * 4u);
            if ((int)(*cell - 1) >= 0) {
                *cell -= 1;
                g_slotIdx = idx + 1;
                AT(g_slot50 + g_slotIdx) = 3;
                goto repeat_reload;
            }
            /* 0x4279cf - mark it and raise the event */
            g_walkSlot6c = 1;
            AT(g_slot58 + n) = 1;
            AT(g_fightGroupHead + g_slotNo) = g_walkSlot6c;
            Push48PreSetTwoStores();
            if (g_framePauseFlag != 0) return;
            goto fire;
        }

repeat_reload:                                   /* 0x4279b0 */
        g_walkSlot6c = 0xc;
        AT(g_slot54 + g_slotNo) = 0xc;
        goto next;

fire:                                            /* 0x427a0e */
        Eleven404b90_404c00();
        if (g_framePauseFlag != 0) return;
        a = g_slotIdx + 1;
        g_slotIdx = a;
        v = AT(g_xformEntityIdx + a);
#ifdef TARGET_SDL
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int n;
          if (getenv("MK4_TRACE_REPEAT") && n < 12) { n++;
              SDL_Log("REPEAT slot=%u idx=%u cb=%08x mask=%x pad=%x", g_slotNo,
                      a, v, g_slot78, g_walkSlot6c); } }
#endif
        g_slot74 = 0x11;
        g_pendingNodeType = v;
        AllocNode();
        if (g_framePauseFlag != 0) return;
        Ten404c40_404bd0();
        if (g_framePauseFlag != 0) return;

next:                                            /* 0x427a5f */
        a = g_slotNo - 1;
        g_slotNo = a;
        if ((int)a < 0)
            break;
        g_slotIdx = a + a;
        g_slot78 = AT(g_xformEntityIdx + a + a);
        MStackPush2TableNot();
        if (g_framePauseFlag != 0)
            return;
    }

    /* 0x427a9f */
    Eleven404b90_404c00();
    if (g_framePauseFlag != 0) return;
    MK4_NODE_AT(unsigned int, self, 8) = REPEAT_VA;
    MK4_NODE_AT(unsigned int, self, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
