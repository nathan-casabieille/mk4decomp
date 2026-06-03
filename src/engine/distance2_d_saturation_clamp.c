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

/* @addr 0x004300a0 (312b game) - distance2D Mul10 clamp / 3-branch saturation.
 *   Sub esi=g_cj. dx=[cj*4+0x54]-g_load_0052ab04; dy=[cj*4+0x5c]-g_load_0052ab08.
 *   Mul10Tail(dx,dx)+Mul10Tail(dy,dy)->g_acc.
 *   If sum > 0x370000: jump to saturation_high.
 *   Else: load g_player1NodeIdx / g_player2NodeIdx (scaledInit/x_48); a=[scaled[+0x58]], c=[48[+0x58]].
 *     if a>c: a=c. If a<=-0x20000: jump to saturation_low. Else jump to high path.
 *   saturation_high: cmp [cj*4+0x58], -0x18000; if >=: store -0x18000, set fields=0, ret.
 *     Else: ecx=0x7ae, store at cj[+0x70]=ecx; pop+ret.
 *   saturation_low: cmp ecx with 0xfffe3334; if < 0: eax=0; mov [cj*4+0x70]=eax; pop+ret.
 *     Else: eax stays -0x7ae, mov to g_walkCallback, store at cj[+0x70]=-0x7ae; pop+ret.
 */
extern unsigned int g_load_0052ab04;
extern unsigned int g_load_0052ab08;

__declspec(naked) void Distance2DSaturationClamp(void) {
    __asm {
        mov     ecx, dword ptr [g_load_0052ab04]
        mov     edx, dword ptr [g_load_0052ab08]
        push    esi
        mov     esi, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     eax, dword ptr [esi*4 + 0x54]
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     esi, dword ptr [esi*4 + 0x5c]
        sub     eax, ecx
        sub     esi, edx
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_acc_00542078], esi
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [g_acc_00542078]
        push    eax
        push    eax
        call    Mul10Tail
        mov     edx, dword ptr [g_eventQueueWorkType]
        add     esp, 8
        add     eax, edx
        cmp     eax, 0x370000
        mov     dword ptr [g_acc_00542078], eax
        _emit   7fh
        _emit   41h
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     ecx, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 0x58]
        cmp     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   7eh
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 0xfffe0000
        _emit   7eh
        _emit   4fh
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [eax*4 + 0x58]
        cmp     ecx, 0xfffe8000
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   7ch
        _emit   21h
        mov     dword ptr [eax*4 + 0x58], 0xfffe8000
        mov     ecx, dword ptr [g_cj_0054205c]
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        pop     esi
        ret
        mov     ecx, 0x7ae
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x70], ecx
        pop     esi
        ret
        mov     edx, dword ptr [g_cj_0054205c]
        mov     eax, 0xfffff852
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [edx*4 + 0x58]
        cmp     ecx, 0xfffe3334
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   7dh
        _emit   07h
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x70], eax
        pop     esi
        ret
    }
}
