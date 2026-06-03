/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00460c60 (61b)
 *   call F1; pause → ret; call F2; if eax != 0 → ret;
 *   inc g_matrixStackTop; set walk=2; push 0x46f6b0 to stack[idx*4]; jmp T.
 */
extern void LeaPlus22StoreSelf(void);
extern int DualGatedStateYield(void);
extern unsigned int g_matrixStackTop;
extern void MstackPopScaledChainPlusThunks(void);
extern void FiveCallGuardSetTail(void);
void CallPauseCallTestStackPushJmp(void) {
    unsigned int top;
    LeaPlus22StoreSelf();
    if (g_framePauseFlag != 0) {
        return;
    }
    if (DualGatedStateYield() != 0) {
        return;
    }
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))2;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&FiveCallGuardSetTail;
    MstackPopScaledChainPlusThunks();
}
