/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00413070 (68b)
 *   inc g_matrixStackTop; push g_fightGroupHead onto stack[idx*4];
 *   call F1; pause-test → ret; call F2; pause-test → ret;
 *   set walk = 0xa; jmp T.
 */
extern void func_004089e0_hh(void);
extern void func_004b8fa0_hh(void);
extern void Phase4StateInit4Helpers_004130c0(void);
void PushStackCallPauseSet0xa_00413070(void) {
    unsigned int top = g_matrixStackTop;
    unsigned int v = g_fightGroupHead;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = v;
    func_004089e0_hh();
    if (g_framePauseFlag) return;
    func_004b8fa0_hh();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0xa;
    Phase4StateInit4Helpers_004130c0();
}
