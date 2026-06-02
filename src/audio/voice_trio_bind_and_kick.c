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

extern unsigned int g_audioStateMachineVar4_004f3220;
extern unsigned int g_dispatchSave503_004f3a30;
extern unsigned int g_audioStateMachineVar_004f3a38;
extern unsigned int g_audioVoiceTrioBase_0050a0f0;
extern unsigned int g_voiceTrioBaseB_0050c618;
extern void GuardedSetupCallTailJmp3_004a2000(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void ScaledOr4DirtyClear(void);

__declspec(naked) void VoiceTrioBindAndKick_004a5ea0(void)
{
    __asm {
        push     ebx
        push     ebp
        mov      eax, OFFSET g_audioVoiceTrioBase_0050a0f0
        push     esi
        mov      esi, dword ptr [esp + 0x10]
        mov      bl, 1
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      cl, byte ptr [esi + 2]
        cmp      cl, bl
        push     edi
        jne      short L_5ee7
        movsx    ecx, byte ptr [esi]
        add      ecx, eax
        mov      eax, dword ptr [ecx*4]
        and      eax, 0xffffff
        mov      dword ptr [g_xformEntityIdx], eax
        mov      edx, dword ptr [eax]
        sar      edx, 2
        and      edx, 0x3fffff
        mov      dword ptr [g_xformEntityIdx], edx
        jmp      short L_5ef4
    L_5ee7:
        mov      eax, OFFSET g_voiceTrioBaseB_0050c618
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
    L_5ef4:
        call     DispatcherComplex260_00407400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_607a
        call     MStackPushComplexCallPop_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_607a
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ecx, dword ptr [esp + 0x20]
        mov      edx, dword ptr [esp + 0x1c]
        mov      ebp, dword ptr [esp + 0x18]
        test     al, 4
        jne      short L_5f80
        mov      al, byte ptr [esi + 2]
        test     al, al
        jne      short L_5f44
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x64], 0x3243f
    L_5f44:
        mov      edi, dword ptr [g_currentNodeIdx]
        lea      eax, [ebp*4]
        mov      dword ptr [edi*4 + 0x54], eax
        mov      edi, dword ptr [g_currentNodeIdx]
        lea      eax, [edx*4]
        mov      dword ptr [edi*4 + 0x58], eax
        mov      edi, dword ptr [g_currentNodeIdx]
        lea      eax, [ecx*4 + 0xc0000]
        mov      dword ptr [edi*4 + 0x5c], eax
    L_5f80:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [esi + 8], eax
        mov      al, byte ptr [esi + 2]
        cmp      al, bl
        jne      L_607a
        mov      eax, 0x55555556
        imul     edx
        mov      eax, edx
        shr      eax, 0x1f
        add      edx, eax
        mov      eax, 0x55555556
        mov      edi, edx
        imul     ebp
        mov      eax, edx
        shr      eax, 0x1f
        lea      ebx, [edx + eax + 0x300000]
        mov      eax, 0x55555556
        imul     ecx
        mov      ecx, edx
        shr      ecx, 0x1f
        add      edx, ecx
        lea      ecx, [edi - 0xa0000]
        mov      ebp, edx
        push     ecx
        movsx    edx, byte ptr [esi + 1]
        push     ebx
        mov      eax, dword ptr [edx*4 + g_audioStateMachineVar_004f3a38]
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp3_004a2000
        mov      edx, dword ptr [g_currentNodeIdx]
        add      ebp, 0x10000
        add      esp, 0xc
        mov      dword ptr [edx*4 + 0x5c], ebp
        mov      eax, dword ptr [g_currentNodeIdx]
        movsx    ecx, byte ptr [esi + 3]
        lea      edx, [edi + 0xa0000]
        mov      dword ptr [esi + 0xc], eax
        mov      eax, dword ptr [ecx*4 + g_dispatchSave503_004f3a30]
        push     edx
        push     ebx
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp3_004a2000
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 0xc
        add      edi, 0x1e0000
        mov      dword ptr [eax*4 + 0x5c], ebp
        mov      ecx, dword ptr [g_currentNodeIdx]
        movsx    edx, byte ptr [esi + 4]
        mov      dword ptr [esi + 0x10], ecx
        push     edi
        mov      eax, dword ptr [edx*4 + g_audioStateMachineVar4_004f3220]
        push     ebx
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp3_004a2000
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 0xc
        mov      dword ptr [eax*4 + 0x5c], ebp
        mov      al, byte ptr [esi + 3]
        mov      ecx, dword ptr [g_currentNodeIdx]
        test     al, al
        mov      dword ptr [esi + 0x14], ecx
        je       short L_607a
        call     ScaledOr4DirtyClear
    L_607a:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
