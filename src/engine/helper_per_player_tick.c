/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_distRefX;
extern unsigned int g_distRefZ;
extern unsigned int g_eventQueueSeed;
extern unsigned int g_phaseThunkSlot7;
extern unsigned int g_audioBridgeSlot2;
extern unsigned int g_dispatchVar35;
extern unsigned int g_primary_0052d74c;
extern unsigned int g_walkBoundsLimit;
extern unsigned int g_walkBoundsSlot;
extern unsigned int g_fightStateProgress;
extern unsigned int g_phaseThunkSlot6;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;
extern unsigned int g_phaseTimer;
#endif
extern unsigned int g_dispatchSave_00537ef4;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_secondary_00538068;
extern unsigned int g_phaseInstallSlot;
extern unsigned int g_phaseThunkState;
extern unsigned int g_dispatchVar14;
extern unsigned int g_scenegraphWalkEnd;
extern unsigned int g_bootInitSaveSlot;
extern unsigned int g_chainAccumCur;
extern unsigned int g_xformScratch94;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_audioBridgeSlot2 (*(unsigned int *)MK4_VA(unsigned int, 0x52d720u))
#define g_bootInitSaveSlot (*(unsigned int *)MK4_VA(unsigned int, 0x541dc4u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchVar14 (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b4u))
#define g_dispatchVar35 (*(unsigned int *)MK4_VA(unsigned int, 0x52d738u))
#define g_distRefX (*(unsigned int *)MK4_VA(unsigned int, 0x52ab04u))
#define g_distRefZ (*(unsigned int *)MK4_VA(unsigned int, 0x52ab08u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_eventQueueSeed (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_phaseInstallSlot (*(unsigned int *)MK4_VA(unsigned int, 0x53a42cu))
#define g_phaseThunkSlot6 (*(unsigned int *)MK4_VA(unsigned int, 0x535de8u))
#define g_phaseThunkSlot7 (*(unsigned int *)MK4_VA(unsigned int, 0x52ab50u))
#define g_phaseThunkState (*(unsigned int *)MK4_VA(unsigned int, 0x53a730u))
#define g_phaseTimer (*(unsigned int *)MK4_VA(unsigned int, 0x537e94u))
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_player2NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_primary_0052d74c (*(unsigned int *)MK4_VA(unsigned int, 0x52d74cu))
#define g_scenegraphWalkEnd (*(unsigned int *)MK4_VA(unsigned int, 0x541d68u))
#define g_secondary_00538068 (*(unsigned int *)MK4_VA(unsigned int, 0x538068u))
#define g_walkBoundsLimit (*(unsigned int *)MK4_VA(unsigned int, 0x535d60u))
#define g_walkBoundsSlot (*(unsigned int *)MK4_VA(unsigned int, 0x535d68u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void DualInstallCallSwap_SqDistThresholdRevertAdvance_then_SqDistThresholdRevertAdvance(void);
extern void DualInstallCallSwap_CjChainResetThreshold_then_CjChainResetThreshold(void);
extern void FpuSqrtMul(void);
extern void GeoTransformDispatchAndApply(void);
extern void Mul10Tail(void);
extern void FixedDiv16(void);
extern void ScaledStateNegCallPauseLoad(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_PerPlayerTick(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  (g_currentNodeIdx) = g_player1NodeIdx;
  g_eventQueuePending = g_player2NodeIdx;
  if ((g_player1NodeIdx != 0) && (g_player2NodeIdx != 0)) {
    g_walkCallback = MK4_NODE_AT(uint, g_player1NodeIdx, 0x54);
    g_eventQueueCurrent = MK4_NODE_AT(int, g_player1NodeIdx, 0x5c);
    iVar1 = MK4_NODE_AT(int, g_player2NodeIdx, 0x54);
    iVar3 = MK4_NODE_AT(int, g_player2NodeIdx, 0x5c);
    g_eventQueueWorkType = iVar1 - g_walkCallback;
    g_distRefX = (int)(iVar1 + g_walkCallback) >> 1;
    g_distRefZ = (int)(iVar3 + g_eventQueueCurrent) >> 1;
    g_chainAccumCur = iVar3 - g_eventQueueCurrent;
    g_eventQueueNotMask = g_eventQueueWorkType;
    g_eventQueueChild = g_chainAccumCur;
    g_eventQueueWorkType = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueWorkType,g_eventQueueWorkType);
    g_chainAccumCur = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_chainAccumCur,g_chainAccumCur);
    g_eventQueueWorkType = g_eventQueueWorkType + g_chainAccumCur;
    FpuSqrtMul();
    uVar2 = g_walkCallback;
    if (g_framePauseFlag == 0) {
      g_fightStateProgress = g_walkCallback;
      if (g_walkCallback != 0) {
        g_eventQueueWorkType = MK4_NODE_AT(uint, g_eventQueuePending, 0x40) | MK4_NODE_AT(uint, (g_currentNodeIdx), 0x40);
        g_xformScratch94 = g_eventQueueWorkType & 0x80;
        if (g_xformScratch94 == 0) {
          g_currentNodeFlags = g_walkCallback;
          g_walkCallback = g_eventQueueNotMask;
          g_eventQueueCurrent = uVar2;
          FixedDiv16();
          uVar2 = g_walkCallback;
          if (g_framePauseFlag != 0) {
            return;
          }
          g_fightAxisPosX = g_walkCallback;
          g_walkCallback = g_eventQueueChild;
          g_fightAxisNegX = -uVar2;
          g_eventQueueCurrent = g_currentNodeFlags;
          FixedDiv16();
          if (g_framePauseFlag != 0) {
            return;
          }
          g_fightAxisNegY = -g_walkCallback;
          g_fightAxisPosY = g_walkCallback;
          g_xformScratch94 =
               (MK4_NODE_AT(uint, g_eventQueuePending, 0x40) | MK4_NODE_AT(uint, (g_currentNodeIdx), 0x40)) & 0x80;
          if (g_xformScratch94 == 0) {
            g_phaseInstallSlot = g_phaseInstallSlot + -1;
            if ((int)g_phaseInstallSlot < 0) {
              g_phaseInstallSlot = 0;
            }
            if (g_phaseInstallSlot == 0) {
              g_phaseThunkSlot6 = g_walkCallback + g_distRefX;
              g_dispatchVar35 = g_distRefX + g_fightAxisNegY;
              g_phaseThunkSlot7 = g_distRefZ + g_fightAxisPosX;
              g_audioBridgeSlot2 = g_distRefZ - g_fightAxisPosX;
              g_eventQueueWorkType = g_phaseThunkSlot6 - g_walkBoundsSlot;
              g_chainAccumCur = g_audioBridgeSlot2 - g_walkBoundsLimit;
              g_walkCallback = g_walkBoundsSlot;
              g_eventQueueCurrent = g_walkBoundsLimit;
              g_eventQueueNotMask = g_dispatchVar35;
              g_eventQueueChild = g_phaseThunkSlot7;
              g_eventQueueWorkType = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueWorkType,g_eventQueueWorkType);
              g_chainAccumCur = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_chainAccumCur,g_chainAccumCur);
              g_eventQueueWorkType = g_eventQueueWorkType + g_chainAccumCur;
              g_eventQueueNotMask = g_eventQueueNotMask - g_walkCallback;
              g_eventQueueChild = g_eventQueueChild - g_eventQueueCurrent;
              g_eventQueueNotMask = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueNotMask,g_eventQueueNotMask);
              g_eventQueueChild = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueChild,g_eventQueueChild);
              g_eventQueueNotMask = g_eventQueueNotMask + g_eventQueueChild;
              g_walkBoundsSlot = g_phaseThunkSlot6;
              g_walkBoundsLimit = g_audioBridgeSlot2;
              if ((int)g_eventQueueNotMask < (int)g_eventQueueWorkType) {
                g_walkBoundsSlot = g_dispatchVar35;
                g_walkBoundsLimit = g_phaseThunkSlot7;
              }
              g_scenegraphWalkEnd = g_walkBoundsLimit - g_distRefZ;
              g_dispatchVar14 = g_walkBoundsSlot - g_distRefX;
              g_eventQueueWorkType = g_distRefX;
              g_chainAccumCur = g_distRefZ;
            }
          }
        }
      }
      g_dualC = g_eventQueueSeed;
      g_walkCallback = g_fightAxisPosY;
      if (g_fightAxisPosY == 0) {
        g_eventQueueChild = MK4_NODE_AT(uint, g_eventQueueSeed, 0x5c);
        iVar1 = MK4_NODE_AT(int, (g_currentNodeIdx), 0x5c);
      }
      else {
        g_eventQueueCurrent = g_fightAxisPosX;
        FixedDiv16();
        if (g_framePauseFlag != 0) {
          return;
        }
        g_eventQueueWorkType = MK4_NODE_AT(uint, (g_currentNodeIdx), 0x54);
        g_chainAccumCur = MK4_NODE_AT(int, (g_currentNodeIdx), 0x5c);
        g_eventQueueNotMask = MK4_NODE_AT(int, g_dualC, 0x54) - g_eventQueueWorkType;
        g_eventQueueChild = MK4_NODE_AT(int, g_dualC, 0x5c) - g_chainAccumCur;
        iVar1 = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_walkCallback,g_eventQueueNotMask);
      }
      g_phaseThunkState = (uint)(iVar1 < (int)g_eventQueueChild);
      g_primary_0052d74c = 0;
      iVar1 = MK4_NODE_AT(int, (g_currentNodeIdx), 0x6c);
      uVar2 = g_fightAxisPosX;
      if ((iVar1 != 0) ||
         (iVar1 = MK4_NODE_AT(int, (g_currentNodeIdx), 0x74), uVar2 = g_fightAxisPosY, iVar1 != 0)) {
        g_eventQueueWorkType = uVar2;
        if ((int)uVar2 < 0) {
          g_eventQueueWorkType = -uVar2;
        }
        iVar3 = iVar1;
        if (iVar1 < 0) {
          iVar3 = -iVar1;
        }
        g_chainAccumCur = iVar3 + g_eventQueueWorkType;
        iVar1 = iVar1 + uVar2;
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        if (iVar1 == g_chainAccumCur) {
          g_primary_0052d74c = 0x10000;
        }
        if (iVar1 < (int)g_chainAccumCur) {
          g_primary_0052d74c = 0xffff0000;
        }
      }
      g_secondary_00538068 = 0;
      g_eventQueueNotMask = 0;
      g_eventQueueCurrent = MK4_NODE_AT(int, g_eventQueuePending, 0x6c);
      uVar2 = g_fightAxisNegX;
      if ((g_eventQueueCurrent != 0) ||
         (g_eventQueueCurrent = MK4_NODE_AT(int, g_eventQueuePending, 0x74), uVar2 = g_fightAxisNegY, g_eventQueueCurrent != 0)
         ) {
        g_eventQueueWorkType = uVar2;
        if ((int)uVar2 < 0) {
          g_eventQueueWorkType = -uVar2;
        }
        iVar1 = g_eventQueueCurrent;
        if ((int)g_eventQueueCurrent < 0) {
          iVar1 = -g_eventQueueCurrent;
        }
        g_chainAccumCur = iVar1 + g_eventQueueWorkType;
        g_eventQueueCurrent = g_eventQueueCurrent + uVar2;
        if ((int)g_eventQueueCurrent < 0) {
          g_eventQueueCurrent = -g_eventQueueCurrent;
        }
        if (g_eventQueueCurrent == g_chainAccumCur) {
          g_secondary_00538068 = 0x10000;
          g_eventQueueNotMask = 0x10000;
        }
        if ((int)g_eventQueueCurrent < (int)g_chainAccumCur) {
          g_secondary_00538068 = 0xffff0000;
          g_eventQueueNotMask = 0xffff0000;
        }
      }
      g_bootInitSaveSlot = (*(unsigned int *)MK4_VA(unsigned int, 0x537ef4)) - 1;
      (*(unsigned int *)MK4_VA(unsigned int, 0x537ef4)) = g_bootInitSaveSlot;
      g_walkCallback = g_bootInitSaveSlot;
      if ((int)g_bootInitSaveSlot < 0) {
        g_walkCallback = 0;
        (*(unsigned int *)MK4_VA(unsigned int, 0x537ef4)) = g_walkCallback;
        DualInstallCallSwap_SqDistThresholdRevertAdvance_then_SqDistThresholdRevertAdvance();
        if (g_framePauseFlag != 0) {
          return;
        }
        g_walkCallback = g_fightStateProgress;
        if ((0x60000 < (int)g_fightStateProgress) && (ScaledStateNegCallPauseLoad(), g_framePauseFlag != 0)) {
          return;
        }
      }
      g_eventQueueCurrent = MK4_NODE_AT(int, (g_currentNodeIdx), 0x58);
      g_eventQueueWorkType = MK4_NODE_AT(int, g_eventQueuePending, 0x58) - g_eventQueueCurrent;
      if ((int)g_eventQueueWorkType < 0) {
        g_eventQueueWorkType = -g_eventQueueWorkType;
      }
      if (((int)g_eventQueueWorkType < 0xb334) &&
         (g_bootInitSaveSlot = g_phaseTimer - 1, g_phaseTimer = g_bootInitSaveSlot, g_eventQueueWorkType = g_bootInitSaveSlot,
         (int)g_bootInitSaveSlot < 0)) {
        g_eventQueueWorkType = 0;
        g_walkCallback = g_fightStateProgress;
        g_phaseTimer = g_eventQueueWorkType;
        if (((int)g_fightStateProgress < 0x8000) && (GeoTransformDispatchAndApply(), g_framePauseFlag != 0)) {
          return;
        }
      }
      DualInstallCallSwap_CjChainResetThreshold_then_CjChainResetThreshold();
    }
  }
  return;
}
#else
__declspec(naked) void Helper_PerPlayerTick(void)
{
    __asm {
        mov      eax, dword ptr [g_player1NodeIdx]
        mov      ecx, dword ptr [g_player2NodeIdx]
        push     esi
        push     edi
        test     eax, eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        je       L_983c
        test     ecx, ecx
        je       L_983c
        mov      edx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], edx
        mov      esi, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_eventQueueCurrent], esi
        mov      eax, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      ecx, dword ptr [ecx*4 + 0x5c]
        lea      edi, [eax + edx]
        sub      eax, edx
        sar      edi, 1
        mov      dword ptr [g_distRefX], edi
        lea      edi, [ecx + esi]
        sar      edi, 1
        sub      ecx, esi
        push     eax
        push     eax
        mov      dword ptr [g_distRefZ], edi
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_chainAccumCur], ecx
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_eventQueueChild], ecx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      eax, dword ptr [g_chainAccumCur]
        push     eax
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueWorkType]
        add      esp, 8
        add      ecx, eax
        mov      dword ptr [g_chainAccumCur], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        call     FpuSqrtMul
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_983c
        mov      edx, dword ptr [g_walkCallback]
        test     edx, edx
        mov      dword ptr [g_fightStateProgress], edx
        je       L_9569
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x40]
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      eax, dword ptr [eax*4 + 0x40]
        or       eax, ecx
        mov      dword ptr [g_eventQueueWorkType], eax
        and      eax, 0x80
        mov      dword ptr [g_xformScratch94], eax
        jne      L_9569
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [g_currentNodeFlags], edx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], edx
        call     FixedDiv16
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_983c
        mov      eax, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      dword ptr [g_fightAxisPosX], eax
        mov      dword ptr [g_walkCallback], edx
        neg      eax
        mov      dword ptr [g_fightAxisNegX], eax
        mov      eax, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_eventQueueCurrent], eax
        call     FixedDiv16
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_983c
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      esi, ecx
        neg      ecx
        mov      eax, ecx
        mov      dword ptr [g_fightAxisPosY], esi
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_fightAxisNegY], eax
        mov      edx, dword ptr [edx*4 + 0x40]
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], edx
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_eventQueueCurrent], eax
        or       eax, edx
        and      eax, 0x80
        mov      dword ptr [g_xformScratch94], eax
        jne      L_9569
        mov      edx, dword ptr [g_phaseInstallSlot]
        lea      eax, [edx - 1]
        test     eax, eax
        jge      L_9415
        xor      eax, eax
    L_9415:
        test     eax, eax
        mov      dword ptr [g_phaseInstallSlot], eax
        jne      L_9569
        mov      edx, dword ptr [g_distRefX]
        mov      edi, dword ptr [g_fightAxisPosX]
        lea      eax, [esi + edx]
        mov      esi, dword ptr [g_distRefZ]
        add      edx, ecx
        mov      ecx, esi
        mov      dword ptr [g_eventQueueNotMask], edx
        add      esi, edi
        mov      dword ptr [g_dispatchVar35], edx
        mov      edx, dword ptr [g_walkBoundsSlot]
        sub      ecx, edi
        mov      dword ptr [g_eventQueueChild], esi
        mov      dword ptr [g_phaseThunkSlot6], eax
        mov      dword ptr [g_phaseThunkSlot7], esi
        mov      esi, dword ptr [g_walkBoundsLimit]
        sub      eax, edx
        mov      dword ptr [g_audioBridgeSlot2], ecx
        sub      ecx, esi
        push     eax
        push     eax
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueCurrent], esi
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_chainAccumCur], ecx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      eax, dword ptr [g_chainAccumCur]
        push     eax
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      edi, dword ptr [g_walkCallback]
        mov      esi, dword ptr [g_eventQueueChild]
        mov      dword ptr [g_chainAccumCur], eax
        add      ecx, eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      ecx, dword ptr [g_eventQueueCurrent]
        sub      eax, edi
        sub      esi, ecx
        push     eax
        push     eax
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_eventQueueChild], esi
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [g_eventQueueChild]
        push     eax
        push     eax
        call     Mul10Tail
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      esi, dword ptr [g_eventQueueWorkType]
        mov      ecx, dword ptr [g_audioBridgeSlot2]
        add      edx, eax
        add      esp, 8
        mov      dword ptr [g_eventQueueChild], eax
        mov      eax, dword ptr [g_phaseThunkSlot6]
        cmp      esi, edx
        mov      dword ptr [g_eventQueueNotMask], edx
        jle      L_9531
        mov      eax, dword ptr [g_dispatchVar35]
        mov      ecx, dword ptr [g_phaseThunkSlot7]
    L_9531:
        mov      esi, dword ptr [g_distRefZ]
        mov      edx, dword ptr [g_distRefX]
        mov      dword ptr [g_walkBoundsLimit], ecx
        mov      dword ptr [g_walkBoundsSlot], eax
        sub      ecx, esi
        sub      eax, edx
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_dispatchVar14], eax
        mov      dword ptr [g_scenegraphWalkEnd], ecx
    L_9569:
        mov      ecx, dword ptr [g_fightAxisPosY]
        mov      eax, dword ptr [g_eventQueueSeed]
        test     ecx, ecx
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_walkCallback], ecx
        jne      L_959e
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueChild], edx
        mov      eax, dword ptr [eax*4 + 0x5c]
        jmp      L_9613
    L_959e:
        mov      ecx, dword ptr [g_fightAxisPosX]
        mov      dword ptr [g_eventQueueCurrent], ecx
        call     FixedDiv16
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_983c
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      esi, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_chainAccumCur], edx
        mov      eax, dword ptr [esi*4 + 0x54]
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      esi, dword ptr [esi*4 + 0x5c]
        sub      eax, ecx
        sub      esi, edx
        mov      edx, dword ptr [g_walkCallback]
        push     eax
        push     edx
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_eventQueueChild], esi
        call     Mul10Tail
        add      esp, 8
    L_9613:
        mov      edx, dword ptr [g_eventQueueChild]
        xor      ecx, ecx
        cmp      edx, eax
        jle      L_9624
        mov      ecx, 1
    L_9624:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_phaseThunkState], ecx
        mov      ecx, dword ptr [g_fightAxisPosX]
        xor      edi, edi
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_walkCallback], ecx
        mov      eax, dword ptr [edx*4 + 0x6c]
        test     eax, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        jne      L_9670
        mov      ecx, dword ptr [g_fightAxisPosY]
        mov      dword ptr [g_walkCallback], ecx
        mov      eax, dword ptr [edx*4 + 0x74]
        test     eax, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        je       L_96b8
    L_9670:
        mov      esi, ecx
        mov      edx, eax
        test     ecx, ecx
        mov      dword ptr [g_eventQueueWorkType], esi
        jge      L_9686
        neg      esi
        mov      dword ptr [g_eventQueueWorkType], esi
    L_9686:
        test     eax, eax
        jge      L_968e
        mov      edx, eax
        neg      edx
    L_968e:
        add      edx, esi
        add      eax, ecx
        mov      dword ptr [g_chainAccumCur], edx
        mov      dword ptr [g_eventQueueCurrent], eax
        jns      L_96a6
        neg      eax
        mov      dword ptr [g_eventQueueCurrent], eax
    L_96a6:
        cmp      eax, edx
        jne      L_96b1
        mov      edi, 0x10000
        cmp      eax, edx
    L_96b1:
        jge      L_96b8
        mov      edi, 0xffff0000
    L_96b8:
        mov      ecx, dword ptr [g_fightAxisNegX]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_primary_0052d74c], edi
        xor      edi, edi
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_walkCallback], ecx
        mov      eax, dword ptr [edx*4 + 0x6c]
        test     eax, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        jne      L_9704
        mov      ecx, dword ptr [g_fightAxisNegY]
        mov      dword ptr [g_walkCallback], ecx
        mov      eax, dword ptr [edx*4 + 0x74]
        test     eax, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        je       L_9758
    L_9704:
        mov      esi, ecx
        mov      edx, eax
        test     ecx, ecx
        mov      dword ptr [g_eventQueueWorkType], esi
        jge      L_971a
        neg      esi
        mov      dword ptr [g_eventQueueWorkType], esi
    L_971a:
        test     eax, eax
        jge      L_9722
        mov      edx, eax
        neg      edx
    L_9722:
        add      edx, esi
        add      eax, ecx
        mov      dword ptr [g_chainAccumCur], edx
        mov      dword ptr [g_eventQueueCurrent], eax
        jns      L_973a
        neg      eax
        mov      dword ptr [g_eventQueueCurrent], eax
    L_973a:
        cmp      eax, edx
        jne      L_974b
        mov      edi, 0x10000
        cmp      eax, edx
        mov      dword ptr [g_eventQueueNotMask], edi
    L_974b:
        jge      L_9758
        mov      edi, 0xffff0000
        mov      dword ptr [g_eventQueueNotMask], edi
    L_9758:
        mov      eax, dword ptr [g_dispatchSave_00537ef4]
        mov      dword ptr [g_secondary_00538068], edi
        dec      eax
        mov      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        test     eax, eax
        mov      dword ptr [g_bootInitSaveSlot], ecx
        jge      L_977c
        xor      eax, eax
        mov      dword ptr [g_walkCallback], eax
    L_977c:
        test     ecx, ecx
        mov      dword ptr [g_dispatchSave_00537ef4], eax
        jge      L_97ba
        call     DualInstallCallSwap_SqDistThresholdRevertAdvance_then_SqDistThresholdRevertAdvance
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_983c
        mov      eax, dword ptr [g_fightStateProgress]
        cmp      eax, 0x60000
        mov      dword ptr [g_walkCallback], eax
        jle      L_97ba
        call     ScaledStateNegCallPauseLoad
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_983c
    L_97ba:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [ecx*4 + 0x58]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      eax, dword ptr [edx*4 + 0x58]
        sub      eax, ecx
        mov      dword ptr [g_eventQueueWorkType], eax
        jns      L_97ea
        neg      eax
        mov      dword ptr [g_eventQueueWorkType], eax
    L_97ea:
        cmp      eax, 0xb333
        jg       L_9837
        mov      eax, dword ptr [g_phaseTimer]
        dec      eax
        mov      ecx, eax
        mov      dword ptr [g_eventQueueWorkType], eax
        test     eax, eax
        mov      dword ptr [g_bootInitSaveSlot], ecx
        jge      L_980f
        xor      eax, eax
        mov      dword ptr [g_eventQueueWorkType], eax
    L_980f:
        test     ecx, ecx
        mov      dword ptr [g_phaseTimer], eax
        jge      L_9837
        mov      eax, dword ptr [g_fightStateProgress]
        cmp      eax, 0x8000
        mov      dword ptr [g_walkCallback], eax
        jge      L_9837
        call     GeoTransformDispatchAndApply
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_983c
    L_9837:
        call     DualInstallCallSwap_CjChainResetThreshold_then_CjChainResetThreshold
    L_983c:
        pop      edi
        pop      esi
        ret      
    }
}
#endif

