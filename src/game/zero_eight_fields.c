/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b8f20 (43b): zero 8 fields
 *   xor     eax, eax
 *   mov     [0x00ab4d9c], eax
 *   mov     [0x00ab4da0], eax
 *   mov     [0x00ab4da4], eax
 *   mov     [0x00ab4da8], eax
 *   mov     [0x00ab4dac], eax
 *   mov     [0x00ab4db0], eax
 *   mov     [0x00ab4db4], eax
 *   mov     [0x00ab4db8], eax
 *   ret
 */
extern unsigned int g_state_00ab4d9c;
extern unsigned int g_state_00ab4da0;
extern unsigned int g_state_00ab4da4;
extern unsigned int g_state_00ab4da8;
extern unsigned int g_state_00ab4dac;
extern unsigned int g_state_00ab4db0;
extern unsigned int g_state_00ab4db4;
extern unsigned int g_state_00ab4db8;
void ZeroEightFields_004b8f20(void) {
    g_state_00ab4d9c = 0;
    g_state_00ab4da0 = 0;
    g_state_00ab4da4 = 0;
    g_state_00ab4da8 = 0;
    g_state_00ab4dac = 0;
    g_state_00ab4db0 = 0;
    g_state_00ab4db4 = 0;
    g_state_00ab4db8 = 0;
}
