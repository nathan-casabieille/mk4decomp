/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00422080 (29b)
 *   mov     eax, [g_X]
 *   inc     eax
 *   cmp     eax, 9
 *   mov     [g_walkCallback], eax
 *   jle     +7
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X], eax
 *   ret
 */
extern unsigned int g_counter_0053a51c;
void IncOrZero9_00422080(void) {
    unsigned int v = g_counter_0053a51c + 1;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 9) {
        g_walkCallback = (void (*)(void))0;
        v = 0;
    }
    g_counter_0053a51c = v;
}
