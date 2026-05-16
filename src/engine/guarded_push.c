/**
 * 6 "guarded push-call" wrappers.
 *
 * Pattern (28 bytes):
 *   call PreFunc                ; e8 + reloc
 *   mov eax, [g_framePauseFlag]
 *   test eax, eax
 *   jne short skip              ; 75 0d
 *   push ARG                     ; 68 + imm32
 *   call Target                 ; e8 + reloc
 *   add esp, 4
 * skip:
 *   ret
 */
#include "game/tick.h"   /* g_framePauseFlag */

/* Externs. */
extern void CopyJmp_00406ba0();   /* 0x00406ba0 */
extern void Thunk_00433950();   /* 0x00433950 */
extern void ScaledLoadInstallOrCall_00433960();   /* 0x00433960 */
extern void PackedAdvanceCallTailJmp_004392c0();   /* 0x004392c0 */
extern void CopyJmp_0043a620();   /* 0x0043a620 */
extern void ArgSarStoreJmp_004594f0();   /* 0x004594f0 */
extern void Wrapper_0048a370();   /* 0x0048a370 */
extern void DualMul10AndDispatchChain_0049c220();   /* 0x0049c220 */
extern void ArgSar_Set0_Jmp_0049c6f0();   /* 0x0049c6f0 */

/* @addr 0x004338a0 */
__declspec(naked) void GuardedPushCall_004338a0(void) {
    __asm {
        call    ScaledLoadInstallOrCall_00433960
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0Dh
        push    0x004e4480
        call    PackedAdvanceCallTailJmp_004392c0
        add     esp, 4
        ret
    }
}

/* @addr 0x004338c0 */
__declspec(naked) void GuardedPushCall_004338c0(void) {
    __asm {
        call    Thunk_00433950
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0Dh
        push    0x004e44a8
        call    PackedAdvanceCallTailJmp_004392c0
        add     esp, 4
        ret
    }
}

/* @addr 0x0043b980 */
__declspec(naked) void GuardedPushCall_0043b980(void) {
    __asm {
        call    CopyJmp_0043a620
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0Dh
        push    0x004e4c48
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
    }
}

/* @addr 0x0046a560 */
__declspec(naked) void GuardedPushCall_0046a560(void) {
    __asm {
        call    CopyJmp_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0Dh
        push    0x004eabc8
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
    }
}

/* @addr 0x00482990 */
__declspec(naked) void GuardedPushCall_00482990(void) {
    __asm {
        call    Wrapper_0048a370
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0Dh
        push    0x004ee158
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
    }
}

/* @addr 0x0049c200 */
__declspec(naked) void GuardedPushCall_0049c200(void) {
    __asm {
        call    DualMul10AndDispatchChain_0049c220
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0Dh
        push    0x004f2758
        call    ArgSar_Set0_Jmp_0049c6f0
        add     esp, 4
        ret
    }
}

