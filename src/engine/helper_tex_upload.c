/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004bf370 (237b engine.scenegraph) - sprite-blit dispatcher.
 *   arg0 = sprite_id (esp+4); ecx = id & 0xf. Mark g_table_00f6e058[id]=1.
 *   If g_data_004ffd4c != 0: per-row bit-encoded blit:
 *     For each of [esp+0x20] rows × outer count [esp+0x24]:
 *       read u16 from [0xf4d050 + offset], split bits (lo6 + hi shifted), or together,
 *       write to [0xf85b34 + offset]. Step both by 0x200 between rows.
 *   Else: bulk rep movsd/movsb copy [0xf4d050] → [0xf85b34], rows of 0x200 bytes.
 */
__declspec(naked) void Helper_TexUpload(void) {
    __asm {
        mov     ecx, [esp + 4]
        mov     eax, dword ptr [g_data_004ffd4c]
        and     ecx, 0x0f
        push    ebx
        push    ebp
        push    esi
        mov     byte ptr [ecx + 0x00f6e058], 1
        push    edi
        shl     ecx, 16
        test    eax, eax
        jz      short L_sb_bulk
        mov     eax, [esp + 0x24]
        test    eax, eax
        jle     L_sb_done
        mov     edi, [esp + 0x1c]
        mov     esi, [esp + 0x18]
        shl     edi, 8
        add     edi, esi
        mov     esi, [esp + 0x20]
        add     edi, ecx
        mov     ebx, 0x00f4d050
        shl     edi, 1
        mov     [esp + 0x24], eax
    L_sb_outer:
        test    esi, esi
        jle     short L_sb_skipRow
        mov     edx, edi
        mov     ecx, ebx
    L_sb_inner:
        mov     ax, word ptr [ecx]
        add     ecx, 2
        mov     ebp, eax
        and     eax, 0x3f
        and     ebp, 0xffe0
        add     edx, 2
        shl     ebp, 1
        or      ebp, eax
        mov     eax, dword ptr [g_data_00f85b34]
        dec     esi
        mov     word ptr [eax + edx - 2], bp
        jne     short L_sb_inner
        mov     esi, [esp + 0x20]
    L_sb_skipRow:
        mov     eax, [esp + 0x24]
        add     edi, 0x200
        add     ebx, 0x200
        dec     eax
        mov     [esp + 0x24], eax
        jne     short L_sb_outer
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_sb_bulk:
        mov     ebx, [esp + 0x24]
        test    ebx, ebx
        jle     short L_sb_done
        mov     edx, [esp + 0x20]
        mov     edi, [esp + 0x18]
        lea     eax, [edx + edx]
        mov     edx, 0x00f4d050
        mov     [esp + 0x20], eax
        mov     eax, [esp + 0x1c]
        shl     eax, 8
        add     eax, edi
        add     eax, ecx
        shl     eax, 1
    L_sb_bulkRow:
        mov     ecx, [esp + 0x20]
        mov     edi, dword ptr [g_data_00f85b34]
        mov     ebp, ecx
        mov     esi, edx
        add     edi, eax
        add     eax, 0x200
        shr     ecx, 2
        rep     movsd
        mov     ecx, ebp
        add     edx, 0x200
        and     ecx, 3
        dec     ebx
        rep     movsb
        jne     short L_sb_bulkRow
    L_sb_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}

