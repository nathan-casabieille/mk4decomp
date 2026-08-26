/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

/* ============================================================
 * Phase4StateInitWithHelpers - 626b boot.
 *
 * Three packed entries in one .text block:
 *
 *   - Main at 0x4143f0 (413b, ends at 0x41458c c3): 1-slot
 *     mstack-bracketed routine that calls into a state-walker
 *     loop. Sets up a slot's field [0x30]=0x9b, [0x48]=0x28f,
 *     installs callback 0x00414590 at [+0x10], then loops over
 *     pending work via mstack pop + ChainNodeAdvanceCallback. Falls into
 *     a tail at 0x41453b on negative-stack or via the L_skip
 *     branch when bit 4 of g_xformDirtyFlags is already set.
 *
 *   - Helper A at 0x414590 (106b, ends with jmp ClampMulShiftStore):
 *     bumps slot[+0x48] += 0xCCC (cap 0x10000) and
 *     slot[+0x14] += 6 (cap 0xC0); tail-jumps to ClampMulShiftStore.
 *     Installed via the literal `mov [eax+0x10], 0x00414590`.
 *
 *   - Helper B at 0x414600 (98b, ends with jmp ClampMulShiftStore):
 *     bumps slot[+0x48] += 0x28F (cap 0x14CCC) and
 *     slot[+0x14] -= 6 (floor 0); tail-jumps to ClampMulShiftStore.
 *     Installed externally (SetDirty4XorScaledLoad
 *     uses the literal `mov ecx, 0x00414600`).
 *
 * Padding between sections is `nop` (0x90) - 3 bytes after the
 * main's `ret`, 6 bytes after Helper A's `jmp` - matching MSVC
 * 5.0's 16-byte function alignment.
 *
 * The literal callback addresses (0x00414590) avoid a DIR32
 * reloc; the original is similarly a raw imm32, so the bytes
 * must match exactly.
 * ============================================================ */

extern unsigned int g_dispatchSave916;
extern void ChainNodeAdvanceCallback(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void PushSetXfmMaskCallPop(void);
extern void ZeroAndDirty4(void);
extern void ClampMulShiftStore(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Phase4StateInitWithHelpers(void)

{
  undefined *puVar1;
  uint *puVar2;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_cj_00542054;
  g_cj_0054205c = 0;
  g_walkCallback = 0xeb85;
  ZeroAndDirty4();
  if (g_framePauseFlag == 0) {
    if ((g_xformDirtyFlags & 4) != 0) {
      g_walkCallback = 0x135a86;
      PushSetXfmMaskCallPop();
      if (g_framePauseFlag != 0) {
        return;
      }
      if ((g_xformDirtyFlags & 4) == 0) {
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x30) = 0x9b;
        (g_currentNodeIdx) = MK4_NODE_AT(int, g_cj_0054205c, 0x18);
        g_eventQueuePending = MK4_NODE_AT(int, (g_currentNodeIdx), 0x28);
        puVar2 = (uint *)(g_eventQueuePending * 4);
        puVar2[4] = (uint)&(*(unsigned int *)MK4_VA(unsigned int, 0x414590));
        puVar2[5] = 0;
        puVar2[0x12] = 0x28f;
        *puVar2 = *puVar2 | 8;
        g_dualC = g_dualC + -1;
        puVar1 = g_matrixStackTop;
        g_walkCallback = g_dualC;
        if (-1 < (int)g_dualC) {
          g_matrixStackTop = g_matrixStackTop + 1;
          *MK4_NODE(int, (int)g_matrixStackTop) = g_dualC;
          ChainNodeAdvanceCallback();
          if (g_framePauseFlag != 0) {
            return;
          }
          while( true ) {
            g_dualC = *MK4_NODE(int, (int)g_matrixStackTop) + -1;
            puVar1 = g_matrixStackTop + -1;
            if ((int)g_dualC < 0) break;
            *MK4_NODE(int, (int)g_matrixStackTop) = g_dualC;
            ChainNodeAdvanceCallback();
            if (g_framePauseFlag != 0) {
              return;
            }
          }
        }
        g_matrixStackTop = puVar1;
        (g_currentNodeIdx) = g_cj_0054205c;
        MStackCall_MStackPush2ChainPrepend_00406600();
        if (g_framePauseFlag != 0) {
          return;
        }
      }
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (g_cj_0054205c != 0) {
      g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
    g_cj_00542054 = *MK4_NODE(undefined4, (int)g_matrixStackTop);
    g_matrixStackTop = g_matrixStackTop + -1;
  }
  return;
}
#else
__declspec(naked) void Phase4StateInitWithHelpers(void)
{
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueEnd]
        inc     eax
        push    ebx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     dword ptr [g_fightGroupHead], 0
        mov     dword ptr [g_walkCallback], 0xEB85
        call    ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 4
        test    al, bl
        je      L_p4s_skip_body
        mov     edx, offset g_dispatchSave916
        shr     edx, 2
        mov     dword ptr [g_walkCallback], edx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_p4s_skip_body
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x9B
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        shl     eax, 2
        mov     dword ptr [eax + 0x10], 0x00414590
        mov     dword ptr [g_walkCallback], 0
        mov     edx, dword ptr [eax]
        mov     dword ptr [eax + 0x14], 0
        or      edx, 8
        mov     dword ptr [eax + 0x48], 0x28F
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [g_pendingNodeType]
        dec     eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_walkCallback], eax
        js      L_p4s_alt_tail
        mov     ecx, dword ptr [g_matrixStackTop]
        inc     ecx
        mov     dword ptr [g_matrixStackTop], ecx
        mov     dword ptr [ecx*4], eax
        call    ChainNodeAdvanceCallback
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
    L_p4s_loop_top:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        dec     ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [g_pendingNodeType], ecx
        js      L_p4s_alt_tail
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        call    ChainNodeAdvanceCallback
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_p4s_loop_top
        pop     ebx
        ret
    L_p4s_alt_tail:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4s_pop1
    L_p4s_skip_body:
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_fightGroupHead]
        or      ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      L_p4s_pop1_doit
        mov     eax, ecx
        xor     eax, ebx
        mov     dword ptr [g_xformDirtyFlags], eax
    L_p4s_pop1_doit:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_p4s_pop1:
        pop     ebx
        ret
        nop
        nop
        nop
    L_p4s_helperA:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4s_helperA_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x48]
        add     eax, 0xCCC
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4s_helperA_cap48_ok
        mov     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperA_cap48_ok:
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x14]
        add     eax, 6
        cmp     eax, 0xC0
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4s_helperA_cap14_ok
        mov     eax, 0xC0
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperA_cap14_ok:
        mov     dword ptr [ecx*4 + 0x14], eax
    L_p4s_helperA_tail:
        jmp     ClampMulShiftStore
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4s_helperB:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4s_helperB_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x48]
        add     eax, 0x28F
        cmp     eax, 0x14CCC
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4s_helperB_cap48_ok
        mov     eax, 0x14CCC
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperB_cap48_ok:
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x14]
        sub     eax, 6
        mov     dword ptr [g_walkCallback], eax
        jns     L_p4s_helperB_cap14_ok
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
    L_p4s_helperB_cap14_ok:
        mov     dword ptr [ecx*4 + 0x14], eax
    L_p4s_helperB_tail:
        jmp     ClampMulShiftStore
    }
}
#endif
