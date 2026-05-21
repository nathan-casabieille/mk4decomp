/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0040a870 (52b)
 *   mov     eax, [g_eventQueueEnd]
 *   mov     ecx, [g_scaledInit_00542044]
 *   shl     eax, 2
 *   shl     ecx, 2
 *   mov     edx, [eax]
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x38], edx
 *   mov     edx, [eax + 4]
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x3c], edx
 *   mov     eax, [eax + 8]
 *   mov     [g_walkCallback], eax
 *   mov     [ecx + 0x40], eax
 *   ret
 */
void Copy3Fields38_0040a870(void) {
    unsigned char *src = (unsigned char *)(g_eventQueueEnd * 4);
    unsigned char *dst = (unsigned char *)(g_scaledInit_00542044 * 4);
    unsigned int v;
    v = *(unsigned int *)(src);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x38) = v;
    v = *(unsigned int *)(src + 4);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x3c) = v;
    v = *(unsigned int *)(src + 8);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x40) = v;
}
