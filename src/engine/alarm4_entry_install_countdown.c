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

/* @addr 0x00496960 (357b game) - 4-entry packed alarm + countdown install.
 *   Entry 1 (offset 0, 28b): calls PushPopWalkSet1006; on no-error
 *     pushes 0x4f17c0 (alarm str) and ArgSarStoreJmp.
 *   4b NOP pad.
 *   Entry 2 (offset 0x20, 75b): pushes 0x4f17c8, sets [scaled+0x68]=0x30b,
 *     [scaled+0x74]=0x112, calls StreamInitCountdownBody; on no-error pushes
 *     0x4f17d8 and ArgSarStoreJmp.
 *   5b NOP pad.
 *   Entry 3 / body (offset 0x70, 202b): phase-state install.
 *     phase != 0: dec g_eventQueueChild; if zero tail-call
 *       InstallSelfMStackPush_004968a0; else fall to mstack-push body.
 *     phase 0: reset g_eventQueueChild = 2. Push it, call ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490;
 *       on no-error pop snapshot, if bit 0 of g_xformDirtyFlags set tail-call
 *       InstallSelfMStackPush_004968a0; else call ScaledLoadIncJmp_00429840,
 *       install Self at offset 0x70 (this entry) and arm 0x541e6c=1.
 *   6b NOP pad.
 *   Entry 4 (offset 0x140, 37b): sets [scaled+0x74]=0x112, pushes
 *     0x4f17f8 → ScaledLookupGuardJmpIndirect.
 */
extern unsigned int g_dispatchSave783;
extern unsigned int g_dispatchSave784;
extern unsigned int g_dispatchSave785;
extern unsigned int g_dispatchSave786;
extern unsigned int g_table_004d57b0;
extern void ArgSarStoreJmp(void);
extern void InstallSelfMStackPush_004968a0(void);
extern void PushPopWalkSet1006(void);
extern void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490(void);
extern void ScaledLoadIncJmp_00429840(void);
extern void ScaledLookupGuardJmpIndirect(void);
extern void StreamInitCountdownBody(void);

__declspec(naked) void Alarm4EntryInstallCountdown(void) {
    __asm {
        call    PushPopWalkSet1006
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aei_e1End
        push    offset g_dispatchSave783
        call    ArgSarStoreJmp
        add     esp, 4
    L_aei_e1End:
        ret
        nop
        nop
        nop
        nop
    L_aei_entry2:
        mov     eax, dword ptr [g_baseSel]
        push    offset g_dispatchSave784
        mov     dword ptr [eax*4 + 0x68], 0x30b
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x112
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    StreamInitCountdownBody
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_aei_e2End
        push    offset g_dispatchSave785
        call    ArgSarStoreJmp
        add     esp, 4
    L_aei_e2End:
        ret
        nop
        nop
        nop
        nop
        nop
    L_aei_body:
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_aei_phase0
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        jne     short L_aei_pushSnapshot
        call    InstallSelfMStackPush_004968a0
        pop     esi
        pop     ebx
        ret
    L_aei_phase0:
        mov     dword ptr [g_eventQueueChild], 2
    L_aei_pushSnapshot:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueChild]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        mov     dword ptr [g_walkCallback], 0xb
        call    ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aei_e3End
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ebx, 1
        mov     edx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        test    al, bl
        mov     dword ptr [g_eventQueueChild], edx
        je      short L_aei_notBit0
        call    InstallSelfMStackPush_004968a0
        pop     esi
        pop     ebx
        ret
    L_aei_notBit0:
        call    ScaledLoadIncJmp_00429840
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_aei_e3End
        mov     dword ptr [esi + 8], offset L_aei_body
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_aei_e3End:
        pop     esi
        pop     ebx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
    L_aei_entry4:
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x112
        mov     dword ptr [g_walkCallback], eax
        push    offset g_dispatchSave786
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ScaledLookupGuardJmpIndirect
        add     esp, 4
        ret
    }
}
