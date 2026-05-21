/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00421d20 (37b)
 *   mov     eax, 0x28f
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   mov     eax, [g_loaded_004f3608]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X3], eax
 *   mov     [g_X4], eax
 *   ret
 */
extern unsigned int g_dst_0053a6dc;
extern unsigned int g_dst_00537f2c;
extern unsigned int g_dst_0053a6e0;
extern unsigned int g_dst_00537ea4;
extern unsigned int g_loaded_004f3608;
void Init28fDecLoad_00421d20(void) {
    unsigned int v;
    g_dst_0053a6dc = 0x028f;
    g_dst_00537f2c = 0x028f;
    v = g_loaded_004f3608 - 1;
    g_walkCallback = (void(*)(void))v;
    g_dst_0053a6e0 = v;
    g_dst_00537ea4 = v;
}
