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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

extern unsigned int g_dispatchSave556_004f3930;
extern unsigned int g_dispatchSave815_004f393c;
extern unsigned int g_dispatchSave816_004f394c;
extern unsigned int g_dispatchSave817_004f39dc;
extern unsigned int g_dispatchSave818_004f3a48;
extern unsigned int g_dispatchSave724_004f6338;
extern unsigned int g_audioPreloadBase;
extern unsigned int g_dispatchSave128_0050f130;
extern unsigned int g_dispatchSave127_0050f14c;
extern unsigned int g_dispatchSave119_0051599c;
extern unsigned int g_bootInitState;
extern unsigned int g_count;
extern unsigned int g_voicePoolTickFlag_005437f4;
extern void AudioBindEntry(void);
extern void CharSelect_CpuBattlesToggle(void);
extern void AudioInitArgs3(void);
extern void AudioState50b4BitDispatcher(void);
extern void FiveTableWalkInit(void);
extern void InstallSelfPackedF80(void);
extern void MStackPush2ChainLLInsert(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void PendingMatch_004a2a80(void);
extern void RetZero_004a1c40(void);
extern void ScaledByteIdxDualCopy(void);
extern void SetJmp_004a1ac0(void);
extern void TableWalkBoundedCmp(void);
extern void TripleCallByteCheck(void);
extern void TripleCallSetCopy(void);

/* @addr 0x004a5290 - EnduranceMode_Handler: the main mode menu's
 * on-select handler for the ENDURANCE row (table at 0x4f308c, +0x14
 * field; see analysis/notes/menu_state.md). A per-frame state machine
 * dispatching on the node's +0x84 state field (0/1/2): drives the
 * endurance-mode flow, manages g_voicePoolTickFlag, and walks the
 * scene node chain. NOT audio / "Konquest" - the old name was a
 * mis-grouping artifact (this is in the 0x4a2000-0x4a9000 menu/mode
 * cluster the symbol table labels "audio"; MK4 has no Konquest mode).
 */
__declspec(naked) void EnduranceMode_Handler(void)
{
    __asm {
    L_5290:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        push     edi
        lea      edi, [eax*4]
        xor      ebp, ebp
        mov      eax, dword ptr [edi + 0x84]
        mov      dword ptr [edi + 0x84], ebp
        sub      eax, ebp
        je       L_5453
        dec      eax
        je       short L_52cd
        mov      dword ptr [g_voicePoolTickFlag_005437f4], 1
        call     PendingMatch_004a2a80
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_52cd:
        mov      eax, dword ptr [g_eventQueueIdx]
        cmp      eax, ebp
        je       short L_52e0
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPush2ChainLLInsert
    L_52e0:
        mov      eax, dword ptr [g_count]
        cmp      eax, 4
        je       short L_52ff
        cmp      eax, 8
        jne      short L_530d
        mov      ecx, OFFSET g_dispatchSave128_0050f130
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        jmp      short L_530d
    L_52ff:
        mov      edx, OFFSET g_dispatchSave127_0050f14c
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
    L_530d:
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueIdx], eax
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_5360
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x54], ebp
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x58], 0xfff60000
    L_5360:
        call     CharSelect_CpuBattlesToggle
        push     OFFSET g_dispatchSave556_004f3930
        call     ScaledByteIdxDualCopy
        add      esp, 4
        push     OFFSET g_dispatchSave556_004f3930
        call     AudioState50b4BitDispatcher
        add      esp, 4
        call     TripleCallByteCheck
        test     eax, eax
        mov      ebx, 1
        je       short L_53cb
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x30]
        lea      ecx, [eax + eax*8]
        mov      eax, dword ptr [ecx*4 + g_dispatchSave815_004f393c]
        cmp      eax, ebp
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_53c3
        call     SetJmp_004a1ac0
        call     dword ptr [g_currentNodeIdx]
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
    L_53c3:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_53d8
    L_53cb:
        call     RetZero_004a1c40
        test     eax, eax
        je       L_5516
    L_53d8:
        mov      dword ptr [g_eventQueueWorkType], 0x32f
        call     Push16Call
        call     CharSelect_CpuBattlesToggle
        mov      dword ptr [g_eventQueueCurrent], 0x20
        mov      dword ptr [edi + 8], OFFSET L_5290
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_5290
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [edi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebp
        call     InstallSelfPackedF80
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_5453:
        mov      ebx, 1
        push     8
        mov      dword ptr [g_bootInitState], ebx
        call     TableWalkBoundedCmp
        add      esp, 4
        call     FiveTableWalkInit
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      L_552f
        mov      esi, OFFSET g_dispatchSave816_004f394c
    L_547e:
        cmp      esi, OFFSET g_dispatchSave817_004f39dc
        jge      short L_54a1
        mov      ecx, dword ptr [esi]
        mov      eax, dword ptr [esi + 4]
        sub      ecx, 0x50000
        push     eax
        push     ecx
        push     ebp
        push     OFFSET g_dispatchSave119_0051599c
        call     AudioInitArgs3
        add      esp, 0x10
    L_54a1:
        movsx    edx, byte ptr [esi - 0xc]
        mov      eax, dword ptr [g_baseSel]
        add      esi, 0x24
        add      edx, eax
        cmp      esi, OFFSET g_dispatchSave818_004f3a48
        mov      dword ptr [edx*4], ebp
        jb       short L_547e
        push     OFFSET g_dispatchSave724_004f6338
        call     AudioBindEntry
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET g_audioPreloadBase
        shr      ecx, 2
        add      esp, 4
        mov      dword ptr [eax*4 + 0x30], ebx
        mov      dword ptr [g_count], 4
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], ebp
        jne      short L_552f
        call     TripleCallSetCopy
        mov      dword ptr [g_eventQueueIdx], ebp
        mov      dword ptr [g_eventQueueWorkType], 9
        call     Push16Call
    L_5516:
        mov      dword ptr [edi + 8], OFFSET L_5290
        mov      dword ptr [edi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_552f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
