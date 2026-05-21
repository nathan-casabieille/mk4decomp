/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00444db0 (66b)
 *   Pushes g_currentNodeIdx (0x542044) and g_eventQueueWorkType
 *   (0x542074) onto the matrix-stack at g_matrixStackTop (0x4d57ac),
 *   sets g_walkCallback (0x54206c) = 0x4e5e28 >> 2, then jmp T.
 */
extern void PendingMatch_00444ef0(void);
extern unsigned int g_table_004e5e28;
void DoublePushScaledInitJmp_00444db0(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_scaledInit_00542044;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_eventQueueWorkType;
    g_walkCallback = (void (*)(void))((unsigned int)&g_table_004e5e28 >> 2);
    PendingMatch_00444ef0();
}
