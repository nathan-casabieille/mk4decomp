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

/* ============================================================
 * FileTellAdjusted - 420b boot.
 * ============================================================ */

extern void Crt_errno(void);
extern void IOWrapper_004c8dd0(void);
extern unsigned int g_arr_00fa0de0;

__declspec(naked) void FileTellAdjusted(void)
{
    __asm {
        sub      esp, 8
        push     ebx
        push     ebp
        push     esi
        mov      esi, dword ptr [esp + 0x18]
        push     edi
        mov      eax, dword ptr [esi + 4]
        mov      ebx, dword ptr [esi + 0x10]
        test     eax, eax
        jge      short L_58fc
        mov      dword ptr [esi + 4], 0
    L_58fc:
        push     1
        push     0
        push     ebx
        call     IOWrapper_004c8dd0
        mov      ecx, eax
        add      esp, 0xc
        test     ecx, ecx
        mov      dword ptr [esp + 0x14], ecx
        jge      short L_591e
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_591e:
        mov      eax, dword ptr [esi + 0xc]
        test     eax, 0x108
        jne      short L_5937
        mov      eax, ecx
        mov      ecx, dword ptr [esi + 4]
        sub      eax, ecx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_5937:
        mov      ecx, dword ptr [esi]
        mov      edi, dword ptr [esi + 8]
        mov      edx, ecx
        sub      edx, edi
        test     al, 3
        mov      dword ptr [esp + 0x10], edx
        je       L_5a66
        mov      ebp, ebx
        mov      eax, ebx
        sar      ebp, 5
        and      eax, 0x1f
        mov      ebp, dword ptr [ebp*4 + g_arr_00fa0de0]
        lea      eax, [eax + eax*8]
        test     byte ptr [ebp + eax*4 + 4], 0x80
        je       short L_597c
        mov      eax, edi
        cmp      eax, ecx
        jae      short L_597c
    L_596d:
        cmp      byte ptr [eax], 0xa
        jne      short L_5973
        inc      edx
    L_5973:
        inc      eax
        cmp      eax, ecx
        jb       short L_596d
        mov      dword ptr [esp + 0x10], edx
    L_597c:
        mov      eax, dword ptr [esp + 0x14]
        test     eax, eax
        jne      short L_598e
        mov      eax, edx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_598e:
        test     byte ptr [esi + 0xc], 1
        je       L_5a57
        mov      eax, dword ptr [esi + 4]
        test     eax, eax
        jne      short L_59b4
        mov      ecx, dword ptr [esp + 0x14]
        mov      edx, eax
        mov      dword ptr [esp + 0x10], eax
        lea      eax, [ecx + edx]
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_59b4:
        lea      esi, [ecx + eax]
        mov      ecx, ebx
        mov      eax, ebx
        sub      esi, edi
        sar      ecx, 5
        and      eax, 0x1f
        lea      ebp, [ecx*4 + g_arr_00fa0de0]
        lea      edi, [eax + eax*8]
        mov      eax, dword ptr [ebp]
        shl      edi, 2
        test     byte ptr [edi + eax + 4], 0x80
        je       short L_5a53
        push     2
        push     0
        push     ebx
        call     IOWrapper_004c8dd0
        mov      ecx, dword ptr [esp + 0x20]
        add      esp, 0xc
        cmp      eax, ecx
        jne      short L_5a12
        mov      edx, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [edx + 8]
        lea      ecx, [esi + eax]
        cmp      eax, ecx
        jae      short L_5a08
    L_59fd:
        cmp      byte ptr [eax], 0xa
        jne      short L_5a03
        inc      esi
    L_5a03:
        inc      eax
        cmp      eax, ecx
        jb       short L_59fd
    L_5a08:
        mov      eax, dword ptr [edx + 0xc]
        test     ah, 0x20
        je       short L_5a4f
        jmp      short L_5a4e
    L_5a12:
        push     0
        push     ecx
        push     ebx
        call     IOWrapper_004c8dd0
        add      esp, 0xc
        cmp      esi, 0x200
        ja       short L_5a3d
        mov      ecx, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [ecx + 0xc]
        test     al, 8
        je       short L_5a3d
        test     ah, 4
        jne      short L_5a3d
        mov      esi, 0x200
        jmp      short L_5a44
    L_5a3d:
        mov      edx, dword ptr [esp + 0x1c]
        mov      esi, dword ptr [edx + 0x18]
    L_5a44:
        mov      eax, dword ptr [ebp]
        test     byte ptr [edi + eax + 4], 4
        je       short L_5a4f
    L_5a4e:
        inc      esi
    L_5a4f:
        mov      edx, dword ptr [esp + 0x10]
    L_5a53:
        sub      dword ptr [esp + 0x14], esi
    L_5a57:
        mov      ecx, dword ptr [esp + 0x14]
        lea      eax, [ecx + edx]
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_5a66:
        test     al, 0x80
        jne      L_597c
        call     Crt_errno
        pop      edi
        pop      esi
        mov      dword ptr [eax], 0x16
        pop      ebp
        or       eax, 0xffffffff
        pop      ebx
        add      esp, 8
        ret
    }
}
