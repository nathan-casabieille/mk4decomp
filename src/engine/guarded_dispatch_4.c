/**
 * 2 "guarded dispatch" helpers (34 bytes each, mask=4).
 *
 * Variant of GuardedDispatch (mask=1) that tests bit 2 of
 * g_xformDirtyFlags instead of bit 0.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void func_004285e0(void);
extern void func_00484a90(void);
extern void func_0046f6b0(void);
extern void func_0048f350(void);
extern void func_00428d60(void);
extern void func_004890b0(void);

/* @addr 0x00484b40 */
__declspec(naked) void GuardedDispatch4_00484b40(void) {
    __asm {
        call    func_004285e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_00484a90
        jmp     func_0046f6b0
        ret
    }
}

/* @addr 0x00489080 */
__declspec(naked) void GuardedDispatch4_00489080(void) {
    __asm {
        call    func_0048f350
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_00428d60
        jmp     func_004890b0
        ret
    }
}
