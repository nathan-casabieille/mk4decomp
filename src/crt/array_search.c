/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cba90 (60b)
 *   array search: arg2 = base, edi = g_state_00522904 = entry count;
 *   linearly scan for entry whose dword == arg1; return matching slot or 0.
 */
extern unsigned int g_state_00522904;
__declspec(naked) void ArraySearch_004cba90(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     esi, dword ptr [esp + 0x0c]
        push    edi
        mov     edi, dword ptr [g_state_00522904]
        mov     ecx, dword ptr [esi]
        mov     eax, esi
        cmp     ecx, edx
        _emit   74h
        _emit   11h
        lea     ecx, [edi + edi*2]
        lea     ecx, [esi + ecx*4]
loop_top:
        add     eax, 0x0c
        cmp     eax, ecx
        _emit   73h
        _emit   04h
        cmp     dword ptr [eax], edx
        _emit   75h
        _emit   0f5h
        lea     ecx, [edi + edi*2]
        lea     ecx, [esi + ecx*4]
        cmp     eax, ecx
        _emit   73h
        _emit   04h
        cmp     dword ptr [eax], edx
        _emit   74h
        _emit   02h
        xor     eax, eax
        pop     edi
        pop     esi
        ret
    }
}
