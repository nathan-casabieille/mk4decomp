/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0046ea70 (39b)
 *   cmp     [g_xformScratch2088], 1
 *   jne     +0x1d
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x70]
 *   cmp     eax, 0x20e
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void GuardedSeq_0047d980(void);
void DirtyTestScaledCmpJmp_0046ea70(void) {
    unsigned int v;
    if (g_xformScratch2088 != 1) return;
    v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x70);
    g_walkCallback = (void (*)(void))v;
    if (v != 0x20e) return;
    GuardedSeq_0047d980();
}
