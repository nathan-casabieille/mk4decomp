/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern u32 g_eventQueueCurrent;
extern u32 g_eventQueueWorkType;

/* @addr 0x00490650 (84b)
 *   PushPopWrapper saving g_eventQueueCurrent;
 *   does (state_004d50a8 << 16) | (state_004d50a4 & 0xffff);
 *   stores to current and ~that to walk; restores current.
 */
extern unsigned int g_state_004d50a8;
extern unsigned int g_state_004d50a4;
void PushPopState70Mask_00490650(void) {
    unsigned int hi;
    unsigned int packed;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_eventQueueCurrent;
    hi = g_state_004d50a8 << 0x10;
    packed = (g_state_004d50a4 & 0xffff) | hi;
    g_eventQueueCurrent = hi;
    g_walkCallback = (void (*)(void))~packed;
    g_eventQueueCurrent = *(unsigned int *)(g_state_004d57ac * 4);
    g_state_004d57ac--;
}
