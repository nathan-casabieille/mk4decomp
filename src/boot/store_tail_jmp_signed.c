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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

/* @addr 0x004107d0 (198b boot) - 2-arg cdecl call + neg-chain + signed-bit branch + final tail-jmp.
 *   g_eventQueueIdx = g_walkCallback; push 0x2f, 0x4109b0; call StoreTwoCall;
 *   g_baseSel = g_scaledInit; g_scaledInit = [0x52ab10];
 *   ecx = -chain[g_scaledInit + 0x64]; g_walkCallback = ecx;
 *   eax = chain[g_fightGroupHead + 0x34]; g_eventQueueCurrent = eax;
 *   g_xformScratch94 = eax & 1; if (bit clear) skip the add;
 *   else: g_walkCallback = ecx + g_pendingMatchVar3_004d5320;
 *   call BootMod6487eClampAndChainMul10; pause? ret;
 *   g_eventQueueWorkType = g_walkCallback; g_pendingNodeType = g_dispatchSave6_00541f94;
 *   call MStackPush2DualModMul10Pop2_00424860; pause? ret;
 *   g_scaledInit = g_baseSel + 0xc; g_xformEntityIdx = g_pendingNodeType;
 *   g_pendingNodeType += 9; jmp QuadInterpolator.
 */
extern unsigned int g_pendingMatchVar3_004d5320;
extern unsigned int g_load_0052ab10;
extern unsigned int g_dispatchSave6_00541f94;
extern void MStackPush2DualModMul10Pop2_00424860(void);
extern void QuadInterpolator(void);

__declspec(naked) void StoreTailJmpSigned_004107d0(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        push    0x2f
        push    0x004109b0
        mov     dword ptr [g_eventQueueIdx], eax
        call    StoreTwoCall
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [g_load_0052ab10]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_baseSel], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, [eax*4 + 0x64]
        neg     ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, [edx*4 + 0x34]
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        and     eax, 1
        mov     dword ptr [g_xformScratch94], eax
        _emit   74h
        _emit   0ch
        add     ecx, dword ptr [g_pendingMatchVar3_004d5320]
        mov     dword ptr [g_walkCallback], ecx
        call    BootMod6487eClampAndChainMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   51h
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_dispatchSave6_00541f94]
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_pendingNodeType], ecx
        call    MStackPush2DualModMul10Pop2_00424860
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2dh
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     eax, dword ptr [g_pendingNodeType]
        add     edx, 0x0c
        add     ecx, 9
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_pendingNodeType], ecx
        jmp     QuadInterpolator
        ret
    }
}
