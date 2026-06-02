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

extern unsigned int g_dispatchSave722;
extern unsigned int g_dispatchSave571;
extern unsigned int g_dispatchSave570;
extern unsigned int g_dispatchSave726;
extern unsigned int g_dispatchSave727;
extern unsigned int g_dispatchSave728;
extern unsigned int g_dispatchSave1626[];
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn2_y;
extern s32 g_vtxOut1_x;
extern s32 g_vtxOut1_y;
extern unsigned int g_triStripRingB;
extern unsigned int g_mat3x3_007af992;
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99a;
extern unsigned int g_mat3x3_007af99e;
extern unsigned int g_mat3x3_007af9a0;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern unsigned int g_dispatchSave1513;
extern unsigned int g_dispatchSave1514;
extern unsigned int g_dispatchSave1515;
extern unsigned int g_dispatchSave1516;
extern unsigned int g_dispatchSave1517;
extern unsigned int g_dispatchSave1518;
extern unsigned int g_dispatchSave1580;

__declspec(naked) void BboxProjectAndStash(void)
{
    __asm {
        mov      eax, dword ptr [g_xformEntityIdx]
        sub      esp, 0xc
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      edi, dword ptr [eax*4 + 0x1c]
        test     edi, edi
        mov      dword ptr [g_walkCallback], edi
        jle      L_c7d1
        cmp      edi, 0x10
        jg       L_c7d1
        shl      edi, 4
        mov      al, byte ptr [edi + g_dispatchSave571]
        test     al, al
        jne      L_c7d1
        mov      eax, dword ptr [g_tickCurConfig]
        cmp      eax, OFFSET g_dispatchSave722
        jne      L_c5f6
        mov      eax, dword ptr [g_dispatchSave1580]
        test     eax, eax
        jne      L_c7d1
        jmp      L_c60b
    L_c5f6:
        mov      dword ptr [g_dispatchSave1580], 0
        mov      cl, byte ptr [eax]
        cmp      cl, 1
        jne      L_c7d1
    L_c60b:
        mov      cx, word ptr [edi + g_dispatchSave570]
        mov      dx, word ptr [edi + g_dispatchSave727]
        movsx    eax, word ptr [g_mat3x3_007af992]
        movsx    ebp, word ptr [g_mat3x3_007af994]
        movsx    ebx, cx
        movsx    ecx, dx
        mov      dword ptr [esp + 0x10], ebx
        mov      dword ptr [esp + 0x14], ecx
        imul     ebx, eax
        mov      eax, dword ptr [esp + 0x14]
        mov      word ptr [g_dispatchSave1626], 0
        imul     eax, ebp
        movsx    ecx, word ptr [g_mat3x3_007af998]
        movsx    esi, word ptr [g_mat3x3_007af99a]
        add      ebx, eax
        mov      eax, dword ptr [g_vtxTransX]
        sar      ebx, 0xc
        add      ebx, eax
        mov      ebp, esi
        movsx    eax, bx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [esp + 0x14]
        mov      ebx, ecx
        imul     ebp, eax
        imul     ebx, dword ptr [esp + 0x10]
        movsx    edx, word ptr [g_mat3x3_007af99e]
        add      ebx, ebp
        mov      ebp, dword ptr [g_vtxTransY]
        sar      ebx, 0xc
        add      ebx, ebp
        mov      dword ptr [esp + 0x18], edx
        movsx    edx, word ptr [g_mat3x3_007af9a0]
        movsx    ebx, bx
        mov      dword ptr [g_xformEntityIdx], ebx
        mov      ebx, edx
        imul     ebx, eax
        mov      eax, dword ptr [esp + 0x18]
        mov      bp, word ptr [g_currentNodeIdx]
        imul     eax, dword ptr [esp + 0x10]
        add      ebx, eax
        mov      eax, dword ptr [g_vtxTransZ]
        sar      ebx, 0xc
        add      ebx, eax
        mov      eax, dword ptr [g_tickX2]
        movsx    ebx, bx
        lea      eax, [eax + eax*2]
        shl      eax, 1
        mov      word ptr [eax + g_dispatchSave1513], bp
        mov      bp, word ptr [g_xformEntityIdx]
        mov      word ptr [eax + g_dispatchSave1514], bp
        mov      word ptr [eax + g_dispatchSave1515], bx
        mov      bx, word ptr [edi + g_dispatchSave726]
        mov      di, word ptr [edi + g_dispatchSave728]
        mov      word ptr [g_vtxIn1_y], bx
        mov      word ptr [g_vtxIn2_y], di
        movsx    ebx, bx
        mov      dword ptr [esp + 0x10], ebx
        mov      ebp, ebx
        movsx    ebx, word ptr [g_mat3x3_007af992]
        movsx    edi, di
        imul     ebp, ebx
        mov      dword ptr [esp + 0x14], edi
        mov      ebx, edi
        movsx    edi, word ptr [g_mat3x3_007af994]
        imul     ebx, edi
        mov      edi, dword ptr [g_vtxTransX]
        add      ebp, ebx
        mov      ebx, dword ptr [esp + 0x14]
        sar      ebp, 0xc
        imul     esi, ebx
        add      ebp, edi
        mov      edi, dword ptr [esp + 0x10]
        imul     ecx, edi
        add      ecx, esi
        mov      esi, dword ptr [g_vtxTransY]
        sar      ecx, 0xc
        add      ecx, esi
        movsx    ebp, bp
        movsx    esi, cx
        mov      dword ptr [g_vtxOut1_x], ebp
        mov      dword ptr [g_vtxOut1_y], esi
        mov      ecx, dword ptr [esp + 0x18]
        imul     edx, ebx
        imul     ecx, edi
        add      edx, ecx
        mov      ecx, dword ptr [g_vtxTransZ]
        sar      edx, 0xc
        add      edx, ecx
        mov      dword ptr [g_currentNodeIdx], ebp
        movsx    ecx, dx
        mov      dx, word ptr [g_vtxOut1_y]
        mov      dword ptr [g_triStripRingB], ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      cx, word ptr [g_vtxOut1_x]
        mov      word ptr [eax + g_dispatchSave1516], cx
        mov      cx, word ptr [g_triStripRingB]
        mov      word ptr [eax + g_dispatchSave1517], dx
        mov      word ptr [eax + g_dispatchSave1518], cx
        mov      eax, dword ptr [g_tickX2]
        mov      dword ptr [g_xformEntityIdx], esi
        add      eax, 2
        mov      dword ptr [g_tickX2], eax
    L_c7d1:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    }
}
