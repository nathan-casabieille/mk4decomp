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
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
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

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
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

extern unsigned int g_eq;
extern void DualGatedStateYield(void);
extern void Set1dCallSet16Jmp(void);
extern void ScaledChain3c7c(void);
extern void PunchAnimCluster(void);
extern void NotMaskStorePair(void);
extern void Install3WayChainCounter(void);
extern void FiveCallGuardSetTail(void);

/* @addr 0x00480840 (356b game) - countdown loop install-self w/ 3-way tails.
 *   On phase = [scaled g_baseSel+0x84] == 0 jumps direct to install
 *   tail. Else runs a polling loop:
 *     DualGatedStateYield → on success decrement g_eventQueueChild
 *     and update g_eq (sete on dec result), if <= 0 sets it
 *     to 0xc. If g_eq != 0 calls Set1dCallSet16Jmp.
 *     If g_xformScratch2088 == 1 tail-jmp Install3WayChainCounter.
 *     Else calls ScaledChain3c7c. If g_walkCallback >= 3
 *     tail-jmp Install3WayChainCounter; else sets g_walkCallback=0xb333
 *     and calls EsiEdiAliasDualMul10, sets g_xformScratch2088=0x9999,
 *     calls PunchAnimCluster, then NotMaskStorePair. Selects
 *     g_eventQueueWorkType = 1 (if 0x54205c == g_player1NodeIdx) or 0x10,
 *     AND's with g_eventQueueCurrent → g_xformScratch94; if zero tail-jmp
 *     FiveCallGuardSetTail; else continues loop iteration by
 *     re-reading phase and jumping back if non-zero. Install tail:
 *     [eax+8]=Self, slot[+0x84]=1, g_pendingNodeType=1, 0x541e6c=1.
 */
extern void EsiEdiAliasDualMul10(void);

__declspec(naked) void CountdownInstallSelfMultiTail(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    ebp
        push    esi
        shl     eax, 2
        push    edi
        xor     edi, edi
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edi
        cmp     ecx, edi
        mov     ebx, 1
        je      L_cis_install
        mov     ebp, 0x9999
    L_cis_loopTop:
        call    DualGatedStateYield
        test    eax, eax
        jne     L_cis_done
        mov     eax, dword ptr [g_eventQueueChild]
        mov     ecx, 0
        dec     eax
        sete    cl
        cmp     eax, edi
        mov     dword ptr [g_eventQueueChild], eax
        mov     dword ptr [g_eq], ecx
        jg      short L_cis_skipReset
        mov     eax, 0xc
        mov     dword ptr [g_eventQueueChild], eax
    L_cis_skipReset:
        cmp     ecx, edi
        mov     esi, eax
        je      short L_cis_skipCall1
        call    Set1dCallSet16Jmp
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_cis_done
    L_cis_skipCall1:
        cmp     dword ptr [g_xformScratch2088], ebx
        je      L_cis_call9e0
        call    ScaledChain3c7c
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_cis_done
        cmp     dword ptr [g_walkCallback], 3
        jge     L_cis_call9e0
        mov     dword ptr [g_walkCallback], 0xb333
        call    EsiEdiAliasDualMul10
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_cis_done
        mov     dword ptr [g_xformScratch2088], ebp
        call    PunchAnimCluster
        cmp     dword ptr [g_framePauseFlag], edi
        jne     short L_cis_done
        call    NotMaskStorePair
        cmp     dword ptr [g_framePauseFlag], edi
        jne     short L_cis_done
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_player1NodeIdx]
        mov     eax, ebx
        cmp     ecx, edx
        mov     dword ptr [g_eventQueueChild], esi
        mov     dword ptr [g_eventQueueWorkType], eax
        je      short L_cis_pickEax
        mov     eax, 0x10
        mov     dword ptr [g_eventQueueWorkType], eax
    L_cis_pickEax:
        and     eax, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [g_xformScratch94], eax
        je      short L_cis_call6b0
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [edx*4 + 0x84]
        lea     eax, [edx*4]
        cmp     ecx, edi
        mov     dword ptr [eax + 0x84], edi
        jne     L_cis_loopTop
    L_cis_install:
        mov     dword ptr [eax + 8], offset CountdownInstallSelfMultiTail
        mov     dword ptr [eax + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_cis_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_cis_call9e0:
        call    Install3WayChainCounter
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_cis_call6b0:
        call    FiveCallGuardSetTail
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
