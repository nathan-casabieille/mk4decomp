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

extern unsigned int g_audioStateMachineVar7_004f2fc0;
extern unsigned int g_dispatchSave807_004f31a0;
extern unsigned int g_audioStateMachineVar6_004f31cc;
extern unsigned int g_audioStateMachineVar5_004f31d0;
extern unsigned int g_dispatchSave557_004f31d8;
extern unsigned int g_audioStateMachineVar4_004f3220;
extern unsigned int g_byte_004f3238;
extern unsigned int g_dispatchSave810_004f3240;
extern unsigned int g_dispatchSave811_004f3264;
extern unsigned int g_dispatchSave812_004f33cc;
extern unsigned int g_dispatchSave822_004f42e0;
extern unsigned int g_dispatchSave823_004f42f4;
extern unsigned int g_dispatchSave824_004f4304;
extern unsigned int g_dispatchSave825_004f4310;
extern unsigned int g_dispatchSave826_004f4320;
extern unsigned int g_dispatchSave827_004f432c;
extern unsigned int g_voiceBankTickBase_00543450;
extern unsigned int g_audioSavedGlobal4_005437f8;
extern unsigned int g_audioSavedGlobal5_005437fc;
extern void GuardedSetupCallTailJmp_004a1fa0(void);
extern void Helper_Sprintf(void);
extern void MStackPush2ChainLLInsert_00406790(void);

/* @addr 0x004a3120 (320b) - DebugMenu_DrawMatchOptions: renders the
 * match-setup section of MK4's hidden debug/"kheat" menu. Walks a
 * per-row record table and, per row, sprintf's a label + state value
 * into the shared text buffer g_voiceBankTickBase (0x543450), then
 * inserts it as a scene text node via GuardedSetupCallTailJmp. The
 * 6 row labels are "Player 1 %s", "Player 2 %s", "Difficulty %s",
 * "Opponent %s", "Background %s", "Practice Info %s"; the %s value is
 * looked up from the 0x4f2fc0 table whose [0]/[1] entries are the
 * strings "OFF"/"ON", so each row shows an ON/OFF (or value) toggle.
 * (NOT audio - the old "VoiceBankTickDispatch" name was wrong; the
 * values come from game/input state globals at 0x4d50xx / 0x543xxx.)
 */
__declspec(naked) void DebugMenu_DrawMatchOptions(void)
{
    __asm {
        push     esi
        push     edi
        xor      edi, edi
        mov      esi, OFFSET g_dispatchSave811_004f3264
    L_3129:
        movsx    eax, byte ptr [esi - 4]
        mov      ecx, dword ptr [g_baseSel]
        add      ecx, eax
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPush2ChainLLInsert_00406790
        lea      eax, [edi - 1]
        cmp      eax, 5
        ja       L_31e2
        jmp      dword ptr [eax*4 + L_120_jmptbl]
    L_315a:
        mov      eax, dword ptr [g_audioStateMachineVar6_004f31cc]
        mov      ecx, dword ptr [eax*4 + g_dispatchSave557_004f31d8]
        push     ecx
        push     OFFSET g_dispatchSave827_004f432c
        jmp      L_31d5
    L_316e:
        mov      edx, dword ptr [g_audioStateMachineVar5_004f31d0]
        mov      eax, dword ptr [edx*4 + g_dispatchSave557_004f31d8]
        push     eax
        push     OFFSET g_dispatchSave826_004f4320
        jmp      L_31d5
    L_3183:
        mov      ecx, dword ptr [g_audioSavedGlobal5_005437fc]
        mov      edx, dword ptr [ecx*4 + g_audioStateMachineVar4_004f3220]
        push     edx
        push     OFFSET g_dispatchSave825_004f4310
        jmp      L_31d5
    L_3198:
        mov      eax, dword ptr [g_gtConfig4f]
        mov      ecx, dword ptr [eax*4 + g_dispatchSave810_004f3240]
        push     ecx
        push     OFFSET g_dispatchSave824_004f4304
        jmp      L_31d5
    L_31ac:
        mov      edx, dword ptr [g_audioSavedGlobal4_005437f8]
        mov      eax, dword ptr [edx*4 + g_dispatchSave807_004f31a0]
        push     eax
        push     OFFSET g_dispatchSave823_004f42f4
        jmp      L_31d5
    L_31c1:
        movsx    ecx, byte ptr [g_byte_004f3238]
        mov      edx, dword ptr [ecx*4 + g_audioStateMachineVar7_004f2fc0]
        push     edx
        push     OFFSET g_dispatchSave822_004f42e0
    L_31d5:
        push     OFFSET g_voiceBankTickBase_00543450
        call     Helper_Sprintf
        add      esp, 0xc
    L_31e2:
        mov      eax, dword ptr [esi + 8]
        mov      ecx, dword ptr [esi]
        push     eax
        push     ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [esi + 0xc]
        add      esp, 8
        add      esi, 0x24
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [esi - 0x20], edx
        mov      edx, dword ptr [g_baseSel]
        movsx    ecx, byte ptr [esi - 0x28]
        mov      dword ptr [g_eventQueueCurrent], ecx
        add      ecx, edx
        inc      edi
        cmp      esi, OFFSET g_dispatchSave812_004f33cc
        mov      dword ptr [ecx*4], eax
        jb       L_3129
        pop      edi
        pop      esi
        ret
        nop
    L_120_jmptbl:
        _emit 0x5a
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0x6e
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0x83
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0x98
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0xac
        _emit 0x31
        _emit 0x4a
        _emit 0x00
        _emit 0xc1
        _emit 0x31
        _emit 0x4a
        _emit 0x00
    }
}
