/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
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

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 Helper_GlideOpen(void)

{
  if ((g_renderer1_active == 0) && (g_glideFnTable == (HMODULE)0x0)) {
    g_glideFnTable = LoadLibraryA(MK4_VA(char, 0x004f4db8));
    if (g_glideFnTable != (HMODULE)0x0) {
      g_dispatchSave1632 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d9c));
      if (g_dispatchSave1632 != (FARPROC)0x0) {
        g_dispatchSave1633 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d88));
        if (g_dispatchSave1633 != (FARPROC)0x0) {
          g_fnptr_007b000c = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d74));
          if (g_fnptr_007b000c != (FARPROC)0x0) {
            g_fnptr_007b0010 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d64));
            if (g_fnptr_007b0010 != (FARPROC)0x0) {
              g_dispatchSave1634 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d50));
              if (g_dispatchSave1634 != (FARPROC)0x0) {
                g_dispatchSave1635 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d3c));
                if (g_dispatchSave1635 != (FARPROC)0x0) {
                  g_dispatchSave1636 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d28));
                  if (g_dispatchSave1636 != (FARPROC)0x0) {
                    g_dispatchSave1637 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d14));
                    if (g_dispatchSave1637 != (FARPROC)0x0) {
                      g_dispatchSave1638 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4d04));
                      if (g_dispatchSave1638 != (FARPROC)0x0) {
                        g_dispatchSave1639 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4cec)
                                                     );
                        if (g_dispatchSave1639 != (FARPROC)0x0) {
                          g_dispatchSave1640 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4cdc));
                          if (g_dispatchSave1640 != (FARPROC)0x0) {
                            g_fnptr_007b0030 = GetProcAddress(g_glideFnTable,
                                                          MK4_VA(char, 0x004f4cc0));
                            if (g_fnptr_007b0030 != (FARPROC)0x0) {
                              g_dispatchSave1641 = GetProcAddress(g_glideFnTable,MK4_VA(char, 0x004f4cb0));
                              if (g_dispatchSave1641 != (FARPROC)0x0) {
                                g_dispatchSave1642 = GetProcAddress(g_glideFnTable,
                                                              MK4_VA(char, 0x004f4c9c));
                                if (g_dispatchSave1642 != (FARPROC)0x0) {
                                  g_PeekMessageA = GetProcAddress(g_glideFnTable,
                                                                MK4_VA(char, 0x004f4c8c));
                                  if (g_PeekMessageA != (FARPROC)0x0) {
                                    g_fnptr_007b0040 = GetProcAddress(g_glideFnTable,
                                                                  MK4_VA(char, 0x004f4c7c));
                                    if (g_fnptr_007b0040 != (FARPROC)0x0) {
                                      g_dispatchSave1643 = GetProcAddress(g_glideFnTable,
                                                                    MK4_VA(char, 0x004f4c68));
                                      if (g_dispatchSave1643 != (FARPROC)0x0) {
                                        g_dispatchSave1644 = GetProcAddress(g_glideFnTable,
                                                                                                                                            
                                                  MK4_VA(char, 0x004f4c50));
                                        if (g_dispatchSave1644 != (FARPROC)0x0) {
                                          g_dispatchSave1645 = GetProcAddress(g_glideFnTable,
                                                                        MK4_VA(char, 0x004f4c40));
                                          if (g_dispatchSave1645 != (FARPROC)0x0) {
                                            g_iat_indirect_007b0050 = GetProcAddress(g_glideFnTable,
                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4c2c));
                                            if (g_iat_indirect_007b0050 != (FARPROC)0x0) {
                                              g_iat_indirect_007b0054 = GetProcAddress(g_glideFnTable,
                                                                                                                                                        
                                                  MK4_VA(char, 0x004f4c18));
                                              if (g_iat_indirect_007b0054 != (FARPROC)0x0) {
                                                g_dispatchSave1646 = GetProcAddress(g_glideFnTable,
                                                                                                                                                            
                                                  MK4_VA(char, 0x004f4bfc));
                                                if (g_dispatchSave1646 != (FARPROC)0x0) {
                                                  g_dispatchSave1647 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                
                                                  MK4_VA(char, 0x004f4be8));
                                                  if (g_dispatchSave1647 != (FARPROC)0x0) {
                                                    g_iat_indirect_007b0060 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4bd0));
                                                  if (g_iat_indirect_007b0060 != (FARPROC)0x0) {
                                                    g_dispatchSave1648 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4bbc));
                                                  if (g_dispatchSave1648 != (FARPROC)0x0) {
                                                    g_dispatchSave1649 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4ba8));
                                                  if (g_dispatchSave1649 != (FARPROC)0x0) {
                                                    g_dispatchSave1650 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4b94));
                                                  if (g_dispatchSave1650 != (FARPROC)0x0) {
                                                    g_dispatchSave1651 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4b80));
                                                  if (g_dispatchSave1651 != (FARPROC)0x0) {
                                                    g_dispatchSave1652 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4b70));
                                                  if (g_dispatchSave1652 != (FARPROC)0x0) {
                                                    g_dispatchSave1653 = GetProcAddress(g_glideFnTable,
                                                                                                                                                                    
                                                  MK4_VA(char, 0x004f4b54));
                                                  if (g_dispatchSave1653 != (FARPROC)0x0) {
                                                    return 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
#else
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
#endif

