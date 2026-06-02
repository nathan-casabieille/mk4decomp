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

extern unsigned int g_const_004d2ba0;
extern unsigned int g_const_004d2bb4;
extern unsigned int g_const_004d2bbc;
extern unsigned int g_const_004d2bc4;
extern unsigned int g_const_004d2bcc;
extern unsigned int g_const_004d2bd4;
extern unsigned int g_const_004d2bdc;
extern void TwinEntryFpHelper(void);
extern void func_004ca267(void);

__declspec(naked) void FloatTransientHelpers(void)
{
    __asm {
        /* H1: __2_to_x */
        fld      st(0)
        frndint
        fsubr    st(1), st(0)
        fxch     st(1)
        fchs
        f2xm1
        fld1
        faddp    st(1), st
        fscale
        fstp     st(1)
        ret
        /* H2: __set_fpcw_precision */
        mov      edx, dword ptr [esp + 4]
        and      edx, 0x300
        or       edx, 0x7f
        mov      word ptr [esp + 6], dx
        fldcw    word ptr [esp + 6]
        ret
        /* H3: denormal-input classifier */
        test     eax, 0x80000
        je       short L_a2e9
        mov      eax, 7
        ret
    L_a2e9:
        fadd     qword ptr [g_const_004d2ba0]
        mov      eax, 1
        ret
        /* H4: __extract_unbiased_exp_xword */
        mov      eax, dword ptr [edx + 4]
        and      eax, 0x7ff00000
        cmp      eax, 0x7ff00000
        je       short L_a307
        fld      qword ptr [edx]
        ret
    L_a307:
        mov      eax, dword ptr [edx + 4]
        sub      esp, 0xa
        or       eax, 0x7fff0000
        mov      dword ptr [esp + 6], eax
        mov      eax, dword ptr [edx + 4]
        mov      ecx, dword ptr [edx]
        shld     eax, ecx, 0xb
        shl      ecx, 0xb
        mov      dword ptr [esp + 4], eax
        mov      dword ptr [esp], ecx
        fld      tbyte ptr [esp]
        add      esp, 0xa
        test     eax, 0
        mov      eax, dword ptr [edx + 4]
        ret
        /* H5: nan-passthrough probe */
        mov      eax, dword ptr [esp + 8]
        and      eax, 0x7ff00000
        cmp      eax, 0x7ff00000
        je       short L_a349
        ret
    L_a349:
        mov      eax, dword ptr [esp + 8]
        ret
        /* H6: conditional fldcw restore */
        cmp      word ptr [esp], 0x27f
        je       short L_a359
        fldcw    word ptr [esp]
    L_a359:
        pop      edx
        ret
        /* H7: fldcw + status check */
        mov      ax, word ptr [esp]
        cmp      ax, 0x27f
        je       short L_a383
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a380
        wait
        fnstsw   ax
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a380
        mov      eax, 8
        call     func_004ca267
        pop      edx
        ret
    L_a380:
        fldcw    word ptr [esp]
    L_a383:
        pop      edx
        ret
        /* H8: inf/nan check path A */
        sub      esp, 8
        fst      qword ptr [esp]
        mov      eax, dword ptr [esp + 4]
        add      esp, 8
        and      eax, 0x7ff00000
        jmp      short L_a3ad
        /* H9: inf/nan check path B + recovery */
        sub      esp, 8
        fst      qword ptr [esp]
        mov      eax, dword ptr [esp + 4]
        add      esp, 8
        and      eax, 0x7ff00000
        je       short L_a3ea
    L_a3ad:
        cmp      eax, 0x7ff00000
        je       short L_a413
        mov      ax, word ptr [esp]
        cmp      ax, 0x27f
        je       short L_a3e8
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        jne      short L_a3e5
        wait
        fnstsw   ax
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a3e5
        mov      eax, 8
    L_a3d2:
        cmp      edx, 0x1d
        je       short L_a3de
        call     func_004ca267
        pop      edx
        ret
    L_a3de:
        call     TwinEntryFpHelper
        pop      edx
        ret
    L_a3e5:
        fldcw    word ptr [esp]
    L_a3e8:
        pop      edx
        ret
    L_a3ea:
        fld      qword ptr [g_const_004d2bcc]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2bbc]
        wait
        fnstsw   ax
        sahf
        mov      eax, 4
        jae      short L_a3d2
        fmul     qword ptr [g_const_004d2bdc]
        jmp      short L_a3d2
    L_a413:
        fld      qword ptr [g_const_004d2bc4]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2bb4]
        wait
        fnstsw   ax
        sahf
        mov      eax, 3
        jbe      short L_a3d2
        fmul     qword ptr [g_const_004d2bd4]
        jmp      short L_a3d2
        int      3
        int      3
        int      3
        int      3
    }
}
