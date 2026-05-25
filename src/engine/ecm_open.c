/**
 * ECM_Open: prepare a streamed cinematic for playback.
 *
 * Opens the .ecm file in "rb" mode, reads its 0xe18-byte header
 * into g_ecmHeaderBuf, validates the magic ('E','C','M',2) and
 * frame count, builds a WAVEFORMATEX (44100 Hz / 2 ch / 16 bit)
 * via stack scratch, calls IDirectSound::CreateSoundBuffer to
 * allocate a streaming buffer, applies the requested volume in dB
 * via log10/log2 + _ftol, then seeks to the requested start-frame
 * and CreateThread's the play worker. Polls the worker via Sleep
 * until it reports "alive" or 3 seconds pass.
 */
#include "engine/ecm.h"
#include "audio/sound.h"   /* Helper_FOpen, Helper_FRead, Helper_FSeek, _ftol */

extern const char $SG_rb[];   /* "rb" - shared with ValidateInstall */

/*
 * @addr 0x004b06f0
 *
extern void ECM_PlayThread(void);

 * Naked + __asm: SEH-style stack-built struct setup, FP volume
 * curve (fldlg2 + fyl2x + fmul + fcom + clamp), COM vtable calls
 * via [edx + 0x0c/0x34/0x44/0x40/0x3c], magic-divide-by-8 frame-
 * offset computation, and IAT-style indirect calls to CreateThread
 * and Sleep. None of this composes naturally as pure C.
 */

