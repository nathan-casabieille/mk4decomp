/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
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
extern void PendingMatch_StoreTwoCall_0042b930(void);
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

/* @addr 0x004b9640 (301b engine.render) - vibration/feedback frame update.
 *   Reads g_fightGroupHead & 0x180000; if both bits 0, skip. Else loads
 *   [esp+0x14] as `i`; if [i*4+0x1c]==-20, set i=2. Validate i in [1,0x18].
 *   Lookup pattern entry at [i*4 + g_dispatchSave554]; bail if 0x10000.
 *   If i==2: load FP, fadd to g_fpuConst, fcomp 0x004d2a00; if FP overflow,
 *     re-init constants to 0x3fec_cccccccd / 0x3f90_624d_d2f1_a9fc.
 *   Else: check fcomp 0x004d2a10; if outside range, re-init to 0x3ff1_9999_9999_999a
 *     / 0xbf78_9374_bc6a_7efa.
 *   Convert via DoubleToInt64, write to g_walkCallback, shift right by 4,
 *   call Transform9Words(esi, &local); OR bit 0x30 of high byte of g_xformDirtyFlags.
 */
extern unsigned int g_dispatchSave887;
extern unsigned int g_dispatchSave888;
extern unsigned int g_dispatchSave554;
extern unsigned int g_fpuConst;
extern unsigned int g_dispatchSave553;
extern unsigned int g_dispatchSave502;
extern unsigned int g_dispatchSave552;
extern void DoubleToInt64(void);
extern void Transform9Words(void);

__declspec(naked) void VibrationFrameUpdate(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        sub     esp, 0x0c
        test    eax, 0x180000
        push    esi
        jz      L_vfu_done
        mov     eax, [esp + 0x14]
        mov     ecx, dword ptr [eax*4 + 0x1c]
        cmp     ecx, -0x14
        jne     short L_vfu_chk
        mov     ecx, 2
    L_vfu_chk:
        test    ecx, ecx
        jle     L_vfu_done
        cmp     ecx, 0x18
        jg      L_vfu_done
        mov     eax, dword ptr [ecx*4 + g_dispatchSave554]
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        jz      L_vfu_done
        mov     edx, dword ptr [g_pendingNodeType]
        cmp     ecx, 2
        lea     esi, [edx*4]
        jne     L_vfu_pathB_sar
        fld     qword ptr [g_dispatchSave502]
        fadd    qword ptr [g_fpuConst]
        fst     qword ptr [g_fpuConst]
        fcomp   qword ptr [g_dispatchSave887]
        fnstsw  ax
        test    ah, 1
        jz      short L_vfu_skipReinitA
        mov     dword ptr [g_fpuConst], 0xcccccccd
        mov     dword ptr [g_dispatchSave553], 0x3feccccc
        mov     dword ptr [g_dispatchSave502], 0xd2f1a9fc
        mov     dword ptr [g_dispatchSave552], 0x3f90624d
    L_vfu_skipReinitA:
        fld     qword ptr [g_fpuConst]
        fcomp   qword ptr [g_dispatchSave888]
        fnstsw  ax
        test    ah, 0x41
        jne     short L_vfu_doConv
        mov     dword ptr [g_fpuConst], 0x9999999a
        mov     dword ptr [g_dispatchSave553], 0x3ff19999
        mov     dword ptr [g_dispatchSave502], 0xbc6a7efa
        mov     dword ptr [g_dispatchSave552], 0xbf789374
    L_vfu_doConv:
        fild    dword ptr [g_walkCallback]
        fmul    qword ptr [g_fpuConst]
        call    DoubleToInt64
        mov     dword ptr [g_walkCallback], eax
    L_vfu_pathB_sar:
        sar     eax, 4
        mov     [esp + 0x0c], eax
        mov     [esp + 0x08], eax
        mov     [esp + 0x04], eax
        lea     eax, [esp + 4]
        push    eax
        push    esi
        call    Transform9Words
        mov     eax, dword ptr [g_xformDirtyFlags]
        add     esp, 8
        or      al, 0x30
        mov     dword ptr [g_xformDirtyFlags], eax
    L_vfu_pathB:
    L_vfu_done:
        pop     esi
        add     esp, 0x0c
        ret
    }
}
