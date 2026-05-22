/**
 * ECM playback worker thread.
 *
 * Reads frames from the open ECM file in blocks, ECM_DecodeFrame's
 * each, and feeds the audio sub-stream into the streaming
 * IDirectSoundBuffer via Lock/copy/Unlock. On lost-buffer errors,
 * restores the buffer via Restore + Play before re-locking. The
 * thread "yields" each pass by setting g_ecmThreadStatus = 0 and
 * SuspendThread'ing itself; the calling driver resumes it when more
 * playback is needed.
 */
#include "engine/ecm.h"
#include "audio/sound.h"   /* Helper_FRead */

extern s32 ESF_DecodeADPCM_Wrapper(s32 a, s32 b, s32 c, s32 d);  /* 0x004ac200 - ESF_DecodeADPCM */

extern void *g_iat_SuspendThread;   /* 0x004d2090 */

/*
 * @addr 0x004b0a50
 *
extern unsigned int g_ecmDSBuffer;

 * Naked + __asm: thread infinite-loop with a "yield" suspend at
 * the bottom (cannot exit normally), magic-divide-by-8 frame
 * offset lookup with cdq+xor+sub idiom for unsigned mod-4, plus
 * IDirectSoundBuffer Lock/Unlock/Restore/Play vtable calls and
 * a rep-stosd zero-clear on the locked buffer when restoring a
 * lost surface. Pure C wouldn't compose identically.
 */

