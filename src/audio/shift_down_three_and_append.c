/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004aa3f0 (32b)
 *   mov     edx, [esp+4]
 *   push    esi
 *   mov     eax, edx
 *   mov     ecx, 3
 *   mov     esi, [eax + 4]
 *   mov     [eax], esi
 *   add     eax, 4
 *   dec     ecx
 *   jne     -10
 *   mov     eax, [esp+0x0c]
 *   pop     esi
 *   mov     [edx + 0x0c], eax
 *   ret
 */
__declspec(naked) void ShiftDownThreeAndAppend_004aa3f0(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     eax, edx
        mov     ecx, 3
        mov     esi, dword ptr [eax + 4]
        mov     dword ptr [eax], esi
        add     eax, 4
        dec     ecx
        _emit   75h
        _emit   0f5h
        mov     eax, dword ptr [esp + 0x0c]
        pop     esi
        mov     dword ptr [edx + 0x0c], eax
        ret
    }
}
