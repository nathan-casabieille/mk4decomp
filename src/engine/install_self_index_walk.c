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
extern void CopyJmp_0048ef90(void);
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

/* @addr 0x00450de0 (229b game) - install-self with index-walk loop.
 *   snapshot+clear chain[+0x84]. If was nonzero -> recompute eax = 0x004e7528>>2 + 5
 *     (jmp at +0xa7 back to +0x63) then resume search.
 *   If was zero: call DualScaledStore; if pause? ret.
 *   else: copy g_cj_0054205c to baseSel[+0x4c] and g_eventQueueIdx; compute
 *   eax = 0x004e7528>>2 -> g_eventQueueEnd -> [eax*4]; if <0: call Thunk_ScaledNeg1SetPause, ret.
 *   else: add g_eventQueueChild; load scaledInit; indirect call. If pause? ret.
 *   else: refetch [g_eventQueueEnd*4+0x10]; if zero: add 5 to eax, jmp back to scaledInit
 *   walk. If non-zero: install-self at [esi+8]=0x00450de0, chain[+0x84]=1, pause=1; ret.
 */
extern unsigned int g_dispatchSave946;
extern void DualScaledStore(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void InstallSelfIndexWalk(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        mov     edi, OFFSET InstallSelfIndexWalk
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        jne     L_isw_resume2
        call    DualScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isw_pop_ret
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     dword ptr [edx*4 + 0x4c], ecx
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, OFFSET g_dispatchSave946
        shr     eax, 2
L_isw_walk:
        mov     dword ptr [g_eventQueueEnd], eax
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jge     short L_isw_after_thunk
        call    Thunk_ScaledNeg1SetPause
        pop     edi
        pop     esi
        ret
L_isw_after_thunk:
        mov     ecx, dword ptr [g_eventQueueChild]
        add     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], eax
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isw_pop_ret
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4 + 0x10]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        jne     short L_isw_install
        add     eax, 5
        jmp     short L_isw_walk
L_isw_resume2:
        mov     eax, dword ptr [g_eventQueueEnd]
        add     eax, 5
        jmp     short L_isw_walk
L_isw_install:
        mov     eax, 1
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [esi + 8], edi
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_framePauseFlag], eax
L_isw_pop_ret:
        pop     edi
        pop     esi
        ret
    }
}
