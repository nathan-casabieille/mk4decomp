/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004462c0 (38b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x5c]
 *   mov     [g_currentNodeIdx], ecx
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax
 *   ret
 */
void ScaledChainStore(void) {
    unsigned int base = g_baseSel;
    unsigned int v = *(unsigned int *)(base * 4 + 0x5c);
    unsigned int v2;
    g_currentNodeIdx = v;
    v2 = *(unsigned int *)(base * 4 + 0x38);
    g_walkCallback = (void (*)(void))v2;
    ((ScenegraphNode *)(v * 4))->queue_idx = v2;
}
