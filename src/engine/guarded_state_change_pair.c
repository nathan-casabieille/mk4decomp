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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

extern unsigned int g_stateFlag;
extern unsigned int g_stateChangePair2_005380a4;
extern unsigned int g_stateChangeBase_005380b0;
extern unsigned int g_stateChangePair3_0053a278;
extern unsigned int g_stateChangePair_00541d6c;
extern void CallSetPause(void);
extern void MStackPush2ClampLookup_00459160(void);
extern void SpawnTrioInitCluster_00458440(void);
extern void TripleEntryDispatch_00458810(void);

__declspec(naked) void GuardedStateChangePair_00458630(void)
{
    __asm
    {
        mov     eax, dword ptr [g_stateChangePair_00541d6c]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_gscp_check27
        jmp     CallSetPause
    L_gscp_check27:
        mov     edx, dword ptr [g_stateChangePair3_0053a278]
        cmp     edx, 0x27
        mov     dword ptr [g_walkCallback], edx
        je      L_gscp_dec
        mov     ecx, dword ptr [g_stateChangePair2_005380a4]
        mov     eax, offset g_stateChangeBase_005380b0
        shr     eax, 2
        cmp     ecx, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        jg      short L_gscp_inst
        add     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        call    MStackPush2ClampLookup_00459160
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_gscp_ret
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, dword ptr [ecx*4]
        dec     ecx
        inc     eax
        mov     dword ptr [g_matrixStackTop], ecx
        cmp     eax, 2
        mov     dword ptr [g_eventQueueCurrent], eax
        jle     short L_gscp_setSlot
    L_gscp_inst:
        mov     eax, 1
        push    0
        push    offset L_gscp_sub2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_stateChangePair_00541d6c], eax
        call    StoreTwoCall
        add     esp, 8
        jmp     CallSetPause
    L_gscp_setSlot:
        mov     dword ptr [g_stateChangePair2_005380a4], eax
        call    SpawnTrioInitCluster_00458440
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gscp_ret
        push    0
        push    offset L_gscp_sub2
        call    StoreTwoCall
        add     esp, 8
        jmp     CallSetPause
    L_gscp_dec:
        mov     edx, dword ptr [g_stateChangePair2_005380a4]
        lea     ecx, [edx - 1]
        test    ecx, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        jge     short L_gscp_decOk
        jmp     CallSetPause
    L_gscp_decOk:
        mov     eax, offset g_stateChangeBase_005380b0
        mov     dword ptr [g_stateChangePair2_005380a4], ecx
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], 0x27
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], 0x27
        call    SpawnTrioInitCluster_00458440
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gscp_ret
        jmp     CallSetPause
    L_gscp_ret:
        ret
        nop
        nop
        nop
    L_gscp_sub2:
        mov     eax, dword ptr [g_baseSel]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        je      short L_gscp_sub2_inst
        mov     dword ptr [g_eventQueueWorkType], 0x264
        call    Push16Call
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_gscp_sub2_ret
        jmp     CallSetPause
    L_gscp_sub2_inst:
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset L_gscp_sub2
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
    L_gscp_sub2_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_gscp_sub3:
        mov     eax, dword ptr [g_stateFlag]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_gscp_sub3_jmp
        jmp     CallSetPause
    L_gscp_sub3_jmp:
        jmp     TripleEntryDispatch_00458810
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_gscp_sub4:
        mov     eax, dword ptr [g_stateFlag]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     short L_gscp_sub4_jmp
        jmp     CallSetPause
    L_gscp_sub4_jmp:
        jmp     TripleEntryDispatch_00458810
    }
}
