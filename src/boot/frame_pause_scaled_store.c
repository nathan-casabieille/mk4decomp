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

extern void ScaledArrStore_004298c0(void);
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

extern void (*g_iat_CloseHandle)();
extern unsigned char g_framePauseArrBase;
extern unsigned int g_chain_disp_64_49b7c0;
extern unsigned int g_arr_next_49b7c0;
extern unsigned int g_chain_disp_1c_49b7c0;
extern unsigned int g_chain_disp_38_49b7c0;
extern void FramePauseScaledStore(void);
extern void MStackPush2ChainPrepend(void);

/* @addr 0x0049b7c0 (143b game) - walk linked chain until end:
 *   g_xformEntityIdx = (0x50b4b4 >> 2); call F; pause? ret.
 *   ecx = chain[sel].slot64; g_xformEntityIdx = ecx;
 *   while (arr_next[ecx] != 0): ecx = arr_next[ecx]; g_walkCallback = ecx.
 *   At tail: eax = -0x4ccc; g_eventQueueCurrent = eax;
 *   ecx = chain[last].slot1c; g_walkCallback = ecx;
 *   if (ecx == 4): eax = 0xffff6667; g_eventQueueCurrent = eax;
 *   chain[g_scaledInit].slot38 = eax; jmp F2.
 */

__declspec(naked) void ChainWalkInstall(void) {
    __asm {
        mov     eax, offset g_framePauseArrBase
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    FramePauseScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   73h
        mov     ecx, dword ptr [g_baseSel]
        mov     ecx, [ecx*4 + g_chain_disp_64_49b7c0]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, [ecx*4 + g_arr_next_49b7c0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
walkNext:
        mov     ecx, eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, [eax*4 + g_arr_next_49b7c0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0e8h
        mov     eax, 0xffffb334
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     ecx, [ecx*4 + g_chain_disp_1c_49b7c0]
        cmp     ecx, 4
        mov     dword ptr [g_walkCallback], ecx
        _emit   75h
        _emit   0ah
        mov     eax, 0xffff6667
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     [edx*4 + g_chain_disp_38_49b7c0], eax
        jmp     MStackPush2ChainPrepend
        ret
    }
}
