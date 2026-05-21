/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049d430 (30b)
 *   mov     eax, [g_scaledInit_00542044]
 *   xor     ecx, ecx
 *   cmp     eax, ecx
 *   mov     [g_walkCallback], eax
 *   je      .ret
 *   mov     [eax*4 + 8], ecx
 *   mov     [g_scaledInit_00542044], ecx
 * .ret:
 *   ret
 */
void ScaledZeroIfNonzero_0049d430(void) {
    unsigned int v = g_scaledInit_00542044;
    g_walkCallback = (void (*)(void))v;
    if (v != 0) {
        *(unsigned int *)(v * 4 + 8) = 0;
        g_scaledInit_00542044 = 0;
    }
}
