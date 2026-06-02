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
extern unsigned int g_iat_GetCurrentProcess;
extern unsigned int g_iat_GetCurrentThread;
extern unsigned int g_iat_GetPriorityClass;
extern unsigned int g_iat_GetThreadPriority;
extern unsigned int g_iat_SetPriorityClass;
extern unsigned int g_iat_SetThreadPriority;
extern HANDLE g_ecmThread;
extern unsigned int g_dispatchSave1606;
extern unsigned int g_dispatchSave1607;
extern unsigned int g_dispatchSave1608;

__declspec(naked) int Helper_ECM_PostCleanup(int flag) {
    __asm {
        mov     al, byte ptr [esp + 4]
        push    ebx
        mov     ebx, dword ptr [g_iat_SetPriorityClass]
        push    ebp
        mov     ebp, dword ptr [g_iat_SetThreadPriority]
        push    esi
        mov     esi, dword ptr [g_iat_GetCurrentProcess]
        push    edi
        mov     edi, dword ptr [g_iat_GetCurrentThread]
        test    al, al
        _emit   74h
        _emit   4eh
        mov     eax, dword ptr [g_dispatchSave1608]
        test    eax, eax
        _emit   75h
        _emit   45h
        call    esi
        push    eax
        call    dword ptr [g_iat_GetPriorityClass]
        mov     dword ptr [g_dispatchSave1606], eax
        call    edi
        push    eax
        call    dword ptr [g_iat_GetThreadPriority]
        push    0x80
        mov     dword ptr [g_dispatchSave1607], eax
        call    esi
        push    eax
        call    ebx
        push    2
        call    edi
        push    eax
        call    ebp
        mov     eax, dword ptr [g_ecmThread]
        test    eax, eax
        _emit   74h
        _emit   05h
        push    0xfffffffe
        push    eax
        call    ebp
        mov     dword ptr [g_dispatchSave1608], 1
        mov     al, byte ptr [esp + 0x14]
        test    al, al
        _emit   75h
        _emit   2ah
        mov     eax, dword ptr [g_dispatchSave1608]
        test    eax, eax
        _emit   74h
        _emit   21h
        mov     eax, dword ptr [g_dispatchSave1606]
        push    eax
        call    esi
        push    eax
        call    ebx
        mov     ecx, dword ptr [g_dispatchSave1607]
        push    ecx
        call    edi
        push    eax
        call    ebp
        mov     dword ptr [g_dispatchSave1608], 0
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}

