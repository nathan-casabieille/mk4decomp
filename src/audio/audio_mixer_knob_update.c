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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
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
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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

extern unsigned int g_byte_004d50b4;
extern unsigned int g_audioStateMachine0;
extern unsigned int g_audioStateMachine1;
extern unsigned int g_audioMixerKnob;
extern unsigned int g_counter_005433c8;
extern unsigned int g_audioMixerKnob2;
extern unsigned int g_counter_0054359c;
extern unsigned int g_byte_005435a0;
extern void ScaledChainStore24(void);
extern void SetJmp_Push16Call_004a1ad0(void);

__declspec(naked) void AudioMixerKnobUpdate(void)
{
    __asm {
        mov      eax, dword ptr [g_audioMixerKnob2]
        test     eax, eax
        jne      short L_8aea
        test     byte ptr [g_byte_004d50b4], 4
        je       short L_8ac6
        mov      eax, dword ptr [g_counter_0054359c]
        test     eax, eax
        jle      short L_8ac6
        call     SetJmp_Push16Call_004a1ad0
        dec      dword ptr [g_counter_0054359c]
    L_8ac6:
        test     byte ptr [g_byte_004d50b4], 8
        je       short L_8aea
        mov      eax, dword ptr [g_audioStateMachine0]
        mov      ecx, dword ptr [g_counter_0054359c]
        dec      eax
        cmp      ecx, eax
        jge      short L_8aea
        call     SetJmp_Push16Call_004a1ad0
        inc      dword ptr [g_counter_0054359c]
    L_8aea:
        cmp      dword ptr [g_audioMixerKnob2], 1
        jne      L_8b98
        mov      al, byte ptr [g_byte_004d50b4]
        mov      ecx, dword ptr [g_counter_0054359c]
        test     al, 4
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       short L_8b34
        call     SetJmp_Push16Call_004a1ad0
        mov      ecx, dword ptr [g_eventQueueCurrent]
        lea      eax, [ecx + ecx*2]
        mov      dl, byte ptr [eax*8 + g_byte_005435a0]
        dec      dl
        mov      byte ptr [eax*8 + g_byte_005435a0], dl
        jns      short L_8b34
        mov      byte ptr [eax*8 + g_byte_005435a0], 0xe
    L_8b34:
        test     byte ptr [g_byte_004d50b4], 8
        je       short L_8b68
        call     SetJmp_Push16Call_004a1ad0
        mov      ecx, dword ptr [g_eventQueueCurrent]
        lea      eax, [ecx + ecx*2]
        mov      dl, byte ptr [eax*8 + g_byte_005435a0]
        inc      dl
        cmp      dl, 0xf
        mov      byte ptr [eax*8 + g_byte_005435a0], dl
        jne      short L_8b68
        mov      byte ptr [eax*8 + g_byte_005435a0], 0
    L_8b68:
        mov      eax, dword ptr [g_baseSel]
        lea      ecx, [ecx + ecx*2]
        movsx    edx, byte ptr [ecx*8 + g_byte_005435a0]
        mov      ecx, dword ptr [g_counter_0054359c]
        mov      dword ptr [g_walkCallback], edx
        add      ecx, eax
        mov      edx, dword ptr [ecx*4 + 0x34]
        mov      dword ptr [g_currentNodeIdx], edx
        call     ScaledChainStore24
    L_8b98:
        mov      eax, dword ptr [g_audioMixerKnob]
        test     eax, eax
        jne      short L_8be4
        mov      eax, dword ptr [g_byte_004d50b4]
        test     ah, 4
        je       short L_8bbf
        mov      eax, dword ptr [g_counter_005433c8]
        test     eax, eax
        jle      short L_8bbf
        call     SetJmp_Push16Call_004a1ad0
        dec      dword ptr [g_counter_005433c8]
    L_8bbf:
        mov      eax, dword ptr [g_byte_004d50b4]
        test     ah, 8
        je       short L_8be4
        mov      eax, dword ptr [g_audioStateMachine1]
        mov      ecx, dword ptr [g_counter_005433c8]
        dec      eax
        cmp      ecx, eax
        jge      short L_8be4
        call     SetJmp_Push16Call_004a1ad0
        inc      dword ptr [g_counter_005433c8]
    L_8be4:
        cmp      dword ptr [g_audioMixerKnob], 1
        jne      L_8c96
        mov      ecx, dword ptr [g_counter_005433c8]
        mov      eax, dword ptr [g_byte_004d50b4]
        add      ecx, 5
        test     ah, 4
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       short L_8c32
        call     SetJmp_Push16Call_004a1ad0
        mov      ecx, dword ptr [g_eventQueueCurrent]
        lea      eax, [ecx + ecx*2]
        mov      dl, byte ptr [eax*8 + g_byte_005435a0]
        dec      dl
        mov      byte ptr [eax*8 + g_byte_005435a0], dl
        jns      short L_8c32
        mov      byte ptr [eax*8 + g_byte_005435a0], 0xe
    L_8c32:
        mov      eax, dword ptr [g_byte_004d50b4]
        test     ah, 8
        je       short L_8c67
        call     SetJmp_Push16Call_004a1ad0
        mov      ecx, dword ptr [g_eventQueueCurrent]
        lea      eax, [ecx + ecx*2]
        mov      dl, byte ptr [eax*8 + g_byte_005435a0]
        inc      dl
        cmp      dl, 0xf
        mov      byte ptr [eax*8 + g_byte_005435a0], dl
        jne      short L_8c67
        mov      byte ptr [eax*8 + g_byte_005435a0], 0
    L_8c67:
        lea      edx, [ecx + ecx*2]
        mov      ecx, dword ptr [g_baseSel]
        movsx    eax, byte ptr [edx*8 + g_byte_005435a0]
        mov      edx, dword ptr [g_counter_005433c8]
        mov      dword ptr [g_walkCallback], eax
        add      edx, ecx
        mov      eax, dword ptr [edx*4 + 0x48]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      ScaledChainStore24
    L_8c96:
        ret
    }
}
