/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00483b50 (36b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [ecx*4 + 0x7c]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   jns     +7
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x7c], eax
 *   ret
 */
void ScaledDecOrZero_00483b50(void) {
    unsigned int b = g_baseSel_00542060;
    int v = *(int *)(b * 4 + 0x7c) - 1;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        v = 0;
        g_walkCallback = (void (*)(void))v;
    }
    *(int *)(b * 4 + 0x7c) = v;
}
