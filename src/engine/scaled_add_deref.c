/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00494800 (39b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, [eax*4 + 0x30]
 *   add     eax, ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0]
 *   mov     [g_scaledInit_00542044], ecx
 *   ret
 */
void ScaledAddDeref_00494800(void) {
    unsigned int idx;
    idx = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30) + (unsigned int)g_walkCallback;
    g_scaledInit_00542044 = idx;
    g_scaledInit_00542044 = *(unsigned int *)(idx * 4);
}
