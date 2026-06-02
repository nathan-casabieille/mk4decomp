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

extern unsigned int g_particleEmitterNode;
extern unsigned int g_walkTreeArrBase;
extern void FlagThunk4EntryDispatcher(void);
extern void DirtyDoubleDeref(void);
extern void PendingMatch_0041afd0(void);
extern void BootStateTriple(void);
extern void MStackBracket1_TreeWalkRecursive2(void);
extern void Thunk_00405ac0(void);

__declspec(naked) void Phase2InitSlotTreeWalk(void)
{
    __asm {
        mov     dword ptr [g_walkCallback], 0
        call    FlagThunk4EntryDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     dword ptr [g_walkCallback], 8
        call    FlagThunk4EntryDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     dword ptr [g_walkCallback], 2
        call    DirtyDoubleDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DispatcherComplex260_00407400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p2is_continue
        jmp     PendingMatch_0041afd0
    L_p2is_continue:
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x30], 0x80
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x3C], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_eventQueueNotMask], 0x10000
        mov     eax, dword ptr [edx*4 + 0x34]
        and     eax, 1
        mov     dword ptr [g_walkCallback], eax
        je      L_p2is_after_select
        mov     dword ptr [g_eventQueueNotMask], 0xFFFF0000
    L_p2is_after_select:
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [ecx*4 + 0x34]
        or      edx, eax
        mov     eax, 0x147A
        mov     dword ptr [ecx*4 + 0x34], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x80], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueEnd], edx
        call    MStackPush2RunCountdown
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        call    MStackBracket7_DispatchAndChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     dword ptr [g_walkCallback], 2
        call    BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [eax*4 + 0x3C]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x40]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x44]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5C], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [eax*4 + 0x30], 0
        mov     ecx, dword ptr [g_eventQueueTotal]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x38], edx
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, offset g_walkTreeArrBase
        sar     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [ecx*4 + 0x34]
        add     eax, edx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4]
        mov     dword ptr [g_xformEntityIdx], edx
        call    MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p2is_after_walk
        jmp     PendingMatch_0041afd0
    L_p2is_after_walk:
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     dword ptr [g_xformEntityIdx], eax
        call    Thunk_00405ac0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p2is_ret
        jmp     PendingMatch_0041afd0
    L_p2is_ret:
        ret
    }
}
