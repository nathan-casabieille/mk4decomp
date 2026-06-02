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

/* ------------------------------------------------------------------ */
/* CRT pow() helper cluster (544b boot/crt)                            */
/* ------------------------------------------------------------------ */
extern void TwinEntryFpHelper(void);
extern void FloatTransientHelpers(void);
extern void func_004ca2c5(void);
extern void func_004ca2f5(void);
extern void func_004ca34e(void);
extern void func_004ca399(void);
extern void CrtPowSpecialCases(void);
extern unsigned int g_dispatchSave118;
extern unsigned int g_crtPowConstBase;
extern unsigned int g_dispatchSave113;
extern unsigned int g_crtFpuTbyte;
extern unsigned int g_dispatchSave1422;

__declspec(naked) void CrtPowCluster(void)
{
    __asm {
        sub      esp, 0x10
        fxch     st(1)
        fstp     qword ptr [esp]
        fst      qword ptr [esp + 8]
        mov      eax, dword ptr [esp + 0xc]
        call     L_6562
        add      esp, 0x10
        ret
        lea      edx, [esp + 0xc]
        call     func_004ca2f5
    L_6562:
        mov      ecx, eax
        push     eax
        wait
        fnstcw   word ptr [esp]
        cmp      word ptr [esp], 0x27f
        je       short L_6576
        call     func_004ca2c5
    L_6576:
        and      ecx, 0x7ff00000
        lea      edx, [esp + 8]
        cmp      ecx, 0x7ff00000
        je       L_6629
        call     func_004ca2f5
        je       L_6625
        test     eax, 0x7ff00000
        je       L_6698
    L_65a2:
        mov      cl, byte ptr [esp + 0xf]
        and      cl, 0x80
        jne      L_6710
    L_65af:
        fyl2x
        call     FloatTransientHelpers
        cmp      cl, 1
        jne      short L_65bd
        fchs
    L_65bd:
        cmp      dword ptr [g_dispatchSave1422], 0
        jne      func_004ca34e
        lea      ecx, [g_crtPowConstBase]
        mov      edx, 0x1d
        jmp      func_004ca399
    L_65da:
        cmp      dword ptr [g_dispatchSave1422], 0
        jne      func_004ca34e
        lea      ecx, [g_crtPowConstBase]
        mov      edx, 0x1d
        call     TwinEntryFpHelper
        pop      edx
        ret
    L_65f9:
        lea      edx, [esp + 8]
        call     func_004ca2f5
        test     byte ptr [esp + 0x16], 8
        jne      short L_660c
        inc      ecx
        jmp      short L_663f
    L_660c:
        faddp    st(1), st
        mov      eax, 1
        jmp      L_65da
    L_6615:
        test     byte ptr [esp + 0xe], 8
        jne      short L_660c
    L_661c:
        faddp    st(1), st
        mov      eax, 7
        jmp      L_65da
    L_6625:
        xor      ecx, ecx
        jmp      short L_663f
    L_6629:
        xor      ecx, ecx
        and      eax, 0xfffff
        or       eax, dword ptr [esp + 0x10]
        jne      short L_65f9
        lea      edx, [esp + 8]
        call     func_004ca2f5
    L_663f:
        mov      eax, dword ptr [esp + 0xc]
        mov      edx, eax
        and      eax, 0x7ff00000
        and      edx, 0xfffff
        cmp      eax, 0x7ff00000
        jne      short L_665d
        or       edx, dword ptr [esp + 8]
        jne      short L_6615
    L_665d:
        test     ecx, ecx
        jne      short L_661c
        sub      esp, 0x74
        mov      ecx, esp
        push     ecx
        sub      esp, 0x10
        fstp     qword ptr [esp]
        fstp     qword ptr [esp + 8]
        wait
        fnsave   dword ptr [ecx + 8]
        call     CrtPowSpecialCases
        add      esp, 0x10
        pop      ecx
        frstor   dword ptr [ecx + 8]
        fld      qword ptr [ecx]
        add      esp, 0x74
        test     eax, eax
        je       func_004ca34e
        mov      eax, 1
        jmp      L_65da
    L_6698:
        mov      eax, dword ptr [esp + 0xc]
        and      eax, 0xfffff
        or       eax, dword ptr [esp + 8]
        jne      L_65a2
        fstp     st(0)
        mov      eax, dword ptr [esp + 0x14]
        test     eax, 0x7ff00000
        je       short L_66f5
        call     L_6735
        mov      ch, byte ptr [esp + 0xf]
        shr      ch, 7
        test     dword ptr [esp + 0x17], 0x80
        je       short L_66e4
        fld      tbyte ptr [g_dispatchSave113]
        test     cl, ch
        je       short L_66da
        fchs
    L_66da:
        mov      eax, 2
        jmp      L_65da
    L_66e4:
        fldz
        test     cl, ch
        je       func_004ca34e
        fchs
        jmp      func_004ca34e
    L_66f5:
        fstp     st(0)
        and      eax, 0xfffff
        or       eax, dword ptr [esp + 0x10]
        jne      short L_6709
        fld1
        jmp      func_004ca34e
    L_6709:
        fldz
        jmp      func_004ca34e
    L_6710:
        fld      st(1)
        call     L_6735
        fchs
        test     cl, cl
        jne      L_65af
        fstp     st(0)
        fstp     st(0)
        fld      tbyte ptr [g_crtFpuTbyte]
        mov      eax, 1
        jmp      L_65da
    L_6735:
        fld      st(0)
        frndint
        fcomp    st(1)
        mov      cl, 0
        wait
        fnstsw   ax
        sahf
        jne      short L_675a
        fmul     qword ptr [g_dispatchSave118]
        inc      cl
        fld      st(0)
        frndint
        fcompp
        wait
        fnstsw   ax
        sahf
        jne      short L_6759
        inc      cl
    L_6759:
        ret
    L_675a:
        fstp     st(0)
        ret
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
    }
}
