/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/*
 * AudioBank2StatePickerWalk_004a9270 - 324b audio 2-bank state picker and roundrobin walk.
 *   g_walkCallback=0; CopyGlobal_004ac1f0; func_004a2080.
 *   eax = g_audioBankSel_00537f94; edx = g_counter_0054359c; edi = g_counter_005433c8.
 *   If eax == 1: chain low table [edi*24 + 0x0054361a/19] += 1.
 *   Else: chain high table [edx*24 + 0x005435a2/a1] += 1.
 *   ++g_bootInitState_00535de4. esi=1. ecx=g_x_004f3ae4; walk g_byte_005435a2[i*24] for i in [0,ecx);
 *     if any !=0: keep esi=1; else esi=0. If esi: g_data_005433c0=2; tail to cleanup.
 *   Else: ebp=g_x_004f3ae8; esi=1. Walk g_byte_0054361a[i*24] for i in [0,ebp). If esi: g_data_005433c0=1;
 *     cleanup: zero g_counter_0054359c, g_counter_005433c8; call PendingMatch_004a93c0; pop+ret.
 *   Else (both banks have something nonzero): eax = g_audioBankSel_00537f94 again.
 *     If eax==2: roundrobin edx through ecx slots looking for g_byte_005435a2[edx*24]!=0; store to g_counter_0054359c.
 *     If eax==1: roundrobin edi through ebp slots looking for g_byte_0054361a[edi*24]!=0; store to g_counter_005433c8.
 *     call PendingMatch_004a93c0; pop+ret.
 */
extern unsigned int g_byte_005435a1;
extern unsigned int g_byte_005435a2;
extern unsigned int g_byte_00543619;
extern unsigned int g_byte_0054361a;
extern unsigned int g_bootInitState_00535de4;
extern unsigned int g_data_005433c0;
extern unsigned int g_counter_0054359c;
extern unsigned int g_x_004f3ae4;
extern unsigned int g_x_004f3ae8;
extern unsigned int g_counter_005433c8;
extern void CopyGlobal_004ac1f0(void);
extern void PendingMatch_004a93c0(void);
extern void func_004a2080(void);

__declspec(naked) void AudioBank2StatePickerWalk_004a9270(void)
{
    __asm
    {
        push    ebp
        push    esi
        push    edi
        mov     dword ptr [g_walkCallback], 0
        call    CopyGlobal_004ac1f0
        call    func_004a2080
        mov     eax, dword ptr [g_audioBankSel_00537f94]
        mov     edx, dword ptr [g_counter_0054359c]
        mov     edi, dword ptr [g_counter_005433c8]
        cmp     eax, 1
        jne     short L_a92_highBank
        lea     eax, [edi + edi*2]
        shl     eax, 3
        mov     byte ptr [eax + g_byte_0054361a], 1
        mov     cl, byte ptr [eax + g_byte_00543619]
        inc     cl
        mov     byte ptr [eax + g_byte_00543619], cl
        jmp     short L_a92_afterStore
    L_a92_highBank:
        lea     eax, [edx + edx*2]
        shl     eax, 3
        mov     byte ptr [eax + g_byte_005435a2], 1
        mov     cl, byte ptr [eax + g_byte_005435a1]
        inc     cl
        mov     byte ptr [eax + g_byte_005435a1], cl
    L_a92_afterStore:
        mov     ecx, dword ptr [g_bootInitState_00535de4]
        mov     esi, 1
        inc     ecx
        mov     dword ptr [g_bootInitState_00535de4], ecx
        mov     ecx, dword ptr [g_x_004f3ae4]
        test    ecx, ecx
        jle     short L_a92_checkLow
        mov     eax, offset g_byte_005435a2
    L_a92_walkHigh:
        cmp     byte ptr [eax], 0
        jne     short L_a92_walkHighCont
        xor     esi, esi
    L_a92_walkHighCont:
        add     eax, 0x18
        dec     ecx
        jne     short L_a92_walkHigh
    L_a92_checkLow:
        test    esi, esi
        je      short L_a92_lowBankCheck
        mov     dword ptr [g_data_005433c0], 2
        jmp     short L_a92_cleanup
    L_a92_lowBankCheck:
        mov     ebp, dword ptr [g_x_004f3ae8]
        mov     esi, 1
        test    ebp, ebp
        jle     short L_a92_decideSet
        mov     eax, offset g_byte_0054361a
        mov     ecx, ebp
    L_a92_walkLow:
        cmp     byte ptr [eax], 0
        jne     short L_a92_walkLowCont
        xor     esi, esi
    L_a92_walkLowCont:
        add     eax, 0x18
        dec     ecx
        jne     short L_a92_walkLow
    L_a92_decideSet:
        test    esi, esi
        je      short L_a92_walkPicks
        mov     dword ptr [g_data_005433c0], 1
    L_a92_cleanup:
        mov     dword ptr [g_counter_0054359c], 0
        mov     dword ptr [g_counter_005433c8], 0
        call    PendingMatch_004a93c0
        pop     edi
        pop     esi
        pop     ebp
        ret
    L_a92_walkPicks:
        mov     eax, dword ptr [g_audioBankSel_00537f94]
        cmp     eax, 2
        jne     short L_a92_checkLowPick
    L_a92_rrHigh:
        mov     ecx, dword ptr [g_x_004f3ae4]
        inc     edx
        cmp     edx, ecx
        jne     short L_a92_rrHighSkip
        xor     edx, edx
    L_a92_rrHighSkip:
        lea     ecx, [edx + edx*2]
        cmp     byte ptr [ecx*8 + g_byte_005435a2], 0
        jne     short L_a92_rrHigh
        mov     dword ptr [g_counter_0054359c], edx
    L_a92_checkLowPick:
        cmp     eax, 1
        jne     short L_a92_callEnd
    L_a92_rrLow:
        inc     edi
        cmp     edi, ebp
        jne     short L_a92_rrLowSkip
        xor     edi, edi
    L_a92_rrLowSkip:
        lea     edx, [edi + edi*2]
        mov     al, byte ptr [edx*8 + g_byte_0054361a]
        test    al, al
        jne     short L_a92_rrLow
        mov     dword ptr [g_counter_005433c8], edi
    L_a92_callEnd:
        call    PendingMatch_004a93c0
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}
