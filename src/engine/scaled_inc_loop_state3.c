/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_pendingNodeType;

/* @addr 0x0048c210 (73b)
 *   mov eax = 0x00541d70 >> 2 → g_scaledInit; clear walk;
 *   set g_state_0053a1ac=3; load walk → ecx; store at [eax*4 + 0];
 *   load g_scaledInit, g_state_0053a1ac; inc both, store back; if not zero loop back.
 */
extern unsigned int g_data_00541d70;
extern unsigned int g_state_0053a1ac;
void ScaledIncLoopState3_0048c210(void) {
    unsigned int p = (unsigned int)&g_data_00541d70 >> 2;
    g_walkCallback = (void (*)(void))0;
    g_scaledInit_00542044 = p;
    g_state_0053a1ac = 3;
    *(unsigned int *)(p * 4) = (unsigned int)g_walkCallback;
    do {
        g_scaledInit_00542044++;
        g_state_0053a1ac--;
    } while ((int)g_state_0053a1ac >= 0);
}
