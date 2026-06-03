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

extern void Helper_AudioRelease(void);
extern void Snd3DVolumePanSet(void);
extern unsigned int g_dispatchSave527[2];  /* double constant */
extern unsigned char g_effectTbl680[];

/* @addr 0x004be870 (216b engine.scenegraph) - effect-table walker.
 *   Reads param (ecx<47), computes table base = &g_table[idx*680], iterates
 *   170 4-byte entries: skip 0xffff; check filter via TableSearch;
 *   compute scaled idx (if ax>100 then ax*(2/5), else ax+0x7d0); random pick
 *   via Helper_AudioRelease; load short [esi+2] (factor), fild+fmul[g_dispatchSave527],
 *   DoubleToInt64 → byte clamp stored at [esp+8]; recompute scaled idx;
 *   apply effect via Snd3DVolumePanSet(idx, -1, byte, byte).
 */
extern void DoubleToInt64(void);
extern void TableSearch(void);

__declspec(naked) void EffectTableWalker(void) {
    __asm {
        push    ecx
        mov     ecx, [esp + 8]
        push    esi
        cmp     ecx, 0x2f
        push    edi
        jae     L_et_done
        mov     eax, ecx
        xor     edi, edi
        shl     eax, 4
        add     eax, ecx
        lea     eax, [eax + eax*4]
        lea     esi, [eax*8 + g_effectTbl680]
    L_et_loop:
        mov     ax, word ptr [esi]
        cmp     ax, 0xffff
        jz      L_et_done
        push    eax
        call    TableSearch
        add     esp, 4
        test    eax, eax
        jne     L_et_next
        mov     ax, word ptr [esi]
        cmp     ax, 100
        jg      short L_et_scaleA
        movsx   edx, ax
        add     edx, 0x7d0
        jmp     short L_et_callRandA
    L_et_scaleA:
        movsx   ecx, ax
        mov     eax, 0x66666667
        imul    ecx
        sar     edx, 1
        mov     ecx, edx
        shr     ecx, 31
        add     edx, ecx
    L_et_callRandA:
        push    edx
        call    Helper_AudioRelease
        movsx   edx, word ptr [esi + 2]
        mov     [esp + 0x14], edx
        add     esp, 4
        fild    dword ptr [esp + 0x10]
        fmul    qword ptr [g_dispatchSave527]
        call    DoubleToInt64
        mov     byte ptr [esp + 8], al
        mov     ax, word ptr [esi]
        cmp     ax, 100
        jg      short L_et_scaleB
        movsx   edx, ax
        add     edx, 0x7d0
        jmp     short L_et_callApply
    L_et_scaleB:
        movsx   ecx, ax
        mov     eax, 0x66666667
        imul    ecx
        sar     edx, 1
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
    L_et_callApply:
        mov     eax, [esp + 8]
        push    eax
        push    eax
        push    -1
        push    edx
        call    Snd3DVolumePanSet
        add     esp, 0x10
    L_et_next:
        inc     edi
        add     esi, 4
        cmp     edi, 0xaa
        jl      L_et_loop
    L_et_done:
        pop     edi
        pop     esi
        pop     ecx
        ret
    }
}
