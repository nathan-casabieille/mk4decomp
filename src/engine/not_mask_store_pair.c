/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045f440 (38b)
 *   mov     eax, [g_X]
 *   mov     ecx, [g_Y]
 *   not     eax
 *   not     ecx
 *   and     eax, 0xffff
 *   and     ecx, 0xffff
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueCurrent], ecx
 *   ret
 */
extern unsigned int g_state_004d50a4;
extern unsigned int g_state_004d50a8;
void NotMaskStorePair_0045f440(void) {
    unsigned int a = ~g_state_004d50a4 & 0xffff;
    unsigned int b = ~g_state_004d50a8 & 0xffff;
    g_walkCallback      = (void(*)(void))a;
    g_eventQueueCurrent = b;
}
