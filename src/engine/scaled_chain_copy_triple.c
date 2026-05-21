/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446280 (56b)
 *   mov     eax, [g_baseSel_00542060]
 *   shl     eax, 2
 *   mov     ecx, [eax + 0x5c]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     edx, [eax + 0x3c]
 *   shl     ecx, 2
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x30], edx
 *   mov     edx, [eax + 0x40]
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x34], edx
 *   mov     eax, [eax + 0x44]
 *   mov     [g_walkCallback], eax
 *   mov     [ecx + 0x38], eax
 *   ret
 */
void ScaledChainCopyTriple_00446280(void) {
    unsigned char *src;
    unsigned char *dst;
    unsigned int v;
    src = (unsigned char *)(g_baseSel_00542060 * 4);
    g_scaledInit_00542044 = *(unsigned int *)(src + 0x5c);
    dst = (unsigned char *)(g_scaledInit_00542044 * 4);
    v = *(unsigned int *)(src + 0x3c);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x30) = v;
    v = *(unsigned int *)(src + 0x40);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x34) = v;
    v = *(unsigned int *)(src + 0x44);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x38) = v;
}
