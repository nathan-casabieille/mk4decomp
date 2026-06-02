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

/* ------------------------------------------------------------------ */
/* Throw event cluster (799b game, 3 packed helpers + 4-case jmp tbl):*/
/*  h1 (0x43e960): inner state save + set [+0x2c]=0x578d + 00408c10.  */
/*  h2 (0x43ea00): pose-fn 4-case dispatch (jmp table at 0x43ebc8)    */
/*    each case installs next state via 0043f3a0/43ede0/43f2c0/copy. */
/*  h3 (0x43ebe0): pose-fn 2-state w/ 0x7ae increment + 00476af0.     */
/* ------------------------------------------------------------------ */
extern void DispatchCopyFields(void);
extern void StackPushCallPopChain(void);
extern void TagTeamHandlerCluster(void);
extern void InstallSelfChainStateInit(void);
extern void ComboMenuFsmCluster(void);
extern unsigned int g_pendingMatchAudio2;

extern unsigned int g_load_0052ab10;
extern void MStackAngleRatioSubchain(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void ThrowEventCluster(void)
{
    __asm {
        /* === h1 (0x43e960): inner state save + 00408c10 === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_xformEntityIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_pendingMatchAudio2]
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_walkCallback], 1
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_e9f4
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, 0x578d
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x2c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_e9f4:
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
        /* === h2 (0x43ea00): pose-fn 4-case dispatch === */
    L_ea00:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_ebbe
        jmp      dword ptr [eax*4 + L_jmptbl_ebc8]
    L_ea2d:
        /* case 1: 43ec80 + install state 2 */
        call     DispatchCopyFields
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_ebc3
        mov      dword ptr [esi + 8], OFFSET L_ea00
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_ea00
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ComboMenuFsmCluster
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_ea9c:
        /* case 2: set 0054205c, 43ed70, install state 3 */
        mov      ecx, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_fightGroupHead], ecx
        call     StackPushCallPopChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_ebc3
        mov      dword ptr [esi + 8], OFFSET L_ea00
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_ea00
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x3000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     TagTeamHandlerCluster
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_eb18:
        /* case 3: install state 4 + 43f2c0 */
        mov      dword ptr [esi + 8], OFFSET L_ea00
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_ea00
        mov      dword ptr [eax*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x4000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfChainStateInit
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_eb76:
        /* case 0: copy params, install state 1 */
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_ea00
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x3d
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_ebbe:
        call     Thunk_ScaledNeg1SetPause
    L_ebc3:
        pop      edi
        pop      esi
        ret
        /* 1-byte nop pad: 8b ff (mov edi, edi - 2 bytes) wait would be wrong size */
        _emit    0x8b
        _emit    0xff
        /* hmm need to dump exact orig bytes between L_ebc3 ret and table 0x43ebc8 */
    L_jmptbl_ebc8:
        /* 4-entry jump table */
        _emit    0x76  /* case 0 -> 0x43eb76 */
        _emit    0xeb
        _emit    0x43
        _emit    0x00
        _emit    0x2d  /* case 1 -> 0x43ea2d */
        _emit    0xea
        _emit    0x43
        _emit    0x00
        _emit    0x9c  /* case 2 -> 0x43ea9c */
        _emit    0xea
        _emit    0x43
        _emit    0x00
        _emit    0x18  /* case 3 -> 0x43eb18 */
        _emit    0xeb
        _emit    0x43
        _emit    0x00
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x43ebe0): pose-fn 2-state w/ 0x7ae inc === */
    L_ebe0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_ec0e
        add      dword ptr [g_currentNodeFlags], 0x7ae
        jmp      short L_ec49
    L_ec0e:
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [eax*4 + 0x68], ecx
        mov      edx, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_currentNodeFlags], 0x1999
        mov      dword ptr [g_fightGroupHead], edx
    L_ec49:
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackAngleRatioSubchain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_ec7d
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_ebe0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_ec7d:
        pop      esi
        ret
    }
}
