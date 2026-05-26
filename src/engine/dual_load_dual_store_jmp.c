/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00485d70 (27b)
 *   mov     eax, [g_X1]
 *   mov     ecx, [g_X2]
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +5
 */
extern unsigned int g_dual_0053a1a8;
extern unsigned int g_dual_0053a1a4;
extern void Mul10Tail5xInterp_00485d90(void);
void DualLoadDualStoreJmp_00485d70(void) {
    g_walkCallback        = (void (*)(void))g_dual_0053a1a8;
    g_eventQueueCurrent   = g_dual_0053a1a4;
    Mul10Tail5xInterp_00485d90();
}
