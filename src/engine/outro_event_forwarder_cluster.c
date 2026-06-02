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

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
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

extern unsigned int g_dispatchSave766;
extern unsigned int g_dispatchSave767;
extern unsigned int g_dispatchSave768;
extern unsigned int g_dispatchSave769;
extern unsigned int g_dispatchSave770;
extern unsigned int g_dispatchSave771;
extern unsigned int g_dispatchSave772;
extern void ArgSarStoreJmp(void);
extern void CmpP1DualInitStore_00482ab0(void);
extern void FiveCallGuardSetTail(void);
extern void GateDispatch6c(void);
extern void Phase3Packed3EntryDispatch(void);
extern void QuadBlockDispatch(void);
extern void QuadBlockInstallChainThunks(void);
extern void ScaledAndAlf7(void);
extern void ScaledCmpJlJmp(void);
extern void ScaledDecOrZero(void);
extern void ScaledMove48to58(void);

__declspec(naked) void OutroEventForwarderCluster(void)
{
    __asm {
    L_5e70:
        call     ScaledAndAlf7
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5e8d
        mov      dword ptr [g_walkCallback], 3
        jmp      ScaledCmpJlJmp
    L_5e8d:
        ret
        nop
        nop
        call     ScaledDecOrZero
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5efc
        call     ScaledAndAlf7
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5efc
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x80]
        cmp      ecx, 0x3333
        mov      dword ptr [g_walkCallback], ecx
        jl       short L_5ecb
        jmp      QuadBlockInstallChainThunks
    L_5ecb:
        mov      eax, dword ptr [eax*4 + 0x34]
        cmp      eax, 0xf
        mov      dword ptr [g_walkCallback], eax
        jne      short L_5ee1
        jmp      QuadBlockInstallChainThunks
    L_5ee1:
        call     L_5e70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5efc
        push     OFFSET g_dispatchSave766
        call     ArgSarStoreJmp
        add      esp, 4
    L_5efc:
        ret
        nop
        nop
        nop
        call     ScaledDecOrZero
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5f54
        call     ScaledAndAlf7
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5f54
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x80]
        cmp      eax, 0x3333
        mov      dword ptr [g_walkCallback], eax
        jl       short L_5f39
        jmp      QuadBlockInstallChainThunks
    L_5f39:
        call     L_5e70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5f54
        push     OFFSET g_dispatchSave767
        call     ArgSarStoreJmp
        add      esp, 4
    L_5f54:
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
        push     OFFSET g_dispatchSave768
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5fa7
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5fa7
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_5f9a
        jmp      QuadBlockDispatch
    L_5f9a:
        push     OFFSET g_dispatchSave769
        call     ArgSarStoreJmp
        add      esp, 4
    L_5fa7:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5fe2
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x100a
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave770
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp
        add      esp, 4
    L_5fe2:
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
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_600b
        push     OFFSET g_dispatchSave771
        call     ArgSarStoreJmp
        add      esp, 4
    L_600b:
        ret
        nop
        nop
        nop
        nop
        mov      dword ptr [g_walkCallback], 0x9999
        call     CmpP1DualInitStore_00482ab0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6051
        call     ScaledMove48to58
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6051
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6051
        push     OFFSET g_dispatchSave772
        call     ArgSarStoreJmp
        add      esp, 4
    L_6051:
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
    L_6060:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        push     edi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        sub      ecx, edx
        je       short L_60bb
        dec      ecx
        je       short L_6085
        call     FiveCallGuardSetTail
        pop      edi
        ret
    L_6085:
        mov      ecx, dword ptr [g_eventQueueChild]
        dec      ecx
        mov      dword ptr [g_eventQueueChild], ecx
        jne      short L_60c5
        mov      dword ptr [eax + 8], OFFSET L_6060
        mov      dword ptr [eax + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    L_60bb:
        mov      dword ptr [g_eventQueueChild], 0xa
    L_60c5:
        mov      dword ptr [g_currentNodeFlags], 0x147a
        mov      dword ptr [eax + 8], OFFSET L_6060
        mov      ecx, dword ptr [g_baseSel]
        mov      edi, OFFSET L_6060
        add      edi, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     Phase3Packed3EntryDispatch
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    }
}
