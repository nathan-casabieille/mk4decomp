/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c4420 (41b)
 *   mov     ax, word ptr [esp+4]
 *   cmp     ax, 0x0898
 *   jae     +0x1d
 *   movsx   eax, ax
 *   mov     ecx, eax
 *   shl     ecx, 3
 *   sub     ecx, eax
 *   lea     eax, [ecx*4 + 0x00f8fade]
 *   mov     cl, [ecx*4 + 0x00f8fade]
 *   or      cl, 4
 *   mov     [eax], cl
 *   ret
 */
extern unsigned int g_flags_00f8fade;
void TableSetBit_004c4420(short idx) {
    if ((unsigned short)idx < 0x0898) {
        *(unsigned char *)((&g_flags_00f8fade) + idx * 7) |= 4;
    }
}
