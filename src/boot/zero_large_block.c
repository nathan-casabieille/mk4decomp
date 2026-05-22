/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_extra_0052ab3c;

void ZeroLargeBlock_0041f270(void) {
    g_extra_0052ab3c = 0;
    memset(g_nodeSlotsArea, 0, 0x0e80 * 4);
}
