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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


extern void MStackBracket5_LinkedListUnlink(void);
extern void PendingMatch_00407d50(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Same body as the matching one below, with the matrix stack addressed
 * through the seam - the raw `top * 4` deref is right on a flat image and
 * lands outside the arena here. */
void MStackPushZeroCallPop(void) {
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
    g_xformEntityIdx = 0;
    MStackBracket5_LinkedListUnlink();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}
#else
/* @addr 0x004066f0 */
void MStackPushZeroCallPop(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_xformEntityIdx;
    g_xformEntityIdx = 0;
    MStackBracket5_LinkedListUnlink();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
#endif

/* @addr 0x00407d00 */
void MStackPushZeroCallPop_PendingMatch(void) {
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
