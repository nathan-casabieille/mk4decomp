/**
 * 2 "complex three-state dispatcher" helpers (115 bytes each).
 *
 * Pattern:
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte ptr [g_xformDirtyFlags], 1
 *   je      .skip_states
 *   mov     eax, [g_state1]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip_states
 *   mov     eax, [g_state2]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip_states
 *   mov     [g_state1], 2                  ; reset state1 to 2
 *   mov     [g_walkCallback], eax           ; eax is still 0 here
 *   mov     [g_state4], eax
 * .skip_states:
 *   call    Worker
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    Finalize
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ax, word ptr [g_lit16]
 *   push    eax
 *   call    Sink
 *   add     esp, 4
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state1_0053a408;
extern unsigned int g_state1_00537e88;
extern unsigned int g_state2_00541d88;
extern unsigned int g_state2_00537ea8;
extern unsigned int g_state4_0053a3e0;
extern unsigned int g_state4_0053a700;
extern unsigned int g_lit16_004e286c;

extern void func_0049fa20(void);
extern void func_0049e7e0(void);
extern void func_0049fa00(void);
extern int  func_004be690(int);

/* @addr 0x0049f900 */
__declspec(naked) void DispatcherComplex115_0049f900(void) {
    __asm {
        call    func_0049fa20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   64h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   5bh
        mov     eax, dword ptr [g_state1_0053a408]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   4dh
        mov     eax, dword ptr [g_state2_00541d88]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   3fh
        mov     dword ptr [g_state1_0053a408], 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state4_0053a3e0], eax
        call    func_0049e7e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        call    func_0049fa00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     ax, word ptr [g_lit16_004e286c]
        push    eax
        call    func_004be690
        add     esp, 4
        ret
    }
}

/* @addr 0x0049f980 */
__declspec(naked) void DispatcherComplex115_0049f980(void) {
    __asm {
        call    func_0049fa20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   64h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   5bh
        mov     eax, dword ptr [g_state1_00537e88]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   4dh
        mov     eax, dword ptr [g_state2_00537ea8]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   3fh
        mov     dword ptr [g_state1_00537e88], 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state4_0053a700], eax
        call    func_0049e7e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        call    func_0049fa00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     ax, word ptr [g_lit16_004e286c]
        push    eax
        call    func_004be690
        add     esp, 4
        ret
    }
}
