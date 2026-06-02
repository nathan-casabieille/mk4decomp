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

extern unsigned int g_const_0044d820;
extern unsigned int g_dispatchSave543_004e65b8;
extern unsigned int g_dispatchSave542_004e65c8;
extern unsigned int g_dispatchTableArr5_00501088;
extern void ArgSarStoreJmp(void);
extern void DoubleScaledCrossStore(void);
extern void GatedWordPushCall(void);
extern void InstallSelfPackedTailJmp(void);
extern void PendingMatch_0044d7a0(void);
extern void SetJmp_004753a0(void);
extern void StoreLoadJmp(void);
extern void Thunk_0049cbc0(void);

__declspec(naked) void IntroFsmCluster_0044d580(void)
{
    __asm {
    L_d580:
        /* H1 */
        push     OFFSET g_dispatchSave543_004e65b8
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        /* H2 */
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        js       short L_d5a2
        /* orig uses near jmp form here (e9 rel32) even though
         * short would fit; force the 5-byte encoding. */
        _emit    0xe9
        _emit    0xde
        _emit    0xff
        _emit    0xff
        _emit    0xff
    L_d5a2:
        call     ScaledZeroFour
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d5b5
        jmp      Thunk_0049cbc0
    L_d5b5:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H3 (L_d5c0): 4-state FSM */
    L_d5c0:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        sub      ecx, 0
        je       L_d6f0
        dec      ecx
        je       short L_d68d
        dec      ecx
        je       short L_d61c
        call     DoubleScaledCrossStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d738
        mov      ecx, dword ptr [g_eventQueueEnd]
        push     OFFSET g_dispatchSave542_004e65c8
        mov      dword ptr [g_fightGroupHead], ecx
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret
    L_d61c:
        mov      edx, OFFSET g_dispatchTableArr5_00501088
        shr      edx, 2
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [eax + 8], OFFSET L_d5c0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_d5c0
        add      edx, 0x3000000
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     SetJmp_004753a0
        mov      dword ptr [g_framePauseFlag], 1
        ret
    L_d68d:
        mov      dword ptr [eax + 8], OFFSET L_d5c0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_d5c0
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfPackedTailJmp
        mov      dword ptr [g_framePauseFlag], 1
        ret
    L_d6f0:
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [ecx*4 + 0x68], edx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_d5c0
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0xb
        mov      dword ptr [g_framePauseFlag], ecx
    L_d738:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H4 */
        mov      eax, dword ptr [g_baseSel]
        push     OFFSET g_const_0044d820
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      edx, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_eventQueueIdx], edx
        call     StoreLoadJmp
        add      esp, 4
        mov      dword ptr [g_walkCallback], 0x2b
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d793
        mov      dword ptr [g_eventQueueEnd], 1
        jmp      PendingMatch_0044d7a0
    L_d793:
        ret
    }
}
