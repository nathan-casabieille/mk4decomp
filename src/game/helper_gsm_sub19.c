/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * MenuFlagBitDispatchSearch_b8730_004b8730 - 255b sister of 0x004b8630, different menu (4f5018 table).
 *   Uses (g_byte_00ab4300, g_dispatchSave1489_00ab4320, g_dispatchSave1495_00ab4368) instead of (00ab42d4, 00ab41a0, 00ab4364).
 *   Pushed table addresses are 0x004f5018 / 0x004f501c.
 */
extern unsigned int g_byte_00ab4300;
extern unsigned int g_gsmVar3_004f5018;
extern unsigned int g_dispatchSave867_004f501c;
extern unsigned int g_dispatchSave1489_00ab4320;
extern unsigned int g_dispatchSave1495_00ab4368;
extern void DrawMenu(void);
extern void MenuInputPoll_004b7020(void);
extern void TableSearchAsc_004b6300(void);
extern void TableSearchDesc_004b62c0(void);

__declspec(naked) void Helper_GSM_Sub19(void)
{
    __asm
    {
        mov     al, byte ptr [g_byte_00ab4300]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_b73_skipSet
        mov     bl, al
        push    offset g_gsmVar3_004f5018
        or      bl, 1
        push    0
        mov     byte ptr [g_byte_00ab4300], bl
        call    TableSearchAsc_004b6300
        add     esp, 8
        mov     dword ptr [g_dispatchSave1489_00ab4320], eax
        jmp     short L_b73_afterFirst
    L_b73_skipSet:
        mov     eax, dword ptr [g_dispatchSave1489_00ab4320]
    L_b73_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1495_00ab4368]
        sub     ecx, 0
        je      L_b73_case0
        sub     ecx, 2
        je      short L_b73_case2
        sub     ecx, 0x43
        jne     L_b73_drawMenu
        mov     dword ptr [g_dispatchSave1495_00ab4368], 0
        jmp     L_b73_drawMenu
    L_b73_case2:
        push    1
        call    MenuInputPoll_004b7020
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_b73_skipDesc
        test    bl, 1
        je      short L_b73_skipDesc
        mov     eax, dword ptr [g_dispatchSave1489_00ab4320]
        push    offset g_gsmVar3_004f5018
        push    eax
        call    TableSearchDesc_004b62c0
        add     esp, 8
        mov     dword ptr [g_dispatchSave1489_00ab4320], eax
        jmp     short L_b73_checkBit2
    L_b73_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1489_00ab4320]
    L_b73_checkBit2:
        test    esi, esi
        jne     short L_b73_drawMenu
        test    bl, 2
        je      short L_b73_checkBit4
        push    offset g_gsmVar3_004f5018
        push    eax
        call    TableSearchAsc_004b6300
        add     esp, 8
        mov     dword ptr [g_dispatchSave1489_00ab4320], eax
    L_b73_checkBit4:
        test    esi, esi
        jne     short L_b73_drawMenu
        test    bl, 0x10
        je      short L_b73_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave867_004f501c]
        mov     dword ptr [g_dispatchSave1495_00ab4368], ecx
    L_b73_checkBit5:
        test    esi, esi
        jne     short L_b73_drawMenu
        test    bl, 0x20
        je      short L_b73_drawMenu
        mov     dword ptr [g_dispatchSave1495_00ab4368], 0x45
        jmp     short L_b73_drawMenu
    L_b73_case0:
        mov     dword ptr [g_dispatchSave1495_00ab4368], 2
    L_b73_drawMenu:
        push    eax
        push    offset g_gsmVar3_004f5018
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1495_00ab4368]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}

