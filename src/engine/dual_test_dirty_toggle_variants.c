/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00427ea0 (54b)
 *   mov     eax, [0x0053a408]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0x0e
 *   mov     eax, [0x00537e88]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_0053a408_s;
extern unsigned int g_state_00537e88_s;
void DualTestDirtyToggle_00427ea0(void) {
    unsigned int s1;
    unsigned int s2;
    s1 = g_state_0053a408_s;
    g_walkCallback = (void (*)(void))s1;
    if (s1 != 0) goto set_bit;
    s2 = g_state_00537e88_s;
    g_walkCallback = (void (*)(void))s2;
    if (s2 != 0) goto set_bit;
    g_xformDirtyFlags &= 0xfffffffe;
    return;
set_bit:
    g_xformDirtyFlags |= 1;
}

/* @addr 0x004282c0 (54b): same as 0x00427ea0 with je/jne swapped at first jcc */
void DualTestDirtyToggle_004282c0(void) {
    unsigned int s1;
    unsigned int s2;
    s1 = g_state_0053a408_s;
    g_walkCallback = (void (*)(void))s1;
    if (s1 == 0) goto clear_bit;
    s2 = g_state_00537e88_s;
    g_walkCallback = (void (*)(void))s2;
    if (s2 == 0) goto clear_bit;
    g_xformDirtyFlags |= 1;
    return;
clear_bit:
    g_xformDirtyFlags &= 0xfffffffe;
}
