/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004ac780 (357b audio) - MIDI tempo/time-event pack&send.
 *   If g_data_00543904 != 0 or g_data_005438ec == 0 early-returns.
 *   Calls Helper_AuxAudio_PostInit. Then sends two MIDI events via two
 *   indirect IAT calls at [0x4d2244] (midiOutShortMsg-like):
 *     1) `0x80d` event with arg 0x400.
 *     2) Computes a time delta via reciprocal-multiplication divide chain:
 *        - tempo = (now - g_data_005438fc) * 0x10624dd3 → /1000
 *        - + g_data_005438f0 → tenths-of-seconds frame
 *        - /60 via 0x88888889 reciprocal → minutes, with remainder seconds
 *        - g_data_005438f4 /60 → hours, remainder minutes
 *        - packs (hh,mm,ss,ff) into ebp with `0x806` event arg
 *   Then if g_data_00543900 != 0 indirect-calls [0x4d2240] (timeGetTime-
 *   like), subtracts saved start time, accumulates into 0x5438fc and
 *   zeroes 0x543900.
 */
__declspec(naked) void Helper_TitleEnterStateA(void) {
    __asm {
        mov     eax, dword ptr [g_data_00543904]
        sub     esp, 0x18
        test    eax, eax
        push    ebx
        push    ebp
        push    esi
        push    edi
        mov     dword ptr [g_data_0054390c], 0
        jne     L_mtps_done
        mov     eax, dword ptr [g_data_005438ec]
        test    eax, eax
        je      L_mtps_done
        call    Helper_AuxAudio_PostInit
        mov     ebx, dword ptr [g_data_004d2240]
        test    eax, eax
        je      L_mtps_finalCheck
        mov     ecx, dword ptr [g_data_005438e8]
        mov     edi, dword ptr [g_data_004d2244]
        lea     eax, [esp + 0x1c]
        mov     dword ptr [esp + 0x20], 0xa
        push    eax
        push    0x400
        push    0x80d
        push    ecx
        call    edi
        mov     eax, dword ptr [g_data_00543900]
        test    eax, eax
        jne     short L_mtps_haveStart
        call    ebx
    L_mtps_haveStart:
        mov     ecx, dword ptr [g_data_005438fc]
        mov     esi, dword ptr [g_data_005438ec]
        sub     eax, ecx
        and     esi, 0xff
        cdq
        mov     ecx, eax
        mov     eax, 0x10624dd3
        xor     ecx, edx
        sub     ecx, edx
        imul    ecx
        mov     ecx, dword ptr [g_data_005438f0]
        sar     edx, 6
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        mov     eax, 0x88888889
        add     edx, ecx
        mov     ecx, edx
        imul    ecx
        add     edx, ecx
        sar     edx, 5
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        mov     eax, ecx
        mov     ebp, edx
        mov     ecx, 0x3c
        cdq
        idiv    ecx
        mov     ecx, dword ptr [g_data_005438f4]
        xor     eax, eax
        and     ebp, 0xffff
        mov     ah, dl
        or      ebp, eax
        mov     eax, 0x88888889
        imul    ecx
        add     edx, ecx
        sar     edx, 5
        mov     eax, edx
        shl     ebp, 8
        shr     eax, 0x1f
        or      ebp, esi
        add     edx, eax
        mov     dword ptr [esp + 0x14], ebp
        mov     eax, ecx
        mov     ebp, edx
        mov     ecx, 0x3c
        cdq
        idiv    ecx
        xor     eax, eax
        and     ebp, 0xffff
        lea     ecx, [esp + 0x10]
        push    ecx
        push    0xc
        push    0x806
        mov     ah, dl
        mov     edx, dword ptr [g_data_005438e8]
        or      ebp, eax
        push    edx
        shl     ebp, 8
        or      ebp, esi
        mov     dword ptr [esp + 0x28], ebp
        call    edi
        neg     eax
        sbb     eax, eax
        inc     eax
        mov     dword ptr [g_data_00543904], eax
    L_mtps_finalCheck:
        mov     eax, dword ptr [g_data_00543900]
        test    eax, eax
        je      short L_mtps_done
        call    ebx
        mov     edx, dword ptr [g_data_00543900]
        mov     ecx, dword ptr [g_data_005438fc]
        sub     eax, edx
        mov     dword ptr [g_data_00543900], 0
        add     ecx, eax
        mov     dword ptr [g_data_005438fc], ecx
    L_mtps_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x18
        ret
    }
}

