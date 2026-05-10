/**
 * 2 "call + pause guard + add into dual store" helpers (38b).
 *
 * Pattern:
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_X]
 *   mov     ecx, [g_walkCallback]
 *   add     eax, ecx
 *   mov     [g_Y], eax
 *   mov     [g_X], eax
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_acc_0053a438;
extern unsigned int g_acc_0053a440;
extern unsigned int g_acc_00542078;

extern void func_0048b500(void);

/* @addr 0x0048b480 */
__declspec(naked) void CallPauseAddDualStore_0048b480(void) {
    __asm {
        call    func_0048b500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     eax, dword ptr [g_acc_0053a438]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, ecx
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [g_acc_0053a438], eax
        ret
    }
}

/* @addr 0x0048b4b0 */
__declspec(naked) void CallPauseAddDualStore_0048b4b0(void) {
    __asm {
        call    func_0048b500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     eax, dword ptr [g_acc_0053a440]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, ecx
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [g_acc_0053a440], eax
        ret
    }
}
