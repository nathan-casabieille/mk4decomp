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

extern unsigned int g_dispatchSave551_004ffe04;
extern void Set200dCallPauseJmp_0047c5e0(void);
extern void StageEventExitCluster_0047cd50(void);
extern void InstallSelfCountdown2Stage_0047c8f0(void);
extern void ScaledChainJmp_00429470(void);

/* @addr 0x0047c990 (357b game) - install-self w/ MStack snapshot + packed_ptr.
 *   On phase != 0 tail-calls Set200dCallPauseJmp_0047c5e0. Then if
 *   g_audioBankSel != 0 tail-calls StageEventExitCluster_0047cd50.
 *   Otherwise pushes g_eventQueueChild onto the mstack and sets
 *   g_walkCallback=0xb333, calls EsiEdiAliasDualMul10_004906b0. On
 *   no-error sets g_xformScratch2088=0x11999, calls PunchAnimCluster_00496d80. Pops
 *   back into g_eventQueueChild, then calls NotMaskStorePair_0045f440.
 *   Selects 0x542074 = 1 or 0x10 based on g_fightGroupHead ==
 *   g_player1NodeIdx, AND with g_eventQueueCurrent → g_xformScratch94: if
 *   nonzero tail-calls InstallSelfCountdown2Stage_0047c8f0; else writes
 *   &g_dispatchSave551_004ffe04>>2 into g_currentNodeIdx / [ecx*4+0x24] and installs
 *   Self at [esi+8], packs (Self + 0x01000000) at the bumped scaled
 *   slot, slot[+0x84]=0, calls ScaledChainJmp_00429470, arms 0x541e6c.
 */
extern unsigned int g_table_004d57b0;
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void NotMaskStorePair_0045f440(void);
extern void PunchAnimCluster_00496d80(void);

__declspec(naked) void InstallSelfMStackPackedFlow_0047c990(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_ism_check2
        call    Set200dCallPauseJmp_0047c5e0
        pop     esi
        ret
    L_ism_check2:
        mov     eax, dword ptr [g_audioBankSel]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_ism_push
        call    StageEventExitCluster_0047cd50
        pop     esi
        ret
    L_ism_push:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueChild]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        mov     dword ptr [g_walkCallback], 0xb333
        call    EsiEdiAliasDualMul10_004906b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ism_done
        mov     dword ptr [g_xformScratch2088], 0x11999
        call    PunchAnimCluster_00496d80
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ism_done
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [g_matrixStackTop], eax
        call    NotMaskStorePair_0045f440
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ism_done
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_player1NodeIdx]
        mov     eax, 1
        cmp     ecx, edx
        mov     dword ptr [g_eventQueueWorkType], eax
        je      short L_ism_pickEax
        mov     eax, 0x10
        mov     dword ptr [g_eventQueueWorkType], eax
    L_ism_pickEax:
        and     eax, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [g_xformScratch94], eax
        je      short L_ism_installSelf
        call    InstallSelfCountdown2Stage_0047c8f0
        pop     esi
        ret
    L_ism_installSelf:
        mov     eax, offset g_dispatchSave551_004ffe04
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [ecx*4 + 0x24], eax
        mov     dword ptr [esi + 8], offset InstallSelfMStackPackedFlow_0047c990
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, offset InstallSelfMStackPackedFlow_0047c990
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    ScaledChainJmp_00429470
        mov     dword ptr [g_framePauseFlag], 1
    L_ism_done:
        pop     esi
        ret
    }
}
