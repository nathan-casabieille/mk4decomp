/**
 * HitReactionDispatcher - 0x0045f650 (625b game.fight)
 *
 * Runs every camera-handler frame (the CallPauseLoadAndDispatch tail).
 * Reads the reaction word 0x54207c (mstack-bracketed around an optional
 * ScaledMove48to58 when group-head[+0x40] has bit 9): byte 2 carries the
 * reaction BITS, byte 0 the reaction INDEX. The first set bit of
 * {1,2,4,8,0x20} picks a code-pointer table (0x4ebee0 / 0x4f2810 /
 * 0x4ed8f8 / 0x4ebff0 / 0x4e4c78); bits 1/2/4 run FiveCallScaledChainTailJmp
 * + ScaledZeroFour first, bits 8/0x20 only the former, each bracketed so
 * the masked index survives the calls. The picked slot (table>>2 + index)
 * is fetched; state-bit 2 in 0x54208c is set while dispatching and cleared
 * once the pointer is known non-null; a null slot (or no bits at all)
 * falls through to ZeroScaledZeroCallPauseJmp, the idle-pose default.
 * Every pause exit leaks the bracket push (the usual abort pattern).
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 * The table entries are raw code VAs - resolved through MK4_ResolveCode,
 * which names any VA the trampoline is missing.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void ScaledMove48to58(void);
extern void FiveCallScaledChainTailJmp(void);
extern void ScaledZeroFour(void);
extern void ZeroScaledZeroCallPauseJmp(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_reactionWord    (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))

static unsigned int hr_bracket_calls(unsigned int idx, int zero_four)
{
    /* push the masked index, run the pre-calls, pop it back; returns the
     * pause flag so the caller can abort (leaking the push, as the
     * original does). */
    unsigned int top = g_matrixStackTop + 1;

    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = idx;
    FiveCallScaledChainTailJmp();
    if (g_framePauseFlag != 0)
        return 1;
    if (zero_four) {
        ScaledZeroFour();
        if (g_framePauseFlag != 0)
            return 1;
    }
    top = g_matrixStackTop;
    g_reactionWord = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    return 0;
}

void HitReactionDispatcher(void)
{
    unsigned int top, word, bits, idx, table, slot, fn;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_reactionWord;

    g_walkSlot6c = MK4_NODE_AT(unsigned int, g_groupHead, 0x40);
    g_scratch94 = g_walkSlot6c & 0x200;
    if (g_scratch94 != 0) {
        ScaledMove48to58();
        if (g_framePauseFlag != 0)
            return;                 /* abort: the push leaks */
    }

    top = g_matrixStackTop;
    word = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    g_reactionWord = word;
    bits = (word >> 16) & 0xff;     /* byte at 0x54207e */
    idx  = word & 0xff;
    g_scratch94 = bits & 1;
    g_slot70 = bits;
    g_reactionWord = idx;

    if ((bits & 1) != 0) {
        if (hr_bracket_calls(idx, 1)) return;
        idx = g_reactionWord;
        table = 0x4ebee0u;
    } else if ((bits & 2) != 0) {
        if (hr_bracket_calls(idx, 1)) return;
        idx = g_reactionWord;
        table = 0x4f2810u;
    } else if ((bits & 4) != 0) {
        if (hr_bracket_calls(idx, 1)) return;
        idx = g_reactionWord;
        table = 0x4ed8f8u;
    } else if ((bits & 8) != 0) {
        if (hr_bracket_calls(idx, 0)) return;
        idx = g_reactionWord;
        table = 0x4ebff0u;
    } else if ((bits & 0x20) != 0) {
        if (hr_bracket_calls(idx, 0)) return;
        idx = g_reactionWord;
        table = 0x4e4c78u;
    } else {
        ZeroScaledZeroCallPauseJmp();
        return;
    }

    slot = (table >> 2) + idx;
    g_stateBits8c |= 4u;
    g_currentNodeIdx = slot;
    fn = *(unsigned int *)MK4_PTR(slot * 4);
    g_currentNodeIdx = fn;
    if (fn == 0) {
        ZeroScaledZeroCallPauseJmp();
        return;
    }
    g_stateBits8c &= ~4u;
    ((void (*)(void))MK4_ResolveCode(fn))();
}

#endif /* NON_MATCHING */
