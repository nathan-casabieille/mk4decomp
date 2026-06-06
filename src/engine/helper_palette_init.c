/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_texturedTriVar;
extern unsigned int g_dispatchSave1340;
extern unsigned int g_dispatchSave1352;
extern unsigned int g_dispatchSave1353;
extern unsigned int g_dispatchSave1354;
extern unsigned int g_dispatchSave1355;
extern unsigned int g_dispatchSave1400;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_PaletteInit(int param_1)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  short sVar8;
  ushort uVar9;
  int iVar10;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  ushort local_c0 [32];
  ushort local_80 [64];
  
  g_dispatchSave1352 = 0x1010101;
  g_dispatchSave1353 = 0x1010101;
  g_dispatchSave1354 = 0x1010101;
  g_dispatchSave1355 = 0x1010101;
  if (param_1 != g_texturedTriVar) {
    if (param_1 == 0) {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 2;
        uVar9 = *(ushort *)(g_dispatchSave1400 + -2 + iVar5);
        *(ushort *)(g_dispatchSave1400 + -2 + iVar5) = uVar9 >> 1 & 0x7fe0 | uVar9 & 0x1f;
      } while (iVar5 < 0x200000);
      local_d4 = 0;
      local_d0 = 1;
    }
    else {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 2;
        uVar9 = *(ushort *)(g_dispatchSave1400 + -2 + iVar5);
        *(ushort *)(g_dispatchSave1400 + -2 + iVar5) = (uVar9 & 0xffe0) << 1 | uVar9 & 0x3f;
      } while (iVar5 < 0x200000);
      local_d4 = 0;
      local_d0 = 1;
    }
    do {
      puVar6 = local_c0;
      iVar7 = 0x20;
      iVar5 = 0;
      do {
        *puVar6 = (ushort)(iVar5 >> 4) & 0x1f;
        puVar6 = puVar6 + 1;
        iVar7 = iVar7 + -1;
        iVar5 = iVar5 + local_d0;
      } while (iVar7 != 0);
      puVar6 = local_80;
      iVar7 = 0x40;
      iVar5 = 0;
      do {
        *puVar6 = (ushort)(iVar5 >> 4) & 0x3f;
        puVar6 = puVar6 + 1;
        iVar7 = iVar7 + -1;
        iVar5 = iVar5 + local_d0;
      } while (iVar7 != 0);
      iVar5 = 0;
      puVar6 = local_c0;
      uVar3 = -(uint)(param_1 != 0) & 0x20;
      local_cc = 0x20;
      do {
        iVar7 = 0;
        if (uVar3 != 0xffffffe0) {
          do {
            puVar4 = local_c0;
            local_c8 = 0x20;
            do {
              if (param_1 == 0) {
                uVar9 = local_c0[iVar7];
                sVar8 = *puVar6 << 5;
              }
              else {
                uVar9 = local_80[iVar7];
                sVar8 = *puVar6 << 6;
              }
              uVar1 = *puVar4;
              iVar10 = local_d4 + iVar5;
              puVar4 = puVar4 + 1;
              iVar5 = iVar5 + 1;
              *(ushort *)(g_dispatchSave1340 + iVar10 * 2) = (uVar9 + sVar8) * 0x20 + uVar1;
              local_c8 = local_c8 + -1;
            } while (local_c8 != 0);
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)(uVar3 + 0x20));
        }
        puVar6 = puVar6 + 1;
        local_cc = local_cc + -1;
      } while (local_cc != 0);
      local_d4 = local_d4 + 0x10000;
      bVar2 = local_d0 < 0x10;
      local_d0 = local_d0 + 1;
    } while (bVar2);
    g_texturedTriVar = param_1;
  }
  return;
}
#else
__declspec(naked) void Helper_PaletteInit(void)
{
    __asm {
        mov     eax, 0x01010101
        sub     esp, 0xD4
        mov     dword ptr [g_dispatchSave1352], eax
        mov     dword ptr [g_dispatchSave1353], eax
        push    esi
        mov     esi, dword ptr [esp + 0xDC]
        mov     dword ptr [g_dispatchSave1354], eax
        mov     dword ptr [g_dispatchSave1355], eax
        mov     eax, dword ptr [g_texturedTriVar]
        cmp     esi, eax
        je      L_ptb_eq_skip
        push    edi
        push    ebp
        test    esi, esi
        push    ebx
        je      L_ptb_5bit
        xor     ecx, ecx
    L_ptb_6bit_loop:
        mov     edx, dword ptr [g_dispatchSave1400]
        add     ecx, 2
        mov     ax, word ptr [edx + ecx - 2]
        mov     edi, eax
        and     eax, 0x3F
        and     edi, 0xFFE0
        shl     edi, 1
        or      edi, eax
        cmp     ecx, 0x00200000
        mov     word ptr [edx + ecx - 2], di
        jl      L_ptb_6bit_loop
        xor     edi, edi
        mov     ebx, 1
        mov     dword ptr [esp + 0x10], edi
        mov     dword ptr [esp + 0x14], ebx
        jmp     L_ptb_after_recode
    L_ptb_5bit:
        xor     ecx, ecx
    L_ptb_5bit_loop:
        mov     edx, dword ptr [g_dispatchSave1400]
        add     ecx, 2
        mov     ax, word ptr [edx + ecx - 2]
        mov     edi, eax
        and     eax, 0x1F
        shr     edi, 1
        and     edi, 0x7FE0
        or      edi, eax
        cmp     ecx, 0x00200000
        mov     word ptr [edx + ecx - 2], di
        jl      L_ptb_5bit_loop
        xor     edi, edi
        mov     ebx, 1
        mov     dword ptr [esp + 0x10], edi
        mov     dword ptr [esp + 0x14], ebx
        jmp     L_ptb_after_recode
    L_ptb_outer_reload:
        mov     esi, dword ptr [esp + 0xE8]
    L_ptb_after_recode:
        xor     eax, eax
        lea     ecx, [esp + 0x24]
        mov     edx, 0x20
    L_ptb_idx20_loop:
        mov     ebp, eax
        add     eax, ebx
        sar     ebp, 4
        and     ebp, 0x1F
        mov     word ptr [ecx], bp
        add     ecx, 2
        dec     edx
        jne     L_ptb_idx20_loop
        xor     eax, eax
        lea     ecx, [esp + 0x64]
        mov     edx, 0x40
    L_ptb_idx40_loop:
        mov     ebp, eax
        add     eax, ebx
        sar     ebp, 4
        and     ebp, 0x3F
        mov     word ptr [ecx], bp
        add     ecx, 2
        dec     edx
        jne     L_ptb_idx40_loop
        mov     eax, esi
        xor     ecx, ecx
        neg     eax
        sbb     eax, eax
        lea     esi, [esp + 0x24]
        and     eax, 0x20
        mov     dword ptr [esp + 0x18], 0x20
        add     eax, 0x20
        mov     dword ptr [esp + 0x20], eax
    L_ptb_outer_check:
        xor     edx, edx
        test    eax, eax
        jle     L_ptb_after_inner_pair
    L_ptb_iter_setup:
        lea     eax, [esp + 0x24]
        mov     dword ptr [esp + 0x1C], 0x20
        jmp     L_ptb_inner_top
    L_ptb_inner_reload_edi:
        mov     edi, dword ptr [esp + 0x10]
    L_ptb_inner_top:
        mov     ebx, dword ptr [esp + 0xE8]
        test    ebx, ebx
        mov     bx, word ptr [esi]
        je      L_ptb_inner_use_24
        mov     bp, word ptr [esp + edx*2 + 0x64]
        shl     bx, 6
        jmp     L_ptb_inner_combine
    L_ptb_inner_use_24:
        mov     bp, word ptr [esp + edx*2 + 0x24]
        shl     bx, 5
    L_ptb_inner_combine:
        add     bp, bx
        mov     ebx, dword ptr [g_dispatchSave1340]
        shl     ebp, 5
        add     bp, word ptr [eax]
        add     edi, ecx
        add     eax, 2
        inc     ecx
        mov     word ptr [ebx + edi*2], bp
        mov     edi, dword ptr [esp + 0x1C]
        dec     edi
        mov     dword ptr [esp + 0x1C], edi
        jne     L_ptb_inner_reload_edi
        mov     eax, dword ptr [esp + 0x20]
        mov     edi, dword ptr [esp + 0x10]
        inc     edx
        cmp     edx, eax
        jl      L_ptb_iter_setup
        mov     ebx, dword ptr [esp + 0x14]
    L_ptb_after_inner_pair:
        mov     edx, dword ptr [esp + 0x18]
        add     esi, 2
        dec     edx
        mov     dword ptr [esp + 0x18], edx
        jne     L_ptb_outer_check
        inc     ebx
        add     edi, 0x10000
        mov     dword ptr [esp + 0x14], ebx
        mov     dword ptr [esp + 0x10], edi
        lea     ecx, [ebx - 1]
        cmp     ecx, 0x10
        jl      L_ptb_outer_reload
        mov     edx, dword ptr [esp + 0xE8]
        pop     ebx
        pop     ebp
        mov     dword ptr [g_texturedTriVar], edx
        pop     edi
    L_ptb_eq_skip:
        pop     esi
        add     esp, 0xD4
        ret
    }
}
#endif

