/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00490310 (28b): same shape, and al, 0xf7 */
void ScaledAndAlf7_00490310(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFFF7u;
    g_eventQueueCurrent = v;
    n->bits = v;
}
