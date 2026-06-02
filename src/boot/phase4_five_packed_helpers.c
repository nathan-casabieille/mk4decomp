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

extern unsigned int g_dispatchSave546;
extern unsigned int g_dispatchSave545;
extern void AudioMixerStep(void);
extern void CallSetPause(void);
extern void ChainListVecAdd(void);
extern void ClampMulShiftStore(void);
extern void CmpDivJmp(void);
extern void MStackPushSet9Jmp(void);
extern void PoseTreeBlendWalker(void);
extern void PushStackCallPauseSet0xa(void);
extern void ScaledStoreThree_00409260(void);
extern void ZeroAndDirty4(void);

__declspec(naked) void Phase4FivePackedHelpers(void)
{
    __asm {
        push    0x8B
        push    0x00412CD0
        call    StoreTwoCall
        add     esp, 8
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
    L_p4fph_B:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p4fph_B_phase0
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_B_call
        call    CallSetPause
        pop     esi
        ret
    L_p4fph_B_phase0:
        mov     dword ptr [g_eventQueueIdx], 0x22
    L_p4fph_B_call:
        mov     dword ptr [g_walkCallback], 0x3333
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_B_exit
        add     dword ptr [g_walkCallback], 0xD999
        call    ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_B_exit
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4fph_B_skip_call
        call    PushStackCallPauseSet0xa
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_B_exit
    L_p4fph_B_skip_call:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412CD0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fph_B_exit:
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
    L_p4fph_C:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4fph_C_phase0
        dec     eax
        je      L_p4fph_C_phase1
        dec     eax
        mov     eax, dword ptr [g_eventQueueIdx]
        je      L_p4fph_C_phase2
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_C_phase3_call
        call    CallSetPause
        pop     esi
        ret
    L_p4fph_C_phase2:
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_C_phase2_dec
        mov     dword ptr [g_eventQueueIdx], 0x28
    L_p4fph_C_phase3_call:
        call    PushStackCallPauseSet0xa
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        call    MStackPushSet9Jmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412D80
        mov     dword ptr [esi + 0x84], 3
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p4fph_C_phase1:
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_C_phase1_call
        mov     dword ptr [g_eventQueueIdx], 6
    L_p4fph_C_phase2_dec:
        call    PushStackCallPauseSet0xa
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        call    MStackPushSet9Jmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        mov     eax, 2
        mov     dword ptr [esi + 8], 0x00412D80
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p4fph_C_phase0:
        mov     dword ptr [g_eventQueueIdx], 5
    L_p4fph_C_phase1_call:
        call    PushStackCallPauseSet0xa
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        call    MStackPushSet9Jmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412D80
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 3
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fph_C_exit:
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
    L_p4fph_D:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p4fph_D_phase0
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_D_call
        call    CallSetPause
        pop     esi
        ret
    L_p4fph_D_phase0:
        mov     dword ptr [g_eventQueueIdx], 3
    L_p4fph_D_call:
        call    PushStackCallPauseSet0xa
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
        mov     eax, dword ptr [g_currentNodeIdx]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      L_p4fph_D_install_self
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, offset g_dispatchSave545
        shr     eax, 2
        mov     dword ptr [ecx*4 + 0x48], 0x4CCC
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x10], 0x00412FF0
        mov     dword ptr [g_walkCallback], eax
        call    ScaledStoreThree_00409260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x20]
        or      ecx, 0x40
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     dword ptr [g_walkCallback], 0x64
        call    CmpDivJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4fph_D_install_self
        mov     edx, offset g_dispatchSave546
        shr     edx, 2
        mov     dword ptr [g_xformEntityIdx], edx
        call    PoseTreeBlendWalker
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
    L_p4fph_D_install_self:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412EC0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 4
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fph_D_exit:
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
    L_p4fph_E:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4fph_E_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], 0xFFFFFDB3
        mov     eax, dword ptr [ecx*4 + 0x48]
        sub     eax, 0x24D
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        call    ChainListVecAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_E_ret
    L_p4fph_E_tail:
        jmp     ClampMulShiftStore
    L_p4fph_E_ret:
        ret
    }
}
