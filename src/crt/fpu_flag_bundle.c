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

/* @addr 0x004cf770 (270b crt) - bundled fpenv-flag-based loader + slot manager.
 *   Sub-1 (89b): conditional FPU loads/stores from tbyte constants based on cl
 *     flag bits 1, 8, 0x10, 4, 0x20. Sub-2 (174b): per-thread slot management.
 *   For consolidation, both bundled into one 270-byte symbol entry.
 */
extern unsigned int g_crtFpuTbyteVar;
extern unsigned int g_crtFpuTbyteVar2;
extern unsigned int g_crtFpuStateBuf;
extern unsigned int g_crtFpuStack;
extern unsigned int g_dispatchSave1447;
extern unsigned int g_dispatchSave1455;
extern void Calloc(void);
extern void CrtInitLocaleInfo(void);
extern void CrtLocaleInfoFreeAll(void);
extern void FreeImpl(void);

__declspec(naked) void FpuFlagBundle(void) {
    __asm {
        /* sub-1: FPU flag-driven constant loader (0x4cf770..0x4cf7c8) */
        push    ebp
        mov     ebp, esp
        sub     esp, 8
        mov     cl, byte ptr [ebp + 8]
        test    cl, 1
        jz      short L_fp1
        fld     tbyte ptr [g_crtFpuTbyteVar]
        fistp   dword ptr [ebp + 8]
        fwait
    L_fp1:
        test    cl, 8
        jz      short L_fp2
        fwait
        fnstsw  ax
        fld     tbyte ptr [g_crtFpuTbyteVar]
        fstp    qword ptr [ebp - 8]
        fwait
        fwait
        fnstsw  ax
    L_fp2:
        test    cl, 0x10
        jz      short L_fp3
        fld     tbyte ptr [g_crtFpuTbyteVar2]
        fstp    qword ptr [ebp - 8]
        fwait
    L_fp3:
        test    cl, 4
        jz      short L_fp4
        fldz
        fld1
        fdivrp  st(1), st(0)
        fstp    st(0)
        fwait
    L_fp4:
        test    cl, 0x20
        jz      short L_fp5
        fldpi
        fstp    qword ptr [ebp - 8]
        fwait
    L_fp5:
        mov     esp, ebp
        pop     ebp
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        /* sub-2: slot management (0x4cf7d0..0x4cf87d) */
        mov     eax, dword ptr [g_dispatchSave1447]
        push    esi
        test    eax, eax
        jz      short L_sm_clearPath
        push    0xac
        push    1
        call    Calloc
        mov     esi, eax
        add     esp, 8
        test    esi, esi
        jne     short L_sm_install
        mov     eax, 1
        pop     esi
        ret
    L_sm_install:
        push    esi
        call    CrtInitLocaleInfo
        add     esp, 4
        test    eax, eax
        jz      short L_sm_storePath
        push    esi
        call    CrtLocaleInfoFreeAll
        add     esp, 4
        push    esi
        call    FreeImpl
        add     esp, 4
        mov     eax, 1
        pop     esi
        ret
    L_sm_storePath:
        mov     eax, dword ptr [g_dispatchSave1455]
        mov     dword ptr [g_crtFpuStack], esi
        push    eax
        call    CrtLocaleInfoFreeAll
        mov     ecx, dword ptr [g_dispatchSave1455]
        add     esp, 4
        push    ecx
        call    FreeImpl
        add     esp, 4
        mov     dword ptr [g_dispatchSave1455], esi
        xor     eax, eax
        pop     esi
        ret
    L_sm_clearPath:
        mov     edx, dword ptr [g_dispatchSave1455]
        mov     dword ptr [g_crtFpuStack], offset g_crtFpuStateBuf
        push    edx
        call    CrtLocaleInfoFreeAll
        mov     eax, dword ptr [g_dispatchSave1455]
        add     esp, 4
        push    eax
        call    FreeImpl
        add     esp, 4
        mov     dword ptr [g_dispatchSave1455], 0
        xor     eax, eax
        pop     esi
        ret
    }
}
