/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * MenuFlagBitDispatchSearch_b8730_004b8730 - 255b sister of 0x004b8630, different menu (4f5018 table).
 *   Uses (g_menuFlags4f5018, g_dispatchSave1489, g_dispatchSave1495) instead of (00ab42d4, 00ab41a0, 00ab4364).
 *   Pushed table addresses are 0x004f5018 / 0x004f501c.
 */
extern unsigned int g_menuFlags4f5018;
extern unsigned int g_gsmVar3;
extern unsigned int g_dispatchSave867;
extern unsigned int g_dispatchSave1489;
extern unsigned int g_dispatchSave1495;
extern void DrawMenu(void);
extern void Menu_PollNavInput(void);
extern void Menu_FindNextSelectable(void);
extern void Menu_FindPrevSelectable(void);

__declspec(naked) void Menu_GlideUnavailableDialog(void)
{
    __asm
    {
        mov     al, byte ptr [g_menuFlags4f5018]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_b73_skipSet
        mov     bl, al
        push    offset g_gsmVar3
        or      bl, 1
        push    0
        mov     byte ptr [g_menuFlags4f5018], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1489], eax
        jmp     short L_b73_afterFirst
    L_b73_skipSet:
        mov     eax, dword ptr [g_dispatchSave1489]
    L_b73_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1495]
        sub     ecx, 0
        je      L_b73_case0
        sub     ecx, 2
        je      short L_b73_case2
        sub     ecx, 0x43
        jne     L_b73_drawMenu
        mov     dword ptr [g_dispatchSave1495], 0
        jmp     L_b73_drawMenu
    L_b73_case2:
        push    1
        call    Menu_PollNavInput
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_b73_skipDesc
        test    bl, 1
        je      short L_b73_skipDesc
        mov     eax, dword ptr [g_dispatchSave1489]
        push    offset g_gsmVar3
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1489], eax
        jmp     short L_b73_checkBit2
    L_b73_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1489]
    L_b73_checkBit2:
        test    esi, esi
        jne     short L_b73_drawMenu
        test    bl, 2
        je      short L_b73_checkBit4
        push    offset g_gsmVar3
        push    eax
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1489], eax
    L_b73_checkBit4:
        test    esi, esi
        jne     short L_b73_drawMenu
        test    bl, 0x10
        je      short L_b73_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave867]
        mov     dword ptr [g_dispatchSave1495], ecx
    L_b73_checkBit5:
        test    esi, esi
        jne     short L_b73_drawMenu
        test    bl, 0x20
        je      short L_b73_drawMenu
        mov     dword ptr [g_dispatchSave1495], 0x45
        jmp     short L_b73_drawMenu
    L_b73_case0:
        mov     dword ptr [g_dispatchSave1495], 2
    L_b73_drawMenu:
        push    eax
        push    offset g_gsmVar3
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1495]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}

