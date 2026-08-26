/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif


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
