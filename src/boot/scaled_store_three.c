/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00409260 (32b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     ecx, [g_walkCallback]
 *   shl     eax, 2
 *   mov     [eax + 4], ecx
 *   xor     ecx, ecx
 *   mov     [eax + 8], ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x0c], ecx
 *   ret
 */
void ScaledStoreThree_00409260(void) {
    unsigned int *base = (unsigned int *)(g_xformEntityIdx * 4);
    base[1] = (unsigned int)g_walkCallback;
    base[2] = 0;
    g_walkCallback = (void (*)(void))0;
    base[3] = 0;
}
