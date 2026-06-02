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

/*
 * AudioMicroEntries - 222b audio function with six small entry points (16b-aligned).
 *   Entry 0x004a7600: g_eventQueueWorkType = table[arg1]; tail-jmp Push16Call.
 *   Entry 0x004a7620: dispatch on g_byte_00543590 == 1: set (g_audioStateMachine2=1, g_audioByteTable=0)
 *     else (g_audioStateMachine2=0, g_audioByteTable=1); g_audioMicroEntry=1; tail-jmp AudioStateMachineMulti.
 *   Entry 0x004a7660: countdown helper on g_audioStateMachine0 (decrements; sets g_xformDirtyFlags|=1 at end).
 *   Entry 0x004a7680: countup helper on g_audioStateMachine0 (increments; sets g_xformDirtyFlags|=1 at end).
 *   Entry 0x004a76a0: same countdown helper but on g_audioStateMachine1.
 *   Entry 0x004a76c0: same countup helper but on g_audioStateMachine1.
 */
extern unsigned int g_audioStateMachine2;
extern unsigned int g_audioByteTable;
extern unsigned int g_audioMicroEntry;
extern unsigned int g_table_004f3af8;
extern unsigned int g_audioStateMachine0;
extern unsigned int g_audioStateMachine1;
extern void AudioStateMachineMulti(void);

__declspec(naked) void AudioMicroEntries(void)
{
    __asm
    {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [eax*4 + g_table_004f3af8]
        mov     dword ptr [g_eventQueueWorkType], ecx
        jmp     Push16Call
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
        mov     cl, byte ptr [g_gtModeFlag]
        mov     eax, 1
        cmp     cl, al
        mov     dword ptr [g_audioMicroEntry], eax
        jne     short L_e2_elseBranch
        mov     dword ptr [g_audioStateMachine2], eax
        mov     dword ptr [g_audioByteTable], 0
        jmp     short L_e2_tail
    L_e2_elseBranch:
        mov     dword ptr [g_audioStateMachine2], 0
        mov     dword ptr [g_audioByteTable], eax
    L_e2_tail:
        jmp     AudioStateMachineMulti
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     ecx, dword ptr [g_audioStateMachine0]
        mov     eax, 1
        cmp     ecx, eax
        jle     short L_e3_set
        mov     eax, ecx
        dec     eax
        mov     dword ptr [g_audioStateMachine0], eax
        ret
    L_e3_set:
        or      dword ptr [g_xformDirtyFlags], eax
        ret
        _emit   90h
        mov     eax, dword ptr [g_audioStateMachine0]
        cmp     eax, 5
        jge     short L_e4_set
        inc     eax
        mov     dword ptr [g_audioStateMachine0], eax
        ret
    L_e4_set:
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        _emit   90h
        _emit   90h
        mov     ecx, dword ptr [g_audioStateMachine1]
        mov     eax, 1
        cmp     ecx, eax
        jle     short L_e5_set
        mov     eax, ecx
        dec     eax
        mov     dword ptr [g_audioStateMachine1], eax
        ret
    L_e5_set:
        or      dword ptr [g_xformDirtyFlags], eax
        ret
        _emit   90h
        mov     eax, dword ptr [g_audioStateMachine1]
        cmp     eax, 5
        jge     short L_e6_set
        inc     eax
        mov     dword ptr [g_audioStateMachine1], eax
        ret
    L_e6_set:
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}
