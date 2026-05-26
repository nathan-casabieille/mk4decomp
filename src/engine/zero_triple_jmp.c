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

/* @addr 0x00491e50 (22b)
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X], eax
 *   mov     [g_Y], eax
 *   jmp     +0xffa
 */
extern unsigned int g_zero_0053a470;
extern unsigned int g_zero_0053a104;
extern void func_00492e50(void);
void ZeroTripleJmp_00491e50(void) {
    g_walkCallback = 0;
    g_zero_0053a470 = 0;
    g_zero_0053a104 = 0;
    func_00492e50();
}
