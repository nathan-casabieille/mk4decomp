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

extern unsigned int g_viewportW;
extern unsigned int g_viewportH;
extern unsigned int g_texturedTriVar;
extern unsigned int g_dispatchSave1707;
extern unsigned int g_dispatchSave1708;
extern unsigned int g_dispatchSave1345;
extern unsigned int g_dispatchSave1346;
extern unsigned int g_dispatchSave1357;
extern unsigned int g_dispatchSave1358;
extern s32 g_clipMinScratch;
extern unsigned int g_dispatchSave1371;
extern unsigned int g_dispatchSave1373;
extern unsigned int g_dispatchSave1374;
extern unsigned int g_dispatchSave1375;
extern unsigned int g_dispatchSave1377;
extern unsigned int g_dispatchSave1378;
extern unsigned int g_dispatchSave1380;
extern unsigned int g_dispatchSave1381;
extern unsigned int g_dispatchSave1383;
extern unsigned int g_dispatchSave1387;
extern unsigned int g_dispatchSave1388;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

__declspec(naked) void ScanlineTexBlitAdditive(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_1129
        mov      ecx, dword ptr [g_dispatchSave1378]
        mov      eax, dword ptr [g_viewportW]
        cmp      ecx, eax
        jge      L_1129
        mov      edi, dword ptr [g_dispatchSave1381]
        mov      eax, dword ptr [g_viewportH]
        cmp      edi, eax
        jge      L_1129
        mov      ebp, dword ptr [g_dispatchSave1380]
        test     ebp, ebp
        jl       L_1129
        mov      eax, dword ptr [g_dispatchSave1383]
        test     eax, eax
        jl       L_1129
        sub      ebp, ecx
        sub      eax, edi
        cmp      ebp, 1
        mov      dword ptr [g_dispatchSave1708], ebp
        mov      dword ptr [g_dispatchSave1707], eax
        jl       L_1129
        cmp      eax, 1
        jl       L_1129
        mov      eax, dword ptr [g_dispatchSave1374]
        mov      edx, dword ptr [g_dispatchSave1371]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1374], eax
        mov      eax, dword ptr [g_dispatchSave1373]
        shl      eax, 0x10
        shl      edx, 0x10
        mov      dword ptr [g_dispatchSave1373], eax
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1371], edx
        mov      ebx, dword ptr [g_dispatchSave1377]
        cdq
        idiv     ebp
        shl      ebx, 0x10
        mov      dword ptr [g_dispatchSave1377], ebx
        mov      esi, eax
        mov      eax, ebx
        mov      ebx, dword ptr [g_dispatchSave1374]
        mov      dword ptr [g_dispatchSave1357], esi
        sub      eax, ebx
        cdq
        idiv     dword ptr [g_dispatchSave1707]
        test     ecx, ecx
        mov      dword ptr [g_dispatchSave1358], eax
        jge      L_0f05
        mov      edx, esi
        mov      ebx, dword ptr [g_dispatchSave1371]
        imul     edx, ecx
        sub      ebx, edx
        add      ebp, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1371], ebx
        mov      dword ptr [g_dispatchSave1708], ebp
        mov      dword ptr [g_dispatchSave1378], ecx
    L_0f05:
        test     edi, edi
        jge      L_0f2e
        imul     eax, edi
        mov      edx, dword ptr [g_dispatchSave1374]
        sub      edx, eax
        mov      eax, dword ptr [g_dispatchSave1707]
        add      eax, edi
        xor      edi, edi
        mov      dword ptr [g_dispatchSave1374], edx
        mov      dword ptr [g_dispatchSave1707], eax
        mov      dword ptr [g_dispatchSave1381], edi
    L_0f2e:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380]
        cmp      edx, eax
        jl       L_0f47
        sub      eax, ecx
        mov      ebp, eax
        mov      dword ptr [g_dispatchSave1708], ebp
    L_0f47:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383]
        cmp      edx, eax
        jl       L_0f5d
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1707], eax
    L_0f5d:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, edi
        add      eax, edx
        lea      edx, [eax + ecx*2]
        mov      eax, dword ptr [g_dispatchSave1403]
        mov      ecx, dword ptr [g_dispatchSave1707]
        and      eax, 0xf
        shl      eax, 0x10
        test     ecx, ecx
        mov      dword ptr [g_dispatchSave1346], edx
        mov      dword ptr [g_dispatchSave1403], eax
        jle      L_1129
        jmp      L_0f9b
    L_0f96:
        mov      eax, dword ptr [g_dispatchSave1403]
    L_0f9b:
        mov      ecx, dword ptr [g_dispatchSave1371]
        mov      dword ptr [g_dispatchSave1345], edx
        mov      dword ptr [g_dispatchSave1387], ecx
        xor      ecx, ecx
        mov      ch, byte ptr [g_dispatchSave1375]
        mov      dword ptr [g_clipMinScratch], ebp
        add      ecx, eax
        mov      eax, dword ptr [g_dispatchSave1400]
        lea      ecx, [eax + ecx*2]
        mov      eax, dword ptr [g_texturedTriVar]
        test     eax, eax
        mov      dword ptr [g_dispatchSave1404], ecx
        je       L_1071
        test     ebp, ebp
        jle      L_10ee
    L_0fe0:
        mov      edi, dword ptr [g_dispatchSave1404]
        xor      ecx, ecx
        mov      cl, byte ptr [g_dispatchSave1388]
        xor      eax, eax
        mov      ax, word ptr [edi + ecx*2]
        test     ax, ax
        je       L_1045
        mov      cx, word ptr [edx]
        and      eax, 0xf7de
        and      ecx, 0xf7de
        add      ecx, eax
        mov      eax, ecx
        and      eax, 0x10820
        mov      edi, eax
        mov      esi, eax
        shr      edi, 1
        and      esi, 0xffff00ff
        and      edi, 0x7f80
        or       esi, edi
        shr      esi, 5
        sub      eax, esi
        or       eax, ecx
        and      eax, 0xf7de
        mov      word ptr [edx], ax
        mov      ebp, dword ptr [g_dispatchSave1708]
        mov      esi, dword ptr [g_dispatchSave1357]
        mov      edx, dword ptr [g_dispatchSave1345]
    L_1045:
        mov      eax, dword ptr [g_clipMinScratch]
        mov      ebx, dword ptr [g_dispatchSave1387]
        dec      eax
        add      ebx, esi
        add      edx, 2
        mov      dword ptr [g_clipMinScratch], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387], ebx
        mov      dword ptr [g_dispatchSave1345], edx
        jg       L_0fe0
        jmp      L_10ee
    L_1071:
        test     ebp, ebp
        jle      L_10ee
    L_1075:
        mov      edi, dword ptr [g_dispatchSave1404]
        xor      ecx, ecx
        mov      cl, byte ptr [g_dispatchSave1388]
        xor      eax, eax
        mov      ax, word ptr [edi + ecx*2]
        test     ax, ax
        je       L_10c8
        mov      cx, word ptr [edx]
        and      eax, 0x7bde
        and      ecx, 0x7bde
        add      ecx, eax
        mov      eax, ecx
        and      eax, 0x8420
        mov      esi, eax
        shr      esi, 5
        sub      eax, esi
        or       eax, ecx
        and      eax, 0x7bde
        mov      word ptr [edx], ax
        mov      ebp, dword ptr [g_dispatchSave1708]
        mov      esi, dword ptr [g_dispatchSave1357]
        mov      edx, dword ptr [g_dispatchSave1345]
    L_10c8:
        mov      eax, dword ptr [g_clipMinScratch]
        mov      ebx, dword ptr [g_dispatchSave1387]
        dec      eax
        add      ebx, esi
        add      edx, 2
        mov      dword ptr [g_clipMinScratch], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387], ebx
        mov      dword ptr [g_dispatchSave1345], edx
        jg       L_1075
    L_10ee:
        mov      edx, dword ptr [g_dispatchSave1358]
        mov      ebx, dword ptr [g_dispatchSave1374]
        mov      eax, dword ptr [g_dispatchSave1707]
        mov      edi, dword ptr [g_viewportY]
        add      ebx, edx
        mov      edx, dword ptr [g_dispatchSave1346]
        dec      eax
        add      edx, edi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707], eax
        mov      dword ptr [g_dispatchSave1374], ebx
        mov      dword ptr [g_dispatchSave1346], edx
        jg       L_0f96
    L_1129:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
