/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0047e640 (77b)
 *   walk = g_eventQueueNotMask; call F1; pause → ret;
 *   load g_fightGroupHead; eax = [head*4+0x70];
 *   push eax, push notMask; walk = eax; call F2 (mixer-like);
 *   add esp 8; restore [head*4+0x70] = eax; ret.
 */
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void Mul10Tail_00404af0(void);
void NotMaskCallStore70_0047e640(void) {
    unsigned int v;
    unsigned int r;
    g_walkCallback = (void (*)(void))g_eventQueueNotMask;
    EsiEdiAliasDualMul10_004906b0();
    if (g_framePauseFlag != 0) return;
    v = *(unsigned int *)(g_fightGroupHead * 4 + 0x70);
    g_walkCallback = (void (*)(void))v;
    r = ((unsigned int (*)(int, int))Mul10Tail_00404af0)((int)g_eventQueueNotMask, (int)v);
    g_walkCallback = (void (*)(void))r;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x70) = r;
}
