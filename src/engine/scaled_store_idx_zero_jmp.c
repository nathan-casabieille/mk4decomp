/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428300 (33b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueIdx]
 *   mov     [eax*4 + 0x24], ecx
 *   mov     [g_walkCallback], 0
 *   jmp     +0xf
 */
extern void ScaledArrStore_00428330(void);
void ScaledStoreIdxZeroJmp_00428300(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = g_eventQueueIdx;
    g_walkCallback = 0;
    ScaledArrStore_00428330();
}
