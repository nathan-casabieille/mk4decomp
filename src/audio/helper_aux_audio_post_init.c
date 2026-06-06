/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/*
 * @addr 0x004ac320 (128b audio) - timer setup helper (PostInit body):
 *   issues two iat-4d2244 calls (timeBeginPeriod and timeSetEvent
 *   style) to set up a timer; returns 1 on success, 0 on failure.
 *   Stashes audio pre-state and start-of-period markers.
 */
extern u32 g_audioPreState;
extern u32 g_audioState08;
extern unsigned int g_iat_mciSendCommandA;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 Helper_AuxAudio_PostInit(void)

{
  MCIERROR MVar1;
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  undefined1 local_14 [4];
  MCIDEVICEID local_10;
  char *local_c;
  
  if (g_audioState08 == 0) {
    local_c = MK4_VA(char, 0x004f4684);
    MVar1 = mciSendCommandA(0,0x803,0x2100,(DWORD_PTR)local_14);
    g_audioState08 = (uint)(MVar1 == 0);
    if (MVar1 != 0) {
      return 0;
    }
    g_audioPreState = local_10;
  }
  local_1c = 5;
  MVar1 = mciSendCommandA(g_audioPreState,0x814,0x100,(DWORD_PTR)local_24);
  if ((MVar1 == 0) && (local_20 != 0)) {
    return 1;
  }
  return 0;
}
#else
__declspec(naked) void Helper_AuxAudio_PostInit(void) {
    __asm {
        mov     eax, dword ptr [g_audioState08]
        sub     esp, 0x24
        test    eax, eax
        push    esi
        mov     esi, dword ptr [g_iat_mciSendCommandA]
        jne     skipBegin
        lea     eax, [esp + 0x14]
        mov     dword ptr [esp + 0x1c], 0x004f4684
        push    eax
        push    0x2100
        push    0x803
        push    0
        call    esi
        neg     eax
        sbb     eax, eax
        inc     eax
        mov     dword ptr [g_audioState08], eax
        je      failPath
        mov     ecx, dword ptr [esp + 0x18]
        mov     dword ptr [g_audioPreState], ecx
skipBegin:
        mov     eax, dword ptr [g_audioPreState]
        lea     edx, [esp + 4]
        push    edx
        push    0x100
        push    0x814
        push    eax
        mov     dword ptr [esp + 0x1c], 5
        call    esi
        test    eax, eax
        jne     failPath
        mov     eax, dword ptr [esp + 8]
        test    eax, eax
        je      failPath
        mov     eax, 1
        pop     esi
        add     esp, 0x24
        ret
failPath:
        xor     eax, eax
        pop     esi
        add     esp, 0x24
        ret
    }
}
#endif

