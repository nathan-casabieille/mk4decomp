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

extern unsigned int g_const_004d2b88;
extern unsigned int g_dispatchSave889;
extern unsigned int g_dispatchSave890;
extern unsigned int g_crtCType;
extern unsigned int g_crtLocaleNumeric;
extern unsigned int g_byte_00522bb4;
extern unsigned int g_iat_GetProcAddress;
extern unsigned int g_iat_GetModuleHandleA;
extern void FPUPrecisionCheck(void);
extern void IsCType(void);
extern void SevenArgThenTwoArg_004ccd20(void);
extern void SevenArgThenTwoArg_004ccd60(void);
extern void TolowerLocale(void);

__declspec(naked) void LocaleNumericHelpers(void)
{
    __asm {
        /* Helper 1: __setusermatherr early-init guard. */
        push     OFFSET g_dispatchSave890
        call     dword ptr [g_iat_GetModuleHandleA]
        test     eax, eax
        je       short L_8474
        push     OFFSET g_dispatchSave889
        push     eax
        call     dword ptr [g_iat_GetProcAddress]
        test     eax, eax
        je       short L_8474
        push     0
        call     eax
        ret
    L_8474:
        jmp      FPUPrecisionCheck
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* Helper 2: scan-and-swap. */
        push     esi
        mov      esi, dword ptr [esp + 8]
        movsx    eax, byte ptr [esi]
        push     eax
        call     TolowerLocale
        add      esp, 4
        cmp      eax, 0x65
        je       short L_84c3
    L_8496:
        mov      eax, dword ptr [g_crtLocaleNumeric]
        inc      esi
        cmp      eax, 1
        jle      short L_84b1
        movsx    ecx, byte ptr [esi]
        push     4
        push     ecx
        call     IsCType
        add      esp, 8
        jmp      short L_84bf
    L_84b1:
        movsx    edx, byte ptr [esi]
        mov      eax, dword ptr [g_crtCType]
        mov      al, byte ptr [eax + edx*2]
        and      eax, 4
    L_84bf:
        test     eax, eax
        jne      short L_8496
    L_84c3:
        mov      cl, byte ptr [g_byte_00522bb4]
        mov      al, byte ptr [esi]
        mov      byte ptr [esi], cl
        inc      esi
    L_84ce:
        mov      cl, byte ptr [esi]
        mov      byte ptr [esi], al
        mov      dl, byte ptr [esi]
        inc      esi
        test     dl, dl
        mov      al, cl
        jne      short L_84ce
        pop      esi
        ret
        nop
        nop
        nop
        /* Helper 3: strip_locale_decimal_zeros. */
        mov      eax, dword ptr [esp + 4]
        push     ebx
        mov      bl, byte ptr [g_byte_00522bb4]
        mov      cl, byte ptr [eax]
        test     cl, cl
        je       short L_84fd
    L_84f1:
        cmp      cl, bl
        je       short L_84fd
        mov      cl, byte ptr [eax + 1]
        inc      eax
        test     cl, cl
        jne      short L_84f1
    L_84fd:
        mov      cl, byte ptr [eax]
        inc      eax
        test     cl, cl
        je       short L_8549
        mov      cl, byte ptr [eax]
        test     cl, cl
        je       short L_851c
    L_850a:
        cmp      cl, 0x65
        je       short L_851c
        cmp      cl, 0x45
        je       short L_851c
        mov      cl, byte ptr [eax + 1]
        inc      eax
        test     cl, cl
        jne      short L_850a
    L_851c:
        mov      cl, byte ptr [eax - 1]
        mov      edx, eax
        dec      eax
        cmp      cl, 0x30
        jne      short L_8530
    L_8527:
        mov      cl, byte ptr [eax - 1]
        dec      eax
        cmp      cl, 0x30
        je       short L_8527
    L_8530:
        cmp      byte ptr [eax], bl
        jne      short L_8535
        dec      eax
    L_8535:
        mov      cl, byte ptr [edx]
        inc      eax
        inc      edx
        test     cl, cl
        mov      byte ptr [eax], cl
        je       short L_8549
    L_853f:
        mov      cl, byte ptr [edx]
        inc      eax
        inc      edx
        test     cl, cl
        mov      byte ptr [eax], cl
        jne      short L_853f
    L_8549:
        pop      ebx
        ret
        nop
        nop
        nop
        nop
        nop
        /* Helper 4: __isnan-ish double-vs-0 check. */
        mov      eax, dword ptr [esp + 4]
        fld      qword ptr [eax]
        fcomp    qword ptr [g_const_004d2b88]
        fnstsw   ax
        test     ah, 1
        jne      short L_8569
        mov      eax, 1
        ret
    L_8569:
        xor      eax, eax
        ret
        nop
        nop
        nop
        nop
        /* Helper 5: 2-dword writeback via SevenArgThenTwoArg_004ccd20. */
        mov      eax, dword ptr [esp + 4]
        sub      esp, 8
        test     eax, eax
        je       short L_85a2
        mov      eax, dword ptr [esp + 0x14]
        /* MASM emits 3-byte `8d 0c 24` for lea ecx, [esp]; orig uses
         * the 4-byte disp8=0 form `8d 4c 24 00` here. */
        _emit    0x8d
        _emit    0x4c
        _emit    0x24
        _emit    0x00
        push     eax
        push     ecx
        call     SevenArgThenTwoArg_004ccd20
        mov      eax, dword ptr [esp + 0x18]
        mov      edx, dword ptr [esp + 8]
        mov      ecx, dword ptr [esp + 0xc]
        add      esp, 8
        mov      dword ptr [eax], edx
        mov      dword ptr [eax + 4], ecx
        add      esp, 8
        ret
        /* Helper 6: 1-dword writeback via SevenArgThenTwoArg_004ccd60. */
    L_85a2:
        mov      edx, dword ptr [esp + 0x14]
        lea      eax, [esp + 0x14]
        push     edx
        push     eax
        call     SevenArgThenTwoArg_004ccd60
        mov      ecx, dword ptr [esp + 0x18]
        mov      edx, dword ptr [esp + 0x1c]
        add      esp, 8
        mov      dword ptr [ecx], edx
        add      esp, 8
        ret
    }
}
