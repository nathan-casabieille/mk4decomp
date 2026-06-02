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
extern unsigned int g_dispatchSave1707;
extern unsigned int g_dispatchSave1708;
extern unsigned int g_dispatchSave1334;
extern unsigned int g_dispatchSave1346;
extern unsigned int g_dispatchSave1357;
extern unsigned int g_dispatchSave1358;
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
extern unsigned int g_dispatchSave1395;
extern unsigned int g_dispatchSave1396;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1402;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

__declspec(naked) void ScanlineTexBlitInterlaced(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_13df
        mov      eax, dword ptr [g_dispatchSave1378]
        mov      ecx, dword ptr [g_viewportW]
        cmp      eax, ecx
        jge      L_13df
        mov      ebx, dword ptr [g_dispatchSave1381]
        mov      ecx, dword ptr [g_viewportH]
        cmp      ebx, ecx
        jge      L_13df
        mov      edi, dword ptr [g_dispatchSave1380]
        test     edi, edi
        jl       L_13df
        mov      ecx, dword ptr [g_dispatchSave1383]
        test     ecx, ecx
        jl       L_13df
        sub      edi, eax
        sub      ecx, ebx
        cmp      edi, 1
        mov      dword ptr [g_dispatchSave1708], edi
        mov      dword ptr [g_dispatchSave1707], ecx
        jl       L_13df
        cmp      ecx, 1
        jl       L_13df
        mov      eax, dword ptr [g_dispatchSave1374]
        mov      esi, dword ptr [g_dispatchSave1371]
        mov      edx, dword ptr [g_dispatchSave1377]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1374], eax
        mov      eax, dword ptr [g_dispatchSave1373]
        shl      eax, 0x10
        shl      esi, 0x10
        mov      dword ptr [g_dispatchSave1373], eax
        sub      eax, esi
        shl      edx, 0x10
        mov      dword ptr [g_dispatchSave1377], edx
        mov      dword ptr [g_dispatchSave1371], esi
        cdq
        idiv     edi
        mov      edx, dword ptr [g_dispatchSave1374]
        mov      dword ptr [g_dispatchSave1357], eax
        mov      eax, dword ptr [g_dispatchSave1377]
        sub      eax, edx
        cdq
        idiv     ecx
        mov      dword ptr [g_dispatchSave1358], eax
        mov      eax, dword ptr [g_dispatchSave1378]
        test     eax, eax
        jge      L_1225
        mov      edx, dword ptr [g_dispatchSave1357]
        add      edi, eax
        imul     edx, eax
        sub      esi, edx
        xor      eax, eax
        mov      dword ptr [g_dispatchSave1371], esi
        mov      dword ptr [g_dispatchSave1708], edi
        mov      dword ptr [g_dispatchSave1378], eax
    L_1225:
        test     ebx, ebx
        jge      L_1254
        mov      eax, dword ptr [g_dispatchSave1358]
        mov      edx, dword ptr [g_dispatchSave1374]
        imul     eax, ebx
        sub      edx, eax
        mov      eax, dword ptr [g_dispatchSave1378]
        add      ecx, ebx
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], edx
        mov      dword ptr [g_dispatchSave1707], ecx
        mov      dword ptr [g_dispatchSave1381], ebx
    L_1254:
        mov      ecx, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380]
        cmp      edx, ecx
        jl       L_126e
        sub      ecx, eax
        mov      edi, ecx
        mov      dword ptr [g_dispatchSave1708], edi
    L_126e:
        mov      ecx, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383]
        cmp      edx, ecx
        jl       L_1286
        sub      ecx, ebx
        mov      dword ptr [g_dispatchSave1707], ecx
    L_1286:
        mov      edx, dword ptr [g_viewportY]
        mov      ecx, dword ptr [g_viewportX]
        imul     edx, ebx
        add      ecx, edx
        mov      edx, dword ptr [g_dispatchSave1707]
        lea      ecx, [ecx + eax*2]
        mov      eax, dword ptr [g_dispatchSave1403]
        and      eax, 0xf
        mov      dword ptr [g_dispatchSave1346], ecx
        shl      eax, 0x10
        test     edx, edx
        mov      dword ptr [g_dispatchSave1403], eax
        jle      L_13df
        jmp      L_12c5
    L_12c0:
        mov      eax, dword ptr [g_dispatchSave1403]
    L_12c5:
        xor      edx, edx
        and      ebx, 1
        mov      dh, byte ptr [g_dispatchSave1375]
        mov      dword ptr [g_dispatchSave1387], esi
        add      edx, eax
        mov      eax, dword ptr [g_dispatchSave1400]
        mov      dword ptr [g_dispatchSave1396], ecx
        mov      dword ptr [g_dispatchSave1334], esi
        lea      edx, [eax + edx*2]
        mov      eax, ecx
        sar      eax, 1
        mov      dword ptr [g_dispatchSave1404], edx
        and      eax, 1
        mov      edx, edi
        xor      ebx, eax
        mov      dword ptr [g_dispatchSave1402], edx
        je       L_1322
        mov      eax, dword ptr [g_dispatchSave1357]
        lea      edx, [edi - 1]
        add      eax, esi
        mov      dword ptr [g_dispatchSave1402], edx
        mov      dword ptr [g_dispatchSave1334], eax
        lea      eax, [ecx + 2]
        mov      dword ptr [g_dispatchSave1396], eax
    L_1322:
        mov      eax, dword ptr [g_dispatchSave1357]
        mov      ebx, dword ptr [g_dispatchSave1381]
        add      eax, eax
        inc      ebx
        cmp      edx, 1
        mov      dword ptr [g_dispatchSave1395], eax
        mov      dword ptr [g_dispatchSave1381], ebx
        jl       L_13b2
        mov      eax, dword ptr [g_dispatchSave1334]
        shl      eax, 0x10
        mov      edx, dword ptr [g_dispatchSave1404]
        shr      edx, 1
        mov      ecx, dword ptr [g_dispatchSave1334]
        shr      ecx, 0x10
        mov      dl, cl
        mov      edi, dword ptr [g_dispatchSave1396]
        add      edi, dword ptr [g_dispatchSave1402]
        add      edi, dword ptr [g_dispatchSave1402]
        mov      esi, dword ptr [g_dispatchSave1402]
        neg      esi
        mov      ecx, dword ptr [g_dispatchSave1395]
        rol      ecx, 0x10
        mov      ch, 0
    L_1380:
        mov      ax, word ptr [edx*2]
        test     ax, ax
        je       L_1391
        mov      word ptr [edi + esi*2], ax
    L_1391:
        add      eax, ecx
        adc      dl, cl
        add      esi, 2
        jl       L_1380
        mov      ebx, dword ptr [g_dispatchSave1381]
        mov      edi, dword ptr [g_dispatchSave1708]
        mov      esi, dword ptr [g_dispatchSave1371]
        mov      ecx, dword ptr [g_dispatchSave1346]
    L_13b2:
        mov      edx, dword ptr [g_dispatchSave1358]
        mov      eax, dword ptr [g_dispatchSave1707]
        add      dword ptr [g_dispatchSave1374], edx
        mov      edx, dword ptr [g_viewportY]
        dec      eax
        add      ecx, edx
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707], eax
        mov      dword ptr [g_dispatchSave1346], ecx
        jg       L_12c0
    L_13df:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
