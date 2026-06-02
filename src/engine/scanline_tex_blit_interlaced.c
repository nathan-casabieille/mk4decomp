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

extern unsigned int g_viewportW;
extern unsigned int g_viewportH;
extern unsigned int g_dispatchSave1707_00b2d008;
extern unsigned int g_dispatchSave1708_00b2d00c;
extern unsigned int g_dispatchSave1334_00f4d010;
extern unsigned int g_dispatchSave1346_00f4d044;
extern unsigned int g_dispatchSave1357_00f70f4c;
extern unsigned int g_dispatchSave1358_00f70f50;
extern unsigned int g_dispatchSave1371_00f70f88;
extern unsigned int g_dispatchSave1373_00f70f90;
extern unsigned int g_dispatchSave1374_00f70f98;
extern unsigned int g_dispatchSave1375_00f70f9a;
extern unsigned int g_dispatchSave1377_00f70fa0;
extern unsigned int g_dispatchSave1378_00f70fa8;
extern unsigned int g_dispatchSave1380_00f70fb0;
extern unsigned int g_dispatchSave1381_00f70fb8;
extern unsigned int g_dispatchSave1383_00f70fc0;
extern unsigned int g_dispatchSave1387_00f70fd8;
extern unsigned int g_dispatchSave1395_00f71300;
extern unsigned int g_dispatchSave1396_00f71304;
extern unsigned int g_dispatchSave1400_00f85b34;
extern unsigned int g_dispatchSave1402_00f85b3c;
extern unsigned int g_dispatchSave1403_00f85b4c;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404_00f85b58;

