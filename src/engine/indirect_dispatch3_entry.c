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

/* @addr 0x0049f530 (354b game) - 3-entry indirect dispatcher with state walk.
 *   Entry 1 (offset 0, 260b): cache [g_audioBitField] into g_xformEntityIdx,
 *     index it by [g_dispatchArg] base, deref once, save in 0x542048
 *     and [edx*4+4] in g_currentNodeIdx then `call eax` (indirect). On
 *     no-error AND bit 0 of g_xformDirtyFlags set: walks an outer state
 *     loop comparing eax to {1,6,11,16} (each takes the install path);
 *     other values get dec'd, call LinkedListIndirectDirtyToggle,
 *     and on bit 0 still set may re-enter the loop. Else writes ecx into
 *     [eax*4], copies g_dispatchArg into g_eventQueueCurrent, calls
 *     RoundWinTransition then GuardedScaledCall with [scaled+8] prep.
 *     Both successful tails fall through to CallSetPause.
 *   (12b NOP align pad.)
 *   Entry 2 (offset 0x110, 34b): if g_state2_00541d88 != 0 tail-jmp
 *     CallSetPause; else zero g_dispatchArg and tail-jmp
 *     IndirectStateDispatcher.
 *   (14b NOP align pad.)
 *   Entry 3 (offset 0x140, 34b): mirror of entry 2 on g_state2_00537ea8.
 *     If non-zero tail-jmp CallSetPause; else set g_dispatchArg
 *     to 1 and tail-jmp IndirectStateDispatcher.
 */
extern unsigned int g_dispatchArg;
extern unsigned int g_state2_00537ea8;
extern unsigned int g_state2_00541d88;
extern unsigned int g_audioBitField;
extern void CallSetPause(void);
extern void GuardedScaledCall(void);
extern void IndirectStateDispatcher(void);
extern void LinkedListIndirectDirtyToggle(void);
extern void RoundWinTransition(void);

__declspec(naked) void IndirectDispatch3Entry(void) {
    __asm {
        mov     eax, dword ptr [g_audioBitField]
        mov     ecx, dword ptr [g_dispatchArg]
        mov     dword ptr [g_xformEntityIdx], eax
        add     eax, ecx
        push    ebx
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_id3_doneNoPop
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 1
        test    al, bl
        je      L_id3_freshPath
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [edx*4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4]
        cmp     eax, ebx
        mov     dword ptr [g_walkCallback], eax
        je      L_id3_freshPath
    L_id3_loopHead:
        cmp     eax, 6
        je      L_id3_freshPath
        cmp     eax, 0xb
        je      short L_id3_freshPath
        cmp     eax, 0x10
        je      short L_id3_freshPath
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        call    LinkedListIndirectDirtyToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_id3_doneNoPop
        test    byte ptr [g_xformDirtyFlags], bl
        je      short L_id3_writeCx
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, ebx
        jne     short L_id3_loopHead
        call    CallSetPause
        pop     ebx
        ret
    L_id3_writeCx:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_dispatchArg]
        mov     dword ptr [g_eventQueueCurrent], edx
        call    RoundWinTransition
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_id3_doneNoPop
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], ecx
        call    GuardedScaledCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_id3_doneNoPop
    L_id3_freshPath:
        call    CallSetPause
    L_id3_doneNoPop:
        pop     ebx
        ret
        /* 12b NOP align pad */
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
        /* entry 2 (offset 0x110) */
    L_id3_entry2:
        mov     eax, dword ptr [g_state2_00541d88]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_id3_e2zero
        jmp     CallSetPause
    L_id3_e2zero:
        mov     dword ptr [g_dispatchArg], 0
        jmp     IndirectStateDispatcher
        /* 14b NOP align pad */
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
        nop
        nop
        /* entry 3 (offset 0x140) */
    L_id3_entry3:
        mov     eax, dword ptr [g_state2_00537ea8]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_id3_e3one
        jmp     CallSetPause
    L_id3_e3one:
        mov     dword ptr [g_dispatchArg], 1
        jmp     IndirectStateDispatcher
    }
}
