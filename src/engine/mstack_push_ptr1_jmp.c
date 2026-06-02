/**
 * MStack-push + ptr-install + tail-jmp sister pair.
 *
 * Two related variants pushing the matrix-stack with different
 * g_walkCallback initial values (3 vs 1) before tail-jmping.
 */
#include "engine/scenegraph.h"

extern void DualCallPauseJmpDual(void);
extern void func_DualScaledInitClear_then_FiveCallGuardSetTail(void);

/* @addr 0x00438e70 (37b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 3
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET DualCallPauseJmpDual
 *   jmp     T
 */
extern void MstackPopScaledChainPlusThunks(void);
void MStackPushPtr1Jmp_00438e70(void) {
    unsigned int v = g_matrixStackTop;
    g_walkCallback = (void (*)(void))3;
    v++;
    g_matrixStackTop = v;
    *(unsigned int *)(v * 4) = (unsigned int)&DualCallPauseJmpDual;
    MstackPopScaledChainPlusThunks();
}

/* @addr 0x00438ef0 (37b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 1
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET func_DualScaledInitClear_then_FiveCallGuardSetTail
 *   jmp     T
 */
extern void MstackPopScaledChainPlusThunks(void);
void MStackPushPtr1Jmp_00438ef0(void) {
    unsigned int v = g_matrixStackTop;
    g_walkCallback = (void (*)(void))1;
    v++;
    g_matrixStackTop = v;
    *(unsigned int *)(v * 4) = (unsigned int)&func_DualScaledInitClear_then_FiveCallGuardSetTail;
    MstackPopScaledChainPlusThunks();
}
