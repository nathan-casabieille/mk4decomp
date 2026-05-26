/**
 * Auto-split from misc_matches6.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490330 (28b): scaled and ah, 0xdf */
void ScaledAndAhdf_00490330(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFFDFu;
    g_eventQueueCurrent = v;
    n->bits = v;
}

/* @addr 0x00490350 (28b): scaled and ah, 0xbf */
void ScaledAndAhbf_00490350(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFFBFu;
    g_eventQueueCurrent = v;
    n->bits = v;
}

/* @addr 0x00490370 (28b): scaled and ah, 0xfb */
void ScaledAndAhfb_00490370(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFFFBu;
    g_eventQueueCurrent = v;
    n->bits = v;
}

/* @addr 0x00490390 (28b): scaled and ah, 0xfe */
void ScaledAndAhfe_00490390(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFFFEu;
    g_eventQueueCurrent = v;
    n->bits = v;
}

/* @addr 0x0048de00 (25b)
 *   mov     eax, [g_xformDirtyFlags]
 *   mov     [g_xformScratch2088], 0
 *   and     al, 0xfe
 *   or      al, 4
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void DirtyFlagsManip_0048de00(void) {
    u32 v = g_xformDirtyFlags;
    g_xformScratch2088 = 0;
    g_xformDirtyFlags = (v & 0xfffffffe) | 4;
}
