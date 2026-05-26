/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_gsmSubOther1Base_004f4f60;
extern unsigned int g_dispatchSave572_004f4f64;
extern unsigned int g_dispatchSave1482_00ab42d8;
extern unsigned int g_dispatchSave1485_00ab42f8;
extern unsigned int g_dispatchSave1499_00ab4384;
extern void DrawMenu(void);
extern void Helper_GSM_PlayMusic(void);
extern void Menu_PollNavInput(void);
extern void Menu_FindNextSelectable(void);
extern void Menu_FindPrevSelectable(void);

__declspec(naked) void Menu_ColorDepthErrorDialog(void)
{
    __asm {
        mov      al, byte ptr [g_dispatchSave1482_00ab42d8]
        push     ebx
        push     esi
        push     edi
        test     al, 1
        jne      short L_8bfb
        mov      bl, al
        push     OFFSET g_gsmSubOther1Base_004f4f60
        or       bl, 1
        push     0
        mov      byte ptr [g_dispatchSave1482_00ab42d8], bl
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1485_00ab42f8], eax
    L_8bfb:
        mov      eax, dword ptr [g_dispatchSave1499_00ab4384]
        sub      eax, 0
        je       L_8d31
        sub      eax, 2
        je       short L_8c26
        sub      eax, 0x43
        jne      L_8d3b
        mov      dword ptr [g_dispatchSave1499_00ab4384], 0
        jmp      L_8d3b
    L_8c26:
        push     1
        call     Menu_PollNavInput
        mov      ebx, eax
        add      esp, 4
        mov      esi, ebx
        and      esi, 0x8000
        jne      short L_8c59
        test     bl, 1
        je       short L_8c59
        mov      eax, dword ptr [g_dispatchSave1485_00ab42f8]
        push     OFFSET g_gsmSubOther1Base_004f4f60
        push     eax
        call     Menu_FindPrevSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1485_00ab42f8], eax
    L_8c59:
        test     esi, esi
        jne      short L_8c7b
        test     bl, 2
        je       short L_8c7b
        mov      ecx, dword ptr [g_dispatchSave1485_00ab42f8]
        push     OFFSET g_gsmSubOther1Base_004f4f60
        push     ecx
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1485_00ab42f8], eax
    L_8c7b:
        test     esi, esi
        mov      edi, 0x45
        jne      short L_8c8f
        test     bl, 0x20
        je       short L_8c8f
        mov      dword ptr [g_dispatchSave1499_00ab4384], edi
    L_8c8f:
        call     Renderer_GetMode
        cmp      eax, 4
        jne      short L_8ca2
        mov      eax, dword ptr [g_mode4PauseGate]
        test     eax, eax
        je       short L_8ca8
    L_8ca2:
        mov      dword ptr [g_dispatchSave1499_00ab4384], edi
    L_8ca8:
        mov      edx, dword ptr [g_dispatchSave1485_00ab42f8]
        movsx    eax, word ptr [edx*8 + g_dispatchSave572_004f4f64]
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
        mov      dword ptr [g_dispatchSave1499_00ab4384], edi
        jmp      short L_8d3b
    L_8ce0:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     2
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_dispatchSave1499_00ab4384], edi
        jmp      short L_8d3b
    L_8cfb:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     3
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_dispatchSave1499_00ab4384], edi
        jmp      short L_8d3b
    L_8d16:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     5
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_dispatchSave1499_00ab4384], edi
        jmp      short L_8d3b
    L_8d31:
        mov      dword ptr [g_dispatchSave1499_00ab4384], 2
    L_8d3b:
        mov      eax, dword ptr [g_dispatchSave1485_00ab42f8]
        push     eax
        push     OFFSET g_gsmSubOther1Base_004f4f60
        call     DrawMenu
        mov      eax, dword ptr [g_dispatchSave1499_00ab4384]
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

