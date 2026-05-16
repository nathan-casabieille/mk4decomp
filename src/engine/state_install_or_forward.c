/**
 * 2 "state install + tail-jmp or forward" helpers (33 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_state]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .forward
 *   jmp     T_default
 * .forward:
 *   mov     eax, [esp+4]
 *   push    eax
 *   call    T_forward
 *   add     esp, 4
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;

extern void CallSetPause_0041f830(void);
extern void ArgSarAddDerefJmp_0048e710(int);

/* @addr 0x0048e6b0 */
__declspec(naked) void StateInstallOrForward_0048e6b0(void) {
    __asm {
        mov     eax, dword ptr [g_active_0053a408]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     CallSetPause_0041f830
        mov     eax, dword ptr [esp + 4]
        push    eax
        call    ArgSarAddDerefJmp_0048e710
        add     esp, 4
        ret
    }
}

/* @addr 0x0048e6e0 */
__declspec(naked) void StateInstallOrForward_0048e6e0(void) {
    __asm {
        mov     eax, dword ptr [g_active_00537e88]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     CallSetPause_0041f830
        mov     eax, dword ptr [esp + 4]
        push    eax
        call    ArgSarAddDerefJmp_0048e710
        add     esp, 4
        ret
    }
}
