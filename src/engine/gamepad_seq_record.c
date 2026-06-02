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

extern unsigned int g_installCountdownEnd;
extern unsigned int g_dispatchCmpEnd2;
extern unsigned int g_movesPanelEnd;
extern unsigned int g_dispatchCmpEnd;
extern unsigned int g_dispatchSave1534;
extern unsigned int g_dispatchSave1535;
extern unsigned int g_dispatchSave1536;
extern unsigned int g_dispatchSave1537;
extern unsigned int g_dispatchSave1538;
extern unsigned int g_dispatchSave1539;

__declspec(naked) void GamepadSeqRecord(void)
{
    __asm {
        push     esi
        call     Renderer_GetMode
        mov      esi, 2
        cmp      eax, esi
        je       L_cd96
        call     Renderer_GetMode
        cmp      eax, 1
        je       L_cd96
        mov      eax, dword ptr [esp + 0xc]
        test     eax, eax
        mov      eax, dword ptr [esp + 8]
        jne      L_cd11
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_ccbe
        inc      word ptr [g_dispatchSave1534]
        mov      ecx, 3
        add      word ptr [g_dispatchSave1536], cx
        add      word ptr [g_dispatchSave1538], cx
    L_ccbe:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_ccd3
        add      word ptr [g_dispatchSave1536], si
        add      word ptr [g_dispatchSave1538], si
    L_ccd3:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_ccf6
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1539]
    L_ccf6:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        inc      word ptr [g_dispatchSave1534]
        add      word ptr [g_dispatchSave1536], si
        jmp      L_cd7f
    L_cd11:
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_cd2e
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        add      word ptr [g_dispatchSave1538], 3
    L_cd2e:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_cd3c
        add      word ptr [g_dispatchSave1538], si
    L_cd3c:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_cd66
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      word ptr [g_dispatchSave1537]
        inc      word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1539]
    L_cd66:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
    L_cd7f:
        inc      word ptr [g_dispatchSave1537]
        add      word ptr [g_dispatchSave1538], si
        inc      word ptr [g_dispatchSave1539]
        pop      esi
        ret
    L_cd96:
        mov      eax, dword ptr [esp + 0xc]
        mov      edx, 0xfffffffe
        test     eax, eax
        mov      eax, dword ptr [esp + 8]
        jne      L_ce8c
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_cde8
        mov      cx, word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1534]
        add      word ptr [g_dispatchSave1535], dx
        add      word ptr [g_dispatchSave1536], si
        add      word ptr [g_dispatchSave1537], dx
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
        jmp      L_cdef
    L_cde8:
        mov      cx, word ptr [g_dispatchSave1538]
    L_cdef:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_ce1c
        add      word ptr [g_dispatchSave1535], dx
        add      word ptr [g_dispatchSave1536], si
        add      word ptr [g_dispatchSave1537], dx
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
    L_ce1c:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_ce3a
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      cx
        mov      word ptr [g_dispatchSave1538], cx
    L_ce3a:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        mov      dx, word ptr [g_dispatchSave1534]
        add      cx, si
        dec      dx
        add      word ptr [g_dispatchSave1536], si
        mov      word ptr [g_dispatchSave1534], dx
        mov      word ptr [g_dispatchSave1538], cx
        movsx    eax, cx
        movsx    edx, dx
        sub      eax, edx
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 3
        jg       L_cf5c
        mov      word ptr [g_dispatchSave1536], cx
        mov      word ptr [g_dispatchSave1534], cx
        pop      esi
        ret
    L_ce8c:
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_cec9
        mov      cx, word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1534]
        add      word ptr [g_dispatchSave1535], dx
        inc      word ptr [g_dispatchSave1536]
        dec      word ptr [g_dispatchSave1537]
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
        jmp      L_ced0
    L_cec9:
        mov      cx, word ptr [g_dispatchSave1538]
    L_ced0:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_cef6
        add      word ptr [g_dispatchSave1535], dx
        dec      word ptr [g_dispatchSave1537]
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
    L_cef6:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_cf14
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      cx
        mov      word ptr [g_dispatchSave1538], cx
    L_cf14:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        mov      dx, word ptr [g_dispatchSave1534]
        add      cx, si
        dec      dx
        dec      word ptr [g_dispatchSave1536]
        mov      word ptr [g_dispatchSave1534], dx
        mov      word ptr [g_dispatchSave1538], cx
        movsx    eax, cx
        movsx    edx, dx
        sub      eax, edx
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 3
        jg       L_cf5c
        mov      word ptr [g_dispatchSave1536], cx
        mov      word ptr [g_dispatchSave1534], cx
    L_cf5c:
        pop      esi
        ret
    }
}
