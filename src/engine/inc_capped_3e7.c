/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00491920 (34b)
 *   mov     eax, [g_state_00535de4]
 *   inc     eax
 *   cmp     eax, 0x3e7
 *   mov     [g_walkCallback], eax
 *   jle     +0x0a
 *   mov     eax, 0x3e7
 *   mov     [g_walkCallback], eax
 *   mov     [g_state_00535de4], eax
 *   ret
 */
extern unsigned int g_state_00535de4;
void IncCapped3e7_00491920(void) {
    int v = (int)g_state_00535de4 + 1;
    g_walkCallback = (void (*)(void))v;
    if (v > 0x03e7) {
        v = 0x03e7;
        g_walkCallback = (void (*)(void))v;
    }
    g_state_00535de4 = (unsigned int)v;
}
