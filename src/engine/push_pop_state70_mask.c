/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_x_00537e94_v2;

/* @addr 0x00490650 (84b)
 *   PushPopWrapper saving g_eventQueueCurrent;
 *   does (state_004d50a8 << 16) | (state_004d50a4 & 0xffff);
 *   stores to current and ~that to walk; restores current.
 */
void PushPopState70Mask_00490650(void) {
    unsigned int hi;
    unsigned int packed;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueCurrent;
    hi = g_fightTableC1 << 0x10;
    packed = (g_fightTableC0 & 0xffff) | hi;
    g_eventQueueCurrent = hi;
    g_walkCallback = (void (*)(void))~packed;
    g_eventQueueCurrent = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
