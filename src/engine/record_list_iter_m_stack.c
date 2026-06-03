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

/* @addr 0x00422ce0 (318b game) - 0xffff0000-terminated record-list iterator with 3-push call + 3-pop.
 *   For each record from g_eventQueueIdx stream: read 3 fields (g_xformEntityIdx, g_eventQueueWorkType, g_currentNodeFlags).
 *   If 3rd field (g_currentNodeFlags) == 0xffff0000: terminate.
 *   Else: read 4th field (g_xformScratch2088). mstack-push g_eventQueueWorkType, g_eventQueueCurrent, g_xformEntityIdx.
 *   g_walkCallback=0x6c. Call StateMachineInit. If pause: ret.
 *   Mstack-pop: g_xformEntityIdx, g_eventQueueCurrent, g_eventQueueWorkType. If g_eventQueueWorkType!=0: [g_cj*4+0x58]=g_eventQueueWorkType.
 *   Re-read next field from g_eventQueueIdx stream, if !=0xffff0000 loop. Pop edi/esi; ret.
 */
extern void StateMachineInit(void);

extern unsigned int g_matrixStack_arr;

__declspec(naked) void RecordListIterMStack(void) {
    __asm {
        mov     ecx, dword ptr [g_eventQueueIdx]
        push    esi
        push    edi
        mov     eax, dword ptr [ecx*4 + 0]
        inc     ecx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     edx, dword ptr [ecx*4 + 0]
        inc     ecx
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0]
        inc     ecx
        cmp     eax, 0xffff0000
        mov     dword ptr [g_currentNodeFlags], eax
        mov     dword ptr [g_eventQueueIdx], ecx
        _emit   0fh
        _emit   84h
        _emit   0eeh
        _emit   00h
        _emit   00h
        _emit   00h
    loop_top:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edi, 0x6c
        mov     esi, dword ptr [ecx*4 + 0]
        inc     ecx
        inc     eax
        mov     dword ptr [g_xformScratch2088], esi
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], edx
        mov     dword ptr [g_walkCallback], edi
        call    StateMachineInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   7fh
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        test    edx, edx
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [g_matrixStackTop], eax
        _emit   74h
        _emit   17h
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [eax*4 + 0x58], edx
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     esi, dword ptr [ecx*4 + 0]
        inc     ecx
        cmp     esi, 0xffff0000
        mov     dword ptr [g_currentNodeFlags], esi
        mov     dword ptr [g_eventQueueIdx], ecx
        _emit   0fh
        _emit   85h
        _emit   1ch
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
        pop     edi
        pop     esi
        ret
    }
}
