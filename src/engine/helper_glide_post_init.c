/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b5010 (134b engine.geo) - mode switch:
 *   If g_x_004f4b50 == arg1: return.
 *   If g_x_004f4b50 == -1 and arg1 == 0: return.
 *   Store arg1; if arg1 == 0: tail-call clean-up (set window mode); ret 1.
 *   Else: call setup; if user mode == 1: re-call setup; return 1; else return 0.
 */
int Helper_GlidePostInit(void) {
    __asm {
        mov     ecx, dword ptr [g_x_004f4b50]
        mov     eax, dword ptr [esp + 4]
        cmp     ecx, eax
        _emit   74h
        _emit   72h
        cmp     ecx, 0xffffffff
        _emit   75h
        _emit   04h
        test    eax, eax
        _emit   74h
        _emit   69h
        test    eax, eax
        mov     dword ptr [g_x_004f4b50], eax
        _emit   74h
        _emit   3fh
        push    offset g_x_007aff48
        call    dword ptr [g_iat_004d21ac]
        push    0
        call    dword ptr [g_iat_004d219c]
        call    DSoundSetAxisPan123_004b50a0
        push    0
        push    2
        push    0
        push    0
        push    0
        push    7
        push    0
        call    dword ptr [g_iat_indirect_007b0054]
        cmp     eax, 1
        _emit   74h
        _emit   03h
        xor     eax, eax
        ret
        call    DSoundSetAxisPan123_004b50a0
        mov     eax, 1
        ret
        call    dword ptr [g_iat_indirect_007b0050]
        mov     eax, dword ptr [g_x_007aff4c]
        mov     ecx, dword ptr [g_x_007aff48]
        push    eax
        push    ecx
        call    dword ptr [g_iat_004d21a4]
        push    1
        call    dword ptr [g_iat_004d219c]
        mov     eax, 1
        }
}

