/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c38d0 (43b)
 *   push    esi
 *   xor     ecx, ecx
 *   xor     eax, eax
 *   mov     esi, 0x00f9eb80
 * .loop:
 *   cmp     word ptr [esi], -1
 *   je      .skip
 *   mov     edx, 1
 *   shl     edx, cl
 *   jmp     .merge
 * .skip:
 *   xor     edx, edx
 * .merge:
 *   or      eax, edx
 *   add     esi, 4
 *   inc     ecx
 *   cmp     esi, 0x00f9ebc0
 *   jl      .loop
 *   pop     esi
 *   ret
 */
int BuildMaskFromArray_004c38d0(void) {
    int i = 0;
    int mask = 0;
    int p = 0x00f9eb80;
    while (p < 0x00f9ebc0) {
        mask |= (*(short *)p != -1) ? (1 << i) : 0;
        p += 4;
        i++;
    }
    return mask;
}
