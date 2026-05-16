/**
 * 2 "five-push + dual-call + five-pop" helpers (249 bytes each).
 *
 * Pattern:
 *   ; PUSH eventQueueIdx, eventQueuePending(?), eventQueueTotal,
 *   ;      eventQueueEnd, fightGroupHead onto matrix stack
 *   (5x: load + inc top + store top + push)
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    Worker                  ; per-helper
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   ; POP back into the 5 globals (in reverse order: fight, end, total,
 *   ;       0x0054204c at 0x00447890 / 0x00542048 at 0x00447990, idx)
 *   (5x: load top + dec + store)
 * .ret:
 *   ret
 *
 * Note: the address ordering of the pop sequence is identical between
 * both stubs in this cluster - what differs is only the second call's
 * target.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern u32 g_pendingNodeType;     /* 0x0054204c */
extern packed_ptr g_xformEntityIdx;      /* 0x00542048 */

extern void PendingMatch_00447a90(void);
extern void DualPushSet7dCallPop_00474290(void);
extern void DoubleStackPushAndJmp7d_00474050(void);

#define DC249_BODY(WORKER_FN)                                                  \
    do {                                                                       \
        g_matrixStackTop++;                                                    \
        *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;            \
        g_matrixStackTop++;                                                    \
        *(unsigned int *)(g_matrixStackTop * 4) = g_pendingNodeType;           \
        g_matrixStackTop++;                                                    \
        *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueTotal;           \
        g_matrixStackTop++;                                                    \
        *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueEnd;             \
        g_matrixStackTop++;                                                    \
        *(unsigned int *)(g_matrixStackTop * 4) = g_fightGroupHead;            \
        PendingMatch_00447a90();                                               \
        if (g_framePauseFlag != 0) return;                                     \
        WORKER_FN();                                                           \
        if (g_framePauseFlag != 0) return;                                     \
        g_fightGroupHead = *(unsigned int *)(g_matrixStackTop * 4);            \
        g_matrixStackTop--;                                                    \
        g_eventQueueEnd = *(unsigned int *)(g_matrixStackTop * 4);             \
        g_matrixStackTop--;                                                    \
        g_eventQueueTotal = *(unsigned int *)(g_matrixStackTop * 4);           \
        g_matrixStackTop--;                                                    \
        g_pendingNodeType = *(unsigned int *)(g_matrixStackTop * 4);           \
        g_matrixStackTop--;                                                    \
        g_xformEntityIdx = *(unsigned int *)(g_matrixStackTop * 4);            \
        g_matrixStackTop--;                                                    \
    } while (0)

/* @addr 0x00447890 */
void DispatcherComplex249_00447890(void) { DC249_BODY(DualPushSet7dCallPop_00474290); }

/* @addr 0x00447990 */
void DispatcherComplex249_00447990(void) { DC249_BODY(DoubleStackPushAndJmp7d_00474050); }
