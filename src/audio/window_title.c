/**
 * Per-frame window-title and audio-state synchronizer.
 *
 * Compares 8 (mode, sub-mode) pairs against the previous frame's
 * snapshot; if anything differs, re-issues SetWindowTextA, fires
 * a handful of audio-state helpers depending on which transition
 * happened, then writes back the snapshot. The 8 snapshot slots
 * are contiguous at 0x004f4ad0..0x004f4aec (g_titleSaved[]); the
 * "current" values are scattered across the data segment.
 */
#include "audio/sound.h"
#include "platform/win32.h"

static const char $SG_titleWaiting[] = "Mortal Kombat 4 - Waiting";
static const char $SG_titleDemo[]    = "Mortal Kombat 4 - Demo Mode";
static const char $SG_titleNormal[]  = "Mortal Kombat 4";

/*
 * @addr 0x004b22e0
 *
 * Naked + __asm: the 8-pair comparison cascade reuses the loaded
 * eax (= g_titleSub) across the cmps in a way pure C wouldn't,
 * and the long-form jl + setne idioms in the tail don't survive
 * MSVC's natural scheduler.
 */
__declspec(naked) void UpdateWindowTitle(void)
{
    __asm {
        mov     ecx, dword ptr [g_titleHwnd]
        push    esi
        test    ecx, ecx
        je      done
        mov     eax, dword ptr [g_titleSaved + 0]
        mov     edx, dword ptr [g_titleMode]
        cmp     eax, edx
        mov     eax, dword ptr [g_titleSub]
        jne     SHORT changed
        mov     edx, dword ptr [g_titleSaved + 4]
        mov     esi, dword ptr [g_titleSlot]
        cmp     edx, esi
        jne     SHORT changed
        cmp     dword ptr [g_titleSaved + 8], eax
        jne     SHORT changed
        mov     edx, dword ptr [g_titleSaved + 0xc]
        mov     esi, dword ptr [g_titlePauseGate]
        cmp     edx, esi
        jne     SHORT changed
        mov     edx, dword ptr [g_titleSaved + 0x10]
        mov     esi, dword ptr [g_titleStateE]
        cmp     edx, esi
        jne     SHORT changed
        mov     edx, dword ptr [g_titleSaved + 0x14]
        mov     esi, dword ptr [g_titleStateF]
        cmp     edx, esi
        jne     SHORT changed
        mov     edx, dword ptr [g_titleSaved + 0x18]
        mov     esi, dword ptr [g_titleStateG]
        cmp     edx, esi
        jne     SHORT changed
        mov     edx, dword ptr [g_titleSaved + 0x1c]
        mov     esi, dword ptr [g_titleStateH]
        cmp     edx, esi
        je      done
changed:
        test    eax, eax
        je      SHORT skip_reset
        call    Helper_TitleAudioReset
        mov     ecx, dword ptr [g_titleHwnd]
        mov     eax, dword ptr [g_titleSub]
skip_reset:
        cmp     dword ptr [g_titleMode], 2
        jl      waiting_path
        mov     edx, dword ptr [g_titleSlot]
        test    edx, edx
        jne     waiting_path
        test    eax, eax
        ; orig short-form jne (75 7d); MASM picks long-form for
        ; forward jcc, so _emit the short-form bytes directly.
        _emit   75h
        _emit   7dh
        mov     eax, dword ptr [g_titlePauseGate]
        test    eax, eax
        mov     eax, offset $SG_titleNormal
        jne     SHORT have_title
        mov     eax, offset $SG_titleDemo
have_title:
        push    eax
        push    ecx
        call    dword ptr [g_iat_SetWindowTextA]
        mov     eax, dword ptr [g_titleAudioFlag]
        test    eax, eax
        mov     eax, dword ptr [g_titleStateE]
        jne     SHORT do_audio_path
        cmp     eax, dword ptr [g_titleSaved + 0x10]
        je      SHORT skip_audio_path
do_audio_path:
        test    eax, eax
        je      SHORT use_fresh
        call    Helper_AudioStart
        jmp     SHORT skip_audio_path
use_fresh:
        call    Helper_AudioStartFresh
skip_audio_path:
        mov     eax, dword ptr [g_titleAudioFlag]
        test    eax, eax
        mov     eax, dword ptr [g_titleStateF]
        jne     SHORT do_state_path
        cmp     eax, dword ptr [g_titleSaved + 0x14]
        je      SHORT after_state
do_state_path:
        test    eax, eax
        je      SHORT use_state_b
        call    Helper_TitleEnterStateA
        mov     dword ptr [g_titleAudioFlag], 0
        jmp     SHORT after_volumes
use_state_b:
        call    Helper_TitleEnterStateB
after_state:
        mov     dword ptr [g_titleAudioFlag], 0
        jmp     SHORT after_volumes
waiting_path:
        push    offset $SG_titleWaiting
        push    ecx
        call    dword ptr [g_iat_SetWindowTextA]
        cmp     dword ptr [g_titleMode], 2
        jl      enter_waiting
        mov     eax, dword ptr [g_titleSlot]
        test    eax, eax
        je      SHORT after_volumes
enter_waiting:
        mov     dword ptr [g_titleAudioFlag], 1
        call    Helper_TitleEnterStateC
        call    Helper_TitleAudioStop
        mov     eax, dword ptr [g_titleAudioState]
        test    eax, eax
        je      SHORT after_volumes
        call    Helper_TitleAudioCleanup
after_volumes:
        mov     eax, dword ptr [g_titleStateG]
        mov     ecx, dword ptr [g_titleSaved + 0x18]
        cmp     ecx, eax
        je      SHORT skip_max_vol
        push    eax
        call    Helper_TitleSetMaxVolume
        add     esp, 4
skip_max_vol:
        mov     eax, dword ptr [g_titleStateH]
        mov     ecx, dword ptr [g_titleSaved + 0x1c]
        cmp     ecx, eax
        je      SHORT do_snapshot
        and     eax, 0xff
        push    eax
        call    AuxAudio_SetVolume
        mov     eax, dword ptr [g_titleStateH]
        add     esp, 4
do_snapshot:
        mov     ecx, dword ptr [g_titleMode]
        mov     edx, dword ptr [g_titleSlot]
        mov     dword ptr [g_titleSaved + 0], ecx
        mov     ecx, dword ptr [g_titleSub]
        mov     dword ptr [g_titleSaved + 4], edx
        mov     edx, dword ptr [g_titlePauseGate]
        mov     dword ptr [g_titleSaved + 8], ecx
        mov     ecx, dword ptr [g_titleStateE]
        mov     dword ptr [g_titleSaved + 0xc], edx
        mov     edx, dword ptr [g_titleStateF]
        mov     dword ptr [g_titleSaved + 0x10], ecx
        mov     ecx, dword ptr [g_titleStateG]
        mov     dword ptr [g_titleSaved + 0x14], edx
        mov     dword ptr [g_titleSaved + 0x18], ecx
        mov     dword ptr [g_titleSaved + 0x1c], eax
done:
        pop     esi
        ret
    }
}
