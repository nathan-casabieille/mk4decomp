/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428e40 (33b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_xformEntityIdx]
 *   mov     [g_eventQueueCurrent], 0
 *   mov     [eax*4 + 0x24], ecx
 *   jmp     +0xf
 */
extern void ScaledArrStore_00428e70(void);
void ScaledStoreEntZeroJmp_00428e40(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int ent = g_xformEntityIdx;
    g_eventQueueCurrent = 0;
    ((ScenegraphNode *)(idx * 4))->queue_end = ent;
    ScaledArrStore_00428e70();
}
