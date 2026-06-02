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

/* @addr 0x004a7e00 (333b audio) - 4-entry audio scope dispatcher.
 *   Entry 1 (offset 0): if g_counter_005433c8 < g_audioStateMachine1 - 1, just bumps
 *     the counter; otherwise OR-sets bit 0 of g_xformDirtyFlags.
 *   (10b NOP padding to 0x4a7e30.)
 *   Entry 2 (offset 0x30): calls DecOrDirty_004a7d90, snapshots g_xformDirtyFlags
 *     into g_bootInitSaveSlot, clears bit 0, calls DecOrDirty_004a7de0; if the
 *     slot[+0x30] == 3 restores from snapshot.
 *   (9b NOP padding to 0x4a7e70.)
 *   Entry 3 (offset 0x70): mirror of entry 2 but calls IncBoundedDirty
 *     first, then this function's own entry 1 (call -0x8b → 0x4a7e00); same
 *     +0x30==3 conditional restore tail.
 *   (9b NOP padding to 0x4a7eb0.)
 *   Entry 5 (offset 0xb0, big): calls SetJmp_Push16Call_004a1ac0 and DrainQueueCallEach,
 *     walks 24-byte-stride records at 0x004f3c20..0x004f3d40 calling
 *     MStackPush2ChainLLInsert for each; then iterates g_audioStateMachine0 records at +0x34
 *     stride 0x24, then g_audioStateMachine1 records at +0x48 stride 0x24, and
 *     finally calls CallSetMultiGlobalsJmp.
 */
extern unsigned int g_audioStateMachine0;
extern unsigned int g_audioStateMachine1;
extern unsigned int g_bootInitSaveSlot;
extern unsigned int g_counter_005433c8;
extern void CallSetMultiGlobalsJmp(void);
extern void DecOrDirty_004a7d90(void);
extern void DecOrDirty_004a7de0(void);
extern void DrainQueueCallEach(void);
extern void IncBoundedDirty(void);
extern void MStackPush2ChainLLInsert(void);
extern void SetJmp_Push16Call_004a1ac0(void);

__declspec(naked) void Audio4EntryScopeDispatch(void) {
    __asm {
        /* entry 1 (offset 0) */
        mov     eax, dword ptr [g_audioStateMachine1]
        mov     ecx, dword ptr [g_counter_005433c8]
        dec     eax
        cmp     ecx, eax
        jge     short L_a4s_setBit
        mov     eax, ecx
        inc     eax
        mov     dword ptr [g_counter_005433c8], eax
        ret
    L_a4s_setBit:
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        /* 10b NOP pad to 0x4a7e30 */
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
        /* entry 2 (offset 0x30) */
    L_a4s_entry2:
        call    DecOrDirty_004a7d90
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_bootInitSaveSlot], eax
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        call    DecOrDirty_004a7de0
        mov     eax, dword ptr [g_baseSel]
        cmp     dword ptr [eax*4 + 0x30], 3
        jne     short L_a4s_e2End
        mov     ecx, dword ptr [g_bootInitSaveSlot]
        mov     dword ptr [g_xformDirtyFlags], ecx
    L_a4s_e2End:
        ret
        /* 9b NOP pad to 0x4a7e70 */
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x70) */
    L_a4s_entry3:
        call    IncBoundedDirty
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_bootInitSaveSlot], eax
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        call    Audio4EntryScopeDispatch
        mov     eax, dword ptr [g_baseSel]
        cmp     dword ptr [eax*4 + 0x30], 3
        jne     short L_a4s_e3End
        mov     ecx, dword ptr [g_bootInitSaveSlot]
        mov     dword ptr [g_xformDirtyFlags], ecx
    L_a4s_e3End:
        ret
        /* 9b NOP pad to 0x4a7eb0 */
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 5 (offset 0xb0) */
    L_a4s_entry5:
        push    esi
        call    SetJmp_Push16Call_004a1ac0
        call    DrainQueueCallEach
        mov     esi, 0x004f3c20
    L_a4s_loop1:
        movsx   eax, byte ptr [esi]
        mov     ecx, dword ptr [g_baseSel]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        add     esi, 0x24
        cmp     esi, 0x004f3d40
        jb      short L_a4s_loop1
        mov     eax, dword ptr [g_audioStateMachine0]
        xor     esi, esi
        test    eax, eax
        jle     short L_a4s_skip2
    L_a4s_loop2:
        mov     eax, dword ptr [g_baseSel]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        mov     eax, dword ptr [g_audioStateMachine0]
        inc     esi
        cmp     esi, eax
        jl      short L_a4s_loop2
    L_a4s_skip2:
        mov     eax, dword ptr [g_audioStateMachine1]
        xor     esi, esi
        test    eax, eax
        jle     short L_a4s_skip3
    L_a4s_loop3:
        mov     eax, dword ptr [g_baseSel]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        mov     eax, dword ptr [g_audioStateMachine1]
        inc     esi
        cmp     esi, eax
        jl      short L_a4s_loop3
    L_a4s_skip3:
        call    CallSetMultiGlobalsJmp
        pop     esi
        ret
    }
}
