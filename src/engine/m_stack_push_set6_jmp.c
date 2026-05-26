/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00438470 (37b main + 11 nop pad + 5b sub-entry at +0x30):
 *   set walk=6, mstack-push func_004384a0, tail-jmp func_0046f230.
 *   Sub-entry MStackCleanupFrom_004384a0 (below) is a 5b tail-jmp
 *   wrapper into StackPopDispatchTagged_0041f780; the 11-byte gap is synth 0x90 fill.
 */
extern void func_004384a0(void);
extern void func_0046f230(void);
extern void StackPopDispatchTagged_0041f780(void);
void MStackPushSet6Jmp_00438470(void) {
    int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))6;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = func_004384a0;
    func_0046f230();
}
