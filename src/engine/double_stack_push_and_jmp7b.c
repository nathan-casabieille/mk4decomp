/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00474090 (63b): DoubleStackPushAndJmp variant, value=0x7b */
extern void func_004740d0_zz(void);
void DoubleStackPushAndJmp7b(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_currentNodeIdx;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_fightGroupHead;
    g_currentNodeIdx = 0x7b;
    func_004740d0_zz();
}
