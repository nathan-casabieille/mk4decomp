/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e5e0 (32b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   mov     [g_walkCallback], ecx
 *   mov     [g_eventQueueTotal], eax
 *   ret
 */
void IterStepNoSecond_0048e5e0(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    g_eventQueueTotal = packed;
    g_walkCallback = (void (*)(void))*(unsigned int *)(packed * 4);
    packed++;
    g_eventQueueTotal = packed;
}
