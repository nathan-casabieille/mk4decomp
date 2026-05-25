/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x004300a0 (312b game) - distance2D Mul10 clamp / 3-branch saturation.
 *   Sub esi=g_cj. dx=[cj*4+0x54]-g_load_0052ab04; dy=[cj*4+0x5c]-g_load_0052ab08.
 *   Mul10Tail(dx,dx)+Mul10Tail(dy,dy)->g_acc.
 *   If sum > 0x370000: jump to saturation_high.
 *   Else: load g_player1NodeIdx / g_player2NodeIdx (scaledInit/x_48); a=[scaled[+0x58]], c=[48[+0x58]].
 *     if a>c: a=c. If a<=-0x20000: jump to saturation_low. Else jump to high path.
 *   saturation_high: cmp [cj*4+0x58], -0x18000; if >=: store -0x18000, set fields=0, ret.
 *     Else: ecx=0x7ae, store at cj[+0x70]=ecx; pop+ret.
 *   saturation_low: cmp ecx with 0xfffe3334; if < 0: eax=0; mov [cj*4+0x70]=eax; pop+ret.
 *     Else: eax stays -0x7ae, mov to g_walkCallback, store at cj[+0x70]=-0x7ae; pop+ret.
 */
extern unsigned int g_load_0052ab04;
extern unsigned int g_load_0052ab08;
extern unsigned int g_player2NodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueWorkType;

__declspec(naked) void Distance2DSaturationClamp_004300a0(void) {
    __asm {
        mov     ecx, dword ptr [g_load_0052ab04]
        mov     edx, dword ptr [g_load_0052ab08]
        push    esi
        mov     esi, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     eax, dword ptr [esi*4 + 0x54]
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     esi, dword ptr [esi*4 + 0x5c]
        sub     eax, ecx
        sub     esi, edx
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_acc_00542078], esi
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [g_acc_00542078]
        push    eax
        push    eax
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_eventQueueWorkType]
        add     esp, 8
        add     eax, edx
        cmp     eax, 0x370000
        mov     dword ptr [g_acc_00542078], eax
        _emit   7fh
        _emit   41h
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     ecx, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 0x58]
        cmp     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   7eh
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 0xfffe0000
        _emit   7eh
        _emit   4fh
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [eax*4 + 0x58]
        cmp     ecx, 0xfffe8000
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   7ch
        _emit   21h
        mov     dword ptr [eax*4 + 0x58], 0xfffe8000
        mov     ecx, dword ptr [g_cj_0054205c]
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        pop     esi
        ret
        mov     ecx, 0x7ae
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x70], ecx
        pop     esi
        ret
        mov     edx, dword ptr [g_cj_0054205c]
        mov     eax, 0xfffff852
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [edx*4 + 0x58]
        cmp     ecx, 0xfffe3334
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   7dh
        _emit   07h
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x70], eax
        pop     esi
        ret
    }
}
