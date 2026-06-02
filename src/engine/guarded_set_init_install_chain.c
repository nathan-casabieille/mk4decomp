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

extern unsigned int g_dispatchSave991;
extern unsigned int g_dispatchVar33;
extern unsigned int g_phaseThunkSlot2;
extern void GatedWordPushCall(void);
extern void StorePauseImulShr16(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void GuardedSetInitInstallChain(void)
{
    __asm
    {
        mov     eax, dword ptr [g_gtFightTickCounter]
        mov     ecx, dword ptr [g_dispatchVar33]
        cmp     ecx, eax
        jne     short L_gsiic_diff
        mov     eax, dword ptr [g_phaseThunkSlot2]
        inc     eax
        test    eax, eax
        mov     dword ptr [g_phaseThunkSlot2], eax
        jg      L_gsiic_ret
        jmp     short L_gsiic_chain
    L_gsiic_diff:
        mov     dword ptr [g_dispatchVar33], eax
        mov     dword ptr [g_phaseThunkSlot2], 0
    L_gsiic_chain:
        mov     dword ptr [g_walkCallback], 4
        call    StorePauseImulShr16
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gsiic_ret
        add     dword ptr [g_walkCallback], 5
        jmp     GatedWordPushCall
    L_gsiic_ret:
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
        nop
    L_gsiic_sub2:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      short L_gsiic_sub2_phase0
        dec     eax
        je      short L_gsiic_sub2_phase1
        mov     eax, dword ptr [g_eventQueueEnd]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], eax
        jns     short L_gsiic_sub2_inner
        call    Thunk_ScaledNeg1SetPause
        pop     esi
        ret
    L_gsiic_sub2_phase1:
        mov     dword ptr [g_eventQueueEnd], 0xf
    L_gsiic_sub2_inner:
        mov     dword ptr [g_walkCallback], 3
        call    StorePauseImulShr16
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gsiic_sub2_ret
        add     dword ptr [g_walkCallback], 0xb
        call    GatedWordPushCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gsiic_sub2_ret
        mov     dword ptr [esi + 8], offset L_gsiic_sub2
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 6
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_gsiic_sub2_phase0:
        mov     dword ptr [g_walkCallback], 0x15
        call    GatedWordPushCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gsiic_sub2_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_gsiic_sub2
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0x11
        mov     dword ptr [g_framePauseFlag], eax
    L_gsiic_sub2_ret:
        pop     esi
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
        nop
        nop
    L_gsiic_sub3:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_gsiic_sub3_phase0
        mov     dword ptr [g_walkCallback], 0xa
        call    GatedWordPushCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gsiic_sub3_ret
        mov     ecx, dword ptr [g_eventQueueEnd]
        jmp     short L_gsiic_sub3_load
    L_gsiic_sub3_phase0:
        mov     ecx, offset g_dispatchSave991
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], ecx
    L_gsiic_sub3_load:
        mov     eax, dword ptr [ecx*4]
        inc     ecx
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_eventQueueEnd], ecx
        jne     short L_gsiic_sub3_install
        call    Thunk_ScaledNeg1SetPause
        pop     esi
        ret
    L_gsiic_sub3_install:
        mov     dword ptr [g_pendingNodeType], eax
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_gsiic_sub3
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_gsiic_sub3_ret:
        pop     esi
        ret
    }
}
