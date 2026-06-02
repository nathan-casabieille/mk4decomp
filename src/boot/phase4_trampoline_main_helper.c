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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern unsigned int g_pendingMatchVar;
extern unsigned int g_dispatchSave609_004d7878;
extern unsigned int g_dispatchSave608_004d78b8;
extern unsigned int g_savedNode;
extern void AudioMixerStep(void);
extern void CallSetPause(void);
extern void ChainListVecAdd(void);
extern void ClampMulShiftStore(void);
extern void CmpDivJmp(void);
extern void LoopUnrolledTripleMul10(void);
extern void MStackCall_004065b0(void);
extern void MStackPush1MagicMod2(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledTripleCopy10(void);
extern void SetJmp_00405420(void);
extern void SetJmp_00408d20(void);

__declspec(naked) void Phase4TrampolineMainHelper(void)
{
    __asm {
        push    0xB3
        push    0x004151C0
        call    StoreTwoCall
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_currentNodeIdx]
        shl     ecx, 2
        shl     eax, 2
        mov     edx, dword ptr [ecx + 0x54]
        add     esp, 8
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x30], edx
        mov     ecx, dword ptr [ecx + 0x5C]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x34], ecx
        ret
        nop
        nop
        nop
        nop
    L_p4tmh_M:
        mov     eax, offset g_dispatchSave609_004d7878
        push    esi
        shr     eax, 2
        push    edi
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4tmh_M_tailjmp
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0xA2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        call    SetJmp_00408d20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_xformEntityIdx]
        lea     ecx, [edx*4]
        mov     edx, dword ptr [g_fightGroupHead]
        lea     edi, [esi*4]
        mov     esi, dword ptr [ecx + 0x20]
        or      esi, 0x00004000
        shl     eax, 2
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [ecx + 0x20], esi
        mov     esi, dword ptr [eax]
        mov     dword ptr [eax + 0x48], 0x4CCC
        or      esi, 0x0A
        mov     dword ptr [eax + 0x14], 0xFF
        mov     dword ptr [eax], esi
        mov     esi, 0x9999
        mov     dword ptr [eax + 0x30], 0x12
        mov     dword ptr [eax + 0x10], 0x00415440
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [eax + 0x2C], esi
        mov     eax, dword ptr [edi + 0x30]
        shl     edx, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx + 0x54], eax
        mov     eax, dword ptr [edi + 0x34]
        mov     dword ptr [edx + 0x5C], eax
        mov     dword ptr [edx + 0x58], 0
        mov     eax, 0x0F
        mov     dword ptr [ecx + 0x3C], 0xC000
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], eax
        call    CmpDivJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4tmh_M_call_4065b0
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_savedNode]
        mov     eax, dword ptr [g_pendingMatchVar]
        dec     ecx
        mov     dword ptr [g_xformLoopCounter], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     eax, dword ptr [g_xformLoopCounter]
        mov     ecx, dword ptr [g_walkCallback]
        test    eax, eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        jl      L_p4tmh_M_call_4065b0
        mov     esi, 0x2666
    L_p4tmh_M_loop_top:
        mov     dword ptr [g_walkCallback], esi
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        add     eax, esi
        add     ecx, 0x10000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        call    MStackPush1MagicMod2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     edx, dword ptr [g_walkCallback]
        mov     eax, dword ptr [g_acc_00542078]
        push    edx
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [ecx*4], eax
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [g_acc_00542078]
        push    edx
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_eventQueueCurrent], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 8], eax
        mov     edx, dword ptr [g_acc_00542078]
        push    edx
        push    0xFFFFFAE2
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [ecx*4 + 4], eax
        call    ScaledTripleCopy10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [g_xformLoopCounter]
        dec     eax
        mov     dword ptr [g_xformLoopCounter], eax
        jns     L_p4tmh_M_loop_top
    L_p4tmh_M_call_4065b0:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    MStackCall_004065b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
    L_p4tmh_M_tailjmp:
        call    CallSetPause
    L_p4tmh_M_ret:
        pop     edi
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4tmh_H:
        call    ClampMulShiftStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [eax*4 + 0x2C]
        push    eax
        push    0xE666
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x2C], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     L_p4tmh_H_dec
        mov     eax, dword ptr [ecx*4 + 0x14]
        sub     eax, 0x0C
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x14], eax
        call    SetJmp_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4tmh_H_after
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], 0x28F
        mov     eax, dword ptr [ecx*4 + 0x48]
        add     eax, 0x28F
        cmp     eax, 0x7333
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4tmh_H_no_cap
        mov     eax, 0x7333
        mov     dword ptr [g_walkCallback], eax
    L_p4tmh_H_no_cap:
        mov     dword ptr [ecx*4 + 0x48], eax
        jmp     L_p4tmh_H_after
    L_p4tmh_H_dec:
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
    L_p4tmh_H_after:
        call    ChainListVecAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, offset g_dispatchSave608_004d78b8
        mov     eax, dword ptr [edx*4 + 0x2C]
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    LoopUnrolledTripleMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_p4tmh_H_ret:
        ret
    }
}
