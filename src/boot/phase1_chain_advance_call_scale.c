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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
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
extern void PendingMatch_StoreTwoCall_0042b930(void);
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
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
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

extern unsigned int g_dispatchSave621;
extern unsigned int g_phase1ChainArr;
extern void AudioVolumeRescale(void);
extern void ChainWalkPushPop(void);
extern void DirtyDoubleDeref(void);
extern void MStackBracket1_TreeWalkRecursive2(void);
extern void MStackCall_00406740(void);
extern void PushPopScaled1cDoubleCall(void);

__declspec(naked) void Phase1ChainAdvanceCallScale(void)
{
    __asm {
        mov     eax, offset g_phase1ChainArr
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1c2_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p1c2_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x40], 0xFFFE6DE1
        mov     dword ptr [edx*4 + 0x3C], 0x0005E666
        lea     eax, [edx*4]
        mov     dword ptr [eax + 0x44], 0x4CCC
        mov     dword ptr [eax + 0x30], 0xFFFFEB03
        mov     dword ptr [g_walkCallback], 0x0A
        call    DirtyDoubleDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1c2_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        jmp     PushPopScaled1cDoubleCall
    L_p1c2_ret:
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
    L_p1c2_helper:
        mov     eax, dword ptr [g_gameMode]
        push    esi
        test    eax, eax
        jne     L_p1c2_helper_pop_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        call    ChainWalkPushPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1c2_helper_pop_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_dispatchSave621]
        add     eax, dword ptr [ecx*4 + 0x70]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        js      L_p1c2_helper_skip_block
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x58]
        add     eax, 0x1999
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jle     L_p1c2_helper_skip_block
        mov     dword ptr [g_walkCallback], 0x28A
        call    AudioVolumeRescale
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1c2_helper_pop_ret
        test    byte ptr [g_xformDirtyFlags], 1
        je      L_p1c2_helper_else
        mov     eax, dword ptr [g_fightGroupHead]
        lea     esi, [eax*4 + 0x70]
        mov     eax, dword ptr [eax*4 + 0x70]
        push    eax
        push    0xFFFF4CCD
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [esi], eax
    L_p1c2_helper_skip_block:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x78]
        lea     esi, [ecx*4]
        push    eax
        push    0xFD70
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [esi + 0x78], eax
        mov     eax, dword ptr [esi + 0x7C]
        push    eax
        push    0xFD70
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [esi + 0x7C], eax
        mov     eax, dword ptr [esi + 0x80]
        push    eax
        push    0xFD70
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [esi + 0x80], eax
        jmp     L_p1c2_helper_pop1
    L_p1c2_helper_else:
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1c2_helper_pop_ret
        mov     dword ptr [g_currentNodeIdx], 0
    L_p1c2_helper_pop1:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_p1c2_helper_pop_ret:
        pop     esi
        ret
    }
}
