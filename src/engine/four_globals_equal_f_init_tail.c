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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

/* @addr 0x004236a0 (125b) - if any of {g_dlNalt1, g_dlNalt2,
 *   g_dlNalt3, g_dlNalt4} == 0xf: clear g_counter_0053a51c & g_walkCallback,
 *   call F1. Then v3 = (data_4dfd48 >> 2) + g_counter_0053a51c;
 *   g_scaledInit_00542044 = v3; arg = arr[v3];
 *   push arg twice; g_rangeBase = arg; call Mul10Tail; g_rangeSqLimit = res; jmp F3.
 */
extern unsigned int g_dispatchSave623_004dfd48;
extern unsigned int g_matrixStack_arr;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern s32 g_dlNalt3;
extern s32 g_dlNalt4;
extern unsigned int g_rangeBase;
extern unsigned int g_counter_0053a51c;
extern void ScenePostInitSequencer_00429b70(void);
extern void TablePushAccumTailJmp_00429e30(void);

__declspec(naked) void FourGlobalsEqualFInitTail_004236a0(void) {
    __asm {
        mov     ecx, dword ptr [g_dlNalt1]
        mov     eax, 0xf
        cmp     ecx, eax
        _emit   74h
        _emit   18h
        cmp     dword ptr [g_dlNalt2], eax
        _emit   74h
        _emit   10h
        cmp     dword ptr [g_dlNalt3], eax
        _emit   74h
        _emit   08h
        cmp     dword ptr [g_dlNalt4], eax
        _emit   75h
        _emit   11h
        xor     eax, eax
        mov     dword ptr [g_counter_0053a51c], eax
        mov     dword ptr [g_walkCallback], eax
        call    TablePushAccumTailJmp_00429e30
        mov     ecx, dword ptr [g_counter_0053a51c]
        mov     eax, offset g_dispatchSave623_004dfd48
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, [eax*4 + g_matrixStack_arr]
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_rangeBase], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_rangeSqLimit], eax
        jmp     ScenePostInitSequencer_00429b70
    }
}
