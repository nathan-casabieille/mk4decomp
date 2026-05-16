/**
 * 2 "matrix-stack push with literal + scaled finalize" helpers (131b).
 *
 * Pattern:
 *   mov     eax, [g_state_0053a430]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   jne     .check_x
 *   mov     eax, [g_X_0052aac4]
 *   cmp     eax, 2
 *   mov     [g_eventQueueCurrent], eax
 *   je      .ret
 * .check_x:
 *   ; PUSH walkCallback w/ literal pointer arg
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_walkCallback]
 *   inc     eax
 *   push    LITERAL_PTR
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   ; POP into walkCallback + propagate
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_walkCallback], ecx
 *   mov     [g_matrixStackTop], eax
 *   mov     [edx*4 + 0x18], ecx
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_fightGroupHead]
 *   mov     [eax*4 + 0x24], ecx
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_0053a430;
extern unsigned int g_X_0052aac4;
extern void *g_lit_004e39d8;
extern void *g_lit_004e3a28;
extern int  PackedAdvanceCallContinue_0048e630(void *p);

/* @addr 0x00431530 */
__declspec(naked) void DispatcherComplex131_00431530(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a430]
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   75h
        _emit   0fh
        mov     eax, dword ptr [g_X_0052aac4]
        cmp     eax, 2
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   74h
        _emit   65h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        push    OFFSET g_lit_004e39d8
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    PackedAdvanceCallContinue_0048e630
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   37h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [edx*4 + 0x18], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x24], ecx
        ret
    }
}

/* @addr 0x004315c0 */
__declspec(naked) void DispatcherComplex131_004315c0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a430]
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   75h
        _emit   0fh
        mov     eax, dword ptr [g_X_0052aac4]
        cmp     eax, 2
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   74h
        _emit   65h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        push    OFFSET g_lit_004e3a28
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    PackedAdvanceCallContinue_0048e630
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   37h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [edx*4 + 0x18], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x24], ecx
        ret
    }
}
