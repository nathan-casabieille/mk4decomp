/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern void Mul10Tail_00404af0(void);

/* @addr 0x0041f230 (49b): same shape, no `sub`, esp adjust earlier */
void RandSarMod0xFFF_0041f230(void) {
    int r;
    unsigned int idx;
    r = ((int (*)(int, int))Mul10Tail_00404af0)(0x028be602, (int)g_eventQueueWorkType);
    idx = (unsigned int)(r >> 16) & 0xfff;
    g_eventQueueWorkType = idx;
    g_walkCallback = (void (*)(void))(g_sinTable[idx] >> 12);
}
