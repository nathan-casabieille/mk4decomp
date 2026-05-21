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

/* @addr 0x004a4260 (75b)
 *   pendingNodeType = 0x4200b0 (a func ptr stored as data);
 *   eventQueueWorkType = 0x1000; call F; pause → ret;
 *   eax = 2; [0x543800] = -1; walk = eax; [0x52aac4] = eax;
 *   eventQueueWorkType = 0; jmp T.
 */
extern unsigned int g_data_00543800;
extern void *AllocNode(void);
extern void Push16Call_00489f50(void);
void InitDispatchersJmp_004a4260(void) {
    g_pendingNodeType = 0x004200b0;
    g_eventQueueWorkType = 0x1000;
    AllocNode();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_data_00543800 = 0xffffffff;
    g_walkCallback = (void (*)(void))2;
    g_data_0052aac4 = 2;
    g_eventQueueWorkType = 0;
    Push16Call_00489f50();
}
