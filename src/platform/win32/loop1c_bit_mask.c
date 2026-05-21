/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c4450 (24b)
 *   mov     eax, 0x00f8fade
 * .loop:
 *   mov     cl, [eax]
 *   add     eax, 0x1c
 *   and     cl, 0xfb
 *   cmp     eax, 0x00f8eb7e
 *   jl      .loop
 *   mov     [eax-0x1c], cl
 *   ret
 *
 * Wait, the cmp+jl should be at the end. Let me re-decode:
 * b8 de fa f8 00     mov eax, 0x00f8fade
 * 8a 08              mov cl, [eax]
 * 83 c0 1c           add eax, 0x1c
 * 80 e1 fb           and cl, 0xfb
 * 3d 7e eb f9 00     cmp eax, 0x00f9eb7e
 * 88 48 e4           mov [eax-0x1c], cl
 * 7c ee              jl .loop
 * c3                 ret
 */
void Loop1cBitMask_004c4450(void) {
    __asm {
        mov     eax, 0x00f8fade
        mov     cl, byte ptr [eax]
        add     eax, 0x1c
        and     cl, 0xfb
        cmp     eax, 0x00f9eb7e
        mov     byte ptr [eax - 0x1c], cl
        _emit   7ch
        _emit   0eeh
        }
}
