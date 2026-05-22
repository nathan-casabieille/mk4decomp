/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_data_004f5128;
extern unsigned int g_data_004f512c;
extern unsigned int g_data_00ab41c4;
extern unsigned int g_data_00ab42f4;
extern unsigned int g_data_00ab4360;
extern void DrawMenu(void);
extern void MenuInputPoll_004b7020(void);
extern void TableSearchAsc_004b6300(void);
extern void TableSearchDesc_004b62c0(void);

__declspec(naked) void Helper_GSM_HandleEvent(void)
{
    __asm {
        mov      al, byte ptr [g_data_00ab42f4]
        push     ebx
        test     al, 1
        push     esi
        jne      short L_84fc
        mov      bl, al
        push     OFFSET g_data_004f5128
        or       bl, 1
        push     0
        mov      byte ptr [g_data_00ab42f4], bl
        call     TableSearchAsc_004b6300
        add      esp, 8
        mov      dword ptr [g_data_00ab41c4], eax
        jmp      short L_8501
    L_84fc:
        mov      eax, dword ptr [g_data_00ab41c4]
    L_8501:
        mov      ecx, dword ptr [g_data_00ab4360]
        cmp      ecx, 0x45
        ja       L_85ba
        xor      edx, edx
        mov      dl, byte ptr [ecx + L_4d0_byidx]
        jmp      dword ptr [edx*4 + L_4d0_jmptbl]
    L_851f:
        mov      dword ptr [g_data_00ab4360], 2
        jmp      L_85ba
    L_852e:
        push     1
        call     MenuInputPoll_004b7020
        mov      ebx, eax
        add      esp, 4
        mov      esi, ebx
        and      esi, 0x8000
        jne      short L_8563
        test     bl, 1
        je       short L_8563
        mov      eax, dword ptr [g_data_00ab41c4]
        push     OFFSET g_data_004f5128
        push     eax
        call     TableSearchDesc_004b62c0
        add      esp, 8
        mov      dword ptr [g_data_00ab41c4], eax
        jmp      short L_8568
    L_8563:
        mov      eax, dword ptr [g_data_00ab41c4]
    L_8568:
        test     esi, esi
        jne      short L_85ba
        test     bl, 2
        je       short L_8584
        push     OFFSET g_data_004f5128
        push     eax
        call     TableSearchAsc_004b6300
        add      esp, 8
        mov      dword ptr [g_data_00ab41c4], eax
    L_8584:
        test     esi, esi
        jne      short L_85ba
        test     bl, 0x10
        je       short L_859b
        movsx    ecx, word ptr [eax*8 + g_data_004f512c]
        mov      dword ptr [g_data_00ab4360], ecx
    L_859b:
        test     esi, esi
        jne      short L_85ba
        test     bl, 0x20
        je       short L_85ba
        mov      dword ptr [g_data_00ab4360], 0x45
        jmp      short L_85ba
    L_85b0:
        mov      dword ptr [g_data_00ab4360], 0
    L_85ba:
        push     eax
        push     OFFSET g_data_004f5128
        call     DrawMenu
        mov      eax, dword ptr [g_data_00ab4360]
        add      esp, 8
        pop      esi
        pop      ebx
        ret
    L_4d0_jmptbl:
        _emit 0x1f
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0x2e
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0xb0
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0xb0
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0xba
        _emit 0x85
        _emit 0x4b
        _emit 0x00
    L_4d0_byidx:
        _emit 0x00
        _emit 0x04
        _emit 0x01
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x02
        _emit 0x02
        _emit 0x02
        _emit 0x02
        _emit 0x02
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x03
    }
}

