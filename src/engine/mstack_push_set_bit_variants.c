/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490140 */
void MStackPushSet0200_00490140(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x0200;
    OrStoreDecStackPop_00490290();
}

/* @addr 0x00490170 */
void MStackPushSet0080_00490170(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x0080;
    OrStoreDecStackPop_00490290();
}

/* @addr 0x004901a0 */
void MStackPushSet0008_004901a0(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 8;
    OrStoreDecStackPop_00490290();
}

/* @addr 0x004901d0 */
void MStackPushSet0020_004901d0(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x20;
    OrStoreDecStackPop_00490290();
}

/* @addr 0x00490200 */
void MStackPushSet0040_00490200(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x40;
    OrStoreDecStackPop_00490290();
}

/* @addr 0x00490230 */
void MStackPushSet0004_00490230(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 4;
    OrStoreDecStackPop_00490290();
}

/* @addr 0x00490260 */
void MStackPushSet0001_00490260(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 1;
    OrStoreDecStackPop_00490290();
}
