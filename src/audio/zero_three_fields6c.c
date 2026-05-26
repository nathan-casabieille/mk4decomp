/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004abfe0 (38b)
 *   mov     eax, [g_fightGroupHead]
 *   xor     ecx, ecx
 *   shl     eax, 2
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x6c], ecx
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax + 0x70], ecx
 *   mov     edx, [g_walkCallback]
 *   mov     [eax + 0x74], edx
 *   ret
 */
void ZeroThreeFields6c_004abfe0(void) {
    unsigned char *base = (unsigned char *)(g_fightGroupHead * 4);
    g_walkCallback = 0;
    *(unsigned int *)(base + 0x6c) = 0;
    *(unsigned int *)(base + 0x70) = (unsigned int)g_walkCallback;
    ((ScenegraphNode *)base)->fsm_state = (unsigned int)g_walkCallback;
}
