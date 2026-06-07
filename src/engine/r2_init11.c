/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004af020 (263b engine.install) - DSound slot init: per-slot capture/buffer setup.
 *   arg0 byte: slot index (0..0x10). If slot already has buffer ptr, return 1.
 *   Else: copy WAVEFORMAT template from g_installCountdownBase (108 bytes); create a
 *   capture buffer via vtbl[+0x18]; query 8-byte interface via [+0x74]; query
 *   for GUID g_iid via vtbl[0]; if global init succeeded and slot
 *   has valid pointers, register via [+0x0c]. Return 1 if all slots valid, 0 else.
 */
extern unsigned int g_installCountdownBase;
extern u8 g_renderer2_buf1[];
extern unsigned int g_comptr_0058c7ac;
extern unsigned int g_renderer2_obj;
extern int g_renderer2_present_rc;
extern unsigned int g_iid;

extern u8 g_renderer2_buf3[];
extern u8 g_renderer2_buf2[];

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 R2_Init11(byte param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c [27];
  
  piVar2 = g_comptr_0058c7ac;
  if (param_1 < 0x10) {
    uVar4 = (uint)param_1;
    if ((&g_renderer2_buf1)[uVar4] != 0) {
      return 1;
    }
    puVar6 = &g_installCountdownBase;
    puVar7 = local_6c;
    for (iVar5 = 0x1b; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    piVar1 = &g_renderer2_buf2 + uVar4;
    bVar8 = g_comptr_0058c7ac != (int *)0x0;
    *piVar1 = 0;
    if (bVar8) {
      g_comret_0058c7dc = (*(MK4ComMethod *)(*piVar2 + 0x18))(piVar2,local_6c,piVar1,0);
    }
    piVar2 = (int *)*piVar1;
    local_74 = 0;
    local_70 = 0;
    if (piVar2 != (int *)0x0) {
      g_comret_0058c7dc = (*(MK4ComMethod *)(*piVar2 + 0x74))(piVar2,8,&local_74);
    }
    puVar6 = (undefined4 *)*piVar1;
    piVar2 = &g_renderer2_buf3 + uVar4;
    *piVar2 = 0;
    if (puVar6 != (undefined4 *)0x0) {
      g_comret_0058c7dc = (*(MK4ComMethod *)*puVar6)(puVar6,&g_iid,piVar2);
    }
    if ((g_comptr_0058c7c0 != 0) && (piVar3 = (int *)*piVar2, piVar3 != (int *)0x0)) {
      g_comret_0058c7dc = (*(MK4ComMethod *)(*piVar3 + 0xc))(piVar3,g_comptr_0058c7c0,&g_renderer2_buf1 + uVar4);
    }
    if (((*piVar1 != 0) && (*piVar2 != 0)) && ((&g_renderer2_buf1)[uVar4] != 0)) {
      return 1;
    }
  }
  return 0;
}
#else
__declspec(naked) void R2_Init11(void) {
    __asm {
        mov     eax, [esp + 4]
        sub     esp, 0x78
        cmp     al, 0x10
        push    ebx
        push    esi
        push    edi
        jae     L_dss_fail
        and     eax, 0xff
        shl     eax, 2
        mov     ebx, eax
        mov     ecx, dword ptr [ebx + g_renderer2_buf1]
        lea     eax, [ebx + g_renderer2_buf1]
        test    ecx, ecx
        mov     [esp + 0xc], eax
        jz      short L_dss_setup
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x78
        ret
    L_dss_setup:
        mov     eax, dword ptr [g_comptr_0058c7ac]
        mov     ecx, 0x1b
        mov     esi, offset g_installCountdownBase
        lea     edi, [esp + 0x18]
        rep     movsd
        lea     esi, [ebx + g_renderer2_buf2]
        test    eax, eax
        mov     dword ptr [esi], 0
        jz      short L_dss_step2
        mov     ecx, [eax]
        push    0
        lea     edx, [esp + 0x1c]
        push    esi
        push    edx
        push    eax
        call    dword ptr [ecx + 0x18]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dss_step2:
        mov     eax, [esi]
        mov     dword ptr [esp + 0x10], 0
        test    eax, eax
        mov     dword ptr [esp + 0x14], 0
        jz      short L_dss_step3
        mov     ecx, [eax]
        lea     edx, [esp + 0x10]
        push    edx
        push    8
        push    eax
        call    dword ptr [ecx + 0x74]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dss_step3:
        mov     eax, [esi]
        lea     edi, [ebx + g_renderer2_buf3]
        test    eax, eax
        mov     dword ptr [edi], 0
        jz      short L_dss_step4
        mov     ecx, [eax]
        push    edi
        push    offset g_iid
        push    eax
        call    dword ptr [ecx]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dss_step4:
        mov     ecx, dword ptr [g_renderer2_obj]
        test    ecx, ecx
        jz      short L_dss_validate
        mov     eax, [edi]
        test    eax, eax
        jz      short L_dss_validate
        mov     ebx, [esp + 0xc]
        mov     edx, [eax]
        push    ebx
        push    ecx
        push    eax
        call    dword ptr [edx + 0x0c]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dss_validate:
        cmp     dword ptr [esi], 0
        jz      short L_dss_fail
        cmp     dword ptr [edi], 0
        jz      short L_dss_fail
        mov     eax, [esp + 0xc]
        cmp     dword ptr [eax], 0
        jz      short L_dss_fail
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x78
        ret
    L_dss_fail:
        pop     edi
        pop     esi
        xor     eax, eax
        pop     ebx
        add     esp, 0x78
        ret
    }
}
#endif

