/**
 * 3 "double-push + dual-call + double-pop + dirty XOR" helpers (181b).
 *
 * Pattern (decoded):
 *   ; PUSH g_currentNodeFlags onto matrix stack
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_currentNodeFlags]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   ; PUSH g_xformEntityIdx
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [g_xformEntityIdx]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], edx
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [g_eventQueueWorkType]
 *   mov     [g_xformEntityIdx], eax
 *   mov     [g_walkCallback], ecx
 *   call    Worker                    ; per-helper
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop                 ; (52 bytes ahead)
 * .late_pop:
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_xformEntityIdx], edx
 *   mov     edx, [g_xformDirtyFlags]
 *   mov     [g_matrixStackTop], eax
 *   mov     ecx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_currentNodeFlags], ecx
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     [g_matrixStackTop], eax
 *   mov     eax, 4
 *   or      edx, eax
 *   test    ecx, ecx
 *   mov     [g_xformDirtyFlags], edx
 *   je      .ret
 *   mov     ecx, edx
 *   xor     ecx, eax
 *   mov     [g_xformDirtyFlags], ecx
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern void Sprintf2WaySelect(void);
extern void StreamChainStringInstall(void);
extern void Push70CallScaleArith(void);
extern void Push70CallScaleArith2(void);

#define BODY(WORKER_FN)                                                       \
    __asm {                                                                   \
        __asm mov     eax, dword ptr [g_matrixStackTop]                       \
        __asm mov     ecx, dword ptr [g_currentNodeFlags]                     \
        __asm inc     eax                                                     \
        __asm mov     dword ptr [g_matrixStackTop], eax                       \
        __asm mov     dword ptr [eax*4 + 0], ecx                              \
        __asm mov     eax, dword ptr [g_matrixStackTop]                       \
        __asm mov     edx, dword ptr [g_xformEntityIdx]                       \
        __asm inc     eax                                                     \
        __asm mov     dword ptr [g_matrixStackTop], eax                       \
        __asm mov     dword ptr [eax*4 + 0], edx                              \
        __asm call    Sprintf2WaySelect                                           \
        __asm mov     eax, dword ptr [g_framePauseFlag]                       \
        __asm test    eax, eax                                                \
        __asm _emit   75h                                                     \
        __asm _emit   76h                                                     \
        __asm mov     eax, dword ptr [g_currentNodeIdx]                  \
        __asm mov     ecx, dword ptr [g_eventQueueWorkType]                   \
        __asm mov     dword ptr [g_xformEntityIdx], eax                       \
        __asm mov     dword ptr [g_walkCallback], ecx                         \
        __asm call    WORKER_FN                                               \
        __asm mov     eax, dword ptr [g_framePauseFlag]                       \
        __asm test    eax, eax                                                \
        __asm _emit   75h                                                     \
        __asm _emit   52h                                                     \
        __asm mov     eax, dword ptr [g_matrixStackTop]                       \
        __asm mov     edx, dword ptr [eax*4 + 0]                              \
        __asm dec     eax                                                     \
        __asm mov     dword ptr [g_xformEntityIdx], edx                       \
        __asm mov     edx, dword ptr [g_xformDirtyFlags]                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                       \
        __asm mov     ecx, dword ptr [eax*4 + 0]                              \
        __asm dec     eax                                                     \
        __asm mov     dword ptr [g_currentNodeFlags], ecx                     \
        __asm mov     ecx, dword ptr [g_currentNodeIdx]                  \
        __asm mov     dword ptr [g_matrixStackTop], eax                       \
        __asm mov     eax, 4                                                  \
        __asm or      edx, eax                                                \
        __asm test    ecx, ecx                                                \
        __asm mov     dword ptr [g_xformDirtyFlags], edx                      \
        __asm _emit   74h                                                     \
        __asm _emit   0ah                                                     \
        __asm mov     ecx, edx                                                \
        __asm xor     ecx, eax                                                \
        __asm mov     dword ptr [g_xformDirtyFlags], ecx                      \
        __asm ret                                                             \
    }

/* @addr 0x00426310 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex181_StreamChainStringInstall(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_currentNodeFlags;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_eventQueuePending;
  Sprintf2WaySelect();
  if (g_framePauseFlag == 0) {
    g_eventQueuePending = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    g_walkCallback = g_eventQueueWorkType;
    StreamChainStringInstall();
    if (g_framePauseFlag == 0) {
      g_eventQueuePending = *(int *)((int)g_matrixStackTop * 4);
      g_currentNodeFlags = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
      g_matrixStackTop = g_matrixStackTop + -2;
      g_xformDirtyFlags = g_xformDirtyFlags | 4;
      if ((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
      }
    }
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex181_StreamChainStringInstall(void) { BODY(StreamChainStringInstall) }
#endif

/* @addr 0x004263d0 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex181_Push70CallScaleArith(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_currentNodeFlags;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_eventQueuePending;
  Sprintf2WaySelect();
  if (g_framePauseFlag == 0) {
    g_eventQueuePending = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    g_walkCallback = g_eventQueueWorkType;
    Push70CallScaleArith();
    if (g_framePauseFlag == 0) {
      g_eventQueuePending = *(int *)((int)g_matrixStackTop * 4);
      g_currentNodeFlags = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
      g_matrixStackTop = g_matrixStackTop + -2;
      g_xformDirtyFlags = g_xformDirtyFlags | 4;
      if ((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
      }
    }
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex181_Push70CallScaleArith(void) { BODY(Push70CallScaleArith) }
#endif

/* @addr 0x00426490 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex181_Push70CallScaleArith2(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_currentNodeFlags;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_eventQueuePending;
  Sprintf2WaySelect();
  if (g_framePauseFlag == 0) {
    g_eventQueuePending = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    g_walkCallback = g_eventQueueWorkType;
    Push70CallScaleArith2();
    if (g_framePauseFlag == 0) {
      g_eventQueuePending = *(int *)((int)g_matrixStackTop * 4);
      g_currentNodeFlags = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
      g_matrixStackTop = g_matrixStackTop + -2;
      g_xformDirtyFlags = g_xformDirtyFlags | 4;
      if ((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
      }
    }
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex181_Push70CallScaleArith2(void) { BODY(Push70CallScaleArith2) }
#endif
