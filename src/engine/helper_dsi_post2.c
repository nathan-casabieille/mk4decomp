/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004c3e30 (118b engine.render) - DSound buffer descriptor
 *   build + vtable call: if g_dsoundPrimary (IDirectSound*) is null
 *   return 0; else preserve prior g_x_00f9eb74; build WAVEFORMATEX
 *   at 0x00f9eb70 (PCM, 2 channels, freq, 16-bit, 4-byte block) and
 *   call IDirectSound::CreateSoundBuffer (vt+0x38).
 */
extern unsigned int g_word_00f9eb70;
extern unsigned int g_word_00f9eb72;
extern unsigned int g_word_00f9eb7c;
extern unsigned int g_word_00f9eb7e;
extern unsigned int g_x_00f9eb74;
extern unsigned int g_x_00f9eb78;
extern void * g_dsoundPrimary;

__declspec(naked) void Helper_DSI_post2(void) {
    __asm {
        mov     eax, dword ptr [g_dsoundPrimary]
        push    esi
        xor     esi, esi
        test    eax, eax
        je      doneRet
        mov     esi, dword ptr [g_x_00f9eb74]
        xor     ecx, ecx
        mov     dword ptr [g_word_00f9eb70], ecx
        mov     word ptr [g_word_00f9eb70], 1
        mov     dword ptr [g_x_00f9eb74], ecx
        mov     word ptr [g_word_00f9eb72], 2
        mov     dword ptr [g_x_00f9eb78], ecx
        push    offset g_word_00f9eb70
        mov     dword ptr [g_word_00f9eb7c], ecx
        mov     ecx, dword ptr [esp + 0xc]
        mov     dword ptr [g_x_00f9eb74], ecx
        mov     word ptr [g_word_00f9eb7e], 0x10
        lea     edx, [ecx*4 + 0]
        mov     word ptr [g_word_00f9eb7c], 4
        mov     dword ptr [g_x_00f9eb78], edx
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x38]
doneRet:
        mov     eax, esi
        pop     esi
        ret
    }
}

