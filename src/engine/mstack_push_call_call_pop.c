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
extern void MStackCall_00406740(void);
extern void func_00405E68(void);

/* @addr 0x00405b30 */
void MStackPushCallCallPop_00405b30(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_fightGroupHead;
    func_00405A40();
    if (g_framePauseFlag != 0) return;
    func_00405CB8();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_fightGroupHead = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00405dd0 */
void MStackPushCallCallPop_00405dd0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_fightGroupHead;
    func_00405A40();
    if (g_framePauseFlag != 0) return;
    MStackCall_00406740();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_fightGroupHead = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00405e20 */
void MStackPushCallCallPop_00405e20(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_fightGroupHead;
    func_00405A40();
    if (g_framePauseFlag != 0) return;
    func_00405E68();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_fightGroupHead = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
