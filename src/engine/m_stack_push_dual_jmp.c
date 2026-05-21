/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

void MStackPushDualJmp_00428370(void) {
    int top = g_matrixStackTop;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = TripleBranchInstall_004283b0;
    func_0042867d();
}
