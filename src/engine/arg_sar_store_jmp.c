/**
 * Auto-split from misc_matches6.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#endif


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

/* @addr 0x004594f0 (30b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [g_baseSel]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     [ecx*4 + 0x48], eax
 *   jmp     +2
 */
extern void PendingMatch_00459510(void);
void ArgSarStoreJmp(int arg) {
    unsigned int base = g_baseSel;
    int v = arg >> 2;
    g_eventQueueTotal = (unsigned int)v;
    *(int *)(base * 4 + 0x48) = v;
    PendingMatch_00459510();
}
