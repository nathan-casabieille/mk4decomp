/**
 * 2 "two-call + pause guard + tail-jmp" helpers (34 bytes each).
 *
 * Pattern:
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   jmp     Tail
 * ret_label:
 *   ret
 */
#include "game/tick.h"

extern void func_0042c390(void);
extern void func_0048fa50(void);
extern void func_0042c3b0(void);
extern void func_00494580(void);
extern void func_00488f00(void);
extern void func_004813b0(void);

/* @addr 0x0042b690 */
__declspec(naked) void TwoCallTail_0042b690(void) {
    __asm {
        call    func_0042c390
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    func_0048fa50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0042c3b0
        ret
    }
}

/* @addr 0x00481380 */
__declspec(naked) void TwoCallTail_00481380(void) {
    __asm {
        call    func_00494580
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    func_00488f00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004813b0
        ret
    }
}
