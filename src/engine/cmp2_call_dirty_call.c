/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_chainAccumCur;
#endif

/* @addr 0x004398b0 (54b)
 *   mov     eax, [0x0052aac4]
 *   cmp     eax, 2
 *   mov     [g_walkCallback], eax
 *   jne     +0x0b
 *   call    F1
 *   mov     eax, 1
 *   ret
 *   call    F2
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +0x0b
 *   call    F3
 *   mov     eax, 1
 *   ret
 *   xor     eax, eax
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_tickFlagF;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif

extern void Thunk_GuardedSeq(void);
extern void WeightedSumClampHelper(void);
extern void Thunk_GuardedSeq(void);
int Cmp2CallDirtyCall(void) {
    unsigned int v = g_tickFlagF;
    g_walkCallback = (void (*)(void))v;
    if (v == 2) {
        Thunk_GuardedSeq();
        return 1;
    }
    WeightedSumClampHelper();
    if ((g_xformDirtyFlags & 1) == 0) {
        Thunk_GuardedSeq();
        return 1;
    }
    return 0;
}
