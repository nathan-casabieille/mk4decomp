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

extern void ScaledNegThreeWords(void);
extern void ChainStreamMatMulVecAdd(void);
extern void RegionFlushChain(void);
extern unsigned int g_dispatchSave1549_00ab48d8;


__declspec(naked) void MStackBracket7_DispatchAndChain(void)
{
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        sub     esp, 0x0C
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        push    esi
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     esi, offset g_dispatchSave1549_00ab48d8
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueTotal]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        push    edi
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueEnd]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     ecx, dword ptr [g_fightGroupHead]
        sar     esi, 2
        mov     eax, dword ptr [ecx*4 + 0x34]
        add     ecx, 0x18
        mov     dword ptr [g_eventQueueIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     ecx, offset g_nodeDispatchTable
        sar     eax, 0x18
        sar     ecx, 2
        and     eax, 7
        add     ecx, eax
        mov     eax, esi
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        call    ecx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_msb7dc_pop7
        test    byte ptr [g_eventQueueIdx], 1
        je      L_msb7dc_skip_be210
        call    ScaledNegThreeWords
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_msb7dc_pop7
    L_msb7dc_skip_be210:
        mov     eax, dword ptr [g_fightGroupHead]
        lea     edi, [esp + 8]
        sar     edi, 2
        mov     edx, edi
        mov     dword ptr [g_currentNodeIdx], edx
        mov     ecx, dword ptr [eax*4 + 0x2C]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        je      L_msb7dc_no_2c
        mov     edx, dword ptr [g_eventQueueTotal]
        add     eax, 0x15
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_eventQueueTotal], eax
        call    ChainStreamMatMulVecAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_msb7dc_chain_init
        pop     edi
        pop     esi
        add     esp, 0x0C
        ret
    L_msb7dc_no_2c:
        mov     eax, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 4], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x5C]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 8], eax
    L_msb7dc_chain_init:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_eventQueueEnd], 0x00AB48D8
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], esi
        mov     dword ptr [g_pendingNodeType], edi
        call    RegionFlushChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_msb7dc_pop7
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xFE
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformDirtyFlags], eax
    L_msb7dc_pop7:
        pop     edi
        pop     esi
        add     esp, 0x0C
        ret
    }
}
