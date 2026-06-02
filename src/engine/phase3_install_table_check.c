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

/* @addr 0x0048acd0 (384b game) - phase-state install-self with table check.
 *   Phase 0: indirect-call [g_eventQueueChild]; on no-error copies the
 *     3-vec at [g_fightGroupHead*4+0x54/0x58/0x5c] into [g_eventQueueTotal*4
 *     + 0/4/8], then IndirectDispatchCjStore, installs Self
 *     at body with slot[+0x84]=1, g_pendingNodeType=1, arms 0x541e6c.
 *   Phase non-0: if byte g_byte_00538148 != 0, checks the scaled
 *     g_eventQueueIdx ptr against the 4 sentinel addresses
 *     {0x4efe18, 0x4eff00, 0x4effe8, 0x4f00d0}; on match tail-call
 *     CallSetPause. Otherwise byte g_byte_00538148 = 0, then
 *     indirect-call [g_eventQueueChild] (vtable advance), call
 *     MStackPush6OpPop6. Reads g_currentNodeFlags cap;
 *     [g_eventQueueIdx*4] + 0x30000 is the next target; if cap >= that
 *     target, store target into g_currentNodeFlags and tail-call
 *     IndirectDispatchCjStore, then StackPopDispatchTagged.
 *     Else tail-call IndirectDispatchCjStore directly.
 */
extern unsigned int g_byte_00538148;
extern void CallSetPause(void);
extern void IndirectDispatchCjStore(void);
extern void MStackPush6OpPop6(void);

__declspec(naked) void Phase3InstallTableCheck(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        xor     ebx, ebx
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], ebx
        cmp     eax, ebx
        je      L_p3itc_phase0
        cmp     byte ptr [g_byte_00538148], bl
        je      short L_p3itc_phase1
        mov     ecx, dword ptr [g_eventQueueIdx]
        lea     eax, [ecx*4]
        cmp     eax, 0x4efe18
        je      L_p3itc_pauseTail
        cmp     eax, 0x4eff00
        je      L_p3itc_pauseTail
        cmp     eax, 0x4effe8
        je      L_p3itc_pauseTail
        cmp     eax, 0x4f00d0
        je      L_p3itc_pauseTail
        mov     byte ptr [g_byte_00538148], bl
    L_p3itc_phase1:
        mov     dword ptr [g_walkCallback], ebx
        call    dword ptr [g_eventQueueChild]
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     L_p3itc_done
        call    MStackPush6OpPop6
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     L_p3itc_done
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     eax, dword ptr [edx*4]
        add     eax, 0x30000
        cmp     ecx, eax
        mov     dword ptr [g_walkCallback], eax
        jl      L_p3itc_dispatchOnly
        mov     dword ptr [g_currentNodeFlags], eax
        call    IndirectDispatchCjStore
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     L_p3itc_done
        call    StackPopDispatchTagged
        pop     esi
        pop     ebx
        ret
    L_p3itc_phase0:
        mov     dword ptr [g_walkCallback], ebx
        call    dword ptr [g_eventQueueChild]
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     L_p3itc_done
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueTotal]
        mov     eax, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueTotal]
        mov     eax, dword ptr [edx*4 + 0x58]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 4], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueTotal]
        mov     eax, dword ptr [edx*4 + 0x5c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 8], eax
    L_p3itc_dispatchOnly:
        call    IndirectDispatchCjStore
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_p3itc_done
        mov     eax, 1
        mov     dword ptr [esi + 8], offset Phase3InstallTableCheck
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p3itc_done:
        pop     esi
        pop     ebx
        ret
    L_p3itc_pauseTail:
        call    CallSetPause
        pop     esi
        pop     ebx
        ret
    }
}
