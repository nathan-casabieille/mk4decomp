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

extern unsigned int g_const_0049db40;
extern unsigned int g_dispatchSave616;
extern void ChainListVecAdd(void);
extern void GuardedSeq_00471670(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void MStackPushCallPop(void);
extern void MStackScopedSlotSetupPair(void);
extern void SetJmp_ZeroAndDirty4(void);

__declspec(naked) void Phase2InitDispatchInstallSelf(void)
{
    __asm {
        call    SetJmp_ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2id_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p2id_ret
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2id_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, offset g_dispatchSave616
        push    0xC0
        shr     edx, 2
        push    offset g_const_0049db40
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_eventQueueIdx], edx
        mov     dword ptr [g_eventQueueNotMask], 0xC1
        call    StoreTwoCall
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     L_p2id_tailjmp
        call    MStackPushCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2id_ret
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x44], eax
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     edx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x48], eax
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x4C], eax
        inc     dword ptr [g_eventQueueTotal]
    L_p2id_tailjmp:
        jmp     MStackPop8
    L_p2id_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
    L_p2id_helper:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p2id_helper_phase0
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x18]
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        jne     L_p2id_helper_have_18
        call    GuardedSeq_00471670
        pop     esi
        ret
    L_p2id_helper_have_18:
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], eax
        and     eax, 0x400
        mov     dword ptr [g_xformScratch94], eax
        je      L_p2id_helper_after_400
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x38]
        sub     eax, 0x33
        mov     dword ptr [g_walkCallback], eax
        jns     L_p2id_helper_store_38
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
    L_p2id_helper_store_38:
        mov     dword ptr [ecx*4 + 0x38], eax
    L_p2id_helper_after_400:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x18]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     L_p2id_helper_link
        call    GuardedSeq_00471670
        pop     esi
        ret
    L_p2id_helper_phase0:
        call    MStackScopedSlotSetupPair
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2id_helper_pop_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      al, 0x40
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [ecx*4 + 0x28]
        mov     ecx, 0x10000
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x2C], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4]
        or      ecx, 0x0A
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x3333
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x48], eax
    L_p2id_helper_link:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    ChainListVecAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2id_helper_pop_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0040BB70
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p2id_helper_pop_ret:
        pop     esi
        ret
    }
}
