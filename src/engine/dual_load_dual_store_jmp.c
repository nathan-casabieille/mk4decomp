/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x00485d70 (27b)
 *   mov     eax, [g_X1]
 *   mov     ecx, [g_X2]
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +5
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dual_0053a1a8;
extern unsigned int g_dual_0053a1a4;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dual_0053a1a4 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1a4u))
#define g_dual_0053a1a8 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1a8u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern void Mul10Tail5xInterp(void);
void DualLoadDualStoreJmp(void) {
    g_walkCallback        = (void (*)(void))g_dual_0053a1a8;
    g_eventQueueCurrent   = g_dual_0053a1a4;
    Mul10Tail5xInterp();
}
