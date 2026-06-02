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

extern void ScaledArrStore_004298c0(void);
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

extern void SlotPhaseResetInstallChain(void);
extern void ZeroScaledZeroCallPauseJmp(void);
extern void DualGatedStateYield(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e4a58(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e4a70(void);
extern void EnduranceRoundMsgCluster(void);
extern void CallPauseScaledStoreCopyJmp(void);
extern unsigned int g_dispatchSave83_00541e20;

/* @addr 0x0043aab0 (313b game) - state-machine: 4-arm cascade dispatcher + install-self.
 *   state==0: g_xformEntityIdx=(0x0053a408>>2); g_pendingNodeType=(0x00537e88>>2).
 *     If g_cj!=g_player1NodeIdx: g_xformEntityIdx=g_pendingNodeType. eax=[*4+0].
 *     If eax!=0: call SlotPhaseResetInstallChain; if pause ret. Tail-call ZeroScaledZeroCallPauseJmp; pop+ret.
 *     Else: g_walkCallback=[0x00541e20]; cmp 0x78; if >: jmp body.
 *   state!=0 / >0x78: call DualGatedStateYield; if !=0 ret. Call LeaPlus22StoreSelf; if pause ret.
 *     Call DualCallPauseDirtyJmp; if pause ret.
 *     Cascade g_table_00535ddc: <0x10000 -> Wrapper_PackedAdvanceCallTailJmp_004e4a58 -> ret; <0x20000 -> Wrapper_PackedAdvanceCallTailJmp_004e4a70 -> ret;
 *       <0x30000 -> EnduranceRoundMsgCluster -> ret; else push 0x004e4a38, call PackedAdvanceCallTailJmp, pop, ret.
 *   Branch 0x78 path: call CallPauseScaledStoreCopyJmp; if pause ret. Install-self at entry;
 *     state=1; g_pendingNodeType=5; pause=1; pop+ret.
 */
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void PackedAdvanceCallTailJmp(void);

__declspec(naked) void StateMachine4ArmCascade(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   6bh
        mov     edx, dword ptr [g_cj_0054205c]
        mov     edi, dword ptr [g_player1NodeIdx]
        mov     eax, offset g_active_0053a408
        mov     ecx, offset g_active_00537e88
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, edi
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_pendingNodeType], ecx
        _emit   74h
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   1ah
        call    SlotPhaseResetInstallChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0bfh
        _emit   00h
        _emit   00h
        _emit   00h
        call    ZeroScaledZeroCallPauseJmp
        pop     edi
        pop     esi
        ret
        mov     eax, dword ptr [g_dispatchSave83_00541e20]
        cmp     eax, 0x78
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   79h
        call    DualGatedStateYield
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   9bh
        _emit   00h
        _emit   00h
        _emit   00h
        call    LeaPlus22StoreSelf
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   89h
        _emit   00h
        _emit   00h
        _emit   00h
        call    DualCallPauseDirtyJmp_00490c30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   7bh
        mov     eax, dword ptr [g_table_00535ddc]
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   08h
        call    Wrapper_PackedAdvanceCallTailJmp_004e4a58
        pop     edi
        pop     esi
        ret
        cmp     eax, 0x20000
        _emit   7dh
        _emit   08h
        call    Wrapper_PackedAdvanceCallTailJmp_004e4a70
        pop     edi
        pop     esi
        ret
        cmp     eax, 0x30000
        _emit   7dh
        _emit   08h
        call    EnduranceRoundMsgCluster
        pop     edi
        pop     esi
        ret
        push    0x004e4a38
        call    PackedAdvanceCallTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        pop     edi
        pop     esi
        ret
        call    CallPauseScaledStoreCopyJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        mov     eax, 1
        mov     dword ptr [esi + 8], offset StateMachine4ArmCascade
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 5
        mov     dword ptr [g_framePauseFlag], eax
        pop     edi
        pop     esi
        ret
    }
}
