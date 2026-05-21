/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00429730 (31b): same shape, or al,1 instead of and al,0xfe */
void ScaledStoreCurDirtyOr1_00429730(void) {
    unsigned int idx = g_fightGroupHead;
    *(unsigned int *)(idx * 4 + 0x28) = g_eventQueueCurrent;
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
