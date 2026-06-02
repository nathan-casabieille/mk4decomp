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

extern void CrtInitPerThreadData(void);
extern void ArraySearch(void);
extern unsigned int g_crtSehFpuDispatch;
extern unsigned int g_crtSehFpuDispatch2_005228fc;
extern unsigned int g_iat_UnhandledExceptionFilter;

__declspec(naked) void SehFpuExceptionDispatch(void)
{
    __asm {
        push     ecx
        push     ebx
        push     ebp
        push     esi
        push     edi
        call     CrtInitPerThreadData
        mov      ecx, dword ptr [esp + 0x18]
        mov      esi, eax
        mov      eax, dword ptr [esi + 0x50]
        push     eax
        push     ecx
        call     ArraySearch
        xor      edi, edi
        add      esp, 8
        cmp      eax, edi
        je       L_ba7c
        mov      edx, dword ptr [eax + 8]
        cmp      edx, edi
        mov      dword ptr [esp + 0x18], edx
        je       L_ba7c
        cmp      edx, 5
        jne      short L_b8c9
        mov      dword ptr [eax + 8], edi
        mov      eax, 1
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b8c9:
        cmp      edx, 1
        jne      short L_b8d7
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b8d7:
        mov      ecx, dword ptr [esi + 0x54]
        mov      dword ptr [esp + 0x10], ecx
        mov      ecx, dword ptr [esp + 0x1c]
        mov      dword ptr [esi + 0x54], ecx
        mov      ecx, dword ptr [eax + 4]
        cmp      ecx, 8
        jne      L_ba63
        mov      ecx, dword ptr [g_crtSehFpuDispatch]
        mov      ebx, dword ptr [g_crtSehFpuDispatch2_005228fc]
        add      ebx, ecx
        cmp      ecx, ebx
        jge      short L_b92a
        lea      edx, [ecx + ecx*2]
        shl      edx, 2
    L_b909:
        mov      ebx, dword ptr [esi + 0x50]
        inc      ecx
        mov      dword ptr [ebx + edx + 8], edi
        mov      ebx, dword ptr [g_crtSehFpuDispatch]
        mov      ebp, dword ptr [g_crtSehFpuDispatch2_005228fc]
        add      edx, 0xc
        add      ebp, ebx
        cmp      ecx, ebp
        jl       short L_b909
        mov      edx, dword ptr [esp + 0x18]
    L_b92a:
        mov      eax, dword ptr [eax]
        mov      edi, dword ptr [esi + 0x58]
        cmp      eax, 0xc000008e
        jne      short L_b95b
        mov      dword ptr [esi + 0x58], 0x83
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b95b:
        cmp      eax, 0xc0000090
        jne      short L_b987
        mov      dword ptr [esi + 0x58], 0x81
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b987:
        cmp      eax, 0xc0000091
        jne      short L_b9b3
        mov      dword ptr [esi + 0x58], 0x84
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b9b3:
        cmp      eax, 0xc0000093
        jne      short L_b9df
        mov      dword ptr [esi + 0x58], 0x85
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b9df:
        cmp      eax, 0xc000008d
        jne      short L_ba0b
        mov      dword ptr [esi + 0x58], 0x82
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba0b:
        cmp      eax, 0xc000008f
        jne      short L_ba37
        mov      dword ptr [esi + 0x58], 0x86
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba37:
        cmp      eax, 0xc0000092
        jne      short L_ba45
        mov      dword ptr [esi + 0x58], 0x8a
    L_ba45:
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba63:
        push     ecx
        mov      dword ptr [eax + 8], edi
        call     edx
        mov      ecx, dword ptr [esp + 0x14]
        add      esp, 4
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba7c:
        mov      edx, dword ptr [esp + 0x1c]
        push     edx
        call     dword ptr [g_iat_UnhandledExceptionFilter]
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    }
}
