/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004464f0 (33b)
 *   mov     eax, [g_baseSel_00542060]
 *   xor     ecx, ecx
 *   mov     eax, [eax*4 + 0x30]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [eax*4 + 0x28], ecx
 *   ret
 */
void ScaledLoadZeroStore_004464f0(void) {
    unsigned int scaled = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = 0;
    g_scaledInit_00542044 = scaled;
    *(unsigned int *)(scaled * 4 + 0x28) = 0;
}
