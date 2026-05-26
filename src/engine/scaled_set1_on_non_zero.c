/**
 * Auto-split from misc_matches6.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490330 (28b): scaled and ah, 0xdf */
void ScaledAndAhdf_00490330(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = ((FightGroupNode *)(idx * 4))->bits & 0xFFFFFFDFu;
    g_eventQueueCurrent = v;
    ((FightGroupNode *)(idx * 4))->bits = v;
}

/* @addr 0x00490350 (28b): scaled and ah, 0xbf */
void ScaledAndAhbf_00490350(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = ((FightGroupNode *)(idx * 4))->bits & 0xFFFFFFBFu;
    g_eventQueueCurrent = v;
    ((FightGroupNode *)(idx * 4))->bits = v;
}

/* @addr 0x00490370 (28b): scaled and ah, 0xfb */
void ScaledAndAhfb_00490370(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = ((FightGroupNode *)(idx * 4))->bits & 0xFFFFFFFBu;
    g_eventQueueCurrent = v;
    ((FightGroupNode *)(idx * 4))->bits = v;
}

/* @addr 0x00490390 (28b): scaled and ah, 0xfe */
void ScaledAndAhfe_00490390(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = ((FightGroupNode *)(idx * 4))->bits & 0xFFFFFFFEu;
    g_eventQueueCurrent = v;
    ((FightGroupNode *)(idx * 4))->bits = v;
}

/* @addr 0x0048c190 (25b)
 *   mov     eax, [g_eventQueueEnd]
 *   test    eax, eax
 *   je      after_set
 *   mov     [eax*4 + 0], 1
 * after_set:
 *   jmp     +0x031407
 */
extern void LoadGeoAsset_Default(void);
void ScaledSet1OnNonZero_0048c190(void) {
    unsigned int v = g_eventQueueEnd;
    if (v != 0) {
        *(unsigned int *)(v * 4) = 1;
    }
    LoadGeoAsset_Default();
}
