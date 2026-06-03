/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x00490330 (28b): same shape, and al, 0xdf */
void ScaledAndAldf(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFFDFu;
    g_eventQueueCurrent = v;
    n->bits = v;
}
