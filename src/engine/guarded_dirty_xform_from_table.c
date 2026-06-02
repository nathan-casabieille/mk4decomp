/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f6d0 (73b)
 *   call F; pause → ret; if (dirty & 4) → ret;
 *   ecx = fightGroupHead; edx = [0x538158]; eax = [0x542038];
 *   xformEntityIdx = eax; cmp ecx,edx; if !=, eax = [0x54203c],
 *   xformEntityIdx = eax; edx = g_scaledInit_00542044;
 *   [eax*4+0] = edx; ret.
 */
extern unsigned int g_dispatchSave416;
extern unsigned int g_dispatchSave417;
extern void DirtyToggleByGate(void);
void GuardedDirtyXformFromTable(void) {
    unsigned int v;
    DirtyToggleByGate();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    v = g_dispatchSave416;
    g_xformEntityIdx = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_dispatchSave417;
        g_xformEntityIdx = v;
    }
    *(unsigned int *)(v * 4) = g_scaledInit_00542044;
}
