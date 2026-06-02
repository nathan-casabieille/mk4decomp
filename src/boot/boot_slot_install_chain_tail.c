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

extern void BootSlotInstallChainTail(void);

/*
 * BootInstallPeriodicTriple - 223b boot 2-body periodic with triple call.
 *   Entry 0x00414920: push (0xb0, &body); StoreTwoCall; chain[+0x34] = g_baseSel; ret.
 *   Body 0x00414950: chain = g_baseSel<<2; saved = chain->state; chain->state=0.
 *     If was nonzero: eax = chain[+0x34]; g_currentNodeIdx = eax; eax = eax->field_74; if 0x1001:
 *       just snapshot g_fightGroupHead to g_eventQueueEnd. Else: push 0x1392; TableHitOrSchedule;
 *       CallSetPause; pop+ret.
 *     Common: call BootSlotInstallChainTail three times with pause-checks between. If completed unpaused:
 *       install-self at body; chain->state=1; g_pendingNodeType=1; g_framePauseFlag=1.
 *     Pop+ret.
 */
extern void CallSetPause(void);
extern void TableHitOrSchedule(void);

__declspec(naked) void BootInstallPeriodicTriple(void)
{
    __asm
    {
        push    0xb0
        push    offset L_body2
        call    StoreTwoCall
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_baseSel]
        add     esp, 8
        mov     dword ptr [eax*4 + 0x34], ecx
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
    L_body2:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_branchB
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x74]
        cmp     eax, 0x1001
        mov     dword ptr [g_walkCallback], eax
        je      short L_callTrip
        push    0x1392
        call    TableHitOrSchedule
        add     esp, 4
        call    CallSetPause
        pop     esi
        ret
    L_branchB:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_eventQueueEnd], edx
    L_callTrip:
        call    BootSlotInstallChainTail
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b2_ret
        call    BootSlotInstallChainTail
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b2_ret
        call    BootSlotInstallChainTail
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_b2_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_body2
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_b2_ret:
        pop     esi
        ret
    }
}
