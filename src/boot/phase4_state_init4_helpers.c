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

extern unsigned int g_dispatchSave909_004d6758;
extern void CallSetPause(void);
extern void ChainListVecAdd(void);
extern void ClampMulShiftStore(void);
extern void CopyThreeFields(void);
extern void MStackCall_00406600(void);
extern void MStackPushNegMul10(void);
extern void MStackPushZeroCallPop_004066f0(void);
extern void PushSetXfmMaskCallPop(void);
extern void ThreeChanPackClamp(void);

__declspec(naked) void Phase4StateInit4Helpers_004130c0(void)
{
    __asm {
        call    ChainDirtyBitWalker
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p44_pop1
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, offset g_dispatchSave909_004d6758
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_walkCallback], ecx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p44_pop1
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_pendingNodeType]
        shl     ecx, 2
        lea     eax, [edx*4]
        mov     edx, 0x98
        mov     dword ptr [g_walkCallback], edx
        push    0x100020
        mov     dword ptr [eax + 0x30], edx
        mov     edx, dword ptr [ecx + 0x3C]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x54], edx
        mov     edx, dword ptr [ecx + 0x40]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        mov     ecx, dword ptr [ecx + 0x44]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax + 0x18]
        mov     dword ptr [eax + 0x5C], ecx
        mov     dword ptr [g_currentNodeIdx], edx
        call    ThreeChanPackClamp
        mov     eax, dword ptr [g_fightGroupHead]
        add     esp, 4
        push    eax
        call    CopyThreeFields
        mov     ecx, dword ptr [g_currentNodeIdx]
        add     esp, 4
        mov     eax, dword ptr [ecx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        shl     eax, 2
        mov     ecx, dword ptr [eax]
        mov     dword ptr [eax + 0x48], 0xA666
        or      ecx, 8
        mov     dword ptr [eax + 0x14], 0xFF
        mov     dword ptr [eax], ecx
        mov     ecx, 0x004131F0
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x10], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_ret
    L_p44_pop1:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_p44_ret:
        ret
        nop
        nop
        nop
    L_p44_helperA:
        call    ClampMulShiftStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperA_ret
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p44_helperA_ret
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x14]
        sub     eax, 0x16
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x14], eax
    L_p44_helperA_ret:
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
    L_p44_helperB:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushZeroCallPop_004066f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperB_ret
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperB_ret
        mov     dword ptr [g_walkCallback], 0xCCC
        call    MStackPushNegMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperB_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x6C], edx
        lea     eax, [ecx*4]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax + 0x74], ecx
        mov     eax, dword ptr [eax + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x20]
        or      ecx, 0x40
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        shl     eax, 2
        mov     ecx, dword ptr [eax]
        mov     dword ptr [eax + 0x48], 0x3333
        or      ecx, 0x0A
        mov     dword ptr [eax + 0x2C], 0x26666
        mov     dword ptr [eax], ecx
        mov     ecx, 0x00413310
        mov     dword ptr [eax + 0x14], 0xFF
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x10], ecx
        jmp     CallSetPause
    L_p44_helperB_ret:
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
        nop
    L_p44_helperC:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p44_helperC_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], 0xFFFFFEB9
        mov     eax, dword ptr [ecx*4 + 0x48]
        sub     eax, 0x147
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        call    ChainListVecAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperC_ret
    L_p44_helperC_tail:
        jmp     ClampMulShiftStore
    L_p44_helperC_ret:
        ret
    }
}
