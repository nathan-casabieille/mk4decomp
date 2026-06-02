/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
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

extern void BootChainTreeRecurseWalk_00405b80(void);

/*
 * BootChainBidirRecurseWalk_00405ca0 - 297b boot mstack-push2 + dual-chain bidir walk.
 *   Push g_currentNodeIdx and g_xformEntityIdx to mstack. g_xformDirtyFlags |= 4.
 *   If g_currentNodeIdx == 0: pop+ret. g_xformDirtyFlags ^= 4. If still ==0: pop+ret.
 *   ecx = chain[+0x1c]; g_walkCallback = ecx; if <=0: skip recurse.
 *   edx = g_fightGroupHead; if 0: skip recurse. Else ecx = chain2[+0x1c]; g_walkCallback = ecx;
 *     if 0: skip recurse. Else call BootChainTreeRecurseWalk_00405b80 (sister); if paused: ret-noPop.
 *   ecx = chain[+0x14]; g_walkCallback = ecx; if !=0: g_xformEntityIdx = 4; call MStackBracket5_LinkedListUnlink_00409aa0;
 *     if paused: ret-noPop; else pop+ret.
 *   Else: eax = chain[+0x18]; g_walkCallback = eax; if 0: pop+ret. Else g_walkCallback = 0;
 *     chain[+0x18] = 0; pop+ret.
 */
extern void MStackBracket5_LinkedListUnlink_00409aa0(void);

void BootChainBidirRecurseWalk_00405ca0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        or      edx, 4
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      L_ca0_pop2
        mov     ecx, edx
        xor     ecx, 4
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      L_ca0_pop2
        mov     ecx, dword ptr [eax*4 + 0x1c]
        mov     edx, dword ptr [g_fightGroupHead]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        jle     short L_ca0_chain1
        test    edx, edx
        mov     dword ptr [g_walkCallback], edx
        je      short L_ca0_chain1
        mov     ecx, dword ptr [edx*4 + 0x1c]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        je      short L_ca0_chain1
        call    BootChainTreeRecurseWalk_00405b80
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ca0_justRet
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_fightGroupHead]
    L_ca0_chain1:
        mov     ecx, dword ptr [eax*4 + 0x14]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        je      short L_ca0_chain2
        mov     dword ptr [g_xformEntityIdx], 4
        call    MStackBracket5_LinkedListUnlink_00409aa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      short L_ca0_pop2
        ret
    L_ca0_chain2:
        mov     eax, dword ptr [eax*4 + 0x18]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_ca0_pop2
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [edx*4 + 0x18], 0
    L_ca0_pop2:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_ca0_justRet:
        }
}

