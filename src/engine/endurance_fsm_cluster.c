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

extern unsigned int g_dispatchSave921;
extern void BootInitGuardedCallChain(void);
extern void BootMultiAssetLoadStateInit(void);
extern void CallSetPause(void);
extern void InstallSelfPackedF80(void);
extern void MStackCall_00406740(void);
extern void TableWalkBoundedCmp(void);

__declspec(naked) void EnduranceFsmCluster(void)
{
    __asm {
        /* === Helper 1 (0x4238e0): 4-state FSM w/ jump table === */
    L_38e0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_3a64
        jmp      dword ptr [eax*4 + L_jmptbl_3a78]
    L_390d:
        /* case 2: bump counter */
        mov      eax, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_eventQueueIdx], eax
        jmp      short L_39c9
    L_391d:
        /* case 3: state-4 install-self */
        mov      eax, 4
        mov      edx, OFFSET L_38e0
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      ecx, dword ptr [g_baseSel]
        add      edx, 0x4000000
        mov      dword ptr [ecx*4 + 0x84], eax
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelfPackedF80
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3981:
        /* case 0: initial → walk table */
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3a73
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_active_0053a408], edi
        mov      dword ptr [g_active_00537e88], edi
        call     BootMultiAssetLoadStateInit
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3a73
        mov      eax, OFFSET g_dispatchSave921
        shr      eax, 2
        mov      dword ptr [g_eventQueueIdx], eax
        jmp      short L_39c9
    L_39c4:
        /* case 1: load from saved table-index, then walk */
        mov      eax, dword ptr [g_eventQueueIdx]
    L_39c9:
        mov      ecx, dword ptr [eax*4]
        cmp      ecx, edi
        mov      dword ptr [g_walkCallback], ecx
        jge      short L_3a02
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x168
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3a02:
        mov      edi, 1
        cmp      ecx, edi
        je       short L_3a3e
        push     0x17
        push     OFFSET L_3a90
        call     StoreTwoCall
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      dword ptr [esi + 0x84], 2
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], 0x12
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_3a3e:
        inc      eax
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [esi + 8], OFFSET L_38e0
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], 0x32
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_3a64:
        push     9
        call     TableWalkBoundedCmp
        add      esp, 4
        call     StackPopDispatchTagged
    L_3a73:
        pop      edi
        pop      esi
        ret
        mov      edi, edi
    L_jmptbl_3a78:
        /* 4 absolute-address entries */
        _emit 0x81
        _emit 0x39
        _emit 0x42
        _emit 0x00
        _emit 0xc4
        _emit 0x39
        _emit 0x42
        _emit 0x00
        _emit 0x0d
        _emit 0x39
        _emit 0x42
        _emit 0x00
        _emit 0x1d
        _emit 0x39
        _emit 0x42
        _emit 0x00
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x423a90): wait-then-end-of-round FSM === */
    L_3a90:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_3ae8
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x58]
        cmp      eax, 0xff060000
        mov      dword ptr [g_walkCallback], eax
        jg       L_3b5d
        call     MStackCall_00406740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b79
        call     CallSetPause
        pop      esi
        ret
    L_3ae8:
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [edx*4]
        mov      dword ptr [g_walkCallback], 0xa
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_acc_00542078], 0
        mov      dword ptr [g_eventQueueNotMask], 0xfa0000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3b79
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x5c], 0x10000
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, 0xfffe1000
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x70], ecx
    L_3b5d:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3a90
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_3b79:
        pop      esi
        ret
    }
}
