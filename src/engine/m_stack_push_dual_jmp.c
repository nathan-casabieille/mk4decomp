/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern void Dirty4Branch_MStackPushDual_StackPop_00428390(void);
extern void EsiInstallChainCallIndirect(void);

void MStackPushDualJmp(void) {
    int top = g_matrixStackTop;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = Dirty4Branch_MStackPushDual_StackPop_00428390;
    EsiInstallChainCallIndirect();
}
