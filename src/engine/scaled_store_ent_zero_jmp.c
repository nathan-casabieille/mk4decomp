/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00428e40 (33b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_xformEntityIdx]
 *   mov     [g_eventQueueCurrent], 0
 *   mov     [eax*4 + 0x24], ecx
 *   jmp     +0xf
 */
extern void ScaledArrStore_EsiInstallBitCallChain_00428e70(void);
void ScaledStoreEntZeroJmp(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int ent = g_xformEntityIdx;
    g_eventQueueCurrent = 0;
    ((ScenegraphNode *)(idx * 4))->queue_end = ent;
    ScaledArrStore_EsiInstallBitCallChain_00428e70();
}
