/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049d310 (42b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_walkCallback]
 *   shl     eax, 2
 *   mov     [eax + 4], ecx
 *   mov     edx, [g_eventQueueCurrent]
 *   mov     [eax + 8], edx
 *   mov     ecx, [g_eventQueueWorkType]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x0c], ecx
 *   ret
 */
extern u32 g_eventQueueWorkType;
void ScaledStoreThree_0049d310(void) {
    unsigned char *base = (unsigned char *)(g_scaledInit_00542044 * 4);
    unsigned int v;
    *(unsigned int *)(base + 4) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 8) = g_eventQueueCurrent;
    v = g_eventQueueWorkType;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(base + 0x0c) = v;
}
