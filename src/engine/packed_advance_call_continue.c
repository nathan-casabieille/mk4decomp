/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0048e630 (75b)
 *   eax = arg0 >> 2 → g_eventQueueTotal; ecx = [eax*4+0];
 *   walk = ecx; inc eax → g_eventQueueTotal; call F; pause → ret;
 *   load eax again, edx = [eax*4+0]; xformEntityIdx = edx;
 *   inc eax → g_eventQueueTotal; jmp T.
 */
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
void PackedAdvanceCallContinue(int arg0) {
    unsigned int packed;
    packed = (unsigned int)(arg0 >> 2);
    g_eventQueueTotal = packed;
    g_walkCallback = (void (*)(void))*(unsigned int *)(packed * 4);
    packed++;
    g_eventQueueTotal = packed;
    SetJmp_Thunk_LinkedListBitMaskSearch();
    if (g_framePauseFlag != 0) return;
    packed = g_eventQueueTotal;
    g_xformEntityIdx = *(unsigned int *)(packed * 4);
    packed++;
    g_eventQueueTotal = packed;
    Thunk_ChainNodeInit();
}
