/**
 * 2 "double-call + double-push + scaled deref + double-pop + tail-deref" (197b).
 *
 * Pattern (decoded):
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret               ; long jne
 *   ; PUSH g_eventQueueIdx
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_eventQueueIdx]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   ; PUSH g_fightGroupHead
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [g_fightGroupHead]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], edx
 *   ; Install scaled child of base[0x38]
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x38]
 *   mov     [g_fightGroupHead], ecx
 *   call    Func                          ; same target as first call
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   ; Read scaled fields off new fightGroupHead
 *   mov     eax, [g_fightGroupHead]
 *   mov     edx, [eax*4 + 0x28]
 *   mov     [g_eventQueueCurrent], edx
 *   mov     eax, [eax*4 + 0x24]
 *   mov     [g_xformEntityIdx], eax
 *   ; POP fightGroupHead
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_fightGroupHead], ecx
 *   mov     [g_matrixStackTop], eax
 *   ; POP eventQueueIdx
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_eventQueueIdx], edx
 *   mov     [g_matrixStackTop], eax
 *   ; Read scaled fields off restored fightGroupHead
 *   mov     eax, [ecx*4 + 0x28]
 *   mov     [g_walkCallback], eax
 *   mov     ecx, [ecx*4 + 0x24]
 *   mov     [g_scaledInit_00542044], ecx
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

extern void GuardedSeq_004297b0(void);
extern void CallPauseScaledDecJmp_00429750(void);

#define DC197_BODY(CALL_FN)                                                   \
    do {                                                                      \
        unsigned int saved_fg;                                                \
        CALL_FN();                                                            \
        if (g_framePauseFlag != 0) return;                                    \
        g_matrixStackTop++;                                                   \
        *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueIdx;            \
        g_matrixStackTop++;                                                   \
        *(unsigned int *)(g_matrixStackTop * 4) = g_fightGroupHead;           \
        g_fightGroupHead = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);  \
        CALL_FN();                                                            \
        if (g_framePauseFlag != 0) return;                                    \
        g_eventQueueCurrent = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx; \
        g_xformEntityIdx = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;    \
        saved_fg = *(unsigned int *)(g_matrixStackTop * 4);                   \
        g_fightGroupHead = saved_fg;                                          \
        g_matrixStackTop--;                                                   \
        g_eventQueueIdx = *(unsigned int *)(g_matrixStackTop * 4);            \
        g_matrixStackTop--;                                                   \
        g_walkCallback = (void (*)(void))(((ScenegraphNode *)(saved_fg * 4))->queue_idx); \
        g_scaledInit_00542044 = ((ScenegraphNode *)(saved_fg * 4))->queue_end;       \
    } while (0)

/* @addr 0x0045be40 */
void DispatcherComplex197_0045be40(void) { DC197_BODY(GuardedSeq_004297b0); }

/* @addr 0x0045bf10 */
void DispatcherComplex197_0045bf10(void) { DC197_BODY(CallPauseScaledDecJmp_00429750); }
