/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004c3e30 (118b engine.render) - DSound buffer descriptor
 *   build + vtable call: if g_dsoundPrimary (IDirectSound*) is null
 *   return 0; else preserve prior g_dispatchSave1410; build WAVEFORMATEX
 *   at 0x00f9eb70 (PCM, 2 channels, freq, 16-bit, 4-byte block) and
 *   call IDirectSound::CreateSoundBuffer (vt+0x38).
 */
extern unsigned int g_wavFmtTag;
extern unsigned int g_wavFmtChannels;
extern unsigned int g_wavFmtBlockAlign;
extern unsigned int g_wavFmtBitsPerSample;
extern unsigned int g_dispatchSave1410;
extern unsigned int g_dispatchSave1411;
extern void * g_dsoundPrimary;

__declspec(naked) void Helper_DSI_post2(void) {
    __asm {
        mov     eax, dword ptr [g_dsoundPrimary]
        push    esi
        xor     esi, esi
        test    eax, eax
        je      doneRet
        mov     esi, dword ptr [g_dispatchSave1410]
        xor     ecx, ecx
        mov     dword ptr [g_wavFmtTag], ecx
        mov     word ptr [g_wavFmtTag], 1
        mov     dword ptr [g_dispatchSave1410], ecx
        mov     word ptr [g_wavFmtChannels], 2
        mov     dword ptr [g_dispatchSave1411], ecx
        push    offset g_wavFmtTag
        mov     dword ptr [g_wavFmtBlockAlign], ecx
        mov     ecx, dword ptr [esp + 0xc]
        mov     dword ptr [g_dispatchSave1410], ecx
        mov     word ptr [g_wavFmtBitsPerSample], 0x10
        lea     edx, [ecx*4 + 0]
        mov     word ptr [g_wavFmtBlockAlign], 4
        mov     dword ptr [g_dispatchSave1411], edx
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x38]
doneRet:
        mov     eax, esi
        pop     esi
        ret
    }
}

