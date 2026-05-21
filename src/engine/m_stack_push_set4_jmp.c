/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004384f0 (37b): same shape value=4 */
extern void func_00438520(void);
extern void func_0046f230_c(void);
extern void func_0042b240(void);
void MStackPushSet4Jmp_004384f0(void) {
    int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))4;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = func_00438520;
    func_0046f230_c();
}
