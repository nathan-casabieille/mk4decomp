/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e3e0 (31b)
 *   mov     eax, [0x0052aac4]
 *   cmp     eax, 2
 *   mov     [g_walkCallback], eax
 *   je      +0x0f
 *   mov     eax, 0x0b
 *   mov     [g_walkCallback], eax
 *   mov     [0x0052aac4], eax
 *   ret
 */
extern unsigned int g_tickFlagF;
void Cmp2OrSet0b_0048e3e0(void) {
    unsigned int v = g_tickFlagF;
    g_walkCallback = (void (*)(void))v;
    if (v == 2) return;
    g_walkCallback = (void (*)(void))0x0b;
    g_tickFlagF = 0x0b;
}
