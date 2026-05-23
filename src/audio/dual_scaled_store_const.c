/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a22c0 (44b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [eax*4 + 0], 0
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     [g_walkCallback], 2
 *   mov     [ecx*4 + 0], 2
 *   ret
 */
void DualScaledStoreConst_004a22c0(void) {
    *(unsigned int *)(g_xformEntityIdx * 4) = 0;
    g_walkCallback = (void (*)(void))2;
    *(unsigned int *)(g_scaledInit_00542044 * 4) = 2;
}
