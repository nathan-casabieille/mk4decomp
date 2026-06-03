/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004464f0 (33b)
 *   mov     eax, [g_baseSel]
 *   xor     ecx, ecx
 *   mov     eax, [eax*4 + 0x30]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_currentNodeIdx], eax
 *   mov     [eax*4 + 0x28], ecx
 *   ret
 */
void ScaledLoadZeroStore(void) {
    unsigned int scaled = *(unsigned int *)(g_baseSel * 4 + 0x30);
    g_walkCallback = 0;
    g_currentNodeIdx = scaled;
    ((ScenegraphNode *)(scaled * 4))->queue_idx = 0;
}
