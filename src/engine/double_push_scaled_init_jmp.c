/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00444db0 (66b)
 *   Pushes g_currentNodeIdx (0x542044) and g_eventQueueWorkType
 *   (0x542074) onto the matrix-stack at g_matrixStackTop (0x4d57ac),
 *   sets g_walkCallback (0x54206c) = 0x4e5e28 >> 2, then jmp T.
 */
extern void PendingMatch_PushSetXfmMaskCallPop_00444ef0(void);
extern unsigned int g_orphanTbl_004e5e28;
void DoublePushScaledInitJmp(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_currentNodeIdx;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueWorkType;
    g_walkCallback = (void (*)(void))((unsigned int)MK4_UNPTR(&g_orphanTbl_004e5e28) >> 2);
    PendingMatch_PushSetXfmMaskCallPop_00444ef0();
}
