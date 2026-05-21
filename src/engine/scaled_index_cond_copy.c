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

/* @addr 0x0048e590 (69b)
 *   eax = arg0 >> 2 → g_eventQueueTotal; ecx = [eax*4+0] → scaled;
 *   if g_fightGroupHead != [0x538158]: ecx = [eax*4+4] → scaled;
 *   eax = [ecx*4+0]; store → walk; ret.
 */
extern u32 g_eventQueueTotal;
extern unsigned int g_data_00538158;
void ScaledIndexCondCopy_0048e590(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int v;
    g_eventQueueTotal = packed;
    v = *(unsigned int *)(packed * 4 + 0);
    g_scaledInit_00542044 = v;
    if (g_fightGroupHead != g_data_00538158) {
        v = *(unsigned int *)(packed * 4 + 4);
        g_scaledInit_00542044 = v;
    }
    g_walkCallback = (void (*)(void))(*(unsigned int *)(v * 4 + 0));
}
