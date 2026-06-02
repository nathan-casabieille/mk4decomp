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

extern void SkelAnimUpdaterCluster_0049d940(void);
extern unsigned int g_dispatchSave544_004d6948;
extern unsigned int g_audioPreloadBase2_0050bbb4;

extern void CallSetPause(void);
extern void MStackCall_004062f0(void);
extern void MStackCall_00406740(void);
extern void MStackPushDispatchBitGate(void);
extern void ScaledChainOr8(void);
extern void SetJmp_00405420(void);
extern void ZeroThreeFields_0040a8b0(void);

__declspec(naked) void Phase4DualHelperTrampoline_00412900(void)
{
    __asm {
        push    0x8A
        push    0x00412920
        call    StoreTwoCall
        add     esp, 8
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
    L_p4dht_A:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4dht_A_phase0
        dec     eax
        je      L_p4dht_A_phase1
        call    SetJmp_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_A_exit
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4dht_A_install_p2
        push    0x8A
        push    0x00412AD0
        call    StoreTwoCall
        add     esp, 8
        call    CallSetPause
        pop     esi
        ret
    L_p4dht_A_phase1:
        push    0x8A
        push    0x00412AD0
        call    StoreTwoCall
        mov     dword ptr [esi + 8], 0x00412920
        mov     dword ptr [esi + 0x84], 2
        add     esp, 8
        mov     dword ptr [g_pendingNodeType], 0x0C
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p4dht_A_phase0:
        call    MStackPush2RunCountdown
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_A_exit
        call    MStackBracket7_DispatchAndChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_A_exit
        mov     dword ptr [g_walkCallback], 0x0A
        call    ChainDirtyBitWalker
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_A_exit
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4dht_A_continue
    L_p4dht_A_install_p2:
        call    CallSetPause
        pop     esi
        ret
    L_p4dht_A_continue:
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_xformEntityIdx]
        lea     eax, [edx*4]
        mov     edx, dword ptr [ecx*4 + 0x3C]
        mov     dword ptr [g_xformScratch2088], edx
        mov     ecx, dword ptr [ecx*4 + 0x44]
        mov     dword ptr [g_currentNodeFlags], ecx
        mov     dword ptr [eax + 0x38], edx
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     ecx, 0xFFFFE667
        mov     dword ptr [eax + 0x40], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x3C], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_currentNodeIdx], eax
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_A_exit
        mov     ecx, offset g_dispatchSave544_004d6948
        mov     dword ptr [g_eventQueueNotMask], 0x99
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    SkelAnimUpdaterCluster_0049d940
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_A_exit
        push    0x8A
        push    0x00412AD0
        call    StoreTwoCall
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412920
        mov     dword ptr [esi + 0x84], eax
        add     esp, 8
        mov     dword ptr [g_pendingNodeType], 0x0C
        mov     dword ptr [g_framePauseFlag], eax
    L_p4dht_A_exit:
        pop     esi
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
        nop
        nop
    L_p4dht_B:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4dht_B_phase0
        dec     eax
        mov     eax, dword ptr [g_eventQueueEnd]
        je      L_p4dht_B_alt
        mov     edx, dword ptr [eax*4 + 0x48]
        add     edx, 0xCCC
        mov     dword ptr [eax*4 + 0x48], edx
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_walkCallback], edx
        mov     ecx, dword ptr [eax*4 + 0x58]
        add     ecx, 0x7AE
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4dht_B_install
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_p4dht_B_call_0041f830
        pop     esi
        ret
    L_p4dht_B_alt:
        mov     ecx, dword ptr [eax*4 + 0x48]
        add     ecx, 0xCCC
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x48]
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4dht_B_after_06740
        mov     dword ptr [g_eventQueueIdx], 7
    L_p4dht_B_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412AD0
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p4dht_B_phase0:
        mov     ecx, offset g_audioPreloadBase2_0050bbb4
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPushDispatchBitGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_B_exit
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4dht_B_continue
    L_p4dht_B_call_0041f830:
        call    CallSetPause
        pop     esi
        ret
    L_p4dht_B_continue:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [edx*4 + 0x30], 0x97
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_xformScratch2088]
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_currentNodeFlags]
        mov     dword ptr [edx*4 + 0x5C], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0xFFFFF334
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        call    ScaledChainOr8
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x28F
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x48], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_eventQueueEnd], eax
        call    MStackCall_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4dht_B_exit
        mov     dword ptr [g_eventQueueIdx], 0x0F
    L_p4dht_B_after_06740:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412AD0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4dht_B_exit:
        pop     esi
        ret
    }
}
