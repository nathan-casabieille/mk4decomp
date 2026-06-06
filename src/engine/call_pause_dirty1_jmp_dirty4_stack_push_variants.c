/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_phaseTimer;

/* @addr 0x00428850 (84b)
 *   call F1; pause → ret; testb 1,[dirty]; je +5 → jmp T1;
 *   call F2; pause → ret; testb 4,[dirty]; je +0x1b →ret-tail;
 *   inc g_matrixStackTop; push 0x00428950 onto stack[idx*4]; jmp T2.
 */
extern void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
extern void ScaledInitOrSelfPtr_StackPopDispatchTagged(void);
extern void DirtyToggleByGate(void);
extern void func_00428950_oo(void);
extern void GameDispatchValidateState(void);
extern void InstallSelfCallBitGate(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void CallPauseDirty1JmpDirty4StackPush_GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void)

{
  GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp();
  if (g_framePauseFlag == 0) {
    if (((byte)g_xformDirtyFlags & 1) != 0) {
      ScaledInitOrSelfPtr_StackPopDispatchTagged();
      return;
    }
    DirtyToggleByGate();
    if (g_framePauseFlag == 0) {
      if (((byte)g_xformDirtyFlags & 4) != 0) {
        g_matrixStackTop = g_matrixStackTop + 1;
        *(code **)((int)g_matrixStackTop * 4) = ScaledInitOrSelfPtr_CallPauseDirty1JmpDirty4StackPush;
        GameDispatchValidateState();
        return;
      }
      ScaledInitOrSelfPtr_CallPauseDirty1JmpDirty4StackPush();
      return;
    }
  }
  return;
}
#else
__declspec(naked) void CallPauseDirty1JmpDirty4StackPush_GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void) {
    __asm {
        call    GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   45h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     ScaledInitOrSelfPtr_StackPopDispatchTagged
        call    DirtyToggleByGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_00428950_oo
        jmp     GameDispatchValidateState
        _emit   0e9h
        _emit   0adh
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}
#endif

/* @addr 0x00483a80 (84b): same shape, push 0x00483ae0 instead of 0x00428950 */
extern void GuardedDoubleIncCmpJmp(void);
extern void LiteralPushCallEntZero(void);
extern void func_0048f330_oo(void);
extern void func_0042b988_oo(void);
__declspec(naked) void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void) {
    __asm {
        call    GuardedDoubleIncCmpJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   45h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     LiteralPushCallEntZero
        call    func_0048f330_oo
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET InstallSelfCallBitGate
        jmp     func_0042b988_oo
        _emit   0e9h
        _emit   0dh
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}