__declspec(naked) DWORD __stdcall ECM_PlayThread(LPVOID param)
{
    __asm {
        sub     esp, 0x10
        push    ebx
        push    ebp
        push    esi
        xor     esi, esi
        push    edi
        mov     ebx, 1
        mov     dword ptr [esp + 0x1c], esi
        mov     ebp, -2
loop_top_entry:
        mov     eax, dword ptr [g_ecmPlayState]
        mov     dword ptr [g_ecmThreadStatus], 1
        cmp     eax, esi
        jne     do_yield
loop_top_body:
        mov     eax, dword ptr [g_ecmFrameTotal]
        mov     ecx, dword ptr [g_ecmFrameIdx]
        sub     ecx, eax
        cmp     ecx, 3
        jge     do_yield
        cmp     ebx, dword ptr [g_ecmHeaderBuf + 4]
        jg      do_yield
        lea     ecx, [ebx - 1]
        mov     eax, 0x88888889
        imul    ecx
        add     edx, ecx
        sar     edx, 3
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        mov     edx, dword ptr [edx*4 + g_ecmHeaderBuf + 8]
        cmp     edx, 0x5ab5c
        ja      err_pre_minus_one
        mov     ecx, dword ptr [g_ecmFile]
        push    ecx
        push    1
        push    edx
        push    offset g_ecmInputBuf
        call    Helper_FRead
        add     esp, 0x10
        cmp     eax, 1
        jne     err_pre_minus_one
        mov     eax, dword ptr [g_ecmFrameIdx]
        inc     eax
        cdq
        xor     eax, edx
        sub     eax, edx
        and     eax, 3
        xor     eax, edx
        sub     eax, edx
        mov     edx, dword ptr [g_ecmInputBuf]
        imul    eax, eax, 0x5ab5c
        mov     dword ptr [eax + g_ecmVideoSlots], edx
        mov     eax, dword ptr [g_ecmFrameIdx]
        inc     eax
        cdq
        xor     eax, edx
        sub     eax, edx
        and     eax, 3
        xor     eax, edx
        sub     eax, edx
        imul    eax, eax, 0x5ab5c
        add     eax, offset g_ecmAudioSlots
        push    eax
        push    offset g_ecmDecodeBuf
        call    ECM_DecodeFrame
        add     esp, 8
        cmp     eax, 0x58044
        jne     err_pre_minus_two
        mov     eax, dword ptr [g_ecmHeaderBuf + 4]
        add     ebx, 0xf
        cmp     ebx, eax
        jle     SHORT after_state_check
        lea     ebx, [eax + 1]
        jmp     SHORT after_state_check
err_pre_minus_two:
        mov     dword ptr [g_ecmPlayState], ebp
        jmp     SHORT after_state_check
err_pre_minus_one:
        mov     dword ptr [g_ecmPlayState], -1
after_state_check:
        cmp     dword ptr [g_ecmPlayState], esi
        jne     after_dsound_long
        mov     edi, dword ptr [g_ecmDSBuffer]
        cmp     edi, esi
        je      after_dsound_long
        push    esi
        push    esi
        lea     eax, [esp + 0x1c]
        push    esi
        push    eax
        mov     eax, dword ptr [g_ecmHeaderBuf + 4]
        lea     edx, [esp + 0x20]
        inc     eax
        push    edx
        mov     dword ptr [esp + 0x24], esi
        cdq
        xor     eax, edx
        mov     dword ptr [esp + 0x28], esi
        mov     ecx, dword ptr [edi]
        sub     eax, edx
        and     eax, 3
        mov     dword ptr [esp + 0x2c], ecx
        xor     eax, edx
        push    0xac44
        sub     eax, edx
        lea     ecx, [eax + eax*2]
        shl     ecx, 4
        add     ecx, eax
        lea     eax, [ecx + ecx*4]
        mov     ecx, dword ptr [esp + 0x30]
        lea     eax, [eax + eax*4]
        lea     eax, [eax + eax*8]
        shl     eax, 2
        push    eax
        push    edi
        call    dword ptr [ecx + 0x2c]
        cmp     eax, 0x88780096
        jne     SHORT not_lost
        mov     eax, dword ptr [g_ecmDSBuffer]
        push    eax
        mov     edx, dword ptr [eax]
        call    dword ptr [edx + 0x50]
        mov     eax, dword ptr [g_ecmDSBuffer]
        push    eax
        mov     ecx, dword ptr [eax]
        call    dword ptr [ecx + 0x48]
        mov     eax, dword ptr [g_ecmDSBuffer]
        push    2
        push    esi
        lea     ecx, [esp + 0x1c]
        mov     edx, dword ptr [eax]
        push    esi
        push    ecx
        lea     ecx, [esp + 0x20]
        push    ecx
        push    esi
        push    esi
        push    eax
        call    dword ptr [edx + 0x2c]
        mov     edi, dword ptr [esp + 0x10]
        cmp     edi, esi
        je      SHORT skip_zero
        mov     ecx, dword ptr [esp + 0x14]
        cmp     ecx, esi
        je      SHORT skip_zero
        mov     edx, ecx
        xor     eax, eax
        shr     ecx, 2
        rep     stosd
        mov     ecx, edx
        and     ecx, 3
        rep     stosb
        mov     edi, dword ptr [esp + 0x10]
skip_zero:
        mov     eax, dword ptr [g_ecmDSBuffer]
        mov     edx, dword ptr [esp + 0x14]
        push    esi
        push    esi
        mov     ecx, dword ptr [eax]
        push    edx
        push    edi
        push    eax
        call    dword ptr [ecx + 0x4c]
        jmp     SHORT after_dsound_short
not_lost:
        mov     ecx, dword ptr [esp + 0x10]
        cmp     ecx, esi
        je      SHORT after_unlock
        cmp     dword ptr [esp + 0x14], 0xac44
        jb      SHORT after_unlock
        lea     edx, [esp + 0x1c]
        push    edx
        push    0xac44
        push    ecx
        push    offset g_ecmInputBufBody
        call    ESF_DecodeADPCM_Wrapper
        mov     ecx, dword ptr [esp + 0x20]
        add     esp, 0x10
after_unlock:
        mov     eax, dword ptr [g_ecmDSBuffer]
        mov     edi, dword ptr [esp + 0x14]
        push    esi
        push    esi
        mov     edx, dword ptr [eax]
        push    edi
        push    ecx
        push    eax
        call    dword ptr [edx + 0x4c]
after_dsound_short:
after_dsound_long:
        mov     eax, dword ptr [g_ecmFrameIdx]
        inc     eax
        mov     dword ptr [g_ecmFrameIdx], eax
        mov     eax, dword ptr [g_ecmPlayState]
        cmp     eax, esi
        je      loop_top_body
do_yield:
        mov     eax, dword ptr [g_ecmThread]
        mov     dword ptr [g_ecmThreadStatus], esi
        cmp     eax, esi
        je      loop_top_entry
        push    eax
        call    dword ptr [g_iat_SuspendThread]
        jmp     loop_top_entry
    }
}
