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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

/* @addr 0x004101f0 (329b boot) - bundled boot installer pair.
 *   sub-1 (~20b @ 0x4101f0): pushes 0x88 and callback ptr (sub-2 @ 0x00410210),
 *     calls StoreTwoCall to register the callback.
 *   sub-2 (~309b @ 0x00410210): boot countdown state machine.
 *     If [esi+0x84] non-zero (already installed): decrement g_eventQueueEnd
 *     countdown, jns to chain-walk, else call GuardedSeq_00471670.
 *     Else: setup pipeline with DispatcherComplex260_00407400, MStackCall_00406340,
 *     install self at [esi+8] = 0x00410210, set state flags.
 */
extern void BossRoomInitCluster_00410340(void);
extern void GuardedSeq_00471670(void);
extern void MStackCall_00406340(void);
extern void CallSetPause(void);

__declspec(naked) void BootInstallerPair_004101f0(void) {
    __asm {
        /* sub-1: trampoline */
        push    0x88
        push    offset L_bip_callback
        call    StoreTwoCall
        add     esp, 8
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        /* sub-2: callback */
    L_bip_callback:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        jz      short L_bip_init
        mov     eax, dword ptr [g_eventQueueEnd]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], eax
        jns     L_bip_resume
        call    GuardedSeq_00471670
        pop     esi
        ret
    L_bip_init:
        mov     ecx, 0x004d57f8
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DispatcherComplex260_00407400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_bip_done
        test    byte ptr [g_xformDirtyFlags], 4
        jz      short L_bip_doMain
        call    CallSetPause
        pop     esi
        ret
    L_bip_doMain:
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_fightGroupHead], eax
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ecx, 2
        mov     dword ptr [eax*4 + 0x34], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x00100000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x5c], eax
        call    MStackCall_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_bip_done
        mov     eax, 0x004d57c8
        mov     dword ptr [g_walkCallback], 0x00ffffff
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], 0x00ffffff
        mov     eax, 0x004d6e20
        shr     eax, 2
        mov     dword ptr [g_eventQueueEnd], 6
        mov     dword ptr [g_eventQueueIdx], eax
        jmp     short L_bip_loadIdx
    L_bip_resume:
        mov     eax, dword ptr [g_eventQueueIdx]
    L_bip_loadIdx:
        mov     ecx, [eax*4]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueIdx], eax
        call    BossRoomInitCluster_00410340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bip_done
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_bip_callback
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_bip_done:
        pop     esi
        ret
    }
}
