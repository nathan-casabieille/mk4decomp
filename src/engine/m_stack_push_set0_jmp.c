/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004384b0 (37b): same shape value=0 + diff target */
extern void func_004384e0(void);
extern void MstackPopScaledChainPlusThunks(void);
extern void StackPopDispatchTagged(void);
void MStackPushSet0Jmp(void) {
    int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))0;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = func_004384e0;
    MstackPopScaledChainPlusThunks();
}
