/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b21d0 (272b engine.app) - per-char glyph emitter for HUD text.
 *   args: (esp+8)=screen_x, (esp+0xc)=string ptr, (esp+0x10)=screen_y, (esp+0x14) bp=z, (esp+0x18) sign_flag.
 *   For each printable char (0x21..0x7e): index = c - 0x21; sprite cell pos = (idx % 28, idx / 28).
 *   Builds quad descriptor at g_data_007af4e8..g_data_007af508, calls Helper_DrawCursor.
 *   Advances screen_x by 9 per char; clears g_data_007af508 at end.
 */
__declspec(naked) void Helper_DrawMenuText(void) {
    __asm {
        mov     eax, [esp + 0xc]
        push    esi
        mov     cl, [eax]
        test    cl, cl
        jz      L_hpc_emptyTail
        mov     esi, [esp + 8]
        push    edi
        mov     edi, [esp + 0x10]
        push    ebp
        mov     bp, word ptr [esp + 0x20]
        push    ebx
    L_hpc_loop:
        cmp     cl, 0x21
        jl      short L_hpc_zero
        cmp     cl, 0x7e
        jg      short L_hpc_zero
        sub     ecx, 0x21
        and     ecx, 0xff
        jmp     short L_hpc_check
    L_hpc_zero:
        xor     ecx, ecx
    L_hpc_check:
        test    ecx, ecx
        jz      L_hpc_advance
        lea     edx, [esi + 9]
        lea     eax, [edi + 0xa]
        mov     word ptr [g_data_007af4f0], dx
        mov     word ptr [g_data_007af4f2], ax
        mov     eax, ecx
        xor     edx, edx
        mov     ebx, 0x1c
        push    offset g_data_007af4e8
        div     ebx
        mov     word ptr [g_data_007af4e8], si
        mov     word ptr [g_data_007af4ea], di
        mov     word ptr [g_data_007af4fa], 0
        mov     word ptr [g_data_007af4fc], bp
        mov     al, dl
        mov     dl, 9
        imul    dl
        mov     bl, al
        mov     eax, 0x24924925
        mul     ecx
        mov     eax, ecx
        mov     cl, 0x0a
        sub     eax, edx
        mov     byte ptr [g_data_007af4f4], bl
        shr     eax, 1
        add     eax, edx
        add     bl, 9
        shr     eax, 4
        imul    cl
        mov     byte ptr [g_data_007af4f5], al
        add     al, cl
        mov     byte ptr [g_data_007af4f9], al
        mov     al, [esp + 0x24]
        neg     al
        sbb     eax, eax
        mov     byte ptr [g_data_007af4f8], bl
        and     eax, 3
        and     eax, 3
        shl     eax, 7
        or      al, 0x0f
        or      ah, 2
        or      al, 0x20
        mov     word ptr [g_data_007af502], ax
        call    Helper_DrawCursor
        add     esp, 4
    L_hpc_advance:
        mov     eax, [esp + 0x1c]
        add     esi, 9
        inc     eax
        mov     [esp + 0x1c], eax
        mov     cl, [eax]
        test    cl, cl
        jne     L_hpc_loop
        pop     ebx
        pop     ebp
        pop     edi
        mov     byte ptr [g_data_007af508], cl
        mov     eax, esi
        pop     esi
        ret
    L_hpc_emptyTail:
        mov     esi, [esp + 8]
        mov     byte ptr [g_data_007af508], 0
        mov     eax, esi
        pop     esi
        ret
    }
}

