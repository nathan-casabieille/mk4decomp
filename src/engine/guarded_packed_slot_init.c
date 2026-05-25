/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428760 (79b)
 *   call F1; if !pause: load arg0>>2 → g_eventQueueTotal;
 *   ecx = [eax*4+0]; inc eax → g_eventQueueTotal;
 *   eax = g_fightGroupHead; g_scaledInit = ecx; [eax*4+0x24] = ecx;
 *   ecx = g_fightGroupHead; walk = 0; [ecx*4+0x28] = 0; ret.
 */
void GuardedPackedSlotInit_00428760(int arg0) {
    unsigned int packed;
    unsigned int v;
    CopyJmp_00406ba0();
    if (g_framePauseFlag != 0) return;
    packed = (unsigned int)(arg0 >> 2);
    g_eventQueueTotal = packed;
    v = *(unsigned int *)(packed * 4);
    g_eventQueueTotal = packed + 1;
    g_scaledInit_00542044 = v;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x24) = v;
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0;
}
