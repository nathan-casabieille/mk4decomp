/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0043aa80 (37b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 5
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET StateMachine4ArmCascade_0043aab0
 *   jmp     T
 */
extern void StateMachine4ArmCascade_0043aab0(void);
extern void MstackPopScaledChainPlusThunks_00471250(void);
void MStackPush5Func_0043aa80(void) {
    unsigned int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))5;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)StateMachine4ArmCascade_0043aab0;
    MstackPopScaledChainPlusThunks_00471250();
}
