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
extern unsigned int g_eq;
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
 * BootChainPushAddSignFlag - 297b boot mstack-push1 + sign-add + bit-flag toggle.
 *   g_eq = (g_walkCallback < 0); push g_xformEntityIdx to mstack.
 *   ecx = g_fightGroupHead[+0x24]; g_xformEntityIdx = ecx. If sign flag was set:
 *     edx = g_currentNodeIdx[+0x28] + g_walkCallback; g_walkCallback = edx. If sign cleared (jns):
 *       pop mstack → g_xformEntityIdx; g_xformDirtyFlags &= 0xfe; pop+ret.
 *     Else: ecx = ecx[+4]; pop mstack into edx; ecx--; g_xformDirtyFlags |= 1;
 *       g_xformEntityIdx = edx; g_walkCallback = ecx; pop+ret.
 *   Otherwise (positive branch): eax = g_walkCallback + g_currentNodeIdx[+0x28]; g_walkCallback = eax.
 *     esi = ecx[+4]; ecx = g_matrixStackTop--; g_eq = (eax < esi);
 *     edx = mstack at top; g_xformEntityIdx = edx; g_xformDirtyFlags &= 0xfffffffe;
 *     commit g_matrixStackTop. If sign result = 0: g_walkCallback = 0; g_xformDirtyFlags |= 1.
 *     pop+ret.
 */

__declspec(naked) void BootChainPushAddSignFlag(void)
{
    __asm
    {
        mov     edx, dword ptr [g_walkCallback]
        xor     eax, eax
        test    edx, edx
        mov     ecx, dword ptr [g_xformEntityIdx]
        push    esi
        setl    al
        mov     dword ptr [g_eq], eax
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_eq]
        mov     ecx, dword ptr [edx*4 + 0x24]
        test    eax, eax
        mov     dword ptr [g_xformEntityIdx], ecx
        je      short L_77_pos
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     edx, dword ptr [g_walkCallback]
        add     edx, eax
        mov     dword ptr [g_walkCallback], edx
        jns     short L_77_signClear
        mov     ecx, dword ptr [ecx*4 + 4]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        dec     ecx
        or      al, 1
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        pop     esi
        ret
    L_77_signClear:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        pop     esi
        ret
    L_77_pos:
        mov     eax, dword ptr [g_walkCallback]
        mov     esi, dword ptr [edx*4 + 0x28]
        add     eax, esi
        xor     edx, edx
        mov     dword ptr [g_walkCallback], eax
        mov     esi, dword ptr [ecx*4 + 4]
        mov     ecx, dword ptr [g_matrixStackTop]
        cmp     eax, esi
        setl    dl
        mov     eax, edx
        dec     ecx
        mov     dword ptr [g_eq], eax
        mov     edx, dword ptr [ecx*4 + 4]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     edx, dword ptr [g_xformDirtyFlags]
        and     edx, 0xfffffffe
        mov     dword ptr [g_matrixStackTop], ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        jne     short L_77_done
        mov     dword ptr [g_walkCallback], eax
        mov     eax, edx
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
    L_77_done:
        pop     esi
        ret
    }
}
