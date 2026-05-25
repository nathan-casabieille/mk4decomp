/**
 * Scaled chain triple-store helper.
 *
 * Reads two fields from g_baseSel-indexed struct and cross-stores them
 * into each other's scaled-indexed slots (forms a 3-way reference chain).
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004465c0 (56b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x60]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [eax*4 + 0x4c]
 *   mov     [g_xformEntityIdx], eax
 *   mov     [ecx*4 + 0x18], eax
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_xformEntityIdx]
 *   mov     [eax*4 + 0x18], ecx
 *   ret
 */
void ScaledChainTripleStore_004465c0(void) {
    unsigned int base = g_baseSel_00542060;
    unsigned int s = *(unsigned int *)(base * 4 + 0x60);
    unsigned int e;
    g_scaledInit_00542044 = s;
    e = *(unsigned int *)(base * 4 + 0x4c);
    g_xformEntityIdx = e;
    *(unsigned int *)(e * 4 + 0x18) = s;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x18) = g_xformEntityIdx;
}
