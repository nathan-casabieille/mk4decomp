/**
 * 2 "matrix-stack push + scaled OR + literal install + call + pop" (117b).
 *
 * Pattern:
 *   ; PUSH g_xformEntityIdx
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_xformEntityIdx]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   ; OR bit-set on scaled slot
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 0xa2
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ; Init secondary scaled slot
 *   mov     edx, [g_scaledInit_00542044]    ; reload (matches orig codegen)
 *   mov     [edx*4 + 0x5c], 0x00010000
 *   mov     eax, [g_lit]
 *   mov     [g_xformEntityIdx], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   ; POP back into g_xformEntityIdx
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_xformEntityIdx], ecx
 *   mov     [g_matrixStackTop], eax
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_lit_00541e90;
extern unsigned int g_lit_00541e94;
extern void MStackPush2ChainPrepend_00409970(void);

/* @addr 0x00406430 */
__declspec(naked) void MStackPushComplexCallPop_00406430(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x34]
        or      al, 0xa2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [edx*4 + 0x5c], 0x00010000
        mov     eax, dword ptr [g_lit_00541e90]
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackPush2ChainPrepend_00409970
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x004064b0 */
__declspec(naked) void MStackPushComplexCallPop_004064b0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x34]
        or      al, 0xa2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [edx*4 + 0x5c], 0x00010000
        mov     eax, dword ptr [g_lit_00541e94]
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackPush2ChainPrepend_00409970
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}
