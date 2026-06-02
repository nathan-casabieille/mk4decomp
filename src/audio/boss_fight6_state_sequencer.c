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

extern unsigned int g_dispatchSave884;
extern unsigned int g_dispatchSave885;
extern unsigned int g_dispatchSave886;
extern unsigned int g_audioStreamState;
extern void AudioInitInstallerPair(void);
extern void BootInitGuardedCallChain(void);
extern void GuardedSetupCallTailJmp(void);
extern void TwoCallsTwoBranchTail(void);

__declspec(naked) void Match_OutcomeScreen(void)
{
    __asm {
    L_3ce0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 5
        ja       L_3f23
        jmp      dword ptr [eax*4 + L_jmptbl_3f30]
    L_3d0d:
        /* case 1: kick off if state == 0 then check 0053a430 flag */
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [edx*4 + 0x74], edi
        mov      eax, dword ptr [g_audioStreamState]
        cmp      eax, edi
        jne      short L_3d63
        call     TwoCallsTwoBranchTail
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3f2d
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x1e
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3d63:
        /* case 2: arm slot-0x34 velocity */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x34]
        mov      dword ptr [ecx*4 + 0x58], 0x140000
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [eax*4 + 0x74], 0xffffc000
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x24
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3dba:
        /* case 3: reset slot-0x34 velocity to 0 */
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x34]
        mov      dword ptr [edx*4 + 0x74], edi
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3df6:
        /* case 4: state-bump only */
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3e1e:
        /* case 5: long-timer state-bump */
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_pendingNodeType], 0xf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3e46:
        /* case 0: initial spawn - pick mesh by flag, install slots */
        push     0xffec0000
        push     OFFSET g_dispatchSave884
        call     GuardedSetupCallTailJmp
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edi, 1
        add      esp, 8
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      eax, dword ptr [g_audioBankSel]
        cmp      eax, edi
        mov      eax, OFFSET g_dispatchSave885
        je       short L_3e82
        mov      eax, OFFSET g_dispatchSave886
    L_3e82:
        push     0x140000
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      dword ptr [edx*4 + 0x34], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0xa0000
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x34]
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x34]
        mov      dword ptr [ecx*4 + 0x58], 0xf0600000
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [edx*4 + 0x30]
        mov      dword ptr [eax*4 + 0x74], 0xffffc000
        mov      dword ptr [esi + 8], OFFSET L_3ce0
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], 0x24
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_3f23:
        call     BootInitGuardedCallChain
        call     AudioInitInstallerPair
    L_3f2d:
        pop      edi
        pop      esi
        ret
    L_jmptbl_3f30:
        /* 6 absolute-address entries (no reloc - orig has DIR32 reloc;
           literal bytes match link-time addresses) */
        _emit 0x46
        _emit 0x3e
        _emit 0x4a
        _emit 0x00
        _emit 0x0d
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0x63
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0xba
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0xf6
        _emit 0x3d
        _emit 0x4a
        _emit 0x00
        _emit 0x1e
        _emit 0x3e
        _emit 0x4a
        _emit 0x00
    }
}
