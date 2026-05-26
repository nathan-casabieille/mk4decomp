/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004296f0 (31b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     [eax*4 + 0x28], ecx
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledStoreCurDirtyClear_004296f0(void) {
    unsigned int idx = g_fightGroupHead;
    ((ScenegraphNode *)(idx * 4))->queue_idx = g_eventQueueCurrent;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
