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

extern void CallPauseTestByte4ZeroCB(void);
extern void SetJmp_SetJmp_00451ad0_00451aa0(void);
extern void SetJmp_SetJmp_00451ad0_00451ab0(void);
extern void SetJmp_SetJmp_00451ad0_00451ac0(void);
extern void SetJmp_SetJmp_00451b10_00451ae0(void);
extern void SetJmp_SetJmp_00451b10_00451af0(void);
extern void SetJmp_SetJmp_00451b10_00451b00(void);
extern void SetJmp_SetJmp_00451b50_00451b20(void);
extern void SetJmp_SetJmp_00451b50_00451b30(void);
extern void SetJmp_SetJmp_00451b50_00451b40(void);
extern void SetJmp_JuggleFsmCluster_00451b60(void);
extern void SetJmp_JuggleFsmCluster_00451b70(void);
extern void SetJmp_JuggleFsmCluster_00451b80(void);

__declspec(naked) void State6CycleFsm(void)
{
    __asm {
    L_17e0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 5
        ja       L_1a40
        jmp      dword ptr [eax*4 + L_jmptbl_1a48]
    L_180e:
        /* case 1 (state 1 → 2) */
        call     CallPauseTestByte4ZeroCB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_184d
        call     SetJmp_SetJmp_00451ad0_00451ab0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
        call     SetJmp_SetJmp_00451b10_00451af0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
    L_184d:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_17e0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_186f:
        /* case 2 (state 2 → 3) */
        call     CallPauseTestByte4ZeroCB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_18ae
        call     SetJmp_SetJmp_00451ad0_00451ac0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
        call     SetJmp_SetJmp_00451b10_00451b00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
    L_18ae:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_17e0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_18d0:
        /* case 3 (state 3 → 4) */
        call     CallPauseTestByte4ZeroCB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_190f
        call     SetJmp_SetJmp_00451b50_00451b20
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
        call     SetJmp_JuggleFsmCluster_00451b60
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
    L_190f:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_17e0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_1931:
        /* case 4 (state 4 → 5) */
        call     CallPauseTestByte4ZeroCB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1a45
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_1970
        call     SetJmp_SetJmp_00451b50_00451b30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
        call     SetJmp_JuggleFsmCluster_00451b70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
    L_1970:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_17e0
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_1992:
        /* case 5 (state 5 → 6) */
        call     CallPauseTestByte4ZeroCB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_19cd
        call     SetJmp_SetJmp_00451b50_00451b40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
        call     SetJmp_JuggleFsmCluster_00451b80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
    L_19cd:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_17e0
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_19ef:
        /* case 0 (state 0 → 1) */
        call     CallPauseTestByte4ZeroCB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_1a22
        call     SetJmp_SetJmp_00451ad0_00451aa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
        call     SetJmp_SetJmp_00451b10_00451ae0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1a45
    L_1a22:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_17e0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_1a40:
        call     StackPopDispatchTagged
    L_1a45:
        pop      esi
        ret
        nop
    L_jmptbl_1a48:
        /* 6 absolute-address entries (no reloc - orig has DIR32 reloc;
           literal bytes match link-time addresses) */
        _emit 0xef
        _emit 0x19
        _emit 0x45
        _emit 0x00
        _emit 0x0e
        _emit 0x18
        _emit 0x45
        _emit 0x00
        _emit 0x6f
        _emit 0x18
        _emit 0x45
        _emit 0x00
        _emit 0xd0
        _emit 0x18
        _emit 0x45
        _emit 0x00
        _emit 0x31
        _emit 0x19
        _emit 0x45
        _emit 0x00
        _emit 0x92
        _emit 0x19
        _emit 0x45
        _emit 0x00
    }
}
