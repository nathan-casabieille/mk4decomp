/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

__declspec(naked) void Helper_TickAlt(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_data_00542044]
        push    ebx
        push    ebp
        push    esi
        mov     eax, dword ptr [ecx*4]
        push    edi
        mov     edi, dword ptr [g_data_0054206c]
        mov     dword ptr [g_data_0054206c], eax
        mov     ebp, dword ptr [ecx*4 + 8]
        mov     ebx, eax
        test    eax, eax
        je      short L_ilw_done
    L_ilw_loop:
        lea     ecx, [ebp + eax]
        mov     dword ptr [g_data_00542044], eax
        mov     esi, dword ptr [ecx*4]
        mov     dword ptr [g_data_00542044], eax
        mov     dword ptr [g_data_0054206c], edi
        call    edi
        mov     eax, dword ptr [g_data_00541e6c]
        test    eax, eax
        jne     short L_ilw_ret
        test    byte ptr [g_data_0054208c], 1
        jne     short L_ilw_setMask
        mov     eax, esi
        mov     ebx, esi
        test    esi, esi
        mov     dword ptr [g_data_0054206c], eax
        jne     short L_ilw_loop
    L_ilw_done:
        mov     ecx, dword ptr [g_data_0054208c]
        mov     eax, 4
        or      ecx, eax
        mov     dword ptr [g_data_0054208c], ecx
        jmp     short L_ilw_finish
    L_ilw_setMask:
        mov     eax, 4
    L_ilw_finish:
        mov     edx, dword ptr [g_data_0054208c]
        mov     dword ptr [g_data_00542044], ebx
        or      edx, eax
        test    ebx, ebx
        mov     dword ptr [g_data_0054208c], edx
        je      short L_ilw_ret
        mov     ecx, edx
        xor     ecx, eax
        mov     dword ptr [g_data_0054208c], ecx
    L_ilw_ret:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_amw_entry:
        mov     eax, dword ptr [g_data_00542048]
        push    ebx
        mov     ebx, dword ptr [g_data_00543550]
        push    esi
        mov     esi, dword ptr [eax*4 + 0x14]
        mov     eax, ebx
        cdq
        push    edi
        mov     edi, dword ptr [g_data_00542058]
        sub     eax, edx
        mov     ecx, dword ptr [edi*4 + 0x64]
        mov     dword ptr [g_data_00ab4e60], ebx
        sar     eax, 1
        mov     dword ptr [g_data_00ab4e5c], eax
        lea     eax, [esi + esi*4]
        mov     dword ptr [g_data_00ab4e64], 2
        lea     edx, [eax + eax*4]
        lea     eax, [esi + edx*8]
        shl     eax, 4
        add     eax, esi
        shl     eax, 5
        sub     eax, esi
        add     ecx, eax
        mov     eax, dword ptr [edi*4 + 0x54]
        cmp     eax, 0x10000
        jl      short L_amw_negC
        add     ecx, 0x6487
        jmp     short L_amw_testNeg
    L_amw_negC:
        add     ecx, 0xc90
    L_amw_testNeg:
        test    ecx, ecx
        jge     short L_amw_wrapHigh
        mov     edx, 0x6487d
        mov     eax, 0xa2f99905
        sub     edx, ecx
        mul     edx
        shr     edx, 0x12
        lea     eax, [edx + edx*4]
        lea     eax, [eax + eax*4]
        lea     eax, [edx + eax*8]
        shl     eax, 4
        add     eax, edx
        shl     eax, 6
        sub     eax, edx
        lea     ecx, [ecx + eax*2]
    L_amw_wrapHigh:
        cmp     ecx, 0x6487e
        jl      short L_amw_check
        mov     eax, 0xa2f99905
        mul     ecx
        shr     edx, 0x12
    L_amw_unrollSub:
        sub     ecx, 0x6487e
        dec     edx
        jne     short L_amw_unrollSub
    L_amw_check:
        test    ecx, ecx
        jl      short L_amw_setNeg
        cmp     ecx, 0x330cf
        jge     short L_amw_setNeg
        mov     eax, dword ptr [g_data_00ab4db8]
        test    eax, eax
        je      short L_amw_skipCall
        call    ZeroEightFields_004b8f20
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_amw_setNeg:
        mov     dword ptr [g_data_00542044], 0xffffffff
    L_amw_skipCall:
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}

