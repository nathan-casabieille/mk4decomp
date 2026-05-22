/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_data_004ffd4c;
extern unsigned int g_data_00f4d028;
extern unsigned int g_data_00f6e058;
extern unsigned int g_data_00f6e05c;
extern unsigned int g_data_00f6e060;
extern unsigned int g_data_00f6e064;
extern unsigned int g_data_00f85b34;

__declspec(naked) void Helper_PaletteInit(void)
{
    __asm {
        mov     eax, 0x01010101
        sub     esp, 0xD4
        mov     dword ptr [g_data_00f6e058], eax
        mov     dword ptr [g_data_00f6e05c], eax
        push    esi
        mov     esi, dword ptr [esp + 0xDC]
        mov     dword ptr [g_data_00f6e060], eax
        mov     dword ptr [g_data_00f6e064], eax
        mov     eax, dword ptr [g_data_004ffd4c]
        cmp     esi, eax
        je      L_ptb_eq_skip
        push    edi
        push    ebp
        test    esi, esi
        push    ebx
        je      L_ptb_5bit
        xor     ecx, ecx
    L_ptb_6bit_loop:
        mov     edx, dword ptr [g_data_00f85b34]
        add     ecx, 2
        mov     ax, word ptr [edx + ecx - 2]
        mov     edi, eax
        and     eax, 0x3F
        and     edi, 0xFFE0
        shl     edi, 1
        or      edi, eax
        cmp     ecx, 0x00200000
        mov     word ptr [edx + ecx - 2], di
        jl      L_ptb_6bit_loop
        xor     edi, edi
        mov     ebx, 1
        mov     dword ptr [esp + 0x10], edi
        mov     dword ptr [esp + 0x14], ebx
        jmp     L_ptb_after_recode
    L_ptb_5bit:
        xor     ecx, ecx
    L_ptb_5bit_loop:
        mov     edx, dword ptr [g_data_00f85b34]
        add     ecx, 2
        mov     ax, word ptr [edx + ecx - 2]
        mov     edi, eax
        and     eax, 0x1F
        shr     edi, 1
        and     edi, 0x7FE0
        or      edi, eax
        cmp     ecx, 0x00200000
        mov     word ptr [edx + ecx - 2], di
        jl      L_ptb_5bit_loop
        xor     edi, edi
        mov     ebx, 1
        mov     dword ptr [esp + 0x10], edi
        mov     dword ptr [esp + 0x14], ebx
        jmp     L_ptb_after_recode
    L_ptb_outer_reload:
        mov     esi, dword ptr [esp + 0xE8]
    L_ptb_after_recode:
        xor     eax, eax
        lea     ecx, [esp + 0x24]
        mov     edx, 0x20
    L_ptb_idx20_loop:
        mov     ebp, eax
        add     eax, ebx
        sar     ebp, 4
        and     ebp, 0x1F
        mov     word ptr [ecx], bp
        add     ecx, 2
        dec     edx
        jne     L_ptb_idx20_loop
        xor     eax, eax
        lea     ecx, [esp + 0x64]
        mov     edx, 0x40
    L_ptb_idx40_loop:
        mov     ebp, eax
        add     eax, ebx
        sar     ebp, 4
        and     ebp, 0x3F
        mov     word ptr [ecx], bp
        add     ecx, 2
        dec     edx
        jne     L_ptb_idx40_loop
        mov     eax, esi
        xor     ecx, ecx
        neg     eax
        sbb     eax, eax
        lea     esi, [esp + 0x24]
        and     eax, 0x20
        mov     dword ptr [esp + 0x18], 0x20
        add     eax, 0x20
        mov     dword ptr [esp + 0x20], eax
    L_ptb_outer_check:
        xor     edx, edx
        test    eax, eax
        jle     L_ptb_after_inner_pair
    L_ptb_iter_setup:
        lea     eax, [esp + 0x24]
        mov     dword ptr [esp + 0x1C], 0x20
        jmp     L_ptb_inner_top
    L_ptb_inner_reload_edi:
        mov     edi, dword ptr [esp + 0x10]
    L_ptb_inner_top:
        mov     ebx, dword ptr [esp + 0xE8]
        test    ebx, ebx
        mov     bx, word ptr [esi]
        je      L_ptb_inner_use_24
        mov     bp, word ptr [esp + edx*2 + 0x64]
        shl     bx, 6
        jmp     L_ptb_inner_combine
    L_ptb_inner_use_24:
        mov     bp, word ptr [esp + edx*2 + 0x24]
        shl     bx, 5
    L_ptb_inner_combine:
        add     bp, bx
        mov     ebx, dword ptr [g_data_00f4d028]
        shl     ebp, 5
        add     bp, word ptr [eax]
        add     edi, ecx
        add     eax, 2
        inc     ecx
        mov     word ptr [ebx + edi*2], bp
        mov     edi, dword ptr [esp + 0x1C]
        dec     edi
        mov     dword ptr [esp + 0x1C], edi
        jne     L_ptb_inner_reload_edi
        mov     eax, dword ptr [esp + 0x20]
        mov     edi, dword ptr [esp + 0x10]
        inc     edx
        cmp     edx, eax
        jl      L_ptb_iter_setup
        mov     ebx, dword ptr [esp + 0x14]
    L_ptb_after_inner_pair:
        mov     edx, dword ptr [esp + 0x18]
        add     esi, 2
        dec     edx
        mov     dword ptr [esp + 0x18], edx
        jne     L_ptb_outer_check
        inc     ebx
        add     edi, 0x10000
        mov     dword ptr [esp + 0x14], ebx
        mov     dword ptr [esp + 0x10], edi
        lea     ecx, [ebx - 1]
        cmp     ecx, 0x10
        jl      L_ptb_outer_reload
        mov     edx, dword ptr [esp + 0xE8]
        pop     ebx
        pop     ebp
        mov     dword ptr [g_data_004ffd4c], edx
        pop     edi
    L_ptb_eq_skip:
        pop     esi
        add     esp, 0xD4
        ret
    }
}

