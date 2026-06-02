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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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
extern void DispatcherComplex260_FramePauseScaledStore(void);
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

/* @addr 0x00446980 (389b game) - 2-entry packed: vec-scale helper +
 *   mstack-push + 3-call rescale.
 *   Entry 1 (offset 0, 85b): scales a vec component. Pushes
 *     g_eventQueueCurrent onto Mul10Tail with 0x13333 weight, then
 *     0x54206c = 0xf5c → StoreDoubleNegPauseSubStore. On
 *     no-error adds 0x10000 to 0x54206c, calls Mul10Tail again with that
 *     value, stores result in g_eventQueueCurrent.
 *   11b NOP align pad.
 *   Entry 2 (offset 0x60, 293b): pushes g_fightGroupHead onto mstack,
 *     calls ChainWalkPushPop. On no-error sets 0x54206c=0x12c
 *     → AudioVolumeRescale. If bit 0 of 0x54208c set also
 *     calls MStackPush2VolumeCascade. Then for each of the
 *     3 components at [g_fightGroupHead*4 + 0x6c/0x70/0x74]:
 *       - copy into g_eventQueueCurrent
 *       - call entry 1 (the scaler)
 *       - store result back
 *     Then clamps the scaled +0x58 field at -0x2666 (0xffffd99a) and
 *     zeroes +0x70 when clamped. Sets g_xformEntityIdx-pointed slot's
 *     +0x10=0, +0x14=&g_dispatchVar43>>2. Pops mstack and returns.
 */
extern unsigned int g_dispatchVar43;
extern unsigned int g_table_004d57b0;
extern void AudioVolumeRescale(void);
extern void ChainWalkPushPop(void);
extern void MStackPush2VolumeCascade(void);
extern void StoreDoubleNegPauseSubStore(void);

__declspec(naked) void VecScaleMStackTripleCall(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    0x13333
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 0xf5c
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_vsm_e1End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
    L_vsm_e1End:
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
        /* entry 2 (offset 0x60) */
    L_vsm_entry2:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        call    ChainWalkPushPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_vsm_pop1
        mov     dword ptr [g_walkCallback], 0x12c
        call    AudioVolumeRescale
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_vsm_pop1
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_vsm_doVecScale
        call    MStackPush2VolumeCascade
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_vsm_pop1
    L_vsm_doVecScale:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x6c]
        lea     esi, [edx*4]
        mov     dword ptr [g_eventQueueCurrent], eax
        call    VecScaleMStackTripleCall
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     edx, dword ptr [esi + 0x70]
        mov     dword ptr [esi + 0x6c], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        call    VecScaleMStackTripleCall
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [esi + 0x74]
        mov     dword ptr [esi + 0x70], eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        call    VecScaleMStackTripleCall
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, 0xffffd99a
        mov     dword ptr [esi + 0x74], edx
        mov     eax, dword ptr [g_fightGroupHead]
        cmp     dword ptr [eax*4 + 0x58], ecx
        jl      short L_vsm_skipClamp
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x70], 0
    L_vsm_skipClamp:
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, offset g_dispatchVar43
        shr     eax, 2
        mov     dword ptr [ecx*4 + 0x10], 0
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x14], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_vsm_pop1:
        pop     esi
        ret
    }
}
