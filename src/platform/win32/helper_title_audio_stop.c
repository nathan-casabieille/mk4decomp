/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004c42f0 (103b platform.win32) - 1-time init walking 16-slot table:
 *   If g_dsoundFieldE0 set: ret. Else: set it, call Audio_UpdateChannels.
 *   For esi in 0xf9eb80..0xf9ebc0 (4-byte stride): if ax!=0xffff,
 *   lookup arr[type*7]; if non-null, call vtbl->method48(ax_obj).
 */
extern unsigned int g_audioVoiceQueue;
extern u32 g_dsoundFieldE0;
extern void Audio_UpdateChannels(void);

extern unsigned int g_audioVoicePool;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_TitleAudioStop(void)

{
  short sVar1;
  short *psVar2;
  
  if (g_dsoundFieldE0 == 0) {
    g_dsoundFieldE0 = 1;
    Audio_UpdateChannels();
    psVar2 = &g_audioChannelQueue;
    do {
      sVar1 = *psVar2;
      if ((sVar1 != -1) && ((&g_audioChannelTable)[sVar1 * 7] != 0)) {
        (*(MK4ComMethod *)(*(int *)(&g_audioChannelTable)[sVar1 * 7 + (int)psVar2[1]] + 0x48))
                  ((int *)(&g_audioChannelTable)[sVar1 * 7 + (int)psVar2[1]]);
      }
      psVar2 = psVar2 + 2;
    } while ((int)psVar2 < 0xf9ebc0);
  }
  return;
}
#else
__declspec(naked) void Helper_TitleAudioStop(void) {
    __asm {
        mov     eax, dword ptr [g_dsoundFieldE0]
        test    eax, eax
        _emit   75h
        _emit   5dh
        push    esi
        mov     dword ptr [g_dsoundFieldE0], 1
        call    Audio_UpdateChannels
        mov     esi, offset g_audioVoiceQueue
loop4c42f0:
        mov     ax, word ptr [esi]
        cmp     ax, 0xffff
        _emit   74h
        _emit   33h
        movsx   eax, ax
        lea     ecx, [eax*8]
        sub     ecx, eax
        mov     edx, [ecx*4 + g_audioVoicePool]
        test    edx, edx
        _emit   74h
        _emit   1ch
        lea     edx, [eax*8]
        sub     edx, eax
        movsx   eax, word ptr [esi + 2]
        add     edx, eax
        mov     eax, [edx*4 + g_audioVoicePool]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x48]
        add     esi, 4
        cmp     esi, 0x00f9ebc0
        _emit   7ch
        _emit   0b9h
        pop     esi
        ret
    }
}
#endif

