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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif


extern void func_00405A40(void);
extern void BootChainBidirRecurseWalk(void);
extern void MStackCall_MStackPush2ChainLLInsert(void);
extern void MStackBracket2_TreeWalkRecursive(void);

/* @addr 0x00405b30 */
void MStackPushCallCallPop_func_00405b30(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
#ifdef MK4_ARENA
    *MK4_NODE(unsigned int, top) = g_fightGroupHead;
#else
    *(unsigned int *)(top * 4) = g_fightGroupHead;
#endif
    func_00405A40();
    if (g_framePauseFlag != 0) return;
    BootChainBidirRecurseWalk();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
#ifdef MK4_ARENA
    g_fightGroupHead = *MK4_NODE(unsigned int, top);
#else
    g_fightGroupHead = *(unsigned int *)(top * 4);
#endif
    g_matrixStackTop = top - 1;
}

/* @addr 0x00405dd0 */
void MStackPushCallCallPop_func_00405dd0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
#ifdef MK4_ARENA
    *MK4_NODE(unsigned int, top) = g_fightGroupHead;
#else
    *(unsigned int *)(top * 4) = g_fightGroupHead;
#endif
    func_00405A40();
    if (g_framePauseFlag != 0) return;
    MStackCall_MStackPush2ChainLLInsert();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
#ifdef MK4_ARENA
    g_fightGroupHead = *MK4_NODE(unsigned int, top);
#else
    g_fightGroupHead = *(unsigned int *)(top * 4);
#endif
    g_matrixStackTop = top - 1;
}

/* @addr 0x00405e20 */
void MStackPushCallCallPop_func_00405e20(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
#ifdef MK4_ARENA
    *MK4_NODE(unsigned int, top) = g_fightGroupHead;
#else
    *(unsigned int *)(top * 4) = g_fightGroupHead;
#endif
    func_00405A40();
    if (g_framePauseFlag != 0) return;
    MStackBracket2_TreeWalkRecursive();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
#ifdef MK4_ARENA
    g_fightGroupHead = *MK4_NODE(unsigned int, top);
#else
    g_fightGroupHead = *(unsigned int *)(top * 4);
#endif
    g_matrixStackTop = top - 1;
}
