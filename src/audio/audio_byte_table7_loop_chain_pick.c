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
 * CharSelect_CpuBattlesToggle - 300b 7-iter audio byte-table loop with extra picks.
 *   Loops edi 0..6: chain index from g_byteTab_004f3940[esi=edi*9*4]; g_currentNodeIdx=chain[ecx*4].
 *   Call MStackPush2ChainLLInsert; load chain pointer (esi-table+0xc) and value (esi-table+0x4).
 *   Special pick when edi==2: ecx = (g_audioStateMachineVar2 != 0) ? 0x004d2420 : 0x004d2438.
 *   For edi in {5,6}: override g_walkCallback with 0x03e80000 based on chain[+0x30] == 1 or 2.
 *   Push (eax, ecx); GuardedSetupCallTailJmp; restore. chain[+0x5c] = esi-table[+0x10];
 *   chain[+0x54] → esi-table[+0x8]; movsx ecx = byte tab; chain[+(baseSel+ecx)*4] = chain.
 *   inc edi; if < 7: loop.
 */
extern unsigned int g_byteTab_004f3940;
extern unsigned int g_audioStateMachineVar2;
extern void GuardedSetupCallTailJmp(void);
extern void MStackPush2ChainLLInsert(void);

__declspec(naked) void CharSelect_CpuBattlesToggle(void)
{
    __asm
    {
        push    ebx
        push    ebp
        push    esi
        push    edi
        xor     edi, edi
        mov     ebx, 2
        mov     ebp, 1
    L_a51_iter:
        mov     ecx, dword ptr [g_baseSel]
        lea     esi, [edi*8 + edi]
        shl     esi, 2
        movsx   eax, byte ptr [esi + g_byteTab_004f3940]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        mov     eax, dword ptr [esi + 0x004f394c]
        mov     ecx, dword ptr [esi + 0x004f3944]
        cmp     edi, ebx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        jne     short L_a51_skipPick
        mov     ecx, dword ptr [g_audioStateMachineVar2]
        test    ecx, ecx
        mov     ecx, 0x004d2420
        jne     short L_a51_storeChan
        mov     ecx, 0x004d2438
    L_a51_storeChan:
        mov     dword ptr [g_currentNodeIdx], ecx
    L_a51_skipPick:
        mov     edx, dword ptr [g_baseSel]
        cmp     edi, 5
        jne     short L_a51_chk6_eq
        cmp     dword ptr [edx*4 + 0x30], ebp
        jne     short L_a51_chk6_eq
        mov     eax, 0x03e80000
        mov     dword ptr [g_walkCallback], eax
    L_a51_chk6_eq:
        cmp     edi, 6
        jne     short L_a51_chk5_ne
        cmp     dword ptr [edx*4 + 0x30], ebp
        je      short L_a51_chk5_ne
        mov     eax, 0x03e80000
        mov     dword ptr [g_walkCallback], eax
    L_a51_chk5_ne:
        cmp     edi, 5
        jne     short L_a51_chk6_ne
        cmp     dword ptr [edx*4 + 0x30], ebx
        jne     short L_a51_chk6_ne
        mov     eax, 0x03e80000
        mov     dword ptr [g_walkCallback], eax
    L_a51_chk6_ne:
        cmp     edi, 6
        jne     short L_a51_callGuard
        cmp     dword ptr [edx*4 + 0x30], ebx
        jne     short L_a51_callGuard
        mov     eax, 0x03e80000
        mov     dword ptr [g_walkCallback], eax
    L_a51_callGuard:
        push    eax
        push    ecx
        call    GuardedSetupCallTailJmp
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [esi + 0x004f3950]
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [esi + 0x004f3948], edx
        mov     edx, dword ptr [g_baseSel]
        movsx   ecx, byte ptr [esi + g_byteTab_004f3940]
        mov     dword ptr [g_eventQueueCurrent], ecx
        add     ecx, edx
        inc     edi
        cmp     edi, 7
        mov     dword ptr [ecx*4], eax
        jb      L_a51_iter
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
