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

extern unsigned int g_installCountdownEnd;
extern unsigned int g_dispatchCmpEnd2;
extern unsigned int g_movesPanelEnd;
extern unsigned int g_dispatchCmpEnd;
extern u32 g_inLoopStep;
extern unsigned int g_dispatchSave1626[];
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
extern unsigned int g_dispatchSave1534;
extern unsigned int g_dispatchSave1536;
extern unsigned int g_dispatchSave1538;
extern unsigned int g_dispatchSave1540;
extern unsigned int g_dispatchSave1541;
extern unsigned int g_dispatchSave1542;
extern unsigned int g_dispatchSave1543;
extern unsigned int g_dispatchSave1544;
extern unsigned int g_dispatchSave1545;
extern unsigned int g_dispatchSave1546;
extern unsigned int g_dispatchSave1547;
extern unsigned int g_dispatchSave1548;
extern void GamepadSeqRecord(void);
extern void Helper_DrawCursor(void);
extern void ProjectTwoVertices(void);
extern void SunbeamSpriteEmit(void);

__declspec(naked) void MovesPanelEmit(void)
{
    __asm {
        mov      eax, dword ptr [g_eventQueueTotal]
        push     ebx
        push     esi
        push     edi
        mov      ecx, dword ptr [eax*4 + 0x18]
        cmp      ecx, 8
        mov      dword ptr [g_xformEntityIdx], ecx
        jge      L_cf83
        call     SunbeamSpriteEmit
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_cf83:
        mov      edx, dword ptr [g_inLoopStep]
        xor      edi, edi
        cmp      edx, edi
        jne      L_d260
        shl      eax, 2
        cmp      eax, OFFSET g_dispatchCmpEnd
        je       L_cfb6
        cmp      eax, OFFSET g_movesPanelEnd
        je       L_cfb6
        cmp      eax, OFFSET g_dispatchCmpEnd2
        je       L_cfb6
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_d260
    L_cfb6:
        mov      eax, dword ptr [g_tickW1]
        cmp      eax, 0x10
        jl       L_cfcc
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_cfce
    L_cfcc:
        xor      eax, eax
    L_cfce:
        mov      edx, dword ptr [ecx*4]
        lea      esi, [ecx*4]
        xor      ecx, ecx
        cmp      edx, 0xa000
        sete     cl
        neg      cl
        sbb      ecx, ecx
        mov      dx, word ptr [g_tickCurMask]
        and      ecx, 0xfffffff4
        mov      word ptr [g_dispatchSave1546], dx
        add      ecx, 0x16
        mov      word ptr [g_dispatchSave1548], 0xf
        mov      byte ptr [g_dispatchSave1542], cl
        mov      byte ptr [g_dispatchSave1544], cl
        mov      byte ptr [g_dispatchSave1540], cl
        mov      cl, 0x64
        mov      byte ptr [g_dispatchSave1543], cl
        mov      byte ptr [g_dispatchSave1545], cl
        mov      byte ptr [g_dispatchSave1541], cl
        mov      ecx, eax
        shl      ecx, 5
        or       ecx, eax
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [g_dispatchSave1547], cx
        mov      eax, dword ptr [esi + 4]
        mov      ecx, eax
        mov      word ptr [g_vtxIn2_y], di
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_dispatchSave1626], cx
        mov      word ptr [g_vtxIn1_y], ax
        mov      eax, dword ptr [esi + 0xc]
        mov      word ptr [g_vtxIn2_z], di
        mov      ecx, eax
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_vtxIn2_x], cx
        mov      word ptr [g_vtxIn1_z], ax
        mov      eax, dword ptr [esi + 0x14]
        mov      word ptr [g_triStripX2], di
        mov      ecx, eax
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_triStripX0], cx
        mov      word ptr [g_triStripX1], ax
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        push     edi
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [g_dispatchSave1534], ecx
        mov      cx, word ptr [g_dispatchSave1548]
        mov      dword ptr [g_dispatchSave1536], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [g_dispatchSave1538], eax
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [g_dispatchSave1548], cx
        mov      eax, dword ptr [g_eventQueueTotal]
        lea      ecx, [eax*4]
        push     ecx
        call     GamepadSeqRecord
        mov      eax, dword ptr [g_triStripRingB]
        add      esp, 8
        cmp      eax, edi
        jle      L_d172
        cmp      dword ptr [g_vtxOut2_z], edi
        jle      L_d172
        cmp      dword ptr [g_vtxOut_z], edi
        jle      L_d172
        push     OFFSET g_dispatchSave1534
        call     Helper_DrawCursor
        add      esp, 4
    L_d172:
        mov      esi, dword ptr [esi + 0x1c]
        mov      word ptr [g_vtxIn2_z], di
        mov      eax, esi
        shl      eax, 0x10
        sar      eax, 0x13
        sar      esi, 0x13
        mov      word ptr [g_vtxIn2_x], ax
        mov      word ptr [g_vtxIn1_z], si
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    esi, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      esi, eax
        imul     edx, esi
        movsx    esi, word ptr [g_vtxScreenP2Y]
        sub      esi, ecx
        push     1
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     esi, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, esi
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [g_dispatchSave1534], ecx
        mov      cx, word ptr [g_dispatchSave1548]
        mov      dword ptr [g_dispatchSave1536], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [g_dispatchSave1538], eax
        mov      eax, dword ptr [g_eventQueueTotal]
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [g_dispatchSave1548], cx
        lea      ecx, [eax*4]
        push     ecx
        call     GamepadSeqRecord
        mov      eax, dword ptr [g_triStripRingB]
        add      esp, 8
        cmp      eax, edi
        jle      L_d260
        cmp      dword ptr [g_vtxOut2_z], edi
        jle      L_d260
        cmp      dword ptr [g_vtxOut_z], edi
        jle      L_d260
        push     OFFSET g_dispatchSave1534
        call     Helper_DrawCursor
        add      esp, 4
    L_d260:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
