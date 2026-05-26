/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_gsmHelperBase_004f4f30;
extern unsigned int g_dispatchSave573_004f4f34;
extern u32 g_gsmOut4;
extern unsigned int g_dispatchSave1480_00ab42cc;
extern unsigned int g_dispatchSave1483_00ab42dc;
extern u32 g_gsmDirty1;
extern u32 g_gsmDirty2;
extern u32 g_gsmDirty3;
extern unsigned int g_dispatchSave1498_00ab4380;
extern void DrawMenu(void);
extern void Menu_PollNavInput(void);
extern void TableSearchAsc_004b6300(void);
extern void TableSearchDesc_004b62c0(void);

__declspec(naked) void Helper_GSM_Sub1C(void)
{
    __asm {
        mov      al, byte ptr [g_dispatchSave1480_00ab42cc]
        push     ebx
        test     al, 1
        push     esi
        jne      short L_8a5c
        mov      bl, al
        push     OFFSET g_gsmHelperBase_004f4f30
        or       bl, 1
        push     0
        mov      byte ptr [g_dispatchSave1480_00ab42cc], bl
        call     TableSearchAsc_004b6300
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483_00ab42dc], eax
        jmp      short L_8a61
    L_8a5c:
        mov      eax, dword ptr [g_dispatchSave1483_00ab42dc]
    L_8a61:
        mov      ecx, dword ptr [g_dispatchSave1498_00ab4380]
        sub      ecx, 0
        je       L_8b84
        sub      ecx, 2
        je       short L_8a8d
        sub      ecx, 0x43
        jne      L_8ba2
        mov      dword ptr [g_dispatchSave1498_00ab4380], 0
        jmp      L_8ba2
    L_8a8d:
        push     1
        call     Menu_PollNavInput
        mov      ebx, eax
        add      esp, 4
        mov      esi, ebx
        and      esi, 0x8000
        jne      short L_8ac2
        test     bl, 1
        je       short L_8ac2
        mov      eax, dword ptr [g_dispatchSave1483_00ab42dc]
        push     OFFSET g_gsmHelperBase_004f4f30
        push     eax
        call     TableSearchDesc_004b62c0
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483_00ab42dc], eax
        jmp      short L_8ac7
    L_8ac2:
        mov      eax, dword ptr [g_dispatchSave1483_00ab42dc]
    L_8ac7:
        test     esi, esi
        jne      short L_8ae3
        test     bl, 2
        je       short L_8ae3
        push     OFFSET g_gsmHelperBase_004f4f30
        push     eax
        call     TableSearchAsc_004b6300
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483_00ab42dc], eax
    L_8ae3:
        test     esi, esi
        mov      edx, 0x45
        jne      short L_8af7
        test     bl, 0x20
        je       short L_8af7
        mov      dword ptr [g_dispatchSave1498_00ab4380], edx
    L_8af7:
        mov      ecx, dword ptr [g_gsmOut4]
        test     ecx, ecx
        jne      short L_8b07
        mov      dword ptr [g_dispatchSave1498_00ab4380], edx
    L_8b07:
        movsx    ecx, word ptr [eax*8 + g_dispatchSave573_004f4f34]
        add      ecx, -0x14
        cmp      ecx, 3
        ja       L_8ba2
        jmp      dword ptr [ecx*4 + L_a30_jmptbl]
    L_8b22:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498_00ab4380], edx
        mov      dword ptr [g_gsmDirty1], 1
        jmp      short L_8ba2
    L_8b3d:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498_00ab4380], edx
        mov      dword ptr [g_gsmDirty2], 1
        jmp      short L_8ba2
    L_8b58:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498_00ab4380], edx
        mov      dword ptr [g_gsmDirty3], 1
        jmp      short L_8ba2
    L_8b73:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498_00ab4380], edx
        jmp      short L_8ba2
    L_8b84:
        push     OFFSET g_gsmHelperBase_004f4f30
        push     0
        mov      dword ptr [g_dispatchSave1498_00ab4380], 2
        call     TableSearchAsc_004b6300
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483_00ab42dc], eax
    L_8ba2:
        push     eax
        push     OFFSET g_gsmHelperBase_004f4f30
        call     DrawMenu
        mov      eax, dword ptr [g_dispatchSave1498_00ab4380]
        add      esp, 8
        pop      esi
        pop      ebx
        ret
    L_a30_jmptbl:
        _emit    0x73
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
        _emit    0x22
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
        _emit    0x3d
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
        _emit    0x58
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
    }
}

