/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* Menu_DirectDrawUnavailableDialog - sister of 0x4b8630 for 0x004f5070 menu. */
extern unsigned int g_menuFlagsSub1b;
extern unsigned int g_gsmVar;
extern unsigned int g_dispatchSave869;
extern unsigned int g_dispatchSave1487;
extern unsigned int g_dispatchSave1497;
extern void DrawMenu(void);
extern void Menu_PollNavInput(void);
extern void Menu_FindNextSelectable(void);
extern void Menu_FindPrevSelectable(void);

__declspec(naked) void Menu_DirectDrawUnavailableDialog(void)
{
    __asm
    {
        mov     al, byte ptr [g_menuFlagsSub1b]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_b93_skipSet
        mov     bl, al
        push    offset g_gsmVar
        or      bl, 1
        push    0
        mov     byte ptr [g_menuFlagsSub1b], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1487], eax
        jmp     short L_b93_afterFirst
    L_b93_skipSet:
        mov     eax, dword ptr [g_dispatchSave1487]
    L_b93_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1497]
        sub     ecx, 0
        je      L_b93_case0
        sub     ecx, 2
        je      short L_b93_case2
        sub     ecx, 0x43
        jne     L_b93_drawMenu
        mov     dword ptr [g_dispatchSave1497], 0
        jmp     L_b93_drawMenu
    L_b93_case2:
        push    1
        call    Menu_PollNavInput
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_b93_skipDesc
        test    bl, 1
        je      short L_b93_skipDesc
        mov     eax, dword ptr [g_dispatchSave1487]
        push    offset g_gsmVar
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1487], eax
        jmp     short L_b93_checkBit2
    L_b93_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1487]
    L_b93_checkBit2:
        test    esi, esi
        jne     short L_b93_drawMenu
        test    bl, 2
        je      short L_b93_checkBit4
        push    offset g_gsmVar
        push    eax
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1487], eax
    L_b93_checkBit4:
        test    esi, esi
        jne     short L_b93_drawMenu
        test    bl, 0x10
        je      short L_b93_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave869]
        mov     dword ptr [g_dispatchSave1497], ecx
    L_b93_checkBit5:
        test    esi, esi
        jne     short L_b93_drawMenu
        test    bl, 0x20
        je      short L_b93_drawMenu
        mov     dword ptr [g_dispatchSave1497], 0x45
        jmp     short L_b93_drawMenu
    L_b93_case0:
        mov     dword ptr [g_dispatchSave1497], 2
    L_b93_drawMenu:
        push    eax
        push    offset g_gsmVar
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1497]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}

