/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e590 (69b)
 *   eax = arg0 >> 2 → g_eventQueueTotal; ecx = [eax*4+0] → scaled;
 *   if g_fightGroupHead != [0x538158]: ecx = [eax*4+4] → scaled;
 *   eax = [ecx*4+0]; store → walk; ret.
 */
void ScaledIndexCondCopy_0048e590(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int v;
    g_eventQueueTotal = packed;
    v = *(unsigned int *)(packed * 4 + 0);
    g_scaledInit_00542044 = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = *(unsigned int *)(packed * 4 + 4);
        g_scaledInit_00542044 = v;
    }
    g_walkCallback = (void (*)(void))(*(unsigned int *)(v * 4 + 0));
}
