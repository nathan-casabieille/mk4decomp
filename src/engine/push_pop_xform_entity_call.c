/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0044d1e0 (66b)
 *   Save g_xformEntityIdx (0x542048) on matrix stack, replace it
 *   with g_eventQueueEnd (0x542054), call helper, restore.
 *   Standard "scoped global swap" wrapper.
 */
extern void Copy3FieldsNeg_0041aa40(void);
void PushPopXformEntityCall_0044d1e0(void) {
    unsigned int top;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_xformEntityIdx;
    g_xformEntityIdx = g_eventQueueEnd;
    Copy3FieldsNeg_0041aa40();
    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
