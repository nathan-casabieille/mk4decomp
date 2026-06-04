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

extern void Phase1ChainSetupCallScale6(void);
extern void InstallSelfHelper2(void);
extern void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
extern void InstallSelfCountdown2Stage_Phase1ChainSetupCallScale6(void);

/* @addr 0x0047e800 (148b game) - install-self with dual-branch dirty check:
 *   chain[sel].slot84 -> eax; clear. If !=0: call Phase1ChainSetupCallScale6; pause? ret.
 *     g_walkCallback=1; call CmpEqInitCallElseJmp; pause? ret.
 *     if (g_xformDirtyFlags & 1): call InstallSelfHelper2; ret.
 *   Else (or after first branch via 0x5a): call GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp; pause? ret.
 *     if (g_xformDirtyFlags & 1): call InstallSelfCountdown2Stage_Phase1ChainSetupCallScale6; ret.
 *     else: install self, set slot84=1, g_pendingNodeType=1, pause flag.
 */
extern void ArgSarStoreJmp(void);
extern void CmpEqInitCallElseJmp(void);
extern void TableLookupCall_g_eventTbl_112(void);

extern void InstallSelfCountdown2Stage_PopCallBitCmpPushCall(void);

extern void FiveCallGuardSetTail(void);

__declspec(naked) void InstallSelfDualBranch(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        mov     ebx, 1
        lea     esi, [eax*4]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   32h
        call    Phase1ChainSetupCallScale6
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   5bh
        mov     dword ptr [g_walkCallback], ebx
        call    CmpEqInitCallElseJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   47h
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   74h
        _emit   08h
        call    InstallSelfHelper2
        pop     esi
        pop     ebx
        ret
        call    GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   74h
        _emit   08h
        call    InstallSelfCountdown2Stage_Phase1ChainSetupCallScale6
        pop     esi
        pop     ebx
        ret
        mov     dword ptr [esi + 8], offset InstallSelfDualBranch
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
    }
}


/* @addr 0x0047c880 (111b game) - triple-entry dispatcher.
 *   Block A: set g_walkCallback=0x37; call TableLookupCall; if !pause set =0x07; ret.
 *   Block B (+0x30): set baseSel[*4+0x74]=0x408; push 0x004ed320; call ArgSarStoreJmp; ret.
 *   Block C (+0x60): set g_eventQueueChild=0x8; jmp InstallSelfCountdown2Stage_PopCallBitCmpPushCall.
 */
__declspec(naked) void TripleEntryTblPushJmp(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x37
        call    TableLookupCall_g_eventTbl_112
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_walkCallback], 0x07
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
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x00000408
        mov     dword ptr [g_walkCallback], eax
        push    0x004ed320
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ArgSarStoreJmp
        add     esp, 4
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
        _emit   90h
        _emit   90h
        mov     dword ptr [g_eventQueueChild], 0x08
        jmp     InstallSelfCountdown2Stage_PopCallBitCmpPushCall
    }
}
