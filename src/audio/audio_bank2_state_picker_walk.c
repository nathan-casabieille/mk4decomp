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

/*
 * AudioBank2StatePickerWalk_004a9270 - 324b audio 2-bank state picker and roundrobin walk.
 *   g_walkCallback=0; CopyGlobal; IncOrZero9_00422080.
 *   eax = g_audioBankSel; edx = g_counter_0054359c; edi = g_counter_005433c8.
 *   If eax == 1: chain low table [edi*24 + 0x0054361a/19] += 1.
 *   Else: chain high table [edx*24 + 0x005435a2/a1] += 1.
 *   ++g_bootInitState_00535de4. esi=1. ecx=g_audioStateMachine0_004f3ae4; walk g_byte_005435a2[i*24] for i in [0,ecx);
 *     if any !=0: keep esi=1; else esi=0. If esi: g_audioBankPick_005433c0=2; tail to cleanup.
 *   Else: ebp=g_audioStateMachine1_004f3ae8; esi=1. Walk g_byte_0054361a[i*24] for i in [0,ebp). If esi: g_audioBankPick_005433c0=1;
 *     cleanup: zero g_counter_0054359c, g_counter_005433c8; call Match_TeamOutcomeScreen; pop+ret.
 *   Else (both banks have something nonzero): eax = g_audioBankSel again.
 *     If eax==2: roundrobin edx through ecx slots looking for g_byte_005435a2[edx*24]!=0; store to g_counter_0054359c.
 *     If eax==1: roundrobin edi through ebp slots looking for g_byte_0054361a[edi*24]!=0; store to g_counter_005433c8.
 *     call Match_TeamOutcomeScreen; pop+ret.
 */
extern unsigned int g_byte_005435a1;
extern unsigned int g_byte_005435a2;
extern unsigned int g_byte_00543619;
extern unsigned int g_byte_0054361a;
extern unsigned int g_bootInitState_00535de4;
extern unsigned int g_audioBankPick_005433c0;
extern unsigned int g_counter_0054359c;
extern unsigned int g_audioStateMachine0_004f3ae4;
extern unsigned int g_audioStateMachine1_004f3ae8;
extern unsigned int g_counter_005433c8;
extern void CopyGlobal(void);
extern void Match_TeamOutcomeScreen(void);
extern void IncOrZero9_00422080(void);

__declspec(naked) void AudioBank2StatePickerWalk_004a9270(void)
{
    __asm
    {
        push    ebp
        push    esi
        push    edi
        mov     dword ptr [g_walkCallback], 0
        call    CopyGlobal
        call    IncOrZero9_00422080
        mov     eax, dword ptr [g_audioBankSel]
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
        mov     ecx, dword ptr [g_audioStateMachine0_004f3ae4]
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
        mov     dword ptr [g_audioBankPick_005433c0], 2
        jmp     short L_a92_cleanup
    L_a92_lowBankCheck:
        mov     ebp, dword ptr [g_audioStateMachine1_004f3ae8]
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
        mov     dword ptr [g_audioBankPick_005433c0], 1
    L_a92_cleanup:
        mov     dword ptr [g_counter_0054359c], 0
        mov     dword ptr [g_counter_005433c8], 0
        call    Match_TeamOutcomeScreen
        pop     edi
        pop     esi
        pop     ebp
        ret
    L_a92_walkPicks:
        mov     eax, dword ptr [g_audioBankSel]
        cmp     eax, 2
        jne     short L_a92_checkLowPick
    L_a92_rrHigh:
        mov     ecx, dword ptr [g_audioStateMachine0_004f3ae4]
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
        call    Match_TeamOutcomeScreen
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}
