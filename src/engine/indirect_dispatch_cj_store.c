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

/* @addr 0x0048ae50 (263b game) - mstack-push pair + indirect dispatch + cj copy.
 *   mstack-push g_currentNodeFlags and g_xformScratch2088. g_eventQueueCurrent = g_currentNodeFlags.
 *   g_scaledInit_00542044 = g_eventQueueEnd; g_xformEntityIdx = g_eventQueueIdx.
 *   g_walkCallback = 0; indirect call [g_eventQueueChild] (cdecl callback).
 *   If pause? final-ret. call AerialKickComboCluster; if pause? final-ret.
 *   cj[+0x58] = g_walkCallback; cj[+0x54] = g_currentNodeFlags; cj[+0x5c] = g_xformScratch2088.
 *   mstack-pop g_xformScratch2088, g_currentNodeFlags. g_walkCallback = 1; tail-jmp [g_eventQueueChild].
 *   ret. Followed by small tail block: if g_walkCallback == 0, g_eventQueueTotal = 0x00537ec0>>2; ret.
 */
extern void AerialKickComboCluster(void);

__declspec(naked) void IndirectDispatchCjStore(void) {
    __asm {
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, dword ptr [g_currentNodeFlags]
        inc     ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_matrixStackTop], ecx
        mov     dword ptr [ecx*4 + 0], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformScratch2088]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_walkCallback], 0
        call    dword ptr [g_eventQueueChild]
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   80h
        _emit   00h
        _emit   00h
        _emit   00h
        call    AerialKickComboCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   72h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x58], edx
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     eax, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_xformScratch2088]
        mov     dword ptr [eax*4 + 0x5c], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformScratch2088], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_currentNodeFlags], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [g_walkCallback], 1
        jmp     dword ptr [g_eventQueueChild]
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        mov     eax, dword ptr [g_walkCallback]
        test    eax, eax
        _emit   75h
        _emit   0dh
        mov     eax, 0x00537ec0
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        ret
    }
}
