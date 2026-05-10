/* Test: NodeApplyMatrix - explicit top++ pattern */
#include "engine/scenegraph.h"

void NodeApplyMatrix(void)
{
    u32 entity;
    s32 i;

    g_matrixStackTop++;
    g_matrixStackA[g_matrixStackTop] = g_currentNodeIdx;
    g_matrixStackTop++;
    g_matrixStackB[g_matrixStackTop] = (u32)g_xformLoopCounter;

    entity = g_xformEntityIdx - 0xf;
    g_xformLoopCounter = 8;
    g_xformEntityIdx = entity;
    entity = *(u32 *)(entity * 4 + 0x28) + 6;
    g_xformEntityIdx = entity;

    g_walkCallback = (void (*)(void))((u32 *)(entity * 4))[0];
    entity++;
    g_xformEntityIdx = entity;

    for (i = 8; i >= 0; i--) {
        u32 src;
        entity = g_xformEntityIdx;
        src = ((u32 *)(entity * 4))[0];
        entity++;
        g_walkCallback = (void (*)(void))src;
        g_xformEntityIdx = entity;
        ((u32 *)(g_currentNodeIdx * 4))[0] = src;
        g_currentNodeIdx++;
    }

    g_xformLoopCounter = (int)g_matrixStackB[g_matrixStackTop];
    g_matrixStackTop--;
    g_currentNodeIdx = g_matrixStackA[g_matrixStackTop];
    g_matrixStackTop--;
}
