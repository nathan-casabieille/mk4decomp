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

extern unsigned int g_screenH;
extern u32 g_inLoopStep;
extern s16 g_vtxIn_x;
extern s16 g_vtxIn2_x;
extern unsigned int g_triStripX0;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn1_z;
extern unsigned int g_triStripX1;
extern s16 g_vtxIn2_y;
extern s16 g_vtxIn2_z;
extern unsigned int g_triStripX2;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenP2Y;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1559;
extern unsigned int g_dispatchSave1570;
extern unsigned int g_dispatchSave1574;
extern unsigned int g_dispatchSave1576;
extern void AdvanceTriStripRing(void);
extern void AltCamMatrixProject(void);
extern void Helper_DrawCursor(void);
extern void MaxOfThree(void);
extern void MinOfThree(void);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);

__declspec(naked) void TristripBatchEmit3Cap(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0xc
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        jne      L_b920
        mov      edi, dword ptr [esp + 0x20]
        mov      eax, dword ptr [edi + 4]
        test     eax, eax
        je       L_b920
        mov      eax, dword ptr [g_dispatchSave1570]
        test     eax, eax
        je       L_b6c4
        mov      eax, dword ptr [g_dispatchSave1574]
        test     eax, eax
        jge      L_b6c4
        push     1
        push     OFFSET g_dispatchSave1501
        call     AltCamMatrixProject
        add      esp, 8
    L_b6c4:
        mov      eax, dword ptr [edi + 8]
        mov      edx, dword ptr [edi + 4]
        lea      ecx, [eax + edi + 8]
        mov      eax, dword ptr [g_pendingNodeType]
        lea      edi, [edi + edx + 4]
        lea      esi, [eax + 4]
        mov      eax, dword ptr [g_dispatchSave1576]
        cmp      eax, 0x10
        jl       L_b6f0
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_b6f2
    L_b6f0:
        xor      eax, eax
    L_b6f2:
        mov      edx, eax
        shl      edx, 5
        or       edx, eax
        shl      edx, 5
        or       eax, edx
        mov      dword ptr [esp + 0x14], eax
    L_b702:
        mov      bp, word ptr [ecx]
        add      ecx, 2
        mov      eax, ebp
        and      ebp, 1
        shr      eax, 8
        and      al, 1
        mov      byte ptr [esp + 0x20], al
        mov      eax, dword ptr [esp + 0x24]
        test     eax, eax
        je       L_b728
        xor      eax, eax
        test     bp, bp
        sete     al
        mov      ebp, eax
    L_b728:
        movsx    ebx, word ptr [ecx]
        xor      eax, eax
        add      ecx, 2
        cmp      ebx, eax
        mov      dword ptr [esp + 0x18], ecx
        jl       L_b920
        mov      word ptr [g_vtxIn_x], ax
        mov      word ptr [g_vtxIn1_y], ax
        mov      word ptr [g_vtxIn2_y], ax
        mov      cx, word ptr [edi]
        mov      word ptr [g_vtxIn2_x], cx
        mov      dx, word ptr [edi + 2]
        mov      word ptr [g_vtxIn1_z], dx
        mov      ax, word ptr [edi + 4]
        mov      word ptr [g_vtxIn2_z], ax
        mov      cx, word ptr [edi + 0xc]
        mov      word ptr [g_triStripX0], cx
        mov      dx, word ptr [edi + 0xe]
        mov      word ptr [g_triStripX1], dx
        mov      ax, word ptr [edi + 0x10]
        mov      word ptr [g_triStripX2], ax
        call     ProjectTwoVertices
        add      edi, 0x18
        inc      ebx
        mov      dword ptr [esp + 0x10], ebx
    L_b79a:
        mov      cx, word ptr [edi + 4]
        mov      dx, word ptr [edi + 2]
        mov      ax, word ptr [edi]
        push     ecx
        push     edx
        push     eax
        call     AdvanceTriStripRing
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        sub      edx, ebx
        test     edx, edx
        setle    al
        xor      edx, edx
        mov      dword ptr [g_vtxValid], eax
        test     eax, eax
        movsx    eax, bp
        sete     dl
        cmp      eax, edx
        je       L_b8f8
        mov      eax, dword ptr [g_triStripRingB]
        test     eax, eax
        jle      L_b8f8
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_b8f8
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_b8f8
        mov      ecx, dword ptr [g_triStripRingA]
        mov      dword ptr [esi], ecx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      cx, word ptr [esi + 0x1a]
        mov      dword ptr [esi + 4], edx
        mov      eax, dword ptr [g_vtxScreenX]
        and      ecx, 0xfbff
        mov      dword ptr [esi + 8], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [esp + 0x28]
        and      edx, 1
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esi + 0x1a], cx
        jne      L_b878
        call     MinOfThree
        jmp      L_b87d
    L_b878:
        call     MaxOfThree
    L_b87d:
        mov      word ptr [esi + 0x12], ax
        mov      ecx, dword ptr [g_dispatchSave1559]
        shl      ecx, 5
        mov      dx, word ptr [esi + 0x1a]
        add      ecx, eax
        mov      al, byte ptr [esp + 0x20]
        mov      word ptr [esi + 0x12], cx
        and      al, 3
        and      edx, 0xfe6f
        movsx    cx, al
        shl      ecx, 7
        or       edx, ecx
        mov      word ptr [esi + 0x1a], dx
        mov      dx, word ptr [esp + 0x14]
        mov      word ptr [esi + 0x14], dx
        mov      eax, dword ptr [g_dispatchSave1570]
        test     eax, eax
        je       L_b8ef
        mov      ax, word ptr [g_screenH]
        cmp      word ptr [esi + 2], ax
        jle      L_b8d5
        mov      word ptr [esi + 2], ax
        mov      ax, word ptr [g_screenH]
    L_b8d5:
        cmp      word ptr [esi + 6], ax
        jle      L_b8e5
        mov      word ptr [esi + 6], ax
        mov      ax, word ptr [g_screenH]
    L_b8e5:
        cmp      word ptr [esi + 0xa], ax
        jle      L_b8ef
        mov      word ptr [esi + 0xa], ax
    L_b8ef:
        push     esi
        call     Helper_DrawCursor
        add      esp, 4
    L_b8f8:
        add      edi, 0xc
        xor      eax, eax
        test     bp, bp
        sete     al
        mov      ebp, eax
        mov      eax, dword ptr [esp + 0x10]
        add      esi, 0x1c
        dec      eax
        mov      dword ptr [esp + 0x10], eax
        jne      L_b79a
        mov      ecx, dword ptr [esp + 0x18]
        jmp      L_b702
    L_b920:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    }
}
