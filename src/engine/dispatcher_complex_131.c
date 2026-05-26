/**
 * 2 "matrix-stack push with literal + scaled finalize" helpers (131b).
 *
 * Pattern:
 *   mov     eax, [g_audioStreamState_0053a430]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   jne     .check_x
 *   mov     eax, [g_tickFlagF]
 *   cmp     eax, 2
 *   mov     [g_eventQueueCurrent], eax
 *   je      .ret
 * .check_x:
 *   ; PUSH walkCallback w/ literal pointer arg
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_walkCallback]
 *   inc     eax
 *   push    LITERAL_PTR
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   ; POP into walkCallback + propagate
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_walkCallback], ecx
 *   mov     [g_matrixStackTop], eax
 *   mov     [edx*4 + 0x18], ecx
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_fightGroupHead]
 *   mov     [eax*4 + 0x24], ecx
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_audioStreamState_0053a430;
extern unsigned int g_tickFlagF;
extern void *g_lit_004e39d8;
extern void *g_lit_004e3a28;
extern int  PackedAdvanceCallContinue_0048e630(void *p);

/* @addr 0x00431530 */
void DispatcherComplex131_00431530(void) {
    unsigned int v;
    unsigned int top;
    unsigned int scaled;
    unsigned int popped;
    v = g_audioStreamState_0053a430;
    g_eventQueueCurrent = v;
    if (v == 0) {
        v = g_tickFlagF;
        g_eventQueueCurrent = v;
        if (v == 2) return;
    }
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)g_walkCallback;
    PackedAdvanceCallContinue_0048e630(&g_lit_004e39d8);
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    scaled = g_scaledInit_00542044;
    popped = *(unsigned int *)(top * 4);
    g_walkCallback = (void (*)(void))popped;
    g_matrixStackTop = top - 1;
    ((ScenegraphNode *)(scaled * 4))->child_chain = popped;
    {
        unsigned int s2 = g_scaledInit_00542044;
        unsigned int fg = g_fightGroupHead;
        ((ScenegraphNode *)(s2 * 4))->queue_end = fg;
    }
}

/* @addr 0x004315c0 */
void DispatcherComplex131_004315c0(void) {
    unsigned int v;
    unsigned int top;
    unsigned int scaled;
    unsigned int popped;
    v = g_audioStreamState_0053a430;
    g_eventQueueCurrent = v;
    if (v == 0) {
        v = g_tickFlagF;
        g_eventQueueCurrent = v;
        if (v == 2) return;
    }
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)g_walkCallback;
    PackedAdvanceCallContinue_0048e630(&g_lit_004e3a28);
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    scaled = g_scaledInit_00542044;
    popped = *(unsigned int *)(top * 4);
    g_walkCallback = (void (*)(void))popped;
    g_matrixStackTop = top - 1;
    ((ScenegraphNode *)(scaled * 4))->child_chain = popped;
    {
        unsigned int s2 = g_scaledInit_00542044;
        unsigned int fg = g_fightGroupHead;
        ((ScenegraphNode *)(s2 * 4))->queue_end = fg;
    }
}
