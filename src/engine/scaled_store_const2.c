/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00446320 (36b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, 2
 *   mov     eax, [eax*4 + 0x5c]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_currentNodeIdx], eax
 *   mov     [eax*4 + 0x1c], ecx
 *   ret
 */
void ScaledStoreConst2(void) {
    unsigned int v = *(unsigned int *)(g_baseSel * 4 + 0x5c);
    g_walkCallback = (void (*)(void))2;
    g_currentNodeIdx = v;
    ((ScenegraphNode *)(v * 4))->alloc_flags = 2;
}
