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

extern unsigned int g_pendingMatchVar;
extern unsigned int g_dispatchSave917;
extern unsigned int g_phase4ThreePackedBase;
extern unsigned int g_dispatchSave778;
extern unsigned int g_load_0052ab04;
extern unsigned int g_load_0052ab08;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_installOwner2;
extern unsigned int g_dispatchSave71;
extern void AudioMixerStep(void);
extern void CallSetPause(void);
extern void EsiInstallSetCbChainExtend_0048a810(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void MStackPushZeroCallPop(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void StoreLoadJmp(void);
extern void StorePauseImulShr16(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void Phase4ThreePackedInstallSelf(void)
{
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        xor     edi, edi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        jne     L_p4tpis_A_call_0049cbc0
        mov     ecx, offset g_phase4ThreePackedBase
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p4tpis_A_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4tpis_A_continue
    L_p4tpis_A_call_0049cbc0:
        call    Thunk_ScaledNeg1SetPause
        pop     edi
        pop     esi
        ret
    L_p4tpis_A_continue:
        mov     eax, dword ptr [g_currentNodeIdx]
        push    0x0041A7D0
        mov     dword ptr [g_installOwnerNode], eax
        mov     dword ptr [eax*4 + 0x64], 0x0004B65F
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_installOwner2], eax
        mov     dword ptr [g_walkCallback], edi
        mov     dword ptr [eax*4 + 0x54], edi
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x5C], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 0xFFFE4CCD
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        call    StoreLoadJmp
        mov     ecx, dword ptr [g_counter_0053a51c]
        mov     eax, offset g_dispatchSave917
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueIdx], eax
        add     esp, 4
        mov     edx, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], edx
        call    StorePauseImulShr16
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p4tpis_A_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, offset g_dispatchSave71
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, dword ptr [g_counter_0053a51c]
        cmp     eax, 3
        jne     L_p4tpis_A_after_3
        mov     ecx, offset g_dispatchSave778
        shr     ecx, 2
        mov     dword ptr [g_eventQueueIdx], ecx
    L_p4tpis_A_after_3:
        mov     edx, dword ptr [g_installOwner2]
        mov     dword ptr [g_eventQueueNotMask], edi
        mov     dword ptr [g_eventQueueEnd], edx
        mov     dword ptr [g_walkCallback], 0xC4
        call    AudioMixerStep
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p4tpis_A_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, 0x0041A610
        add     eax, 0x189
        add     edx, 0x01000000
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [esi + 8], 0x0041A610
        mov     ecx, dword ptr [g_baseSel]
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edi
        call    EsiInstallSetCbChainExtend_0048a810
        mov     dword ptr [g_framePauseFlag], 1
    L_p4tpis_A_ret:
        pop     edi
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
    L_p4tpis_B:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        mov     dword ptr [eax*4 + 0x84], 0
        lea     esi, [eax*4]
        mov     eax, dword ptr [g_installOwnerNode]
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, dword ptr [eax*4 + 0x54]
        push    eax
        push    0xCCCC
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_load_0052ab04]
        push    eax
        push    0x3333
        mov     dword ptr [g_eventQueueCurrent], eax
        call    Mul10Tail
        mov     edx, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueIdx]
        add     eax, edx
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     eax, dword ptr [edx*4 + 0x5C]
        push    eax
        push    0xCCCC
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_load_0052ab08]
        push    eax
        push    0x3333
        mov     dword ptr [g_eventQueueCurrent], eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_walkCallback]
        add     esp, 8
        add     eax, ecx
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x5C], eax
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0041A7D0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
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
    L_p4tpis_C:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushZeroCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      al, 0x40
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4]
        or      ecx, 0x0A
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_pendingMatchVar]
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x3C], ecx
        mov     eax, dword ptr [g_pendingMatchVar]
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x40], ecx
        mov     eax, dword ptr [g_pendingMatchVar]
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x44], ecx
        mov     dword ptr [g_walkCallback], 0x6666
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     eax, 0x9999
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     dword ptr [g_walkCallback], 0x6666
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tpis_C_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x2C], edx
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x0049D200
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x10], eax
        jmp     CallSetPause
    L_p4tpis_C_ret:
        ret
    }
}
