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

/* @addr 0x0049c710 (305b game) - install-self body with state-machine, bit2-loop, indirect-call dispatch.
 *   Load state; clear. state==0: call TripleBlockChainDiffMStackThunks; if pause ret.
 *   ebx=1. If g_eventQueueChild==0: call ScaledChain3c74; if pause ret.
 *     If g_walkCallback==0x2001: jmp bit2-loop block.
 *   Else (state!=0 OR not 0x2001): mstack-push g_eventQueueChild; load chain[g_eventQueueEnd*4+0] -> g_walkCallback.
 *     Call AtanDualDeltaThreshold; if pause ret. Mstack-pop into g_eventQueueChild.
 *     If bit0(0054208c): chain[g_eventQueueEnd*4+8] -> g_scaledInit; indirect call; pop; ret.
 *   bit2-loop: eax = [g_eventQueueEnd*4+4]; ecx=4; set bit2 of g_xformDirtyFlags.
 *     If eax!=0: toggle bit2 off; call eax; if pause ret.
 *     Install-self at entry; state=1; g_pendingNodeType=1; pause=1; pop esi/ebx; ret.
 */
extern void AtanDualDeltaThreshold(void);
extern void ScaledChain3c74(void);
extern void TripleBlockChainDiffMStackThunks(void);

extern unsigned int g_matrixStack_arr;

__declspec(naked) void InstallSelfBit2LoopIndirect(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   12h
        call    TripleBlockChainDiffMStackThunks
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0f9h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_eventQueueChild]
        mov     ebx, 1
        test    eax, eax
        _emit   75h
        _emit   1eh
        call    ScaledChain3c74
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d9h
        _emit   00h
        _emit   00h
        _emit   00h
        cmp     dword ptr [g_walkCallback], 0x2001
        _emit   74h
        _emit   74h
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     edx, dword ptr [ecx*4 + 0]
        mov     ecx, dword ptr [g_eventQueueChild]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        call    AtanDualDeltaThreshold
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   90h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        _emit   84h
        _emit   0c3h
        mov     dword ptr [g_eventQueueChild], edx
        _emit   74h
        _emit   16h
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [eax*4 + 8]
        mov     dword ptr [g_scaledInit_00542044], eax
        call    eax
        pop     esi
        pop     ebx
        ret
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [ecx*4 + 4]
        mov     ecx, 4
        or      edx, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   0eh
        xor     edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   02h
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   19h
        mov     dword ptr [esi + 8], offset InstallSelfBit2LoopIndirect
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
    }
}
