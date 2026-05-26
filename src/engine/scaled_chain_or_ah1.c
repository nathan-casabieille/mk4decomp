/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004462f0 (41b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x5c]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [ecx*4 + 0x20]
 *   or      ah, 1                           ; set bit 8
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
void ScaledChainOrAh1_004462f0(void) {
    unsigned int scaled = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c);
    unsigned int v;
    g_scaledInit_00542044 = scaled;
    v = ((ScenegraphNode *)(scaled * 4))->flags | 0x100;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(scaled * 4))->flags = v;
}
