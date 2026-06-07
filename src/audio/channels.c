/**
 * Per-frame DirectSound channel sweep.
 *
 * Walks g_audioChannelQueue (16 active-channel slots) and for each
 * live entry: looks up the channel's COM object, calls its vtable
 * method 9 (offset 0x24 - probably IDirectSoundBuffer::GetStatus),
 * then dispatches Helper_AudioStop / Helper_AudioRelease based on
 * the returned status byte and per-channel flags.
 */
#include "audio/sound.h"
#include "portable/ghidra_types.h"

/*
 * @addr 0x004c37f0
 *
 * Naked + __asm: register-level pointer arithmetic doesn't map
 * well to plain C - the per-channel offsets compute (id*28) and
 * (other*8 - id + other) into the same state table, the COM call
 * result is mixed with bit-test bl, [esi + flags] dispatch, and
 * the loop back-edge is a long jl that would force MSVC to lay
 * out the blocks differently from C source.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void __fastcall Audio_UpdateChannels(uint param_1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  uint local_4;
  
  psVar5 = &g_audioChannelQueue;
  local_4 = param_1;
  do {
    sVar1 = *psVar5;
    if (sVar1 != -1) {
      iVar3 = (int)sVar1;
      iVar4 = iVar3 * 0x1c;
      if ((&g_audioChannelTable)[iVar3 * 7] == 0) {
        *psVar5 = -1;
      }
      else {
        (*(MK4ComMethod *)(*(int *)(&g_audioChannelTable)[iVar3 * 7 + (int)psVar5[1]] + 0x24))
                  ((int *)(&g_audioChannelTable)[iVar3 * 7 + (int)psVar5[1]],&local_4);
        if (((&g_flags_00f8fade)[iVar4] & 2) == 0) {
LAB_004c3874:
          bVar2 = (byte)local_4;
          if (g_audioMute != '\0') goto LAB_004c38b7;
        }
        else if (((local_4 & 1) == 0) || (bVar2 = (byte)local_4, g_audioMute != '\0')) {
          Helper_AudioStop(sVar1);
          goto LAB_004c3874;
        }
        if (((bVar2 & 1) == 0) || ((bVar2 & 2) != 0)) {
          (&g_flags_00f8fadf)[iVar4 + psVar5[1]] = 0;
          *psVar5 = -1;
          if ((bVar2 & 2) != 0) {
            Helper_AudioStop(sVar1);
            if (((&g_flags_00f8fade)[iVar4] & 2) == 0) {
              Helper_AudioRelease(sVar1);
            }
          }
        }
      }
    }
LAB_004c38b7:
    psVar5 = psVar5 + 2;
    if (0xf9ebbf < (int)psVar5) {
      return;
    }
  } while( true );
}
#else
__declspec(naked) void Audio_UpdateChannels(void)
{
    __asm {
        push    ecx
        push    ebx
        push    ebp
        push    esi
        push    edi
        mov     edi, offset g_audioChannelQueue
        mov     bl, 2
chan_loop:
        mov     bp, word ptr [edi]
        cmp     bp, 0xffff
        je      next_chan_long
        movsx   eax, bp
        lea     esi, [eax*8]
        sub     esi, eax
        shl     esi, 2
        mov     ecx, dword ptr [esi + g_audioChannelTable]
        test    ecx, ecx
        jne     have_obj
        mov     word ptr [edi], 0xffff
        jmp     next_chan_long
have_obj:
        movsx   edx, word ptr [edi + 2]
        lea     ecx, [eax*8]
        sub     ecx, eax
        add     ecx, edx
        lea     edx, [esp + 0x10]
        push    edx
        mov     eax, dword ptr [ecx*4 + g_audioChannelTable]
        push    eax
        mov     ecx, dword ptr [eax]
        call    dword ptr [ecx + 0x24]
        test    byte ptr [esi + g_audioChannelTable + 0x16], bl
        mov     al, byte ptr [esp + 0x10]
        jz      check_mute
        test    al, 1
        jz      do_stop1
        mov     cl, byte ptr [g_audioMute]
        test    cl, cl
        jz      after_stop1
do_stop1:
        push    ebp
        call    Helper_AudioStop
        mov     al, byte ptr [esp + 0x14]
        add     esp, 4
check_mute:
        mov     cl, byte ptr [g_audioMute]
        test    cl, cl
        jne     next_chan
after_stop1:
        test    al, 1
        jz      mark_dead
        ; orig encodes `test bl, al` as 84 c3, MASM emits 84 d8.
        _emit   84h
        _emit   0C3h
        jz      next_chan
mark_dead:
        movsx   ecx, word ptr [edi + 2]
        ; orig encodes `test bl, al` as 84 c3, MASM emits 84 d8.
        _emit   84h
        _emit   0C3h
        mov     byte ptr [ecx + esi + g_audioChannelTable + 0x17], 0
        mov     word ptr [edi], 0xffff
        jz      next_chan
        push    ebp
        call    Helper_AudioStop
        mov     al, byte ptr [esi + g_audioChannelTable + 0x16]
        add     esp, 4
        ; orig encodes `test bl, al` as 84 c3, MASM emits 84 d8.
        _emit   84h
        _emit   0C3h
        jne     next_chan
        push    ebp
        call    Helper_AudioRelease
        add     esp, 4
next_chan:
next_chan_long:
        add     edi, 4
        cmp     edi, offset g_audioChannelQueue + 0x40
        jl      chan_loop                            ; long form
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
#endif
