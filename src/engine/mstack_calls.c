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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif


/* Externs for call targets. */
extern void MStackCall_MStackPush2ChainInsert_004062a0(void);   /* 0x545ecf1e */
extern void MStackPush2ChainInsert(void);   /* 0x545ecf6e */
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);   /* 0x545ecfbe */
extern void MStackPush2ChainPrepend(void);   /* 0x545ed00e */
extern void MStackPush2ChainPrepend(void);   /* 0x545ed05e */
extern void MStackPush2ChainPrepend(void);   /* 0x545ed0ae */
extern void MStackPush2ChainInsert(void);   /* 0x545ed27e */
extern void MStackPush2ChainPrepend(void);   /* 0x545ed2ce */
extern void MStackPush2ChainLLInsert(void);   /* 0x545ed40e */
extern void MStackPush2ChainInsert(void);   /* 0x545ed81e */
extern void PushPopScaled1cDoubleCall(void);   /* 0x54633efe */

/* The wrappers. */
/* @addr 0x00406250 */
void MStackCall_MStackPush2ChainInsert_00406250(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackCall_MStackPush2ChainInsert_004062a0();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x004062a0 */
void MStackCall_MStackPush2ChainInsert_004062a0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainInsert();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x004062f0 */
void MStackCall_MStackPush2ChainPrepend_004062f0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackCall_MStackPush2ChainPrepend_00406340();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406340 */
void MStackCall_MStackPush2ChainPrepend_00406340(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406390 */
void MStackCall_MStackPush2ChainPrepend_00406390(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x004063e0 */
void MStackCall_MStackPush2ChainPrepend_004063e0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x004065b0 */
void MStackCall_MStackPush2ChainInsert_004065b0(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainInsert();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406600 */
void MStackCall_MStackPush2ChainPrepend_00406600(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406740 */
void MStackCall_MStackPush2ChainLLInsert(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainLLInsert();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x00406b50 */
void MStackCall_MStackPush2ChainInsert_00406b50(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    MStackPush2ChainInsert();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

/* @addr 0x0044d230 */
void MStackCall_PushPopScaled1cDoubleCall(void) {
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR((top * 4)) = g_currentNodeIdx;
    g_currentNodeIdx = g_fightGroupHead;
    PushPopScaled1cDoubleCall();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((top * 4));
    g_matrixStackTop = top - 1;
}

