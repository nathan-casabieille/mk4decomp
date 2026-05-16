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

#define DC197_BODY(CALL_FN)                                                    \
    __asm {                                                                    \
        __asm call    CALL_FN                                                  \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   0fh                                                      \
        __asm _emit   85h                                                      \
        __asm _emit   0b2h                                                     \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_eventQueueIdx]                         \
        __asm inc     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], ecx                               \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     edx, dword ptr [g_fightGroupHead]                        \
        __asm inc     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], edx                               \
        __asm mov     eax, dword ptr [g_baseSel_00542060]                      \
        __asm mov     ecx, dword ptr [eax*4 + 0x38]                            \
        __asm mov     dword ptr [g_fightGroupHead], ecx                        \
        __asm call    CALL_FN                                                  \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   75h                                                      \
        __asm _emit   62h                                                      \
        __asm mov     eax, dword ptr [g_fightGroupHead]                        \
        __asm mov     edx, dword ptr [eax*4 + 0x28]                            \
        __asm mov     dword ptr [g_eventQueueCurrent], edx                     \
        __asm mov     eax, dword ptr [eax*4 + 0x24]                            \
        __asm mov     dword ptr [g_xformEntityIdx], eax                        \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_fightGroupHead], ecx                        \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     edx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_eventQueueIdx], edx                         \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     eax, dword ptr [ecx*4 + 0x28]                            \
        __asm mov     dword ptr [g_walkCallback], eax                          \
        __asm mov     ecx, dword ptr [ecx*4 + 0x24]                            \
        __asm mov     dword ptr [g_scaledInit_00542044], ecx                   \
        __asm ret                                                              \
    }

/* @addr 0x0045be40 */
__declspec(naked) void DispatcherComplex197_0045be40(void) { DC197_BODY(GuardedSeq_004297b0) }

/* @addr 0x0045bf10 */
__declspec(naked) void DispatcherComplex197_0045bf10(void) { DC197_BODY(CallPauseScaledDecJmp_00429750) }
