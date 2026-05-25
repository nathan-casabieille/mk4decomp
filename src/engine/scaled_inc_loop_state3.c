/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048c210 (73b)
 *   mov eax = 0x00541d70 >> 2 → g_scaledInit; clear walk;
 *   set g_xformLoopCounter=3; load walk → ecx; store at [eax*4 + 0];
 *   load g_scaledInit, g_xformLoopCounter; inc both, store back; if not zero loop back.
 */
extern unsigned int g_data_00541d70;
void ScaledIncLoopState3_0048c210(void) {
    unsigned int p = (unsigned int)&g_data_00541d70 >> 2;
    g_walkCallback = (void (*)(void))0;
    g_scaledInit_00542044 = p;
    g_xformLoopCounter = 3;
    *(unsigned int *)(p * 4) = (unsigned int)g_walkCallback;
    do {
        g_scaledInit_00542044++;
        g_xformLoopCounter--;
    } while ((int)g_xformLoopCounter >= 0);
}
