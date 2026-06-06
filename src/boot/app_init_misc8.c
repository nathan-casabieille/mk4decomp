/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004c51f0 (171b boot) - aux audio reference-window probe.
 *   Frame: sub esp, 0x3c; push esi, edi.
 *   Init 15-dword reference window on stack: buf[0]=0, buf[1..8]=0x5c,
 *   buf[9]=0x7a, buf[10]=0x10, buf[11]=0x38, buf[12..14]=0x5c, buf[15]=0x5a.
 *   Clear g_demoModeFlag; call Helper_AuxAudio_PostInit.
 *   If success, call DSoundQueryProperty; require rv==0xf.
 *   Loop esi=1..14: rv=AuxAudioDevCapsQuery(esi); abs(rv - buf[esi-1]) must be <= 5.
 *   If all pass, set g_demoModeFlag = 1.
 */
extern u32 g_demoModeFlag;
extern void AuxAudioDevCapsQuery(void);
extern void DSoundQueryProperty(void);
extern void Helper_AuxAudio_PostInit(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AppInit_Misc8(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int local_3c [15];
  
  local_3c[1] = 0x5c;
  local_3c[2] = 0x5c;
  local_3c[3] = 0x5c;
  local_3c[4] = 0x5c;
  local_3c[5] = 0x5c;
  local_3c[6] = 0x5c;
  local_3c[7] = 0x5c;
  local_3c[8] = 0x7a;
  local_3c[9] = 0x10;
  local_3c[10] = 0x38;
  local_3c[0xb] = 0x5c;
  local_3c[0xc] = 0x5c;
  local_3c[0xd] = 0x5c;
  local_3c[0xe] = 0x5a;
  g_demoModeFlag = 0;
  iVar1 = Helper_AuxAudio_PostInit();
  if ((iVar1 != 0) && (iVar1 = DSoundQueryProperty(), iVar1 == 0xf)) {
    iVar1 = 1;
    piVar4 = local_3c;
    do {
      piVar4 = (int *)((int)piVar4 + 4);
      iVar2 = AuxAudioDevCapsQuery(iVar1);
      uVar3 = iVar2 - piVar4[0xffffffff] >> 0x1f;
      if (5 < (int)((iVar2 - piVar4[0xffffffff] ^ uVar3) - uVar3)) {
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    g_demoModeFlag = 1;
  }
  return;
}
#else
__declspec(naked) void AppInit_Misc8(void) {
    __asm {
        sub     esp, 0x3c
        push    esi
        xor     ecx, ecx
        mov     eax, 0x5c
        push    edi
        mov     dword ptr [esp + 0x08], ecx
        mov     dword ptr [esp + 0x0c], eax
        mov     dword ptr [esp + 0x10], eax
        mov     dword ptr [esp + 0x14], eax
        mov     dword ptr [esp + 0x18], eax
        mov     dword ptr [esp + 0x1c], eax
        mov     dword ptr [esp + 0x20], eax
        mov     dword ptr [esp + 0x24], eax
        mov     dword ptr [esp + 0x28], 0x7a
        mov     dword ptr [esp + 0x2c], 0x10
        mov     dword ptr [esp + 0x30], 0x38
        mov     dword ptr [esp + 0x34], eax
        mov     dword ptr [esp + 0x38], eax
        mov     dword ptr [esp + 0x3c], eax
        mov     dword ptr [esp + 0x40], 0x5a
        mov     dword ptr [g_demoModeFlag], ecx
        call    Helper_AuxAudio_PostInit
        test    eax, eax
        jz      short L_c51_done
        call    DSoundQueryProperty
        cmp     eax, 0x0f
        jne     short L_c51_done
        mov     esi, 1
        lea     edi, [esp + 0x0c]
    L_c51_loop:
        push    esi
        call    AuxAudioDevCapsQuery
        mov     edx, dword ptr [edi - 4]
        add     esp, 4
        sub     eax, edx
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 5
        jg      short L_c51_done
        inc     esi
        add     edi, 4
        cmp     esi, 0x0f
        jle     short L_c51_loop
        mov     dword ptr [g_demoModeFlag], 1
    L_c51_done:
        pop     edi
        pop     esi
        add     esp, 0x3c
        ret
    }
}
#endif

