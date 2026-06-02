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

extern unsigned int g_viewportW;
extern unsigned int g_viewportH;
extern unsigned int g_dispatchSave1707;
extern unsigned int g_dispatchSave1708;
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
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

__declspec(naked) void ScanlineTexBlit(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_0b63
        mov      edi, dword ptr [g_dispatchSave1378]
        mov      eax, dword ptr [g_viewportW]
        cmp      edi, eax
        jge      L_0b63
        mov      eax, dword ptr [g_dispatchSave1381]
        mov      ecx, dword ptr [g_viewportH]
        cmp      eax, ecx
        jge      L_0b63
        mov      ecx, dword ptr [g_dispatchSave1380]
        test     ecx, ecx
        jl       L_0b63
        mov      esi, dword ptr [g_dispatchSave1383]
        test     esi, esi
        jl       L_0b63
        sub      ecx, edi
        sub      esi, eax
        cmp      ecx, 1
        mov      dword ptr [g_dispatchSave1708], ecx
        mov      dword ptr [g_dispatchSave1707], esi
        jl       L_0b63
        cmp      esi, 1
        jl       L_0b63
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
        idiv     ecx
        mov      edx, dword ptr [g_dispatchSave1374]
        shl      ebx, 0x10
        mov      dword ptr [g_dispatchSave1377], ebx
        mov      ebx, eax
        mov      eax, dword ptr [g_dispatchSave1377]
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1357], ebx
        cdq
        idiv     esi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1358], eax
        jge      L_0a13
        imul     ebx, edi
        mov      edx, dword ptr [g_dispatchSave1371]
        add      ecx, edi
        sub      edx, ebx
        xor      edi, edi
        mov      dword ptr [g_dispatchSave1371], edx
        mov      dword ptr [g_dispatchSave1708], ecx
        mov      dword ptr [g_dispatchSave1378], edi
    L_0a13:
        mov      ecx, dword ptr [g_dispatchSave1381]
        test     ecx, ecx
        jge      L_0a46
        imul     eax, ecx
        mov      edx, dword ptr [g_dispatchSave1374]
        mov      dword ptr [g_dispatchSave1381], 0
        sub      edx, eax
        add      esi, ecx
        mov      ecx, dword ptr [g_dispatchSave1381]
        mov      dword ptr [g_dispatchSave1374], edx
        mov      dword ptr [g_dispatchSave1707], esi
    L_0a46:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380]
        cmp      edx, eax
        jl       L_0a5c
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1708], eax
    L_0a5c:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383]
        cmp      edx, eax
        jl       L_0a75
        sub      eax, ecx
        mov      esi, eax
        mov      dword ptr [g_dispatchSave1707], esi
    L_0a75:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, ecx
        add      eax, edx
        lea      eax, [eax + edi*2]
        mov      dword ptr [g_dispatchSave1346], eax
        mov      eax, dword ptr [g_dispatchSave1403]
        and      eax, 0xf
        shl      eax, 0x10
        test     esi, esi
        mov      dword ptr [g_dispatchSave1403], eax
        jle      L_0b63
        jmp      L_0aac
    L_0aa7:
        mov      eax, dword ptr [g_dispatchSave1403]
    L_0aac:
        mov      ecx, dword ptr [g_dispatchSave1371]
        xor      edx, edx
        mov      dh, byte ptr [g_dispatchSave1375]
        mov      dword ptr [g_dispatchSave1387], ecx
        add      edx, eax
        mov      eax, dword ptr [g_dispatchSave1400]
        lea      ecx, [eax + edx*2]
        mov      dword ptr [g_dispatchSave1404], ecx
        mov      eax, dword ptr [g_dispatchSave1387]
        shl      eax, 0x10
        mov      edx, dword ptr [g_dispatchSave1404]
        shr      edx, 1
        mov      ecx, dword ptr [g_dispatchSave1387]
        shr      ecx, 0x10
        mov      dl, cl
        mov      edi, dword ptr [g_dispatchSave1346]
        add      edi, dword ptr [g_dispatchSave1708]
        add      edi, dword ptr [g_dispatchSave1708]
        mov      esi, dword ptr [g_dispatchSave1708]
        neg      esi
        mov      ecx, dword ptr [g_dispatchSave1357]
        rol      ecx, 0x10
        mov      ch, 0
    L_0b10:
        mov      ax, word ptr [edx*2]
        test     ax, ax
        je       L_0b21
        mov      word ptr [edi + esi*2], ax
    L_0b21:
        add      eax, ecx
        adc      dl, cl
        inc      esi
        jl       L_0b10
        mov      edx, dword ptr [g_dispatchSave1358]
        mov      esi, dword ptr [g_dispatchSave1374]
        mov      eax, dword ptr [g_dispatchSave1707]
        mov      ecx, dword ptr [g_viewportY]
        add      esi, edx
        mov      edx, dword ptr [g_dispatchSave1346]
        dec      eax
        add      edx, ecx
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707], eax
        mov      dword ptr [g_dispatchSave1374], esi
        mov      dword ptr [g_dispatchSave1346], edx
        jg       L_0aa7
    L_0b63:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
