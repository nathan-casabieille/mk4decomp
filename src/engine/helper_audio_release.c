/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_dispatchSave569;
extern u8 g_audioChannelTable[];
extern unsigned int g_obj_size;
extern unsigned int g_dispatchSave1408;
extern unsigned int g_flags_00f8fade;
extern void * g_dsoundContext;
extern unsigned int g_dispatchSave1415;
extern u32 g_dsoundFieldE4;
extern u32 g_dsoundFieldE8;
extern void ESF_Close(void);
extern void ESF_Open(void);
extern void ESF_ReadData(void);
extern void Helper_AudioStop(void);
extern void Helper_Sprintf(void);

extern unsigned int g_dispatchSave1407;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_AudioRelease(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  ushort **ppuVar7;
  int iVar8;
  ushort *puStack_158;
  ushort *puStack_154;
  int *piStack_150;
  ushort *puStack_14c;
  undefined4 uStack_130;
  int iStack_12c;
  int iStack_128;
  undefined4 uStack_124;
  int iStack_120;
  int aiStack_11c [4];
  undefined4 uStack_10c;
  undefined4 *puStack_108;
  ushort auStack_104 [2];
  ushort local_100 [128];
  
  if ((ushort)param_1 < 0x898) {
    iVar2 = (int)(short)(ushort)param_1;
    iVar5 = iVar2 * 0x1c;
    if (((&g_flags_00f8fade)[iVar5] & 2) != 0) {
      (&g_flags_00f8fade)[iVar5] = (&g_flags_00f8fade)[iVar5] & 0xfd;
      return;
    }
    piVar1 = &g_audioChannelTable + iVar2 * 7;
    if ((&g_audioChannelTable)[iVar2 * 7] == 0) {
      piVar6 = piVar1;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar6 = 0;
        piVar6 = piVar6 + 1;
      }
      if ((100 < g_dispatchSave1415) && (g_dispatchSave1415 = 0, g_dsoundContext != (ushort *)0x0)) {
        puStack_14c = g_dsoundContext;
        piStack_150 = (int *)0x4c351d;
        (*(MK4ComMethod *)(*(int *)g_dsoundContext + 0x1c))();
      }
      puStack_14c = (ushort *)(param_1 & 0xffff);
      puStack_154 = local_100;
      piStack_150 = (int *)MK4_VA(char, 0x004ffd50);
      puStack_158 = (ushort *)0x4c3533;
      Helper_Sprintf();
      puStack_14c = (ushort *)aiStack_11c;
      piStack_150 = &iStack_120;
      puStack_154 = auStack_104;
      puStack_158 = local_100;
      uVar3 = ESF_Open();
      *(undefined4 *)(&g_obj_size + iVar5) = uVar3;
      *(undefined2 *)(&g_dispatchSave1408 + iVar5) = 0;
      iVar4 = 1;
      (&g_flags_00f8fade)[iVar5] =
           (aiStack_11c[0] != 0 ^ (&g_flags_00f8fade)[iVar5] & 0xf9) & 1 ^ (&g_flags_00f8fade)[iVar5] & 0xf9
      ;
      uStack_124 = CONCAT22(auStack_104[0],auStack_104[0] >> 3);
      iStack_12c = iStack_120;
      iStack_128 = iStack_120 * (uint)(auStack_104[0] >> 3);
      aiStack_11c[3] = *(int *)(&g_obj_size + iVar5);
      uStack_10c = 0;
      puStack_108 = &uStack_130;
      uStack_130 = 0x10001;
      aiStack_11c[1] = 0x14;
      aiStack_11c[2] = 0xe2;
      if (g_dsoundContext != (ushort *)0x0) {
        puStack_14c = (ushort *)0x0;
        puStack_154 = (ushort *)(aiStack_11c + 1);
        puStack_158 = g_dsoundContext;
        piStack_150 = piVar1;
        (*(MK4ComMethod *)(*(int *)g_dsoundContext + 0xc))();
      }
      piVar6 = (int *)*piVar1;
      if (piVar6 != (int *)0x0) {
        puStack_14c = (ushort *)0x0;
        puStack_154 = (ushort *)0x4c362c;
        piStack_150 = piVar6;
        (*(MK4ComMethod *)(*piVar6 + 0x34))();
        puStack_158 = (ushort *)*piVar1;
        puStack_154 = (ushort *)0x0;
        (*(MK4ComMethod *)(*(int *)puStack_158 + 0x44))();
        (*(MK4ComMethod *)(*(int *)*piVar1 + 0x40))((int *)*piVar1,0);
        (*(MK4ComMethod *)(*(int *)*piVar1 + 0x3c))((int *)*piVar1,0);
        ppuVar7 = &puStack_158;
        iVar8 = 0;
        (*(MK4ComMethod *)(*(int *)*piVar1 + 0x2c))((int *)*piVar1,0,0,&puStack_154,ppuVar7,0,0,2);
        if ((iVar8 != 0) && (*(ushort ***)(&g_obj_size + iVar5) <= ppuVar7)) {
          ESF_ReadData(iVar8);
        }
        (*(MK4ComMethod *)(*(int *)*piVar1 + 0x4c))((int *)*piVar1,iVar8,ppuVar7,0,0);
        piVar6 = &g_dispatchSave1407 + iVar2 * 7;
        do {
          piStack_150 = (int *)*piVar1;
          puStack_154 = g_dsoundContext;
          puStack_158 = (ushort *)0x4c36b6;
          puStack_14c = (ushort *)piVar6;
          (*(MK4ComMethod *)(*(int *)g_dsoundContext + 0x14))();
          if (*piVar6 == 0) {
            puStack_14c = (ushort *)param_1;
            piStack_150 = (int *)0x4c36d3;
            Helper_AudioStop();
            break;
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar4 < 4);
        if (*piVar1 != 0) {
          g_dsoundFieldE4 = g_dsoundFieldE4 + *(int *)(&g_obj_size + iVar5);
          g_dsoundFieldE8 = g_dsoundFieldE8 + 1;
        }
      }
      puStack_14c = (ushort *)0x4c3700;
      ESF_Close();
    }
  }
  return;
}
#else
__declspec(naked) void Helper_AudioRelease(void)
{
    __asm {
        sub      esp, 0x138
        push     ebx
        mov      ebx, dword ptr [esp + 0x140]
        push     ebp
        xor      edx, edx
        push     esi
        cmp      bx, 0x898
        push     edi
        mov      dword ptr [esp + 0x14], edx
        mov      dword ptr [esp + 0x10], edx
        jae      L_3700
        movsx    eax, bx
        mov      esi, eax
        shl      esi, 3
        sub      esi, eax
        shl      esi, 2
        mov      al, byte ptr [esi + g_flags_00f8fade]
        test     al, 2
        je       L_34e0
        and      al, 0xfd
        mov      byte ptr [esi + g_flags_00f8fade], al
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x138
        ret
    L_34e0:
        mov      eax, dword ptr [esi + g_audioChannelTable]
        lea      ebp, [esi + g_audioChannelTable]
        cmp      eax, edx
        jne      L_3700
        mov      ecx, 7
        xor      eax, eax
        mov      edi, ebp
        rep stosd
        cmp      dword ptr [g_dispatchSave1415], 0x64
        jle      L_351d
        mov      eax, dword ptr [g_dsoundContext]
        mov      dword ptr [g_dispatchSave1415], edx
        cmp      eax, edx
        je       L_351d
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x1c]
    L_351d:
        and      ebx, 0xffff
        lea      edx, [esp + 0x48]
        push     ebx
        push     OFFSET g_dispatchSave569
        push     edx
        call     Helper_Sprintf
        add      esp, 0xc
        lea      eax, [esp + 0x2c]
        lea      ecx, [esp + 0x28]
        lea      edx, [esp + 0x44]
        push     eax
        push     ecx
        lea      eax, [esp + 0x50]
        push     edx
        push     eax
        call     ESF_Open
        mov      edx, dword ptr [esp + 0x3c]
        mov      dword ptr [esi + g_obj_size], eax
        mov      word ptr [esi + g_dispatchSave1408], 0
        mov      al, byte ptr [esi + g_flags_00f8fade]
        add      esp, 0x10
        and      al, 0xf9
        xor      ecx, ecx
        mov      ebx, 1
        test     edx, edx
        setne    cl
        xor      cl, al
        xor      edx, edx
        and      cl, bl
        mov      dword ptr [esp + 0x18], edx
        xor      cl, al
        mov      dword ptr [esp + 0x1c], edx
        mov      byte ptr [esi + g_flags_00f8fade], cl
        mov      ecx, dword ptr [esp + 0x44]
        mov      dword ptr [esp + 0x20], edx
        mov      eax, dword ptr [esp + 0x28]
        mov      dword ptr [esp + 0x24], edx
        mov      word ptr [esp + 0x26], cx
        shr      cx, 3
        mov      word ptr [esp + 0x24], cx
        mov      ecx, dword ptr [esp + 0x24]
        and      ecx, 0xffff
        mov      dword ptr [esp + 0x1c], eax
        imul     eax, ecx
        mov      dword ptr [esp + 0x30], edx
        mov      dword ptr [esp + 0x20], eax
        mov      eax, dword ptr [esi + g_obj_size]
        mov      dword ptr [esp + 0x34], edx
        mov      dword ptr [esp + 0x38], edx
        mov      dword ptr [esp + 0x38], eax
        mov      eax, dword ptr [g_dsoundContext]
        mov      dword ptr [esp + 0x3c], edx
        lea      ecx, [esp + 0x18]
        mov      dword ptr [esp + 0x40], edx
        test     eax, eax
        mov      word ptr [esp + 0x18], bx
        mov      word ptr [esp + 0x1a], bx
        mov      dword ptr [esp + 0x30], 0x14
        mov      dword ptr [esp + 0x34], 0xe2
        mov      dword ptr [esp + 0x40], ecx
        je       L_3619
        mov      edx, dword ptr [eax]
        push     0
        lea      ecx, [esp + 0x34]
        push     ebp
        push     ecx
        push     eax
        call     dword ptr [edx + 0xc]
    L_3619:
        mov      eax, dword ptr [ebp]
        test     eax, eax
        je       L_36fb
        mov      edx, dword ptr [eax]
        push     0
        push     eax
        call     dword ptr [edx + 0x34]
        mov      eax, dword ptr [ebp]
        push     0
        push     eax
        mov      ecx, dword ptr [eax]
        call     dword ptr [ecx + 0x44]
        mov      eax, dword ptr [ebp]
        push     0
        push     eax
        mov      edx, dword ptr [eax]
        call     dword ptr [edx + 0x40]
        mov      eax, dword ptr [ebp]
        push     0
        push     eax
        mov      ecx, dword ptr [eax]
        call     dword ptr [ecx + 0x3c]
        mov      eax, dword ptr [ebp]
        push     2
        push     0
        lea      ecx, [esp + 0x18]
        mov      edx, dword ptr [eax]
        push     0
        push     ecx
        lea      ecx, [esp + 0x24]
        push     ecx
        push     0
        push     0
        push     eax
        call     dword ptr [edx + 0x2c]
        mov      ecx, dword ptr [esp + 0x14]
        test     ecx, ecx
        je       L_368d
        mov      edx, dword ptr [esp + 0x10]
        mov      eax, dword ptr [esi + g_obj_size]
        cmp      edx, eax
        jb       L_368d
        push     ecx
        call     ESF_ReadData
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 4
    L_368d:
        mov      eax, dword ptr [ebp]
        mov      edi, dword ptr [esp + 0x10]
        push     0
        push     0
        mov      edx, dword ptr [eax]
        push     edi
        push     ecx
        push     eax
        call     dword ptr [edx + 0x4c]
        lea      edi, [esi + g_dispatchSave1407]
    L_36a6:
        mov      eax, dword ptr [g_dsoundContext]
        mov      edx, dword ptr [ebp]
        push     edi
        push     edx
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x14]
        cmp      dword ptr [edi], 0
        je       L_36c6
        inc      ebx
        add      edi, 4
        cmp      ebx, 4
        jl       L_36a6
        jmp      L_36d6
    L_36c6:
        mov      eax, dword ptr [esp + 0x14c]
        push     eax
        call     Helper_AudioStop
        add      esp, 4
    L_36d6:
        cmp      dword ptr [ebp], 0
        je       L_36fb
        mov      ecx, dword ptr [esi + g_obj_size]
        mov      edx, dword ptr [g_dsoundFieldE4]
        mov      eax, dword ptr [g_dsoundFieldE8]
        add      edx, ecx
        inc      eax
        mov      dword ptr [g_dsoundFieldE4], edx
        mov      dword ptr [g_dsoundFieldE8], eax
    L_36fb:
        call     ESF_Close
    L_3700:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x138
        ret
    }
}
#endif

