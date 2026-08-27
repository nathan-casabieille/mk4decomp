/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0048c210 (73b)
 *   mov eax = 0x00541d70 >> 2 → g_scaledInit; clear walk;
 *   set g_xformLoopCounter=3; load walk → ecx; store at [eax*4 + 0];
 *   load g_scaledInit, g_xformLoopCounter; inc both, store back; if not zero loop back.
 */
extern unsigned int g_scaledIncLoopBase;
void ScaledIncLoopState3(void) {
    unsigned int p = (unsigned int)MK4_UNPTR(&g_scaledIncLoopBase) >> 2;
    g_walkCallback = (void (*)(void))0;
    g_currentNodeIdx = p;
    g_xformLoopCounter = 3;
    *(unsigned int *)(p * 4) = (unsigned int)g_walkCallback;
    do {
        g_currentNodeIdx++;
        g_xformLoopCounter--;
    } while ((int)g_xformLoopCounter >= 0);
}
