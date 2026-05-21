/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004cca00 (29b): copy 3 dwords from src to dst with stride
 *   mov     eax, [esp+8]
 *   mov     ecx, [esp+4]
 *   push    esi
 *   sub     ecx, eax
 *   mov     edx, 3
 * .loop:
 *   mov     esi, [eax]
 *   mov     [eax + ecx], esi
 *   add     eax, 4
 *   dec     edx
 *   jne     .loop
 *   pop     esi
 *   ret
 */
__declspec(naked) void Copy3Dwords_004cca00(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [esp + 4]
        push    esi
        sub     ecx, eax
        mov     edx, 3
        mov     esi, dword ptr [eax]
        mov     dword ptr [eax + ecx], esi
        add     eax, 4
        dec     edx
        _emit   75h
        _emit   0f5h
        pop     esi
        ret
    }
}
