/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/*
 * @addr 0x004af190 (127b engine.install) - DirectInput EnumDevices
 *   bootstrap: copies a 108-byte DIDATAFORMAT template from
 *   0x544298; if IDirectInput exists, EnumDevices into 0x58c7c8;
 *   if the device was created, calls CreateDevice via the 0x4d28f0
 *   GUID; returns 1 on full success, 0 otherwise.
 */
extern unsigned int g_installCountdownBase;
extern unsigned int g_comptr_0058c7ac;
extern unsigned int g_renderer2_state9;
extern unsigned int g_renderer2_var2;
extern int g_renderer2_present_rc;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 R2_Init9(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_6c [26];
  undefined4 local_4;
  
  puVar2 = &g_installCountdownBase;
  puVar3 = local_6c;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_4 = 0x1800;
  if (g_comptr_0058c7ac != (int *)0x0) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_comptr_0058c7ac + 0x18))(g_comptr_0058c7ac,local_6c,&g_renderer2_state9,0);
  }
  if (g_renderer2_state9 != (undefined4 *)0x0) {
    g_comret_0058c7dc = (*(MK4ComMethod *)*g_renderer2_state9)(g_renderer2_state9,&g_iid,&g_renderer2_var2);
    if ((g_renderer2_state9 != (undefined4 *)0x0) && (g_renderer2_var2 != 0)) {
      return 1;
    }
  }
  return 0;
}
#else
__declspec(naked) void R2_Init9(void) {
    __asm {
        sub     esp, 0x6c
        mov     eax, dword ptr [g_comptr_0058c7ac]
        push    esi
        push    edi
        mov     ecx, 0x1b
        mov     esi, offset g_installCountdownBase
        lea     edi, [esp + 8]
        rep     movsd
        test    eax, eax
        mov     dword ptr [esp + 0x70], 0x1800
        je      step2
        mov     ecx, dword ptr [eax]
        push    0
        lea     edx, [esp + 0xc]
        push    offset g_renderer2_state9
        push    edx
        push    eax
        call    dword ptr [ecx + 0x18]
        mov     dword ptr [g_renderer2_present_rc], eax
step2:
        mov     eax, dword ptr [g_renderer2_state9]
        test    eax, eax
        je      failPath
        mov     ecx, dword ptr [eax]
        push    offset g_renderer2_var2
        push    0x004d28f0
        push    eax
        call    dword ptr [ecx]
        mov     dword ptr [g_renderer2_present_rc], eax
        mov     eax, dword ptr [g_renderer2_state9]
        test    eax, eax
        je      failPath
        mov     eax, dword ptr [g_renderer2_var2]
        test    eax, eax
        je      failPath
        mov     eax, 1
        pop     edi
        pop     esi
        add     esp, 0x6c
        ret
failPath:
        pop     edi
        xor     eax, eax
        pop     esi
        add     esp, 0x6c
        ret
    }
}
#endif

