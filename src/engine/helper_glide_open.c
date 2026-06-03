/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_dispatchSave835;
extern unsigned int g_dispatchSave836;
extern unsigned int g_dispatchSave837;
extern unsigned int g_dispatchSave838;
extern unsigned int g_dispatchSave839;
extern unsigned int g_dispatchSave840;
extern unsigned int g_dispatchSave841;
extern unsigned int g_dispatchSave842;
extern unsigned int g_dispatchSave843;
extern unsigned int g_dispatchSave844;
extern unsigned int g_dispatchSave845;
extern unsigned int g_dispatchSave846;
extern unsigned int g_dispatchSave847;
extern unsigned int g_dispatchSave848;
extern unsigned int g_dispatchSave849;
extern unsigned int g_dispatchSave850;
extern unsigned int g_dispatchSave851;
extern unsigned int g_dispatchSave852;
extern unsigned int g_dispatchSave853;
extern unsigned int g_dispatchSave854;
extern unsigned int g_dispatchSave855;
extern unsigned int g_dispatchSave856;
extern unsigned int g_dispatchSave857;
extern unsigned int g_dispatchSave858;
extern unsigned int g_dispatchSave859;
extern unsigned int g_dispatchSave860;
extern unsigned int g_dispatchSave861;
extern unsigned int g_dispatchSave862;
extern unsigned int g_dispatchSave863;
extern unsigned int g_dispatchSave864;
extern unsigned int g_dispatchSave865;
extern int g_renderer1_active;
extern unsigned int g_glideFnTable;
extern unsigned int g_dispatchSave1632;
extern unsigned int g_dispatchSave1633;
extern unsigned int g_fnptr_007b000c;
extern unsigned int g_fnptr_007b0010;
extern unsigned int g_dispatchSave1634;
extern unsigned int g_dispatchSave1635;
extern unsigned int g_dispatchSave1636;
extern unsigned int g_dispatchSave1637;
extern unsigned int g_dispatchSave1638;
extern unsigned int g_dispatchSave1639;
extern unsigned int g_dispatchSave1640;
extern unsigned int g_fnptr_007b0030;
extern unsigned int g_dispatchSave1641;
extern unsigned int g_dispatchSave1642;
extern unsigned int g_PeekMessageA;
extern unsigned int g_fnptr_007b0040;
extern unsigned int g_dispatchSave1643;
extern unsigned int g_dispatchSave1644;
extern unsigned int g_dispatchSave1645;
extern unsigned int g_iat_indirect_007b0050;
extern unsigned int g_iat_indirect_007b0054;
extern unsigned int g_dispatchSave1646;
extern unsigned int g_dispatchSave1647;
extern unsigned int g_iat_indirect_007b0060;
extern unsigned int g_dispatchSave1648;
extern unsigned int g_dispatchSave1649;
extern unsigned int g_dispatchSave1650;
extern unsigned int g_dispatchSave1651;
extern unsigned int g_dispatchSave1652;
extern unsigned int g_dispatchSave1653;
extern unsigned int g_iat_LoadLibraryA;
extern unsigned int g_iat_GetProcAddress;

__declspec(naked) void Helper_GlideOpen(void)
{
    __asm {
        mov      eax, dword ptr [g_renderer1_active]
        push     esi
        test     eax, eax
        jne      L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        test     eax, eax
        jne      L_4f52
        push     OFFSET g_dispatchSave865
        call     dword ptr [g_iat_LoadLibraryA]
        test     eax, eax
        mov      dword ptr [g_glideFnTable], eax
        je       L_4f52
        mov      esi, dword ptr [g_iat_GetProcAddress]
        push     OFFSET g_dispatchSave864
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1632], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave863
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1633], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave862
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_fnptr_007b000c], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave861
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_fnptr_007b0010], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave860
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1634], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave859
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1635], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave858
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1636], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave857
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1637], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave856
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1638], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave855
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1639], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave854
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1640], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave853
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_fnptr_007b0030], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave852
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1641], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave851
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1642], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave850
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_PeekMessageA], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave849
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_fnptr_007b0040], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave848
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1643], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave847
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1644], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave846
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1645], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave845
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_indirect_007b0050], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave844
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_indirect_007b0054], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave843
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1646], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave842
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1647], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave841
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_indirect_007b0060], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave840
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1648], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave839
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1649], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave838
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1650], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave837
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1651], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave836
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1652], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave835
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1653], eax
        je       L_4f52
        mov      eax, 1
        pop      esi
        ret
    L_4f52:
        xor      eax, eax
        pop      esi
        ret
    }
}

