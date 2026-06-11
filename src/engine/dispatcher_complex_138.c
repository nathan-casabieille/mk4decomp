/**
 * 2 "matrix-stack push + state walk loop + dirty XOR" helpers (138b).
 *
 * Pattern (decoded):
 *   ; PUSH g_eventQueueCurrent
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_eventQueueCurrent]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   ; Load scaled + walkCallback
 *   mov     eax, [g_currentNodeIdx]
 *   mov     edx, [g_walkCallback]
 *   test    eax, eax
 *   jne     .pop                         ; if scaled non-zero, skip walk
 *   ; State walk loop
 *   mov     eax, [g_state]               ; per-helper
 *   test    eax, eax
 *   mov     [g_currentNodeIdx], eax
 *   je      .pop
 * .loop:
 *   mov     ecx, [eax*4 + 0x30]          ; next field
 *   cmp     edx, ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   je      .pop
 *   mov     eax, [eax*4 + 0]             ; deref via SIB+0
 *   jmp     .loop                        ; loop back
 * .pop:
 *   mov     ecx, [g_matrixStackTop]
 *   mov     edx, [ecx*4 + 0]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], edx
 *   mov     edx, [g_xformDirtyFlags]
 *   mov     [g_matrixStackTop], ecx
 *   mov     ecx, 4
 *   or      edx, ecx                     ; set bit 2
 *   test    eax, eax
 *   mov     [g_xformDirtyFlags], edx     ; persist
 *   je      .ret_simple                  ; if no walked entry, finalize
 *   mov     eax, edx
 *   xor     eax, ecx                     ; clear bit 2
 *   mov     [g_xformDirtyFlags], eax
 * .ret_simple:
 *   ret
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_dispatchSave_0053a2c0;
extern unsigned int g_cj_00535df0;

/* @addr 0x00476060 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex138_00476060(void)

{
  int iVar1;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_eventQueueCurrent;
  iVar1 = (*(unsigned int *)MK4_VA(unsigned int, 0x53a2c0));
  if ((g_currentNodeIdx) != 0) goto LAB_004760a6;
  while (((g_currentNodeIdx) = iVar1, iVar1 != 0 && (g_walkCallback != MK4_NODE_AT(int, iVar1, 0x30)))) {
LAB_004760a6:
    iVar1 = *MK4_NODE(int, (g_currentNodeIdx));
  }
  g_eventQueueCurrent = *MK4_NODE(undefined4, (int)g_matrixStackTop);
  g_matrixStackTop = g_matrixStackTop + -1;
  g_xformDirtyFlags = g_xformDirtyFlags | 4;
  if (iVar1 != 0) {
    g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex138_00476060(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_walkCallback]
        test    eax, eax
        _emit   75h
        _emit   1fh
        mov     eax, dword ptr [g_dispatchSave_0053a2c0]
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        _emit   74h
        _emit   1ah
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     edx, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   74h
        _emit   09h
        mov     eax, dword ptr [eax*4 + 0]
        _emit   0ebh
        _emit   0ddh
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [ecx*4 + 0]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_matrixStackTop], ecx
        mov     ecx, 4
        or      edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   09h
        mov     eax, edx
        xor     eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}
#endif

/* @addr 0x004760f0 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex138_004760f0(void)

{
  int iVar1;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_eventQueueCurrent;
  iVar1 = g_cj_00535df0;
  if ((g_currentNodeIdx) != 0) goto LAB_00476136;
  while (((g_currentNodeIdx) = iVar1, iVar1 != 0 && (g_walkCallback != MK4_NODE_AT(int, iVar1, 0x30)))) {
LAB_00476136:
    iVar1 = *MK4_NODE(int, (g_currentNodeIdx));
  }
  g_eventQueueCurrent = *MK4_NODE(undefined4, (int)g_matrixStackTop);
  g_matrixStackTop = g_matrixStackTop + -1;
  g_xformDirtyFlags = g_xformDirtyFlags | 4;
  if (iVar1 != 0) {
    g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex138_004760f0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_walkCallback]
        test    eax, eax
        _emit   75h
        _emit   1fh
        mov     eax, dword ptr [g_cj_00535df0]
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        _emit   74h
        _emit   1ah
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     edx, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   74h
        _emit   09h
        mov     eax, dword ptr [eax*4 + 0]
        _emit   0ebh
        _emit   0ddh
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [ecx*4 + 0]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_matrixStackTop], ecx
        mov     ecx, 4
        or      edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   09h
        mov     eax, edx
        xor     eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}
#endif
