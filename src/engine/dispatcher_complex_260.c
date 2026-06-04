/**
 * 2 "complex multi-call dispatcher with bit gates" (260 bytes each).
 *
 * Pattern (simplified):
 *   ; PUSH g_pendingNodeType
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_pendingNodeType]
 *   inc     eax
 *   push    ebx
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    SetupA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop                  ; long jne (rel32=0xd7)
 *   mov     al, [g_xformDirtyFlags]
 *   mov     ebx, 4
 *   test    bl, al
 *   jne     .skip_first_path           ; long jne (rel32=0x8d)
 *   ; First sub-path
 *   mov     edx, [g_currentNodeIdx]
 *   mov     eax, [g_xformEntityIdx]
 *   mov     [edx*4 + 0x38], eax
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     [g_pendingNodeType], ecx
 *   call    Worker                     ; per-helper
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop                  ; long jne (rel32=0x95)
 *   test    [g_xformDirtyFlags], bl
 *   jne     .second_init               ; short
 *   mov     edx, [g_pendingNodeType]
 *   mov     eax, [g_currentNodeIdx]
 *   mov     [edx*4 + 0x18], eax
 *   mov     edx, [g_currentNodeIdx]
 *   mov     ecx, [g_pendingNodeType]
 *   mov     [edx*4 + 0x18], ecx
 *   mov     eax, [g_pendingNodeType]
 *   mov     [g_currentNodeIdx], eax
 *   jmp     .after_init
 * .second_init:
 *   mov     ecx, [g_pendingNodeType]
 *   mov     [g_currentNodeIdx], ecx
 * .after_init:
 * .skip_first_path:
 *   call    SetupB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop                  ; (skip pop+xor, just ret)
 *   mov     [g_currentNodeIdx], 0
 * .late_pop:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_xformDirtyFlags]
 *   or      ecx, ebx                   ; set bit 2
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     eax, [g_currentNodeIdx]
 *   test    eax, eax
 *   mov     [g_pendingNodeType], edx
 *   mov     [g_xformDirtyFlags], ecx
 *   je      .ret_with_xor
 *   mov     eax, ecx
 *   xor     eax, ebx
 *   mov     [g_xformDirtyFlags], eax
 * .ret_with_xor:
 *   pop     ebx
 *   ret
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

extern void BootPhaseGateBracketedInit(void);
extern void MStackBracket1_TreeWalkRecursive2(void);
extern void FramePauseScaledStore(void);
extern void MStackPush2ChainLLInsert(void);

#define DC260_BODY(WORKER_FN)                                                  \
    __asm {                                                                    \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_pendingNodeType]                       \
        __asm inc     eax                                                      \
        __asm push    ebx                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], ecx                               \
        __asm call    BootPhaseGateBracketedInit                                            \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   0fh                                                      \
        __asm _emit   85h                                                      \
        __asm _emit   0d7h                                                     \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm mov     al, byte ptr [g_xformDirtyFlags]                         \
        __asm mov     ebx, 4                                                   \
        __asm _emit   84h                                                      \
        __asm _emit   0c3h                                                   \
        __asm _emit   0fh                                                      \
        __asm _emit   85h                                                      \
        __asm _emit   8dh                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm mov     edx, dword ptr [g_currentNodeIdx]                   \
        __asm mov     eax, dword ptr [g_xformEntityIdx]                        \
        __asm mov     dword ptr [edx*4 + 0x38], eax                            \
        __asm mov     ecx, dword ptr [g_currentNodeIdx]                   \
        __asm mov     dword ptr [g_pendingNodeType], ecx                       \
        __asm call    WORKER_FN                                                \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   0fh                                                      \
        __asm _emit   85h                                                      \
        __asm _emit   95h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm test    byte ptr [g_xformDirtyFlags], bl                         \
        __asm _emit   75h                                                      \
        __asm _emit   31h                                                      \
        __asm mov     edx, dword ptr [g_pendingNodeType]                       \
        __asm mov     eax, dword ptr [g_currentNodeIdx]                   \
        __asm mov     dword ptr [edx*4 + 0x18], eax                            \
        __asm mov     edx, dword ptr [g_currentNodeIdx]                   \
        __asm mov     ecx, dword ptr [g_pendingNodeType]                       \
        __asm mov     dword ptr [edx*4 + 0x18], ecx                            \
        __asm mov     eax, dword ptr [g_pendingNodeType]                       \
        __asm mov     dword ptr [g_currentNodeIdx], eax                   \
        __asm _emit   0ebh                                                     \
        __asm _emit   24h                                                      \
        __asm mov     ecx, dword ptr [g_pendingNodeType]                       \
        __asm mov     dword ptr [g_currentNodeIdx], ecx                   \
        __asm call    MStackPush2ChainLLInsert                                            \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   75h                                                      \
        __asm _emit   42h                                                      \
        __asm mov     dword ptr [g_currentNodeIdx], 0                     \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_xformDirtyFlags]                       \
        __asm or      ecx, ebx                                                 \
        __asm mov     edx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     eax, dword ptr [g_currentNodeIdx]                   \
        __asm test    eax, eax                                                 \
        __asm mov     dword ptr [g_pendingNodeType], edx                       \
        __asm mov     dword ptr [g_xformDirtyFlags], ecx                       \
        __asm _emit   74h                                                      \
        __asm _emit   09h                                                      \
        __asm mov     eax, ecx                                                 \
        __asm xor     eax, ebx                                                 \
        __asm mov     dword ptr [g_xformDirtyFlags], eax                       \
        __asm pop     ebx                                                      \
        __asm ret                                                              \
    }

/* @addr 0x00407030 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_dualC;
  BootPhaseGateBracketedInit();
  if (g_framePauseFlag == 0) {
    if ((g_xformDirtyFlags & 4) == 0) {
      MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x38) = g_eventQueuePending;
      g_dualC = g_currentNodeIdx;
      MStackBracket1_TreeWalkRecursive2();
      if (g_framePauseFlag != 0) {
        return;
      }
      if ((g_xformDirtyFlags & 4) == 0) {
        MK4_NODE_AT(int, g_dualC, 0x18) = g_currentNodeIdx;
        MK4_NODE_AT(int, g_currentNodeIdx, 0x18) = g_dualC;
        g_currentNodeIdx = g_dualC;
      }
      else {
        g_currentNodeIdx = g_dualC;
        MStackPush2ChainLLInsert();
        if (g_framePauseFlag != 0) {
          return;
        }
        g_currentNodeIdx = 0;
      }
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    g_dualC = *(undefined4 *)((int)g_matrixStackTop * 4);
    g_matrixStackTop = g_matrixStackTop + -1;
    if (g_currentNodeIdx != 0) {
      g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void) { DC260_BODY(MStackBracket1_TreeWalkRecursive2) }
#endif

/* @addr 0x00407400 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex260_FramePauseScaledStore(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_dualC;
  BootPhaseGateBracketedInit();
  if (g_framePauseFlag == 0) {
    if ((g_xformDirtyFlags & 4) == 0) {
      MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x38) = g_eventQueuePending;
      g_dualC = g_currentNodeIdx;
      FramePauseScaledStore();
      if (g_framePauseFlag != 0) {
        return;
      }
      if ((g_xformDirtyFlags & 4) == 0) {
        MK4_NODE_AT(int, g_dualC, 0x18) = g_currentNodeIdx;
        MK4_NODE_AT(int, g_currentNodeIdx, 0x18) = g_dualC;
        g_currentNodeIdx = g_dualC;
      }
      else {
        g_currentNodeIdx = g_dualC;
        MStackPush2ChainLLInsert();
        if (g_framePauseFlag != 0) {
          return;
        }
        g_currentNodeIdx = 0;
      }
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    g_dualC = *(undefined4 *)((int)g_matrixStackTop * 4);
    g_matrixStackTop = g_matrixStackTop + -1;
    if (g_currentNodeIdx != 0) {
      g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex260_FramePauseScaledStore(void) { DC260_BODY(FramePauseScaledStore) }
#endif
