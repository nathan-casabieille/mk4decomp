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

extern void AudioMode2BankSetup(void);
extern unsigned char g_byte_00543840;
extern unsigned char g_byte_0054383c;
extern unsigned char g_byte_005435a0;
extern unsigned char g_byte_005435b8;
extern unsigned int g_audioModeBankFlag;
extern unsigned int g_audioPathFlag;
extern unsigned int g_table_00543848;

/*
 * AudioByteCounterChain - 204b audio counter+state machine.
 *   chain = g_baseSel<<2; saved = chain->state; chain->state = 0.
 *   If was 0: dispatch on g_audioBankSel == 1/2 to increment indexed slots in g_table_00543848;
 *     call BootInitGuardedCallChain; if paused: ret.
 *     Call FiveTableWalkInit; if paused: ret.
 *     Inc g_byte_00543840; g_audioPathFlag=1; g_audioModeBankFlag=1;
 *     if hit 0xf: inc g_byte_0054383c; if also equal to (post-inc) al: zero it.
 *     Stash to g_byte_005435a0; push (&g_byte_005435b8, &g_byte_005435a0);
 *     g_byte_005435b8 = g_byte_0054383c; zero g_byte_005435a3 / g_byte_005435bb;
 *     call AudioMode2BankSetup; call TwoStageAudioInit.
 */
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern void BootInitGuardedCallChain(void);
extern void FiveTableWalkInit(void);
extern void TwoStageAudioInit(void);

__declspec(naked) void AudioByteCounterChain(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        xor     ebx, ebx
        mov     ecx, dword ptr [eax*4 + 0x84]
        mov     dword ptr [eax*4 + 0x84], ebx
        cmp     ecx, ebx
        jne     short L_skipInit
        mov     eax, dword ptr [g_audioBankSel]
        cmp     eax, 1
        jne     short L_check2
        mov     ecx, dword ptr [g_dlNalt1]
        inc     dword ptr [ecx*4 + g_table_00543848]
    L_check2:
        cmp     eax, 2
        jne     short L_skipInit
        mov     eax, dword ptr [g_dlNalt2]
        inc     dword ptr [eax*4 + g_table_00543848]
    L_skipInit:
        call    BootInitGuardedCallChain
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_end
        call    FiveTableWalkInit
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_end
        mov     al, byte ptr [g_byte_00543840]
        mov     dword ptr [g_audioPathFlag], 1
        inc     al
        mov     dword ptr [g_audioModeBankFlag], 1
        cmp     al, 0xf
        mov     byte ptr [g_byte_00543840], al
        jne     short L_finalize
        mov     cl, byte ptr [g_byte_0054383c]
        inc     cl
        cmp     cl, al
        mov     byte ptr [g_byte_0054383c], cl
        jne     short L_finalize
        mov     byte ptr [g_byte_0054383c], bl
    L_finalize:
        mov     byte ptr [g_byte_005435a0], al
        mov     al, byte ptr [g_byte_0054383c]
        push    offset g_byte_005435b8
        push    offset g_byte_005435a0
        mov     byte ptr [g_byte_005435b8], al
        mov     byte ptr [g_byte_005435a0 + 3], bl
        mov     byte ptr [g_byte_005435b8 + 3], bl
        call    AudioMode2BankSetup
        add     esp, 8
        call    TwoStageAudioInit
    L_end:
        pop     ebx
        ret
    }
}
