/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004c3710 (206b engine.render) - COM object slot release/dealloc by index.
 *   arg ax = obj idx. if (idx >= 0x898) ret.
 *   edi = idx * 28 (object slot stride).
 *   if (chain[idx+0xc8 base] == 0): ret.
 *   if ([0xf9eff0] == 0): scan 4 entries; if marked, bit-2 of flag byte; jmp end-set-flag.
 *   esi = &chain[idx + 0x4f8fad4]; for i in 4..1: if (slot != 0) {
 *     call slot->vtable[0x48](slot); call slot->vtable[8](slot); slot = 0;
 *   } esi -= 4.
 *   Update [0xf9efe4] -= chain[+0xd8]; [0xf9efe8]--; [0xf9efd8]++.
 *   pop edi/esi/ebx; ret.
 *   Alt path: g_flags |= 2; pop and ret.
 */
__declspec(naked) void Helper_AudioStop(void) {
    __asm {
        mov     ax, word ptr [esp + 4]
        push    ebx
        push    esi
        cmp     ax, 0x0898
        push    edi
        _emit   0fh
        _emit   83h
        _emit   0a6h
        _emit   00h
        _emit   00h
        _emit   00h
        movsx   eax, ax
        mov     edi, eax
        shl     edi, 3
        sub     edi, eax
        shl     edi, 2
        mov     eax, [edi + g_obj_table_00f8fac8]
        lea     ecx, [edi + g_obj_table_00f8fac8]
        test    eax, eax
        _emit   0fh
        _emit   84h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_x_00f9eff0]
        test    eax, eax
        _emit   75h
        _emit   25h
        xor     eax, eax
        mov     dl, 1
        cmp     dword ptr [ecx], 0
        _emit   74h
        _emit   13h
        mov     bl, byte ptr [eax + edi + g_flags_00f8fadf]
        test    bl, bl
        _emit   74h
        _emit   08h
        test    byte ptr [edi + g_flags_00f8fade], dl
        _emit   74h
        _emit   64h
        inc     eax
        add     ecx, 4
        cmp     eax, 4
        _emit   7ch
        _emit   0dfh
        lea     esi, [edi + g_obj_used_00f8fad4]
        mov     ebx, 4
        mov     eax, [esi]
        test    eax, eax
        _emit   74h
        _emit   14h
        mov     ecx, [eax]
        push    eax
        call    dword ptr [ecx + 0x48]
        mov     eax, [esi]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 8]
        mov     dword ptr [esi], 0
        sub     esi, 4
        dec     ebx
        _emit   75h
        _emit   0e0h
        mov     eax, [edi + g_obj_size_00f8fad8]
        mov     edx, dword ptr [g_x_00f9efe4]
        mov     ecx, dword ptr [g_x_00f9efe8]
        sub     edx, eax
        mov     eax, dword ptr [g_x_00f9efd8]
        dec     ecx
        inc     eax
        mov     dword ptr [g_x_00f9efe4], edx
        mov     dword ptr [g_x_00f9efe8], ecx
        mov     dword ptr [g_x_00f9efd8], eax
        pop     edi
        pop     esi
        pop     ebx
        ret
        mov     al, byte ptr [edi + g_flags_00f8fade]
        or      al, 2
        mov     byte ptr [edi + g_flags_00f8fade], al
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}

