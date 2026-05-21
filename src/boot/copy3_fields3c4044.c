/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404e90 (54b)
 *   mov     ecx, [g_pendingNodeType]
 *   mov     eax, [g_fightGroupHead]
 *   shl     ecx, 2
 *   shl     eax, 2
 *   mov     edx, [ecx + 0x3c]
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x54], edx
 *   mov     edx, [ecx + 0x40]
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x58], edx
 *   mov     ecx, [ecx + 0x44]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x5c], ecx
 *   ret
 */
extern u32 g_pendingNodeType;
void Copy3Fields3c4044_00404e90(void) {
    unsigned char *dst = (unsigned char *)(g_fightGroupHead * 4);
    unsigned char *src = (unsigned char *)(g_pendingNodeType * 4);
    unsigned int v;
    v = *(unsigned int *)(src + 0x3c);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x54) = v;
    v = *(unsigned int *)(src + 0x40);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x58) = v;
    v = *(unsigned int *)(src + 0x44);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x5c) = v;
}
