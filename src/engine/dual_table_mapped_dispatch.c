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

extern unsigned int g_dispatchSave137;
extern unsigned int g_load_0052ab10;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_dispatchSave62;
extern void BootInitGuardedCallChain(void);
extern void TableWalkBoundedCmp(void);
extern void ZeroThreeFields_00404ed0(void);

__declspec(naked) void DualTableMappedDispatch(void)
{
    __asm
    {
        push    esi
        push    5
        call    TableWalkBoundedCmp
        add     esp, 4
        call    BootInitGuardedCallChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, offset g_dispatchSave137
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, dword ptr [g_dlNalt1]
        mov     esi, offset g_dispatchSave62
        shr     esi, 2
        cmp     eax, 0xf
        mov     ecx, esi
        jne     short L_dtmd_skip1
        mov     eax, 6
    L_dtmd_skip1:
        cmp     eax, 0x10
        jne     short L_dtmd_skip2
        mov     eax, 2
    L_dtmd_skip2:
        cmp     eax, 0x11
        jne     short L_dtmd_skip3
        mov     eax, 7
    L_dtmd_skip3:
        add     eax, eax
        add     ecx, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     edx, dword ptr [ecx*4]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_xformEntityIdx], 0x7e20000
        call    Thunk_LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_xformEntityIdx], 0x7e00000
        call    Thunk_LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dtmd_ret
        mov     eax, dword ptr [g_dlNalt2]
        cmp     eax, 0xf
        jne     short L_dtmd_skip4
        mov     eax, 6
    L_dtmd_skip4:
        cmp     eax, 0x10
        jne     short L_dtmd_skip5
        mov     eax, 2
    L_dtmd_skip5:
        cmp     eax, 0x11
        jne     short L_dtmd_skip6
        mov     eax, 7
    L_dtmd_skip6:
        add     eax, eax
        add     esi, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_pendingNodeType], esi
        mov     edx, dword ptr [esi*4]
        inc     esi
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_pendingNodeType], esi
        mov     dword ptr [g_xformEntityIdx], 0x7f10000
        call    Thunk_LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dtmd_ret
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_xformEntityIdx], 0x7e10000
        call    Thunk_LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dtmd_ret
        mov     eax, dword ptr [g_load_0052ab10]
        mov     dword ptr [g_currentNodeIdx], eax
        lea     esi, [eax*4]
        call    ZeroThreeFields_00404ed0
        mov     eax, 0xfff88000
        mov     dword ptr [esi + 0x54], 0
        mov     dword ptr [esi + 0x58], 0x1999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [esi + 0x5c], eax
    L_dtmd_ret:
        pop     esi
        ret
    }
}
