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

extern unsigned int g_word_004e2860;
extern unsigned int g_poseGridGenVar_004e2864;
extern unsigned int g_dispatchArg;
extern unsigned int g_audioInitPeriodic_00537e90;
extern unsigned int g_audioInstall2State_00537f88;
extern unsigned int g_state2_0053a1bc;
extern unsigned int g_audioBitField_00541fc0;
extern u32 g_dlMode;
extern void DualPushSetCallDualPop(void);
extern void RoundWinTransition(void);
extern void SetOnePairJmp_004a0110(void);
extern void TripleStageRollback(void);
extern void TripleTestInstallJmp_004a0130(void);

__declspec(naked) void AudioMStackPushHandlerPair(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueEnd]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_dispatchArg]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     ecx, dword ptr [g_audioBitField_00541fc0]
        mov     eax, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [g_xformEntityIdx], ecx
        add     ecx, eax
        mov     dword ptr [g_dispatchArg], eax
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     ecx, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     ecx, dword ptr [ecx*4]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        jne     short L_amspp_skipPush
        test    eax, eax
        jne     short L_amspp_else
        push    0x22f
        call    TripleStageRollback
        mov     dx, word ptr [g_word_004e2860]
        add     esp, 4
        push    edx
        jmp     short L_amspp_callBe690
    L_amspp_else:
        push    0x230
        call    TripleStageRollback
        mov     ax, word ptr [g_poseGridGenVar_004e2864]
        add     esp, 4
        push    eax
    L_amspp_callBe690:
        call    TaggedSceneDispatch
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_walkCallback], 1
        add     esp, 4
        mov     dword ptr [ecx*4], 1
    L_amspp_skipPush:
        call    RoundWinTransition
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_amspp_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_dispatchArg], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_amspp_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
    L_amspp_sub2:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        jne     short L_amspp_sub2_check
        mov     ecx, dword ptr [g_audioInstall2State_00537f88]
        push    0x239
        mov     dword ptr [g_eventQueueEnd], ecx
        call    DualPushSetCallDualPop
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        add     esp, 4
        test    cl, al
        je      short L_amspp_sub2_check
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_audioInitPeriodic_00537e90]
        cmp     edx, ecx
        je      short L_amspp_sub2_install
    L_amspp_sub2_check:
        mov     eax, dword ptr [g_dlMode]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     short L_amspp_sub2_check2
        call    SetOnePairJmp_004a0110
        pop     esi
        ret
    L_amspp_sub2_check2:
        mov     eax, dword ptr [g_state2_0053a1bc]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     short L_amspp_sub2_callPair
        call    TripleTestInstallJmp_004a0130
        pop     esi
        ret
    L_amspp_sub2_callPair:
        call    SetOnePairJmp_004a0110
        pop     esi
        ret
    L_amspp_sub2_install:
        mov     dword ptr [esi + 8], offset L_amspp_sub2
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
