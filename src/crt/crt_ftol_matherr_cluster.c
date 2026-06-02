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

extern unsigned int g_const_004d2c00;
extern unsigned int g_const_004d2c08;
extern unsigned int g_const_004d2c10;
extern unsigned int g_const_004d2c18;
extern unsigned int g_const_004d2c20;
extern unsigned int g_const_004d2c28;
extern unsigned int g_crtFpuExceptionMask;
extern unsigned int g_dispatchSave1422;
extern void Crt_fpieee_flt(void);
extern void FpExceptionFilter(void);
extern void func_004ca0e7(void);

__declspec(naked) void CrtFtolMatherrCluster(void)
{
    __asm {
        /* === Helper 1 (0x4ca700): 2-arg matherr-trigger via fxch === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        wait
        fnstcw   word ptr [ebp - 0xa4]
        wait
        cmp      dword ptr [g_crtFpuExceptionMask], 0
        je       short L_a72f
    L_a71b:
        call     func_004ca0e7
        or       byte ptr [ebp - 0x2c8], 3
        call     L_a7ca
        pop      ebx
        leave
        ret
    L_a72f:
        fxch     st(1)
        fst      qword ptr [ebp - 0x86]
        fxch     st(1)
        fst      qword ptr [ebp - 0x7e]
        jmp      short L_a71b
        /* === Helper 2: 1-arg matherr === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        wait
        fnstcw   word ptr [ebp - 0xa4]
        cmp      dword ptr [g_crtFpuExceptionMask], 0
        je       short L_a773
    L_a758:
        call     FpExceptionFilter
        or       byte ptr [ebp - 0x2c8], 1
        and      byte ptr [ebp - 0x2c8], 0xfd
        call     L_a7ca
        pop      ebx
        leave
        ret
    L_a773:
        fst      qword ptr [ebp - 0x86]
        jmp      short L_a758
        /* === Helper 3: 4-arg matherr === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        push     dword ptr [ebp + 0xc]
        push     dword ptr [ebp + 8]
        call     L_a92e
        add      esp, 8
        push     dword ptr [ebp + 0x14]
        push     dword ptr [ebp + 0x10]
        call     L_a92e
        add      esp, 8
        wait
        fnstcw   word ptr [ebp - 0xa4]
        or       byte ptr [ebp - 0x2c8], 2
        mov      byte ptr [ebp - 0x8f], 1
        call     func_004ca0e7
        call     L_a7c3
        pop      ebx
        leave
        ret
    L_a7c3:
        and      byte ptr [ebp - 0x2c8], 0xfe
    L_a7ca:
        cmp      dword ptr [g_dispatchSave1422], 0
        jne      short L_a81f
        fst      qword ptr [ebp - 0x2d0]
        mov      al, byte ptr [ebp - 0x90]
        or       al, al
        je       short L_a7fd
        cmp      al, 0xff
        je       short L_a827
        cmp      al, 0xfe
        je       short L_a827
        or       al, al
        je       short L_a81f
        movsx    eax, al
        mov      dword ptr [ebp - 0x8e], eax
        jmp      L_a899
    L_a7fd:
        mov      ax, word ptr [ebp - 0xa4]
        /* force `and ax, imm8` sign-extended form (per feedback) */
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        jne      short L_a81f
        wait
        fnstsw   ax
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a81f
        mov      dword ptr [ebp - 0x8e], 8
        jmp      short L_a899
    L_a81f:
        fldcw    word ptr [ebp - 0xa4]
        wait
        ret
    L_a827:
        mov      ax, word ptr [ebp - 0x2ca]
        and      ax, 0x7ff0
        or       ax, ax
        je       short L_a83f
        cmp      ax, 0x7ff0
        je       short L_a86d
        jmp      short L_a7fd
    L_a83f:
        mov      dword ptr [ebp - 0x8e], 4
        fld      qword ptr [g_const_004d2c18]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2c08]
        wait
        fnstsw   ax
        sahf
        jae      short L_a899
        fmul     qword ptr [g_const_004d2c28]
        jmp      short L_a899
    L_a86d:
        mov      dword ptr [ebp - 0x8e], 3
        fld      qword ptr [g_const_004d2c10]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2c00]
        wait
        fnstsw   ax
        sahf
        jbe      short L_a899
        fmul     qword ptr [g_const_004d2c20]
    L_a899:
        push     esi
        push     edi
        mov      ebx, dword ptr [ebp - 0x94]
        inc      ebx
        mov      dword ptr [ebp - 0x8a], ebx
        test     byte ptr [ebp - 0x2c8], 1
        jne      short L_a8cb
        cld
        lea      esi, [ebp + 8]
        lea      edi, [ebp - 0x86]
        movsd
        movsd
        cmp      byte ptr [ebx + 0xc], 1
        je       short L_a8cb
        lea      esi, [ebp + 0x10]
        lea      edi, [ebp - 0x7e]
        movsd
        movsd
    L_a8cb:
        fstp     qword ptr [ebp - 0x76]
        lea      eax, [ebp - 0x8e]
        lea      ebx, [ebp - 0xa4]
        push     ebx
        push     eax
        mov      ebx, dword ptr [ebp - 0x94]
        mov      al, byte ptr [ebx + 0xe]
        movsx    eax, al
        push     eax
        call     Crt_fpieee_flt
        add      esp, 0xc
        pop      edi
        pop      esi
        fld      qword ptr [ebp - 0x76]
        jmp      short L_a81f
        /* === Helper 4: 2-arg matherr (no fxch) === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        push     dword ptr [ebp + 0xc]
        push     dword ptr [ebp + 8]
        call     L_a92e
        add      esp, 8
        wait
        fnstcw   word ptr [ebp - 0xa4]
        and      byte ptr [ebp - 0x2c8], 0xfd
        call     FpExceptionFilter
        call     L_a7c3
        pop      ebx
        leave
        ret
    L_a92e:
        /* === Helper 5: denormal-handler (shifts into tbyte) === */
        push     ebp
        mov      ebp, esp
        add      esp, -0xc
        push     ebx
        mov      ax, word ptr [ebp + 0xe]
        mov      bx, ax
        and      ax, 0x7ff0
        cmp      ax, 0x7ff0
        jne      short L_a964
        or       bx, 0x7fff
        mov      word ptr [ebp - 2], bx
        mov      eax, dword ptr [ebp + 0xc]
        mov      ebx, dword ptr [ebp + 8]
        shld     eax, ebx, 0xb
        mov      dword ptr [ebp - 6], eax
        mov      dword ptr [ebp - 0xa], ebx
        fld      tbyte ptr [ebp - 0xa]
        jmp      short L_a967
    L_a964:
        fld      qword ptr [ebp + 8]
    L_a967:
        pop      ebx
        leave
        ret
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
    }
}
