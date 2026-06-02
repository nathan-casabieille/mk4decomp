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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
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
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
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

extern unsigned int g_dispatchSave968_004eb1e0;
extern unsigned int g_dispatchSave969_004eb240;
extern unsigned int g_dispatchSave970_004eb258;
extern void ArgSarStoreJmp(void);
extern void ComboScriptDispatchCluster(void);
extern void FiveCallGuardSetTail(void);
extern void GuardedSeq_004297b0(void);
extern void InstallSelfChainedDispatch(void);
extern void InstallSelfIndirectJmp(void);
extern void InstallSelfMStackPush_0046cc80(void);
extern void PushPopWalkSet1006(void);
extern void ScaledAndAlfe(void);
extern void ScaledInit_0048d450(void);
extern void ScaledLoadIncJmp_00429840(void);
extern void ScaledMove74to70(void);
extern void SlotEvent3EntryChain(void);

__declspec(naked) void HitStateCluster(void)
{
    __asm {
        mov      eax, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_eventQueueWorkType], eax
        and      eax, 0x200
        mov      dword ptr [g_xformScratch94], eax
        mov      eax, dword ptr [g_xformDirtyFlags]
        je       L_c7ea
        or       al, 1
        mov      dword ptr [g_xformDirtyFlags], eax
        ret      
    L_c7ea:
        and      al, 0xfe
        mov      dword ptr [g_xformDirtyFlags], eax
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
        call     ScaledMove74to70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c840
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x600
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ScaledAndAlfe
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c840
        push     OFFSET g_dispatchSave968_004eb1e0
        call     ArgSarStoreJmp
        add      esp, 4
    L_c840:
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
        nop      
        mov      eax, OFFSET g_dispatchSave969_004eb240
        sar      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        jmp      ComboScriptDispatchCluster
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
        push     OFFSET g_dispatchSave970_004eb258
        call     ArgSarStoreJmp
        add      esp, 4
        ret      
        nop      
        nop      
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], 0x51e
        mov      eax, dword ptr [ecx*4 + 0x4c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_c8aa
        mov      eax, 0x51e
        mov      dword ptr [g_walkCallback], eax
    L_c8aa:
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_c8d0
        jmp      InstallSelfIndirectJmp
        nop
        nop
        nop
        nop
    L_c8d0:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_c8ef
        jmp      FiveCallGuardSetTail
    L_c8ef:
        mov      dword ptr [eax + 8], OFFSET L_c8d0
        mov      ecx, dword ptr [g_baseSel]
        push     edi
        mov      edi, OFFSET L_c8d0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    L_c950:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_c96f
        jmp      FiveCallGuardSetTail
    L_c96f:
        mov      dword ptr [eax + 8], OFFSET L_c950
        mov      ecx, dword ptr [g_baseSel]
        push     edi
        mov      edi, OFFSET L_c950
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    L_c9d0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_cab8
        dec      eax
        mov      ebx, 1
        je       L_ca67
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_ca22
        call     InstallSelfMStackPush_0046cc80
        pop      esi
        pop      ebx
        ret      
    L_ca22:
        call     GuardedSeq_004297b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], 0x51e
        mov      eax, dword ptr [ecx*4 + 0x4c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_ca5e
        mov      eax, 0x51e
        mov      dword ptr [g_walkCallback], eax
    L_ca5e:
        mov      dword ptr [ecx*4 + 0x4c], eax
        jmp      L_ca74
    L_ca67:
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        jne      L_cac2
    L_ca74:
        call     ScaledAndAlfe
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        call     PushPopWalkSet1006
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      dword ptr [esi + 8], OFFSET L_c9d0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_cab8:
        mov      dword ptr [g_eventQueueChild], 3
    L_cac2:
        call     ScaledLoadIncJmp_00429840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_walkCallback], 0x27
        call     ScaledInit_0048d450
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ebx, 1
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, bl
        mov      dword ptr [g_eventQueueChild], edx
        je       L_cb32
        call     InstallSelfChainedDispatch
        pop      esi
        pop      ebx
        ret      
    L_cb32:
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb69
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_cb50
        call     InstallSelfMStackPush_0046cc80
        pop      esi
        pop      ebx
        ret      
    L_cb50:
        mov      dword ptr [esi + 8], OFFSET L_c9d0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_cb69:
        pop      esi
        pop      ebx
        ret      
    }
}
