/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e780 (35b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +0x2d
 */
extern void ScaledLoadJmp_74_0048e7b0(void);
void ScaledChain3c74Jmp_0048e780(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x74);
    ScaledLoadJmp_74_0048e7b0();
}
