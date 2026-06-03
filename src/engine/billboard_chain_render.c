/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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

extern unsigned int g_dispatchSave531;
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
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenX;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1502;
extern unsigned int g_dispatchSave1503;
extern unsigned int g_dispatchSave1576;
extern void Helper_DrawCursor(void);
extern void ProjectTwoVertices(void);

__declspec(naked) void BillboardChainRender(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0x20
        push     ebx
        xor      ebx, ebx
        cmp      eax, ebx
        jne      L_b24a
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_dispatchSave1501]
        mov      edx, dword ptr [g_dispatchSave1502]
        push     edi
        mov      edi, dword ptr [eax*4 + 0x2c]
        mov      eax, dword ptr [g_dispatchSave1503]
        sar      eax, 7
        mov      dword ptr [g_vtxTransZ], eax
        mov      eax, dword ptr [g_dispatchSave1576]
        sar      ecx, 0x10
        sar      edx, 0x10
        cmp      eax, 0x10
        push     esi
        mov      dword ptr [g_currentNodeIdx], edi
        mov      dword ptr [g_vtxTransX], ecx
        mov      dword ptr [g_vtxTransY], edx
        jl       L_b098
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_b09a
    L_b098:
        xor      eax, eax
    L_b09a:
        mov      ecx, eax
        mov      word ptr [esp + 0x26], 0x60
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [esp + 0x1e], 0x40
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [esp + 0x20], cx
    L_b0b9:
        mov      eax, dword ptr [edi*4 + 0xc]
        cmp      eax, ebx
        mov      dword ptr [g_walkCallback], eax
        je       L_b233
        mov      edx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_xformEntityIdx], edx
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      eax, dword ptr [edx + 4]
        cmp      eax, ebx
        je       L_b233
        shl      ecx, 4
        xor      edx, edx
        mov      dl, byte ptr [ecx + eax + 0xe]
        lea      esi, [ecx + eax + 0xc]
        mov      ecx, dword ptr [eax + 4]
        lea      edx, [ecx + edx*4]
        mov      cl, byte ptr [esp + 0x26]
        mov      al, byte ptr [edx + eax + 0xa]
        xor      al, cl
        and      eax, 0xf
        xor      word ptr [esp + 0x26], ax
        mov      cl, byte ptr [esi + 1]
        and      ecx, 3
        mov      dl, byte ptr [ecx + g_dispatchSave531]
        mov      ecx, dword ptr [esp + 0x26]
        and      dl, 3
        and      ecx, 0xfe7f
        movsx    ax, dl
        shl      eax, 7
        or       eax, ecx
        mov      word ptr [esp + 0x26], ax
        mov      eax, dword ptr [edi*4 + 4]
        mov      cx, word ptr [esi + 8]
        mov      edx, dword ptr [edi*4 + 8]
        mov      di, word ptr [esi + 6]
        sar      eax, 7
        add      cx, ax
        mov      ax, word ptr [esi + 0xa]
        sar      edx, 7
        add      ax, dx
        mov      dx, word ptr [esi + 4]
        add      dx, cx
        add      di, ax
        mov      word ptr [g_dispatchSave1626], cx
        mov      word ptr [g_vtxIn1_y], ax
        mov      word ptr [g_vtxIn2_y], bx
        mov      word ptr [g_vtxIn2_x], dx
        mov      word ptr [g_vtxIn1_z], ax
        mov      word ptr [g_vtxIn2_z], bx
        mov      word ptr [g_triStripX0], dx
        mov      word ptr [g_triStripX1], di
        mov      word ptr [g_triStripX2], bx
        call     ProjectTwoVertices
        mov      dl, byte ptr [esi + 0xc]
        mov      byte ptr [esp + 0x18], dl
        mov      al, byte ptr [esi + 0xd]
        mov      byte ptr [esp + 0x19], al
        mov      cl, byte ptr [esi + 0xe]
        add      cl, byte ptr [esi + 0xc]
        mov      byte ptr [esp + 0x1c], cl
        mov      dl, byte ptr [esi + 0xf]
        mov      al, byte ptr [esi + 0xd]
        mov      ecx, dword ptr [g_vtxScreenP2X]
        add      dl, al
        mov      eax, dword ptr [g_triStripRingA]
        mov      dword ptr [esp + 0x10], ecx
        mov      cl, byte ptr [g_vtxValid]
        mov      dword ptr [esp + 0xc], eax
        mov      eax, dword ptr [esp + 0x26]
        and      ecx, 1
        and      eax, 0xfbff
        shl      ecx, 0xa
        or       eax, ecx
        mov      byte ptr [esp + 0x1d], dl
        mov      edx, dword ptr [g_vtxScreenX]
        mov      word ptr [esp + 0x26], ax
        mov      eax, dword ptr [g_triStripRingB]
        mov      dword ptr [esp + 0x14], edx
        cmp      eax, ebx
        jle      L_b22d
        cmp      dword ptr [g_vtxOut2_z], ebx
        jle      L_b22d
        cmp      dword ptr [g_vtxOut_z], ebx
        jle      L_b22d
        lea      edx, [esp + 0xc]
        push     edx
        call     Helper_DrawCursor
        add      esp, 4
    L_b22d:
        mov      edi, dword ptr [g_currentNodeIdx]
    L_b233:
        mov      edi, dword ptr [edi*4]
        cmp      edi, ebx
        mov      dword ptr [g_currentNodeIdx], edi
        jne      L_b0b9
        pop      esi
        pop      edi
    L_b24a:
        pop      ebx
        add      esp, 0x20
        ret
    }
}
