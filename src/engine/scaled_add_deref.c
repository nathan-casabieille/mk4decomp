/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00494800 (39b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, [eax*4 + 0x30]
 *   add     eax, ecx
 *   mov     [g_currentNodeIdx], eax
 *   mov     ecx, [eax*4 + 0]
 *   mov     [g_currentNodeIdx], ecx
 *   ret
 */
void ScaledAddDeref(void) {
    unsigned int idx;
    idx = *(unsigned int *)(g_baseSel * 4 + 0x30) + (unsigned int)g_walkCallback;
    g_currentNodeIdx = idx;
    g_currentNodeIdx = *(unsigned int *)(idx * 4);
}
