/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004779d0 (80b)
 *   Multi-gate dispatch: if [0x54355c]: ret;
 *   if [0x543714] == 0: tail-call F1 then jmp T (no early ret);
 *   if [0x53a408] != 0: call F1, pause → ret;
 *   if [0x537e88] != 0: tail-call F2.
 */
extern unsigned int g_audioPathFlag;
extern unsigned int g_audioMatchStartFlag;
extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;
extern void DualSeqBranchInit(void);
extern void YRiseSpawnerCluster(void);
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int MultiGateDispatchCallJmp(void)

{
  int iVar1;
  
  iVar1 = g_audioPathFlag;
  if (g_audioPathFlag == 0) {
    if (g_audioMatchStartFlag == 0) {
      DualSeqBranchInit();
      iVar1 = g_framePauseFlag;
      if (g_framePauseFlag == 0) {
        iVar1 = YRiseSpawnerCluster();
        return iVar1;
      }
    }
    else {
      if ((g_active_0053a408 != 0) && (DualSeqBranchInit(), g_framePauseFlag != 0)) {
        return g_framePauseFlag;
      }
      iVar1 = 0;
      if (g_active_00537e88 != 0) {
        YRiseSpawnerCluster();
        iVar1 = g_framePauseFlag;
      }
    }
  }
  return iVar1;
}
#else
__declspec(naked) void MultiGateDispatchCallJmp(void) {
    __asm {
        mov     eax, dword ptr [g_audioPathFlag]
        test    eax, eax
        _emit   75h
        _emit   33h
        mov     eax, dword ptr [g_audioMatchStartFlag]
        test    eax, eax
        _emit   74h
        _emit   2bh
        mov     eax, dword ptr [g_active_0053a408]
        test    eax, eax
        _emit   74h
        _emit   0eh
        call    DualSeqBranchInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        mov     eax, dword ptr [g_active_00537e88]
        test    eax, eax
        _emit   74h
        _emit   0ah
        call    YRiseSpawnerCluster
        mov     eax, dword ptr [g_framePauseFlag]
ret_label:
        ret
        call    DualSeqBranchInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     ret_label
        jmp     YRiseSpawnerCluster
    }
}
#endif
