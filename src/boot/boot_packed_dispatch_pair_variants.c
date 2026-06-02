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

extern unsigned int g_dispatchSave911;
extern unsigned int g_dispatchSave912;
extern unsigned int g_dispatchSave913;
extern unsigned int g_dispatchSave914;
extern unsigned int g_packedDispatchVar;
extern void AudioMixerStep(void);
extern void CallSetPause(void);
extern void MStackCall_00406600(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledTripleCopy54(void);
extern void ZeroAndDirty4(void);

__declspec(naked) void BootPackedDispatchPair_00413380(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, offset g_dispatchSave911
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [ecx*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        je      short L_bpdp_skipReplace
        mov     edx, offset g_dispatchSave913
        shr     edx, 2
        mov     dword ptr [g_walkCallback], edx
    L_bpdp_skipReplace:
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_bpdp_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_bpdp_ret
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x34]
        and     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [ecx*4 + 0x34]
        or      eax, edx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        call    ScaledTripleCopy54
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        add     ecx, 0xffffe667
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [eax*4 + 0x14], 0xff
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x4ba0e0
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     MStackCall_00406600
    L_bpdp_ret:
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
        nop
    L_bpdp_main:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_bpdp_main_phase0
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     short L_bpdp_main_chain
        call    CallSetPause
        pop     esi
        ret
    L_bpdp_main_phase0:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_packedDispatchVar]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [edx*4 + 0x30], eax
        mov     dword ptr [g_eventQueueIdx], 5
    L_bpdp_main_chain:
        mov     dword ptr [g_walkCallback], 0x3333
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp_main_ret
        add     dword ptr [g_walkCallback], 0xd999
        call    ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp_main_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_bpdp_main_install
        call    BootPackedDispatchPair_00413380
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp_main_ret
    L_bpdp_main_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_bpdp_main
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 4
        mov     dword ptr [g_framePauseFlag], eax
    L_bpdp_main_ret:
        pop     esi
        ret
    }
}

__declspec(naked) void BootPackedDispatchPair_00413580(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, offset g_dispatchSave912
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [ecx*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        je      short L_bpdp2_skipReplace
        mov     edx, offset g_dispatchSave914
        shr     edx, 2
        mov     dword ptr [g_walkCallback], edx
    L_bpdp2_skipReplace:
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_bpdp2_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_bpdp2_ret
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x34]
        and     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [ecx*4 + 0x34]
        or      eax, edx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        call    ScaledTripleCopy54
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp2_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        add     ecx, 0xffffe667
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [eax*4 + 0x14], 0xff
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x4ba0e0
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     MStackCall_00406600
    L_bpdp2_ret:
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
        nop
    L_bpdp2_main:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_bpdp2_main_phase0
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     short L_bpdp2_main_chain
        call    CallSetPause
        pop     esi
        ret
    L_bpdp2_main_phase0:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_packedDispatchVar]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [edx*4 + 0x30], eax
        mov     dword ptr [g_eventQueueIdx], 4
    L_bpdp2_main_chain:
        mov     dword ptr [g_walkCallback], 0x3333
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp2_main_ret
        add     dword ptr [g_walkCallback], 0xd999
        call    ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp2_main_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_bpdp2_main_install
        call    BootPackedDispatchPair_00413580
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bpdp2_main_ret
    L_bpdp2_main_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_bpdp2_main
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 4
        mov     dword ptr [g_framePauseFlag], eax
    L_bpdp2_main_ret:
        pop     esi
        ret
    }
}
