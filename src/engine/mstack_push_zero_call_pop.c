/**
 * 2 "matrix-stack push, clear, call, pause-guarded pop" helpers (73b).
 *
 * Pattern:
 *   ; Save current g_X onto matrix stack
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_X]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   mov     [g_X], 0                          ; reset X
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   ; Restore g_X from matrix stack
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_X], edx
 *   mov     [g_matrixStackTop], eax
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void func_00409aa0(void);
extern void func_00407d50(void);

/* @addr 0x004066f0 */
__declspec(naked) void MStackPushZeroCallPop_004066f0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_xformEntityIdx], 0
        call    func_00409aa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00407d00 */
__declspec(naked) void MStackPushZeroCallPop_00407d00(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueTotal]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_eventQueueTotal], 0
        call    func_00407d50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}
