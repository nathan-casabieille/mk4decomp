/**
 * 2 "matrix-stack push with literal + scaled finalize" helpers (131b).
 *
 * Pattern:
 *   mov     eax, [g_audioStreamState]
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
 *   mov     edx, [g_currentNodeIdx]
 *   mov     ecx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_walkCallback], ecx
 *   mov     [g_matrixStackTop], eax
 *   mov     [edx*4 + 0x18], ecx
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [g_fightGroupHead]
 *   mov     [eax*4 + 0x24], ecx
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_audioStreamState;
extern unsigned int g_tickFlagF;
extern void *g_litArg12_a;
extern void *g_litArg12_b;
extern int  PackedAdvanceCallContinue(void *p);

/* @addr 0x00431530 */
void DispatcherComplex131_00431530(void) {
    unsigned int v;
    unsigned int top;
    unsigned int scaled;
    unsigned int popped;
    v = g_audioStreamState;
    g_eventQueueCurrent = v;
    if (v == 0) {
        v = g_tickFlagF;
        g_eventQueueCurrent = v;
        if (v == 2) return;
    }
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)g_walkCallback;
    PackedAdvanceCallContinue(&g_litArg12_a);
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    scaled = g_currentNodeIdx;
    popped = *(unsigned int *)(top * 4);
    g_walkCallback = (void (*)(void))popped;
    g_matrixStackTop = top - 1;
    ((ScenegraphNode *)(scaled * 4))->child_chain = popped;
    {
        unsigned int s2 = g_currentNodeIdx;
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
    v = g_audioStreamState;
    g_eventQueueCurrent = v;
    if (v == 0) {
        v = g_tickFlagF;
        g_eventQueueCurrent = v;
        if (v == 2) return;
    }
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)g_walkCallback;
    PackedAdvanceCallContinue(&g_litArg12_b);
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    scaled = g_currentNodeIdx;
    popped = *(unsigned int *)(top * 4);
    g_walkCallback = (void (*)(void))popped;
    g_matrixStackTop = top - 1;
    ((ScenegraphNode *)(scaled * 4))->child_chain = popped;
    {
        unsigned int s2 = g_currentNodeIdx;
        unsigned int fg = g_fightGroupHead;
        ((ScenegraphNode *)(s2 * 4))->queue_end = fg;
    }
}
