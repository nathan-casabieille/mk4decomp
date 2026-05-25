/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004d6788;
extern unsigned int g_data_004f2100;
extern unsigned int g_data_004f2158;
extern unsigned int g_data_004f2168;
extern unsigned int g_data_004f27f0;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_00800000;
extern void ArgSarStoreJmp_004594f0(void);
extern void ArgSar_Set0_Jmp_0049c6f0(void);
extern void CallSetPause_0041f830(void);
extern void CondPickDualStore_0049c670(void);
extern void CopyThreeFields_00404df0(void);
extern void DualCmpSwapStore_0049c5a0(void);
extern void MStackPush8SlotInitPop8_00415010(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledStackCallPause_0049c360(void);
extern void ThreeChanPackClamp_00404cc0(void);
extern void TripleEntry3Block_00498df0(void);
extern void Vec3AccMul10ChainBlend_0049c3d0(void);

__declspec(naked) void AiComboDispatcherCluster_00497470(void)
{
    __asm {
        /* === h1 (0x497470): main combo install === */
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [g_xformScratch2088]
        mov      dword ptr [edx*4 + 0x60], eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, OFFSET g_data_004d6788
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop_00407140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_759d
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_data_004d57ac]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dl, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        test     dl, 4
        mov      dword ptr [g_data_004d57ac], eax
        je       short L_753d
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_data_004d57ac], eax
        jmp      CallSetPause_0041f830
    L_753d:
        inc      eax
        mov      edx, OFFSET g_data_004f27f0
        mov      dword ptr [g_data_004d57ac], eax
        shr      edx, 2
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_eventQueueTotal], edx
        call     Vec3AccMul10ChainBlend_0049c3d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_759d
        call     TripleEntry3Block_00498df0
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [eax*4 + 0x64], 0
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_data_004d57ac], eax
    L_759d:
        ret
        nop
        nop
        /* === h2 (0x4975a0): event 004f2100 forwarder w/ 0x310 === */
        call     CondPickDualStore_0049c670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_75d2
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x310
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_data_004f2100
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_75d2:
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
        nop
        nop
        nop
        /* === h3 (0x4975e0): event 004f2158 chained w/ 0x3333 ratio === */
        push     esi
        call     DualCmpSwapStore_0049c5a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_770d
        push     OFFSET g_data_004f2158
        call     ScaledStackCallPause_0049c360
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_770d
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_761d
        call     CallSetPause_0041f830
        pop      esi
        ret
    L_761d:
        push     OFFSET g_data_00800000
        call     ThreeChanPackClamp_00404cc0
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields_00404df0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0x9999
        add      esp, 4
        mov      eax, dword ptr [ecx*4 + 0x34]
        lea      esi, [ecx*4]
        mov      ecx, eax
        not      ecx
        and      ecx, 1
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       short L_766f
        mov      dword ptr [g_eventQueueWorkType], 0xffff6667
    L_766f:
        and      al, 0xfe
        or       eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x34], eax
        mov      edx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [esi + 0x80], edx
        mov      eax, dword ptr [g_currentNodeFlags]
        push     eax
        push     0x3333
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        push     ecx
        push     0x3333
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_xformScratch2088], eax
        mov      dword ptr [esi + 0x6c], edx
        mov      eax, dword ptr [g_xformScratch2088]
        mov      dword ptr [esi + 0x74], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [g_fightGroupHead], ecx
        add      esp, 8
        mov      dword ptr [edx*4 + 0x5c], 0x30
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [g_walkCallback], 1
        push     OFFSET g_data_004f2168
        mov      dword ptr [eax*4 + 0x74], 1
        call     ArgSar_Set0_Jmp_0049c6f0
        add      esp, 4
    L_770d:
        pop      esi
        ret
        nop
        /* === h4 (0x497720): combo state cycle 1→3, dec [+0x5c] === */
        push     0x100000
        call     ThreeChanPackClamp_00404cc0
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 4
        push     eax
        call     CopyThreeFields_00404df0
        mov      ecx, dword ptr [g_baseSel_00542060]
        add      esp, 4
        mov      eax, dword ptr [ecx*4 + 0x74]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        jne      short L_774a
        mov      eax, 3
        mov      dword ptr [g_walkCallback], eax
    L_774a:
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      eax, dword ptr [g_walkCallback]
        test     eax, eax
        jne      short L_7768
        call     MStackPush8SlotInitPop8_00415010
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7789
    L_7768:
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [ecx*4 + 0x5c]
        dec      eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        jne      short L_7789
        jmp      ScaledIndirectJmp_0049c850
    L_7789:
        ret
    }
}
