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

/* @addr 0x0049a4e0 (312b game) - dual-block: install-self entry + sibling-tail with Mul10 chain.
 *   Entry (0..0x96): load state; clear. state!=0: tail-jmp FiveCallGuardSetTail.
 *     state==0: g_walkCallback=0x1016; chain[baseSel*4+0x74]=0x1016; install-self at entry+0x01000000.
 *     state=1; call ScaledLoadJmp; pause=1; pop esi/edi; ret.
 *   Tail (+0xa0): call PendingMatch_DualCmpSwapStore; if pause ret.
 *     Mul10Tail(0x3333, g_currentNodeFlags)->[g_currentNodeFlags + scaledInit chain offset +0x6c].
 *     Mul10Tail(0x3333, g_xformScratch2088)->chain[+0x74].
 *     g_cj=scaledInit; push 0x23fb23; call ThreeChanPackClamp; push g_cj; call CopyThreeFields;
 *     push 0x004f2410; call ArgSar_Set0_Jmp; pop+ret.
 */
extern void ArgSar_Set0_Jmp(void);
extern void CopyThreeFields(void);
extern void FiveCallGuardSetTail(void);
extern void PendingMatch_DualCmpSwapStore(void);
extern void ScaledLoadJmp_00428d20(void);
extern void ThreeChanPackClamp(void);

__declspec(naked) void DualBlockInstallMul10Tail(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   05h
        jmp     FiveCallGuardSetTail
        push    edi
        push    esi
        mov     esi, dword ptr [g_baseSel]
        mov     ecx, 0x1016
        mov     dword ptr [g_walkCallback], ecx
        mov     edi, offset DualBlockInstallMul10Tail
        mov     dword ptr [esi*4 + 0x74], ecx
        mov     dword ptr [eax + 8], offset DualBlockInstallMul10Tail
        mov     ecx, dword ptr [g_baseSel]
        mov     esi, 1
        add     edi, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], esi
        mov     ecx, dword ptr [eax + 4]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4 + 0], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    ScaledLoadJmp_00428d20
        mov     dword ptr [g_framePauseFlag], esi
        pop     esi
        pop     edi
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    PendingMatch_DualCmpSwapStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        push    esi
        push    ecx
        push    0x3333
        lea     esi, [eax*4 + 0]
        call    Mul10Tail
        mov     edx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        push    edx
        push    0x3333
        call    Mul10Tail
        mov     dword ptr [g_xformScratch2088], eax
        mov     eax, dword ptr [g_currentNodeFlags]
        mov     dword ptr [esi + 0x6c], eax
        mov     ecx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [esi + 0x74], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        push    0x23fb23
        mov     dword ptr [g_cj_0054205c], edx
        call    ThreeChanPackClamp
        mov     eax, dword ptr [g_cj_0054205c]
        add     esp, 4
        push    eax
        call    CopyThreeFields
        add     esp, 4
        push    0x004f2410
        call    ArgSar_Set0_Jmp
        add     esp, 4
        pop     esi
        ret
    }
}
