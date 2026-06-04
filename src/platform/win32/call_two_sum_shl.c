/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern s32 g_clientWidth;
extern void CallThreeSumLea(void);
extern unsigned int g_iat_GetSystemMetrics;

/*
 * NON-COAXABLE: MSVC picks lea eax,[edi+edi]+pop edi+a3 store over
 * the orig shl edi,1+mov [g],edi; scheduler frees edi early for a3 -
 * same byte count, different encoding, not controllable from C source.
 */
__declspec(naked) void CallTwoSumShl(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [g_iat_GetSystemMetrics]
        push    edi
        push    0x2d
        call    esi
        push    7
        mov     edi, eax
        call    esi
        add     edi, eax
        shl     edi, 1
        mov     dword ptr [g_clientWidth], edi
        pop     edi
        pop     esi
        ret
    }
}
