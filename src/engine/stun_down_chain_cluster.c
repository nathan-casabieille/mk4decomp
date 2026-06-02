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

extern void StoreLoadJmp(void);
extern void ChainDirtyBitWalker(void);
extern void Chain2AxisDiffStoreTailJmp(void);
extern void MStackPush3SideStore(void);
extern void StunDownChainCluster(void);
extern void func_0045231b(void);
extern void DualScaledStore(void);
extern void PendingMatch_00452770(void);
extern void DualPushSet7dCallPop(void);
extern void Thunk_ScaledNeg1SetPause(void);
extern unsigned int g_dispatchSave688;

__declspec(naked) void StunDownCluster(void)
{
    __asm {
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueEnd], eax
        jl       L_2054
    L_1fdc:
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2054
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      edx, OFFSET g_dispatchSave688
        shr      edx, 2
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_eventQueueEnd], eax
        mov      eax, dword ptr [g_xformEntityIdx]
        add      eax, 0xf
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_eventQueueIdx], eax
    L_201d:
        call     DualPushSet7dCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2054
        mov      eax, dword ptr [g_eventQueueTotal]
        dec      eax
        mov      dword ptr [g_eventQueueTotal], eax
        jns      L_201d
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueEnd], eax
        jge      L_1fdc
    L_2054:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop
    L_2060:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 7
        ja       L_22da
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_208d:
        mov      dword ptr [g_eventQueueEnd], 0x4f
        mov      dword ptr [g_xformScratch2088], 0xfffffeb9
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_2060
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x2000000
        jmp      L_223b
    L_20d1:
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x50
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_20f9:
        push     OFFSET StunDownChainCluster + 0x380
        call     StoreLoadJmp
        mov      dword ptr [g_eventQueueEnd], 0x22
        mov      dword ptr [g_xformScratch2088], 0xfffffeb9
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_2060
        add      esp, 4
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x4000000
        jmp      L_223b
    L_214a:
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 0xc8
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_2172:
        mov      dword ptr [g_eventQueueEnd], 0x1e
        mov      dword ptr [g_xformScratch2088], 0xfffffd71
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_2060
        mov      dword ptr [ecx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x6000000
        jmp      L_223b
    L_21b6:
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      dword ptr [esi + 0x84], 7
        mov      dword ptr [g_pendingNodeType], 0x1e
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_21de:
        call     PendingMatch_00452770
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_22df
        push     OFFSET StunDownChainCluster + 0x80
        call     StoreLoadJmp
        mov      dword ptr [g_eventQueueEnd], 0x4b
        mov      dword ptr [g_xformScratch2088], 0x28f
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_2060
        add      esp, 4
        mov      dword ptr [ecx*4 + 0x84], 8
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      edx, 0x8000000
    L_223b:
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     StunDownChainCluster
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_226e:
        push     OFFSET StunDownChainCluster + 0x2d0
        call     StoreLoadJmp
        add      esp, 4
        call     DualScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_22df
        call     Chain2AxisDiffStoreTailJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_22df
        mov      dword ptr [g_eventQueueWorkType], 0xe666
        mov      dword ptr [g_walkCallback], 0xfffe7334
        call     MStackPush3SideStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_22df
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_2060
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x28
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret      
    L_22da:
        call     Thunk_ScaledNeg1SetPause
    L_22df:
        pop      edi
        pop      esi
        ret
        _emit 0x8b
        _emit 0xff
    L_jmptbl:
        _emit 0x6e
        _emit 0x22
        _emit 0x45
        _emit 0x00
        _emit 0x8d
        _emit 0x20
        _emit 0x45
        _emit 0x00
        _emit 0xd1
        _emit 0x20
        _emit 0x45
        _emit 0x00
        _emit 0xf9
        _emit 0x20
        _emit 0x45
        _emit 0x00
        _emit 0x4a
        _emit 0x21
        _emit 0x45
        _emit 0x00
        _emit 0x72
        _emit 0x21
        _emit 0x45
        _emit 0x00
        _emit 0xb6
        _emit 0x21
        _emit 0x45
        _emit 0x00
        _emit 0xde
        _emit 0x21
        _emit 0x45
        _emit 0x00
    }
}
