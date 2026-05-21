/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004462c0 (38b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x5c]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax
 *   ret
 */
void ScaledChainStore_004462c0(void) {
    unsigned int base = g_baseSel_00542060;
    unsigned int v = *(unsigned int *)(base * 4 + 0x5c);
    unsigned int v2;
    g_scaledInit_00542044 = v;
    v2 = *(unsigned int *)(base * 4 + 0x38);
    g_walkCallback = (void (*)(void))v2;
    *(unsigned int *)(v * 4 + 0x28) = v2;
}
