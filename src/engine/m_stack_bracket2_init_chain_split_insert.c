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

extern unsigned int g_vertexInitFlag;
extern unsigned int g_vertexInitVar;
extern void MStackBracket5_LinkedListUnlink(void);
extern void MStackPush2ChainInsert(void);

__declspec(naked) void MStackBracket2InitChainSplitInsert(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        push    ebx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ebx, 4
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, ebx
        mov     dword ptr [g_eventQueueCurrent], eax
        jae     short L_mbsi_skip1
        mov     dword ptr [g_eventQueueCurrent], ebx
    L_mbsi_skip1:
        mov     eax, dword ptr [g_vertexInitFlag]
        mov     dword ptr [g_walkCallback], 0x425ba0
        mov     dword ptr [g_currentNodeIdx], eax
        call    Helper_TickAlt
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mbsi_pop
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_mbsi_loadSav
        mov     dword ptr [g_xformEntityIdx], 0
        call    MStackBracket5_LinkedListUnlink
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mbsi_pop
        mov     ecx, dword ptr [g_vertexInitVar]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPush2ChainInsert
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mbsi_pop
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [eax*4 + 0xc]
        sub     ecx, edx
        cmp     ecx, 8
        mov     dword ptr [g_walkCallback], ecx
        jb      L_mbsi_combine
        mov     dword ptr [eax*4 + 0xc], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_walkCallback]
        add     edx, -4
        lea     eax, [ecx + eax + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0xc], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 4], 0
        mov     ecx, dword ptr [g_vertexInitFlag]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPush2ChainInsert
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mbsi_pop
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, dword ptr [ecx*4]
        dec     ecx
        mov     dword ptr [g_matrixStackTop], ecx
    L_mbsi_combine:
        add     eax, ebx
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     short L_mbsi_loadCommon
    L_mbsi_loadSav:
        mov     eax, dword ptr [g_currentNodeIdx]
    L_mbsi_loadCommon:
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], edx
        mov     edx, dword ptr [ecx*4]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_matrixStackTop], ecx
        mov     edx, dword ptr [ecx*4]
        dec     ecx
        mov     dword ptr [g_xformEntityIdx], edx
        mov     edx, dword ptr [g_xformDirtyFlags]
        or      edx, ebx
        mov     dword ptr [g_matrixStackTop], ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      short L_mbsi_pop
        mov     eax, edx
        xor     eax, ebx
        mov     dword ptr [g_xformDirtyFlags], eax
    L_mbsi_pop:
        pop     ebx
        ret
    }
}
