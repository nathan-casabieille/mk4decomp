/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446320 (36b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, 2
 *   mov     eax, [eax*4 + 0x5c]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [eax*4 + 0x1c], ecx
 *   ret
 */
void ScaledStoreConst2_00446320(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c);
    g_walkCallback = (void (*)(void))2;
    g_scaledInit_00542044 = v;
    ((ScenegraphNode *)(v * 4))->alloc_flags = 2;
}
