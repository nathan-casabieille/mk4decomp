/**
 * 2 "triple test+install with three jmp targets" helpers (83b).
 *
 * Pattern:
 *   mov     eax, [g_eventQueueEnd]
 *   mov     [g_eventQueueWorkType], eax
 *   mov     [g_acc_00542078], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_dlMode]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip1
 *   jmp     T1
 * .skip1:
 *   mov     eax, [g_state2]                  ; per-helper
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip2
 *   jmp     T2
 * .skip2:
 *   mov     eax, [g_acc_00542078]
 *   mov     [g_finalDest], eax               ; per-helper
 *   jmp     T3
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "game/statemachine.h"

extern unsigned int g_acc_00542078;
extern unsigned int g_state2_0053a1bc;
extern unsigned int g_state2_0053a354;
extern unsigned int g_finalDest_0053a178;
extern unsigned int g_finalDest_0053a250;

extern void func_004a0d60(void);
extern void func_004a0190(void);
extern void func_004a0210(void);
extern void func_004a04a0(void);
extern void func_004a0520(void);

/* @addr 0x004a0130 */
__declspec(naked) void TripleTestInstallJmp_004a0130(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_acc_00542078], eax
        call    func_004a0d60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   35h
        mov     eax, dword ptr [g_dlMode]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_004a0190
        mov     eax, dword ptr [g_state2_0053a1bc]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_004a0190
        mov     eax, dword ptr [g_acc_00542078]
        mov     dword ptr [g_finalDest_0053a178], eax
        jmp     func_004a0210
        ret
    }
}

/* @addr 0x004a0440 */
__declspec(naked) void TripleTestInstallJmp_004a0440(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_acc_00542078], eax
        call    func_004a0d60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   35h
        mov     eax, dword ptr [g_dlMode]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_004a04a0
        mov     eax, dword ptr [g_state2_0053a354]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_004a04a0
        mov     eax, dword ptr [g_acc_00542078]
        mov     dword ptr [g_finalDest_0053a250], eax
        jmp     func_004a0520
        ret
    }
}
