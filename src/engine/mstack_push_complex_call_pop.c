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
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 0xa2
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ; Init secondary scaled slot
 *   mov     edx, [g_scaledInit_00542044]    ; reload (matches orig codegen)
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

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_lit_00541e90;
extern unsigned int g_lit_00541e94;
extern void MStackPush2ChainPrepend_00409970(void);

/* @addr 0x00406430 */
void MStackPushComplexCallPop_00406430(void) {
    unsigned int idx;
    unsigned int v;
    unsigned int top;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    idx = g_scaledInit_00542044;
    v = ((ScenegraphNode *)(idx * 4))->state_mask;
    v |= 0xa2;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(idx * 4))->state_mask = v;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x5c) = 0x00010000;
    g_xformEntityIdx = g_lit_00541e90;
    MStackPush2ChainPrepend_00409970();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}

/* @addr 0x004064b0 */
void MStackPushComplexCallPop_004064b0(void) {
    unsigned int idx;
    unsigned int v;
    unsigned int top;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    idx = g_scaledInit_00542044;
    v = ((ScenegraphNode *)(idx * 4))->state_mask;
    v |= 0xa2;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(idx * 4))->state_mask = v;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x5c) = 0x00010000;
    g_xformEntityIdx = g_lit_00541e94;
    MStackPush2ChainPrepend_00409970();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
