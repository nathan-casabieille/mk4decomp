/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004c4390 (133b platform.win32) - guarded second-init dispatch:
 *   clear g_byte_00f9efd4; if (!g_x_00f9efe0): ret;
 *   Else: clear g_x_00f9efe0; walk 16 slots; per slot if type!=0xffff and
 *   arr[type*7].slot0 != 0 and g_byte_00f9efd4 == 0:
 *   key2 = (subtype)+type*7; call arr[key2].method30(arr[type*7].byte_16 & 1, 0, 0).
 */
extern unsigned int g_arr_00f8fac8;
extern unsigned int g_arr_00f9eb80;
extern unsigned int g_byte_00f9efd4;
extern unsigned int g_x_00f9efe0;

__declspec(naked) void Helper_AudioStart(void) {
    __asm {
        mov     eax, dword ptr [g_x_00f9efe0]
        mov     byte ptr [g_byte_00f9efd4], 0
        test    eax, eax
        _emit   74h
        _emit   74h
        push    edi
        push    esi
        mov     dword ptr [g_x_00f9efe0], 0
        mov     esi, offset g_arr_00f9eb80
loop4c4390:
        mov     ax, word ptr [esi]
        cmp     ax, 0xffff
        _emit   74h
        _emit   4dh
        movsx   ecx, ax
        lea     eax, [ecx*8 + g_arr_00f8fac8]
        sub     eax, ecx
        shl     eax, 2
        mov     edx, dword ptr [eax + g_arr_00f8fac8]
        test    edx, edx
        _emit   74h
        _emit   34h
        mov     dl, byte ptr [g_byte_00f9efd4]
        test    dl, dl
        _emit   75h
        _emit   2ah
        movsx   edx, word ptr [esi + 2]
        mov     al, byte ptr [eax + g_arr_00f8fac8 + 0x16]
        lea     edi, [ecx*8 + g_arr_00f8fac8]
        sub     edi, ecx
        and     eax, 1
        add     edx, edi
        push    eax
        push    0
        push    0
        mov     ecx, [edx*4 + g_arr_00f8fac8]
        push    ecx
        mov     edx, [ecx]
        call    dword ptr [edx + 0x30]
        add     esi, 4
        cmp     esi, 0x00f9ebc0
        _emit   7ch
        _emit   9fh
        pop     esi
        pop     edi
        ret
    }
}

