/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c45a0 (37b)
 *   push    esi
 *   mov     esi, [iat]
 *   push    edi
 *   push    0x2d
 *   call    esi
 *   push    7
 *   mov     edi, eax
 *   call    esi
 *   add     edi, eax
 *   shl     edi, 1
 *   mov     [0x00f9f7b8], edi
 *   pop     edi
 *   pop     esi
 *   ret
 *   nop
 *   jmp     +0x0b
 */
extern unsigned int g_state_00f9f7b8;
extern void func_004c45c1(void);
extern unsigned int g_iat_004d21b0;

/*
 * NON-COAXABLE: MSVC picks lea eax,[edi+edi]+pop edi+a3 store over
 * the orig shl edi,1+mov [g],edi; scheduler frees edi early for a3 -
 * same byte count, different encoding, not controllable from C source.
 */
__declspec(naked) void CallTwoSumShl_004c45a0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [g_iat_004d21b0]
        push    edi
        push    0x2d
        call    esi
        push    7
        mov     edi, eax
        call    esi
        add     edi, eax
        shl     edi, 1
        mov     dword ptr [g_state_00f9f7b8], edi
        pop     edi
        pop     esi
        ret
    }
}
