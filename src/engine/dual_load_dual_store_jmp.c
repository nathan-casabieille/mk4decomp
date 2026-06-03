/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00485d70 (27b)
 *   mov     eax, [g_X1]
 *   mov     ecx, [g_X2]
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +5
 */
extern unsigned int g_dual_0053a1a8;
extern unsigned int g_dual_0053a1a4;
extern void Mul10Tail5xInterp(void);
void DualLoadDualStoreJmp(void) {
    g_walkCallback        = (void (*)(void))g_dual_0053a1a8;
    g_eventQueueCurrent   = g_dual_0053a1a4;
    Mul10Tail5xInterp();
}
