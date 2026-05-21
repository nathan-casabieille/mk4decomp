/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b09a0 (169b engine.ecm) - acquire/release critical section pair via IAT thunks.
 *   Cached: ebx=IAT[0x4d208c], ebp=IAT[0x4d2094], esi=IAT[0x4d2060], edi=IAT[0x4d2064].
 *   arg1 (al): if non-zero AND [0x7ab084]==0:
 *     [0x7ab07c] = IAT[0x4d2068](esi()); [0x7ab080] = IAT[0x4d206c](edi());
 *     ebp(2, ebx(esi(), 0x80)); if ([0x7ab06c] != 0): ebp([0x7ab06c], -2).
 *     [0x7ab084] = 1.
 *   arg2 ([esp+0x14] al): if zero AND [0x7ab084]!=0:
 *     ebp(edi([0x7ab080]), ebx(esi([0x7ab07c]))); [0x7ab084] = 0.
 */
__declspec(naked) void Helper_ECM_PostCleanup(void) {
    __asm {
        mov     al, byte ptr [esp + 4]
        push    ebx
        mov     ebx, dword ptr [g_iat_004d208c]
        push    ebp
        mov     ebp, dword ptr [g_iat_004d2094]
        push    esi
        mov     esi, dword ptr [g_iat_004d2060]
        push    edi
        mov     edi, dword ptr [g_iat_004d2064]
        test    al, al
        _emit   74h
        _emit   4eh
        mov     eax, dword ptr [g_x_007ab084]
        test    eax, eax
        _emit   75h
        _emit   45h
        call    esi
        push    eax
        call    dword ptr [g_iat_004d2068]
        mov     dword ptr [g_x_007ab07c], eax
        call    edi
        push    eax
        call    dword ptr [g_iat_004d206c]
        push    0x80
        mov     dword ptr [g_x_007ab080], eax
        call    esi
        push    eax
        call    ebx
        push    2
        call    edi
        push    eax
        call    ebp
        mov     eax, dword ptr [g_x_007ab06c]
        test    eax, eax
        _emit   74h
        _emit   05h
        push    0xfffffffe
        push    eax
        call    ebp
        mov     dword ptr [g_x_007ab084], 1
        mov     al, byte ptr [esp + 0x14]
        test    al, al
        _emit   75h
        _emit   2ah
        mov     eax, dword ptr [g_x_007ab084]
        test    eax, eax
        _emit   74h
        _emit   21h
        mov     eax, dword ptr [g_x_007ab07c]
        push    eax
        call    esi
        push    eax
        call    ebx
        mov     ecx, dword ptr [g_x_007ab080]
        push    ecx
        call    edi
        push    eax
        call    ebp
        mov     dword ptr [g_x_007ab084], 0
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}

