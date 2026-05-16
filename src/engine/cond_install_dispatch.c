/**
 * 3 "conditional install + dispatch + xform-flag clear" helpers (58b).
 *
 * Pattern:
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     eax, [eax*4 + 0x0c]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      .after_dispatch
 *   mov     [g_walkCallback], OFFSET fnLiteral   ; override with literal fn ptr
 *   call    func_004baea0
 * .after_dispatch:
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 * .ret:
 *   ret
 *
 * Loads a callback from a per-helper table slot. If non-null, also
 * stamps in a literal function pointer and dispatches. Then clears
 * bit 0 of g_xformDirtyFlags unless paused.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern void ScaledOr4Jmp_00476e00(void);
extern void func_00476e90(void);
extern void ScaledAndFBJmp_00476fe0(void);
extern void func_004baea0(void);

/* @addr 0x00476e20 */
__declspec(naked) void CondInstallDispatch_00476e20(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 0x0c]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
        mov     dword ptr [g_walkCallback], OFFSET ScaledOr4Jmp_00476e00
        call    func_004baea0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x00476ed0 */
__declspec(naked) void CondInstallDispatch_00476ed0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 0x0c]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
        mov     dword ptr [g_walkCallback], OFFSET func_00476e90
        call    func_004baea0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x00477000 */
__declspec(naked) void CondInstallDispatch_00477000(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 0x0c]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
        mov     dword ptr [g_walkCallback], OFFSET ScaledAndFBJmp_00476fe0
        call    func_004baea0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}
