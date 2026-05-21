/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004ce2c0 (45b)
 *   96-bit shift right by 1: counterpart of Shl96By1_004ce290.
 */
__declspec(naked) void Shr96By1_004ce2c0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        push    edi
        mov     edx, dword ptr [eax + 8]
        mov     ecx, dword ptr [eax + 4]
        mov     esi, edx
        mov     edi, ecx
        shl     esi, 0x1f
        shr     ecx, 1
        or      ecx, esi
        mov     dword ptr [eax + 4], ecx
        mov     ecx, dword ptr [eax]
        shl     edi, 0x1f
        shr     ecx, 1
        shr     edx, 1
        or      ecx, edi
        pop     edi
        mov     dword ptr [eax + 8], edx
        mov     dword ptr [eax], ecx
        pop     esi
        ret
    }
}
