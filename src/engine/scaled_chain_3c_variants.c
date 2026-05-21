/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f910 (31b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   ret
 */
void ScaledChain3c74_0048f910(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x74);
}

/* @addr 0x0048f930 (31b): same shape with offset 0x7c instead of 0x74 */
void ScaledChain3c7c_0048f930(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x7c);
}
