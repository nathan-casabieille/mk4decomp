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

/* @addr 0x0042e800 (206b game) - scaledInit chain init with 2 phases.
 *   Phase 1: scaledInit[+0x54] = 0; +0x58 = 0; +0x5c += 0x41999; +0x68 = 0x62978;
 *   +0x74 = 0xffffaaab; +0x30 = arg1; g_walkCallback = arg1.
 *   call MStackCall_00406340; if !pause: phase 2: g_pendingNodeType = g_particleEmitterNode;
 *   second chain at g_pendingNodeType[+0x54/0x58/0x5c]=0/0xfffc0000/0;
 *   g_scaledInit[+0x3c] = g_pendingNodeType. pop+ret.
 */
extern unsigned int g_particleEmitterNode;
extern void MStackCall_00406340(void);

__declspec(naked) void ScaledChainInit2Phase_0042e800(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        push    esi
        xor     esi, esi
        mov     dword ptr [eax*4 + 0x54], esi
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [ecx*4 + 0x58], esi
        mov     edx, dword ptr [g_cj_00542054]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [edx*4 + 0x5c]
        add     eax, 0x00041999
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [edx*4 + 0x68], 0x00062978
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [eax*4 + 0x74], 0xffffaaab
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        call    MStackCall_00406340
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   75h
        _emit   47h
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [eax*4 + 0x54], esi
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [edx*4 + 0x58], 0xfffc0000
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [eax*4 + 0x5c], esi
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [ecx*4 + 0x3c], edx
        pop     esi
        ret
    }
}
