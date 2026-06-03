/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00490140 */
void MStackPushSet0200(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x0200;
    OrStoreDecStackPop();
}

/* @addr 0x00490170 */
void MStackPushSet0080(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x0080;
    OrStoreDecStackPop();
}

/* @addr 0x004901a0 */
void MStackPushSet0008(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 8;
    OrStoreDecStackPop();
}

/* @addr 0x004901d0 */
void MStackPushSet0020(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x20;
    OrStoreDecStackPop();
}

/* @addr 0x00490200 */
void MStackPushSet0040(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 0x40;
    OrStoreDecStackPop();
}

/* @addr 0x00490230 */
void MStackPushSet0004(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 4;
    OrStoreDecStackPop();
}

/* @addr 0x00490260 */
void MStackPushSet0001(void) {
    unsigned int acc = g_eventQueueNotMask;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_eventQueueNotMask = 1;
    OrStoreDecStackPop();
}
