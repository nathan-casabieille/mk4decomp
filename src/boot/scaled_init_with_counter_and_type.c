/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041f1b0 (53b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, 1
 *   shl     eax, 2
 *   mov     [eax + 0x84], 0
 *   mov     [eax + 8], 0x0041f1b0
 *   mov     [eax + 0x84], ecx
 *   mov     [g_pendingNodeType], 0x3c
 *   mov     [g_walkCallback], 0    (g_framePauseFlag area)
 *   ret
 */
extern u32 g_pendingNodeType;
void ScaledInitWithCounterAndType_0041f1b0(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    *(unsigned int *)(base + 0x84) = 0;
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitWithCounterAndType_0041f1b0;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 0x3c;
    g_framePauseFlag = 1;
}
