/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004ac650 (290b audio) - MIDI MCI playback position setter.
 *   Calls Audio_TimerTeardown. Saves 4 args into globals (5438f8/ec/f0/f4).
 *   If 0x54390c non-zero or PostInit fails or already-init flag 0x543904 set:
 *     skip to timeGetTime tail. Else build MCI packet with mciSendCommandA
 *     (cmd 0x80d MCI_SET, 0x806 MCI_PLAY); convert esi/edi via /60 divmod
 *     using 0x88888889 reciprocal-mul to TMSF (mins:secs:frames) format.
 *     Set flag 0x543904 on success. Tail-call timeGetTime via IAT[0x4d2240];
 *     save in 0x5438fc.
 */
extern u32 g_timerActive;
extern u32 g_timerStartSec;
extern u32 g_timerEndSec;
extern u32 g_timerHandle;
extern u32 g_timerLastNow;
extern u32 g_timerFlag;
extern u32 g_audioState0C;
extern unsigned int g_iat_004d2240;
extern unsigned int g_iat_004d2244;
extern u32 g_audioPreState;
extern void Audio_TimerTeardown_004ac5f0(void);
extern void Helper_AuxAudio_PostInit(void);

__declspec(naked) void Audio_TimerSet(void) {
    __asm {
        sub     esp, 0x18
        push    ebx
        push    esi
        push    edi
        call    Audio_TimerTeardown_004ac5f0
        mov     eax, [esp + 0x34]
        mov     ebx, [esp + 0x28]
        mov     esi, [esp + 0x2c]
        mov     edi, [esp + 0x30]
        mov     dword ptr [g_timerHandle], eax
        mov     eax, dword ptr [g_audioState0C]
        test    eax, eax
        mov     dword ptr [g_timerActive], ebx
        mov     dword ptr [g_timerStartSec], esi
        mov     dword ptr [g_timerEndSec], edi
        jne     L_mp_tailCall
        call    Helper_AuxAudio_PostInit
        test    eax, eax
        jz      L_mp_tailCall
        mov     eax, dword ptr [g_timerFlag]
        test    eax, eax
        jne     L_mp_tailCall
        mov     edx, dword ptr [g_audioPreState]
        lea     ecx, [esp + 0x18]
        push    ebp
        mov     ebp, dword ptr [g_iat_004d2244]
        push    ecx
        push    0x400
        push    0x80d
        push    edx
        mov     dword ptr [esp + 0x30], 0x0a
        call    ebp
        mov     eax, 0x88888889
        mov     ecx, ebx
        imul    esi
        add     edx, esi
        and     ecx, 0xff
        sar     edx, 5
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
        mov     eax, esi
        mov     ebx, edx
        mov     esi, 60
        cdq
        idiv    esi
        xor     eax, eax
        and     ebx, 0xffff
        mov     ah, dl
        or      ebx, eax
        mov     eax, 0x88888889
        imul    edi
        add     edx, edi
        sar     edx, 5
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
        mov     eax, edi
        mov     esi, edx
        mov     edi, 60
        cdq
        idiv    edi
        xor     eax, eax
        and     esi, 0xffff
        shl     ebx, 8
        or      ebx, ecx
        mov     [esp + 0x14], ebx
        mov     ah, dl
        mov     edx, dword ptr [g_audioPreState]
        or      esi, eax
        shl     esi, 8
        or      esi, ecx
        lea     ecx, [esp + 0x10]
        push    ecx
        push    0xc
        push    0x806
        push    edx
        mov     [esp + 0x28], esi
        call    ebp
        neg     eax
        sbb     eax, eax
        pop     ebp
        inc     eax
        mov     dword ptr [g_timerFlag], eax
    L_mp_tailCall:
        call    dword ptr [g_iat_004d2240]
        pop     edi
        pop     esi
        mov     dword ptr [g_timerLastNow], eax
        pop     ebx
        add     esp, 0x18
        ret
    }
}

