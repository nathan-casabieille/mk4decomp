/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004aa940 (76b)
 *   PushPopScaledInit save/restore wrapper around: load [0x54343c]
 *   into g_scaledInit, call helper, clear [0x54343c]. Standard
 *   "scoped global swap" pattern.
 */
extern unsigned int g_audioInitScaled;
extern void MStackPush2ChainLLInsert(void);
void PushPopScaledInit343c(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_scaledInit_00542044;
    g_scaledInit_00542044 = g_audioInitScaled;
    MStackPush2ChainLLInsert();
    g_audioInitScaled = 0;
    g_scaledInit_00542044 = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
