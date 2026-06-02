/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer;

/* @addr 0x00474010 (63b)
 *   inc g_matrixStackTop twice, push g_scaledInit_00542044 and g_fightGroupHead
 *   onto stack[idx*4]; mov g_scaledInit_00542044 = 0x7c; jmp T.
 */
extern void HalveChainTriplePop2(void);
void DoubleStackPushAndJmp(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_scaledInit_00542044;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_fightGroupHead;
    g_scaledInit_00542044 = 0x7c;
    HalveChainTriplePop2();
}
