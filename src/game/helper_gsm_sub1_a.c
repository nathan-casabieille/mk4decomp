/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* Helper_GSM_Sub1A - sister of 0x4b8630 for 0x004f5050 menu. */
extern unsigned int g_byte_00ab42ec;
extern unsigned int g_data_004f5050;
extern unsigned int g_data_004f5054;
extern unsigned int g_data_00ab4304;
extern unsigned int g_data_00ab436c;
extern void DrawMenu(void);
extern void MenuInputPoll_004b7020(void);
extern void TableSearchAsc_004b6300(void);
extern void TableSearchDesc_004b62c0(void);

__declspec(naked) void Helper_GSM_Sub1A(void)
{
    __asm
    {
        mov     al, byte ptr [g_byte_00ab42ec]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_b83_skipSet
        mov     bl, al
        push    offset g_data_004f5050
        or      bl, 1
        push    0
        mov     byte ptr [g_byte_00ab42ec], bl
        call    TableSearchAsc_004b6300
        add     esp, 8
        mov     dword ptr [g_data_00ab4304], eax
        jmp     short L_b83_afterFirst
    L_b83_skipSet:
        mov     eax, dword ptr [g_data_00ab4304]
    L_b83_afterFirst:
        mov     ecx, dword ptr [g_data_00ab436c]
        sub     ecx, 0
        je      L_b83_case0
        sub     ecx, 2
        je      short L_b83_case2
        sub     ecx, 0x43
        jne     L_b83_drawMenu
        mov     dword ptr [g_data_00ab436c], 0
        jmp     L_b83_drawMenu
    L_b83_case2:
        push    1
        call    MenuInputPoll_004b7020
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_b83_skipDesc
        test    bl, 1
        je      short L_b83_skipDesc
        mov     eax, dword ptr [g_data_00ab4304]
        push    offset g_data_004f5050
        push    eax
        call    TableSearchDesc_004b62c0
        add     esp, 8
        mov     dword ptr [g_data_00ab4304], eax
        jmp     short L_b83_checkBit2
    L_b83_skipDesc:
        mov     eax, dword ptr [g_data_00ab4304]
    L_b83_checkBit2:
        test    esi, esi
        jne     short L_b83_drawMenu
        test    bl, 2
        je      short L_b83_checkBit4
        push    offset g_data_004f5050
        push    eax
        call    TableSearchAsc_004b6300
        add     esp, 8
        mov     dword ptr [g_data_00ab4304], eax
    L_b83_checkBit4:
        test    esi, esi
        jne     short L_b83_drawMenu
        test    bl, 0x10
        je      short L_b83_checkBit5
        movsx   ecx, word ptr [eax*8 + g_data_004f5054]
        mov     dword ptr [g_data_00ab436c], ecx
    L_b83_checkBit5:
        test    esi, esi
        jne     short L_b83_drawMenu
        test    bl, 0x20
        je      short L_b83_drawMenu
        mov     dword ptr [g_data_00ab436c], 0x45
        jmp     short L_b83_drawMenu
    L_b83_case0:
        mov     dword ptr [g_data_00ab436c], 2
    L_b83_drawMenu:
        push    eax
        push    offset g_data_004f5050
        call    DrawMenu
        mov     eax, dword ptr [g_data_00ab436c]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}

