/**
 * 2 "matrix-stack push + scaled OR + literal install + call + pop" (117b).
 *
 * Pattern:
 *   ; PUSH g_xformEntityIdx
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_xformEntityIdx]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   ; OR bit-set on scaled slot
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 0xa2
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ; Init secondary scaled slot
 *   mov     edx, [g_currentNodeIdx]    ; reload (matches orig codegen)
 *   mov     [edx*4 + 0x5c], 0x00010000
 *   mov     eax, [g_lit]
 *   mov     [g_xformEntityIdx], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   ; POP back into g_xformEntityIdx
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_xformEntityIdx], ecx
 *   mov     [g_matrixStackTop], eax
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_tickFrameNodeA;
extern unsigned int g_tickFrameNodeB;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_tickFrameNodeA (*(unsigned int *)MK4_VA(unsigned int, 0x541e90u))
#define g_tickFrameNodeB (*(unsigned int *)MK4_VA(unsigned int, 0x541e94u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif

extern void MStackPush2ChainPrepend(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* NATIVE twins: identical bodies through the node seam. */
/* @addr 0x00406430 */
void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void) {
    unsigned int idx;
    unsigned int v;
    unsigned int top;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
    idx = g_currentNodeIdx;
    v = MK4_NODE_AT(unsigned int, idx, 0x34);
    v |= 0xa2;   /* byte-form or al, 0xa2 in the original */
    g_walkCallback = v;
    MK4_NODE_AT(unsigned int, idx, 0x34) = v;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x00010000;
    g_xformEntityIdx = g_tickFrameNodeA;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *MK4_NODE(unsigned int, top);
    g_matrixStackTop = top - 1;
}

/* @addr 0x004064b0 */
void MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0(void) {
    unsigned int idx;
    unsigned int v;
    unsigned int top;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
    idx = g_currentNodeIdx;
    v = MK4_NODE_AT(unsigned int, idx, 0x34);
    v |= 0xa2;   /* byte-form or al, 0xa2 in the original */
    g_walkCallback = v;
    MK4_NODE_AT(unsigned int, idx, 0x34) = v;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x00010000;
    g_xformEntityIdx = g_tickFrameNodeB;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *MK4_NODE(unsigned int, top);
    g_matrixStackTop = top - 1;
}
#else
/* @addr 0x00406430 */
void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void) {
    unsigned int idx;
    unsigned int v;
    unsigned int top;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    idx = g_currentNodeIdx;
    v = ((ScenegraphNode *)(idx * 4))->state_mask;
    v |= 0xa2;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(idx * 4))->state_mask = v;
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x5c) = 0x00010000;
    g_xformEntityIdx = g_tickFrameNodeA;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x004064b0 */
void MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0(void) {
    unsigned int idx;
    unsigned int v;
    unsigned int top;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    idx = g_currentNodeIdx;
    v = ((ScenegraphNode *)(idx * 4))->state_mask;
    v |= 0xa2;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(idx * 4))->state_mask = v;
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x5c) = 0x00010000;
    g_xformEntityIdx = g_tickFrameNodeB;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
#endif

