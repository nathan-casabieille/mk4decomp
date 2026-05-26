/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern u8 g_memHeapStart[];
extern unsigned int g_dispatchSave1654_007b41a8;
__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_memHeapStart
        rep stosd
        mov     eax, dword ptr [g_memHeapStart]
        mov     dword ptr [g_dispatchSave1654_007b41a8], OFFSET g_memHeapStart
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_memHeapStart], eax
        ret
    }
}

/* @addr 0x004b62c0 (55b)
 *   table search descending from arg-1; each entry is 8 bytes.
 *   while (eax >= 0 && tab[eax].first != 0) { if (tab[eax].second != 1) break; eax--; }
 *   complex tail computing the final index.
 */
__declspec(naked) void Menu_FindPrevSelectable(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     esi, 1
        lea     eax, [edx - 1]
        test    eax, eax
        _emit   7ch
        _emit   1ah
        mov     ecx, dword ptr [esp + 0x0c]
        lea     ecx, [ecx + eax*8]
        cmp     dword ptr [ecx], 0
        _emit   74h
        _emit   0eh
        cmp     word  ptr [ecx + 4], si
        _emit   75h
        _emit   12h
        dec     eax
        sub     ecx, 8
        test    eax, eax
        _emit   7dh
        _emit   0edh
        xor     eax, eax
        cmp     edx, esi
        setl    al
        dec     eax
        and     eax, edx
        pop     esi
        ret
    }
}
