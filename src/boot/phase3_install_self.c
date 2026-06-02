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

extern void Phase3InstallSelf(void);
extern unsigned int g_dst_0053a6e0;

/*
 * BootStateMachine4Way - 257b boot 4-state install-self machine.
 *   chain = g_baseSel<<2; saved = chain->state; chain->state=0.
 *   sub ecx,0 flags branch:
 *     state 0 → init full: g_phaseIdx_0053a50c=7; g_dst_0053a6e0=1; g_walkCallback=0; g_dst_00537ea4=0;
 *       install-self; chain->state=1; mstack-push (entry+0x01000000); g_currentNodeIdx++; chain->state=0;
 *       call Phase3InstallSelf; g_framePauseFlag=1; pop+ret.
 *     state 1 → install-self; chain->state=2; g_pendingNodeType=0xa0; g_framePauseFlag=1; pop+ret.
 *     state 2 → install-self; chain->state=3; g_pendingNodeType=0x384; g_framePauseFlag=1;
 *       g_walkCallback=1; g_smState4Way_00541dc8=1; pop+ret.
 *     state 3+ → tail-call BootDualStateInstallSelf; pop+ret.
 */
extern unsigned int g_phaseIdx_0053a50c;
extern unsigned int g_smState4Way_00541dc8;
extern unsigned int g_dst_00537ea4;
extern void BootDualStateInstallSelf(void);

__declspec(naked) void BootStateMachine4Way(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        push    esi
        push    edi
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        sub     ecx, edx
        je      short L_s0
        dec     ecx
        je      short L_s1
        dec     ecx
        je      short L_s2
        call    BootDualStateInstallSelf
        pop     edi
        pop     esi
        ret
    L_s2:
        mov     esi, 1
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_smState4Way_00541dc8], esi
        mov     dword ptr [eax + 8], offset BootStateMachine4Way
        mov     dword ptr [eax + 0x84], 3
        mov     dword ptr [g_pendingNodeType], 0x384
        mov     dword ptr [g_framePauseFlag], esi
        pop     edi
        pop     esi
        ret
    L_s1:
        mov     dword ptr [eax + 8], offset BootStateMachine4Way
        mov     dword ptr [eax + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 0xa0
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        pop     esi
        ret
    L_s0:
        mov     esi, 1
        mov     dword ptr [g_phaseIdx_0053a50c], 7
        mov     dword ptr [g_dst_0053a6e0], esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_dst_00537ea4], edx
        mov     dword ptr [eax + 8], offset BootStateMachine4Way
        mov     ecx, dword ptr [g_baseSel]
        mov     edi, offset BootStateMachine4Way
        add     edi, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], esi
        mov     ecx, dword ptr [eax + 4]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    Phase3InstallSelf
        mov     dword ptr [g_framePauseFlag], esi
        pop     edi
        pop     esi
        ret
    }
}
