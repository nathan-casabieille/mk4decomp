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

/* @addr 0x004c9440 (217b crt) - heap-region scan with per-slot init.
 *   Lock(2). For esi=0..[g_dispatchSave1466]-1:
 *     slot = (*g_dispatchSave1465)[esi]
 *     If slot == 0: allocate 0x38 bytes via LoadArgPushCall,
 *       store into slot; init critsec at slot+0x20 via IAT[0x4d215c],
 *       acquire via IAT[0x4d2140], reload slot ptr into edi, fall to finalize.
 *     Else:
 *       If [slot+0xc] & 0x83 == 0: call TwoPathIATDispatch_004c7030(esi, slot),
 *         reload slot, recheck [slot+0xc] & 0x83;
 *         if zero: edi = slot, jmp finalize;
 *         else: call TwoPathIATDispatch_004c70a0(esi, slot), continue iter.
 *       Else: skip helper, continue iter.
 *   Finalize: if edi != 0, init fields at edi (+0,+4,+8,+0xc,+0x1c = 0; +0x10 = -1).
 *   Unlock(2) via TableLookupIatCall; return edi.
 */
extern unsigned int g_dispatchSave1465;
extern unsigned int g_dispatchSave1466;
extern unsigned int g_iat_EnterCriticalSection;
extern unsigned int g_iat_InitializeCriticalSection;
extern void LoadArgPushCall(void);
extern void Lock(void);
extern void TableLookupIatCall(void);
extern void TwoPathIATDispatch_004c7030(void);
extern void TwoPathIATDispatch_004c70a0(void);

__declspec(naked) void HeapScanInit(void) {
    __asm {
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    2
        xor     ebp, ebp
        xor     edi, edi
        call    Lock
        mov     eax, dword ptr [g_dispatchSave1466]
        add     esp, 4
        xor     esi, esi
        cmp     eax, ebp
        jle     L_hsi_finalize
        mov     bl, 0x83
    L_hsi_loop:
        mov     eax, dword ptr [g_dispatchSave1465]
        mov     eax, [eax + esi*4]
        cmp     eax, ebp
        jz      short L_hsi_alloc
        test    byte ptr [eax + 0xc], bl
        jne     short L_hsi_next
        push    eax
        push    esi
        call    TwoPathIATDispatch_004c7030
        mov     ecx, dword ptr [g_dispatchSave1465]
        add     esp, 8
        mov     eax, [ecx + esi*4]
        test    byte ptr [eax + 0xc], bl
        jz      short L_hsi_setEdi
        push    eax
        push    esi
        call    TwoPathIATDispatch_004c70a0
        add     esp, 8
    L_hsi_next:
        mov     eax, dword ptr [g_dispatchSave1466]
        inc     esi
        cmp     esi, eax
        jl      short L_hsi_loop
        jmp     L_hsi_finalize
    L_hsi_setEdi:
        mov     edi, [ecx + esi*4]
        jmp     L_hsi_finalize
    L_hsi_alloc:
        push    0x38
        shl     esi, 2
        call    LoadArgPushCall
        mov     ecx, dword ptr [g_dispatchSave1465]
        add     esp, 4
        mov     [ecx + esi], eax
        mov     edx, dword ptr [g_dispatchSave1465]
        mov     eax, [edx + esi]
        cmp     eax, ebp
        jz      short L_hsi_finalize
        add     eax, 0x20
        push    eax
        call    dword ptr [g_iat_InitializeCriticalSection]
        mov     eax, dword ptr [g_dispatchSave1465]
        mov     ecx, [eax + esi]
        add     ecx, 0x20
        push    ecx
        call    dword ptr [g_iat_EnterCriticalSection]
        mov     edx, dword ptr [g_dispatchSave1465]
        mov     edi, [edx + esi]
    L_hsi_finalize:
        cmp     edi, ebp
        jz      short L_hsi_unlock
        mov     [edi + 4], ebp
        mov     [edi + 0xc], ebp
        mov     [edi + 8], ebp
        mov     [edi], ebp
        mov     [edi + 0x1c], ebp
        mov     dword ptr [edi + 0x10], -1
    L_hsi_unlock:
        push    2
        call    TableLookupIatCall
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
