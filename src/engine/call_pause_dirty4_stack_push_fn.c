/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004839d0 (70b)
 *   call F1; pause-test → ret; call F2; pause → ret;
 *   testb 4,[dirty]; jz +0x1b →ret; inc g_matrixStackTop;
 *   push 0x00483a20 onto stack[idx*4]; jmp T.
 */
extern void GuardedDoubleIncCmpJmp(void);
extern void DirtyToggleByGate(void);
extern void InstallSelfOrChainJmp(void);
extern void GameDispatchValidateState(void);
void CallPauseDirty4StackPushFn(void) {
    GuardedDoubleIncCmpJmp();
    if (g_framePauseFlag != 0) return;
    DirtyToggleByGate();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        g_matrixStackTop++;
        *(unsigned int *)(g_matrixStackTop * 4) = (unsigned int)&InstallSelfOrChainJmp;
        GameDispatchValidateState();
        return;
    }
    InstallSelfOrChainJmp();
}
