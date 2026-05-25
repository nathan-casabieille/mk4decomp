/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00460c60 (61b)
 *   call F1; pause → ret; call F2; if eax != 0 → ret;
 *   inc g_matrixStackTop; set walk=2; push 0x46f6b0 to stack[idx*4]; jmp T.
 */
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern int DualGatedStateYield_0048fc80(void);
extern unsigned int g_state_004d57ac_ff;
extern void MstackPopScaledChainPlusThunks_00471250(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
void CallPauseCallTestStackPushJmp_00460c60(void) {
    unsigned int top;
    LeaPlus22StoreSelf_0048e4d0();
    if (g_framePauseFlag != 0) {
        return;
    }
    if (DualGatedStateYield_0048fc80() != 0) {
        return;
    }
    top = g_state_004d57ac_ff;
    g_walkCallback = (void (*)(void))2;
    top++;
    g_state_004d57ac_ff = top;
    *(unsigned int *)(top * 4) = (unsigned int)&FiveCallGuardSetTail_0046f6b0;
    MstackPopScaledChainPlusThunks_00471250();
}
