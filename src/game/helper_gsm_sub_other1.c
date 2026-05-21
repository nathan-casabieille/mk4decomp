/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

__declspec(naked) void Helper_GSM_Sub_Other1(void)
{
    __asm {
        mov      al, byte ptr [g_data_00ab42d8]
        push     ebx
        push     esi
        push     edi
        test     al, 1
        jne      short L_8bfb
        mov      bl, al
        push     OFFSET g_data_004f4f60
        or       bl, 1
        push     0
        mov      byte ptr [g_data_00ab42d8], bl
        call     TableSearchAsc_004b6300
        add      esp, 8
        mov      dword ptr [g_data_00ab42f8], eax
    L_8bfb:
        mov      eax, dword ptr [g_data_00ab4384]
        sub      eax, 0
        je       L_8d31
        sub      eax, 2
        je       short L_8c26
        sub      eax, 0x43
        jne      L_8d3b
        mov      dword ptr [g_data_00ab4384], 0
        jmp      L_8d3b
    L_8c26:
        push     1
        call     MenuInputPoll_004b7020
        mov      ebx, eax
        add      esp, 4
        mov      esi, ebx
        and      esi, 0x8000
        jne      short L_8c59
        test     bl, 1
        je       short L_8c59
        mov      eax, dword ptr [g_data_00ab42f8]
        push     OFFSET g_data_004f4f60
        push     eax
        call     TableSearchDesc_004b62c0
        add      esp, 8
        mov      dword ptr [g_data_00ab42f8], eax
    L_8c59:
        test     esi, esi
        jne      short L_8c7b
        test     bl, 2
        je       short L_8c7b
        mov      ecx, dword ptr [g_data_00ab42f8]
        push     OFFSET g_data_004f4f60
        push     ecx
        call     TableSearchAsc_004b6300
        add      esp, 8
        mov      dword ptr [g_data_00ab42f8], eax
    L_8c7b:
        test     esi, esi
        mov      edi, 0x45
        jne      short L_8c8f
        test     bl, 0x20
        je       short L_8c8f
        mov      dword ptr [g_data_00ab4384], edi
    L_8c8f:
        call     Renderer_GetMode
        cmp      eax, 4
        jne      short L_8ca2
        mov      eax, dword ptr [g_data_004ffd78]
        test     eax, eax
        je       short L_8ca8
    L_8ca2:
        mov      dword ptr [g_data_00ab4384], edi
    L_8ca8:
        mov      edx, dword ptr [g_data_00ab42f8]
        movsx    eax, word ptr [edx*8 + g_data_004f4f64]
        add      eax, -0xd
        cmp      eax, 3
        ja       short L_8d3b
        jmp      dword ptr [eax*4 + L_bd0_jmptbl]
    L_8cc5:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     1
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_data_00ab4384], edi
        jmp      short L_8d3b
    L_8ce0:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     2
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_data_00ab4384], edi
        jmp      short L_8d3b
    L_8cfb:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     3
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_data_00ab4384], edi
        jmp      short L_8d3b
    L_8d16:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     5
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_data_00ab4384], edi
        jmp      short L_8d3b
    L_8d31:
        mov      dword ptr [g_data_00ab4384], 2
    L_8d3b:
        mov      eax, dword ptr [g_data_00ab42f8]
        push     eax
        push     OFFSET g_data_004f4f60
        call     DrawMenu
        mov      eax, dword ptr [g_data_00ab4384]
        add      esp, 8
        pop      edi
        pop      esi
        pop      ebx
        ret
        nop
    L_bd0_jmptbl:
        _emit    0xc5
        _emit    0x8c
        _emit    0x4b
        _emit    0x00
        _emit    0xe0
        _emit    0x8c
        _emit    0x4b
        _emit    0x00
        _emit    0xfb
        _emit    0x8c
        _emit    0x4b
        _emit    0x00
        _emit    0x16
        _emit    0x8d
        _emit    0x4b
        _emit    0x00
    }
}

