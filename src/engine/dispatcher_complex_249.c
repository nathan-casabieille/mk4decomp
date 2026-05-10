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
 * both stubs in this cluster — what differs is only the second call's
 * target.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_pendingNodeType;     /* 0x0054204c */
extern unsigned int g_xformEntityIdx;      /* 0x00542048 */

extern void func_00447a90(void);
extern void func_00474290(void);
extern void func_00474050(void);

#define DC249_BODY(WORKER_FN)                                                  \
    __asm {                                                                    \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_xformEntityIdx]                        \
        __asm inc     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], ecx                               \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     edx, dword ptr [g_pendingNodeType]                       \
        __asm inc     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], edx                               \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_eventQueueTotal]                       \
        __asm inc     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], ecx                               \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     edx, dword ptr [g_eventQueueEnd]                         \
        __asm inc     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], edx                               \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_fightGroupHead]                        \
        __asm inc     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], ecx                               \
        __asm call    func_00447a90                                            \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   75h                                                      \
        __asm _emit   72h                                                      \
        __asm call    WORKER_FN                                                \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   75h                                                      \
        __asm _emit   64h                                                      \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     edx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_fightGroupHead], edx                        \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     ecx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_eventQueueEnd], ecx                         \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     edx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_eventQueueTotal], edx                       \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     ecx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_pendingNodeType], ecx                       \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     edx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_xformEntityIdx], edx                        \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm ret                                                              \
    }

/* @addr 0x00447890 */
__declspec(naked) void DispatcherComplex249_00447890(void) { DC249_BODY(func_00474290) }

/* @addr 0x00447990 */
__declspec(naked) void DispatcherComplex249_00447990(void) { DC249_BODY(func_00474050) }
