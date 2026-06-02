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
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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

extern unsigned int g_pendingMatchVar;
extern unsigned int g_dispatchSave930;
extern unsigned int g_dispatchSave931;
extern void AudioMixerStep(void);
extern void ChainInitMul10BulkStore(void);
extern void CopyThreeFields(void);
extern void DispatcherComplex138_004760f0(void);
extern void FourSegmentPoseWalk(void);
extern void MStackCall_00406600(void);
extern void PendingMatch_ArgSarStoreJmp_004411d0(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledOr4Jmp(void);
extern void SpawnFreezeProjectileChain(void);
extern void StoreLoadJmp(void);
extern void ThreeChanPackClamp(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void SpawnEffectCluster(void)
{
    __asm {
    L_20a0:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        push     ebx
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      esi, 0x91
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_currentNodeIdx], 0
        mov      dword ptr [g_walkCallback], esi
        call     DispatcherComplex138_004760f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2165
        mov      bl, 4
    L_20e3:
        test     byte ptr [g_xformDirtyFlags], bl
        mov      eax, dword ptr [g_matrixStackTop]
        jne      L_2152
        mov      edx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     ScaledOr4Jmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2165
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [g_walkCallback], esi
        call     DispatcherComplex138_004760f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_20e3
        pop      esi
        pop      ebx
        ret      
    L_2152:
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_2165:
        pop      esi
        pop      ebx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_2170:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        mov      edi, OFFSET L_2170
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_21b0
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_walkCallback], ecx
        jmp      L_224b
    L_21b0:
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueEnd]
        push     OFFSET L_23c0
        mov      dword ptr [edx*4 + 0x64], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [ecx*4 + 0x68], edx
        call     StoreLoadJmp
        add      esp, 4
        push     OFFSET PendingMatch_ArgSarStoreJmp_004411d0 + 0xb60
        call     StoreLoadJmp
        mov      eax, dword ptr [g_eventQueueEnd]
        add      esp, 4
        mov      dword ptr [g_fightGroupHead], eax
        push     0x806000
        call     ThreeChanPackClamp
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     ecx
        call     CopyThreeFields
        add      esp, 4
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      dword ptr [g_eventQueueEnd], 3
    L_2243:
        mov      eax, OFFSET g_dispatchSave930
        shr      eax, 2
    L_224b:
        mov      dword ptr [g_eventQueueIdx], eax
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_227e
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      L_2243
        call     L_20a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_22d6
        pop      edi
        pop      esi
        ret      
    L_227e:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, OFFSET g_dispatchSave931
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, 4
        mov      dword ptr [g_fightGroupHead], ecx
        je       L_22de
    L_22d6:
        call     Thunk_ScaledNeg1SetPause
        pop      edi
        pop      esi
        ret      
    L_22de:
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [edx*4]
        mov      dword ptr [g_walkCallback], eax
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x54], eax
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_pendingMatchVar]
        mov      dword ptr [g_walkCallback], edx
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23af
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x68], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], edi
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_23af:
        pop      edi
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_23c0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 3
        ja       L_24f7
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_23ee:
        call     SpawnFreezeProjectileChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 3
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_2427:
        mov      ecx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [ecx*4 + 0x64]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 4
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_2476:
        call     FourSegmentPoseWalk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_24af:
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [edx*4 + 0x64], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, 1
        mov      dword ptr [ecx*4 + 0x68], edx
        mov      dword ptr [esi + 8], OFFSET L_23c0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_24f7:
        call     FourSegmentPoseWalk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        call     ChainInitMul10BulkStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2518
        call     Thunk_ScaledNeg1SetPause
    L_2518:
        pop      esi
        ret
        _emit 0x8b
        _emit 0xff
    L_jmptbl:
        _emit 0xaf
        _emit 0x24
        _emit 0x44
        _emit 0x00
        _emit 0xee
        _emit 0x23
        _emit 0x44
        _emit 0x00
        _emit 0x27
        _emit 0x24
        _emit 0x44
        _emit 0x00
        _emit 0x76
        _emit 0x24
        _emit 0x44
        _emit 0x00
    }
}
