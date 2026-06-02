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

extern unsigned int g_crtFpuTbyte;
extern unsigned int g_dispatchSave112;
extern unsigned int g_crtFpuExceptionBase;

__declspec(naked) void FpExceptionFilter(void)
{
    __asm {
    /* Entry A: single-operand */
        cmp      byte ptr [edx + 0xe], 5
        jne      short L_a097
        mov      bx, word ptr [ebp - 0xa4]
        or       bh, 2
        and      bh, 0xfe
        mov      bl, 0x3f
        jmp      short L_a09b
    L_a097:
        mov      bx, 0x133f
    L_a09b:
        mov      word ptr [ebp - 0xa2], bx
        fldcw    word ptr [ebp - 0xa2]
        mov      ebx, OFFSET g_crtFpuExceptionBase
        fxam
        mov      dword ptr [ebp - 0x94], edx
        wait
        fnstsw   word ptr [ebp - 0xa0]
        mov      byte ptr [ebp - 0x90], 0
        wait
        mov      cl, byte ptr [ebp - 0x9f]
        shl      cl, 1
        sar      cl, 1
        rol      cl, 1
        mov      al, cl
        and      al, 0xf
        xlatb
        movsx    eax, al
        and      ecx, 0x404
        mov      ebx, edx
        add      ebx, eax
        add      ebx, 0x10
        jmp      dword ptr [ebx]
    /* Entry B: dual-operand */
        cmp      byte ptr [edx + 0xe], 5
        jne      short L_a0fe
        mov      bx, word ptr [ebp - 0xa4]
        or       bh, 2
        and      bh, 0xfe
        mov      bl, 0x3f
        jmp      short L_a102
    L_a0fe:
        mov      bx, 0x133f
    L_a102:
        mov      word ptr [ebp - 0xa2], bx
        fldcw    word ptr [ebp - 0xa2]
        mov      ebx, OFFSET g_crtFpuExceptionBase
        fxam
        mov      dword ptr [ebp - 0x94], edx
        wait
        fnstsw   word ptr [ebp - 0xa0]
        mov      byte ptr [ebp - 0x90], 0
        fxch     st(1)
        mov      cl, byte ptr [ebp - 0x9f]
        fxam
        wait
        fnstsw   word ptr [ebp - 0xa0]
        fxch     st(1)
        mov      ch, byte ptr [ebp - 0x9f]
        shl      ch, 1
        sar      ch, 1
        rol      ch, 1
        mov      al, ch
        and      al, 0xf
        xlatb
        mov      ah, al
        shl      cl, 1
        sar      cl, 1
        rol      cl, 1
        mov      al, cl
        and      al, 0xf
        xlatb
        shl      ah, 1
        shl      ah, 1
        or       al, ah
        movsx    eax, al
        and      ecx, 0x404
        mov      ebx, edx
        add      ebx, eax
        add      ebx, 0x10
        jmp      dword ptr [ebx]
    /* Sub-handlers (each its own dispatch target). */
        call     L_a239
        fxch     st(1)
    L_a17a:
        fstp     st(0)
        ret
        call     L_a239
        jmp      short L_a17a
        fstp     st(0)
        fstp     st(0)
        fldz
        ret
        fstp     st(0)
        fstp     st(0)
        fld1
        ret
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a1af
        mov      byte ptr [ebp - 0x90], 7
        ret
    L_a1af:
        mov      byte ptr [ebp - 0x90], 1
        fadd     qword ptr [g_dispatchSave112]
        ret
        fxch     st(1)
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a1dd
        mov      byte ptr [ebp - 0x90], 7
        jmp      short L_a1e4
    L_a1dd:
        mov      byte ptr [ebp - 0x90], 1
    L_a1e4:
        faddp    st(1), st
        ret
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a21c
        fxch     st(1)
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a21c
        mov      byte ptr [ebp - 0x90], 7
        jmp      short L_a223
    L_a21c:
        mov      byte ptr [ebp - 0x90], 1
    L_a223:
        faddp    st(1), st
        ret
        fstp     st(0)
        fstp     st(0)
        fld      tbyte ptr [g_crtFpuTbyte]
        cmp      byte ptr [ebp - 0x90], 0
        jg       short L_a240
    L_a239:
        mov      byte ptr [ebp - 0x90], 1
    L_a240:
        or       cl, cl
        ret
        or       cl, cl
        je       short L_a249
        fchs
    L_a249:
        ret
        int      3
        int      3
        int      3
        int      3
        int      3
        int      3
    }
}
