/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004ce290 (46b)
 *   96-bit shift left by 1: arg points to {dword[0], dword[1], dword[2]}
 *   shifts the whole 96-bit value left by 1, carrying the high bit between dwords.
 */
__declspec(naked) void Shl96By1_004ce290(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        push    edi
        mov     esi, dword ptr [eax]
        mov     edi, dword ptr [eax + 4]
        mov     ecx, esi
        add     esi, esi
        mov     dword ptr [eax], esi
        lea     esi, [edi + edi*1]
        shr     ecx, 0x1f
        or      esi, ecx
        mov     ecx, dword ptr [eax + 8]
        mov     edx, edi
        mov     dword ptr [eax + 4], esi
        shr     edx, 0x1f
        shl     ecx, 1
        or      ecx, edx
        pop     edi
        mov     dword ptr [eax + 8], ecx
        pop     esi
        ret
    }
}
