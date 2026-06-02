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

/*
 * BootMultiAssetLoadStateInit - 258b boot multi-asset loader chain.
 *   push 8; TableWalkBoundedCmp; g_currentNodeIdx = (0x00506c14>>2);
 *   call LoadGeoAsset_Default; if paused: ret. g_currentNodeIdx = (0x00506c14>>2) again;
 *   call LoadGeoAsset_Default; if paused: ret. g_xformEntityIdx = (0x005080d8>>2);
 *   call DispatcherComplex260_FramePauseScaledStore; if paused: ret. esi=0x1f; chain[g_currentNodeIdx*4 + 0x54] = 0x00627d70;
 *   g_walkCallback=0x1f; chain[g_currentNodeIdx*4 + 0x30]=0x1f; call PushSetCallPop; if paused: ret.
 *   call RegistryPushBindPop; if paused: ret. g_xformEntityIdx = (0x005080bc>>2);
 *   call DispatcherComplex260; if paused: ret. chain[g_currentNodeIdx*4 + 0x54] = 0x8bff9b80;
 *   g_walkCallback=0x1f; chain[+0x30]=0x1f; call PushSetCallPop; if paused: ret. Tail-call RegistryPushBindPop.
 */
extern unsigned int g_assetLoadStateInit;
extern unsigned int g_dispatchSave143;
extern unsigned int g_dispatchSave142;
extern void RegistryPushBindPop(void);
extern void TableWalkBoundedCmp(void);

__declspec(naked) void BootMultiAssetLoadStateInit(void)
{
    __asm
    {
        push    esi
        push    8
        call    TableWalkBoundedCmp
        mov     eax, offset g_assetLoadStateInit
        add     esp, 4
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ml_ret
        mov     ecx, offset g_assetLoadStateInit
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        call    LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ml_ret
        mov     edx, offset g_dispatchSave142
        shr     edx, 2
        mov     dword ptr [g_xformEntityIdx], edx
        call    DispatcherComplex260_FramePauseScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ml_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     esi, 0x1f
        mov     dword ptr [eax*4 + 0x54], 0x00627d70
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [ecx*4 + 0x30], esi
        call    PushSetCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_ml_ret
        call    RegistryPushBindPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_ml_ret
        mov     edx, offset g_dispatchSave143
        shr     edx, 2
        mov     dword ptr [g_xformEntityIdx], edx
        call    DispatcherComplex260_FramePauseScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_ml_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x54], 0xff9b8000
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [ecx*4 + 0x30], esi
        call    PushSetCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_ml_ret
        call    RegistryPushBindPop
    L_ml_ret:
        pop     esi
        ret
    }
}
