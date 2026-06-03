/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x004902f0 (28b): same shape, and al, 0x7f */
void ScaledAndAl7f(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFF7Fu;
    g_eventQueueCurrent = v;
    n->bits = v;
}
