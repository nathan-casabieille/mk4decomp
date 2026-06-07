/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_comptr_0058c7bc;
extern unsigned int g_renderer2_obj;
extern unsigned int g_renderer2_state7;
extern unsigned int g_renderer2_r7_data;
extern int g_renderer2_present_rc;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 R2_Init7(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int local_80 [8];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 auStack_50 [20];
  
  local_80[0] = 0;
  if (g_comptr_0058c7bc != (int *)0x0) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_comptr_0058c7bc + 0x18))(g_comptr_0058c7bc,&g_renderer2_state7,0);
  }
  if ((g_renderer2_state7 != (int *)0x0) && (g_comptr_0058c7c0 != (int *)0x0)) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_comptr_0058c7c0 + 0x18))(g_comptr_0058c7c0,g_renderer2_state7);
  }
  piVar2 = local_80;
  for (iVar1 = 0xb; piVar2 = (int *)((int)piVar2 + 4), iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
  }
  local_80[1] = 0x2c;
  local_80[4] = 0x280;
  local_80[5] = 0x1e0;
  uStack_60 = 0x44200000;
  uStack_5c = 0x43f00000;
  uStack_58 = 0;
  uStack_54 = 0x3f800000;
  if (((g_renderer2_state7 != (int *)0x0) &&
      (g_comret_0058c7dc = (*(MK4ComMethod *)(*g_renderer2_state7 + 0x44))(g_renderer2_state7,local_80 + 1),
      g_renderer2_state7 != (int *)0x0)) && (g_comptr_0058c7c0 != (int *)0x0)) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_comptr_0058c7c0 + 0x34))(g_comptr_0058c7c0,g_renderer2_state7);
  }
  if (g_comptr_0058c7bc != (int *)0x0) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_comptr_0058c7bc + 0x14))(g_comptr_0058c7bc,&g_renderer2_r7_data,0);
  }
  puVar3 = auStack_50;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  auStack_50[0] = 0x50;
  if (g_renderer2_r7_data != (int *)0x0) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_renderer2_r7_data + 0xc))(g_renderer2_r7_data,auStack_50);
  }
  if ((g_comptr_0058c7c0 != (int *)0x0) && (g_renderer2_r7_data != (int *)0x0)) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_renderer2_r7_data + 0x14))(g_renderer2_r7_data,g_comptr_0058c7c0,local_80);
  }
  if (local_80[0] != 0) {
    if (g_renderer2_state7 == (int *)0x0) {
      return 0;
    }
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_renderer2_state7 + 0x20))(g_renderer2_state7,local_80[0]);
  }
  if (((g_renderer2_state7 != (int *)0x0) && (g_renderer2_r7_data != (int *)0x0)) && (local_80[0] != 0)) {
    return 1;
  }
  return 0;
}
#else
__declspec(naked) void R2_Init7(void)
{
    __asm {
        sub     esp, 0x80
        push    ebx
        mov     ebx, dword ptr [g_comptr_0058c7bc]
        push    esi
        push    edi
        test    ebx, ebx
        mov     dword ptr [esp + 0x0C], 0
        je      L_dxic_after_obj1
        mov     eax, dword ptr [ebx]
        push    0
        push    offset g_renderer2_state7
        push    ebx
        call    dword ptr [eax + 0x18]
        mov     ebx, dword ptr [g_comptr_0058c7bc]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dxic_after_obj1:
        mov     edx, dword ptr [g_renderer2_state7]
        mov     esi, dword ptr [g_renderer2_obj]
        test    edx, edx
        je      L_dxic_after_obj2
        test    esi, esi
        je      L_dxic_after_obj2
        mov     ecx, dword ptr [esi]
        push    edx
        push    esi
        call    dword ptr [ecx + 0x18]
        mov     ebx, dword ptr [g_comptr_0058c7bc]
        mov     edx, dword ptr [g_renderer2_state7]
        mov     esi, dword ptr [g_renderer2_obj]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dxic_after_obj2:
        mov     ecx, 0x0B
        xor     eax, eax
        lea     edi, [esp + 0x10]
        rep     stosd
        test    edx, edx
        mov     dword ptr [esp + 0x10], 0x2C
        mov     dword ptr [esp + 0x1C], 0x280
        mov     dword ptr [esp + 0x20], 0x01E0
        mov     dword ptr [esp + 0x2C], 0x44200000
        mov     dword ptr [esp + 0x30], 0x43F00000
        mov     dword ptr [esp + 0x34], eax
        mov     dword ptr [esp + 0x38], 0x3F800000
        je      L_dxic_after_obj3
        mov     eax, dword ptr [edx]
        lea     ecx, [esp + 0x10]
        push    ecx
        push    edx
        call    dword ptr [eax + 0x44]
        mov     edx, dword ptr [g_renderer2_state7]
        mov     ebx, dword ptr [g_comptr_0058c7bc]
        mov     esi, dword ptr [g_renderer2_obj]
        mov     dword ptr [g_renderer2_present_rc], eax
        test    edx, edx
        je      L_dxic_after_obj3
        test    esi, esi
        je      L_dxic_after_obj3
        mov     eax, dword ptr [esi]
        push    edx
        push    esi
        call    dword ptr [eax + 0x34]
        mov     ebx, dword ptr [g_comptr_0058c7bc]
        mov     edx, dword ptr [g_renderer2_state7]
        mov     esi, dword ptr [g_renderer2_obj]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dxic_after_obj3:
        test    ebx, ebx
        je      L_dxic_after_obj4
        mov     ecx, dword ptr [ebx]
        push    0
        push    offset g_renderer2_r7_data
        push    ebx
        call    dword ptr [ecx + 0x14]
        mov     edx, dword ptr [g_renderer2_state7]
        mov     esi, dword ptr [g_renderer2_obj]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dxic_after_obj4:
        mov     ecx, 0x14
        xor     eax, eax
        lea     edi, [esp + 0x3C]
        rep     stosd
        mov     eax, dword ptr [g_renderer2_r7_data]
        mov     dword ptr [esp + 0x3C], 0x50
        test    eax, eax
        je      L_dxic_after_obj5
        mov     edx, dword ptr [eax]
        lea     ecx, [esp + 0x3C]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x0C]
        mov     edx, dword ptr [g_renderer2_state7]
        mov     esi, dword ptr [g_renderer2_obj]
        mov     dword ptr [g_renderer2_present_rc], eax
        mov     eax, dword ptr [g_renderer2_r7_data]
    L_dxic_after_obj5:
        test    esi, esi
        je      L_dxic_after_obj6
        test    eax, eax
        je      L_dxic_after_obj6
        mov     edx, dword ptr [eax]
        lea     ecx, [esp + 0x0C]
        push    ecx
        push    esi
        push    eax
        call    dword ptr [edx + 0x14]
        mov     edx, dword ptr [g_renderer2_state7]
        mov     dword ptr [g_renderer2_present_rc], eax
        mov     eax, dword ptr [g_renderer2_r7_data]
    L_dxic_after_obj6:
        mov     ecx, dword ptr [esp + 0x0C]
        test    ecx, ecx
        je      L_dxic_after_obj7
        test    edx, edx
        je      L_dxic_fail
        mov     eax, dword ptr [edx]
        push    ecx
        push    edx
        call    dword ptr [eax + 0x20]
        mov     edx, dword ptr [g_renderer2_state7]
        mov     dword ptr [g_renderer2_present_rc], eax
        mov     eax, dword ptr [g_renderer2_r7_data]
    L_dxic_after_obj7:
        test    edx, edx
        je      L_dxic_fail
        test    eax, eax
        je      L_dxic_fail
        mov     eax, dword ptr [esp + 0x0C]
        test    eax, eax
        je      L_dxic_fail
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x80
        ret
    L_dxic_fail:
        pop     edi
        pop     esi
        xor     eax, eax
        pop     ebx
        add     esp, 0x80
        ret
    }
}
#endif

