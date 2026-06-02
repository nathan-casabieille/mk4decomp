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

extern unsigned int g_audioStateMachine0_004f3ae4;
extern unsigned int g_audioStateMachine1_004f3ae8;
extern unsigned int g_audioCrewState_00541d8c;
extern unsigned int g_byte_005435a2;
extern unsigned int g_byte_0054361a;
extern unsigned int g_dispatchSave1701_00600000;
extern unsigned int g_glideFnTable;
extern unsigned int g_dispatchSave1710_00c00000;
extern void AudioChainInit(void);
extern void AudioInitLoopTriple(void);
extern void ScaledChainStore24(void);

__declspec(naked) void SpawnLeftRightAudioCrew(void)
{
    __asm {
        mov      eax, dword ptr [g_audioStateMachine0_004f3ae4]
        push     ebx
        push     ebp
        push     esi
        lea      ecx, [eax + eax*2]
        push     edi
        shl      ecx, 0x15
        sub      ecx, OFFSET g_dispatchSave1701_00600000
        xor      edi, edi
        test     eax, eax
        mov      dword ptr [g_audioCrewState_00541d8c], ecx
        jle      L_8183
        xor      ebp, ebp
        mov      esi, OFFSET g_byte_005435a2
        mov      ebx, 0xfde40000
    L_80b1:
        mov      dword ptr [g_walkCallback], 0x10
        call     AudioChainInit
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        lea      eax, [edi + edx]
        mov      edx, ebp
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      eax, dword ptr [g_audioCrewState_00541d8c]
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        shl      edx, 2
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], ebx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x64], 0
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x5c], 0xc0000
        movsx    ecx, byte ptr [esi - 2]
        mov      dword ptr [g_walkCallback], ecx
        call     ScaledChainStore24
        cmp      byte ptr [esi], 0
        je       short L_816c
        call     AudioInitLoopTriple
        mov      eax, dword ptr [g_audioCrewState_00541d8c]
        mov      edx, ebp
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], 0xff890000
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x5c], 0x30000
    L_816c:
        mov      eax, dword ptr [g_audioStateMachine0_004f3ae4]
        inc      edi
        add      esi, 0x18
        add      ebp, OFFSET g_dispatchSave1710_00c00000
        cmp      edi, eax
        jl       L_80b1
    L_8183:
        mov      eax, dword ptr [g_audioStateMachine1_004f3ae8]
        xor      edi, edi
        lea      ecx, [eax + eax*2]
        shl      ecx, 0x15
        sub      ecx, OFFSET g_dispatchSave1701_00600000
        test     eax, eax
        mov      dword ptr [g_audioCrewState_00541d8c], ecx
        jle      short L_8282
        xor      ebp, ebp
        mov      esi, OFFSET g_byte_0054361a
        mov      ebx, 0x12c0000
    L_81b0:
        mov      dword ptr [g_walkCallback], 0x10
        call     AudioChainInit
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        lea      eax, [edi + edx]
        mov      edx, ebp
        mov      dword ptr [eax*4 + 0x48], ecx
        mov      eax, dword ptr [g_audioCrewState_00541d8c]
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        shl      edx, 2
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], ebx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x64], 0
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x5c], 0xc0000
        movsx    ecx, byte ptr [esi - 2]
        mov      dword ptr [g_walkCallback], ecx
        call     ScaledChainStore24
        cmp      byte ptr [esi], 0
        je       short L_826b
        call     AudioInitLoopTriple
        mov      eax, dword ptr [g_audioCrewState_00541d8c]
        mov      edx, ebp
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], OFFSET g_glideFnTable
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x5c], 0x30000
    L_826b:
        mov      eax, dword ptr [g_audioStateMachine1_004f3ae8]
        inc      edi
        add      esi, 0x18
        add      ebp, OFFSET g_dispatchSave1710_00c00000
        cmp      edi, eax
        jl       L_81b0
    L_8282:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
