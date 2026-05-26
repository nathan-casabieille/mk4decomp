/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00490390 (28b): same shape, and al, 0xfe */
void ScaledAndAlfe_00490390(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = ((FightGroupNode *)(idx * 4))->bits & 0xFFFFFFFEu;
    g_eventQueueCurrent = v;
    ((FightGroupNode *)(idx * 4))->bits = v;
}
