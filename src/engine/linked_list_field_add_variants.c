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

/* @addr 0x0049d380 (174b game) - linked-list iteration with field-add via 3 sub-calls.
 *   eax=g_scaledInit; if zero pop+ret. Loop: ecx=g_xformEntityIdx; esi=eax*4; eax=[ecx*4+0];
 *     edi=ecx*4. Three nested calls to StoreDoubleNegPauseSubStore (each gated on pause and
 *     non-null operand). Sets [esi+0x4/0x8/0xc] from g_walkCallback. Walk: esi=[esi]; eax=esi;
 *     scaledInit=eax; loop if nonzero. ret.
 */
extern unsigned int g_eq;
extern void StoreDoubleNegPauseSubStore(void);

__declspec(naked) void LinkedListFieldAdd_StoreDoubleNegPauseSubStore(void) {
    __asm {
        mov     eax, dword ptr [g_currentNodeIdx]
        push    esi
        test    eax, eax
        push    edi
        mov     dword ptr [g_walkCallback], eax
        _emit   0fh
        _emit   84h
        _emit   97h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_xformEntityIdx]
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [ecx*4 + 0]
        lea     edi, [ecx*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   13h
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   65h
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [edi + 4]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   13h
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   43h
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 8], eax
        mov     edi, dword ptr [edi + 8]
        test    edi, edi
        mov     dword ptr [g_walkCallback], edi
        _emit   74h
        _emit   14h
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   20h
        mov     edi, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x0c], edi
        mov     esi, dword ptr [esi]
        mov     eax, esi
        mov     dword ptr [g_walkCallback], esi
        test    esi, esi
        mov     dword ptr [g_currentNodeIdx], eax
        _emit   0fh
        _emit   85h
        _emit   69h
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x0049d450 (248b game) - linked-list traverse adding 3 fields per node.
 *   eax = [g_currentNodeIdx]; if 0 ret.
 *   ecx = [g_xformEntityIdx]<<2 (table base, byte address).
 *   For each node: node[+4/+8/+0xc] += table[+0/+4/+8] (g_walkCallback temp).
 *   eax = node[+0] (next link). Loop while eax != 0.
 *   Two loop body copies in the original - first uses shl/mov, second uses lea+mov.
 */
__declspec(naked) void LinkedListFieldAdd(void) {
    __asm {
        mov     eax, dword ptr [g_currentNodeIdx]
        push    esi
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   0fh
        _emit   84h
        _emit   0e3h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_xformEntityIdx]
        shl     ecx, 2
        shl     eax, 2
        mov     edx, dword ptr [ecx]
        mov     dword ptr [g_walkCallback], edx
        mov     esi, dword ptr [eax + 4]
        add     edx, esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 4], edx
        mov     edx, dword ptr [ecx + 4]
        mov     dword ptr [g_walkCallback], edx
        mov     esi, dword ptr [eax + 8]
        add     edx, esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 8], edx
        mov     ecx, dword ptr [ecx + 8]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax + 0x0c]
        add     ecx, edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x0c], ecx
        mov     eax, dword ptr [eax]
        xor     ecx, ecx
        test    eax, eax
        setne   cl
        test    ecx, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_eq], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        _emit   74h
        _emit   76h
        mov     edx, dword ptr [g_xformEntityIdx]
        shl     eax, 2
        lea     ecx, [edx*4 + 0]
        mov     edx, dword ptr [edx*4 + 0]
        mov     dword ptr [g_walkCallback], edx
        mov     esi, dword ptr [eax + 4]
        add     edx, esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 4], edx
        mov     edx, dword ptr [ecx + 4]
        mov     dword ptr [g_walkCallback], edx
        mov     esi, dword ptr [eax + 8]
        add     edx, esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 8], edx
        mov     ecx, dword ptr [ecx + 8]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax + 0x0c]
        add     ecx, edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x0c], ecx
        mov     eax, dword ptr [eax]
        xor     ecx, ecx
        test    eax, eax
        setne   cl
        test    ecx, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_eq], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        _emit   75h
        _emit   8ah
        pop     esi
        ret
    }
}
