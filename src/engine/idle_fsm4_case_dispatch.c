/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern void DualConstJmp_00453480(void);
extern void DualConstJmp_004534a0(void);
extern void DualConstJmp_004534c0(void);
extern void GatedWordPushCall(void);
extern void GuardedSetCallOrJmp(void);
extern void StorePauseImulShr16(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void IdleFsm4CaseDispatch(void)
{
    __asm {
        /* === Helper 1 (0x4531d0): tiny pre-roll === */
        mov      dword ptr [g_walkCallback], 4
        call     StorePauseImulShr16
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_31f4
        add      dword ptr [g_walkCallback], 0x3b
        jmp      GatedWordPushCall
    L_31f4:
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
        /* === Helper 2 (0x453200): main 4-case dispatcher === */
    L_3200:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 3
        ja       L_33b1
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_322e:
        /* case 1: decrement counter, branch on sign */
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      L_3365
        mov      dword ptr [g_eventQueueEnd], 0x33
        jmp      L_33be
    L_324e:
        /* case 2: 0x420 / 0x4a0 then state 3 */
        call     GuardedSetCallOrJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
        call     DualConstJmp_004534a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3200
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_3294:
        /* case 3: 0x420 / 0x4c0 then state 4 */
        call     GuardedSetCallOrJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
        call     DualConstJmp_004534c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3200
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_32da:
        /* case 0: init loop then state 1 */
        mov      dword ptr [g_eventQueueEnd], 4
        call     GuardedSetCallOrJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
    L_32f6:
        call     DualConstJmp_004534a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
        call     DualConstJmp_004534c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
        call     DualConstJmp_004534a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3401
        call     DualConstJmp_004534c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3401
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        js       short L_335b
        call     GuardedSetCallOrJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_32f6
        pop      esi
        ret
    L_335b:
        mov      dword ptr [g_eventQueueEnd], 4
    L_3365:
        call     GuardedSetCallOrJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3401
        call     DualConstJmp_004534a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3401
        call     DualConstJmp_004534c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3401
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3200
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_33b1:
        /* default (state >= 4): decrement, fall through to L_33be */
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        js       short L_33fc
    L_33be:
        call     GuardedSetCallOrJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3401
        call     DualConstJmp_00453480
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3401
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3200
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_33fc:
        call     Thunk_ScaledNeg1SetPause
    L_3401:
        pop      esi
        ret
        nop
    L_jmptbl:
        /* 4 absolute-address entries (no reloc - orig has DIR32 reloc;
           literal bytes match link-time addresses) */
        _emit 0xda
        _emit 0x32
        _emit 0x45
        _emit 0x00
        _emit 0x2e
        _emit 0x32
        _emit 0x45
        _emit 0x00
        _emit 0x4e
        _emit 0x32
        _emit 0x45
        _emit 0x00
        _emit 0x94
        _emit 0x32
        _emit 0x45
        _emit 0x00
    }
}