__declspec(naked) void ScanlineTexBlitInterlaced(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_13df
        mov      eax, dword ptr [g_dispatchSave1378_00f70fa8]
        mov      ecx, dword ptr [g_viewportW]
        cmp      eax, ecx
        jge      L_13df
        mov      ebx, dword ptr [g_dispatchSave1381_00f70fb8]
        mov      ecx, dword ptr [g_viewportH]
        cmp      ebx, ecx
        jge      L_13df
        mov      edi, dword ptr [g_dispatchSave1380_00f70fb0]
        test     edi, edi
        jl       L_13df
        mov      ecx, dword ptr [g_dispatchSave1383_00f70fc0]
        test     ecx, ecx
        jl       L_13df
        sub      edi, eax
        sub      ecx, ebx
        cmp      edi, 1
        mov      dword ptr [g_dispatchSave1708_00b2d00c], edi
        mov      dword ptr [g_dispatchSave1707_00b2d008], ecx
        jl       L_13df
        cmp      ecx, 1
        jl       L_13df
        mov      eax, dword ptr [g_dispatchSave1374_00f70f98]
        mov      esi, dword ptr [g_dispatchSave1371_00f70f88]
        mov      edx, dword ptr [g_dispatchSave1377_00f70fa0]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1374_00f70f98], eax
        mov      eax, dword ptr [g_dispatchSave1373_00f70f90]
        shl      eax, 0x10
        shl      esi, 0x10
        mov      dword ptr [g_dispatchSave1373_00f70f90], eax
        sub      eax, esi
        shl      edx, 0x10
        mov      dword ptr [g_dispatchSave1377_00f70fa0], edx
        mov      dword ptr [g_dispatchSave1371_00f70f88], esi
        cdq
        idiv     edi
        mov      edx, dword ptr [g_dispatchSave1374_00f70f98]
        mov      dword ptr [g_dispatchSave1357_00f70f4c], eax
        mov      eax, dword ptr [g_dispatchSave1377_00f70fa0]
        sub      eax, edx
        cdq
        idiv     ecx
        mov      dword ptr [g_dispatchSave1358_00f70f50], eax
        mov      eax, dword ptr [g_dispatchSave1378_00f70fa8]
        test     eax, eax
        jge      L_1225
        mov      edx, dword ptr [g_dispatchSave1357_00f70f4c]
        add      edi, eax
        imul     edx, eax
        sub      esi, edx
        xor      eax, eax
        mov      dword ptr [g_dispatchSave1371_00f70f88], esi
        mov      dword ptr [g_dispatchSave1708_00b2d00c], edi
        mov      dword ptr [g_dispatchSave1378_00f70fa8], eax
    L_1225:
        test     ebx, ebx
        jge      L_1254
        mov      eax, dword ptr [g_dispatchSave1358_00f70f50]
        mov      edx, dword ptr [g_dispatchSave1374_00f70f98]
        imul     eax, ebx
        sub      edx, eax
        mov      eax, dword ptr [g_dispatchSave1378_00f70fa8]
        add      ecx, ebx
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      dword ptr [g_dispatchSave1707_00b2d008], ecx
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ebx
    L_1254:
        mov      ecx, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380_00f70fb0]
        cmp      edx, ecx
        jl       L_126e
        sub      ecx, eax
        mov      edi, ecx
        mov      dword ptr [g_dispatchSave1708_00b2d00c], edi
    L_126e:
        mov      ecx, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383_00f70fc0]
        cmp      edx, ecx
        jl       L_1286
        sub      ecx, ebx
        mov      dword ptr [g_dispatchSave1707_00b2d008], ecx
    L_1286:
        mov      edx, dword ptr [g_viewportY]
        mov      ecx, dword ptr [g_viewportX]
        imul     edx, ebx
        add      ecx, edx
        mov      edx, dword ptr [g_dispatchSave1707_00b2d008]
        lea      ecx, [ecx + eax*2]
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
        and      eax, 0xf
        mov      dword ptr [g_dispatchSave1346_00f4d044], ecx
        shl      eax, 0x10
        test     edx, edx
        mov      dword ptr [g_dispatchSave1403_00f85b4c], eax
        jle      L_13df
        jmp      L_12c5
    L_12c0:
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
    L_12c5:
        xor      edx, edx
        and      ebx, 1
        mov      dh, byte ptr [g_dispatchSave1375_00f70f9a]
        mov      dword ptr [g_dispatchSave1387_00f70fd8], esi
        add      edx, eax
        mov      eax, dword ptr [g_dispatchSave1400_00f85b34]
        mov      dword ptr [g_dispatchSave1396_00f71304], ecx
        mov      dword ptr [g_dispatchSave1334_00f4d010], esi
        lea      edx, [eax + edx*2]
        mov      eax, ecx
        sar      eax, 1
        mov      dword ptr [g_dispatchSave1404_00f85b58], edx
        and      eax, 1
        mov      edx, edi
        xor      ebx, eax
        mov      dword ptr [g_dispatchSave1402_00f85b3c], edx
        je       L_1322
        mov      eax, dword ptr [g_dispatchSave1357_00f70f4c]
        lea      edx, [edi - 1]
        add      eax, esi
        mov      dword ptr [g_dispatchSave1402_00f85b3c], edx
        mov      dword ptr [g_dispatchSave1334_00f4d010], eax
        lea      eax, [ecx + 2]
        mov      dword ptr [g_dispatchSave1396_00f71304], eax
    L_1322:
        mov      eax, dword ptr [g_dispatchSave1357_00f70f4c]
        mov      ebx, dword ptr [g_dispatchSave1381_00f70fb8]
        add      eax, eax
        inc      ebx
        cmp      edx, 1
        mov      dword ptr [g_dispatchSave1395_00f71300], eax
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ebx
        jl       L_13b2
        mov      eax, dword ptr [g_dispatchSave1334_00f4d010]
        shl      eax, 0x10
        mov      edx, dword ptr [g_dispatchSave1404_00f85b58]
        shr      edx, 1
        mov      ecx, dword ptr [g_dispatchSave1334_00f4d010]
        shr      ecx, 0x10
        mov      dl, cl
        mov      edi, dword ptr [g_dispatchSave1396_00f71304]
        add      edi, dword ptr [g_dispatchSave1402_00f85b3c]
        add      edi, dword ptr [g_dispatchSave1402_00f85b3c]
        mov      esi, dword ptr [g_dispatchSave1402_00f85b3c]
        neg      esi
        mov      ecx, dword ptr [g_dispatchSave1395_00f71300]
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
        mov      ebx, dword ptr [g_dispatchSave1381_00f70fb8]
        mov      edi, dword ptr [g_dispatchSave1708_00b2d00c]
        mov      esi, dword ptr [g_dispatchSave1371_00f70f88]
        mov      ecx, dword ptr [g_dispatchSave1346_00f4d044]
    L_13b2:
        mov      edx, dword ptr [g_dispatchSave1358_00f70f50]
        mov      eax, dword ptr [g_dispatchSave1707_00b2d008]
        add      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      edx, dword ptr [g_viewportY]
        dec      eax
        add      ecx, edx
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707_00b2d008], eax
        mov      dword ptr [g_dispatchSave1346_00f4d044], ecx
        jg       L_12c0
    L_13df:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
