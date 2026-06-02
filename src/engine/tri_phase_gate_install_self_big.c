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

extern void GuardedSeq_00433bb0(void);
extern void PrefixThunkInstallSelf3State(void);
extern void JumpTableDispatch_0043a550(void);
extern void MStackPushPtr1Jmp_00438e70(void);
extern void EsiInstallTwoCallCmpInstall_00438b10(void);
extern void QuadBlockArgInstallChain(void);
extern void Cmp2CallDirtyCall(void);
extern void TriPhaseGateInstallSelfBig_00437140(void);
extern void EntryThenDispatcherPair_00438cd0(void);
extern void ProneFsmCluster_004355f0(void);
extern void InstallSelfBitGate_00438aa0(void);

__declspec(naked) void TriEntryGateMain_00435440(void)
{
    __asm
    {
        mov     eax, dword ptr [g_table_00535ddc]
        cmp     eax, 0x20000
        mov     dword ptr [g_walkCallback], eax
        jle     short L_tegm_jmp2
        jmp     GuardedSeq_00433bb0
    L_tegm_jmp2:
        jmp     PrefixThunkInstallSelf3State
        nop
        nop
        nop
        nop
        nop
    L_tegm_sub2:
        mov     edx, dword ptr [g_walkCallback]
        push    0x4e4600
        and     edx, 0xff
        mov     dword ptr [g_walkCallback], edx
        call    JumpTableDispatch_0043a550
        add     esp, 4
        ret
    L_tegm_main:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      short L_tegm_phase0
        dec     eax
        je      short L_tegm_phase1
        call    MStackPushPtr1Jmp_00438e70
        pop     esi
        ret
    L_tegm_phase1:
        mov     dword ptr [g_currentNodeFlags], 0x70000
        mov     dword ptr [esi + 8], offset L_tegm_main
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset L_tegm_main
        add     edx, 0x2000000
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    EsiInstallTwoCallCmpInstall_00438b10
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_tegm_phase0:
        push    0x4e4a08
        call    QuadBlockArgInstallChain
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     L_tegm_ret
        call    Cmp2CallDirtyCall
        test    eax, eax
        jne     L_tegm_ret
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x74]
        cmp     eax, 0x200e
        mov     dword ptr [g_walkCallback], eax
        jne     short L_tegm_cmp2
        call    TriPhaseGateInstallSelfBig_00437140
        pop     esi
        ret
    L_tegm_cmp2:
        mov     eax, dword ptr [g_table_00535ddc]
        cmp     eax, 0x20000
        mov     dword ptr [g_walkCallback], eax
        jge     short L_tegm_cmp3
        call    EntryThenDispatcherPair_00438cd0
        pop     esi
        ret
    L_tegm_cmp3:
        cmp     eax, 0x40000
        jge     short L_tegm_install0
        call    ProneFsmCluster_004355f0
        pop     esi
        ret
    L_tegm_install0:
        mov     dword ptr [esi + 8], offset L_tegm_main
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset L_tegm_main
        mov     dword ptr [edx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x1000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    InstallSelfBitGate_00438aa0
        mov     dword ptr [g_framePauseFlag], 1
    L_tegm_ret:
        pop     esi
        ret
    }
}
