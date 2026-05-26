/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00490330 (28b): same shape, and al, 0xdf */
void ScaledAndAldf_00490330(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFFDFu;
    g_eventQueueCurrent = v;
    n->bits = v;
}
