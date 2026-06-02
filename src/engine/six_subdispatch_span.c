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

extern void MatchPredicateCluster_0045ef50(void);
extern void Mul10Tail(void);
extern void SixSubdispatchSpan_0045ec10(void);

/* @addr 0x0045ede0 (356b game) - 2-entry packed dual-stream diff+mul wrapper.
 *   Entry 1 (offset 0, 301b): for each of two streams identified by
 *   g_player1NodeIdx and g_player2NodeIdx, stores into g_currentNodeIdx and
 *   calls MatchPredicateCluster_0045ef50. If both succeed and bit 0 of g_xformDirtyFlags is
 *   set on each, computes the per-component (x,y,z) differences between
 *   the two stream slot's +0x54/+0x58/+0x5c fields, multiplies each diff
 *   by itself via Mul10Tail (push twice → call), accumulates the
 *   3 squares into g_eventQueueWorkType, then thresholds against 0x20000:
 *     - sum > 0x20000: OR 0x01 into 0x54208c
 *     - else: AND ~0x01 into 0x54208c
 *   (3b NOP align pad.)
 *   Entry 2 (offset 0x130, 52b): reads [g_fightGroupHead*4 + 0x58] and
 *     compares to 0xfffe3334: if greater clears bit 0 of g_xformDirtyFlags
 *     and returns; else sets g_eventQueueCurrent=4 and tail-jmp SixSubdispatchSpan_0045ec10.
 */

__declspec(naked) void DualStreamSqDistThresh_0045ede0(void) {
    __asm {
        mov     eax, dword ptr [g_player1NodeIdx]
        push    esi
        push    edi
        mov     dword ptr [g_currentNodeIdx], eax
        call    MatchPredicateCluster_0045ef50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dsd_skip
        test    byte ptr [g_xformDirtyFlags], 1
        je      L_dsd_skip
        mov     ecx, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    MatchPredicateCluster_0045ef50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dsd_skip
        test    byte ptr [g_xformDirtyFlags], 1
        je      L_dsd_skip
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     edx, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        mov     eax, dword ptr [ecx*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     esi, dword ptr [ecx*4 + 0x58]
        mov     dword ptr [g_eventQueueCurrent], esi
        mov     ecx, dword ptr [ecx*4 + 0x5c]
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     edi, dword ptr [edx*4 + 0x54]
        sub     eax, edi
        mov     dword ptr [g_walkCallback], eax
        mov     edi, dword ptr [edx*4 + 0x58]
        sub     esi, edi
        push    eax
        mov     dword ptr [g_eventQueueCurrent], esi
        mov     esi, dword ptr [edx*4 + 0x5c]
        sub     ecx, esi
        push    eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     eax, dword ptr [g_eventQueueWorkType]
        push    eax
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     esi, dword ptr [g_walkCallback]
        add     ecx, esi
        add     esp, 8
        add     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_eventQueueWorkType], eax
        cmp     eax, 0x20000
        mov     eax, dword ptr [g_xformDirtyFlags]
        jle     short L_dsd_setBit
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        pop     edi
        pop     esi
        ret
    L_dsd_setBit:
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
    L_dsd_skip:
        pop     edi
        pop     esi
        ret
        nop
        nop
        nop
    L_dsd_entry2:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x58]
        cmp     eax, 0xfffe3334
        mov     dword ptr [g_walkCallback], eax
        jle     short L_dsd_e2tail
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    L_dsd_e2tail:
        mov     dword ptr [g_eventQueueCurrent], 4
        jmp     SixSubdispatchSpan_0045ec10
    }
}
