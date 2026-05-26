/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00488ed0 (33b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, [eax*4 + 0x7c]
 *   cmp     eax, ecx
 *   mov     [g_eventQueueCurrent], eax
 *   jl      +0x10
 *   ret
 */
extern void CjTableThresholdDispatch_00488f00(void);
void ScaledCmpJlJmp_00488ed0(void) {
    unsigned int walk = (unsigned int)g_walkCallback;
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x7c);
    g_eventQueueCurrent = v;
    if ((int)v < (int)walk) return;
    CjTableThresholdDispatch_00488f00();
}
