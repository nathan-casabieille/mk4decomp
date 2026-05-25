/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042f4f0 (75b)
 *   PushPop save/restore of g_pendingNodeType across two
 *   push-arg calls (0x249, 0x24a) to SaveCallRestore_004049d0.
 */
extern void SaveCallRestore_004049d0(int);
void PushPopPendingTwoCalls_0042f4f0(void) {
    unsigned int top;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_pendingNodeType;
    SaveCallRestore_004049d0(0x249);
    SaveCallRestore_004049d0(0x24a);
    top = g_matrixStackTop;
    g_pendingNodeType = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
