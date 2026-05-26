/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004839d0 (70b)
 *   call F1; pause-test → ret; call F2; pause → ret;
 *   testb 4,[dirty]; jz +0x1b →ret; inc g_matrixStackTop;
 *   push 0x00483a20 onto stack[idx*4]; jmp T.
 */
extern void func_0047f860(void);
extern void func_00484342(void);
extern void InstallSelfOrChainJmp_00483a20(void);
extern void GameDispatchValidateState_004339c0(void);
void CallPauseDirty4StackPushFn_004839d0(void) {
    func_0047f860();
    if (g_framePauseFlag != 0) return;
    func_00484342();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        g_matrixStackTop++;
        *(unsigned int *)(g_matrixStackTop * 4) = (unsigned int)&InstallSelfOrChainJmp_00483a20;
        GameDispatchValidateState_004339c0();
        return;
    }
    InstallSelfOrChainJmp_00483a20();
}
