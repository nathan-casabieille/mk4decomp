/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueEnd;

/* @addr 0x004949b0 (55b)
 *   arg sar 2 → g_eventQueueEnd; +3 → g_eventQueueTotal;
 *   load [eax*4 + 0]; store at [baseSel*4 + 0x6c]; clear g_eventQueueTotal; jmp T.
 */
extern void MoveDispatch4StateFsm_00494a60(void);
void ArgScaledChain_004949b0(int arg) {
    unsigned int base = (unsigned int)(arg >> 2);
    unsigned int basePlus3;
    g_eventQueueEnd = base;
    basePlus3 = base + 3;
    g_eventQueueTotal = basePlus3;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x6c) = *(unsigned int *)(basePlus3 * 4);
    g_eventQueueTotal = 0;
    MoveDispatch4StateFsm_00494a60();
}
