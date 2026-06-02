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
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
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

extern void CrtFpieeeFlt(void);
extern void CrtFpuExceptionFilter(void);
extern void SwitchErrorCode(void);
/* extern void RetZero_004cf700(void); -- defined elsewhere with diff sig */
extern void FpuMaskMerge(void);
extern unsigned int g_crtFpuExceptionMask;

extern void RetZero_004cf700(void);

__declspec(naked) void Crt_fpieee_flt(void)
{
    __asm {
        sub      esp, 0x58
        mov      ecx, dword ptr [esp + 0x64]
        push     ebx
        push     esi
        mov      esi, dword ptr [esp + 0x68]
        xor      eax, eax
        push     edi
        mov      ax, word ptr [ecx]
        mov      ecx, dword ptr [esi]
        dec      ecx
        mov      dword ptr [esp + 0x70], eax
        cmp      ecx, 7
        ja       short L_ddb0
        jmp      dword ptr [ecx*4 + L_d20_jmptbl]
    L_dd46:
        mov      edi, 8
    L_dd4b:
        lea      ebx, [esi + 0x18]
        push     eax
        push     ebx
        push     edi
        call     CrtFpuExceptionFilter
        add      esp, 0xc
        test     eax, eax
        jne      short L_ddac
        mov      eax, dword ptr [esp + 0x68]
        cmp      eax, 0x10
        je       short L_dd77
        cmp      eax, 0x16
        je       short L_dd77
        cmp      eax, 0x1d
        je       short L_dd77
        and      dword ptr [esp + 0x44], 0xfffffffe
        jmp      short L_dd93
    L_dd77:
        mov      edx, dword ptr [esp + 0x44]
        mov      ecx, dword ptr [esi + 0x10]
        and      edx, 0xffffffe3
        mov      dword ptr [esp + 0x34], ecx
        or       edx, 3
        mov      dword ptr [esp + 0x44], edx
        mov      edx, dword ptr [esi + 0x14]
        mov      dword ptr [esp + 0x38], edx
    L_dd93:
        lea      ecx, [esi + 8]
        push     ebx
        push     ecx
        push     eax
        lea      edx, [esp + 0x7c]
        push     edi
        lea      eax, [esp + 0x1c]
        push     edx
        push     eax
        call     CrtFpieeeFlt
        add      esp, 0x18
    L_ddac:
        mov      eax, dword ptr [esp + 0x70]
    L_ddb0:
        push     0xffff
        push     eax
        call     FpuMaskMerge
        mov      ecx, dword ptr [esi]
        add      esp, 8
        xor      eax, eax
        cmp      ecx, 8
        je       short L_ddda
        mov      ecx, dword ptr [g_crtFpuExceptionMask]
        test     ecx, ecx
        jne      short L_ddda
        push     esi
        call     RetZero_004cf700
        add      esp, 4
    L_ddda:
        test     eax, eax
        jne      short L_dde9
        mov      ecx, dword ptr [esi]
        push     ecx
        call     SwitchErrorCode
        add      esp, 4
    L_dde9:
        pop      edi
        pop      esi
        pop      ebx
        add      esp, 0x58
        ret
    L_ddf0:
        mov      edi, 0x11
        jmp      L_dd4b
    L_ddfa:
        mov      edi, 0x12
        jmp      L_dd4b
    L_de04:
        mov      edi, 4
        jmp      L_dd4b
    L_de0e:
        mov      edi, 0x10
        jmp      L_dd4b
    L_de18:
        mov      dword ptr [esi], 1
        jmp      short L_ddb0
    L_d20_jmptbl:
        _emit 0x46
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0x04
        _emit 0xde
        _emit 0x4c
        _emit 0x00
        _emit 0xf0
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0xfa
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0x46
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0xb0
        _emit 0xdd
        _emit 0x4c
        _emit 0x00
        _emit 0x18
        _emit 0xde
        _emit 0x4c
        _emit 0x00
        _emit 0x0e
        _emit 0xde
        _emit 0x4c
        _emit 0x00
    }
}
