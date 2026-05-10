/**
 * 3 "matrix-stack push, two guarded calls, pop" helpers (77 bytes).
 *
 * Pattern:
 *   ; PUSH g_fightGroupHead
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_fightGroupHead]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   ; POP into g_fightGroupHead
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_fightGroupHead], edx
 *   mov     [g_matrixStackTop], eax
 * .ret:
 *   ret
 *
 * Pushes the fight-group head onto the matrix stack, runs two
 * subsystem ticks (with pause-flag bail between them), then pops
 * back. If either tick triggers a pause, the pop is skipped (so the
 * outer caller can resume from the saved state).
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void func_00405A40(void);
extern void func_00405CB8(void);
extern void func_00406740(void);
extern void func_00405E68(void);

/* @addr 0x00405b30 */
__declspec(naked) void MStackPushCallCallPop_00405b30(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_00405A40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   26h
        call    func_00405CB8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00405dd0 */
__declspec(naked) void MStackPushCallCallPop_00405dd0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_00405A40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   26h
        call    func_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00405e20 */
__declspec(naked) void MStackPushCallCallPop_00405e20(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_00405A40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   26h
        call    func_00405E68
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}
