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

extern void MStackBracket5_LinkedListUnlink_00409aa0(void);
extern void PendingMatch_00407d50(void);

/* @addr 0x004066f0 */
void MStackPushZeroCallPop_004066f0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_xformEntityIdx;
    g_xformEntityIdx = 0;
    MStackBracket5_LinkedListUnlink_00409aa0();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00407d00 */
void MStackPushZeroCallPop_00407d00(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_eventQueueTotal;
    g_eventQueueTotal = 0;
    PendingMatch_00407d50();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_eventQueueTotal = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
