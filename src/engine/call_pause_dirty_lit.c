/**
 * 2 "call + pause + dirty-bit + literal-call" helpers (42 bytes).
 *
 * Pattern:
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte ptr [g_xformDirtyFlags], 1
 *   je      .literal_path
 *   jmp     T1
 * .literal_path:
 *   push    LITERAL
 *   call    FuncB
 *   add     esp, 4
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void *g_lit_004e44d8;
extern void *g_lit_004ef218;

extern void func_0048e780(void);
extern void func_00433940(void);
extern int  func_004392c0(void *p);
extern void func_00488dc0(void);
extern void func_00488ca0(void);
extern int  func_00491520(void *p);

/* @addr 0x00433910 */
__declspec(naked) void CallPauseDirtyLit_00433910(void) {
    __asm {
        call    func_0048e780
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00433940
        push    OFFSET g_lit_004e44d8
        call    func_004392c0
        add     esp, 4
        ret
    }
}

/* @addr 0x00488c70 */
__declspec(naked) void CallPauseDirtyLit_00488c70(void) {
    __asm {
        call    func_00488dc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00488ca0
        push    OFFSET g_lit_004ef218
        call    func_00491520
        add     esp, 4
        ret
    }
}
