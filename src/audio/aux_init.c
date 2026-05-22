/**
 * Auxiliary-audio init: zero the timer/state globals, enumerate
 * aux-out devices, and snapshot each device's current volume.
 */
#include "audio/sound.h"
#include "platform/win32.h"
#include <mmsystem.h>

/*
 * @addr 0x004ac8f0
 *
extern unsigned int g_auxChannels;

 * Naked + __asm: the prologue zeros 10 globals via xor edi + 89 3d
 * (5 bytes / store) instead of c7 imm32 (10 bytes / store) - MSVC
 * SP3 won't reuse a single zeroed register that aggressively from C.
 * Loop body uses cached IAT pointers in edi (auxGetDevCapsA) and
 * ebp (auxGetVolume) to avoid reloading the IAT each iteration.
 */

__declspec(naked) s32 AuxAudio_Init(HWND hwnd)
{
    __asm {
        mov     eax, dword ptr [esp + 4]            ; hwnd
        sub     esp, 0x30                           ; AUXCAPSA local
        mov     dword ptr [g_auxAudioHwnd], eax
        push    ebx
        push    ebp
        push    esi
        push    edi
        xor     edi, edi
        mov     dword ptr [g_timerFlag],     edi
        mov     dword ptr [g_audioState00],  edi
        mov     dword ptr [g_timerLastNow],  edi
        mov     dword ptr [g_timerHandle],   edi
        mov     dword ptr [g_timerEndSec],   edi
        mov     dword ptr [g_timerStartSec], edi
        mov     dword ptr [g_audioState08],  edi
        mov     dword ptr [g_timerActive],   edi
        mov     dword ptr [g_audioPreState], edi
        mov     dword ptr [g_audioState0C],  edi
        call    dword ptr [auxGetNumDevs]
        mov     esi, eax
        mov     dword ptr [g_auxCount], edi
        dec     esi
        js      done
        mov     edi, dword ptr [auxGetDevCapsA]
        mov     ebp, dword ptr [auxGetVolume]
        mov     bl, 3
loop_top:
        cmp     dword ptr [g_auxCount], 8
        jge     done
        lea     ecx, [esp + 0x10]                   ; &caps
        push    0x30                                ; sizeof(AUXCAPSA)
        push    ecx
        push    esi
        call    edi                                  ; auxGetDevCapsA
        test    byte ptr [esp + 0x38], bl           ; caps.wTechnology & 3
        jz      next_dev
        mov     eax, dword ptr [g_auxCount]
        lea     edx, [eax*8 + g_auxChannels + 4]   ; &g_auxChannels[i]._pad
        mov     dword ptr [eax*8 + g_auxChannels], esi  ; .deviceId = esi
        push    edx
        push    esi
        call    ebp                                  ; auxGetVolume
        inc     dword ptr [g_auxCount]
next_dev:
        dec     esi
        jns     loop_top
done:
        call    Helper_AuxAudio_PostInit
        pop     edi
        pop     esi
        pop     ebp
        mov     eax, 1
        pop     ebx
        add     esp, 0x30
        ret
    }
}
