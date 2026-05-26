/**
 * 11 "matrix-stack push + call + guarded pop" wrappers.
 *
 * Pattern (75 bytes):
 *   mov eax, [g_matrixStackTop]
 *   mov ecx, [g_currentNodeIdx]
 *   inc eax
 *   mov [g_matrixStackTop], eax
 *   mov [eax*4 + 0], ecx     ; SIB+disp32=0 - scaled-base array
 *   mov edx, [g_fightGroupHead]
 *   mov [g_currentNodeIdx], edx
 *   call Target
 *   mov eax, [g_framePauseFlag]
 *   test eax, eax
 *   jne short skip          ; bail if pause set
 *   mov eax, [g_matrixStackTop]
 *   mov ecx, [eax*4 + 0]
 *   dec eax
 *   mov [g_currentNodeIdx], ecx
 *   mov [g_matrixStackTop], eax
 * skip:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"   /* g_framePauseFlag */

/* Externs for call targets. */
extern void MStackCall_004062a0(void);   /* 0x545ecf1e */
extern void MStackPush2ChainInsert_00409870(void);   /* 0x545ecf6e */
extern void MStackCall_00406340(void);   /* 0x545ecfbe */
extern void MStackPush2ChainPrepend_00409970(void);   /* 0x545ed00e */
extern void MStackPush2ChainPrepend_00409970(void);   /* 0x545ed05e */
extern void MStackPush2ChainPrepend_00409970(void);   /* 0x545ed0ae */
extern void MStackPush2ChainInsert_00409870(void);   /* 0x545ed27e */
extern void MStackPush2ChainPrepend_00409970(void);   /* 0x545ed2ce */
extern void MStackPush2ChainLLInsert_00406790(void);   /* 0x545ed40e */
extern void MStackPush2ChainInsert_00409870(void);   /* 0x545ed81e */
extern void PushPopScaled1cDoubleCall_00408510(void);   /* 0x54633efe */

/* The wrappers. */
/* @addr 0x00406250 */
void MStackCall_00406250(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackCall_004062a0();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x004062a0 */
void MStackCall_004062a0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainInsert_00409870();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x004062f0 */
void MStackCall_004062f0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackCall_00406340();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406340 */
void MStackCall_00406340(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend_00409970();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406390 */
void MStackCall_00406390(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend_00409970();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x004063e0 */
void MStackCall_004063e0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend_00409970();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x004065b0 */
void MStackCall_004065b0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainInsert_00409870();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406600 */
void MStackCall_00406600(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend_00409970();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406740 */
void MStackCall_00406740(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainLLInsert_00406790();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406b50 */
void MStackCall_00406b50(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainInsert_00409870();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x0044d230 */
void MStackCall_0044d230(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    PushPopScaled1cDoubleCall_00408510();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

