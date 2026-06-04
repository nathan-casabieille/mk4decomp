/**
 * Call + pause-check + scaled decrement dispatcher.
 *
 * Naked because of dec-flag preservation across store
 * (`dec ecx; mov [g], ecx; js`).
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

/* @addr 0x00429750 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x28]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   js      +5
 *   jmp     -0x88
 *   mov     [g_eventQueueCurrent], 0
 *   jmp     -0x57
 *   ret
 */
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledStoreCurDirtyClear(void);
extern void ScaledStoreCurDirtyOr1(void);
extern u32 g_framePauseFlag;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void CallPauseScaledDecJmp(void)

{
  GuardedChainCmpDualBitXor();
  if (g_framePauseFlag != 0) {
    return;
  }
  g_eventQueueCurrent = MK4_NODE_AT(int, g_cj_0054205c, 0x28) + -1;
  if (-1 < g_eventQueueCurrent) {
    ScaledStoreCurDirtyClear();
    return;
  }
  g_eventQueueCurrent = 0;
  MK4_NODE_AT(undefined4, g_cj_0054205c, 0x28) = 0;
  g_xformDirtyFlags = g_xformDirtyFlags | 1;
  return;
}
#else
__declspec(naked) void CallPauseScaledDecJmp(void) {
    __asm {
        call    GuardedChainCmpDualBitXor
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_cpsdj_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        js      short L_cpsdj_neg
        jmp     ScaledStoreCurDirtyClear
L_cpsdj_neg:
        mov     dword ptr [g_eventQueueCurrent], 0
        jmp     ScaledStoreCurDirtyOr1
L_cpsdj_ret:
        ret
    }
}
#endif
