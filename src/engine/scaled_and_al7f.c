/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004902f0 (28b): same shape, and al, 0x7f */
void ScaledAndAl7f_004902f0(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFF7Fu;
    g_eventQueueCurrent = v;
    n->bits = v;
}
