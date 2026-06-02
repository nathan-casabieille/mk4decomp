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

extern void ScaledMove48to58(void);
extern void SixEntryYieldThunks(void);
extern void InstallSelfPlusTrampoline(void);
extern void FlagCascadeStateSet(void);
extern void StageTransitionCluster_0046f250(void);
extern void StateDispatchYield(void);
extern void QuadEntryChainPush(void);
extern void MStackBitFlagDispatch(void);
extern void PushFourCallPopBitJmp(void);

/* @addr 0x0046c6e0 (212b game) - four adjacent state-handler blocks.
 *   B1 (0..19, +12 NOPs): call ScaledMove48to58; if !pause jmp SixEntryYieldThunks; ret.
 *   B2 (32..71, +8 NOPs): call ScaledMove48to58; if !pause call InstallSelfPlusTrampoline; if !pause
 *     call FlagCascadeStateSet; if !pause test bit0 of g_xformDirtyFlags (clear=>jmp
 *     StageTransitionCluster_0046f250; set=>store 5 at g_walkCallback and tail-jmp StateDispatchYield); ret.
 *   B3 (112..187, +4 NOPs): scaled chain via baseSel[+0x30]; if eax==0 jmp
 *     QuadEntryChainPush; else call MStackBitFlagDispatch; if !pause: chain[+0xc][+4]
 *     extracted and tail-call eax; ret.
 *   B4 (192..211): call ScaledMove48to58; if !pause jmp PushFourCallPopBitJmp; ret.
 */
extern unsigned int g_dispatchSave693;
extern unsigned int g_dispatchSave694;
extern void ArgSarStoreJmp(void);
extern void GatedWordPushCall(void);
extern void PendingMatch_00452770(void);
extern void StoreLoadJmp(void);
extern void ThrowInitLinkCluster(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void QuadStateHandler(void) {
    __asm {
        call    ScaledMove48to58
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     SixEntryYieldThunks
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call    ScaledMove48to58
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   39h
        call    InstallSelfPlusTrampoline
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2bh
        call    FlagCascadeStateSet
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     StageTransitionCluster_0046f250
        mov     dword ptr [g_walkCallback], 5
        jmp     StateDispatchYield
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_eventQueueNotMask], eax
        _emit   75h
        _emit   05h
        jmp     QuadEntryChainPush
        call    MStackBitFlagDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        mov     eax, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x0c]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x04]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     eax
        ret
        nop
        nop
        nop
        call    ScaledMove48to58
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     PushFourCallPopBitJmp
        ret
    }
}

__declspec(naked) void StageTransitionCluster_00455340(void)
{
    __asm {
        /* === Helper 1 (0x455340): pre-stage event + force-slot === */
        call     PendingMatch_00452770
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_538a
        push     OFFSET L_5530
        call     StoreLoadJmp
        add      esp, 4
        mov      dword ptr [g_walkCallback], 0x5c
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_538a
        mov      eax, dword ptr [g_eventQueueIdx]
        push     OFFSET g_dispatchSave693
        mov      dword ptr [g_fightGroupHead], eax
        call     ArgSarStoreJmp
        add      esp, 4
    L_538a:
        ret
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2: set slot-bit 4 + event === */
        mov      ecx, dword ptr [g_eventQueueIdx]
        push     OFFSET g_dispatchSave694
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 4
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 3: jmp tailcall === */
        jmp      StackPopDispatchTagged
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 4 (0x4553d0): cleanup + clamp === */
    L_53d0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        shl      eax, 2
        xor      esi, esi
        push     edi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], esi
        cmp      ecx, esi
        je       short L_540a
    L_53ec:
        mov      ecx, dword ptr [g_baseSel]
        lea      eax, [ecx*4]
        mov      ecx, dword ptr [ecx*4 + 0x84]
        mov      dword ptr [eax + 0x84], esi
        cmp      ecx, esi
        jne      short L_53ec
    L_540a:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [edx*4 + 0x4c]
        cmp      ecx, esi
        mov      dword ptr [g_walkCallback], ecx
        je       short L_5495
        add      ecx, dword ptr [edx*4 + 0x70]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x70], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [edx*4 + 0x58]
        mov      dword ptr [g_walkCallback], ecx
        mov      edi, dword ptr [edx*4 + 0x48]
        sub      ecx, edi
        cmp      ecx, esi
        mov      dword ptr [g_walkCallback], ecx
        jle      short L_5495
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [edx*4 + 0x70], esi
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x4c], ecx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [ecx*4 + 0x48]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx*4 + 0x58], edx
    L_5495:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_53d0
        mov      dword ptr [eax + 0x84], ecx
        pop      edi
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 5 (0x4554c0): finalize callback === */
    L_54c0:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_5510
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [ecx*4 + 0x4c]
        test     ecx, ecx
        mov      dword ptr [g_walkCallback], ecx
        jne      short L_5510
        mov      dword ptr [g_walkCallback], 0x47
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_552e
        jmp      Thunk_ScaledNeg1SetPause
    L_5510:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_54c0
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_framePauseFlag], ecx
    L_552e:
        ret
        nop
        /* === Helper 6 (0x455530): 2-state FSM === */
    L_5530:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       short L_55c8
        dec      eax
        je       short L_556a
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      short L_5598
        call     Thunk_ScaledNeg1SetPause
        pop      esi
        ret
    L_556a:
        mov      dword ptr [g_walkCallback], 0x4c
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_55e9
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_eventQueueEnd], 0x28
        mov      dword ptr [g_fightGroupHead], ecx
    L_5598:
        call     ThrowInitLinkCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_55e9
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_5530
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_55c8:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_5530
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], eax
    L_55e9:
        pop      esi
        ret
    }
}
