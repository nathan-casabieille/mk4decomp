/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

__declspec(naked) void GameStateMachineMaybeRebuild(void)
{
    __asm {
        mov     eax, dword ptr [g_data_004ffd7c]
        push    esi
        xor     esi, esi
        cmp     eax, esi
        mov     dword ptr [g_data_004d50b0], esi
        mov     dword ptr [g_data_004d50a4], esi
        mov     dword ptr [g_data_004d50a8], esi
        mov     dword ptr [g_data_004d50ac], esi
        je      L_idep_after_clear_masks
        cmp     dword ptr [g_data_007af918], esi
        jne     L_idep_after_clear_masks
        push    esi
        call    PadPollDispatcher_004b5650
        add     esp, 4
        push    1
        call    PadPollDispatcher_004b5650
        add     esp, 4
        push    esi
        call    InputBitMaskDispatcher_004b5470
        add     esp, 4
        push    1
        call    InputBitMaskDispatcher_004b5470
        mov     eax, dword ptr [g_data_004f4e98]
        add     esp, 4
        cmp     eax, esi
        je      L_idep_pause_gate2
        cmp     dword ptr [g_data_004d50b0], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_data_004d50a4], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_data_004d50a8], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_data_004d50ac], esi
        jne     L_idep_clear_loop
        push    0x1B
        call    Helper_JoyButtonInit
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x20
        call    Helper_JoyButtonInit
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x0D
        call    Helper_JoyButtonInit
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        mov     dword ptr [g_data_004f4e98], esi
    L_idep_clear_loop:
        mov     dword ptr [g_data_004d50b0], esi
        mov     dword ptr [g_data_004d50a4], esi
        mov     dword ptr [g_data_004d50a8], esi
        mov     dword ptr [g_data_004d50ac], esi
    L_idep_pause_gate2:
        cmp     dword ptr [g_data_007af920], esi
        je      L_idep_after_clear_masks
        mov     eax, dword ptr [g_data_004f4dec]
        mov     ecx, dword ptr [g_data_004f4de8]
        not     ecx
        mov     edx, dword ptr [eax]
        and     edx, ecx
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [g_data_004f4df4]
        mov     edx, dword ptr [g_data_004f4df0]
        mov     ecx, dword ptr [eax]
        not     edx
        and     ecx, edx
        mov     dword ptr [eax], ecx
    L_idep_after_clear_masks:
        mov     ecx, dword ptr [g_data_004f4dcc]
        mov     eax, dword ptr [g_data_004f4dc8]
        test    dword ptr [ecx], eax
        je      L_idep_skip1
        mov     eax, dword ptr [g_data_004f4ddc]
        mov     edx, dword ptr [g_data_004f4dd8]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip1:
        mov     ecx, dword ptr [g_data_004f4dd4]
        mov     eax, dword ptr [g_data_004f4dd0]
        test    dword ptr [ecx], eax
        je      L_idep_skip2
        mov     eax, dword ptr [g_data_004f4de4]
        mov     edx, dword ptr [g_data_004f4de0]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip2:
        mov     ecx, dword ptr [g_data_004f4dec]
        mov     eax, dword ptr [g_data_004f4de8]
        test    dword ptr [ecx], eax
        je      L_idep_skip3
        mov     eax, dword ptr [g_data_004f4dfc]
        mov     edx, dword ptr [g_data_004f4df8]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip3:
        mov     ecx, dword ptr [g_data_004f4df4]
        mov     eax, dword ptr [g_data_004f4df0]
        test    dword ptr [ecx], eax
        je      L_idep_skip4
        mov     eax, dword ptr [g_data_004f4e04]
        mov     edx, dword ptr [g_data_004f4e00]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip4:
        mov     esi, dword ptr [g_data_004d50ac]
        mov     eax, dword ptr [g_data_004d50b0]
        mov     ecx, dword ptr [g_data_004d50a4]
        mov     edx, dword ptr [g_data_004d50a8]
        not     esi
        not     eax
        not     ecx
        not     edx
        mov     dword ptr [g_data_004d50ac], esi
        mov     dword ptr [g_data_00543368], esi
        mov     dword ptr [g_data_004d50b0], eax
        mov     dword ptr [g_data_004d50a4], ecx
        mov     dword ptr [g_data_004d50a8], edx
        mov     dword ptr [g_data_0054357c], eax
        mov     dword ptr [g_data_0054336c], ecx
        mov     dword ptr [g_data_00543370], edx
        pop     esi
        ret
    }
}

