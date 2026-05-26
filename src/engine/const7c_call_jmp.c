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

/* @addr 0x0049afe0 (30b)
 *   mov     [g_walkCallback], 0x7c
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret
 *   jmp     +3
 *   ret
 */
extern void func_00490fd8(void);
extern void func_0049b00f(void);
void Const7cCallJmp_0049afe0(void) {
    g_walkCallback = (void(*)(void))0x7c;
    func_00490fd8();
    if (g_framePauseFlag) return;
    func_0049b00f();
}
