/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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

/* @addr 0x0049ea30 (216b game) - dual-guard then state-machine init. */
extern unsigned int g_state2_0053a1bc;
extern unsigned int g_state2_0053a354;
extern u32 g_dlMode;
extern unsigned int g_audioBitField;
extern void MStackCall_MStackPush2ChainInsert_004062a0(void);
extern void SaveCallRestoreOrXor(void);
extern void SaveCallRestore(void);
extern void ThrowFlowSetupCluster(void);
extern void Wrapper_SaveCallRestore(void);

void DualGuardStateMachine(void) {
    __asm {
        mov     eax, dword ptr [g_dlMode]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0eh
        mov     eax, dword ptr [g_state2_0053a1bc]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0eh
        push    0x00000266
        call    SaveCallRestore
        add     esp, 4
        ret
        push    0x00000266
        call    SaveCallRestoreOrXor
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        test    al, 4
        _emit   0fh
        _emit   84h
        _emit   93h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_audioBitField]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        call    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   63h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   5ah
        call    MStackCall_MStackPush2ChainInsert_004062a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4ch
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [ecx*4 + 0x30], 0x00000266
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_walkCallback], 2
        call    ThrowFlowSetupCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x0000028f
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5c], eax
        }
}

/* @addr 0x0049eb20 (216b game) - variant of DualGuardStateMachine, uses 0x267 tag and
 *   [scaledInit*4+4] field instead of 0x266 and [scaledInit*4+0]. Initial path differs: jmp Wrapper_SaveCallRestore.
 */

__declspec(naked) void DualGuardStateMachine_SaveCallRestore(void) {
    __asm {
        mov     eax, dword ptr [g_dlMode]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     Wrapper_SaveCallRestore
        mov     eax, dword ptr [g_state2_0053a354]
        push    0x00000267
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   09h
        call    SaveCallRestore
        add     esp, 4
        ret
        call    SaveCallRestoreOrXor
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        test    al, 4
        _emit   0fh
        _emit   84h
        _emit   93h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_audioBitField]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        call    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   63h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   5ah
        call    MStackCall_MStackPush2ChainInsert_004062a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4ch
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [ecx*4 + 0x30], 0x00000267
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_walkCallback], 4
        call    ThrowFlowSetupCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x0000028f
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5c], eax
        ret
    }
}
