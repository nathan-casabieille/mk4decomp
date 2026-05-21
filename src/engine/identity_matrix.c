/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00424b70 (42b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, 0x10000
 *   shl     eax, 2
 *   mov     [eax], ecx
 *   mov     [eax + 0x10], ecx
 *   mov     [eax + 0x20], ecx
 *   xor     ecx, ecx
 *   mov     [eax + 4], ecx
 *   mov     [eax + 8], ecx
 *   mov     [eax + 0x0c], ecx
 *   mov     [eax + 0x14], ecx
 *   mov     [eax + 0x18], ecx
 *   mov     [eax + 0x1c], ecx
 *   ret
 */
void IdentityMatrix_00424b70(void) {
    int *base = (int *)(g_scaledInit_00542044 * 4);
    base[0] = 0x10000;
    base[4] = 0x10000;
    base[8] = 0x10000;
    base[1] = 0;
    base[2] = 0;
    base[3] = 0;
    base[5] = 0;
    base[6] = 0;
    base[7] = 0;
}
