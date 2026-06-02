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
extern void CopyJmp_0048ef90(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
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

extern unsigned int g_dispatchSave804_004f308c;
extern unsigned int g_dispatchSave578_004f3094;
extern unsigned int g_dispatchSave806_004f313c;
extern unsigned int g_dispatchSave808_004f31a4;
extern unsigned int g_dispatchSave809_004f31ac;
extern unsigned int g_dispatchSave723_004f62f8;
extern unsigned int g_dispatchSave120_00515964;
extern unsigned int g_dispatchSave1332_00f00000;
extern void AudioBindEntry(void);
extern void AudioInitArgs3(void);
extern void GuardedSetupCallTailJmp(void);

__declspec(naked) void VoiceMixerTickDispatch(void)
{
    __asm {
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      esi, OFFSET g_dispatchSave578_004f3094
    L_27c9:
        cmp      esi, OFFSET g_dispatchSave806_004f313c
        jae      L_27ed
        mov      eax, dword ptr [esi]
        push     0x10000
        sub      eax, 0x50000
        push     eax
        push     0
        push     OFFSET g_dispatchSave120_00515964
        call     AudioInitArgs3
        add      esp, 0x10
    L_27ed:
        add      esi, 0x1c
        cmp      esi, OFFSET g_dispatchSave809_004f31ac
        jb       L_27c9
        push     OFFSET g_dispatchSave723_004f62f8
        call     AudioBindEntry
        add      esp, 4
        xor      edi, edi
        mov      esi, OFFSET g_dispatchSave804_004f308c
        mov      ebp, 0xff100000
        mov      ebx, OFFSET g_dispatchSave1332_00f00000
    L_2816:
        mov      eax, dword ptr [esi + 8]
        mov      ecx, dword ptr [esi]
        push     eax
        push     ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        call     GuardedSetupCallTailJmp
        lea      eax, [edi - 6]
        add      esp, 8
        cmp      eax, 3
        ja       L_2864
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_283f:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x54]
        add      ecx, ebp
        jmp      L_285d
    L_284f:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x54]
        add      ecx, ebx
    L_285d:
        mov      dword ptr [eax*4 + 0x54], ecx
    L_2864:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [esi + 0xc]
        add      esi, 0x1c
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [esi - 0x18], ecx
        movsx    ecx, byte ptr [esi - 0x20]
        mov      dword ptr [g_eventQueueCurrent], ecx
        add      ecx, edx
        inc      edi
        cmp      esi, OFFSET g_dispatchSave808_004f31a4
        mov      dword ptr [ecx*4], eax
        jb       L_2816
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
        /* 3-byte lea ecx, [ecx+0] alignment nop (MASM picks 2-byte form; force 3-byte via _emit) */
        _emit 0x8d
        _emit 0x49
        _emit 0x00
    L_jmptbl:
        /* 4 dwords (2 unique targets, each twice) */
        _emit 0x3f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
        _emit 0x3f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
        _emit 0x4f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
        _emit 0x4f
        _emit 0x28
        _emit 0x4a
        _emit 0x00
    }
}
