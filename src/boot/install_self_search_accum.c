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

/* @addr 0x00402b40 (193b boot) - install-self with init+search loop and accumulate.
 *   esi = base*4; flag = [esi+0x84]; clear.
 *   if (flag == 0): g_eventQueueWorkType = 0x34d (init); fall through.
 *   call Push16Call; pause? -> end.
 *   if (flag == 0): ecx = (0x4d5760 >> 2) (packed_ptr); g_fightGroupHead = ecx; jmp +6.
 *   else: ecx = g_fightGroupHead (already set).
 *   ecx++; eax = chain[ecx]; g_walkCallback = eax; g_fightGroupHead = ecx;
 *   if (eax != 0): {
 *     ecx = g_eventQueueEnd; chain[ecx + 0x58] += eax;
 *     g_eventQueueCurrent = sum; chain[g_eventQueueIdx + 0x58] = sum;
 *     install self; [esi+0x84]=1; g_pendingNodeType=2; pause=1.
 *   } else: call StackPopDispatchTagged; pop esi; ret.
 */

extern unsigned int g_matrixStack_arr;

__declspec(naked) void InstallSelfSearchAccum(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + g_matrixStack_arr]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   2ch
        mov     dword ptr [g_eventQueueWorkType], 0x34d
        call    Push16Call
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   81h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, 0x004d5760
        shr     ecx, 2
        mov     dword ptr [g_fightGroupHead], ecx
        _emit   0ebh
        _emit   06h
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, [ecx*4 + g_matrixStack_arr]
        inc     ecx
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_fightGroupHead], ecx
        _emit   75h
        _emit   07h
        call    StackPopDispatchTagged
        pop     esi
        ret
        mov     ecx, dword ptr [g_eventQueueEnd]
        add     eax, [ecx*4 + 0x58]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     eax, 1
        mov     [edx*4 + 0x58], ecx
        mov     dword ptr [esi + 8], 0x00402b40
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 2
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
