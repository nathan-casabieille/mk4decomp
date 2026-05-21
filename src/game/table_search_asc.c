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
extern unsigned int g_state_007b41a0;
extern unsigned int g_state_007b41a8;
__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_state_007b41a0
        rep stosd
        mov     eax, dword ptr [g_state_007b41a0]
        mov     dword ptr [g_state_007b41a8], OFFSET g_state_007b41a0
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_state_007b41a0], eax
        ret
    }
}

/* @addr 0x004b6300 (58b)
 *   table search ascending from arg+1; clamps arg < -1 to -1; returns count
 *   of contiguous valid entries (each 8 bytes; .second must equal 1, .next != 0).
 */
__declspec(naked) void TableSearchAsc_004b6300(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        cmp     edx, 0xffffffff
        push    edi
        _emit   7dh
        _emit   03h
        or      edx, 0xffffffff
        mov     ecx, dword ptr [esp + 0x10]
        lea     eax, [edx + 1]
        mov     esi, dword ptr [ecx + eax*8]
        lea     ecx, [ecx + eax*8]
        test    esi, esi
        _emit   74h
        _emit   16h
        mov     esi, 1
        cmp     word  ptr [ecx + 4], si
        _emit   75h
        _emit   0dh
        mov     edi, dword ptr [ecx + 8]
        add     ecx, 8
        inc     eax
        test    edi, edi
        _emit   75h
        _emit   0efh
        mov     eax, edx
        pop     edi
        pop     esi
        ret
    }
}
