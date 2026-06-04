/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
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

extern void ComboSpecialEventCluster(void);
extern void DualGatedStateYield(void);
extern void DualScaledInitCmp_0046df50(void);
extern void GuardedDualAndFlagToggle(void);
extern void ScaledChain3c74(void);
extern void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d430(void);

__declspec(naked) void TriCounterReinitChain(void)
{
    __asm
    {
        mov     eax, dword ptr [g_eventQueueNotMask]
        test    eax, eax
        jne     L_tcrc_ret1
        call    ScaledChain3c74
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tcrc_ret1
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x5c]
        cmp     eax, 1
        mov     dword ptr [g_walkCallback], eax
        je      short L_tcrc_ret1
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     dword ptr [g_walkCallback], 0
        call    ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d430
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tcrc_ret1
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        test    al, 1
        mov     dword ptr [g_eventQueueNotMask], edx
        je      short L_tcrc_ret1
        mov     dword ptr [g_eventQueueNotMask], 1
    L_tcrc_ret1:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_tcrc_sub2:
        call    ScaledChain3c74
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tcrc_sub2_ret
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x2001
        je      short L_tcrc_sub2_ret
        cmp     eax, 0x106
        je      short L_tcrc_sub2_ret
        cmp     eax, 0x107
        je      short L_tcrc_sub2_ret
        cmp     eax, 0x10c
        jne     short L_tcrc_sub2_check102
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        cmp     eax, 0x18
        mov     dword ptr [g_walkCallback], eax
        jg      short L_tcrc_sub2_setOne
        cmp     eax, 5
        jge     short L_tcrc_sub2_setOne
    L_tcrc_sub2_ret:
        ret
    L_tcrc_sub2_check102:
        cmp     eax, 0x102
        jne     short L_tcrc_sub2_setOne
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x3c]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x5c]
        cmp     eax, 1
        mov     dword ptr [g_walkCallback], eax
        je      short L_tcrc_sub2_ret
    L_tcrc_sub2_setOne:
        mov     dword ptr [g_walkCallback], 1
        jmp     ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d430
    L_tcrc_sub3:
        call    DualGatedStateYield
        test    eax, eax
        jne     short L_tcrc_sub3_ret
        call    GuardedDualAndFlagToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tcrc_sub3_ret
        test    byte ptr [g_xformDirtyFlags], 1
        jne     short L_tcrc_sub3_doCall
        jmp     ComboSpecialEventCluster
    L_tcrc_sub3_doCall:
        call    DualScaledInitCmp_0046df50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tcrc_sub3_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4]
        mov     dword ptr [g_eventQueueCurrent], 0
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4], 0
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, 4
        or      edx, eax
        test    ecx, ecx
        mov     dword ptr [g_xformDirtyFlags], edx
        je      short L_tcrc_sub3_ret
        mov     ecx, edx
        xor     ecx, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
    L_tcrc_sub3_ret:
        ret
    }
}
