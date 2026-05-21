/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490e90 (43b)
 *   mov     eax, [g_fightGroupHead]
 *   xor     ecx, ecx
 *   shl     eax, 2
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x60], ecx
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax + 0x68], ecx
 *   mov     ecx, 0x0004c7ae
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x64], ecx
 *   ret
 */
void InitThreeFields_00490e90(void) {
    unsigned char *base = (unsigned char *)(g_fightGroupHead * 4);
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(base + 0x60) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x68) = (unsigned int)g_walkCallback;
    g_walkCallback = (void (*)(void))0x0004c7ae;
    *(unsigned int *)(base + 0x64) = (unsigned int)g_walkCallback;
}