__declspec(naked) u32 ECM_Open(const char *filename, void *dsound_iface,
                                u32 unused, u32 frame_skip)
{
    __asm {
        sub     esp, 0x24
        push    ebx
        push    ebp
        push    esi
        push    edi
        call    ECM_Cleanup
        mov     edi, dword ptr [esp + 0x44]
        mov     ebx, 1
        xor     ebp, ebp
        cmp     edi, ebx
        mov     dword ptr [g_ecmPlayState], ebp
        jge     SHORT have_skip
        mov     edi, ebx
have_skip:
        mov     eax, dword ptr [esp + 0x38]
        push    offset $SG_rb
        push    eax
        call    Helper_FOpen
        add     esp, 8
        cmp     eax, ebp
        mov     dword ptr [g_ecmFile], eax
        je      fail_long
        push    eax
        push    ebx
        push    0xe18
        push    offset g_ecmHeaderBuf
        call    Helper_FRead
        add     esp, 0x10
        cmp     eax, ebx
        jne     fail_long
        mov     ecx, dword ptr [g_ecmFile]
        test    byte ptr [ecx + 0xc], 0x20
        jne     fail_long
        cmp     dword ptr [g_ecmHeaderBuf], 0x024d4345
        jne     fail_long
        cmp     edi, dword ptr [g_ecmHeaderBuf + 4]
        jb      SHORT have_frame_count
        call    ECM_Cleanup
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x24
        ret
have_frame_count:
        mov     eax, dword ptr [esp + 0x3c]
        xor     edx, edx
        xor     ecx, ecx
        mov     dword ptr [esp + 0x10], edx
        mov     dword ptr [esp + 0x20], ecx
        mov     dword ptr [esp + 0x14], edx
        mov     dword ptr [esp + 0x24], ecx
        mov     dword ptr [esp + 0x18], edx
        mov     dword ptr [esp + 0x28], ecx
        mov     dword ptr [esp + 0x1c], edx
        mov     dword ptr [esp + 0x2c], ecx
        lea     edx, [esp + 0x10]
        xor     esi, esi
        mov     dword ptr [esp + 0x30], ecx
        cmp     eax, ebp
        mov     dword ptr [g_ecmDsContext], eax
        mov     word ptr [esp + 0x10], bx
        mov     word ptr [esp + 0x12], bx
        mov     dword ptr [esp + 0x14], 0x5622
        mov     word ptr [esp + 0x1e], 0x10
        mov     word ptr [esp + 0x1c], 2
        mov     dword ptr [esp + 0x18], 0xac44
        mov     dword ptr [esp + 0x20], 0x14
        mov     dword ptr [esp + 0x24], 0x100e0
        mov     dword ptr [esp + 0x28], 0x2b110
        mov     dword ptr [esp + 0x30], edx
        mov     dword ptr [g_ecmDSBuffer], esi
        je      SHORT skip_dsound
        mov     ecx, dword ptr [eax]
        push    ebp
        lea     edx, [esp + 0x24]
        push    offset g_ecmDSBuffer
        push    edx
        push    eax
        call    dword ptr [ecx + 0xc]
        mov     esi, dword ptr [g_ecmDSBuffer]
skip_dsound:
        cmp     esi, ebp
        je      compute_offset
        movsx   eax, byte ptr [esp + 0x40]
        fldlg2
        mov     dword ptr [esp + 0x40], eax
        fild    dword ptr [esp + 0x40]
        fmul    qword ptr [k_ecmC1]
        fyl2x
        fmul    qword ptr [k_ecmC2]
        fcom    qword ptr [k_ecmC3]
        fnstsw  ax
        test    ah, 1
        je      SHORT not_too_high
        fstp    st(0)
        fld     qword ptr [k_ecmC3]
        jmp     SHORT after_clamp
not_too_high:
        fcom    qword ptr [k_ecmC4]
        fnstsw  ax
        test    ah, 0x41
        jne     SHORT after_clamp
        fstp    st(0)
        fld     qword ptr [k_ecmC4]
after_clamp:
        call    _ftol
        mov     dword ptr [g_ecmVolumeFromFtol], eax
        mov     ecx, dword ptr [esi]
        push    ebp
        push    esi
        call    dword ptr [ecx + 0x34]
        mov     eax, dword ptr [g_ecmDSBuffer]
        push    ebp
        push    eax
        mov     edx, dword ptr [eax]
        call    dword ptr [edx + 0x44]
        mov     eax, dword ptr [g_ecmDSBuffer]
        push    ebp
        push    eax
        mov     ecx, dword ptr [eax]
        call    dword ptr [ecx + 0x40]
        mov     eax, dword ptr [g_ecmDSBuffer]
        mov     ecx, dword ptr [g_ecmVolumeFromFtol]
        push    ecx
        push    eax
        mov     edx, dword ptr [eax]
        call    dword ptr [edx + 0x3c]
compute_offset:
        lea     ecx, [edi - 1]
        mov     eax, 0x88888889
        imul    ecx
        add     edx, ecx
        mov     dword ptr [g_ecmFrameSizeDiv8], ecx
        sar     edx, 3
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        je      SHORT after_seek
        xor     eax, eax
        cmp     edx, ebp
        jle     SHORT seek_check
        mov     ecx, offset g_ecmHeaderBuf + 8
sum_offsets:
        mov     esi, dword ptr [ecx]
        add     ecx, 4
        add     eax, esi
        dec     edx
        jne     SHORT sum_offsets
seek_check:
        cmp     eax, ebp
        jle     SHORT after_seek
        mov     ecx, dword ptr [g_ecmFile]
        push    ebx
        push    eax
        push    ecx
        call    Helper_FSeek
        add     esp, 0xc
after_seek:
        push    offset g_ecmThreadIdOut
        push    ebp
        push    ebp
        push    offset ECM_PlayThread
        push    ebp
        push    ebp
        mov     dword ptr [g_ecmReserved], ebp
        mov     dword ptr [g_ecmRunFlag], ebx
        mov     dword ptr [g_ecmFrameIdx], -1
        mov     dword ptr [g_ecmFrameTotal], ebp
        mov     dword ptr [g_ecmThreadStatus], ebx
        call    dword ptr [g_iat_CreateThread]
        cmp     eax, ebp
        mov     dword ptr [g_ecmThread], eax
        jne     SHORT have_thread
        mov     dword ptr [g_ecmThreadStatus], ebp
        call    ECM_Cleanup
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x24
        ret
have_thread:
        push    ebx
        call    Helper_ECM_PostCleanup
        mov     eax, dword ptr [g_ecmThreadStatus]
        add     esp, 4
        xor     esi, esi
        cmp     eax, ebp
        je      SHORT thread_done
        mov     edi, dword ptr [g_iat_Sleep]
poll_loop:
        cmp     esi, 0xbb8
        jge     SHORT fail_long
        push    0x64
        call    edi
        mov     eax, dword ptr [g_ecmThreadStatus]
        add     esi, 0x64
        cmp     eax, ebp
        jne     SHORT poll_loop
thread_done:
        cmp     esi, 0xbb8
        jl      SHORT good_exit
fail_long:
        call    ECM_Cleanup
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x24
        ret
good_exit:
        mov     eax, dword ptr [g_ecmHeaderBuf + 4]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x24
        ret
    }
}
