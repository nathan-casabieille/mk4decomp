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

extern unsigned int g_load_0052ab10;
extern unsigned int g_vec3TripleSlot_00538098;
extern unsigned int g_dispatchSave97_005380a0;
extern unsigned int g_packedTripleSlot;
extern unsigned int g_dispatchSave90_0053a424;
extern unsigned int g_dispatchSave89_0053a428;
extern unsigned int g_packedTripleSlot2_00541f88;
extern void QuadInterpolator(void);

__declspec(naked) void Vec3PackedTripleCallBracket(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueWorkType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_acc_00542078]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_load_0052ab10]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     esi, dword ptr [edx*4]
        mov     dword ptr [g_walkCallback], esi
        mov     ecx, dword ptr [eax*4 + 0x54]
        sub     ecx, esi
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_packedTripleSlot], ecx
        mov     esi, dword ptr [edx*4 + 4]
        mov     dword ptr [g_walkCallback], esi
        mov     ecx, dword ptr [eax*4 + 0x58]
        sub     ecx, esi
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_dispatchSave90_0053a424], ecx
        mov     edx, dword ptr [edx*4 + 8]
        mov     ecx, offset g_vec3TripleSlot_00538098
        mov     dword ptr [g_walkCallback], edx
        mov     eax, dword ptr [eax*4 + 0x5c]
        sub     eax, edx
        mov     edx, offset g_packedTripleSlot
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_dispatchSave89_0053a428], eax
        mov     eax, dword ptr [g_packedTripleSlot2_00541f88]
        shr     edx, 2
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        call    QuadInterpolator
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v3ptcb_ret
        mov     edx, dword ptr [g_dispatchSave97_005380a0]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], edx
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_acc_00542078], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueWorkType], edx
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
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_v3ptcb_ret:
        pop     esi
        ret
    }
}
