/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e710 (40b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [0x0052aac4]
 *   sar     eax, 2
 *   add     eax, ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     eax
 */
extern unsigned int g_state_0052aac4_k;
void ArgSarAddDerefJmp_0048e710(int arg) {
    unsigned int c = g_state_0052aac4_k;
    unsigned int v = (unsigned int)(arg >> 2) + c;
    g_walkCallback = (void (*)(void))c;
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4);
    g_scaledInit_00542044 = v;
    ((void (*)(void))v)();
}
