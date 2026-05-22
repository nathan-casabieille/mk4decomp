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

/* @addr 0x0048f6d0 (73b)
 *   call F; pause → ret; if (dirty & 4) → ret;
 *   ecx = fightGroupHead; edx = [0x538158]; eax = [0x542038];
 *   xformEntityIdx = eax; cmp ecx,edx; if !=, eax = [0x54203c],
 *   xformEntityIdx = eax; edx = g_scaledInit_00542044;
 *   [eax*4+0] = edx; ret.
 */
extern unsigned int g_data_00538158;
extern unsigned int g_data_00542038;
extern unsigned int g_data_0054203c;
extern void DirtyToggleByGate_0048f350(void);
void GuardedDirtyXformFromTable_0048f6d0(void) {
    unsigned int v;
    DirtyToggleByGate_0048f350();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    v = g_data_00542038;
    g_xformEntityIdx = v;
    if (g_fightGroupHead != g_data_00538158) {
        v = g_data_0054203c;
        g_xformEntityIdx = v;
    }
    *(unsigned int *)(v * 4) = g_scaledInit_00542044;
}
