/**
 * 2 "matrix-stack push + call + pause + pop + dirty test + jmp" (77b).
 *
 * Pattern:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_walkCallback]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     al, [g_xformDirtyFlags]
 *   test    al, 1
 *   mov     [g_walkCallback], edx
 *   je      .ret
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void State208cBit0Flag_0048f160(void);
extern void GuardedRangeCmpToggle_0048f210(void);
extern void MStackCjChainSwapDualCall_0042cd30(void);

/* @addr 0x0042cc90 */
__declspec(naked) void MStackPushCallPopDirtyJmp_0042cc90(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    State208cBit0Flag_0048f160
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mscpd_ret_a
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        test    al, 1
        mov     dword ptr [g_walkCallback], edx
        je      short L_mscpd_ret_a
        jmp     MStackCjChainSwapDualCall_0042cd30
L_mscpd_ret_a:
        ret
    }
}

/* @addr 0x0042cce0 */
__declspec(naked) void MStackPushCallPopDirtyJmp_0042cce0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    GuardedRangeCmpToggle_0048f210
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mscpd_ret_b
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        test    al, 1
        mov     dword ptr [g_walkCallback], edx
        je      short L_mscpd_ret_b
        jmp     MStackCjChainSwapDualCall_0042cd30
L_mscpd_ret_b:
        ret
    }
}
