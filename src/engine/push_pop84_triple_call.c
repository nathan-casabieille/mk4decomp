/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00438b90 (91b)
 *   push g_currentNodeFlags onto stack[idx*4]; 3-call pause chain;
 *   pop stack value back into g_currentNodeFlags.
 */
extern void func_0049072e(void);
extern void func_00490c0a(void);
extern void func_0046121e(void);
void PushPop84TripleCall_00438b90(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_currentNodeFlags;
    func_0049072e();
    if (g_framePauseFlag != 0) {
        return;
    }
    func_00490c0a();
    if (g_framePauseFlag != 0) {
        return;
    }
    func_0046121e();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_currentNodeFlags = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
